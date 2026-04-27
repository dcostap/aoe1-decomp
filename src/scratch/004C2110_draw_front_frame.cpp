// VA: 004C2110 draw_front_frame (125B)
// stat_obj.cpp

extern int* rge_base_game;

void __cdecl draw_something(int a1, int a2, int a3);

void __cdecl draw_front_frame(int x, int y, int z) {
    if (rge_base_game && *(int*)((char*)rge_base_game + 0x1B4) == 1) {
        draw_something(x, y, z);
    }
}
