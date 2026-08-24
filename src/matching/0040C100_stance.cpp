// VA: 0040C100 DiplomacyAIModule::stance
// The standalone declaration uses the ordinary parameter ABI.
class MainDecisionAIModule;
#ifndef AOE1_AIDIPMOD_TU_CONTEXT
class AIModule { public: virtual ~AIModule() {} virtual void dummy1() {} char _gap_04[0xEC]; };
class DiplomacyAIModule { public: char base[0xF0]; MainDecisionAIModule* md; int dislikeTable[10]; int likeTable[10]; unsigned char changeableTable[10]; int stance(int player_id, int type); };
#endif
int DiplomacyAIModule::stance(int player_id, int type)
{
    if ((0 < player_id) && (player_id < *(short*)(*(char**)(*(char**)((char*)this->md + 0xF0) + 0x3C) + 0x3C))) {
        switch (type) {
        case 0:
            return this->dislikeTable[player_id];
        case 1: {
            int dislike_diff = 0x31 - this->dislikeTable[player_id];
            if (dislike_diff < 0) dislike_diff = -dislike_diff;
            int like_diff = 0x31 - this->likeTable[player_id];
            if (like_diff < 0) like_diff = -like_diff;
            int result = 100 - dislike_diff - like_diff;
            if (result < 0) result = 0;
            return result;
        }
        case 2:
            return this->likeTable[player_id];
        }
    }
    return -1;
}
