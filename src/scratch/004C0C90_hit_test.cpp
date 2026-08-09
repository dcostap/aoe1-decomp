// VA: 004C0C90 RGE_Sprite::hit_test(short, short, long, long)
// sprite.cpp
//
// Attempt log:
// - Established the RGE_Sprite box/draw-list/facet ownership and the
//   binary-observed 16-byte picture-list stride.
// - A nested box-presence guard plus an explicit while scan reproduces the
//   original size, frame, ordered calls, and branch topology.
// - The remaining mismatch is VC5 register/liveness coloring in the scan;
//   raw cross-member cursor experiments improved bytes only marginally and
//   were restored to this typed entry form.

class RGE_Sprite;

class RGE_Picture_List {
public:
    short picture_num;
    unsigned char gap_02[2];
    RGE_Sprite* sprite;
    short offset_x;
    short offset_y;
    short facet;
    unsigned char gap_0E[2];
};

class RGE_Sprite {
public:
    unsigned char gap_00[0x2E];
    short box_x1;
    short box_y1;
    short box_x2;
    short box_y2;
    short draw_list_num;
    RGE_Picture_List* draw_list;
    unsigned char gap_3C[0x24];
    short facet_num;

    unsigned char shape_hit_test(short x, short y, long facet, long value);
    unsigned char hit_test(short x, short y, long facet, long value);
};

unsigned char RGE_Sprite::hit_test(short x, short y, long facet, long value) {
    int index = 0;

    if (((this->box_x1 != 0) || (this->box_x2 != 0)) &&
        ((this->box_y1 != 0) || (this->box_y2 != 0))) {
        if ((x >= this->box_x1) && (x <= this->box_x2) &&
            (y >= this->box_y1) && (y <= this->box_y2)) {
            return 1;
        }
    }

    if ((this->draw_list_num > 0) && (this->draw_list != 0)) {
        int i = 0;
        if (this->draw_list_num > 0) {
            while (i < this->draw_list_num) {
                RGE_Picture_List* list =
                    (RGE_Picture_List*)((char*)this->draw_list + index);
                RGE_Sprite* sprite = list->sprite;
                if (sprite->shape_hit_test(
                        x - list->offset_x,
                        y - list->offset_y,
                        (sprite->facet_num * facet) / (int)this->facet_num,
                        value)) {
                    return 1;
                }
                index += 0x10;
                i++;
            }
        }
        return 0;
    }

    return this->shape_hit_test(x, y, facet, value);
}
