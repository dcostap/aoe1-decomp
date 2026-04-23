class RGE_Game_World;

class RGE_Timeline {
public:
    virtual ~RGE_Timeline();
    RGE_Game_World* world;
    void* time_list;
    short list_num;
    short avail_id;
    float old_time;

    RGE_Timeline(RGE_Game_World* world);
};

RGE_Timeline::RGE_Timeline(RGE_Game_World* world) {
    this->world = world;
    this->time_list = 0;
    this->list_num = 0;
    this->avail_id = 0;
    this->old_time = -1.0f;
}
