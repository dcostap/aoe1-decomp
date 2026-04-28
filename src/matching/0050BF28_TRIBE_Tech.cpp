// VA: 0050BF28 TRIBE_Tech::~TRIBE_Tech (116 B)
// __thiscall, destructor: free each non-null tech entry in the array, then free the array itself

extern void free(void* p);

struct TRIBE_Tech {
    void** tech_array;   // +0x00
    short count;         // +0x04
    void* world;         // +0x08
};

void TRIBE_Tech_dtor(TRIBE_Tech* self)
{
    if (!self->tech_array)
        return;
    
    int i;
    for (i = 0; i < self->count; i++) {
        void* p = self->tech_array[i * (0x3C / 4)]; // each entry is 0x3C bytes, first dword
        if (p)
            free(p);
    }
    
    free(self->tech_array);
    self->tech_array = 0;
}
