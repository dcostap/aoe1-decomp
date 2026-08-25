#ifndef DIAM_MAP_CONTEXT_H
class TPanel {
public:
    long handle_size(long width, long height);
};

class RGE_Diamond_Map {
public:
    char gap_00[0x14C];
    short view_col;
    short view_row;

    long handle_size(long width, long height);
    int create_surfaces(void);
};
#endif

long RGE_Diamond_Map::handle_size(long width, long height) {
#ifdef DIAM_MAP_CONTEXT_H
    this->TPanel::handle_size(width, height);
#else
    ((TPanel*)this)->handle_size(width, height);
#endif
    this->view_col = -1;
    this->view_row = -1;
    this->create_surfaces();
    return 0;
}
