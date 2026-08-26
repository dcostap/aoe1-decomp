// VA: 00524150 TRIBE_Game::quit_game (582 B)
// PDB source: tribegam.cpp (lines 1642-1733)
// Attempt log:
// baseline: replaced the free-function scaffold with the period-typed quit
// flow from the executable: lobby/world notification, multiplayer disconnect,
// campaign selection, testing-scenario editor, menu, and join-screen paths.
// control-flow: made the second singlePlayerGame test independent and split
// direct finish jumps from the common panel cleanup; this reduced the emitted
// drift to 18 bytes before local/layout probes.
// layout: scenario_dir at RGE_Prog_Info+0xC17 and direct temp-buffer ownership
// removed the decompiler-only +4 cursor, yielding 12 bytes of localized drift.
// liveness/control-flow probes (rolled back): declaration reordering, explicit
// return, moving the common testing flag clear before destroyPanel, and placing
// the clear before the finish label did not improve the 12-byte suffix gap;
// the latter two changed size/CFG and were restored.
// liveness (rolled back): function-scoped join-screen pointer preserved the
// same 582-byte output and did not move the common flag store before EH restore.
// liveness (rolled back): bare new expression, label-scope cleanup, and a
// volatile testing field were codegen-neutral; the pointer-based clean source
// remains the better reconstruction.
// control-flow (rolled back): direct returns or an epilogue label after the
// final flag store changed size/CFG; original direct jumps skip that store.
// revisit: the original +0193/+01C2 jumps land after the common clear, while
// fall-through cleanup stores the flag before EH restore; explicit labels,
// natural returns, and common-clear variants moved the whole 582-byte basin.
// abi/context (rolled back): removing the virtual destructor changed the new
// size to 0x4AC; an equivalent virtual slot and explicit operator-new decl.
// kept the 0x4B0 allocation but did not move the 12-byte EH tail gap.
// exact-finish revisit (rolled back): putting the common clear before the
// finish label, with function-scope, bare-new, nested-scope, or reverse-label
// variants, grew the function to 623 bytes and 213 differing bytes. A direct
// scenario-editor return grew it to 601 bytes and 191 differing bytes. The
// clean 582-byte source remains the smallest supported reconstruction.
// ACCEPTED DRIFT: Two changed bytes are branch displacements to the same
// reviewed cleanup destinations. The remaining edit exchanges the final
// testing-scenario byte store with the independent saved-SEH-chain stack load.
// The FS restore still occurs later at the same address. No call, branch, or
// faulting memory dependency intervenes. Values, writes, cleanup, and calls match.

extern "C" int __cdecl sprintf(char* buffer, const char* format, ...);
extern "C" long __cdecl _findfirst(const char* filespec, void* fileinfo);

extern int do_debug_random;
extern void debug_random_write();
extern void dump_vismap_log();

#include "../../include/tribegam_context.h"

void TRIBE_Game::quit_game()
{
    unsigned char campaign = 0;
    char temp_test_scenario[260];
    char file_info[0x118];

    if (this->comm_handler->IsLobbyLaunched() != 0 && this->world != 0) {
        this->world->send_zone_score_info();
    }

    this->disconnect_multiplayer_game();
    this->prog_mode = 0;

    if (do_debug_random != 0) {
        debug_random_write();
        dump_vismap_log();
    }

    if (this->singlePlayerGame() == 1) {
        if (this->world != 0 && this->world->campaign > -1) {
            if (this->game_info->set_current_person(this->world->person) != 0 &&
                this->game_info->set_current_campaign(this->world->campaign) != 0) {
                campaign = 1;
            }
        }

    }

    if (this->world != 0) {
        this->world->del_game_info();
    }

    if (this->singlePlayerGame() == 1) {
        if (campaign != 0) {
            if (this->start_campaign_menu() == 0) {
                this->close();
            }
        } else {
            if (this->testing_scenario[0] != 0) {
                this->close_game_screens(0);
                this->game_screen = 0;
                panel_system.destroyPanel("Game Screen");

                sprintf(temp_test_scenario, "%s%s.scn",
                        this->prog_info->scenario_dir,
                        this->testing_scenario);
                if (_findfirst(temp_test_scenario, file_info) == -1) {
                    sprintf(temp_test_scenario, "%s.scx",
                            this->testing_scenario);
                } else {
                    sprintf(temp_test_scenario, "%s.scn",
                            this->testing_scenario);
                }
                this->testing_scenario[0] = 0;
                if (this->start_scenario_editor(temp_test_scenario, 0) != 0) {
                    this->testing_scenario[0] = 0;
                    goto quit_game_finish;
                }
            }

            if (this->start_menu() == 0) {
                this->close();
            }
        }
    } else {
        if (this->comm_handler->IsLobbyLaunched() != 0) {
            this->close();
            goto quit_game_finish;
        }

        TribeJoinScreen* join_screen = new TribeJoinScreen;
        panel_system.setCurrentPanel("Join Screen", 0);
        this->set_prog_mode(2);
    }

quit_game_common:
    this->close_game_screens(0);
    this->game_screen = 0;
    panel_system.destroyPanel("Game Screen");

quit_game_finish:
    this->testing_scenario[0] = 0;
    return;
}
