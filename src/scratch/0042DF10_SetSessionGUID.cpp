struct GUID_loc3 {
    int a; int b; int c; int d;
};

class TCommunications_Handler_sssg {
public:
    void SetSessionGUID(int a, int b, int c, int d);
    char gap_00[0x12FC];
    GUID_loc3 sess_guid;
};

void TCommunications_Handler_sssg::SetSessionGUID(int a, int b, int c, int d) {
    this->sess_guid.a = a;
    this->sess_guid.b = b;
    this->sess_guid.c = c;
    this->sess_guid.d = d;
}
