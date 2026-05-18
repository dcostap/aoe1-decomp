// 005196E0 TRIBE_Player::get_mouse_pointer_action_vars
// Attempt log:
// try 1: packet-grounded high-level reconstruction. Models object lookup, default outputs, special contained-object path, player bounds, right-click table lookup, current action override, action/var switch, and final ret/clear-current-action loop.
// try 2: matched function size exactly (978B) with natural high-level source, enabling byte compare.
// try 3: modeled initial world->object(id) call and zeroing output refs before null-object return.
// try 4: modeled special kind 0x19 object path using +94/+98 inner object pointers versus normal +8/+c path.
// try 5: modeled owner/player bounds check against world player_count at +3c and virtual call at player vtable +0x98.
// try 6: modeled master-id 0x9e/0xa3 current-offset bonus 50.
// try 7: modeled selected vs normal right-click-table choice from global game offsets +0xa24/+0xa28 and +0xa2c/+0xa30.
// try 8: modeled indexed table probe plus fallback linear scan over 0x2c-byte entries.
// try 9: modeled table-mode switch selecting action/var pairs from entry offsets and default -1/-1.
// try 10: modeled action switch cases 0..9, current-action flags at +0x198, hp/range ftol tests, shared default zero-output path, and recursive clear-current-action retry.
// Current validation: exact size but broad mismatch (86.6053% positional / 68.3027% edit). First mismatch is prologue/local topology: rebuilt frame 0x18 and early EBX=this, original frame 0x1c and EDI=this with saved self at [esp+2c].
// GIVEUP blockers: exact TRIBE_Player/object/right-click-entry layout, source shape for two-level switch/tail-sharing, selected-action retry loop without recursion, and local/register allocation preserving EDI=this, ESI=entry/add value, EBP=current bonus. No inline asm used; no accepted_drift proposal.

typedef unsigned char byte;
extern "C" long __cdecl ftol(float);
extern int DAT_0086bc88;
extern int DAT_0086bc8c;

class RGE_Game_World { public: void* object(long id); short player_count; };
class TRIBE_Game { public: char gap[0xa24]; int sel_action; int sel_var; int norm_action; int norm_var; };
extern TRIBE_Game* rge_base_game;

struct ObjDef { char gap00[0x10]; short rightTable; char gap12[2]; short owner; char gap16[0x10]; short masterId; char gap28[8]; float range1; char gap34[0x18]; byte state; char gap4d; byte kind; char gap4f[0x1d]; float f6c; float f70; };
struct ObjWrap { char gap00[8]; ObjDef* def; void* extra; char gap10[0x84]; ObjDef* inner; void* inner2; };
struct RightClickEntry { int key; int a; int b; int c; int d; int e; int f; int g; int h; int i; int j; };

class TRIBE_Player {
public:
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37();
    virtual void maybe_update_mouse();
    char gap04[0x3c-4]; RGE_Game_World* world; char gap40[0x10]; void* policy; char gap54[0x144]; int currentActionFlags; int currentTarget;
    int get_mouse_pointer_action_vars(long id, int& action, int& var);
};

int TRIBE_Player::get_mouse_pointer_action_vars(long id, int& action, int& var)
{
    TRIBE_Player* self = this;
    ObjWrap* obj = (ObjWrap*)self->world->object(id);
    RightClickEntry* entry = 0;
    int owner;
    int table;
    int master;
    int maxhp;
    int current = 0;
    action = 0;
    var = 0;
    if (!obj) return 0;

    if (obj->def->kind == 0x19) {
        ObjDef* d = obj->inner;
        owner = d->owner;
        table = d->rightTable;
        master = d->masterId;
        maxhp = (int)obj->inner2;
    } else {
        ObjDef* d = obj->def;
        owner = d->owner;
        maxhp = (int)obj->extra;
        table = d->rightTable;
        master = d->masterId;
    }
    if (owner < 0 || owner >= self->world->player_count) return 0;

    self->maybe_update_mouse();
    if (master == 0x9e || master == 0xa3) current = 50;

    TRIBE_Game* game = rge_base_game;
    RightClickEntry* list;
    int listCount;
    int useSelection;
    if (*(short*)&self->currentActionFlags && self->currentTarget) {
        useSelection = 1; list = (RightClickEntry*)game->sel_action; listCount = game->sel_var;
    } else {
        useSelection = 0; list = (RightClickEntry*)game->norm_action; listCount = game->norm_var;
    }
    if (owner >= 0 && owner < listCount) {
        RightClickEntry* probe = &list[owner];
        if (probe->key == owner) entry = probe;
    }
    if (!entry) {
        for (int i = 0; i < listCount; ++i) {
            if (list[i].key == owner) { entry = &list[i]; break; }
        }
    }
    if (!entry) return 0;

    int code;
    int add;
    switch (((int*)self->policy)[table + 34]) {
    case 0: code = entry->c; add = entry->d; break;
    case 1: code = entry->a; add = entry->b; break;
    case 2: code = entry->e; add = entry->f; break;
    case 3: code = entry->g; add = entry->h; break;
    case 4: code = entry->i; add = entry->j; break;
    default: code = -1; add = -1; break;
    }
    if (code == -1) return 0;

again:
    switch (code) {
    case 0:
        if ((self->currentActionFlags & 1) && ((ObjDef*)obj)->state > 2) { action = 4; var = current + add; break; }
        if (code == 8) { current = 50; code = 7; goto again; }
        break;
    case 1:
        action = 0; var = current + add; break;
    case 2:
        if (self->currentActionFlags & 2) { action = 5; var = current + add; }
        break;
    case 3:
        if (self->currentActionFlags & 4) { action = 5; var = current + add; }
        break;
    case 4:
        if (self->currentActionFlags & 0x10) {
            if (!(DAT_0086bc8c == 1 && id == DAT_0086bc88)) {
                int hp = ftol(obj->def->range1);
                if (hp > 0 && hp < maxhp) { action = 5; var = current + add; }
            }
        }
        break;
    case 5:
        if (self->currentActionFlags & 0x20) {
            if (!obj->def->state) current = 50;
            int hp = ftol(obj->def->range1);
            if (hp > 0 && hp < maxhp) { action = 3; var = current + add; }
        }
        break;
    case 6:
        if (!(self->currentActionFlags & 0x40)) { if (code == 9) { current = 50; code = 1; goto again; } }
        else { action = 3; var = current + add; }
        break;
    case 7:
        if (self->currentActionFlags & 0x80) {
            if (master == 0x12 && obj->def->f6c == 0.0f) break;
            if (master == 3 && obj->def->f70 == 0.0f) break;
            if (master != master) break;
            if (master == 0x6d || master == 0x114) break;
            action = 5; var = current + add;
        }
        break;
    case 8:
        current = 50; code = 7; goto again;
    case 9:
        if (!(self->currentActionFlags & 0x40)) { current = 50; code = 1; goto again; }
        action = 3; var = current + add; break;
    default:
        action = 0; var = 0; break;
    }
    int ret = 1;
    if (useSelection == 1 && action == 0 && var == 0) {
        self->currentActionFlags = 0;
        return self->get_mouse_pointer_action_vars(id, action, var);
    }
    return ret;
}
