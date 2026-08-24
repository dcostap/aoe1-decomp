#ifndef AIBOBJ_CONTEXT_READY
class BaseObject {
public:
    virtual ~BaseObject();
    char gap_04[0x1C];
    char name_arr[1];

    char * name();
};
#endif

char * BaseObject::name() {
    return this->name_arr;
}
