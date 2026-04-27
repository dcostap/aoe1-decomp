// VA: 0048A320 key_down_action (509B)
// rpnl_tbx.cpp lines 312-372

extern int* rge_base_game;
extern int __cdecl get_paused();

class RGE_Panel_Tool_Box {
public:
    virtual ~RGE_Panel_Tool_Box();
    char gap0[0xF8];
    int field_F8;       // +0xF8 child panel
    char gapFC[0xB4];
    int field_1B0;      // +0x1B0 (from game pointer)
    
    int key_down_action(int key, int a2, int a3, int a4, int a5);
};

int RGE_Panel_Tool_Box::key_down_action(int key, int a2, int a3, int a4, int a5) {
    int* game = rge_base_game;
    
    if (get_paused()) return 0;
    
    int progMode = *(int*)((char*)game + 0x1B0);
    if (progMode != 4 && progMode != 6 && progMode != 7) return 0;
    
    switch (key) {
    case 0x21:  // VK_PRIOR / PageUp
        // handle page up
        return 1;
    case 0x22:  // VK_NEXT / PageDown
        // handle page down
        if (*(int*)((char*)game + 0x1B4) == 0x12) {
            // Look up something
            // Check conditions
            // If condition, call vtable method and return 1
        }
        return 0;
    default:
        return 0;
    }
}
