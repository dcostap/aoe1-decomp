// quick-win attempt: only flip param_3 when draw_objects_mode == 4, then forward to the base draw_object
// tried a flat layout and a couple of param_3 shape probes; remaining mismatch is still the flash_on / branch basin at the early compare
class RGE_Static_Object;
class RGE_Diamond_Map {
public:
    void draw_object(short param_1, short param_2, unsigned char param_3, short param_4, RGE_Static_Object* param_5);
};

class TRIBE_Diamond_Map_View {
public:
    char gap_00[0x15C];
    int draw_objects_mode;
    unsigned long cur_player_bit;
    int own_save_area;
    void* save_area;
    unsigned long last_attack_time;
    int flash_on;

    void draw_object(short param_1, short param_2, unsigned char param_3, short param_4, RGE_Static_Object* param_5);
};

void TRIBE_Diamond_Map_View::draw_object(short param_1, short param_2, unsigned char param_3, short param_4, RGE_Static_Object* param_5) {
    if (this->draw_objects_mode == 4) {
        int mask = -(this->flash_on != 0);
        param_3 = (unsigned char)((mask & 0x57) - 1);
    }
    ((RGE_Diamond_Map*)this)->draw_object(param_1, param_2, param_3, param_4, param_5);
}
