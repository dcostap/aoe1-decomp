/* scr_set.cpp - TribeGameSettingsScreen implementation
 * Source-of-truth: scr_set.cpp.decomp, scr_set.cpp.asm, TribeGameSettingsScreen.h
 *
 * This implements the "Game Settings Screen" opened from the SP/MP setup screen
 * when the user clicks the "Settings" button.
 *
 * The constructor does ALL setup work (matching the original binary):
 *   1. TScreenPanel("Game Settings Screen") registers with panel_system
 *   2. init_vars() zeroes all member pointers
 *   3. TEasy_Panel::setup() loads background SLP
 *   4. UI panels created with exact language.dll string IDs from decomp
 *   5. fillScenarios / getSettings / fillMissionText / activatePanels
 */

#include "TribeGameSettingsScreen.h"
#include "TribeMPSetupScreen.h"
#include "TDropDownPanel.h"
#include "ui_core.h"
#include "TTextPanel.h"
#include "TListPanel.h"
#include "TScrollBarPanel.h"
#include "TPanelSystem.h"
#include "TRIBE_Game.h"
#include "globals.h"
#include "custom_debug.h"

// ============================================================================
// init_vars  (decomp @ 0x004B5810)
// ============================================================================
void TribeGameSettingsScreen::init_vars()
{
    this->title = nullptr;
    this->mapSizeLabel = nullptr;
    this->mapSizeDrop = nullptr;
    this->mapTypeLabel = nullptr;
    this->mapTypeDrop = nullptr;
    this->victoryTypeLabel = nullptr;
    this->victoryTypeDrop = nullptr;
    this->scoreLabel = nullptr;
    this->scoreDrop = nullptr;
    this->timeLabel = nullptr;
    this->timeDrop = nullptr;
    this->victoryFixedText = nullptr;
    this->difficultyLabel = nullptr;
    this->difficultyDrop = nullptr;
    this->ageLabel = nullptr;
    this->ageDrop = nullptr;
    this->limitLabel = nullptr;
    this->limitDrop = nullptr;
    this->resourcesLabel = nullptr;
    this->resourcesDrop = nullptr;
    this->pathingLabel = nullptr;
    this->pathingDrop = nullptr;
    this->scenarioTitle = nullptr;
    this->scenarioPlayersTitle = nullptr;
    this->scenarioList = nullptr;
    this->scenarioScrollbar = nullptr;
    this->scenarioCount = 0;
    this->scenarioMission = nullptr;
    this->scenarioFixed = nullptr;
    this->scenariosLoaded = 0;
    this->missionTitle = nullptr;
    this->missionText = nullptr;
    this->missionScrollbar = nullptr;
    this->percentLabel = nullptr;
    for (int i = 0; i < 4; ++i) {
        this->optionButton[i] = nullptr;
        this->optionText[i] = nullptr;
    }
    this->okButton = nullptr;
    this->cancelButton = nullptr;
    this->help_button = nullptr;
    this->chat_scr = nullptr;
    this->last_scenario_line = -1;
    this->scenario_line_offset = 0;
    this->last_send_shared = 0;
}

