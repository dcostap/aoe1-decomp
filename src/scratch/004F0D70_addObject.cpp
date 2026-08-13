// 004F0D70 TribeTacticalAIModule::addObject
// PDB: taitacmd.cpp lines 3098-3167
//
// Attempt log:
// - Earlier source used an add_unique_scan helper and wrong list offsets.
//   It collapsed the four inline scan blocks and produced a 500-byte body.
// - The binary uses one shared resize/append tail for civilians and soldiers.
//   Boat and subtype lists use separate inline bodies.
// - Fresh typed reconstruction: model the ten ManagedArray fields at their
//   proven offsets and use the declaration-only period array methods.
// - Baseline direct scans with do/while loops rebuilt 879 bytes and aligned
//   all 11 calls.  Matching the same-TU for-loop donor reduced this to 839.
// - Loading each subtype list before contains reduced the body to 825 bytes.
//   The player/world correction then reduced it to 822 bytes and aligned the
//   difficulty chain at md->player->world (+0x3c).
// - A split scan-ID/contains-ID local reduced size to 801 but worsened byte
//   alignment.  It was restored.  Current source is the 822-byte candidate:
//   all calls and list offsets align, but register ownership and several
//   subtype blocks still differ.
// - Session shardA4: direct `this`/parameter use, declaration reordering, and
//   the donor-backed TacticalAIModule virtual base were natural ABI probes;
//   each was a codegen duplicate.
// - The original has a dedicated boat-chain return before the shared
//   civilian/soldier append.  Added that return and the fishing early-return
//   form; returns became 3/3 and exact-block coverage improved to 60.66%, but
//   the 822-byte body and first prologue mismatch remained.
// - A preincrement resize capacity form was also a codegen duplicate and was
//   restored to the clearer `number + 1` spelling.

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    char gap_04[0x0c];
    short id;
    char gap_12[2];
    short object_group;
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    int id;
    RGE_Master_Static_Object* master_obj;
};

class RGE_Game_World {
public:
    char gap_00[0x3c];
    int difficultyLevel();
};

class RGE_Player {
public:
    char gap_00[0x3c];
    RGE_Game_World* world;
};

class TribeMainDecisionAIModule {
public:
    char gap_00[0xf0];
    RGE_Player* player;
};

template <class T>
class ManagedArray {
public:
    T* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;

    int resize(int new_size);
    int contains(const T& wanted) const;
    int add(T value);
};

class TacticalAIModule {
public:
    virtual ~TacticalAIModule();
};

class TribeTacticalAIModule : public TacticalAIModule {
public:
    char gap_04[0xec];
    TribeMainDecisionAIModule* md;
    ManagedArray<int> civilians;
    ManagedArray<int> civilianExplorers;
    ManagedArray<int> soldiers;
    ManagedArray<int> ungroupedSoldiers;
    ManagedArray<int> boats;
    ManagedArray<int> warBoats;
    ManagedArray<int> fishingBoats;
    ManagedArray<int> tradeBoats;
    ManagedArray<int> transportBoats;
    ManagedArray<int> artifacts;

    void addObject(RGE_Static_Object* obj);
};

void TribeTacticalAIModule::addObject(RGE_Static_Object* obj)
{
    short group = obj->master_obj->object_group;
    int id;
    int number;
    int i;
    ManagedArray<int>* list;

    if (group == 4) {
        number = this->civilians.numberValue;
        id = obj->id;
        list = &this->civilians;
        for (i = 0; i < number; i++) {
            if (i >= list->maximumSizeValue)
                break;
            if (list->value[i] == id)
                return;
        }
        if (number <= list->maximumSizeValue - 1)
            goto append;
    }
    else {
        if (group == 0 || group == 0x18 || group == 6 || group == 0x19 ||
            group == 0x1a || group == 0x0c || group == 0x23 ||
            group == 0x17 || group == 0x24 || group == 0x1c ||
            group == 0x12 || group == 0x0d || group == 0x27) {
            number = this->soldiers.numberValue;
            id = obj->id;
            list = &this->soldiers;
            for (i = 0; i < number; i++) {
                if (i >= list->maximumSizeValue)
                    break;
                if (list->value[i] == id)
                    return;
            }
            if (number <= list->maximumSizeValue - 1)
                goto append;
        }
        else {
            if (group != 2 && group != 0x14 && group != 0x16 && group != 0x15) {
                if (obj->master_obj->id != 0x9f)
                    return;
                if (this->md->player->world->difficultyLevel() >= 4)
                    return;
                this->artifacts.add(obj->id);
                return;
            }

            number = this->boats.numberValue;
            id = obj->id;
            list = &this->boats;
            for (i = 0; i < number; i++) {
                if (i >= list->maximumSizeValue)
                    break;
                if (list->value[i] == id)
                    goto boat_done;
            }
            if (number > list->maximumSizeValue - 1)
                list->resize(number + 1);
            list->value[list->numberValue] = id;
            list->numberValue++;

boat_done:
            if (obj->master_obj->object_group == 2) {
                number = this->tradeBoats.numberValue;
                id = obj->id;
                list = &this->tradeBoats;
                for (i = 0; i < number; i++) {
                    if (i >= list->maximumSizeValue)
                        break;
                    if (list->value[i] == id)
                        goto trade_done;
                }
                if (number > list->maximumSizeValue - 1)
                    list->resize(number + 1);
                list->value[list->numberValue] = id;
                list->numberValue++;
            }

trade_done:
            if (obj->master_obj->object_group == 0x14) {
                id = obj->id;
                list = &this->transportBoats;
                if (list->contains(id) != 1) {
                    number = list->numberValue;
                    if (number > list->maximumSizeValue - 1)
                        list->resize(number + 1);
                    list->value[list->numberValue] = id;
                    list->numberValue++;
                }
            }

            if (obj->master_obj->object_group == 0x16) {
                id = obj->id;
                list = &this->warBoats;
                if (list->contains(id) != 1) {
                    number = list->numberValue;
                    if (number > list->maximumSizeValue - 1)
                        list->resize(number + 1);
                    list->value[list->numberValue] = id;
                    list->numberValue++;
                }
            }

            if (obj->master_obj->object_group == 0x15) {
                id = obj->id;
                list = &this->fishingBoats;
                if (list->contains(id) == 1)
                    return;
                number = list->numberValue;
                if (number > list->maximumSizeValue - 1)
                    list->resize(number + 1);
                list->value[list->numberValue] = id;
                list->numberValue++;
                return;
            }
            return;
        }
    }

    list->resize(number + 1);

append:
    list->value[list->numberValue] = id;
    list->numberValue++;
}
