// VA: 004C82A0 TRIBE_Building_Object::~TRIBE_Building_Object
// PDB source: t_b_obj.cpp:129-151
// Baseline: period-plausible derived destructor with the production queue and
// action-list ownership shown by the executable.
// Attempt log:
// - Natural virtual action-list destruction emitted an indirect call; the
//   qualified derived destructor call below preserves the observed direct
//   RGE_Action_List::~RGE_Action_List call at 00403EC0.

extern "C" void free(void*);
void operator delete(void*);

class TRIBE_Building_Object;

class RGE_Doppleganger_Creator {
public:
    int remove_doppleganger_check(TRIBE_Building_Object* object);
};

class TRIBE_World {
public:
    char gap_00[0x3C];
    void* destructables;
    RGE_Doppleganger_Creator* creator;
    char gap_44[0x06];
    short map_id;
};

class RGE_Action_List {
public:
    virtual ~RGE_Action_List();
};

class TRIBE_Combat_Object {
public:
    virtual ~TRIBE_Combat_Object();
};

class TRIBE_Player {
public:
    char gap_00[0x4A];
    short player_id;
};

class TRIBE_Game {
public:
    char gap_00[0xA34];
    long queue_is_waiting_on_pop_counter[9];
};

extern TRIBE_Game* rge_base_game;

class TRIBE_Building_Object : public TRIBE_Combat_Object {
public:
    char gap_04[0x08];
    TRIBE_World* world;
    char gap_10[0x1B8];
    void* production_queue;
    char gap_1CC[0x08];
    RGE_Action_List* production_queue_actions;
    char gap_1D8[0x02];
    short production_queue_need_attr;

    virtual ~TRIBE_Building_Object();
};

TRIBE_Building_Object::~TRIBE_Building_Object()
{
    this->world->creator->remove_doppleganger_check(this);

    RGE_Action_List* actions = this->production_queue_actions;
    if (actions != 0) {
        actions->RGE_Action_List::~RGE_Action_List();
        operator delete(actions);
        this->production_queue_actions = 0;
    }

    if (this->production_queue != 0) {
        free(this->production_queue);
        this->production_queue = 0;
        if (this->production_queue_need_attr == 4) {
            this->production_queue_need_attr = -1;
            TRIBE_Game* game = rge_base_game;
            int map_id = (int)(short)this->world->map_id;
            long* count = &game->queue_is_waiting_on_pop_counter[map_id];
            *count = *count - 1;
        }
    }
}
