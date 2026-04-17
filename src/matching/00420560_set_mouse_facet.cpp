struct RenderSystem {
    void set_mouse_facet(long param);
};

class RGE_Base_Game {
public:
    char gap_0[0x1C0];
    RenderSystem* render_sys; // offset 0x1C0

    void set_mouse_facet(long param);
};

void RGE_Base_Game::set_mouse_facet(long param)
{
    this->render_sys->set_mouse_facet(param);
}
