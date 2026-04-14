// STATUS: scratch
// FLAGS: config\flags\0041C9A0_get_string.rsp

static char g_string_buffer[0x200];

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
    virtual void vf20(long id, char* buf, int maxlen);

    char* get_string(long id);
};

char* RGE_Base_Game::get_string(long id)
{
    this->vf20(id, g_string_buffer, 0x200);
    return g_string_buffer;
}
