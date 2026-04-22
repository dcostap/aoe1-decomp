class RGE_Game_World;
class TCommunications_Handler;

extern void* RGE_Command_vftable;

class RGE_Command {
public:
    void* vfptr;
    RGE_Game_World* world;
    void* last_order;
    int last_order_size;
    char gap_10[0x04];
    TCommunications_Handler* com_hand;

    RGE_Command(RGE_Game_World* world, TCommunications_Handler* com_hand);
};

RGE_Command::RGE_Command(RGE_Game_World* world, TCommunications_Handler* com_hand) {
    this->world = world;
    this->com_hand = com_hand;
    this->vfptr = &RGE_Command_vftable;
    this->last_order = 0;
    this->last_order_size = 0;
}
