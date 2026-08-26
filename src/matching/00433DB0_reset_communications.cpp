#ifndef COMMAND_TU_CONTEXT
class TCommunications_Handler;

class RGE_Command {
public:
    virtual ~RGE_Command();
    char gap_0[0x10];
    TCommunications_Handler* field_14;
    void reset_communications(TCommunications_Handler* v);
};
#endif

// BINARY NOTE: Command.cpp passes TCommunications_Handler* at this owner.
void RGE_Command::reset_communications(TCommunications_Handler* v) {
#ifdef COMMAND_TU_CONTEXT
    this->com_hand = v;
#else
    this->field_14 = v;
#endif
}
