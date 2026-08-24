// TRIBE_Screen_Name::get_player_names
// VA: 004A6800
// Luna4A6800 pass: natural member reconstruction reaches 178B/178B, frame 8, saved EBX/EDI,
// all 7 direct calls, and 93.22% instruction-shape similarity; best remains 41 positional bytes,
// first mismatch +24 (the get_people_list out-parameter setup).
// Exact donor ABI corrections: get_people_list uses long& and append_line uses long; neither changed
// emitted bytes, but they restore the original external symbol identities. The full polymorphic
// TRIBE_Screen_Name surface is retained from same-TU exact donor setup_tab_order with name_list +480.
// Tried curr_player pointer casts, declaration/comma initialization, local/loop/temp/source-order
// variants, and a 27-case source lab plus 2048-case invariant-gated lab; all eligible variants stayed
// in the same 41-byte codegen basin. Remaining drift is setup LEA/store ordering plus append/free
// register coloring and get_line argument scheduling. Paused unresolved; not accepted_drift.
// orch-w8 pass: mirroring the exact same-family donor 004911A0 fillCampaigns (scr_cams.cpp) body
// shape: resolved RGE_Game_Info* info = rge_base_game->player_game_info local, char** players = 0
// declaration-with-initializer, long count declared at the call site, nested { int i; for(...) }
// loop blocks. That donor's original call-setup and loop bytes are identical to this target's, so
// the same source shape should reproduce the original register coloring and call-setup scheduling.
// Luna4A6800b sequential pass: restored canonical TPanel/TEasy_Panel/TScreenPanel inheritance,
// exact TRIBE_Screen_Name field ownership, TListPanel name_list type, and polymorphic RGE_Base_Game;
// aggregate-output, extern-global, /GX, source-order, and decompiler-curr_player probes were all
// unchanged or worse. Final normalized source remains the natural char** player-list form.

#ifdef SCR_NAME_TU_CONTEXT
#include "../../include/scr_name_context.h"
#else
extern "C" void __cdecl free(void*);

class TPanel {
public:
    char gap_04[0xEC];
    virtual ~TPanel();
};

class TTextPanel : public TPanel {
public:
    char gap_F0[0x6C];
    int flag_15c;
    void empty_list();
    int append_line(char* text, long index);
    long get_line(long line);
    void set_line(long line);
};

class TListPanel : public TTextPanel {
};

class TScrollBarPanel : public TPanel {
};

class TButtonPanel : public TPanel {
};

class RGE_Game_Info {
public:
    long get_people_list(char*** players, long& current_player);
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    RGE_Game_Info* player_game_info;
};

extern RGE_Base_Game* rge_base_game;

class TEasy_Panel : public TPanel {
public:
    char gap_F0[0x384];
};

class TScreenPanel : public TEasy_Panel {
public:
    char gap_474[4];
    virtual ~TScreenPanel();
};

class TRIBE_Screen_Name : public TScreenPanel {
public:
    TTextPanel* title;
    TTextPanel* name_text;
    TListPanel* name_list;
    TScrollBarPanel* name_scrollbar;
    TButtonPanel* new_button;
    TButtonPanel* remove_button;
    TButtonPanel* ok_button;
    TButtonPanel* cancel_button;
    TButtonPanel* close_button;
    int started_input;
    void get_player_names();
};
#endif

void TRIBE_Screen_Name::get_player_names()
{
    this->name_list->empty_list();

    RGE_Game_Info* info = rge_base_game->player_game_info;
    char** players = 0;
    long current_player;

    long count = info->get_people_list(&players, current_player);

    if (count != 0) {
        this->name_list->flag_15c = 1;

        {
            int i;
            for (i = 0; i < count; i++) {
                this->name_list->append_line(players[i], i);
            }
        }

        this->name_list->set_line(this->name_list->get_line(current_player));

        {
            int i;
            for (i = 0; i < count; i++) {
                free(players[i]);
            }
        }
        free(players);
    }
}
