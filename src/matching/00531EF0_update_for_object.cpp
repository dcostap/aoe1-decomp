class RGE_Static_Object;

struct RGE_Victory_Entry {
    char gap_00[0x24];
    RGE_Static_Object* this_obj;
    RGE_Static_Object* target_obj;
    char gap_2C[0x04];
    RGE_Victory_Entry* next;
};

class RGE_Victory_Conditions {
public:
    char gap_00[0x04];
    RGE_Victory_Entry* victory_list;

    void sub(RGE_Victory_Entry* entry);
    void update_for_object(RGE_Static_Object* object);
};

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
