#include "RGE_Random_Map_Module.h"
#include "RGE_Map.h"
#include "debug_helpers.h"

#include <math.h>
RGE_Random_Map_Module::RGE_Random_Map_Module()
    : RGE_Random_Map_Module(nullptr, nullptr, 0) {
}

// Fully verified. Source of truth: rmm_base.cpp.decomp @ 0x00480790
RGE_Random_Map_Module::RGE_Random_Map_Module(RGE_Map* param_1, RGE_Random_Map_Module* param_2, uchar param_3) {
    this->parent = param_2;
    this->list = nullptr;
    this->map = param_1;
    this->schedule = 0.0f;

    if (param_1 == nullptr) {
        this->map_row_offset = nullptr;
        this->map_width = 0;
        this->map_height = 0;
    } else {
        this->map_row_offset = param_1->map_row_offset;
        this->map_width = param_1->map_width;
        this->map_height = param_1->map_height;
    }

    this->search_map = nullptr;
    this->search_map_rows = nullptr;
    this->stack_array = nullptr;
    this->stack_offsets = nullptr;

    if (this->parent == nullptr) {
        if (param_3 != 0) {
            this->create_shared_resources();
        }
    } else {
        this->parent->add_module(this);
        this->parent->share_resources(&this->search_map, &this->search_map_rows, &this->stack_array, &this->stack_offsets);
    }
}

// Fully verified. Source of truth: rmm_base.cpp.decomp @ 0x00480840
RGE_Random_Map_Module::~RGE_Random_Map_Module() {
    while (this->list != nullptr) {
        RGE_Random_Map_Module_List* head = this->list;
        RGE_Random_Map_Module* child = head->module;
        if (child != nullptr) {
            delete child;
        } else {
            this->list = head->next;
            free(head);
        }
    }

    if (this->parent != nullptr) {
        this->parent->remove_module(this);
        this->search_map = nullptr;
        this->search_map_rows = nullptr;
        this->stack_array = nullptr;
        this->stack_offsets = nullptr;
        this->map = nullptr;
        this->map_row_offset = nullptr;
        this->map_width = 0;
        this->map_height = 0;
        return;
    }

    this->destroy_shared_resources();
    this->map = nullptr;
    this->map_row_offset = nullptr;
    this->map_width = 0;
    this->map_height = 0;
}

// Fully verified. Source of truth: rmm_base.cpp.decomp @ 0x004808C0
float RGE_Random_Map_Module::get_schedule() {
    return this->schedule;
}

// Fully verified. Source of truth: rmm_base.cpp.decomp @ 0x004808D0
uchar RGE_Random_Map_Module::generate() {
    RGE_Random_Map_Module_List* sorted = nullptr;
    RGE_Random_Map_Module_List* node = this->list;

    while (node != nullptr) {
        RGE_Random_Map_Module_List* next = node->next;
        node->next = nullptr;

        if (sorted == nullptr) {
            sorted = node;
        } else {
            float node_sched = node->module ? node->module->get_schedule() : 0.0f;
            float head_sched = sorted->module ? sorted->module->get_schedule() : 0.0f;
            if (node_sched < head_sched) {
                node->next = sorted;
                sorted = node;
            } else {
                RGE_Random_Map_Module_List* ins = sorted;
                while (ins->next != nullptr) {
                    float next_sched = ins->next->module ? ins->next->module->get_schedule() : 0.0f;
                    if (node_sched < next_sched) {
                        break;
                    }
                    ins = ins->next;
                }
                node->next = ins->next;
                ins->next = node;
            }
        }

        node = next;
    }

    this->list = sorted;

    for (RGE_Random_Map_Module_List* it = this->list; it != nullptr; it = it->next) {
        if (it->module != nullptr) {
            if (it->module->generate() == 0) {
                return 0;
            }
        }
    }

    return 1;
}

