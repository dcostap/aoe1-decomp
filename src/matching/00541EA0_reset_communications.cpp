#include "../../include/world_scenario_context.h"

void RGE_Game_World::reset_communications(TCommunications_Handler* communications) {
    this->commands->reset_communications(communications);
}
