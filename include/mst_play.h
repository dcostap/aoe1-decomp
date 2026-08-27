#ifndef AOE1_MST_PLAY_H
#define AOE1_MST_PLAY_H

#include <stdio.h>

class RGE_Master_Static_Object;
class RGE_Sprite;
class RGE_Sound;

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
    RGE_Master_Static_Object** master_objects;
    short attribute_num;
    float* attributes;
    unsigned char culture;
    unsigned char type;
    short tribe_effect;

    RGE_Master_Player(FILE* file);
    RGE_Master_Player(int fd);
};

typedef char mst_play_master_player_size[
    (sizeof(RGE_Master_Player) == 0x2C) ? 1 : -1];

#endif  // AOE1_MST_PLAY_H
