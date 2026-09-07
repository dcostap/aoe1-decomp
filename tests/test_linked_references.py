"""Unit checks for shared storage relationships."""
import sys
from pathlib import Path
import unittest
from types import SimpleNamespace

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools'))
from audit_linked_references import classify, decode


class FixedPE:
    OPTIONAL_HEADER = SimpleNamespace(ImageBase=0x400000)

    def __init__(self, code):
        self.code = code

    def get_data(self, rva, size):
        return self.code[rva:rva + size]


class StorageTests(unittest.TestCase):
    def setUp(self):
        self.owners = [dict(original=0x1000, rebuilt=0x2000, size=20, name='riff')]

    def test_member_offset(self):
        self.assertEqual(classify(0x1004, 0x2004, self.owners)[0], 'pass')

    def test_split_storage(self):
        self.assertEqual(classify(0x1004, 0x3000, self.owners)[0], 'fail')

    def test_outside_owner(self):
        self.assertEqual(classify(0x1014, 0x2014, self.owners)[0], 'unknown')

    def test_ambiguous_owner(self):
        self.assertEqual(classify(0x1004, 0x2004, self.owners * 2)[0], 'unknown')

    def test_fixed_base_absolute_reference_without_relocations(self):
        a = decode(FixedPE(bytes.fromhex('8b0d04100000c3')), 0x400000, 7)
        b = decode(FixedPE(bytes.fromhex('8b0d00300000c3')), 0x400000, 7)
        self.assertEqual(a[0], b[0])
        self.assertEqual(a[1], [(2, 'address', 0x1004)])
        self.assertEqual(classify(a[1][0][2], b[1][0][2], self.owners)[0], 'fail')

    def test_arithmetic_immediate_is_not_an_address(self):
        a = decode(FixedPE(bytes.fromhex('b804100000c3')), 0x400000, 6)
        self.assertEqual(a[1], [])

    def test_different_code_does_not_align(self):
        a = decode(FixedPE(bytes.fromhex('8b0d04100000c3')), 0x400000, 7)
        b = decode(FixedPE(bytes.fromhex('8b1504100000c3')), 0x400000, 7)
        self.assertNotEqual(a[0], b[0])


if __name__ == '__main__':
    unittest.main()
