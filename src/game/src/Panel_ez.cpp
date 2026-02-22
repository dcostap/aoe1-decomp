#include "../include/TEasy_Panel.h"
#include "../include/TButtonPanel.h"
#include "../include/TTextPanel.h"
#include "../include/TDropDownPanel.h"
#include "../include/TListPanel.h"
#include "../include/TScrollBarPanel.h"
#include "../include/TDrawArea.h"
#include "../include/TDrawSystem.h"
#include "../include/TShape.h"
#include "../include/RGE_Color_Table.h"
#include "../include/Res_file.h"
#include "../include/RGE_Base_Game.h"
#include "../include/TMousePointer.h"
#include "../include/RGE_Font.h"
#include "../include/TMessageDialog.h"
#include "../include/globals.h"
#include "../include/TMessageDialog.h"
#include "../include/custom_debug.h"

#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// NOTE: This file is a best-effort reimplementation based on immutable references:
// `src/game/src/Panel_ez.cpp.asm` and `src/game/src/Panel_ez.cpp.decomp`.

static int is_none_token(const char* s) {
    if (!s) return 1;
    return (_stricmp(s, "none") == 0) || (s[0] == '\0');
}

static void trim_in_place(char* s) {
    if (!s) return;
    size_t len = strlen(s);
    while (len > 0) {
        char c = s[len - 1];
        if (c != '\r' && c != '\n' && c != ' ' && c != '\t') break;
        s[len - 1] = '\0';
        len--;
    }
    char* p = s;
    while (*p == ' ' || *p == '\t') p++;
    if (p != s) memmove(s, p, strlen(p) + 1);
}

class EasyPseudoEditPanel : public TTextPanel {
public:
    EasyPseudoEditPanel(short max_len, FormatType format, int auto_sel) {
        this->max_len_ = (max_len > 1) ? (max_len - 1) : 259;
        if (this->max_len_ > 259) {
            this->max_len_ = 259;
        }
        this->format_ = format;
        this->auto_sel_ = auto_sel;
        this->select_all_ = 0;
        this->buffer_[0] = '\0';
        this->len_ = 0;
    }

    void easy_set_text(const char* text) {
        this->buffer_[0] = '\0';
        this->len_ = 0;
        if (text != nullptr) {
            strncpy(this->buffer_, text, (size_t)this->max_len_);
            this->buffer_[this->max_len_] = '\0';
            this->len_ = (int)strlen(this->buffer_);
        }
        TTextPanel::set_text(this->buffer_);
        this->set_redraw(TPanel::RedrawMode::Redraw);
    }

    const char* easy_text() const {
        return this->buffer_;
    }

    virtual void set_focus(int param_1) override {
        TTextPanel::set_focus(param_1);
        if ((param_1 != 0) && (this->auto_sel_ != 0)) {
            this->select_all_ = 1;
        }
    }

    virtual long key_down_action(long param_1, short param_2, int param_3, int param_4, int param_5) override {
        (void)param_2;
        (void)param_3;
        (void)param_4;
        (void)param_5;

        if (param_1 == VK_BACK || param_1 == VK_DELETE) {
            if (this->select_all_ != 0) {
                this->easy_set_text("");
                this->select_all_ = 0;
                return 1;
            }
            if (this->len_ > 0) {
                this->buffer_[this->len_ - 1] = '\0';
                this->len_--;
                TTextPanel::set_text(this->buffer_);
                this->set_redraw(TPanel::RedrawMode::Redraw);
            }
            return 1;
        }

        if (param_1 == VK_RETURN) {
            if (this->parent_panel != nullptr) {
                this->parent_panel->action(this, 0, 0, 0);
                return 1;
            }
        } else if (param_1 == VK_ESCAPE) {
            if (this->parent_panel != nullptr) {
                this->parent_panel->action(this, 1, 0, 0);
                return 1;
            }
        }

        return 0;
    }

    virtual long char_action(long param_1, short param_2) override {
        if (param_2 <= 0) {
            param_2 = 1;
        }

        if (param_1 < 0x20) {
            return 1;
        }

        while (param_2-- > 0) {
            char ch = (char)param_1;
            if (!this->allow_char(ch)) {
                MessageBeep(0xffffffff);
                return 1;
            }

            if (this->select_all_ != 0) {
                this->buffer_[0] = '\0';
                this->len_ = 0;
                this->select_all_ = 0;
            }

            if (this->len_ >= this->max_len_) {
                MessageBeep(0xffffffff);
                return 1;
            }

            this->buffer_[this->len_] = ch;
            this->len_++;
            this->buffer_[this->len_] = '\0';
        }

        TTextPanel::set_text(this->buffer_);
        this->set_redraw(TPanel::RedrawMode::Redraw);
        return 1;
    }

private:
    bool allow_char(char c) {
        if (this->format_ == FormatNumber || this->format_ == FormatInteger || this->format_ == FormatUnsignedInt) {
            if (c >= '0' && c <= '9') {
                return true;
            }
            if (c == '-' && this->len_ == 0 && this->format_ != FormatUnsignedInt) {
                return true;
            }
            if (c == '.' && this->format_ == FormatNumber) {
                return strchr(this->buffer_, '.') == nullptr;
            }
            return false;
        }

        if (this->format_ == FormatFile || this->format_ == FormatFileNoExt) {
            if (c == '.' && this->format_ == FormatFileNoExt) {
                return false;
            }
            if (c == '\\' || c == '/' || c == ':' || c == '"' || c == '*' || c == '?' || c == '<' || c == '>' || c == '|') {
                return false;
            }
            return true;
        }

        if (this->format_ == FormatPath) {
            if (c == '"' || c == '*' || c == '?' || c == '<' || c == '>' || c == '|') {
                return false;
            }
            if (c == ':' && this->len_ != 1) {
                return false;
            }
            return true;
        }

        if (this->format_ == FormatPercent) {
            if (c < '0' || c > '9') {
                return false;
            }
            if (this->len_ >= 2) {
                return false;
            }
            return true;
        }

        return isprint((unsigned char)c) != 0;
    }

private:
    char buffer_[260];
    int len_;
    int max_len_;
    FormatType format_;
    int auto_sel_;
    int select_all_;
};

static void init_vars(TEasy_Panel* this_) {
    // Matches `TEasy_Panel::init_vars` in `src/game/src/Panel_ez.cpp.decomp` (immutable reference).
    this_->ideal_width = 0x280;
    this_->ideal_height = 0x1e0;
    this_->info_file_name[0] = '\0';
    this_->info_id = -1;
    this_->background_pic = nullptr;
    this_->background_pic2 = nullptr;
    this_->palette = nullptr;
    this_->cursor_file[0] = '\0';
    this_->cursor_id = -1;
    this_->background_pos = 0;
    this_->use_bevels = 0;
    this_->bevel_color1 = 0;
    this_->bevel_color2 = 0;
    this_->bevel_color3 = 0;
    this_->bevel_color4 = 0;
    this_->bevel_color5 = 0;
    this_->bevel_color6 = 0;
    this_->text_color1 = 0x00ffffff;
    this_->text_color2 = 0;
    this_->focus_color1 = 0x0000ffff;
    this_->focus_color2 = 0;
    this_->state_color1 = 0x00ffffff;
    this_->state_color2 = 0;
    this_->popup_info_file_name[0] = '\0';
    this_->popup_info_id = -1;
    this_->button_pics = nullptr;
    this_->shadow_color_table = nullptr;
    this_->background_color1 = 0;
    this_->background_color2 = 0;
    this_->enable_ime = 0;
    this_->help_mode = 0;
    this_->stock_brush = 0;
    this_->brush = nullptr;
    this_->brush_color = 0;
    this_->shadow_amount = 0;
    this_->shadow_area = nullptr;
    this_->saved_mouse_mode = 0;
    this_->allow_shadow_area = 0;
}

TEasy_Panel::TEasy_Panel() : TPanel(nullptr) {
    init_vars(this);
}

TEasy_Panel::TEasy_Panel(char* name) : TPanel(name) {
    init_vars(this);
}

