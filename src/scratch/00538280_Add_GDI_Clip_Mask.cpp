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
// Current retained source: typed, period-plausible function-scope local surface;
// 402-byte output, 273 positional bytes, exact 9-call set, 0x8 frame, and 59.74%
// shape. Remaining lead is TU/register coloring for node versus span manager and
// the original type2/3/type4 stack-home topology.

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
    int xl;
    int xr;
    int y1v;
    int y2v;
    int x1v;
    int x2v;
    int tmp;
    int y;

    if (node->Node_Type == 1) {
        span_mgr->AddLine_Align(node->x1, node->y1, node->x2, node->y2);
        span_mgr->AddLine_Align(node->x2, node->y2, node->x3, node->y3);
        span_mgr->AddLine_Align(node->x3, node->y3, node->x4, node->y4);
        span_mgr->AddLine_Align(node->x4, node->y4, node->x1, node->y1);
        return;
    }
    if (node->Node_Type == 2 || node->Node_Type == 3) {
        y1v = node->y1;
        y2v = node->y2;
        if (y1v > y2v) {
            tmp = y1v; y1v = y2v; y2v = tmp;
        }
        xl = node->x1 & ~3;
        xr = node->x2 | 3;
        y = y1v;
        for (; y <= y2v; y++) {
            span_mgr->AddSpan(xl, xr, y);
        }
        return;
    }
    if (node->Node_Type == 4) {
        x1v = node->x1;
        x2v = node->x2;
        if (x1v > x2v) {
            tmp = x1v; x1v = x2v; x2v = tmp;
        }
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
            span_mgr->AddSpan(xl, x1v | 3, y);
            span_mgr->AddSpan(x2v & ~3, xr, y);
        }
    }
}
