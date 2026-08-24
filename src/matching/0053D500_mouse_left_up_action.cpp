// 0053D500 mouse_left_up_action (284 bytes)
// PDB: vw_dimap.cpp (RGE_Diamond_Map_View::mouse_left_up_action)
// Attempt log:
//   attempt 1: padded vtable to 61 base entries, natural source with switch/if chains

#ifndef VW_DIMAP_SHARED_CONTEXT
class RGE_Tile;

class RGE_Prog_Info {
public:
    char gap_00[0x8DC];
    short interface_style;   // +0x8DC
};

class RGE_Base_Game {
public:
    char gap_00[0x0C];
    RGE_Prog_Info* prog_info; // +0x0C
    char gap_10[0x1A0];
    int prog_mode;            // +0x1B0
    int game_mode;            // +0x1B4

    int get_paused();
};

extern RGE_Base_Game* rge_base_game;

// TPanel: 9 virtuals (vt[0]-vt[8])
class TPanel {
public:
    virtual void vt00() {}
    virtual void vt04() {}
    virtual void vt08() {}
    virtual void vt0C() {}
    virtual void vt10() {}
    virtual void vt14() {}
    virtual void vt18() {}
    virtual void vt1C() {}
    virtual void set_redraw(int) {}
    char gap_04[0xF0];

    void release_mouse();
};

// RGE_Diamond_Map: adds 52 virtuals (vt[9]-vt[60]) → total 61 base virtuals
class RGE_Diamond_Map : public TPanel {
public:
    virtual void dm_v09() {}
    virtual void dm_v10() {}
    virtual void dm_v11() {}
    virtual void dm_v12() {}
    virtual void dm_v13() {}
    virtual void dm_v14() {}
    virtual void dm_v15() {}
    virtual void dm_v16() {}
    virtual void dm_v17() {}
    virtual void dm_v18() {}
    virtual void dm_v19() {}
    virtual void dm_v20() {}
    virtual void dm_v21() {}
    virtual void dm_v22() {}
    virtual void dm_v23() {}
    virtual void dm_v24() {}
    virtual void dm_v25() {}
    virtual void dm_v26() {}
    virtual void dm_v27() {}
    virtual void dm_v28() {}
    virtual void dm_v29() {}
    virtual void dm_v30() {}
    virtual void dm_v31() {}
    virtual void dm_v32() {}
    virtual void dm_v33() {}
    virtual void dm_v34() {}
    virtual void dm_v35() {}
    virtual void dm_v36() {}
    virtual void dm_v37() {}
    virtual void dm_v38() {}
    virtual void dm_v39() {}
    virtual void dm_v40() {}
    virtual void dm_v41() {}
    virtual void dm_v42() {}
    virtual void dm_v43() {}
    virtual void dm_v44() {}
    virtual void dm_v45() {}
    virtual void dm_v46() {}
    virtual void dm_v47() {}
    virtual void dm_v48() {}
    virtual void dm_v49() {}
    virtual void dm_v50() {}
    virtual void dm_v51() {}
    virtual void dm_v52() {}
    virtual void dm_v53() {}
    virtual void dm_v54() {}
    virtual void dm_v55() {}
    virtual void dm_v56() {}
    virtual void dm_v57() {}
    virtual void dm_v58() {}
    virtual void dm_v59() {}
    virtual void dm_v60() {}

    char gap_F4[0x60];        // +0xF4 to +0x153
    int scrolling;             // +0x154

    int pick_tile(long x, long y, short* col, short* row, RGE_Tile** tile);
    void end_scroll_view();
};

// RGE_Diamond_Map_View: adds 3 virtuals (vt[61]-vt[63]) → total 64 virtuals
class RGE_Diamond_Map_View : public RGE_Diamond_Map {
public:
    virtual int command_make_do(long x, long y);     // vt[61] at +0xF4
    virtual int command_make_move(long x, long y);   // vt[62] at +0xF8
    virtual int command_make_work(long x, long y);   // vt[63] at +0xFC

    long mouse_left_up_action(long x, long y, int key, int flags);
};
#endif

long RGE_Diamond_Map_View::mouse_left_up_action(long x, long y, int key, int flags)
{
    int mode = rge_base_game->prog_mode;

    if (mode == 4 || mode == 6 || mode == 7 || mode == 5) {
        if (this->scrolling) {
            this->end_scroll_view();
            return 1;
        }

        this->release_mouse();

        if (rge_base_game->get_paused()) {
            return 0;
        }

        if (rge_base_game->prog_mode == 5) {
            return 0;
        }

        short col, row;
        RGE_Tile* tile;

        if (this->pick_tile(x, y, &col, &row, &tile)) {
            switch (rge_base_game->game_mode) {
                case 0:
                    if (rge_base_game->prog_info->interface_style != 2) {
                        if (this->command_make_do(x, y)) {
                            return 1;
                        }
                    }
                    break;
                case 4:
                    this->command_make_move(x, y);
                    return 1;
                case 5:
                    this->command_make_work(x, y);
                    return 1;
            }
        }
    }

    return 0;
}
