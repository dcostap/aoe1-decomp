#pragma once
#include "common.h"

struct DClipInfo_Node;
struct Shape_Info;

struct DClipInfo_List {
    DClipInfo_List(int initial_blocks, int grow_size, int element_size, int y_min, int y_max, int max_draw_levels);
    ~DClipInfo_List();

    void SetCaptureLevel(int min_level, int max_level);
    void SetDrawRegion(int xmin, int ymin, int xmax, int ymax);
    void AddDrawNode(void* shape_base, Shape_Info* shape, int draw_line, int draw_x, int draw_y, int draw_flag, uchar* color_table, int xform_mask, int draw_level, int object_id);
    DClipInfo_Node* AddGDINode(int node_type, int draw_line, int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, int draw_level, int draw_flag, int object_id);
    DClipInfo_Node* LocateIDbyDrawLevel(int object_id, int min_level, int max_level, int node_type);
    void Scroll(int scroll_x, int scroll_y);
    void FreeNode(DClipInfo_Node* node);
    int FreeThread(DClipInfo_Node* head, DClipInfo_Node* tail);
    void ReclaimAllNodes();
    void ResetStats();

    DClipInfo_Node* GetNode();
    void SetNumZones(int num_zones);
    void InitNewZone(int blocks);

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
    int Alloc_Count;
    int Dealloc_Count;
    int NewZone_Count;
    int Reset_Count;
    int SD_XMin;
    int SD_XMax;
    int SD_YMin;
    int SD_YMax;
    int Max_Draw_Levels;
    int Accept_Min_Level;
    int Accept_Max_Level;
    DClipInfo_Node** Draw_Clip_Nodes;
    DClipInfo_Node** Draw_Level_Head;
    DClipInfo_Node** Draw_Level_Tail;
    int YLine_Offset;
    int YLine_Size;
    short* Select_Box;
};
static_assert(sizeof(DClipInfo_List) == 0x70, "Size mismatch");
