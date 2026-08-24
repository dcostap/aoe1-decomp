// 0040C010 DiplomacyAIModule::update
// try 1: avoid bound local; reload player/world at loop bottom like original, no cached num_players.
class MainDecisionAIModule;
#ifndef AOE1_AIDIPMOD_TU_CONTEXT
class AIModule { public: virtual ~AIModule() {} virtual void dummy1() {} char _gap_04[0xEC]; };
class DiplomacyAIModule : public AIModule {
public:
    MainDecisionAIModule* md; int dislikeTable[10]; int likeTable[10]; unsigned char changeableTable[10];
    virtual int update(int param); int isAlly(int id); int isAlliedWithMe(int id); void changeStance(int id, int a, int b);
};
#endif
int DiplomacyAIModule::update(int)
{
    int i = 1;
    char* player = *(char**)((char*)this->md + 0xF0);
    char* world = *(char**)(player + 0x3C);
    if (*(short*)(world + 0x3C) > i) {
        do {
            if (i != *(short*)(player + 0x4A)) {
                if (isAlly(i)) {
                    if (!isAlliedWithMe(i)) changeStance(i, 0, 1);
                }
                if (!isAlly(i)) {
                    if (isAlliedWithMe(i)) changeStance(i, 2, 1);
                }
            }
            player = *(char**)((char*)this->md + 0xF0);
            ++i;
            world = *(char**)(player + 0x3C);
        } while (i < *(short*)(world + 0x3C));
    }
    return 1;
}
