// VA: 00451000 calc_base_damage_ability (188B)
// m_co_obj.cpp

extern float base_damage_factor;

class RGE_Master_Combat_Object {
public:
    char gap4[0xFE];
    short field_102;
    char gap104[0x4];
    short field_108;
    int field_10C;
    
    float calc_base_damage_ability(void* target);
};

float RGE_Master_Combat_Object::calc_base_damage_ability(void* target) {
    float result = base_damage_factor;
    
    short count = *(short*)((char*)target + 0x108);
    if (count <= 0) return result;
    
    short abilityIdx = field_102;
    for (int i = 0; i < count; i++) {
        int* abilities = *(int**)((char*)target + 0x10C);
        if (abilities) {
            // Process ability
            break;
        }
    }
    
    return result;
}
