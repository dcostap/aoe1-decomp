class RGE_Master_Static_Object {
public:
    char gap_0[0x4A4];
    short list_id;
    short get_list_id();
};

short RGE_Master_Static_Object::get_list_id() {
    return this->list_id;
}
