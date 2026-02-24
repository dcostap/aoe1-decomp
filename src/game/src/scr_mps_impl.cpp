#include "../include/TribeMPSetupScreen.h"
#include "../include/TribeGameSettingsScreen.h"
#include "../include/TribeSPMenuScreen.h"
#include "../include/RGE_Base_Game.h"
#include "../include/TRIBE_Game.h"
#include "../include/TChat.h"
#include "../include/TTextPanel.h"
#include "../include/TButtonPanel.h"
#include "../include/TDropDownPanel.h"
#include "../include/RGE_Scenario.h"
#include "../include/T_Scenario.h"
#include "../include/TCommunications_Handler.h"
#include "../include/TEasy_Panel.h"
#include "../include/custom_debug.h"
#include "../include/debug_helpers.h"
#include "../include/globals.h"
#include "../include/TDebuggingLog.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <io.h>

namespace {

static int mps_clamp(int value, int lo, int hi) {
    if (value < lo) return lo;
    if (value > hi) return hi;
    return value;
}

static const char* mps_get_string_safe(TribeMPSetupScreen* owner, int resid, const char* fallback, char* out, size_t out_size) {
    if (!out || out_size == 0) return "";
    out[0] = '\0';
    if (owner) {
        owner->get_string(resid, out, (int)out_size);
    } else if (rge_base_game) {
        rge_base_game->get_string(resid, out, (int)out_size);
    }
    if (out[0] == '\0' && fallback) {
        strncpy(out, fallback, out_size - 1);
        out[out_size - 1] = '\0';
    }
    return out;
}

static int mps_map_size_resid(int map_size) {
    switch (map_size) {
    case 0: return 0x2973; // Tiny
    case 1: return 0x2974; // Small
    case 2: return 0x2975; // Medium
    case 3: return 0x2976; // Large
    case 4: return 0x2977; // Huge
    case 5: return 0x2978; // Gigantic
    default: return -1;
    }
}

static int mps_map_type_resid(int map_type) {
    switch (map_type) {
    case 0: return 0x296a; // All Water
    case 1: return 0x296b; // Mostly Water
    case 2: return 0x296c; // Water and Land
    case 3: return 0x296d; // Mostly Land
    case 4: return 0x296e; // All Land
    case 5: return 0x296f; // Continental
    case 6: return 0x2970; // Lake
    case 7: return 0x2971; // Hilly
    case 8: return 0x2972; // Narrows
    default: return -1;
    }
}

static int mps_civ_resid(int civ_id) {
    switch (civ_id) {
    case 1: return 0x27f7;
    case 2: return 0x27f8;
    case 3: return 0x27f9;
    case 4: return 0x27fa;
    case 5: return 0x27fb;
    case 6: return 0x27fc;
    case 7: return 0x27fd;
    case 8: return 0x27fe;
    case 9: return 0x27ff;
    case 10: return 0x2800;
    case 11: return 0x2801;
    case 12: return 0x2802;
    case 13: return 0x2806;
    case 14: return 0x2807;
    case 15: return 0x2809;
    case 16: return 0x2808;
    case 17: return 0x280a; // Random
    default: return -1;
    }
}

static int mps_victory_resid(int victory_type) {
    switch (victory_type) {
    case 0: return 0x10e1; // Conquest
    case 2: return 0x10e9; // Time
    case 3: return 0x10ea; // Score
    default: return 0x10ec; // Standard
    }
}

static void mps_set_text(TTextPanel* panel, const char* text) {
    if (!panel) return;
    panel->set_text((char*)(text ? text : ""));
}

static void mps_set_button_text(TButtonPanel* panel, const char* text) {
    if (!panel) return;
    panel->set_text((short)0, (char*)(text ? text : ""));
}

static int mps_civ_to_line(int civ_id) {
    int v = mps_clamp(civ_id, 1, 17);
    return v - 1;
}

static unsigned long mps_player_color_rgb(int color_index) {
    switch (color_index) {
    case 0: return 0xff0000;
    case 1: return 0x0000ff;
    case 2: return 0x00ffff;
    case 3: return 0x284673;
    case 4: return 0x0764f0;
    case 5: return 0x00ff00;
    case 6: return 0xb4b4b4;
    case 7: return 0x93bf2b;
    default: return 0xffffff;
    }
}

static int mps_button_state_index(TButtonPanel* button) {
    if (!button) {
        return 0;
    }

    int state = (int)button->cur_state;
    const int state_count = (int)button->num_states;
    if (state_count <= 0) {
        return 0;
    }
    if (state < 0) {
        state = 0;
    }
    if (state >= state_count) {
        state = state_count - 1;
    }
    return state;
}

static long mps_button_state_id(TButtonPanel* button) {
    if (!button) {
        return 0;
    }
    const int state = mps_button_state_index(button);
    return button->id[state];
}

static const char* mps_button_state_text(TButtonPanel* button) {
    if (!button) {
        return "";
    }
    const int state = mps_button_state_index(button);
    const char* text = button->text1[state];
    return text ? text : "";
}

static unsigned long mps_button_state_color(TButtonPanel* button) {
    if (!button) {
        return 0x00ffffff;
    }
    const int state = mps_button_state_index(button);
    return button->text_color1[state];
}

static void mps_button_set_state_by_id(TButtonPanel* button, long id) {
    if (!button) {
        return;
    }
    const int state_count = (int)button->num_states;
    if (state_count <= 0) {
        button->set_state(0);
        return;
    }

    for (int state = 0; state < state_count; ++state) {
        if (button->id[state] == id) {
            button->set_state((short)state);
            return;
        }
    }
    button->set_state(0);
}

static void mps_button_set_disabled(TButtonPanel* button, int disabled) {
    if (!button) {
        return;
    }
    button->disabled = disabled;
}

static int mps_comm_is_player_ready(TCommunications_Handler* comm_handler, uint player_number) {
    if (comm_handler == nullptr || player_number >= 10) {
        return 0;
    }
    return (comm_handler->PlayerOptions.PlayerReady[player_number] != 0) ? 1 : 0;
}

static long mps_dropdown_find_line_by_id(TDropDownPanel* drop, long id) {
    if (!drop || !drop->list_panel) {
        return 0;
    }

    TTextPanel* list = (TTextPanel*)drop->list_panel;
    const int lines = list->numberLines();
    for (int i = 0; i < lines; ++i) {
        if (list->get_id(i) == id) {
            return i;
        }
    }
    return 0;
}

static const char* mps_dropdown_current_text(TDropDownPanel* drop) {
    if (!drop || !drop->list_panel) {
        return "";
    }

    TTextPanel* list = (TTextPanel*)drop->list_panel;
    const long line = list->get_line();
    char* text = list->get_text(line);
    return text ? text : "";
}

static int mps_team_value_to_state(int team_value) {
    int v = team_value;
    if (v > 0x31) {
        v -= 0x32;
    }
    if (v < 1) {
        v = 1;
    }
    if (v > 5) {
        v = 5;
    }
    return v - 1;
}

static void mps_fill_player_colors(TribeMPSetupScreen* owner) {
    if (!owner || !rge_base_game) {
        return;
    }

    const int scenario_game = (int)rge_base_game->rge_game_options.scenarioGameValue;
    const int single_player = (rge_base_game->rge_game_options.multiplayerGameValue == 0);
    RGE_Scenario* scenario = (RGE_Scenario*)owner->scenarioInfo;

    for (int row = 0; row < 8; ++row) {
        TButtonPanel* button = owner->playerColor[row];
        if (!button) {
            continue;
        }

        int state_count = 0;
        for (int color_idx = 0; color_idx < 8; ++color_idx) {
            int allow = 1;
            if (scenario_game && scenario) {
                allow = scenario->PlActive[color_idx];
                if (allow && single_player) {
                    allow = (scenario->PlType[color_idx] == 1);
                }
            }

            if (!allow) {
                continue;
            }

            char color_text[16];
            sprintf(color_text, "%d", color_idx + 1);
            button->set_text((short)state_count, color_text);
            button->set_id((short)state_count, color_idx + 1, 0);
            button->text_color1[state_count] = mps_player_color_rgb(color_idx);
            button->text_color2[state_count] = 0;
            button->highlight_text_color1[state_count] = mps_player_color_rgb(color_idx);
            button->highlight_text_color2[state_count] = 0;
            ++state_count;
        }

        if (state_count <= 0) {
            state_count = 1;
            button->set_text((short)0, "1");
            button->set_id((short)0, 1, 0);
            button->text_color1[0] = mps_player_color_rgb(0);
            button->text_color2[0] = 0;
            button->highlight_text_color1[0] = mps_player_color_rgb(0);
            button->highlight_text_color2[0] = 0;
        }
        button->set_state_info(state_count);
    }
}

static void mps_fill_number_players(TribeMPSetupScreen* owner) {
    if (!owner || !owner->numberPlayersDrop || !rge_base_game) {
        return;
    }

    owner->numberPlayersDrop->empty_list();

    int max_players = owner->scenarioPlayerCount;
    if (max_players < 2 || max_players > 8) {
        max_players = 8;
    }

    for (int players = 2; players <= max_players; ++players) {
        char text[16];
        sprintf(text, "%d", players);
        owner->numberPlayersDrop->append_line(text, players);
    }

    int number_players = (int)rge_base_game->rge_game_options.numberPlayersValue;
    number_players = mps_clamp(number_players, 2, max_players);
    const long line = mps_dropdown_find_line_by_id(owner->numberPlayersDrop, number_players);
    owner->numberPlayersDrop->set_line(line);
}

static void mps_update_player_rows(TribeMPSetupScreen* owner) {
    if (!owner || !rge_base_game) return;
    TRIBE_Game* game = (TRIBE_Game*)rge_base_game;

    int max_players = owner->scenarioPlayerCount;
    if (max_players < 2 || max_players > 8) {
        max_players = 8;
    }
    int number_players = mps_clamp((int)rge_base_game->rge_game_options.numberPlayersValue, 2, max_players);
    if ((int)rge_base_game->rge_game_options.numberPlayersValue != number_players) {
        rge_base_game->setNumberPlayers(number_players);
    }

    const int single_player = (rge_base_game->rge_game_options.multiplayerGameValue == 0);
    mps_fill_player_colors(owner);

    if (single_player && owner->numberPlayersDrop) {
        const long line = mps_dropdown_find_line_by_id(owner->numberPlayersDrop, number_players);
        owner->numberPlayersDrop->set_line(line);
    }

    for (int i = 0; i < 8; ++i) {
        const int active = (i < number_players) ? 1 : 0;
        int humanity = (i == 0) ? 2 : 4; // Human/Computer ids used by original comm-humanity flow.
        if (!active) {
            humanity = 0; // Absent
        } else if (single_player && i > 0 && owner->playerNameDrop[i]) {
            humanity = (int)owner->playerNameDrop[i]->get_id();
        }

        // Source-of-truth: scr_mps.cpp.asm (fillPlayers, 0x004A3B95 / 0x004A3CA9 / 0x004A3F88).
        // SP has different enable rules per column:
        // - Civ/Team: local player OR computer slots are interactive.
        // - Color: only local player is interactive, and only when at least two scenario-eligible players exist.
        const int allow_civ_team_controls = (active && (i == 0 || humanity == 4)) ? 1 : 0;
        const int allow_color_control = (active && (i == 0) && (owner->numberAnyPlayers > 1)) ? 1 : 0;
        const int show_civ_team_read_only = (active && (humanity == 2 || humanity == 4)) ? 1 : 0;
        const int show_color_read_only = (active && (humanity == 2)) ? 1 : 0;

        if (single_player) {
            if (owner->playerNameDrop[i]) owner->playerNameDrop[i]->set_active(0);
            if (owner->playerNameText[i]) owner->playerNameText[i]->set_active(active);

            if (owner->playerCivDrop[i]) owner->playerCivDrop[i]->set_active(0);
            if (owner->playerCivText[i]) owner->playerCivText[i]->set_active(0);
            if (owner->playerColor[i]) owner->playerColor[i]->set_active(0);
            if (owner->playerColorText[i]) owner->playerColorText[i]->set_active(0);
            if (owner->playerTeam[i]) owner->playerTeam[i]->set_active(0);
            if (owner->playerTeamText[i]) owner->playerTeamText[i]->set_active(0);

            if (allow_civ_team_controls) {
                if (owner->playerCivDrop[i]) owner->playerCivDrop[i]->set_active(1);
                if (owner->playerTeam[i]) {
                    owner->playerTeam[i]->set_active(1);
                    owner->playerTeam[i]->disabled = 0;
                }
            } else if (show_civ_team_read_only) {
                if (owner->playerCivText[i]) owner->playerCivText[i]->set_active(1);
                if (owner->playerTeamText[i]) owner->playerTeamText[i]->set_active(1);
            }

            if (allow_color_control) {
                if (owner->playerColor[i]) {
                    owner->playerColor[i]->set_active(1);
                    owner->playerColor[i]->disabled = 0;
                }
            } else if (show_color_read_only) {
                if (owner->playerColorText[i]) owner->playerColorText[i]->set_active(1);
            }
        } else {
            if (owner->playerNameDrop[i]) owner->playerNameDrop[i]->set_active(active);
            if (owner->playerNameText[i]) owner->playerNameText[i]->set_active(active);
            if (owner->playerCivDrop[i]) owner->playerCivDrop[i]->set_active(active);
            if (owner->playerCivText[i]) owner->playerCivText[i]->set_active(active);
            if (owner->playerColor[i]) {
                owner->playerColor[i]->set_active(active);
                if (active) {
                    owner->playerColor[i]->disabled = 0;
                }
            }
            if (owner->playerColorText[i]) owner->playerColorText[i]->set_active(active);
            if (owner->playerTeam[i]) {
                owner->playerTeam[i]->set_active(active);
                if (active) {
                    owner->playerTeam[i]->disabled = 0;
                }
            }
            if (owner->playerTeamText[i]) owner->playerTeamText[i]->set_active(active);
        }

        if (owner->scenarioPlayerDrop[i]) owner->scenarioPlayerDrop[i]->set_active(0);
        if (owner->scenarioPlayerText[i]) owner->scenarioPlayerText[i]->set_active(0);
        if (owner->playerCDText[i]) owner->playerCDText[i]->set_active(0);
        if (owner->playerVersionText[i]) owner->playerVersionText[i]->set_active(0);

        if (!active) {
            mps_set_text(owner->playerNameText[i], "");
            mps_set_text(owner->playerCivText[i], "");
            mps_set_text(owner->playerColorText[i], "");
            mps_set_text(owner->playerTeamText[i], "");
            continue;
        }

        char name_text[128];
        if (i == 0) {
            mps_get_string_safe(owner, 0x25b3, "You", name_text, sizeof(name_text));
        } else {
            const char* current = mps_dropdown_current_text(owner->playerNameDrop[i]);
            if (single_player && humanity == 0) {
                mps_get_string_safe(owner, 0x25d6, "None", name_text, sizeof(name_text));
            } else if (single_player && humanity == 4) {
                mps_get_string_safe(owner, 0x25d3, "Computer", name_text, sizeof(name_text));
            } else if (current && current[0] != '\0') {
                strncpy(name_text, current, sizeof(name_text) - 1);
                name_text[sizeof(name_text) - 1] = '\0';
            } else {
                mps_get_string_safe(owner, 0x25d3, "Computer", name_text, sizeof(name_text));
            }
        }
        name_text[sizeof(name_text) - 1] = '\0';
        mps_set_text(owner->playerNameText[i], name_text);

        if (single_player && i > 0 && owner->playerNameDrop[i]) {
            const long line = mps_dropdown_find_line_by_id(owner->playerNameDrop[i], humanity);
            owner->playerNameDrop[i]->set_line(line);
        }

        int civ_id = (int)game->tribe_game_options.civilizationValue[i];
        if (civ_id > 0x31) {
            civ_id -= 0x32;
        }
        civ_id = mps_clamp(civ_id, 1, 17);
        if (owner->playerCivDrop[i] && owner->playerCivDrop[i]->mode != TDropDownPanel::ModeList) {
            const long line = mps_dropdown_find_line_by_id(owner->playerCivDrop[i], civ_id);
            owner->playerCivDrop[i]->set_line(line);
        }

        const char* civ_text = mps_dropdown_current_text(owner->playerCivDrop[i]);
        if (civ_text && civ_text[0] != '\0') {
            mps_set_text(owner->playerCivText[i], civ_text);
        } else {
            char civ_fallback[128];
            const int civ_resid = mps_civ_resid(civ_id);
            if (civ_resid >= 0) {
                mps_get_string_safe(owner, civ_resid, "Random", civ_fallback, sizeof(civ_fallback));
            } else {
                mps_get_string_safe(owner, 0x280a, "Random", civ_fallback, sizeof(civ_fallback));
            }
            mps_set_text(owner->playerCivText[i], civ_fallback);
        }

        int color_id = (int)game->tribe_game_options.playerColorValue[i];
        color_id = mps_clamp(color_id, 1, 8);
        if (owner->playerColor[i]) {
            mps_button_set_state_by_id(owner->playerColor[i], color_id);
        }
        mps_set_text(owner->playerColorText[i], mps_button_state_text(owner->playerColor[i]));
        if (owner->playerColorText[i]) {
            owner->playerColorText[i]->set_text_color(mps_button_state_color(owner->playerColor[i]), 0);
        }

        int team_state = mps_team_value_to_state((int)rge_base_game->rge_game_options.playerTeamValue[i]);
        if (owner->playerTeam[i]) {
            owner->playerTeam[i]->set_state((short)team_state);
        }
        mps_set_text(owner->playerTeamText[i], mps_button_state_text(owner->playerTeam[i]));
    }
}

static void mps_update_option_buttons(TribeMPSetupScreen* owner) {
    if (!owner || !rge_base_game) return;
    TRIBE_Game* game = (TRIBE_Game*)rge_base_game;

    char value[256];
    char fmt[256];
    char line[320];

    // NOTE: The temporary cycle buttons (hiddenMapButton, ready_button, readyButtons, netInfoButton)
    // have been removed to match the original scr_mps behavior. 
    // Settings are now changed via the Settings button or the new player row controls.
    (void)owner; (void)game; (void)value; (void)fmt; (void)line;
}

static void mps_update_summary(TribeMPSetupScreen* owner) {
    if (!owner || !rge_base_game) return;
    TRIBE_Game* game = (TRIBE_Game*)rge_base_game;

    char value[256];
    char fmt[256];
    char line[320];

    const int scenario_game = (int)rge_base_game->rge_game_options.scenarioGameValue;
    const int single_player = (rge_base_game->rge_game_options.multiplayerGameValue == 0);
    if (scenario_game && owner->scenarioInfo) {
        RGE_Scenario* scenario = (RGE_Scenario*)owner->scenarioInfo;
        int scenario_players = 0;
        int any_players = 0;
        for (int i = 0; i < 9; ++i) {
            if (!scenario->PlActive[i]) {
                continue;
            }
            ++scenario_players;
            if (!single_player || scenario->PlType[i] == 1) {
                ++any_players;
            }
        }
        if (scenario_players < 2) {
            scenario_players = 2;
        }
        if (scenario_players > 8) {
            scenario_players = 8;
        }
        owner->scenarioPlayerCount = scenario_players;
        owner->numberAnyPlayers = any_players;
    } else if (!scenario_game) {
        owner->scenarioPlayerCount = 8;
        owner->numberAnyPlayers = 8;
    }

    const int line_base = scenario_game ? 3 : 1;

    if (scenario_game) {
        mps_get_string_safe(owner, 0x25ed, "Scenario: %s", fmt, sizeof(fmt));
        snprintf(line, sizeof(line), fmt, rge_base_game->rge_game_options.scenarioNameValue);
    } else {
        const int scenario_name = (game->tribe_game_options.deathMatchValue != 0) ? 0x2617 : 0x25b5;
        mps_get_string_safe(owner, scenario_name, "Random Map", value, sizeof(value));
        mps_get_string_safe(owner, 0x25ed, "Scenario: %s", fmt, sizeof(fmt));
        snprintf(line, sizeof(line), fmt, value);
    }
    line[sizeof(line) - 1] = '\0';
    mps_set_text(owner->scenarioName, line);

    for (int i = 0; i < 20; ++i) {
        mps_set_text(owner->settingText[i], "");
    }

    int line_idx = line_base;

    if (scenario_game == 0) {
        const int map_size_resid = mps_map_size_resid((int)game->tribe_game_options.mapSizeValue);
        if (map_size_resid >= 0) mps_get_string_safe(owner, map_size_resid, "Medium", value, sizeof(value));
        else strncpy(value, "Medium", sizeof(value) - 1);
        value[sizeof(value) - 1] = '\0';
        mps_get_string_safe(owner, 0x25da, "Map Size: %s", fmt, sizeof(fmt));
        snprintf(line, sizeof(line), fmt, value);
        line[sizeof(line) - 1] = '\0';
        mps_set_text(owner->settingText[line_idx++], line);

        const int map_type_resid = mps_map_type_resid((int)game->tribe_game_options.mapTypeValue);
        if (map_type_resid >= 0) mps_get_string_safe(owner, map_type_resid, "Inland", value, sizeof(value));
        else strncpy(value, "Inland", sizeof(value) - 1);
        value[sizeof(value) - 1] = '\0';
        mps_get_string_safe(owner, 0x25b6, "Map Type: %s", fmt, sizeof(fmt));
        snprintf(line, sizeof(line), fmt, value);
        line[sizeof(line) - 1] = '\0';
        mps_set_text(owner->settingText[line_idx++], line);
    }

    int max_players = owner->scenarioPlayerCount;
    if (max_players < 2 || max_players > 8) {
        max_players = 8;
    }
    mps_get_string_safe(owner, 0x25b7, "Players:", fmt, sizeof(fmt));
    snprintf(line, sizeof(line), "%s %d", fmt, mps_clamp((int)rge_base_game->rge_game_options.numberPlayersValue, 2, max_players));
    line[sizeof(line) - 1] = '\0';
    mps_set_text(owner->settingText[line_idx++], line);

    const int victory_type = (int)game->tribe_game_options.victoryTypeValue;
    mps_get_string_safe(owner, mps_victory_resid(victory_type), "Standard", value, sizeof(value));
    if (victory_type == 2 || victory_type == 3) {
        mps_get_string_safe(owner, 0x25be, "Victory: %s (%d)", fmt, sizeof(fmt));
        snprintf(line, sizeof(line), fmt, value, (int)game->tribe_game_options.victoryAmountValue);
    } else {
        mps_get_string_safe(owner, 0x25bc, "Victory: %s", fmt, sizeof(fmt));
        snprintf(line, sizeof(line), fmt, value);
    }
    line[sizeof(line) - 1] = '\0';
    mps_set_text(owner->settingText[line_idx++], line);

    int age_resid = 0x10e7; // Default
    if ((int)game->tribe_game_options.startingAgeValue == 5) {
        age_resid = 0x106e; // Nomad
    } else if ((int)game->tribe_game_options.startingAgeValue > 0) {
        age_resid = 0x1067 + (int)game->tribe_game_options.startingAgeValue;
    }
    mps_get_string_safe(owner, age_resid, "Default", value, sizeof(value));
    mps_get_string_safe(owner, 0x25e4, "Age: %s", fmt, sizeof(fmt));
    snprintf(line, sizeof(line), fmt, value);
    line[sizeof(line) - 1] = '\0';
    mps_set_text(owner->settingText[line_idx++], line);

    if ((int)game->tribe_game_options.resourceLevelValue == 0) {
        mps_get_string_safe(owner, 0x10e7, "Default", value, sizeof(value));
    } else {
        mps_get_string_safe(owner, 0x25e5 + (int)game->tribe_game_options.resourceLevelValue, "Default", value, sizeof(value));
    }
    mps_get_string_safe(owner, 0x25e5, "Resources: %s", fmt, sizeof(fmt));
    snprintf(line, sizeof(line), fmt, value);
    line[sizeof(line) - 1] = '\0';
    mps_set_text(owner->settingText[line_idx++], line);

    mps_get_string_safe(owner, 0x2bd0 + (int)rge_base_game->rge_game_options.difficultyValue, "Hardest", value, sizeof(value));
    mps_get_string_safe(owner, 0x25e0, "Difficulty Level: %s", fmt, sizeof(fmt));
    snprintf(line, sizeof(line), fmt, value);
    line[sizeof(line) - 1] = '\0';
    mps_set_text(owner->settingText[line_idx++], line);

    mps_get_string_safe(owner, game->tribe_game_options.randomizePositionsValue ? 0xfa4 : 0xfa3, game->tribe_game_options.randomizePositionsValue ? "No" : "Yes", value, sizeof(value));
    mps_get_string_safe(owner, 0x25e9, "Fixed Positions: %s", fmt, sizeof(fmt));
    snprintf(line, sizeof(line), fmt, value);
    line[sizeof(line) - 1] = '\0';
    mps_set_text(owner->settingText[line_idx++], line);

    mps_get_string_safe(owner, rge_base_game->rge_game_options.fullVisibilityValue ? 0xfa3 : 0xfa4, rge_base_game->rge_game_options.fullVisibilityValue ? "Yes" : "No", value, sizeof(value));
    mps_get_string_safe(owner, 0x25b8, "Reveal Map: %s", fmt, sizeof(fmt));
    snprintf(line, sizeof(line), fmt, value);
    line[sizeof(line) - 1] = '\0';
    mps_set_text(owner->settingText[line_idx++], line);

    mps_get_string_safe(owner, game->tribe_game_options.fullTechTreeValue ? 0xfa3 : 0xfa4, game->tribe_game_options.fullTechTreeValue ? "Yes" : "No", value, sizeof(value));
    mps_get_string_safe(owner, 0x25ec, "Full Tech Tree: %s", fmt, sizeof(fmt));
    snprintf(line, sizeof(line), fmt, value);
    line[sizeof(line) - 1] = '\0';
    mps_set_text(owner->settingText[line_idx++], line);

    mps_get_string_safe(owner, 0x260e + (int)rge_base_game->pathFindingValue, "Medium", value, sizeof(value));
    mps_get_string_safe(owner, 0x25f1, "Path Finding: %s", fmt, sizeof(fmt));
    snprintf(line, sizeof(line), fmt, value);
    line[sizeof(line) - 1] = '\0';
    mps_set_text(owner->settingText[line_idx++], line);

    mps_get_string_safe(owner, 0x25f0, "Population Limit: %d", fmt, sizeof(fmt));
    snprintf(line, sizeof(line), fmt, (int)game->tribe_game_options.popLimitValue);
    line[sizeof(line) - 1] = '\0';
    mps_set_text(owner->settingText[line_idx++], line);

    if (rge_base_game->rge_game_options.multiplayerGameValue == 0) {
        const int show_number_players =
            (scenario_game == 0) || ((owner->settingsFixed == 0) && (owner->scenarioPlayerCount > 2));
        if (owner->numberPlayersTitle) {
            owner->numberPlayersTitle->set_active(show_number_players);
        }
        if (owner->numberPlayersDrop) {
            owner->numberPlayersDrop->set_active(show_number_players);
        }
    }
}

static void mps_refresh_ui(TribeMPSetupScreen* owner) {
    mps_update_summary(owner);
    if (owner && rge_base_game && (rge_base_game->rge_game_options.multiplayerGameValue == 0)) {
        mps_fill_number_players(owner);
    }
    mps_update_player_rows(owner);
    mps_update_option_buttons(owner);
}

void mps_enable_input() {
    if (!rge_base_game) return;
    rge_base_game->enable_input();
}

static int mps_ensure_multiplayer_comm() {
    if (!rge_base_game || rge_base_game->multiplayerGame() == 0) {
        return 1;
    }

    if (rge_base_game->comm_handler != nullptr && comm == nullptr) {
        comm = rge_base_game->comm_handler;
    }

    if (rge_base_game->comm_handler == nullptr || comm == nullptr) {
        if (rge_base_game->reset_comm() == 0) {
            return 0;
        }
    }

    if (rge_base_game->comm_handler != nullptr && comm == nullptr) {
        comm = rge_base_game->comm_handler;
    }

    return (rge_base_game->comm_handler != nullptr && comm != nullptr) ? 1 : 0;
}

void mps_popup_resid(TribeMPSetupScreen* owner, int resid, const char* fallback) {
    char text[512];
    text[0] = '\0';
    if (owner) {
        owner->get_string(resid, text, sizeof(text));
    } else if (rge_base_game) {
        rge_base_game->get_string(resid, text, sizeof(text));
    }

    if (text[0] == '\0') {
        if (fallback && fallback[0] != '\0') {
            strncpy(text, fallback, sizeof(text) - 1);
            text[sizeof(text) - 1] = '\0';
        } else {
            sprintf(text, "Missing UI string %d", resid);
        }
    }

    TEasy_Panel* panel = nullptr;
    if (owner) {
        panel = (TEasy_Panel*)owner;
    } else if (panel_system && panel_system->currentPanelValue) {
        panel = dynamic_cast<TEasy_Panel*>(panel_system->currentPanelValue);
    }
    if (panel) {
        panel->popupOKDialog((char*)text, (char*)0, 0x1c2, 100);
    }
}

void mps_popup_text(const char* text) {
    const char* safe = (text && text[0] != '\0') ? text : "No message.";
    TEasy_Panel* panel = (panel_system && panel_system->currentPanelValue)
        ? dynamic_cast<TEasy_Panel*>(panel_system->currentPanelValue)
        : nullptr;
    if (panel) {
        panel->popupOKDialog((char*)safe, (char*)0, 0x1c2, 100);
    }
}

} // namespace

