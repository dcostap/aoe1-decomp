// VA: 0040DE70 AIModuleMessage default ctor
// aimodule.cpp lines 68-70
// BINARY NOTE: The executable stores all zero-valued data fields before its vptr.
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
    int data1;
    int data2;
    int data3;
    AIModuleMessage* callbackMessage;
    int timeStamp;
    AIModuleMessage* next;
    AIModuleMessage* prev;

    AIModuleMessage();
};
#endif

AIModuleMessage::AIModuleMessage()
    : id(0),
      priority(0),
      sender((char*)0x57F4B0, 0),
      recipient((char*)0x57F4A4, 0),
      data1(0),
      data2(0),
      data3(0),
      callbackMessage(0),
      timeStamp(0),
      next(0),
      prev(0)
{
    strcpy(text, (char*)0x592A40);
}
