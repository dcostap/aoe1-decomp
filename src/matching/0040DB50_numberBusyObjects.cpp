// attempt 2: typed game/world and combined growth-copy condition matching VC5 managed array pattern

void* operator new(unsigned int);
void operator delete(void*);
class RGE_Static_Object;
class RGE_Game_World { public: RGE_Static_Object* object(long id); };
class GameShell { public: char gap_00[0x3C]; RGE_Game_World* world; };
class UnitAIModule { public: int currentAction(); };
class RGE_Static_Object { public: UnitAIModule* unitAI(); };

class MainDecisionAIModule {
public:
    char gap_000[0xF0];
    GameShell* game;
    long* object_ids;
    long object_count;
    char gap_0FC[4];
    long object_capacity;
    int numberBusyObjects();
};

int MainDecisionAIModule::numberBusyObjects() {
    int count = 0;
    int i = 0;
    if (this->object_count > 0) {
        do {
            if (i > this->object_capacity - 1) {
                int newCapacity = i + 1;
                long* newIds = (long*)operator new(newCapacity * 4);
                if (newIds != 0) {
                    int j = 0;
                    while (j < this->object_capacity && j < newCapacity) {
                        newIds[j] = this->object_ids[j];
                        ++j;
                    }
                    operator delete(this->object_ids);
                    this->object_ids = newIds;
                    this->object_capacity = newCapacity;
                }
            }
            RGE_Static_Object* obj = this->game->world->object(this->object_ids[i]);
            if (obj != 0 && obj->unitAI() != 0) {
                UnitAIModule* ai = obj->unitAI();
                if (ai->currentAction() == -1) {
                    count++;
                }
            }
            ++i;
        } while (i < this->object_count);
    }
    return count;
}
