// VA: 00462670 TMusic_System::resume_play (207B)
// Source: music.cpp lines 779-820
// Attempt log:
// Baseline: canonical TMusic_System offsets and natural resume dispatch.
// Probe 2: switch preserved the decrement dispatch but merged the identical MCI arms.
// Probe 3: nested if/else followed the decompiler shape but moved the dispatch farther away.
// Probe 4: duplicate switch-arm predicates restored both MCI calls but changed the zero-test basin.
// Probe 5: spelling the outer guard as truthiness was tested after an unchanged explicit comparison.
// Probe 6: retain the negative early-return guard while keeping duplicated MCI checks.
// Probe 7: materialize the device-open guard value before the remaining state checks.
// Probe 8: use unary negation for the three early state checks.
// Probe 9: split the three early returns so each field has an independent test.
// Probe 10: split guards worsened CFG/size; restored the combined negative guard and duplicate MCI arms.
// Fresh pass orch-luna-462670-w3: nested positive guards and a common success block were codegen duplicates.
// Fresh pass: signed >0 predicates worsened the early CFG (177 diff bytes); restored.
// Fresh pass: same-TU gap-only TMusic_System layout, bool playing_track, and a common no_resume label were nonproductive.
// Fresh pass: negated conjunction, narrow volatile/raw guard reads, and named guard locals did not leave the zero-register basin.
// Fresh pass: period mmsystem.h/MCI_PLAY_PARMS API context compiled but emitted the same 176-byte mismatch and is retained as the canonical SDK surface.
// Fresh pass result: natural source retained; all 10 hypotheses exhausted. Persistent gap is VC5 zero-register/compare basin in the line-782 guard and zero stores/pushes; call set, size, CFG counts, and field ownership are otherwise aligned.
// Current session hypothesis 1: restore the older natural result-local/default dispatch
// shape; its emitted code previously preserved the original load/test and immediate-zero
// stores, while the newer direct duplicate-call shape shared a zero register too early.
// Current session hypothesis 2: restoring duplicated per-case notify tests recovered both
// indirect calls but returned to the prior zero-register basin.
// Current session hypothesis 3: scoped result locals in each MCI case preserved both calls
// and the original liveness; exact match.
// Main-agent audit confirmed canonical non-polymorphic music/WinMM ownership and
// natural state dispatch; exact bytes were revalidated after promotion.

#include "../../include/music_context.h"

int TMusic_System::resume_play()
{
    if (this->device_open == 0 || this->playing_track == 0 || this->paused == 0) {
        return 0;
    }

    this->paused = 0;
    this->auto_paused = 0;

    if (this->fading_track != 0) {
        this->end_fade();
        return 1;
    }

    switch (this->music_type) {
    case 1: {
        int result = mciSendCommandA(this->device_id, 0x806, 0,
                                     (unsigned long)&this->play_info);
        if (result == 0) {
            this->notify_waiting++;
        }
        break;
    }
    case 2: {
        int result = mciSendCommandA(this->device_id, 0x806, 0,
                                     (unsigned long)&this->play_info);
        if (result == 0) {
            this->notify_waiting++;
        }
        break;
    }
    case 3:
        if (this->sound_system != 0) {
            this->sound_system->resume_stream();
            return 1;
        }
        break;
    }
    return 1;
}
