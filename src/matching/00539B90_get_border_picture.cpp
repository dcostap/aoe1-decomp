// 00539B90 RGE_View::get_border_picture
// view.cpp:5617-5671, 239 bytes, __thiscall
// short get_border_picture(uchar terrain_type, uchar row_idx, uchar col_idx, short param_4, short param_5)

struct RGE_TOB_Picts { short count; short animations; short shape_index; };
struct RGE_Border_Type { unsigned char gap_00[0x20]; void* shape; unsigned char gap_24[0x42 - 0x24]; RGE_TOB_Picts borders[19][12]; unsigned char gap_59A[4]; short border_style; };
struct RGE_Map { unsigned char gap_00[0x8C]; unsigned char terrain_types[32][0x198]; RGE_Border_Type border_types[32]; };
class TPanel { public: unsigned char gap_00[0xF4]; };
class RGE_View : public TPanel { public: unsigned char gap_F4[0x10]; RGE_Map* map; short get_border_picture(unsigned char param_1, unsigned char param_2, unsigned char param_3, short param_4, short param_5); };

short RGE_View::get_border_picture(unsigned char param_1, unsigned char param_2, unsigned char param_3, short param_4, short param_5) {
    RGE_Border_Type* bt = &this->map->border_types[param_1];
    if (bt->shape == 0) return -1;

    RGE_TOB_Picts* tile = &bt->borders[param_2 - 1][param_3 + 0xB];
    if (tile->count == 0) return -1;

    short result = 0;
    if (tile->count > 1) {
        short style = bt->border_style;
        if ((style == 0 && (param_3 == 0xB || param_3 == 0xC)) ||
            (style == 1 && (param_3 == 0x3 || param_3 == 0x2))) {
            result = param_5 % tile->count;
        } else if ((style == 0 && (param_3 == 0x9 || param_3 == 0xA)) ||
                   (style == 1 && (param_3 == 0x1 || param_3 == 0x4))) {
            result = param_4 % tile->count;
        } else {
            result = 0;
        }
    }

    if (result > tile->count - 1) result = 0;
    return (short)(tile->animations * result + tile->shape_index);
}
