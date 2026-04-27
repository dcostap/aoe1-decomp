from __future__ import annotations

import subprocess
import sys
from pathlib import Path

from common import (
    classify_corpus_bucket,
    function_record_by_va,
    function_slug,
    load_asm_special_function_names,
    load_asm_special_regions,
    load_toolchain_supplied_function_names,
    load_toolchain_supplied_regions,
)

REPO_ROOT = Path(__file__).resolve().parent.parent
SCRATCH_DIR = REPO_ROOT / "src" / "scratch"
MATCHING_DIR = REPO_ROOT / "src" / "matching"
ACCEPTED_DRIFT_DIR = REPO_ROOT / "src" / "accepted_drift"

SOURCES: dict[str, str] = {
    "00411B40": """class ResourceItem;\n\nclass TechnologyItem {\npublic:\n    ResourceItem* resourceCost();\n};\n\nclass ResearchAIModule {\npublic:\n    TechnologyItem* item(int id);\n    ResourceItem* resourceCost(int id);\n};\n\nResourceItem* ResearchAIModule::resourceCost(int id) {\n    TechnologyItem* tech = this->item(id);\n    if (tech == 0) {\n        return 0;\n    }\n    return tech->resourceCost();\n}\n""",
    "00433DC0": """class RGE_Static_Object;\nclass RGE_Game_World {\npublic:\n    RGE_Static_Object* object(int id);\n};\n\nclass RGE_Command {\npublic:\n    char gap_00[0x4];\n    RGE_Game_World* world;\n\n    RGE_Static_Object* get_obj(int id);\n};\n\nRGE_Static_Object* RGE_Command::get_obj(int id) {\n    if (id == -1) {\n        return 0;\n    }\n    return this->world->object(id);\n}\n""",
    "00449A20": """class DriveInformation {\npublic:\n    int resetCurrentDrive();\n    int resetCurrentDirectory();\n    int resetCurrentDriveAndDirectory();\n};\n\nint DriveInformation::resetCurrentDriveAndDirectory() {\n    if (this->resetCurrentDrive() != 0) {\n        return this->resetCurrentDirectory();\n    }\n    return 0;\n}\n""",
    "0044CC20": """class RGE_Campaign {\npublic:\n    int open_scenario(int index);\n};\n\nclass RGE_Campaign_Info {\npublic:\n    char gap_00[0x100];\n    int current_scenario;\n    char gap_104[0xC];\n    RGE_Campaign* campaign;\n\n    int open_scenario();\n};\n\nint RGE_Campaign_Info::open_scenario() {\n    if (this->current_scenario > -1) {\n        return this->campaign->open_scenario(this->current_scenario);\n    }\n    return -1;\n}\n""",
    "0045B2C0": """class TMousePointer {\npublic:\n    char gap_00[0x138];\n    int game_mode;\n    int game_enabled;\n\n    int in_game_mode();\n};\n\nint TMousePointer::in_game_mode() {\n    if (this->game_mode && this->game_enabled) {\n        return 1;\n    }\n    return 0;\n}\n""",
    "0045D120": """class RGE_Moving_Object {\npublic:\n    char gap_00[0x88];\n    float move_speed;\n\n    unsigned char is_moving();\n};\n\nunsigned char RGE_Moving_Object::is_moving() {\n    if (this->move_speed > 0.0f) {\n        return 1;\n    }\n    return 0;\n}\n""",
    "0041B530": """struct SpriteState {\n    char gap_00[0x70];\n    unsigned char flags;\n};\n\nclass RGE_Active_Animated_Sprite {\npublic:\n    SpriteState* state;\n    char gap_08[0x1C];\n    unsigned char animate_flag;\n\n    virtual int is_animating();\n};\n\nint RGE_Active_Animated_Sprite::is_animating() {\n    if (this->animate_flag == 0 || (this->state->flags & 1) == 0) {\n        return 0;\n    }\n    return 1;\n}\n""",
    "004745E0": """class TTextPanel {\npublic:\n    void set_text_color(unsigned long fg, unsigned long bg);\n};\n\nclass TDropDownPanel {\npublic:\n    char gap_00[0xF4];\n    TTextPanel* val_panel;\n\n    void set_val_text_color(unsigned long fg, unsigned long bg);\n};\n\nvoid TDropDownPanel::set_val_text_color(unsigned long fg, unsigned long bg) {\n    if (this->val_panel != 0) {\n        this->val_panel->set_text_color(fg, bg);\n    }\n}\n""",
    "004889D0": """class RGE_RMM_Terrain_Generator {\npublic:\n    unsigned char water(unsigned char value);\n};\n\nunsigned char RGE_RMM_Terrain_Generator::water(unsigned char value) {\n    if (value == 1) {\n        return value;\n    }\n    if (value == 4) {\n        return 1;\n    }\n    if (value == 0x16) {\n        return 1;\n    }\n    return 0;\n}\n""",
    "00480EA0": """struct Map_Stack {\n    char gap_00[0x10];\n    Map_Stack* next;\n    Map_Stack* prev;\n};\n\nclass RGE_Random_Map_Module {\npublic:\n    unsigned char check_stack(Map_Stack* stack);\n};\n\nunsigned char RGE_Random_Map_Module::check_stack(Map_Stack* stack) {\n    if (stack->next == 0 && stack->prev == 0) {\n        return 0;\n    }\n    return 1;\n}\n""",
    "004A87D0": """class TRIBE_Screen_Sed {\npublic:\n    void get_string(long panel_id, char* buffer, int limit);\n    void set_string(char* buffer, long panel_id, int limit);\n};\n\nvoid TRIBE_Screen_Sed::set_string(char* buffer, long panel_id, int limit) {\n    this->get_string(panel_id, buffer, limit);\n}\n""",
    "004AB2B0": """class RGE_Scenario {\npublic:\n    void Set_player_Active(int player, int active);\n};\n\nclass ScreenWorld {\npublic:\n    char gap_00[0x5C];\n    RGE_Scenario* scenario;\n};\n\nclass TRIBE_Screen_Sed {\npublic:\n    char gap_00[0x928];\n    ScreenWorld* world;\n\n    void set_player_active(short player, int active);\n};\n\nvoid TRIBE_Screen_Sed::set_player_active(short player, int active) {\n    this->world->scenario->Set_player_Active((int)player, active);\n}\n""",
    "004BC930": """extern \"C\" int __cdecl ds_stream_volume(long value);\n\nclass TSound_Driver {\npublic:\n    unsigned char ready;\n\n    int set_stream_volume(long value);\n};\n\nint TSound_Driver::set_stream_volume(long value) {\n    if (this->ready == 0) {\n        return 0;\n    }\n    return ds_stream_volume(value);\n}\n""",
    "004BD4C0": """class TDigital {\npublic:\n    char gap_00[0x28];\n    int loop;\n\n    void set_loop(short value);\n};\n\nvoid TDigital::set_loop(short value) {\n    if (value == 0) {\n        this->loop = 0;\n        return;\n    }\n    this->loop = 1;\n}\n""",
    "004CB040": """struct CombatDataA {\n    char gap_00[0x8F];\n    unsigned char value_8F;\n};\n\nstruct CombatDataB {\n    char gap_00[0x8];\n    short value_08;\n};\n\nclass TRIBE_Combat_Object {\npublic:\n    char gap_00[0x8];\n    CombatDataA* data_a;\n    char gap_0C[0x18];\n    CombatDataB* data_b;\n\n    int can_debark();\n};\n\nint TRIBE_Combat_Object::can_debark() {\n    if (this->data_a->value_8F != 7) {\n        return 0;\n    }\n    return this->data_b->value_08 != 0;\n}\n""",
    "004DB0B0": """class TribeInformationAIModule {\npublic:\n    int importantMisc(int value);\n};\n\nint TribeInformationAIModule::importantMisc(int value) {\n    if (value != 1 && value != 0x1E) {\n        return 0;\n    }\n    return 1;\n}\n""",
    "004E6C40": """extern \"C\" void __cdecl rge_write(int file_handle, void* data, int size);\n\nclass TribeResourceAIModule {\npublic:\n    char gap_00[0xF4];\n    int numberResourcesValue;\n\n    int save(int file_handle);\n};\n\nint TribeResourceAIModule::save(int file_handle) {\n    rge_write(file_handle, &this->numberResourcesValue, 4);\n    return 1;\n}\n""",
    "00506C70": """class TribeFishingShipUnitAIModule {\npublic:\n    virtual int importantWhenDead(int value);\n};\n\nint TribeFishingShipUnitAIModule::importantWhenDead(int value) {\n    if (value != 0x1F && value != 5) {\n        return 0;\n    }\n    return 1;\n}\n""",
    "00514690": """struct TechPlayerEntry {\n    char gap_00[4];\n    short state;\n    short gap_06;\n};\n\nstruct TechTree {\n    TechPlayerEntry* tech_player_tree;\n};\n\nclass TRIBE_Player {\npublic:\n    char gap_00[0x220];\n    TechTree* tech_tree;\n\n    int researchAvailable(int index);\n};\n\nint TRIBE_Player::researchAvailable(int index) {\n    return this->tech_tree->tech_player_tree[index].state == 1;\n}\n""",
    "0052C080": """class RGE_Static_Object;\nclass RGE_Game_World {\npublic:\n    RGE_Static_Object* object(int id);\n};\n\nclass T_Scenario {\npublic:\n    char gap_00[0x8];\n    RGE_Game_World* world;\n\n    RGE_Static_Object* get_object_pointer(int index);\n};\n\nRGE_Static_Object* T_Scenario::get_object_pointer(int index) {\n    RGE_Static_Object* result = 0;\n    if (index > 0) {\n        result = this->world->object(index - 1);\n    }\n    return result;\n}\n""",
    "00510C90": """class TRIBE_Map {\npublic:\n    unsigned char water(unsigned char value);\n};\n\nunsigned char TRIBE_Map::water(unsigned char value) {\n    if (value == 1) {\n        return value;\n    }\n    if (value == 0x16) {\n        return 1;\n    }\n    if (value == 4) {\n        return 1;\n    }\n    return 0;\n}\n""",
    "005474B0": """class RGE_Zone_Map;\n\nclass RGE_Zone_Map_List {\npublic:\n    RGE_Zone_Map** zone_maps;\n    int zone_map_num;\n\n    RGE_Zone_Map* get_zone_map(long index);\n};\n\nRGE_Zone_Map* RGE_Zone_Map_List::get_zone_map(long index) {\n    if (index < this->zone_map_num) {\n        if (index >= 0) {\n            return this->zone_maps[index];\n        }\n    }\n    return 0;\n}\n""",
}


