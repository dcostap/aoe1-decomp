// 004BE5F0 TSpan_List_Manager::Merge_n_Align (155B)
// spanlist.cpp:1436-1477
// Default flags

struct VSpan_Node {
    VSpan_Node* Next;   // +0
    char gap_04[4];     // +4
    int StartPx;        // +8
    int EndPx;           // +C
};

class TSpan_List_Manager {
public:
    char gap_00[0x3C];
    int* Line_Head_Ptrs;    // +0x3C  (array of VSpan_Node*)
    char gap_40[0x50-0x40];
    int Num_Lines;          // +0x50
    int Num_Pixels;         // +0x54

    void ResetAll();
    void AddSpan(int StartPx, int EndPx, int lineIdx);

    void Merge_n_Align(TSpan_List_Manager* p1, TSpan_List_Manager* p2);
};

void TSpan_List_Manager::Merge_n_Align(TSpan_List_Manager* p1, TSpan_List_Manager* p2)
{
    ResetAll();

    if (Num_Lines != p1->Num_Lines) return;
    if (Num_Lines != p2->Num_Lines) return;
    if (Num_Pixels != p1->Num_Pixels) return;
    if (Num_Pixels != p2->Num_Pixels) return;

    for (int i = 0; i < Num_Lines; i++) {
        VSpan_Node* node1 = (VSpan_Node*)p1->Line_Head_Ptrs[i];
        VSpan_Node* node2 = (VSpan_Node*)p2->Line_Head_Ptrs[i];

        while (node1 || node2) {
            if (node1) {
                AddSpan(node1->StartPx & 0xFFFFFFFC, node1->EndPx | 3, i);
                node1 = node1->Next;
            }
            if (node2) {
                AddSpan(node2->StartPx & 0xFFFFFFFC, node2->EndPx | 3, i);
                node2 = node2->Next;
            }
        }
    }
}
