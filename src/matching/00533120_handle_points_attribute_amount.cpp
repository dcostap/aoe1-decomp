#include "../../include/victory_context.h"

void RGE_Victory_Conditions::handle_points_attribute_amount(RGE_Victory_Point_Entry* param_1) {
    if (param_1->state == 0) {
        int iVar1 = (int)this->player->attributes[param_1->attribute];
        int iVar2 = iVar1 / param_1->amount;
        param_1->curr_attribute_amount = (float)iVar1;
        if (iVar2 < 0) {
            iVar2 = 0;
        }
        iVar2 = param_1->points * iVar2;
        if (iVar2 != param_1->curr_points) {
            this->tot_victory_points += iVar2 - param_1->curr_points;
            param_1->curr_points = iVar2;
        }
    }
}
