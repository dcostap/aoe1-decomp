// 00501260 TribeTacticalAIModule::selectBestCommander
// Attempt log:
// 1: Reconstruct from packet with helper: too small due outlined helper.
// 2: Inline ManagedArray operator[] growth at all use sites.
// 3: Fix md at +f0, virtual slot +0x10c, and avoid direct early return: improved to 10.58% positional / 6.26% edit, first mismatch offset 3.
// 4: Tried /Ob0: no codegen change; removed flag.
// 5: Tried /O1: too-small 449-byte text; removed flag.
// 6: Tried /Od: broad 92.66% mismatch from first byte; removed flag.
// 7: Hoisted score local declaration to function scope: worsened first mismatch; rolled back.
// 8: Reordered bestUnit/bestScore/i locals and probed result-initialized-to-minus-one form: best current is 1.51% positional/edit, first mismatch offset 10 from swapped `xor edi` / `or ebp,-1` and local home order.
// BLOCKER: behavior and main body are close, but prologue/control topology differs. Original delays `push ebx` until after the empty-array check and uses the pre-EBX local slots (`result=-1`, `i=0`, saved this) exactly; current VC5 saves EBX immediately because the inlined array-growth blocks use EBX, causing stack-offset drift from offset 3 despite matching most loop bodies.
// 4: Initialize selected unit to -1 and return it directly: improved to 1.08%; remaining store order and score-conversion jump.
// 5: Reorder locals and make vf10c return float with named fscore worsened (extra stack/FPU drift); keep float return but use direct conditional conversion.
// 6: Restore exact local order/value: bestScore=-1, bestUnit=-1, i=0; direct return bestUnit. Validates exact before promotion.

extern void* operator new(unsigned int);
extern void operator delete(void*);
extern "C" int __cdecl _ftol();

struct ManagedArray_int { int* value; int numberValue; int desiredNumberValue; int maximumSizeValue; };

class MasterObject { public: char pad_00[0x10]; short type; };
class RGE_Static_Object {
public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60();
    virtual void v61();
    virtual void v62();
    virtual void v63();
    virtual void v64();
    virtual void v65();
    virtual void v66();
    virtual float vf10c();
    char pad_04[4];
    MasterObject* master_obj;
    char pad_0c[0x24];
    float field_30;
};
class MainDecisionAIModule { public: RGE_Static_Object* object(int id); };
class TribeTacticalAIModule {
public:
    char pad_000[0x0f0]; MainDecisionAIModule* md; char pad_0f4[0x2c0-0x0f4]; int mode;
    int selectBestCommander(ManagedArray_int* a);
};

int TribeTacticalAIModule::selectBestCommander(ManagedArray_int* a)
{
    int bestScore = -1;
    int bestUnit = -1;
    int i = 0;
    if (a->numberValue > 0) {
    do {
        if (i > a->maximumSizeValue - 1) {
            int newMax = i + 1;
            int* n = (int*)operator new(newMax * 4);
            if (n) {
                int j = 0;
                while (j < a->maximumSizeValue && j < newMax) { n[j] = a->value[j]; ++j; }
                operator delete(a->value); a->value = n; a->maximumSizeValue = newMax;
            }
        }
        int id = a->value[i];
        RGE_Static_Object* obj = this->md->object(id);
        if (obj != 0) {
            if (obj->master_obj->type != 0x7d) {
                int score;
                if (this->mode == 2) {
                    score = (int)obj->vf10c();
                } else {
                    score = (int)obj->field_30;
                }
                if (this->mode == 1 || this->mode == 3) {
                    if (bestScore == -1 || score < bestScore) {
                        if (i > a->maximumSizeValue - 1) {
                            int newMax = i + 1;
                            int* n = (int*)operator new(newMax * 4);
                            if (n) { int j = 0; while (j < a->maximumSizeValue && j < newMax) { n[j] = a->value[j]; ++j; } operator delete(a->value); a->value = n; a->maximumSizeValue = newMax; }
                        }
                        bestUnit = a->value[i];
                        bestScore = score;
                    }
                } else {
                    if (bestScore == -1 || score > bestScore) {
                        if (i > a->maximumSizeValue - 1) {
                            int newMax = i + 1;
                            int* n = (int*)operator new(newMax * 4);
                            if (n) { int j = 0; while (j < a->maximumSizeValue && j < newMax) { n[j] = a->value[j]; ++j; } operator delete(a->value); a->value = n; a->maximumSizeValue = newMax; }
                        }
                        bestUnit = a->value[i];
                        bestScore = score;
                    }
                }
            }
        }
        ++i;
    } while (i < a->numberValue);
    }
    return bestUnit;
}
