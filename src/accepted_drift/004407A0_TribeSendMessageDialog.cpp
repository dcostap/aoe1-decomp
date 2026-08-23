// VA: 004407A0 TribeSendMessageDialog::TribeSendMessageDialog
// FLAGS: config/flags/004407A0_TribeSendMessageDialog.rsp (/GX for the observed EH frame)
// Attempt log:
// 1: initial natural EH-framed reconstruction from packet/decomp; validating codegen basin.
// 2: added /GX response file; frame and EH structure reached 0x80, 49/50 calls, -13 bytes, 86.44% diff.
// 3: split chat-group draw_background predicate into explicit branches; restored missing virtual call (50/50), -9 bytes, 84.78% diff.
// 4: reordered vtable/field initialization and loop surfaces; no localized improvement; exact code remains broad mismatch.
// 5: final validated build is size 1615/1623, frame 0x80/0x80, 50/50 calls, 87.8004% strict diff, first mismatch +002F.
// 6: restored the earlier natural initializer surface (implicit derived
//     vtable store, literal null title, and late check cursor); this is the
//     prior 1376-byte best basin and avoids an explicit vtable/raw-zero hack.
// 7: positive shape guard and an explicit shape-null boolean were optimized
//     to the same code; no structural movement.
// 8: hoisting/reordering the row cursor and y local had no codegen effect.
// 9: raw integer cursor arithmetic for the proven +0x58/player-row relation
//     also collapsed to the same 1376-byte basin; restored typed cursor form.
// 10: assigned the new shape directly to the proven +0x528 owner; strict drift
//     improved by 73 bytes, but the size and block topology stayed structural.
// 11: used the binary-supported positive shape guard around setup; emitted code
//     was unchanged, so no further control-flow lead remains in this basin.
// 12: materialized a named background-missing result after direct +0x528
//     ownership; emitted code and structural metrics were unchanged. Restored
//     the clean candidate; the first unresolved hunk remains the null decision.
// 13: added the same-TU TShape destructor declaration used by the exact
//     destructor donor; emitted code was unchanged, so restored the clean
//     constructor surface. The null-lowering hunk remains structural.
// 14: made shape allocation an assignment-in-condition positive guard; this
//     recovered the oracle's sete/test block family and cut strict drift.
// 15: inverted that guard to test allocation failure directly; null lowering
//     became an exact block through the member store and early exit.
// 16: used the live humanity index for the first player-scan bound; the
//     oracle's cmp/jl gate became exact instead of test/jle.
// 17-18: moved the language buffer around scalar locals; VC5 emitted no
//     change, so the typed declaration order was restored.
// 19-22: named radio-array cursors and varied their lifetimes; the donor-like
//     radio-link block improved in one basin, but the whole function worsened.
//     Restored direct member creation and linking.
// 23-24: block-scoped and separate radio-link indices were codegen duplicates.
// 25: held the created OK panel in a named local; this matched the oracle's
//     one-object reload and improved strict drift to 546 bytes.
// 26: a narrow radio-array alias for the first help call was unchanged; retain
//     it as the binary-supported pointer ownership form.
// 27: passing the language buffer base, not base + 4, restored both observed
//     LEA displacements and improved strict drift from 546 to 544 bytes. Radio
//     register coloring remains the first unresolved structural hunk.
// Main-agent audit replaced fixed string addresses and cross-member pointer
// arithmetic with literals and direct playerName/playerCivilization/checkButton/
// commPlayers row ownership. The canonical source retains all 50 calls.
// Accepted-drift review: current code is exact through +0x3FC. The executable
// changes EBP from zero to the radio-array base. The rebuild keeps EBP zero and
// uses EBX for that base. Residual changes are zero pushes, equivalent LEAs,
// and one zero store. EH state, all calls, publications, links, and returns match.
// Probe 28: the PDB-supported set_radio_info(TPanel*, int) surface and the
// matching cast compile to the same bytes. Keep that ABI instead of the old
// TButtonPanel** proxy.
// Probes 29-35: nested radio-call conditions, aliases, cursor loops, parent
// casts, zero spellings, register hints, headers, and the full factory virtual
// surface did not move the radio register basin. A bounded eight-variant lab
// also produced one /GX code group with the same 544-byte difference.
// BINARY NOTE: PDB lines 209-212 and the original CFG require four separate
// radio-call statements. The nested logical-chain form was not retained.
// Final unresolved lead: the original loads radioButton into EBP at +0x3E3;
// this source loads it into EBX. No natural, PDB-supported source form found
// the EBP basin without harming the exact prefix or the dialog ABI.

