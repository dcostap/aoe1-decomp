// 00538D60 RGE_View::draw_terrain_obstruction_map
// view.cpp:4676-4707, 250 bytes, __thiscall
//
// Attempt log:
// - baseline: natural nested 4x4 obstruction-map draw with parameter reuse;
//   268 bytes and an 8-byte frame because the narrow obstruction result spilled.
// - widened the obstruction result to int; this recovered the original 250-byte
//   size/frame and the exact prologue plus pre-loop call sequence.
// - a positive `obstruction > 0` test recovered the original AND/JLE predicate.
// - local/parameter row-expression, declaration-scope, operand-order,
//   coordinate-term, and obstruction-shape variants emitted the same basin.
// - focused variant lab (18 natural setup/guard/coordinate spellings) found no
//   exact group; best remains 110 positional bytes (44%), 61 edit bytes.
// - paused: calls, stack cleanup, size/frame, and loop behavior align; remaining
//   drift starts at outer-loop LEA scheduling (original LEA/LEA/LEA versus the
//   compiler's early row add), then register/load ordering in the draw branch.
// - Session follow-up: canonical polymorphic TPanel context was retained;
//   named row and dead-frame-home reuse were duplicate probes.  The clean
//   source below preserves the natural parameter/field ownership and leaves
//   only the localized VC5 outer-loop LEA scheduling gap.
// Main-agent audit removed unused fake-size context and restored canonical
// draw-area ownership while retaining the ordinary nested obstruction loop.

class TDrawArea {
public:
    virtual ~TDrawArea();
    char gap_04[0xCC];
    void* CurSpanList;
};

class TShape {
public:
    unsigned char shape_draw(TDrawArea*, int, int, int, unsigned char, unsigned char*);
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    TShape* get_shape(int);
};

class PathingSystem {
public:
    unsigned char obstruction(int, int);
};

extern RGE_Base_Game* rge_base_game;
extern PathingSystem pathSystem;

class TPanel {
public:
    virtual ~TPanel();
    char gap_04[0xF0];
};

class RGE_View : public TPanel {
public:
    TDrawArea* cur_render_area;
    char gap_F8[0x178 - 0xF8];
    void* Terrain_Clip_Mask;

    void draw_terrain_obstruction_map(int, int, TShape*, int, int, int);
};

void RGE_View::draw_terrain_obstruction_map(
    int x, int y, TShape* shape, int frame, int tile_x, int tile_y)
{
    int tile_x4 = tile_x * 4;
    int i;
    int x_offset;
    int y_offset;
    tile_y *= 4;

    this->cur_render_area->CurSpanList = this->Terrain_Clip_Mask;
    shape->shape_draw(this->cur_render_area, x, y, frame, 0, 0);

    TShape* obstruction_shape = rge_base_game->get_shape(0);
    tile_x = 0;

    do {
        i = 0;
        x_offset = tile_x * 8;
        y_offset = tile_x * 4;
        frame = tile_x + tile_y;

        do {
            int obstruction = pathSystem.obstruction(i + tile_x4, frame);
            if (obstruction > 0) {
                obstruction_shape->shape_draw(this->cur_render_area,
                    x + 2 + x_offset,
                    y + 0x0D + y_offset,
                    obstruction - 1, 0, 0);
            }
            ++i;
            x_offset += 8;
            y_offset -= 4;
        } while (i < 4);

        ++tile_x;
    } while (tile_x < 4);
}
