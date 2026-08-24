#ifndef MAP_CONTEXT_H
class RGE_Map {
public:
    virtual ~RGE_Map();
    int field_4;
    int map_width;
    int map_height;

    void set_map_screen_pos(int left, int top, int right, int bottom);
    void coordinate_map();
};

#endif

void RGE_Map::coordinate_map() {
    this->set_map_screen_pos(0, 0, this->map_width - 1, this->map_height - 1);
}