// Fully verified. Source of truth: scr_mps.cpp.asm @ 0x004A5210
void TribeMPSetupScreen::setupSinglePlayerPlayers() {
    if (rge_base_game == nullptr) {
        return;
    }

    TRIBE_Game* game = (TRIBE_Game*)rge_base_game;

    if (rge_base_game->scenarioGame() == 0) {
        int i = 0;
        do {
            int r = debug_rand("C:\\msdev\\work\\age1_x1\\scr_mps.cpp", 0xb31);
            int s = r >> 0x1f;
            r = r ^ s;
            r = r - s;
            r = r & 0xf;
            r = r ^ s;
            r = r - s;
            r = r + 1;

            game->setCivilization(i, r);
            game->setPlayerColor(i, i + 1);
            ++i;
        } while (i < 8);
    } else {
        int first_any_player = -1; // scenario player index
        int first_any_civ = -1;    // civ id
        int first_any_color = -1;  // color id (scenario idx + 1)

        if (this->scenarioInfo != nullptr) {
            int slot = 0;
            for (int scen_player = 0; scen_player < 9; ++scen_player) {
                if (((RGE_Scenario*)this->scenarioInfo)->Get_player_Active(scen_player) == 0) {
                    continue;
                }

                game->setScenarioPlayer(slot, scen_player);
                int civ = ((RGE_Scenario*)this->scenarioInfo)->Get_player_Civ(scen_player);
                game->setCivilization(slot, civ);
                game->setPlayerColor(slot, scen_player + 1);

                if (((RGE_Scenario*)this->scenarioInfo)->Get_player_Type(scen_player) == 1 && first_any_player == -1) {
                    first_any_player = scen_player;
                    first_any_civ = civ;
                    first_any_color = scen_player + 1;
                }

                ++slot;
            }
        }

        rge_base_game->setNumberPlayers(this->scenarioPlayerCount);

        if (first_any_player != -1) {
            if (1 < this->scenarioPlayerCount) {
                for (int i = 1; i < this->scenarioPlayerCount; ++i) {
                    if (game->tribe_game_options.scenarioPlayerValue[i] == first_any_player) {
                        const int old_scen = game->tribe_game_options.scenarioPlayerValue[0];
                        const int old_civ = (int)game->tribe_game_options.civilizationValue[0];
                        const int old_color = (int)game->tribe_game_options.playerColorValue[0];

                        game->setScenarioPlayer(i, old_scen);
                        game->setCivilization(i, old_civ);
                        game->setPlayerColor(i, old_color);
                        break;
                    }
                }
            }

            game->setScenarioPlayer(0, first_any_player);
            game->setCivilization(0, first_any_civ);
            game->setPlayerColor(0, first_any_color);
        }
    }

    for (int i = 0; i < 8; ++i) {
        rge_base_game->setPlayerTeam(i, 1);
    }

    if (comm != nullptr) {
        TCommunications_Handler* comm_handler = (TCommunications_Handler*)comm;
        comm_handler->SetPlayerHumanity(1, 2);
        for (uint player = 2; player <= 8; ++player) {
            comm_handler->SetPlayerHumanity(player, 4);
        }
        comm_handler->SetPlayerHumanity(9, 0);
    }

    mps_fill_number_players(this);
}

