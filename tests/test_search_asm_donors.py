from __future__ import annotations

import json
import sys
import tempfile
import unittest
from unittest.mock import patch
from pathlib import Path


REPO_ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(REPO_ROOT / "tools"))

from search_asm_donors import (  # noqa: E402
    _basic_block_at,
    align_fragment,
    current_validation,
    make_instructions,
    parse_asm_text,
)


class SearchAsmDonorsTests(unittest.TestCase):
    def test_parser_normalizes_direct_calls_branches_and_register_shapes(self) -> None:
        text = (
            "00401000  8bf1              mov esi,ecx\n"
            "00401002  e8f9000000        call 00401100h\n"
            "00401007  85c0              test eax,eax\n"
            "00401009  7503              jne short 0040100Eh\n"
            "0040100B  8b4604            mov eax,[esi+4]\n"
            "0040100E  c3                ret\n"
        )
        instructions = parse_asm_text(text, {0x00401100: "helper"})
        self.assertEqual(len(instructions), 6)
        self.assertEqual(instructions[1].strict, "call helper")
        self.assertEqual(instructions[1].shape, "call direct")
        self.assertEqual(instructions[3].strict, "jne forward")
        self.assertEqual(instructions[0].shape, "mov r32,r32")
        self.assertEqual(instructions[4].operand_classes, "r32,mem")

    def test_mapped_alignment_finds_register_renamed_block_inside_noise(self) -> None:
        query = make_instructions(
            [
                (0x1000, "8b", "mov esi,ecx"),
                (0x1002, "8b", "mov eax,[esi+20h]"),
                (0x1005, "50", "push eax"),
                (0x1006, "e8", "call 00402000h"),
                (0x100B, "83", "add esp,4"),
            ],
            {0x00402000: "worker"},
        )
        donor = make_instructions(
            [
                (0x2000, "55", "push ebp"),
                (0x2001, "8b", "mov edi,edx"),
                (0x2003, "8b", "mov ecx,[edi+20h]"),
                (0x2006, "51", "push ecx"),
                (0x2007, "e8", "call 00402000h"),
                (0x200C, "83", "add esp,4"),
                (0x200F, "5d", "pop ebp"),
            ],
            {0x00402000: "worker"},
        )
        alignment = align_fragment(query, donor, "mapped")
        self.assertIsNotNone(alignment)
        assert alignment is not None
        self.assertGreater(alignment["score"], 75)
        self.assertEqual(alignment["donor_start"], 1)
        self.assertEqual(alignment["donor_end"], 6)
        self.assertEqual(alignment["query_coverage"], 1.0)

    def test_basic_block_selection_obeys_branch_leaders(self) -> None:
        instructions = make_instructions(
            [
                (0x3000, "85", "test eax,eax"),
                (0x3002, "74", "je short 00300Ah"),
                (0x3004, "40", "inc eax"),
                (0x3005, "eb", "jmp 00300Bh"),
                (0x300A, "48", "dec eax"),
                (0x300B, "c3", "ret"),
            ],
            {},
        )
        selected = _basic_block_at(instructions, 0x300A)
        self.assertEqual([row.address for row in selected], [0x300A])

    def test_current_validation_requires_new_checker_and_fresh_inputs(self) -> None:
        with tempfile.TemporaryDirectory() as temporary:
            root = Path(temporary)
            build = root / "build"
            source = root / "src" / "matching" / "00401000_demo.cpp"
            manifest = build / "manifests" / "build_00401000_demo.json"
            diff = build / "diff" / "00401000_demo.json"
            obj = build / "obj" / "00401000_demo.obj"
            for path in (source, manifest, diff, obj):
                path.parent.mkdir(parents=True, exist_ok=True)
            source.write_text("void demo() {}\n", encoding="utf-8")
            obj.write_bytes(b"x")
            manifest.write_text(
                '{"returncode":0,"input_fingerprint":"fresh","object":' +
                json.dumps(str(obj)) + "}",
                encoding="utf-8",
            )
            good_diff = {
                "result": "MATCH",
                "relocation_target_mismatches": [],
                "rebuilt_extraction": {"size_status": "within-expected-span", "boundary_escape_offsets": []},
            }
            diff.write_text(json.dumps(good_diff), encoding="utf-8")
            row = {"slug": "00401000_demo", "source_path": "src/matching/00401000_demo.cpp", "va": "00401000"}
            records = {"00401000": {"va": "00401000", "slug": "00401000_demo"}}
            with (
                patch("search_asm_donors.REPO_ROOT", root),
                patch("search_asm_donors.BUILD_DIR", build),
                patch("search_asm_donors.preferred_flags_rsp_path", return_value=root / "flags.rsp"),
                patch("search_asm_donors.build_input_manifest", return_value={"fingerprint": "fresh"}),
            ):
                self.assertEqual(current_validation(row, {}, records)["status"], "fresh-match")
                good_diff.pop("relocation_target_mismatches")
                diff.write_text(json.dumps(good_diff), encoding="utf-8")
                self.assertEqual(current_validation(row, {}, records)["status"], "stale")


if __name__ == "__main__":
    unittest.main()
