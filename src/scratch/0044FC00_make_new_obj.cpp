// 0044FC00 RGE_Master_Animated_Object::make_new_obj
// Source: m_an_obj.cpp lines 100-114
// Size: 201 bytes, EH-framed, /GX

void* __cdecl operator_new(size_t sz);

struct RGE_Master_Animated_Object {
    char gap_00[0x04];
    unsigned char byte_04;     // +0x04
    char gap_05[0x9B];
    unsigned char byte_A0;     // +0xA0  
    char gap_A1[0x03];
    unsigned char byte_A4;     // +0xA4
    
    void* make_new_obj(void* player, float x, float y, float z);
};

void* RGE_Master_Animated_Object::make_new_obj(void* player, float x, float y, float z) {
    if (byte_A4 != 0) {
        unsigned char b = byte_04;
        void* ecx_val = *(void**)((char*)player + 0x3C);
        void* obj;
        
        // Call alloc_helper via __fastcall: ecx = ecx_val, stack = b
        typedef void* (__fastcall* AllocFn)(void* ecx, int edx, unsigned char stack);
        obj = ((AllocFn)0x00546180)(ecx_val, 0, b);
        
        if (obj != 0) {
            void** vt = *(void***)obj;
            typedef void (__fastcall* VirtFn)(void* ecx, int edx, void* p1, void* p2, float f1, float f2, float f3);
            ((VirtFn)vt[1])(obj, 0, this, player, x, y, z);
            return obj;
        }
    }
    
    void* obj = operator_new(0x8C);
    if (obj != 0) {
        typedef void (__fastcall* InitFn)(void* ecx, int edx, int p1, void* p2, void* p3, void* p4, float f1, float f2, float f3);
        ((InitFn)0x0041A150)(obj, 0, 1, this, this, player, x, y, z);
        return obj;
    }
    
    return 0;
}
