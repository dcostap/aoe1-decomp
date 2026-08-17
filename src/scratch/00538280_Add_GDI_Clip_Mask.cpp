// VA: 00538280 RGE_View::Add_GDI_Clip_Mask
// Source: view.cpp lines 4281-4335
// Size: 385 bytes
// Calling convention: __thiscall, ret 8
//
// Attempt log:
// Probes 1-22 (default flags /O2 /Oy): sub esp always 0x0C vs 0x08 needed.
// Various local layouts, arrays, switch, early returns, inline asm tricks all
// produced the same extra 4 bytes of stack.
//
// Probe 23 (all ints at function scope): **BREAKTHROUGH** sub esp=8 matches!
// But register coloring differs: original uses esi=node, my code uses ebp=node.
// First mismatch at offset 5 (mov ebp,[esp+14h] vs push esi).
//
// Probes 24-28: tried reordering decls, adding n=node local, removing nt var,
// reducing function-scope vars to 2. Register coloring unchanged (ebp=node).
// Node_Type 4 path also diverges structurally due to different variable
// management (original stores 4 derived values upfront to stack; my code
// computes some inline and uses different stack slots).
//
// Left in scratch: remaining mismatch is register coloring (ebp vs esi for node)
// combined with cascading block-shape differences in type 2/3 and type 4 paths.
// Core insight: function-scope ints (any number >= 2) produce sub esp,8 match.
// Probe 29: outer non-type-1 structure — 408-byte output/frame loss; rolled back.
// Probe 30: register-qualified node/span parameters — codegen duplicate; rolled back.
// Probe 31: cache initial Node_Type — codegen duplicate; rolled back.
// Probe 32: guarded type2/3 do/while — 398-byte output/frame loss; rolled back.
// Probe 33: branch-local span-manager aliases — codegen duplicate; rolled back.
// Probe 34: hoist all integer temporaries to function scope in old-TU style.
// This historical function-scope source emitted 402 bytes, 273 positional diff
// bytes, the exact 9-call set, the 0x8 frame, and 59.74% shape.
//
// Probes 35-39: nested else, type2 fallthrough, guarded do/while, and else-if
// forms either lost the 0x8 frame or reproduced the clean baseline. Rolled back.
// Probe 40: block-local lifetimes matched more block shapes but lost the frame;
// rolled back.
// Probes 41-42: compute type4 edge bounds before y normalization. The best
// diagnostic diff was 251, but it used a 0xC frame and lost block coverage.
// Rolled back. Current source is the validated typed baseline.
// Probe 43: natural type2/3 source-order fallthrough with a guarded do/while
// produced a 400-byte body and lost the required 0x8 frame; rolled back.
// Probe 44: reordered coordinate declarations; emitted code was unchanged.
// Probe 45: separate line-manager alias; emitted code was unchanged.
// Probe 46: switch dispatch; 408 bytes and 397 diff, rolled back.
// Probe 47: source-order type2 fallthrough with named type4 edge locals; 370
// bytes and no frame, rolled back.
// Probes 49-51: named/reused type4 inner edges improved the diagnostic diff to
// 248-249 and shape to 68.6%, but forced a 0xC frame and only 2% exact blocks;
// the source also depended on dead-local reuse. Restored the clean 0x8-frame
// typed baseline. Next lead remains the original node/manager register basin
// and type2/type4 block topology, not further register tuning at this stage.

