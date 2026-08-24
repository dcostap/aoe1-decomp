// VA: 00434320 RGE_Command::do_command_work (216B)
// Command.cpp lines 466-494.
//
// Initial reconstruction: the order packet owns a target id followed by a
// variable-length unit-id array.  Each resolved unit is removed from its old
// pathing group, marked waiting, rebuilt into the same group except for itself,
// and sent the work command.
//
// Attempt log:
// - The inherited stub was only a placeholder and omitted the command loop.
// - Restored the canonical packet layout, target/unit lookups, pathing calls,
//   and work virtual surface; this reached the correct frame, size, and call set.
// - Replaced the nested for loop with the binary-supported do/while topology;
//   this removed the extra inner pretest and aligned the loop body.
// - Declared count/base before the target lookup.  This preserves VC5's original
//   load/save order and produces an exact 216-byte match under default.rsp.

#ifndef COMMAND_TU_CONTEXT
struct RGE_Obj_Info {
    int id;
};

class RGE_Command_Order {
public:
    unsigned char command;
    unsigned char gap_01[3];
    RGE_Obj_Info target;
    unsigned char unit_num;
    unsigned char gap_09[3];
    float location_x;
    float location_y;
    RGE_Obj_Info units[1];
};

class RGE_Static_Object {
public:
    virtual void vf00(); virtual void vf04(); virtual void vf08(); virtual void vf0C();
    virtual void vf10(); virtual void vf14(); virtual void vf18(); virtual void vf1C();
    virtual void vf20(); virtual void vf24(); virtual void vf28(); virtual void vf2C();
    virtual void vf30(); virtual void vf34(); virtual void vf38(); virtual void vf3C();
    virtual void vf40(); virtual void vf44(); virtual void vf48(); virtual void vf4C();
    virtual void vf50(); virtual void vf54(); virtual void vf58(); virtual void vf5C();
    virtual void vf60(); virtual void vf64(); virtual void vf68(); virtual void vf6C();
    virtual void vf70(); virtual void vf74(); virtual void vf78(); virtual void vf7C();
    virtual void vf80(); virtual void vf84(); virtual void vf88(); virtual void vf8C();
    virtual void vf90(); virtual void vf94(); virtual void vf98(); virtual void vf9C();
    virtual void work(RGE_Static_Object* target, float x, float y, float z);
    virtual void vfA4(); virtual void vfA8(); virtual void vfAC();
    virtual void vfB0(); virtual void vfB4(); virtual void vfB8(); virtual void vfBC();
    virtual void vfC0(); virtual void vfC4(); virtual void vfC8(); virtual void vfCC();
    virtual void vfD0(); virtual void vfD4(); virtual void vfD8(); virtual void vfDC();
    virtual void vfE0(); virtual void vfE4(); virtual void vfE8(); virtual void vfEC();
    virtual void vfF0(); virtual void vfF4(); virtual void vfF8(); virtual void vfFC();
    virtual void vf100(); virtual void vf104(); virtual void vf108(); virtual void vf10C();
    virtual void vf110(); virtual void vf114(); virtual void vf118(); virtual void vf11C();
    virtual void vf120(); virtual void vf124(); virtual void vf128();
    virtual void setWaitingToMove(unsigned char waiting);

    void removeAllFromPathingGroup();
    void addToPathingGroup(int group_index);
};

class RGE_Command {
public:
    virtual ~RGE_Command();
    char gap_04[4];
    void* world;
    RGE_Static_Object* get_obj(RGE_Obj_Info info);
    void do_command_work(RGE_Command_Order* order);
};
#endif

void RGE_Command::do_command_work(RGE_Command_Order* order)
{
    int unit_num = order->unit_num;
    RGE_Obj_Info* units = order->units;
    RGE_Static_Object* target = this->get_obj(order->target);
    int index = 0;

    if (unit_num > 0) {
        RGE_Obj_Info* unit = units;
        do {
            RGE_Static_Object* obj = this->get_obj(*unit);
            if (obj != 0) {
                obj->removeAllFromPathingGroup();
                obj->setWaitingToMove(1);
                int i = 0;
                do {
                    if (i != index)
                        obj->addToPathingGroup(units[i].id);
                    ++i;
                } while (i < unit_num);
                obj->work(target, order->location_x, order->location_y, 0);
            }
            ++index;
            ++unit;
        } while (index < unit_num);
    }
}
