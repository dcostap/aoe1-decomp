// 004C11E0 RGE_Static_Object constructor
// stat_obj.cpp:182-186, 164 bytes, /GX
// Round2 pass: 10 variants tried: field-by-field natural ctor, temp zero local,
// raw *(int*) field stores, explicit state local, do_setup temp, visible destructor
// definition, shared -1 temp, small source order changes, and checking nearby ctor
// patterns. Best behavior source compiles to 160-byte non-EH .text; visible dtor
// variant emits a different broad EH/codegen family. Original has VC5 constructor EH
// registration/state around otherwise simple field initialization and optional setup;
// local stubs could not reproduce the exact EH/vptr/state basin. Not accepted drift.

class RGE_Game_World;
class RGE_Sprite;
class RGE_Object_Node;
class UnitAIModule;

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    char gap04[0x0C];
    RGE_Sprite* sprite;
    RGE_Sprite* old_sprite;
    char gap18[0x38];
    RGE_Object_Node* player_object_node;
    int pathingGroupValue;
    int pathingGroupNumber;
    int pathingGroupDesired;
    int pathingGroupMax;
    int groupValue;
    int groupNumber;
    int groupDesired;
    int groupMax;
    int unitAIValue;
    int groupCommanderValue;
    int zoneMapIndex;
    float groupRangeValue;
    unsigned char inObstructionMapValue;
    unsigned char lastInObstructionMapValue;
    unsigned char underAttackValue;

    RGE_Static_Object(int id, RGE_Game_World* world, int do_setup);
    int setup(int id, RGE_Game_World* world);
};

RGE_Static_Object::RGE_Static_Object(int id, RGE_Game_World* world, int do_setup)
{
    sprite = 0;
    old_sprite = 0;
    pathingGroupValue = 0;
    pathingGroupNumber = 0;
    pathingGroupDesired = 0;
    pathingGroupMax = 0;
    groupValue = 0;
    groupNumber = 0;
    groupDesired = 0;
    groupMax = 0;
    groupCommanderValue = -1;
    zoneMapIndex = -1;
    unitAIValue = 0;
    groupRangeValue = 5.0f;
    inObstructionMapValue = 0;
    lastInObstructionMapValue = 0;
    underAttackValue = 0;
    player_object_node = 0;
    if (do_setup != 0)
        setup(id, world);
}
