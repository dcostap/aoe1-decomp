// VA: 00489F50 action (973B)
// PDB source: rpnl_tbx.cpp:180-306
// FLAGS: /GX is required by the binary-observed new-expression EH frame.
// Attempt log:
// - Initial scratch was an unrelated placeholder with the wrong signature and no
//   behavior. Reconstructed the typed panel/button/dialog ownership from the
//   same-TU constructor/destructor and executable field accesses.
// - Baseline: /GX source is 973 bytes with 25/25 ordered calls, exact frame and
//   97.28% exact-block coverage. Remaining drift starts at the late object-list
//   action check: the oracle reloads [esp+20] into EAX before cmp 1 and reuses
//   EAX for the common cmp 2; default VC5 chooses direct memory compares.
// - Tried late/top-level action-code aliases, an explicit dialog allocation
//   result local, register-qualified parameter use, and adding stdlib.h: all
//   emitted the same clean 311-byte positional diff (aliases are rolled back).
// - Diagnostic volatile parameter/home forms changed broad scheduling or size;
//   rolled back. A volatile late local improved diff by 10 bytes but added two
//   bytes and lost structural parity, so it is not retained.
// - Focused variant lab of natural/switch/negated/repeated/ternary late gates
//   found no invariant-eligible exact output; clean source remains authoritative.
// - Tried a branch-local typed long alias for the late action code; emitted code
//   was unchanged at 311 bytes, so restored the clean source.

#include <string.h>

class TPanel {
public:
    virtual ~TPanel();
    char gap_04[0xF0];

    char* panelName();
    char* get_string(int id);
};

class TScreenPanel : public TPanel {
public:
    long get_popup_info_id();
    char* get_popup_info_file();
};

class RGE_Game_World {
public:
    void* vtable_ptr;
    char gap_04[0x18];
    unsigned char temp_pause;
};

class RGE_Player {
public:
    void unselect_object();
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    virtual void vf04();
    virtual void vf08();
    virtual void set_prog_mode(int mode);
    virtual void set_game_mode(int mode, int sub_mode);

    char gap_14[0x1AC];
    int prog_mode;                         // +0x1B0
    int game_mode;                         // +0x1B4
    char gap_1B8[0x23C];
    RGE_Game_World* world;                 // +0x3F4
    int render_all;                        // +0x3F8
    short master_obj_id;                   // +0x3FC
    short terrain_id;                      // +0x3FE

    void delete_dialog(TPanel** dialog);
    RGE_Player* get_player();
};

class RGE_Dialog_List : public TPanel {
public:
    virtual ~RGE_Dialog_List();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3C();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4C();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5C();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void vf6C();
    virtual void vf70();
    virtual void vf74();
    virtual void vf78();
    virtual void vf7C();
    virtual void vf80();
    virtual void vf84();
    virtual void vf88();
    virtual void vf8C();
    virtual void vf90();
    virtual void vf94();
    virtual void vf98();
    virtual void vf9C();
    virtual void vfA0();
    virtual void vfA4();
    virtual void vfA8();
    virtual void vfAC();
    virtual void vfB0();
    virtual void vfB4();
    virtual void vfB8();
    virtual void vfBC();
    virtual void vfC0();
    virtual void vfC4();
    virtual void vfC8();
    virtual void vfCC();
    virtual void vfD0();
    virtual void vfD4();
    virtual void vfD8();
    virtual void vfDC();
    virtual void vfE0();
    virtual void vfE4();
    virtual void vfE8();
    virtual void vfEC();
    virtual void vfF0();
    virtual void vfF4();
    virtual void vfF8();
    virtual void vfFC();
    virtual void vf100();
    virtual void vf104();
    virtual void vf108();
    virtual void vf10C();
    virtual void vf110();
    virtual void vf114();
    virtual void vf118();
    virtual void vf11C();
    virtual void vf120();
    virtual void vf124();
    virtual void vf128();
    virtual void vf12C();
    virtual short get_cur_id();            // vtable +0x130