TEasy_Panel::~TEasy_Panel() {
CUSTOM_DEBUG_BEGIN
    CUSTOM_DEBUG_LOG_FMT("TEasy_Panel dtor: begin panel='%s' this=%p", this->panelNameValue ? this->panelNameValue : "(null)", this);
    CUSTOM_DEBUG_LOG_FMT(
        "TEasy_Panel dtor state: bg1=%p bg2=%p btn_pics=%p shadow_area=%p shadow_ct=%p palette=%p brush=%p stock_brush=%d",
        this->background_pic,
        this->background_pic2,
        this->button_pics,
        this->shadow_area,
        this->shadow_color_table,
        this->palette,
        this->brush,
        this->stock_brush);
CUSTOM_DEBUG_END

    // Best-effort match for `prepare_for_close` behavior; keep minimal for now.
    if (this->background_pic) {
CUSTOM_DEBUG_BEGIN
        CUSTOM_DEBUG_LOG_FMT("TEasy_Panel dtor: deleting background_pic=%p", this->background_pic);
CUSTOM_DEBUG_END
        delete this->background_pic;
        this->background_pic = nullptr;
    }
    if (this->background_pic2) {
CUSTOM_DEBUG_BEGIN
        CUSTOM_DEBUG_LOG_FMT("TEasy_Panel dtor: deleting background_pic2=%p", this->background_pic2);
CUSTOM_DEBUG_END
        delete this->background_pic2;
        this->background_pic2 = nullptr;
    }
    if (this->button_pics) {
CUSTOM_DEBUG_BEGIN
        CUSTOM_DEBUG_LOG_FMT("TEasy_Panel dtor: deleting button_pics=%p", this->button_pics);
CUSTOM_DEBUG_END
        delete this->button_pics;
        this->button_pics = nullptr;
    }
    if (this->shadow_area) {
CUSTOM_DEBUG_BEGIN
        CUSTOM_DEBUG_LOG_FMT("TEasy_Panel dtor: deleting shadow_area=%p", this->shadow_area);
CUSTOM_DEBUG_END
        delete this->shadow_area;
        this->shadow_area = nullptr;
    }
    if (this->shadow_color_table) {
        if (this->render_area && this->render_area->shadow_color_table == this->shadow_color_table) {
CUSTOM_DEBUG_BEGIN
            CUSTOM_DEBUG_LOG_FMT(
                "TEasy_Panel dtor: clearing render_area stale shadow table area=%p table=%p",
                this->render_area,
                this->shadow_color_table);
CUSTOM_DEBUG_END
            this->render_area->SetShadowTable(nullptr);
        }
CUSTOM_DEBUG_BEGIN
        CUSTOM_DEBUG_LOG_FMT("TEasy_Panel dtor: deleting shadow_color_table=%p", this->shadow_color_table);
CUSTOM_DEBUG_END
        delete this->shadow_color_table;
        this->shadow_color_table = nullptr;
    }
    if (this->palette && panel_system) {
CUSTOM_DEBUG_BEGIN
        CUSTOM_DEBUG_LOG_FMT("TEasy_Panel dtor: releasing palette=%p via panel_system=%p", this->palette, panel_system);
CUSTOM_DEBUG_END
        panel_system->release_palette(this->palette);
        this->palette = nullptr;
    }
    if (this->brush) {
CUSTOM_DEBUG_BEGIN
        CUSTOM_DEBUG_LOG_FMT("TEasy_Panel dtor: brush still set (not freed here) brush=%p stock=%d", this->brush, this->stock_brush);
CUSTOM_DEBUG_END
    }

CUSTOM_DEBUG_BEGIN
    CUSTOM_DEBUG_LOG_FMT("TEasy_Panel dtor: end panel='%s' this=%p", this->panelNameValue ? this->panelNameValue : "(null)", this);
CUSTOM_DEBUG_END
}

// Source of truth: panel_ez.cpp.decomp @ 0x00469EE0
void TEasy_Panel::popupOKDialog(long text_id, char* panel_name, int param_4, int param_5) {
    char text[256];
    this->get_string(text_id, text, sizeof(text));
    this->popupOKDialog(text, panel_name, param_4, param_5);
}

// Source of truth: panel_ez.cpp.decomp @ 0x00469F30
void TEasy_Panel::popupOKDialog(char* text, char* panel_name, int param_4, int param_5) {
    if (panel_name == nullptr || *panel_name == '\0') {
        panel_name = (char*)"OKDialog";
    }

    if (panel_system) {
        TPanel* existing = panel_system->panel(panel_name);
        if (existing != nullptr) {
            panel_system->destroyPanel(panel_name);
        }
    }

    TMessageDialog* dlg = new TMessageDialog(panel_name);
    if (dlg != nullptr) {
        dlg->setup((TPanel*)this, this->popup_info_file_name, this->popup_info_id, param_4, param_5, 0, text, 0x5a, 0x1e);
    }
}

// Source of truth: panel_ez.cpp.decomp @ 0x0046A040
void TEasy_Panel::popupYesNoDialog(long text_id, char* panel_name, int param_4, int param_5) {
    char text[256];
    this->get_string(text_id, text, sizeof(text));
    this->popupYesNoDialog(text, panel_name, param_4, param_5);
}

// Source of truth: panel_ez.cpp.decomp @ 0x0046A090
void TEasy_Panel::popupYesNoDialog(char* text, char* panel_name, int param_4, int param_5) {
    if (panel_name == nullptr || *panel_name == '\0') {
        panel_name = (char*)"YesNoDialog";
    }

    TMessageDialog* dlg = new TMessageDialog(panel_name);
    if (dlg != nullptr) {
        dlg->setup((TPanel*)this, this->popup_info_file_name, this->popup_info_id, param_4, param_5, 2, text, 0x5a, 0x1e);
    }
}

// Virtual setup (base signature): forward to TPanel::setup.
long TEasy_Panel::setup(TDrawArea* param_1, TPanel* param_2, long param_3, long param_4, long param_5, long param_6, uchar param_7) {
    return TPanel::setup(param_1, param_2, param_3, param_4, param_5, param_6, param_7);
}

static void set_info_file(TEasy_Panel* this_, char* info_file, long info_id) {
    this_->info_id = info_id;
    if (info_file) {
        strncpy(this_->info_file_name, info_file, sizeof(this_->info_file_name) - 1);
        this_->info_file_name[sizeof(this_->info_file_name) - 1] = '\0';
    } else {
        this_->info_file_name[0] = '\0';
    }
}

struct EasyCfgBackground {
    char file1[260];
    char file2[260];
    long id1;
    long id2;
};

struct EasyCfg {
    EasyCfgBackground bg1;
    EasyCfgBackground bg2;
    EasyCfgBackground bg3;
    char pal_file[260];
    long pal_id;
    char cursor_file[260];
    long cursor_id;
    int shade_amount_percent;
    char button_file[260];
    long button_id;
    char popup_file[260];
    long popup_id;
    int background_pos;
    int background_color;
    // -1 = not specified in cfg text (use heuristic)
    int use_bevels;
    int bevel[6];
    int text1[3];
    int text2[3];
    int focus1[3];
    int focus2[3];
    int state1[3];
    int state2[3];
};

static void easycfg_init(EasyCfg* cfg) {
    memset(cfg, 0, sizeof(*cfg));
    cfg->bg1.file1[0] = '\0'; cfg->bg1.file2[0] = '\0'; cfg->bg1.id1 = -1; cfg->bg1.id2 = -1;
    cfg->bg2.file1[0] = '\0'; cfg->bg2.file2[0] = '\0'; cfg->bg2.id1 = -1; cfg->bg2.id2 = -1;
    cfg->bg3.file1[0] = '\0'; cfg->bg3.file2[0] = '\0'; cfg->bg3.id1 = -1; cfg->bg3.id2 = -1;
    cfg->pal_file[0] = '\0'; cfg->pal_id = -1;
    cfg->cursor_file[0] = '\0'; cfg->cursor_id = -1;
    cfg->shade_amount_percent = 0;
    cfg->button_file[0] = '\0'; cfg->button_id = -1;
    cfg->popup_file[0] = '\0'; cfg->popup_id = -1;
    cfg->background_pos = 0;
    cfg->background_color = 0;
    cfg->use_bevels = 1;
    for (int i = 0; i < 6; ++i) cfg->bevel[i] = 0;
    for (int i = 0; i < 3; ++i) {
        cfg->text1[i] = 255; cfg->text2[i] = 0;
        cfg->focus1[i] = (i < 2) ? 255 : 0; cfg->focus2[i] = 0;
        cfg->state1[i] = 255; cfg->state2[i] = 0;
    }
}

static void parse_background_line(EasyCfgBackground* out, const char* file1, const char* file2, long id1, long id2) {
    strncpy(out->file1, file1 ? file1 : "", sizeof(out->file1) - 1);
    out->file1[sizeof(out->file1) - 1] = '\0';
    strncpy(out->file2, file2 ? file2 : "", sizeof(out->file2) - 1);
    out->file2[sizeof(out->file2) - 1] = '\0';
    out->id1 = id1;
    out->id2 = id2;
}