// Follow-up probes 52-53: removing the type2/3 return and restoring source-order
// x/y loads with a guarded do/while produced 400 and 396 bytes without the frame.
// Probe 54: named type4 inner edges recovered the 0x8 frame, 150 instructions,
// 384 bytes, 68.67% exact blocks, and 94.67% shape.
// Probes 55-56: branch aliases and declaration-order changes were duplicates.
// Probe 57: mutating the type2 lower bound directly lost the frame and was rolled
// back. Probe 58: block-local type2/type4 lifetimes improved exact blocks to
// 79.33% and shape to 96.67%, while positional diff stayed 153 bytes.
// Probes 59-61: separate alias assignment, declaration order, and register hints
// were duplicates. Probes 62 and 66: in-place type4 edge masks changed the type2
// stack-home order and produced 390 bytes; rolled back.
// Probes 63-65: a function-scope manager alias, loop declaration movement, and a
// reference receiver were duplicates. Probe 67: x declaration initializers caused
// uninitialized warnings and lost the frame. Probe 68: mutating raw x locals
// produced 378 bytes without the frame; rolled back.
// Final validation after removing the unused padding declaration stayed at 384
// bytes, 153 positional diff bytes, 79.33% exact blocks, 96.67% shape, exact
// 9-call order, and the required 0x8 frame. The natural source remains in scratch.
// Original EBX/EDI roles and the type4 raw-edge schedule remain unresolved.
// Follow-up pass: typed mask aliases, an explicit non-line else arm, a typed
// manager reference, and natural type4 edge-order variants were tested. The
// aliases and else/reference forms were codegen duplicates. Edge-order and
// direct-expression forms reduced structural parity or lost the frame. The
// clean typed source remains the best natural reconstruction: 153-byte diff,
// exact 9-call order, 0x8 frame, and first mismatch at type2 manager/loop
// register assignment (+0x8E). Keep the source in scratch.
// Revisit pass: direct type2 x-local mutation, narrow x locals, a branch-local
// manager reference, and the period windows.h context were tested. The first,
// narrow, and context forms were worse or lost the frame; the manager form was
// a codegen duplicate. All experiments were restored. Final validation remains
// the clean typed source: 384/385 bytes, 153 positional diff bytes, exact calls,
// 0x8 frame, and first mismatch at +0x8E.

struct DClipInfo_Node {
    char gap_00[0x2C];
    int Node_Type;          // +0x2C
    short x1;               // +0x30
    short y1;               // +0x32
    short x2;               // +0x34
    short y2;               // +0x36
    short x3;               // +0x38
    short y3;               // +0x3A
    short x4;               // +0x3C
    short y4;               // +0x3E
};

class TSpan_List_Manager {
public:
    void AddLine_Align(int x1, int y1, int x2, int y2);
    void AddSpan(int left, int right, int line);
};

class RGE_View {
public:
    void Add_GDI_Clip_Mask(DClipInfo_Node* node, TSpan_List_Manager* span_mgr);
};

void RGE_View::Add_GDI_Clip_Mask(DClipInfo_Node* node, TSpan_List_Manager* span_mgr)
{
    if (node->Node_Type == 1) {
        span_mgr->AddLine_Align(node->x1, node->y1, node->x2, node->y2);
        span_mgr->AddLine_Align(node->x2, node->y2, node->x3, node->y3);
        span_mgr->AddLine_Align(node->x3, node->y3, node->x4, node->y4);
        span_mgr->AddLine_Align(node->x4, node->y4, node->x1, node->y1);
        return;
    }
    if (node->Node_Type == 2 || node->Node_Type == 3) {
        int xl;
        int xr;
        int y1v;
        int y2v;
        int x1v;
        int x2v;
        int tmp;
        int y;

        x1v = node->x1;
        x2v = node->x2;
        y1v = node->y1;
        y2v = node->y2;
        xl = x1v & ~3;
        xr = x2v | 3;
        if (y1v > y2v) {
            tmp = y1v; y1v = y2v; y2v = tmp;
        }
        if (y1v <= y2v) {
            y = y1v;
            do {
                span_mgr->AddSpan(xl, xr, y);
                y++;
            } while (y <= y2v);
        }
    }
    if (node->Node_Type == 4) {
        int xl;
        int xr;
        int y1v;
        int y2v;
        int x1v;
        int x2v;
        int left_edge;
        int right_edge;
        int tmp;
        int y;

        x1v = node->x1;
        x2v = node->x2;
        if (x1v > x2v) {
            tmp = x1v; x1v = x2v; x2v = tmp;
        }
        left_edge = x1v | 3;
        right_edge = x2v & ~3;
        y1v = node->y1;
        y2v = node->y2;
        if (y1v > y2v) {
            tmp = y1v; y1v = y2v; y2v = tmp;
        }
        xl = x1v & ~3;
        xr = x2v | 3;
        span_mgr->AddSpan(xl, xr, y1v);
        span_mgr->AddSpan(xl, xr, y2v);
        y = y1v + 1;
        for (; y < y2v; y++) {
            span_mgr->AddSpan(xl, left_edge, y);
            span_mgr->AddSpan(right_edge, xr, y);
        }
    }
}
