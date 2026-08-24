// VA: 00524880 TRIBE_Game::calc_timing_text (476 B)
// PDB source: tribegam.cpp:2003-2069
//
// Attempt log:
// - Replaced the raw-offset/incomplete scaffold with the period timing
//   counters: frame/world/view counts, the 30-entry RGE_Timing_Info array,
//   and the two named timing text buffers.
// - Exact after correcting the +0x6ac timing entry to its natural array index
//   and using the original zero-count fallback block as the early return.

extern "C" unsigned long __cdecl debug_timeGetTime(char* file, int line);
extern "C" char* __cdecl strcpy(char* destination, const char* source);
extern "C" int __cdecl sprintf(char* buffer, const char* format, ...);

extern unsigned char DAT_0086bcd0;
extern unsigned long DAT_0086bcd8;
extern int show_timing_max;

#ifndef TRIBEGAM_TU_CONTEXT
class RGE_Timing_Info {
public:
    unsigned long accum_time; // +0x00
    unsigned long last_time; // +0x04
    unsigned long start_time; // +0x08
    int include_in_total; // +0x0C
    int is_summary; // +0x10
    unsigned long last_single_time; // +0x14
    unsigned long max_time; // +0x18
    unsigned long last_max_time; // +0x1C
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();

    char gap_04[0x400];
    char timing_text[0x100]; // +0x404
    unsigned long frame_count; // +0x504
    unsigned long world_update_count; // +0x508
    unsigned long view_update_count; // +0x50C
    unsigned long last_frame_count; // +0x510
    unsigned long last_world_update_count; // +0x514
    unsigned long last_view_update_count; // +0x518
    unsigned long fps; // +0x51C
    unsigned long world_update_fps; // +0x520
    unsigned long view_update_fps; // +0x524
    RGE_Timing_Info timings[30]; // +0x528
    char gap_8E8[0x13C];
};

class TRIBE_Game : public RGE_Base_Game {
public:
    char gap_A24[0x440];
    char save_game_name[260]; // +0xE64
    char load_game_name[260]; // +0xF68
    char timing_text2[256]; // +0x106C

    virtual void calc_timing_text();
};
#endif

void TRIBE_Game::calc_timing_text()
{
    if ((DAT_0086bcd0 & 1) == 0) {
        DAT_0086bcd0 |= 1;
        DAT_0086bcd8 = debug_timeGetTime(
            "C:\\msdev\\work\\age1_x1\\tribegam.cpp", 0x7D4);
    }

    DAT_0086bcd8 = debug_timeGetTime(
        "C:\\msdev\\work\\age1_x1\\tribegam.cpp", 0x7D6);

    if (this->world_update_count == 0) {
        strcpy(this->timing_text2, "f?");
    } else if (show_timing_max == 0) {
        sprintf(
            this->timing_text2,
            "t%lu,f%lu,avg(r(v%lu,m%lu,o%lu),s%lu,u%lu,c%lu,l%lu,p%lu,o%lu)",
            this->world_update_fps,
            this->view_update_fps,
            this->timings[6].last_time / this->world_update_count,
            this->timings[7].last_time / this->world_update_count,
            this->timings[17].last_time / this->world_update_count,
            this->timings[3].last_time / this->world_update_count,
            this->timings[1].last_time / this->world_update_count,
            this->timings[14].last_time / this->world_update_count,
            (this->timings[10].last_time + this->timings[12].last_time) /
                this->world_update_count,
            this->timings[13].last_time / this->world_update_count,
            this->timings[4].last_time / this->world_update_count);
    } else {
        sprintf(
            this->timing_text2,
            "t%lu,f%lu,max(r(v%lu,m%lu,o%lu),s%lu,u%lu,c%lu,ls%lu,lg%lu,p%lu,o%lu)",
            this->world_update_fps,
            this->view_update_fps,
            this->timings[6].last_max_time,
            this->timings[7].last_max_time,
            this->timings[17].last_max_time,
            this->timings[3].last_max_time,
            this->timings[1].last_max_time,
            this->timings[14].last_max_time,
            this->timings[10].last_max_time,
            this->timings[12].last_max_time,
            this->timings[13].last_max_time,
            this->timings[4].last_max_time);
    }

    if (this->view_update_count == 0) {
        strcpy(this->timing_text, "avg view time=???");
        return;
    }

    sprintf(this->timing_text, "avg view time=%lu, count=%lu",
            this->timings[6].last_time / this->view_update_count,
            this->view_update_count);
}
