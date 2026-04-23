// first pass: walk 3-byte span records, stop on 0xFF in the first byte, and feed each span into AddSpan
// tried direct AddSpan calls, swapped offset parameter names, and an unsigned-int first-byte compare; the remaining mismatch stayed in the early prolog / branch-displacement basin

class VSpanMiniList {
public:
    unsigned char x;
    unsigned char y;
    unsigned char z;
};

class TSpan_List_Manager {
public:
    void AddMiniList(VSpanMiniList* list, int yoff, int xoff);
};

extern void AddSpan(TSpan_List_Manager* this_, int x, int y, int z);

void TSpan_List_Manager::AddMiniList(VSpanMiniList* list, int yoff, int xoff) {
    int xadd = xoff;
    int yadd = yoff;

    if (list == 0) {
        return;
    }

    while (1) {
        unsigned int x = (unsigned char)list->x;
        if (x == 0xFF) {
            return;
        }
        AddSpan(this, (int)x + xadd, (int)list->y + yadd, (int)list->z + yadd);
        list = (VSpanMiniList*)((char*)list + 3);
    }
}
