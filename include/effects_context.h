#ifndef EFFECTS_CONTEXT_H
#define EFFECTS_CONTEXT_H

// Binary-proven record widths are 0x0C and 0x2C.
struct RGE_Effect_Command {
    unsigned char command;
    unsigned char _pad_0;
    short change_num1;
    short change_num2;
    short change_num3;
    float change_amount;
};

typedef char effects_command_size_check[
    (sizeof(RGE_Effect_Command) == 0x0C) ? 1 : -1];

struct RGE_Effect {
    short id;
    char name[31];
    unsigned char _pad_0;
    short string_table_id;
    short effect_list_num;
    unsigned char _pad_1[2];
    RGE_Effect_Command* effect_list;
};

typedef char effects_record_size_check[
    (sizeof(RGE_Effect) == 0x2C) ? 1 : -1];

class RGE_Player;

class RGE_Effects {
public:
    RGE_Effect* effects;
    long effect_num;

    virtual ~RGE_Effects();
    virtual void save(int fd);
    virtual void do_effect(short effect_id, RGE_Player* player);

    RGE_Effects(int fd);
    RGE_Effects(char* path);
};

typedef char effects_object_size_check[
    (sizeof(RGE_Effects) == 0x0C) ? 1 : -1];

#endif