// ============================================================================
// Constructor  (decomp @ 0x004B4880)
//
// The constructor does ALL work: registers with panel_system via
// TScreenPanel("Game Settings Screen"), loads background, creates every
// UI panel with the exact language.dll IDs from the ASM/decomp.
// ============================================================================
TribeGameSettingsScreen::TribeGameSettingsScreen()
    : TScreenPanel((char*)"Game Settings Screen")
{
    CUSTOM_DEBUG_FUNC_ENTER();

    // Decomp: init_vars(this)
    init_vars();

    // Decomp: this->chat_scr = TPanelSystem::panel(&panel_system, "MP Setup Screen")
    this->chat_scr = (TribeMPSetupScreen*)panel_system->panel((char*)"MP Setup Screen");

    // Decomp: choose background SLP - "scr2" for SP, "scr3" for MP
    char* bg_name = (char*)"scr2";
    if (rge_base_game->rge_game_options.multiplayerGameValue != 0) {
        bg_name = (char*)"scr3";
    }

    // Decomp: TEasy_Panel::setup(this, draw_area, nullptr, bg_name, 0xc384 + (mp!=0), 1, 0, 0, 0, 0, 1)
    // 0xc384 = 50052 (background SLP ID for SP), +1 for MP
    long bg_id = 0xc384;
    if (rge_base_game->rge_game_options.multiplayerGameValue != 0) {
        bg_id = 0xc385;
    }
    long result = this->TEasy_Panel::setup(
        rge_base_game->draw_area, (TPanel*)nullptr, bg_name, bg_id,
        1, 0, 0, 0, 0, 1
    );
    if (result == 0) {
        // Decomp: this->error_code = 1; return;
        this->error_code = 1;
        return;
    }

    // Decomp: setup_shadow_area(0), set_ideal_size(0x280, 0x1e0) = 640x480
    this->setup_shadow_area(0);
    this->set_ideal_size(0x280, 0x1e0);

    int iVar9;
    // ---- Title: "Scenario Settings" (0x2616) ----
    // Decomp: create_text(this, this, &title, 0x2616, 0x14, 10, 600, 0x1e, 1, 1, 0, 1)
    iVar9 = this->create_text((TPanel*)this, &this->title, 0x2616, 0x14, 10, 600, 0x1e, 1, 1, 0, 1);
    if (iVar9 == 0) goto fail;

    // ---- Map Size label (0x29a0) ----
    iVar9 = this->create_text((TPanel*)this, &this->mapSizeLabel, 0x29a0, 0x14, 0xd8, 0xb4, 0x14, 0xb, 0, 0, 0);
    if (iVar9 == 0) goto fail;

    // ---- Map Size dropdown ----
    iVar9 = this->create_drop_down((TPanel*)this, &this->mapSizeDrop, 0xb4, 100, 0x14, 0xec, 0xb4, 0x18, 0xb);
    if (iVar9 == 0) goto fail;
    this->mapSizeDrop->empty_list();
    this->mapSizeDrop->append_line((long)0x2973, 0);  // "Tiny"
    this->mapSizeDrop->append_line((long)0x2974, 1);  // "Small"
    this->mapSizeDrop->append_line((long)0x2975, 2);  // "Medium"
    this->mapSizeDrop->append_line((long)0x2976, 3);  // "Large"
    this->mapSizeDrop->append_line((long)0x2977, 4);  // "Huge"
    this->mapSizeDrop->append_line((long)0x2978, 5);  // "Gigantic"
    this->mapSizeDrop->set_help_info(0x762a, -1);

    // ---- Map Type label (0x25db) ----
    iVar9 = this->create_text((TPanel*)this, &this->mapTypeLabel, 0x25db, 0xdc, 0xd8, 0xb4, 0x14, 0xb, 0, 0, 0);
    if (iVar9 == 0) goto fail;

    // ---- Map Type dropdown ----
    iVar9 = this->create_drop_down((TPanel*)this, &this->mapTypeDrop, 0xb4, 100, 0xdc, 0xec, 0xb4, 0x18, 0xb);
    if (iVar9 == 0) goto fail;
    this->mapTypeDrop->empty_list();
    this->mapTypeDrop->append_line((long)0x296a, 0);  // "Small Islands"
    this->mapTypeDrop->append_line((long)0x296b, 1);  // "Large Islands"
    this->mapTypeDrop->append_line((long)0x296c, 2);  // "Coastal"
    this->mapTypeDrop->append_line((long)0x296d, 3);  // "Inland"
    this->mapTypeDrop->append_line((long)0x296e, 4);  // "Highland"
    this->mapTypeDrop->append_line((long)0x296f, 5);  // "Continental"
    this->mapTypeDrop->append_line((long)0x2970, 6);  // "Mediterranean"
    this->mapTypeDrop->append_line((long)0x2971, 7);  // "Hill Country"
    this->mapTypeDrop->append_line((long)0x2972, 8);  // "Narrows"
    this->mapTypeDrop->set_help_info(0x762b, -1);

    // ---- Victory Condition label (0x2a34) ----
    iVar9 = this->create_text((TPanel*)this, &this->victoryTypeLabel, 0x2a34, 0x14, 0x108, 0xb4, 0x14, 0xb, 0, 0, 0);
    if (iVar9 == 0) goto fail;

    // ---- Victory Condition dropdown ----
    iVar9 = this->create_drop_down((TPanel*)this, &this->victoryTypeDrop, 0xb4, 100, 0x14, 0x11c, 0xb4, 0x18, 0xb);
    if (iVar9 == 0) goto fail;
    this->victoryTypeDrop->empty_list();
    // Decomp: if scenarioGame, prepend "Default" with id=0, then lVar12=9
    if (rge_base_game->rge_game_options.scenarioGameValue != 0) {
        this->victoryTypeDrop->append_line((long)0x10e7, 0);  // "Default"
    }
    {
        long std_id = (rge_base_game->rge_game_options.scenarioGameValue != 0) ? 9 : 0;
        this->victoryTypeDrop->append_line((long)0x10ec, std_id);  // "Standard"
    }
    this->victoryTypeDrop->append_line((long)0x10e1, 1);  // "Conquest"
    this->victoryTypeDrop->append_line((long)0x10e9, 7);  // "Time Limit"
    this->victoryTypeDrop->append_line((long)0x10ea, 8);  // "Score"
    this->victoryTypeDrop->set_help_info(0x762c, 0x25f0a);

    // ---- Time Limit label (0x10e9) ----
    iVar9 = this->create_text((TPanel*)this, &this->timeLabel, 0x10e9, 0x14, 0x138, 0xb4, 0x14, 0xb, 0, 0, 0);
    if (iVar9 == 0) goto fail;

    // ---- Time Limit dropdown ----
    iVar9 = this->create_drop_down((TPanel*)this, &this->timeDrop, 0xb4, 100, 0x14, 0x14c, 0xb4, 0x18, 0xb);
    if (iVar9 == 0) goto fail;
    this->timeDrop->empty_list();
    this->timeDrop->append_line((long)0x2634, 15000);  // "15,000 years (2:00 hr)"
    this->timeDrop->append_line((long)0x2635, 13000);  // "13,000 years (1:45 hr)"
    this->timeDrop->append_line((long)0x2636, 11000);  // "11,000 years (1:30 hr)"
    this->timeDrop->append_line((long)0x2637, 9000);   // "9,000 years (1:15 hr)"
    this->timeDrop->append_line((long)0x2638, 7000);   // "7,000 years (60 min)"
    this->timeDrop->append_line((long)0x2639, 5000);   // "5,000 years (40 min)"
    this->timeDrop->append_line((long)0x263a, 3000);   // "3,000 years (25 min)"
    this->timeDrop->set_help_info(0x763b, -1);

    // ---- Score label (0x10ea) ----
    iVar9 = this->create_text((TPanel*)this, &this->scoreLabel, 0x10ea, 0x14, 0x138, 0xb4, 0x14, 0xb, 0, 0, 0);
    if (iVar9 == 0) goto fail;

    // ---- Score dropdown ----
    iVar9 = this->create_drop_down((TPanel*)this, &this->scoreDrop, 0xb4, 100, 0x14, 0x14c, 0xb4, 0x18, 0xb);
    if (iVar9 == 0) goto fail;
    this->scoreDrop->empty_list();
    this->scoreDrop->append_line((char*)"3000", 3000);
    this->scoreDrop->append_line((char*)"2700", 0xa8c);
    this->scoreDrop->append_line((char*)"2400", 0x960);
    this->scoreDrop->append_line((char*)"2100", 0x834);
    this->scoreDrop->append_line((char*)"1800", 0x708);
    this->scoreDrop->append_line((char*)"1500", 0x5dc);
    this->scoreDrop->append_line((char*)"1200", 0x4b0);
    this->scoreDrop->append_line((char*)"900", 900);
    this->scoreDrop->append_line((char*)"800", 800);
    this->scoreDrop->append_line((char*)"700", 700);
    this->scoreDrop->append_line((char*)"600", 600);
    this->scoreDrop->append_line((char*)"500", 500);
    this->scoreDrop->append_line((char*)"400", 400);
    this->scoreDrop->append_line((char*)"300", 300);
    this->scoreDrop->set_help_info(0x763c, -1);

    // ---- Victory Fixed Text (0x25d9) ----
    iVar9 = this->create_text((TPanel*)this, &this->victoryFixedText, 0x25d9, 0x14, 0x108, 0xb4, 0x5c, 0xb, 1, 1, 0);
    if (iVar9 == 0) goto fail;
    // TODO: decomp calls victoryFixedText vtable+0xec (set_text_color) here; skipping for now

    // ---- Starting Age label (0x2606) ----
    iVar9 = this->create_text((TPanel*)this, &this->ageLabel, 0x2606, 0xdc, 0x108, 0xb4, 0x14, 0xb, 0, 0, 0);
    if (iVar9 == 0) goto fail;

    // ---- Starting Age dropdown ----
    iVar9 = this->create_drop_down((TPanel*)this, &this->ageDrop, 0xb4, 100, 0xdc, 0x11c, 0xb4, 0x18, 0xb);
    if (iVar9 == 0) goto fail;
    this->ageDrop->empty_list();
    this->ageDrop->append_line((long)0x10e7, 0);  // "Default"
    this->ageDrop->append_line((long)0x106e, 1);  // "Nomad"
    this->ageDrop->append_line((long)0x1069, 2);  // "Stone Age"
    this->ageDrop->append_line((long)0x106a, 3);  // "Tool Age"
    this->ageDrop->append_line((long)0x106b, 4);  // "Bronze Age"
    this->ageDrop->append_line((long)0x106c, 5);  // "Iron Age"
    this->ageDrop->set_help_info(0x7631, -1);

    // ---- Resources label (0x2607) ----
    iVar9 = this->create_text((TPanel*)this, &this->resourcesLabel, 0x2607, 0xdc, 0x138, 0xb4, 0x14, 0xb, 0, 0, 0);
    if (iVar9 == 0) goto fail;

    // ---- Resources dropdown ----
    iVar9 = this->create_drop_down((TPanel*)this, &this->resourcesDrop, 0xb4, 100, 0xdc, 0x14c, 0xb4, 0x18, 0xb);
    if (iVar9 == 0) goto fail;
    this->resourcesDrop->empty_list();
    this->resourcesDrop->append_line((long)0x10e7, 0);  // "Default"
    this->resourcesDrop->append_line((long)0x2609, 2);  // "Medium"
    this->resourcesDrop->append_line((long)0x260a, 3);  // "High"
    this->resourcesDrop->set_help_info(0x7632, -1);

    // ---- Path Finding label (0x260d) ----
    iVar9 = this->create_text((TPanel*)this, &this->pathingLabel, 0x260d, 0x1a4, 0x138, 0xb4, 0x14, 0xb, 0, 0, 0);
    if (iVar9 == 0) goto fail;

    // ---- Path Finding dropdown ----
    iVar9 = this->create_drop_down((TPanel*)this, &this->pathingDrop, 0xb4, 100, 0x1a4, 0x14c, 0xb4, 0x18, 0xb);
    if (iVar9 == 0) goto fail;
    this->pathingDrop->empty_list();
    this->pathingDrop->append_line((long)0x260e, 0);  // "Default"
    this->pathingDrop->append_line((long)0x260f, 1);  // "Medium"
    this->pathingDrop->append_line((long)0x2610, 2);  // "High"
    this->pathingDrop->set_help_info(0x763e, -1);

    // ---- Population Limit (MP only) ----
    if (rge_base_game->rge_game_options.multiplayerGameValue != 0) {
        iVar9 = this->create_text((TPanel*)this, &this->limitLabel, 0x2613, 0x1a4, 0xd8, 0xb4, 0x14, 0xb, 0, 0, 0);
        if (iVar9 == 0) goto fail;
        iVar9 = this->create_drop_down((TPanel*)this, &this->limitDrop, 0xb4, 100, 0x1a4, 0xec, 0xb4, 0x18, 0xb);
        if (iVar9 == 0) goto fail;
        this->limitDrop->empty_list();
        {
            char num_str[8];
            for (int pop = 25; pop < 201; pop += 25) {
                sprintf(num_str, "%d", pop);
                this->limitDrop->append_line(num_str, pop);
            }
        }
        this->limitDrop->set_help_info(0x763f, -1);
    }

    // ---- Difficulty Level label (0x2bcf) ----
    iVar9 = this->create_text((TPanel*)this, &this->difficultyLabel, 0x2bcf, 0x1a4, 0x108, 0xb4, 0x14, 0xb, 0, 0, 0);
    if (iVar9 == 0) goto fail;

    // ---- Difficulty Level dropdown ----
    iVar9 = this->create_drop_down((TPanel*)this, &this->difficultyDrop, 0xb4, 100, 0x1a4, 0x11c, 0xb4, 0x18, 0xb);
    if (iVar9 == 0) goto fail;
    this->difficultyDrop->empty_list();
    this->difficultyDrop->append_line((long)0x2bd4, 4);  // "Easiest"
    this->difficultyDrop->append_line((long)0x2bd3, 3);  // "Easy"
    this->difficultyDrop->append_line((long)0x2bd2, 2);  // "Moderate"
    this->difficultyDrop->append_line((long)0x2bd1, 1);  // "Hard"
    this->difficultyDrop->append_line((long)0x2bd0, 0);  // "Hardest"
    this->difficultyDrop->set_help_info(0x763d, -1);

    // ---- Checkboxes: Fixed Positions, Reveal Map, Full Tech Tree, Enable Cheating ----
    // Option 0: Fixed Positions
    iVar9 = this->create_check_box((TPanel*)this, &this->optionButton[0], 10, 0x168, 0x1e, 0x1e, 0, 0);
    if (iVar9 == 0) goto fail;
    iVar9 = this->create_text((TPanel*)this, &this->optionText[0], 0x2601, 0x28, 0x168, 0xaa, 0x1e, 0xb, 0, 1, 0);
    if (iVar9 == 0) goto fail;
    this->optionButton[0]->set_help_info(0x7633, -1);

    // Option 2: Full Tech Tree
    iVar9 = this->create_check_box((TPanel*)this, &this->optionButton[2], 0xdc, 0x168, 0x1e, 0x1e, 0, 0);
    if (iVar9 == 0) goto fail;
    iVar9 = this->create_text((TPanel*)this, &this->optionText[2], 0x2604, 0xfa, 0x168, 0xaa, 0x1e, 0xb, 0, 1, 0);
    if (iVar9 == 0) goto fail;
    this->optionButton[2]->set_help_info(0x7637, -1);

    // Option 1: Reveal Map
    iVar9 = this->create_check_box((TPanel*)this, &this->optionButton[1], 0x1ae, 0x168, 0x1e, 0x1e, 0, 0);
    if (iVar9 == 0) goto fail;
    iVar9 = this->create_text((TPanel*)this, &this->optionText[1], 0x25fc, 0x1cc, 0x168, 0xaa, 0x1e, 0xb, 0, 1, 0);
    if (iVar9 == 0) goto fail;
    this->optionButton[1]->set_help_info(0x7634, -1);

    // Option 3: Enable Cheating (MP only)
    if (rge_base_game->rge_game_options.multiplayerGameValue != 0) {
        iVar9 = this->create_check_box((TPanel*)this, &this->optionButton[3], 0x1ae, 0x18b, 0x1e, 0x1e, 0, 0);
        if (iVar9 == 0) goto fail;
        iVar9 = this->create_text((TPanel*)this, &this->optionText[3], 0x25fb, 0x1cc, 0x18b, 0xa5, 0x1e, 0xb, 0, 1, 0);
        if (iVar9 == 0) goto fail;
        this->optionButton[3]->set_help_info(0x7638, -1);
    }

    // ---- Scenario list area ----
    this->scenarioListX = 0x14;
    this->scenarioListY = 0x3c;
    this->scenarioListWidth = 600;
    if (rge_base_game->rge_game_options.multiplayerGameValue == 0) {
        this->scenarioListHeight = 0x18;
    } else {
        this->scenarioListHeight = 0x6f;
    }

    iVar9 = this->create_list((TPanel*)this, &this->scenarioList,
        this->scenarioListX, this->scenarioListY,
        this->scenarioListWidth, this->scenarioListHeight, 0xb);
    if (iVar9 == 0) goto fail;

    // Decomp: for SP, scenarioList->selectable = 0, setDrawHighlightBar(0), set_spacer_size(0)
    if (rge_base_game->rge_game_options.multiplayerGameValue == 0) {
        // SP: list is not selectable, no highlight, no spacer
        // TODO: these are vtable calls in decomp; stubbing for now
    } else {
        // MP: "Loading list of scenarios..." and scrollbar
        // TODO: stub for MP scenario list
    }

    // ---- Scenario title text ----
    {
        int title_y = this->scenarioListY - 0x14;
        // Decomp: string ID depends on MP: (-(mp!=0) & 0xffffffde) + 0x2620
        // SP: 0x2620 = "Scenario", MP: 0x2620 - 0x22 = 0x25fe... 
        // Actually decomp: (-(uint)(iVar11 != 0) & 0xffffffde) + 0x2620
        // If MP: -1 & 0xffffffde = 0xffffffde, + 0x2620 = 0x25fe... that seems wrong
        // Let's use 0x2620 for SP (matches "Game Type" or similar)
        long title_resid = 0x2620;
        if (rge_base_game->rge_game_options.multiplayerGameValue != 0) {
            // Decomp: 0x2620 + 0xffffffde = 0x25fe... but 0x25fe doesn't match
            // Actually: -(1) = 0xFFFFFFFF, & 0xFFFFFFDE = 0xFFFFFFDE, + 0x2620 = overflow...
            // Re-reading: NEG EAX; SBB EAX,EAX gives -1 if mp, AND 0xFFFFFFDE = 0xFFFFFFDE
            // 0x2620 + (int)0xFFFFFFDE = 0x2620 - 0x22 = 0x25FE
            // But wait: 0x2620 - 34 = 0x25FE. Let's check: 0x2620 = 9760, -34 = 9726 = 0x25FE
            title_resid = 0x25FE;
        }
        iVar9 = this->create_text((TPanel*)this, &this->scenarioTitle,
            (int)title_resid, this->scenarioListX, title_y, 300, 0x14, 4, 0, 0, 0);
        if (iVar9 == 0) goto fail;
    }

    // ---- Scenario Players title ----
    {
        iVar9 = this->create_text((TPanel*)this, &this->scenarioPlayersTitle,
            0x25ff, this->scenarioListWidth - 0xdc + this->scenarioListX,
            this->scenarioListY - 0x14, 0xdc, 0x14, 4, 0, 0, 0);
        if (iVar9 == 0) goto fail;
        // TODO: decomp calls set_alignment(AlignTop, AlignRight) on scenarioPlayersTitle
    }

    // ---- Mission text area ----
    {
        int mission_y = this->scenarioListHeight + 0x18 + this->scenarioListY;
        this->missionTextWidth = this->scenarioListWidth;
        this->missionTextY = mission_y;
        this->missionTextX = this->scenarioListX;
        this->missionTextHeight = 0x104 - mission_y;

        // Mission title: "Scenario Instructions" (0x2600)
        iVar9 = this->create_text((TPanel*)this, &this->missionTitle,
            0x2600, this->scenarioListX, mission_y - 0x14, 300, 0x14, 4, 0, 0, 0);
        if (iVar9 == 0) goto fail;

        // Mission text panel
        iVar9 = this->create_text((TPanel*)this, &this->missionText,
            (char*)"", this->missionTextX, this->missionTextY,
            this->missionTextWidth, this->missionTextHeight, 0xb, 0, 0, 0);
        if (iVar9 == 0) goto fail;

        // TODO: decomp calls missionText vtable+0xec (set_text_color) here

        // Mission scrollbar
        iVar9 = this->create_auto_scrollbar(&this->missionScrollbar, this->missionText, 0x14);
        if (iVar9 == 0) goto fail;
        if (this->missionScrollbar) {
            this->missionScrollbar->set_help_info(0x763a, -1);
        }
    }

    // ---- OK button (0xfa1) ----
    iVar9 = this->create_button((TPanel*)this, &this->okButton, (long)0xfa1, 0, 0x3c, 0x1b8, 0xf0, 0x1e, 0, 0, 0);
    if (iVar9 == 0) goto fail;
    this->okButton->set_help_info(0x7531, -1);

    // ---- Cancel button (0xfa2) ----
    iVar9 = this->create_button((TPanel*)this, &this->cancelButton, (long)0xfa2, 0, 0x140, 0x1b8, 0xf0, 0x1e, 0, 0, 0);
    if (iVar9 == 0) goto fail;
    this->cancelButton->hotkey = 0x1b;  // ESC
    this->cancelButton->hotkey_shift = 0;
    this->cancelButton->set_help_info(0x7532, -1);

    // ---- Help button (0xfa9 = "?") ----
    iVar9 = this->create_button((TPanel*)this, &this->help_button, (long)0xfa9, 0, 0x244, 0x1b8, 0x1e, 0x1e, 0, 0, 0);
    if (iVar9 == 0) goto fail;

    // ---- Final init: fill scenarios, get settings, activate panels ----
    this->fillScenarios();
    this->scenariosLoaded = 1;
    this->getSettings();
    this->fillMissionText();
    this->activatePanels();
    this->set_curr_child((TPanel*)this->okButton);

    CUSTOM_DEBUG_LOG("TribeGameSettingsScreen constructed successfully");
    return;

fail:
    // Decomp: falls through to LAB_004b57d9 which just returns
    CUSTOM_DEBUG_LOG("TribeGameSettingsScreen: panel creation failed");
    return;
}

