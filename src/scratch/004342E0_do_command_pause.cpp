// first pass: packed command-pause payload, unit count byte at +1, ids starting at +2
// tried a straightforward packed-struct loop; the mismatch stayed at the entry register/setup shape
// tried biasing the source toward the original this-in-edi / pause-in-ecx arrangement; VC5 still loaded the pause pointer through eax and counted in bl

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
    virtual ~RGE_Static_Object();
    char gap_04[0x190 - 4];
    void (*pause_callback)();
};

void RGE_Command::do_command_pause(RGE_Command_Pause* pause) {
    RGE_Command* command = this;
    unsigned char count = pause->unit_num;
    int* id = (int*)((char*)pause + 2);

    if (count > 0) {
        do {
            RGE_Static_Object* obj = command->get_obj(*id);
            if (obj != 0) {
                obj->pause_callback();
            }
            ++id;
        } while (--count != 0);
    }
}