class TDrawArea;
class TPanel;
class TTextPanel;
class TEditPanel;
class TButtonPanel;
class TShape;
class TScreenPanel;
class RGE_Player;
class RGE_Game_World;

class TPanel {
public:
    virtual ~TPanel();
    virtual void v04(); virtual void v08(); virtual void v0C(); virtual void v10();
    virtual void v14(); virtual void v18(); virtual void v1C(); virtual void v20();
    virtual void v24(); virtual void v28(); virtual void v2C(); virtual void v30();
    virtual void v34(); virtual void v38(); virtual void v3C(); virtual void v40();
    virtual void v44(); virtual void v48(); virtual void v4C(); virtual void v50();
    virtual void v54(); virtual void v58(); virtual void v5C(); virtual void v60();
    virtual void v64(); virtual void v68(); virtual void v6C(); virtual void v70();
    virtual void v74(); virtual void v78(); virtual void v7C(); virtual void v80();
    virtual void v84(); virtual void v88(); virtual void v8C(); virtual void v90();
    virtual void v94(); virtual void v98(); virtual void v9C(); virtual void vA0();
    virtual void vA4(); virtual void vA8(); virtual void vAC(); virtual void vB0();
    virtual void vB4(); virtual void vB8(); virtual void vBC(); virtual void vC0();
    virtual void vC4(); virtual void vC8(); virtual void vCC(); virtual void vD0();
    virtual void vD4(); virtual void vD8(); virtual void vDC(); virtual void draw_background(int);

    char gap_04[0x10];
    int width;
    int height;
    char gap_1C[4];
    TDrawArea* draw_area;
    char gap_24[0x1C];
    void* parent_panel;
    char gap_44[0x28];
    int active;
    int visible;
    char gap_74[0x14];
    void* clip_rgn;
    char gap_8C[0x54];
    int display_changed_count;
    char gap_E4[0x10];

    TDrawArea* renderArea();
    void set_help_info(long, long);
    void set_curr_child(TPanel*);
};

class TEasy_Panel : public TPanel {
public:
    char gap_F4[0x384];
    virtual ~TEasy_Panel();
    long get_popup_info_id();
    char* get_popup_info_file();
protected:
    virtual int create_text(TPanel*, TTextPanel**, int, long, long, long, long, long, int, int, int);
    virtual int create_text(TPanel*, TTextPanel**, char*, long, long, long, long, long, int, int, int);
    virtual int create_edit(TPanel*, TEditPanel**, char*, short, long, long, long, long, long, long, int, int);
    virtual int create_check_box(TPanel*, TButtonPanel**, long, long, long, long, long, long);
    virtual int create_radio_button(TPanel*, TButtonPanel**, long, long, long, long, long, long);
    virtual int create_button(TPanel*, TButtonPanel**, long, long, long, long, long, long, long, long, long);
};

class TDialogPanel : public TEasy_Panel {
public:
    char gap_478[0x18];
    TDialogPanel(char*);
    virtual int setup(TDrawArea*, TPanel*, long, long, char*, long, int);
};

class TScreenPanel : public TEasy_Panel {};

class TTextPanel : public TPanel {};
class TEditPanel : public TPanel {};

class TButtonPanel : public TPanel {
public:
    char gap_F4[0x1A4];
    int hotkey;
    int hotkey_shift;
    void set_radio_info(TPanel*, int);
};