static int parse_easy_cfg_text(EasyCfg* cfg, char* text) {
    // The `bina` config is line-oriented and whitespace-separated.
    // We intentionally parse it loosely to tolerate formatting differences.
    int parsed_items = 0;
    char* ctx_line = nullptr;
    for (char* line = strtok_s(text, "\n", &ctx_line); line; line = strtok_s(nullptr, "\n", &ctx_line)) {
        trim_in_place(line);
        if (line[0] == '\0') continue;

        char* ctx_tok = nullptr;
        char* key = strtok_s(line, " \t", &ctx_tok);
        if (!key) continue;

        if (_stricmp(key, "background1_files") == 0 ||
            _stricmp(key, "background2_files") == 0 ||
            _stricmp(key, "background3_files") == 0) {
            char* file1 = strtok_s(nullptr, " \t", &ctx_tok);
            char* file2 = strtok_s(nullptr, " \t", &ctx_tok);
            char* id1s = strtok_s(nullptr, " \t", &ctx_tok);
            char* id2s = strtok_s(nullptr, " \t", &ctx_tok);
            long id1 = id1s ? strtol(id1s, nullptr, 0) : -1;
            long id2 = id2s ? strtol(id2s, nullptr, 0) : -1;

            if (_stricmp(key, "background1_files") == 0) parse_background_line(&cfg->bg1, file1, file2, id1, id2);
            if (_stricmp(key, "background2_files") == 0) parse_background_line(&cfg->bg2, file1, file2, id1, id2);
            if (_stricmp(key, "background3_files") == 0) parse_background_line(&cfg->bg3, file1, file2, id1, id2);
            parsed_items++;
            continue;
        }

        if (_stricmp(key, "palette_file") == 0) {
            char* file = strtok_s(nullptr, " \t", &ctx_tok);
            char* id = strtok_s(nullptr, " \t", &ctx_tok);
            if (file) {
                strncpy(cfg->pal_file, file, sizeof(cfg->pal_file) - 1);
                cfg->pal_file[sizeof(cfg->pal_file) - 1] = '\0';
            }
            cfg->pal_id = id ? strtol(id, nullptr, 0) : -1;
            parsed_items++;
            continue;
        }

        if (_stricmp(key, "cursor_file") == 0) {
            char* file = strtok_s(nullptr, " \t", &ctx_tok);
            char* id = strtok_s(nullptr, " \t", &ctx_tok);
            if (file) {
                strncpy(cfg->cursor_file, file, sizeof(cfg->cursor_file) - 1);
                cfg->cursor_file[sizeof(cfg->cursor_file) - 1] = '\0';
            }
            cfg->cursor_id = id ? strtol(id, nullptr, 0) : -1;
            parsed_items++;
            continue;
        }

        if (_stricmp(key, "shade_amount") == 0) {
            strtok_s(nullptr, " \t", &ctx_tok); // "percent"
            char* val = strtok_s(nullptr, " \t", &ctx_tok);
            cfg->shade_amount_percent = val ? atoi(val) : 0;
            parsed_items++;
            continue;
        }

        if (_stricmp(key, "button_file") == 0) {
            char* file = strtok_s(nullptr, " \t", &ctx_tok);
            char* id = strtok_s(nullptr, " \t", &ctx_tok);
            if (file) {
                strncpy(cfg->button_file, file, sizeof(cfg->button_file) - 1);
                cfg->button_file[sizeof(cfg->button_file) - 1] = '\0';
            }
            cfg->button_id = id ? strtol(id, nullptr, 0) : -1;
            parsed_items++;
            continue;
        }

        if (_stricmp(key, "popup_dialog_sin") == 0) {
            char* file = strtok_s(nullptr, " \t", &ctx_tok);
            char* id = strtok_s(nullptr, " \t", &ctx_tok);
            if (file) {
                strncpy(cfg->popup_file, file, sizeof(cfg->popup_file) - 1);
                cfg->popup_file[sizeof(cfg->popup_file) - 1] = '\0';
            }
            cfg->popup_id = id ? strtol(id, nullptr, 0) : -1;
            parsed_items++;
            continue;
        }

        if (_stricmp(key, "background_position") == 0) {
            char* val = strtok_s(nullptr, " \t", &ctx_tok);
            cfg->background_pos = val ? atoi(val) : 0;
            parsed_items++;
            continue;
        }

        if (_stricmp(key, "background_color") == 0) {
            char* val = strtok_s(nullptr, " \t", &ctx_tok);
            cfg->background_color = val ? atoi(val) : 0;
            parsed_items++;
            continue;
        }

        if (_stricmp(key, "use_bevels") == 0) {
            char* val = strtok_s(nullptr, " \t", &ctx_tok);
            cfg->use_bevels = val ? atoi(val) : 0;
            parsed_items++;
            continue;
        }

        if (_stricmp(key, "bevel_colors") == 0) {
            for (int i = 0; i < 6; ++i) {
                char* v = strtok_s(nullptr, " \t", &ctx_tok);
                cfg->bevel[i] = v ? atoi(v) : 0;
            }
            parsed_items++;
            continue;
        }

        if (_stricmp(key, "text_color1") == 0 || _stricmp(key, "text_color2") == 0 ||
            _stricmp(key, "focus_color1") == 0 || _stricmp(key, "focus_color2") == 0 ||
            _stricmp(key, "state_color1") == 0 || _stricmp(key, "state_color2") == 0) {
            int rgb[3] = {0, 0, 0};
            for (int i = 0; i < 3; ++i) {
                char* v = strtok_s(nullptr, " \t", &ctx_tok);
                rgb[i] = v ? atoi(v) : 0;
            }
            if (_stricmp(key, "text_color1") == 0) { cfg->text1[0] = rgb[0]; cfg->text1[1] = rgb[1]; cfg->text1[2] = rgb[2]; }
            if (_stricmp(key, "text_color2") == 0) { cfg->text2[0] = rgb[0]; cfg->text2[1] = rgb[1]; cfg->text2[2] = rgb[2]; }
            if (_stricmp(key, "focus_color1") == 0) { cfg->focus1[0] = rgb[0]; cfg->focus1[1] = rgb[1]; cfg->focus1[2] = rgb[2]; }
            if (_stricmp(key, "focus_color2") == 0) { cfg->focus2[0] = rgb[0]; cfg->focus2[1] = rgb[1]; cfg->focus2[2] = rgb[2]; }
            if (_stricmp(key, "state_color1") == 0) { cfg->state1[0] = rgb[0]; cfg->state1[1] = rgb[1]; cfg->state1[2] = rgb[2]; }
            if (_stricmp(key, "state_color2") == 0) { cfg->state2[0] = rgb[0]; cfg->state2[1] = rgb[1]; cfg->state2[2] = rgb[2]; }
            parsed_items++;
            continue;
        }
    }
    return parsed_items;
}

static void load_bg_shape_pair(TShape** out1, TShape** out2, const EasyCfgBackground* bg) {
    if (*out1) { delete *out1; *out1 = nullptr; }
    if (*out2) { delete *out2; *out2 = nullptr; }

    if (bg->id1 >= 0 && !is_none_token(bg->file1)) {
        *out1 = new TShape((char*)bg->file1, (int)bg->id1);
        if (*out1 && !(*out1)->is_loaded()) {
            delete *out1;
            *out1 = nullptr;
        }
    }
    if (bg->id2 >= 0 && !is_none_token(bg->file2)) {
        *out2 = new TShape((char*)bg->file2, (int)bg->id2);
        if (*out2 && !(*out2)->is_loaded()) {
            delete *out2;
            *out2 = nullptr;
        }
    }
}

long TEasy_Panel::setup(TDrawArea* param_1, TPanel* param_2, char* param_3, long param_4, int param_5, long param_6, long param_7, long param_8, long param_9, int param_10) {
    // Best-effort implementation targeting accuracy for boot->main menu path.
    // Source of truth: `src/game/src/Panel_ez.cpp.asm` / `.decomp` (immutable references).
    this->allow_shadow_area = param_10;
    set_info_file(this, param_3, param_4);

    // Compute panel rect.
    long x = param_6;
    long y = param_7;
    long w = param_8;
    long h = param_9;
    if (param_1) {
        if (w <= 0) w = param_1->Width;
        if (h <= 0) h = param_1->Height;
        if (param_5 == 0 && w > 0 && h > 0) {
            if (x == -1) x = (param_1->Width / 2) - (w / 2);
            if (y == -1) y = (param_1->Height / 2) - (h / 2);
        }
    }
    if (x < 0) x = 0;
    if (y < 0) y = 0;

    if (!TPanel::setup(param_1, param_2, x, y, w, h, 0)) {
        this->error_code = 1;
        return 0;
    }

    // Allow blank screens.
    if (this->info_id < 0) {
        return 1;
    }

    int res_size = 0;
    int res_type = 0;
    unsigned char* res = RESFILE_load(0x62696e61, (unsigned long)this->info_id, &res_size, &res_type); // 'bina'
    if (!res || res_size <= 0) {
        CUSTOM_DEBUG_LOG_FMT("TEasy_Panel::setup: failed to load bina id=%ld", this->info_id);
        this->error_code = 1;
        return 0;
    }

    // Make a writable null-terminated copy for tokenization.
    char* cfg_text = (char*)calloc(1, (size_t)res_size + 1);
    if (!cfg_text) {
        if (res_type == 1) free(res);
        this->error_code = 1;
        return 0;
    }
    memcpy(cfg_text, res, (size_t)res_size);
    cfg_text[res_size] = '\0';
    if (res_type == 1) free(res);

    EasyCfg cfg;
    easycfg_init(&cfg);
    const int parsed_items = parse_easy_cfg_text(&cfg, cfg_text);
    free(cfg_text);

    if (parsed_items <= 0) {
        // Source of truth: `Panel_ez.cpp.decomp` only applies parsed style/state data when `sscanf != -1`.
        // If parsing failed, keep constructor defaults and treat setup as successful.
        return 1;
    }

    // Palette.
    if (panel_system && !is_none_token(cfg.pal_file) && cfg.pal_id >= 0) {
        void* pal = panel_system->get_palette(cfg.pal_file, cfg.pal_id);
        this->palette = pal;
        if (pal && param_1 && param_1->DrawSystem) {
            param_1->DrawSystem->SetPalette(pal);
        }
    }

    // Cursor.
    if (!is_none_token(cfg.cursor_file)) {
        strncpy(this->cursor_file, cfg.cursor_file, sizeof(this->cursor_file) - 1);
        this->cursor_file[sizeof(this->cursor_file) - 1] = '\0';
        this->cursor_id = cfg.cursor_id;
    }

    // Background selection by resolution.
    const EasyCfgBackground* bg = &cfg.bg1;
    if (param_1) {
        if (param_1->Width >= 1024) bg = &cfg.bg3;
        else if (param_1->Width >= 800) bg = &cfg.bg2;
    }
    load_bg_shape_pair(&this->background_pic, &this->background_pic2, bg);

    // Colors / bevels.
    this->background_pos = cfg.background_pos;
    this->background_color1 = (unsigned char)cfg.background_color;
    this->background_color2 = (unsigned char)cfg.background_color;

    // Source of truth: `Panel_ez.cpp.asm` calls `set_use_bevels(this,1)` on parse success.
    this->use_bevels = 1;
    this->bevel_color1 = (unsigned char)cfg.bevel[0];
    this->bevel_color2 = (unsigned char)cfg.bevel[1];
    this->bevel_color3 = (unsigned char)cfg.bevel[2];
    this->bevel_color4 = (unsigned char)cfg.bevel[3];
    this->bevel_color5 = (unsigned char)cfg.bevel[4];
    this->bevel_color6 = (unsigned char)cfg.bevel[5];

    this->text_color1 = RGB(cfg.text1[0], cfg.text1[1], cfg.text1[2]);
    this->text_color2 = RGB(cfg.text2[0], cfg.text2[1], cfg.text2[2]);
    this->focus_color1 = RGB(cfg.focus1[0], cfg.focus1[1], cfg.focus1[2]);
    this->focus_color2 = RGB(cfg.focus2[0], cfg.focus2[1], cfg.focus2[2]);
    this->state_color1 = RGB(cfg.state1[0], cfg.state1[1], cfg.state1[2]);
    this->state_color2 = RGB(cfg.state2[0], cfg.state2[1], cfg.state2[2]);

    // Popup dialog info.
    if (!is_none_token(cfg.popup_file)) {
        strncpy(this->popup_info_file_name, cfg.popup_file, sizeof(this->popup_info_file_name) - 1);
        this->popup_info_file_name[sizeof(this->popup_info_file_name) - 1] = '\0';
        this->popup_info_id = cfg.popup_id;
    }

    // Button pics (scr1 uses `none -1`).
    if (!is_none_token(cfg.button_file) && cfg.button_id >= 0) {
        if (this->button_pics) {
            delete this->button_pics;
            this->button_pics = nullptr;
        }
        this->button_pics = new TShape((char*)cfg.button_file, (int)cfg.button_id);
        if (this->button_pics && !this->button_pics->is_loaded()) {
            delete this->button_pics;
            this->button_pics = nullptr;
        }
    }

CUSTOM_DEBUG_BEGIN
    CUSTOM_DEBUG_LOG_FMT(
        "TEasy_Panel::setup cfg: info='%s' id=%ld bg='%s'(%ld) pos=%d use_bevels=%d bevel=%d,%d,%d,%d,%d,%d",
        this->info_file_name, this->info_id,
        bg->file1, bg->id1,
        this->background_pos, this->use_bevels,
        (int)this->bevel_color1, (int)this->bevel_color2, (int)this->bevel_color3,
        (int)this->bevel_color4, (int)this->bevel_color5, (int)this->bevel_color6);
CUSTOM_DEBUG_END

    this->set_shadow_amount(cfg.shade_amount_percent);
CUSTOM_DEBUG_BEGIN
    CUSTOM_DEBUG_LOG_FMT("TEasy_Panel::setup done: info='%s' id=%ld shade=%ld", this->info_file_name, this->info_id, this->shadow_amount);
CUSTOM_DEBUG_END
    return 1;
}

