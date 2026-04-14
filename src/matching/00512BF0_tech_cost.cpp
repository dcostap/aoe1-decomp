class Tech_Tree_tc {
public:
    void tech_cost(int a, int b, int c, int d, int e, int f, int g);
};

class TRIBE_Player_tc {
public:
    void tech_cost(int a, int b, int c, int d, int e, int f, int g);
    char gap_00[0x220];
    Tech_Tree_tc* tech_tree;
};

void TRIBE_Player_tc::tech_cost(int a, int b, int c, int d, int e, int f, int g) {
    this->tech_tree->tech_cost(a, b, c, d, e, f, g);
}
