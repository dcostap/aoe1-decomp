#include "../../include/victory_context.h"

void RGE_Victory_Conditions::update_for_object(RGE_Static_Object* object) {
    RGE_Victory_Entry* entry = this->victory_list;

    while (entry != 0) {
        RGE_Victory_Entry* next = entry->next;
        if ((entry->this_obj == object) || (entry->target_obj == object)) {
            this->sub(entry);
        }
        entry = next;
    }
}
