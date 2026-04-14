class Base_TRIBE_Master_Player {
public:
    virtual ~Base_TRIBE_Master_Player();
};

class TRIBE_Master_Player : public Base_TRIBE_Master_Player {
public:
    virtual ~TRIBE_Master_Player();
};

TRIBE_Master_Player::~TRIBE_Master_Player() {
}
