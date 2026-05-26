// VA: 00414E80 notify (177B)
// aiuaimod.cpp
// 2026-05-24 Boss pass: replaced placeholder with full behavior from packet. Baseline decompiler-shaped source reached exact size but 67.2316% positional, first mismatch +25 due parameter/register coloring and list-scan topology. Tried msg/target locals in both orders, register locals, direct parameter expressions, original if/else shape, several loop forms (while/do/continue), positive 1FB guard, currentAction local, direct addToNotifyQueue args, explicit max/array locals, volatile/raw-offset variants, goto-fail/shared tail, no-else/break form, and delayed target load. Best kept source (explicit msg/target plus max/arr locals and do loop) improves to 18.6441% positional / 28.8136% edit, first mismatch +25. Remaining drift is register-coloring (msg/target/max/array in different registers), list-scan block shape, and equivalent final addToNotifyQueue argument registers; not accepted_drift-quality because differences are broad control-flow/register topology, not localized benign drift.
// 2026-05-26 Boss pass: matched on try 3. Negative probes: target-before-msg local order
// moved first diff but still wrong final arg registers; hoisting n/max/arr locals failed/regressed.
// Winning shape preserves msg then target locals, but rewrites the 0x2BB scan as an explicit
// `while(1)` with `if(i>=max) goto fail2; ... if(i<n) continue; return 0;` and a separate
// `fail2: return 0;`. This recovers the original loop block order/register coloring and final
// addToNotifyQueue pushes. MATCH.

class RGE_Static_Object {
public:
    char gap_00[0x48];
    unsigned char object_state;
};

class UnitAIModule {
public:
    virtual ~UnitAIModule();
    RGE_Static_Object* objectValue; // +0x04
    char gap_08[0x28];
    int currentActionValue;         // +0x30
    char gap_34[0x2C];
    int* attackingUnitsValue;       // +0x60
    int attackingUnitsNumberValue;  // +0x64
    char gap_68[4];
    int attackingUnitsMaximumSizeValue; // +0x6C

    int notify(int param_1, int param_2, int param_3, long param_4, long param_5, long param_6);
    int addToNotifyQueue(int param_1, int param_2, int param_3, long param_4, long param_5, long param_6);
};

int UnitAIModule::notify(int param_1, int param_2, int param_3, long param_4, long param_5, long param_6)
{
    if (objectValue->object_state != 2)
        return 0;

    int msg = param_3;
    int target = param_1;

    if (msg == 0x2BB) {
        int n = attackingUnitsNumberValue;
        int i = 0;
        if (n <= 0)
            goto fail2;
        int max = attackingUnitsMaximumSizeValue;
        while (1) {
            if (i >= max)
                goto fail2;
            if (attackingUnitsValue[i] == target)
                goto found;
            ++i;
            if (i < n)
                continue;
            return 0;
        }
    } else {
found:
        if ((msg != 0x1FB) || (param_4 == currentActionValue)) {
            if ((msg == 0x1FA) && (param_4 == 0x262) &&
                (currentActionValue != 0x262) && (currentActionValue != 0x268))
                return 1;
            return addToNotifyQueue(param_1, param_2, param_3, param_4, param_5, param_6);
        }
    }
fail2:
    return 0;
}
