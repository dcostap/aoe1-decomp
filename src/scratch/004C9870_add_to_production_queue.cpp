// 004C9870 TRIBE_Building_Object::add_to_production_queue(short, short)
// Source: t_b_obj.cpp lines 966-1043
// Attempt log:
// - Initial reconstruction from packet/decompiler.
// - Tried plain local queue_changed: compiler kept it in BL and omitted original push-ecx stack byte; first mismatch at prologue, 86.5471% positional / 62.4813% edit.
// - Tried volatile stack byte for queue_changed: restored push ecx but lost EBX allocation; 86.8460% positional / 61.4350% edit.
// - Added an int id local to keep the object id in EDI like original; prologue now matches through push edi, but VC5 stores the volatile byte before loading EDI/AX and broad drift remains.
// - Tried qcount as int vs short; best current is same-size 669B mismatch, positional 85.5007%, edit 47.9821%, first mismatch at offset 7. Remaining drift is broad source-shape/register allocation around stack bool timing, repeated cost-check loops, and queue growth copy; not accepted_drift-safe.

void* __cdecl calloc(unsigned int n, unsigned int size);
void __cdecl free(void* p);

struct RGE_Base_Game { virtual void v0(); virtual void v4(); virtual void v8(); virtual void vC(); virtual void v10(); virtual void v14(); virtual void v18(); virtual void v1C(); virtual void v20(); virtual void v24(); virtual void v28(); virtual void v2C(); virtual void v30(); virtual void v34(); virtual void v38(); virtual void v3C(); virtual void notify(int, int, int, int, int); };
extern RGE_Base_Game* rge_base_game;

class TRIBE_Player { public: char gap[0x4A]; short player_id; unsigned char check_obj_cost(short, short*, float, int); unsigned char pay_obj_cost(short, float, int); };
struct Production_Queue_Record { short master_id; short unit_count; };

class TRIBE_Building_Object {
public:
    char gap0[0x0C];
    TRIBE_Player* owner;
    char gap10[0x1C8-0x10];
    Production_Queue_Record* production_queue;
    short production_queue_size;
    short production_queue_count;
    char gap1D0[8];
    unsigned char production_queue_change_flag;
    void remove_from_production_queue(short, int);
    void add_to_production_queue(short master_id, short count);
};

void TRIBE_Building_Object::add_to_production_queue(short master_id, short count)
{
    int id = master_id;
    int qcount = this->production_queue_count;
    volatile unsigned char queue_changed = 0;
    if (qcount > 0 && this->production_queue[qcount - 1].master_id == id) {
        int n = count;
        int i = 0;
        if (n > 0) {
            do {
                if (!this->owner->check_obj_cost((short)id, &master_id, 1.0f, 1)) {
                    rge_base_game->notify(0x7d, this->owner->player_id, id, 0, 0);
                    break;
                }
                this->owner->pay_obj_cost((short)id, 1.0f, 1);
                this->production_queue[this->production_queue_count - 1].unit_count++;
                i++;
                queue_changed = 1;
            } while (i < n);
        }
        if (queue_changed) {
            this->production_queue_change_flag++;
            rge_base_game->notify(0x7c, this->owner->player_id, 0, 0, 0);
        }
        return;
    }
    while (qcount > 0) {
        this->remove_from_production_queue(this->production_queue[0].master_id, 1);
        qcount = this->production_queue_count;
    }
    if (!this->owner->check_obj_cost((short)id, &master_id, 1.0f, 1)) {
        rge_base_game->notify(0x7d, this->owner->player_id, id, 0, 0);
        return;
    }
    if (this->production_queue_count == this->production_queue_size) {
        Production_Queue_Record* newq = (Production_Queue_Record*)calloc((int)this->production_queue_size + 10, 4);
        if (newq == 0) return;
        if (this->production_queue != 0) {
            short i = 0;
            if (this->production_queue_size > 0) {
                do {
                    newq[i].master_id = this->production_queue[i].master_id;
                    newq[i].unit_count = this->production_queue[i].unit_count;
                    i++;
                } while (i < this->production_queue_size);
            }
            free(this->production_queue);
        }
        this->production_queue_size += 10;
        this->production_queue = newq;
    }
    int n = count;
    int i = 0;
    this->production_queue[this->production_queue_count].unit_count = 0;
    if (n > 0) {
        do {
            if (!this->owner->check_obj_cost((short)id, &master_id, 1.0f, 1)) {
                rge_base_game->notify(0x7d, this->owner->player_id, id, 0, 0);
                break;
            }
            this->owner->pay_obj_cost((short)id, 1.0f, 1);
            this->production_queue[this->production_queue_count].unit_count++;
            i++;
        } while (i < n);
    }
    this->production_queue[this->production_queue_count].master_id = (short)id;
    this->production_queue_count++;
    this->production_queue_change_flag++;
    rge_base_game->notify(0x7c, this->owner->player_id, 0, 0, 0);
}