// ============================================================================
// Destructor  (decomp @ 0x004B5920)
// ============================================================================
TribeGameSettingsScreen::~TribeGameSettingsScreen()
{
    CUSTOM_DEBUG_FUNC_ENTER();

    // Decomp: delete_panel for each member in exact order
    this->delete_panel((TPanel**)&this->title);
    this->delete_panel((TPanel**)&this->mapSizeLabel);
    this->delete_panel((TPanel**)&this->mapSizeDrop);
    this->delete_panel((TPanel**)&this->mapTypeLabel);
    this->delete_panel((TPanel**)&this->mapTypeDrop);
    this->delete_panel((TPanel**)&this->victoryTypeLabel);
    this->delete_panel((TPanel**)&this->victoryTypeDrop);
    this->delete_panel((TPanel**)&this->timeDrop);
    this->delete_panel((TPanel**)&this->timeLabel);
    this->delete_panel((TPanel**)&this->scoreDrop);
    this->delete_panel((TPanel**)&this->scoreLabel);
    this->delete_panel((TPanel**)&this->victoryFixedText);
    this->delete_panel((TPanel**)&this->difficultyLabel);
    this->delete_panel((TPanel**)&this->difficultyDrop);
    this->delete_panel((TPanel**)&this->ageLabel);
    this->delete_panel((TPanel**)&this->ageDrop);
    this->delete_panel((TPanel**)&this->resourcesLabel);
    this->delete_panel((TPanel**)&this->resourcesDrop);
    this->delete_panel((TPanel**)&this->scenarioTitle);
    this->delete_panel((TPanel**)&this->scenarioPlayersTitle);
    this->delete_panel((TPanel**)&this->scenarioList);
    this->delete_panel((TPanel**)&this->scenarioScrollbar);
    this->delete_panel((TPanel**)&this->missionTitle);
    this->delete_panel((TPanel**)&this->missionText);
    this->delete_panel((TPanel**)&this->missionScrollbar);
    this->delete_panel((TPanel**)&this->pathingLabel);
    this->delete_panel((TPanel**)&this->pathingDrop);
    this->delete_panel((TPanel**)&this->limitLabel);
    this->delete_panel((TPanel**)&this->limitDrop);

    for (int i = 0; i < 4; ++i) {
        this->delete_panel((TPanel**)&this->optionButton[i]);
        this->delete_panel((TPanel**)&this->optionText[i]);
    }

    this->delete_panel((TPanel**)&this->okButton);
    this->delete_panel((TPanel**)&this->cancelButton);
    this->delete_panel((TPanel**)&this->help_button);

    // Free scenario data
    if (this->scenarioMission != nullptr) {
        for (int i = 0; i < this->scenarioCount; ++i) {
            if (this->scenarioMission[i] != nullptr) {
                free(this->scenarioMission[i]);
            }
        }
        free(this->scenarioMission);
    }
    if (this->scenarioFixed != nullptr) {
        free(this->scenarioFixed);
    }
}

