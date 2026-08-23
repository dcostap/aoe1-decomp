// VA: 00540010 pick_best_target (823B)
// vw_main.cpp
// Attempt log:
// - Baseline: natural typed reconstruction had 829B output, a 0x220 frame, and
//   621 positional mismatch bytes. Calls and owner symbol were exact.
// - The inner fallback scan as while(k < object_count), rather than do/while,
//   recovered the 0x224 frame, 95.79% shape, and 87.80% exact-block coverage.
// - The exact player helper ABI is unsigned char. This changed TEST EAX to
//   TEST AL and raised exact-block coverage to 90.55%.
// - Inventory evidence supports int pick_objects return and RGE_View::pick_weight
//   at vslot +E4. The return-width spelling is codegen-neutral here.
// - The original zero-fill block is two REP STOSD loops. Dynamic memset emits
//   two unnecessary byte-tail paths under VC5.
// - The original first action call reads selected_object +8 before +D8. A typed
//   RGE_Master_Static_Object model restores that owner and raises exact-block
//   coverage to 93.31%, with 95.82% shape and 844B output.
// - The +4/+8 calls match reviewed RGE_Task_List::get_target_task and
//   is_attack_task arity and slots. The +6 action field is typed as action_type.
// - Replaced generic virtual slots with the reviewed TPanel/RGE_View surface and
//   used natural polymorphic class layouts.
// - Removing the redundant positive object-count wrapper recovered the target
//   fallback-loop compare. The clean body is now 841B with 96.56% shape and
//   95.28% exact-block coverage.
// - Authentic game ownership identifies player +24 as the master-object array.
//   Selected entries retain the static-object layout and +8 master pointer.
// - Exact finish: two indexed zero loops with `target_count != master_obj`
//   lower to the original REP STOSD-only block. A focused 11-form lab also
//   found an exact pointer/count loop, but the indexed form is simpler.
// - Walkback: removing the unused memset declaration and using post-increment
//   remain exact. Changing either loop bound to `< master_obj` is non-exact.

extern "C" void __cdecl free(void*);

struct RGE_Static_Object;
struct RGE_Master_Static_Object;
struct RGE_Action_Object;
struct RGE_Task;
class RGE_Game_World;

struct RGE_Pick_Obj_Info {
    int object_id;
    short confidence;
    short draw_level;
    short draw_x;
    short draw_y;
};

extern RGE_Pick_Obj_Info Picked_Objects[];

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_004[0x1E];
    short object_count; // +22
    RGE_Master_Static_Object** master_objects; // +24
    char gap_028[0xB0];
    unsigned char get_selected_objects_to_command(RGE_Static_Object*** out, short* count,
                                                   short a, short b, short c, short d);
};

class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    char gap_004[0x84];
    RGE_Static_Object** objects;
};

class TPanel {
public:
    virtual ~TPanel();
    virtual long setup(void*, TPanel*, long, long, long, long, unsigned char);
    virtual void set_rect(void*);
    virtual void set_rect(long, long, long, long);
    virtual void set_color(unsigned char);
    virtual void set_active(int);
    virtual void set_positioning(int, long, long, long, long, long, long,
                                 long, long, TPanel*, TPanel*, TPanel*, TPanel*);
    virtual void set_fixed_position(long, long, long, long);
    virtual void set_redraw(int);
    virtual void set_overlapped_redraw(TPanel*, TPanel*, int);
    virtual void draw_setup(int);
    virtual void draw_finish();
    virtual void draw();
    virtual void draw_rect(void*);
    virtual void draw_offset(long, long, void*);
    virtual void draw_rect2(void*);
    virtual void draw_offset2(long, long, void*);
    virtual void paint();
    virtual long wnd_proc(void*, unsigned int, unsigned int, long);
    virtual long handle_idle();
    virtual long handle_size(long, long);
    virtual long handle_paint();
    virtual long handle_key_down(long, short, int, int, int);
    virtual long handle_char(long, short);
    virtual long handle_command(unsigned int, long);
    virtual long handle_user_command(unsigned int, long);
    virtual long handle_timer_command(unsigned int, long);
    virtual long handle_scroll(long, long);
    virtual long handle_mouse_down(unsigned char, long, long, int, int);
    virtual long handle_mouse_move(long, long, int, int);
    virtual long handle_mouse_up(unsigned char, long, long, int, int);
    virtual long handle_mouse_dbl_click(unsigned char, long, long, int, int);
    virtual long mouse_move_action(long, long, int, int);
    virtual long mouse_left_down_action(long, long, int, int);
    virtual long mouse_left_hold_action(long, long, int, int);
    virtual long mouse_left_move_action(long, long, int, int);
    virtual long mouse_left_up_action(long, long, int, int);
    virtual long mouse_left_dbl_click_action(long, long, int, int);
    virtual long mouse_right_down_action(long, long, int, int);
    virtual long mouse_right_hold_action(long, long, int, int);
    virtual long mouse_right_move_action(long, long, int, int);
    virtual long mouse_right_up_action(long, long, int, int);
    virtual long mouse_right_dbl_click_action(long, long, int, int);
    virtual long key_down_action(long, short, int, int, int);
    virtual long char_action(long, short);
    virtual long action(TPanel*, long, unsigned long, unsigned long);
    virtual void get_true_render_rect(void*);
    virtual int is_inside(long, long);
    virtual void set_focus(int);
    virtual void set_tab_order(TPanel*, TPanel*);
    virtual void set_tab_order(TPanel**, short);
    virtual unsigned char get_help_info(char**, long*, long, long);
    virtual void stop_sound_system();
    virtual int restart_sound_system();
    virtual void take_snapshot();
    virtual void handle_reactivate();

