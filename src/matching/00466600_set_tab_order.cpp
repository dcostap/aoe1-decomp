// Context gate: Panel.cpp lines 2328-2347, TPanel owner. The loop uses a
// signed short count and calls each panel's scalar tab-order overload.
// BINARY NOTE: the original call reaches virtual slot +0xC4.
// Blocker: grouped context places that overload at +0xC8 because of the
// shared overload declaration order.

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
