#ifndef DIAM_MAP_CONTEXT_H
class TPanel {
public:
    void release_mouse();
};

class RGE_Diamond_Map : public TPanel {
public:
    char gap_0[0x154];
    int scrolling;
    void end_scroll_view();
};
#endif

void RGE_Diamond_Map::end_scroll_view() {
    this->scrolling = 0;
    this->release_mouse();
}
