// attempt 1: natural resend request sender/logging flow from asm

unsigned long debug_timeGetTime(char* file, int line);
void* operator new(unsigned int);
void operator delete(void*);

class TDebuggingLog { public: void Log(char* fmt, ...); };
extern TDebuggingLog* L;
extern int dco_id;
class Sender { public:
    virtual void vf00(); virtual void vf04(); virtual void vf08(); virtual void vf0c(); virtual void vf10(); virtual void vf14(); virtual void vf18(); virtual void vf1c();
    virtual void vf20(); virtual void vf24(); virtual void vf28(); virtual void vf2c(); virtual void vf30(); virtual void vf34(); virtual void vf38(); virtual void vf3c();
    virtual void vf40(); virtual void vf44(); virtual void vf48(); virtual void vf4c(); virtual void vf50(); virtual void vf54(); virtual void vf58(); virtual void vf5c(); virtual void vf60(); virtual void vf64();
    virtual int send(int dco, int to, int zero, void* msg, int size);
};
extern Sender* sender;

class TCommunications_Handler {
public:
    char gap_0000[0x12C0];
    int bytes_sent;
    char gap_12C4[0x13E4-0x12C4];
    unsigned int last_serial[10];
    unsigned int last_time[10];
    char gap_1434[0x1514-0x1434];
    unsigned char connected;
    char gap_1515[0x1564-0x1515];
    int player_dpid[10];
    int TXResendRequest(unsigned int serial, unsigned int player);
};

int TCommunications_Handler::TXResendRequest(unsigned int serial, unsigned int player) {
    if (!this->connected) {
        return 0;
    }
    unsigned long now = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\Com_hand.cpp", 3980);
    if (serial == this->last_serial[player]) {
        unsigned long elapsed = now - this->last_time[player];
        if (elapsed < 500) {
            return 0;
        }
    }
    this->last_serial[player] = serial;
    this->last_time[player] = now;
    char* msg = (char*)operator new(8);
    msg[0] = 0x58;
    *(unsigned int*)(msg + 4) = serial;
    L->Log("GTD: TX RESEND REQ to P#%d  Ser#%d ", player, serial);
    if (dco_id == 0) {
        L->Log("+++BAD DCOID=0 NO TX");
        return 0;
    }
    unsigned long sendStart = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\Com_hand.cpp", 4009);
    L->Log("  >TX RES REQ #%d %d (%d)", player, serial, 8);
    int to = this->player_dpid[player];
    Sender* s = sender;
    int ok = s->send(dco_id, to, 0, msg, 8);
    unsigned long elapsed2 = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\Com_hand.cpp", 4024) - sendStart;
    if (elapsed2 > 50) {
        L->Log("  TX RES REQ took %d", elapsed2);
    }
    operator delete(msg);
    if (ok == 0) {
        this->bytes_sent += 8;
        return 1;
    }
    return 0;
}
