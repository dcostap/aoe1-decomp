// VA: 0046B270 PathingSystem::~PathingSystem (148B)
// pathsys.cpp lines 142-144
// EH frame (/GX)

#ifndef PATHSYS_TU_CONTEXT
void operator delete(void* ptr);

class IntList {
public:
    void* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;
    ~IntList()
    {
        if (this->value != 0) {
            operator delete(this->value);
            this->value = 0;
        }
        this->numberValue = 0;
        this->desiredNumberValue = 0;
        this->maximumSizeValue = 0;
    }
};

class PathingSystem {
public:
    virtual ~PathingSystem();
    char gap_04[0x11DC64 - 4];
    IntList initialCollidingObjects; // +0x11DC64
    char gap_11DC74[0x70];
    IntList currentUnobstructibles;  // +0x11DCE4
};
#endif

PathingSystem::~PathingSystem()
{
}
