extern "C" void* __cdecl calloc(unsigned int count, unsigned int size);
extern "C" void __cdecl free(void* block);

#ifndef RGE_VIEW_SHARED_CONTEXT
struct DClipInfo_Node;

class DClipInfo_List {
public:
    DClipInfo_Node** Zone_Ptrs;
    int* Zone_Size_Ptrs;
    int Used_Zones;
    int Max_Zones;

private:
    void SetNumZones(int num_zones);
};
#endif

void DClipInfo_List::SetNumZones(int num_zones) {
    DClipInfo_Node** new_zone_ptrs;
    int* new_zone_sizes;
    int i;

    if (num_zones >= Max_Zones) {
        new_zone_ptrs = (DClipInfo_Node**)calloc(num_zones, 4);
        new_zone_sizes = (int*)calloc(num_zones, 4);
        if (Zone_Ptrs != 0) {
            i = 0;
            if (Used_Zones > 0) {
                do {
                    new_zone_ptrs[i] = Zone_Ptrs[i];
                    new_zone_sizes[i] = Zone_Size_Ptrs[i];
                    i = i + 1;
                } while (i < Used_Zones);
            }
            free(Zone_Ptrs);
            free(Zone_Size_Ptrs);
        }
        Zone_Ptrs = new_zone_ptrs;
        Zone_Size_Ptrs = new_zone_sizes;
        Max_Zones = num_zones;
    }
}
