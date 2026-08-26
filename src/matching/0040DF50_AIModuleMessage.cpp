// VA: 0040DF50 AIModuleMessage::AIModuleMessage(int,int,int,int,long,long,long,AIModuleMessage*,int)
// aimodule.cpp lines 85-87
// FLAGS: /GX
// retry: full nine-parameter constructor surface from packet; model two AIModuleID member ctors and trailing empty-string copy.
// BINARY NOTE: The executable stores the scalar and pointer arguments before its vptr.
// The initializer list preserves that VC5 constructor order in the authentic TU.

#include <string.h>

#ifndef AOE1_AIMODULE_TU_CONTEXT
class AIModuleID {
public:
    AIModuleID(char* str, int param);
    ~AIModuleID();
    char gap_00[0x48];
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

    AIModuleMessage(int sender_id, int recipient_id, int msg_id, int msg_priority,
                    long p5, long p6, long p7, AIModuleMessage* callback, int timestamp);
};
#endif

AIModuleMessage::AIModuleMessage(int sender_id, int recipient_id, int msg_id, int msg_priority,
                                 long p5, long p6, long p7, AIModuleMessage* callback, int timestamp)
    : id(msg_id),
      priority(msg_priority),
      sender((char*)0x592A40, sender_id),
      recipient((char*)0x592A40, recipient_id),
      data1(p5),
      data2(p6),
      data3(p7),
      callbackMessage(callback),
      timeStamp(timestamp)
{
    strcpy(this->text, (char*)0x592A40);
}
