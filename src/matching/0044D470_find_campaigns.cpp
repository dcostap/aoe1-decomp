// VA: 0044D470 RGE_Game_Info::find_campaigns()
// gameinfo.cpp lines 561-633, 671 bytes, EH-framed (/GX)
//
// Attempt log:
// - baseline: the prior stub only established the 0x220 local frame; it had
//   no campaign/file-enumeration behavior.
// - behavior: reconstructed the period file scans, named RGE_Campaign and
//   RGE_Person_Info ownership, and the proven _finddata_t/file-name stack
//   window.  The first full compile is the structural baseline.
// - probes: scoped/reused indices, explicit positive guards, long versus int
//   counters, a live-zero experiment, and typed stack aggregates all kept the
//   same 609-byte mismatch (21 calls and the 0x220 frame aligned).
// - layout: a natural 256-byte filename local shrank the frame to 0x21C and
//   worsened the diff; restored the 260-byte local.
// - layout: swapping the natural filename/find-data declaration order emitted
//   identical 671-byte code and retained the +130 filename home; restored the
//   original declaration order.
// - current probe: expressed each scan as a guarded do/while whose condition
//   calls _findnext with the stable _findfirst handle; this matches the
//   original API use and reduces the drift to 298 bytes with exact size.
// - layout: the binary-proven 0x20C RGE_Campaign object size restored the
//   original allocation and reduced the mismatch to 157 bytes.
// - control-flow: the second typed scan now breaks on _findnext failure before
//   incrementing i; this restores the original ordered block shape and reduces
//   the mismatch to 10 bytes.
// - layout: the typed find-data work window uses the proven name position and
//   a four-byte tail gap; this restores the 0x220 frame and exact output.
// - exact: the final local check is a positional byte match with zero drift.

extern "C" int __cdecl sprintf(char* buffer, const char* format, ...);
extern "C" long __cdecl _findfirst(const char* filespec, void* file_info);
extern "C" int __cdecl _findnext(long handle, void* file_info);
extern "C" void* __cdecl calloc(int count, int size);
extern "C" void __cdecl free(void* p);
void __cdecl operator_delete(void* p);

class RGE_Prog_Info {
public:
    char gap_00[0xD1C];
    char campaign_dir[256];
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    char gap_04[8];
    RGE_Prog_Info* prog_info;
};

extern RGE_Base_Game* rge_base_game;

class RGE_Campaign {
public:
    char gap_00[0x20C];
    RGE_Campaign(char* filename);
    ~RGE_Campaign();
};

class RGE_Person_Info {
public:
    void rehook_campaigns(RGE_Campaign** campaigns, long campaign_num);
};

#pragma pack(push, 4)
struct FindDataLocal {
    unsigned int attrib;
    int time_create;
    int time_access;
    int time_write;
    char name[260];
};

struct FindCampaignWork {
    FindDataLocal file_info;
    char file_name[260];
    // Binary-proven unused tail in the 0x220-byte local work window.
    char gap_21C[4];
};
#pragma pack(pop)

class RGE_Game_Info {
public:
    int current_person;
    int people_num;
    RGE_Person_Info** people_info;
    int campaign_num;
    RGE_Campaign** campaigns;
    char save_filename[256];

    void find_campaigns();
};

void RGE_Game_Info::find_campaigns() {
    FindCampaignWork work;
    long handle;
    int i = 0;

    if (campaigns != 0) {
        i = 0;
        if (campaign_num > 0) {
            do {
                RGE_Campaign* campaign = campaigns[i];
                if (campaign != 0) {
                    campaign->~RGE_Campaign();
                    operator_delete(campaign);
                }
                ++i;
            } while (i < campaign_num);
        }
        free(campaigns);
        campaigns = 0;
    }

    sprintf(work.file_name + 4, "%s*.cpn", rge_base_game->prog_info->campaign_dir);
    handle = _findfirst(work.file_name + 4, &work.file_info);
    campaign_num = 0;
    if (handle != -1) {
        do {
            ++campaign_num;
        } while (_findnext(handle, &work.file_info) != -1);
    }

    sprintf(work.file_name + 4, "%s*.cpx", rge_base_game->prog_info->campaign_dir);
    handle = _findfirst(work.file_name + 4, &work.file_info);
    if (handle != -1) {
        do {
            ++campaign_num;
        } while (_findnext(handle, &work.file_info) != -1);
    }

    if (campaign_num > 0) {
        campaigns = (RGE_Campaign**)calloc(campaign_num, 4);
        i = 0;

        sprintf(work.file_name + 4, "%s*.cpn", rge_base_game->prog_info->campaign_dir);
        handle = _findfirst(work.file_name + 4, &work.file_info);
        if (handle != -1) {
            do {
                campaigns[i] = new RGE_Campaign(work.file_info.name + 4);
                ++i;
            } while (_findnext(handle, &work.file_info) != -1);
        }

        sprintf(work.file_name + 4, "%s*.cpx", rge_base_game->prog_info->campaign_dir);
        handle = _findfirst(work.file_name + 4, &work.file_info);
        if (handle != -1) {
            for (;;) {
                campaigns[i] = new RGE_Campaign(work.file_info.name + 4);
                if (_findnext(handle, &work.file_info) == -1) {
                    break;
                }
                ++i;
            }
        }
    } else {
        campaigns = 0;
    }

    for (i = 0; i < people_num; ++i) {
        people_info[i]->rehook_campaigns(campaigns, campaign_num);
    }
}