// Fully verified. Source of truth: scr_mps.cpp.asm @ 0x004A37D0
void TribeMPSetupScreen::fillPlayers() {
    if (rge_base_game == nullptr) {
        return;
    }

    TRIBE_Game* game = (TRIBE_Game*)rge_base_game;
    TCommunications_Handler* comm_handler = (TCommunications_Handler*)comm;

    if (rge_base_game->multiplayerGame() != 0 && comm_handler != nullptr && comm_handler->IsHost() != 0) {
        int changed = 0;
        const int num_players = rge_base_game->numberPlayers();
        for (int i = 0; i < num_players; ++i) {
            const uint player_num = (uint)(i + 1);
            if (mps_comm_is_player_ready(comm_handler, player_num) != 0 &&
                this->playerNameText[i] != nullptr &&
                this->playerNameText[i]->text_color1 == 0xff) {

                for (int j = 0; j < num_players; ++j) {
                    if (i == j) {
                        continue;
                    }

                    if (mps_comm_is_player_ready(comm_handler, (uint)(j + 1)) == 0) {
                        continue;
                    }

                    const int color_j = game->playerColor(j);
                    const int color_i = game->playerColor(i);
                    if (color_j == color_i) {
                        if (L != nullptr) {
                            L->Log("$$$ SETTING CIV/TEAM+50 (%d,%d)", i, j);
                        }
                        const int civ = game->civilization(i);
                        game->setCivilization(j, civ + 0x32);

                        const int team = rge_base_game->playerTeam(i);
                        rge_base_game->setPlayerTeam(j, team + 0x32);
                        changed = 1;
                    }
                }
            }
        }

        if (changed != 0) {
            rge_base_game->send_game_options();
        }
    }

    const int num_players = rge_base_game->numberPlayers();
    for (int slot = 0; slot < num_players; ++slot) {
        int humanity = 0;
        int is_me = 0;

        if (rge_base_game->multiplayerGame() != 0 && comm_handler != nullptr) {
            humanity = comm_handler->GetPlayerHumanity((uint)(slot + 1));
            is_me = (comm_handler->WhoAmI() == (uint)(slot + 1)) ? 1 : 0;
        } else {
            if (slot == 0) {
                humanity = 2;
                is_me = 1;
            } else if (this->playerNameDrop[slot] != nullptr) {
                humanity = (int)this->playerNameDrop[slot]->get_id();
            } else {
                humanity = 0;
            }
            is_me = 0;
        }

        // CD + version indicators are only shown for human players in multiplayer.
        if (rge_base_game->multiplayerGame() == 0 || humanity != 2) {
            if (this->playerCDText[slot]) this->playerCDText[slot]->set_active(0);
            if (this->playerVersionText[slot]) this->playerVersionText[slot]->set_active(0);
        } else {
            if (this->playerCDText[slot]) {
                this->playerCDText[slot]->set_active(rge_base_game->playerHasCD(slot));
            }

            int show_version = 0;
            if (comm_handler != nullptr && comm_handler->IsHost() != 0) {
                show_version = 1;
            } else if (rge_base_game->playerVersion(0) != 0) {
                show_version = 1;
            }

            if (show_version != 0) {
                if (this->playerVersionText[slot]) {
                    this->playerVersionText[slot]->set_text((char*)rge_base_game->playerVersionString(slot));
                    this->playerVersionText[slot]->set_active(1);
                }
            } else if (slot == 0) {
                if (this->playerVersionText[0]) {
                    this->playerVersionText[0]->set_text((char*)rge_base_game->playerVersionString(0));
                    this->playerVersionText[0]->set_active(1);
                }
            } else if (is_me != 0) {
                rge_base_game->setPlayerVersion(slot, 1);
                if (this->playerVersionText[slot]) {
                    this->playerVersionText[slot]->set_text((char*)rge_base_game->playerVersionString(slot));
                    this->playerVersionText[slot]->set_active(1);
                }
            } else {
                if (this->playerVersionText[slot]) this->playerVersionText[slot]->set_active(0);
            }
        }

        // Player color button/text.
        int color_id = 0;
        if (is_me != 0 && this->myPlayerColor != 0) {
            color_id = this->myPlayerColor;
        } else {
            color_id = game->playerColor(slot);
        }
        if (this->playerColor[slot]) {
            mps_button_set_state_by_id(this->playerColor[slot], color_id);
        }
        if (this->playerColorText[slot]) {
            this->playerColorText[slot]->set_text((char*)mps_button_state_text(this->playerColor[slot]));
            this->playerColorText[slot]->set_text_color(mps_button_state_color(this->playerColor[slot]), 0);
        }
        if (this->playerColor[slot]) this->playerColor[slot]->set_active(0);
        if (this->playerColorText[slot]) this->playerColorText[slot]->set_active(0);

        if (((rge_base_game->multiplayerGame() != 0) && (is_me != 0) && (this->i_am_ready == 0)) ||
            ((rge_base_game->singlePlayerGame() != 0) && (is_me != 0) && (1 < this->numberAnyPlayers))) {
            if (this->playerColor[slot]) {
                this->playerColor[slot]->set_active(1);
                mps_button_set_disabled(this->playerColor[slot], 0);
            }
        } else if (humanity == 2) {
            if (this->playerColorText[slot]) this->playerColorText[slot]->set_active(1);
        }

        // Player team button/text.
        if (this->playerTeam[slot]) {
            if (is_me != 0 && this->myPlayerTeam != 0) {
                this->playerTeam[slot]->set_state((short)(this->myPlayerTeam - 1));
            } else {
                int team = rge_base_game->playerTeam(slot);
                if (team > 0x31) {
                    team -= 0x32;
                }
                this->playerTeam[slot]->set_state((short)(team - 1));
            }
        }
        if (this->playerTeamText[slot]) {
            this->playerTeamText[slot]->set_text((char*)mps_button_state_text(this->playerTeam[slot]));
        }
        if (this->playerTeam[slot]) this->playerTeam[slot]->set_active(0);
        if (this->playerTeamText[slot]) this->playerTeamText[slot]->set_active(0);

        if (((rge_base_game->multiplayerGame() != 0) &&
            (((is_me != 0) && (this->i_am_ready == 0)) ||
             (comm_handler != nullptr && comm_handler->IsHost() != 0 && humanity == 4 && this->i_am_ready == 0))) ||
            ((rge_base_game->singlePlayerGame() != 0) && ((is_me != 0) || (humanity == 4)))) {
            if (this->playerTeam[slot]) {
                this->playerTeam[slot]->set_active(1);
                mps_button_set_disabled(this->playerTeam[slot], 0);
            }
        } else if (humanity == 2 || humanity == 4) {
            if (this->playerTeamText[slot]) this->playerTeamText[slot]->set_active(1);
        }

        // Name text coloring (ready state) in multiplayer.
        if (rge_base_game->multiplayerGame() != 0 && comm_handler != nullptr) {
            unsigned long color = 0xff00;
            if (humanity == 2 && mps_comm_is_player_ready(comm_handler, (uint)(slot + 1)) == 0) {
                color = 0xff;
            }
            if (this->playerNameDrop[slot]) {
                this->playerNameDrop[slot]->set_val_text_color(color, 0);
            }
            if (this->playerNameText[slot]) {
                this->playerNameText[slot]->set_text_color(color, 0);
            }
        }

        // Player name UI.
        if (rge_base_game->multiplayerGame() == 0) {
            if (slot == 0) {
                if (this->playerNameText[0]) {
                    this->playerNameText[0]->set_text(0x25b3); // "You"
                }
            } else if (this->playerNameText[slot] && this->playerNameDrop[slot]) {
                this->playerNameText[slot]->set_text((char*)mps_dropdown_current_text(this->playerNameDrop[slot]));
            }
        } else if (this->playerNameDrop[slot] && this->playerNameText[slot] && comm_handler != nullptr) {
            if (this->playerNameDrop[slot]->get_id(0) == 2) {
                if (this->playerNameDrop[slot]->list_panel) {
                    ((TTextPanel*)this->playerNameDrop[slot]->list_panel)->delete_line(0);
                }
            }

            if (humanity == 2) {
                const char* name = comm_handler->GetPlayerName((uint)(slot + 1));
                if (this->playerNameDrop[slot]->list_panel) {
                    ((TTextPanel*)this->playerNameDrop[slot]->list_panel)->insert_line(0, (char*)(name ? name : ""), 2);
                }
            }

            const long line = this->playerNameDrop[slot]->get_line((long)humanity);
            this->playerNameDrop[slot]->set_line(line);
            this->playerNameText[slot]->set_text((char*)mps_dropdown_current_text(this->playerNameDrop[slot]));
        }

        // Civilization UI.
        if (this->playerCivDrop[slot] && this->playerCivDrop[slot]->mode != TDropDownPanel::ModeList) {
            int civ = 0;
            if (is_me != 0 && this->myCivilization != 0) {
                civ = this->myCivilization;
            } else {
                civ = game->civilization(slot);
                if (civ > 0x31) {
                    civ -= 0x32;
                }
            }
            this->playerCivDrop[slot]->set_line(this->playerCivDrop[slot]->get_line(civ));
        }
        if (this->playerCivText[slot] && this->playerCivDrop[slot]) {
            this->playerCivText[slot]->set_text((char*)mps_dropdown_current_text(this->playerCivDrop[slot]));
        }

        // Scenario player UI.
        if (this->scenarioPlayerDrop[slot] && this->scenarioPlayerDrop[slot]->mode != TDropDownPanel::ModeList) {
            int scen = -1;
            if (is_me != 0 && this->myScenarioPlayer != -1) {
                scen = this->myScenarioPlayer;
            } else {
                scen = game->tribe_game_options.scenarioPlayerValue[slot];
            }
            this->scenarioPlayerDrop[slot]->set_line(this->scenarioPlayerDrop[slot]->get_line(scen));
        }
        if (this->scenarioPlayerText[slot] && this->scenarioPlayerDrop[slot]) {
            this->scenarioPlayerText[slot]->set_text((char*)mps_dropdown_current_text(this->scenarioPlayerDrop[slot]));
        }

        // Enable/disable dropdowns vs text mirrors.
        if ((rge_base_game->multiplayerGame() == 0) ||
            (comm_handler == nullptr) ||
            (comm_handler->IsHost() == 0) ||
            (is_me != 0)) {
            if (this->playerNameDrop[slot]) this->playerNameDrop[slot]->set_active(0);
            if (this->playerNameText[slot]) this->playerNameText[slot]->set_active(1);
        } else {
            if (this->playerNameDrop[slot]) this->playerNameDrop[slot]->set_active(1);
            if (this->playerNameText[slot]) this->playerNameText[slot]->set_active(0);
        }

        if (this->playerCivDrop[slot]) this->playerCivDrop[slot]->set_active(0);
        if (this->playerCivText[slot]) this->playerCivText[slot]->set_active(0);
        if (((rge_base_game->multiplayerGame() != 0) &&
            (((is_me != 0) && (this->i_am_ready == 0)) ||
             (comm_handler != nullptr && comm_handler->IsHost() != 0 && humanity == 4 && this->i_am_ready == 0))) ||
            ((rge_base_game->singlePlayerGame() != 0) && ((is_me != 0) || (humanity == 4)))) {
            if (this->playerCivDrop[slot]) this->playerCivDrop[slot]->set_active(1);
        } else if (humanity == 2 || humanity == 4) {
            if (this->playerCivText[slot]) this->playerCivText[slot]->set_active(1);
        }

        if (this->scenarioPlayerDrop[slot]) this->scenarioPlayerDrop[slot]->set_active(0);
        if (this->scenarioPlayerText[slot]) this->scenarioPlayerText[slot]->set_active(0);
    }

    // Hide unused rows (beyond numberPlayers).
    for (int row = num_players; row < 8; ++row) {
        if (this->playerNameDrop[row]) this->playerNameDrop[row]->set_active(0);
        if (this->playerNameText[row]) this->playerNameText[row]->set_active(0);
        if (this->playerCivDrop[row]) this->playerCivDrop[row]->set_active(0);
        if (this->playerCivText[row]) this->playerCivText[row]->set_active(0);
        if (this->scenarioPlayerDrop[row]) this->scenarioPlayerDrop[row]->set_active(0);
        if (this->scenarioPlayerText[row]) this->scenarioPlayerText[row]->set_active(0);
        if (this->playerColor[row]) this->playerColor[row]->set_active(0);
        if (this->playerColorText[row]) this->playerColorText[row]->set_active(0);
        if (this->playerTeam[row]) this->playerTeam[row]->set_active(0);
        if (this->playerTeamText[row]) this->playerTeamText[row]->set_active(0);
        if (this->playerCDText[row]) this->playerCDText[row]->set_active(0);
        if (this->playerVersionText[row]) this->playerVersionText[row]->set_active(0);
    }

    mps_fill_player_colors(this);
}

