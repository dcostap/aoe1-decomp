from __future__ import annotations

import sys
import unittest
from pathlib import Path


REPO_ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(REPO_ROOT / "tools"))

from common import (  # noqa: E402
    classify_corpus_bucket,
    load_binaries,
    load_layout,
    load_pe_image,
    owned_function_ranges,
    repo_path,
)


class ExtractOriginalFunctionTests(unittest.TestCase):
    def test_parent_owned_fragments_restore_one_contiguous_boundary(self) -> None:
        layout = {
            "functions": [
                {
                    "start": "0047EE90",
                    "body_ranges": [
                        {"start": "0047EE90", "end": "0047F00B"},
                        {"start": "0047F027", "end": "0047F075"},
                        {"start": "0047F122", "end": "0047F173"},
                    ],
                },
                {"start": "0047F00C", "body_ranges": [{"start": "0047F00C", "end": "0047F026"}]},
                {"start": "0047F076", "body_ranges": [{"start": "0047F076", "end": "0047F121"}]},
            ]
        }
        fragments = {
            0x0047F00C: (0x0047EE90, "RESFILE_open_new_resource_file", "internal_error_exit"),
            0x0047F076: (0x0047EE90, "RESFILE_open_new_resource_file", "internal_shared_tail"),
        }

        ranges, included = owned_function_ranges(layout, 0x0047EE90, fragments)

        self.assertEqual(ranges, [(0x0047EE90, 0x0047F173)])
        self.assertEqual(included, [0x0047F00C, 0x0047F076])

    def test_unowned_gap_is_not_concatenated(self) -> None:
        layout = {
            "functions": [
                {
                    "start": "00401000",
                    "body_ranges": [
                        {"start": "00401000", "end": "00401001"},
                        {"start": "00401004", "end": "00401005"},
                    ],
                }
            ]
        }

        with self.assertRaisesRegex(ValueError, "refusing to concatenate"):
            owned_function_ranges(layout, 0x00401000, {})

    def test_fragment_manifest_classifies_only_fragment_entries(self) -> None:
        fragments = {
            0x0047F00C: (0x0047EE90, "RESFILE_open_new_resource_file", "internal_error_exit")
        }

        parent = classify_corpus_bucket(
            {"va": "0047EE90", "name": "RESFILE_open_new_resource_file"},
            parent_owned_fragments=fragments,
        )
        fragment = classify_corpus_bucket(
            {"va": "0047F00C", "name": "FUN_0047f00c"},
            parent_owned_fragments=fragments,
        )

        self.assertEqual(parent, ("normal", ""))
        self.assertEqual(fragment, ("parent_owned_fragment", "parent 0047EE90 RESFILE_open_new_resource_file internal_error_exit"))

    def test_shipped_int3_remains_inside_parent_boundary(self) -> None:
        binaries = load_binaries()
        layout = load_layout(repo_path(binaries["ghidra_layout"]))
        ranges, _ = owned_function_ranges(layout, 0x0047EE90)
        image = load_pe_image(repo_path(binaries["original_exe"]))

        self.assertEqual(ranges, [(0x0047EE90, 0x0047F173)])
        self.assertEqual(image.read_va_range(0x0047F00B, 0x0047F00B), b"\xCC")


if __name__ == "__main__":
    unittest.main()
