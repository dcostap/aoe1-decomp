// 004BE750 TSpan_List_Manager::ScrollSpansHorizontally
// Source: spanlist.cpp
// Size: 242 bytes
#include "..\..\include\game_globals.h"
struct VSpan_Node { VSpan_Node* Next; char _pad[12]; };
class TSpan_Node_List { public: char _gap_00[0x2C]; };
class TSpan_List_Manager : public TSpan_Node_List {
public:
    char _gap_2C[0x44];
    void ScrollSpansHorizontally(int dx);
};
void TSpan_List_Manager::ScrollSpansHorizontally(int dx) { (void)dx; }
