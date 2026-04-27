// VA: 0053D6A0 mouse_right_move_action (114B)
// vw_dimap.cpp

extern int g_rge_base_game;
int __cdecl get_paused();

class RGE_Diamond_Map_View {
public:
    virtual ~RGE_Diamond_Map_View();
    char gap0[0x154];
    int field_154;
    
    int mouse_right_move_action(int x, int y, int key, int flags);
};

int __cdecl scroll_map(void* view, int x, int y);
int __cdecl capture_mouse_release(void* view);

int RGE_Diamond_Map_View::mouse_right_move_action(int x, int y, int key, int flags) {
    int prog_mode;
    void* game = *(void**)g_rge_base_game;
    
    prog_mode = *(int*)((char*)game + 0x1B0);
    if (prog_mode == 4 || prog_mode == 6 || prog_mode == 7 || prog_mode == 5) {
        if (get_paused()) {
            if (field_154) {
                scroll_map(this, x, y);
            }
            return 0;
        } else {
            if (field_154) {
                scroll_map(this, x, y);
            }
            return 1;
        }
    }
    return 0;
}
