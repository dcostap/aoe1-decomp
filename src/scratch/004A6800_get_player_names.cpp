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

extern "C" void __cdecl free(void*);

class TTextPanel {
public:
    char gap_00[0x15C];
    int flag_15c;
    void empty_list();
    int append_line(char* text, long index);
    long get_line(long line);
    void set_line(long line);
};

class RGE_Game_Info {
public:
    long get_people_list(char*** players, long& current_player);
};

class RGE_Base_Game {
public:
    void* vtable;
    RGE_Game_Info* player_game_info;
};

#define rge_base_game (*(RGE_Base_Game**)0x62C574)

#define VPAD1(n) virtual void vpad##n();
#define VPAD2(n) VPAD1(n) VPAD1(n##_1)
#define VPAD4(n) VPAD2(n) VPAD2(n##_2)
#define VPAD8(n) VPAD4(n) VPAD4(n##_4)
#define VPAD16(n) VPAD8(n) VPAD8(n##_8)
#define VPAD32(n) VPAD16(n) VPAD16(n##_16)

class TRIBE_Screen_Name {
public:
    VPAD32(0)
    VPAD16(32)
    VPAD1(48)
    VPAD1(49)
    virtual void set_tab_order(void** panels, int count);
    char gap_04[0x47C];
    TTextPanel* name_list;
    void get_player_names();
};

void TRIBE_Screen_Name::get_player_names()
{
    char** players;
    long local_4;
    int count;
    int i;

    this->name_list->empty_list();

    RGE_Base_Game* game = rge_base_game;
    players = 0;
    count = game->player_game_info->get_people_list(&players, local_4);
    if (count != 0) {
        this->name_list->flag_15c = 1;

        for (i = 0; i < count; i++) {
            this->name_list->append_line(players[i], i);
        }

        this->name_list->set_line(this->name_list->get_line(local_4));

        for (i = 0; i < count; i++) {
            free(players[i]);
        }
        free(players);
    }
}
