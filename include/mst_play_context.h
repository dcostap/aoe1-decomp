#ifndef MST_PLAY_TU_CONTEXT_H
#define MST_PLAY_TU_CONTEXT_H

#include <stdio.h>
#include <stdlib.h>

class RGE_Sprite;
class RGE_Sound;

extern "C" {
    void rge_read(int fd, void* buffer, int size);
    void rge_write(int fd, void* buffer, int size);
}

extern void* __cdecl operator new(unsigned int size);

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    virtual void copy_obj(RGE_Master_Static_Object* object);
    virtual void modify(float amount, unsigned char flag);
    virtual void modify_delta(float amount, unsigned char flag);
    virtual void modify_percent(float amount, unsigned char flag);
    virtual void save(int fd);

    RGE_Master_Static_Object(int id, RGE_Sprite** sprites,
                            RGE_Sound** sounds, int setup);
    RGE_Master_Static_Object(FILE* file, RGE_Sprite** sprites,
                            RGE_Sound** sounds, short index, int setup);

    char pad_04[0xB4];
};

class RGE_Master_Animated_Object : public RGE_Master_Static_Object {
public:
    RGE_Master_Animated_Object(int id, RGE_Sprite** sprites,
                               RGE_Sound** sounds, int setup);
    RGE_Master_Animated_Object(FILE* file, RGE_Sprite** sprites,
                               RGE_Sound** sounds, short index, int setup);

    char pad_04[4];
};

class RGE_Master_Moving_Object : public RGE_Master_Static_Object {
public:
    RGE_Master_Moving_Object(int id, RGE_Sprite** sprites,
                             RGE_Sound** sounds, int setup);
    RGE_Master_Moving_Object(FILE* file, RGE_Sprite** sprites,
                             RGE_Sound** sounds, short index, int setup);

    char pad_04[0x20];
};

class RGE_Master_Missile_Object : public RGE_Master_Static_Object {
public:
    RGE_Master_Missile_Object(int id, RGE_Sprite** sprites,
                              RGE_Sound** sounds, int setup);
    RGE_Master_Missile_Object(FILE* file, RGE_Sprite** sprites,
                              RGE_Sound** sounds, short index, int setup);

    char pad_04[0x9C];
};

class RGE_Master_Action_Object : public RGE_Master_Static_Object {
public:
    RGE_Master_Action_Object(int id, RGE_Sprite** sprites,
                             RGE_Sound** sounds, int setup);
    RGE_Master_Action_Object(FILE* file, RGE_Sprite** sprites,
                             RGE_Sound** sounds, short index, int setup);

    char pad_04[0x44];
};

class RGE_Master_Combat_Object : public RGE_Master_Static_Object {
public:
    RGE_Master_Combat_Object(int id, RGE_Sprite** sprites,
                             RGE_Sound** sounds, int setup);
    RGE_Master_Combat_Object(FILE* file, RGE_Sprite** sprites,
                             RGE_Sound** sounds, short index, int setup);

    char pad_04[0x90];
};

class RGE_Master_Doppleganger_Object : public RGE_Master_Static_Object {
public:
    RGE_Master_Doppleganger_Object(int id, RGE_Sprite** sprites,
                                   RGE_Sound** sounds, int setup);
    RGE_Master_Doppleganger_Object(FILE* file, RGE_Sprite** sprites,
                                   RGE_Sound** sounds, short index, int setup);

    char pad_04[4];
};

class RGE_Master_Player {
public:
    virtual ~RGE_Master_Player();
    virtual void finish_init(int fd, RGE_Sprite** sprites, RGE_Sound** sounds);
    virtual void load_master_object(int id, unsigned char type,
                                    RGE_Sprite** sprites, RGE_Sound** sounds,
                                    short index);
    virtual void create_master_object_space(short count);
    virtual void load_object(FILE* file, unsigned char type,
                             RGE_Sprite** sprites, RGE_Sound** sounds,
                             short index);
    virtual void save(int fd);

    char name[20];
    short master_object_num;
    unsigned char pad_1A[2];
    RGE_Master_Static_Object** master_objects;
    short attribute_num;
    unsigned char pad_22[2];
    float* attributes;
    unsigned char culture;
    unsigned char type;
    short tribe_effect;

    RGE_Master_Player(FILE* file);
    RGE_Master_Player(int fd);
};

#endif
