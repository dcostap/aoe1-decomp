#include "../include/TribeMPSetupScreen.h"
#include "../include/TribeSPMenuScreen.h"
#include "../include/RGE_Base_Game.h"
#include "../include/TRIBE_Game.h"
#include "../include/TTextPanel.h"
#include "../include/globals.h"

#include <stdio.h>
#include <string.h>

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

static void mps_update_player_rows(TribeMPSetupScreen* owner) {
    if (!owner || !rge_base_game) return;
    TRIBE_Game* game = (TRIBE_Game*)rge_base_game;
    const int number_players = mps_clamp((int)rge_base_game->rge_game_options.numberPlayersValue, 2, 8);

    for (int i = 0; i < 8; ++i) {
        const int active = (i < number_players) ? 1 : 0;

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
            char computer[128];
            mps_get_string_safe(owner, 0x25d3, "Computer", computer, sizeof(computer));
            snprintf(name_text, sizeof(name_text), "%s %d", computer, i);
            name_text[sizeof(name_text) - 1] = '\0';
        }

        char civ_text[128];
        const int civ_resid = mps_civ_resid((int)game->tribe_game_options.civilizationValue[i]);
        if (civ_resid >= 0) {
            mps_get_string_safe(owner, civ_resid, "Random", civ_text, sizeof(civ_text));
        } else {
            mps_get_string_safe(owner, 0x280a, "Random", civ_text, sizeof(civ_text));
        }

        char color_text[32];
        snprintf(color_text, sizeof(color_text), "%d", (int)game->tribe_game_options.playerColorValue[i]);
        color_text[sizeof(color_text) - 1] = '\0';

        char team_text[32];
        snprintf(team_text, sizeof(team_text), "%d", (int)rge_base_game->rge_game_options.playerTeamValue[i]);
        team_text[sizeof(team_text) - 1] = '\0';

        mps_set_text(owner->playerNameText[i], name_text);
        mps_set_text(owner->playerCivText[i], civ_text);
        mps_set_text(owner->playerColorText[i], color_text);
        mps_set_text(owner->playerTeamText[i], team_text);
    }
}

static void mps_update_option_buttons(TribeMPSetupScreen* owner) {
    if (!owner || !rge_base_game) return;
    TRIBE_Game* game = (TRIBE_Game*)rge_base_game;

    char value[256];
    char fmt[256];
    char line[320];

    const int map_size_resid = mps_map_size_resid((int)game->tribe_game_options.mapSizeValue);
    if (map_size_resid >= 0) {
        mps_get_string_safe(owner, map_size_resid, "Medium", value, sizeof(value));
    } else {
        strncpy(value, "Medium", sizeof(value) - 1);
        value[sizeof(value) - 1] = '\0';
    }
    mps_get_string_safe(owner, 0x25da, "Map Size: %s", fmt, sizeof(fmt));
    snprintf(line, sizeof(line), fmt, value);
    line[sizeof(line) - 1] = '\0';
    mps_set_button_text(owner->hiddenMapButton, line);

    const int map_type_resid = mps_map_type_resid((int)game->tribe_game_options.mapTypeValue);
    if (map_type_resid >= 0) {
        mps_get_string_safe(owner, map_type_resid, "Inland", value, sizeof(value));
    } else {
        strncpy(value, "Inland", sizeof(value) - 1);
        value[sizeof(value) - 1] = '\0';
    }
    mps_get_string_safe(owner, 0x25b6, "Map Type: %s", fmt, sizeof(fmt));
    snprintf(line, sizeof(line), fmt, value);
    line[sizeof(line) - 1] = '\0';
    mps_set_button_text(owner->ready_button, line);

    mps_get_string_safe(owner, 0x2bd0 + (int)rge_base_game->rge_game_options.difficultyValue, "Hardest", value, sizeof(value));
    mps_get_string_safe(owner, 0x25e0, "Difficulty Level: %s", fmt, sizeof(fmt));
    snprintf(line, sizeof(line), fmt, value);
    line[sizeof(line) - 1] = '\0';
    mps_set_button_text(owner->readyButtons[0], line);

    if ((int)game->tribe_game_options.resourceLevelValue == 0) {
        mps_get_string_safe(owner, 0x10e7, "Default", value, sizeof(value));
    } else {
        mps_get_string_safe(owner, 0x25e5 + (int)game->tribe_game_options.resourceLevelValue, "Default", value, sizeof(value));
    }
    mps_get_string_safe(owner, 0x25e5, "Resources: %s", fmt, sizeof(fmt));
    snprintf(line, sizeof(line), fmt, value);
    line[sizeof(line) - 1] = '\0';
    mps_set_button_text(owner->readyButtons[1], line);

    mps_get_string_safe(owner, 0x25b7, "Players:", fmt, sizeof(fmt));
    snprintf(line, sizeof(line), "%s %d", fmt, mps_clamp((int)rge_base_game->rge_game_options.numberPlayersValue, 2, 8));
    line[sizeof(line) - 1] = '\0';
    mps_set_button_text(owner->netInfoButton, line);
}