// Fully verified. Source of truth: rmm_base.cpp.decomp @ 0x004809E0
uchar RGE_Random_Map_Module::add_module(RGE_Random_Map_Module* param_1) {
    if (param_1 == nullptr) {
        return 0;
    }
    RGE_Random_Map_Module_List* node = (RGE_Random_Map_Module_List*)calloc(1, sizeof(RGE_Random_Map_Module_List));
    if (node == nullptr) {
        return 0;
    }
    node->next = this->list;
    node->module = param_1;
    this->list = node;
    return 1;
}

// Fully verified. Source of truth: rmm_base.cpp.decomp @ 0x00480A20
uchar RGE_Random_Map_Module::remove_module(RGE_Random_Map_Module* param_1) {
    RGE_Random_Map_Module_List* prev = nullptr;
    RGE_Random_Map_Module_List* it = this->list;

    while (it != nullptr) {
        if (it->module == param_1) {
            if (prev == nullptr) {
                this->list = it->next;
            } else {
                prev->next = it->next;
            }
            free(it);
            return 1;
        }
        prev = it;
        it = it->next;
    }
    return 0;
}

// Fully verified. Source of truth: rmm_base.cpp.decomp @ 0x00480A80
void RGE_Random_Map_Module::create_shared_resources() {
    if (this->map_width <= 0 || this->map_height <= 0) {
        return;
    }

    long count = this->map_width * this->map_height;

    this->search_map = (uchar*)calloc((size_t)count, 1);
    this->search_map_rows = (uchar**)calloc((size_t)this->map_height, sizeof(uchar*));
    for (long y = 0; y < this->map_height; ++y) {
        this->search_map_rows[y] = this->search_map + y * this->map_width;
    }

    this->stack_array = (Map_Stack*)calloc((size_t)count, sizeof(Map_Stack));
    this->stack_offsets = (Map_Stack**)calloc((size_t)this->map_height, sizeof(Map_Stack*));
    for (long y = 0; y < this->map_height; ++y) {
        this->stack_offsets[y] = this->stack_array + y * this->map_width;
    }

    for (long y = 0; y < this->map_height; ++y) {
        for (long x = 0; x < this->map_width; ++x) {
            this->stack_offsets[y][x].x = x;
            this->stack_offsets[y][x].y = y;
        }
    }
}

// Fully verified. Source of truth: rmm_base.cpp.decomp @ 0x00480B60
void RGE_Random_Map_Module::destroy_shared_resources() {
    if (this->search_map != nullptr) {
        free(this->search_map);
        this->search_map = nullptr;
    }
    if (this->search_map_rows != nullptr) {
        free(this->search_map_rows);
        this->search_map_rows = nullptr;
    }
    if (this->stack_array != nullptr) {
        free(this->stack_array);
        this->stack_array = nullptr;
    }
    if (this->stack_offsets != nullptr) {
        free(this->stack_offsets);
        this->stack_offsets = nullptr;
    }
}

// Fully verified. Source of truth: rmm_base.cpp.decomp @ 0x00480BC0
void RGE_Random_Map_Module::update_child_resources() {
    for (RGE_Random_Map_Module_List* it = this->list; it != nullptr; it = it->next) {
        if (it->module != nullptr) {
            it->module->update_resources();
        }
    }
}

// Fully verified. Source of truth: rmm_base.cpp.decomp @ 0x00480BE0
void RGE_Random_Map_Module::update_resources() {
    if (this->parent != nullptr) {
        this->parent->share_resources(&this->search_map, &this->search_map_rows, &this->stack_array, &this->stack_offsets);
    }
    this->update_child_resources();
}

// Fully verified. Source of truth: rmm_base.cpp.decomp @ 0x00480C10
void RGE_Random_Map_Module::update_child_map_info() {
    for (RGE_Random_Map_Module_List* it = this->list; it != nullptr; it = it->next) {
        if (it->module != nullptr) {
            it->module->update_map_info(this->map);
        }
    }
}

