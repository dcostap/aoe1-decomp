#ifndef BASEGAME_GROUPED_TU
class RGE_Base_Game {
public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual char* get_string2(int p1, long p2, long p3, char* buf, int maxlen);

    char* get_string(int p1, long p2, char* buf, int maxlen);
};
#endif

char* RGE_Base_Game::get_string(int p1, long p2, char* buf, int maxlen)
{
    return this->get_string2(p1, p2, 0, buf, maxlen);
}
