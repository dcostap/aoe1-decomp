// VA: 00443F10 ~TDrawArea (292 B)
// PDB source: Drawarea.cpp
// Packet-grounded: destructor — unlink from DD surface chain, release surfaces, cleanup

extern void operator_delete(void* p);
extern int Release(void* surface);
extern void TSpan_List_Manager_dtor(void* mgr);

struct Shim_dtor_3F10 {
    char gap00[0x0C];
    void* Bits;                // +0x0C
    char gap10[0x18 - 0x10];
    int Width;                 // +0x18
    int Height;                // +0x1C
    char gap20[0x24 - 0x20];
    int Orien;                 // +0x24
    int ClipLeft;
    int ClipTop;
    int ClipRight;
    int ClipBottom;
    char gap38[0x3C - 0x38];
    void* Surface;             // +0x3C
    char gap40[0xAC - 0x40];
    void* SurfNode;            // +0xAC (linked list node in DD surface chain)
    char gapB0[0xB4 - 0xB0];
    void* SpanList;            // +0xB4 (used for clip rect span management)
    char gapB8[0xCC - 0xB8];
    void* SpanList2;           // +0xCC
    void* CurSpanList;         // +0xD0
};

int TDrawArea_dtor(Shim_dtor_3F10* self, int flags)
{
    // Unlink from DDraw surface chain
    void* surfNode = self->SurfNode;
    if (surfNode) {
        void* vtable = *(void**)self;
        if (vtable) {
            // Remove from linked list
            if (surfNode == vtable) {
                // self is head of list, update head
                void* next = *(void**)((char*)surfNode + 8);
                *(void**)((char*)vtable + 0x14) = next;
            }
        }
        
        // Unlink from prev/next in doubly-linked list
        void* prev = *(void**)((char*)surfNode + 4);
        if (prev) {
            void* next = *(void**)((char*)surfNode + 8);
            *(void**)((char*)prev + 8) = next;
        }
        void* next2 = *(void**)((char*)surfNode + 8);
        if (next2) {
            void* prev2 = *(void**)((char*)surfNode + 4);
            *(void**)((char*)next2 + 4) = prev2;
        }
        
        self->SurfNode = 0;
    }
    
    // Release surface if present
    if (self->Surface) {
        Release(self->Surface);
        self->Surface = 0;
    }
    
    // Cleanup span lists
    // TSpan_List_Manager_dtor(...) if needed
    
    // Handle bits
    // operator_delete if allocated
    
    // Handle deleting destructor flag
    if (flags & 1)
        operator_delete(self);
    
    return 1;
}
