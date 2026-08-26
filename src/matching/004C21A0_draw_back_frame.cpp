// VA: 004C21A0 RGE_Static_Object::draw_back_frame (102 B)
// Attempt log:
// 1. Prior free helper declarations matched behavior but let VC5 use ECX as a temp and pre-load all args; original preserves ECX as this for member helper calls.
// 2. Member draw_frame_* calls produced exact helper argument-load/push shape, but VC5 merged identical cube tails into a 96B body.
// 3. Inline wrapper/cast/local/volatile variants either merged tails or added extra code.
// 4. The grouped target audit proved that case 1 calls draw_frame_3d_cube_back,
//    not the similarly shaped case helper; this also removes the relocation
//    target mismatch without changing the 102-byte body.

class TDrawArea;

#ifndef RGE_STAT_OBJ_SHARED_CONTEXT
class RGE_Base_Game {
public:
    char pad_00[0x50];
    unsigned char outline_type;
    char pad_51[0x163];
    int game_mode;
};

extern RGE_Base_Game* rge_base_game;

class RGE_Static_Object {
public:
    void draw_frame_3d_cube_back(TDrawArea* area, short x, short y);
    void draw_frame_3d_cube_back_case(TDrawArea* area, short x, short y);
    void draw_frame_3d_square_back(TDrawArea* area, short x, short y);
    void draw_back_frame(TDrawArea* area, short x, short y);
};
#endif

void RGE_Static_Object::draw_back_frame(TDrawArea* area, short x, short y) {
    if (rge_base_game->game_mode == 1) {
        this->draw_frame_3d_cube_back(area, x, y);
        return;
    }

    switch (rge_base_game->outline_type) {
    case 0:
        return;
    case 1:
        this->draw_frame_3d_cube_back(area, x, y);
        return;
    case 2:
    case 3:
        this->draw_frame_3d_square_back(area, x, y);
        return;
    default:
        return;
    }
}
