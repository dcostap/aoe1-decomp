extern "C" void __cdecl free(void* block);

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
    char gap_10[0x48];
    DClipInfo_Node** Draw_Clip_Nodes;
    DClipInfo_Node** Draw_Level_Head;
    DClipInfo_Node** Draw_Level_Tail;

    ~DClipInfo_List(void);
};
#endif

DClipInfo_List::~DClipInfo_List(void) {
    int i;

    i = 0;
    if (Used_Zones > 0) {
        do {
            if (Zone_Ptrs[i] != 0) {
                free(Zone_Ptrs[i]);
            }
            i = i + 1;
        } while (i < Used_Zones);
    }
    if (Zone_Ptrs != 0) {
        free(Zone_Ptrs);
    }
    if (Zone_Size_Ptrs != 0) {
        free(Zone_Size_Ptrs);
    }
    if (Draw_Clip_Nodes != 0) {
        free(Draw_Clip_Nodes);
    }
    if (Draw_Level_Head != 0) {
        free(Draw_Level_Head);
    }
    if (Draw_Level_Tail != 0) {
        free(Draw_Level_Tail);
    }
}
