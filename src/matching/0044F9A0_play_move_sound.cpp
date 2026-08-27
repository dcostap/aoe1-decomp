#ifndef RGE_MAC_OBJ_SHARED_CONTEXT
class RGE_Sound {
public:
    void play(int mode);
};

class RGE_Master_Action_Object {
public:
    RGE_Sound* move_sound;
    void play_move_sound();
};
#endif

void RGE_Master_Action_Object::play_move_sound() {
    if (this->move_sound) {
        this->move_sound->play(1);
    }
}
