class RGE_Combat_Object {
public:
    virtual void vf00(void);
    void stop(void);
};

struct ProductionEntry {
    short master_id;
};

class TRIBE_Building_Object : public RGE_Combat_Object {
public:
    char gap_04[0x1C4];
    ProductionEntry* production_queue;
    char gap_1CC[0x02];
    short production_queue_count;

    void remove_from_production_queue(short master_id, int value);
    void stop(void);
};

void TRIBE_Building_Object::stop(void) {
    RGE_Combat_Object::stop();
    while (this->production_queue_count > 0) {
        this->remove_from_production_queue(this->production_queue->master_id, 1);
    }
}
