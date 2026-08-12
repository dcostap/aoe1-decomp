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

class TribeTacticalAIModule {
public:
    char gap_00[0xf0];
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
    TribeTacticalAIModule* self = this;
    RGE_Static_Object* object = obj;
    short group = object->master_obj->object_group;
    ManagedArray<int>* list;
    int number;
    int id;
    int i;

    if (group == 4) {
        number = self->civilians.numberValue;
        id = object->id;
        list = &self->civilians;
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
            number = self->soldiers.numberValue;
            id = object->id;
            list = &self->soldiers;
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
                if (object->master_obj->id != 0x9f)
                    return;
                if (self->md->player->world->difficultyLevel() >= 4)
                    return;
                self->artifacts.add(object->id);
                return;
            }

            number = self->boats.numberValue;
            id = object->id;
            list = &self->boats;
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
            if (object->master_obj->object_group == 2) {
                number = self->tradeBoats.numberValue;
                id = object->id;
                list = &self->tradeBoats;
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
            if (object->master_obj->object_group == 0x14) {
                id = object->id;
                list = &self->transportBoats;
                if (list->contains(id) != 1) {
                    number = list->numberValue;
                    if (number > list->maximumSizeValue - 1)
                        list->resize(number + 1);
                    list->value[list->numberValue] = id;
                    list->numberValue++;
                }
            }

            if (object->master_obj->object_group == 0x16) {
                id = object->id;
                list = &self->warBoats;
                if (list->contains(id) != 1) {
                    number = list->numberValue;
                    if (number > list->maximumSizeValue - 1)
                        list->resize(number + 1);
                    list->value[list->numberValue] = id;
                    list->numberValue++;
                }
            }

            if (object->master_obj->object_group == 0x15) {
                id = object->id;
                list = &self->fishingBoats;
                if (list->contains(id) != 1) {
                    number = list->numberValue;
                    if (number > list->maximumSizeValue - 1)
                        list->resize(number + 1);
                    list->value[list->numberValue] = id;
                    list->numberValue++;
                }
            }
        }
    }

    list->resize(number + 1);

append:
    list->value[list->numberValue] = id;
    list->numberValue++;
}