// Fully verified. Source of truth: scr_mps.cpp.asm @ 0x004A4190
void TribeMPSetupScreen::updateSummary() {
    if (rge_base_game == nullptr) {
        return;
    }

    TRIBE_Game* game = (TRIBE_Game*)rge_base_game;

    char str1[256];
    char str2[256];
    char file_name[260];
    char str3[256];
    _finddata_t file_info;

    str1[0] = '\0';
    str2[0] = '\0';
    file_name[0] = '\0';
    str3[0] = '\0';

    int reload = 0;
    const int scenario_game = rge_base_game->scenarioGame();
    const int prev_random = this->saveRandomGame;

    if (scenario_game == 0) {
        if (prev_random == 0) {
            reload = 1;
        }
    } else {
        if (prev_random == 0) {
            if (strcmp(this->saveScenarioName, rge_base_game->scenarioName()) != 0) {
                reload = 1;
            }
        } else {
            reload = 1;
        }
    }

    if (reload != 0) {
        if (rge_base_game->scenarioGame() != 0) {
            if (this->scenarioInfo != nullptr) {
                delete this->scenarioInfo;
                this->scenarioInfo = nullptr;
            }

            const char* scen_name = rge_base_game->scenarioName();
            const char* scen_dir = (rge_base_game->prog_info != nullptr) ? rge_base_game->prog_info->scenario_dir : "";
            sprintf(file_name, "%s%s.scn", scen_dir, scen_name ? scen_name : "");
            if (_findfirst(file_name, &file_info) == -1) {
                sprintf(str1, "%s.scx", scen_name ? scen_name : "");
            } else {
                sprintf(str1, "%s.scn", scen_name ? scen_name : "");
            }

            if (str1[0] != '.') {
                this->scenarioInfo = (T_Scenario*)rge_base_game->get_scenario_info(str1, 0);
            }

            if (this->scenarioInfo == nullptr) {
                rge_base_game->setScenarioGame(0);
            } else {
                for (int i = 0; i < 8; ++i) {
                    if (this->scenarioPlayerDrop[i]) {
                        this->scenarioPlayerDrop[i]->empty_list();
                    }
                }

                this->settingsFixed = ((T_Scenario*)this->scenarioInfo)->any_sp_victory();
                this->numberAnyPlayers = 0;
                this->scenarioPlayerCount = 0;

                for (int scen_player = 0; scen_player < 9; ++scen_player) {
                    if (((RGE_Scenario*)this->scenarioInfo)->Get_player_Active(scen_player) == 0) {
                        continue;
                    }

                    this->scenarioPlayerCount = this->scenarioPlayerCount + 1;
                    sprintf(str2, "%d", scen_player + 1);

                    int allow_any = 0;
                    if (rge_base_game->multiplayerGame() != 0) {
                        allow_any = 1;
                    } else if (rge_base_game->singlePlayerGame() != 0 &&
                               ((RGE_Scenario*)this->scenarioInfo)->Get_player_Type(scen_player) == 1) {
                        allow_any = 1;
                    }

                    if (allow_any != 0) {
                        this->numberAnyPlayers = this->numberAnyPlayers + 1;
                        for (int i = 0; i < 8; ++i) {
                            if (this->scenarioPlayerDrop[i]) {
                                this->scenarioPlayerDrop[i]->append_line(str2, scen_player);
                            }
                        }
                    }
                }

                int scen_index = -1;
                for (int slot = 0; slot < 8; ++slot) {
                    int active = 0;
                    do {
                        scen_index = scen_index + 1;
                        if (scen_index == 9) {
                            scen_index = 0;
                        }
                        active = ((RGE_Scenario*)this->scenarioInfo)->Get_player_Active(scen_index);
                    } while (active == 0);

                    this->defaultColor[slot] = (unsigned char)(scen_index + 1);
                    game->setScenarioPlayer(slot, scen_index);
                    game->setPlayerColor(slot, (uint)this->defaultColor[slot]);
                    rge_base_game->setPlayerTeam(slot, 1);
                }
            }
        }

        if (rge_base_game->randomGame() != 0) {
            for (int i = 0; i < 8; ++i) {
                if (this->scenarioPlayerDrop[i]) {
                    this->scenarioPlayerDrop[i]->empty_list();
                }
            }

            this->scenarioPlayerCount = 8;
            this->numberAnyPlayers = 8;
            this->settingsFixed = 0;

            for (int i = 0; i < 8; ++i) {
                this->defaultColor[i] = (unsigned char)(i + 1);
                game->setScenarioPlayer(i, i);
                game->setPlayerColor(i, (uint)this->defaultColor[i]);
                rge_base_game->setPlayerTeam(i, 1);

                sprintf(str2, "%d", (int)this->defaultColor[i]);
                for (int drop = 0; drop < 8; ++drop) {
                    if (this->scenarioPlayerDrop[drop]) {
                        this->scenarioPlayerDrop[drop]->append_line(str2, i);
                    }
                }
            }
        }

        if (rge_base_game->singlePlayerGame() != 0) {
            this->setupSinglePlayerPlayers();
        }

        this->saveRandomGame = rge_base_game->randomGame();
        if (this->saveRandomGame == 0) {
            strncpy(this->saveScenarioName, rge_base_game->scenarioName(), sizeof(this->saveScenarioName) - 1);
            this->saveScenarioName[sizeof(this->saveScenarioName) - 1] = '\0';
        } else {
            this->saveScenarioName[0] = '\0';
        }

        for (int i = 0; i < 8; ++i) {
            this->scenarioCheckSum[i] = 0;
        }

        if (rge_base_game->scenarioGame() == 0) {
            this->myScenarioChecksum = 0;
        } else {
            const char* scen_name = rge_base_game->scenarioName();
            const char* scen_dir = (rge_base_game->prog_info != nullptr) ? rge_base_game->prog_info->scenario_dir : "";
            sprintf(file_name, "%s%s.scn", scen_dir, scen_name ? scen_name : "");
            if (_findfirst(file_name, &file_info) == -1) {
                sprintf(file_name, "%s.scx", scen_name ? scen_name : "");
            } else {
                sprintf(file_name, "%s.scn", scen_name ? scen_name : "");
            }
            this->myScenarioChecksum = rge_base_game->get_scenario_checksum(file_name);
        }
    }

    for (int i = 0; i < 20; ++i) {
        if (this->settingText[i]) {
            this->settingText[i]->set_active(0);
        }
    }

    // Scenario name line + base index.
    int base_index = 1;
    if (rge_base_game->scenarioGame() == 0) {
        const int scen_resid = (game->deathMatch() != 0) ? 0x2617 : 0x25b5;
        mps_get_string_safe(this, scen_resid, "Random Map", str1, sizeof(str1));
        mps_get_string_safe(this, 0x25ed, "Scenario: %s", str2, sizeof(str2));
        snprintf(str3, sizeof(str3), str2, str1);
        str3[sizeof(str3) - 1] = '\0';
        mps_set_text(this->scenarioName, str3);
        base_index = 1;
    } else {
        mps_get_string_safe(this, 0x25ed, "Scenario: %s", str2, sizeof(str2));
        snprintf(str3, sizeof(str3), str2, rge_base_game->scenarioName());
        str3[sizeof(str3) - 1] = '\0';
        mps_set_text(this->scenarioName, str3);
        base_index = 3;
    }

    int idx = base_index;

    // Random-map-only entries.
    if (rge_base_game->randomGame() != 0) {
        char value[256];
        char fmt[256];
        char line[320];

        const int map_size_resid = mps_map_size_resid((int)game->tribe_game_options.mapSizeValue);
        mps_get_string_safe(this, (map_size_resid >= 0) ? map_size_resid : 0x2975, "Medium", value, sizeof(value));
        mps_get_string_safe(this, 0x25da, "Map Size: %s", fmt, sizeof(fmt));
        snprintf(line, sizeof(line), fmt, value);
        line[sizeof(line) - 1] = '\0';
        mps_set_text(this->settingText[idx], line);
        if (this->settingText[idx]) this->settingText[idx]->set_active(1);
        ++idx;

        const int map_type_resid = mps_map_type_resid((int)game->tribe_game_options.mapTypeValue);
        mps_get_string_safe(this, (map_type_resid >= 0) ? map_type_resid : 0x296d, "Mostly Land", value, sizeof(value));
        mps_get_string_safe(this, 0x25b6, "Map Type: %s", fmt, sizeof(fmt));
        snprintf(line, sizeof(line), fmt, value);
        line[sizeof(line) - 1] = '\0';
        mps_set_text(this->settingText[idx], line);
        if (this->settingText[idx]) this->settingText[idx]->set_active(1);
        ++idx;
    }

    // Players.
    {
        char fmt[256];
        char line[320];
        int max_players = (rge_base_game->scenarioGame() != 0) ? this->scenarioPlayerCount : 8;
        if (max_players < 2 || max_players > 8) {
            max_players = 8;
        }
        const int players = mps_clamp((int)rge_base_game->rge_game_options.numberPlayersValue, 2, max_players);
        mps_get_string_safe(this, 0x25b7, "Players:", fmt, sizeof(fmt));
        snprintf(line, sizeof(line), "%s %d", fmt, players);
        line[sizeof(line) - 1] = '\0';
        mps_set_text(this->settingText[idx], line);
        if (this->settingText[idx]) this->settingText[idx]->set_active(1);
        ++idx;
    }

    // Victory.
    {
        char value[256];
        char fmt[256];
        char line[320];
        const int victory_type = (int)game->tribe_game_options.victoryTypeValue;
        mps_get_string_safe(this, mps_victory_resid(victory_type), "Standard", value, sizeof(value));
        if (victory_type == 2 || victory_type == 3) {
            mps_get_string_safe(this, 0x25be, "Victory: %s (%d)", fmt, sizeof(fmt));
            snprintf(line, sizeof(line), fmt, value, (int)game->tribe_game_options.victoryAmountValue);
        } else {
            mps_get_string_safe(this, 0x25bc, "Victory: %s", fmt, sizeof(fmt));
            snprintf(line, sizeof(line), fmt, value);
        }
        line[sizeof(line) - 1] = '\0';
        mps_set_text(this->settingText[idx], line);
        if (this->settingText[idx]) this->settingText[idx]->set_active(1);
        ++idx;
    }

    // Age.
    {
        char value[256];
        char fmt[256];
        char line[320];
        int age_resid = 0x10e7;
        if ((int)game->tribe_game_options.startingAgeValue == 5) {
            age_resid = 0x106e;
        } else if ((int)game->tribe_game_options.startingAgeValue > 0) {
            age_resid = 0x1067 + (int)game->tribe_game_options.startingAgeValue;
        }
        mps_get_string_safe(this, age_resid, "Default", value, sizeof(value));
        mps_get_string_safe(this, 0x25e4, "Age: %s", fmt, sizeof(fmt));
        snprintf(line, sizeof(line), fmt, value);
        line[sizeof(line) - 1] = '\0';
        mps_set_text(this->settingText[idx], line);
        if (this->settingText[idx]) this->settingText[idx]->set_active(1);
        ++idx;
    }

    // Resources.
    {
        char value[256];
        char fmt[256];
        char line[320];
        if ((int)game->tribe_game_options.resourceLevelValue == 0) {
            mps_get_string_safe(this, 0x10e7, "Default", value, sizeof(value));
        } else {
            mps_get_string_safe(this, 0x25e5 + (int)game->tribe_game_options.resourceLevelValue, "Default", value, sizeof(value));
        }
        mps_get_string_safe(this, 0x25e5, "Resources: %s", fmt, sizeof(fmt));
        snprintf(line, sizeof(line), fmt, value);
        line[sizeof(line) - 1] = '\0';
        mps_set_text(this->settingText[idx], line);
        if (this->settingText[idx]) this->settingText[idx]->set_active(1);
        ++idx;
    }

    // Difficulty.
    {
        char value[256];
        char fmt[256];
        char line[320];
        mps_get_string_safe(this, 0x2bd0 + (int)rge_base_game->rge_game_options.difficultyValue, "Hardest", value, sizeof(value));
        mps_get_string_safe(this, 0x25e0, "Difficulty Level: %s", fmt, sizeof(fmt));
        snprintf(line, sizeof(line), fmt, value);
        line[sizeof(line) - 1] = '\0';
        mps_set_text(this->settingText[idx], line);
        if (this->settingText[idx]) this->settingText[idx]->set_active(1);
        ++idx;
    }

    // Fixed Positions.
    {
        char value[256];
        char fmt[256];
        char line[320];
        mps_get_string_safe(this, game->tribe_game_options.randomizePositionsValue ? 0xfa4 : 0xfa3,
            game->tribe_game_options.randomizePositionsValue ? "No" : "Yes", value, sizeof(value));
        mps_get_string_safe(this, 0x25e9, "Fixed Positions: %s", fmt, sizeof(fmt));
        snprintf(line, sizeof(line), fmt, value);
        line[sizeof(line) - 1] = '\0';
        mps_set_text(this->settingText[idx], line);
        if (this->settingText[idx]) this->settingText[idx]->set_active(1);
        ++idx;
    }

    // Reveal Map.
    {
        char value[256];
        char fmt[256];
        char line[320];
        mps_get_string_safe(this, rge_base_game->rge_game_options.fullVisibilityValue ? 0xfa3 : 0xfa4,
            rge_base_game->rge_game_options.fullVisibilityValue ? "Yes" : "No", value, sizeof(value));
        mps_get_string_safe(this, 0x25b8, "Reveal Map: %s", fmt, sizeof(fmt));
        snprintf(line, sizeof(line), fmt, value);
        line[sizeof(line) - 1] = '\0';
        mps_set_text(this->settingText[idx], line);
        if (this->settingText[idx]) this->settingText[idx]->set_active(1);
        ++idx;
    }

    // Full Tech Tree.
    {
        char value[256];
        char fmt[256];
        char line[320];
        mps_get_string_safe(this, game->tribe_game_options.fullTechTreeValue ? 0xfa3 : 0xfa4,
            game->tribe_game_options.fullTechTreeValue ? "Yes" : "No", value, sizeof(value));
        mps_get_string_safe(this, 0x25ec, "Full Tech Tree: %s", fmt, sizeof(fmt));
        snprintf(line, sizeof(line), fmt, value);
        line[sizeof(line) - 1] = '\0';
        mps_set_text(this->settingText[idx], line);
        if (this->settingText[idx]) this->settingText[idx]->set_active(1);
        ++idx;
    }

    // Enable Cheating (multiplayer only).
    if (rge_base_game->multiplayerGame() != 0) {
        char value[256];
        char fmt[256];
        char line[320];
        const int allow = (int)rge_base_game->rge_game_options.allowCheatCodesValue;
        mps_get_string_safe(this, allow ? 0xfa3 : 0xfa4, allow ? "Yes" : "No", value, sizeof(value));
        mps_get_string_safe(this, 0x25bb, "Enable Cheating: %s", fmt, sizeof(fmt));
        snprintf(line, sizeof(line), fmt, value);
        line[sizeof(line) - 1] = '\0';
        mps_set_text(this->settingText[idx], line);
        if (this->settingText[idx]) this->settingText[idx]->set_active(1);
        ++idx;
    }

    // Path Finding.
    {
        char value[256];
        char fmt[256];
        char line[320];
        const unsigned char pf = (rge_base_game->multiplayerGame() != 0) ? rge_base_game->mpPathFinding() : rge_base_game->pathFinding();
        mps_get_string_safe(this, 0x260e + (int)pf, "Medium", value, sizeof(value));
        mps_get_string_safe(this, 0x25f1, "Path Finding: %s", fmt, sizeof(fmt));
        snprintf(line, sizeof(line), fmt, value);
        line[sizeof(line) - 1] = '\0';
        mps_set_text(this->settingText[idx], line);
        if (this->settingText[idx]) this->settingText[idx]->set_active(1);
        ++idx;
    }

    // Population limit.
    {
        char fmt[256];
        char line[320];
        mps_get_string_safe(this, 0x25f0, "Population Limit: %d", fmt, sizeof(fmt));
        snprintf(line, sizeof(line), fmt, (int)game->tribe_game_options.popLimitValue);
        line[sizeof(line) - 1] = '\0';
        mps_set_text(this->settingText[idx], line);
        if (this->settingText[idx]) this->settingText[idx]->set_active(1);
        ++idx;
    }

    if (rge_base_game->singlePlayerGame() != 0) {
        const int show_number_players =
            (rge_base_game->scenarioGame() == 0) || ((this->settingsFixed == 0) && (2 < this->scenarioPlayerCount));
        if (this->numberPlayersTitle) {
            this->numberPlayersTitle->set_active(show_number_players);
        }
        if (this->numberPlayersDrop) {
            this->numberPlayersDrop->set_active(show_number_players);
        }
    }

    this->fillPlayers();
}

