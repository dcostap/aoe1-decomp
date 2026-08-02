// VA: 0048F0B0 TribeAchievementsScreen::draw (215 B)
// PDB source: scr_ach.cpp
// Attempt log:
// baseline: raw shims had the right broad effects but wrong direct-call symbols,
//   a 253-byte body, and no recognizable base-class draw call.
// structural: restored the period TPanel/TScreenPanel, TDrawArea, TShape, and
//   game/player member surfaces; all eight call sites then aligned.
// index/layout: a shared player index with player_names[i] and players[i+1]
//   is the cleanest source reconstruction. It gives the exact frame, call set,
//   player/name array ownership, and 97.10% instruction-shape similarity.
// diagnostic: volatile count plus separate cursors reproduced the observed
//   stack counter and reached an 87-byte diff, but retained compiler steering
//   and a less canonical source topology; rolled back.
// diagnostic: pointer subtraction and a narrow win-decal local both worsened
//   structure; rolled back. The remaining drift is register/address scheduling
//   around the spilled count, player-array load, and shape-call setup.
// left in scratch: natural typed reconstruction; no exact match this claim.

typedef unsigned char uchar;

struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};

class TDrawArea;
class TPanel;
class TShape;
class RGE_Player;
class RGE_Game_World;
class RGE_Base_Game;

class TPanel {
public:
    virtual ~TPanel();
    virtual long setup(TDrawArea*, TPanel*, long, long, long, long, uchar);
    virtual void set_rect(tagRECT);
    virtual void set_rect(long, long, long, long);
    virtual void set_color(uchar);
    virtual void set_active(int);
    virtual void set_positioning(int, long, long, long, long, long, long, long,
                                 long, TPanel*, TPanel*, TPanel*, TPanel*);
    virtual void set_fixed_position(long, long, long, long);
    virtual void set_redraw(int);
    virtual void set_overlapped_redraw(TPanel*, TPanel*, int);
    virtual void draw_setup(int);
    virtual void draw_finish();
    virtual void draw();

    char gap_04[0x1C];
    TDrawArea* render_area;
    char gap_24[0xD0];

    long xPosition();
    long yPosition();
};

class TEasy_Panel : public TPanel {
public:
    char gap_F4[0x384];
};

class TScreenPanel : public TEasy_Panel {
public:
    virtual void draw();
};

class TTextPanel : public TPanel {
};

class TribeAchievementsScreen : public TScreenPanel {
public:
    int end_game_flag;
    int current_mode;
    char gap_480[0x128];
    TTextPanel* player_names[8];
    char gap_5C8[0x28];
    TShape* win_decal;

    virtual void draw();
};

class TDrawArea {
public:
    uchar* Lock(char* name, int wait);
    void Unlock(char* name);
};

class TShape {
public:
    uchar shape_draw(TDrawArea* draw_area, long x, long y, long shape_idx,
                     uchar color_flag, uchar* color_table);
};

class RGE_Player {
public:
    char gap_00[0x80];
    uchar active;
};

class RGE_Game_World {
public:
    char gap_00[0x3C];
    short player_num;
    char gap_3E[2];
    RGE_Player** players;
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    char gap_04[0x3F0];
    RGE_Game_World* world;
};

extern RGE_Base_Game* rge_base_game;

void TribeAchievementsScreen::draw()
{
    TScreenPanel::draw();

    if (this->current_mode < 5) {
        this->draw_setup(0);

        if (this->win_decal != 0 &&
            this->render_area->Lock((char*)"scr_ach::draw", 1) != 0) {
            RGE_Game_World* world = rge_base_game->world;
            int count = world->player_num - 1;

            if (count > 0) {
                int player_index = 0;
                do {
                    if (world->players[player_index + 1]->active == 1) {
                        this->win_decal->shape_draw(
                            this->render_area,
                            this->player_names[player_index]->xPosition() - 0x14,
                            this->player_names[player_index]->yPosition(),
                            0, 0, 0);
                    }
                    ++player_index;
                    --count;
                } while (count != 0);
            }

            this->render_area->Unlock((char*)"scr_ach::draw");
        }

        this->draw_finish();
    }
}
