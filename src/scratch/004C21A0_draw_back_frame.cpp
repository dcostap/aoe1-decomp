// VA: 004C21A0 RGE_Static_Object::draw_back_frame (102 B)
// PDB source: stat_obj.cpp lines 885-907
// Notes: remaining 25.5% diff is register allocation (ecx vs edx).
// VC5 consistently uses ecx for the outline_type temp where original uses edx,
// and uses 3-register push pattern where original uses 2-register reuse.

class TDrawArea;

class RGE_Base_Game {
public:
    char pad_00[0x50];
    unsigned char outline_type;
    char pad_51[0x163];
    int game_mode;
};

extern RGE_Base_Game* rge_base_game;
extern void __stdcall draw_frame_3d_cube_back(TDrawArea* area, short x, short y);
extern void __stdcall draw_frame_3d_square_back(TDrawArea* area, short x, short y);

class RGE_Static_Object {
public:
    void draw_back_frame(TDrawArea* area, short x, short y);
};

void RGE_Static_Object::draw_back_frame(TDrawArea* area, short x, short y) {
    if (rge_base_game->game_mode == 1) {
        draw_frame_3d_cube_back(area, x, y);
        return;
    }

    switch (rge_base_game->outline_type) {
    case 0:
        return;
    case 1:
        draw_frame_3d_cube_back(area, x, y);
        return;
    case 2:
    case 3:
        draw_frame_3d_square_back(area, x, y);
        return;
    default:
        return;
    }
}
