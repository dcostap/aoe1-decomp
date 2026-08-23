#ifndef OBJLIST_SHARED_CONTEXT
class RGE_Static_Object {
public:
    virtual char vf00();
    virtual char vf04();
    virtual char vf08();
    virtual char vf0C();
    virtual char vf10();
    virtual char vf14();
    virtual char vf18();
    virtual char vf1C();
    virtual char vf20();
    virtual char vf24();
};

struct RGE_Object_Node {
    RGE_Static_Object* node;
    RGE_Object_Node* next;
};

class TMousePointer {
public:
    void Poll(void);
};

extern TMousePointer* MouseSystem;

class RGE_Object_List {
public:
    char gap_00[4];
    RGE_Object_Node* list;
    short number_of_objects;

    void update(void);
};
#endif

#ifdef OBJLIST_SHARED_CONTEXT
class TMousePointer {
public:
    void Poll(void);
};
extern TMousePointer* MouseSystem;
#endif

void RGE_Object_List::update(void) {
    RGE_Object_Node* pRVar1 = this->list;
    int iVar4 = 0;

    while (pRVar1 != 0) {
        RGE_Object_Node* pRVar2 = pRVar1->next;
        if (pRVar1->node != 0) {
            char cVar3 = pRVar1->node->vf24();
            if (cVar3 != 0) {
                pRVar1->node->vf08();
            }
            iVar4 = iVar4 + 1;
            if (9 < iVar4) {
                iVar4 = 0;
                if (MouseSystem != 0) {
                    MouseSystem->Poll();
                }
            }
        }
        pRVar1 = pRVar2;
    }
}
