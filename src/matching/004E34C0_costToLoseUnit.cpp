// 004E34C0 TribeInformationAIModule::costToLoseUnit
// Authentic RGE_Player::objectCostByType owns the cost lookup.

int TribeInformationAIModule::costToLoseUnit(int param_1) {
    RGE_Static_Object* object = md->object(param_1);
    if (object == 0) {
        return -1;
    }
    return md->costTableOwner->objectCostByType(object->master_obj->unitType);
}
