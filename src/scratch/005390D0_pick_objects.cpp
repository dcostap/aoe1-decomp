// 005390D0 RGE_View::pick_objects
// Attempt log:
// try 1-10: prior decompiler-shaped grid/object model was too short (674-688B) and
// used a fake pick_mask_test call; the binary actually walks prior_objs draw levels
// and calls RGE_View::sprite_check while maintaining sorted RGE_SPick_Info lists.
// probe 1 baseline: canonical ownership rewrite pending; prior source was not a
// behavior-backed reconstruction.
// probe 2: replaced the grid/object scaffold with the binary-backed draw-level
// scan, sprite_check call, free-list reuse, sorted insertion, and compact output;
// call set and size became structurally close.
// probe 3: removed artificial head[0] initialization; this recovered the
// compiler's overlapping count/list stack window and improved the diff.
// probe 4: separate validation guards, explicit level cursor, integer keep flag,
// and natural for loops recovered the 0x54 frame and many exact blocks.
// probe 5-7: tested declaration/context and a named pick_list_size[1..4] pointer;
// the contiguous member initialization improved resync similarity.
// probe 8: named all rectangle bounds reached exact size but worsened the
// register basin; restored direct canonical member expressions.
// probe 10: a named normalized hot_y lifetime worsened strict bytes; restored.
// probe 12: register total_picked was a codegen duplicate and was not retained.
// probe 14: paired entry hunk proved the original first test is x < 0; replacing
// the radius guard improved shape but worsened strict bytes and did not recover
// the pre-save x load. Restored the clean canonical source; first-hunk lead is
// exhausted without a natural typed declaration-order explanation.
// best retained check: 1048B rebuilt vs 1081B, 956 strict diff bytes, 65.98%
// shape similarity, exact frame/call set; remaining drift is broad prologue,
// register/liveness, and block-layout scheduling, not a call or layout blocker.
// worker pass: parameter-left upper viewport checks improve strict diff to 952
// bytes; coordinate aliases, scalar-home reuse, and ambient TU samples did not.

#ifndef RGE_VIEW_SHARED_CONTEXT
struct Shape_Info;

struct RGE_SPick_Info {
    int object_id;                 // +0x00
    short confidence;              // +0x04
    short draw_level;              // +0x06
    short draw_x;                  // +0x08
    short draw_y;                  // +0x0A
    RGE_SPick_Info* next;          // +0x0C
    RGE_SPick_Info* prev;          // +0x10
};

struct Picked_Info {
    int object_id;
    short confidence;
    short draw_level;
    short draw_x;
    short draw_y;
};

extern Picked_Info Picked_Objects[];

struct DClipInfo_Node {
    DClipInfo_Node* Next;          // +0x00
    DClipInfo_Node* NextOnLevel;   // +0x04
    int Object_ID;                 // +0x08
    Shape_Info* Shape;             // +0x0C
    int Draw_Level;                // +0x10
    int Draw_X;                    // +0x14
    int Draw_Y;                    // +0x18
    int Draw_Flag;                 // +0x1C
    unsigned char* Shape_Base;     // +0x20
    unsigned char* Color_Table;    // +0x24
    int Xform_Mask;                // +0x28
    int Node_Type;                 // +0x2C
    short x1;                      // +0x30
    short y1;                      // +0x32
    short x2;                      // +0x34
    short y2;                      // +0x36
    short x3;                      // +0x38
    short y3;                      // +0x3A
    short x4;                      // +0x3C
    short y4;                      // +0x3E
};

class DClipInfo_List {
public:
    char gap_00[0x5C];
    DClipInfo_Node** Draw_Level_Head;
};

class RGE_View {
public:
    char gap_00[0x8C];
    int x_min;
    int y_min;
    int x_max;
    int y_max;
    char gap_9C[0x260];
    RGE_SPick_Info* pick_lists[5];
    int pick_list_size[5];
    char gap_324[0x10];
    DClipInfo_List* prior_objs;

    int sprite_check(unsigned char* shape_base, Shape_Info* shape, int x, int y);
    int pick_objects(int x, int y, int min_level, int max_level,
                     int radius, int priority, int skip_negative);
};
#endif

