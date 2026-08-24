#ifndef RGE_STAT_OBJ_SHARED_CONTEXT
class RGE_Sprite;

class RGE_Active_Sprite_List {
public:
    unsigned char get_frame(short* param_1, short* param_2, short* param_3,
                            short* param_4, RGE_Sprite* param_5, long param_6);
};

class RGE_Static_Object {
public:
    char gap_00[0x10];
    RGE_Sprite* sprite;
    char gap_14[0x4];
    RGE_Active_Sprite_List* sprite_list;
    char gap_1C[0x19];
    unsigned char facet;

    int get_frame(short* param_1, short* param_2, short* param_3, short* param_4);
};
#endif

int RGE_Static_Object::get_frame(short* param_1, short* param_2, short* param_3, short* param_4) {
    if (this->sprite != 0 && this->sprite_list != 0) {
        return this->sprite_list->get_frame(param_1, param_2, param_3, param_4, this->sprite, (unsigned char)this->facet);
    }
    return 0;
}
