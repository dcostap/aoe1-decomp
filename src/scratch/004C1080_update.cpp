// VA: 004C1080 RGE_Sprite::update (123 B)
// PDB source: sprite.cpp lines 955-975
//
// Status: STUCK — instruction scheduling diff.
//
// First 11 bytes match (push ecx/bx/si, mov esi, push di). Then VC5 schedules
// differently: (1) param_1 loaded AFTER branch in first-time path (original loads
// before), (2) delta_time=1 stored before last_time in first-time path (original
// does last_time first), (3) accumulate path compares before storing delta_time
// (original stores before compare). These are VC5 internal scheduler decisions.
//
// Best: 53.66% positional, 38.21% edit diff. No source form tried (comma op,
// temp locals, register hints, inverted ops) controls VC5's scheduler to match
// the original's exact order. Multiple prior passes exhausted variants.
//
// No accepted_drift: 54% positional diff, broad scheduling/layout drift.
// Top-20 scratch retry notes:
// try 1: baseline validation in current tree: exact size 123B but 107 positional diff bytes / 86.99%; current source no longer hits old best and omits original EBX save.
// try 2: introduced explicit `new_dt` local and compared that rather than `this->delta_time`; worsened scheduling/arithmetic, rolled back.
// try 3: tried `register int old_time`; no improvement, same no-EBX basin.
// try 4: tried `volatile int old_time`; worsened stack-slot scheduling, rolled back.
// try 5: /GX probe; no code/size improvement, removed flag.
// try 6: reviewed original target shape: wants EBX saved at entry, param loaded before the zero-delta branch, first-time path stores last_time before delta_time, accumulate path stores delta_time before compare, and retains redundant `if (pS)` test before delete.
// try 7: reviewed current rebuilt shape: no EBX save, param load after branch in first-time path, delta_time store before last_time, compare before delta_time store, and delete block lacks redundant null test.
// tries 8-9: prior scratch already records comma/temp/register/inverted-op variants and flags; no retained variant produced the original scheduler/register basin.
// try 10: accepted_drift review rejected: mismatch is broad scheduling/layout/register-save drift across prologue, both time-update paths, delete block, and epilogues. GIVEUP.
// Retry 2026-05-19:
// try 11: revalidated assigned target baseline: exact size 123B but 107 positional bytes / 86.99%; no EBX save, scheduler differs in both update paths.
// try 12: introduced `time` temp and `register old_time`/`new_dt`; worsened arithmetic order, still no EBX save; rolled back.
// try 13: hoisted old_time before zero-delta test to increase live pressure; added early load but still no EBX save and worse schedule; rolled back.
// try 14: /G5 flag probe; no codegen change, removed flag.
// try 15: tried `delete pS` instead of explicit destructor+operator_delete; identical codegen to explicit form, restored explicit form.
// try 16: assignment-in-condition for delta_time threshold; no codegen improvement, kept only because it compiles to same current baseline.
// GIVEUP: remaining issue still broad VC5 scheduling/register allocation (missing EBX save/use, param load after branch, first-time stores reversed, compare/store order reversed, delete redundant test optimized out). Not accepted_drift.
// Retry 2026-05-19/20 assigned pass:
// try 17: introduced `time = param_1` and explicit elapsed/new_dt locals; restored EBX save and improved from 86.99% to old-best 53.6585%, but still schedules param load after zero-delta branch and reverses first-path store order / compare-store order.
// try 18: moving `time` declaration inside the loaded/shape block produced identical codegen to try 17.
// try 19: volatile last_time stores did not affect scheduling; rolled back.
// try 20: separated new_dt store then compared local; VC5 still compared before store.
// try 21: compared `this->delta_time` after store with volatile delta_time field; forced store+reload before compare but worsened layout/size (52.8455% positional, bad tail truncation); rolled back.
// try 22: reloaded `shape` into pS2 to preserve redundant null test before delete; did preserve test but overgrew/truncated tail and worsened layout; rolled back.
// try 23: /Ob0 flag improved to 35.7724% and exact size but inserted an extra `push 0` before the shape destructor call, so rejected/flag removed.
// try 24: fake non-dtor destroy() call removed /Ob0 extra push but is not a valid source model and returned to 53.6585%; rolled back.
// Final remains default flags, 123B, 53.6585% positional / 38.2114% edit, first mismatch offset 12. No accepted_drift: broad scheduler/layout drift across both time paths and delete block.
// Retry 2026-05-19 late pass:
// try 25: register dt no change.
// try 26: volatile pointer reload of param after dt improved to 48.7805% / 37.3984% by loading param before the zero-delta branch and fixing first-time store order; kept.
// try 27: declaring time before dt lost EBX-save basin and regressed to 86.9919%; rolled back.
// try 28: volatile time local regressed to 86.1789%; rolled back.
// try 29: assignment-in-condition for dt with early param load regressed to 86.9919%; rolled back.
// try 30: comparing this->delta_time after store did not change compare/store order.
// try 31: volatile new_dt local slightly improved positional to 47.9675% but edit diff worsened to 49.5935%; rolled back.
// try 32: /Ob1 and /Og flag probes no better than kept source; removed flags.
// GIVEUP: best kept default-flags source is 123B, 48.7805% positional / 37.3984% edit, first mismatch offset 12. It fixes early param-load/store ordering but still has broad register/scheduler/layout drift (dt in EDX not ECX, compare before delta store, no redundant delete null test). Not accepted_drift.
// Retry assigned 2026-05-20:
// try 33: baseline revalidation: same 48.7805% positional / 37.3984% edit, first mismatch +12.
// try 34: removed volatile param reload to recover ECX=dt; regressed to 53.6585%, param load delayed and first-path stores reversed.
// try 35: volatile int dt forced stack frame / no EBX-save basin, 89.4309%; rolled back.
// try 36: register-qualified param declaration/definition: no codegen change from kept baseline.
// try 37: duplicated `time = param_1` in if/else around zero-delta test; same as no-volatile 53.6585%, rolled back.
// try 38: inverted zero test to put nonzero path first; worsened layout to 60.9756% and moved first-time path out of line.
// try 39: assignment-in-condition `(this->delta_time = new_dt) >= ...`; no change from kept baseline.
// try 40: `dt + elapsed` operand order for new_dt; no change.
// try 41: /Ob0 with current source still emits extra `push 0` before destructor call; 48.7805%, rejected and flag removed.
// try 42: /O1 and /Os flag probes produced too-small .text (100B < configured 123B); removed flags.
// try 43: reversed threshold spelling `180000 <= new_dt`; no codegen change from kept baseline.
// GIVEUP: leave in scratch. Not accepted_drift: differences remain broad scheduler/register/layout drift across both update paths and delete block, not a localized harmless encoding/scheduling swap.
// Retry 2026-05-21 Boss pass: 10 more probes. Tried dt-before-param with volatile reload after FPU test, plain dt/time locals to recover ECX/EAX, function-scope time/dt locals, volatile delta reload after store, redundant shape reload before delete, delete-expression form, assignment-in-condition store+compare, float zero comparison, explicit goto tails, and dt+elapsed operand/source-order variants. Best remains the kept default-flags source at 123B, 48.7805% positional / 37.3984% edit, first mismatch +12. Most variants lost the EBX-save basin and mismatched from +1; none fixed the compare-before-delta-store or delete-block layout. Still no accepted_drift: broad scheduler/register/layout drift, not a localized benign swap.

struct TShape {
    ~TShape();
};

void operator_delete(void* ptr);

struct RGE_Sprite {
    char field_00[0x14];
    unsigned char loaded;
    char field_15[0x07];
    TShape* shape;
    unsigned long last_time;
    int delta_time;

    void update(unsigned long param_1);
};

void RGE_Sprite::update(unsigned long param_1) {
    if (loaded) {
        TShape* pS = shape;
        if (pS) {
            int dt = delta_time;
            volatile unsigned long* ptime = &param_1;
            unsigned long time = *ptime;
            if ((double)dt == 0.0) {
                this->last_time = time;
                this->delta_time = 1;
                return;
            }
            int old_time = this->last_time;
            int elapsed = time - old_time;
            this->last_time = time;
            int new_dt = elapsed + dt;
            this->delta_time = new_dt;
            if (180000 <= new_dt) {
                if (pS) {
                    pS->~TShape();
                    operator_delete(pS);
                }
                this->shape = 0;
            }
        }
    }
}
