#ifndef RGE_VIEW_SHARED_CONTEXT
struct DClipInfo_Node {
    DClipInfo_Node* Next;
    char gap_04[0x3C];
};

class DClipInfo_List {
public:
    DClipInfo_Node** Zone_Ptrs;
    int* Zone_Size_Ptrs;
    int Used_Zones;
    int Max_Zones;
    DClipInfo_Node* Free_Head;
    int Free_Pool_Zone;
    int Free_Pool_Index;
    int Total_Blocks;
    int Free_Blocks;
    int Default_Grow_Size;

    void InitNewZone(int zone_size);
    DClipInfo_Node* GetNode(void);
};
#endif

DClipInfo_Node* DClipInfo_List::GetNode(void) {
    DClipInfo_Node* node;

    if (Free_Blocks == 0) {
        InitNewZone(Default_Grow_Size);
    }
    node = Free_Head;
    if (node != 0) {
        Free_Head = node->Next;
        Free_Blocks = Free_Blocks - 1;
        return node;
    }
    node = Zone_Ptrs[Free_Pool_Zone] + Free_Pool_Index;
    Free_Blocks = Free_Blocks - 1;
    Free_Pool_Index = Free_Pool_Index + 1;
    if (Free_Pool_Index == Zone_Size_Ptrs[Free_Pool_Zone]) {
        Free_Pool_Zone = Free_Pool_Zone + 1;
        Free_Pool_Index = 0;
        if (Free_Pool_Zone == Used_Zones) {
            Free_Pool_Zone = -1;
        }
    }
    return node;
}
