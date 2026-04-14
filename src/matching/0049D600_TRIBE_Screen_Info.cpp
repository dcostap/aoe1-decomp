class Base_TRIBE_Screen_Info {
public:
    virtual ~Base_TRIBE_Screen_Info();
};

class TRIBE_Screen_Info : public Base_TRIBE_Screen_Info {
public:
    virtual ~TRIBE_Screen_Info();
};

TRIBE_Screen_Info::~TRIBE_Screen_Info() {
}
