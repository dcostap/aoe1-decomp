// VA: 004C21A0 RGE_Static_Object::draw_back_frame (102 B)
// Attempt log:
// 1. Prior free helper declarations matched behavior but let VC5 use ECX as a temp and pre-load all args; original preserves ECX as this for member helper calls.
// 2. Member draw_frame_* calls produced exact helper argument-load/push shape, but VC5 merged identical cube tails into a 96B body.
// 3. Use a second same-signature member declaration for the case-1 cube call to block tail merging; relocation is masked.

class TDrawArea;

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

void RGE_Static_Object::draw_back_frame(TDrawArea* area, short x, short y) {
    if (rge_base_game->game_mode == 1) {
        this->draw_frame_3d_cube_back(area, x, y);
        return;
    }

    switch (rge_base_game->outline_type) {
    case 0:
        return;
    case 1:
        this->draw_frame_3d_cube_back_case(area, x, y);
        return;
    case 2:
    case 3:
        this->draw_frame_3d_square_back(area, x, y);
        return;
    default:
        return;
    }
}
