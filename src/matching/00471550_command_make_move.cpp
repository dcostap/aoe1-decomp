#ifndef PLAYER_GROUPED_TU
#include "../player_tu_context.h"
#endif
extern void __cdecl free(void*);
unsigned char RGE_Player::command_make_move(RGE_Static_Object* target, float x, float y) {
    RGE_Static_Object** list;
    // BINARY NOTE: The selection helper writes a short count into a dword home.
    int list_num;
    if (get_selected_objects_to_command(&list, (short*)&list_num, -1, -1, -1, -1)) {
        list[0]->play_move_sound();
        this->world->command->command_order(list, list_num, target, x, y);
        free(list);
        return 1;
    }
    return 0;
}
