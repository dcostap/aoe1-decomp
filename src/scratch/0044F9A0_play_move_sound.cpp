class MemberType {
public:
    void target_method(int param);
};

class RGE_Master_Combat_Object {
public:
    char gap_0[0xF4];
    MemberType* member_F4;

    void play_move_sound();
};

void RGE_Master_Combat_Object::play_move_sound() {
    if (this->member_F4) {
        this->member_F4->target_method(1);
    }
}
