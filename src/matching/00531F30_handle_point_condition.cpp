#include "../../include/victory_context.h"

void RGE_Victory_Conditions::handle_point_condition(RGE_Victory_Point_Entry* param_1) {
    switch (param_1->command) {
    case 0:
        this->handle_points_attribute_amount(param_1);
        return;
    case 1:
        this->handle_points_attribute_first(param_1);
        return;
    case 2:
        this->handle_points_highest_attribute(param_1);
        return;
    case 3:
        this->handle_points_high_attribute_once(param_1);
        return;
    case 4:
        this->handle_points_high_attribute_amount(param_1);
        return;
    }
}
