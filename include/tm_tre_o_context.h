#ifndef TM_TRE_O_CONTEXT_H
#define TM_TRE_O_CONTEXT_H

// Canonical declarations for the tm_tre_o.cpp owner sequence.
// The base object has a byte type marker at +0x04 and a total size of 0xB8.

class RGE_Player;
class RGE_Static_Object;

class RGE_Master_Static_Object {
public:
    char field_04;
    char _gap_05[0xB7];

    virtual ~RGE_Master_Static_Object();

    RGE_Master_Static_Object(RGE_Master_Static_Object* object, int do_setup);
    RGE_Master_Static_Object(int param_1, void** sprites, void** sounds, int flag);
    RGE_Master_Static_Object(void* stream, void** sprites, void** sounds,
        int index, int flag);

    void setup(RGE_Master_Static_Object* object);
    void setup(int param_1, void** sprites, void** sounds);
    void setup(void* stream, void** sprites, void** sounds, int index);
};

class TRIBE_Master_Tree_Object : public RGE_Master_Static_Object {
public:
    virtual ~TRIBE_Master_Tree_Object();

    TRIBE_Master_Tree_Object(TRIBE_Master_Tree_Object* param_1, int param_2);
    TRIBE_Master_Tree_Object(int param_1, void** sprites, void** sounds, int flag);
    TRIBE_Master_Tree_Object(void* stream, void** sprites, void** sounds,
        int index, int flag);

    virtual RGE_Static_Object* make_new_obj(RGE_Player* player,
        float x, float y, float z);
    RGE_Master_Static_Object* make_new_master(void);
};

#endif
