// VA: 0040DE70 AIModuleMessage default ctor
// aimodule.cpp lines 68-70

#include <string.h>

class AIModuleID {
public:
    AIModuleID(char* str, int param);
    ~AIModuleID();
    char gap_00[0x48];
};

class __declspec(novtable) AIModuleMessage {
public:
    void* vptr;
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

AIModuleMessage::AIModuleMessage()
    : id(0), priority(0), sender((char*)0x57F4B0, 0), recipient((char*)0x57F4A4, 0)
{
    data1 = 0;
    data2 = 0;
    data3 = 0;
    callbackMessage = 0;
    timeStamp = 0;
    next = 0;
    prev = 0;
    *(int*)this = 0x56E92C;
    strcpy(text, (char*)0x592A40);
}
