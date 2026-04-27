// 004BE4B0 TSpan_List_Manager::DeleteShape
// Source: spanlist.cpp
// Size: 244 bytes
#include "..\..\include\game_globals.h"
struct VSpan_Node { VSpan_Node* Next; char _pad[12]; };
class TSpan_Node_List { public: char _gap_00[0x2C]; };
class TSpan_List_Manager : public TSpan_Node_List {
public:
    char _gap_2C[0x44];
    void DeleteShape(int a, int b, int c, int d, int e, int f, int g);
};
void TSpan_List_Manager::DeleteShape(int a, int b, int c, int d, int e, int f, int g)
{ (void)a; (void)b; (void)c; (void)d; (void)e; (void)f; (void)g; }
