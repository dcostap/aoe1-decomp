// VA: 004C1100 RGE_Static_Object ctor (179B)
// stat_obj.cpp lines 132-136
// Attempt log:
// try 1: inherited one-int ctor stub with /GX too small/wrong signature.
// try 2: natural virtual class and full six-arg constructor; emitted EH but .text was 176 bytes (3 bytes short).
// try 3: novtable plus manual vptr store removed the EH constructor basin, 144-byte wrong family.
// try 4: normal virtual plus volatile keep local did not change 176-byte size.
// try 5: normal virtual plus manual vptr store again collapsed to 144-byte wrong family.
// try 6: polymorphic base class to force EH/base context reached 179 bytes but broad drift: compiler emits base vptr zero/store early and reorders -1/state/zero stores.
// try 7: setup return type void vs int; no codegen/size change.
// try 8: moving -1 stores before zero stores; no size/codegen improvement.
// try 9: flag probes /Ob0, /Ob1, /O2 without /Oy kept 176-byte short object; /O1 wrong smaller family.
// GIVEUP: left in scratch. Behavior and class layout are understood, but the exact constructor lowering needs a hidden class/member lifetime surface. Best natural virtual version is only 3 bytes short; adding novtable/manual vptr loses EH, while adding a polymorphic base reaches size but causes broad vptr/store-order drift. Not proposing accepted_drift because current comparable variant has broad constructor store-order/vptr drift, and the best 176-byte variant cannot be positionally validated by the checker.

class RGE_Master_Static_Object;
class RGE_Player;

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    char gap_04[0x0C];
    void* sprite;
    void* old_sprite;
    char gap_18[0x38];
    void* player_object_node;
    int pathing_value;
    int pathing_number;
    int pathing_desired;
    int pathing_maximum;
    int group_value;
    int group_number;
    int group_desired;
    int group_maximum;
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
{
    this->sprite = 0;
    this->old_sprite = 0;
    this->pathing_value = 0;
    this->pathing_number = 0;
    this->pathing_desired = 0;
    this->pathing_maximum = 0;
    this->group_value = 0;
    this->group_number = 0;
    this->group_desired = 0;
    this->group_maximum = 0;
    this->groupCommanderValue = -1;
    this->zoneMapIndex = -1;
    this->unitAIValue = 0;
    this->groupRangeValue = 5.0f;
    this->inObstructionMapValue = 0;
    this->lastInObstructionMapValue = 0;
    this->underAttackValue = 0;
    this->player_object_node = 0;
    if (do_setup != 0) {
        this->setup(master, player, x, y, z);
    }
}
