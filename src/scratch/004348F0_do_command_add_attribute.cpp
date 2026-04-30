// VA: 004348F0 do_command_add_attribute (40B)
// Command.cpp - local forced to control scheduling

class RGE_Player002 {
public:
    virtual void v00(); virtual void v04(); virtual void v08();
    virtual void v0C(); virtual void v10(); virtual void v14();
    virtual void v18(); virtual void v1C(); virtual void v20();
    virtual void v24(); virtual void v28(); virtual void v2C();
    virtual void v30(); virtual void v34(); virtual void v38();
    virtual void v3C(); virtual void v40(); virtual void v44();
    virtual void v48(); virtual void v4C(); virtual void v50();
    virtual void v54(); virtual void v58(); virtual void v5C();
    virtual void v60(); virtual void v64(); virtual void v68();
    virtual void v6C(); virtual void v70(); virtual void v74();
    virtual void add_attribute_num(unsigned short attr_id, int attr_amount, int zero);
};

struct RGE_Command_Add_Attribute {
    unsigned char command;    // +0x00
    unsigned char player_id;  // +0x01
    unsigned char attr_id;    // +0x02
    unsigned char _pad_03;    // +0x03
    int attr_amount;          // +0x04
};

class RGE_Game_World_002 {
public:
    char gap_00[0x40];
    RGE_Player002** players;
};

class RGE_Command_002 {
public:
    char gap_00[0x04];
    RGE_Game_World_002* world;

    void do_command_add_attribute(RGE_Command_Add_Attribute* param_1);
};

void RGE_Command_002::do_command_add_attribute(RGE_Command_Add_Attribute* param_1) {
    RGE_Player002* player = this->world->players[param_1->player_id];
    player->add_attribute_num(param_1->attr_id, param_1->attr_amount, 0);
}
