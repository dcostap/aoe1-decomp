// ~TDrawSystem — real pass
// VA: 00442710

void __fastcall dtor_TDrawSystem(void* _this, int _)
{
    // Check if +0x479 byte == 2 and +0x1C non-null → release via vtable[0x14]
    if (*(char*)((char*)_this + 0x479) == 2 && *(void**)((char*)_this + 0x1C)) {
        void* ddb = *(void**)((char*)_this + 0x1C);
        void* vtable = *(void**)ddb;
        int buf[32];
        buf[0] = 0x64;
        buf[28] = 0;
        ((void(__stdcall*)(void*,void*,int,int,int,int,void*))((int*)vtable)[0x14/4])(ddb, (void*)0, 0, 0, 0, 0x1000400, buf);
    }
    
    // DeleteSurfaces
    ((void(__fastcall*)(void*,int))0x443090)(_this, 0);
    
    // Release and null surfaces
    if (*(void**)((char*)_this + 0x18)) {
        if (*(void**)((char*)_this + 0x24)) {
            void* v = *(void**)((char*)_this + 0x24);
            void* vt = *(void**)v;
            ((void(__stdcall*)(void*))(*((void**)vt + 2)))(v);
            *(void**)((char*)_this + 0x24) = 0;
        }
        if (*(void**)((char*)_this + 0x20)) {
            void* w = *(void**)((char*)_this + 0x20);
            void* vt2 = *(void**)w;
            ((void(__stdcall*)(void*))(*((void**)vt2 + 2)))(w);
            *(void**)((char*)_this + 0x20) = 0;
        }
        // For field +0x3C
        if (*(void**)((char*)_this + 0x3C)) {
            void* primary = *(void**)((char*)_this + 0x18);
            void* vt3 = *(void**)primary;
            ((void(__stdcall*)(void*))(*((void**)vt3 + 19)))(primary);
            *(void**)((char*)_this + 0x3C) = 0;
        }
        // Release primary surface
        void* primary = *(void**)((char*)_this + 0x18);
        void* vt4 = *(void**)primary;
        ((void(__stdcall*)(void*))(*((void**)vt4 + 2)))(primary);
        *(void**)((char*)_this + 0x18) = 0;
    }
}