    char gap_F4[0x3B8];
    int list_type;
    short list_size;
    short list_line;
    void* list_info;
    char** list_text;

    RGE_Dialog_List(char* name);
    int setup(TScreenPanel* screen, char* popup_file, long popup_id,
              int list_type, char* title);
};

class RGE_Panel_Tool_Box : public TPanel {
public:
    virtual ~RGE_Panel_Tool_Box();
    TScreenPanel* screen_panel;             // +0xF4
    void* view;                             // +0xF8
    void* map;                              // +0xFC
    TPanel* game_mode_button;               // +0x100
    TPanel* object_mode_button;             // +0x104
    TPanel* delete_mode_button;             // +0x108
    TPanel* move_mode_button;               // +0x10C
    TPanel* terrain_mode_button;            // +0x110
    TPanel* elevation_mode_button;          // +0x114
    TPanel* command_button;                // +0x118
    TPanel* dialog;                         // +0x11C

    void game_mode_changed(int mode, int new_mode);
    virtual long action(TPanel* panel, long code,
                        unsigned long param_3, unsigned long param_4);
};

extern RGE_Base_Game* rge_base_game;
extern char s_Object_List_Dialog[];
extern char s_Terrain_List_Dialog[];

long RGE_Panel_Tool_Box::action(TPanel* panel, long code,
                                unsigned long param_3, unsigned long param_4)
{
    if (panel != 0) {
        if ((panel == this->game_mode_button) && (code == 1)) {
            rge_base_game->set_game_mode(0, 0);
            return 1;
        }

        if ((panel == this->object_mode_button) && (code == 1)) {
            this->dialog = new RGE_Dialog_List(s_Object_List_Dialog);
            if (this->dialog != 0) {
                if (((RGE_Dialog_List*)this->dialog)->setup(
                        this->screen_panel,
                        this->screen_panel->get_popup_info_file(),
                        this->screen_panel->get_popup_info_id(),
                        1,
                        this->get_string(0x232A)) == 0) {
                    delete this->dialog;
                    this->dialog = 0;
                }
            }
            return 1;
        }
        else {
            if ((panel == this->move_mode_button) && (code == 1)) {
                rge_base_game->set_game_mode(0x12, 0);
                return 1;
            }
            if ((panel == this->delete_mode_button) && (code == 1)) {
                rge_base_game->set_game_mode(0x0E, 0);
                return 1;
            }
            if ((panel == this->elevation_mode_button) && (code == 1)) {
                rge_base_game->set_game_mode(3, 0);
                return 1;
            }
            if ((panel == this->command_button) && (code == 1)) {
                if (rge_base_game->prog_mode == 4) {
                    rge_base_game->set_prog_mode(6);
                    rge_base_game->world->temp_pause = 1;
                    return 1;
                }
                rge_base_game->set_prog_mode(4);
                return 1;
            }

            TPanel** dialog = &this->dialog;
            if (panel != *dialog) {
                return 0;
            }

            if (strcmp((*dialog)->panelName(), s_Object_List_Dialog) == 0) {
                if (code == 1) {
                    rge_base_game->master_obj_id =
                        ((RGE_Dialog_List*)*dialog)->get_cur_id();
                    rge_base_game->delete_dialog(dialog);
                    rge_base_game->set_game_mode(1, 0);
                    rge_base_game->get_player()->unselect_object();
                    return 1;
                }
            }
            else if (strcmp((*dialog)->panelName(), s_Terrain_List_Dialog) == 0) {
                if (code == 1) {
                    rge_base_game->terrain_id =
                        ((RGE_Dialog_List*)*dialog)->get_cur_id();
                    rge_base_game->delete_dialog(dialog);
                    rge_base_game->set_game_mode(2, 0);
                    return 1;
                }
            }

            if (code == 2) {
                rge_base_game->delete_dialog(dialog);
                this->game_mode_changed(rge_base_game->game_mode,
                                        rge_base_game->game_mode);
            }
        }
        return 1;
    }
    return 0;
}
