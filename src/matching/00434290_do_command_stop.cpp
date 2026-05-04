// VA: 00434290 do_command_stop (70 B)
// PDB source: Command.cpp lines 425-442
// attempt 2: mirror the exact pause-family topology
// - count before id to mimic the exact pause-family source order
// - id pointer at function scope for unconditional edi save/setup
// - counter inside the if block for conditional ebp save
// - object local inside the loop for conditional esi save

class RGE_Static_Object;
class RGE_Command_Stop;

class RGE_Command {
public:
    virtual ~RGE_Command();
    char gap_04[0x4];
    void* world;

    RGE_Static_Object* get_obj(int id);
    void do_command_stop(RGE_Command_Stop* stop);
};

#pragma pack(push, 1)
class RGE_Command_Stop {
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
    virtual void vfA0() = 0;  virtual void stop() = 0;

    void removeAllFromPathingGroup();
};

void RGE_Command::do_command_stop(RGE_Command_Stop* stop) {
    int count = stop->unit_num;
    int* id = stop->object_ids;
    if (count > 0) {
        int cnt = count;
        do {
            RGE_Static_Object* obj = this->get_obj(*id);
            if (obj != 0) {
                obj->removeAllFromPathingGroup();
                obj->stop();
            }
            id++;
            cnt--;
        } while (cnt != 0);
    }
}
