// STATUS: scratch
// FLAGS: config\flags\004201A0_get_font.rsp

class RGE_Base_Game {
public:
    char gap_0[0x1E4];
    void* font_ptr; // offset 0x1E4

    void* get_font(int index);
};

void* RGE_Base_Game::get_font(int index)
{
    if (!this->font_ptr)
        return 0;
    return (char*)this->font_ptr + index * 12;
}
