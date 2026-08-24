extern "C" void* actionFile;
extern "C" int fprintf(void* stream, const char* format, ...);

#ifndef RGE_COM_OBJ_SHARED_CONTEXT
class UnitAIModule {
public:
    virtual void slot_00();
    virtual void slot_04();
    virtual void slot_08();
    virtual void slot_0C();
    virtual void slot_10();
    virtual void slot_14();
    virtual void slot_18();
    virtual void slot_1C();
    virtual void slot_20();
    virtual void slot_24();
    virtual void slot_28();
    virtual void slot_2C();
    virtual void slot_30();
    virtual void slot_34();
    virtual void slot_38();
    virtual void slot_3C();
    virtual void slot_40();
    virtual void slot_44();
    virtual void slot_48();
    virtual void slot_4C();
    virtual void slot_50();
    virtual void slot_54();
    virtual void stop(int force);
};

class RGE_Action_Object {
public:
    virtual void stop();
};

class RGE_Combat_Object : public RGE_Action_Object {
public:
    int id;
    unsigned char gap_08[0x6C];
    UnitAIModule* unitAIValue;

    virtual void stop();
};
#endif

void RGE_Combat_Object::stop() {
    RGE_Action_Object::stop();
    if (unitAIValue != 0) {
        if (actionFile != 0) {
            fprintf(actionFile, "#%d call stopObject %s %d\n", id, "C:\\msdev\\work\\age1_x1\\com_obj.cpp", 0xAB);
        }
        unitAIValue->stop(1);
    }
}
