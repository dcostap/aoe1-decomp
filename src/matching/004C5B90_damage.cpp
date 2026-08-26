// 004C5B90 RGE_Static_Object::damage
// PDB: stat_obj.cpp:3099-3109, 74 bytes
// FLAGS: default
//
// Fixed: removed redundant `void* vtable_ptr` member (pushed hp from +0x30 to
// +0x34) and changed `1.0f` to `1.0` (original uses fcomp qword with double).
void RGE_Static_Object::damage(int count, RGE_Armor_Weapon_Info* info, float scale, RGE_Player* player, RGE_Static_Object* object) {
    float damage_amount;

    damage_amount = this->calculateDamage(count, info, scale, player, object);
    this->hp = this->hp - damage_amount;
    if (this->hp < 1.0) {
        this->hp = 0.0f;
        this->set_sleep_flag(0);
    }
}
