#include "../include/RGE_Action_Make.h"

#include "../include/RGE_Action_Object.h"
#include "../include/RGE_Base_Game.h"
#include "../include/RGE_Task.h"
#include "../include/globals.h"

#include <stdint.h>

// Fully verified. Source of truth: act_make.cpp.decomp @ 0x004049B0
RGE_Action_Make::RGE_Action_Make(int param_1, RGE_Action_Object* param_2) {
    RGE_Action::setup(param_1, param_2);
    this->action_type = 0x15;
}

// Fully verified. Source of truth: act_make.cpp.decomp @ 0x00404A10
RGE_Action_Make::RGE_Action_Make(RGE_Action_Object* param_1, RGE_Task* param_2) {
    RGE_Action::setup(param_1);
    this->action_type = 0x15;
    this->task = param_2;
}

// Fully verified. Source of truth: bucket_0404.decomp @ 0x00404A00
RGE_Action_Make::~RGE_Action_Make() {
    // Intentionally empty: decomp shows the base cleanup inlined here; our base destructor handles it.
}

int RGE_Action_Make::setup(RGE_Action_Object* param_1) {
    RGE_Action::setup(param_1);
    this->action_type = 0x15;
    return 1;
}

int RGE_Action_Make::setup(int param_1, RGE_Action_Object* param_2) {
    RGE_Action::setup(param_1, param_2);
    this->action_type = 0x15;
    return 1;
}

RGE_Action_List* RGE_Action_Make::create_action_list(RGE_Action_Object* param_1) { return RGE_Action::create_action_list(param_1); }
void RGE_Action_Make::rehook() { RGE_Action::rehook(); }
void RGE_Action_Make::save(int param_1) { RGE_Action::save(param_1); }
short RGE_Action_Make::type() { return RGE_Action::type(); }
uchar RGE_Action_Make::inside_obj_update() { return RGE_Action::inside_obj_update(); }
uchar RGE_Action_Make::idle_update() { return RGE_Action::idle_update(); }
int RGE_Action_Make::stop() { return RGE_Action::stop(); }
int RGE_Action_Make::move_to(RGE_Static_Object* param_1, float param_2, float param_3, float param_4) { return RGE_Action::move_to(param_1, param_2, param_3, param_4); }
int RGE_Action_Make::work(RGE_Static_Object* param_1, float param_2, float param_3, float param_4) { return RGE_Action::work(param_1, param_2, param_3, param_4); }
uchar RGE_Action_Make::attack_response(RGE_Static_Object* param_1) { return RGE_Action::attack_response(param_1); }
uchar RGE_Action_Make::relation_response(long param_1, uchar param_2) { return RGE_Action::relation_response(param_1, param_2); }
void RGE_Action_Make::copy_obj(RGE_Master_Action_Object* param_1) { RGE_Action::copy_obj(param_1); }
void RGE_Action_Make::copy_obj_sprites(RGE_Master_Action_Object* param_1, RGE_Task* param_2, RGE_Task* param_3) { RGE_Action::copy_obj_sprites(param_1, param_2, param_3); }
void RGE_Action_Make::get_state_name(char* param_1) { RGE_Action::get_state_name(param_1); }
RGE_Static_Object* RGE_Action_Make::get_target_obj() { return RGE_Action::get_target_obj(); }
RGE_Static_Object* RGE_Action_Make::get_target_obj2() { return RGE_Action::get_target_obj2(); }
void RGE_Action_Make::set_target_obj(RGE_Static_Object* param_1) { RGE_Action::set_target_obj(param_1); }
void RGE_Action_Make::set_target_obj2(RGE_Static_Object* param_1) { RGE_Action::set_target_obj2(param_1); }

// Fully verified. Source of truth: act_make.cpp.decomp @ 0x00404A40
void RGE_Action_Make::first_in_stack(uchar param_1) {
    (void)param_1;

    this->set_state(6);

    short attribute_type = (this->task != nullptr) ? this->task->attribute_type : (short)-1;
    if (attribute_type < 0) {
        return;
    }

    if ((this->obj != nullptr) && ((short)((int*)this->obj)[0x13] != attribute_type)) {
        this->obj->set_attribute(attribute_type, 0.0f);
    }
}

// Fully verified. Source of truth: act_make.cpp.decomp @ 0x00404A70
void RGE_Action_Make::set_state(uchar param_1) {
    this->state = param_1;

    // Matches: *(float *)&this->field_0x2c = *(float *)(*(int *)(*(int *)(obj + 0xc) + 0x50) + 0x90);
    const uintptr_t obj = (uintptr_t)this->obj;
    const uintptr_t master_obj = *(const uintptr_t*)(obj + 0x0C);
    const uintptr_t ptr_50 = *(const uintptr_t*)(master_obj + 0x50);
    this->timer = *(const float*)(ptr_50 + 0x90);
}

// Fully verified. Source of truth: act_make.cpp.decomp @ 0x00404A90
uchar RGE_Action_Make::update() {
    if (this->state == 1) {
        return 1;
    }

    if (this->state == 6) {
        if (this->timer <= 0.0f) {
            const uintptr_t obj = (uintptr_t)this->obj;
            const uintptr_t master_obj = *(const uintptr_t*)(obj + 0x0C);
            const uintptr_t ptr_50 = *(const uintptr_t*)(master_obj + 0x50);

            if (0.0f < *(const float*)(ptr_50 + 0x90)) {
                if (0.0f < *(const float*)(obj + 0x44)) {
                    return 0;
                }

                if (rge_base_game != nullptr) {
                    // __ftol
                    const long world_y = (long)*(const float*)(obj + 0x3C);
                    const long world_x = (long)*(const float*)(obj + 0x38);
                    const int obj_id = *(const int*)(obj + 0x04);
                    const long master_id = (long)*(const short*)(master_obj + 0x4A);

                    // language.dll match for 0x7e: "10"
                    rge_base_game->notification(0x7e, master_id, (long)obj_id, world_x, world_y);
                }

                if (this->obj != nullptr) {
                    this->obj->die_die_die();
                }
                return 0;
            }
        }

        const uintptr_t obj = (uintptr_t)this->obj;
        const uintptr_t owner = *(const uintptr_t*)(obj + 0x08);
        const uintptr_t master_obj = *(const uintptr_t*)(obj + 0x0C);
        const uintptr_t master_sub = *(const uintptr_t*)(master_obj + 0x3C); // ((int*)master_obj)[0xF]

        const uintptr_t task = (uintptr_t)this->task;

        const float pre_attribute = *(const float*)(obj + 0x44);
        const float work =
            *(const float*)(owner + 0xE4) * *(const float*)(master_sub + 0x84) * *(const float*)(task + 0x1C);

        if (*(const short*)(task + 0x30) == 0) {
            this->obj->set_attribute_amount(work, 1, 1);
        } else {
            typedef void(__thiscall* MasterSetAttrFn)(void* this_, int param_1, float param_2, int param_3);
            void** vtbl = *(void***)(void*)master_obj;
            MasterSetAttrFn fn = (MasterSetAttrFn)vtbl[0x78 / 4];

            fn((void*)master_obj, (int)*(const short*)(task + 0x14), work, 0);
        }

        const float cur_attribute = *(const float*)(obj + 0x44);
        this->timer = this->timer - (cur_attribute - pre_attribute);
    }

    return 0;
}

