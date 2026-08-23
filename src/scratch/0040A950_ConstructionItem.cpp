class Base_ConstructionItem {
public:
    virtual ~Base_ConstructionItem();
};

class ConstructionItem : public Base_ConstructionItem {
public:
    virtual ~ConstructionItem();
};

ConstructionItem::~ConstructionItem() {
}
