// VA: 00490120 TRIBE_Campaign_Editor_Screen::make_campaign
// Source: scr_cam.cpp lines 388-457
// Attempt log:
// 1: initial reconstruction used manual operator_new and placement new. It
//    lacked the original EH frame and used the wrong campaign call surface.
// 2: fresh typed reconstruction uses the same-TU popup, list, base-game, and
//    ordinary RGE_Campaign new/delete surfaces as the executable.
// 3: inverted the filename and count guards and placed both popup paths in
//    compiler-visible tail blocks. This fixed frame size and ordered calls.
// 4: duplicate array ownership is intentionally spelled with the first copy
//    read into scenarios_text and the second copy read into campaign_filename.
//    Reversing those source uses selected the original VC5 stack slots.
// 5: swapped duplicate-array allocation and cleanup order. The source now
//    matches all calls, branch counts, frame size, and most emitted blocks.
//    Remaining drift is 61 positional bytes, centered on the allocation-store
//    order and the no-scenario cleanup tail. Budget exhausted; left in scratch.
// 6: swapped the natural calloc assignments so campaign_filename received the
//    first allocation. This worsened the first block and was restored.
// 7: reordered the typed array declarations; VC5 emitted the same stack homes.
// 8: grouped the typed array declarations; VC5 emitted the same stack homes.
// 9: moved the name declaration after the arrays; VC5 emitted the same homes.
// 10: tested loop-scoped indices for pointer-home coloring; VC5 rejects the
//    second declaration with C2374, so the shared top-level index was restored.

typedef unsigned int uint;

extern "C" void* __cdecl calloc(uint count, uint size);
extern "C" void __cdecl free(void* p);
extern "C" int __cdecl sprintf(char* buffer, const char* format, ...);
extern "C" long __cdecl _findfirst(char* path, void* info);
extern "C" void __cdecl addstring(char** dst, char* src, char* ext);
extern "C" void __cdecl getstring(char** dst, char* src);

class TPanel {
public:
    virtual void v00();
};

class TEasy_Panel : public TPanel {
public:
    void popupOKDialog(long text_id, char* panel_name, int width, int height);
};

class TEditPanel : public TPanel {
public:
    char* get_text();
};

class TTextPanel : public TPanel {
public:
    int numberLines();
    char* get_text(int line);
};

struct RGE_Prog_Info {
    char gap_000[0xC17];
    char scenario_dir[1];
};

class RGE_Base_Game {
public:
    char gap_000[0x0C];
    RGE_Prog_Info* prog_info;
    void find_campaigns();
};

extern RGE_Base_Game* rge_base_game;

class RGE_Campaign {
public:
    char gap_000[0x20C];
    RGE_Campaign(char* text, char* name, int count, char** scenario_text,
                 char** scenario_filenames);
    ~RGE_Campaign();
};

class TRIBE_Campaign_Editor_Screen : public TEasy_Panel {
public:
    char gap_004[0x474];
    unsigned char need_to_save;
    char gap_479[0x13];
    TTextPanel* scenarios;
    TTextPanel* campaign_scenarios;
    char gap_494[8];
    TEditPanel* filename;
    char gap_4A0[0x20];
    RGE_Campaign* campaign;

    void fill_campaign_drop();
    void make_campaign();
};

void TRIBE_Campaign_Editor_Screen::make_campaign()
{
    char* name;
    char* text = 0;
    char** campaign_filename;
    char** scenarios_text;
    char test[260];
    char file_info[280];
    int count;
    int i;
    RGE_Campaign* new_campaign;

    name = this->filename->get_text();
    if (name != 0) {
        if (*name == 0 || *name == ' ') {
            goto invalid_name;
        }

            addstring(&text, name, (char*)".cpx");
            count = this->campaign_scenarios->numberLines();
            if (count > 0) {
                scenarios_text = (char**)calloc(count, 4);
                campaign_filename = (char**)calloc(count, 4);
                for (i = 0; i < count; ++i) {
                    getstring(&scenarios_text[i],
                              this->campaign_scenarios->get_text(i));
                    getstring(&campaign_filename[i],
                              this->campaign_scenarios->get_text(i));
                    sprintf(test, (char*)"%s%s.scn",
                            rge_base_game->prog_info->scenario_dir,
                            campaign_filename[i]);
                    if (_findfirst(test, file_info) == -1) {
                        addstring(&campaign_filename[i], campaign_filename[i],
                                  (char*)".scx");
                    } else {
                        addstring(&campaign_filename[i], campaign_filename[i],
                                  (char*)".scn");
                    }
                }

                new_campaign = new RGE_Campaign(
                    text, name, count, campaign_filename, scenarios_text);
                this->campaign = new_campaign;
                if (new_campaign != 0) {
                    delete new_campaign;
                }
                this->campaign = 0;

                for (i = 0; i < count; ++i) {
                    free(scenarios_text[i]);
                    free(campaign_filename[i]);
                }
                free(campaign_filename);
                free(scenarios_text);
            } else {
                this->popupOKDialog(0x2BCB, 0, 0x1C2, 100);
            }
            free(text);
            this->fill_campaign_drop();
            rge_base_game->find_campaigns();
    }

    goto done;

done:
    this->need_to_save = 0;
    return;

invalid_name:
    this->popupOKDialog(0x2BCC, 0, 0x1C2, 100);
    goto done;
}
