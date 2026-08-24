#ifndef RGE_MAC_OBJ_SHARED_CONTEXT
class RGE_Sound {
public:
    void play(int mode);
};

class RGE_Master_Action_Object {
public:
    RGE_Sound* command_sound;
    void play_command_sound();
};
#endif

void RGE_Master_Action_Object::play_command_sound() {
    if (this->command_sound) {
        this->command_sound->play(1);
    }
}
