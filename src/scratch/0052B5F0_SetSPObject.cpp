class RGE_Static_Object;

class T_Scenario {
public:
    char gap_00[0x1AD4];
    int sp_victory_obj_id[1024];
    char gap_2AD4[0x211C];
    int which_player;

    int get_object_ID(RGE_Static_Object* object);
    void SetSPObject(int index, RGE_Static_Object* object);
};

void T_Scenario::SetSPObject(int index, RGE_Static_Object* object) {
    if (object != 0) {
        int object_id = this->get_object_ID(object);
        int result = object_id;
        int which_player = this->which_player;
        int offset;

        result++;
        offset = index + (which_player + which_player * 2) * 4;
        offset = offset + offset * 2;
        offset = offset + offset * 4;
        this->sp_victory_obj_id[offset] = result;
    }
}
