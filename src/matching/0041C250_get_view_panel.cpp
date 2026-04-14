class TPanel;

class RGE_Base_Game {
public:
    virtual TPanel * get_view_panel();
};

TPanel * RGE_Base_Game::get_view_panel() {
    return 0;
}