// Fully verified. Source of truth: rmm_base.cpp.decomp @ 0x00480C30
void RGE_Random_Map_Module::update_map_info(RGE_Map* param_1) {
    this->map = param_1;
    if (param_1 != nullptr) {
        this->map_row_offset = param_1->map_row_offset;
        this->map_width = param_1->map_width;
        this->map_height = param_1->map_height;
    } else {
        this->map_row_offset = nullptr;
        this->map_width = 0;
        this->map_height = 0;
    }
    this->update_child_map_info();
}

// Fully verified. Source of truth: rmm_base.cpp.decomp @ 0x00480C80
void RGE_Random_Map_Module::share_resources(uchar** param_1, uchar*** param_2, Map_Stack** param_3, Map_Stack*** param_4) {
    if (param_1 != nullptr) {
        *param_1 = this->search_map;
    }
    if (param_2 != nullptr) {
        *param_2 = this->search_map_rows;
    }
    if (param_3 != nullptr) {
        *param_3 = this->stack_array;
    }
    if (param_4 != nullptr) {
        *param_4 = this->stack_offsets;
    }
}

// Fully verified. Source of truth: rmm_base.cpp.decomp @ 0x00480CC0
void RGE_Random_Map_Module::init_stack(Map_Stack* param_1) {
    if (param_1 == nullptr) return;
    param_1->x = -1;
    param_1->y = -1;
    param_1->next = nullptr;
    param_1->prev = nullptr;
    param_1->cost = 0.0f;
    param_1->tot_cost = 0.0f;
}

// Fully verified. Source of truth: rmm_base.cpp.decomp @ 0x00480CF0
void RGE_Random_Map_Module::deinit_stack(Map_Stack* param_1) {
    if (param_1 == nullptr) return;
    if (param_1->next != nullptr) {
        param_1->next->prev = nullptr;
        param_1->next = nullptr;
    }
}

// Fully verified. Source of truth: rmm_base.cpp.decomp @ 0x00480D10
void RGE_Random_Map_Module::push_stack(Map_Stack* param_1, long param_2, long param_3, float param_4, float param_5) {
    if (param_1 == nullptr || this->stack_offsets == nullptr) {
        return;
    }
    if (param_2 < 0 || param_2 >= this->map_width || param_3 < 0 || param_3 >= this->map_height) {
        return;
    }

    Map_Stack* node = this->stack_offsets[param_3] + param_2;
    this->remove_stack_node(node);

    Map_Stack* it = param_1->next;
    if (it == nullptr || param_5 <= it->tot_cost) {
        this->add_stack_node(param_1, node);
        node->cost = param_4;
        node->tot_cost = param_5;
        return;
    }

    Map_Stack* prev = it;
    while (it != nullptr && it->tot_cost < param_5) {
        prev = it;
        it = it->next;
    }
    this->add_stack_node(prev, node);
    node->cost = param_4;
    node->tot_cost = param_5;
}

// Fully verified. Source of truth: rmm_base.cpp.decomp @ 0x00480DA0
Map_Stack* RGE_Random_Map_Module::pop_stack(Map_Stack* param_1, long* param_2, long* param_3, float* param_4) {
    if (param_1 == nullptr) {
        return nullptr;
    }
    Map_Stack* node = param_1->next;
    if (node == nullptr) {
        return nullptr;
    }
    if (param_2 != nullptr) *param_2 = node->x;
    if (param_3 != nullptr) *param_3 = node->y;
    if (param_4 != nullptr) *param_4 = node->cost;
    this->remove_stack_node(node);
    return node;
}

// Fully verified. Source of truth: rmm_base.cpp.decomp @ 0x00480DE0
void RGE_Random_Map_Module::add_stack_node(Map_Stack* param_1, Map_Stack* param_2) {
    if (param_1 == nullptr || param_2 == nullptr) {
        return;
    }

    if (param_2->next != nullptr || param_2->prev != nullptr) {
        this->remove_stack_node(param_2);
    }

    Map_Stack* next = param_1->next;
    param_2->prev = param_1;
    param_2->next = next;
    if (next != nullptr) {
        next->prev = param_2;
    }
    param_1->next = param_2;
}

