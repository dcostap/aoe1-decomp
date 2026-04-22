extern void* TRIBE_Command_vftable;

class RGE_Command {
public:
    RGE_Command(void* world, void* com_hand);
};

class TRIBE_Command : public RGE_Command {
public:
    void* vfptr;
    TRIBE_Command(void* world, void* com_hand);
};

TRIBE_Command::TRIBE_Command(void* world, void* com_hand) : RGE_Command(world, com_hand) {
    this->vfptr = &TRIBE_Command_vftable;
}
