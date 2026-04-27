// VA: 00513860
// TRIBE_Player::command_attack_ground(float, float)
// Source: tplayer.cpp lines 1228-1241

// attempt 1: same pattern as matched command_trade_attribute -> EXACT MATCH (111/111, 0.0000%)
// default flags; sibling of 005137D0 with (float,float) params instead of (long)

void __cdecl free(void*);

class RGE_Static_Object;

class SelectedObject {
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
    virtual void vf78(void);
    virtual void vf7C(void);
    virtual void vf80(void);
    virtual void vf84(void);
    virtual void vf88(void);
    virtual void vf8C(void);
    virtual void vf90(void);
    virtual void vf94(void);
    virtual void vf98(void);
    virtual void vf9C(void);
    virtual void vfA0(void);
    virtual void vfA4(void);
    virtual void vfA8(void);
    virtual void vfAC(void);
};

class RGE_Command {
public:
    void command_attack_ground(RGE_Static_Object** list, short list_num, float x, float y);
};

class PlayerWorld {
public:
    char gap_00[0x58];
    RGE_Command* commands;
};

class RGE_Player {
public:
    char gap_00[0x3C];
    PlayerWorld* world;

    unsigned char get_selected_objects_to_command(RGE_Static_Object*** list, short* list_num, int a, int b, int c, int d);
};

class TRIBE_Player : public RGE_Player {
public:
    unsigned char command_attack_ground(float x, float y);
};

unsigned char TRIBE_Player::command_attack_ground(float x, float y) {
    RGE_Static_Object** list;
    short local_4[2];

    if (this->get_selected_objects_to_command(&list, local_4, 4, -1, -1, 4)) {
        ((SelectedObject*)*list)->vfAC();
        this->world->commands->command_attack_ground(list, local_4[0], x, y);
        free(list);
        return 1;
    }

    return 0;
}
