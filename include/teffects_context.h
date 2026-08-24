#ifndef AOE1_TEFFECTS_CONTEXT_H
#define AOE1_TEFFECTS_CONTEXT_H

// Authentic source-module context for C:\\msdev\\work\\age1_x1\\teffects.cpp.
// The complete RGE_Effects surface is required before the TRIBE_Effects owners.

class RGE_Player {
};

class TRIBE_Player : public RGE_Player {
public:
    void tech_abling(long tech_value, unsigned char enable);
};

class RGE_Effect;

class RGE_Effects {
public:
    virtual ~RGE_Effects();
    virtual void save(int file);
    virtual void do_effect(short effect_id, RGE_Player* player);

    RGE_Effect* effects;
    long effect_num;

    RGE_Effects(int file);
    RGE_Effects(char* path);
};

class TRIBE_Effects : public RGE_Effects {
public:
    virtual ~TRIBE_Effects();
    virtual void save(int file);
    virtual void do_effect(short effect_id, RGE_Player* player);

    TRIBE_Effects(int file);
    TRIBE_Effects(char* path);
    void do_tech_effect(short effect_id, RGE_Player* player);
};

typedef char teffects_rge_effects_size_check[
    (sizeof(RGE_Effects) == 0x0C) ? 1 : -1];
typedef char teffects_tribe_effects_size_check[
    (sizeof(TRIBE_Effects) == 0x0C) ? 1 : -1];

#endif
