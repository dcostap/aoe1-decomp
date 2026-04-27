// 004BDEA0 TSpan_List_Manager::AddShape
// Source: spanlist.cpp
// Size: 254 bytes
//
// Attempt log:
// Probe 1: structural

#include "..\..\include\game_globals.h"

struct VSpan_Node {
    VSpan_Node* Next;
    char _pad[12];
};

class TSpan_Node_List {
public:
    char _gap_00[0x2C];
};

class TSpan_List_Manager : public TSpan_Node_List {
public:
    char _gap_2C[0x44];

    void AddShape(int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8);
};

void TSpan_List_Manager::AddShape(int a, int b, int c, int d, int e, int f, int g, int h)
{
    (void)a; (void)b; (void)c; (void)d; (void)e; (void)f; (void)g; (void)h;
}
