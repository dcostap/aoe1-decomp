// first pass was too generic; VC5 drifted immediately in the prolog because the signature/stub shape was off
// tried a byte counter and a pointer temp; VC5 saved ebx up front instead of using the original eax/bl basin
// tried int counter + unsigned char* walk; still missed at entry because VC5 kept choosing the wrong save/register basin
// current gap: prolog/register shape at the first counter load, not the loop body or call sequence
// next try: exact TRIBE_Command method signature with the packed 4-byte object-id walk kept as close to the asm as possible
class RGE_Static_Object {
public:
    short attribute_type_held;
};

class RGE_Command {
public:
    char gap_00[4];
    void* world;
    RGE_Static_Object* get_obj(int id);
};

class TRIBE_Command_Trade_Attribute {
public:
    unsigned char command;
    unsigned char unit_num;
    unsigned char _pad_0[2];
    long attribute;
};

class TRIBE_Command : public RGE_Command {
public:
    void do_command_trade_attribute(TRIBE_Command_Trade_Attribute* param_1);
};

void TRIBE_Command::do_command_trade_attribute(TRIBE_Command_Trade_Attribute* param_1) {
    int count = param_1->unit_num;
    unsigned char* p = (unsigned char*)(param_1 + 1);

    if (count > 0) {
        do {
            RGE_Static_Object* obj = this->get_obj(*(int*)p);
            if (obj != 0) {
                obj->attribute_type_held = (short)param_1->attribute;
            }
            p += 4;
        } while (--count != 0);
    }
}
