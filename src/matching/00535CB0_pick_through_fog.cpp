#ifndef RGE_VIEW_SHARED_CONTEXT
class RGE_View {
public:
    virtual ~RGE_View();
    int pick_through_fog(int p0);
};
#endif

int RGE_View::pick_through_fog(int p0) { return 0; }