int RGE_View::pick_objects(int x, int y, int min_level, int max_level,
                           int radius, int priority, int skip_negative)
{
    RGE_SPick_Info* head[5];
    RGE_SPick_Info* tail[5];
    RGE_SPick_Info* freep[5];
    RGE_SPick_Info* found;
    RGE_SPick_Info* previous;
    RGE_SPick_Info* current;
    RGE_SPick_Info** head_ptr;
    DClipInfo_Node* node;
    int level;
    int confidence;
    int object_id;
    int selected_level;
    short draw_level;
    int i;
    int keep;
    int total_picked = 0;
    int* pick_sizes;

    if (radius < 0) {
        return 0;
    }
    if (max_level < min_level) {
        return 0;
    }
    // BINARY NOTE: The shipped code compares upper bounds with the parameter left.
    if (x < this->x_min || x > this->x_max ||
        y < this->y_min || y > this->y_max) {
        return 0;
    }
    if (0x28 < min_level || max_level < 0) {
        return 0;
    }

    if (min_level < 0) {
        min_level = 0;
    }
    if (max_level > 0x28) {
        max_level = 0x28;
    }

    y -= this->y_min;
    x -= this->x_min;

    pick_sizes = this->pick_list_size + 1;
    pick_sizes[0] = 0;
    pick_sizes[1] = 0;
    pick_sizes[2] = 0;
    pick_sizes[3] = 0;

    freep[1] = 0;
    freep[2] = 0;
    freep[3] = 0;
    freep[4] = 0;
    tail[1] = 0;
    tail[2] = 0;
    tail[3] = 0;
    tail[4] = 0;
    head[1] = 0;
    head[2] = 0;
    head[3] = 0;
    head[4] = 0;

    level = max_level;
    do {
        if (level < min_level) {
            int output_level = 1;
            head_ptr = head + 1;
            for (; output_level < 5; ++output_level, ++head_ptr) {
                current = *head_ptr;
                if (current != 0) {
                    Picked_Info* output = &Picked_Objects[total_picked];
                    do {
                        output->object_id = current->object_id;
                        output->confidence = current->confidence;
                        output->draw_level = current->draw_level;
                        output->draw_x = current->draw_x;
                        output->draw_y = current->draw_y;
                        ++total_picked;
                        ++output;
                        current = current->next;
                    } while (current != 0);
                }
            }
            return total_picked;
        }

        node = this->prior_objs->Draw_Level_Head[level];
        for (; node != 0; node = node->NextOnLevel) {
            confidence = 0;
            if (node->Node_Type == 0 &&
                (skip_negative == 0 || node->Object_ID >= 0)) {
                int node_y1 = node->y1;
                int node_x2 = node->x2;
                if (x < node->x1 - radius ||
                    y < node_y1 - radius ||
                    radius + node_x2 < x ||
                    node->y2 + radius < y) {
                    confidence = 0;
                } else {
                    confidence = 4;
                    if (node->x1 <= x && node_y1 <= y &&
                        x <= node_x2 && y <= node->y2) {
                        confidence = 3;
                        if ((node->Draw_Flag & 2) == 2) {
                            node_x2 -= x;
                        } else {
                            node_x2 = x - node->x1;
                        }
                        int mask = this->sprite_check(
                            node->Shape_Base, node->Shape,
                            node_x2, y - node_y1);
                        if (mask == 1) {
                            confidence = 2;
                        } else if (mask == 2) {
                            confidence = 1;
                        }
                    }
                }
            }

            if (confidence != 0 && confidence <= priority) {
                draw_level = node->y3;
                object_id = node->Object_ID;
                keep = 1;
                found = 0;
                int picked_level = 1;
                head_ptr = head + 1;
                do {
                    if (found == 0) {
                        current = *head_ptr;
                        if (current != 0) {
                            do {
                                if (current->object_id == object_id) {
                                    found = current;
                                    selected_level = picked_level;
                                    break;
                                }
                                current = current->next;
                            } while (current != 0);
                        }
                    }
                    ++picked_level;
                    ++head_ptr;
                } while (picked_level < 5);

                if (found != 0) {
                    if (selected_level < confidence ||
                        (selected_level == confidence &&
                         draw_level < found->draw_level)) {
                        keep = 0;
                    }

                    if (keep) {
                        if (head[selected_level] == found) {
                            head[selected_level] = found->next;
                        }
                        if (tail[selected_level] == found) {
                            tail[selected_level] = found->prev;
                        }
                        if (found->next != 0) {
                            found->next->prev = found->prev;
                        }
                        if (found->prev != 0) {
                            found->prev->next = found->next;
                        }
                        found->next = freep[selected_level];
                        found->prev = 0;
                        freep[selected_level] = found;
                    }
                }

                if (keep) {
                    current = freep[confidence];
                    if (current == 0) {
                        i = this->pick_list_size[confidence];
                        if (i == 0x40) {
                            keep = 0;
                        } else {
                            current = this->pick_lists[confidence] + i;
                            this->pick_list_size[confidence] = i + 1;
                        }
                    } else {
                        freep[confidence] = current->next;
                    }

                    if (keep) {
                        current->object_id = object_id;
                        current->confidence = (short)confidence;
                        current->draw_level = draw_level;
                        current->draw_x = (short)node->Draw_X;
                        current->draw_y = (short)node->Draw_Y;
                        head_ptr = head + confidence;
                        current->next = 0;
                        current->prev = 0;
                        found = *head_ptr;
                        if (found == 0) {
                            *head_ptr = current;
                            tail[confidence] = current;
                        } else {
                            do {
                                if (found->draw_level <= draw_level) {
                                    current->next = found;
                                    previous = found->prev;
                                    current->prev = previous;
                                    if (previous == 0) {
                                        *head_ptr = current;
                                        found->prev = current;
                                    } else {
                                        current->prev->next = current;
                                        found->prev = current;
                                    }
                                    break;
                                }
                                previous = found->next;
                                if (previous == 0) {
                                    found->next = current;
                                    current->prev = found;
                                    tail[confidence] = current;
                                    break;
                                }
                                found = previous;
                            } while (found != 0);
                        }
                    }
                }
            }

        }
        --level;
    } while (true);
}
