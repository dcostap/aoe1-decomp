class RGE_Moving_Object {
public:
    char gap_00[0x88];
    float move_speed;

    unsigned char is_moving();
};

unsigned char RGE_Moving_Object::is_moving() {
    if (this->move_speed > 0.0f) {
        return 1;
    }
    return 0;
}