TribeMPSetupScreen::TribeMPSetupScreen() : TScreenPanel((char*)"MP Setup Screen") {
    CUSTOM_DEBUG_BEGIN
    CUSTOM_DEBUG_LOG("MPS ctor: enter");
    CUSTOM_DEBUG_END

    this->title = nullptr;
    this->playerTitle = nullptr;
    this->civTitle = nullptr;
    this->settingsTitle = nullptr;
    this->colorTitle = nullptr;
    this->teamTitle = nullptr;
    for (int i = 0; i < 8; ++i) {
        this->playerNameText[i] = nullptr;
        this->playerCivText[i] = nullptr;
        this->scenarioPlayerText[i] = nullptr;
        this->playerCDText[i] = nullptr;
        this->playerVersionText[i] = nullptr;
        this->playerColorText[i] = nullptr;
        this->playerTeamText[i] = nullptr;
        this->playerColor[i] = nullptr;
        this->playerTeam[i] = nullptr;
        this->playerNameDrop[i] = nullptr;
        this->playerCivDrop[i] = nullptr;
        this->scenarioPlayerDrop[i] = nullptr;
        this->defaultColor[i] = 0;
        this->scenarioCheckSum[i] = 0;
    }
    this->chatInput = nullptr;
    this->chatTitle = nullptr;
    this->chatBox = nullptr;
    this->chatScrollbar = nullptr;
    this->gameSettingsButton = nullptr;
    this->scenarioName = nullptr;
    this->victoryFixedText = nullptr;
    for (int i = 0; i < 20; ++i) {
        this->settingText[i] = nullptr;
        this->settingValue[i] = nullptr;
    }
    this->mapSizeLabel = nullptr;
    this->mapSizeDrop = nullptr;
    this->mapTypeLabel = nullptr;
    this->mapTypeDrop = nullptr;
    this->numberPlayersTitle = nullptr;
    this->numberPlayersDrop = nullptr;
    this->numberPlayersText = nullptr;
    this->hiddenMapButton = nullptr;
    this->hiddenMapText = nullptr;
    this->victoryTypeLabel = nullptr;
    this->victoryTypeDrop = nullptr;
    this->victoryAmountLabel = nullptr;
    this->victoryAmountInput = nullptr;
    this->startButton = nullptr;
    this->readyButtons[0] = nullptr;
    this->readyButtons[1] = nullptr;
    this->cancelButton = nullptr;
    this->help_button = nullptr;
    this->ready_button = nullptr;
    this->close_button = nullptr;
    this->ready_button_label = nullptr;
    this->cancelMode = 0;
    this->playerToKick = 0;
    this->scenarioPlayerCount = 8;
    this->myCivilization = 0;
    this->myScenarioPlayer = -1;
    this->myPlayerColor = 0;
    this->myPlayerTeam = 0;
    this->myScenarioChecksum = 0;
    this->saveScenarioName[0] = '\0';
    this->saveRandomGame = 0;
    this->saveScenarioChecksum = 0;
    this->scenarioInfo = nullptr;
    this->settingsFixed = 0;
    this->numberAnyPlayers = 8;
    this->sent_cd_status = 0;
    this->netInfoButton = nullptr;
    this->i_am_ready = 0;
    this->last_send_shared = 0;
    this->resend_game_options = 0;

    if (!rge_base_game || !rge_base_game->draw_area) {
        this->error_code = 1;
        return;
    }

    if (!mps_ensure_multiplayer_comm()) {
        this->error_code = 1;
        return;
    }

    CUSTOM_DEBUG_BEGIN
    CUSTOM_DEBUG_LOG("MPS ctor: base game/draw area ok");
    CUSTOM_DEBUG_END

    char* setup_name = (rge_base_game->rge_game_options.multiplayerGameValue != 0) ? (char*)"scr3" : (char*)"scr2";
    long setup_id = (rge_base_game->rge_game_options.multiplayerGameValue != 0) ? 0xc385 : 0xc384;
    if (!TEasy_Panel::setup(rge_base_game->draw_area, (TPanel*)0, setup_name, setup_id, 1, 0, 0, 0, 0, 1)) {
        this->error_code = 1;
        return;
    }

    CUSTOM_DEBUG_BEGIN
    CUSTOM_DEBUG_LOG_FMT("MPS ctor: setup ok name='%s' id=%ld", setup_name, setup_id);
    CUSTOM_DEBUG_END

    this->setup_shadow_area(0);
    this->set_ideal_size(0x280, 0x1e0);

    CUSTOM_DEBUG_BEGIN
    CUSTOM_DEBUG_LOG("MPS ctor: shadow/setup_ideal done");
    CUSTOM_DEBUG_END

    const int title_resid = 0x25cf - ((rge_base_game->rge_game_options.multiplayerGameValue != 0) ? 1 : 0);
    CUSTOM_DEBUG_BEGIN
    CUSTOM_DEBUG_LOG_FMT("MPS ctor: creating title resid=%d", title_resid);
    CUSTOM_DEBUG_END
    if (!this->create_text((TPanel*)this, &this->title, title_resid, 0x14, 0x6, 600, 0x1e, 1, 1, 0, 0)) {
        this->error_code = 1;
        return;
    }

    CUSTOM_DEBUG_BEGIN
    CUSTOM_DEBUG_LOG("MPS ctor: title ok");
    CUSTOM_DEBUG_END

    CUSTOM_DEBUG_BEGIN
    CUSTOM_DEBUG_LOG("MPS ctor: creating column titles");
    CUSTOM_DEBUG_END
    if (!this->create_text((TPanel*)this, &this->playerTitle, 0x25d0, 0x1a, 0x32, 0xa0, 0x1e, 0, 0, 1, 0)) {
        this->error_code = 1;
        return;
    }
    if (!this->create_text((TPanel*)this, &this->civTitle, 0x25d1, 0xbd, 0x32, 0xa0, 0x1e, 0, 0, 1, 0)) {
        this->error_code = 1;
        return;
    }
    if (!this->create_text((TPanel*)this, &this->colorTitle, 0x25ae, 0xf0, 0x32, 100, 0x1e, 0, 0, 1, 0)) {
        this->error_code = 1;
        return;
    }
    this->colorTitle->set_alignment(TTextPanel::AlignCenter, TTextPanel::AlignRight);
    if (!this->create_text((TPanel*)this, &this->teamTitle, 0x25af, 0x136, 0x32, 100, 0x1e, 0, 0, 1, 0)) {
        this->error_code = 1;
        return;
    }
    this->teamTitle->set_alignment(TTextPanel::AlignCenter, TTextPanel::AlignRight);

    CUSTOM_DEBUG_BEGIN
    CUSTOM_DEBUG_LOG("MPS ctor: column titles done");
    CUSTOM_DEBUG_END

    CUSTOM_DEBUG_BEGIN
    CUSTOM_DEBUG_LOG("MPS ctor: begin player row construction");
    CUSTOM_DEBUG_END

    int row_y = 0x55;
    for (int i = 0; i < 8; ++i) {
        CUSTOM_DEBUG_BEGIN
        CUSTOM_DEBUG_LOG_FMT("MPS ctor: row %d begin", i);
        CUSTOM_DEBUG_END

        // Player name dropdown (Computer/None/Closed/Open list storage; in SP it is hidden and mirrored to text).
        this->create_drop_down((TPanel*)this, &this->playerNameDrop[i], 0x9e, 100, 7, row_y - 1, 0x9e, 0x18, 0xb);
        if (this->playerNameDrop[i]) {
            this->playerNameDrop[i]->set_draw_style(TDropDownPanel::DrawStyleLeftButton);
            this->playerNameDrop[i]->set_draw_val_rect(0);
            this->playerNameDrop[i]->set_help_info(0x75f9, -1); // Help: "To limit a game to less than 8 players..."
            this->playerNameDrop[i]->empty_list();
            // Add player type entries
            // 0x25d3 = "Computer", 0x25d6 = "None" for single player
            // 0x25d4 = "Closed", 0x25d5 = "Open" for multiplayer
            this->playerNameDrop[i]->append_line(0x25d3, 4);  // Computer
            if (rge_base_game->rge_game_options.multiplayerGameValue != 0) {
                this->playerNameDrop[i]->append_line(0x25d4, 1);  // Closed
                this->playerNameDrop[i]->append_line(0x25d5, 2);  // Open
            }
            this->playerNameDrop[i]->append_line(0x25d6, 0);  // None
        }
        
        // Player name text display (for single player - shows "You" or "Computer N")
        // FIXED: Corrected y position to match civ text alignment
        if (!this->create_text((TPanel*)this, &this->playerNameText[i], (char*)"", 0x1c, row_y + 2, 0x8b, 0x16, 0xb, 0, 0, 0)) {
            this->error_code = 1;
            return;
        }
        
        // Civilization dropdown
        this->create_drop_down((TPanel*)this, &this->playerCivDrop[i], 0x80, 100, 0xaa, row_y - 1, 0x80, 0x18, 0xb);
        if (this->playerCivDrop[i]) {
            this->playerCivDrop[i]->set_draw_style(TDropDownPanel::DrawStyleLeftButton);
            this->playerCivDrop[i]->set_draw_val_rect(0);
            this->playerCivDrop[i]->set_help_info(0x75fa, 0x25f09); // Help: "Click to select a civilization..."
            this->playerCivDrop[i]->empty_list();
            // Add civilization entries (IDs 1-17, where 17 is Random)
            this->playerCivDrop[i]->append_line(0x27f7, 1);  // Egyptian
            this->playerCivDrop[i]->append_line(0x27f8, 2);  // Greek
            this->playerCivDrop[i]->append_line(0x27f9, 3);  // Babylonian
            this->playerCivDrop[i]->append_line(0x27fa, 4);  // Assyrian
            this->playerCivDrop[i]->append_line(0x27fb, 5);  // Minoan
            this->playerCivDrop[i]->append_line(0x27fc, 6);  // Hittite
            this->playerCivDrop[i]->append_line(0x27fd, 7);  // Phoenician
            this->playerCivDrop[i]->append_line(0x27fe, 8);  // Sumerian
            this->playerCivDrop[i]->append_line(0x27ff, 9);  // Persian
            this->playerCivDrop[i]->append_line(0x2800, 10); // Shang
            this->playerCivDrop[i]->append_line(0x2801, 11); // Yamato
            this->playerCivDrop[i]->append_line(0x2802, 12); // Choson
            this->playerCivDrop[i]->append_line(0x2806, 13); // Roman
            this->playerCivDrop[i]->append_line(0x2807, 14); // Carthaginian
            this->playerCivDrop[i]->append_line(0x2809, 15); // Palmyran
            this->playerCivDrop[i]->append_line(0x2808, 16); // Macedonian
            this->playerCivDrop[i]->append_line(0x280a, 17); // Random
        }

        // Scenario player dropdown (kept for layout/vtable parity; populated by scenario summary flow).
        this->create_drop_down((TPanel*)this, &this->scenarioPlayerDrop[i], 0x28, 100, 0x144, row_y - 1, 0x28, 0x18, 0xb);
        if (this->scenarioPlayerDrop[i]) {
            this->scenarioPlayerDrop[i]->set_draw_style(TDropDownPanel::DrawStyleLeftButton);
            this->scenarioPlayerDrop[i]->set_draw_val_rect(0);
            this->scenarioPlayerDrop[i]->set_help_info(0x75fb, -1);
        }
        
        // Player civ text display (shows selected civ name)
        // FIXED: Corrected position and width per decomp source
        // Decomp: x=0xbf (191), width=0x6d (109)
        if (!this->create_text((TPanel*)this, &this->playerCivText[i], (char*)"", 0xbf, row_y + 2, 0x6d, 0x16, 0xb, 0, 0, 0)) {
            this->error_code = 1;
            return;
        }

        CUSTOM_DEBUG_BEGIN
        CUSTOM_DEBUG_LOG_FMT("MPS ctor: row %d civ text done", i);
        CUSTOM_DEBUG_END

        CUSTOM_DEBUG_BEGIN
        CUSTOM_DEBUG_LOG_FMT("MPS ctor: row %d scenario text begin", i);
        CUSTOM_DEBUG_END

        if (!this->create_text((TPanel*)this, &this->scenarioPlayerText[i], (char*)"", 0x159, row_y + 2, 0x28, 0x16, 0xb, 0, 0, 0)) {
            this->error_code = 1;
            return;
        }

        CUSTOM_DEBUG_BEGIN
        CUSTOM_DEBUG_LOG_FMT("MPS ctor: row %d scenario text done", i);
        CUSTOM_DEBUG_END

        if (!this->create_text((TPanel*)this, &this->playerCDText[i], 0x25df, 0x151, row_y + 3, 0x14, 0x16, 6, 0, 0, 0)) {
            this->error_code = 1;
            return;
        }
        if (!this->create_text((TPanel*)this, &this->playerVersionText[i], (char*)"", 0x161, row_y + 3, 0x1d, 0x16, 6, 0, 0, 0)) {
            this->error_code = 1;
            return;
        }

        CUSTOM_DEBUG_BEGIN
        CUSTOM_DEBUG_LOG_FMT("MPS ctor: row %d cd/version text done", i);
        CUSTOM_DEBUG_END
        this->playerCDText[i]->set_active(0);
        
        // Player color button (cycling button)
        if (!this->create_button((TPanel*)this, &this->playerColor[i], (char*)"", (char*)0, 0x136, row_y, 0x1e, 0x14, 0xb, 0, 1)) {
            this->error_code = 1;
            return;
        }
        if (this->playerColor[i]) {
            this->playerColor[i]->set_help_info(0x7604, -1); // Help: "Click to select your starting position..."
        }

        CUSTOM_DEBUG_BEGIN
        CUSTOM_DEBUG_LOG_FMT("MPS ctor: row %d color button done", i);
        CUSTOM_DEBUG_END
        
        // Team button (cycling button with states)
        if (!this->create_button((TPanel*)this, &this->playerTeam[i], 0x25b0, 0, 0x17c, row_y, 0x1e, 0x14, 0xb, 0, 1)) {
            this->error_code = 1;
            return;
        }
        if (this->playerTeam[i]) {
            this->playerTeam[i]->set_help_info(0x7603, -1); // Help: "Click to select a team..."
            this->playerTeam[i]->set_state_info(5);
            // Set up team button states: 0="-", 1="1", 2="2", 3="3", 4="4"
            this->playerTeam[i]->set_text((short)0, "-");  // State 0 = no team
            char team_str[4];
            for (int t = 1; t <= 4; ++t) {
                sprintf(team_str, "%d", t);
                this->playerTeam[i]->set_text((short)t, team_str);
                this->playerTeam[i]->set_id((short)t, t + 1, 0);
            }
            this->playerTeam[i]->set_state(0); // Start with no team
        }

        CUSTOM_DEBUG_BEGIN
        CUSTOM_DEBUG_LOG_FMT("MPS ctor: row %d team button done", i);
        CUSTOM_DEBUG_END
        
        // Team text display
        if (!this->create_text((TPanel*)this, &this->playerTeamText[i], (char*)"", 0x177, row_y, 0x28, 0x16, 0xb, 1, 1, 0)) {
            this->error_code = 1;
            return;
        }

        CUSTOM_DEBUG_BEGIN
        CUSTOM_DEBUG_LOG_FMT("MPS ctor: row %d team text done", i);
        CUSTOM_DEBUG_END
        
        // Player color text display
        CUSTOM_DEBUG_BEGIN
        CUSTOM_DEBUG_LOG_FMT("MPS ctor: row %d color text begin", i);
        CUSTOM_DEBUG_END
        if (!this->create_text((TPanel*)this, &this->playerColorText[i], (char*)"", 0x131, row_y, 0x28, 0x16, 0xb, 1, 1, 0)) {
            this->error_code = 1;
            return;
        }

        CUSTOM_DEBUG_BEGIN
        CUSTOM_DEBUG_LOG_FMT("MPS ctor: row %d done", i);
        CUSTOM_DEBUG_END
        
        row_y += 0x18;
    }

    CUSTOM_DEBUG_BEGIN
    CUSTOM_DEBUG_LOG("MPS ctor: player row construction done");
    CUSTOM_DEBUG_END

    CUSTOM_DEBUG_BEGIN
    CUSTOM_DEBUG_LOG("MPS ctor: creating footer/summary controls");
    CUSTOM_DEBUG_END

    if (!this->create_button((TPanel*)this, &this->gameSettingsButton, 0x25d2, 0, 0x1a4, 0x32, 0xd2, 0x1e, 0, 0, 0)) {
        this->error_code = 1;
        return;
    }
    if (this->gameSettingsButton) {
        this->gameSettingsButton->set_help_info(0x75fc, -1); // Help: "Click to change the scenario settings."
    }

    if (!this->create_text((TPanel*)this, &this->scenarioName, (char*)"", 0x1a4, 0x54, 0xdc, 0x44, 0xb, 0, 0, 1)) {
        this->error_code = 1;
        return;
    }

    int summary_y = 0x53;
    for (int i = 0; i < 20; ++i) {
        if (!this->create_text((TPanel*)this, &this->settingText[i], (char*)"", 0x1a4, summary_y, 0xdc, 0x14, 0xb, 0, 0, 0)) {
            this->error_code = 1;
            return;
        }
        summary_y += 0x18;
    }

    // Non-original temporary UI controls:
    // source-of-truth `scr_set` uses a separate settings screen with drop-downs/edit controls.
    // Those controls are still blocked by unimplemented TEasy_Panel creators in this branch,
    // so we expose the key random-map settings inline as cycle buttons for now.
    // NOTE: These have been removed to match the original scr_mps behavior.
    // Settings should be changed via the Settings button which opens TribeGameSettingsScreen.
    
    // Number of Players dropdown (single player only)
    if (rge_base_game->rge_game_options.multiplayerGameValue == 0) {
        if (!this->create_text((TPanel*)this, &this->numberPlayersTitle, 0x25d8, 0x1a, 0x127, 0x14f, 0x14, 0, 0, 1, 0)) {
            this->error_code = 1;
            return;
        }
        this->create_drop_down((TPanel*)this, &this->numberPlayersDrop, 0x46, 100, 0x1f, 0x142, 0x46, 0x18, 0xb);
        if (this->numberPlayersDrop) {
            this->numberPlayersDrop->set_help_info(0x7600, -1); // "Select the number of players."
        }
    }

    if (!this->create_button((TPanel*)this, &this->startButton, (char*)"", (char*)0, 0x46, 0x1b8, 0xf0, 0x1e, 0, 0, 0)) {
        this->error_code = 1;
        return;
    }
    this->startButton->set_text(0, 0x25ee);
    this->startButton->set_help_info(0x75ff, -1);

    if (!this->create_button((TPanel*)this, &this->cancelButton, 0xfa2, 0, 0x14a, 0x1b8, 0xf0, 0x1e, 0, 0, 0)) {
        this->error_code = 1;
        return;
    }
    this->cancelButton->set_help_info(0x7532, -1);

    if (!this->create_button((TPanel*)this, &this->help_button, 0xfa9, 0, 600, 0x1b8, 0x1e, 0x1e, 0, 0, 0)) {
        this->error_code = 1;
        return;
    }

    if (!this->create_button((TPanel*)this, &this->close_button, 0x3ea, 0, 0, 0, 0, 0, -1, -1, 0)) {
        this->error_code = 1;
        return;
    }

    this->close_button->set_active(1);
    this->close_button->set_positioning((PositionMode)9, 4, 4, 4, 4, 0x11, 0x11, 0x11, 0x11, (TPanel*)0, (TPanel*)0, (TPanel*)0, (TPanel*)0);

    this->cancelButton->hotkey = 0x1b;
    this->cancelButton->hotkey_shift = 0;
    this->curr_child = (TPanel*)this->startButton;

    if (rge_base_game->rge_game_options.multiplayerGameValue == 0) {
        TPanel* tab_list_sp[3];
        tab_list_sp[0] = (TPanel*)this->startButton;
        tab_list_sp[1] = (TPanel*)this->cancelButton;
        tab_list_sp[2] = (TPanel*)this->gameSettingsButton;
        this->set_tab_order(tab_list_sp, 3);
        this->curr_child = (TPanel*)this->startButton;
    } else {
        TPanel* tab_list[5];
        tab_list[0] = (TPanel*)this->gameSettingsButton;
        tab_list[1] = (TPanel*)this->startButton;
        tab_list[2] = (TPanel*)this->cancelButton;
        tab_list[3] = (TPanel*)this->help_button;
        tab_list[4] = (TPanel*)this->close_button;
        this->set_tab_order(tab_list, 5);
    }

    CUSTOM_DEBUG_BEGIN
    CUSTOM_DEBUG_LOG("MPS ctor: controls created, refreshing ui");
    CUSTOM_DEBUG_END

    this->updateSummary();

    CUSTOM_DEBUG_BEGIN
    CUSTOM_DEBUG_LOG("MPS ctor: complete");
    CUSTOM_DEBUG_END
}

