// 00515070 TRIBE_Player::addObject (tplayer.cpp:1974-1997, 105B)

#ifndef AOE1_TPLAYER_TU_SHARED_CONTEXT
struct RGE_Object_Node;
class RGE_Static_Object;
class RGE_Player {
public:
    virtual RGE_Object_Node* addObject(RGE_Static_Object* obj, int p2, int p3);
};

class AI_Manager {
public:
    virtual void method0();
    virtual void method1();
    virtual void method2();
    virtual void method3();
    virtual void method4();
    virtual void method5();
    virtual void method6();
    virtual void method7();
    virtual void method8();
    virtual void method9();
    virtual void method10();
    virtual void method11();
    virtual void method12();
    virtual void method13();
    virtual void method14();
    virtual void method15();
    virtual void method16(void* obj); // vtable[0x40]
};

class AI_Flags {
public:
    char gap_00[0x1D];
    unsigned char field_1D;
};

class TribeBuildAIModule {
public:
    int addItem(void* obj, int flag);
};

class TRIBE_Player : public RGE_Player {
public:
    char gap_04[0x38];
    AI_Flags* field_3C;
    char gap_40[0x1F8];
    AI_Manager* playerAI;

    virtual RGE_Object_Node* addObject(RGE_Static_Object* obj, int param2, int param3);
};
#endif

RGE_Object_Node* TRIBE_Player::addObject(RGE_Static_Object* obj, int param2, int param3)
{
    RGE_Object_Node* node = RGE_Player::addObject(obj, param2, param3);
    void* master = *(void**)((char*)obj + 8);
    if (*(short*)((char*)master + 0x14) == 0x0B) {
        return node;
    }
    if (this->playerAI == 0) {
        return node;
    }
    if (*(int*)((char*)obj + 4) < 0) {
        return node;
    }
    this->playerAI->addObject(obj);
    int flag = 1;
    if (this->field_3C->field_1D == 2) {
        flag = 0;
    }
    ((TribeBuildAIModule*)((char*)this->playerAI + 0x104))->addItem(obj, flag);
    return node;
}
