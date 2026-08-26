// 005196E0 TRIBE_Player::get_mouse_pointer_action_vars
// Attempt log:
// try 1: packet-grounded high-level reconstruction. Models object lookup, default outputs, special contained-object path, player bounds, right-click table lookup, current action override, action/var switch, and final ret/clear-current-action loop.
// try 2: matched function size exactly (978B) with natural high-level source, enabling byte compare.
// try 3: modeled initial world->object(id) call and zeroing output refs before null-object return.
// try 4: modeled special kind 0x19 object path using +94/+98 inner object pointers versus normal +8/+c path.
// try 5: modeled owner/player bounds check against world player_count at +3c and virtual call at player vtable +0x98.
// try 6: modeled master-id 0x9e/0xa3 current-offset bonus 50.
// try 7: modeled selected vs normal right-click-table choice from global game offsets +0xa24/+0xa28 and +0xa2c/+0xa30.
// try 8: modeled indexed table probe plus fallback linear scan over 0x2c-byte entries.
// try 9: modeled table-mode switch selecting action/var pairs from entry offsets and default -1/-1.
// try 10: modeled action switch cases 0..9, current-action flags at +0x198, hp/range ftol tests, shared default zero-output path, and recursive clear-current-action retry.
// try 11: restored the direct RGE_Static_Object/master/player ownership proven by the packet, the world +0x3c layout, absolute game-global identity, and the original retry_table/redo_mouseFunc loop instead of recursive re-entry.
// probe 12: corrected the object/master ABI widths and compiler-owned __ftol casts; call count and frame became exact.
// probe 13: corrected master +0x10/+0x14/+0x26, static-object +0x30/+0x48/+0x4e, world player_count +0x3c, and short target +0x19c ownership; emitted size stayed exact.
// probe 14: tested the positive outer object guard; VC5 emitted the same code as the prior natural guard.
// probe 15: moved period-style locals to function scope; instruction count became 268 and exact-block coverage improved, but the saved-this home remained wrong.
// probe 16: tested a boolean selection local; it worsened CFG/return shape and was rolled back to the integer storage form supported by the dword stores.
// probe 17: changed table selection to the decompiler-supported negative OR guard; body layout improved but the prologue remained unchanged.
// probe 18: tested an ordinary self alias for the saved-this lifetime; VC5 emitted duplicate code and it is retained only as readable ownership context.
// probe 19: tested a shared action-5 label after case 4; it moved the code farther and was rolled back.
// probe 20: replaced the self alias with direct typed this-member access to test the saved-this home; emitted code was unchanged and was rolled back.
// probe 21: corrected the right-click table key to master->object_group; the original uses +0x10 for table lookup and +0x14 only for the player bound. The codegen basin became structurally worse, but this restores the executable's key behavior.
// probe 22: reordered the local declarations and removed the explicit self alias after the key correction; both emitted the same 0x18-frame basin.
// probe 23: declared the fallback scan pointer inside the positive-count block; this follows the original post-test iterator copy at line 5248 and improved CFG/block shape without changing size or calls.
// probe 24: post-lookup current initialization plus a pretested fallback scan improved the clean result to 891 strict bytes and 74.35% shape; this is now pinned.
// probes 25-32: zero-local, receiver-alias, entry-pointer, narrow-field, register, positive-guard, and context variants either duplicated code or worsened the clean basin.
// probe 29: caching current_action_flags produced the original 0x1c frame and EDI receiver, but local homes and broad CFG drift worsened; do not retain the cache.
// probe 26: a scoped rge_base_game receiver improved exact-block coverage but worsened strict bytes and did not recover the original ECX count color.
// context sweep: 32 ambient declaration samples all emitted one unchanged nonexact basin; neutral front-end declarations are not the blocker.
// probe 33: corrected action dispatch to mouse_actions[object_type]. The original reloads the bounded owner/special value at [esp+14], not RtClickTable at [esp+20]. Frame became exact and shape improved.
// probe 34: changed object-state < 3 to <= 2. The original emits cmp byte,2 plus JBE.
// probe 35: moved current=50 before action-code rewrites for cases 8 and 9. This matches the original fallthrough instruction order.
// probe 36: scoped TRIBE_Game* receivers around both global table arms. This removes two compiler-generated receiver copies and improved the result to 882 strict bytes and 80.22% shape.
// probes 37-39: no-reset entry state, receiver aliases, declaration order, and register qualifiers did not improve the scoped-receiver basin. The no-reset source produced 914-930 strict bytes and was rolled back.
// Probe 40: retained the executable's function-scope entry lifetime and cleared
// entry only on the retry path. This recovered the saved-this home and local
// homes. The strict difference fell to 341 bytes.
// Probe 41: removed the redundant positive-count guard from the fallback scan.
// The source now keeps the binary's null and fault order. The scan assignment
// remains two bytes early because VC5 hoists its local pointer initialization.
// Probe 42: restored the reviewed extern rge_base_game ABI and the global zero
// float DAT_00576828. Relocation identity now matches the game ABI evidence.
// The virtual call is named analyize_selected_objects at slot 0x98.
// Current validation: 341 strict bytes, 86.30% shape, 91.42% exact blocks,
// 978-byte size, 270 instructions, four ordered calls, and a 0x1c frame.
// Remaining blocker: VC5 places scan = table before the count test. The target
// places it after the test and rereads object_player before the null test.
// No inline asm, fake volatility, broad header edits, or accepted_drift proposal.
// Claim audit: explicit count guards, do-loops, and label forms did not match.
// A natural table + index scan reduced the strict difference to 335 bytes and
// matched the target through the first action dispatch, but changed source
// ownership from the observed moving cursor. It was restored to this baseline.
// Moving the shared action-5 label into the switch improved block coverage but
// did not remove the case-2 duplicate. It was also restored.

