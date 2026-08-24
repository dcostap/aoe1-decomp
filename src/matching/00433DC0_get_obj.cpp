#ifndef COMMAND_TU_CONTEXT
class RGE_Static_Object;
class RGE_Game_World {
public:
    RGE_Static_Object* object(int id);
};

class RGE_Command {
public:
    char gap_00[0x4];
    RGE_Game_World* world;

    RGE_Static_Object* get_obj(int id);
};
#endif

RGE_Static_Object* RGE_Command::get_obj(int id) {
    if (id == -1) {
        return 0;
    }
    return this->world->object(id);
}
