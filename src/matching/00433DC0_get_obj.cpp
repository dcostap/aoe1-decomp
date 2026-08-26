#ifndef COMMAND_TU_CONTEXT
class RGE_Static_Object;
struct RGE_Obj_Info {
    int id;
};
class RGE_Game_World {
public:
    RGE_Static_Object* object(int id);
};

class RGE_Command {
public:
    char gap_00[0x4];
    RGE_Game_World* world;

protected:
    RGE_Static_Object* get_obj(RGE_Obj_Info info);
};
#endif

// BINARY NOTE: RGE_Obj_Info is one dword and owns this original ABI.
RGE_Static_Object* RGE_Command::get_obj(RGE_Obj_Info info) {
    if (info.id == -1) {
        return 0;
    }
    return this->world->object(info.id);
}
