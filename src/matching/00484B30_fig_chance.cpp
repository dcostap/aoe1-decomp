class RGE_RMM_Elevation_Generator {
public:
    float fig_chance(long p0, long p1, long p2);
};

float RGE_RMM_Elevation_Generator::fig_chance(long p0, long p1, long p2) {
    return (float)(0xFA - p0 * 15);
}
