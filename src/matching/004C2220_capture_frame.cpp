// VA: 004C2220 RGE_Static_Object::capture_frame
// stat_obj.cpp lines 911-935
//
// Attempt log:
// - Initial scratch was a free-function stub with unrelated globals.
// - SpruceGlow MATCH: use natural member helper calls and a real `switch` on `rge_base_game->outline_type` after the
//   game-mode fast path. The two case arms that call the same helper must remain distinct source cases (`game_mode==1`
//   fast path and switch case 1) to preserve the different parameter load/register ordering in the original.
// Result: MATCH locally with `python tools/check_function.py --va 004C2220`.

class TDrawArea;

extern int SDI_Capture_Info;

class RGE_Base_Game {
public:
    char gap_00[0x50];
    unsigned char outline_type;
    char gap_51[0x163];
    int game_mode;
};

extern RGE_Base_Game* rge_base_game;

class RGE_Static_Object {
public:
    void capture_square_frame(TDrawArea* area, short x, short y);
    void capture_frame_3d_cube(TDrawArea* area, short x, short y);
    void capture_frame_3d_square(TDrawArea* area, short x, short y);
    void capture_frame(TDrawArea* area, short x, short y);
};

void RGE_Static_Object::capture_frame(TDrawArea* area, short x, short y) {
    if (SDI_Capture_Info) {
        if (rge_base_game->game_mode == 1) {
            this->capture_frame_3d_cube(area, x, y);
            return;
        }

        switch (rge_base_game->outline_type) {
        case 0:
            this->capture_square_frame(area, x, y);
            return;
        case 1:
            this->capture_frame_3d_cube(area, x, y);
            return;
        case 2:
        case 3:
            this->capture_frame_3d_square(area, x, y);
            return;
        }
    }
}
