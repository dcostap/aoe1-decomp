// 005236A0 TRIBE_Game::show_status_message
// tribegam.cpp:1216-1230, 164 bytes, __thiscall, ret 0Ch

extern "C" void* panel_system;  // 0x62E870

class TRIBE_Game {
public:
    void show_status_message(char* s1, char* s2, long p3);
};

void TRIBE_Game::show_status_message(char* s1, char* s2, long p3) {
    __try {
        void* addr;
        
        addr = (void*)0x00463D50;
        void* p = (*(void* (__thiscall**)(void*, const char*))&addr)(&panel_system, "Status Screen");
        
        if (p != 0) {
            addr = (void*)0x004B7560;
            (*(void (__thiscall**)(void*, const char*))&addr)(p, s1);
            
            addr = (void*)0x00420360;
            (*(void (__thiscall**)(void*))&addr)(this);
        } else {
            addr = (void*)0x0054B6F0;
            void* np = (*(void* (__cdecl**)(unsigned int))&addr)(0x47C);
            
            int guard = 0;
            if (np != 0) {
                addr = (void*)0x004B7140;
                (*(void (__thiscall**)(void*, const char*, const char*, const char*, long))&addr)(np, "Status Screen", s1, s2, p3);
            }
            guard = -1;
        }
        
        addr = (void*)0x00463E60;
        (*(int (__thiscall**)(void*, const char*, int))&addr)(&panel_system, "Status Screen", 0);
    }
    __except(1) {
    }
}
