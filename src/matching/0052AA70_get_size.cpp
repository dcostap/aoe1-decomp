#include "../../include/tscenaro_context.h"

long TRIBE_Scenario_Header::get_size() {
    return RGE_Scenario_Header::get_size() + 8;
}
