// VA: 0047E2A0 TTextPanel::get_text (61 B)
// PDB source: Pnl_txt.cpp lines 1774-1790
// ACCEPTED_DRIFT: 3-byte benign register allocation (counter in ecx vs edx).
// Remaining diff: xor edx,edx vs xor ecx,ecx; mov ecx,[esp+4] vs mov edx,[esp+4]; inc edx vs inc ecx.
// These are register swaps (edx↔ecx) for counter vs parameter. 37 trailing bytes identical.

#ifndef PNL_TXT_TU_CONTEXT
struct TextNode {
    char* text;
    char gap_04[8];
    TextNode* next;
};

class TTextPanel {
public:
    char gap_00[0xF4];
    TextNode* list;

    char* get_text(long index);
};
#endif

extern char DAT_0086B250;

char* TTextPanel::get_text(long index) {
    TextNode* node = this->list;
    long i = 0;
    if (node == 0) {
        DAT_0086B250 = 0;
        return &DAT_0086B250;
    }
    while (node != 0) {
        if (index == i) {
            return node->text;
        }
        node = node->next;
        i++;
    }
    DAT_0086B250 = 0;
    return &DAT_0086B250;
}
