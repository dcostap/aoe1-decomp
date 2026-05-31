// VA: 00414F70 UnitAIModule::notifyCommander(int,int,int,long,long,long)
// aiuaimod.cpp
// attempt 1: packet-grounded natural UnitAIModule/RGE_Static_Object surfaces, padded virtual slots for NotifyEvent (+0xD0) and owner notify (+0xE8).

struct NotifyEvent {
    int recipient;
    int mType;
    int p1;
    long p2;
    long p3;
    long p4;
};

class UnitAIModule;
class RGE_Player;

class RGE_Static_Object {
public:
    virtual void v00();
    int id;                         // +0x04
    char gap_08[4];                 // +0x08
    RGE_Player* owner;              // +0x0C
    char gap_10[0x48 - 0x10];
    unsigned char object_state;     // +0x48
    char gap_49[0x78 - 0x49];
    int groupCommanderValue;        // +0x78

    int inGroup();
    UnitAIModule* unitAI();
};

class RGE_Player {
public:
    virtual void p00(); virtual void p01(); virtual void p02(); virtual void p03();
    virtual void p04(); virtual void p05(); virtual void p06(); virtual void p07();
    virtual void p08(); virtual void p09(); virtual void p10(); virtual void p11();
    virtual void p12(); virtual void p13(); virtual void p14(); virtual void p15();
    virtual void p16(); virtual void p17(); virtual void p18(); virtual void p19();
    virtual void p20(); virtual void p21(); virtual void p22(); virtual void p23();
    virtual void p24(); virtual void p25(); virtual void p26(); virtual void p27();
    virtual void p28(); virtual void p29(); virtual void p30(); virtual void p31();
    virtual void p32(); virtual void p33(); virtual void p34(); virtual void p35();
    virtual void p36(); virtual void p37(); virtual void p38(); virtual void p39();
    virtual void p40(); virtual void p41(); virtual void p42(); virtual void p43();
    virtual void p44(); virtual void p45(); virtual void p46(); virtual void p47();
    virtual void p48(); virtual void p49(); virtual void p50(); virtual void p51();
    virtual void p52(); virtual void p53(); virtual void p54(); virtual void p55();
    virtual void p56(); virtual void p57();
    virtual void notifyCommander(int a1, int a2, int a3, long a4, long a5, long a6); // +0xE8
};

class UnitAIModule {
public:
    virtual void u00(); virtual void u01(); virtual void u02(); virtual void u03();
    virtual void u04(); virtual void u05(); virtual void u06(); virtual void u07();
    virtual void u08(); virtual void u09(); virtual void u10(); virtual void u11();
    virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15();
    virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19();
    virtual void u20(); virtual void u21(); virtual void u22(); virtual void u23();
    virtual void u24(); virtual void u25(); virtual void u26(); virtual void u27();
    virtual void u28(); virtual void u29(); virtual void u30(); virtual void u31();
    virtual void u32(); virtual void u33(); virtual void u34(); virtual void u35();
    virtual void u36(); virtual void u37(); virtual void u38(); virtual void u39();
    virtual void u40(); virtual void u41(); virtual void u42(); virtual void u43();
    virtual void u44(); virtual void u45(); virtual void u46(); virtual void u47();
    virtual void u48(); virtual void u49(); virtual void u50(); virtual void u51();
    virtual void notifyCommander(NotifyEvent* ev); // +0xD0

    RGE_Static_Object* objectValue; // +0x04

    RGE_Static_Object* lookupObject(int id);
    int notifyCommander(int a1, int a2, int a3, long a4, long a5, long a6);
};

int UnitAIModule::notifyCommander(int a1, int a2, int a3, long a4, long a5, long a6)
{
    NotifyEvent nEvent;

    if (this->objectValue->inGroup() == 1) {
        nEvent.recipient = a1;
        nEvent.mType = a2;
        nEvent.p1 = a3;
        nEvent.p2 = a4;
        nEvent.p3 = a5;
        nEvent.p4 = a6;

        RGE_Static_Object* obj = this->objectValue;
        int commander = obj->groupCommanderValue;
        if (obj->id == commander) {
            this->notifyCommander(&nEvent);
        } else {
            RGE_Static_Object* commanderObj = this->lookupObject(commander);
            if (commanderObj != 0) {
                if (commanderObj->unitAI() != 0) {
                    commanderObj->unitAI()->notifyCommander(&nEvent);
                }
            }
        }
    }

    this->objectValue->owner->notifyCommander(a1, a2, a3, a4, a5, a6);
    return 1;
}
