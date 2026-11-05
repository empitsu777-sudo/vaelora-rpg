import hashlib
import importlib.util
import json
import pathlib
import tempfile
import unittest

SCRIPT = pathlib.Path(__file__).resolve().parents[1] / 'tools' / 'release_gate.py'
spec = importlib.util.spec_from_file_location('release_gate', SCRIPT)
module = importlib.util.module_from_spec(spec)
spec.loader.exec_module(module)


class ReleaseGateTests(unittest.TestCase):
    def test_repair04_is_not_release_eligible(self):
        evidence = json.loads((SCRIPT.parent.parent / 'docs' / 'RELEASE_EVIDENCE_REPAIR04.json').read_text())
        errors = module.check(evidence)
        self.assertTrue(any('emulator_collision' in e for e in errors))
        self.assertTrue(any('open_p0_count' in e for e in errors))

    def test_matching_rom_and_artifact_requirements(self):
        with tempfile.TemporaryDirectory() as directory:
            root = pathlib.Path(directory)
            rom = root / 'test.gba'
            rom.write_bytes(b'fake ROM bytes for gate unit test only')
            evidence_file = root / 'evidence.log'
            evidence_file.write_bytes(b'synthetic proof for checking file hashes only')
            good = {
                'release_status': 'candidate_for_acceptance',
                'open_p0_count': 0,
                'rom_sha256': hashlib.sha256(rom.read_bytes()).hexdigest(),
            }
            for name in module.REQUIRED:
                good[name] = {
                    'passed': True,
                    'evidence': 'synthetic gate schema test, not an actual emulator run',
                    'evidence_file': 'evidence.log',
                    'evidence_sha256': hashlib.sha256(evidence_file.read_bytes()).hexdigest(),
                }
            self.assertEqual(module.check(good, rom, root), [])
            good['rom_sha256'] = '0'*64
            self.assertIn('rom_sha256 mismatch', module.check(good, rom, root))

    def test_missing_evidence_file_is_not_accepted(self):
        with tempfile.TemporaryDirectory() as directory:
            root = pathlib.Path(directory)
            rom = root / 't.gba'
            rom.write_bytes(b'fake rom')
            evidence = {'release_status': 'candidate_for_acceptance', 'open_p0_count': 0,
                        'rom_sha256': hashlib.sha256(rom.read_bytes()).hexdigest()}
            for name in module.REQUIRED:
                evidence[name] = {'passed': True, 'evidence': 'reported passed but without file'}
            self.assertTrue(any('missing evidence_file' in e for e in module.check(evidence, rom, root)))


if __name__ == '__main__':
    unittest.main()