// The scalar deleting destructor at 0040CDC0 is compiler generated and has no

#include "../include/aiinfmod.h"

InformationAIModule::InformationAIModule(void* param1, int param2)
    : AIModule("InfAI", 0x3ED, param2, param1)
{
}

InformationAIModule::~InformationAIModule()
{
}
