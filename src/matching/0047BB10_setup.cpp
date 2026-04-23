class TDrawArea;
class TPanel;

class TEasy_Panel {
public:
    long setup(TDrawArea* draw_area, TPanel* parent, char* text, long id, int visible, int a6, int a7, int a8, int a9, int a10);
};

class TScreenPanel : public TEasy_Panel {
public:
    long setup(TDrawArea* draw_area, char* text, long id, unsigned char flag, int param5);
};

long TScreenPanel::setup(TDrawArea* draw_area, char* text, long id, unsigned char flag, int param5) {
    return TEasy_Panel::setup(draw_area, 0, 0, -1, 1, 0, 0, 0, 0, param5) != 0;
}