static void mps_update_summary(TribeMPSetupScreen* owner) {
    if (!owner || !rge_base_game) return;
    TRIBE_Game* game = (TRIBE_Game*)rge_base_game;

    char value[256];
    char fmt[256];
    char line[320];

    const int scenario_game = (int)rge_base_game->rge_game_options.scenarioGameValue;
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

    mps_get_string_safe(owner, 0x25b7, "Players:", fmt, sizeof(fmt));
    snprintf(line, sizeof(line), "%s %d", fmt, mps_clamp((int)rge_base_game->rge_game_options.numberPlayersValue, 2, 8));
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
}

static void mps_refresh_ui(TribeMPSetupScreen* owner) {
    mps_update_player_rows(owner);
    mps_update_option_buttons(owner);
    mps_update_summary(owner);
}

void mps_enable_input() {
    if (!rge_base_game) return;
    rge_base_game->enable_input();
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

    HWND wnd = (rge_base_game && rge_base_game->prog_window) ? (HWND)rge_base_game->prog_window : NULL;
    MessageBoxA(wnd, text, "Age of Empires", MB_OK | MB_ICONINFORMATION);
}

void mps_popup_text(const char* text) {
    const char* safe = (text && text[0] != '\0') ? text : "No message.";
    HWND wnd = (rge_base_game && rge_base_game->prog_window) ? (HWND)rge_base_game->prog_window : NULL;
    MessageBoxA(wnd, safe, "Age of Empires", MB_OK | MB_ICONINFORMATION);
}

int mps_start_game_single_player(TribeMPSetupScreen* owner) {
    if (!owner || !rge_base_game) {
        return 0;
    }

    // Single-player scope for this branch:
    // keep multiplayer start unimplemented for now as requested in project scope.
    if (rge_base_game->rge_game_options.multiplayerGameValue != 0) {
        mps_popup_resid(owner, 0x9ca, "Multiplayer start is not implemented in this branch yet.");
        return 0;
    }

    // `scr_mps.cpp.asm/.decomp`: startGame validates scenario metadata before launch.
    if ((rge_base_game->rge_game_options.scenarioGameValue != 0) && (owner->scenarioInfo == nullptr)) {
        mps_popup_resid(owner, 0x25c2, "The selected scenario is invalid.");
        return 0;
    }

    TRIBE_Game* game = (TRIBE_Game*)rge_base_game;
    if (!game->start_game(0)) {
        // language.dll(0x961): "An error occurred while trying to start the game."
        mps_popup_resid(owner, 0x961, "An error occurred while trying to start the game.");
        return 0;
    }

    return 1;
}

} // namespace

