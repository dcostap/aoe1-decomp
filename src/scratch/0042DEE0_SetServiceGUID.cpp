struct GUID_loc2 {
    int a; int b; int c; int d;
};

class TCommunications_Handler_ssg {
public:
    void SetServiceGUID(int a, int b, int c, int d);
    char gap_00[0x12DC];
    GUID_loc2 svc_guid;
};

void TCommunications_Handler_ssg::SetServiceGUID(int a, int b, int c, int d) {
    this->svc_guid.a = a;
    this->svc_guid.b = b;
    this->svc_guid.c = c;
    this->svc_guid.d = d;
}
