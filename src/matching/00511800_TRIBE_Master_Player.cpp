class BaseClass {
public:
    virtual ~BaseClass();
    BaseClass(int param);
};

class TRIBE_Master_Player : public BaseClass {
public:
    char gap_4[0x25];
    unsigned char field_29;

    TRIBE_Master_Player(int param);
};

TRIBE_Master_Player::TRIBE_Master_Player(int param) : BaseClass(param) {
    this->field_29 = 1;
}
