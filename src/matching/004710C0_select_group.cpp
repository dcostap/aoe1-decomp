#ifndef PLAYER_GROUPED_TU
class RGE_Game_Object { public: char gap_00[0x37]; unsigned char group; };
class Node { public: RGE_Game_Object* object; Node* next; };
class List { public: Node* head; Node* first; };
class RGE_Player { public: char pad_00[0x28]; List* selected_list; int select_one_object(RGE_Game_Object* obj, int first); int select_group(int group); };
#endif
int RGE_Player::select_group(int group) {
    int first = 1;
    RGE_Object_Node* node = this->objects->list;
    while (node != 0) {
        RGE_Static_Object* obj = node->node;
        if (obj->selected_group == (unsigned char)group) {
            if (first) {
                if (this->select_one_object(obj, 1) == 0) break;
                first = 0;
            } else {
                if (this->select_one_object(obj, 0) == 0) break;
            }
        }
        node = node->next;
    }
    return first == 0;
}
