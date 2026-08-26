// VA: 0040E030 AIModuleMessage::AIModuleMessage(AIModuleMessage*) copy ctor
// aimodule.cpp lines 103-105
// FLAGS: /GX
// retry: full copy-constructor surface with AIModuleID member ctors, visible dtors for EH, and setText(other->text).
// BINARY NOTE: The executable copies data fields and links before its vptr.
// The initializer list preserves that VC5 constructor order in the authentic TU.

#ifndef AOE1_AIMODULE_TU_CONTEXT
class AIModuleID {
public:
    char gap_00[4];
    int id;
    char name[0x40];

    AIModuleID(char* str, int param);
    ~AIModuleID();
};

class AIModuleMessage {
public:
    virtual ~AIModuleMessage();
    int id;
    char text[0x80];
    int priority;
    AIModuleID sender;
    AIModuleID recipient;
    long data1;
    long data2;
    long data3;
    AIModuleMessage* callbackMessage;
    int timeStamp;
    AIModuleMessage* next;
    AIModuleMessage* prev;

    AIModuleMessage(AIModuleMessage* other);
    void setText(char* text);
};
#endif

AIModuleMessage::AIModuleMessage(AIModuleMessage* other)
    : id(other->id),
      priority(other->priority),
      sender(other->sender.name, other->sender.id),
      recipient(other->recipient.name, other->recipient.id),
      data1(other->data1),
      data2(other->data2),
      data3(other->data3),
      callbackMessage(other->callbackMessage),
      timeStamp(other->timeStamp),
      next(0),
      prev(0)
{
    this->setText(other->text);
}
