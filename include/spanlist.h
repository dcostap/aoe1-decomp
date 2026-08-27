#ifndef AOE1_SPANLIST_H
#define AOE1_SPANLIST_H

#include <windows.h>

#ifndef AOE1_SPANLIST_TYPES_H
#define AOE1_SPANLIST_TYPES_H

struct VSpan_Node {
    union {
        VSpan_Node* Next;
        VSpan_Node* next;
    };
    union {
        VSpan_Node* Prev;
        VSpan_Node* prev;
    };
    int StartPx;
    int EndPx;
};

struct VSpanMiniList {
    union {
        unsigned char Y_delta;
        unsigned char y;
    };
    union {
        unsigned char X_start;
        unsigned char x;
    };
    union {
        unsigned char X_end;
        unsigned char z;
    };
};

struct Shape_Header;
struct Shape_File_Header;
struct Shape_Offsets;
struct Shape_Info;
struct SLhape_File_Header;
class TShape;
class TDrawArea;

class TSpan_Node_List {
public:
    union {
        VSpan_Node** Zone_Ptrs;
        VSpan_Node** zonePtrs;
    };
    union {
        int* Zone_Size_Ptrs;
        int* zoneSizePtrs;
    };
    union {
        int Used_Zones;
        int usedZones;
    };
    union {
        int Max_Zones;
        int maxZones;
    };
    union {
        VSpan_Node* Free_Head;
        VSpan_Node* freeHead;
        VSpan_Node* field_10;
    };
    union {
        union {
            int Free_Pool_Zone;
            int freePoolZone;
        };
        int field_14;
    };
    union {
        union {
            int Free_Pool_Index;
            int freePoolIndex;
        };
        int field_18;
    };
    union {
        int Total_Blocks;
        int totalBlocks;
        int field_1C;
    };
    union {
        int Free_Blocks;
        int freeBlocks;
        int field_20;
    };
    union {
        int Default_Grow_Size;
        int defaultGrowSize;
    };
    union {
        int Element_Size;
        int elementSize;
    };
    union {
        int Alloc_Count;
        int field_2C;
    };
    union {
        int Dealloc_Count;
        int field_30;
    };
    union {
        int NewZone_Count;
        int newZoneCount;
        int field_34;
    };
    union {
        int Reset_Count;
        int field_38;
    };

    TSpan_Node_List(int initial_size, int grow_size, int item_size);
    ~TSpan_Node_List();

private:
    void SetNumZones(int new_count);
    void InitNewZone(int grow_size);

public:
    VSpan_Node* GetNode();
    void FreeNode(VSpan_Node* node);
    int FreeThread(VSpan_Node* first, VSpan_Node* last);
    void ReclaimAllNodes();
    void ResetStats();
};

class TSpan_List_Manager {
public:
    TSpan_Node_List VSList;
    union {
        VSpan_Node** Line_Head_Ptrs;
        void** line_head_ptrs;
    };
    union {
        VSpan_Node** Line_Tail_Ptrs;
        void** line_tail_ptrs;
    };
    union {
        int* LeftMostPx;
        int* left_most_px;
    };
    union {
        int* RightMostPx;
        int* right_most_px;
    };
    union {
        int* Span_Count;
        int* span_count;
    };
    union {
        int Num_Lines;
        int num_lines;
    };
    int Num_Pixels;
    int Min_Span_Px;
    int Max_Span_Px;
    int Min_Line;
    int Max_Line;

    TSpan_List_Manager(int num_pixels, int num_lines);
    ~TSpan_List_Manager();
    void SetSpanRegions(int min_s, int min_l, int max_s, int max_l);
    void ResetAll();
    void AddSpan(int start, int end, int line);
    void AddShape(TShape* shape, int shape_number, int x, int y, int mirror);
    void AddShape_Align(unsigned char* data, Shape_Info* shape,
                        int x, int y, int align);
    void AddLine_Align(int x1, int y1, int x2, int y2);
    void AddMiniList(VSpanMiniList* list, int yoff, int xoff);
    void SubtractMiniList(VSpanMiniList* list, int xoff, int yoff);
    void DeleteSpan(int left, int right, int line);
    void DeleteShape(TShape* shape, int shape_number, int x, int y, int mirror);
    int PointVisible(int x, int line);
    void Merge_n_Align(TSpan_List_Manager* list1, TSpan_List_Manager* list2);
    void AlignamizeSpans();
    void ScrollSpansHorizontally(int dx, int use_regions);
    void ScrollSpansVertically(int dy, int use_regions);
    int ValidateSpan(int line);
    int DecodeLine(unsigned char* line, int line_index,
                   unsigned char delta, int unused);
    void take_snapshot(char* name, int& number, TDrawArea* area, int color,
                       TSpan_List_Manager** spans, int* colors, int count);
};

#endif  // AOE1_SPANLIST_TYPES_H

#endif
