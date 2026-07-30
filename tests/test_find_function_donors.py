from __future__ import annotations

import sys
import tempfile
import unittest
from pathlib import Path


REPO_ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(REPO_ROOT / "tools"))

from find_function_donors import packet_features, score_donor  # noqa: E402


class FindFunctionDonorsTests(unittest.TestCase):
    def test_packet_features_extract_calls_slots_frame_and_eh(self) -> None:
        with tempfile.TemporaryDirectory() as temporary:
            packet = Path(temporary) / "f.txt"
            packet.write_text(
                "=== OriginalAsm ===\n"
                "  00401000  83ec10  sub esp,10h\n"
                "  00401003  53      push ebx\n"
                "  00401004  64a100000000 mov eax,[fs:0]\n"
                "  0040100A  e8...   call 00402000h\n"
                "  0040100F  ff5010  call dword [eax+10h]\n"
                "  00401012  8b481c  mov ecx,[eax+1Ch]\n"
                "=== GhidraListingExcerpt ===\n",
                encoding="utf-8",
            )
            features = packet_features(packet, {0x00402000: "helper"})
        self.assertEqual(features["calls"], {"helper"})
        self.assertEqual(features["vslots"], {0x10})
        self.assertEqual(features["frame_size"], 0x10)
        self.assertTrue(features["eh_frame"])
        self.assertIn(0x1C, features["displacements"])

    def test_score_prioritizes_same_tu_class_and_call_surface(self) -> None:
        common = {
            "pdb_source_file": "a.cpp",
            "class_name": "Owner",
            "family": "constructor",
            "calling_convention": "__thiscall",
            "size_bytes": 100,
            "name": "Owner",
            "packet_features": {
                "calls": {"a", "b"}, "vslots": {4}, "displacements": {8, 12},
                "frame_size": 16, "saved_registers": ["esi"], "eh_frame": True,
            },
        }
        close = {**common, "name": "Owner2", "size_bytes": 110}
        distant = {
            **common,
            "pdb_source_file": "other.cpp",
            "class_name": "Other",
            "family": "ordinary",
            "packet_features": {
                "calls": {"z"}, "vslots": set(), "displacements": {200},
                "frame_size": 0, "saved_registers": [], "eh_frame": False,
            },
        }
        self.assertGreater(score_donor(common, close)[0], score_donor(common, distant)[0])


if __name__ == "__main__":
    unittest.main()
