#include "../../include/victory_context.h"

RGE_Victory_Conditions::~RGE_Victory_Conditions() {
    RGE_Victory_Entry* entry = this->victory_list;
    *(void**)this = (void*)0x005775A8;
    while (entry != 0) {
        this->sub(entry);
        entry = this->victory_list;
    }

    RGE_Victory_Point_Entry* point = this->victory_point_list;
    while (point != 0) {
        this->sub_point(point);
        point = this->victory_point_list;
    }

    this->list_num = 0;
    this->point_list_num = 0;
    this->victory = 0;
    this->player = 0;
}
