// Authentic PDB-order source module for C:\\msdev\\work\\age1_x1\\rmm_base.cpp.

#include "../include/rmm_base.h"
#include "../include/map.h"
#include "../include/debuglog.h"
#include "../include/game_globals.h"

#include <stdlib.h>
#include <string.h>

extern "C" int __cdecl debug_rand(char* file, int line);
void operator_delete(void* block);

extern "C" double sqrt(double value);
#pragma intrinsic(sqrt)

RGE_Random_Map_Module::RGE_Random_Map_Module(
    RGE_Map* map, RGE_Random_Map_Module* parent, uchar create_shared)
{
    this->parent = parent;
    this->map = map;

    if (map != 0) {
        this->map_row_offset = map->give_up_map_offsets();
        this->map_width = this->map->get_map_width();
        this->map_height = this->map->get_map_height();
    } else {
        this->map_row_offset = 0;
        this->map_width = 0;
        this->map_height = 0;
    }

    // BINARY NOTE: Publish empty state before a parent receives this object.
    this->list = 0;
    this->search_map = 0;
    this->search_map_rows = 0;
    this->stack_array = 0;
    this->stack_offsets = 0;

    if (this->parent == 0) {
        if (create_shared != 0) {
            this->create_shared_resources();
        }
    } else {
        this->parent->add_module(this);
        this->parent->share_resources(&this->search_map, &this->search_map_rows,
                                      &this->stack_array, &this->stack_offsets);
    }
}

RGE_Random_Map_Module::~RGE_Random_Map_Module()
{
    while (this->list != 0) {
        RGE_Random_Map_Module* module = this->list->module;
        if (module != 0) {
            module->~RGE_Random_Map_Module();
            operator_delete(module);
        }
    }

    if (this->parent == 0) {
        this->destroy_shared_resources();
    } else {
        this->parent->remove_module(this);
        this->search_map = 0;
        this->search_map_rows = 0;
        this->stack_array = 0;
        this->stack_offsets = 0;
    }

    this->map = 0;
    this->map_row_offset = 0;
    this->map_width = 0;
    this->map_height = 0;
}

float RGE_Random_Map_Module::get_schedule()
{
    return this->schedule;
}

uchar RGE_Random_Map_Module::generate()
{
    RGE_Random_Map_Module_List* current = this->list;
    RGE_Random_Map_Module_List* sorted = 0;

    while (current != 0) {
        RGE_Random_Map_Module_List* next = current->next;
        if (sorted != 0 &&
            current->module->get_schedule() >= sorted->module->get_schedule()) {
            RGE_Random_Map_Module_List* search = sorted;
            while (search != 0) {
                if (search->next == 0 ||
                    current->module->get_schedule() < search->next->module->get_schedule()) {
                    current->next = search->next;
                    search->next = current;
                    break;
                }
                search = search->next;
            }
        } else {
            current->next = sorted;
            sorted = current;
        }
        current = next;
    }

    this->list = sorted;
    L->Log("RGE_RANDOM_MAP_MODULE::map start",
           debug_rand("C:\\msdev\\work\\age1_x1\\rmm_base.cpp", 0x8A));

    current = this->list;
    if (current == 0)
        return 1;

    while (current != 0) {
        if (current->module->generate() == 0)
            return 0;

        L->Log("RGE_RANDOM_MAP_MODULE::module completed with ret:",
               debug_rand("C:\\msdev\\work\\age1_x1\\rmm_base.cpp", 0x8F));
        current = current->next;
    }

    return 1;
}

uchar RGE_Random_Map_Module::add_module(RGE_Random_Map_Module* module)
{
    RGE_Random_Map_Module_List* item;

    if (module == 0) {
        return 0;
    }
    // BINARY NOTE: The shipped code dereferences allocation failure.
    // Publish the complete node only after both fields have values.
    item = (RGE_Random_Map_Module_List*)calloc(1, 8);
    item->next = this->list;
    item->module = module;
    this->list = item;
    return 1;
}