void TEasy_Panel::set_rect(tagRECT param_1) { TPanel::set_rect(param_1); }
void TEasy_Panel::set_rect(long param_1, long param_2, long param_3, long param_4) { TPanel::set_rect(param_1, param_2, param_3, param_4); }
void TEasy_Panel::set_color(uchar param_1) { TPanel::set_color(param_1); }
void TEasy_Panel::set_active(int param_1) { TPanel::set_active(param_1); }
void TEasy_Panel::set_positioning(PositionMode param_1, long param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, TPanel* param_10, TPanel* param_11, TPanel* param_12, TPanel* param_13) {
    (void)param_10;
    (void)param_11;
    (void)param_12;
    (void)param_13;
    TPanel::set_positioning(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9);
}
void TEasy_Panel::set_fixed_position(long param_1, long param_2, long param_3, long param_4) { TPanel::set_fixed_position(param_1, param_2, param_3, param_4); }
void TEasy_Panel::set_redraw(RedrawMode param_1) { TPanel::set_redraw(param_1); }
void TEasy_Panel::set_overlapped_redraw(TPanel* param_1, TPanel* param_2, RedrawMode param_3) { TPanel::set_overlapped_redraw(param_1, param_2, param_3); }
void TEasy_Panel::draw_setup(int param_1) { TPanel::draw_setup(param_1); }
void TEasy_Panel::draw_finish() { TPanel::draw_finish(); }

void TEasy_Panel::draw() {
    // `TScreenPanel::draw` in `Pnl_scr.cpp.decomp` ultimately calls virtual draw_background.
    this->draw_background(0);
    // NOTE: `TPanel::draw()` clears/restores background only (no child recursion) and is not part of
    // the `TEasy_Panel` screen draw path in the original. Keep this panel-only draw minimal.
}

void TEasy_Panel::draw_rect(tagRECT* param_1) { TPanel::draw_rect(param_1); }
void TEasy_Panel::draw_offset(long param_1, long param_2, tagRECT* param_3) { TPanel::draw_offset(param_1, param_2, param_3); }
void TEasy_Panel::draw_rect2(tagRECT* param_1) { TPanel::draw_rect2(param_1); }
void TEasy_Panel::draw_offset2(long param_1, long param_2, tagRECT* param_3) { TPanel::draw_offset2(param_1, param_2, param_3); }
void TEasy_Panel::paint() { TPanel::paint(); }
long TEasy_Panel::wnd_proc(void* param_1, uint param_2, uint param_3, long param_4) { return TPanel::wnd_proc(param_1, param_2, param_3, param_4); }
long TEasy_Panel::handle_idle() { return TPanel::handle_idle(); }
long TEasy_Panel::handle_size(long param_1, long param_2) { return TPanel::handle_size(param_1, param_2); }
long TEasy_Panel::handle_paint() { return TPanel::handle_paint(); }
long TEasy_Panel::handle_key_down(long param_1, short param_2, int param_3, int param_4, int param_5) { return TPanel::handle_key_down(param_1, param_2, param_3, param_4, param_5); }
long TEasy_Panel::handle_char(long param_1, short param_2) { return TPanel::handle_char(param_1, param_2); }
long TEasy_Panel::handle_command(uint param_1, long param_2) { return TPanel::handle_command(param_1, param_2); }
long TEasy_Panel::handle_user_command(uint param_1, long param_2) { return TPanel::handle_user_command(param_1, param_2); }
long TEasy_Panel::handle_timer_command(uint param_1, long param_2) { return TPanel::handle_timer_command(param_1, param_2); }
long TEasy_Panel::handle_scroll(long param_1, long param_2) { return TPanel::handle_scroll(param_1, param_2); }
long TEasy_Panel::handle_mouse_down(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TPanel::handle_mouse_down(param_1, param_2, param_3, param_4, param_5); }
long TEasy_Panel::handle_mouse_move(long param_1, long param_2, int param_3, int param_4) { return TPanel::handle_mouse_move(param_1, param_2, param_3, param_4); }
long TEasy_Panel::handle_mouse_up(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TPanel::handle_mouse_up(param_1, param_2, param_3, param_4, param_5); }
long TEasy_Panel::handle_mouse_dbl_click(uchar param_1, long param_2, long param_3, int param_4, int param_5) { return TPanel::handle_mouse_dbl_click(param_1, param_2, param_3, param_4, param_5); }
long TEasy_Panel::mouse_move_action(long param_1, long param_2, int param_3, int param_4) { return TPanel::mouse_move_action(param_1, param_2, param_3, param_4); }
long TEasy_Panel::mouse_left_down_action(long param_1, long param_2, int param_3, int param_4) { return TPanel::mouse_left_down_action(param_1, param_2, param_3, param_4); }
long TEasy_Panel::mouse_left_hold_action(long param_1, long param_2, int param_3, int param_4) { return TPanel::mouse_left_hold_action(param_1, param_2, param_3, param_4); }
long TEasy_Panel::mouse_left_move_action(long param_1, long param_2, int param_3, int param_4) { return TPanel::mouse_left_move_action(param_1, param_2, param_3, param_4); }
long TEasy_Panel::mouse_left_up_action(long param_1, long param_2, int param_3, int param_4) { return TPanel::mouse_left_up_action(param_1, param_2, param_3, param_4); }
long TEasy_Panel::mouse_left_dbl_click_action(long param_1, long param_2, int param_3, int param_4) { return TPanel::mouse_left_dbl_click_action(param_1, param_2, param_3, param_4); }
long TEasy_Panel::mouse_right_down_action(long param_1, long param_2, int param_3, int param_4) { return TPanel::mouse_right_down_action(param_1, param_2, param_3, param_4); }
long TEasy_Panel::mouse_right_hold_action(long param_1, long param_2, int param_3, int param_4) { return TPanel::mouse_right_hold_action(param_1, param_2, param_3, param_4); }
long TEasy_Panel::mouse_right_move_action(long param_1, long param_2, int param_3, int param_4) { return TPanel::mouse_right_move_action(param_1, param_2, param_3, param_4); }
long TEasy_Panel::mouse_right_up_action(long param_1, long param_2, int param_3, int param_4) { return TPanel::mouse_right_up_action(param_1, param_2, param_3, param_4); }
long TEasy_Panel::mouse_right_dbl_click_action(long param_1, long param_2, int param_3, int param_4) { return TPanel::mouse_right_dbl_click_action(param_1, param_2, param_3, param_4); }
long TEasy_Panel::key_down_action(long param_1, short param_2, int param_3, int param_4, int param_5) { return TPanel::key_down_action(param_1, param_2, param_3, param_4, param_5); }
long TEasy_Panel::char_action(long param_1, short param_2) { return TPanel::char_action(param_1, param_2); }
long TEasy_Panel::action(TPanel* param_1, long param_2, ulong param_3, ulong param_4) {
    (void)param_1;
    (void)param_3;
    (void)param_4;

    // Minimal parity for popup-help mode:
    // original TEasy_Panel::action routes clicks through command_do_popup_help.
    // We at least clear help mode on the next click so cursor/game-mouse state is restored.
    if (this->help_mode == 1 && (param_2 == 0 || param_2 == 1)) {
        this->clear_popup_help();
        return 1;
    }

    return TPanel::action(param_1, param_2, param_3, param_4);
}
void TEasy_Panel::get_true_render_rect(tagRECT* param_1) { TPanel::get_true_render_rect(param_1); }
int TEasy_Panel::is_inside(long param_1, long param_2) { return TPanel::is_inside(param_1, param_2); }
void TEasy_Panel::set_focus(int param_1) { TPanel::set_focus(param_1); }
void TEasy_Panel::set_tab_order(TPanel* param_1, TPanel* param_2) { TPanel::set_tab_order(param_1, param_2); }
void TEasy_Panel::set_tab_order(TPanel** param_1, short param_2) { TPanel::set_tab_order(param_1, param_2); }
uchar TEasy_Panel::get_help_info(char** param_1, long* param_2, long param_3, long param_4) { return TPanel::get_help_info(param_1, param_2, param_3, param_4); }
void TEasy_Panel::stop_sound_system() { TPanel::stop_sound_system(); }
int TEasy_Panel::restart_sound_system() { return TPanel::restart_sound_system(); }
void TEasy_Panel::take_snapshot() { TPanel::take_snapshot(); }
void TEasy_Panel::handle_reactivate() { TPanel::handle_reactivate(); }