def check_function(va: str) -> bool:
    result = subprocess.run(
        [sys.executable, str(REPO_ROOT / "tools" / "check_function.py"), "--va", va],
        capture_output=True,
        text=True,
    )
    sys.stdout.write(result.stdout)
    sys.stderr.write(result.stderr)
    return result.returncode == 0


def main() -> None:
    matched = 0
    failed = 0
    skipped = 0
    toolchain_supplied_names = load_toolchain_supplied_function_names()
    toolchain_supplied_regions = load_toolchain_supplied_regions()
    asm_special_names = load_asm_special_function_names()
    asm_special_regions = load_asm_special_regions()

    for va, source in SOURCES.items():
        record = function_record_by_va(int(va, 16))
        corpus_bucket, corpus_reason = classify_corpus_bucket(
            record,
            toolchain_supplied_names=toolchain_supplied_names,
            toolchain_supplied_regions=toolchain_supplied_regions,
            asm_special_names=asm_special_names,
            asm_special_regions=asm_special_regions,
        )
        if corpus_bucket != "normal":
            print(f"[skip] {va} non-normal corpus bucket={corpus_bucket} ({corpus_reason})")
            skipped += 1
            continue

        slug = function_slug(record)
        matching_path = MATCHING_DIR / f"{slug}.cpp"
        accepted_drift_path = ACCEPTED_DRIFT_DIR / f"{slug}.cpp"
        if accepted_drift_path.exists():
            print(f"[skip] {va} already in accepted_drift")
            skipped += 1
            continue
        if matching_path.exists():
            print(f"[skip] {va} already in matching")
            skipped += 1
            continue

        scratch_path = SCRATCH_DIR / f"{slug}.cpp"
        scratch_path.write_text(source, encoding="utf-8")
        print(f"\n[easy] {va} {record['name']}")
        print(f"  wrote {scratch_path}")

        if check_function(va):
            scratch_path.rename(matching_path)
            print(f"  OK MATCH -> {matching_path}")
            matched += 1
        else:
            print(f"  XX MISMATCH -> kept in scratch: {scratch_path}")
            failed += 1

    print("\n============================================================")
    print("EASY SMALL BATCH RESULTS")
    print("============================================================")
    print(f"Matched: {matched}")
    print(f"Failed:  {failed}")
    print(f"Skipped: {skipped}")


if __name__ == "__main__":
    main()
