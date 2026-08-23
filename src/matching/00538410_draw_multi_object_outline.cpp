#ifndef RGE_VIEW_SHARED_CONTEXT
class RGE_View {
public:
    virtual ~RGE_View();
    void draw_multi_object_outline();
};
#endif

void RGE_View::draw_multi_object_outline() {}
