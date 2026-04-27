// 004BE690 TSpan_List_Manager::AlignamizeSpans
// Source: spanlist.cpp
// Size: 190 bytes
#include "..\..\include\game_globals.h"
struct VSpan_Node { VSpan_Node* Next; char _pad[12]; };
class TSpan_Node_List { public: char _gap_00[0x2C]; };
class TSpan_List_Manager : public TSpan_Node_List {
public:
    char _gap_2C[0x44];
    void AlignamizeSpans();
};
void TSpan_List_Manager::AlignamizeSpans() {}
