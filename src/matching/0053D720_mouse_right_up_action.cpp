// VA: 0053D720 RGE_Diamond_Map_View::mouse_right_up_action(long,long,int,int)
// PDB source: vw_dimap.cpp lines 206-261
// attempt 1: natural reconstruction from packet with local tile and typed offsets.
// attempt 2: RGE_Diamond_Map must not derive from local TPanel stub (release_mouse this was +4); swap set_view_loc args.
// attempt 3: force right_click failure to jump to the common final fail epilogue instead of booleanizing the call result.

class RGE_Tile;

class RGE_Player {
public:
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0C();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1C();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2C();
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3C();
    virtual void v40(); virtual void v44(); virtual void v48(); virtual void v4C();
    virtual void v50(); virtual void v54(); virtual void v58(); virtual void v5C();
    virtual void v60(); virtual void v64(); virtual void v68(); virtual void v6C();
    virtual void v70(); virtual void v74(); virtual void v78(); virtual void v7C();
    virtual void v80(); virtual void v84(); virtual void v88(); virtual void v8C();
    virtual void v90(); virtual void v94(); virtual void v98(); virtual void v9C();
    virtual void vA0(); virtual void vA4(); virtual void vA8(); virtual void vAC();
    virtual void vB0(); virtual void vB4(); virtual void vB8(); virtual void vBC();
    virtual void vC0(); virtual void vC4(); virtual void vC8(); virtual void vCC();
    virtual void vD0(); virtual void vD4();
    virtual void set_view_loc(float x, float y, float z);
    void unselect_object();
};

class RGE_Base_Game {
public:
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0C();
    virtual void set_game_mode(int a, int b);
    char gap_04[8];
    void* prog_info;      // +0x0C
    char gap_10[0x1A0];
    int prog_mode;        // +0x1B0
    int game_mode;        // +0x1B4
    int get_paused();
};

extern RGE_Base_Game* rge_base_game;

class RGE_Diamond_Map {
public:
    virtual void v00(); virtual void v04(); virtual void v08(); virtual void v0C();
    virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1C();
    virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2C();
    virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3C();
    virtual void v40(); virtual void v44(); virtual void v48(); virtual void v4C();
    virtual void v50(); virtual void v54(); virtual void v58(); virtual void v5C();
    virtual void v60(); virtual void v64(); virtual void v68(); virtual void v6C();
    virtual void v70(); virtual void v74(); virtual void v78(); virtual void v7C();
    virtual void v80(); virtual void v84(); virtual void v88(); virtual void v8C();
    virtual void v90(); virtual void v94(); virtual void v98(); virtual void v9C();
    virtual void vA0(); virtual void vA4(); virtual void vA8(); virtual void vAC();
    virtual void vB0(); virtual void vB4(); virtual void vB8(); virtual void vBC();
    virtual void vC0(); virtual void vC4(); virtual void vC8(); virtual void vCC();
    virtual void vD0(); virtual void vD4(); virtual void vD8(); virtual void vDC();
    virtual void vE0(); virtual void vE4(); virtual void vE8(); virtual void vEC();
    virtual int right_click(long x, long y); // +0xF0? probe
    virtual int right_click2(long x, long y); // +0xF4

    char gap_04[0xE8];
    unsigned char field_EC;       // +0xEC
    char gap_ED[7];
    void* world;                  // +0xF4
    RGE_Player* player;           // +0xF8
    char gap_FC[0x58];
    int scroll_view;              // +0x154

    void release_mouse();
    void end_scroll_view();
    int pick_tile(long x, long y, short* out_x, short* out_y, RGE_Tile** tile);
};

class RGE_Diamond_Map_View : public RGE_Diamond_Map {
public:
    long mouse_right_up_action(long x, long y, int param_3, int param_4);
};

long RGE_Diamond_Map_View::mouse_right_up_action(long x, long y, int param_3, int param_4)
{
    RGE_Tile* tile;
    int mode = rge_base_game->prog_mode;
    if (mode != 4 && mode != 6 && mode != 7 && mode != 5) {
        return 0;
    }

    if (this->scroll_view != 0) {
        this->end_scroll_view();
        return 1;
    }

    this->release_mouse();
    if (rge_base_game->get_paused() != 0) {
        return 0;
    }

    if (this->field_EC != 1 && this->field_EC != 2) {
        return 0;
    }

    if (*(short*)((char*)rge_base_game->prog_info + 0x8DC) == 2) {
        if (rge_base_game->game_mode != 0 || rge_base_game->prog_mode == 5) {
            return 0;
        }
        if (param_4 == 0) {
            if (this->right_click2(x, y) == 0) {
                goto fail;
            }
            return 1;
        }
        if (this->pick_tile(x, y, (short*)&x, (short*)&y, &tile) != 0) {
            this->player->set_view_loc((float)(short)x - -0.5f, (float)(short)y - -0.5f, 1.0f);
        }
        return 1;
    }

    if (rge_base_game->prog_mode == 7) {
        return 0;
    }
    if (rge_base_game->game_mode != 0) {
        rge_base_game->set_game_mode(0, 0);
        return 0;
    }
    this->player->unselect_object();
fail:
    return 0;
}
