"""Run: PYTHONPATH=. python -m unittest discover -s tests -v"""
import tempfile
import unittest
from pathlib import Path
from PIL import Image
from tools.validate_sprites import check_sprite

class SpriteValidatorTests(unittest.TestCase):
    def setUp(self):
        temp=tempfile.TemporaryDirectory()
        self.addCleanup(temp.cleanup)
        self.root=Path(temp.name)
        (self.root/"assets").mkdir()
        self.path=self.root/"assets"/"sprite.png"
        self.spec={"id":"test","file":"assets/sprite.png","frame_width":16,"frame_height":32,
                   "columns":3,"rows":4,"palette_bank":0,"origin":"original"}
    def image(self,size=(48,128),pixel=1,transparent=True):
        im=Image.new("P",size,0)
        im.putpalette([0,0,0,255,255,255]+[0,0,0]*254)
        im.putpixel((1,1),pixel)
        if transparent: im.save(self.path,transparency=0)
        else: im.save(self.path)
    def test_valid(self):
        self.image()
        self.assertEqual([],check_sprite(self.spec,self.root))
    def test_bad_size(self):
        self.image((32,32))
        self.assertTrue(any("expected" in e for e in check_sprite(self.spec,self.root)))
    def test_palette_overflow(self):
        self.image(pixel=17)
        self.assertTrue(any("0..15" in e for e in check_sprite(self.spec,self.root)))
    def test_missing_alpha_zero(self):
        self.image(transparent=False)
        self.assertTrue(any("transparent" in e for e in check_sprite(self.spec,self.root)))
    def test_hardware_dimensions(self):
        self.image()
        self.spec["frame_width"]=24
        self.assertTrue(any("not a legal" in e for e in check_sprite(self.spec,self.root)))
    def test_third_party_origin(self):
        self.image()
        self.spec["origin"]="copied"
        self.assertTrue(any("origin" in e for e in check_sprite(self.spec,self.root)))
