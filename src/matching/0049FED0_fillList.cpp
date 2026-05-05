// attempt 2: reconstruct scr_mp service-list fill using automatic TCommunications_Services, inline strcpy/strcmp, and exact local layout sizes

#include <string.h>

class TTextPanel {
public:
    void empty_list();
    int append_line(char* line, long param);
    int append_line(long string_id, long param);
    long get_line(long index);
    void set_line(long line);
};

class TRegistry {
public:
    char* RegGetAscii(int key, char* name);
};

extern TRegistry* Regs;

class TCommunications_Services {
public:
    char data[0x2584];
    TCommunications_Services();
    ~TCommunications_Services();
    int GetServiceCount();
    int GetServiceActive(int index);
    char* GetServiceName(int index);
};

struct FindDataLocal {
    char data[0x118];
};

extern "C" long __cdecl _findfirst(char* filespec, FindDataLocal* fileinfo);

class TribeMPStartupScreen {
public:
    char gap_000[0x498];
    TTextPanel* list;
    int field_49C;
    char zone_exec[0xFF];
    char browser_exec[1];

    void fillList();
};

void TribeMPStartupScreen::fillList() {
    int lastServiceNumber;
    char lastServiceName[256];
    FindDataLocal file_info;

    this->list->empty_list();
    TCommunications_Services Serv;
    int serviceCount = Serv.GetServiceCount();

    lastServiceNumber = -1;
    if (Regs->RegGetAscii(1, "Default Age Of Empires Multiplayer Service")) {
        strcpy(lastServiceName, Regs->RegGetAscii(1, "Default Age Of Empires Multiplayer Service"));
    } else {
        strcpy(lastServiceName, "");
    }

    int i = 0;
    if (serviceCount > 0) {
        do {
            if (Serv.GetServiceActive(i) && Serv.GetServiceName(i)) {
                this->list->append_line(Serv.GetServiceName(i), i);
                if (strcmp(Serv.GetServiceName(i), lastServiceName) == 0) {
                    lastServiceNumber = i;
                }
            }
            i++;
        } while (i < serviceCount);
    }

    if (_findfirst(this->browser_exec, &file_info) != -1 && this->zone_exec[0]) {
        this->list->append_line(0x258E, -1);
    }

    if (lastServiceNumber != -1) {
        this->list->set_line(this->list->get_line(lastServiceNumber));
    }
}
