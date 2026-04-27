// VA: 0043F130 TListDialog::setup (wrapper)
// dlg_list.cpp lines 106-116

// attempt 1: wrapper that resolves string, calls main setup
// ret 58h

#include <string.h>

class TPanel {
public:
    virtual ~TPanel();
    int get_string(int id, char* buffer, int max_len);
};

class TTextPanel : public TPanel {
public:
    virtual ~TTextPanel();
};

class TListPanel : public TTextPanel {
public:
    virtual ~TListPanel();
};

class TButtonPanel : public TPanel {
public:
    virtual ~TButtonPanel();
};

class TEasy_Panel : public TPanel {
public:
    virtual ~TEasy_Panel();
};

class TDialogPanel : public TEasy_Panel {
public:
    virtual ~TDialogPanel();
};

class TListDialog : public TDialogPanel {
public:
    TPanel* parent;
    TPanel* title;
    TListPanel* list;
    TPanel* extra_scroll;
    TButtonPanel* ok_btn;
    TButtonPanel* cancel_btn;
    short list_id;
    char* list_name;

    virtual ~TListDialog();
    long setup(TPanel* param_1, char* param_2, long param_3, long param_4,
        long param_5, long param_6, long param_7, long param_8, long param_9,
        char* param_10, long param_11, long param_12, long param_13, long param_14,
        char** param_15, short param_16, short param_17, long param_18, long param_19,
        long param_20, long param_21, long param_22);
    long action(TPanel* param_1, long param_2, unsigned long param_3, unsigned long param_4);
};

long TListDialog::setup(TPanel* param_1, char* param_2, long param_3, long param_4,
    long param_5, long param_6, long param_7, long param_8, long param_9,
    char* param_10, long param_11, long param_12, long param_13, long param_14,
    char** param_15, short param_16, short param_17, long param_18, long param_19,
    long param_20, long param_21, long param_22) {
    
    char str[256];
    TPanel::get_string((int)param_10, str, 0x100);
    
    return ((TListDialog*)this)->setup(param_1, param_2, param_3, param_4,
        param_5, param_6, param_7, param_8, param_9,
        str, param_11, param_12, param_13, param_14,
        param_15, param_16, param_17, param_18, param_19,
        param_20, param_21, param_22);
}
