class RGE_Sprite;

class RGE_Active_Sprite_List {
public:
    void add_sprite(RGE_Sprite* sprite, unsigned char mode, int a4, int a5);
};

class RGE_Static_Object {
public:
    char gap_04[0x14];
    RGE_Active_Sprite_List* sprite_list;

    virtual void add_overlay_sprite(RGE_Sprite* sprite, unsigned char mode);
};

void RGE_Static_Object::add_overlay_sprite(RGE_Sprite* sprite, unsigned char mode) {
    sprite_list->add_sprite(sprite, mode, 0, 0);
}