TribeMPSetupScreen::~TribeMPSetupScreen() {
    // Source of truth: scr_mps.cpp.decomp @ 0x004A1300.
    // Use TPanel::delete_panel to match panel-tree ownership semantics.
    this->delete_panel((TPanel**)&this->title);
    this->delete_panel((TPanel**)&this->playerTitle);
    this->delete_panel((TPanel**)&this->civTitle);
    this->delete_panel((TPanel**)&this->settingsTitle);
    this->delete_panel((TPanel**)&this->colorTitle);
    this->delete_panel((TPanel**)&this->teamTitle);

    for (int i = 0; i < 8; ++i) {
        this->delete_panel((TPanel**)&this->playerNameDrop[i]);
        this->delete_panel((TPanel**)&this->playerCivDrop[i]);
        this->delete_panel((TPanel**)&this->scenarioPlayerDrop[i]);
        this->delete_panel((TPanel**)&this->playerNameText[i]);
        this->delete_panel((TPanel**)&this->playerCivText[i]);
        this->delete_panel((TPanel**)&this->scenarioPlayerText[i]);
        this->delete_panel((TPanel**)&this->playerCDText[i]);
        this->delete_panel((TPanel**)&this->playerVersionText[i]);
        this->delete_panel((TPanel**)&this->playerColorText[i]);
        this->delete_panel((TPanel**)&this->playerTeamText[i]);
        this->delete_panel((TPanel**)&this->playerColor[i]);
        this->delete_panel((TPanel**)&this->playerTeam[i]);
    }

    this->delete_panel((TPanel**)&this->chatInput);
    this->delete_panel((TPanel**)&this->chatTitle);
    this->delete_panel((TPanel**)&this->chatBox);
    this->delete_panel((TPanel**)&this->chatScrollbar);

    this->delete_panel((TPanel**)&this->gameSettingsButton);
    this->delete_panel((TPanel**)&this->scenarioName);
    this->delete_panel((TPanel**)&this->victoryFixedText);

    for (int i = 0; i < 20; ++i) {
        this->delete_panel((TPanel**)&this->settingText[i]);
        this->delete_panel((TPanel**)&this->settingValue[i]);
    }

    this->delete_panel((TPanel**)&this->mapSizeLabel);
    this->delete_panel((TPanel**)&this->mapSizeDrop);
    this->delete_panel((TPanel**)&this->mapTypeLabel);
    this->delete_panel((TPanel**)&this->mapTypeDrop);

    this->delete_panel((TPanel**)&this->numberPlayersTitle);
    this->delete_panel((TPanel**)&this->numberPlayersDrop);
    this->delete_panel((TPanel**)&this->numberPlayersText);

    this->delete_panel((TPanel**)&this->hiddenMapButton);
    this->delete_panel((TPanel**)&this->hiddenMapText);
    this->delete_panel((TPanel**)&this->victoryTypeLabel);
    this->delete_panel((TPanel**)&this->victoryTypeDrop);
    this->delete_panel((TPanel**)&this->victoryAmountLabel);
    this->delete_panel((TPanel**)&this->victoryAmountInput);

    this->delete_panel((TPanel**)&this->startButton);
    this->delete_panel((TPanel**)&this->readyButtons[0]);
    this->delete_panel((TPanel**)&this->readyButtons[1]);
    this->delete_panel((TPanel**)&this->cancelButton);
    this->delete_panel((TPanel**)&this->help_button);
    this->delete_panel((TPanel**)&this->ready_button);
    this->delete_panel((TPanel**)&this->close_button);
    this->delete_panel((TPanel**)&this->ready_button_label);
    this->delete_panel((TPanel**)&this->netInfoButton);
}

