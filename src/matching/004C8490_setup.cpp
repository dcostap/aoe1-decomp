// VA: 004C8490 TRIBE_Building_Object::setup (307 B)
// PDB source: t_b_obj.cpp
// Attempt log:
// - Initial natural load mirror from save.cpp and packet.

#include <stddef.h>

extern "C" {
    void rge_read(int fd, void* buf, int size);
    void* calloc(size_t count, size_t size);
}

extern float save_game_version;

#ifndef T_B_OBJ_CONTEXT_H
struct RGE_Game_World;

struct TRIBE_Combat_Object_Base {
    char base[0x1C8];
    int setup(int fd, RGE_Game_World* world);
};

struct RGE_Action_List {
    char base[4];
    void load(int fd);
};

struct TRIBE_Building_Object {
    char pad0[0x4A];
    unsigned char type;              // +0x4E
    char pad1[0x1C8 - 0x4F];
    short* production_queue;         // +0x1C8
    short production_queue_size;     // +0x1CC
    short production_queue_count;    // +0x1CE
    unsigned char production_queue_enabled; // +0x1D0
    char pad2[3];                    // +0x1D1
    RGE_Action_List* production_queue_actions;  // +0x1D4
    unsigned char production_queue_change_flag; // +0x1D8
    char pad3[3];                    // +0x1D9
    int build_pts;                   // +0x1DC
    int unique_build_id;             // +0x1E0
    unsigned char culture;           // +0x1E4
    unsigned char built;             // +0x1E5

    virtual void vpad000();
    virtual void vpad001();
    virtual void vpad002();
    virtual void vpad003();
    virtual void vpad004();
    virtual void vpad005();
    virtual void vpad006();
    virtual void vpad007();
    virtual void vpad008();
    virtual void vpad009();
    virtual void vpad010();
    virtual void vpad011();
    virtual void vpad012();
    virtual void vpad013();
    virtual void vpad014();
    virtual void vpad015();
    virtual void vpad016();
    virtual void vpad017();
    virtual void vpad018();
    virtual void vpad019();
    virtual void vpad020();
    virtual void vpad021();
    virtual void vpad022();
    virtual void vpad023();
    virtual void vpad024();
    virtual void vpad025();
    virtual void vpad026();
    virtual void vpad027();
    virtual void vpad028();
    virtual void vpad029();
    virtual void vpad030();
    virtual void vpad031();
    virtual void vpad032();
    virtual void vpad033();
    virtual void vpad034();
    virtual void vpad035();
    virtual void vpad036();
    virtual void vpad037();
    virtual void vpad038();
    virtual void vpad039();
    virtual void vpad040();
    virtual void vpad041();
    virtual void vpad042();
    virtual void vpad043();
    virtual void vpad044();
    virtual void vpad045();
    virtual void vpad046();
    virtual void vpad047();
    virtual void vpad048();
    virtual void vpad049();
    virtual void vpad050();
    virtual void vpad051();
    virtual void vpad052();
    virtual void vpad053();
    virtual void vpad054();
    virtual void vpad055();
    virtual void vpad056();
    virtual void vpad057();
    virtual void vpad058();
    virtual void vpad059();
    virtual void vpad060();
    virtual void vpad061();
    virtual void vpad062();
    virtual void vpad063();
    virtual void vpad064();
    virtual void vpad065();
    virtual void vpad066();
    virtual void vpad067();
    virtual void vpad068();
    virtual void vpad069();
    virtual void vpad070();
    virtual void vpad071();
    virtual void vpad072();
    virtual void vpad073();
    virtual void vpad074();
    virtual void vpad075();
    virtual void vpad076();
    virtual void vpad077();
    virtual void vpad078();
    virtual void vpad079();
    virtual void vpad080();
    virtual void vpad081();
    virtual void vpad082();
    virtual void vpad083();
    virtual void vpad084();
    virtual void vpad085();
    virtual void vpad086();
    virtual void vpad087();
    virtual void vpad088();
    virtual void vpad089();
    virtual void vpad090();
    virtual void vpad091();
    virtual void vpad092();
    virtual void vpad093();
    virtual void vpad094();
    virtual void vpad095();
    virtual void vpad096();
    virtual void vpad097();
    virtual void vpad098();
    virtual void vpad099();
    virtual void vpad100();
    virtual void vpad101();
    virtual void vpad102();
    virtual void vpad103();
    virtual void vpad104();
    virtual void vpad105();
    virtual void vpad106();
    virtual void vpad107();
    virtual void vpad108();
    virtual void vpad109();
    virtual void vpad110();
    virtual void vpad111();
    virtual void vpad112();
    virtual void vpad113();
    virtual void vpad114();
    virtual void vpad115();
    virtual void vpad116();
    virtual void vpad117();
    virtual void vpad118();
    virtual void vpad119();
    virtual void vpad120();
    virtual void vpad121();
    virtual void vpad122();
    virtual void vpad123();
    virtual void vpad124();
    virtual void vpad125();
    virtual void vpad126();
    virtual void vpad127();
    virtual void vpad128();
    virtual void vpad129();
    virtual void vpad130();
    virtual void vpad131();
    virtual void vpad132();
    virtual void vpad133();
    virtual RGE_Action_List* create_action_list();

    int setup(int fd, RGE_Game_World* world);
};
#endif

int TRIBE_Building_Object::setup(int fd, RGE_Game_World* world)
{
    ((TRIBE_Combat_Object_Base*)this)->setup(fd, world);
    this->type = 0x50;
    rge_read(fd, &this->built, 1);
    rge_read(fd, &this->build_pts, 4);
    rge_read(fd, &this->unique_build_id, 4);
    rge_read(fd, &this->culture, 1);
    this->production_queue_actions = this->create_action_list();

    if (save_game_version >= 7.21f) {
        short* psize = &this->production_queue_size;
        rge_read(fd, psize, 2);
        if (*psize > 0) {
            Production_Queue_Record* queue = (Production_Queue_Record*)calloc(*psize, 4);
            short i = 0;
            if (i < *psize) {
                this->production_queue = queue;
                do {
                    rge_read(fd, &this->production_queue[i * 2], 2);
                    rge_read(fd, &this->production_queue[i * 2 + 1], 2);
                    i++;
                } while (i < this->production_queue_size);
            } else {
                this->production_queue = queue;
            }
        }
        rge_read(fd, &this->production_queue_count, 2);
        rge_read(fd, &this->production_queue_enabled, 1);
        this->production_queue_actions->load(fd);
    }
    return 1;
}
