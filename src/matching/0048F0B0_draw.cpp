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
// fresh pass (orch-luna-48f0b0-w3): name-pointer cursor plus shared index was
//   a duplicate/worse basin; full TPanel donor surface, function-scope locals,
//   and a register-qualified count were unchanged. A natural loop variant lab
//   (six loop forms, size/frame/call gates) found no eligible improvement.
// fresh pass: a local players[] alias caused a 192-byte frame-less body; proven
//   polymorphic RGE_Player/RGE_Game_World surfaces were codegen-identical; a
//   short countdown moved to 216 bytes but emitted 16-bit operations. The final
//   binary-proven raw name/this player-address relation fell to 193 bytes.
// left in scratch: restored natural typed shared-index reconstruction; all eight
//   calls/frame remain aligned, with unresolved world/count register scheduling.
// main-agent normalization restored the donor-backed polymorphic RGE_Player and
// RGE_Game_World surfaces; emitted code is unchanged.
// retained source reconstruction: a distinct post-guard remaining counter is
// binary-supported by the persistent stack countdown and preserves the natural
// typed indexed player/name ownership.
// final ordering probe: split the remaining declaration from its assignment so
// the source statement order can place the count copy after loop-address setup.
// fresh bounded pass (orch-scrach-01): repeated world-chain access lost the
//   frame; delaying the world fetch, splitting/binding the count decrement,
//   world reference/const/register qualifiers, cached players, hoisted index,
//   and old-C declaration order were either duplicates or broader mismatches.
//   No new codegen basin beat the clean 121-byte result; the clean typed source
//   remains the defensible reconstruction and the world/count register swap is
//   still unresolved.
// orch-scrach-fresh-04 final candidate: the separate remaining counter restores
//   exact size, all calls, and all late body bytes; residual 12-byte drift is
//   only the LEA/name-base versus count-spill order at the loop setup.
// exact-loop probe: make the remaining-count copy the initializer of a natural
//   countdown for loop; VC5 schedules the name-base LEA before that store.
// setup-order lab: array-reference aliases changed the world/name cursor
//   relation; no exact output. Natural for/while countdown forms with the
//   remaining assignment in the loop initializer emitted the exact bytes.

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
    virtual ~RGE_Player();
    char gap_04[0x7C];
    uchar active;
};

class RGE_Game_World {
public:
    virtual void data_load_world();
    char gap_04[0x38];
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
                int remaining;
                int player_index = 0;
                for (remaining = count; remaining != 0; --remaining) {
                    if (world->players[player_index + 1]->active == 1) {
                        this->win_decal->shape_draw(
                            this->render_area,
                            this->player_names[player_index]->xPosition() - 0x14,
                            this->player_names[player_index]->yPosition(),
                            0, 0, 0);
                    }
                    ++player_index;
                }
            }

            this->render_area->Unlock((char*)"scr_ach::draw");
        }

        this->draw_finish();
    }
}
