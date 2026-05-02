// VA: 0051EDD0 Time_Line_Panel::set_special_events (258 B, EXACT MATCH)
// PDB source: tpnl_tml.cpp lines 321-341
// Key insight: function-scope locals force the 16-byte sub area to be fully
// occupied, leaving the param_1 slot available for operator_new result reuse.
// Must use /GX flag for EH prologue (delete + new with throwing constructor).

void* __cdecl operator_new(unsigned int size);
void __cdecl operator_delete(void* ptr);

class TShape {
public:
    unsigned char* shape_data; // +0x00
    int load_type;             // +0x04
    int load_size;             // +0x08
    void* shape_header;        // +0x0C
    void* head;                // +0x10
    void* offsets;             // +0x14
    void* fshape;              // +0x18
    void* shape_info;          // +0x1C

    TShape() {}
    TShape(char* filename, int file_id);
    ~TShape();
    unsigned char shape_minmax(long* a1, long* a2, long* a3, long* a4, int a5);
};

class Time_Line_Panel {
public:
    char gap_00[0x4D4];
    TShape* special_events_pic; // +0x4D4
    short special_events_pic_wid; // +0x4D8
    short special_events_pic_hgt; // +0x4DA

    int set_special_events(char* param_1);
};

int Time_Line_Panel::set_special_events(char* param_1) {
    long x_min;
    long y_max;
    long y_min;
    long loc;
    if (this->special_events_pic) {
        delete this->special_events_pic;
        this->special_events_pic = 0;
        this->special_events_pic_wid = 0;
        this->special_events_pic_hgt = 0;
    }
    if (param_1 && *param_1) {
        this->special_events_pic = new TShape(param_1, -1);
        this->special_events_pic->shape_minmax(&y_max, &loc, &x_min, &y_min, 0);
        this->special_events_pic_wid = (short)(x_min - y_max + 1);
        this->special_events_pic_hgt = (short)(y_min - loc + 1);
        return 1;
    }
    return 0;
}
