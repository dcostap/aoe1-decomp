class Base_BuildItem {
public:
    virtual ~Base_BuildItem();
};

class BuildItem : public Base_BuildItem {
public:
    virtual ~BuildItem();
};

BuildItem::~BuildItem() {
}
