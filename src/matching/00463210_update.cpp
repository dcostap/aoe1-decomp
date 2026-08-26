#ifndef OBJLIST_SHARED_CONTEXT
class RGE_Master_Static_Object;
class RGE_Player;
class TDrawArea;
class RGE_Color_Table;

class RGE_Static_Object {
public:
    virtual void destroy(int);
    virtual void recycle_in_to_game(RGE_Master_Static_Object*, RGE_Player*,
                                    float, float, float);
    virtual void recycle_out_of_game();
    virtual void draw(TDrawArea*, short, short, RGE_Color_Table*);
    virtual void shadow_draw(TDrawArea*, short, short, unsigned char);
    virtual void normal_draw(TDrawArea*, short, short);
    virtual void draw_front_frame(TDrawArea*, short, short);
    virtual void draw_back_frame(TDrawArea*, short, short);
    virtual void draw_frame(TDrawArea*, short, short);
    virtual unsigned char update();
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
            unsigned char cVar3 = pRVar1->node->update();
            if (cVar3 != 0) {
                pRVar1->node->recycle_out_of_game();
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
