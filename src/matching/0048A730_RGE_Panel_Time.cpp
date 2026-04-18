class RGE_Panel_Time {
public:
    void parent_destroy();
    void destroy();
};

void RGE_Panel_Time::destroy() {
    this->parent_destroy();
}
