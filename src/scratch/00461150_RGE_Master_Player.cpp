// VA: 00461150 RGE_Master_Player::~RGE_Master_Player
// left in scratch: fields/vtable/free/delete behavior modeled; exact until master_objects gate.
// Remaining drift: VC5 emits memory cmp [edi+18] directly and shorter epilogue, while original loads
// master_object_num into AX, compares AX against zero twice before loop, then loops on [edi+18].

#include <stdlib.h>

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
};

class RGE_Master_Player {
public:
    char name[20];
    short master_object_num;
    RGE_Master_Static_Object** master_objects;
    short attribute_num;
    char culture;
    char type;
    float* attributes;

    virtual ~RGE_Master_Player();
};

RGE_Master_Player::~RGE_Master_Player() {
    *(int*)this = 0x00570C08;

    if (this->attribute_num > 0 && this->attributes != 0) {
        free(this->attributes);
        this->attributes = 0;
        this->attribute_num = 0;
    }

    short num = *(short*)((char*)this + 0x18);
    if (num > 0 && this->master_objects != 0) {
        short i = 0;
        if (num > 0) {
            do {
                RGE_Master_Static_Object* obj = this->master_objects[i];
                if (obj != 0) {
                    delete obj;
                    this->master_objects[i] = 0;
                }
                i++;
            } while (i < this->master_object_num);
        }
        free(this->master_objects);
        this->master_objects = 0;
        this->master_object_num = 0;
    }
}
