// VA: 0041CB80 RGE_Base_Game::get_scenario_info (275 B)
// PDB source: basegame.cpp
// Attempt log:
// baseline: packet-based reconstruction with local shim and free open_scenario wrapper;
// it preserved the frame but emitted the wrong direct call and a two-byte overrun.
// probe 2: restored the same-TU typed RGE_Game_Info member and RGE_Base_Game virtual
// slot surface used by get_scenario_header; this is the canonical source shape.
// probes 3-4: reading the final header into the filename buffer removed the four-byte
// local frame slot; an unused header_size declaration did not preserve it.
// probe 5: using the packet-declared header_size as the final read destination restored
// the 0x138 frame and left only the two filename LEA displacements.
// probes 6-7: declaration reordering was a codegen duplicate; probe 8's aggregate work
// window changed liveness and was rolled back.
// probe 9: with the separate header_size stack scalar, the natural temp_name base is
// already the binary's effective +4 address; removing the redundant source offset is exact.

extern int sprintf(char* buf, const char* fmt, ...);
extern int rge_open(const char* path, int flags);
extern int rge_read_uncompressed(int fd, void* buf, int len);
extern int rge_read(int fd, void* buf, int len);
extern int rge_close(int fd);
extern void* malloc(int size);
extern "C" void free(void* p);




class RGE_Scenario;
RGE_Scenario* RGE_Base_Game::get_scenario_info(char* param1, int param2)
{
    char temp_name[300];
    int fd;
    int version;
    int obj_id;
    int header_size;
    RGE_Scenario* result;
    void* buf;

    sprintf(temp_name, "%s%s", this->prog_info->scenario_dir, param1);

    if (param2) {
        fd = this->player_game_info->open_scenario();
    } else {
        if (!param1)
            return 0;
        fd = rge_open(temp_name, 0x8000);
    }

    if (fd == -1)
        return 0;

    rge_read_uncompressed(fd, &obj_id, 4);
    rge_read_uncompressed(fd, &version, 4);

    if (version > 0) {
        buf = malloc(version);
        if (!buf) {
            rge_close(fd);
            return 0;
        }
        rge_read_uncompressed(fd, buf, version);
        free(buf);
    }

    rge_read(fd, &header_size, 4);

    result = this->new_scenario_info(fd);
    rge_close(fd);
    return result;
}
