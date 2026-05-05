// attempt 6: minimal base layout with exact offsets, no stray class surfaces
class TPanel {
public:
    void* vtable_ptr;
    char gap_04[0x7C];
    int handle_mouse_input;
    char gap_84[0xEE - 0x84];
    unsigned char panel_type;
    char gap_EF[0xF4 - 0xEF];
    TPanel();
};
class TPicturePanel : public TPanel {
public:
    char pic_name[12];
    long res_id;
    int size_from_pic;
    int keep_loaded;
    int own_pic;
    int pic_type;
    void* pic;
    void* shape;
    TPicturePanel();
};
TPicturePanel::TPicturePanel() : TPanel() {
    this->keep_loaded = 1;
    this->size_from_pic = 0;
    this->own_pic = 0;
    this->pic_type = 0;
    this->pic = 0;
    this->shape = 0;
    this->handle_mouse_input = 0;
    this->pic_name[0] = 0;
    this->vtable_ptr = (void*)0x571750;
    this->panel_type = 2;
    this->res_id = -1;
}