    char gap_004[0xF0];
};

class RGE_View : public TPanel {
public:
    virtual int pick_through_fog(RGE_Static_Object*);
    virtual int pick_weight(RGE_Static_Object*, int);
    virtual int start_scroll_view(unsigned char, long, long, int, int);
    virtual int handle_scroll_view(long, long);
    virtual void end_scroll_view();
    virtual int do_paint(long, long, long, long, int);
    virtual void draw_multi_object_outline();

    void* cur_render_area; // +F4
    int calc_draw_count; // +F8
    RGE_Game_World* world; // +FC
    RGE_Player* player; // +100
    int pick_objects(long x, long y, int a, int b, int c, int d, int e);
};

class RGE_Main_View : public RGE_View {
public:
    RGE_Static_Object* pick_best_target(long x, long y, int* attacking_out, short action_filter);
};

class RGE_Task_List {
public:
    virtual RGE_Task* create_task(short, short);
    virtual RGE_Task* get_target_task(RGE_Action_Object*, RGE_Static_Object*, float, float, float);
    virtual int is_attack_task(RGE_Task*);
};

struct RGE_Task {
    short task_type;
    short id;
    unsigned char gap_004[2];
    short action_type; // +6
};

struct RGE_Static_Object {
    virtual ~RGE_Static_Object();
    long id; // +4
    RGE_Master_Static_Object* master_obj; // +8
    void* owner; // +C
    void* sprite; // +10
    void* old_sprite; // +14
    char gap_018[0x30];
    unsigned char owner_type; // +48
};

struct RGE_Master_Static_Object {
    virtual ~RGE_Master_Static_Object();
    unsigned char kind; // +4
    char gap_005[1];
    short action_id; // +6
    char gap_008[0x0C];
    short object_type; // +14
    char gap_016[0xC2];
    RGE_Task_List* tasks; // +D8
    char gap_0DC[0x10];
    unsigned char flag_ec; // +EC
};

RGE_Static_Object* RGE_Main_View::pick_best_target(long x, long y, int* attacking_out, short action_filter) {
    short selected_count;
    RGE_Static_Object** selected_objects;
    int j;
    int target_count;
    int master_obj;
    RGE_Master_Static_Object* cur_target;
    RGE_Pick_Obj_Info* info;
    RGE_Pick_Obj_Info* info2;
    int valid_target_count[64];
    int attacking[64];

    if (attacking_out != 0) {
        *attacking_out = 0;
    }

    master_obj = this->pick_objects(x, y, 10, 20, 15, 4, 1);
    if (master_obj == 0) {
        return 0;
    }

    if (!this->player->get_selected_objects_to_command(&selected_objects, &selected_count, -1, -1, -1, -1)) {
        return 0;
    }

    if (master_obj > 0) {
        for (target_count = 0; target_count != master_obj; target_count++) {
            attacking[target_count] = 0;
        }
        for (target_count = 0; target_count != master_obj; target_count++) {
            valid_target_count[target_count] = 0;
        }
    }

    j = 0;
    if (selected_count > 0) {
        do {
            target_count = 0;
            cur_target = selected_objects[j]->master_obj;
            if (master_obj > 0) {
                info = Picked_Objects;
                do {
                    int picked = info->object_id;
                    if (picked >= 0) {
                        RGE_Static_Object* obj = this->world->objects[picked];
                        if (obj != 0 && obj->owner_type < 7) {
                            RGE_Task* action = cur_target->tasks->get_target_task(
                                (RGE_Action_Object*)selected_objects[j], obj, 0, 0, 0);
                            if (action != 0) {
                                if (action_filter != -1 && action->action_type != action_filter) {
                                    action = 0;
                                }
                                if (action != 0) {
                                    valid_target_count[target_count] += this->pick_weight(obj, info->confidence);
                                    if (cur_target->tasks->is_attack_task(action)) {
                                        attacking[target_count] = 1;
                                    }
                                    goto next_target;
                                }
                            }
                            if (cur_target->flag_ec != 0) {
                                int k = 0;
                                while (k < this->player->object_count) {
                                    RGE_Master_Static_Object* obj2 = this->player->master_objects[k];
                                    if (obj2 != 0 && obj2->object_type == cur_target->object_type &&
                                        obj2->kind == cur_target->kind && obj2->flag_ec == cur_target->flag_ec) {
                                        RGE_Task* action2 = obj2->tasks->get_target_task(
                                            (RGE_Action_Object*)selected_objects[j], obj, 0, 0, 0);
                                        if (action2 != 0) {
                                            if (action_filter != -1 && action2->action_type != action_filter) {
                                                action2 = 0;
                                            }
                                            if (action2 != 0) {
                                                valid_target_count[target_count] += this->pick_weight(obj, info->confidence);
                                                if (obj2->tasks->is_attack_task(action2)) {
                                                    attacking[target_count] = 1;
                                                }
                                                goto next_target;
                                            }
                                        }
                                    }
                                    k++;
                                }
                            }
                        }
                    }
next_target:
                    target_count++;
                    info++;
                } while (target_count < master_obj);
            }
            j++;
        } while (j < selected_count);
    }

    free(selected_objects);

    int best = 0;
    RGE_Static_Object* best_obj = 0;
    int i = 0;
    if (master_obj > 0) {
        info2 = Picked_Objects;
        do {
            int score = valid_target_count[i];
            if (score > best) {
                int picked = info2->object_id;
                best_obj = this->world->objects[picked];
                if (attacking_out != 0) {
                    *attacking_out = attacking[i];
                }
                best = score;
            }
            i++;
            info2++;
        } while (i < master_obj);
    }
    return best_obj;
}
