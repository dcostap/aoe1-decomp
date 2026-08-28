#ifndef AOE1_COM_SESS_H
#define AOE1_COM_SESS_H

#include "com_hand.h"

struct SEs {
    char Name[255];
    char Password[255];
    unsigned char Reserved[2];
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
    GUID glpGuid;
    IDirectPlay2* glpIDC;

    TCommunications_Sessions(TCommunications_Handler* handler);
    ~TCommunications_Sessions();

private:
    void EraseInformation();

public:
    int GetSessionCount();
    char* GetSessionName(int index);
    unsigned long GetSessionMaxPlayers(int index);
    unsigned long GetSessionCurrentPlayers(int index);
    GUID* GetSessionGUID(int index);
    int IncSessionCount();
    int AddSession(GUID sessGUID, GUID appGUID,
                   unsigned long maxPlayers, unsigned long currentPlayers,
                   char* name, char* password,
                   unsigned long user1, unsigned long user2,
                   unsigned long user3, unsigned long user4);
    int Refresh();
    int IsEqualGuid(GUID* guid1, GUID* guid2);
};

extern IDirectPlay3* glpSERV;
extern GUID gServGUID;
extern GUID gAppGUID;
extern TCommunications_Handler* g_com_handler;

int __stdcall EnumSessionCallback(DPSESSIONDESC2* desc,
                                   unsigned long* timeout,
                                   unsigned long flags,
                                   void* context);

typedef char com_sess_guid_size_check[(sizeof(GUID) == 0x10) ? 1 : -1];
typedef char com_sess_entry_size_check[(sizeof(SEs) == 0x238) ? 1 : -1];
typedef char com_sess_desc_size_check[(sizeof(DPSESSIONDESC2) == 0x50) ? 1 : -1];
typedef char com_sess_size_check[(sizeof(TCommunications_Sessions) == 0x457B0) ? 1 : -1];

#endif