class TShape {
public:
    char gap_00[0x20];
    TShape(char*, int);
};

class RGE_Player {
public:
    char gap_00[0x80];
    unsigned char game_status;
    char gap_81[0x84];
    unsigned char master_player_id;
};

class RGE_Game_World {
public:
    char gap_00[0x40];
    RGE_Player** players;
};

class RGE_Base_Game {
public:
    virtual ~RGE_Base_Game();
    virtual void v04(); virtual void v08(); virtual void v0C(); virtual void v10();
    virtual void v14(); virtual void v18(); virtual void v1C(); virtual void v20();
    virtual void v24();
    virtual void language(int, int, int, char*, int);
    char gap_04[0x3F0];
    RGE_Game_World* world;
    int playerID(int);
    int multiplayerGame();
    int numberPlayers();
};

class TCommunications_Handler {
public:
    int GetPlayerHumanity(int);
    char* GetPlayerName(int);
    int WhoAmI();
    char gap_00[4];
};

class TChat {
public:
    int inChatGroup(int);
};

extern RGE_Base_Game* rge_base_game;
extern TCommunications_Handler* comm;
extern TChat* chat;
extern void* operator new(unsigned int);

class TribeSendMessageDialog : public TDialogPanel {
public:
    TTextPanel* title;
    TTextPanel* playerName[8];
    TTextPanel* playerCivilization[8];
    TButtonPanel* checkButton[8];
    TTextPanel* radioTitle[4];
    TButtonPanel* radioButton[4];
    TShape* radioButtonShapes;
    TEditPanel* chatInput;
    TTextPanel* chatTitle;
    TButtonPanel* okButton;
    TButtonPanel* help_button;
    TShape* backgroundPics;
    int commPlayers[8];

    TribeSendMessageDialog(TScreenPanel*);
};

