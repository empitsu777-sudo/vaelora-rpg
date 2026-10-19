"""Test exact 1-pixel collision probes used by the actual C player movement.
This catches warp triggers that coarse 8x8 tile graph tests miss.
"""
import collections
import unittest
from test_rom_and_routes import array

def reachable(scene,start,predicate,gate=False):
 c=array('vaelora_solid_%d'%scene)
 visited=bytearray(512*512)
 def solid(x,y):
  if x<12 or x>=500 or y<12 or y>=500:return True
  tx,ty=x>>3,y>>3
  if scene==1 and gate and ty in (29,30) and 29<=tx<35:return False
  return bool(c[ty*64+tx])
 def canmove(x,y):return not (solid(x-5,y-2) or solid(x+5,y-2) or solid(x-5,y-8) or solid(x+5,y-8))
 initial=start[1]*512+start[0];q=collections.deque([initial]);visited[initial]=1
 while q:
  n=q.popleft();x=n%512;y=n//512
  if predicate(x,y):return True
  for xx,yy in ((x-1,y),(x+1,y),(x,y-1),(x,y+1)):
   if 0<=xx<512 and 0<=yy<512:
    idx=yy*512+xx
    if not visited[idx] and canmove(xx,yy):visited[idx]=1;q.append(idx)
 return False
class TestPixelTraversal(unittest.TestCase):
 def test_bellhaven_north_exit_actually_reachable(self):
  self.assertTrue(reachable(0,(256,253),lambda x,y:y<25 and 230<x<286))
 def test_maera_and_workshop_reachable(self):
  self.assertTrue(reachable(0,(256,253),lambda x,y:abs(x-145)+abs(y-234)<45))
  self.assertTrue(reachable(0,(256,253),lambda x,y:abs(x-128)+abs(y-202)<30))
 def test_reedglass_gate_access_and_shard(self):
  self.assertTrue(reachable(1,(256,470),lambda x,y:abs(x-256)+abs(y-240)<60))
  self.assertFalse(reachable(1,(256,470),lambda x,y:abs(x-256)+abs(y-120)<35))
  self.assertTrue(reachable(1,(256,470),lambda x,y:abs(x-256)+abs(y-120)<35,gate=True))
 def test_reedglass_return_exit(self):
  self.assertTrue(reachable(1,(256,470),lambda x,y:y>493 and 224<x<288))
