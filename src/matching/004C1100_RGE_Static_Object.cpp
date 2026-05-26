// VA: 004C1100 RGE_Static_Object ctor (179B)
// Retry 2026-05-26: testing ManagedArray subobject surface.

class RGE_Master_Static_Object;
class RGE_Player;

class ManagedArrayInt {
public:
    int* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;
    ManagedArrayInt() : value(0), numberValue(0), desiredNumberValue(0), maximumSizeValue(0) {}
    ~ManagedArrayInt();
};

class __declspec(novtable) RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    char gap_04[0x0C];
    void* sprite;
    void* old_sprite;
    char gap_18[0x38];
    void* player_object_node;
    ManagedArrayInt pathingGroupMembers;
    ManagedArrayInt groupMembers;
    void* unitAIValue;
    int groupCommanderValue;
    int zoneMapIndex;
    float groupRangeValue;
    unsigned char inObstructionMapValue;
    unsigned char lastInObstructionMapValue;
    unsigned char underAttackValue;

    RGE_Static_Object(RGE_Master_Static_Object* master, RGE_Player* player, float x, float y, float z, int do_setup);
    void setup(RGE_Master_Static_Object* master, RGE_Player* player, float x, float y, float z);
};

RGE_Static_Object::RGE_Static_Object(RGE_Master_Static_Object* master, RGE_Player* player, float x, float y, float z, int do_setup)
    : sprite(0), old_sprite(0)
{
    this->unitAIValue = 0;
    this->groupCommanderValue = -1;
    this->zoneMapIndex = -1;
    this->groupRangeValue = 5.0f;
    this->inObstructionMapValue = 0;
    this->lastInObstructionMapValue = 0;
    this->underAttackValue = 0;
    *(int*)this = 0x574530;
    this->player_object_node = 0;
    if (do_setup != 0) {
        this->setup(master, player, x, y, z);
    }
}