// ============================================================================
// handle_idle  (decomp @ 0x004B5BB0)
// ============================================================================
long TribeGameSettingsScreen::handle_idle()
{
    // Decomp: if scenariosLoaded == 0, fill and activate
    if (this->scenariosLoaded == 0) {
        this->fillScenarios();
        this->fillMissionText();
        this->scenariosLoaded = 1;
        this->activatePanels();
        this->set_curr_child((TPanel*)this->scenarioList);
    }

    // Decomp: enable input if disabled
    if (rge_base_game->input_enabled == 0) {
        rge_base_game->enable_input();
    }

    // Decomp: MP shared data sending - skip for SP
    // TODO: implement MP shared data timing if needed

    return TPanel::handle_idle();
}

// ============================================================================
// handle_user_command  (decomp @ 0x004B5C70)
// ============================================================================
long TribeGameSettingsScreen::handle_user_command(uint param_1, long param_2)
{
    // Decomp: delegate to chat_scr first if present
    if (this->chat_scr != nullptr) {
        long r = this->chat_scr->handle_user_command(param_1, param_2);
        if (r != 0) return r;
    }
    return TPanel::handle_user_command(param_1, param_2);
}

// ============================================================================
// action  (decomp @ 0x004B5CB0)
// ============================================================================
long TribeGameSettingsScreen::action(TPanel* param_1, long param_2, ulong param_3, ulong param_4)
{
    CUSTOM_DEBUG_BEGIN
    CUSTOM_DEBUG_LOG_FMT("TribeGameSettingsScreen::action param_1=%p param_2=%ld param_3=%lu param_4=%lu",
        param_1, param_2, param_3, param_4);
    CUSTOM_DEBUG_LOG_FMT("  okButton=%p cancelButton=%p help_button=%p victoryTypeDrop=%p scenarioList=%p",
        this->okButton, this->cancelButton, this->help_button, this->victoryTypeDrop, this->scenarioList);
    CUSTOM_DEBUG_LOG_FMT("  mapSizeDrop=%p mapTypeDrop=%p ageDrop=%p resourcesDrop=%p difficultyDrop=%p pathingDrop=%p",
        this->mapSizeDrop, this->mapTypeDrop, this->ageDrop, this->resourcesDrop, this->difficultyDrop, this->pathingDrop);
    CUSTOM_DEBUG_LOG_FMT("  timeDrop=%p scoreDrop=%p limitDrop=%p scenariosLoaded=%d",
        this->timeDrop, this->scoreDrop, this->limitDrop, this->scenariosLoaded);
    CUSTOM_DEBUG_END

    if (param_1 == nullptr || this->scenariosLoaded == 0) {
        return TEasy_Panel::action(param_1, param_2, param_3, param_4);
    }

    // OK button
    if ((TButtonPanel*)param_1 == this->okButton && param_2 == 1) {
        this->set_curr_child((TPanel*)this->scenarioList);
        this->sendSettings();
        // Decomp: chat_scr->action(this, 1, 0, 0) - notify parent we're done with OK
        if (this->chat_scr != nullptr) {
            this->chat_scr->action(this, 1, 0, 0);
        }
        return 1;
    }

    // Cancel button
    if ((TButtonPanel*)param_1 == this->cancelButton && param_2 == 1) {
        this->set_curr_child((TPanel*)this->scenarioList);
        this->getSettings();
        // Decomp: chat_scr->action(this, 0, 0, 0) - notify parent we cancelled
        if (this->chat_scr != nullptr) {
            this->chat_scr->action(this, 0, 0, 0);
        }
        return 1;
    }

    // Help button
    if ((TButtonPanel*)param_1 == this->help_button && param_2 == 1) {
        this->setup_popup_help();
        return 1;
    }

    // Victory type dropdown changed
    if ((TDropDownPanel*)param_1 == this->victoryTypeDrop && param_2 == 0) {
        long vic_id = this->victoryTypeDrop->get_id();
        if (vic_id == 7) {
            // Time victory selected - set time drop to line 3
            this->timeDrop->set_line(3);
        } else if (vic_id == 8) {
            // Score victory selected - set score drop to line 7
            this->scoreDrop->set_line(7);
        }
        this->activatePanels();
        return 1;
    }

    // Scenario list selection
    if ((TListPanel*)param_1 == this->scenarioList) {
        if (param_2 == 3) {
            return 1;
        }
        if (param_2 == 1) {
            this->fillMissionText();
            this->activatePanels();
        }
        return 1;
    }

    // Decomp @ 0x004B5DE2: fall through to TEasy_Panel::action for unhandled actions.
    // This is the correct behavior per the original game.
    return TEasy_Panel::action(param_1, param_2, param_3, param_4);
}

