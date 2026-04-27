// VA: 004C2220 capture_frame (134B)
// stat_obj.cpp

extern int* rge_base_game;
extern int some_global_flag;

void __cdecl draw_something(int a1, int a2, int a3);

void __cdecl capture_frame(int x, int y, int z) {
    if (!some_global_flag) return;
    
    if (rge_base_game && *(int*)((char*)rge_base_game + 0x1B4) == 1) {
        draw_something(x, y, z);
    }
}
