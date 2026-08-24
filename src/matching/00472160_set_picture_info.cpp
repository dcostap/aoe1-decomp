class TShape;

#ifndef PNL_BTN_SHARED_CONTEXT
class TButtonPanel {
public:
    char gap_00[0x184];
    long auto_pic_pos;
    long pic_x;
    long pic_y;
    int all_hot;

    void set_picture(short state, TShape* shape, short index);
    void set_picture_info(TShape* shape, short index, long x, long y, int all_hot, int auto_pic_pos);
};
#endif /* PNL_BTN_SHARED_CONTEXT */

void TButtonPanel::set_picture_info(TShape* shape, short index, long x, long y, int all_hot_value, int auto_pic_pos_value) {
    pic_x = x;
    pic_y = y;
    all_hot = all_hot_value;
    auto_pic_pos = auto_pic_pos_value;
    set_picture(0, shape, index);
}
