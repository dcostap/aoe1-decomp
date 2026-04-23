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