// Fully verified. Source of truth: rmm_base.cpp.decomp @ 0x00480E20
void RGE_Random_Map_Module::remove_stack_node(Map_Stack* param_1) {
    if (param_1 == nullptr) {
        return;
    }
    if (param_1->prev != nullptr) {
        param_1->prev->next = param_1->next;
    }
    if (param_1->next != nullptr) {
        param_1->next->prev = param_1->prev;
    }
    param_1->next = nullptr;
    param_1->prev = nullptr;
}

// Fully verified. Source of truth: rmm_base.cpp.decomp @ 0x00480E50
void RGE_Random_Map_Module::clear_stack() {
    if (this->stack_offsets == nullptr || this->map_width <= 0 || this->map_height <= 0) {
        return;
    }

    for (long y = 0; y < this->map_height; ++y) {
        for (long x = 0; x < this->map_width; ++x) {
            this->stack_offsets[y][x].next = nullptr;
            this->stack_offsets[y][x].prev = nullptr;
        }
    }
}

// Fully verified. Source of truth: rmm_base.cpp.decomp @ 0x00480EA0
uchar RGE_Random_Map_Module::check_stack(Map_Stack* param_1) {
    if (param_1 == nullptr) {
        return 0;
    }
    if (param_1->next == nullptr && param_1->prev == nullptr) {
        return 0;
    }
    return 1;
}

// Fully verified. Source of truth: rmm_base.cpp.decomp @ 0x00480EC0
void RGE_Random_Map_Module::randomize_stack(Map_Stack* param_1) {
    if (param_1 == nullptr) {
        return;
    }

    Map_Stack sub_stacks[100];
    for (int i = 0; i < 100; ++i) {
        this->init_stack(&sub_stacks[i]);
    }

    int pass_count = 2;
    while (pass_count > 0) {
        while (param_1->next != nullptr) {
            int r = debug_rand("C:\\msdev\\work\\age1_x1\\rmm_base.cpp", 0x1e8);
            int idx = (r * 100) / 0x7fff;
            if (idx < 0) idx = 0;
            if (idx > 99) idx = 99;
            this->add_stack_node(&sub_stacks[idx], param_1->next);
        }

        for (int i = 0; i < 100; ++i) {
            while (sub_stacks[i].next != nullptr) {
                this->add_stack_node(param_1, sub_stacks[i].next);
            }
        }

        pass_count = pass_count - 1;
    }
}

// Fully verified. Source of truth: rmm_base.cpp.decomp @ 0x00480FB0
uchar RGE_Random_Map_Module::find_path(long param_1, long param_2, long* param_3, long* param_4, float* param_5) {
    Map_Stack path_stack;
    this->init_stack(&path_stack);
    uchar ret = this->find_path(&path_stack, param_1, param_2, param_3, param_4, param_5);
    this->deinit_stack(&path_stack);
    return ret;
}

