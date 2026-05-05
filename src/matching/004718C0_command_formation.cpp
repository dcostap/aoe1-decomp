// 004718C0 RGE_Player::command_formation
// Pattern from neighboring matched command_* helpers.

void __cdecl free(void*);

class RGE_Static_Object;

class SelectedObject {
public:
    virtual void vf00(void); virtual void vf04(void); virtual void vf08(void); virtual void vf0C(void);
    virtual void vf10(void); virtual void vf14(void); virtual void vf18(void); virtual void vf1C(void);
    virtual void vf20(void); virtual void vf24(void); virtual void vf28(void); virtual void vf2C(void);
    virtual void vf30(void); virtual void vf34(void); virtual void vf38(void); virtual void vf3C(void);
    virtual void vf40(void); virtual void vf44(void); virtual void vf48(void); virtual void vf4C(void);
    virtual void vf50(void); virtual void vf54(void); virtual void vf58(void); virtual void vf5C(void);
    virtual void vf60(void); virtual void vf64(void); virtual void vf68(void); virtual void vf6C(void);
    virtual void vf70(void); virtual void vf74(void); virtual void vf78(void); virtual void vf7C(void);
    virtual void vf80(void); virtual void vf84(void); virtual void vf88(void); virtual void vf8C(void);
    virtual void vf90(void); virtual void vf94(void); virtual void vf98(void); virtual void vf9C(void);
    virtual void vfA0(void); virtual void vfA4(void); virtual void vfA8(void); virtual void vfAC(void);
};

class RGE_Command {
public:
    void command_formation(RGE_Static_Object** list, int list_num, int formation);
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
    unsigned char command_formation(int formation);
};

unsigned char RGE_Player::command_formation(int formation) {
    RGE_Static_Object** list;

    if (formation >= 0 && formation <= 5) {
        int iVar1 = formation;
        if (this->get_selected_objects_to_command(&list, (short*)&formation, -1, -1, -1, -1)) {
            ((SelectedObject*)*list)->vfAC();
            this->world->commands->command_formation(list, *(short*)&formation, iVar1);
            free(list);
            return 1;
        }
    }

    return 0;
}