void TEasy_Panel::draw_background(int param_1) {
    // Best-effort match for `TEasy_Panel::draw_background` in `Panel_ez.cpp.decomp`.
    if (!this->render_area) return;

    this->draw_setup(0);

    // Fast path: for shaded backgrounds, we can use a prebuilt shadow_area.
    if (param_1 != 0 && this->shadow_area) {
        const long w = this->shadow_area->Width;
        const long h = this->shadow_area->Height;

        if (this->background_pos == 0) {
            this->shadow_area->Copy(this->render_area, this->pnl_x, this->pnl_y, (tagRECT*)0, 0);
        } else if (this->background_pos == 1) {
            const long dx = this->pnl_x + (this->pnl_wid / 2) - (w / 2);
            const long dy = this->pnl_y + (this->pnl_hgt / 2) - (h / 2);
            this->shadow_area->Copy(this->render_area, dx, dy, (tagRECT*)0, 0);
        } else if (this->background_pos == 2) {
            for (long yy = 0; yy <= this->pnl_hgt; yy += h) {
                for (long xx = 0; xx <= this->pnl_wid; xx += w) {
                    this->shadow_area->Copy(this->render_area, this->pnl_x + xx, this->pnl_y + yy, (tagRECT*)0, 0);
                }
            }
        }

        this->draw_finish();
        return;
    }

    // Choose background pic.
    TShape* pic = 0;
    if (param_1 == 0) {
        pic = this->background_pic;
    } else {
        pic = this->background_pic2 ? this->background_pic2 : this->background_pic;
    }

    // If no picture, clear the background using the configured color.
    if (!pic || !pic->is_loaded()) {
        const int c = (param_1 == 0) ? (int)this->background_color1 : (int)this->background_color2;
        this->render_area->Clear(&this->clip_rect, c);
        this->draw_finish();
        return;
    }

    // If the original background does not fully cover the draw area (or clip rect is partial), the engine clears first.
    {
        const int c = (param_1 == 0) ? (int)this->background_color1 : (int)this->background_color2;
        this->render_area->Clear(&this->clip_rect, c);
    }

    // Draw the picture (clipped via `TDrawArea::ClipRect` + `TShape::shape_draw`).
    long x_min = 0, y_min = 0, x_max = 0, y_max = 0;
    pic->shape_minmax(&x_min, &y_min, &x_max, &y_max, 0);
    const long pic_w = (x_max - x_min) + 1;
    const long pic_h = (y_max - y_min) + 1;

    if (this->render_area->Lock((char*)"panel_ez::draw_background", 0)) {
        if (this->background_pos == 1) {
            const long dx = this->pnl_x + (this->pnl_wid / 2) - (pic_w / 2) - x_min;
            const long dy = this->pnl_y + (this->pnl_hgt / 2) - (pic_h / 2) - y_min;
            pic->shape_draw(this->render_area, dx, dy, 0, 0, 0, (uchar*)0);

            if (param_1 != 0 && this->shadow_color_table) {
                this->render_area->SetShadowTable(this->shadow_color_table);
                this->render_area->DrawShadowBox(dx, dy, dx + pic_w - 1, dy + pic_h - 1);
            }
        } else if (this->background_pos == 2) {
            for (long yy = 0; yy <= this->pnl_hgt; yy += pic_h) {
                for (long xx = 0; xx <= this->pnl_wid; xx += pic_w) {
                    const long dx = this->pnl_x + xx - x_min;
                    const long dy = this->pnl_y + yy - y_min;
                    pic->shape_draw(this->render_area, dx, dy, 0, 0, 0, (uchar*)0);
                }
            }
            if (param_1 != 0 && this->shadow_color_table) {
                this->render_area->SetShadowTable(this->shadow_color_table);
                this->render_area->DrawShadowBox(this->pnl_x, this->pnl_y, this->pnl_x + this->pnl_wid - 1, this->pnl_y + this->pnl_hgt - 1);
            }
        } else {
            // Top-left anchored.
            pic->shape_draw(this->render_area, this->pnl_x, this->pnl_y, 0, 0, 0, (uchar*)0);
            if (param_1 != 0 && this->shadow_color_table) {
                this->render_area->SetShadowTable(this->shadow_color_table);
                this->render_area->DrawShadowBox(this->pnl_x, this->pnl_y, this->pnl_x + (x_max - x_min), this->pnl_y + (y_max - y_min));
            }
        }

        this->render_area->Unlock((char*)"panel_ez::draw_background");
    }

    // Optional screen bevel.
    if (this->use_bevels != 0) {
        if (this->render_area->Lock((char*)"panel_ez::draw_background2", 0)) {
            this->render_area->DrawBevel3(this->pnl_x, this->pnl_y, this->pnl_x + this->pnl_wid - 1, this->pnl_y + this->pnl_hgt - 1,
                this->bevel_color1, this->bevel_color2, this->bevel_color3, this->bevel_color4, this->bevel_color5, this->bevel_color6);
            this->render_area->Unlock((char*)"panel_ez::draw_background2");
        }
    }

    this->draw_finish();
}

void TEasy_Panel::set_shadow_amount(long amount_percent) {
    // Source of truth: `Panel_ez.cpp.decomp` (`TEasy_Panel::set_shadow_amount`).
    if (amount_percent == -1) {
        this->shadow_amount = 0;
    } else {
        this->shadow_amount = amount_percent;
    }

    if (this->shadow_color_table) {
        if (this->render_area && this->render_area->shadow_color_table == this->shadow_color_table) {
CUSTOM_DEBUG_BEGIN
            CUSTOM_DEBUG_LOG_FMT(
                "TEasy_Panel::set_shadow_amount: clearing previous render_area shadow table area=%p table=%p",
                this->render_area,
                this->shadow_color_table);
CUSTOM_DEBUG_END
            this->render_area->SetShadowTable(nullptr);
        }
        delete this->shadow_color_table;
        this->shadow_color_table = 0;
    }

    if (this->shadow_amount > 0) {
        tagPALETTEENTRY pe[256];
        memset(pe, 0, sizeof(pe));

        // If we have a Win32 palette, prefer that (matches original).
        int have = 0;
        if (this->palette) {
            have = (int)GetPaletteEntries((HPALETTE)this->palette, 0, 256, pe);
        } else if (this->render_area) {
            // Fallback: use the current draw-system palette.
            this->render_area->GetPalette(pe);
            have = 1;
        }

        if (have) {
            // Create a runtime color table for shadowing.
            this->shadow_color_table = new RGE_Color_Table(this->render_area, this->shadow_amount, (tagPALETTEENTRY*)0, pe);
        }
    }

    if (this->active) {
        this->set_redraw(TPanel::RedrawMode::RedrawFull);
    }
}

void TEasy_Panel::setup_popup_help() {
    // Source of truth: `Panel_ez.cpp.decomp` (`setup_popup_help` @ 0x0046A360).
    this->help_mode = 1;
    if (rge_base_game) {
        void* cursor = (void*)LoadCursorA(0, (LPCSTR)0x7f8b);
        rge_base_game->set_mouse_cursor(cursor);
        rge_base_game->set_mouse_facet(6);
        if (rge_base_game->mouse_pointer) {
            this->saved_mouse_mode = rge_base_game->mouse_pointer->get_game_enable();
            rge_base_game->mouse_pointer->set_game_enable(0);
        }
    }
}

void TEasy_Panel::clear_popup_help() {
    // Source of truth: `Panel_ez.cpp.decomp` (`clear_popup_help` @ 0x0046A3C0).
    this->help_mode = 0;
    if (rge_base_game) {
        void* cursor = (void*)LoadCursorA(0, (LPCSTR)0x7f00);
        rge_base_game->set_mouse_cursor(cursor);
        rge_base_game->set_mouse_facet(0);
        if (rge_base_game->mouse_pointer) {
            rge_base_game->mouse_pointer->set_game_enable(this->saved_mouse_mode);
        }
    }
}

char* TEasy_Panel::get_popup_info_file() {
    // Fully verified. Source of truth: panel_ez.cpp.decomp @ 0x00468440
    return this->popup_info_file_name;
}

long TEasy_Panel::get_popup_info_id() {
    // Fully verified. Source of truth: panel_ez.cpp.decomp @ 0x00468450
    return this->popup_info_id;
}

void TEasy_Panel::popupOKDialog(long param_1, char* param_2, int param_3, int param_4) {
    // Fully verified. Source of truth: panel_ez.cpp.decomp @ 0x00469EE0
    char text[256];
    this->get_string((int)param_1, text, 0x100);
    this->popupOKDialog(text, param_2, param_3, param_4);
}

void TEasy_Panel::popupOKDialog(char* param_1, char* param_2, int param_3, int param_4) {
    // Fully verified. Source of truth: panel_ez.cpp.decomp @ 0x00469F30
    char temp_title[256];

    if (param_2 == nullptr || *param_2 == '\0') {
        param_2 = (char*)"OKDialog";
    }

    strcpy(temp_title, param_2);

    TPanel* existing = panel_system->panel(temp_title);
    if (existing != nullptr) {
        panel_system->destroyPanel(temp_title);
    }

    TMessageDialog* dialog = new TMessageDialog(temp_title);
    dialog->setup((TPanel*)this, this->popup_info_file_name, this->popup_info_id, param_3, param_4, '\0', param_1, 0x5a, 0x1e);
}

void TEasy_Panel::popupYesNoDialog(long param_1, char* param_2, int param_3, int param_4) {
    // Fully verified. Source of truth: panel_ez.cpp.decomp @ 0x0046A040
    char text[256];
    this->get_string((int)param_1, text, 0x100);
    this->popupYesNoDialog(text, param_2, param_3, param_4);
}

