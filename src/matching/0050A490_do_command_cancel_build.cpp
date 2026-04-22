class RGE_Static_Object {
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
    virtual void vfB0(void);
    virtual void vfB4(void);
    virtual void vfB8(void);
    virtual void vfBC(void);
    virtual void vfC0(void);
    virtual void vfC4(void);
    virtual void vfC8(void);
    virtual void vfCC(void);
    virtual void vfD0(void);
    virtual void vfD4(void);
    virtual void vfD8(void);
    virtual void vfDC(void);
    virtual void vfE0(void);
    virtual void vfE4(void);
    virtual void vfE8(void);
    virtual void vfEC(void);
    virtual void vfF0(void);
    virtual void vfF4(void);
    virtual void vfF8(void);
    virtual void vfFC(void);
    virtual void vf100(void);
    virtual void vf104(void);
    virtual void vf108(void);
    virtual void vf10C(void);
    virtual void vf110(void);
    virtual void vf114(void);
    virtual void vf118(void);
    virtual void vf11C(void);
    virtual void vf120(void);
    virtual void vf124(void);
    virtual void vf128(void);
    virtual void vf12C(void);
    virtual void vf130(void);
    virtual void vf134(void);
    virtual void vf138(void);
    virtual void vf13C(void);
    virtual void vf140(void);
    virtual void vf144(void);
    virtual void vf148(void);
    virtual void vf14C(void);
    virtual void vf150(void);
    virtual void vf154(void);
    virtual void vf158(void);
    virtual void vf15C(void);
    virtual void vf160(void);
    virtual void vf164(void);
    virtual void vf168(void);
    virtual void vf16C(void);
    virtual void vf170(void);
    virtual void vf174(void);
    virtual void vf178(void);
    virtual void vf17C(void);
    virtual void vf180(void);
    virtual void vf184(void);
    virtual void vf188(void);
    virtual void vf18C(void);
    virtual void vf190(void);
    virtual void vf194(void);
    virtual void vf198(void);
    virtual void vf19C(void);
    virtual void vf1A0(void);
    virtual void vf1A4(void);
    virtual void vf1A8(void);
    virtual void vf1AC(void);
    virtual void vf1B0(void);
    virtual void vf1B4(void);
    virtual void vf1B8(void);
    virtual void vf1BC(void);
    virtual void vf1C0(void);
    virtual void vf1C4(void);
    virtual void vf1C8(void);
    virtual void vf1CC(void);
    virtual void vf1D0(void);
    virtual void vf1D4(void);
    virtual void vf1D8(void);
    virtual void vf1DC(void);
    virtual void vf1E0(void);
    virtual void vf1E4(void);
    virtual void vf1E8(void);
    virtual void vf1EC(void);
    virtual void vf1F0(void);
    virtual void vf1F4(void);
    virtual void vf1F8(void);
    virtual void vf1FC(void);
    virtual void vf200(void);
    virtual void vf204(void);
    virtual void vf208(void);
    virtual void vf20C(void);
    virtual void vf210(void);
    virtual void vf214(void);
    virtual void vf218(void);
    virtual void vf21C(void);
    virtual void vf220(void);
    virtual void vf224(void);
    virtual void vf228(void);
    virtual void vf22C(void);
    virtual void vf230(void);
    virtual void vf234(void);
    virtual void vf238(void);
    virtual void vf23C(void);
    virtual void cancel_build(void);
};

class RGE_Game_World {
public:
    RGE_Static_Object* object(int id);
};

struct TRIBE_Command_Cancel_Build {
    char gap_00[0x04];
    int unit_id;
};

class TRIBE_Command {
public:
    void* vfptr;
    RGE_Game_World* world;

    void do_command_cancel_build(TRIBE_Command_Cancel_Build* cmd);
};

void TRIBE_Command::do_command_cancel_build(TRIBE_Command_Cancel_Build* cmd) {
    RGE_Static_Object* object;

    object = this->world->object(cmd->unit_id);
    if (object != 0) {
        object->cancel_build();
    }
}
