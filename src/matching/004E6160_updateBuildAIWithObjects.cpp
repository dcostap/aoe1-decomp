// VA: 004E6160 updateBuildAIWithObjects (236B)
// taimdmd.cpp:929-943
//
// Baseline reconstruction: the important-object ManagedArray growth is kept in
// its natural period source form, followed by the build-list update and the
// construction reference-point update for objects of master type 0x6d.
//
// Attempt log:
// - baseline: replaced the stale field-only stub with the binary-backed object
//   array, object/world/map ownership, and typed AI-module calls.
// - a decompiler-shaped do/break copy loop was 4 bytes too large; the natural
//   bounded while loop restored the original copy CFG and register roles.
// - keeping the i+1 limit local across allocation/copy/delete restored the
//   original EBP lifetime; the final source matches all five ordered calls.
// - Main-agent audit replaced explicit allocation helpers with natural
//   `new int[limit]` / `delete[]`; VC5 emits identical exact code.

#include <stdlib.h>

class RGE_Map {
public:
    char gap_00[0x08];
    int xSizeValue;
    int ySizeValue;
};

class RGE_Game_World {
public:
    char gap_00[0x28];
    RGE_Map* mapValue;
};

class RGE_Player {
public:
    char gap_00[0x3C];
    RGE_Game_World* worldValue;
};

class RGE_Master_Static_Object {
public:
    char gap_00[0x10];
    short id;
};

class RGE_Static_Object {
public:
    char gap_00[0x08];
    RGE_Master_Static_Object* master_obj;
    char gap_0C[0x2C];
    float world_x;
    float world_y;
    float world_z;
};

class MainDecisionAIModule {
public:
    char gap_00[0xF0];
    RGE_Player* player;
    int* objects_value;
    int objects_numberValue;
    int objects_pad_FC;
    int objects_maximumSizeValue;

    RGE_Static_Object* object(int object_id);
};

class TribeBuildAIModule {
public:
    char gap_00[0x5C0];
    int addItem(RGE_Static_Object* object, int flag);
};

class TribeConstructionAIModule {
public:
    char gap_00[0x318];
    void setReferencePoint(int mapX, int mapY, float xRef, float yRef, float zRef);
};

class TribeMainDecisionAIModule : public MainDecisionAIModule {
public:
    TribeBuildAIModule buildAI;
    TribeConstructionAIModule constructionAI;

    void updateBuildAIWithObjects();
};

void TribeMainDecisionAIModule::updateBuildAIWithObjects()
{
    int* newList;
    int j;
    RGE_Static_Object* object;
    int i;

    i = 0;
    if (this->objects_numberValue > 0) {
        do {
            if (i > this->objects_maximumSizeValue - 1) {
                int limit = i + 1;
                newList = new int[limit];
                if (newList != 0) {
                    j = 0;
                    if (this->objects_maximumSizeValue > 0) {
                        while (j < this->objects_maximumSizeValue && j < limit) {
                            newList[j] = this->objects_value[j];
                            ++j;
                        }
                    }
                    delete[] this->objects_value;
                    this->objects_value = newList;
                    this->objects_maximumSizeValue = limit;
                }
            }

            object = this->object(this->objects_value[i]);
            if (object != 0) {
                this->buildAI.addItem(object, 0);
                if (object->master_obj->id == 0x6d) {
                    this->constructionAI.setReferencePoint(
                        this->player->worldValue->mapValue->xSizeValue,
                        this->player->worldValue->mapValue->ySizeValue,
                        object->world_x,
                        object->world_y,
                        object->world_z);
                }
            }

            ++i;
        } while (i < this->objects_numberValue);
    }
}
