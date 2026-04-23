class RGE_Sprite_Master {
public:
    char gap_00[0x18];
    void* default_sprite;
};

class RGE_Moving_Object_Type {
public:
    char gap_00[0x18];
    void* default_sprite;
};

class RGE_Static_Object {
public:
    virtual void new_sprite(void* sprite);
};

class RGE_Moving_Object : public RGE_Static_Object {
public:
    char gap_04[4];
    RGE_Moving_Object_Type* type;
    int gap_0C;
    void* current_sprite;
    void* previous_sprite;

    virtual void new_sprite(void* sprite);
    void set_angle(void);
};

void RGE_Moving_Object::new_sprite(void* sprite) {
    if (sprite == 0) {
        sprite = this->type->default_sprite;
    }
    if (this->current_sprite != sprite) {
        this->previous_sprite = this->current_sprite;
        RGE_Static_Object::new_sprite(sprite);
        this->set_angle();
    }
}
