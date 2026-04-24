// TEasy_Panel::position_panel at 00469DB0 (Panel_ez.cpp)
// Inventory: 00469DB0_position_panel
// Attempt log:
//   v1: direct translation of Ghidra snippet; compiling now.

class TShape;

class TEasy_Panel {
public:
    char pad_before[0xF4];         // filler up to ideal_width
    int  ideal_width;              // +0xF4
    int  ideal_height;             // +0xF8
    char info_file_name[260];      // +0xFC
    int  info_id;                  // +0x200
    TShape* background_pic;        // +0x204
    TShape* background_pic2;       // +0x208
    void* palette;                 // +0x20C (unused)
    char cursor_file[260];         // +0x210
    int  cursor_id;                // +0x314
    int  background_pos;           // +0x318
    // method declaration
    void position_panel(long param);
};

class TShape {
public:
    void Place(int x1, int y1, int w, int h, int p5, int p6, int p7, int p8, int p9);
    void Place(int x1, int y1, int w, int h, int p5, int p6, int p7);
};

void TEasy_Panel::position_panel(long param) {
    // First block
    TShape* bg = this->background_pic;
    if (bg != 0) {
        TShape* bg2 = this->background_pic2;
        if (bg2 != 0) {
            int tmp = (this->ideal_width * this->ideal_height) / 2;
            bg->Place(0, 0, this->ideal_width, this->ideal_height, tmp, 0, 0xFFFF, 0, 0);
            bg2->Place(0, 0, this->ideal_width, this->ideal_height, tmp, 0, 0xFFFF, 0, 0);
        }
    }

    // Second block
    TShape* bg3 = this->background_pic;
    if (bg3 != 0) {
        int pos = this->background_pos;
        int w = this->ideal_width - (pos * 2);
        int h = this->ideal_height - (pos * 2);
        int tmp = (this->ideal_width * this->ideal_height) / 2;
        bg3->Place(pos, pos, w, h, tmp, 0, 0);
    }
}
