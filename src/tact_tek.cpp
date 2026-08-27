#include "../include/tact_tek.h"

// Original PDB module: C:\\msdev\\work\\age1_x1\\tact_tek.cpp.
// Normal owners follow the PDB source and address order below. The nearby
// 004D2230 vector-deleting destructor is compiler generated, not handwritten.
//
// 004D21B0  lines 29-34  matching
// 004D2250  lines 41-45  accepted_drift
// 004D2290  lines 49-64  scratch
// 004D2370  lines 68-73  matching
// 004D23B0  lines 76-98  matching
// 004D2440  lines 102-106 matching
// 004D2450  lines 109-134 scratch
// 004D2550  lines 138-147 matching
// 004D25E0  lines 151-164 accepted_drift

// VA 004D21B0; PDB tact_tek.cpp:29-34; matching.
TRIBE_Action_Make_Tech::TRIBE_Action_Make_Tech(int file, RGE_Action_Object* object)
    : RGE_Action(file, object, 1) {
    this->action_type = 0x67;
    rge_read(file, &this->tech_id, 2);
    rge_read(file, &this->unique_id, 4);
}

// VA 004D2250; PDB tact_tek.cpp:41-45; accepted drift.
// The constructor preserves the original base construction and field values.
TRIBE_Action_Make_Tech::TRIBE_Action_Make_Tech(RGE_Action_Object* object,
                                               short tech_id_value,
                                               int unique_id_value)
    : RGE_Action(object, 1) {
    this->unique_id = unique_id_value;
    this->action_type = 0x67;
    this->tech_id = tech_id_value;
}

// VA 004D2290; PDB tact_tek.cpp:49-64; scratch.
TRIBE_Action_Make_Tech::~TRIBE_Action_Make_Tech() {
    if (this->status != 1) {
        TRIBE_Player_Tech* player_tech = *(TRIBE_Player_Tech**)(
            (char*)this->action_obj->obj_ptr + 0x220);
        player_tech->cancel_research(this->tech_id, 0);

        unsigned char game_state = *(unsigned char*)(
            *(int*)((char*)rge_base_game + 0x3F4) + 0x1D);
        if (game_state == 0) {
            rge_base_game->notification(
                0x65,
                *(short*)((char*)this->action_obj->obj_ptr + 0x4A),
                this->tech_id,
                0,
                0);

            ((TRIBE_Player*)this->action_obj->obj_ptr)->cancelResearch(
                (int)this->tech_id,
                this->action_obj->player_id,
                -1,
                this->unique_id);

            this->action_obj->notify(
                this->action_obj->player_id,
                this->action_obj->player_id,
                0x1F9,
                0x26C,
                0,
                0);
        }
    }
}

// VA 004D2370; PDB tact_tek.cpp:68-73; matching.
void TRIBE_Action_Make_Tech::save(int file) {
    RGE_Action::save(file);
    rge_write(file, &this->tech_id, 2);
    rge_write(file, &this->unique_id, 4);
}

// VA 004D23B0; PDB tact_tek.cpp:76-98; matching.
void TRIBE_Action_Make_Tech::first_in_stack(unsigned char value) {
    if (value == 0 || this->tech_id < 0) {
        return;
    }

    TRIBE_Player_Tech* player_tech = *(TRIBE_Player_Tech**)(
        (char*)this->action_obj->obj_ptr + 0x220);
    unsigned char result = player_tech->start_research(this->tech_id, 1, &value);
    if (result == 1) {
        this->set_state(6);
        return;
    }

    ((TRIBE_Player*)this->action_obj->obj_ptr)->cancelResearch(
        (int)*(short*)&value,
        (int)this->tech_id,
        this->action_obj->player_id,
        this->unique_id);

    this->action_obj->notify(
        this->action_obj->player_id,
        this->action_obj->player_id,
        0x1F9,
        0x26C,
        0,
        0);

    this->set_state(1);
}

// VA 004D2440; PDB tact_tek.cpp:102-106; matching.
void TRIBE_Action_Make_Tech::set_state(unsigned char new_state) {
    this->status = new_state;
}

// VA 004D2450; PDB tact_tek.cpp:109-134; scratch.
unsigned char TRIBE_Action_Make_Tech::update() {
    if (this->status == 1) {
        return 1;
    }
    if (this->status != 6) {
        return 0;
    }

    float work;
    if (rge_base_game->quick_build == 0) {
        float* research_rate = *(float**)(
            (char*)this->action_obj->obj_ptr + 0x3C);
        work = research_rate[0x84 / 4] *
            *(float*)((char*)this->action_obj->field_08 + 0xE4);
    } else {
        work = 1000.0f;
    }

    TRIBE_Player_Tech* player_tech = *(TRIBE_Player_Tech**)(
        (char*)this->action_obj->obj_ptr + 0x220);
    if (player_tech->research(this->tech_id, work) != 0) {
        return 0;
    }

    this->set_state(1);
    RGE_Action_Object* action_object = this->action_obj;
    rge_base_game->notification(
        0x64,
        *(short*)((char*)action_object->obj_ptr + 0x4A),
        this->tech_id,
        (int)action_object->world_y,
        (int)action_object->world_x);

    ((TRIBE_Player*)action_object->obj_ptr)->registerResearch(
        (int)this->tech_id,
        action_object->player_id,
        this->unique_id);

    action_object->notify(
        action_object->player_id,
        action_object->player_id,
        0x1FA,
        0x26C,
        0,
        0);

    return 1;
}

// VA 004D2550; PDB tact_tek.cpp:138-147; matching.
int TRIBE_Action_Make_Tech::stop() {
    this->set_state(1);

    static_cast<TRIBE_Player*>(this->action_obj->owner)->tech_tree->cancel_research(
        this->tech_id, 1);

    rge_base_game->notification(
        0x65,
        static_cast<TRIBE_Player*>(this->action_obj->owner)->id,
        this->tech_id,
        0,
        0);

    static_cast<TRIBE_Player*>(this->action_obj->owner)->cancelResearch(
        (int)this->tech_id,
        this->action_obj->player_id,
        -1,
        this->unique_id);

    this->action_obj->notify(
        this->action_obj->player_id,
        this->action_obj->player_id,
        0x1F9,
        0x26C,
        0,
        0);

    return 1;
}

// VA 004D25E0; PDB tact_tek.cpp:151-164; accepted drift.
// The final terminator store is behavior-equivalent despite VC5 SIB ordering.
void TRIBE_Action_Make_Tech::get_info(short& tech_id_out,
                                       short& progress_out,
                                       char* name_out,
                                       short max_length) {
    register TRIBE_Action_Make_Tech* self = this;
    char* destination = name_out;

    tech_id_out = self->tech_id;
    if (self->status == 1) {
        progress_out = 100;
    } else {
        void* scenario = self->action_obj->obj_ptr;
        TRIBE_Player_Tech* player_tech = *(TRIBE_Player_Tech**)(
            (char*)scenario + 0x220);
        progress_out = player_tech->get_progress(self->tech_id);
    }

    if (destination != 0) {
        int length = max_length;
        void* scenario = self->action_obj->obj_ptr;
        TRIBE_Player_Tech* player_tech = *(TRIBE_Player_Tech**)(
            (char*)scenario + 0x220);
        strncpy(destination, player_tech->get_name(self->tech_id), length);
        destination[length - 1] = 0;
    }
}
