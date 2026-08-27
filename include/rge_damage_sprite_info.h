#ifndef AOE1_RGE_DAMAGE_SPRITE_INFO_H
#define AOE1_RGE_DAMAGE_SPRITE_INFO_H

// Owner-only record used by the m_s_obj and stat_obj consumers.
class RGE_Sprite;

class RGE_Damage_Sprite_Info {
public:
    RGE_Sprite* sprite;
    unsigned char damage_percent;
    unsigned char flag;
};

typedef char rge_damage_sprite_info_size_check[
    (sizeof(RGE_Damage_Sprite_Info) == 0x8) ? 1 : -1];

#endif
