#ifndef TECH_GROUP_CONTEXT
struct InnerObj { long get_help_page(short param_1); };
class TRIBE_Player_Tech {
public:
    long get_help_page(short param_1);
    char pad[0x08]; InnerObj* field_08;
};
#endif

long TRIBE_Player_Tech::get_help_page(short param_1) {
    return this->field_08->get_help_page(param_1);
}
