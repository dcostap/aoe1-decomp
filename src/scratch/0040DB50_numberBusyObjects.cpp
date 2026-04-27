// attempt 1: 224 vs 218 bytes, 6 bytes too large
// PAUSED: same growth-pattern register allocation issue as save/addObject
// The inlined ManagedArray growth code causes VC5 to use different register allocation

struct ManagedArray_Int {
    int* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;
};

class AIModule {
public:
    void* vftable;
    char pad[0xEC];
};

struct RGE_Player;

class MainDecisionAIModule : public AIModule {
public:
    RGE_Player* player;
    ManagedArray_Int objects;

    int numberBusyObjects();
};

struct RGE_Static_Object;
class UnitAIModule;

RGE_Static_Object* get_object_from_world(void* world, int objectId);
UnitAIModule* RGE_Static_Object__unitAI(RGE_Static_Object* obj);
int UnitAIModule__currentAction(UnitAIModule* ai);
void* operator_new(unsigned int size);
void operator_delete(void* ptr);

int MainDecisionAIModule::numberBusyObjects() {
    int i = 0;
    int count = 0;
    if (this->objects.numberValue > 0) {
        do {
            if (this->objects.maximumSizeValue - 1 < i) {
                int* newArray = (int*)operator_new(i * 4 + 4);
                if (newArray != 0) {
                    for (int j = 0; j < this->objects.maximumSizeValue; j++) {
                        newArray[j] = this->objects.value[j];
                    }
                    operator_delete(this->objects.value);
                    this->objects.value = newArray;
                    this->objects.maximumSizeValue = i + 1;
                }
            }
            RGE_Static_Object* obj = get_object_from_world(this->player, this->objects.value[i]);
            if (obj != 0) {
                UnitAIModule* ai = RGE_Static_Object__unitAI(obj);
                if (ai != 0) {
                    ai = RGE_Static_Object__unitAI(obj);
                    if (UnitAIModule__currentAction(ai) == -1) {
                        count++;
                    }
                }
            }
            i++;
        } while (i < this->objects.numberValue);
    }
    return count;
}
