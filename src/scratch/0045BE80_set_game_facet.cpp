// 0045BE80 TMousePointer::set_game_facet
// Raw-offset implementation from packet.
// HollowSnowdrop pass: fixed local layout offsets (prior source was 8 bytes low). Current exact size 91/91 and body after facet-address calculation mostly matches; remaining drift is register/order near prologue: rebuilt uses EAX for the facet and saves ESI before storing game_facet, while original keeps facet in EDX, loads Cursor_Shape into EAX, stores game_facet, shifts EDX, then pushes ESI. Tried local facet copy; same EAX basin.

class Shape_Info {
public:
    char pad_00[0x10];
    int width;      // +0x10
    int height;     // +0x14
    int hotspot_x;  // +0x18
    int hotspot_y;  // +0x1C
};

class TShape {
public:
    char pad_00[0x1C];
    Shape_Info* shape_info;
};

class TMousePointer {
public:
    char gap_00[0x10];
    int Num_Cursors;
    char gap_14[0x58 - 0x14];
    TShape* Cursor_Shape;
    char gap_5C[0x70 - 0x5C];
    int gWidth;
    int gHeight;
    char gap_78[0x8C - 0x78];
    int game_facet;
    char gap_90[0xA8 - 0x90];
    int g_top;
    int g_left;
    int g_bottom;
    int g_right;

    void set_game_facet(int facet);
};

void TMousePointer::set_game_facet(int facet) {
    int f;
    f = facet;
    if (f >= 0 && f < this->Num_Cursors) {
        Shape_Info* info;
        this->game_facet = f;
        info = this->Cursor_Shape->shape_info + f;
        this->gWidth = info->width;
        this->gHeight = info->height;
        this->g_top = info->hotspot_y;
        this->g_left = info->hotspot_x;
        this->g_right = this->gWidth - info->hotspot_x;
        this->g_bottom = this->gHeight - info->hotspot_y;
    }
}