long TribeMPSetupScreen::handle_idle() {
    if (rge_base_game && rge_base_game->input_enabled == 0) {
        rge_base_game->enable_input();
    }
    return TPanel::handle_idle();
}

void TribeMPSetupScreen::calcRandomPositions() {
    // Fully verified. Source of truth: scr_mps.cpp.decomp @ 0x004A27A0
    if (!rge_base_game || !comm) {
        return;
    }

    TCommunications_Handler* comm_handler = (TCommunications_Handler*)comm;

    int active_players = 0;
    int number_players = rge_base_game->numberPlayers();
    for (int player = 1; player <= number_players; ++player) {
        int humanity = comm_handler->GetPlayerHumanity((uint)player);
        if (humanity == 2 || humanity == 4) {
            active_players++;
        }
    }

    int available_slots = 0;
    int position_used[9];
    for (int i = 0; i < 9; ++i) {
        position_used[i] = -2;
    }

    for (int position = 0; position < 8; ++position) {
        long line = -1;
        if (this->scenarioPlayerDrop[0] != nullptr) {
            line = this->scenarioPlayerDrop[0]->get_line(position);
        }

        if (line == -1) {
            position_used[position + 1] = -2;
        } else {
            position_used[position + 1] = -1;
            available_slots++;
        }
    }

    if (active_players > available_slots) {
        return;
    }

    int fallback_pos = 0;
    number_players = rge_base_game->numberPlayers();
    for (int player_slot = 0; player_slot < number_players; ++player_slot) {
        int humanity = comm_handler->GetPlayerHumanity((uint)(player_slot + 1));
        if (humanity != 2 && humanity != 4) {
            continue;
        }

        int selected_fallback = fallback_pos;
        if (this->scenarioPlayerCount > 0) {
            for (int i = 0; i < this->scenarioPlayerCount; ++i) {
                if (position_used[i + 1] == -1) {
                    selected_fallback = i;
                    break;
                }
            }
        }

        int chosen_pos = selected_fallback;
        int attempts = 0;
        while (attempts < 1000 && this->scenarioPlayerCount > 0) {
            int candidate = (debug_rand("C:\\msdev\\work\\age1_x1\\scr_mps.cpp", 0x5e4) * this->scenarioPlayerCount) / 0x7fff;
            if (candidate < 0) {
                candidate = 0;
            } else if (candidate >= this->scenarioPlayerCount) {
                candidate = this->scenarioPlayerCount - 1;
            }

            if (position_used[candidate + 1] == -1) {
                chosen_pos = candidate;
                break;
            }

            chosen_pos = selected_fallback;
            attempts++;
        }

        ((TRIBE_Game*)rge_base_game)->setScenarioPlayer(player_slot, chosen_pos);
        position_used[chosen_pos + 1] = player_slot;
        fallback_pos = chosen_pos;
    }
}

int TribeMPSetupScreen::startGame() {
    // Source of truth: scr_mps.cpp.decomp @ 0x004A2060.
    if (!rge_base_game) {
        return 0;
    }

    if (!mps_ensure_multiplayer_comm()) {
        return 0;
    }

    TRIBE_Game* game = (TRIBE_Game*)rge_base_game;
    TCommunications_Handler* comm_handler = (TCommunications_Handler*)comm;
    int send_options = 0;

    char msg[1024];
    msg[0] = '\0';
    char msg_small[256];
    msg_small[0] = '\0';

    if (rge_base_game->multiplayerGame() != 0) {
        if (comm_handler->IsHost() == 0) {
            return 0;
        }

        if (comm_handler->AllPlayersReady() == 0) {
            mps_popup_resid(this, 0x25c1, "All players must be ready for a game to start.");
            return 0;
        }

        if (rge_base_game->scenarioGame() != 0) {
            for (int player = 1; player < 9; ++player) {
                if (player == (int)comm_handler->WhoAmI()) {
                    continue;
                }

                if (comm_handler->GetPlayerHumanity((uint)player) == 2 &&
                    this->scenarioCheckSum[player - 1] != this->myScenarioChecksum) {
                    const char* player_name = comm_handler->GetPlayerName((uint)player);
                    char* fmt = this->get_string(0x25e1);
                    if (fmt != nullptr && fmt[0] != '\0') {
                        _snprintf(msg, sizeof(msg), fmt, (player_name != nullptr) ? player_name : "");
                    } else {
                        _snprintf(msg, sizeof(msg), "%s does not have this scenario or has a different version of it.",
                            (player_name != nullptr) ? player_name : "A player");
                    }
                    msg[sizeof(msg) - 1] = '\0';
                    mps_popup_text(msg);
                    return 0;
                }
            }
        }

        for (int player = 1; player < 9; ++player) {
            if (player == (int)comm_handler->WhoAmI()) {
                continue;
            }

            if (comm_handler->GetPlayerHumanity((uint)player) == 2 &&
                rge_base_game->playerVersion(player - 1) != 1) {
                const char* player_name = comm_handler->GetPlayerName((uint)player);
                char* fmt = this->get_string(0x25e2);
                if (fmt != nullptr && fmt[0] != '\0') {
                    _snprintf(msg, sizeof(msg), fmt, (player_name != nullptr) ? player_name : "");
                } else {
                    _snprintf(msg, sizeof(msg), "%s is not running version 1.0b of the game.",
                        (player_name != nullptr) ? player_name : "A player");
                }
                msg[sizeof(msg) - 1] = '\0';
                mps_popup_text(msg);
                return 0;
            }
        }
    }

    if (rge_base_game->scenarioGame() != 0 && this->scenarioInfo == nullptr) {
        mps_popup_resid(this, 0x25c2, "The selected scenario is invalid.");
        return 0;
    }

    if (rge_base_game->multiplayerGame() != 0 &&
        rge_base_game->scenarioGame() != 0 &&
        this->scenarioPlayerDrop[0] != nullptr &&
        comm_handler != nullptr) {
        int scenario_index = 0;
        for (int slot = 0; slot < 8; ++slot) {
            int humanity = comm_handler->GetPlayerHumanity((uint)(slot + 1));
            if (humanity == 2 || humanity == 4) {
                long scenario_player = this->scenarioPlayerDrop[0]->get_id(scenario_index);
                game->setScenarioPlayer(slot, (int)scenario_player);
                scenario_index++;

                if (this->scenarioPlayerDrop[0]->list_panel != nullptr) {
                    int lines = ((TTextPanel*)this->scenarioPlayerDrop[0]->list_panel)->numberLines();
                    if (scenario_index >= lines) {
                        scenario_index = 0;
                    }
                }
            }
        }
    }

    if (rge_base_game->multiplayerGame() != 0 && comm_handler != nullptr) {
        int color_used[9];
        for (int i = 0; i < 9; ++i) {
            color_used[i] = 0;
        }

        int active_count = 0;
        int number_players = rge_base_game->numberPlayers();
        for (int slot = 0; slot < number_players; ++slot) {
            int humanity = comm_handler->GetPlayerHumanity((uint)(slot + 1));
            if (humanity == 2) {
                int color = game->playerColor(slot);
                if (color >= 0 && color < 9) {
                    if (color_used[color] == 0) {
                        color_used[color] = 1;
                        active_count++;
                    }
                } else {
                    active_count++;
                }
            } else if (humanity == 4) {
                active_count++;
            }
        }

        if (active_count < 2) {
            mps_popup_resid(this, 0x25c6, "You cannot start a game with only one player.");
            return 0;
        }

        if (rge_base_game->scenarioGame() != 0 && this->scenarioPlayerCount < active_count) {
            char* fmt = this->get_string(0x25c3);
            if (fmt != nullptr && fmt[0] != '\0') {
                _snprintf(msg_small, sizeof(msg_small), fmt, this->scenarioPlayerCount);
            } else {
                _snprintf(msg_small, sizeof(msg_small), "This scenario only supports up to %d players.", this->scenarioPlayerCount);
            }
            msg_small[sizeof(msg_small) - 1] = '\0';
            mps_popup_text(msg_small);
            return 0;
        }

        if (rge_base_game->scenarioGame() != 0 && this->settingsFixed != 0 && active_count != this->scenarioPlayerCount) {
            char* fmt = this->get_string(0x25c5);
            if (fmt != nullptr && fmt[0] != '\0') {
                _snprintf(msg_small, sizeof(msg_small), fmt, this->scenarioPlayerCount);
            } else {
                _snprintf(msg_small, sizeof(msg_small), "This scenario requires exactly %d players.", this->scenarioPlayerCount);
            }
            msg_small[sizeof(msg_small) - 1] = '\0';
            mps_popup_text(msg_small);
            return 0;
        }

        int human_count = 0;
        number_players = rge_base_game->numberPlayers();
        for (int slot = 0; slot < number_players; ++slot) {
            if (comm_handler->GetPlayerHumanity((uint)(slot + 1)) == 2) {
                human_count++;
            }
        }

        int has_cd = rge_base_game->check_for_cd(0);
        int who_am_i = (int)comm_handler->WhoAmI();
        rge_base_game->setPlayerHasCD(who_am_i - 1, has_cd);
        if (rge_base_game->check_for_cd(human_count) == 0) {
            mps_popup_resid(this, 0x7d9, "One game CD is required for every three players.");
            return 0;
        }
    }

    if (rge_base_game->scenarioGame() != 0 && game->randomizePositions() != 0) {
        this->calcRandomPositions();
        if (rge_base_game->multiplayerGame() != 0) {
            send_options = 1;
        }
    }

    if (rge_base_game->singlePlayerGame() != 0 && comm_handler != nullptr) {
        int number_players = rge_base_game->numberPlayers();
        if (number_players < 8) {
            for (int slot = number_players + 1; slot < 9; ++slot) {
                comm_handler->SetPlayerHumanity((uint)slot, 0);
            }
        }
    }

    if (rge_base_game->multiplayerGame() != 0) {
        int number_players = rge_base_game->numberPlayers();
        for (int slot = 0; slot < number_players; ++slot) {
            int civ = game->civilization(slot);
            if (civ > 0x31) {
                game->setCivilization(slot, civ - 0x32);
                send_options = 1;
            }

            int team = rge_base_game->playerTeam(slot);
            if (team > 0x31) {
                rge_base_game->setPlayerTeam(slot, team - 0x32);
                send_options = 1;
            }
        }
    }

    if (rge_base_game->multiplayerGame() != 0 && comm_handler != nullptr) {
        int temp_team[9];
        int temp_color[9];
        int temp_civ[9];

        for (int i = 1; i < 9; ++i) {
            temp_team[i] = 1;
            temp_color[i] = i;
            temp_civ[i] = 1;
        }

        int active_count = 0;
        for (int player = 1; player < 9; ++player) {
            int humanity = comm_handler->GetPlayerHumanity((uint)player);
            if (humanity == 2 || humanity == 4) {
                int slot = player - 1;
                temp_color[active_count + 1] = game->playerColor(slot);
                temp_civ[active_count + 1] = game->civilization(slot);
                temp_team[active_count + 1] = rge_base_game->playerTeam(slot);
                active_count++;
            }
        }

        if (active_count > 0) {
            for (int slot = 0; slot < 8; ++slot) {
                game->setPlayerColor(slot, temp_color[slot + 1]);
                game->setCivilization(slot, temp_civ[slot + 1]);
                rge_base_game->setPlayerTeam(slot, temp_team[slot + 1]);
            }
            send_options = 1;
        }
    }

    if (panel_system != nullptr) {
        panel_system->destroyPanel((char*)"Status Screen");
    }

    if (rge_base_game->multiplayerGame() != 0) {
        if (send_options != 0 || this->resend_game_options != 0) {
            rge_base_game->send_game_options();
            this->resend_game_options = 0;
        }

        if (comm_handler != nullptr) {
            comm_handler->LaunchMultiplayerGame();
            if (chat != nullptr) {
                ((TChat*)chat)->setWindowHandle((void*)AppWnd);
            }
            comm_handler->SetWindowHandle((void*)AppWnd);
        }
    }

    if (game->start_game(0) == 0) {
        mps_popup_resid(this, 0x961, "An error occurred while trying to start the game.");
        return 0;
    }

    return 1;
}

