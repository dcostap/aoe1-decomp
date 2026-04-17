extern "C" int __cdecl strcmp(const char* s1, const char* s2);

class TPanel {
public:
    char* panelName(void);
};

struct PanelNode {
    TPanel* panel;
    PanelNode* prev_node;
    PanelNode* next_node;
};

class TPanelSystem {
public:
    int field_00;
    int field_04;
    int field_08;
    int field_0C;
    PanelNode* panelListValue;

    PanelNode* findPanelNode(char* name);
};

PanelNode* TPanelSystem::findPanelNode(char* name) {
    TPanelSystem* self;
    char* target;
    PanelNode* node;

    self = this;
    target = name;
    if (target == 0) {
        return 0;
    }
    node = self->panelListValue->next_node;
    while (node != self->panelListValue && strcmp(node->panel->panelName(), target) != 0) {
        node = node->next_node;
    }
    if (node != self->panelListValue && strcmp(node->panel->panelName(), target) == 0) {
        return node;
    }
    return 0;
}
