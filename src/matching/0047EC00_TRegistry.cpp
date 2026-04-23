extern "C" __declspec(dllimport) long __stdcall RegCloseKey(void* key);


class TRegistry {
public:
    void* ghMachineKey;
    void* ghUserKey;
    void* ghMachineKeyRead;
    unsigned long gdwDisp;
    char Data[255];

    ~TRegistry();
};

TRegistry::~TRegistry() {
    long (__stdcall *closeKey)(void*) = RegCloseKey;

    if (this->ghUserKey != 0) {
        closeKey(this->ghUserKey);
        this->ghUserKey = 0;
    }
    if (this->ghMachineKey != 0) {
        closeKey(this->ghMachineKey);
        this->ghMachineKey = 0;
    }
    if (this->ghMachineKeyRead != 0) {
        closeKey(this->ghMachineKeyRead);
        this->ghMachineKeyRead = 0;
    }
}
