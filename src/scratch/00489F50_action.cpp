// VA: 00489F50 action (973B)
// rpnl_tbx.cpp

class RGE_Panel_Tool_Box {
public:
    virtual ~RGE_Panel_Tool_Box();
    char fields[0x400];
    
    int action(int a1, int a2);
};

extern int* rge_base_game;
extern int __cdecl get_paused();

int RGE_Panel_Tool_Box::action(int a1, int a2) {
    int* game = rge_base_game;
    
    if (get_paused()) return 0;
    
    int progMode = *(int*)((char*)game + 0x1B0);
    if (progMode != 4 && progMode != 6 && progMode != 7) return 0;
    
    // Handle action based on a1, a2
    switch (a1) {
    case 0:
        // build mode
        break;
    case 1:
        // select mode
        break;
    case 2:
        // delete mode
        break;
    default:
        break;
    }
    
    return 1;
}
