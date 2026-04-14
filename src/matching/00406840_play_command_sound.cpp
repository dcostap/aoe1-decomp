struct SoundMember {
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
};

class RGE_Action_Object {
public:
    char gap_0[8];
    SoundMember *sound;
    void play_command_sound();
};

void RGE_Action_Object::play_command_sound() {
    this->sound->vf2C();
}
