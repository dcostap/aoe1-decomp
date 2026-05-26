// TRIBE_Screen_Name::get_player_names
// VA: 004A6800
// Retry 2026-05-26 Boss pass: rebuilt source with real thiscall member surfaces and absolute rge_base_game.
// Revalidated best: 178B exact size, MISMATCH 41 positional / 41 edit, first mismatch +24.
// Tried 15 variants: players initialized at declaration (before/after empty_list), local order swaps,
// direct rge_base_game vs game local, casted/swapped get_people_list args, count as long, TTextPanel
// list local, text local before append_line, while/do loops, split get_line/set_line, comma assignment,
// and declaration-after-statement forms. Real member surface fixed compile and most calls, but remaining
// drift is broad scheduling/register order: get_people_list out-param LEAs/init ordering, append/free loop
// ECX/EDX/EAX coloring, and get_line argument push scheduling. GIVEUP; not accepted_drift without review.

extern "C" void __cdecl free(void*);

class TTextPanel {
public:
    char gap_00[0x15C];
    int flag_15c;
    void empty_list();
    int append_line(char* text, int index);
    long get_line(long line);
    void set_line(long line);
};

class RGE_Game_Info {
public:
    long get_people_list(char*** players, long* current_player);
};

class RGE_Base_Game {
public:
    void* vtable;
    RGE_Game_Info* player_game_info;
};

#define rge_base_game (*(RGE_Base_Game**)0x62C574)

class TRIBE_Screen_Name {
public:
    char gap_00[0x480];
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
    count = game->player_game_info->get_people_list(&players, &local_4);
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
