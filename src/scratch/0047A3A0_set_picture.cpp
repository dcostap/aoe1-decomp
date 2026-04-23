class TShape;
class TPanel {
public:
    char gap_00[0xF4];
};

class TPicturePanel : public TPanel {
public:
    char pic_name[0xC];
    long res_id;
    int size_from_pic;
    int keep_loaded;
    int own_pic;
    int pic_type;
    void* pic;
    TShape* shape;

    void free_pic(void);
    void vf20(int param_1);
    void set_picture(TShape* param_1, long param_2);
};

void TPicturePanel::set_picture(TShape* param_1, long param_2) {
    long res = param_2;
    TShape* shape = param_1;
    this->free_pic();
    this->res_id = res;
    this->shape = shape;
    this->own_pic = 0;
    this->vf20(1);
}
