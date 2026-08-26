#ifndef AOE1_PANEL_CONTEXT_H
class TPanel {
public:

    void set_tab_order(TPanel** panels, short count);
    void set_tab_order(TPanel* previous, TPanel* next);
};

#endif
void TPanel::set_tab_order(TPanel** panels, short count) {
    int i;
    int total;

    total = (int)count;
    i = 0;
    if (0 < total) {
        do {
            TPanel* prev;
            TPanel* next;

            if (i == 0) {
                prev = panels[total - 1];
            } else {
                prev = panels[i - 1];
            }
            if (i == total - 1) {
                next = panels[0];
            } else {
                next = panels[i + 1];
            }
            panels[i]->set_tab_order(prev, next);
            i++;
        } while (i < total);
    }
}
