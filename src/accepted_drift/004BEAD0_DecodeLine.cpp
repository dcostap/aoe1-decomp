// first pass: decode a linked span list for one line, adding the byte delta across each covered pixel range
// tried the straightforward nested-loop shape; mismatch stayed at the early push/register order (node/line registers swapped)
// tried a dest alias and the same loop body; VC5 still picked the wrong node/line register basin

#ifndef SPANLIST_SHARED_CONTEXT
class VSpan_Node {
public:
    VSpan_Node* Next;
    char gap_04[0x4];
    int StartPx;
    int EndPx;
};

class TSpan_List_Manager {
public:
    char gap_00[0x3C];
    VSpan_Node** Line_Head_Ptrs;

    int DecodeLine(unsigned char* line, int line_index, unsigned char delta, int unused);
};
#endif

int TSpan_List_Manager::DecodeLine(unsigned char* line, int line_index, unsigned char delta, int unused) {
    int count = 0;

    if (Line_Head_Ptrs[line_index] != 0) {
        VSpan_Node* node = Line_Head_Ptrs[line_index];
        do {
            int x = node->StartPx;
            int end = node->EndPx;
            if (x <= end) {
                do {
                    line[x] = line[x] + delta;
                    ++x;
                } while (x <= end);
            }
            node = node->Next;
            ++count;
        } while (node != 0);
    }

    return count;
}
