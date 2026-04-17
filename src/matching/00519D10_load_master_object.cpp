class RGE_Sprite;
class RGE_Sound;

class TRIBE_Player_lmo {
public:
    void load_master_object(int a, short b, unsigned char c, RGE_Sprite** d, RGE_Sound** e);
};

class TRIBE_Gaia_lmo : public TRIBE_Player_lmo {
public:
    void load_master_object(int a, short b, unsigned char c, RGE_Sprite** d, RGE_Sound** e);
};

void TRIBE_Gaia_lmo::load_master_object(int a, short b, unsigned char c, RGE_Sprite** d, RGE_Sound** e) {
    ((TRIBE_Player_lmo*)this)->load_master_object(a, b, c, d, e);
}
