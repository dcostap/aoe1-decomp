// target: VA 004AA730 TRIBE_Screen_Sed::set_paint_object_mode(void)
// first pass: use the shared working headers and keep the gate/call shape direct
// tried shared headers; they only expose forward decls here, so the member body still needs a local surface
// tried local stubs earlier; the member definition collided with an existing declaration in this TU context

#include "..\..\include\game_types.h"
#include "..\..\include\game_globals.h"

void TRIBE_Screen_Sed::set_paint_object_mode() {
    int enabled;
    RGE_Static_Object* object;
    unsigned char* object_bytes;

    enabled = 0;
    if (rge_base_game->master_obj_id != -1) {
        object = this->world->object(rge_base_game->master_obj_id);
        if (object != 0) {
            object_bytes = (unsigned char*)object;
            if (object_bytes[4] == 0x50 && object_bytes[0x16C] != 0) {
                enabled = 1;
            }
        }
    }

    if (enabled != 0) {
        ((void (*)(RGE_Base_Game*, int, int))(*(void***)rge_base_game)[4])(rge_base_game, 0x15, 0);
        return;
    }

    ((void (*)(RGE_Base_Game*, int, int))(*(void***)rge_base_game)[4])(rge_base_game, 8, rge_base_game->sub_game_mode);
}
