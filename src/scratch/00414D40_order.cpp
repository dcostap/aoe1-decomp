// VA: 00414D40 UnitAIModule::order(int,int,int,int,float,float,float,float,int,int,int)
// aiuaimod.cpp
// attempt 1: packet-grounded natural order handling, direct addToOrderQueue calls, padded virtual slots for stop/process queue.
// attempt 2: block-scoped orderType and negative object-state guard; no codegen change.
// attempt 3: explicit else for the p9!=0 block; no codegen change.
// current best: exact size and 10.46% edit diff, but VC5 saves EDI at function entry while original delays push edi until the p9!=0 path.

class RGE_Static_Object;

extern void* actionFile;
extern int fprintf(void* file, const char* fmt, ...);
extern const char str_fmt_stopObject[];
extern const char str_aiuaimod_path[];

class RGE_Static_Object {
public:
    virtual void v00();
    int id;                         // +0x04
    char gap_08[0x48 - 0x08];
    unsigned char object_state;     // +0x48
};

class UnitAIModule {
public:
    virtual void u00(); virtual void u01(); virtual void u02(); virtual void u03();
    virtual void u04(); virtual void u05(); virtual void u06(); virtual void u07();
    virtual void u08(); virtual void u09(); virtual void u10(); virtual void u11();
    virtual void u12(); virtual void u13(); virtual void u14(); virtual void u15();
    virtual void u16(); virtual void u17(); virtual void u18(); virtual void u19();
    virtual void u20(); virtual void u21();
    virtual void stopObject(int flag); // +0x58
    virtual void u23(); virtual void u24(); virtual void u25(); virtual void u26();
    virtual void u27(); virtual void u28(); virtual void u29(); virtual void u30();
    virtual void u31(); virtual void u32(); virtual void u33(); virtual void u34();
    virtual void u35(); virtual void u36(); virtual void u37(); virtual void u38();
    virtual void u39(); virtual void u40(); virtual void u41(); virtual void u42();
    virtual void u43(); virtual void u44(); virtual void u45(); virtual void u46();
    virtual void u47(); virtual void u48(); virtual void u49();
    virtual void processOrderQueue(int queue, int flag); // +0xC8

    RGE_Static_Object* objectValue;  // +0x04
    char gap_08[0x18 - 0x08];
    int orderQueueValue;             // +0x18
    char gap_1C[0x28 - 0x1C];
    int currentOrderValue;           // +0x28
    int currentOrderPriorityValue;   // +0x2C
    char gap_30[0x34 - 0x30];
    int currentTargetValue;          // +0x34
    char gap_38[0x3C - 0x38];
    float currentTargetXValue;       // +0x3C
    float currentTargetYValue;       // +0x40
    float currentTargetZValue;       // +0x44
    float desiredTargetDistanceValue;// +0x48

    int addToOrderQueue(int p1, int p2, int p3, int p4, float p5, float p6, float p7, float p8, int p9, int p10);
    void removeCurrentTarget();
    void purgeNotifyQueue(unsigned long flags);
    int order(int p1, int p2, int p3, int p4, float p5, float p6, float p7, float p8, int p9, int p10, int p11);
};

int UnitAIModule::order(int p1, int p2, int p3, int p4, float p5, float p6, float p7, float p8, int p9, int p10, int p11)
{
    if (this->objectValue->object_state > 2)
        return 1;

    if (p9 == 0) {
        this->addToOrderQueue(p1, p2, p3, p4, p5, p6, p7, p8, p10, p11);
        return 1;
    } else {
        int orderType;

        if (p10 == 1) {
            this->addToOrderQueue(this->objectValue->id,
                                  this->currentOrderValue,
                                  this->currentTargetValue,
                                  -1,
                                  this->currentTargetXValue,
                                  this->currentTargetYValue,
                                  this->currentTargetZValue,
                                  this->desiredTargetDistanceValue,
                                  1,
                                  this->currentOrderPriorityValue);
        }

        orderType = p2;
        this->addToOrderQueue(p1, orderType, p3, p4, p5, p6, p7, p8, 1, p11);

        if (orderType != 0x2D9) {
            this->removeCurrentTarget();
            if (actionFile != 0) {
                int id;
                if (this->objectValue != 0)
                    id = this->objectValue->id;
                else
                    id = -1;
                fprintf(actionFile, str_fmt_stopObject, id, str_aiuaimod_path, 0x6F3);
            }
            this->stopObject(1);
        }

        this->purgeNotifyQueue(0);
        this->processOrderQueue(this->orderQueueValue, 0);
    }
    return 1;
}
