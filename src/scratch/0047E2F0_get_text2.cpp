// fifth pass: mirror the decompiler's variable roles exactly, using the same list/index terminology
// if this still misses, the function is now a register-basin problem rather than a logic problem

class TTTextPanel {
public:
    struct TextNode {
        char* text;
        char* text2;
        long id;
        TextNode* next_node;
    };

    char gap_00[0xF4];
    TextNode* list;

    char* get_text2(long param_1);
};

extern char DAT_0086B24C[4];

char* TTTextPanel::get_text2(long param_1) {
    TextNode* pTVar1;
    int iVar2;

    pTVar1 = this->list;
    iVar2 = 0;
    if (pTVar1 == 0) {
        DAT_0086B24C[0] = 0;
        return DAT_0086B24C;
    }
    do {
        if (iVar2 == param_1) {
            return pTVar1->text2;
        }
        pTVar1 = pTVar1->next_node;
        iVar2 = iVar2 + 1;
    } while (pTVar1 != 0);
    DAT_0086B24C[0] = 0;
    return DAT_0086B24C;
}
