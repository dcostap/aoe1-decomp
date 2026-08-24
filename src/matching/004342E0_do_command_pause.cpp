// VA: 004342E0 RGE_Command::do_command_pause (59B, 27 asm lines)
// PDB source: Command.cpp lines 447-461
// Declare counter inside if block for conditional ebx save;
// id pointer before the if for unconditional esi setup

#ifndef COMMAND_TU_CONTEXT
class RGE_Static_Object;
class RGE_Command_Pause;

class RGE_Command {
public:
    virtual ~RGE_Command();
    char gap_04[0x4];
    void* world;

    RGE_Static_Object* get_obj(int id);
    void do_command_pause(RGE_Command_Pause* pause);
};

#pragma pack(push, 1)
class RGE_Command_Pause {
public:
    char gap_00;
    unsigned char unit_num;
    int object_ids[1];
};
#pragma pack(pop)

class RGE_Static_Object {
public:
    virtual void vf00() = 0;  virtual void vf04() = 0;  virtual void vf08() = 0;  virtual void vf0C() = 0;
    virtual void vf10() = 0;  virtual void vf14() = 0;  virtual void vf18() = 0;  virtual void vf1C() = 0;
    virtual void vf20() = 0;  virtual void vf24() = 0;  virtual void vf28() = 0;  virtual void vf2C() = 0;
    virtual void vf30() = 0;  virtual void vf34() = 0;  virtual void vf38() = 0;  virtual void vf3C() = 0;
    virtual void vf40() = 0;  virtual void vf44() = 0;  virtual void vf48() = 0;  virtual void vf4C() = 0;
    virtual void vf50() = 0;  virtual void vf54() = 0;  virtual void vf58() = 0;  virtual void vf5C() = 0;
    virtual void vf60() = 0;  virtual void vf64() = 0;  virtual void vf68() = 0;  virtual void vf6C() = 0;
    virtual void vf70() = 0;  virtual void vf74() = 0;  virtual void vf78() = 0;  virtual void vf7C() = 0;
    virtual void vf80() = 0;  virtual void vf84() = 0;  virtual void vf88() = 0;  virtual void vf8C() = 0;
    virtual void vf90() = 0;  virtual void vf94() = 0;  virtual void vf98() = 0;  virtual void vf9C() = 0;
    virtual void vfA0() = 0;  virtual void vfA4() = 0;  virtual void vfA8() = 0;  virtual void vfAC() = 0;
    virtual void vfB0() = 0;  virtual void vfB4() = 0;  virtual void vfB8() = 0;  virtual void vfBC() = 0;
    virtual void vfC0() = 0;  virtual void vfC4() = 0;  virtual void vfC8() = 0;  virtual void vfCC() = 0;
    virtual void vfD0() = 0;  virtual void vfD4() = 0;  virtual void vfD8() = 0;  virtual void vfDC() = 0;
    virtual void vfE0() = 0;  virtual void vfE4() = 0;  virtual void vfE8() = 0;  virtual void vfEC() = 0;
    virtual void vfF0() = 0;  virtual void vfF4() = 0;  virtual void vfF8() = 0;  virtual void vfFC() = 0;
    virtual void vf100() = 0; virtual void vf104() = 0; virtual void vf108() = 0; virtual void vf10C() = 0;
    virtual void vf110() = 0; virtual void vf114() = 0; virtual void vf118() = 0; virtual void vf11C() = 0;
    virtual void vf120() = 0; virtual void vf124() = 0; virtual void vf128() = 0; virtual void vf12C() = 0;
    virtual void vf130() = 0; virtual void vf134() = 0; virtual void vf138() = 0; virtual void vf13C() = 0;
    virtual void vf140() = 0; virtual void vf144() = 0; virtual void vf148() = 0; virtual void vf14C() = 0;
    virtual void vf150() = 0; virtual void vf154() = 0; virtual void vf158() = 0; virtual void vf15C() = 0;
    virtual void vf160() = 0; virtual void vf164() = 0; virtual void vf168() = 0; virtual void vf16C() = 0;
    virtual void vf170() = 0; virtual void vf174() = 0; virtual void vf178() = 0; virtual void vf17C() = 0;
    virtual void vf180() = 0; virtual void vf184() = 0; virtual void vf188() = 0; virtual void vf18C() = 0;
    virtual void pause_callback() = 0;
};
#endif

void RGE_Command::do_command_pause(RGE_Command_Pause* pause) {
    int count = pause->unit_num;
    int* id = pause->object_ids;
    if (count > 0) {
        int cnt = count;
        do {
            RGE_Static_Object* obj = this->get_obj(*id);
            if (obj != 0) {
                obj->pause_callback();
            }
            id++;
            cnt--;
        } while (cnt != 0);
    }
}
