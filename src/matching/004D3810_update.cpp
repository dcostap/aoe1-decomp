// 004D3810 TRIBE_Action_Wonder::update (tact_wnd.cpp:152-179)
// 204 bytes, virtual uchar __thiscall update(void)
// FLAGS: default
//
// === Attempt log ===
// probes 1-3: baseline hand-shaped dispatch and switch-only variants; switch improved
// structural alignment but remained 192 bytes and retained wrong FPU/call ownership.
// probe 4: restored the prior natural switch/countdown nesting and f+f timer form;
// this is the best prior period-plausible reconstruction to rebaseline (28-byte drift).
// probes 5-7: switch case reordering, an explicit case-6 cleanup label, and the
// canonical RGE_Base_Game local name did not move emitted bytes.
// probe 8: positive case-2 predicate with direct return on set_state and explicit
// cleanup fallthrough recovered the original cold-case/timer-cleanup block layout.
// probe 9: long,long set_countdown_timer ABI declaration preserved the exact bytes
// and the proven decorated helper identity.
// Exact source shape is intentionally ordinary switch/guard code plus a shared
// cleanup label: the label expresses the binary-proven FPU cleanup before the
// common return and is not register/byte steering or an asm substitute.

#include "../../include/game_globals.h"

static const float LIMIT = 2000.0f;

unsigned char TRIBE_Action_Wonder::update()
{
    switch (this->state) {
    case 6:
        if (this->field_2C >= LIMIT) return 0;

        {
            float f = this->object->owner->world->world_time_delta_seconds;
            this->field_2C = (f + f) + this->field_2C;

            if (rge_base_game->world->countdown_active != 0) {
                goto cleanup;
            }

            int pid = this->object->owner->id;
            rge_base_game->set_countdown_timer(pid, (int)(LIMIT - this->field_2C));

            if (this->field_2C >= LIMIT) {
                RGE_Player* pl = this->object->owner;
                pl->win_game_now();
                rge_base_game->world->wonder_state = 100;
            }
        }
        goto cleanup;

    case 2:
        if (this->object->object_state == 2) {
            this->set_state(6);
            return 0;
        }
        goto cleanup;

cleanup:
        return 0;

    default:
        return 0;
    }
}