TribeMPSetupScreen::TribeMPSetupScreen() : TScreenPanel((char*)"MP Setup Screen") {
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
    this->scenarioPlayerCount = 0;
    this->myCivilization = 0;
    this->myScenarioPlayer = 0;
    this->myPlayerColor = 0;
    this->myPlayerTeam = 0;
    this->myScenarioChecksum = 0;
    this->saveScenarioName[0] = '\0';
    this->saveRandomGame = 0;
    this->saveScenarioChecksum = 0;
    this->scenarioInfo = nullptr;
    this->settingsFixed = 0;
    this->numberAnyPlayers = 0;
    this->sent_cd_status = 0;
    this->netInfoButton = nullptr;
    this->i_am_ready = 0;
    this->last_send_shared = 0;
    this->resend_game_options = 0;

    if (!rge_base_game || !rge_base_game->draw_area) {
        this->error_code = 1;
        return;
    }

    char* setup_name = (rge_base_game->rge_game_options.multiplayerGameValue != 0) ? (char*)"scr3" : (char*)"scr2";
    long setup_id = (rge_base_game->rge_game_options.multiplayerGameValue != 0) ? 0xc385 : 0xc384;
    if (!TEasy_Panel::setup(rge_base_game->draw_area, (TPanel*)0, setup_name, setup_id, 1, 0, 0, 0, 0, 1)) {
        this->error_code = 1;
        return;
    }

    this->setup_shadow_area(0);
    this->set_ideal_size(0x280, 0x1e0);

    const int title_resid = 0x25cf - ((rge_base_game->rge_game_options.multiplayerGameValue != 0) ? 1 : 0);
    if (!this->create_text((TPanel*)this, &this->title, title_resid, 0x14, 0x6, 600, 0x1e, 1, 1, 0, 0)) {
        this->error_code = 1;
        return;
    }

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

    int row_y = 0x57;
    for (int i = 0; i < 8; ++i) {
        if (!this->create_text((TPanel*)this, &this->playerNameText[i], (char*)"", 0x1c, row_y, 0x8b, 0x16, 0xb, 0, 0, 0) ||
            !this->create_text((TPanel*)this, &this->playerCivText[i], (char*)"", 0xbf, row_y, 0x6d, 0x16, 0xb, 0, 0, 0) ||
            !this->create_text((TPanel*)this, &this->playerColorText[i], (char*)"", 0x131, row_y, 0x28, 0x16, 0xb, 1, 1, 0) ||
            !this->create_text((TPanel*)this, &this->playerTeamText[i], (char*)"", 0x177, row_y, 0x28, 0x16, 0xb, 1, 1, 0)) {
            this->error_code = 1;
            return;
        }
        row_y += 0x18;
    }

    if (!this->create_button((TPanel*)this, &this->gameSettingsButton, 0x25d2, 0, 0x1a4, 0x32, 0xd2, 0x1e, 0, 0, 0)) {
        this->error_code = 1;
        return;
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
    if (!this->create_button((TPanel*)this, &this->hiddenMapButton, (char*)"", (char*)0, 0x1a, 0x142, 0x172, 0x16, 0xb, 0, 0) ||
        !this->create_button((TPanel*)this, &this->ready_button, (char*)"", (char*)0, 0x1a, 0x15a, 0x172, 0x16, 0xb, 0, 0) ||
        !this->create_button((TPanel*)this, &this->readyButtons[0], (char*)"", (char*)0, 0x1a, 0x172, 0x172, 0x16, 0xb, 0, 0) ||
        !this->create_button((TPanel*)this, &this->readyButtons[1], (char*)"", (char*)0, 0x1a, 0x18a, 0x172, 0x16, 0xb, 0, 0) ||
        !this->create_button((TPanel*)this, &this->netInfoButton, (char*)"", (char*)0, 0x1a, 0x1a2, 0x172, 0x16, 0xb, 0, 0)) {
        this->error_code = 1;
        return;
    }

    if (!this->create_button((TPanel*)this, &this->startButton, (char*)"", (char*)0, 0x46, 0x1b8, 0xf0, 0x1e, 0, 0, 0)) {
        this->error_code = 1;
        return;
    }
    this->startButton->set_text(0, 0x25ee);

    if (!this->create_button((TPanel*)this, &this->cancelButton, 0xfa2, 0, 0x14a, 0x1b8, 0xf0, 0x1e, 0, 0, 0)) {
        this->error_code = 1;
        return;
    }

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

    TPanel* tab_list[9];
    tab_list[0] = (TPanel*)this->hiddenMapButton;
    tab_list[1] = (TPanel*)this->ready_button;
    tab_list[2] = (TPanel*)this->readyButtons[0];
    tab_list[3] = (TPanel*)this->readyButtons[1];
    tab_list[4] = (TPanel*)this->netInfoButton;
    tab_list[5] = (TPanel*)this->gameSettingsButton;
    tab_list[6] = (TPanel*)this->startButton;
    tab_list[7] = (TPanel*)this->cancelButton;
    tab_list[8] = (TPanel*)this->help_button;
    this->set_tab_order(tab_list, 9);

    mps_refresh_ui(this);
}

TribeMPSetupScreen::~TribeMPSetupScreen() {}

long TribeMPSetupScreen::handle_idle() {
    if (rge_base_game && rge_base_game->input_enabled == 0) {
        rge_base_game->enable_input();
    }
    return TPanel::handle_idle();
}

long TribeMPSetupScreen::action(TPanel* param_1, long param_2, ulong param_3, ulong param_4) {
    if (param_1 && (param_2 == 1)) {
        TRIBE_Game* game = (TRIBE_Game*)rge_base_game;

        if ((TButtonPanel*)param_1 == this->hiddenMapButton) {
            int map_size = (int)game->tribe_game_options.mapSizeValue;
            map_size = (map_size + 1) % 6;
            game->setMapSize((MapSize)map_size);
            mps_refresh_ui(this);
            return 1;
        }

        if ((TButtonPanel*)param_1 == this->ready_button) {
            int map_type = (int)game->tribe_game_options.mapTypeValue;
            map_type = (map_type + 1) % 9;
            game->setMapType((MapType)map_type);
            mps_refresh_ui(this);
            return 1;
        }

        if ((TButtonPanel*)param_1 == this->readyButtons[0]) {
            int diff = (int)rge_base_game->rge_game_options.difficultyValue;
            diff = (diff + 1) % 5;
            rge_base_game->setDifficulty(diff);
            mps_refresh_ui(this);
            return 1;
        }

        if ((TButtonPanel*)param_1 == this->readyButtons[1]) {
            int resources = (int)game->tribe_game_options.resourceLevelValue;
            resources = (resources + 1) % 4;
            game->setResourceLevel((ResourceLevel)resources);
            mps_refresh_ui(this);
            return 1;
        }

        if ((TButtonPanel*)param_1 == this->netInfoButton) {
            int players = mps_clamp((int)rge_base_game->rge_game_options.numberPlayersValue, 2, 8);
            players += 1;
            if (players > 8) players = 2;
            rge_base_game->setNumberPlayers(players);
            mps_refresh_ui(this);
            return 1;
        }

        if ((TButtonPanel*)param_1 == this->gameSettingsButton) {
            // TODO(accuracy): route to real `TribeGameSettingsScreen` from `scr_set` once
            // `TEasy_Panel::create_drop_down/create_edit/create_list/create_scrollbar` are reimplemented.
            mps_popup_text("Use the inline option buttons under the player list to configure Random Map settings.");
            return 1;
        }

        if ((TButtonPanel*)param_1 == this->startButton) {
            rge_base_game->disable_input();

            if (!mps_start_game_single_player(this)) {
                mps_enable_input();
            }
            return 1;
        }

        if ((TButtonPanel*)param_1 == this->cancelButton) {
            rge_base_game->disable_input();

            TribeSPMenuScreen* menu = new TribeSPMenuScreen();
            if (menu && menu->error_code == 0) {
                tribe_queue_screen_switch(menu);
            } else {
                if (menu) delete menu;
                mps_enable_input();
            }
            return 1;
        }

        if ((TButtonPanel*)param_1 == this->help_button) {
            mps_popup_resid(this, 0x23f5, "Help is not implemented in this screen yet.");
            return 1;
        }

        if ((TButtonPanel*)param_1 == this->close_button) {
            rge_base_game->close();
            return 1;
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