// ============================================================================
// fillScenarios  (decomp @ 0x004B5E00) - stub for SP
// ============================================================================
void TribeGameSettingsScreen::fillScenarios()
{
    // Decomp: empties scenario list, reloads scenario files, populates list
    // For SP random map, we just insert "Random Map" and optionally "Death Match"
    if (this->scenarioList == nullptr) return;

    // TODO: Full scenario loading requires RGE_Scenario_File_Info which is not yet implemented
    // For now, insert "Random Map" entry for SP
    this->scenario_line_offset = 0;

    if (rge_base_game->rge_game_options.multiplayerGameValue != 0 ||
        rge_base_game->rge_game_options.scenarioGameValue != 0) {
        // MP/scenario: would need full scenario enumeration
        // TODO: stub
    }

    // Decomp: insert "Random Map" at line 0 with id=-2 for SP random games
    // and "Death Match" at line 1 with id=-1 for death match
    TRIBE_Game* game = (TRIBE_Game*)rge_base_game;

    if (rge_base_game->rge_game_options.multiplayerGameValue != 0 ||
        (game->tribe_game_options.deathMatchValue == 0)) {
        // Decomp: insert "Random Map" (0x25b5) with id=-2
        this->scenarioList->append_line((long)0x25b5, -2);
        this->scenario_line_offset += -1;
    }

    if (rge_base_game->rge_game_options.multiplayerGameValue != 0 ||
        (game->tribe_game_options.deathMatchValue != 0)) {
        // Decomp: insert "Death Match" (0x2617) with id=-1
        this->scenarioList->append_line((long)0x2617, -1);
        this->scenario_line_offset += -1;
    }
}

