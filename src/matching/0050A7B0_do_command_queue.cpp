class TRIBE_Building_Object;

class RGE_Game_World {
public:
    TRIBE_Building_Object* object(unsigned long id);
};

class TRIBE_Command_Queue {
public:
    char gap_00[0x4];
    unsigned long bldg_id;
    unsigned short train_id;
    short train_count;
};

class TRIBE_Command {
public:
    char gap_00[0x4];
    RGE_Game_World* world;

    void do_command_queue(TRIBE_Command_Queue* queue);
};

class TRIBE_Building_Object {
public:
    void add_to_production_queue(unsigned short train_id, short count);
    void remove_from_production_queue(unsigned short train_id, short count);
};

void TRIBE_Command::do_command_queue(TRIBE_Command_Queue* queue) {
    TRIBE_Building_Object* building = this->world->object(queue->bldg_id);
    if (building != 0) {
        if (0 < queue->train_count) {
            building->add_to_production_queue(queue->train_id, queue->train_count);
            return;
        }
        building->remove_from_production_queue(queue->train_id, (short)-queue->train_count);
    }
}
