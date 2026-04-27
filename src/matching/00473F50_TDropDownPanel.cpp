// Pnl_drop.cpp target: TDropDownPanel::~TDropDownPanel
// initial natural destructor body without /GX emitted only 112 bytes and missed the original EH frame.
// removed the explicit vftable data member once virtual destructors were declared; that fixed +4 member offset drift.
// FLAGS: config\flags\00473F50_TDropDownPanel.rsp

struct PanelNode;
struct TDrawArea;
struct HRGN__;
typedef HRGN__* HRGN;

class TPanel {
public:
    TPanel* previousPanelValue;
    TPanel* previousModalPanelValue;
    int pnl_x;
    int pnl_y;
    int pnl_wid;
    int pnl_hgt;
    char* panelNameValue;
    TDrawArea* render_area;
    int clip_left;
    int clip_top;
    int clip_right;
    int clip_bottom;
    int position_mode;
    int need_redraw;
    int field_3C;
    TPanel* parent_panel;
    TPanel* left_panel;
    TPanel* top_panel;
    TPanel* right_panel;
    TPanel* bottom_panel;
    PanelNode* node;
    PanelNode* first_child_node;
    PanelNode* last_child_node;
    TPanel* curr_child;
    int field_64;
    int field_68;
    int active;
    int field_70;
    int have_focus;
    int field_78;
    int field_7C;
    int field_80;
    int gap_84;
    HRGN clip_rgn;
    int field_8C;
    int field_90;
    int field_94;
    int field_98;
    int left_border;
    int top_border;
    int right_border;
    int bottom_border;
    int min_wid;
    int max_wid;
    int min_hgt;
    int max_hgt;
    int field_BC;
    int field_C0;
    int field_C4;
    int field_C8;
    int field_CC;
    int field_D0;
    int field_D4;
    int field_D8;
    int field_DC;
    int field_E0;
    int field_E4;
    int field_E8;
    unsigned char field_EC;
    unsigned char field_ED;
    unsigned char field_EE;
    unsigned char field_EF;
    unsigned char field_F0;
    unsigned char gap_F1;
    unsigned char field_F2;

    virtual ~TPanel();
    void delete_panel(TPanel** panel);
};

class TTextPanel;
class TButtonPanel;
class TListPanel;
class TScrollBarPanel;

class TDropDownPanel : public TPanel {
public:
    TTextPanel* val_panel;
    TButtonPanel* btn_panel;
    TListPanel* list_panel;
    TScrollBarPanel* scbar_panel;
    int mode;
    short val_num;
    char gap_0A[2];
    long val_wid;
    long val_hgt;
    long btn_wid;
    long btn_hgt;
    long list_wid;
    long list_hgt;
    long scbar_wid;
    long scbar_arrow_hgt;
    long scbar_tab_hgt;
    unsigned char list_is_above;
    char gap_131[3];
    long font_hgt;
    int outline_color;
    int draw_style;
    int draw_val_rect;

    virtual ~TDropDownPanel();
};

TDropDownPanel::~TDropDownPanel() {
    this->delete_panel((TPanel**)&this->btn_panel);
    this->delete_panel((TPanel**)&this->list_panel);
    this->delete_panel((TPanel**)&this->scbar_panel);
    this->delete_panel((TPanel**)&this->val_panel);
}
