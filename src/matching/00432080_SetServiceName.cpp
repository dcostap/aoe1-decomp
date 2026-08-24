#ifndef COM_SERV_TU_CONTEXT
class SPs {
public:
    char Name[80];
    char gap_50[0x10];
};

class TCommunications_Services {
public:
    SPs Service[100];

    int SetServiceName(int serviceIndex, char* name);
};
#endif

extern "C" char* strcpy(char*, const char*);

int TCommunications_Services::SetServiceName(int serviceIndex, char* name) {
    strcpy(this->Service[serviceIndex].Name, name);
    return 1;
}
