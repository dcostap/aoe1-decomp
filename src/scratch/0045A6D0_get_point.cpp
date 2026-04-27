// attempt 1: preserve the x87/__ftol basin for the map-point helper using the real tile-half offsets
// later tries: switched the output args to int and tried direct vs temp-shaped stores; the remaining mismatch stayed in the first output-store basin
// target shape: two short outputs from (param4+param3)*tile_half_width and (param4-DAT_005706ec-param3-param5)*tile_half_height, plus the short offsets
// paused here because the math is understood but VC5 still prefers a different first-store/load ordering than the packet


class RGE_Map {
public:
    char pad_00[0x8D9A];
    short tile_half_height;
    short tile_half_width;

    void get_point(short* out_x, short* out_y, float param_3, float param_4, float param_5, int param_6, int param_7);
};

void RGE_Map::get_point(short* out_x, short* out_y, float param_3, float param_4, float param_5, int param_6, int param_7) {
    int x;

    x = (int)((param_4 + param_3) * this->tile_half_width);
    *out_x = (short)(x + param_6);

    x = (int)((param_4 - *(float*)0x5706EC - param_3 - param_5) * this->tile_half_height);
    *out_y = (short)(x + param_7 - 0x10);
}
