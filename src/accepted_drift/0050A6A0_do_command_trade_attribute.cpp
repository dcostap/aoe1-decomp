// VA: 0050A6A0 TRIBE_Command::do_command_trade_attribute
// PDB: tcommand.cpp lines 776-789.
// ACCEPTED_DRIFT: natural shared-closure reconstruction.
#include "../tcommand_context.h"

void TRIBE_Command::do_command_trade_attribute(TRIBE_Command_Trade_Attribute* packet)
{
    int count = packet->unit_num;
    unsigned char* ids = (unsigned char*)(packet + 1);
    if (count > 0) {
        do {
            RGE_Static_Object* object = this->get_obj(*(int*)ids);
            if (object != 0) {
                object->attribute_type_held = (short)packet->attribute;
            }
            ids += 4;
        } while (--count != 0);
    }
}
