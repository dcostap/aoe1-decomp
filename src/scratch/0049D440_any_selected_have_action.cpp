// scr_game.cpp:5882-5902, 101 bytes
// attempt 1: 81.2%, prolog too different (eax vs ecx, no ebp push)
// attempt 2: 77.2%, sel_count loaded early into ebp, extra test+jle
// attempt 3: 84.2%, sel_count inside loop worse
// attempt 4: 96 bytes, nested while+break too small
// attempt 5: 77.2%, int sel_count same as short
// BEST: 77.2% (attempts 2,5). Prolog matches (mov ecx + 4 pushes + call).
// BLOCKER: VC5 hoists sel_count load outside loop (into ebp), adds
//   early-exit test+jle guard, and uses ebp for sel_count (not eax).
//   Original loads sel_count inside loop each iteration via [ebp+19C].
//   23 bytes match; 78 bytes differ (mainly loop body shift from prolog diff).
extern void* rge_base_game;
extern void* __fastcall get_player(void* game);
extern unsigned char __fastcall have_action(void* obj);

class TRIBE_Screen_Game {
public:
    int any_selected_have_action();
};

int TRIBE_Screen_Game::any_selected_have_action() {
    void* player = get_player(rge_base_game);
    int sel_count = *(short*)((char*)player + 0x19C);
    void** sel_list = (void**)((char*)player + 0x134);
    int index = 0;
    int slot = 0;
    do {
        if (index >= sel_count) {
            return 0;
        }
        void* obj = sel_list[0];
        if (obj != 0) {
            unsigned char type = *(unsigned char*)((char*)(*(void**)((char*)obj + 8)) + 4);
            if (type > 0x27 && type < 0x51) {
                if (have_action(obj)) {
                    return 1;
                }
            }
            index++;
        }
        slot++;
        sel_list++;
    } while (slot < 0x19);
    return 0;
}
