struct InnerObj_shadow {
    int check_for_shadows();
};

class RGE_Sprite {
public:
    char gap_0[4];
    InnerObj_shadow *ptr;
    int check_for_shadows();
};

int RGE_Sprite::check_for_shadows() {
    if (this->ptr)
        return this->ptr->check_for_shadows();
    return 0;
}
