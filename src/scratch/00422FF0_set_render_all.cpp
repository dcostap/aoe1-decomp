struct GlobalRenderObj {
    void invalidate_all();
};

extern GlobalRenderObj g_render_obj;

class RGE_Base_Game {
public:
    char gap_0[0x3F8];
    int render_all; // offset 0x3F8

    void set_render_all();
};

void RGE_Base_Game::set_render_all()
{
    this->render_all = 1;
    g_render_obj.invalidate_all();
}
