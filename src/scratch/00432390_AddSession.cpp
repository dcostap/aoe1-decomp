// attempt 1: 336/342 bytes (6 short) - struct GUID copy + normal User1-4 fields
// attempt 2: explicit redundant User stores to match original's 4 writes to same offset

#include <string.h>

struct GUID {
    unsigned int Data1;
    unsigned int Data2;
    unsigned int Data3;
    unsigned int Data4_0, Data4_1;
};

class TCommunications_Sessions {
public:
    int SessionCount;
    char gap_04[0x257C];

    struct Session {
        GUID SessGUID;
        GUID AppGUID;
        char Name[160];
        char Password[46];
        unsigned int CurrentPlayers;
        unsigned int MaxPlayers;
        unsigned int User1, User2, User3, User4;
    };

    Session Session[100];

public:
    int AddSession(const GUID& sessGUID, const GUID& appGUID,
                   unsigned long maxPlayers, unsigned long currentPlayers,
                   char* name, char* password,
                   unsigned long user1, unsigned long user2,
                   unsigned long user3, unsigned long user4);
    int IncSessionCount();
};

int TCommunications_Sessions::AddSession(const GUID& sessGUID, const GUID& appGUID,
                                          unsigned long maxPlayers, unsigned long currentPlayers,
                                          char* name, char* password,
                                          unsigned long user1, unsigned long user2,
                                          unsigned long user3, unsigned long user4) {
    this->Session[SessionCount].SessGUID = sessGUID;
    this->Session[SessionCount].AppGUID = appGUID;
    this->Session[SessionCount].MaxPlayers = maxPlayers;
    this->Session[SessionCount].CurrentPlayers = currentPlayers;
    this->Session[SessionCount].User1 = user1;
    this->Session[SessionCount].User1 = user2;
    this->Session[SessionCount].User1 = user3;
    this->Session[SessionCount].User1 = user4;

    if (name) {
        strcpy(this->Session[SessionCount].Name, name);
    }
    if (password) {
        strcpy(this->Session[SessionCount].Password, password);
    }

    IncSessionCount();
    return 1;
}
