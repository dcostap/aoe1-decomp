extern "C" void __cdecl operator_delete(void* ptr);

#ifndef AIBOBJ_CONTEXT_READY
class BaseObject {
public:
    virtual ~BaseObject();

    char gap_04[0x08];
    int numberGroupsValue;
    int* groupIDValue;
    char gap_14[0x08];
    int gameIDValue;
};
#endif

BaseObject::~BaseObject() {
    operator_delete(groupIDValue);
}
