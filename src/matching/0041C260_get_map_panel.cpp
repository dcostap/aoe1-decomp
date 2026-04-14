class TPanel;

class RGE_Base_Game {
public:
    virtual TPanel * get_map_panel();
};

TPanel * RGE_Base_Game::get_map_panel() {
    return 0;
}
