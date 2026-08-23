// 00539C80 RGE_View::get_border_edge_pictures
// PDB: view.cpp:5677-5703, ?get_border_edge_pictures@RGE_View@@IAEHEEEFFAAH000@Z.
// Body: 00539C80-00539D83. Padding: 00539D84-00539D8F. Next: 00539D90.
// 260 bytes, __thiscall, protected member with four int& outputs.
// BINARY NOTE: Output stores occur before the map shape read.
// BINARY NOTE: The four calls keep the protected get_border_picture ABI.
// int get_border_edge_pictures(uchar terrain_type, uchar row_idx, uchar edge_mask, short param_4, short param_5, int& out1, int& out2, int& out3, int& out4)

struct RGE_TOB_Picts { short count; short animations; short shape_index; };
struct RGE_Border_Type { unsigned char gap_00[0x20]; void* shape; unsigned char gap_24[0x42 - 0x24]; RGE_TOB_Picts borders[19][12]; unsigned char gap_59A[4]; short border_style; };
struct RGE_Map { unsigned char gap_00[0x8C]; unsigned char terrain_types[32][0x198]; RGE_Border_Type border_types[32]; };
class TPanel { public: unsigned char gap_00[0xF4]; };
class RGE_View : public TPanel { public: unsigned char gap_F4[0x10]; RGE_Map* map; protected: short get_border_picture(unsigned char, unsigned char, unsigned char, short, short); int get_border_edge_pictures(unsigned char param_1, unsigned char param_2, unsigned char param_3, short param_4, short param_5, int& param_6, int& param_7, int& param_8, int& param_9); };

int RGE_View::get_border_edge_pictures(unsigned char param_1, unsigned char param_2, unsigned char param_3, short param_4, short param_5, int& param_6, int& param_7, int& param_8, int& param_9) {
    param_6 = -1;
    param_8 = -1;
    param_7 = -1;
    param_9 = -1;

    if (this->map->border_types[param_1].shape && param_3) {
        if (param_3 & 1) {
            short s = this->get_border_picture(param_1, param_2, 1, param_4, param_5);
            param_6 = (int)s;
        }
        if (param_3 & 2) {
            short s = this->get_border_picture(param_1, param_2, 4, param_4, param_5);
            param_9 = (int)s;
        }
        if (param_3 & 4) {
            short s = this->get_border_picture(param_1, param_2, 3, param_4, param_5);
            param_8 = (int)s;
        }
        if (param_3 & 8) {
            short s = this->get_border_picture(param_1, param_2, 2, param_4, param_5);
            param_7 = (int)s;
        }
        return 1;
    }
    return 0;
}
