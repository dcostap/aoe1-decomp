// VA: 00444C30 TDrawArea::SetClipRect (279 B)
// PDB source: Drawarea.cpp
// Packet-grounded: EH-framed. Store clip rect, manage SpanList (create or reuse), 
//   reset + set span regions, loop add spans, store cur span list

extern void* operator_new(unsigned int size);
extern void operator_delete(void* p);
extern int TSpan_List_Manager_ctor(void* mgr, int width, int height);
extern int TSpan_List_Manager_dtor(void* mgr);
extern void TSpan_List_Manager_ResetAll(void* mgr);
extern void TSpan_List_Manager_SetSpanRegions(void* mgr, int left, int top, int right, int bottom);
extern void TSpan_List_Manager_AddSpan(void* mgr, int left, int right, int y);

struct Shim_SetClipRect_4C30 {
    char gap00[0x18];
    int Width;                 // +0x18
    int Height;                // +0x1C
    char gap20[0x28 - 0x20];
    int ClipLeft;              // +0x28
    int ClipTop;               // +0x2C
    int ClipRight;             // +0x30
    int ClipBottom;            // +0x34
    char gap38[0xCC - 0x38];
    void* SpanList;            // +0xCC
    int field_D0;              // +0xD0 (CurSpanList)
};

void TDrawArea_SetClipRect(Shim_SetClipRect_4C30* self, int left, int top, int right, int bottom)
{
    // EH frame: FS:[0] setup (this is __thiscall with EH bookkeeping)
    
    // Store old SpanList before updating clip rect
    void* oldSpanList = self->SpanList;
    
    // Store the new clip rect
    self->ClipLeft = left;
    self->ClipTop = top;
    self->ClipRight = right;
    self->ClipBottom = bottom;
    
    // If old SpanList exists but its height doesn't match current height, destroy it
    if (oldSpanList && *(int*)((char*)oldSpanList + 0x50) != self->Height) {
        if (oldSpanList) {
            TSpan_List_Manager_dtor(oldSpanList);
            operator_delete(oldSpanList);
        }
        self->SpanList = 0;
    }
    
    // If SpanList is null, create a new one
    if (!self->SpanList) {
        void* newSpanList = operator_new(0x68);
        if (newSpanList) {
            // TSpan_List_Manager ctor(width, height)
            // returns the object
            TSpan_List_Manager_ctor(newSpanList, self->Width, self->Height);
        } else {
            newSpanList = 0;
        }
        self->SpanList = newSpanList;
    }
    
    // Reset and set spans
    TSpan_List_Manager_ResetAll(self->SpanList);
    TSpan_List_Manager_SetSpanRegions(self->SpanList, self->ClipLeft, self->ClipTop, self->ClipRight, self->ClipBottom);
    
    // Loop rows from top to bottom, adding spans
    int y = self->ClipTop;
    if (y <= self->ClipBottom) {
        do {
            TSpan_List_Manager_AddSpan(self->SpanList, self->ClipLeft, self->ClipRight, y);
            y++;
        } while (y <= self->ClipBottom);
    }
    
    // Store as current span list
    self->field_D0 = (int)self->SpanList;
    
    // EH frame teardown: FS:[0] restore
}