extern unsigned int DAT_0086bc88;
extern unsigned int DAT_0086bc8c;
extern float DAT_00576828;

class RGE_Static_Object;
class RGE_Master_Static_Object;
class RGE_Player;
class RGE_Base_Game;

#ifndef AOE1_TPLAYER_TU_SHARED_CONTEXT
class RGE_Game_World {
public:
    RGE_Static_Object* object(int id);
    char gap_00[0x3C];
    short player_count;
};

class RGE_Master_Static_Object {
public:
    char gap_00[0x10];
    short right_click_table;
    char gap_12[2];
    short object_group;
    char gap_16[0x10];
    short hp;
};

class RGE_Player {
public:
    virtual void set_game_status(); virtual void update();
    virtual void addObject(); virtual void update_dopplegangers();
    virtual void scenario_save(); virtual void do_resign();
    virtual void changeToHumanPlayer(); virtual void changeToComputerPlayer();
    virtual void aiStatus(); virtual void isEnemy(); virtual void isAlly();
    virtual void isNeutral(); virtual void isAllNeutral();
    virtual void setDiplomaticStance(); virtual void loadAIInformation();
    virtual void add_attribute_num(); virtual void removeObject();
    virtual void load_master_object(); virtual void load();
    virtual void scenario_load(); virtual void scenario_postload();
    virtual void sendUnitAIOrder(); virtual void processAIOrder();
    virtual void kickAI(); virtual void strategicNumber();
    virtual void sendGameOrder(); virtual void sendAddWaypointCommand();
    virtual void processAddWaypointCommand(); virtual void sendPlayCommand();
    virtual void processPlayCommand(); virtual void sendAICommand();
    virtual void objectCostByType(); virtual void trackUnitGather();
    virtual void make_scenario_obj(); virtual void save();
    virtual void save2(); virtual void save_info(); virtual void random_start();
    char gap_04[0x38];
    RGE_Game_World* world;
    char gap_40[0x0A];
    short id;
};

class RGE_Static_Object {
public:
    char gap_00[8];
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;
    char gap_10[0x20];
    float range;
    char gap_34[0x14];
    unsigned char object_state;
    char gap_49[5];
    unsigned char type;
    char gap_4f[0x45];
    RGE_Master_Static_Object* special_master;
    int special_owner;
};

class RGE_Progress_Info {
public:
    char gap_00[0x6C];
    float field_6c;
    float field_70;
};

class TRIBE_Game {
public:
    char gap_00[0xA24];
    RGE_Static_Object** selected_table;
    int selected_count;
    RGE_Static_Object** normal_table;
    int normal_count;
};

extern RGE_Base_Game* rge_base_game;

struct RightClickEntry {
    int key;
    int action_1;
    int var_1;
    int action_0;
    int var_0;
    int action_2;
    int var_2;
    int action_3;
    int var_3;
    int action_4;
    int var_4;
};

class TRIBE_Player : public RGE_Player {
public:
    virtual void analyize_selected_objects();
    virtual int get_mouse_pointer_action_vars(int id, int& action, int& var);

    char gap_4c[4];
    RGE_Progress_Info* progress_info;
    char gap_54[0x34];
    int mouse_actions[68];
    int current_action_flags;
    short current_target;
    short gap_19e;
};
#endif

