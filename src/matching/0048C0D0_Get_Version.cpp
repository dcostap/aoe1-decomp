extern float g_version;

class TComm_System {
public:
    float Get_Version();
};

float TComm_System::Get_Version() {
    return g_version;
}
