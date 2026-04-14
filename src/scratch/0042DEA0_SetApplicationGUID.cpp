struct GUID_local {
    int a; int b; int c; int d;
};

class TCommunications_Handler_sag {
public:
    void SetApplicationGUID(int a, int b, int c, int d);
    char gap_00[0x12EC];
    GUID_local app_guid;
};

void TCommunications_Handler_sag::SetApplicationGUID(int a, int b, int c, int d) {
    this->app_guid.a = a;
    this->app_guid.b = b;
    this->app_guid.c = c;
    this->app_guid.d = d;
}
