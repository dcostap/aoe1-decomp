#ifndef AOE1_TVICTORY_H
#define AOE1_TVICTORY_H

#include "victory.h"

class TRIBE_Victory_Conditions : public RGE_Victory_Conditions {
  public:
    TRIBE_Victory_Conditions(RGE_Player* in_player, int infile, long* player_id_hash, unsigned char version_control);
    TRIBE_Victory_Conditions(RGE_Player* in_Player);
    ~TRIBE_Victory_Conditions();
    virtual void handle_condition(RGE_Victory_Entry* node);

  protected:
    void handle_tech(RGE_Victory_Entry* node);

  public:
    unsigned char add_tech(unsigned char v_group, long tech_id);
};

typedef char tribe_victory_conditions_size_check[(sizeof(TRIBE_Victory_Conditions) == 0x20) ? 1 : -1];

#endif