void TEasy_Panel::popupYesNoDialog(char* param_1, char* param_2, int param_3, int param_4) {
    // Fully verified. Source of truth: panel_ez.cpp.decomp @ 0x0046A090
    TMessageDialog* dialog = nullptr;
    if (param_2 == nullptr || *param_2 == '\0') {
        dialog = new TMessageDialog((char*)"YesNoDialog");
    } else {
        dialog = new TMessageDialog(param_2);
    }
    dialog->setup((TPanel*)this, this->popup_info_file_name, this->popup_info_id, param_3, param_4, '\x02', param_1, 0x5a, 0x1e);
}

void TEasy_Panel::popupYesNoCancelDialog(long param_1, char* param_2, int param_3, int param_4) {
    // Fully verified. Source of truth: panel_ez.cpp.decomp @ 0x0046A150
    char text[256];
    this->get_string((int)param_1, text, 0x100);
    this->popupYesNoCancelDialog(text, param_2, param_3, param_4);
}

void TEasy_Panel::popupYesNoCancelDialog(char* param_1, char* param_2, int param_3, int param_4) {
    // Fully verified. Source of truth: panel_ez.cpp.decomp @ 0x0046A1A0
    TMessageDialog* dialog = nullptr;
    if (param_2 == nullptr || *param_2 == '\0') {
        dialog = new TMessageDialog((char*)"YesNoCancelDialog");
    } else {
        dialog = new TMessageDialog(param_2);
    }
    dialog->setup((TPanel*)this, this->popup_info_file_name, this->popup_info_id, param_3, param_4, '\x04', param_1, 0x78, 0x19);
}

void TEasy_Panel::setup_shadow_area(int force_rebuild) {
    // Source of truth: `Panel_ez.cpp.decomp` (`TEasy_Panel::setup_shadow_area`).
    if (!this->allow_shadow_area) return;
    if (!this->background_pic) return;
    if (!this->shadow_color_table) return;

    if (!this->shadow_area) {
        this->shadow_area = new TDrawArea((char*)"Shadow Panel");
    }
    if (!this->shadow_area) return;

    if (force_rebuild || !this->shadow_area->DrawSurface) {
        long x_min = 0, y_min = 0, x_max = 0, y_max = 0;
        this->background_pic->shape_minmax(&x_min, &y_min, &x_max, &y_max, 0);
        long w = (x_max - x_min) + 1;
        long h = (y_max - y_min) + 1;
        if (w > this->pnl_wid) w = this->pnl_wid;
        if (h > this->pnl_hgt) h = this->pnl_hgt;
        if (w <= 0 || h <= 0) return;

        if (!this->shadow_area->Init(this->render_area ? this->render_area->DrawSystem : 0, 0, (int)w, (int)h, 0, 0, 1)) {
            return;
        }

        this->shadow_area->Clear((tagRECT*)0, (int)this->background_color1);
        if (this->shadow_area->Lock((char*)"panel_ez::setup_shadow_area", 0)) {
            this->background_pic->shape_draw(this->shadow_area, 0, 0, 0, 0, 0, (uchar*)0);
            this->shadow_area->SetShadowTable(this->shadow_color_table);
            this->shadow_area->DrawShadowBox(0, 0, w - 1, h - 1);
            this->shadow_area->Unlock((char*)"panel_ez::setup_shadow_area");
        }
    }
}

void TEasy_Panel::set_ideal_size(long param_1, long param_2) {
    this->ideal_width = param_1;
    this->ideal_height = param_2;
}

int TEasy_Panel::create_button(TPanel* param_1, TButtonPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, long param_10, long param_11) {
    // String-id overload: load strings then call string overload.
    // Source of truth: `src/game/src/Panel_ez.cpp.decomp` (immutable reference).
    char text1[120];
    char text2[120];
    text1[0] = '\0';
    text2[0] = '\0';
    this->get_string((int)param_3, text1, sizeof(text1));
    this->get_string((int)param_4, text2, sizeof(text2));
    return this->create_button(param_1, param_2, text1, (text2[0] != '\0') ? text2 : nullptr, param_5, param_6, param_7, param_8, param_9, param_10, param_11);
}

int TEasy_Panel::create_button(TPanel* param_1, TButtonPanel** param_2, char* param_3, char* param_4, long param_5, long param_6, long param_7, long param_8, long param_9, long param_10, long param_11) {
    if (!param_2) return 0;

    *param_2 = new TButtonPanel();
    if (!*param_2) {
        this->error_code = 1;
        return 0;
    }

    // Scale from ideal coords to current panel size.
    long scaled_x = (this->ideal_width > 0) ? (param_5 * this->pnl_wid) / this->ideal_width : param_5;
    long scaled_y = (this->ideal_height > 0) ? (param_6 * this->pnl_hgt) / this->ideal_height : param_6;
    long scaled_w = (this->ideal_width > 0) ? (param_7 * this->pnl_wid) / this->ideal_width : param_7;
    long scaled_h = (this->ideal_height > 0) ? (param_8 * this->pnl_hgt) / this->ideal_height : param_8;

    TDigital* sound = nullptr;
    if (rge_base_game && (int)param_10 >= 0) {
        sound = rge_base_game->get_sound((int)param_10);
    }

    long ok = (*param_2)->setup(this->render_area, param_1, scaled_x, scaled_y, scaled_w, scaled_h, TButtonPanel::DrawTextA, sound, TButtonPanel::NotifyAction, param_11);
    if (!ok) {
        this->error_code = 1;
        return 0;
    }

    (*param_2)->set_sound_number((int)param_10);

    int font_index = (int)param_9;
    if (font_index < 0) font_index = 10;
    RGE_Font* font = (rge_base_game) ? rge_base_game->get_font(font_index) : nullptr;
    if (font) {
        (*param_2)->set_font(font->font, font->font_wid, font->font_hgt);
    }

    // Default text placement.
    (*param_2)->text_x = -1;
    (*param_2)->text_y = -1;
    (*param_2)->set_text(0, param_3);
    if (param_4) {
        (*param_2)->set_text(1, param_4);
    }

    if (this->use_bevels) {
        (*param_2)->bevel_type = 4;
        (*param_2)->bevel_color1 = this->bevel_color1;
        (*param_2)->bevel_color2 = this->bevel_color2;
        (*param_2)->bevel_color3 = this->bevel_color3;
        (*param_2)->bevel_color4 = this->bevel_color4;
        (*param_2)->bevel_color5 = this->bevel_color5;
        (*param_2)->bevel_color6 = this->bevel_color6;
    }

    for (int i = 0; i < 9; ++i) {
        (*param_2)->text_color1[i] = this->text_color1;
        (*param_2)->text_color2[i] = this->text_color2;
        (*param_2)->highlight_text_color1[i] = this->focus_color1;
        (*param_2)->highlight_text_color2[i] = this->focus_color2;
    }

    (*param_2)->text_color1[1] = this->state_color1;
    (*param_2)->text_color2[1] = this->state_color2;
    (*param_2)->highlight_text_color1[1] = this->focus_color1;
    (*param_2)->highlight_text_color2[1] = this->focus_color2;

    return 1;
}

int TEasy_Panel::create_check_box(TPanel* param_1, TButtonPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8) {
    // Source of truth: Panel_ez.cpp.decomp @ 0x00468760
    // params: parent, out_ptr, x, y, w, h, sound_id, unk
    if (!param_2) return 0;

    *param_2 = new TButtonPanel();
    if (!*param_2) {
        this->error_code = 1;
        return 0;
    }

    // Scale from ideal coords to current panel size
    long scaled_x = (this->ideal_width > 0) ? (param_3 * this->pnl_wid) / this->ideal_width : param_3;
    long scaled_y = (this->ideal_height > 0) ? (param_4 * this->pnl_hgt) / this->ideal_height : param_4;
    long scaled_w = (this->ideal_width > 0) ? (param_5 * this->pnl_wid) / this->ideal_width : param_5;
    long scaled_h = (this->ideal_height > 0) ? (param_6 * this->pnl_hgt) / this->ideal_height : param_6;

    TDigital* sound = nullptr;
    if (rge_base_game && (int)param_7 >= 0) {
        sound = rge_base_game->get_sound((int)param_7);
    }

    // Decomp: setup with DrawBevelPicture, NotifyAction
    long ok = (*param_2)->setup(this->render_area, param_1, scaled_x, scaled_y, scaled_w, scaled_h,
                                TButtonPanel::DrawBevelPicture, sound, TButtonPanel::NotifyAction, param_8);
    if (!ok) {
        this->error_code = 1;
        return 0;
    }

    (*param_2)->set_sound_number((int)param_7);

    // Decomp: set_state_info(2) — 2 states for checkbox (unchecked/checked)
    (*param_2)->set_state_info(2);

    // Decomp: if button_pics is null, use text fallback ("" for unchecked, "X" for checked)
    if (this->button_pics == nullptr) {
        RGE_Font* font = (rge_base_game) ? rge_base_game->get_font(0) : nullptr;
        if (font) {
            (*param_2)->set_font(font->font, font->font_wid, font->font_hgt);
        }
        (*param_2)->text_x = -1;
        (*param_2)->text_y = -1;
        (*param_2)->set_text(0, (char*)"");
        (*param_2)->set_text(1, (char*)"X");
        (*param_2)->drawTypeValue = TButtonPanel::DrawTextA;
    } else {
        // Decomp: use button_pics for checkbox graphics
        (*param_2)->drawTypeValue = TButtonPanel::DrawBevelPicture;
        (*param_2)->set_picture(0, this->button_pics, 0);
        (*param_2)->set_picture(1, this->button_pics, 2);
    }

    // Decomp: apply bevels if enabled
    if (this->use_bevels) {
        (*param_2)->bevel_type = 4;
        (*param_2)->bevel_color1 = this->bevel_color1;
        (*param_2)->bevel_color2 = this->bevel_color2;
        (*param_2)->bevel_color3 = this->bevel_color3;
        (*param_2)->bevel_color4 = this->bevel_color4;
        (*param_2)->bevel_color5 = this->bevel_color5;
        (*param_2)->bevel_color6 = this->bevel_color6;
    }

    // Decomp: set text colors for both states
    (*param_2)->text_color1[0] = this->text_color1;
    (*param_2)->text_color2[0] = this->text_color2;
    (*param_2)->highlight_text_color1[0] = this->focus_color1;
    (*param_2)->highlight_text_color2[0] = this->focus_color2;
    (*param_2)->text_color1[1] = this->state_color1;
    (*param_2)->text_color2[1] = this->state_color2;
    (*param_2)->highlight_text_color1[1] = this->focus_color1;
    (*param_2)->highlight_text_color2[1] = this->focus_color2;

    return 1;
}

