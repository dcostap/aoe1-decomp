// BINARY NOTE: 0045D5F0 calls RGE_Moving_Object::set_angle. The former
// other_method declaration produced the wrong direct symbol.
#ifndef MOVE_OBJ_CANONICAL_TU
class RGE_Moving_Object {
public:
    void set_angle();
    void new_angle(float param_1);
    char pad[0x9C];
    float angle;
};
#endif
void RGE_Moving_Object::new_angle(float param_1) {
    *(int*)&this->angle = *(int*)&param_1;
    this->set_angle();
}
