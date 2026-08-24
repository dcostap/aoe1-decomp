// 0053B220 DClipInfo_List::AddGDINode
// Source: view.cpp lines 6746-6793
// Size: 219 bytes
// NC: no custom flags (default /O2 /Oy)

#ifndef RGE_VIEW_SHARED_CONTEXT
struct DClipInfo_Node {
    DClipInfo_Node* Next;        // +0x00
    DClipInfo_Node* NextOnLevel; // +0x04
    int Object_ID;               // +0x08
    void* Shape;                 // +0x0C
    int Draw_Level;              // +0x10
    int Draw_X;                  // +0x14
    int Draw_Y;                  // +0x18
    int Draw_Flag;               // +0x1C
    unsigned char* Shape_Base;   // +0x20
    unsigned char* Color_Table;  // +0x24
    int Xform_Mask;              // +0x28
    int Node_Type;               // +0x2C
    short x1;                    // +0x30
    short y1;                    // +0x32
    short x2;                    // +0x34
    short y2;                    // +0x36
    short x3;                    // +0x38
    short y3;                    // +0x3A
    short x4;                    // +0x3C
    short y4;                    // +0x3E
};

class DClipInfo_List {
public:
    DClipInfo_Node** Zone_Ptrs;   // +0x00
    int* Zone_Size_Ptrs;          // +0x04
    int Used_Zones;               // +0x08
    int Max_Zones;                // +0x0C
    char gap_10[0x40];            // +0x10 through +0x4F
    int Accept_Min_Level;         // +0x50
    int Accept_Max_Level;         // +0x54
    DClipInfo_Node** Draw_Clip_Nodes; // +0x58
    char gap_5C[0x08];            // +0x5C through +0x63
    int YLine_Offset;             // +0x64
    int YLine_Size;               // +0x68
    char gap_6C[0x04];            // +0x6C through +0x6F

    DClipInfo_Node* GetNode();
    DClipInfo_Node* AddGDINode(int param_1, int param_2, short param_3, short param_4, short param_5, short param_6, short param_7, short param_8, short param_9, short param_10, int param_11, int param_12, int param_13);
};
#endif

DClipInfo_Node* DClipInfo_List::AddGDINode(int param_1, int param_2, short param_3, short param_4, short param_5, short param_6, short param_7, short param_8, short param_9, short param_10, int param_11, int param_12, int param_13)
{
    int iVar2 = YLine_Offset + param_2;

    if (param_11 > Accept_Max_Level || param_11 < Accept_Min_Level || iVar2 < 0 || iVar2 >= YLine_Size)
        return 0;

    DClipInfo_Node* node = GetNode();
    node->Next = Draw_Clip_Nodes[iVar2];
    Draw_Clip_Nodes[iVar2] = node;

    node->Object_ID = param_13;
    node->Draw_Flag = param_12;
    node->Node_Type = param_1;
    node->x1 = param_3;
    node->y1 = param_4;
    node->x2 = param_5;
    node->y2 = param_6;
    node->x3 = param_7;
    node->y3 = param_8;
    node->NextOnLevel = 0;
    node->Shape = 0;
    node->Draw_X = 0;
    node->Draw_Y = 0;
    node->Shape_Base = 0;
    node->Color_Table = 0;
    node->Xform_Mask = 0;
    node->Draw_Level = param_11;
    node->x4 = param_9;
    node->y4 = param_10;

    return node;
}
