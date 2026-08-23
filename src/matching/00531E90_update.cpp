#include "../../include/victory_context.h"

unsigned char RGE_Victory_Conditions::update() {
    {
        for (RGE_Victory_Point_Entry* p = victory_point_list; p != 0; p = p->next) {
            if (p->state != 3 && p->state != 1) {
                this->handle_point_condition(p);
            }
        }
    }
    {
        for (RGE_Victory_Entry* p = victory_list; p != 0; p = p->next) {
            if (p->state != 3 && p->state != 1) {
                this->handle_condition(p);
            }
        }
    }
    check_for_victory();
    return victory;
}
