// RGE_Base_Game::handle_mouse_move
// VA: 00421110
// basegame.cpp

struct tagPOINT { long x; long y; };

class TMousePointer {
public:
    int in_game_mode();
    void Poll();
    void draw(int flag);
};

#define VPAD1(n) virtual void vpad##n();
#define VPAD2(n) VPAD1(n) VPAD1(n##_1)
#define VPAD4(n) VPAD2(n) VPAD2(n##_2)
#define VPAD8(n) VPAD4(n) VPAD4(n##_4)
#define VPAD16(n) VPAD8(n) VPAD8(n##_8)
#define VPAD32(n) VPAD16(n) VPAD16(n##_16)

class RGE_Base_Game {
public:
    VPAD32(0) VPAD8(32) VPAD4(40) VPAD2(44) VPAD1(46)
    virtual void handle_mouse_click(); // slot47 +0xBC
    VPAD8(48) VPAD4(56) VPAD2(60) VPAD1(62)
    virtual int v_mouse_move(int y, int local4, int x, int left, int right, int ctrl); // slot63 +0xFC

    char gap_04[0x10];
    int prog_ready;      // +0x14
    char gap_18[0x3C];
    int custom_mouse;    // +0x54
    char gap_58[0x168];
    TMousePointer* mouse_pointer; // +0x1C0
    char gap_1C4[0x0C];
    int windows_mouse;   // +0x1D0

    void get_mouse_info(unsigned int p3, long p4, long* py, long* px, int* left, int* right, int* ctrl);
    virtual int handle_mouse_move(void* p1, unsigned int p2, unsigned int p3, long p4);
};

int RGE_Base_Game::handle_mouse_move(void* p1, unsigned int p2, unsigned int p3, long p4)
{
    struct Frame {
        int ctrl_key;
        int right_btn;
        int left_btn;
        tagPOINT point;
        int shift_key;
    } f;
    if (this->prog_ready == 0) {
        return 1;
    }

    if (this->custom_mouse != 0 && this->windows_mouse == 0) {
        if (this->mouse_pointer->in_game_mode()) {
            this->mouse_pointer->Poll();
        } else {
            this->mouse_pointer->draw(0);
        }
    }

    this->get_mouse_info(p3, p4, &f.point.y, &f.point.x, &f.left_btn, &f.right_btn, &f.ctrl_key);
    this->v_mouse_move(f.point.y, f.shift_key, f.point.x, f.left_btn, f.right_btn, f.ctrl_key);
    this->handle_mouse_click();
    return 1;
}