long TribeMPSetupScreen::action(TPanel* param_1, long param_2, ulong param_3, ulong param_4) {
    if (param_1 && (param_2 == 1)) {
        TRIBE_Game* game = (TRIBE_Game*)rge_base_game;

        // Handle player color buttons (cycle through colors 1-8)
        for (int i = 0; i < 8; ++i) {
            if ((TButtonPanel*)param_1 == this->playerColor[i]) {
                int color_id = (int)mps_button_state_id(this->playerColor[i]);
                color_id = mps_clamp(color_id, 1, 8);
                game->setPlayerColor(i, color_id);
                this->fillPlayers();
                return 1;
            }
        }

        // Handle team buttons (cycle through teams 0-4, where 0 = no team)
        for (int i = 0; i < 8; ++i) {
            if ((TButtonPanel*)param_1 == this->playerTeam[i]) {
                int state = mps_button_state_index(this->playerTeam[i]);
                rge_base_game->setPlayerTeam(i, state + 1);
                this->fillPlayers();
                return 1;
            }
        }

        if ((TButtonPanel*)param_1 == this->gameSettingsButton) {
            // Decomp @ 004a1aaf: check if settings screen already exists
            TPanel* existing = panel_system->panel((char*)"Game Settings Screen");
            if (existing == nullptr) {
                rge_base_game->disable_input();
                // Decomp: operator_new(0x560) then constructor does all setup
                TribeGameSettingsScreen* settingsScreen = new TribeGameSettingsScreen();
                if (settingsScreen && settingsScreen->error_code == 0) {
                    panel_system->setCurrentPanel((char*)"Game Settings Screen", 0);
                } else {
                    if (settingsScreen) {
                        delete settingsScreen;
                    }
                    mps_enable_input();
                }
            } else {
                panel_system->setCurrentPanel((char*)"Game Settings Screen", 0);
            }
            return 1;
        }

        if ((TButtonPanel*)param_1 == this->startButton) {
            rge_base_game->disable_input();

            if (!this->startGame()) {
                mps_enable_input();
            }
            return 1;
        }

        if ((TButtonPanel*)param_1 == this->cancelButton) {
            rge_base_game->disable_input();

            TribeSPMenuScreen* menu = new TribeSPMenuScreen();
            if (menu && menu->error_code == 0) {
                panel_system->setCurrentPanel((char*)"Single Player Menu", 0);
                panel_system->destroyPanel((char*)"MP Setup Screen");
            } else {
                if (menu) delete menu;
                mps_enable_input();
            }
            return 1;
        }

        if ((TButtonPanel*)param_1 == this->help_button) {
            this->setup_popup_help();
            return 1;
        }

        if ((TButtonPanel*)param_1 == this->close_button) {
            rge_base_game->close();
            return 1;
        }
    }

    // Decomp @ 004a1c3c: Handle "Game Settings Screen" returning via action
    // The settings screen calls chat_scr->action(this, 1, 0, 0) for OK
    // or chat_scr->action(this, 0, 0, 0) for Cancel.
    if (param_1 && param_1->panelNameValue != nullptr) {
        if (strcmp(param_1->panelNameValue, "Game Settings Screen") == 0) {
            if (param_2 != 0) {
                this->updateSummary();
                if (rge_base_game && rge_base_game->singlePlayerGame() == 0) {
                    rge_base_game->send_game_options();
                    this->resend_game_options = 0;
                }
            }
            // Both OK and Cancel: return to MP Setup Screen
            panel_system->setCurrentPanel((char*)"MP Setup Screen", 0);
            return 1;
        }
    }

    // Handle drop-down selections (param_2 == 0 for selection)
    if (param_2 == 0) {
        // Handle number of players dropdown
        if (this->numberPlayersDrop && (TDropDownPanel*)param_1 == this->numberPlayersDrop) {
            long selected_id = this->numberPlayersDrop->get_id();
            int max_players = this->scenarioPlayerCount;
            if (max_players < 2 || max_players > 8) {
                max_players = 8;
            }
            selected_id = mps_clamp((int)selected_id, 2, max_players);
            rge_base_game->setNumberPlayers(selected_id);
            this->updateSummary();
            return 1;
        }
        
        // Handle player civilization dropdowns
        for (int i = 0; i < 8; ++i) {
            if (this->playerCivDrop[i] && (TDropDownPanel*)param_1 == this->playerCivDrop[i]) {
                long selected_civ = this->playerCivDrop[i]->get_id();
                if (selected_civ >= 1 && selected_civ <= 17) {
                    TRIBE_Game* game = (TRIBE_Game*)rge_base_game;
                    game->setCivilization(i, selected_civ);
                    this->fillPlayers();
                }
                return 1;
            }
        }
        
        // Handle player name/type dropdowns (for single player - Computer/None)
        for (int i = 0; i < 8; ++i) {
            if (this->playerNameDrop[i] && (TDropDownPanel*)param_1 == this->playerNameDrop[i]) {
                // Source-of-truth: scr_mps.cpp.decomp (`action`) sets comm humanity from slot dropdown.
                if (comm) {
                    TCommunications_Handler* comm_handler = (TCommunications_Handler*)comm;
                    long selected_humanity = this->playerNameDrop[i]->get_id();
                    comm_handler->SetPlayerHumanity((uint)(i + 1), (int)selected_humanity);
                }
                this->fillPlayers();
                return 1;
            }
        }
    }

    return TEasy_Panel::action(param_1, param_2, param_3, param_4);
}

// Virtual wrappers: forward to TScreenPanel unless overridden.
long TribeMPSetupScreen::setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, long param_5, long param_6, uchar param_7) { return TScreenPanel::setup(param_1, param_2, param_3, param_4, param_5, param_6, param_7); }
void TribeMPSetupScreen::set_rect(tagRECT param_1) { TScreenPanel::set_rect(param_1); }
void TribeMPSetupScreen::set_rect(long param_1, long param_2, long param_3, long param_4) { TScreenPanel::set_rect(param_1, param_2, param_3, param_4); }
void TribeMPSetupScreen::set_color(uchar param_1) { TScreenPanel::set_color(param_1); }
void TribeMPSetupScreen::set_active(int param_1) { TScreenPanel::set_active(param_1); }
void TribeMPSetupScreen::set_positioning(PositionMode param_1, long param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, TPanel* param_10, TPanel* param_11, TPanel* param_12, TPanel* param_13) { TScreenPanel::set_positioning(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12, param_13); }
void TribeMPSetupScreen::set_fixed_position(long param_1, long param_2, long param_3, long param_4) { TScreenPanel::set_fixed_position(param_1, param_2, param_3, param_4); }
void TribeMPSetupScreen::set_redraw(RedrawMode param_1) { TScreenPanel::set_redraw(param_1); }
void TribeMPSetupScreen::set_overlapped_redraw(TPanel* param_1, TPanel* param_2, RedrawMode param_3) { TScreenPanel::set_overlapped_redraw(param_1, param_2, param_3); }
void TribeMPSetupScreen::draw_setup(int param_1) { TScreenPanel::draw_setup(param_1); }
void TribeMPSetupScreen::draw_finish() { TScreenPanel::draw_finish(); }
void TribeMPSetupScreen::draw() { TScreenPanel::draw(); }
void TribeMPSetupScreen::draw_rect(tagRECT* param_1) { TScreenPanel::draw_rect(param_1); }
void TribeMPSetupScreen::draw_offset(long param_1, long param_2, tagRECT* param_3) { TScreenPanel::draw_offset(param_1, param_2, param_3); }
void TribeMPSetupScreen::draw_rect2(tagRECT* param_1) { TScreenPanel::draw_rect2(param_1); }
void TribeMPSetupScreen::draw_offset2(long param_1, long param_2, tagRECT* param_3) { TScreenPanel::draw_offset2(param_1, param_2, param_3); }
void TribeMPSetupScreen::paint() { TScreenPanel::paint(); }
long TribeMPSetupScreen::wnd_proc(void* param_1, uint param_2, uint param_3, long param_4) { return TScreenPanel::wnd_proc(param_1, param_2, param_3, param_4); }
long TribeMPSetupScreen::handle_size(long param_1, long param_2) { return TScreenPanel::handle_size(param_1, param_2); }
long TribeMPSetupScreen::handle_paint() { return TScreenPanel::handle_paint(); }
long TribeMPSetupScreen::handle_key_down(long param_1, short param_2, int param_3, int param_4, int param_5) { return TScreenPanel::handle_key_down(param_1, param_2, param_3, param_4, param_5); }
long TribeMPSetupScreen::handle_char(long param_1, short param_2) { return TScreenPanel::handle_char(param_1, param_2); }
long TribeMPSetupScreen::handle_command(uint param_1, long param_2) { return TScreenPanel::handle_command(param_1, param_2); }
long TribeMPSetupScreen::handle_user_command(uint param_1, long param_2) { return TScreenPanel::handle_user_command(param_1, param_2); }
long TribeMPSetupScreen::handle_timer_command(uint param_1, long param_2) { return TScreenPanel::handle_timer_command(param_1, param_2); }
long TribeMPSetupScreen::handle_scroll(long param_1, long param_2) { return TScreenPanel::handle_scroll(param_1, param_2); }
long TribeMPSetupScreen::handle_mouse_down(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TScreenPanel::handle_mouse_down(param_1, param_2, param_3, param_4, param_5); }
long TribeMPSetupScreen::handle_mouse_move(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::handle_mouse_move(param_1, param_2, param_3, param_4); }
long TribeMPSetupScreen::handle_mouse_up(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TScreenPanel::handle_mouse_up(param_1, param_2, param_3, param_4, param_5); }
long TribeMPSetupScreen::handle_mouse_dbl_click(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TScreenPanel::handle_mouse_dbl_click(param_1, param_2, param_3, param_4, param_5); }
long TribeMPSetupScreen::mouse_move_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_move_action(param_1, param_2, param_3, param_4); }
long TribeMPSetupScreen::mouse_left_down_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_left_down_action(param_1, param_2, param_3, param_4); }
long TribeMPSetupScreen::mouse_left_hold_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_left_hold_action(param_1, param_2, param_3, param_4); }
long TribeMPSetupScreen::mouse_left_move_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_left_move_action(param_1, param_2, param_3, param_4); }
long TribeMPSetupScreen::mouse_left_up_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_left_up_action(param_1, param_2, param_3, param_4); }
long TribeMPSetupScreen::mouse_left_dbl_click_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_left_dbl_click_action(param_1, param_2, param_3, param_4); }
long TribeMPSetupScreen::mouse_right_down_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_right_down_action(param_1, param_2, param_3, param_4); }
long TribeMPSetupScreen::mouse_right_hold_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_right_hold_action(param_1, param_2, param_3, param_4); }
long TribeMPSetupScreen::mouse_right_move_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_right_move_action(param_1, param_2, param_3, param_4); }
long TribeMPSetupScreen::mouse_right_up_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_right_up_action(param_1, param_2, param_3, param_4); }
long TribeMPSetupScreen::mouse_right_dbl_click_action(long param_1, long param_2, int param_3, int param_4) { return TScreenPanel::mouse_right_dbl_click_action(param_1, param_2, param_3, param_4); }
long TribeMPSetupScreen::key_down_action(long param_1, short param_2, int param_3, int param_4, int param_5) { return TScreenPanel::key_down_action(param_1, param_2, param_3, param_4, param_5); }
long TribeMPSetupScreen::char_action(long param_1, short param_2) { return TScreenPanel::char_action(param_1, param_2); }
void TribeMPSetupScreen::get_true_render_rect(tagRECT* param_1) { TScreenPanel::get_true_render_rect(param_1); }
int TribeMPSetupScreen::is_inside(long param_1, long param_2) { return TScreenPanel::is_inside(param_1, param_2); }
void TribeMPSetupScreen::set_focus(int param_1) { TScreenPanel::set_focus(param_1); }
void TribeMPSetupScreen::set_tab_order(TPanel* param_1, TPanel* param_2) { TScreenPanel::set_tab_order(param_1, param_2); }
void TribeMPSetupScreen::set_tab_order(TPanel** param_1, short param_2) { TScreenPanel::set_tab_order(param_1, param_2); }
uchar TribeMPSetupScreen::get_help_info(char** param_1, long* param_2, long param_3, long param_4) { return TScreenPanel::get_help_info(param_1, param_2, param_3, param_4); }
void TribeMPSetupScreen::stop_sound_system() { TScreenPanel::stop_sound_system(); }
int TribeMPSetupScreen::restart_sound_system() { return TScreenPanel::restart_sound_system(); }
void TribeMPSetupScreen::take_snapshot() { TScreenPanel::take_snapshot(); }
void TribeMPSetupScreen::handle_reactivate() { TScreenPanel::handle_reactivate(); }
void TribeMPSetupScreen::draw_background(int param_1) { TScreenPanel::draw_background(param_1); }
void TribeMPSetupScreen::set_ideal_size(long param_1, long param_2) { TScreenPanel::set_ideal_size(param_1, param_2); }
int TribeMPSetupScreen::create_button(TPanel* param_1, TButtonPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, long param_10, long param_11) { return TScreenPanel::create_button(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int TribeMPSetupScreen::create_button(TPanel* param_1, TButtonPanel** param_2, char* param_3, char* param_4, long param_5, long param_6, long param_7, long param_8, long param_9, long param_10, long param_11) { return TScreenPanel::create_button(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int TribeMPSetupScreen::create_check_box(TPanel* param_1, TButtonPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8) { return TScreenPanel::create_check_box(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8); }
int TribeMPSetupScreen::create_radio_button(TPanel* param_1, TButtonPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8) { return TScreenPanel::create_radio_button(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8); }
int TribeMPSetupScreen::create_text(TPanel* param_1, TTextPanel** param_2, int param_3, long param_4, long param_5, long param_6, long param_7, long param_8, int param_9, int param_10, int param_11) { return TScreenPanel::create_text(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int TribeMPSetupScreen::create_text(TPanel* param_1, TTextPanel** param_2, char** param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, int param_10, int param_11) { return TScreenPanel::create_text(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int TribeMPSetupScreen::create_text(TPanel* param_1, TTextPanel** param_2, char* param_3, long param_4, long param_5, long param_6, long param_7, long param_8, int param_9, int param_10, int param_11) { return TScreenPanel::create_text(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11); }
int TribeMPSetupScreen::create_input(TPanel* param_1, TInputPanel** param_2, char* param_3, short param_4, FormatType param_5, long param_6, long param_7, long param_8, long param_9, long param_10) { return TScreenPanel::create_input(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10); }
int TribeMPSetupScreen::create_edit(TPanel* param_1, TEditPanel** param_2, char* param_3, short param_4, FormatType param_5, long param_6, long param_7, long param_8, long param_9, long param_10, int param_11, int param_12) { return TScreenPanel::create_edit(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12); }
int TribeMPSetupScreen::create_drop_down(TPanel* param_1, TDropDownPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9) { return TScreenPanel::create_drop_down(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9); }
int TribeMPSetupScreen::create_list(TPanel* param_1, TListPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7) { return TScreenPanel::create_list(param_1, param_2, param_3, param_4, param_5, param_6, param_7); }
int TribeMPSetupScreen::create_scrollbar(TPanel* param_1, TScrollBarPanel** param_2, TTextPanel* param_3, long param_4, long param_5, long param_6, long param_7, long param_8) { return TScreenPanel::create_scrollbar(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8); }
int TribeMPSetupScreen::create_auto_scrollbar(TScrollBarPanel** param_1, TTextPanel* param_2, long param_3) { return TScreenPanel::create_auto_scrollbar(param_1, param_2, param_3); }
int TribeMPSetupScreen::create_vert_slider(TPanel* param_1, TVerticalSliderPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9) { return TScreenPanel::create_vert_slider(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9); }
int TribeMPSetupScreen::create_horz_slider(TPanel* param_1, THorizontalSliderPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9) { return TScreenPanel::create_horz_slider(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9); }
void TribeMPSetupScreen::position_panel(TPanel* param_1, long param_2, long param_3, long param_4, long param_5) { TScreenPanel::position_panel(param_1, param_2, param_3, param_4, param_5); }