int TEasy_Panel::create_radio_button(TPanel* param_1, TButtonPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8) {
    (void)param_1; (void)param_2; (void)param_3; (void)param_4; (void)param_5; (void)param_6; (void)param_7; (void)param_8;
    return 0;
}

int TEasy_Panel::create_text(TPanel* param_1, TTextPanel** param_2, int param_3, long param_4, long param_5, long param_6, long param_7, long param_8, int param_9, int param_10, int param_11) {
    char text[256];
    text[0] = '\0';
    this->get_string(param_3, text, sizeof(text));
    return this->create_text(param_1, param_2, text, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11);
}

int TEasy_Panel::create_text(TPanel* param_1, TTextPanel** param_2, char** param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9, int param_10, int param_11) {
    if (!param_2) return 0;

    *param_2 = new TTextPanel();
    if (!*param_2) {
        this->error_code = 1;
        return 0;
    }

    long scaled_x = (this->ideal_width > 0) ? (param_5 * this->pnl_wid) / this->ideal_width : param_5;
    long scaled_y = (this->ideal_height > 0) ? (param_6 * this->pnl_hgt) / this->ideal_height : param_6;
    long scaled_w = (this->ideal_width > 0) ? (param_7 * this->pnl_wid) / this->ideal_width : param_7;
    long scaled_h = (this->ideal_height > 0) ? (param_8 * this->pnl_hgt) / this->ideal_height : param_8;

    int font_index = (int)param_9;
    if (font_index < 0) font_index = 10;
    RGE_Font* font = (rge_base_game) ? rge_base_game->get_font(font_index) : nullptr;
    void* font_handle = font ? font->font : nullptr;
    long font_wid = font ? font->font_wid : 0;
    long font_hgt = font ? font->font_hgt : 0;

    if (!(*param_2)->setup(this->render_area, param_1, scaled_x, scaled_y, scaled_w, scaled_h, font_handle, font_wid, font_hgt, (char*)0, 0, 0, 0, 0, 0, (char*)0)) {
        this->error_code = 1;
        return 0;
    }

    (*param_2)->set_text(param_3, (short)param_4);
    (*param_2)->set_alignment((param_11 != 0) ? TTextPanel::AlignCenter : TTextPanel::AlignTop,
                              (param_10 != 0) ? TTextPanel::AlignCenter : TTextPanel::AlignLeft);
    (*param_2)->set_text_color(this->text_color1, this->text_color2);
    (*param_2)->set_highlight_text_color(this->focus_color1, this->focus_color2);
    return 1;
}

int TEasy_Panel::create_text(TPanel* param_1, TTextPanel** param_2, char* param_3, long param_4, long param_5, long param_6, long param_7, long param_8, int param_9, int param_10, int param_11) {
    if (!param_2) return 0;

    *param_2 = new TTextPanel();
    if (!*param_2) {
        this->error_code = 1;
        return 0;
    }

    long scaled_x = (this->ideal_width > 0) ? (param_4 * this->pnl_wid) / this->ideal_width : param_4;
    long scaled_y = (this->ideal_height > 0) ? (param_5 * this->pnl_hgt) / this->ideal_height : param_5;
    long scaled_w = (this->ideal_width > 0) ? (param_6 * this->pnl_wid) / this->ideal_width : param_6;
    long scaled_h = (this->ideal_height > 0) ? (param_7 * this->pnl_hgt) / this->ideal_height : param_7;

    int font_index = (int)param_8;
    if (font_index < 0) font_index = 10;
    RGE_Font* font = (rge_base_game) ? rge_base_game->get_font(font_index) : nullptr;
    void* font_handle = font ? font->font : nullptr;
    long font_wid = font ? font->font_wid : 0;
    long font_hgt = font ? font->font_hgt : 0;

    if (!(*param_2)->setup(this->render_area, param_1, scaled_x, scaled_y, scaled_w, scaled_h, font_handle, font_wid, font_hgt, (char*)0, 0, 0, 0, 0, 0, (char*)0)) {
        this->error_code = 1;
        return 0;
    }

    TTextPanel::Alignment horz;
    TTextPanel::Alignment vert;
    if (param_9 == 0 || param_10 == 0) {
        horz = (param_9 == 0) ? TTextPanel::AlignLeft : TTextPanel::AlignCenter;
        vert = (param_9 == 0 && param_10 != 0) ? TTextPanel::AlignCenter : TTextPanel::AlignTop;
    } else {
        horz = TTextPanel::AlignCenter;
        vert = TTextPanel::AlignCenter;
    }

    (*param_2)->set_alignment(vert, horz);
    (*param_2)->set_word_wrap(param_11);
    (*param_2)->set_text(param_3);
    (*param_2)->set_text_color(this->text_color1, this->text_color2);
    (*param_2)->set_highlight_text_color(this->focus_color1, this->focus_color2);
    return 1;
}

int TEasy_Panel::create_input(TPanel* param_1, TInputPanel** param_2, char* param_3, short param_4, FormatType param_5, long param_6, long param_7, long param_8, long param_9, long param_10) {
    (void)param_1; (void)param_2; (void)param_3; (void)param_4; (void)param_5; (void)param_6; (void)param_7; (void)param_8; (void)param_9; (void)param_10;
    return 0;
}

int TEasy_Panel::create_edit(TPanel* param_1, TEditPanel** param_2, char* param_3, short param_4, FormatType param_5, long param_6, long param_7, long param_8, long param_9, long param_10, int param_11, int param_12) {
    // Best-effort implementation for Save/Scenario name entry paths while full TEditPanel parity
    // remains pending.
    if (param_2 == nullptr) {
        return 0;
    }
    *param_2 = nullptr;

    const long scaled_x = (this->ideal_width > 0) ? (param_6 * this->pnl_wid) / this->ideal_width : param_6;
    const long scaled_y = (this->ideal_height > 0) ? (param_7 * this->pnl_hgt) / this->ideal_height : param_7;
    const long scaled_w = (this->ideal_width > 0) ? (param_8 * this->pnl_wid) / this->ideal_width : param_8;
    const long scaled_h = (this->ideal_height > 0) ? (param_9 * this->pnl_hgt) / this->ideal_height : param_9;

    int font_index = (int)param_10;
    if (font_index < 0) {
        font_index = 10;
    }
    RGE_Font* font = (rge_base_game != nullptr) ? rge_base_game->get_font(font_index) : nullptr;
    void* font_handle = (font != nullptr) ? font->font : nullptr;
    long font_wid = (font != nullptr) ? font->font_wid : 0;
    long font_hgt = (font != nullptr) ? font->font_hgt : 0;

    EasyPseudoEditPanel* edit = new EasyPseudoEditPanel(param_4, param_5, param_12);
    if (edit == nullptr) {
        this->error_code = 1;
        return 0;
    }

    const short fixed_len = (param_4 > 1) ? param_4 : 260;
    if (edit->setup(this->render_area, param_1, scaled_x, scaled_y, scaled_w, scaled_h,
                    font_handle, font_wid, font_hgt, nullptr, 0, 0, 0, 0, fixed_len,
                    (param_3 != nullptr) ? param_3 : (char*)"") == 0) {
        delete edit;
        this->error_code = 1;
        return 0;
    }

    edit->set_alignment(TTextPanel::AlignCenter, TTextPanel::AlignHorizontalScroll);
    edit->set_word_wrap(0);
    edit->set_text_color(this->text_color1, this->text_color2);
    edit->set_highlight_text_color(this->focus_color1, this->focus_color2);
    if (this->use_bevels != 0) {
        edit->set_bevel_info(
            3,
            (int)this->bevel_color1,
            (int)this->bevel_color2,
            (int)this->bevel_color3,
            (int)this->bevel_color4,
            (int)this->bevel_color5,
            (int)this->bevel_color6);
    }
    if (param_11 != 0) {
        edit->set_focus(1);
    }
    edit->easy_set_text((param_3 != nullptr) ? param_3 : "");

    *param_2 = reinterpret_cast<TEditPanel*>(edit);
    return 1;
}

