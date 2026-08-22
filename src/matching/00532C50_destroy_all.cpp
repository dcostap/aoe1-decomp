#include "../../include/victory_description_context.h"

void RGE_Victory_Conditions::destroy_all() {
    RGE_Victory_Entry* entry;

    entry = this->victory_list;
    while (entry != 0) {
        sub(entry);
        entry = this->victory_list;
    }
}
