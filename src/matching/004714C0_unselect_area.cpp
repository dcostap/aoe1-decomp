class RGE_Player_ua {
public:
    void unselect_area(void);
    char gap_00[0x120];
    short sel_x1;
    short sel_y1;
    short sel_x2;
    short sel_y2;
};

void RGE_Player_ua::unselect_area(void) {
    this->sel_x1 = -1;
    this->sel_y1 = -1;
    this->sel_x2 = -1;
    this->sel_y2 = -1;
}
