// VA: 0050A7B0 TRIBE_Command::do_command_queue
// PDB: tcommand.cpp lines 852-867.

#include "../tcommand_context.h"

void TRIBE_Command::do_command_queue(TRIBE_Command_Queue* queue) {
    TRIBE_Building_Object* building = this->world->object(queue->bldg_id);
    if (building != 0) {
        if (0 < queue->train_count) {
            building->add_to_production_queue(queue->train_id, queue->train_count);
            return;
        }
        building->remove_from_production_queue(
            queue->train_id, (short)-queue->train_count);
    }
}
