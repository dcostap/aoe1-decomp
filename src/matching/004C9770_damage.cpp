// 004C9770 TRIBE_Building_Object::damage (t_b_obj.cpp:931-962)
// Attempt log:
// - Baseline decompiler-shaped reconstruction was 10 bytes short because the
//   two branch-local HP reductions tail-merged.
// - Restored the normal-path one-point reduction (the special path is 0.1),
//   which reproduced the original duplicated FPU blocks and exact 246 bytes.
// - Replaced the raw HP bit shuttle with a natural pre-guard float snapshot;
//   VC5 emitted the same observed stack home.
// - Named the proven master/static-object fields and bound the observed
//   constants to their established globals without changing codegen.
// - Used the known player add_attribute_num ABI and qualified base damage call;
//   both remain exact under the default flags.

#include <string.h>
#include <stdio.h>

#include "../../include/t_b_obj_context.h"

void TRIBE_Building_Object::damage(int param_1, RGE_Armor_Weapon_Info* param_2, float param_3, RGE_Player* param_4, RGE_Static_Object* param_5)
{
    float saved_hp = this->hp;

    if (this->hp <= DAT_005749f4) {
        return;
    }

    RGE_Combat_Object::damage(param_1, param_2, param_3, param_4, param_5);

    RGE_Master_Static_Object* master = param_5->master_obj;
    short group = master->object_group;
    short id;
    float damage_taken;

    // Sequential if-checks with je-to-handler pattern for alternate path
    if (group == 0 || group == 0x17 || group == 0x24 || group == 0x1A ||
        (id = master->id,
         id == 0x4F || id == 0x45 || id == 0xC7 || id == 0x17F || id == 0x17C))
    {
        // Alternate path
        damage_taken = saved_hp - this->hp;
        if (damage_taken < DAT_00574a10) {
            this->hp = saved_hp - DAT_00574a18;
        }
    }
    else
    {
        // Normal path
        damage_taken = saved_hp - this->hp;
        if (damage_taken < DAT_00574a00) {
            this->hp = saved_hp - DAT_00574a08;
        }
    }

    RGE_Player* player = this->owner;

    if (player->id > 0 && this->hp < DAT_00574a00) {
        param_4->add_attribute_num(0x2B, 1.0f, 0);
    }
}
