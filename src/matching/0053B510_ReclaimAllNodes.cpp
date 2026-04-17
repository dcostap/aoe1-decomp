extern "C" void* __cdecl memset(void* dest, int value, unsigned int count);

class DClipInfo_Node;

class DClipInfo_List {
public:
    char gap_00[0x10];
    DClipInfo_Node* Free_Head;
    int Free_Pool_Zone;
    int Free_Pool_Index;
    int Total_Blocks;
    int Free_Blocks;
    char gap_24[0x14];
    int Reset_Count;
    char gap_3C[0x10];
    int Max_Draw_Levels;
    char gap_50[0x08];
    DClipInfo_Node** Draw_Clip_Nodes;
    DClipInfo_Node** Draw_Level_Head;
    DClipInfo_Node** Draw_Level_Tail;
    char gap_64[0x04];
    int YLine_Size;

    void ReclaimAllNodes(void);
};

void DClipInfo_List::ReclaimAllNodes(void) {
    memset(Draw_Clip_Nodes, 0, YLine_Size * 4);
    memset(Draw_Level_Head, 0, (Max_Draw_Levels * 4) + 4);
    memset(Draw_Level_Tail, 0, (Max_Draw_Levels * 4) + 4);
    Free_Head = 0;
    Free_Pool_Zone = 0;
    Free_Pool_Index = 0;
    Free_Blocks = Total_Blocks;
    Reset_Count = Reset_Count + 1;
}
