// STATUS: blocked
// BLOCKER: constructor stays byte-identical except VC5 keeps loading/storing the 2nd and 3rd int params in source-order/field-order opposite the original prologue (Default_Grow_Size vs Element_Size)
// NOTE: layout, helper calls, and later body shape match; remaining drift is early parameter/load ordering only

extern "C" void* __cdecl calloc(unsigned int count, unsigned int size);

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
    int Default_Grow_Size;
    int Element_Size;
    int field_2C;
    int field_30;
    int NewZone_Count;
    int Reset_Count;
    char gap_3C[0x10];
    int Max_Draw_Levels;
    int Accept_Min_Level;
    int Accept_Max_Level;
    DClipInfo_Node** Draw_Clip_Nodes;
    DClipInfo_Node** Draw_Level_Head;
    DClipInfo_Node** Draw_Level_Tail;
    int YLine_Offset;
    int YLine_Size;
    short* Select_Box;

    DClipInfo_List(int init_zone_size, int element_size, int default_grow_size, int ymin, int ymax, int max_draw_levels);
    void SetCaptureLevel(int min_level, int max_level);
    void ResetStats(void);
    void SetNumZones(int num_zones);
    void InitNewZone(int zone_size);
};

DClipInfo_List::DClipInfo_List(int init_zone_size, int element_size, int default_grow_size, int ymin, int ymax, int max_draw_levels) {
    int yline_offset;
    int yline_size;

    Free_Pool_Zone = -1;
    Free_Pool_Index = -1;
    Element_Size = default_grow_size;
    Default_Grow_Size = element_size;
    yline_offset = -ymin;
    yline_size = (ymax - ymin) + 1;
    Zone_Ptrs = 0;
    Zone_Size_Ptrs = 0;
    Max_Zones = 8;
    Used_Zones = 0;
    Free_Head = 0;
    Total_Blocks = 0;
    Free_Blocks = 0;
    YLine_Offset = yline_offset;
    YLine_Size = yline_size;
    Max_Draw_Levels = max_draw_levels;
    SetCaptureLevel(0, max_draw_levels);
    Draw_Clip_Nodes = (DClipInfo_Node**)calloc(YLine_Size, 4);
    Draw_Level_Head = (DClipInfo_Node**)calloc(Max_Draw_Levels + 1, 4);
    Draw_Level_Tail = (DClipInfo_Node**)calloc(Max_Draw_Levels + 1, 4);
    ResetStats();
    SetNumZones(8);
    InitNewZone(init_zone_size);
    Select_Box = 0;
}
