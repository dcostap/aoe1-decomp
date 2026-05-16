// VA: 0040D780 AIModule::object
// Source: aimdmod.cpp lines 194-213
// Attempt log:
// 1: natural reconstruction from packet: scan important object ids, grow id array when index exceeds capacity, fetch world object, apply optional filters, return first match; compiled too small (464 vs 578) because one grow block only and wrong filter mapping.
// 2: duplicated grow before virtual filter; size now matches but class data offsets were four bytes low and loop index register is EBX not original EBP.
// 3: fixed AIModule local layout so owner/array/count/capacity land at +F0/+F4/+F8/+100; offsets fixed, but loop index still EBX instead of original EBP.
// 4: declared loop index as register to try EBP allocation; no change.
// 5: tried /O1 /Oy flag probe; object shrank to 533 and failed configured size, flag removed.
// 6: tried /O2 /Oy /Ob0 flag probe; no change, flag removed.
// 7: used ordinary stack-visible loop index instead of register declaration; no change.
// 8: reviewed original line map: first loop/grow/fetch is line 195/196, then filters on line 207; rebuilt has same high-level behavior but VC5 picked EBX as index and preserves EBP for object.
// 9: tried class/vtable surface correction; vcall offset +4C and data offsets now binary-observed, but source shape still wrong for register reuse.
// 10: left in scratch: remaining broad drift is not accepted_drift-safe; original reuses EBP as loop index then object pointer and has exact duplicated grow topology before vf+4C, while rebuilt uses EBX index/EBP object and very different branch layout despite same size.

#include <stddef.h>

extern void* __cdecl operator new(unsigned int size);
extern void __cdecl operator delete(void* p);

class RGE_Master_Object {
public:
    char gap_00[0x10];
    short object_type;       // +10
    char gap_12[2];
    short object_class;      // +14
    int resource_class();
    int resource_subclass();
    int civilization();
};

class RGE_Static_Object {
public:
    void* vfptr;
    int id;                 // +04
    RGE_Master_Object* master; // +08
    char gap_0C[0x44 - 0x0C];
    float hit_points;       // +44
    unsigned char state;    // +48
    RGE_Master_Object* master_object();
};

class RGE_Game_World {
public:
    char gap_00[0x3C];
    RGE_Static_Object* object(int id);
};

class AIModule {
public:
    virtual void v00();
    virtual int vf04();
    virtual int vf08();
    virtual int vf0C();
    virtual int vf10();
    virtual int vf14();
    virtual int vf18();
    virtual int vf1C();
    virtual int vf20();
    virtual int vf24();
    virtual int vf28();
    virtual int vf2C();
    virtual int vf30();
    virtual int vf34();
    virtual int vf38();
    virtual int vf3C();
    virtual int vf40();
    virtual int vf44();
    virtual int vf48();
    virtual int vf4C(int obj_id, int filter);
    char gap_04[0xF0 - 0x04];
    void* owner;            // +F0
    int* importantObjects;  // +F4
    int numberImportantObjects; // +F8
    char gap_FC[4];
    int maxImportantObjects;    // +100

    RGE_Static_Object* object(int object_id, int type, int class_id, int action, int has_order_filter,
                              int resource_class, int resource_subclass, int state, int min_hit_points,
                              int civilization);
};

RGE_Static_Object* AIModule::object(int object_id, int type, int class_id, int action, int has_order_filter,
                                    int resource_class, int resource_subclass, int state, int min_hit_points,
                                    int civilization)
{
    int i = 0;
    if (this->numberImportantObjects <= 0) {
        return 0;
    }

    do {
        if (i > this->maxImportantObjects - 1) {
            int newMax = i + 1;
            int* newList = (int*)operator new(i * 4 + 4);
            if (newList != 0) {
                int j = 0;
                if (this->maxImportantObjects > 0) {
                    while (j < this->maxImportantObjects && j < newMax) {
                        newList[j] = this->importantObjects[j];
                        ++j;
                    }
                }
                operator delete(this->importantObjects);
                this->importantObjects = newList;
                this->maxImportantObjects = newMax;
            }
        }

        RGE_Static_Object* obj = ((RGE_Game_World*)((char*)this->owner + 0x3C))->object(this->importantObjects[i]);
        if (obj != 0 && obj->master_object() != 0) {
            if (object_id == -1 || obj->id == object_id) {
                if (type == -1 || (int)obj->master->object_type == type) {
                    if (class_id == -1 || (int)obj->master->object_class == class_id) {
                        if (action == -1 || obj->master_object()->resource_class() == action) {
                            if (has_order_filter != -1) {
                                if (i > this->maxImportantObjects - 1) {
                                    int newMax2 = i + 1;
                                    int* newList2 = (int*)operator new(i * 4 + 4);
                                    if (newList2 != 0) {
                                        int j2 = 0;
                                        if (this->maxImportantObjects > 0) {
                                            while (j2 < this->maxImportantObjects && j2 < newMax2) {
                                                newList2[j2] = this->importantObjects[j2];
                                                ++j2;
                                            }
                                        }
                                        operator delete(this->importantObjects);
                                        this->importantObjects = newList2;
                                        this->maxImportantObjects = newMax2;
                                    }
                                }
                                if (!this->vf4C(this->importantObjects[i], has_order_filter)) {
                                    goto next_object;
                                }
                            }
                            {
                                if (resource_class == -1 || obj->master_object()->resource_class() == resource_class) {
                                    if (resource_subclass == -1 || obj->master_object()->resource_subclass() == resource_subclass) {
                                        if (state == -1 || (int)obj->state == state) {
                                            if (min_hit_points == -1 || !((float)min_hit_points < obj->hit_points)) {
                                                if (civilization == -1 || obj->master_object()->civilization() == civilization) {
                                                    return obj;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

next_object:
        ++i;
    } while (i < this->numberImportantObjects);

    return 0;
}
