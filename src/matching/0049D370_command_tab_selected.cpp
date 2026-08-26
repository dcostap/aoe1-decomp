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
// orch-w19 probe: the +10-byte drift is the peeled count check: do/while with a
// top `count >= selected_count` break makes VC5 fold count==0 into `test bp,bp;
// jle` at entry and re-test `cmp dx,bp` at the loop bottom (5 extra bytes per
// scan). Hypothesis: make `count < selected_count` the while-loop header test
// (back-edge targets the top test, as in the original `cmp dx,bp; jge done`)
// and keep `slot < 25` as a bottom break only.
// orch-w19 probe 2: while(count<sel_count) normalized to the same peeled IR
// (codegen duplicate). Mirror the exact same-file donor 0049D440
// (any_selected_have_action): write `while (slot < 25)` with the count test as
// the BODY's first statement (`if (count >= selected_count) break;`). VC5 then
// rotates to entry=count test (unfolded), bottom=slot test only.
// orch-w19: EXACT MATCH (diff=0) with the donor-mirrored loop shape. The count
// test must be a body first-statement inside `while (slot < 25)` (not the loop
// condition); the found-arm direct sel_list[slot] reload is binary-proven.
// Field sel_object_properties named from exact donor 004992E0.
// TU context gate: proved module scr_game.cpp, lines 5824-5876, with
// TRIBE_Screen_Game ownership.  Exact anchors are get_player at 0049D37A,
// get_paused at 0049D38B, and the two scan bodies through 0049D437.  The
// wrapper preserves the surrounding address sequence.  Standalone output is
// a 199-byte MATCH; the grouped candidate remains a 2-byte mismatch with
// owner, calls, relocations, and boundary correct.  Reduction moved candidate
// before found and produced a 2-byte register recolor, so the original order
// is restored.

#if !defined(SCR_GAME_TU_CONTEXT)
class RGE_Static_Object;

class RGE_Player {
public:
    char gap_00[0x130];
    RGE_Static_Object* selected_obj;
    RGE_Static_Object* sel_list[25];
    unsigned long sel_object_properties;
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
#endif

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
                while (slot < 25) {
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
                }
            } else {
                slot = 0;
                count = 0;
                while (slot < 25) {
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
                }
            }

            if (candidate != 0) {
            update_selected:
                player->selected_obj = candidate;
            }
        }
    }
}