// ACCEPTED DRIFT: The compared pointers, list edits, free call, and return
// values match.  The remaining bytes are register-color and address-source
// choices in the list walk.
uchar RGE_Random_Map_Module::remove_module(
    RGE_Random_Map_Module* param_1)
{
    RGE_Random_Map_Module_List* head = this->list;
    RGE_Random_Map_Module_List* found = 0;

    if (head != 0) {
        if (head->module == param_1) {
            found = head;
            this->list = head->next;
        } else {
            RGE_Random_Map_Module_List* curr;
            RGE_Random_Map_Module_List** pprev = &head->next;
            curr = *pprev;
            if (curr != 0) {
                do {
                    if (curr->module == param_1) {
                        found = curr;
                        *pprev = curr->next;
                    }
                    pprev = &(*pprev)->next;
                    curr = *pprev;
                } while (curr != 0);
            }
        }
    }

    if (found != 0) {
        free(found);
        return 1;
    }
    return 0;
}

void RGE_Random_Map_Module::create_shared_resources()
{
    int i;
    int y;
    int count;

    count = map_height;
    count *= map_width;
    // BINARY NOTE: Store each allocation before row-pointer publication.
    // The shipped code does not test allocation results.
    search_map = (uchar*)calloc(count, 1);
    search_map_rows = (uchar**)calloc(map_height, 4);

    for (i = 0; i < map_height; i++) {
        search_map_rows[i] = search_map + i * map_width;
    }

    count = map_height;
    count *= map_width;
    stack_array = (Map_Stack*)calloc(count, 0x18);
    stack_offsets = (Map_Stack**)calloc(map_height, 4);

    for (i = 0; i < map_height; i++) {
        stack_offsets[i] = &stack_array[i * map_width];
    }

    for (i = 0; i < map_height; i++) {
        for (y = 0; y < map_width; y++) {
            stack_offsets[i][y].x = y;
            stack_offsets[i][y].y = i;
        }
    }
}

void RGE_Random_Map_Module::destroy_shared_resources()
{
    if (search_map != 0) {
        free(search_map);
    }
    search_map = 0;
    if (search_map_rows != 0) {
        free(search_map_rows);
    }
    search_map_rows = 0;
    if (stack_array != 0) {
        free(stack_array);
    }
    stack_array = 0;
    if (stack_offsets != 0) {
        free(stack_offsets);
    }
    stack_offsets = 0;
}

void RGE_Random_Map_Module::update_child_resources()
{
    RGE_Random_Map_Module_List* node;

    node = this->list;
    while (node != 0) {
        node->module->update_resources();
        node = node->next;
    }
}

void RGE_Random_Map_Module::update_resources()
{
    this->parent->share_resources(&this->search_map, &this->search_map_rows,
                                  &this->stack_array, &this->stack_offsets);
    this->update_child_resources();
}

void RGE_Random_Map_Module::update_child_map_info()
{
    RGE_Random_Map_Module_List* node;

    node = this->list;
    while (node != 0) {
        node->module->update_map_info(this->map);
        node = node->next;
    }
}

void RGE_Random_Map_Module::update_map_info(RGE_Map* param_1)
{
    this->map = param_1;
    if (param_1 != 0) {
        this->map_row_offset = param_1->give_up_map_offsets();
        this->map_width = this->map->get_map_width();
        this->map_height = this->map->get_map_height();
    } else {
        this->map_row_offset = 0;
        this->map_width = 0;
        this->map_height = 0;
    }
    this->update_child_map_info();
}

void RGE_Random_Map_Module::share_resources(
    uchar** a, uchar*** b, Map_Stack** c, Map_Stack*** d)
{
    if (a != 0) {
        *a = this->search_map;
    }
    if (b != 0) {
        *b = this->search_map_rows;
    }
    if (c != 0) {
        *c = this->stack_array;
    }
    if (d != 0) {
        *d = this->stack_offsets;
    }
}

void RGE_Random_Map_Module::init_stack(Map_Stack& stack)
{
    stack.x = -1;
    stack.y = -1;
    stack.next = 0;
    stack.prev = 0;
    stack.cost = 0;
    stack.tot_cost = 0;
}

void RGE_Random_Map_Module::deinit_stack(Map_Stack& stack)
{
    if (stack.next) {
        stack.next->prev = 0;
        stack.next = 0;
    }
}

void RGE_Random_Map_Module::push_stack(
    Map_Stack& list, long param_2, long param_3, float param_4, float param_5)
{
    Map_Stack* node = &this->stack_offsets[param_3][param_2];
    this->remove_stack_node(node);

    Map_Stack* current = list.next;

    if (current != 0 && current->tot_cost < param_5) {
        Map_Stack* prev;
        do {
            prev = current;
            current = current->next;
        } while (current != 0 && current->tot_cost < param_5);

        this->add_stack_node(prev, node);
        *(long*)&node->cost = *(long*)&param_4;
        node->tot_cost = param_5;
        return;
    }

    this->add_stack_node(&list, node);
    *(long*)&node->cost = *(long*)&param_4;
    node->tot_cost = param_5;
}

