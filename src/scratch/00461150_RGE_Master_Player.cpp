// VA: 00461150 RGE_Master_Player::~RGE_Master_Player

#include <stdlib.h>

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
};

class RGE_Master_Player {
public:
    void* vtable;
    char name[20];
    short master_object_num;
    RGE_Master_Static_Object** master_objects;
    short tribe_effect;
    float* attributes;
    char culture;
    char type;
    short attribute_num;

    virtual ~RGE_Master_Player();
};

RGE_Master_Player::~RGE_Master_Player() {
    *(int*)this = 0x00570C08;

    if (this->attribute_num > 0 && this->attributes != 0) {
        free(this->attributes);
        this->attributes = 0;
        this->attribute_num = 0;
    }

    if (this->master_object_num > 0 && this->master_objects != 0) {
        short i = 0;
        if (this->master_object_num > 0) {
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
