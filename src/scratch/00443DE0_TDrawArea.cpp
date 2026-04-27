// VA: 00443DE0 TDrawArea::TDrawArea (304 B)
// PDB source: Drawarea.cpp
// Packet-grounded: constructor — zero init, alloc Bits, copy name

extern void* operator_new(unsigned int size);
extern void* calloc(int count, int size);
extern void* memset(void* s, int c, int n);
extern int sprintf(char* buf, const char* fmt, ...);
extern int strcpy(char* dst, const char* src);
extern int strlen(const char* s);
extern char* strncpy(char* dst, const char* src, int n);

struct Shim_ctor_3DE0 {
    char gap00[8];
    unsigned char* Bits;       // +0x08
    int field_0C;              // +0x0C
    int field_10;              // +0x10
    int field_14;              // +0x14
    int Width;                 // +0x18
    int Height;                // +0x1C
    int Pitch;                 // +0x20
    int Orien;                 // +0x24 (1=top-down)
    int ClipLeft;              // +0x28
    int ClipTop;               // +0x2C
    int ClipRight;             // +0x30
    int ClipBottom;            // +0x34
    char gap38[0x3C - 0x38];
    void* Surface;             // +0x3C
    char gap40[0xAC - 0x40];
    void* SurfNode;            // +0xAC
    char gapB0[0xB4 - 0xB0];
    void* SpanList;            // +0xB4
    void* SpanList2;           // +0xBC
    void* SpanList3;           // +0xC0
    char gapC4[0xC8 - 0xC4];
    void* SpanList4;           // +0xC8
    void* SpanList5;           // +0xCC
    void* CurSpanList;         // +0xD0
    char gapD4[0xD8 - 0xD4];
    void* field_D8;            // +0xD8
    char gapDC[0xE0 - 0xDC];
    void* field_E0;            // +0xE0
    int field_E4;              // +0xE4
    int field_E8;              // +0xE8
    int field_EC;              // +0xEC
    int field_F0;              // +0xF0
    int field_F4;              // +0xF4
    int field_F8;              // +0xF8
    unsigned char field_FC;    // +0xFC
};

void* TDrawArea_ctor(Shim_ctor_3DE0* self, const char* name, int height)
{
    int i;
    
    // Zero-initialize most fields
    self->Bits = 0;
    self->Width = 0;
    self->Height = 0;
    self->Pitch = 0;
    self->Orien = 0;
    self->ClipLeft = 0;
    self->ClipTop = 0;
    self->ClipRight = 0;
    self->ClipBottom = 0;
    self->Surface = 0;
    self->SurfNode = 0;
    self->SpanList = 0;
    self->SpanList2 = 0;
    self->SpanList3 = 0;
    self->SpanList4 = 0;
    self->SpanList5 = 0;
    self->CurSpanList = 0;
    self->field_D8 = 0;
    self->field_E0 = 0;
    self->field_E4 = 0;
    self->field_E8 = 0;
    self->field_EC = 0;
    self->field_F0 = 0;
    self->field_F4 = 0;
    self->field_F8 = 0;
    self->field_FC = 0xFF;
    
    // memset at this+0x40 for 0x6C bytes
    memset((char*)self + 0x40, 0, 0x6C);
    
    // Allocate Bits = calloc(1, 0x428) ... actually operator_new(0x428)?
    self->Bits = (unsigned char*)operator_new(0x428);
    self->Orien = 1;
    
    // Clear span list manager pointers
    self->SpanList4 = 0;
    self->CurSpanList = 0;
    self->SpanList5 = 0;
    
    // Copy name string
    int nameLen = strlen(name);
    if (nameLen > 0) {
        char* nameCopy = (char*)operator_new(nameLen + 1);
        strcpy(nameCopy, name);
        // Store at this+0xB0?
        *(char**)((char*)self + 0xB0) = nameCopy;
    } else {
        *(char**)((char*)self + 0xB0) = 0;
    }
    
    return self;
}
