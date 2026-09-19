
#include "../include/rmm_base.h"
#include "../include/map.h"
#include "../include/debuglog.h"
#include "../include/game_globals.h"

#include <stdlib.h>
#include <string.h>

extern int __cdecl debug_rand(char* file, int line);
#include <new.h>

extern "C" double sqrt(double value);
#pragma intrinsic(sqrt)

RGE_Random_Map_Module::RGE_Random_Map_Module(
    RGE_Map* in_map, RGE_Random_Map_Module* parent_module,
    uchar resources_needed) {
    this->parent = parent_module;
    this->map = in_map;

    if (in_map != 0) {
        this->map_row_offset = in_map->give_up_map_offsets();
        this->map_width = this->map->get_map_width();
        this->map_height = this->map->get_map_height();
    } else {
        this->map_row_offset = 0;
        this->map_width = 0;
        this->map_height = 0;
    }

    // Publish empty state before a parent receives this object.
    this->list = 0;
    this->search_map = 0;
    this->search_map_rows = 0;
    this->stack_array = 0;
    this->stack_offsets = 0;

    if (this->parent == 0) {
        if (resources_needed != 0) {
            this->create_shared_resources();
        }
    } else {
        this->parent->add_module(this);
        this->parent->share_resources(&this->search_map, &this->search_map_rows, &this->stack_array, &this->stack_offsets);
    }
}