TribeSendMessageDialog::TribeSendMessageDialog(TScreenPanel* parent)
    : TDialogPanel("Send Message Dialog")
{
    int humanity;
    int world_humanity;
    RGE_Game_World* world;
    int id;
    char temp_str[100];

    int n;
    title = 0;
    for (n = 0; n < 8; ++n) {
        playerName[n] = 0;
        playerCivilization[n] = 0;
        checkButton[n] = 0;
        commPlayers[n] = 0;
    }
    for (n = 0; n < 3; ++n) {
        radioTitle[n] = 0;
        radioButton[n] = 0;
    }
    chatInput = 0;
    chatTitle = 0;
    okButton = 0;
    help_button = 0;
    backgroundPics = 0;

    if ((backgroundPics = new TShape("dlg_plbn.shp", 0xC63A)) == 0)
        return;
    else {
        if (!setup(parent->renderArea(), parent, 0x208, 0x1D1,
                   parent->get_popup_info_file(), parent->get_popup_info_id(), 1))
            return;

    if (!create_text(this, &title, 0x2667, 5, 10, width - 0x28, 0x1E, 1, 1, 1, 0))
        return;

    humanity = 1;
    world = rge_base_game->world;
    int y = 0x28;
    int row = 0;
    do {
        id = rge_base_game->playerID(humanity);
        if (id != 0) {
            int special = 0;
            if (world->players[id]->game_status == 2) {
                special = 1;
            }
            else if (rge_base_game->multiplayerGame()) {
                world_humanity = 0;
                int j = 1;
                int count = rge_base_game->numberPlayers();
                if (j <= count) {
                    do {
                        if (rge_base_game->playerID(j) == id) {
                            int h = comm->GetPlayerHumanity(j);
                            if (h == 2 || h == 4)
                                world_humanity = h;
                        }
                        ++j;
                        count = rge_base_game->numberPlayers();
                    } while (j <= count);
                }
                if (world_humanity != 2 && world_humanity != 4)
                    special = 1;
            }

            int font = special ? 8 : 11;
            if (!create_text(this, &playerName[row],
                             comm->GetPlayerName(humanity), 0x32, y, 0xBE, 0x1E,
                             font, 0, 1, 0))
                return;

            // BINARY NOTE: The executable passes this buffer base to both
            // language and civilization creation. It does not use a +4 offset.
            rge_base_game->language(0x69, world->players[id]->master_player_id,
                                    0, temp_str, 100);
            if (!create_text(this, &playerCivilization[row],
                             temp_str, 0x104, y, 0x78, 0x1E, 0x0B, 0, 1, 0))
                return;

            if (humanity != comm->WhoAmI()) {
                int h = comm->GetPlayerHumanity(humanity);
                if (h == 2 || comm->GetPlayerHumanity(humanity) == 4) {
                    if (!create_check_box(this, &checkButton[row], 10, y, 0x1E, 0x1E, 0, 0))
                        return;
                    checkButton[row]->set_help_info(0x767F, -1);
                    if (chat->inChatGroup(humanity) != 0)
                        checkButton[row]->draw_background(1);
                    else
                        checkButton[row]->draw_background(0);
                }
            }
            commPlayers[row] = humanity;
            ++row;
            y += 0x1E;
        }
        ++humanity;
    } while (humanity < 9);

    if (!create_text(this, &chatTitle, 0x2668, 10, 0x13B, 0x78, 0x1E, 4, 1, 1, 0))
        return;
    if (!create_edit(this, &chatInput, "", 0x41, 0, 0x82,
                     0x13B, 0x17C, 0x17, 0x0B, 1, 0))
        return;
    chatInput->set_help_info(0x767A, -1);

    if (!create_radio_button(this, &radioButton[0], 0x2D, 0x15E, 0x1E, 0x1E, 0, 0)) return;
    if (!create_radio_button(this, &radioButton[1], 0x113, 0x15E, 0x1E, 0x1E, 0, 0)) return;
    if (!create_radio_button(this, &radioButton[2], 0x2D, 0x181, 0x1E, 0x1E, 0, 0)) return;
    if (!create_radio_button(this, &radioButton[3], 0x113, 0x181, 0x1E, 0x1E, 0, 0)) return;

    if (!create_text(this, &radioTitle[0], 0x2669, 0x4B, 0x15E, 0xC8, 0x1E, 0x0B, 0, 1, 0)) return;
    radioTitle[0]->set_help_info(-1, -1);
    if (!create_text(this, &radioTitle[1], 0x266A, 0x131, 0x15E, 0xC8, 0x1E, 0x0B, 0, 1, 0)) return;
    radioTitle[1]->set_help_info(-1, -1);
    if (!create_text(this, &radioTitle[2], 0x266B, 0x4B, 0x181, 0xC8, 0x1E, 0x0B, 0, 1, 0)) return;
    radioTitle[2]->set_help_info(-1, -1);
    if (!create_text(this, &radioTitle[3], 0x266E, 0x131, 0x181, 0xC8, 0x1E, 0x0B, 0, 1, 0)) return;
    radioTitle[3]->set_help_info(-1, -1);

    for (n = 0; n < 4; ++n)
        radioButton[n]->set_radio_info((TPanel*)radioButton, 4);
    TButtonPanel** radio_buttons = radioButton;
    radioButton[3]->draw_background(1);
    radio_buttons[0]->set_help_info(0x767B, -1);
    radioButton[1]->set_help_info(0x767C, -1);
    radioButton[2]->set_help_info(0x767D, -1);
    radioButton[3]->set_help_info(0x767E, -1);

    if (!create_button(this, &okButton, 0x266C, 0, 100, 0x1A9, 0x12C, 0x1E, 0, 0, 0))
        return;
    okButton->set_help_info(0x7531, -1);
    TButtonPanel* ok = okButton;
    ok->hotkey = 0x1B;
    ok->hotkey_shift = 0;
        set_curr_child(chatInput);
    }
}