Map_Stack* RGE_Random_Map_Module::pop_stack(
    Map_Stack& head, long& x, long& y, float& cost)
{
    Map_Stack* node = head.next;
    if (node == 0) {
        return 0;
    }
    x = node->x;
    y = node->y;
    cost = node->cost;
    this->remove_stack_node(node);
    return node;
}

void RGE_Random_Map_Module::add_stack_node(
    Map_Stack* target, Map_Stack* node)
{
    if ((node->next != 0) || (node->prev != 0)) {
        this->remove_stack_node(node);
    }
    Map_Stack* next = target->next;
    node->prev = target;
    node->next = next;
    if (target->next != 0) {
        target->next->prev = node;
    }
    target->next = node;
}

void RGE_Random_Map_Module::remove_stack_node(Map_Stack* node)
{
    if (node->prev != 0) {
        node->prev->next = node->next;
    }
    if (node->next != 0) {
        node->next->prev = node->prev;
    }
    node->next = 0;
    node->prev = 0;
}

void RGE_Random_Map_Module::clear_stack()
{
    int y;
    int x;

    for (y = 0; y < this->map_height; ++y) {
        for (x = 0; x < this->map_width; ++x) {
            this->stack_offsets[y][x].next = 0;
            this->stack_offsets[y][x].prev = 0;
        }
    }
}

uchar RGE_Random_Map_Module::check_stack(Map_Stack* stack)
{
    if (stack->next == 0 && stack->prev == 0) {
        return 0;
    }
    return 1;
}

// SCRATCH: The five randomization calls and list edits remain aligned, but the
// natural body has a frame-size and control-flow mismatch.
void RGE_Random_Map_Module::randomize_stack(Map_Stack* param_1)
{
    Map_Stack sub_stacks[100];
    int i;

    for (i = 0; i < 100; i++) {
        init_stack(sub_stacks[i]);
    }

    for (int outer = 2; outer != 0; outer--) {
        while (param_1->next != 0) {
            int r = (debug_rand("C:\\msdev\\work\\age1_x1\\rmm_base.cpp", 0x1E8) * 100) / 0x7FFF;
            add_stack_node(&sub_stacks[r], param_1->next);
        }

        for (int stack_index = 1; stack_index < 100; stack_index += 2) {
            while (sub_stacks[stack_index - 1].next != 0 ||
                   sub_stacks[stack_index].next != 0) {
                if (sub_stacks[stack_index - 1].next != 0) {
                    add_stack_node(param_1, sub_stacks[stack_index - 1].next);
                }
                if (sub_stacks[stack_index].next != 0) {
                    add_stack_node(param_1, sub_stacks[stack_index].next);
                }
            }
        }
    }
}

uchar RGE_Random_Map_Module::find_path(
    long param_1, long param_2, long& param_3, long& param_4,
    float* param_5)
{
    Map_Stack path_stack;
    uchar result;

    this->init_stack(path_stack);
    result = this->find_path(path_stack, param_1, param_2,
                             param_3, param_4, param_5);
    this->deinit_stack(path_stack);
    return result;
}

