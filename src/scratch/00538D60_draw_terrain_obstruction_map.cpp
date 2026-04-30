// 00538D60 RGE_View::draw_terrain_obstruction_map
// view.cpp:4676-4707, 250 bytes, __thiscall
// Paused: complex function with parameter reuse, external calls (shape_draw, get_shape, obstruction),
// and nested loop register allocation. Needs proper struct definitions for TShape, TDrawArea,
// RGE_Base_Game, and PathingSystem before matching can be attempted.

struct TDrawArea { int gap[0x34]; int CurSpanList; };
struct TShape { int gap[4]; void shape_draw(TDrawArea*, int, int, int, unsigned char, unsigned char*); };
struct RGE_Base_Game { int gap[4]; TShape* get_shape(int); };
struct PathingSystem { unsigned char obstruction(int, int); };

extern RGE_Base_Game* rge_base_game;
extern PathingSystem pathSystem;

class TPanel { public: unsigned char gap_00[0xF4]; };
class RGE_View : public TPanel {
public:
    unsigned char gap_F4[0x104 - 0xF4];
    TDrawArea* cur_render_area;
    unsigned char gap_104[0x178 - 0x108];
    void* Terrain_Clip_Mask;
    
    void draw_terrain_obstruction_map(int p1, int p2, TShape* p3, int p4, int p5, int p6);
};