RGE_Random_Map_Module::~RGE_Random_Map_Module() {
    while (this->list != 0) {
        RGE_Random_Map_Module* module = this->list->module;
        if (module != 0) {
            module->~RGE_Random_Map_Module();
            ::operator delete(module);
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

float RGE_Random_Map_Module::get_schedule() {
    return this->schedule;
}

uchar RGE_Random_Map_Module::generate() {
    RGE_Random_Map_Module_List* current = this->list;
    RGE_Random_Map_Module_List* sorted = 0;

    while (current != 0) {
        RGE_Random_Map_Module_List* next = current->next;
        if (sorted != 0 && current->module->get_schedule() >= sorted->module->get_schedule()) {
            RGE_Random_Map_Module_List* search = sorted;
            while (search != 0) {
                if (search->next == 0 || current->module->get_schedule() < search->next->module->get_schedule()) {
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
    L->Log("RGE_RANDOM_MAP_MODULE::map start", debug_rand("C:\\msdev\\work\\age1_x1\\rmm_base.cpp", 138));

    current = this->list;
    if (current == 0)
        return 1;

    while (current != 0) {
        if (current->module->generate() == 0)
            return 0;

        L->Log("RGE_RANDOM_MAP_MODULE::module completed with ret:",
               debug_rand("C:\\msdev\\work\\age1_x1\\rmm_base.cpp", 143));
        current = current->next;
    }

    return 1;
}

uchar RGE_Random_Map_Module::add_module(RGE_Random_Map_Module* module) {
    RGE_Random_Map_Module_List* item;

    if (module == 0) {
        return 0;
    }
    // The shipped code dereferences allocation failure.
    // Publish the complete node only after both fields have values.
    item = (RGE_Random_Map_Module_List*)calloc(1, 8);
    item->next = this->list;
    item->module = module;
    this->list = item;
    return 1;
}

// choices in the list walk.
uchar RGE_Random_Map_Module::remove_module(
    RGE_Random_Map_Module* module) {
    RGE_Random_Map_Module_List* head = this->list;
    RGE_Random_Map_Module_List* found = 0;

    if (head != 0) {
        if (head->module == module) {
            found = head;
            this->list = head->next;
        } else {
            RGE_Random_Map_Module_List* curr;
            RGE_Random_Map_Module_List** pprev = &head->next;
            curr = *pprev;
            if (curr != 0) {
                do {
                    if (curr->module == module) {
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

void RGE_Random_Map_Module::create_shared_resources() {
    int i;
    int y;
    int count;

    count = map_height;
    count *= map_width;
    // Store each allocation before row-pointer publication.
    // The shipped code does not test allocation results.
    search_map = (uchar*)calloc(count, 1);
    search_map_rows = (uchar**)calloc(map_height, 4);

    for (i = 0; i < map_height; i++) {
        search_map_rows[i] = search_map + i * map_width;
    }

    count = map_height;
    count *= map_width;
    stack_array = (Map_Stack*)calloc(count, 24);
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

void RGE_Random_Map_Module::destroy_shared_resources() {
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

void RGE_Random_Map_Module::update_child_resources() {
    RGE_Random_Map_Module_List* node;

    node = this->list;
    while (node != 0) {
        node->module->update_resources();
        node = node->next;
    }
}

void RGE_Random_Map_Module::update_resources() {
    this->parent->share_resources(&this->search_map, &this->search_map_rows, &this->stack_array, &this->stack_offsets);
    this->update_child_resources();
}

void RGE_Random_Map_Module::update_child_map_info() {
    RGE_Random_Map_Module_List* node;

    node = this->list;
    while (node != 0) {
        node->module->update_map_info(this->map);
        node = node->next;
    }
}

void RGE_Random_Map_Module::update_map_info(RGE_Map* new_map) {
    this->map = new_map;
    if (new_map != 0) {
        this->map_row_offset = new_map->give_up_map_offsets();
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
    uchar** search_map_pointer, uchar*** search_map_rows_pointer,
    Map_Stack** stack_array_pointer, Map_Stack*** stack_offsets_pointer) {
    if (search_map_pointer != 0) {
        *search_map_pointer = this->search_map;
    }
    if (search_map_rows_pointer != 0) {
        *search_map_rows_pointer = this->search_map_rows;
    }
    if (stack_array_pointer != 0) {
        *stack_array_pointer = this->stack_array;
    }
    if (stack_offsets_pointer != 0) {
        *stack_offsets_pointer = this->stack_offsets;
    }
}

void RGE_Random_Map_Module::init_stack(Map_Stack& stack) {
    stack.x = -1;
    stack.y = -1;
    stack.next = 0;
    stack.prev = 0;
    stack.cost = 0;
    stack.tot_cost = 0;
}

void RGE_Random_Map_Module::deinit_stack(Map_Stack& stack) {
    if (stack.next) {
        stack.next->prev = 0;
        stack.next = 0;
    }
}

void RGE_Random_Map_Module::push_stack(
    Map_Stack& stack, long x, long y, float cost, float tot_cost) {
    Map_Stack* node = &this->stack_offsets[y][x];
    this->remove_stack_node(node);

    Map_Stack* current = stack.next;

    if (current != 0 && current->tot_cost < tot_cost) {
        Map_Stack* prev;
        do {
            prev = current;
            current = current->next;
        } while (current != 0 && current->tot_cost < tot_cost);

        this->add_stack_node(prev, node);
        *(long*)&node->cost = *(long*)&cost;
        node->tot_cost = tot_cost;
        return;
    }

    this->add_stack_node(&stack, node);
    *(long*)&node->cost = *(long*)&cost;
    node->tot_cost = tot_cost;
}

Map_Stack* RGE_Random_Map_Module::pop_stack(
    Map_Stack& stack, long& x, long& y, float& cost) {
    Map_Stack* node = stack.next;
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
    Map_Stack* stack, Map_Stack* new_stack) {
    if ((new_stack->next != 0) || (new_stack->prev != 0)) {
        this->remove_stack_node(new_stack);
    }
    Map_Stack* next = stack->next;
    new_stack->prev = stack;
    new_stack->next = next;
    if (stack->next != 0) {
        stack->next->prev = new_stack;
    }
    stack->next = new_stack;
}

void RGE_Random_Map_Module::remove_stack_node(Map_Stack* stack) {
    if (stack->prev != 0) {
        stack->prev->next = stack->next;
    }
    if (stack->next != 0) {
        stack->next->prev = stack->prev;
    }
    stack->next = 0;
    stack->prev = 0;
}

void RGE_Random_Map_Module::clear_stack() {
    int y;
    int x;

    for (y = 0; y < this->map_height; ++y) {
        for (x = 0; x < this->map_width; ++x) {
            this->stack_offsets[y][x].next = 0;
            this->stack_offsets[y][x].prev = 0;
        }
    }
}

uchar RGE_Random_Map_Module::check_stack(Map_Stack* stack) {
    if (stack->next == 0 && stack->prev == 0) {
        return 0;
    }
    return 1;
}

void RGE_Random_Map_Module::randomize_stack(Map_Stack* stack) {
    int i;
    int j;
    Map_Stack sub_stacks[100];

    for (i = 0; i < 100; ++i) {
        this->init_stack(sub_stacks[i]);
    }

    for (i = 0; i < 2; ++i) {
        while (stack->next != 0) {
            j = (debug_rand("C:\\msdev\\work\\age1_x1\\rmm_base.cpp", 488) * 100) / 0x7fff;
            this->add_stack_node(&sub_stacks[j], stack->next);
        }

        for (j = 0; j < 100; j += 2) {
            while (sub_stacks[j].next != 0 || sub_stacks[j + 1].next != 0) {
                if (sub_stacks[j].next != 0) {
                    this->add_stack_node(stack, sub_stacks[j].next);
                }
                if (sub_stacks[j + 1].next != 0) {
                    this->add_stack_node(stack, sub_stacks[j + 1].next);
                }
            }
        }
    }
}

uchar RGE_Random_Map_Module::find_path(
    long x, long y, long& end_x, long& end_y, float* terrain) {
    Map_Stack path_stack;
    uchar result;

    this->init_stack(path_stack);
    result = this->find_path(path_stack, x, y, end_x, end_y, terrain);
    this->deinit_stack(path_stack);
    return result;
}

uchar RGE_Random_Map_Module::find_path(
    Map_Stack& path_stack, long x, long y, long& end_x, long& end_y,
    float* terrain) {
    long max_x = this->map_width - 1;
    long max_y = this->map_height - 1;
    float path_cost = 0.0f;

    this->clear_stack();
    memset(this->search_map, 0, this->map_height * this->map_width);

    this->search_map_rows[y][x] = 3;
    uchar tile_type = this->map_row_offset[end_y][end_x].terrain_type;
    this->search_map_rows[end_y][end_x] = 2;

    if (!(terrain[tile_type] > 0.0f)) {
        return 0;
    }

    for (;;) {
        long dx = x - end_x;
        long dy = y - end_y;
        float cost = (float)sqrt((double)(dx * dx + dy * dy));

        if (cost == 0.0) {
            if (path_stack.next != 0) {
                path_stack.next->prev = 0;
            }
            return 1;
        }

        uchar down;
        uchar up;
        uchar side;
        float hcost;
        float calc_cost;
        long next_x;
        long next_y;
        uchar state;

        if (y < max_y) {
            hcost = cost -
                ((y < end_y) ? 1.0f : -1.0f);
            next_y = y + 1;
            state = this->search_map_rows[next_y][x];
            if (state == 0) {
                tile_type = this->map_row_offset[next_y][x].terrain_type;
                if (terrain[tile_type] > 0.0) {
                    calc_cost = path_cost + terrain[tile_type];
                    this->search_map_rows[next_y][x] = 7;
                    this->push_stack(path_stack, x, next_y, calc_cost, calc_cost + hcost);
                    down = 1;
                } else {
                    this->search_map_rows[next_y][x] = 1;
                    down = 0;
                }
            } else if (state == 2) {
                this->search_map_rows[next_y][x] = 7;
                end_x = x;
                end_y = next_y;
                return 1;
            } else {
                down = state != 1;
            }
        } else {
            down = 0;
        }

        if (y > 0) {
            hcost = cost -
                ((end_y < y) ? 1.0f : -1.0f);
            next_y = y - 1;
            state = this->search_map_rows[next_y][x];
            if (state == 0) {
                tile_type = this->map_row_offset[next_y][x].terrain_type;
                if (terrain[tile_type] > 0.0) {
                    calc_cost = path_cost + terrain[tile_type];
                    this->search_map_rows[next_y][x] = 6;
                    this->push_stack(path_stack, x, next_y, calc_cost, calc_cost + hcost);
                    up = 1;
                } else {
                    this->search_map_rows[next_y][x] = 1;
                    up = 0;
                }
            } else if (state == 2) {
                this->search_map_rows[next_y][x] = 6;
                end_x = x;
                end_y = next_y;
                return 1;
            } else {
                up = state != 1;
            }
        } else {
            up = 0;
        }

        if (x > 0) {
            hcost = cost -
                ((end_x < x) ? 1.0f : -1.0f);
            next_x = x - 1;
            state = this->search_map_rows[y][next_x];
            if (state == 0) {
                tile_type = this->map_row_offset[y][next_x].terrain_type;
                if (terrain[tile_type] > 0.0f) {
                    calc_cost = path_cost + terrain[tile_type];
                    this->search_map_rows[y][next_x] = 4;
                    this->push_stack(path_stack, next_x, y, calc_cost, calc_cost + hcost);
                    side = 1;
                } else {
                    this->search_map_rows[y][next_x] = 1;
                    side = 0;
                }
            } else if (state == 2) {
                this->search_map_rows[y][next_x] = 4;
                end_x = next_x;
                end_y = y;
                return 1;
            } else {
                side = state != 1;
            }

            if (y > 0) {
                next_y = y - 1;
                state = this->search_map_rows[next_y][next_x];
                if (state == 0) {
                    tile_type =
                        this->map_row_offset[next_y][next_x].terrain_type;
                    if (!(terrain[tile_type] > 0.0f)) {
                        this->search_map_rows[next_y][next_x] = 1;
                    } else if (up && side) {
                        calc_cost = path_cost -
                            terrain[tile_type] * g_rmm_path_terrain_cost_adjustment;
                        this->search_map_rows[next_y][next_x] = 8;
                        this->push_stack(path_stack, next_x, next_y, calc_cost, calc_cost + (hcost -
                             ((end_y < y) ? g_rmm_path_vertical_adjustment_positive : g_rmm_path_vertical_adjustment_negative)));
                    }
                } else if (state == 2) {
                    this->search_map_rows[next_y][next_x] = 8;
                    end_x = next_x;
                    end_y = next_y;
                    return 1;
                }
            }

            if (y < max_y) {
                next_y = y + 1;
                state = this->search_map_rows[next_y][next_x];
                if (state == 0) {
                    tile_type =
                        this->map_row_offset[next_y][next_x].terrain_type;
                    if (!(terrain[tile_type] > 0.0f)) {
                        this->search_map_rows[next_y][next_x] = 1;
                    } else if (down && side) {
                        calc_cost = path_cost -
                            terrain[tile_type] * g_rmm_path_terrain_cost_adjustment;
                        this->search_map_rows[next_y][next_x] = 9;
                        this->push_stack(path_stack, next_x, next_y, calc_cost, calc_cost + (hcost -
                             ((y < end_y) ? g_rmm_path_vertical_adjustment_positive : g_rmm_path_vertical_adjustment_negative)));
                    }
                } else if (state == 2) {
                    this->search_map_rows[next_y][next_x] = 9;
                    end_x = next_x;
                    end_y = next_y;
                    return 1;
                }
            }
        }

        if (x < max_x) {
            hcost = cost -
                ((x < end_x) ? 1.0f : -1.0f);
            next_x = x + 1;
            state = this->search_map_rows[y][next_x];
            if (state == 0) {
                tile_type = this->map_row_offset[y][next_x].terrain_type;
                if (terrain[tile_type] > 0.0f) {
                    calc_cost = path_cost + terrain[tile_type];
                    this->search_map_rows[y][next_x] = 5;
                    this->push_stack(path_stack, next_x, y, calc_cost, calc_cost + hcost);
                    side = 1;
                } else {
                    this->search_map_rows[y][next_x] = 1;
                    side = 0;
                }
            } else if (state == 2) {
                this->search_map_rows[y][next_x] = 5;
                end_x = next_x;
                end_y = y;
                return 1;
            } else {
                side = state != 1;
            }

            if (y > 0) {
                next_y = y - 1;
                state = this->search_map_rows[next_y][next_x];
                if (state == 0) {
                    tile_type =
                        this->map_row_offset[next_y][next_x].terrain_type;
                    if (!(terrain[tile_type] > 0.0f)) {
                        this->search_map_rows[next_y][next_x] = 1;
                    } else if (up && side) {
                        calc_cost = path_cost -
                            terrain[tile_type] * g_rmm_path_terrain_cost_adjustment;
                        this->search_map_rows[next_y][next_x] = 10;
                        this->push_stack(path_stack, next_x, next_y, calc_cost, calc_cost + (hcost -
                             ((end_y < y) ? g_rmm_path_vertical_adjustment_small_positive : g_rmm_path_vertical_adjustment_small_negative)));
                    }
                } else if (state == 2) {
                    this->search_map_rows[next_y][next_x] = 10;
                    end_x = next_x;
                    end_y = next_y;
                    return 1;
                }
            }

            if (y < max_y) {
                next_y = y + 1;
                state = this->search_map_rows[next_y][next_x];
                if (state == 0) {
                    tile_type =
                        this->map_row_offset[next_y][next_x].terrain_type;
                    if (!(terrain[tile_type] > 0.0f)) {
                        this->search_map_rows[next_y][next_x] = 1;
                    } else if (down && side) {
                        calc_cost = path_cost -
                            terrain[tile_type] * g_rmm_path_terrain_cost_adjustment;
                        this->search_map_rows[next_y][next_x] = 11;
                        this->push_stack(path_stack, next_x, next_y, calc_cost, calc_cost + (hcost -
                             ((y < end_y) ? g_rmm_path_vertical_adjustment_small_positive : g_rmm_path_vertical_adjustment_small_negative)));
                    }
                } else if (state == 2) {
                    this->search_map_rows[next_y][next_x] = 11;
                    end_x = next_x;
                    end_y = next_y;
                    return 1;
                }
            }
        }

        if (this->pop_stack(path_stack, x, y, path_cost) == 0) {
            return 0;
        }
    }
}