int TRIBE_Player::get_mouse_pointer_action_vars(int id, int& action, int& var)
{
    int object_type;
    int object_player;
    RGE_Static_Object* object;
    int max_hp;
    int right_click_table;
    RGE_Master_Static_Object* master;
    RightClickEntry* entry;
    int use_selection;
    RightClickEntry* table;
    int table_count;
    int action_code;
    int action_var;
    int current;
    object = this->world->object(id);
    entry = 0;
    action = 0;
    var = 0;
    current = 0;
    if (object != 0) {
    if ((int)(long)object->type == 0x19) {
        master = object->special_master;
        object_type = object->special_owner;
        object_player = (short)master->object_group;
        right_click_table = (short)master->right_click_table;
        max_hp = (short)master->hp;
    } else {
        master = object->master_obj;
        object_player = (short)master->object_group;
        object_type = (short)object->owner->id;
        right_click_table = (short)master->right_click_table;
        max_hp = (short)master->hp;
    }

    if (object_type < 0 || object_type >= this->world->player_num) {
        return 0;
    }

    this->analyize_selected_objects();
    if (right_click_table == 0x9e || right_click_table == 0xa3) {
        current = 50;
    }

retry_table:
    if (this->current_target == 0 || this->current_action_flags == 0) {
        TRIBE_Game* game = (TRIBE_Game*)rge_base_game;
        use_selection = 0;
        table = (RightClickEntry*)game->normal_table;
        table_count = game->normal_count;
    } else {
        TRIBE_Game* game = (TRIBE_Game*)rge_base_game;
        use_selection = 1;
        table = (RightClickEntry*)game->selected_table;
        table_count = game->selected_count;
    }

    if (object_player >= 0 && object_player < table_count) {
        RightClickEntry* probe = table + object_player;
        if (probe->key == object_player) {
            entry = probe;
        }
    }
    if (entry == 0) {
        int i = 0;
        RightClickEntry* scan = table;
        while (i < table_count) {
            if (scan->key == object_player) {
                entry = table + i;
                break;
            }
            ++i;
            ++scan;
        }
    }
    if (entry == 0) {
        return 0;
    }

    switch (this->mouse_actions[object_type]) {
    case 0:
        action_code = entry->action_0;
        action_var = entry->var_0;
        break;
    case 1:
        action_code = entry->action_1;
        action_var = entry->var_1;
        break;
    case 2:
        action_code = entry->action_2;
        action_var = entry->var_2;
        break;
    case 3:
        action_code = entry->action_3;
        action_var = entry->var_3;
        break;
    case 4:
        action_code = entry->action_4;
        action_var = entry->var_4;
        break;
    default:
        action_code = -1;
        action_var = -1;
        break;
    }
    if (action_code == -1) {
        return 0;
    }

redo_mouseFunc:
    do {
        switch (action_code) {
        case 0:
            action = 0;
            var = current + action_var;
            goto finish;
        case 1:
        case 8:
            if ((this->current_action_flags & 1) != 0 && object->object_state <= 2) {
                action = 4;
                var = current + action_var;
                goto finish;
            }
            if (action_code != 8) {
                goto finish;
            }
            current = 50;
            action_code = 7;
            continue;
        case 2:
            if ((this->current_action_flags & 2) == 0) {
                goto finish;
            }
            goto set_action_5;
        case 3:
            if ((this->current_action_flags & 4) == 0) {
                goto finish;
            }
            action = 5;
            var = current + action_var;
            goto finish;
        case 4:
            if ((this->current_action_flags & 0x10) == 0) {
                goto finish;
            }
            if (DAT_0086bc8c == 1 && id == DAT_0086bc88) {
                goto finish;
            }
            {
                int hp = (int)object->groupRangeValue;
                if (hp > 0 && hp < max_hp) {
                    goto set_action_5;
                }
            }
            goto finish;
        case 5:
            if ((this->current_action_flags & 0x20) == 0) {
                goto finish;
            }
            if (object->object_state == 0) {
                current = 50;
            }
            {
                int hp = (int)object->groupRangeValue;
                if (hp <= 0 || hp >= max_hp) {
                    goto finish;
                }
            }
            action = 3;
            var = current + action_var;
            goto finish;
        case 6:
        case 9:
            if ((this->current_action_flags & 0x40) != 0) {
                action = 3;
                var = current + action_var;
                goto finish;
            }
            if (action_code != 9) {
                goto finish;
            }
            current = 50;
            action_code = 1;
            continue;
        case 7:
            if ((this->current_action_flags & 0x80) == 0) {
                goto finish;
            }
            if (object_player == 0x12 && this->progress_info->field_6c == DAT_00576828) {
                goto finish;
            }
            if (object_player == 3 && this->progress_info->field_70 == DAT_00576828) {
                goto finish;
            }
            if (object_player == 3 &&
                (right_click_table == 0x6d || right_click_table == 0x114)) {
                goto finish;
            }
            action = 5;
            var = current + action_var;
            goto finish;
        default:
            action = 0;
            var = 0;
            goto finish;
        }
    } while (1);

set_action_5:
    action = 5;
    var = current + action_var;
    goto finish;

finish:
    if (use_selection == 1 && action == 0 && var == 0) {
        this->current_action_flags = 0;
        entry = 0;
        goto retry_table;
    }
    return 1;
    }
    return 0;
}
