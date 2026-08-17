// VA: 004AD960 TRIBE_Screen_Sed::command_save_as
// Attempt log:
// baseline: natural scr_sed.cpp reconstruction with the proven scenario world,
// validation gates, and Save Game Screen construction surface.
// probe: default flags omitted the original EH registration (224 bytes, frame 0xE0).
// probe: /GX restored the 0xE4 frame and all 10 ordered calls, but emitted 313 bytes.
// probe: nested/positive guards, returns, gotos, and a do/while were tested; the
// do/while and positive form merged the two popup call sites, while nested negative
// guards returned to the same 313-byte /GX basin.
// probe: pointer-overlay struct added 8 bytes; a union overlay was codegen-neutral.
// blocker: original popup failures jump at 004AD9BD/004AD9EA to one cleanup at
// 004ADA58; VC5 keeps separate /GX cleanup-and-return blocks for the natural source,
// leaving +41 bytes past the original boundary despite matching frame and calls.
// probe: adding the proven polymorphic Save Game Screen base/destructor surface
// preserved the 313-byte basin; the class model is retained for source plausibility.
// probe: scoping scenario_name to the success arm was codegen-identical; the
// function-scope array is retained because the PDB local begins at the function band.
// probe: a named screen result and an explicit success return were codegen-neutral;
// the 313-byte /GX cleanup-tail basin is independent of those source spellings.
// probe: the decompiler's merged stack window was split experimentally; a separate
// 220-byte name tail changed the frame/CFG, while retaining a 224-byte name and
// zeroing/passing its actual base restored the late constructor/panel blocks and
// raised exact-block coverage to 59.70% (the binary supports name[0], not name[4]).
// probe: the natural else-if spelling is codegen-identical to the nested guards.
// probe: adding the exact 004AD700 same-TU command_save declaration after
// command_save_as did not change the /GX cleanup basin or any emitted byte.
// blocker: both popup failure arms still receive duplicated /GX cleanup-and-return
// blocks instead of the original shared jmp tail at 004ADA58; current source is
// retained as the best canonical reconstruction with the late stack/name topology.
// FLAGS: config/flags/004AD960_command_save_as.rsp (/GX; original EH frame and
// same-TU command_save donor both require the historical exception basin).
// Main-agent audit restored canonical world/panel destructor ownership; emitted
// code and the shared-cleanup blocker are unchanged.
// shardE probe: explicit common done labels with goto, including all three
// arms, remained the 313-byte duplicated-EH basin; restored natural source.
// shardE probe: switch-shaped guards worsened to 330 bytes; named boolean
// predicates worsened to 327 bytes; neither changed the shared-tail blocker.
// sa-b7d0516a pass: explicit done goto, do/while-break, positive nested guards,
// positive nested goto, final return, and a null-panel alias were rechecked;
// none changed the best 313-byte basin or restored the shared cleanup tail.
// sa-4131dd60 pass: immediate popup returns, success-only name scope with failure
// gotos, full donor scenario/world virtual surfaces, the SaveScenario enum cast,
// and an empty RAII scope were tested; the first four were codegen-neutral and
// the RAII scope worsened the frame/CFG. Restored the pinned natural source.
// sa-cd410ac2-r1 pass: flat and full screen layout surfaces, explicit base calls,
// enum types, named count results, control-flow labels, period header contexts,
// and symbol-backed panel strings were tested. Only the last source cleanup was
// retained for policy; the shared /GX cleanup-tail blocker remains unchanged.
// sa-e800da1c-r1 revisit: /O1, /G5, /Oy-, and /Ob0 flag probes either lost the
// EH/frame basin or were codegen duplicates. Reviewed popup int/int parameter
// types, canonical panel constructor ownership, scenario-mode and save-screen
// enum surfaces, a for-loop validation form, and an explicit derived destructor;
// none changed the 313-byte basin. A typed validation status reached 272 bytes
// but merged one popup call and lost the original ordered call set. A 64-sample
// ambient declaration context sweep was codegen-identical in all samples.
// sa-e800da1c-r2 focused TU pass: exact same-file command-save context reached a
// 272-byte exact result even with an empty command_save body. Reduction showed
// that the result needs the narrow full-slot T_Scenario and WorldHolder facades;
// removing those surfaces or inheriting RGE_Scenario restored the 313-byte basin.
// The facades conflict with reviewed RGE_Scenario/T_Scenario/RGE_Game_World
// ownership, so the exact result failed policy audit and was not retained.
// Canonical panel ownership, destructor-owned screen members, and world dtor
// declarations did not change that result. Real throw() specifications on the
// screen constructor/destructors and popup call were neutral or removed EH.
// A period stdio.h context was neutral. Final source is restored to the pinned
// natural typed reconstruction; shared /GX cleanup-tail drift remains.
// sa-3397897f-r1 independent audit: direct popup ownership, save-screen base and
// destructor surfaces, scenario/world virtual surfaces, nested allocation scope,
// cached scenario receiver, and <= 0 predicate variants were tested and restored.
// The current source preserves the observed call order, null-allocation path,
// constructor lifetime, panel side effects, and both validation guards. No
// supported semantic or lifetime variant explains the duplicated normal EH exits.
// BINARY NOTE: both popup failure arms jump to 004ADA58, while natural /GX source
// emits two cleanup-and-return tails and adds 41 bytes after the original boundary.
// The original EH handler is the constructor-allocation cleanup at 0055F50E; it
// does not prove a source branch or object-lifetime difference in the popup arms.
// sa-abc15279-r1 audit: named panel, dialog, scenario, and game-world ownership
// now replaces the former narrow facade types. The audit emits the same 313-byte
// /GX body. The original popup target is TEasy_Panel::popupOKDialog(long, char*,
// int, int), and the world field is the proven TRIBE_World surface.

