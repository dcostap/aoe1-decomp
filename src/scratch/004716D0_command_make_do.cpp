#ifndef PLAYER_GROUPED_TU
#include "../player_tu_context.h"
#endif

extern void __cdecl free(void*);

unsigned char RGE_Player::command_make_do(RGE_Static_Object* target, float x, float y) {
    RGE_Static_Object** list;
    // BINARY NOTE: The helper writes a short count into a dword home.
    // The command call forwards that complete home.
    int local_count;
    if (get_selected_objects_to_command(&list, (short*)&local_count, -1, -1, -1, -1)) {
        RGE_Master_Static_Object* master = list[0]->get_command_master(target, x, y, 0);
        if (master != 0) {
            master->play_command_sound();
        }
        this->world->command->command_order(list, local_count, target, x, y);
        free(list);
        return 1;
    }
    return 0;
}
