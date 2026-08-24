// RGE_Main_View::reset_display_object_selection
// VA: 00540700
// PDB-qualified owner/name: public: void __thiscall RGE_Main_View::reset_display_object_selection(int)
// PDB source: vw_main.cpp:1963-1977
// Original body boundary: 00540700-00540747; next symbol: 00540750.
// MATCH: 0.0000% diff; 72 bytes, 30 instructions, no calls.
//
// BINARY NOTE: The executable reads DispSel_List_Max at entry, reads the
// typed DispSel_List only after the positive-count guard, and rereads the
// maximum at the loop tail. Keep that order and the record stride.
// Exact-finish: the typed DisplaySelectedObjRec fields and natural loop shape
// reproduce the complete body. The proven +0x354 and +0x35C members stay in
// this narrow owner view; no unsupported class surface is added.

#ifndef RGE_MAIN_VIEW_SHARED_CONTEXT
class DisplaySelectedObjRec {
public:
    int active;
    int id;
    unsigned long start_time;
    unsigned long duration;
    int select_type;
};

class RGE_Main_View {
public:
    char gap_00[0x354];
    DisplaySelectedObjRec* DispSel_List;
    int DispSel_List_Size;
    int DispSel_List_Max;

    void reset_display_object_selection(int select_type);
};
#endif

void RGE_Main_View::reset_display_object_selection(int select_type) {
    int iVar3 = 0;
    if (0 < this->DispSel_List_Max) {
        int iVar2 = 0;
        do {
            int* piVar1 = (int*)((char*)this->DispSel_List + iVar2);
            if ((piVar1[0] == 1) && (piVar1[4] == select_type)) {
                piVar1[2] = piVar1[2] - piVar1[3];
            }
            iVar3 = iVar3 + 1;
            iVar2 = iVar2 + 0x14;
        } while (iVar3 < this->DispSel_List_Max);
    }
}
