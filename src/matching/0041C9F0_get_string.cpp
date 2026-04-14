// STATUS: scratch
// FLAGS: config\flags\0041C9F0_get_string.rsp

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
    virtual void vf28(int p1, int p2, int p3, char* buf, int maxlen);

    void get_string(int p1, int p2, char* buf, int maxlen);
};

void RGE_Base_Game::get_string(int p1, int p2, char* buf, int maxlen)
{
    this->vf28(p1, p2, 0, buf, maxlen);
}
