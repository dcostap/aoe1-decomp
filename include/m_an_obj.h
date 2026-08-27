#ifndef AOE1_M_AN_OBJ_H
#define AOE1_M_AN_OBJ_H

#include "m_s_obj_context.h"

extern "C" void __cdecl rge_read(int file, void* buffer, int size);
extern "C" void __cdecl rge_write(int file, void* buffer, int size);

class RGE_Master_Animated_Object : public RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Animated_Object();
    virtual void copy_obj(RGE_Master_Static_Object* source);
    virtual void modify(float value, unsigned char attribute);
    virtual void modify_delta(float value, unsigned char attribute);
    virtual void modify_percent(float value, unsigned char attribute);
    virtual void save(int file);
    virtual RGE_Static_Object* make_new_obj(RGE_Player* player, float x,
                                             float y, float z);
    virtual RGE_Master_Static_Object* make_new_master();

    RGE_Master_Animated_Object(RGE_Master_Animated_Object* source,
                               int do_setup);
    RGE_Master_Animated_Object(int id, RGE_Sprite** sprites,
                               RGE_Sound** sounds, int do_setup);
    RGE_Master_Animated_Object(FILE* file, RGE_Sprite** sprites,
                               RGE_Sound** sounds, short id, int do_setup);

protected:
    int setup(RGE_Master_Animated_Object* source);
    int setup(int file, RGE_Sprite** sprites, RGE_Sound** sounds);
    int setup(FILE* file, RGE_Sprite** sprites, RGE_Sound** sounds,
              short id);

    float speed;
};

typedef char m_an_obj_animated_size[
    (sizeof(RGE_Master_Animated_Object) == 0xBC) ? 1 : -1];

class RGE_Animated_Object : public RGE_Static_Object {
public:
    char gap_88[4];

    RGE_Animated_Object(RGE_Master_Animated_Object* master,
                        RGE_Player* player, float x, float y, float z,
                        int do_setup);
};

typedef char m_an_obj_object_size[
    (sizeof(RGE_Animated_Object) == 0x8C) ? 1 : -1];

#endif
