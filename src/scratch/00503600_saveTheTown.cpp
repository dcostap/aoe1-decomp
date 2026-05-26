// VA: 00503600 TribeTacticalAIModule::saveTheTown
// PDB source: taitacmd.cpp
// Attempt log:
// - broad reconstruction from packet: locate attacking object/task, command defenders, scan up to six units, request reinforcements near town.
// - default /O2 compiles but .text is 928 bytes vs target 1450, too short for extraction; broad behavior is present but many unitAI/vtable/helper surfaces and duplicated dynamic-array growth blocks are under-modeled.
// - tried /Od diagnostically: 1279 bytes, still too short and wrong EBP/debug-frame family.
// - restored default flags. Give-up: requires faithful task/unit helper declarations, original virtual call surfaces, and exact loop/array-growth shape; no accepted_drift proposed.

extern int time_line(int,char*);
extern int ftol(float);
extern void* operator new(unsigned int);
extern void operator delete(void*);

struct World { void* vt; char gap4[0x3c-4]; void* objmgr; void* object(int); };
struct Game { char gap0[0x3c]; World* world; };
struct Player { char gap0[0xf0]; Game* game; char gapf4[0x1256c-0xf4]; Game* game2; };
struct ObjType { char gap0[0x10]; short civ; char gap12[0x4a-0x12]; short player; };
struct Obj { void* vt; int id; ObjType* type; char gapc[0x38-0xc]; float x,y,z; float dist(Obj*); void* unitAI(); int cmd(int,int,int,int,int); int move(float,float,float); };
struct Task { int id(); void setTarget(int); void setType(short); void setPos(float,float,float); void init(Player*, void*, int, int, int); };
struct AI { char gap0[0xf0]; Player* player; char gapf4[0x114-0xf4]; int* ids; int idCount; char gap11c[4]; int idCap; char gap124[0x1e4-0x124]; int town; char gap1e8[0xd28-0x1e8]; int* allies; char gapd2c[8]; int allyCap;
    Task* findTask(int,void*,int*); int request(int,int,int,int,int,int*); void send(int,float,float,int,short,int,int,int,int); void saveTheTown(int);
};
static void grow(AI* a,int n){ if(n>a->idCap-1){ int nc=n+1; int* q=(int*)operator new(nc*4); if(q){ for(int i=0;i<a->idCap;i++) q[i]=a->ids[i]; operator delete(a->ids); a->ids=q; a->idCap=nc; } } }

void AI::saveTheTown(int objid)
{
    time_line(0x3420,(char*)0x5880c0);
    Obj* town=(Obj*)player->game->world->object(objid); if(!town) return;
    int xy[2]; xy[0]=ftol(town->x); xy[1]=ftol(town->y);
    Task* task=findTask(0x64,town,xy); if(!task) task=findTask(0x67,town,xy);
    if(task) {
        Obj* enemy=(Obj*)player->game->world->object(task->id());
        if(enemy) {
            int p[3]; p[0]=ftol(town->x); p[1]=ftol(town->y); p[2]=ftol(town->z);
            if(enemy->cmd(objid,0,1,-1,-1)==1 && enemy->move(town->x,town->y,town->z)==1) {
                task->setTarget(objid); task->setType(town->type->civ); task->setPos(town->x,town->y,town->z); task->init(player,this,2,1,0); return;
            }
        }
    }
    int count=0;
    for(int i=0;i<idCount && count<6;i++) {
        if(count>1 && (unsigned)(time_line(0x3447,(char*)0x5880c0)-0)>10) return;
        grow(this,i);
        Obj* o=(Obj*)player->game2->world->object(ids[i]);
        if(!o || !o->unitAI()) continue;
        void* ai=o->unitAI();
        if(0==0x258) {
            int tid=-1;
            if(tid!=-1 && tid==town->id) { count++; continue; }
            Obj* target=(Obj*)player->game->world->object(tid);
            if(target && allies && allies[0]==target->type->player) continue;
        }
        if (!(o->dist(town) < *(float*)0x575784)) continue;
        if (o->move(town->x,town->y,town->z)) {
            grow(this,i); send(ids[i], town->x,town->y,town->z,town->type->player,0,0,-1,0); count++;
        }
    }
    int point[2];
    int rid=request(1,0x2bc,-1000,-1000,1,point);
    while(rid!=-1 && count<6) {
        Obj* r=(Obj*)player->game->world->object(rid); if(!r) return;
        if(r->move(town->x,town->y,town->z)) { send(rid,town->x,town->y,town->z,town->type->player,0,0,-1,0); count++; }
        rid=request(1,0x2bc,0x2c9,0x2c9,1,point);
    }
}
