// VA: 00538420 RGE_View::Draw_GDI_Object(DClipInfo_Node*, TDrawArea*)
// PDB source: view.cpp lines 4347-4387
// attempt 1: direct decompiler-shaped control flow and typed fields.

#ifndef RGE_VIEW_SHARED_CONTEXT
class TDrawArea {
public:
    void DrawLine(int x1, int y1, int x2, int y2, unsigned char color);
};

struct DClipInfo_Node {
    char gap_00[0x1C];
    unsigned char Draw_Flag; // +0x1C
    char gap_1D[0x0F];
    int Node_Type;           // +0x2C
    short x1;                // +0x30
    short y1;                // +0x32
    short x2;                // +0x34
    short y2;                // +0x36
    short x3;                // +0x38
    short y3;                // +0x3A
    short x4;                // +0x3C
    short y4;                // +0x3E
};

class RGE_View {
public:
    void Draw_GDI_Object(DClipInfo_Node* node, TDrawArea* draw);
};
#endif

void RGE_View::Draw_GDI_Object(DClipInfo_Node* node, TDrawArea* draw) {
    int i;

    if (node->Node_Type == 1) {
        draw->DrawLine(node->x1, node->y1, node->x2, node->y2, node->Draw_Flag);
        draw->DrawLine(node->x2, node->y2, node->x3, node->y3, node->Draw_Flag);
        draw->DrawLine(node->x3, node->y3, node->x4, node->y4, node->Draw_Flag);
        draw->DrawLine(node->x4, node->y4, node->x1, node->y1, node->Draw_Flag);
        return;
    }

    if (node->Node_Type == 2) {
        i = node->y1;
        if (i <= node->y2) {
            do {
                if (node->y3 != 0) {
                    draw->DrawLine(node->x1, i, node->x3, i, 0x4A);
                }
                if (node->y4 != 0) {
                    draw->DrawLine(node->x4, i, node->x2, i, 0x97);
                }
                i++;
            } while (i <= node->y2);
        }
    }

    if (node->Node_Type == 4) {
        draw->DrawLine(node->x1, node->y1, node->x2, node->y1, 0xFF);
        draw->DrawLine(node->x1, node->y2, node->x2, node->y2, 0xFF);
        draw->DrawLine(node->x1, node->y1, node->x1, node->y2, 0xFF);
        draw->DrawLine(node->x2, node->y1, node->x2, node->y2, 0xFF);
    }
}
