#ifndef AOE1_TPLAYER_TU_SHARED_CONTEXT
class RGE_Player {
public:
    virtual void update_dopplegangers();
};

class TRIBE_Player : public RGE_Player {
public:
    void update_dopplegangers();
};
#endif

void TRIBE_Player::update_dopplegangers() { RGE_Player::update_dopplegangers(); }
