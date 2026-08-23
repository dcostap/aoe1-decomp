class TPanel;

#ifndef BASEGAME_GROUPED_TU
class RGE_Base_Game {
public:
    virtual TPanel * get_map_panel();
};
#endif

TPanel * RGE_Base_Game::get_map_panel() {
    return 0;
}
