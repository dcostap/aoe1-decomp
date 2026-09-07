"""Tests for initial PE storage reads."""
import sys
from pathlib import Path
from types import SimpleNamespace
import unittest

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools'))
from audit_global_initializers import read_storage


class StorageTests(unittest.TestCase):
    def image(self):
        return SimpleNamespace(
            OPTIONAL_HEADER=SimpleNamespace(ImageBase=0x400000),
            sections=[SimpleNamespace(VirtualAddress=0x1000,
                                      Misc_VirtualSize=8, SizeOfRawData=4)],
            get_data=lambda rva, size: b'abcd'[rva - 0x1000:rva - 0x1000 + size])

    def test_stored_data(self):
        self.assertEqual(read_storage(self.image(), 0x401000, 4), b'abcd')

    def test_zero_tail(self):
        self.assertEqual(read_storage(self.image(), 0x401002, 6), b'cd' + bytes(4))

    def test_zero_storage(self):
        self.assertEqual(read_storage(self.image(), 0x401004, 4), bytes(4))

    def test_bad_range(self):
        with self.assertRaises(ValueError):
            read_storage(self.image(), 0x401007, 2)


if __name__ == '__main__':
    unittest.main()