// PDB CONTEXT: C:\\msdev\\work\\age1_x1\\rmm_base.cpp lines 526-849
// own this second overload.  The executable has ten ordered helper calls,
// including clear_stack, eight push_stack calls, and pop_stack.
// LIKELY INTENT: Search eight neighboring tiles through the shared stack and
// byte map.  The retained source is scratch because its FPU/local-slot basin
// differs from the executable.
uchar RGE_Random_Map_Module::find_path(
    Map_Stack& path_stack, long x, long y, long& target_x, long& target_y,
    float* terrain_cost)
{
    unsigned char calc_cost[4];  // [1]=up, [2]=right, [3]=down
    float tcost;
    unsigned char tile_type;
    float cost;
    float ty;
    long map_h;
    long map_w;
    long local_4;
    unsigned char state;
    unsigned char* cell;

    ty = 0.0f;
    local_4 = this->map_width;
    --local_4;
    map_w = this->map_height;
    --map_w;
    this->clear_stack();
    memset(this->search_map, 0, this->map_height * this->map_width);

    this->search_map_rows[y][x] = 3;
    tile_type = this->map_row_offset[target_y][target_x].terrain_type & 0x1F;
    this->search_map_rows[target_y][target_x] = 2;

    if (terrain_cost[tile_type] > 0.0f) {
        map_h = (x - target_x) * (x - target_x)
            + (y - target_y) * (y - target_y);
        cost = (float)sqrt((double)map_h);

        while (cost != 0.0) {
            if (y < map_w) {
                float hcost;
                if (target_y <= y) {
                    hcost = cost - -1.0f;
                } else {
                    hcost = cost - 1.0f;
                }

                cell = this->search_map_rows[y + 1] + x;
                state = this->search_map_rows[y + 1][x];
                if (state == 0) {
                    tile_type = this->map_row_offset[y + 1][x].terrain_type & 0x1F;
                    if (terrain_cost[tile_type] > 0.0) {
                        tcost = ty + terrain_cost[tile_type];
                        *cell = 7;
                        this->push_stack(path_stack, x, y + 1,
                                         tcost, tcost + hcost);
                        calc_cost[2] = 1;
                    } else {
                        *cell = 1;
                        calc_cost[2] = 0;
                    }
                } else if (state == 2) {
                    *cell = 7;
                    target_x = x;
                    target_y = y + 1;
                    return 1;
                } else {
                    if (state == 1) calc_cost[2] = 0;
                    else calc_cost[2] = 1;
                }
            } else {
                calc_cost[2] = 0;
            }

            if (y > 0) {
                float hcost;
                if (target_y < y) {
                    hcost = cost - 1.0f;
                } else {
                    hcost = cost - -1.0f;
                }

                cell = this->search_map_rows[y - 1] + x;
                state = this->search_map_rows[y - 1][x];
                if (state == 0) {
                    tile_type = this->map_row_offset[y - 1][x].terrain_type & 0x1F;
                    if (terrain_cost[tile_type] > 0.0) {
                        tcost = ty + terrain_cost[tile_type];
                        *cell = 6;
                        this->push_stack(path_stack, x, y - 1,
                                         tcost, tcost + hcost);
                        calc_cost[1] = 1;
                    } else {
                        *cell = 1;
                        calc_cost[1] = 0;
                    }
                } else if (state == 2) {
                    *cell = 6;
                    target_x = x;
                    target_y = y - 1;
                    return 1;
                } else {
                    if (state == 1) calc_cost[1] = 0;
                    else calc_cost[1] = 1;
                }
            } else {
                calc_cost[1] = 0;
            }

            if (x > 0) {
                float hcost;
                if (target_x < x) {
                    hcost = cost - 1.0f;
                } else {
                    hcost = cost - -1.0f;
                }

                cell = this->search_map_rows[y] + x - 1;
                state = this->search_map_rows[y][x - 1];
                if (state == 0) {
                    tile_type = this->map_row_offset[y][x - 1].terrain_type & 0x1F;
                    if (terrain_cost[tile_type] > 0.0f) {
                        tcost = terrain_cost[tile_type] + ty;
                        *cell = 4;
                        this->push_stack(path_stack, x - 1, y,
                                         tcost, tcost + hcost);
                        calc_cost[3] = 1;
                    } else {
                        *cell = 1;
                        calc_cost[3] = 0;
                    }
                } else if (state == 2) {
                    *cell = 4;
                    target_x = x - 1;
                    target_y = y;
                    return 1;
                } else {
                    if (state == 1) calc_cost[3] = 0;
                    else calc_cost[3] = 1;
                }

                if (y > 0) {
                    map_h = y - 1;
                    cell = this->search_map_rows[map_h] + x - 1;
                    state = this->search_map_rows[map_h][x - 1];
                    if (state == 0) {
                        tile_type = this->map_row_offset[map_h][x - 1].terrain_type & 0x1F;
                        if (terrain_cost[tile_type] > 0.0f) {
                            if (calc_cost[1] && calc_cost[3]) {
                                tcost = ty - terrain_cost[tile_type] * DAT_00571e50;
                                *cell = 8;
                                if (target_y < y) {
                                    hcost = hcost - 0.41f;
                                } else {
                                    hcost = hcost - -0.41f;
                                }
                                this->push_stack(path_stack, x - 1, map_h,
                                                 tcost, tcost + hcost);
                            }
                        } else {
                            *cell = 1;
                        }
                    } else if (state == 2) {
                        *cell = 8;
                        target_x = x - 1;
                        target_y = y - 1;
                        return 1;
                    }
                }

                if (y < map_w) {
                    map_h = y + 1;
                    cell = this->search_map_rows[map_h] + x - 1;
                    state = this->search_map_rows[map_h][x - 1];
                    if (state == 0) {
                        tile_type = this->map_row_offset[map_h][x - 1].terrain_type & 0x1F;
                        if (terrain_cost[tile_type] > 0.0f) {
                            if (calc_cost[2] && calc_cost[3]) {
                                tcost = ty - terrain_cost[tile_type] * DAT_00571e50;
                                *cell = 9;
                                if (target_y < y) {
                                    hcost = hcost - 0.41f;
                                } else {
                                    hcost = hcost - -0.41f;
                                }
                                this->push_stack(path_stack, x - 1, map_h,
                                                 tcost, tcost + hcost);
                            }
                        } else {
                            *cell = 1;
                        }
                    } else if (state == 2) {
                        *cell = 9;
                        target_x = x - 1;
                        target_y = y + 1;
                        return 1;
                    }
                }
            }

            if (x < local_4) {
                float hcost;
                if (target_x <= x) {
                    hcost = cost - -1.0f;
                } else {
                    hcost = cost - 1.0f;
                }

                cell = this->search_map_rows[y] + x + 1;
                state = this->search_map_rows[y][x + 1];
                if (state == 0) {
                    tile_type = this->map_row_offset[y][x + 1].terrain_type & 0x1F;
                    if (terrain_cost[tile_type] > 0.0f) {
                        tcost = ty + terrain_cost[tile_type];
                        *cell = 5;
                        this->push_stack(path_stack, x + 1, y,
                                         tcost, tcost + hcost);
                        calc_cost[3] = 1;
                    } else {
                        *cell = 1;
                        calc_cost[3] = 0;
                    }
                } else if (state == 2) {
                    *cell = 5;
                    target_x = x + 1;
                    target_y = y;
                    return 1;
                } else {
                    if (state == 1) calc_cost[3] = 0;
                    else calc_cost[3] = 1;
                }

                if (y > 0) {
                    map_h = y - 1;
                    cell = this->search_map_rows[map_h] + x + 1;
                    state = this->search_map_rows[map_h][x + 1];
                    if (state == 0) {
                        tile_type = this->map_row_offset[map_h][x + 1].terrain_type & 0x1F;
                        if (terrain_cost[tile_type] > 0.0f) {
                            if (calc_cost[1] && calc_cost[3]) {
                                tcost = ty - terrain_cost[tile_type] * DAT_00571e50;
                                *cell = 10;
                                if (target_y <= y) {
                                    hcost = hcost - -0.41f;
                                } else {
                                    hcost = hcost - 0.41f;
                                }
                                this->push_stack(path_stack, x + 1, map_h,
                                                 tcost, tcost + hcost);
                            }
                        } else {
                            *cell = 1;
                        }
                    } else if (state == 2) {
                        *cell = 10;
                        target_x = x + 1;
                        target_y = y - 1;
                        return 1;
                    }
                }

                if (y < map_w) {
                    map_h = y + 1;
                    cell = this->search_map_rows[map_h] + x + 1;
                    state = this->search_map_rows[map_h][x + 1];
                    if (state == 0) {
                        tile_type = this->map_row_offset[map_h][x + 1].terrain_type & 0x1F;
                        if (terrain_cost[tile_type] > 0.0f) {
                            if (calc_cost[2] && calc_cost[3]) {
                                tcost = ty - terrain_cost[tile_type] * DAT_00571e50;
                                *cell = 11;
                                if (target_y <= y) {
                                    hcost = hcost - -0.41f;
                                } else {
                                    hcost = hcost - 0.41f;
                                }
                                this->push_stack(path_stack, x + 1, map_h,
                                                 tcost, tcost + hcost);
                            }
                        } else {
                            *cell = 1;
                        }
                    } else if (state == 2) {
                        *cell = 11;
                        target_x = x + 1;
                        target_y = y + 1;
                        return 1;
                    }
                }
            }

            if (this->pop_stack(path_stack, x, y, ty) == 0) {
                return 0;
            }

            map_h = (x - target_x) * (x - target_x)
                + (y - target_y) * (y - target_y);
            cost = (float)sqrt((double)map_h);
        }

        if (path_stack.next != 0) {
            path_stack.next->prev = 0;
        }
        return 1;
    }
    return 0;
}
