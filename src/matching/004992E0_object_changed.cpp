// VA: 004992E0 object_changed (199B)
// scr_game.cpp
// PDB owner: protected TRIBE_Screen_Game::object_changed, scr_game.cpp:3261-3298.
// Body: 004992E0-004993A6. 00498950 is data, not a function.
// Exact finish: natural player-state publication, mode guards, and reset cleanup
// produce 60 instructions, 7 ordered calls, and the protected IAEXXZ symbol.

#if !defined(SCR_GAME_TU_CONTEXT)
class TRIBE_Main_View {
public:
    virtual void vf00() = 0;
    virtual void vf04() = 0;
    virtual void vf08() = 0;
    virtual void vf0C() = 0;
    virtual void vf10() = 0;
    virtual void vf14() = 0;
    virtual void vf18() = 0;
    virtual void vf1C() = 0;
    virtual void vf20() = 0;
    virtual void vf24() = 0;
    virtual void vf28() = 0;
    virtual void vf2C() = 0;
    virtual void vf30() = 0;
    virtual void vf34() = 0;
    virtual void vf38() = 0;
    virtual void vf3C() = 0;
    virtual void vf40() = 0;
    virtual void vf44() = 0;
    virtual void vf48() = 0;
    virtual void vf4C() = 0;
    virtual void vf50() = 0;
    virtual void vf54() = 0;
    virtual void vf58() = 0;
    virtual void vf5C() = 0;
    virtual void vf60() = 0;
    virtual void vf64() = 0;
    virtual void vf68() = 0;
    virtual void vf6C() = 0;
    virtual void vf70() = 0;
    virtual void vf74() = 0;
    virtual void vf78() = 0;
    virtual void vf7C() = 0;
    virtual void vf80() = 0;
    virtual void vf84() = 0;
    virtual void vf88() = 0;
    virtual void vf8C() = 0;
    virtual void vf90() = 0;
    virtual void vf94() = 0;
    virtual void vf98() = 0;
    virtual void vf9C() = 0;
    virtual void vfA0() = 0;
    virtual void vfA4() = 0;
    virtual void vfA8() = 0;
    virtual void vfAC() = 0;
    virtual void vfB0() = 0;
    virtual void vfB4() = 0;
    virtual void vfB8() = 0;
    virtual void vfBC() = 0;
    virtual void vfC0() = 0;
    virtual void vfC4() = 0;
    virtual void vfC8() = 0;
    virtual void vfCC() = 0;
    virtual void vfD0() = 0;
    virtual void vfD4() = 0;
    virtual void vfD8() = 0;
    virtual void vfDC() = 0;
    virtual void vfE0() = 0;
    virtual void vfE4() = 0;
    virtual void vfE8() = 0;
    virtual void vfEC() = 0;
    virtual void vfF0() = 0;
    void set_selection_area(long left, long top, long right, long bottom);
};

class RGE_Static_Object;

class RGE_Player {
public:
    virtual void vf00();
    char gap_04[0x12C];
    RGE_Static_Object* selected_obj;
    RGE_Static_Object* sel_list[25];
    unsigned long sel_object_properties;
    short sel_count;
};

class RGE_Base_Game {
public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void set_game_action(int action, int value);

    char gap_04[0x1B0];
    int game_mode;

    RGE_Player* get_player(void);
};

extern RGE_Base_Game* rge_base_game;

class TRIBE_Screen_Game {
public:
    char gap_00[0x4B8];
    TRIBE_Main_View* main_view;
    char gap_4BC[0x10C];
    RGE_Static_Object* game_obj;
    short sel_count;

    void reset_buttons(void);

protected:
    void object_changed(void);
};
#endif

void TRIBE_Screen_Game::object_changed(void) {
    int changed = this->game_obj != rge_base_game->get_player()->selected_obj;
    this->game_obj = rge_base_game->get_player()->selected_obj;
    this->sel_count = rge_base_game->get_player()->sel_count;

    if (changed != 0) {
        if (rge_base_game->game_mode == 0x15) {
            this->main_view->vfF0();
            this->main_view->set_selection_area(-1, -1, -1, -1);
        }

        int mode = rge_base_game->game_mode;
        if ((char)mode != 1 &&
            (char)mode != 0x12 &&
            (char)mode != 0x0E &&
            (char)mode != 2 &&
            (char)mode != 3 &&
            (char)mode != 8 &&
            (char)mode != 9 &&
            (char)mode != 0x0A) {
            rge_base_game->set_game_action(0, 0);
        }
    }

    this->reset_buttons();
}
