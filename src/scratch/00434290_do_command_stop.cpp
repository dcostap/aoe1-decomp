// tried a direct loop with packed stop-record fields; compiler still put the stack arg load before the ebx save
// tried the decompiler-style count/pointer loop and then a packed 1-byte header + +2 data layout; mismatch stayed at entry prolog
// remaining gap looks like register allocation / prolog shape, not the loop body

struct RGE_Command_Stop;

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

    void removeAllFromPathingGroup(void);
};

class RGE_Game_World {
public:
    RGE_Static_Object* object(int id);
};

class RGE_Command {
public:
    char gap_00[4];
    RGE_Game_World* world;

    RGE_Static_Object* get_obj(int id);
    void do_command_stop(RGE_Command_Stop* stop);
};

#pragma pack(push, 1)
struct RGE_Command_Stop {
    char gap_00[1];
    unsigned char unit_num;
    int object_ids[1];
};
#pragma pack(pop)

void RGE_Command::do_command_stop(RGE_Command_Stop* stop) {
    unsigned char count = stop->unit_num;
    int* pRVar2 = stop->object_ids;

    if (count > 0) {
        do {
            RGE_Static_Object* this_00 = this->get_obj(*pRVar2);
            if (this_00 != 0) {
                this_00->removeAllFromPathingGroup();
                this_00->vfA4();
            }
            pRVar2 = pRVar2 + 1;
        } while (--count != 0);
    }
}