// ============================================================================
// fillMissionText  (decomp @ 0x004B6160) - stub
// ============================================================================
void TribeGameSettingsScreen::fillMissionText()
{
    // Decomp: sets mission text based on selected scenario
    // For SP random map, shows description of random map or death match
    if (this->missionText == nullptr) return;

    // TODO: Full implementation requires TTextPanel vtable calls for set_text
    // For now, just set state based on scenario list selection
    // Decomp: if id==-2, show random map description (0x25dc)
    //         if id==-1, show death match description (0x2618)
    //         else show scenario mission text

    this->state = StateRandom;  // Default for SP
    this->last_scenario_line = 0;
}

// ============================================================================
// getSettings  (decomp @ 0x004B6230)
// ============================================================================
void TribeGameSettingsScreen::getSettings()
{
    CUSTOM_DEBUG_FUNC_ENTER();
    if (!rge_base_game) return;

    TRIBE_Game* game = (TRIBE_Game*)rge_base_game;

    // Decomp: set state based on scenarioGame
    if (rge_base_game->rge_game_options.scenarioGameValue == 0) {
        this->state = StateRandom;
    } else {
        this->state = StateScenario;
    }
    this->last_scenario_line = 0;

    // Decomp: scroll scenario list to current game type
    // For SP random: scroll to line 0 (Random Map) or 1 (Death Match)
    if (this->state == StateRandom) {
        // Decomp: if deathMatch, sVar12=1 else sVar12=0
        // TODO: scroll_cur_line on scenarioList
    }

    // Decomp: set dropdown values from game options using get_line(value) then set_line
    if (this->mapSizeDrop) {
        long line = this->mapSizeDrop->get_line((long)game->tribe_game_options.mapSizeValue);
        this->mapSizeDrop->set_line(line);
    }
    if (this->mapTypeDrop) {
        long line = this->mapTypeDrop->get_line((long)game->tribe_game_options.mapTypeValue);
        this->mapTypeDrop->set_line(line);
    }
    if (this->victoryTypeDrop) {
        long line = this->victoryTypeDrop->get_line((long)game->tribe_game_options.victoryTypeValue);
        this->victoryTypeDrop->set_line(line);
    }

    // Decomp: option buttons use vtable+0xe0 (set_state via checkbox)
    if (this->optionButton[3] != nullptr) {
        this->optionButton[3]->set_state((short)rge_base_game->rge_game_options.allowCheatCodesValue);
    }
    if (this->optionButton[1] != nullptr) {
        this->optionButton[1]->set_state((short)rge_base_game->rge_game_options.fullVisibilityValue);
    }
    if (this->optionButton[0] != nullptr) {
        this->optionButton[0]->set_state((short)(game->tribe_game_options.randomizePositionsValue == 0 ? 1 : 0));
    }
    if (this->optionButton[2] != nullptr) {
        this->optionButton[2]->set_state((short)game->tribe_game_options.fullTechTreeValue);
    }

    if (this->resourcesDrop) {
        long line = this->resourcesDrop->get_line((long)game->tribe_game_options.resourceLevelValue);
        this->resourcesDrop->set_line(line);
    }
    if (this->ageDrop) {
        long line = this->ageDrop->get_line((long)game->tribe_game_options.startingAgeValue);
        this->ageDrop->set_line(line);
    }
    if (this->difficultyDrop) {
        long line = this->difficultyDrop->get_line((long)rge_base_game->rge_game_options.difficultyValue);
        this->difficultyDrop->set_line(line);
    }

    // Pathfinding
    if (this->pathingDrop) {
        unsigned char pf = rge_base_game->pathFindingValue;
        if (rge_base_game->rge_game_options.multiplayerGameValue != 0) {
            pf = rge_base_game->rge_game_options.mpPathFindingValue;
        }
        long line = this->pathingDrop->get_line((long)(unsigned int)pf);
        this->pathingDrop->set_line(line);
    }

    // Population limit (MP only)
    if (rge_base_game->rge_game_options.multiplayerGameValue != 0 && this->limitDrop) {
        long line = this->limitDrop->get_line((long)(unsigned int)game->tribe_game_options.popLimitValue);
        this->limitDrop->set_line(line);
    }

    // Victory amount for time/score
    if ((VictoryType)game->tribe_game_options.victoryTypeValue == 7) {  // VictoryTime
        if (this->timeDrop) {
            long line = this->timeDrop->get_line((long)game->tribe_game_options.victoryAmountValue);
            this->timeDrop->set_line(line);
        }
    } else if ((VictoryType)game->tribe_game_options.victoryTypeValue == 8) {  // VictoryScore
        if (this->scoreDrop) {
            long line = this->scoreDrop->get_line((long)game->tribe_game_options.victoryAmountValue);
            this->scoreDrop->set_line(line);
        }
    }
}

