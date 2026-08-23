class MemberType {
public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void save_info(int param);
};

class TRIBE_Gaia {
public:
    char gap_0[0x34];
    MemberType* member_34;

    void save_info(int param);
};

void TRIBE_Gaia::save_info(int param) {
    this->member_34->save_info(param);
}
