#ifndef RGE_STAT_OBJ_SHARED_CONTEXT
class RGE_Sprite;

class RGE_Active_Sprite_List {
public:
    void remove_sprite(RGE_Sprite* param);
};

class RGE_Static_Object {
public:
    char gap_0[0x14];
    RGE_Active_Sprite_List *sprite_list;
    virtual void remove_overlay_sprite(RGE_Sprite* param);
};
#endif

// BINARY NOTE: this virtual member takes an RGE_Sprite pointer.
void RGE_Static_Object::remove_overlay_sprite(RGE_Sprite* param) {
    this->sprite_list->remove_sprite(param);
}
