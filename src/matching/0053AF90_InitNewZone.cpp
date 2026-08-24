extern "C" void* __cdecl malloc(unsigned int size);

#ifndef RGE_VIEW_SHARED_CONTEXT
struct DClipInfo_Node;

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
    char gap_24[0x04];
    int Element_Size;
    char gap_2C[0x08];
    int NewZone_Count;

    void SetNumZones(int num_zones);
    void InitNewZone(int zone_size);
};
#endif

void DClipInfo_List::InitNewZone(int zone_size) {
    int zone_index;
    unsigned int alloc_size;

    if (Used_Zones == Max_Zones) {
        SetNumZones(Used_Zones + 4);
    }
    zone_index = Used_Zones;
    Used_Zones = zone_index + 1;
    alloc_size = Element_Size * zone_size;
    Zone_Size_Ptrs[zone_index] = zone_size;
    Zone_Ptrs[zone_index] = (DClipInfo_Node*)malloc(alloc_size);
    NewZone_Count = NewZone_Count + 1;
    Total_Blocks = Total_Blocks + zone_size;
    Free_Blocks = Free_Blocks + zone_size;
    if (Free_Pool_Zone == -1) {
        Free_Pool_Zone = zone_index;
        Free_Pool_Index = 0;
    }
}
