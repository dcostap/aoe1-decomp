// VA: 004F8E20 updateGathererDistribution (1369B)
// taitacmd.cpp

extern int g_update_flag;

class TribeAICommand {
public:
    char gap4[0xD64];
    int field_D68;
    
    void updateGathererDistribution();
};

int g_update_flag = 0;

void TribeAICommand::updateGathererDistribution() {
    field_D68 = g_update_flag;
    g_update_flag = field_D68;
}