int TEasy_Panel::create_drop_down(TPanel* param_1, TDropDownPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9) {
    // Source of truth: Panel_ez.cpp.decomp @ 0x00469380
    // param_1=parent, param_2=out_ptr, param_3=val_width, param_4=val_height,
    // param_5=x, param_6=y, param_7=wid, param_8=hgt, param_9=font_id
    if (!param_2) return 0;
    *param_2 = nullptr;

    // Scale coordinates from ideal to actual screen size
    // decomp: iVar17 = this->_padding_ (actual_width), iVar2 = this->ideal_width
    //         iVar3 = this->_padding_ (actual_height), iVar4 = this->ideal_height
    long actual_w = this->pnl_wid;
    long actual_h = this->pnl_hgt;
    long ideal_w = this->ideal_width;
    long ideal_h = this->ideal_height;

    // iVar5 = (param_8 * actual_h) / ideal_h  -- scaled height
    // iVar6 = (actual_w * 0x12) / ideal_w     -- scaled button width (18 ideal pixels)
    long scaled_hgt = (param_8 * actual_h) / ideal_h;
    long scaled_btn = (actual_w * 0x12) / ideal_w;

    // Get font
    int font_id = (param_9 < 0) ? 10 : (int)param_9;
    RGE_Font* font_info = rge_base_game ? rge_base_game->get_font(font_id) : nullptr;
    if (!font_info) return 0;

    // Create empty string list (1 entry with empty string)
    char** string_list = (char**)calloc(1, sizeof(char*));
    if (!string_list) { this->error_code = 1; return 0; }
    string_list[0] = (char*)calloc(0x14, 1);
    if (!string_list[0]) { free(string_list); return 0; }
    // Copy empty string into it
    string_list[0][0] = '\0';

    // Create dropdown
    TDropDownPanel* drop = new TDropDownPanel();
    if (!drop) { free(string_list[0]); free(string_list); this->error_code = 1; return 0; }

    *param_2 = drop;

    // From decomp: TDropDownPanel::setup call
    // setup(draw_area, parent, font, font_wid, font_hgt,
    //       fill_back=0, back_color='\0', have_outline=1, outline_color=0xff,
    //       x=(param_5*actual_w)/ideal_w, y=(param_6*actual_h)/ideal_h,
    //       wid=(param_7*actual_w)/ideal_w, hgt=scaled_hgt,
    //       bevel_type=0, btn_wid=0, btn_hgt=scaled_btn, list_wid_unused=scaled_hgt,
    //       back_pic_name=nullptr,
    //       val_width=(param_3*actual_w)/ideal_w, val_height=(param_4*actual_h)/ideal_h,
    //       string_list, sorted=1, scbar_wid=scaled_btn,
    //       pic1-4=nullptr, scbar_arrow_hgt=scaled_btn, scbar_tab_hgt=scaled_btn)
    long result = drop->setup(
        this->render_area, param_1,
        font_info->font, font_info->font_wid, font_info->font_hgt,
        0, '\0', 1, (uchar)0xff,
        (param_5 * actual_w) / ideal_w, (param_6 * actual_h) / ideal_h,
        (param_7 * actual_w) / ideal_w, scaled_hgt,
        0, 0, scaled_btn, scaled_hgt, nullptr,
        (param_3 * actual_w) / ideal_w, (param_4 * actual_h) / ideal_h,
        string_list, 1, scaled_btn,
        nullptr, nullptr, nullptr, nullptr,
        scaled_btn, scaled_btn
    );

    // Free temp string list
    if (string_list[0]) free(string_list[0]);
    free(string_list);

    if (result == 0) {
        this->error_code = 1;
        // Don't delete drop - it's assigned to *param_2 already
        return 0;
    }

    // Set button pics if available
    if (this->button_pics) {
        drop->set_buttons(this->button_pics, 0xe, -1, 8, 10, 0xc);
    }

    // Set bevel info
    if (this->use_bevels) {
        drop->set_bevel_info(3, (int)this->bevel_color1, (int)this->bevel_color2,
                            (int)this->bevel_color3, (int)this->bevel_color4,
                            (int)this->bevel_color5, (int)this->bevel_color6);
    }

    // Set text colors on val_panel and list_panel
    drop->set_val_text_color(this->text_color1, this->text_color2);
    if (drop->list_panel) {
        ((TTextPanel*)drop->list_panel)->set_text_color(this->text_color1, this->text_color2);
        ((TTextPanel*)drop->list_panel)->set_highlight_text_color(this->focus_color1, this->focus_color2);
    }

    // From decomp: set bevel_info on val_panel directly
    // (**(code**)((*param_2)->val_panel->_padding_ + 0xec))(3, bevel_color1..6)
    // 0xec = vt[59] = set_bevel_info
    if (drop->val_panel) {
        drop->val_panel->set_bevel_info(3,
            (int)this->bevel_color1, (int)this->bevel_color2,
            (int)this->bevel_color3, (int)this->bevel_color4,
            (int)this->bevel_color5, (int)this->bevel_color6);
    }

    return 1;
}

int TEasy_Panel::create_list(TPanel* param_1, TListPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7) {
    // Source of truth: Panel_ez.cpp.decomp @ 0x004696B0
    // params: parent, out_ptr, x, y, w, h, font_index

    // Scale from ideal coords to current panel size (source of truth uses unconditional division).
    long scaled_x = (param_3 * this->pnl_wid) / this->ideal_width;
    long scaled_y = (param_4 * this->pnl_hgt) / this->ideal_height;
    long scaled_w = (param_5 * this->pnl_wid) / this->ideal_width;
    long scaled_h = (param_6 * this->pnl_hgt) / this->ideal_height;

    int font_index = (int)param_7;
    if (font_index < 0) font_index = 10;

    // Source of truth calls get_font once before allocation (return value unused).
    rge_base_game->get_font(font_index);

    // Decomp: allocate a string list with 1 empty string entry
    char** string_list = (char**)calloc(1, sizeof(char*));
    if (!string_list) {
        this->error_code = 1;
        return 0;
    }
    string_list[0] = (char*)calloc(20, 1);
    if (!string_list[0]) {
        free(string_list);
        this->error_code = 1;
        return 0;
    }
    strcpy(string_list[0], "");

    // Decomp: create TListPanel
    *param_2 = new TListPanel();
    if (!*param_2 || (*param_2)->error_code != 0) {
        if (string_list[0]) free(string_list[0]);
        free(string_list);
        this->error_code = 1;
        return 0;
    }

    // Decomp: get font and call setup
    RGE_Font* font = rge_base_game->get_font(font_index);

    // Decomp: TTextPanel::setup(list, draw_area, parent, x, y, w, h, font, font_wid, font_hgt,
    //                           back_pic=0, fill_back=0, back_color=0, have_outline=1, outline_color=0xff,
    //                           word_wrap=0, string_list, sorted=1)
    long ok = (*param_2)->setup(this->render_area, param_1,
                                scaled_x, scaled_y, scaled_w, scaled_h,
                                font->font, font->font_wid, font->font_hgt,
                                nullptr, 0, 0, 1, 0xff, 0,
                                string_list, 1);

    if (!ok) {
        if (string_list[0]) free(string_list[0]);
        free(string_list);
        this->error_code = 1;
        return 0;
    }

    // Source of truth: Panel_ez.cpp.decomp calls `TListPanel::scroll_cur_line(list, 1, 0, 1)` here.
    (*param_2)->scroll_cur_line(1, 0, 1);

    // Decomp: free the temporary string list
    if (string_list[0]) {
        free(string_list[0]);
        string_list[0] = nullptr;
    }
    free(string_list);

    // Decomp: apply bevels if enabled (vtable+0xec = set_bevel_info)
    if (this->use_bevels) {
        (*param_2)->set_bevel_info(3,
            (int)this->bevel_color1, (int)this->bevel_color2,
            (int)this->bevel_color3, (int)this->bevel_color4,
            (int)this->bevel_color5, (int)this->bevel_color6);
    }

    // Decomp: set text colors
    (*param_2)->set_text_color(this->text_color1, this->text_color2);
    (*param_2)->set_highlight_text_color(this->focus_color1, this->focus_color2);

    return 1;
}

int TEasy_Panel::create_scrollbar(TPanel* param_1, TScrollBarPanel** param_2, TTextPanel* param_3, long param_4, long param_5, long param_6, long param_7, long param_8) {
    // Fully verified. Source of truth: Panel_ez.cpp.decomp @ 0x00469910
    long scaled_x = (this->pnl_wid * param_5) / this->ideal_width;
    long scaled_y = (param_6 * this->pnl_hgt) / this->ideal_height;
    long scaled_h = (param_8 * this->pnl_hgt) / this->ideal_height;

    TScrollBarPanel* scrollbar = new TScrollBarPanel();
    *param_2 = scrollbar;

    if ((scrollbar == nullptr) || (scrollbar->error_code != 0) ||
        (scrollbar->setup(
             this->render_area,
             param_1,
             scaled_x,
             scaled_y,
             param_7,
             scaled_h,
             nullptr,
             nullptr,
             nullptr,
             nullptr,
             param_7,
             param_7,
             (TPanel*)param_3,
             (int)param_4,
             TScrollBarPanel::Vertical) == 0)) {
        return 0;
    }

    if (param_3 != nullptr) {
        param_3->set_scrollbar(*param_2, 0);
    }
    if (this->button_pics != nullptr) {
        (*param_2)->set_buttons(this->button_pics, -1, 8, 10, 0xC);
    }
    if (this->use_bevels != 0) {
        (*param_2)->set_bevel_info(
            3,
            this->bevel_color1,
            this->bevel_color2,
            this->bevel_color3,
            this->bevel_color4,
            this->bevel_color5,
            this->bevel_color6);
    }

    return 1;
}

int TEasy_Panel::create_auto_scrollbar(TScrollBarPanel** param_1, TTextPanel* param_2, long param_3) {
    // Fully verified. Source of truth: Panel_ez.cpp.decomp @ 0x00469A80
    int ok = this->create_scrollbar(param_2->parent_panel, param_1, param_2, 0, 0, 0, param_3, 0);
    if (ok == 0) {
        return 0;
    }
    param_2->set_scrollbar(*param_1, 1);
    return 1;
}

int TEasy_Panel::create_vert_slider(TPanel* param_1, TVerticalSliderPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9) {
    (void)param_1; (void)param_2; (void)param_3; (void)param_4; (void)param_5; (void)param_6; (void)param_7; (void)param_8; (void)param_9;
    return 0;
}

int TEasy_Panel::create_horz_slider(TPanel* param_1, THorizontalSliderPanel** param_2, long param_3, long param_4, long param_5, long param_6, long param_7, long param_8, long param_9) {
    (void)param_1; (void)param_2; (void)param_3; (void)param_4; (void)param_5; (void)param_6; (void)param_7; (void)param_8; (void)param_9;
    return 0;
}

void TEasy_Panel::position_panel(TPanel* param_1, long param_2, long param_3, long param_4, long param_5) {
    (void)param_1; (void)param_2; (void)param_3; (void)param_4; (void)param_5;
}
