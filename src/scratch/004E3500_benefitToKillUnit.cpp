// 004E3500 TribeInformationAIModule::benefitToKillUnit
// Authentic owner and named game methods are supplied by the module context.

int __fastcall benefitToKillUnit(TribeTacticalAIModule* self, int, int unitId) {
    RGE_Static_Object* object = self->mainDecisionAI->object(unitId);
    if (object == 0)
        return -1;
    return object->owner->objectCostByType(object->master_obj->id);
}
