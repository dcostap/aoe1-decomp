// attempt 1: natural RGE_Timeline update with event scan and switch dispatch

class Obj { public:
    virtual void vf00(); virtual void vf04(); virtual void vf08(); virtual void vf0c(); virtual void vf10(); virtual void vf14();
    virtual void vf18(Obj*, long, long, void*);
    virtual void vf1c(); virtual void vf20(); virtual void vf24(); virtual void vf28(); virtual void vf2c();
    virtual void vf30(); virtual void vf34(); virtual void vf38(); virtual void vf3c(); virtual void vf40(); virtual void vf44();
    virtual void vf48(); virtual void vf4c(); virtual void vf50(); virtual void vf54(); virtual void vf58(); virtual void vf5c();
    virtual void vf60(); virtual void vf64(); virtual void vf68();
    virtual void vf6c(); virtual void vf70(); virtual void vf74(); virtual void vf78(); virtual void vf7c(); virtual void vf80();
    virtual void vf84(); virtual void vf88(); virtual void vf8c(); virtual void vf90(); virtual void vf94(); virtual void vf98();
    char gap_04[0x44]; unsigned char state;
    virtual void vf9c(long, long, long, int);
    virtual void vfA0(); virtual void vfA4(); virtual void vfA8(Obj*);
};
class ProtoList { public: char gap_00[0x24]; Obj** lists; };
class Game { public: char gap_00[4]; int time; char gap_08[0x38]; ProtoList** proto_lists; };
struct RGE_Timeline_Node {
    float time; unsigned char action; short index; unsigned char list; char pad09[3];
    long p0c; long p10; long p14; char pad18[4]; Obj* obj1; short id1; char pad22[2]; Obj* obj2; short id2; char pad2a[2]; RGE_Timeline_Node* next;
};
class RGE_Timeline { public: char gap_00[4]; Game* game; RGE_Timeline_Node* list; float last_time; void update(); };

void RGE_Timeline::update() {
    float time;
    RGE_Timeline_Node* event = 0;
    __int64 ticks = 0;
    *(int*)&ticks = this->game->time;
    time = (float)ticks * 0.001f;
    RGE_Timeline_Node* node = this->list;
    if (node == 0) {
        this->last_time = time;
        return;
    }
    do {
        if (event == 0 && !(node->time < this->last_time)) {
            event = node;
        }
        if (node->obj1 != 0 && node->obj1->state >= 8) {
            node->obj1 = 0;
        }
        if (node->obj2 != 0 && node->obj2->state >= 8) {
            node->obj2 = 0;
        }
        node = node->next;
    } while (node != 0);

    if (event != 0) {
        do {
            if (!(event->time < time)) {
                break;
            }
            switch (event->action) {
            case 0:
                if (event->obj1 != 0 && event->obj2 != 0) {
                    event->obj1->vfA8(event->obj2);
                }
                break;
            case 1: {
                Obj* obj = this->game->proto_lists[event->list]->lists[event->index];
                if (obj != 0) {
                    obj->vf18((Obj*)this->game->proto_lists[event->list], event->p0c, event->p10, 0);
                    RGE_Timeline_Node* scan = this->list;
                    while (scan != 0) {
                        if (event->id1 == scan->id1) {
                            scan->obj1 = obj;
                        }
                        if (event->id1 == scan->id2) {
                            scan->obj2 = obj;
                        }
                        scan = scan->next;
                    }
                }
                break;
            }
            case 2:
                if (event->obj1 != 0) {
                    event->obj1->vf9c(event->p0c, event->p10, event->p14, 0);
                }
                break;
            case 4:
                if (event->obj1 != 0) {
                    event->obj1->vf68();
                }
                break;
            }
            event = event->next;
        } while (event != 0);
    }
    this->last_time = time;
}
