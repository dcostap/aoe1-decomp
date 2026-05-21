// 00470D80 RGE_Player::select_one_object
// Source: player.cpp lines 1803-1842
// Attempt log:
// Probe 1: raw-offset natural implementation from packet; wrong sel_count offset and early fail tails.
// Probe 2: added extra selection slot for +0x19C count and explicit gotos; gotos made fail tail too early.
// Probe 3: positive outer guard and success body before final return 0.
// Probe 4: slot initialized to -1 before current-count slot test to match original ESI setup.
// Probe 5: explicit loop labels worsened into peeled loop.
// Probe 6: for-loop scan form.

class RGE_Sound { public: void play(int); };
class RGE_Static_Object { public: char gap_00[0x08]; void* master_obj; void* owner; char gap_10[0x26]; unsigned char selected; };
class RGE_Player {
public:
    char gap_00[0x130];
    RGE_Static_Object* selected_obj;
    RGE_Static_Object* sel_list[26];
    short sel_count;
    int select_one_object(RGE_Static_Object* obj, int play_sound);
};

int RGE_Player::select_one_object(RGE_Static_Object* obj, int play_sound)
{
    short count = this->sel_count;
    if (count < 25) {
        short slot = -1;
        if (this->sel_list[count] == 0) {
            slot = count;
        } else {
            short i = 0;
            if (count > 0) {
                for (; i < count; ++i) {
                    if (this->sel_list[i] == 0) {
                        slot = i;
                        break;
                    }
                }
            }
        }
        if (slot != -1) {
            this->sel_list[slot] = obj;
            ++this->sel_count;
            this->selected_obj = obj;
            obj->selected = 1;
            if (play_sound != 0) {
                RGE_Sound* sound = *(RGE_Sound**)((char*)obj->master_obj + 0x3C);
                if (sound != 0) {
                    RGE_Player* owner = (RGE_Player*)obj->owner;
                    if (owner == this || *(short*)((char*)owner + 0x4A) == 0)
                        sound->play(1);
                }
            }
            return 1;
        }
    }
    return 0;
}
