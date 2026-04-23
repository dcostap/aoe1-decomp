// tried a direct thiscall virtual dispatch shape; VC5 still hoists the world load before param_1
// remaining gap is a prolog register-order issue only
class RGE_Player {
public:
    virtual void vf00(void);
    virtual void vf04(void);
    virtual void vf08(void);
    virtual void vf0C(void);
    virtual void vf10(void);
    virtual void vf14(void);
    virtual void vf18(void);
    virtual void vf1C(void);
    virtual void vf20(void);
    virtual void vf24(void);
    virtual void vf28(void);
    virtual void vf2C(void);
    virtual void vf30(void);
    virtual void vf34(void);
    virtual void vf38(void);
    virtual void vf3C(void);
    virtual void vf40(void);
    virtual void vf44(void);
    virtual void vf48(void);
    virtual void vf4C(void);
    virtual void vf50(void);
    virtual void vf54(void);
    virtual void vf58(void);
    virtual void vf5C(void);
    virtual void vf60(void);
    virtual void vf64(void);
    virtual void vf68(void);
    virtual void vf6C(void);
    virtual void vf70(void);
    virtual void vf74(void);
    virtual void add_attribute_num(short param_1, float param_2, unsigned char param_3);
};

struct RGE_Command_Add_Attribute {
    unsigned char command;
    unsigned char player_id;
    unsigned char attr_id;
    unsigned char _pad_0[0x1];
    float attr_amount;
};

class RGE_Game_World {
public:
    char gap_00[0x40];
    RGE_Player** players;
};

class RGE_Command {
public:
    char gap_00[0x4];
    RGE_Game_World* world;

    void do_command_add_attribute(RGE_Command_Add_Attribute* param_1);
};

void RGE_Command::do_command_add_attribute(RGE_Command_Add_Attribute* param_1) {
    unsigned char player_id = param_1->player_id;
    this->world->players[player_id]->add_attribute_num(param_1->attr_id, param_1->attr_amount, 0);
}
