#ifndef VICTORY_CONTEXT_H
class RGE_Victory_Point_Entry {
public:
    unsigned char command;
    unsigned char state;
    unsigned char id;
    unsigned char group;
    long attribute;
    long amount;
    long points;
    long curr_points;
    float curr_attribute_amount;
    RGE_Victory_Point_Entry* next;
};

class RGE_Player {
public:
    char gap_00[0x50];
    float* attributes;
};

class RGE_Victory_Conditions {
public:
    void* vtable_ptr;
    char gap_04[0x8];
    RGE_Player* player;
    unsigned char victory;
    char gap_11[0x3];
    RGE_Victory_Point_Entry* victory_point_list;
    long point_list_num;
    long tot_victory_points;

    void handle_points_attribute_amount(RGE_Victory_Point_Entry*);
};
#endif

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
