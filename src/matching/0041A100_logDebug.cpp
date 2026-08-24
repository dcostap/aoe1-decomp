#include <stdio.h>
extern "C" int __cdecl vsprintf(char* dest, const char* fmt, char* args);

// BINARY NOTE: 0041A100 is UnitAIModule::logDebug, public virtual varargs,
// at aiuaimod.cpp lines 5932-5942. Its body ends at 0041A14E; the next bytes
// are padding. Keep the preceding 0041A020 purgeNotifyQueue owner separate.
// compact debug logger first
// tried va_start/va_end and a direct stack-address cast for the varargs pack; mismatch stayed on the vsprintf arg-list stack slot
// tried changing textOut+4 to textOut (both vsprintf dest and virtual call arg); original uses plain textOut, not textOut+4
// MATCHED: changed textOut+4 to textOut in both vsprintf dest and virtual call arg — original uses plain textOut
#ifndef AOE1_AIUAIMOD_COMPLETE_TU
class RGE_Static_Object {
public:
    // Slot 0x144 is logDebug. The preceding slots preserve the real vtable
    // position without inventing unrelated object fields.
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43();
    virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47();
    virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51();
    virtual void v52(); virtual void v53(); virtual void v54(); virtual void v55();
    virtual void v56(); virtual void v57(); virtual void v58(); virtual void v59();
    virtual void v60(); virtual void v61(); virtual void v62(); virtual void v63();
    virtual void v64(); virtual void v65(); virtual void v66(); virtual void v67();
    virtual void v68(); virtual void v69(); virtual void v70(); virtual void v71();
    virtual void v72(); virtual void v73(); virtual void v74(); virtual void v75();
    virtual void v76(); virtual void v77(); virtual void v78(); virtual void v79();
    virtual void v80();
    virtual void logDebug(char* text, ...);
};

class UnitAIModule {
public:
    RGE_Static_Object* objectValue;

    virtual void logDebug(char* param_1, ...);
};
#endif

void UnitAIModule::logDebug(char* param_1, ...) {
    char textOut[1024];
    if (this->objectValue != 0) {
        // BINARY NOTE: The variadic receiver uses caller cleanup. Keep the
        // original parameter-home address and the object null-check order.
        vsprintf(textOut, param_1, (char*)&param_1 + 4);
        this->objectValue->logDebug(textOut);
    }
}
