extern const double g_zero_double;
#include "../../include/rge_zone_map_context.h"

RGE_Zone_Map* RGE_Zone_Map::check_info(float* input, long count) {
    int n = this->terrain_passability_rules_num;
    if (count == n) {
        int i = 0;
        if (n > 0) {
            do {
                if (input[i] <= g_zero_double) {
                    if (this->terrain_passability_rules[i] > g_zero_double) return 0;
                } else {
                    if (this->terrain_passability_rules[i] <= g_zero_double) return 0;
                }
                ++i;
            } while (i < n);
        }
        return this;
    }
    return 0;
}
