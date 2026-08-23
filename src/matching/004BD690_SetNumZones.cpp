// VA: 004BD690 TSpan_Node_List::SetNumZones
// Source: spanlist.cpp lines 96-132
//
// Attempt log:
// - Prior scratch had +0x08/+0x0C names swapped and used operator_delete, producing relocation/copy-count drift.
// - SpruceGlow MATCH: model +0x08 as Used_Zones and +0x0C as Max_Zones, use natural calloc/free, and keep the simple
//   indexed for loop copying both arrays under the `if (Zone_Ptrs)` guard.
// Result: MATCH locally with `python tools/check_function.py --va 004BD690`.

#ifndef SPANLIST_SHARED_CONTEXT
struct VSpan_Node;

extern void* __cdecl calloc(int num, int size);
extern void __cdecl free(void* p);

class TSpan_Node_List {
public:
    VSpan_Node** Zone_Ptrs;   // +0x00
    int* Zone_Size_Ptrs;      // +0x04
    int Used_Zones;           // +0x08
    int Max_Zones;            // +0x0C

    void SetNumZones(int newCount);
};
#endif

void TSpan_Node_List::SetNumZones(int newCount) {
    if (newCount >= this->Max_Zones) {
        VSpan_Node** newZonePtrs = (VSpan_Node**)calloc(newCount, 4);
        int* newZoneSizePtrs = (int*)calloc(newCount, 4);

        if (this->Zone_Ptrs) {
            for (int i = 0; i < this->Used_Zones; i++) {
                newZonePtrs[i] = this->Zone_Ptrs[i];
                newZoneSizePtrs[i] = this->Zone_Size_Ptrs[i];
            }

            free(this->Zone_Ptrs);
            free(this->Zone_Size_Ptrs);
        }

        this->Zone_Ptrs = newZonePtrs;
        this->Zone_Size_Ptrs = newZoneSizePtrs;
        this->Max_Zones = newCount;
    }
}
