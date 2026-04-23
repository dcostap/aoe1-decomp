class TDrawArea;
class TPanel;

class TEasy_Panel {
public:
    long setup(TDrawArea* draw_area, TPanel* parent, char* text, long id, int visible, int a, int b, int c, int d, int e);
};

class TScreenPanel : public TEasy_Panel {
public:
    long setup(TDrawArea* draw_area, char* text, long id, int value);
};

long TScreenPanel::setup(TDrawArea* draw_area, char* text, long id, int value) {
    return TEasy_Panel::setup(draw_area, 0, text, id, 1, 0, 0, 0, 0, value) != 0;
}
