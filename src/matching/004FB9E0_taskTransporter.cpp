// VA: 004FB9E0 TribeTacticalAIModule::taskTransporter (336 bytes)
// PDB: taitacmd.cpp:9286-9313
// __thiscall, int, ret 0Ch
//
// Attempt log:
// - Replaced the raw-offset/free-function scaffold with the binary-backed
//   MainDecision object lookup, distance/priority calls, unitsTaskedThisUpdate
//   ManagedArray growth, and typed player slot-0x30 dispatch.
// - Exact baseline: the same natural bounded scan/growth idiom as the
//   taskFollower/taskDefender donors, with sendUnitAIOrder's high-confidence
//   RGE_Player slot-0x30 signature; generic proxy naming was removed.

struct ManagedIntArray {
    int* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSize;
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    char gap_04[0x34];
    float world_x;
    float world_y;

    float distance_to_position(float x, float y, float z);
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    virtual void set_game_status(unsigned char status);
    virtual void do_resign(int player_id);
    virtual void changeToHumanPlayer();
    virtual void changeToComputerPlayer();
    virtual char* aiStatus(int value);
    virtual int isEnemy(int player_id);
    virtual int isAlly(int player_id);
    virtual int isNeutral(int player_id);
    virtual int isAllNeutral();
    virtual void setDiplomaticStance(int player_id, int stance);
    virtual void loadAIInformation(char* file_name, char* player_name,
                                   char* civilization_name, int player_id,
                                   int civilization_id);
    virtual void sendUnitAIOrder(int owner, int unit_id, int command,
                                 int arg4, int arg5, float x1, float y1,
                                 float z1, float z2, int arg10, int arg11,
                                 int priority) = 0;
    char gap_04[0x46];
    short id;
};

class MainDecisionAIModule {
public:
    virtual ~MainDecisionAIModule();
    char gap_04[0xEC];
    RGE_Player* player;

    RGE_Static_Object* object(int id);
};

class TribeMainDecisionAIModule : public MainDecisionAIModule {
};

class TribeTacticalAIModule {
public:
    virtual ~TribeTacticalAIModule();
    char gap_04[0xEC];
    TribeMainDecisionAIModule* md;
    char gap_F4[0xD58 - 0xF4];
    ManagedIntArray unitsTaskedThisUpdate;

    int calculatePriority(float distance);
    int taskTransporter(int playerID, float x, float y);
};

int TribeTacticalAIModule::taskTransporter(int playerID, float x, float y)
{
    RGE_Static_Object* object = this->md->object(playerID);
    if (playerID == -1 || object == 0) {
        return 0;
    }

    float distance = object->distance_to_position(x, y, 1.0f);
    int priority = this->calculatePriority(distance);

    ManagedIntArray& arr = this->unitsTaskedThisUpdate;
    int i;
    for (i = 0; i < arr.numberValue; i++) {
        if (i >= arr.maximumSize)
            break;
        if (arr.value[i] == playerID)
            goto dispatch;
    }

    if (arr.numberValue > arr.maximumSize - 1) {
        int newSize = arr.numberValue + 1;
        int* newArray = new int[newSize];
        if (newArray != 0) {
            int j;
            for (j = 0; j < arr.maximumSize && j < newSize; j++) {
                newArray[j] = arr.value[j];
            }
            delete[] arr.value;
            arr.value = newArray;
            arr.maximumSize = newSize;
        }
    }

    arr.value[arr.numberValue] = playerID;
    arr.numberValue++;

dispatch:
    RGE_Player* player = this->md->player;
    player->sendUnitAIOrder((int)player->id, playerID, 0x2CA, -1,
                            (int)player->id, x, y, 1.0f, 1.0f,
                            1, 0, priority);
    return 1;
}
