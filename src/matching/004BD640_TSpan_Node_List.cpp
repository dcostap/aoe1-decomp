#include <stdlib.h>

class VSpan_Node;

class TSpan_Node_List {
public:
    VSpan_Node** Zone_Ptrs;
    int* Zone_Size_Ptrs;
    int Used_Zones;
    int Max_Zones;
    VSpan_Node* Free_Head;
    int Free_Pool_Zone;
    int Free_Pool_Index;
    int Total_Blocks;
    int Free_Blocks;
    int Default_Grow_Size;
    int Element_Size;
    int Alloc_Count;
    int Dealloc_Count;
    int NewZone_Count;
    int Reset_Count;

    ~TSpan_Node_List();
};

TSpan_Node_List::~TSpan_Node_List(void) {
    int i = 0;

    while (i < this->Used_Zones) {
        if (this->Zone_Ptrs[i] != 0) {
            free(this->Zone_Ptrs[i]);
        }
        i++;
    }

    if (this->Zone_Ptrs != 0) {
        free(this->Zone_Ptrs);
    }
    if (this->Zone_Size_Ptrs != 0) {
        free(this->Zone_Size_Ptrs);
    }
}
