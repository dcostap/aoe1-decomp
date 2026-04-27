// 004BDFA0 TSpan_List_Manager::AddShape_Align
// Source: spanlist.cpp
// Size: 239 bytes
#include "..\..\include\game_globals.h"
struct VSpan_Node { VSpan_Node* Next; char _pad[12]; };
class TSpan_Node_List { public: char _gap_00[0x2C]; };
class TSpan_List_Manager : public TSpan_Node_List {
public:
    char _gap_2C[0x44];
    void AddShape_Align(int a, int b, int c, int d, int e, int f, int g, int h);
};
void TSpan_List_Manager::AddShape_Align(int a, int b, int c, int d, int e, int f, int g, int h)
{ (void)a; (void)b; (void)c; (void)d; (void)e; (void)f; (void)g; (void)h; }
