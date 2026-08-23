#ifndef AOE1_PNL_LST_CONTEXT_H
class TPanel {};
class TTextPanel : public TPanel {
public:
    virtual long action(TPanel*, long, unsigned long, unsigned long);
};

class TListPanel : public TTextPanel {
public:
    virtual long action(TPanel*, long, unsigned long, unsigned long);

};
#endif

long TListPanel::action(TPanel* panel, long value,
                        unsigned long index, unsigned long zero) {
    return TTextPanel::action(panel, value, index, zero);
}
