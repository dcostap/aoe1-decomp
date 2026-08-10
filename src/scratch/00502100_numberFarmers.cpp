// 00502100 TribeTacticalAIModule::numberFarmers()
// Source: taitacmd.cpp lines 12516-12535
// Size: 249 bytes
// NC: no custom flags (default /O2 /Oy)
//
// Attempt log:
// Probe 1: initial parked reconstruction — 92.3695% positional after rebuild;
//   manual _new/_delete declarations produced the wrong relocation identities
//   and a register-held result, so this was not a useful source baseline.
// Probe 2: use the period ManagedArray<int>::operator[] source shape inline,
//   with the exact operator_new/operator_delete declarations and positive
//   loop guard suggested by the PDB line bands.
// Probe 3: swapped the outer result/index declaration order to test VC5's
//   callee-save coloring; emitted code was unchanged.
// Probe 4: use the natural counted-for form with the index declared in the
//   header, testing whether VC5 assigns the outer induction variable EBX.
// Probe 5: move the index zeroing into its declaration and restore the
//   positive-guarded do-while topology while retaining the shared join.
// Probe 6: variant lab over declaration and new-size spellings; all 12
//   invariant-eligible variants collapsed to the same 15-byte register drift.
// Probe 7: restored the period template ManagedArray<T> surface; duplicate.
// Probe 8: register-qualified the outer index; duplicate.
// Probe 9: reversed explicit zeroing order; duplicate.
// Probe 10: variant lab over inner-copy name, owner tail, and declaration
//   context; all 16 variants collapsed to the same 15-byte drift.
// Best reconstruction: exact call/CFG/size parity; only EBX/EBP coloring
//   differs (outer index versus inlined operator[] new_size).
// Main-agent audit restored canonical polymorphic module/object/master
// ownership; emitted code and the 15-byte coloring drift are unchanged.
// Current session probes: hand-expanded the period ManagedArray growth body,
// then reordered count/index declarations and initialization to match the
// exact same-TU array donor; both emitted the unchanged 15-byte basin.
// Fresh replacement probes (orch-taitacmd-fresh-03):
// - baseline rebuilt the pinned canonical source; exact size/CFG/ordered calls,
//   with the persistent outer-index/new-size EBX/EBP coloring swap.
// - full AIModule/TacticalAIModule inheritance, chained zero assignment,
//   canonical TribeMainDecisionAIModule pointer, postfix increments, a named
//   civilian ID, register-qualified new_size, and exact sibling-style
//   MainDecision layout all duplicated the 15-byte basin.
// - volatile rVal worsened the natural stack increment to 254 bytes; ordinary
//   while topology worsened to 251 bytes and broad drift. Both were rolled back.
// Final clean reconstruction restored and validated: blocker remains localized
//   callee-save coloring only; future lead is original TU/compiler register
//   context or an as-yet-untried natural declaration/lifetime distinction.
// wave20-taitacmd-01 probes (current bounded assignment):
// - function-scope obj/ai/action declarations, game_globals.h context, and
//   operator-scope ManagedArray locals all duplicated the 15-byte basin.
// - removing new_size or caching civilians.value broke the canonical growth
//   surface; an out-of-class operator[] definition, civilians reference alias,
//   long outer index, and combined zero declaration all duplicated the basin.
// - the clean source remains exact in size/CFG/ordered eight-call surface; the
//   only unresolved bytes are the EBX/EBP outer-index/new-size coloring swap.

void* operator_new(unsigned int size);
void __cdecl operator_delete(void* ptr);

class UnitAIModule {
public:
    virtual ~UnitAIModule();
    int currentAction();
};

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    char gap_04[0x0C];
    short id;
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    int id;
    RGE_Master_Static_Object* master_obj;
    char gap_0c[0x68];
    UnitAIModule* unitAI();
};

class MainDecisionAIModule {
public:
    virtual ~MainDecisionAIModule();
    RGE_Static_Object* object(int objectID);
};

template <class T>
class ManagedArray {
public:
    T* value;
    int numberValue;
    int desiredNumberValue;
    int maximumSizeValue;

    T& operator[](int index) {
        if (index > this->maximumSizeValue - 1) {
            int new_size = index + 1;
            T* new_data = (T*)operator_new(new_size * 4);
            if (new_data != 0) {
                for (int i = 0; i < this->maximumSizeValue && i < new_size; i++) {
                    new_data[i] = this->value[i];
                }
                operator_delete(this->value);
                this->value = new_data;
                this->maximumSizeValue = new_size;
            }
        }
        return this->value[index];
    }
};

// Main-agent audit confirmed canonical ManagedArray/AI ownership and retained
// the natural farmer count/growth source.
class TribeTacticalAIModule {
public:
    virtual ~TribeTacticalAIModule();
    char gap_04[0xEC];
    MainDecisionAIModule* md;
    ManagedArray<int> civilians;

    int numberFarmers();
};

int TribeTacticalAIModule::numberFarmers()
{
    int i;
    int rVal;

    i = 0;
    rVal = 0;

    if (this->civilians.numberValue > 0) {
        do {
            RGE_Static_Object* obj = this->md->object(this->civilians[i]);
            if ((obj != 0) && (obj->unitAI() != 0) &&
                (obj->master_obj->id == 0x103)) {
                UnitAIModule* ai = obj->unitAI();
                int action = ai->currentAction();
                if (action != 0x261) {
                    ai = obj->unitAI();
                    action = ai->currentAction();
                    if (action != 0x262)
                        goto next;
                }
                rVal = rVal + 1;
            }
        next:
            i = i + 1;
        } while (i < this->civilians.numberValue);
    }
    return rVal;
}
