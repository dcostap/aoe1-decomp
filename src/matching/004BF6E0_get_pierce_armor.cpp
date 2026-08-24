#ifndef SPNL_OBJ_TU
class RGE_Master_Static_Object {
public:
    char gap_00[0x4];
    unsigned char master_type;
    char gap_05[0x45];
    unsigned char sort_number;
    unsigned char can_be_built_on;
    short button_pict;
    char gap_4E[0x6A];
};

class TRIBE_Scenario_Editor_Panel_Object {
public:
    char gap_00[0x214];
    RGE_Master_Static_Object* master_game_obj;

    long get_pierce_armor(void);
};
#endif

long TRIBE_Scenario_Editor_Panel_Object::get_pierce_armor(void) {
    RGE_Master_Static_Object* master = this->master_game_obj;
    if (master == 0) {
        return 0;
    }
    if (master->master_type != 'F') {
        return 0;
    }

    RGE_Master_Static_Object* obj = master + 1;
    int count = *(short*)((char*)obj + 0x4A);
    long result = 0;
    if (count > 0) {
        short* table = *(short**)((char*)obj + 0x4C);
        do {
            if (table[0] == 3) {
                result = table[1];
            }
            table += 2;
            count--;
        } while (count != 0);
    }
    return result;
}
