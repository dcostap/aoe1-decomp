class RGE_Master_Static_Object;
class RGE_Player;

class RGE_Static_Object {
public:
    virtual void recycle_in_to_game(RGE_Master_Static_Object* master, RGE_Player* player, float x, float y, float z);
    void set_sleep_flag(unsigned char value);
};

class RGE_Animated_Object : public RGE_Static_Object {
public:
    char gap_00[0x84];
    float speed;

    void recycle_in_to_game(RGE_Master_Static_Object* master, RGE_Player* player, float x, float y, float z);
};

void RGE_Animated_Object::recycle_in_to_game(RGE_Master_Static_Object* master, RGE_Player* player, float x, float y, float z) {
    RGE_Static_Object::recycle_in_to_game(master, player, x, y, z);
    this->speed = 0.0f;
    RGE_Static_Object::set_sleep_flag(0);
}
