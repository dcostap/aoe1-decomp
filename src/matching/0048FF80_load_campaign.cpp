// VA: 0048FF80 TRIBE_Campaign_Editor_Screen::load_campaign
// Source: scr_cam.cpp lines 342-382
// Attempt log:
// 1: initial natural reconstruction; /GX needed for constructor cleanup EH frame; addstring arity and campaign size wrong.
// 2: wrong: get_text has no suffix arg; suffix is addstring's third arg evaluated before get_text.
// 3: restore addstring 3-arg and use get_text(); close, but second missing-file branch uses xor+jmp before campaign block.
// 4: restructure as found/else so second cmp can je to no-campaign tail.
// FLAGS: config/flags/0048FF80_load_campaign.rsp

class TEditPanel { public: char* get_text(); };
class TTextPanel { public: void empty_list(); };
class RGE_Campaign { public: char gap_000[0x20C]; RGE_Campaign(char* path); ~RGE_Campaign(); };

struct ProgInfo { char gap_000[0xD1C]; char campaign_dir[1]; };
class RGE_Base_Game { public: char gap_00[0x0C]; ProgInfo* prog_info; };
#define rge_base_game (*(RGE_Base_Game**)0x0062C574)

extern void __cdecl addstring(char** dst, char* a, char* b);
extern long __cdecl _findfirst(char* path, void* fileinfo);
extern void* __cdecl operator new(unsigned int size);
extern void __cdecl operator delete(void* p);
extern void __cdecl free(void* p);

class TRIBE_Campaign_Editor_Screen {
public:
    char gap_000[0x478];
    unsigned char need_to_save;
    char gap_479[0x490 - 0x479];
    TTextPanel* campaign_scenarios;
    char gap_494[0x49C - 0x494];
    TEditPanel* filename;
    char gap_4A0[0x4C0 - 0x4A0];
    RGE_Campaign* campaign;

    void fill_scenario_list();
    void fill_campaign_scenario_list();
    unsigned char check_lists();
    void load_campaign();
};

void TRIBE_Campaign_Editor_Screen::load_campaign()
{
    char* text = 0;
    char* text2 = 0;
    char file_info[0x118];

    addstring(&text, this->filename->get_text(), (char*)".cpn");
    addstring(&text2, rge_base_game->prog_info->campaign_dir, text);
    long found = _findfirst(text2, file_info);
    unsigned char ok;
    if (found == -1) {
        addstring(&text, this->filename->get_text(), (char*)".cpx");
        addstring(&text2, rge_base_game->prog_info->campaign_dir, text);
        found = _findfirst(text2, file_info);
    }

    if (found != -1) {
        this->campaign = new RGE_Campaign(text);
        this->fill_scenario_list();
        this->fill_campaign_scenario_list();
        ok = this->check_lists();
        if (this->campaign != 0) {
            delete this->campaign;
        }
        this->campaign = 0;
    } else {
        ok = 0;
    }

    if (!ok) {
        this->campaign_scenarios->empty_list();
    }
    free(text);
    free(text2);
    this->need_to_save = 0;
}
