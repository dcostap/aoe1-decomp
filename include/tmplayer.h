#ifndef AOE1_TMPLAYER_H
#define AOE1_TMPLAYER_H

#include "mst_play.h"
#include "tm_b_obj.h"
#include "tm_tre_o.h"

// tmplayer.cpp owns the derived master-player dispatch.
class TRIBE_Master_Player : public RGE_Master_Player {
public:
    virtual ~TRIBE_Master_Player();
    virtual void finish_init(int, RGE_Sprite**, RGE_Sound**);
    virtual void load_master_object(int, unsigned char, RGE_Sprite**,
                                    RGE_Sound**, short);
    virtual void create_master_object_space(short);
    virtual void load_object(FILE*, unsigned char, RGE_Sprite**, RGE_Sound**,
                             short);
    virtual void save(int);

    TRIBE_Master_Player(FILE*);
    TRIBE_Master_Player(int);
};

typedef char tribe_master_player_size_check[
    (sizeof(TRIBE_Master_Player) == 0x2C) ? 1 : -1];

#endif  // AOE1_TMPLAYER_H
