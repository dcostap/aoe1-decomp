class MemberType {
public:
    void target_method(int param);
};

class RGE_Master_Combat_Object {
public:
    char gap_0[0xF0];
    MemberType* member_F0;

    void play_command_sound();
};

void RGE_Master_Combat_Object::play_command_sound() {
    if (this->member_F0) {
        this->member_F0->target_method(1);
    }
}
