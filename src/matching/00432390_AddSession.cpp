// Attempt log:
// - Earlier source used a 20-byte pseudo-GUID and an invented session layout; it
//   produced 336/342 bytes and did not own the observed offsets canonically.
// - Reconstructed from the exact SEs layout: 255-byte name/password fields,
//   two 16-byte GUIDs, and four distinct user fields in a 0x238-byte record.

#include <string.h>

#ifndef COM_SESS_TU_CONTEXT
struct GUID {
    unsigned int d[4];
};

class SEs {
public:
    char Name[255];
    char Password[255];
    unsigned char gap_1FE[2];
    GUID AppGUID;
    GUID SessGUID;
    unsigned long CurrentPlayers;
    unsigned long MaxPlayers;
    unsigned long User1;
    unsigned long User2;
    unsigned long User3;
    unsigned long User4;
};

class TCommunications_Sessions {
public:
    int SessionCount;
    SEs Session[501];

public:
    int AddSession(GUID sessGUID, GUID appGUID,
                   unsigned long maxPlayers, unsigned long currentPlayers,
                   char* name, char* password,
                   unsigned long user1, unsigned long user2,
                   unsigned long user3, unsigned long user4);
    int IncSessionCount();
};
#endif

int TCommunications_Sessions::AddSession(GUID sessGUID, GUID appGUID,
                                          unsigned long maxPlayers, unsigned long currentPlayers,
                                          char* name, char* password,
                                          unsigned long user1, unsigned long user2,
                                          unsigned long user3, unsigned long user4) {
    this->Session[SessionCount].AppGUID = appGUID;
    this->Session[SessionCount].SessGUID = sessGUID;
    this->Session[SessionCount].MaxPlayers = maxPlayers;
    this->Session[SessionCount].CurrentPlayers = currentPlayers;
    this->Session[SessionCount].User1 = user1;
    // The executable writes all four callback user values to User1; preserve
    // this observed original bug rather than normalizing the distinct fields.
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
