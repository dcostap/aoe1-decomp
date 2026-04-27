// attempt log:
// first pass: direct member cleanup plus final base recycle call
// target shape: delete action-list if present, free production queue if present, reset queue fields, then call base recycle_out_of_game

void __cdecl free(void*);

class RGE_Action_List {
public:
    void delete_list();
};

class RGE_Action_Object {
public:
    void recycle_out_of_game();
};

class Production_Queue_Record;

class TRIBE_Building_Object {
public:
    char gap_00[0x1C8];
    Production_Queue_Record* production_queue_1c8;
    short production_queue_size_1cc;
    short production_queue_count_1ce;
    unsigned char production_queue_enabled_1d0;
    char gap_1d1[0x3];
    RGE_Action_List* action_list_1d4;
    unsigned char production_queue_change_flag_1d8;
    unsigned char production_queue_auto_paused_1d9;
    short production_queue_need_attr_1da;

    void recycle_out_of_game();
};

void TRIBE_Building_Object::recycle_out_of_game() {
    RGE_Action_List* list = this->action_list_1d4;
    if (list != 0) {
        list->delete_list();
    }

    Production_Queue_Record* queue = this->production_queue_1c8;
    if (queue != 0) {
        free(queue);
        this->production_queue_1c8 = 0;
        this->production_queue_size_1cc = 0;
        this->production_queue_count_1ce = 0;
        this->production_queue_enabled_1d0 = 1;
        this->production_queue_change_flag_1d8 = 0;
        this->production_queue_auto_paused_1d9 = 0;
        this->production_queue_need_attr_1da = -1;
    }

    ((RGE_Action_Object*)this)->recycle_out_of_game();
}
