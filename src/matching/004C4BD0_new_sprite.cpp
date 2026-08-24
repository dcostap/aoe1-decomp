class RGE_Sprite;
class RGE_Active_Sprite_List;
#ifndef RGE_STAT_OBJ_SHARED_CONTEXT
class RGE_Master_Static_Object {
public:
    char gap_00[0x18];
    RGE_Sprite* sprite;
    RGE_Sprite* death_sprite;
};

class RGE_Static_Object {
public:
    char gap_00[4];
    RGE_Master_Static_Object* master_obj;
    char gap_0C[4];
    RGE_Sprite* sprite;
    RGE_Sprite* old_sprite;
    RGE_Active_Sprite_List* sprite_list;
    char gap_1C[0x19];
    unsigned char facet;

    virtual void new_sprite(RGE_Sprite* sprite);
};

class RGE_Active_Sprite_List {
public:
    void remove_sprite(RGE_Sprite* sprite);
    void add_sprite(RGE_Sprite* sprite, int a3, int a4, int a5);
};
#endif

void RGE_Static_Object::new_sprite(RGE_Sprite* sprite) {
    if (sprite == 0) {
        sprite = this->master_obj->sprite;
    }
    if (this->sprite != sprite && (this->sprite != this->master_obj->death_sprite || this->master_obj->death_sprite == 0)) {
        this->old_sprite = this->sprite;
        this->sprite_list->remove_sprite(this->sprite);
        this->sprite = sprite;
        this->sprite_list->add_sprite(sprite, 0x3C, 0, 0);
        this->facet = 0;
    }
}
