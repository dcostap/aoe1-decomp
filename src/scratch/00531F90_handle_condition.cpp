// RGE_Victory_Conditions::handle_condition — first pass
// VA: 00531F90
#include "../../include/game_globals.h"

// Each handler: __fastcall taking (this, _, entry)
extern void __fastcall _handle_capture(void* _this, void* entry);
extern void __fastcall _handle_create(void* _this, void* entry);
extern void __fastcall _handle_create_in_area(void* _this, void* entry);
extern void __fastcall _handle_destroy(void* _this, void* entry);
extern void __fastcall _handle_destroy_multiple(void* _this, void* entry);
extern void __fastcall _handle_destroy_all(void* _this, void* entry);
extern void __fastcall _handle_destroy_player(void* _this, void* entry);
extern void __fastcall _handle_bring_area(void* _this, void* entry);
extern void __fastcall _handle_bring_object(void* _this, void* entry);
extern void __fastcall _handle_attribute_fn(void* _this, void* entry);
extern void __fastcall _handle_explore(void* _this, void* entry);
extern void __fastcall _handle_victory_points_fn(void* _this, void* entry);

void __fastcall handle_condition(void* _this, void* entry)
{
    switch (*(char*)entry) {
    case 0: _handle_capture(_this, entry); return;
    case 1: _handle_create(_this, entry); return;
    case 2: _handle_destroy(_this, entry); return;
    case 3: _handle_destroy_multiple(_this, entry); return;
    case 4: _handle_bring_area(_this, entry); return;
    case 5: _handle_bring_object(_this, entry); return;
    case 6: _handle_attribute_fn(_this, entry); return;
    case 7: _handle_explore(_this, entry); return;
    case 8: _handle_create_in_area(_this, entry); return;
    case 9: _handle_destroy_all(_this, entry); return;
    case 0xA: _handle_destroy_player(_this, entry); return;
    case 0xC: _handle_victory_points_fn(_this, entry); return;
    }
}
