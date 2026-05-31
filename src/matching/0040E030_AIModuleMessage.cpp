// VA: 0040E030 AIModuleMessage::AIModuleMessage(AIModuleMessage*) copy ctor
// aimodule.cpp lines 103-105
// FLAGS: /GX
// retry: full copy-constructor surface with AIModuleID member ctors, visible dtors for EH, and setText(other->text).

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
    void* vtable_ptr;
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

AIModuleMessage::AIModuleMessage(AIModuleMessage* other)
    : id(other->id),
      priority(other->priority),
      sender(other->sender.name, other->sender.id),
      recipient(other->recipient.name, other->recipient.id)
{
    this->data1 = other->data1;
    this->data2 = other->data2;
    this->data3 = other->data3;
    this->callbackMessage = other->callbackMessage;
    this->timeStamp = other->timeStamp;
    this->next = 0;
    this->prev = 0;
    this->vtable_ptr = (void*)0x56E92C;
    this->setText(other->text);
}
