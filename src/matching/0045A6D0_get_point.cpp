// VA: 0045A6D0 RGE_Map::get_point(short*, short*, float, float, float, int, int)
// PDB source: map.cpp lines 3129-3132
// Match: 103/103 bytes, 0.0000%
//
// Two short outputs from float coords with tile-half offsets.
// tile_half_width at +0x8D9C, tile_half_height at +0x8D9A.
// Constant 0.5f used as half-tile offset.

class RGE_Map {
public:
    char pad_00[0x8D9A];
    short tile_half_height;  // +0x8D9A
    short tile_half_width;   // +0x8D9C

    void get_point(short* out_x, short* out_y,
                   float param_3, float param_4, float param_5,
                   int param_6, int param_7);
};

void RGE_Map::get_point(short* out_x, short* out_y,
                         float param_3, float param_4, float param_5,
                         int param_6, int param_7) {
    *out_x = (short)((int)((param_4 + param_3) * this->tile_half_width) + param_6);
    *out_y = (short)((int)((param_4 - 0.5f - param_3 - param_5) * this->tile_half_height) + param_7 - 0x10);
}
