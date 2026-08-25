// 004DC1B0 TribeInformationAIModule::addObject
// Attempt log:
// 1: Natural reconstruction from packet and matching removeObject array layout: helper outlined, too small.
// 2: Inline duplicate managed-array append logic.
// 3: Use register object local to try EDI param preservation: no change.
// 4: Rewrite loop conditions as combined && instead of explicit breaks.

extern void* operator new(unsigned int);
extern void operator delete(void*);

#ifndef TAIINFMD_PREFIX_CONTEXT
#ifndef TAIINFMD_PREFIX_CONTEXT
struct ManagedArray_int {
    int* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;
};

struct ObjectMemory { unsigned char pad_00[0x0B]; unsigned char owner; };

class RGE_Player { public: unsigned char pad_00[0x4A]; unsigned char player_num; };
class RGE_Master_Static_Object { public: unsigned char pad_00[0x10]; short type; };
class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    int id;
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;
};

#endif
#ifndef TAIINFMD_PREFIX_CONTEXT
class TribeInformationAIModule {
public:
    unsigned char pad_000[0x180];
    ManagedArray_int playerObjects;
    ManagedArray_int playerBuildings;

    ObjectMemory* objectMemory(int id);
    int includeObject(RGE_Static_Object* obj);
    void addDocks();
    void addHouse(RGE_Static_Object* obj);
    void addObject(RGE_Static_Object* obj);
};
#endif

#endif
void TribeInformationAIModule::addObject(RGE_Static_Object* obj)
{
    register RGE_Static_Object* object = obj;
    if (object != 0 && object->id >= 0) {
        ObjectMemory* mem = this->objectMemory(object->id);
        if (mem != 0) {
            mem->owner = object->owner->player_num;
        }

        int id = object->id;
        int count = this->playerObjects.numberValue;
        int i = 0;
        while (i < count && i < this->playerObjects.maximumSizeValue) {
            if (this->playerObjects.value[i] == id) goto after_objects;
            ++i;
        }
        if (count > this->playerObjects.maximumSizeValue - 1) {
            int newMax = count + 1;
            int* newArray = (int*)operator new(newMax * 4);
            if (newArray != 0) {
                i = 0;
                while (i < this->playerObjects.maximumSizeValue && i < newMax) {
                    newArray[i] = this->playerObjects.value[i];
                    ++i;
                }
                operator delete(this->playerObjects.value);
                this->playerObjects.value = newArray;
                this->playerObjects.maximumSizeValue = newMax;
            }
        }
        this->playerObjects.value[this->playerObjects.numberValue] = id;
        ++this->playerObjects.numberValue;
after_objects:

        if (this->includeObject(object) == 1) {
            id = object->id;
            count = this->playerBuildings.numberValue;
            i = 0;
            while (i < count && i < this->playerBuildings.maximumSizeValue) {
                if (this->playerBuildings.value[i] == id) goto after_buildings;
                ++i;
            }
            if (count > this->playerBuildings.maximumSizeValue - 1) {
                int newMax = count + 1;
                int* newArray = (int*)operator new(newMax * 4);
                if (newArray != 0) {
                    i = 0;
                    while (i < this->playerBuildings.maximumSizeValue && i < newMax) {
                        newArray[i] = this->playerBuildings.value[i];
                        ++i;
                    }
                    operator delete(this->playerBuildings.value);
                    this->playerBuildings.value = newArray;
                    this->playerBuildings.maximumSizeValue = newMax;
                }
            }
            this->playerBuildings.value[this->playerBuildings.numberValue] = id;
            ++this->playerBuildings.numberValue;
after_buildings:

            short type = object->master_obj->type;
            if (type == 0x6d || type == 0x67 || type == 0x44) {
                this->addDocks();
            }
            if (object->master_obj->type == 0x32) {
                this->addHouse(object);
            }
        }
    }
}
