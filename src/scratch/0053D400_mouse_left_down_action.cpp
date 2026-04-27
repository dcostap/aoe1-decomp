// VA: 0053D400 mouse_left_down_action (126B)
// vw_dimap.cpp lines 50-63

extern int __cdecl get_paused();
extern int __cdecl start_scroll_view(void*, int, int);
extern int __cdecl capture_mouse(void*);

extern void* rge_base_game;

class RGE_Diamond_Map_View {
public:
    virtual ~RGE_Diamond_Map_View();
    char gap0[0xC];
    void* diamondMap;
    
    int mouse_left_down_action(int x, int y, int key, int flags);
};

int RGE_Diamond_Map_View::mouse_left_down_action(int x, int y, int key, int flags) {
    void* game;
    int prog_mode;
    void* prog_info;
    
    if (get_paused()) return 0;
    
    game = *(void**)rge_base_game;
    prog_mode = *(int*)((char*)game + 0x1B0);
    if (prog_mode == 4 || prog_mode == 6 || prog_mode == 7 || prog_mode == 5) {
        prog_info = *(void**)((char*)game + 0x0C);
        if (*(short*)((char*)prog_info + 0x8DC) == 2) {
            start_scroll_view(this, x, y);
        } else {
            if (prog_mode == 4 || prog_mode == 6 || prog_mode == 7) {
                capture_mouse(this);
            }
        }
        return 1;
    }
    
    return 0;
}
