#include "../../include/victory_context.h"

RGE_Victory_Conditions::RGE_Victory_Conditions(RGE_Player* player) {
    this->player = player;
    this->list_num = 0;
    this->victory_list = 0;
    this->victory_point_list = 0;
    this->victory = 0;
    this->point_list_num = 0;
    this->tot_victory_points = 0;
}