// ============================================================================
// sendSettings  (decomp @ 0x004B6500)
// ============================================================================
void TribeGameSettingsScreen::sendSettings()
{
    CUSTOM_DEBUG_FUNC_ENTER();
    if (!rge_base_game) return;

    TRIBE_Game* game = (TRIBE_Game*)rge_base_game;

    // Decomp: check scenario list selection
    // For SP random map, id < 0 means random/death match
    long scenario_id = -2;  // Default: random map (no scenario list interaction yet)
    // TODO: get actual id from scenarioList when scenario selection is implemented

    if (scenario_id < 0) {
        rge_base_game->setScenarioGame(0);
        rge_base_game->setScenarioName((char*)"");
    } else {
        rge_base_game->setScenarioGame(1);
        // TODO: get scenario name from list
    }

    // Decomp: setDeathMatch(id == -1)
    game->setDeathMatch(scenario_id == -1 ? 1 : 0);

    // Victory type and amount
    if (this->victoryTypeDrop) {
        long vic_id = this->victoryTypeDrop->get_id();
        VictoryType vtype;
        long vamount;

        if (vic_id == 7) {
            // Time victory
            vamount = this->timeDrop ? this->timeDrop->get_id() : 15000;
            vtype = (VictoryType)7;
        } else if (vic_id == 8) {
            // Score victory
            vamount = this->scoreDrop ? this->scoreDrop->get_id() : 3000;
            vtype = (VictoryType)8;
        } else {
            vamount = 1;
            vtype = (VictoryType)this->victoryTypeDrop->get_id();
        }
        game->setVictoryType(vtype, (int)vamount);
    }

    // Map settings (only for random games)
    // Decomp: if randomGame() != 0
    if (rge_base_game->rge_game_options.scenarioGameValue == 0) {
        if (this->mapSizeDrop) {
            game->setMapSize((MapSize)this->mapSizeDrop->get_id());
        }
        if (this->mapTypeDrop) {
            game->setMapType((MapType)this->mapTypeDrop->get_id());
        }
    }

    // Option flags
    if (this->optionButton[3] != nullptr) {
        rge_base_game->setAllowCheatCodes(this->optionButton[3]->get_state());
    }
    if (this->optionButton[1] != nullptr) {
        rge_base_game->setFullVisibility(this->optionButton[1]->get_state());
    }
    if (this->optionButton[0] != nullptr) {
        game->setRandomizePositions(this->optionButton[0]->get_state() == 0 ? 1 : 0);
    }
    if (this->optionButton[2] != nullptr) {
        game->setFullTechTree(this->optionButton[2]->get_state());
    }

    // Resources
    if (this->resourcesDrop) {
        // Decomp: if death match (id==-1), use DefaultResources, else use dropdown
        if (scenario_id == -1) {
            game->setResourceLevel((ResourceLevel)0);  // DefaultResources
        } else {
            game->setResourceLevel((ResourceLevel)this->resourcesDrop->get_id());
        }
    }

    // Pathfinding
    if (this->pathingDrop) {
        if (rge_base_game->rge_game_options.multiplayerGameValue == 0) {
            rge_base_game->setPathFinding((unsigned char)this->pathingDrop->get_id());
        } else {
            rge_base_game->setMpPathFinding((unsigned char)this->pathingDrop->get_id());
        }
    }

    // Population limit (MP only)
    if (rge_base_game->rge_game_options.multiplayerGameValue != 0 && this->limitDrop) {
        game->setPopLimit((unsigned char)this->limitDrop->get_id());
    }

    // Starting age
    if (this->ageDrop) {
        game->setStartingAge((Age)this->ageDrop->get_id());
    }

    // Difficulty
    if (this->difficultyDrop) {
        rge_base_game->setDifficulty((int)this->difficultyDrop->get_id());
        if (rge_base_game->rge_game_options.singlePlayerGameValue != 0) {
            rge_base_game->single_player_difficulty = (int)this->difficultyDrop->get_id();
        }
    }
}

