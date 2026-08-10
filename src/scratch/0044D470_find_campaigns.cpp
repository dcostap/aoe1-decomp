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
// - left in scratch: natural typed enumeration is retained; the remaining
//   drift is source-order/register scheduling in the cleanup and file-scan
//   blocks, plus the 16-byte total-size gap.

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
    RGE_Campaign(char* filename);
    ~RGE_Campaign();
};

class RGE_Person_Info {
public:
    void rehook_campaigns(RGE_Campaign** campaigns, long campaign_num);
};

struct FindDataLocal {
    unsigned int attrib;
    long time_create;
    long time_access;
    long time_write;
    unsigned long size;
    char name[260];
};

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
    FindDataLocal file_info;
    char file_name[260];
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

    sprintf(file_name + 4, "%s*.cpn", rge_base_game->prog_info->campaign_dir);
    handle = _findfirst(file_name + 4, &file_info);
    campaign_num = 0;
    while (handle != -1) {
        ++campaign_num;
        handle = _findnext(handle, &file_info);
    }

    sprintf(file_name + 4, "%s*.cpx", rge_base_game->prog_info->campaign_dir);
    handle = _findfirst(file_name + 4, &file_info);
    while (handle != -1) {
        ++campaign_num;
        handle = _findnext(handle, &file_info);
    }

    if (campaign_num > 0) {
        campaigns = (RGE_Campaign**)calloc(campaign_num, 4);
        i = 0;

        sprintf(file_name + 4, "%s*.cpn", rge_base_game->prog_info->campaign_dir);
        handle = _findfirst(file_name + 4, &file_info);
        while (handle != -1) {
            campaigns[i] = new RGE_Campaign(file_info.name + 4);
            ++i;
            handle = _findnext(handle, &file_info);
        }

        sprintf(file_name + 4, "%s*.cpx", rge_base_game->prog_info->campaign_dir);
        handle = _findfirst(file_name + 4, &file_info);
        while (handle != -1) {
            campaigns[i] = new RGE_Campaign(file_info.name + 4);
            ++i;
            handle = _findnext(handle, &file_info);
        }
    } else {
        campaigns = 0;
    }

    for (i = 0; i < people_num; ++i) {
        people_info[i]->rehook_campaigns(campaigns, campaign_num);
    }
}
