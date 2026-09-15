#ifndef AOE1_TMPLAYER_H
#define AOE1_TMPLAYER_H

#include "mst_play.h"
#include "tm_b_obj.h"
#include "tm_tre_o.h"

// tmplayer.cpp owns the derived master-player dispatch.
class TRIBE_Master_Player : public RGE_Master_Player {
public:
    virtual ~TRIBE_Master_Player();
    virtual void load_master_object(int infile, unsigned char obj_type,
                                    RGE_Sprite** sprites, RGE_Sound** sounds,
                                    short index);
    virtual void load_object(FILE* infile, unsigned char obj_type,
                             RGE_Sprite** sprites, RGE_Sound** sounds,
                             short index);

    TRIBE_Master_Player(FILE* infile);
    TRIBE_Master_Player(int infile);
};

typedef char tribe_master_player_size_check[
    (sizeof(TRIBE_Master_Player) == 0x2C) ? 1 : -1];

#endif  // AOE1_TMPLAYER_H
