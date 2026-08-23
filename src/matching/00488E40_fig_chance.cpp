#include "../../include/rmm_terr_context.h"

float RGE_RMM_Terrain_Generator::fig_chance(long p0, long p1, long p2, long p3) {
    return (float)(0xFA - p3 * p0);
}
