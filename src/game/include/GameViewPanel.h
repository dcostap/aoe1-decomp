#pragma once
#include "common.h"
#include "TScreenPanel.h"

class RGE_Map;

// Temporary game-view panel for rendering an isometric tile grid with camera scrolling.
// This replaces the blank TScreenPanel used by create_game_screen() until the real
// TRIBE_Screen_Game is reimplemented.
class GameViewPanel : public TScreenPanel {
public:
    GameViewPanel(RGE_Map* map);
    virtual ~GameViewPanel();

    virtual void draw() override;
    virtual long handle_key_down(long param_1, short param_2, int param_3, int param_4, int param_5) override;
    virtual long handle_idle() override;

    // Camera world-pixel offsets (top-left of screen in world coords)
    long cam_x;
    long cam_y;

    // Scroll speed in pixels per key-press / per idle tick for edge scroll
    long scroll_speed;

    // Pointer to the world map (not owned — owned by TRIBE_World)
    RGE_Map* world_map;

    // Key state for continuous scrolling
    int scroll_left;
    int scroll_right;
    int scroll_up;
    int scroll_down;
};
