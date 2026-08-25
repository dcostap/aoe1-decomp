// 004E3390 TribeInformationAIModule::damagePerSecond
// Authentic RGE_Player and RGE_Static_Object methods own the calls.

float TribeInformationAIModule::damagePerSecond(int param_1, int param_2, int param_3) {
    float rateOfFire = 0.0f;

    RGE_Static_Object* target = (RGE_Static_Object*)md->object(param_1);
    if (target == 0) {
        return 0.0f;
    }

    int i = 0;
    if (maxImportantObjectMemory > 0) {
        int base = 0;
        do {
            unsigned char owner = *(unsigned char*)(importantObjectMemory + base + 0x0B);
            if (md->player->isEnemy(owner)) {
                int id = *(int*)(importantObjectMemory + base);
                RGE_Static_Object* unit = (RGE_Static_Object*)md->object(id);
                if (unit != 0 && unit->object_state <= 2) {
                    float dist = unit->distance_to_position(
                        (float)param_2, (float)param_3, *(float*)&unit->world_z);
                    if (dist <= unit->master_obj->los) {
                        float rVal = target->get104(unit);
                        float rateTmp = unit->get100();
                        if (rateTmp != 0.0f && rVal != 0.0f) {
                            rateOfFire = rVal / rateTmp + rateOfFire;
                        }
                    }
                }
            }
            i++;
            base += 0x24;
        } while (i < maxImportantObjectMemory);
    }

    return rateOfFire;
}
