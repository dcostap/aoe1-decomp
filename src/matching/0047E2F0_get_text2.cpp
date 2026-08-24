// VA: 0047E2F0 TTextPanel::get_text2 (62 B)
// PDB source: Pnl_txt.cpp lines 1804-1820
//
// Attempt log:
// 1. do-while: register swap, extra param==0 check, wrong loop structure.
// 2. for-loop + explicit null check: duplicate null check.
// 3. while-loop (long i): 6.45% diff, structure exact, only 4 register-swap bytes.
// 4. while-loop (short i): 62.9% diff, push esi/movsx added. Bad.
// 5. while-loop (decl order + volatile): trying register alloc tricks for edx=counter, ecx=param.

#ifndef PNL_TXT_TU_CONTEXT
struct TTextPanel_TextNode {
    char* text;                    // +0x00
    char* text2;                   // +0x04
    long id;                       // +0x08
    TTextPanel_TextNode* next_node; // +0x0C
};
#else
typedef TextNode TTextPanel_TextNode;
#endif

#ifndef PNL_TXT_TU_CONTEXT
class TPanel {
public:
    char gap_00[0xF4];
};

class TTextPanel : public TPanel {
public:
    TTextPanel_TextNode* list;     // +0xF4

    char* get_text2(long index);
};
#endif

extern unsigned char DAT_0086b24c;

char* TTextPanel::get_text2(long index) {
    long i;
    TTextPanel_TextNode* node;

    i = 0;
    node = this->list;
    if (node == 0) {
        DAT_0086b24c = 0;
        return (char*)&DAT_0086b24c;
    }
    while (node != 0) {
        if (i == index) return node->text2;
        node = node->next_node;
        i++;
    }
    DAT_0086b24c = 0;
    return (char*)&DAT_0086b24c;
}
