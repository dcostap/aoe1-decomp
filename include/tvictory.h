#ifndef AOE1_TVICTORY_H
#define AOE1_TVICTORY_H


#include "victory.h"

class TRIBE_Victory_Conditions : public RGE_Victory_Conditions {
public:
    TRIBE_Victory_Conditions(RGE_Player* player, int handle, long* version_map,
                             unsigned char version_flag);
    TRIBE_Victory_Conditions(RGE_Player* player);
    ~TRIBE_Victory_Conditions();
    virtual void handle_condition(RGE_Victory_Entry* entry);

protected:
    void handle_tech(RGE_Victory_Entry* entry);

public:
    unsigned char add_tech(unsigned char id, long count);
};

typedef char tribe_victory_conditions_size_check[
    (sizeof(TRIBE_Victory_Conditions) == 0x20) ? 1 : -1];

#endif