// ============================================================================
// activatePanels  (decomp @ 0x004B6740)
// ============================================================================
void TribeGameSettingsScreen::activatePanels()
{
    CUSTOM_DEBUG_FUNC_ENTER();

    // Decomp: show/hide panels based on state (random vs scenario)
    int isRandom = (this->state != StateScenario) ? 1 : 0;
    int isScenario = !isRandom;

    // Mission panels: visible in scenario mode only
    if (this->missionTitle) this->missionTitle->set_active(isScenario);
    if (this->missionText) this->missionText->set_active(isScenario);

    // Map dropdowns: visible in random mode only
    if (this->mapSizeDrop) this->mapSizeDrop->set_active(isRandom);
    if (this->mapTypeDrop) this->mapTypeDrop->set_active(isRandom);
    if (this->mapSizeLabel) this->mapSizeLabel->set_active(isRandom);
    if (this->mapTypeLabel) this->mapTypeLabel->set_active(isRandom);

    // Resources: active if not death match (id != -1)
    // TODO: check scenarioList get_id for death match detection
    // For now, always show resources in random mode
    if (this->resourcesDrop) this->resourcesDrop->set_active(1);
    if (this->resourcesLabel) this->resourcesLabel->set_active(1);

    // Victory panels
    this->activateVictoryPanels();

    // Tab order
    // Decomp: for MP, includes scenarioList; for SP, just OK + Cancel
    TPanel* tabList[4];
    int tabCount = 0;

    if (rge_base_game->rge_game_options.multiplayerGameValue != 0) {
        tabList[tabCount++] = (TPanel*)this->scenarioList;
    }
    tabList[tabCount++] = (TPanel*)this->okButton;
    tabList[tabCount++] = (TPanel*)this->cancelButton;
    this->set_tab_order(tabList, (short)tabCount);

    // Decomp: if no curr_child, set to okButton
    if (this->curr_child == nullptr) {
        this->set_curr_child((TPanel*)this->okButton);
    }
}

// ============================================================================
// activateVictoryPanels  (decomp @ 0x004B6870)
// ============================================================================
void TribeGameSettingsScreen::activateVictoryPanels()
{
    CUSTOM_DEBUG_FUNC_ENTER();

    // Decomp: hide time and score controls
    if (this->timeLabel) this->timeLabel->set_active(0);
    if (this->timeDrop) this->timeDrop->set_active(0);
    if (this->scoreLabel) this->scoreLabel->set_active(0);
    if (this->scoreDrop) this->scoreDrop->set_active(0);

    // Decomp: check for fixed victory in scenario mode
    if (this->state == StateScenario) {
        // TODO: check scenarioFixed array for current scenario
        // For now, assume not fixed (show victory controls)
    }

    // Decomp: show victory controls (not fixed)
    if (this->victoryFixedText) this->victoryFixedText->set_active(0);
    if (this->victoryTypeLabel) this->victoryTypeLabel->set_active(1);
    if (this->victoryTypeDrop) this->victoryTypeDrop->set_active(1);

    // Decomp: show time/score controls based on victory type
    if (this->victoryTypeDrop) {
        long vic_id = this->victoryTypeDrop->get_id();
        if (vic_id == 7) {  // Time victory
            if (this->timeLabel) this->timeLabel->set_active(1);
            if (this->timeDrop) this->timeDrop->set_active(1);
        }
        if (vic_id == 8) {  // Score victory
            if (this->scoreLabel) this->scoreLabel->set_active(1);
            if (this->scoreDrop) this->scoreDrop->set_active(1);
        }
    }
}
