struct GlobalRenderObj {
    void invalidate_all();
};

extern GlobalRenderObj g_render_obj;


void RGE_Base_Game::set_render_all()
{
    this->render_all = 1;
    g_render_obj.invalidate_all();
}