// Fully verified. Source of truth: rmm_base.cpp.decomp @ 0x00481000
uchar RGE_Random_Map_Module::find_path(
    Map_Stack* param_1,
    long param_2,
    long param_3,
    long* param_4,
    long* param_5,
    float* param_6) {
    if (param_1 == nullptr || param_4 == nullptr || param_5 == nullptr || param_6 == nullptr) {
        return 0;
    }
    if (this->map_row_offset == nullptr || this->search_map == nullptr || this->search_map_rows == nullptr ||
        this->map_width <= 0 || this->map_height <= 0) {
        return 0;
    }
    if (param_2 < 0 || param_2 >= this->map_width || param_3 < 0 || param_3 >= this->map_height) {
        return 0;
    }
    if (*param_4 < 0 || *param_4 >= this->map_width || *param_5 < 0 || *param_5 >= this->map_height) {
        return 0;
    }

    long cur_x = param_2;
    long cur_y = param_3;
    long max_x = this->map_width - 1;
    long max_y = this->map_height - 1;

    this->clear_stack();
    memset(this->search_map, 0, (size_t)this->map_height * (size_t)this->map_width);

    this->search_map_rows[cur_y][cur_x] = 3;
    uchar start_tt = (uchar)(this->map_row_offset[*param_5][*param_4].terrain_type & 0x1f);
    this->search_map_rows[*param_5][*param_4] = 2;

    if (!(0.0f < param_6[start_tt])) {
        return 0;
    }

    float cur_cost = 0.0f;
    long start_y = *param_5;
    long dist_sq = (cur_x - *param_4) * (cur_x - *param_4) + (cur_y - start_y) * (cur_y - start_y);

    while (1) {
        float dist = (float)sqrt((double)dist_sq);
        if (dist == 0.0f) {
            if (param_1->next == nullptr) {
                return 1;
            }
            param_1->next->prev = nullptr;
            return 1;
        }

        bool south_ok = false;
        bool north_ok = false;
        bool west_ok = false;

        if (cur_y < max_y) {
            float h = (cur_y < *param_5) ? 1.0f : -1.0f;
            long ny = cur_y + 1;
            uchar* mark = this->search_map_rows[ny] + cur_x;
            uchar state = *mark;
            if (state == 0) {
                uchar tt = (uchar)(this->map_row_offset[ny][cur_x].terrain_type & 0x1f);
                if (param_6[tt] <= 0.0f) {
                    *mark = 1;
                } else {
                    float step = param_6[tt];
                    *mark = 7;
                    this->push_stack(param_1, cur_x, ny, cur_cost + step, cur_cost + step + (dist - h));
                    south_ok = true;
                }
            } else if (state == 2) {
                this->search_map_rows[ny][cur_x] = 7;
                *param_4 = cur_x;
                *param_5 = ny;
                return 1;
            } else {
                south_ok = (state != 1);
            }
        }

        if (cur_y > 0) {
            float h = (*param_5 < cur_y) ? 1.0f : -1.0f;
            long ny = cur_y - 1;
            uchar* mark = this->search_map_rows[ny] + cur_x;
            uchar state = *mark;
            if (state == 0) {
                uchar tt = (uchar)(this->map_row_offset[ny][cur_x].terrain_type & 0x1f);
                if (param_6[tt] <= 0.0f) {
                    *mark = 1;
                } else {
                    float step = param_6[tt];
                    *mark = 6;
                    this->push_stack(param_1, cur_x, ny, cur_cost + step, cur_cost + step + (dist - h));
                    north_ok = true;
                }
            } else if (state == 2) {
                this->search_map_rows[ny][cur_x] = 6;
                *param_4 = cur_x;
                *param_5 = ny;
                return 1;
            } else {
                north_ok = (state != 1);
            }
        }

        if (cur_x > 0) {
            float h = (*param_4 < cur_x) ? 1.0f : -1.0f;
            float d = dist - h;
            long nx = cur_x - 1;
            uchar* mark = this->search_map_rows[cur_y] + nx;
            uchar state = *mark;
            if (state == 0) {
                uchar tt = (uchar)(this->map_row_offset[cur_y][nx].terrain_type & 0x1f);
                if (param_6[tt] <= 0.0f) {
                    *mark = 1;
                } else {
                    float step = param_6[tt];
                    *mark = 4;
                    this->push_stack(param_1, nx, cur_y, cur_cost + step, cur_cost + step + d);
                    west_ok = true;
                }
            } else if (state == 2) {
                this->search_map_rows[cur_y][nx] = 4;
                *param_4 = nx;
                *param_5 = cur_y;
                return 1;
            } else {
                west_ok = (state != 1);
            }

            if (cur_y > 0) {
                long ny = cur_y - 1;
                mark = this->search_map_rows[ny] + nx;
                if (*mark == 0) {
                    uchar tt = (uchar)(this->map_row_offset[ny][nx].terrain_type & 0x1f);
                    if (param_6[tt] <= 0.0f) {
                        *mark = 1;
                    } else if (north_ok && west_ok) {
                        float step = cur_cost + param_6[tt] * 1.36f;
                        *mark = 8;
                        float bias = (*param_5 < cur_y) ? 0.41f : -0.41f;
                        this->push_stack(param_1, nx, ny, step, step + (d - bias));
                    }
                } else if (*mark == 2) {
                    this->search_map_rows[ny][nx] = 8;
                    *param_4 = nx;
                    *param_5 = ny;
                    return 1;
                }
            }

            if (cur_y < max_y) {
                long ny = cur_y + 1;
                mark = this->search_map_rows[ny] + nx;
                if (*mark == 0) {
                    uchar tt = (uchar)(this->map_row_offset[ny][nx].terrain_type & 0x1f);
                    if (param_6[tt] <= 0.0f) {
                        *mark = 1;
                    } else if (south_ok && west_ok) {
                        float step = cur_cost + param_6[tt] * 1.36f;
                        *mark = 9;
                        float bias = (cur_y < *param_5) ? 0.41f : -0.41f;
                        this->push_stack(param_1, nx, ny, step, step + (d - bias));
                    }
                } else if (*mark == 2) {
                    this->search_map_rows[ny][nx] = 9;
                    *param_4 = nx;
                    *param_5 = ny;
                    return 1;
                }
            }
        }

        if (cur_x < max_x) {
            float h = (cur_x < *param_4) ? 1.0f : -1.0f;
            dist = dist - h;
            long nx = cur_x + 1;
            uchar* mark = this->search_map_rows[cur_y] + nx;
            uchar state = *mark;
            if (state == 0) {
                uchar tt = (uchar)(this->map_row_offset[cur_y][nx].terrain_type & 0x1f);
                if (param_6[tt] <= 0.0f) {
                    *mark = 1;
                    west_ok = false;
                } else {
                    float step = param_6[tt];
                    *mark = 5;
                    this->push_stack(param_1, nx, cur_y, cur_cost + step, cur_cost + step + dist);
                    west_ok = true;
                }
            } else if (state == 2) {
                this->search_map_rows[cur_y][nx] = 5;
                *param_4 = nx;
                *param_5 = cur_y;
                return 1;
            } else {
                west_ok = (state != 1);
            }

            if (cur_y > 0) {
                long ny = cur_y - 1;
                mark = this->search_map_rows[ny] + nx;
                state = *mark;
                if (state == 0) {
                    uchar tt = (uchar)(this->map_row_offset[ny][nx].terrain_type & 0x1f);
                    if (param_6[tt] <= 0.0f) {
                        *mark = 1;
                    } else if (north_ok && west_ok) {
                        float step = cur_cost + param_6[tt] * 1.36f;
                        *mark = 10;
                        float bias = (*param_5 < cur_y) ? 0.4f : -0.4f;
                        this->push_stack(param_1, nx, ny, step, step + (dist - bias));
                    }
                } else if (state == 2) {
                    this->search_map_rows[ny][nx] = 10;
                    *param_4 = nx;
                    *param_5 = ny;
                    return 1;
                }
            }

            if (cur_y < max_y) {
                long ny = cur_y + 1;
                mark = this->search_map_rows[ny] + nx;
                state = *mark;
                if (state == 0) {
                    uchar tt = (uchar)(this->map_row_offset[ny][nx].terrain_type & 0x1f);
                    if (param_6[tt] <= 0.0f) {
                        *mark = 1;
                    } else if (south_ok && west_ok) {
                        float step = cur_cost + param_6[tt] * 1.36f;
                        *mark = 11;
                        float bias = (cur_y < *param_5) ? 0.4f : -0.4f;
                        this->push_stack(param_1, nx, ny, step, step + (dist - bias));
                    }
                } else if (state == 2) {
                    this->search_map_rows[ny][nx] = 11;
                    *param_4 = nx;
                    *param_5 = ny;
                    return 1;
                }
            }
        }

        Map_Stack* popped = this->pop_stack(param_1, &cur_x, &cur_y, &cur_cost);
        if (popped == nullptr) {
            break;
        }
        start_y = *param_5;
        dist_sq = (cur_x - *param_4) * (cur_x - *param_4) + (cur_y - start_y) * (cur_y - start_y);
    }

    return 0;
}


