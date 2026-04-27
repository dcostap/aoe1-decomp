// TPicturePanel::TPicturePanel (0047A1D0, 89 bytes, Pnl_pic.cpp)
// Attempt 5 - minimal TPanel stub

class TDrawArea {};
class TPicture {};
class TShape {};

class TPanel {
public:
    void* vtable_ptr;       // 0x00
    char gap_04[0x7c];     // 0x04 - 0x7f
    int handle_mouse_input;// 0x80
    char gap_84[0x6e];     // 0x84 - 0xef
    unsigned char panel_type;// 0xee

    TPanel();
};

class TPicturePanel : public TPanel {
public:
    char pic_name[12];   // 0xf4
    long res_id;         // 0x100
    int size_from_pic;   // 0x104
    int keep_loaded;     // 0x108
    int own_pic;         // 0x10c
    int pic_type;        // 0x110
    TPicture* pic;       // 0x114
    TShape* shape;       // 0x118

    TPicturePanel();
};

TPicturePanel::TPicturePanel() {
    TPanel::TPanel();
    this->keep_loaded = 1;
    this->size_from_pic = 0;
    this->own_pic = 0;
    this->pic_type = 0;
    this->pic = (TPicture*)0;
    this->shape = (TShape*)0;
    this->handle_mouse_input = 0;
    this->pic_name[0] = 0;
    this->vtable_ptr = (void*)0x571750;
    this->panel_type = 2;
    this->res_id = -1;
}
