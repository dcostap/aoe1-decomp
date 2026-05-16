// VA: 00490120 TRIBE_Campaign_Editor_Screen::make_campaign
// Source: scr_cam.cpp lines 388-457
// Attempt log:
// 1: initial reconstruction from packet/decompiler; uses /GX for RGE_Campaign new/dtor cleanup.
// 2: current source compiles but rebuilt .text is 560 bytes vs original 608; EH prologue is missing because placement-new/operator_new source did not induce VC5 cleanup state.
// 3: behavior/calls/stack buffers are broadly modeled, but code shape is far off: early invalid-name message block is laid inline instead of original tail block, and campaign construction/EH cleanup basin is wrong.
// 4: left in scratch; not accepted_drift-safe.

typedef unsigned int uint;
extern "C" void* __cdecl calloc(uint count, uint size);
extern "C" void __cdecl free(void* p);
extern "C" void* __cdecl operator_new(uint size);
extern "C" void __cdecl operator_delete(void* p);
extern "C" int __cdecl sprintf(char* buf, const char* fmt, ...);
extern "C" long __cdecl _findfirst(char* path, void* info);

extern "C" void __cdecl addstring(char** dst, char* src, char* ext);
extern "C" void __cdecl getstring(char** dst, char* src);

class TEditPanel { public: char* get_text(); };
class TTextPanel { public: int numberLines(); char* get_text(int i); };
class RGE_Base_Game { public: char gap[0x0C]; char* base_path; };
extern RGE_Base_Game* rge_base_game;

class RGE_Campaign {
public:
    RGE_Campaign(char* text, char** campaign_filename, int count, char** scenarios_text, char** scenarios_filenames);
    ~RGE_Campaign();
};

class TRIBE_Campaign_Editor_Screen {
public:
    char gap_000[0x478];
    unsigned char flag478;
    char gap_479[0x490 - 0x479];
    TTextPanel* list;
    char gap_494[0x49C - 0x494];
    TEditPanel* input;
    char gap_4A0[0x4C0 - 0x4A0];
    RGE_Campaign* campaign;

    void make_campaign();
    void message_box(int a, int b, int c, int d);
    void sub_48FBC0();
};

inline void* operator new(uint, void* p) { return p; }

void TRIBE_Campaign_Editor_Screen::make_campaign()
{
    char* text;
    char** campaign_filename;
    char** scenarios_text;
    char* saved_text;
    char test[260];
    char file_info[296];
    int count;

    text = 0;
    saved_text = this->input->get_text();
    if (saved_text == 0) {
        goto done;
    }
    if (*saved_text == 0 || *saved_text == ' ') {
        this->message_box(0x2BCC, 0, 0x1C2, 100);
        goto done_epilog;
    }

    addstring(&text, saved_text, (char*)".cpx");
    count = this->list->numberLines();
    if (count <= 0) {
        this->message_box(0x2BCB, 0, 0x1C2, 100);
    } else {
        campaign_filename = (char**)calloc(count, 4);
        scenarios_text = (char**)calloc(count, 4);
        for (int i = 0; i < count; ++i) {
            getstring(&campaign_filename[i], this->list->get_text(i));
            getstring(&scenarios_text[i], this->list->get_text(i));
            sprintf(test, (char*)"%s%s.scn", rge_base_game->base_path + 0xC17, scenarios_text[i]);
            if (_findfirst(test, file_info) == -1) {
                addstring(&scenarios_text[i], scenarios_text[i], (char*)".scx");
            } else {
                addstring(&scenarios_text[i], scenarios_text[i], (char*)".scn");
            }
        }
        RGE_Campaign* c = (RGE_Campaign*)operator_new(0x20C);
        if (c != 0) {
            c = new (c) RGE_Campaign(text, campaign_filename, count, scenarios_text, campaign_filename);
        } else {
            c = 0;
        }
        this->campaign = c;
        if (c != 0) {
            c->~RGE_Campaign();
            operator_delete(c);
        }
        this->campaign = 0;
        for (int j = 0; j < count; ++j) {
            free(scenarios_text[j]);
            free(campaign_filename[j]);
        }
        free(campaign_filename);
        free(scenarios_text);
    }

    free(text);
    this->sub_48FBC0();
    rge_base_game; // placeholder for call below in real source

done:
    this->flag478 = 0;
    return;

done_epilog:
    this->flag478 = 0;
}
