// Exact-finish: this source mirrors the exact SubtractMiniList loop basin.
// BINARY NOTE: the 3-byte record starts with Y_delta, then X_start and X_end.
// The local y_delta is required to preserve the sentinel load and call setup.
// Direct offsets, implicit byte promotion, and an unqualified AddSpan call
// were each walked back without changing the exact bytes.

#ifndef SPANLIST_SHARED_CONTEXT
class VSpanMiniList {
public:
    unsigned char Y_delta;
    unsigned char X_start;
    unsigned char X_end;
};

class TSpan_List_Manager {
public:
    void AddSpan(int start, int end, int line);
    void AddMiniList(VSpanMiniList* list, int x_off, int y_off);
};
#endif

void TSpan_List_Manager::AddMiniList(VSpanMiniList* list, int x_off, int y_off) {
    if (list == 0) {
        return;
    }

    while (list != 0) {
        int y_delta = list->Y_delta;

        if (y_delta == 0xFF) {
            return;
        }

        AddSpan(list->X_start + x_off,
            list->X_end + x_off,
            y_delta + y_off);

        list = (VSpanMiniList*)((char*)list + 3);
    }
}
