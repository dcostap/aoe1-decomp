#ifndef AOE1_DIRECTPLAY4A_CONTEXT_H
#define AOE1_DIRECTPLAY4A_CONTEXT_H

// DirectPlay caller surface used by Com_hand.cpp.
// Executable call sites prove GetMessageCount at +0x44, Receive at +0x64,
// and Send at +0x68. The method order uses the period DirectPlay names.
class IDirectPlay4A {
public:
    virtual long __stdcall QueryInterface(void*, void**);
    virtual unsigned long __stdcall AddRef();
    virtual unsigned long __stdcall Release();
    virtual long __stdcall AddPlayerToGroup();
    virtual long __stdcall Close();
    virtual long __stdcall CreateGroup();
    virtual long __stdcall CreatePlayer();
    virtual long __stdcall DeletePlayerFromGroup();
    virtual long __stdcall DestroyGroup();
    virtual long __stdcall DestroyPlayer(unsigned long player);
    virtual long __stdcall EnumGroupPlayers();
    virtual long __stdcall EnumGroups();
    virtual long __stdcall EnumPlayers();
    virtual long __stdcall EnumSessions();
    virtual long __stdcall GetCaps();
    virtual long __stdcall GetGroupData();
    virtual long __stdcall GetGroupName();
    virtual long __stdcall GetMessageCount(unsigned long id,
                                            unsigned long* count);
    virtual long __stdcall GetPlayerAddress();
    virtual long __stdcall GetPlayerCaps();
    virtual long __stdcall GetPlayerData();
    virtual long __stdcall GetPlayerName();
    virtual long __stdcall GetSessionDesc();
    virtual long __stdcall Initialize();
    virtual long __stdcall Open(void* desc, unsigned long flags);
    virtual long __stdcall Receive(unsigned long* from, unsigned long* to,
                                   unsigned long flags, void* data,
                                   unsigned long* size);
    virtual long __stdcall Send(unsigned long from, unsigned long to,
                                unsigned long flags, void* data,
                                unsigned long size);

    long __stdcall SetPlayerName(unsigned long player, void* name,
                                 unsigned long flags);
};

#endif
