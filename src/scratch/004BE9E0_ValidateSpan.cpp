// 004BE9E0 TSpan_List_Manager::ValidateSpan
// Source: spanlist.cpp
// Size: 225 bytes
#include "..\..\include\game_globals.h"
struct VSpan_Node { VSpan_Node* Next; char _pad[12]; };
class TSpan_Node_List { public: char _gap_00[0x2C]; };
class TSpan_List_Manager : public TSpan_Node_List {
public:
    char _gap_2C[0x44];
    int ValidateSpan(int a, int b, int c, int d, int e);
};
int TSpan_List_Manager::ValidateSpan(int a, int b, int c, int d, int e)
{ (void)a; (void)b; (void)c; (void)d; (void)e; return 0; }
