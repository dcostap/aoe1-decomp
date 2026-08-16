extern void __stdcall setTaskedHelper(int val);

class RGE_Active_Sprite_List {
public:
    void setTaskedByPlayer();
};

void RGE_Active_Sprite_List::setTaskedByPlayer() {
    setTaskedHelper(0);
}
