class RGE_Active_Sprite_List {
public:
    char gap_0[4];
    int field_4;

    void base_init();
    void use_sprite_list(int param);
};

void RGE_Active_Sprite_List::use_sprite_list(int param) {
    this->base_init();
    this->field_4 = param;
}