class TDrawArea;

class TPanel {
public:
    virtual ~TPanel();
    virtual long setup(TDrawArea* render_area, TPanel* parent, long x, long y,
                       long width, long height, unsigned char flags);
    char gap_04[0x1C];
    TDrawArea* render_area;
    char gap_24[0xB4];
    int setup_error;
    char gap_DC[0x18];
};

class PanelNode;

class TPanelSystem {
public:
    TPanel* mouseOwnerValue;
    TPanel* keyboardOwnerValue;
    TPanel* modalPanelValue;
    TPanel* currentPanelValue;
    PanelNode* panelListValue;
    int numberActivePanelsValue;
    TPanel* prevCurrentChildValue;
    void* palette[10];
    char palette_file[10][260];
    int palette_use_count[10];
    long palette_id[10];
    unsigned long Imc;
    int ImeEnabled;
    int ImeOn;
    int InputEnabled;
    int saved_colors;
    unsigned long save_back_color;
    unsigned long save_text_color;

    int setCurrentPanel(char* name, int mode);
    int destroyPanel(char* name);
};

extern TPanelSystem panel_system;
extern char s_Save_Game_Screen[];
extern char s_Scenario_Menu_Dialog[];

class RGE_Static_Object;
struct _iobuf;
typedef struct _iobuf FILE;

class RGE_Scenario {
public:
    virtual RGE_Static_Object* get_object_pointer(int id);
    virtual ~RGE_Scenario();
    virtual void rehook();
    virtual void save(int handle);

    int active_player_count();
    int any_player_count();
};

class T_Scenario : public RGE_Scenario {
public:
    virtual RGE_Static_Object* get_object_pointer(int id);
    virtual ~T_Scenario();
    virtual void rehook();
    virtual void save(int handle);

    void Save_victory_conditions_into_players(int flag);
};

class RGE_Game_World {
public:
    virtual unsigned char data_load_world(FILE* file);
    virtual unsigned char data_load_terrain_tables(char* file);
    virtual unsigned char data_load_players(char* file);
    virtual unsigned char data_load_objects(char* file);
    char gap_04[0x58];
    T_Scenario* scenario;
    char gap_60[0xA4];
};

class TRIBE_World : public RGE_Game_World {
public:
    char gap_104[0x20];
};

class TEasy_Panel : public TPanel {
public:
    virtual ~TEasy_Panel();
    char gap_F4[0x384];
    void popupOKDialog(long text_id, char* panel_name, int param_4, int param_5);
};

class TScreenPanel : public TEasy_Panel {
public:
    virtual ~TScreenPanel();
};

class TribeSaveGameScreen : public TScreenPanel {
public:
    char gap_0478[0x6A4 - 0x478];
    TribeSaveGameScreen(int mode, char* name, int quit_after_save);
};

class TRIBE_Screen_Sed : public TScreenPanel {
public:
    virtual ~TRIBE_Screen_Sed();
    char gap_0478[0x4B0];
    TRIBE_World* world;

    void set_scenario_mode(int mode);
    void command_save_as(unsigned char post_action);
};

void TRIBE_Screen_Sed::command_save_as(unsigned char post_action)
{
    char scenario_name[224];

    this->set_scenario_mode(11);
    this->world->scenario->Save_victory_conditions_into_players(1);
    if (this->world->scenario->active_player_count() < 1) {
        this->popupOKDialog(0x2742, (char*)0, 0x1C2, 100);
    } else if (this->world->scenario->any_player_count() < 1) {
        this->popupOKDialog(0x2743, (char*)0, 0x1C2, 100);
    } else {
        scenario_name[0] = 0;
        new TribeSaveGameScreen(2, scenario_name, post_action);
        panel_system.setCurrentPanel(s_Save_Game_Screen, 0);
        panel_system.destroyPanel(s_Scenario_Menu_Dialog);
    }
}
