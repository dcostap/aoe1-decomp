"""Check the unit AI random call site against the pinned original image."""
import hashlib
import json
from pathlib import Path

import pefile


ROOT = Path(__file__).resolve().parents[1]


def test_closest_undiscovered_tile_uses_original_cpp_path():
    executable = json.loads((ROOT / "config/executable.json").read_text())
    original = (ROOT / executable["original"]).read_bytes()
    assert hashlib.sha256(original).hexdigest() == executable["original_sha256"]
    image = pefile.PE(data=original)
    base = image.OPTIONAL_HEADER.ImageBase

    ai_registry = json.loads((ROOT / "config/functions/src/aiuaimod.cpp.json").read_text())
    assert ai_registry["functions"]["00415F40"]["symbol"] == (
        "?closestUndiscoveredTile@UnitAIModule@@UAEHPAH0H@Z"
    )
    assert ai_registry["functions"]["004161D0"]["symbol"] == (
        "?waypoint@UnitAIModule@@QBEPAUWaypoint@@H@Z"
    )
    assert 0x415F40 <= 0x41601A < 0x4161D0

    # 0041601A pushes line 2862 and the path address. It then calls debug_rand.
    callsite = image.get_data(0x41601A - base, 15)
    assert callsite == bytes.fromhex("68 2E 0B 00 00 68 80 F9 57 00 E8 77 D0 00 00")
    path_address = int.from_bytes(callsite[6:10], "little")
    call_target = 0x416029 + int.from_bytes(callsite[11:15], "little", signed=True)
    assert image.get_data(path_address - base, 40).split(b"\0", 1)[0] == (
        b"C:\\msdev\\work\\age1_x1\\aiuaimod.cpp"
    )

    base_registry = json.loads((ROOT / "config/functions/src/basegame.cpp.json").read_text())
    assert call_target == 0x4230A0
    assert base_registry["functions"][f"{call_target:08X}"]["symbol"] == (
        "?debug_rand@@YAHPADH@Z"
    )

    source = (ROOT / "src/aiuaimod.cpp").read_text()
    body = source.split("int UnitAIModule::closestUndiscoveredTile", 1)[1].split(
        "Waypoint* UnitAIModule::waypoint", 1
    )[0]
    assert '"C:\\\\msdev\\\\work\\\\age1_x1\\\\aiuaimod.cpp", 0xB2E' in body
    assert '"C:\\\\msdev\\\\work\\\\age1_x1\\\\aiuaimod.c", 0xB2E' not in body


def test_debug_rand_gets_rng_value_before_it_reads_log_identity():
    executable = json.loads((ROOT / "config/executable.json").read_text())
    image = pefile.PE(str(ROOT / executable["original"]), fast_load=True)
    base = image.OPTIONAL_HEADER.ImageBase

    # The function calls rand and saves EAX before it reads either logging flag.
    prefix = image.get_data(0x4230A0 - base, 27)
    assert prefix == bytes.fromhex(
        "83 EC 0C 57 E8 C7 9B 12 00 8B F8 A1 D0 C4 62 00 85 C0 74 7F "
        "A1 D4 C4 62 00 85 C0"
    )
