// VA: 0041CCA0 RGE_Base_Game::get_scenario_header (253 B)
// PDB source: basegame.cpp
// Attempt log:
// baseline: canonical scenario filename/open/read/version-gate reconstruction;
// the initial local shim still used free helper wrappers and had a 0x12C frame.
// probe 2: typed RGE_Game_Info::open_scenario and RGE_Base_Game virtual dispatch
// fixed the ordered call surface and reduced the mismatch to stack/codegen shape.
// probe 3: restored the observed vtable slot 0x38 (one additional preceding slot).
// probe 4: reading directly into version produced the correct 0x130 frame but
// shifted the filename buffer by four bytes; probe 5 declaration reordering was
// a codegen duplicate. Probe 6 reproduced the same direct-read result.
// probe 7: a typed local work window for the PDB-proven 300-byte temp_name and
// adjacent version slot, while keeping the compared scalar separate, matched.
// probe 8: using the aggregate version member emitted an extra store/reload;
// probe 9: reading into that member selected the wrong stack address. Rolled
// both back; retain the best period-plausible typed window and scalar compare.
// Main-agent audit restored the canonical base-game destructor slot; emitted
// code remains exact.

extern int sprintf(char* buf, const char* fmt, ...);
extern int rge_open(char* path, int flags);
extern void rge_read_uncompressed(int fd, void* buf, int len);
extern int rge_close(int fd);




class RGE_Scenario_Header;
struct Scenario_Header_Work {
    char temp_name[300];
    int version;
};

RGE_Scenario_Header* RGE_Base_Game::get_scenario_header(char* param1, int param2)
{
    int version;
    Scenario_Header_Work work;
    int fd;
    RGE_Scenario_Header* result;

    sprintf(work.temp_name + 4, "%s%s", this->prog_info->scenario_dir, param1);

    if (param2) {
        fd = this->player_game_info->open_scenario();
    } else {
        if (!param1)
            return 0;
        fd = rge_open(work.temp_name + 4, 0x8000);
    }

    if (fd == -1)
        return 0;

    rge_read_uncompressed(fd, work.temp_name, 4);
    version = *(int*)work.temp_name;

    result = 0;
    if (version == *(int*)"1.03" ||
        version == *(int*)"1.04" ||
        version == *(int*)"1.05" ||
        version == *(int*)"1.06" ||
        version == *(int*)"1.07" ||
        version == *(int*)"1.08" ||
        version == *(int*)"1.09" ||
        version == *(int*)"1.10" ||
        version == *(int*)"1.11")
    {
        result = this->new_scenario_header(fd);
    }

    rge_close(fd);
    return result;
}
