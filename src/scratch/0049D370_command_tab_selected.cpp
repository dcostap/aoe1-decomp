// VA: 0049D370 command_tab_selected
// Attempt log:
// baseline candidate: reconstruct the two selection scans with named RGE_Player
// ownership, short index/count locals, and the direct get_player/get_paused calls.
// probe: >= 2 preserves the original cmp bp,2 / jl guard (improved 116 -> 114).
// probe: value-nonzero scan first recovers the original je into the second scan
// and the common loop body (improved to 88 positional bytes).
// probe: int found reproduces EDI while candidate stays in EBX; short slot/count
// locals reproduce the 16-bit induction accesses. Direct reload of sel_list[slot]
// in the found-after-current arm is binary-supported but leaves a +10-byte size
// drift while aligning that arm; loop-guard variants did not change this basin.
// paused after the 10-hypothesis budget; final source below is the clean natural
// scan form with the binary-proven direct reload retained.

class RGE_Static_Object;

class RGE_Player {
public:
    char gap_00[0x130];
    RGE_Static_Object* selected_obj;
    RGE_Static_Object* sel_list[25];
    char gap_198[4];
    short sel_count;
};

class RGE_Base_Game {
public:
    RGE_Player* get_player(void);
    int get_paused(void);
};

extern RGE_Base_Game* rge_base_game;

class TRIBE_Screen_Game {
public:
    void command_tab_selected(int value);
};

void TRIBE_Screen_Game::command_tab_selected(int value) {
    RGE_Player* player = rge_base_game->get_player();
    int found = 0;
    RGE_Static_Object* candidate = 0;
    int paused = rge_base_game->get_paused();

    if (paused == 0) {
        short selected_count = player->sel_count;
        if (selected_count >= 2) {
            short slot;
            short count;
            if (value != 0) {
                slot = 0;
                count = 0;
                do {
                    if (count >= selected_count) {
                        break;
                    }
                    RGE_Static_Object* current = player->sel_list[slot];
                    if (current != 0) {
                        if (current == player->selected_obj) {
                            found = true;
                        } else {
                            if (found) {
                                candidate = player->sel_list[slot];
                                break;
                            }
                            if (candidate == 0) {
                                candidate = current;
                            }
                        }
                        ++count;
                    }
                    ++slot;
                } while (slot < 25);
            } else {
                slot = 0;
                count = 0;
                do {
                    if (count >= selected_count) {
                        break;
                    }
                    RGE_Static_Object* current = player->sel_list[slot];
                    if (current != 0) {
                        if (current == player->selected_obj) {
                            if (candidate != 0) {
                                goto update_selected;
                            }
                        } else {
                            candidate = current;
                        }
                        ++count;
                    }
                    ++slot;
                } while (slot < 25);
            }

            if (candidate != 0) {
            update_selected:
                player->selected_obj = candidate;
            }
        }
    }
}
