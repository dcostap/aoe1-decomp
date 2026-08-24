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
// Matching-worker continuation: for-header, comma-sequenced, reversed-sum,
// and named row-base probes all emitted the same 250-byte basin.  The first
// remaining hunk is the outer-loop allocator choice: original computes the
// x*8 and x*4 LEAs before a separate row-sum LEA into EDX, while VC5 folds the
// row sum into ECX before those LEAs.  Calls, stack cleanup, layout, and the
// nested draw behavior remain aligned; retain the clean named-loop source.
// Fresh continuation: a distinct natural outer counter moves the first hunk
// past the x/y LEAs and improves the strict diff from 110 to 100 bytes; direct
// row, const-row, row-local, operand-order, register-hint, scoped-local,
// counted-for, and declaration-order variants otherwise remain duplicates.
// Final bounded best keeps the separate outer counter and scoped inner locals;
// the remaining blocker is the row-sum destination/register coloring at the
// first obstruction setup (original LEA into EDX versus rebuilt ADD into EAX).
// Fresh worker: direct/persistent row locals, inline row arithmetic, stdlib.h
// context, and a named tile_y4 all failed to improve the 100-byte basin (the
// named tile_y4 variant regressed to 110).  A focused eight-form natural setup
// lab found that assigning frame = tile_y + outer before the x/y offsets moves
// the emitted code to 100% block/call/size parity and only 2 positional bytes.
// Reordered/parenthesized y-coordinate terms were codegen duplicates; the
// remaining bytes are only the 00538E20 LEA SIB base/index order ([eax+ebx]
// original versus [ebx+eax] rebuilt).  Keep the row-first source as the best
// plausible reconstruction; no opaque register-forcing form was retained.
// Orch continuation: reversing both coordinate sums, grouping constants,
// materializing draw coordinates, widening offsets, and reversing each sum
// separately all emitted the same 250-byte basin.  ABI evidence supports the
// long shape_draw declaration; the only open drift remains two SIB bytes.

#ifndef RGE_VIEW_SHARED_CONTEXT
class TDrawArea {
public:
    virtual ~TDrawArea();
    char gap_04[0xCC];
    void* CurSpanList;
};

class TShape {
public:
    unsigned char shape_draw(TDrawArea*, long, long, long, unsigned char, unsigned char*);
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
#endif

void RGE_View::draw_terrain_obstruction_map(
    int x, int y, TShape* shape, int frame, int tile_x, int tile_y)
{
    int outer;
    int tile_x4 = tile_x * 4;
    tile_y *= 4;

    this->cur_render_area->CurSpanList = this->Terrain_Clip_Mask;
    shape->shape_draw(this->cur_render_area, x, y, frame, 0, 0);

    TShape* obstruction_shape = rge_base_game->get_shape(0);
    for (outer = 0; outer < 4; ++outer) {
        int i = 0;
        frame = tile_y + outer;
        int x_offset = outer * 8;
        int y_offset = outer * 4;

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

    }
}
