// VA: 0050A510 TRIBE_Command::do_command_give_attribute
// PDB: tcommand.cpp lines 708-770.
#include "../tcommand_context.h"

void TRIBE_Command::do_command_give_attribute(TRIBE_Command_Give_Attribute* ca)
{
    float cost;
    float v;

    cost = 0.0f;
    if (ca->attr_amount >= 0.0f) {
        v = ca->attr_amount;
    } else {
        v = 0.0f;
    }

    if (v > 0.0) {
        cost = ca->attr_cost * v;
    }

    {
        float* attr_ptr = &this->world->players[ca->player_id]->attributes[ca->attr_id];
        if (v + cost > *attr_ptr) {
            cost = *attr_ptr;
            cost *= ca->attr_cost;
            v = *attr_ptr - cost;
        }
    }

    this->world->players[ca->to_player_id]->add_attribute_num(ca->attr_id, v, 0);
    this->world->players[ca->player_id]->add_attribute_num(ca->attr_id, -(v + cost), 0);
    this->world->players[ca->player_id]->add_attribute_num(0x35, v + cost, 0);
    this->world->players[ca->to_player_id]->add_attribute_num(0x35, -v, 0);
    rge_base_game->notification(7, ca->player_id, ca->to_player_id,
                                ca->attr_id, (long)v);
    this->world->players[ca->to_player_id]->sendEvent(
        ca->player_id, ca->to_player_id, 0x20A, ca->attr_id,
        (long)ca->attr_amount, 0);
}
