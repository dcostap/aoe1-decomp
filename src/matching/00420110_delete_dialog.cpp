struct VBase {
    virtual void scalar_deleting_destructor(int flag);
};

class RGE_Base_Game {
public:
    void delete_dialog(VBase** p);
};

void RGE_Base_Game::delete_dialog(VBase** p)
{
    if (*p) {
        (*p)->scalar_deleting_destructor(1);
        *p = 0;
    }
}
