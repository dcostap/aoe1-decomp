class RGE_Sprite;

struct SpriteWorld {
    char gap_00[0x34];
    short sprite_num;
    char gap_36[0x02];
    RGE_Sprite** sprites;
};

struct OwnerInfo {
    char gap_00[0x3C];
    SpriteWorld* world;
};

class RGE_Static_Object {
public:
    char gap_00[0x0C];
    OwnerInfo* owner;

    RGE_Sprite* get_sprite_pointer(short index);
};

RGE_Sprite* RGE_Static_Object::get_sprite_pointer(short index) {
    SpriteWorld* world;

    if (index >= 0) {
        world = this->owner->world;
        if (index < world->sprite_num) {
            return world->sprites[index];
        }
    }
    return 0;
}
