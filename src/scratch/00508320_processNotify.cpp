// VA: 00508320 TribeBuildingUnitAIModule::processNotify
// Attempt log:
// initial rough decompiler-style reconstruction. Compiles but intentionally incomplete (resize omitted) and mismatches broadly.
// modeled packet-observed cases 0x1f4/0x1f5/0x1f6, notify calls, list scans, changed(1), purge, askForHelp.
// left in scratch: not accepted_drift-safe; broad list-management switch needs real type/context and resize exactness.

struct NotifyEvent { int object_id; int unk4; unsigned long type; int value; };
class RGE_Player { public: int computerPlayer(); };
class GameLike { public:
    int field_0; int player_id; char gap[4]; RGE_Player* player;
#define GPAD(n) virtual void g##n();
    GPAD(0) GPAD(1) GPAD(2) GPAD(3) GPAD(4) GPAD(5) GPAD(6) GPAD(7)
    GPAD(8) GPAD(9) GPAD(10) GPAD(11) GPAD(12) GPAD(13) GPAD(14) GPAD(15)
    GPAD(16) GPAD(17) GPAD(18) GPAD(19) GPAD(20) GPAD(21) GPAD(22) GPAD(23)
    GPAD(24) GPAD(25) GPAD(26) GPAD(27) GPAD(28) GPAD(29) GPAD(30) GPAD(31)
    GPAD(32) GPAD(33) GPAD(34) GPAD(35) GPAD(36) GPAD(37) GPAD(38) GPAD(39)
    GPAD(40) GPAD(41) GPAD(42) GPAD(43) GPAD(44) GPAD(45) GPAD(46) GPAD(47)
    GPAD(48) GPAD(49) GPAD(50) GPAD(51) GPAD(52) GPAD(53) GPAD(54) GPAD(55)
    GPAD(56) GPAD(57)
#undef GPAD
    virtual void notify(int,int,int,int,int,int); virtual void changed(int); };
class UnitAIModule {
public:
    char gap_00[4]; GameLike* game; char gap_08[0x34-0x08]; int object_id; char gap_38[0x60-0x38];
    int* list; int count; char gap_68[4]; int max;
    void purgeNotifyQueue(unsigned long); void askForHelp(int); int processNotify(NotifyEvent*, unsigned long);
};

int UnitAIModule::processNotify(NotifyEvent* ev, unsigned long param)
{
    int i, j, k, m, n;
    switch (ev->type) {
    case 0x1f4:
        if (ev->value <= 0) {
            this->game->notify(this->game->player_id, this->game->player_id, 0x209, ev->object_id, 0, 0);
            this->purgeNotifyQueue(param);
            return 4;
        }
        if (this->count == 0 || this->game->player->computerPlayer() == 1)
            this->game->notify(this->game->player_id, this->game->player_id, 0x201, ev->object_id, 0, 0);
        for (i=0; i<this->count && i<this->max; ++i) if (this->list[i] == ev->object_id) goto have;
        if (this->game->player->computerPlayer() == 0 && this->object_id != ev->object_id) this->askForHelp(ev->object_id);
have:
        for (j=0; j<this->count && j<this->max; ++j) if (this->list[j] == ev->object_id) { this->game->changed(1); return 2; }
        this->list[this->count++] = ev->object_id;
        this->game->changed(1);
        return 2;
    case 0x1f5:
        for (k=0; k<this->count && k<this->max; ++k) if (this->list[k] == ev->object_id) { this->game->changed(1); return 2; }
        this->list[this->count++] = ev->object_id;
        this->game->changed(1);
        return 2;
    case 0x1f6:
        for (m=0; m<this->count && m<this->max; ++m) if (this->list[m] == ev->object_id) goto remove;
        return 2;
remove:
        for (n=0; n<this->max; ++n) if (this->list[n] == ev->object_id) { for (; n < this->max-1; ++n) this->list[n]=this->list[n+1]; break; }
        if (--this->count < 0) this->count = 0;
        return 2;
    }
    return 2;
}
