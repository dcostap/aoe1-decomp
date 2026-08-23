#ifndef SPANLIST_SHARED_CONTEXT
class VSpanMiniList {
public:
    unsigned char x;
    unsigned char y;
    unsigned char z;
};

class TSpan_List_Manager {
public:
    void AddSpan(int y1, int y2, int x);
    void AddMiniList(VSpanMiniList* list, int yoff, int xoff);
};
#endif

void TSpan_List_Manager::AddMiniList(VSpanMiniList* list, int yoff, int xoff) {
    if (list == 0) {
        return;
    }

    while (list != 0) {
        unsigned int x = 0;
        x = list->x;
        if (x == 0xFF) {
            return;
        }
        AddSpan((unsigned char)list->y + yoff, (unsigned char)list->z + yoff, x + xoff);
        list = (VSpanMiniList*)((char*)list + 3);
    }
}
