class RGE_Moving_Object {
public:
    void other_method();
    void new_angle(float param_1);
    char pad[0x9C];
    float field_9C;
};
void RGE_Moving_Object::new_angle(float param_1) {
    *(int*)&this->field_9C = *(int*)&param_1;
    this->other_method();
}
