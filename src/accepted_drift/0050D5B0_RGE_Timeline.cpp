// VA: 0050D5B0 RGE_Timeline::RGE_Timeline
// Attempt log:
// initial natural constructor from packet/decompiler reached exact size with early stack-slot/tail drift.
// swapped index/link declarations and init order; fixed all pre-tail bytes, first mismatch moved to 0050D74C.
// tried direct store/update order (*link=entry; ++index; link=&entry->next; next=0); worsened early local slots and tail ordering, rolled back.
// tried explicit old_link local (block local and function local); same best family, tail-only register/scheduling drift.
// tried volatile old_link; worsened frame size to 0x14, rolled back.
// left in scratch / accepted_drift proposal: current build exact size and behavior; remaining diff is localized to final list-link/index update at 0050D74C-0050D76D (register choices/order only: eax/ecx/edx scheduling around old link, next pointer, index increment, list_num compare).

#include <stdlib.h>

extern "C" void __cdecl rge_read(int fd, void* buf, int size);

class RGE_Static_Object;
class RGE_Object_List {
public:
    RGE_Static_Object* find_by_id(long id);
};

struct RGE_PlayerLike {
    char gap_00[0x28];
    RGE_Object_List* objects; // +0x28
};

struct RGE_Game_World {
    char gap_00[0x40];
    RGE_PlayerLike** players; // +0x40
};

struct RGE_Time_Entry {
    int time;             // +00
    char type;            // +04
    char gap_05;          // +05
    short id;             // +06
    char flag;            // +08
    char gap_09[3];       // +09
    int x;                // +0c
    int y;                // +10
    int z;                // +14
    short a;              // +18
    char gap_1a[2];       // +1a
    RGE_Static_Object* source; // +1c
    short source_id;      // +20
    char gap_22[2];       // +22
    RGE_Static_Object* target; // +24
    short target_id;      // +28
    char gap_2a[2];       // +2a
    RGE_Time_Entry* next; // +2c
};

class RGE_Timeline {
public:
    RGE_Game_World* world;     // +04
    RGE_Time_Entry* time_list; // +08
    short list_num;           // +0c
    short avail_id;           // +0e
    long old_time;            // +10

    RGE_Timeline(int fd, RGE_Game_World* world);
    virtual ~RGE_Timeline();
};

RGE_Timeline::RGE_Timeline(int fd, RGE_Game_World* world_arg)
{
    int index;
    RGE_Time_Entry** link;
    RGE_Time_Entry** old_link;
    short target_player_id;
    short player_id;

    rge_read(fd, &this->list_num, 2);
    rge_read(fd, &this->avail_id, 2);
    rge_read(fd, &this->old_time, 4);
    this->world = world_arg;
    this->time_list = 0;

    link = &this->time_list;
    index = 0;
    if (this->list_num > 0) {
        do {
            RGE_Time_Entry* entry = (RGE_Time_Entry*)calloc(1, 0x30);
            rge_read(fd, &entry->time, 4);
            rge_read(fd, &entry->type, 1);
            rge_read(fd, &entry->id, 2);
            rge_read(fd, &entry->flag, 1);
            rge_read(fd, &entry->x, 4);
            rge_read(fd, &entry->y, 4);
            rge_read(fd, &entry->z, 4);
            rge_read(fd, &entry->a, 2);
            rge_read(fd, &entry->source_id, 2);
            rge_read(fd, &target_player_id, 2);
            rge_read(fd, &entry->target_id, 2);
            rge_read(fd, &player_id, 2);

            if (target_player_id >= 0 && this->world != 0) {
                entry->source = this->world->players[target_player_id]->objects->find_by_id(entry->source_id);
            } else {
                entry->source = 0;
            }

            if (player_id >= 0 && this->world != 0) {
                entry->target = this->world->players[target_player_id]->objects->find_by_id(entry->target_id);
            } else {
                entry->target = 0;
            }

            old_link = link;
            link = &entry->next;
            entry->next = 0;
            *old_link = entry;
            ++index;
        } while (index < this->list_num);
    }
}
