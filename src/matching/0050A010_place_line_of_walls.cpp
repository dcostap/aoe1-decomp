// VA: 0050A010 TRIBE_Command::place_line_of_walls
// PDB: tcommand.cpp lines 456-503.
#include "../tcommand_context.h"

void TRIBE_Command::place_line_of_walls(
    TRIBE_Player* player,
    TRIBE_Master_Building_Object* master,
    int object_id,
    int start_x,
    int start_y,
    int end_x,
    int end_y,
    RGE_Static_Object** result)
{
    int y_skip;
    int x_skip;

    if (start_x == end_x) {
        y_skip = 0;
    } else {
        y_skip = (((int)(end_x <= start_x) - 1) & 2) - 1;
    }

    if (start_y == end_y) {
        x_skip = 0;
    } else {
        x_skip = (((int)(end_y <= start_y) - 1) & 2) - 1;
    }

    int temp = start_y;
    start_y = start_x;
    start_x = temp;

    for (;;) {
        float coordinate_x = (float)start_y + 0.5f;
        float coordinate_y = (float)start_x + 0.5f;
        if (((RGE_Master_Static_Object*)master)->check_placement(
                player,
                coordinate_x,
                coordinate_y,
                0, 1, master->elevation_flag,
                0, 1, 1, 1) == 0) {
            if (player->pay_obj_cost(master->id, 1.0f, 0) == 0) {
                return;
            }

            RGE_Static_Object* object = master->make_new_obj(
                player,
                coordinate_x,
                coordinate_y,
                0,
                object_id);
            if (object != 0 && *result == 0) {
                *result = object;
            }
        }

        if (start_y == end_x && start_x == end_y) {
            break;
        }

        start_y += y_skip;
        start_x += x_skip;
    }
}
