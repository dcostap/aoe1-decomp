// VA: 004A71D0 TRIBE_Dialog_Name::wnd_proc
// PDB: scr_name.cpp lines 429-440
// BINARY NOTE: the shipped body forwards all four parameters to TPanel::wnd_proc.

#ifdef SCR_NAME_TU_CONTEXT
#include "../../include/scr_name_context.h"
#else
class TPanel {
public:
    virtual long wnd_proc(void*, unsigned int, unsigned int, long);
};

class TRIBE_Dialog_Name : public TPanel {
public:
    virtual long wnd_proc(void*, unsigned int, unsigned int, long);
};
#endif

long TRIBE_Dialog_Name::wnd_proc(void* param1, unsigned int param2,
                                 unsigned int param3, long param4)
{
    return TPanel::wnd_proc(param1, param2, param3, param4);
}
