// first pass: direct global-game guard and the outline-type switch to the two back-frame helpers
// tried the direct helper-call spelling, then a local game pointer; VC5 kept moving the push/register order around the helper calls
// the remaining mismatch is now localized to the helper-call basin / push order, not the global guard or switch topology
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
