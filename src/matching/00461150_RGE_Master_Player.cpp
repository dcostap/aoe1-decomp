// VA: 00461150 RGE_Master_Player::~RGE_Master_Player
//
// Attempt log:
// - Prior scratch modeled fields/vtable/free/delete behavior; exact through attribute cleanup, then drifted at
//   master_objects gate because VC5 emitted memory cmp [edi+18] directly and shorter epilogue, while original loads
//   master_object_num into AX and compares AX before loop.
// - SpruceGlow tries: current/nested/goto forms stayed in same drift; using a saved `num` for the loop bound worsened
//   prologue/block shape.
// - SpruceGlow MATCH: spell the master_objects pass as a plain `for (short i = 0; i < master_object_num; i++)` inside
//   the outer `if (num > 0 && master_objects != 0)`. VC5 naturally emits the original AX load/gate plus loop compare
//   against `[edi+18]` and exact tail cleanup.
// Result: MATCH locally with `python tools/check_function.py --va 00461150`.

#ifndef MST_PLAY_SHARED_CONTEXT
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
#endif

RGE_Master_Player::~RGE_Master_Player() {
    *(int*)this = 0x00570C08;

    if (this->attribute_num > 0 && this->attributes != 0) {
        free(this->attributes);
        this->attributes = 0;
        this->attribute_num = 0;
    }

    short num = this->master_object_num;
    if (num > 0 && this->master_objects != 0) {
        for (short i = 0; i < this->master_object_num; i++) {
            RGE_Master_Static_Object* obj = this->master_objects[i];
            if (obj != 0) {
                delete obj;
                this->master_objects[i] = 0;
            }
        }

        free(this->master_objects);
        this->master_objects = 0;
        this->master_object_num = 0;
    }
}
