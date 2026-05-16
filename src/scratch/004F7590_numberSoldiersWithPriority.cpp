// VA: 004F7590 TribeTacticalAIModule::numberSoldiersWithPriority
// Attempt log:
// try 1: adapted dynamic-array/scanning shape from numberUngroupedSoldiers and packet: reset working list, scan soldiers, resolve object, filter valid/busy/grouped/priority, count unique working soldiers.
// try 2: fixed local layout for busy array near +0xD58 so source compiles.
// try 3: minimal behavioral source compiled but only 400B vs 726B.
// try 4: /Od probe still too small (584B) and wrong basin; removed.
// try 5: inlined soldier array growth at scan index like original dynamic-array pattern.
// try 6: inlined working array growth/copy/delete before adding accepted soldier.
// try 7: modeled reset flag clearing workingNumber at +0xD4C.
// try 8: modeled busy-list duplicate exclusion loop using busyValue/busyNumber/busyMaximum.
// try 9: modeled negative/positive/zero priority comparisons via UnitAI priority/taskPriority calls.
// try 10: /GX probe no size/codegen change; removed.
// left in scratch: current clean source is 624B vs original 726B and broad dynamic-array/filter/call topology is still missing, not accepted_drift-safe.

void* __cdecl operator new(unsigned int size);
void __cdecl operator delete(void* p);
class TacticalAIGroup;
class RGE_Game_World { public: void* object(int); };
class UnitAI { public: int priority(); int taskPriority(); };
class RGE_Static_Object { public: char gap0[8]; UnitAI* ai; };
class AIPlayer { public: char gap[0x1256C]; RGE_Game_World* world; };

struct IntArray { int* value; int number; int max; void set_size(int); };

class TribeTacticalAIModule {
public:
    char gap_000[0xF0];
    AIPlayer* aiPlayer;
    char gap_0F4[0x20];
    int* soldierValue;
    int soldierNumber;
    char gap_11C[4];
    int soldierMaximum;
    char gap_124[0xD48 - 0x124];
    int* workingValue;
    int workingNumber;
    char gap_D50[4];
    int workingMaximum;
    int* busyValue;
    int busyNumber;
    char gap_D60[4];
    int busyMaximum;

    UnitAI* unitAI(RGE_Static_Object*);
    int numberSoldiersWithPriority(int pri, int threshold, int reset);
};

int TribeTacticalAIModule::numberSoldiersWithPriority(int pri, int threshold, int reset)
{
    int count;
    int rNum;
    int i;

    count = (int)this;
    rNum = 0;
    if (reset == 1) this->workingNumber = 0;
    i = 0;
    if (this->soldierNumber > 0) {
        do {
            if (i > this->soldierMaximum - 1) {
                int* nv = (int*)operator new(i * 4 + 4);
                if (nv != 0) {
                    int a = 0;
                    if (this->soldierMaximum > 0) {
                        do {
                            if (a >= i + 1) break;
                            nv[a] = this->soldierValue[a];
                            a++;
                        } while (a < this->soldierMaximum);
                    }
                    operator delete(this->soldierValue);
                    this->soldierValue = nv;
                    this->soldierMaximum = i + 1;
                }
            }
            RGE_Static_Object* obj = (RGE_Static_Object*)this->aiPlayer->world->object(this->soldierValue[i]);
            if (obj != 0 && this->unitAI(obj) != 0) {
                int id = this->soldierValue[i];
                int busy = 0;
                for (int j = 0; j < this->busyNumber && j < this->busyMaximum; j++) {
                    if (this->busyValue[j] == id) { busy = 1; break; }
                }
                if (!busy) {
                    int ok = 0;
                    UnitAI* ai = this->unitAI(obj);
                    if (pri < 0) {
                        int p = ai->priority();
                        if (p == -1 || ai->taskPriority() < threshold) ok = 1;
                    } else if (pri > 0) {
                        int p = ai->priority();
                        if (p != -1 && ai->taskPriority() > threshold) ok = 1;
                    } else {
                        int p = ai->priority();
                        if (p != -1 && ai->taskPriority() == threshold) ok = 1;
                    }
                    if (ok) {
                        int present = 0;
                        for (int k = 0; k < this->workingNumber && k < this->workingMaximum; k++) {
                            if (this->workingValue[k] == id) { present = 1; break; }
                        }
                        if (!present) {
                            if (this->workingNumber > this->workingMaximum - 1) {
                                int newMax = this->workingNumber + 1;
                                int* nv2 = (int*)operator new(newMax * 4);
                                if (nv2 != 0) {
                                    int b = 0;
                                    if (this->workingMaximum > 0) {
                                        do {
                                            if (b >= newMax) break;
                                            nv2[b] = this->workingValue[b];
                                            b++;
                                        } while (b < this->workingMaximum);
                                    }
                                    operator delete(this->workingValue);
                                    this->workingValue = nv2;
                                    this->workingMaximum = newMax;
                                }
                            }
                            this->workingValue[this->workingNumber] = id;
                            this->workingNumber++;
                        }
                        rNum++;
                    }
                }
            }
            i++;
        } while (i < this->soldierNumber);
    }
    return rNum;
}
