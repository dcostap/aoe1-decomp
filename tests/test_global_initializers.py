"""Tests for initial PE storage reads."""
import sys
from pathlib import Path
from types import SimpleNamespace
import unittest

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / 'tools'))
from audit_global_initializers import compare_initial_bytes, read_storage


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

    def test_string_tail_layout_is_not_value_data(self):
        self.assertEqual(
            compare_initial_bytes(b'name\0\0', b'name\0E', 'char_array'),
            ('equal_value_tail_layout_differs', 5))

    def test_string_content_difference_fails(self):
        self.assertEqual(
            compare_initial_bytes(b'name\0', b'names', 'char_array'),
            ('different_initial_bytes', 5))


if __name__ == '__main__':
    unittest.main()
