// VA: 0053D620 mouse_right_down_action (126B)
// vw_dimap.cpp

extern int g_rge_base_game;
int __cdecl get_paused();

class RGE_Diamond_Map_View {
public:
    virtual ~RGE_Diamond_Map_View();
    char gap0[0xC];
    void* diamondMap;
    
    int mouse_right_down_action(int x, int y, int key, int flags);
};

int __cdecl start_scroll_view(void* view, int x, int y);
int __cdecl capture_mouse(void* view);

int RGE_Diamond_Map_View::mouse_right_down_action(int x, int y, int key, int flags) {
    int prog_mode;
    void* game = *(void**)g_rge_base_game;
    
    if (get_paused()) return 0;
    
    prog_mode = *(int*)((char*)game + 0x1B0);
    if (prog_mode == 4 || prog_mode == 6 || prog_mode == 7 || prog_mode == 5) {
        void* prog_info = *(void**)((char*)game + 0x0C);
        if (*(short*)((char*)prog_info + 0x8DC) == 2) {
            if (prog_mode == 4 || prog_mode == 6 || prog_mode == 7) {
                capture_mouse(this);
            }
            return 1;
        }
        start_scroll_view(this, x, y);
        return 1;
    }
    return 0;
}
