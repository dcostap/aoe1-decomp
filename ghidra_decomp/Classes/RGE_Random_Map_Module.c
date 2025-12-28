// Class: RGE_Random_Map_Module
// Size:  0x30
//
// VTable Layout:
// [00] generate
//
// Member Layout:
// [0x004] RGE_Random_Map_Module * parent
// [0x008] RGE_Random_Map_Module_List * list
// [0x00C] RGE_Map * map
// [0x010] RGE_Tile * * map_row_offset
// [0x014] long map_width
// [0x018] long map_height
// [0x01C] float schedule
// [0x020] uchar * search_map
// [0x024] uchar * * search_map_rows
// [0x028] Map_Stack * stack_array
// [0x02C] Map_Stack * * stack_offsets
// ----------------------------------------------------------------

// Function: RGE_Random_Map_Module
// Address: 00480790
RGE_Random_Map_Module * __thiscall
RGE_Random_Map_Module::RGE_Random_Map_Module
          (RGE_Random_Map_Module *this,RGE_Map *param_1,RGE_Random_Map_Module *param_2,uchar param_3
          )
{
  RGE_Tile **ppRVar1;
  long lVar2;
  
  this->_padding_ = (int)&_vftable_;
  this->parent = param_2;
  this->map = param_1;
  if (param_1 == (RGE_Map *)0x0) {
    this->map_row_offset = (RGE_Tile **)0x0;
    this->map_width = 0;
    this->map_height = 0;
  }
  else {
    ppRVar1 = RGE_Map::give_up_map_offsets(param_1);
    this->map_row_offset = ppRVar1;
    lVar2 = RGE_Map::get_map_width(this->map);
    this->map_width = lVar2;
    lVar2 = RGE_Map::get_map_height(this->map);
    this->map_height = lVar2;
  }
  this->list = (RGE_Random_Map_Module_List *)0x0;
  this->search_map = (uchar *)0x0;
  this->stack_array = (Map_Stack *)0x0;
  this->search_map_rows = (uchar **)0x0;
  this->stack_offsets = (Map_Stack **)0x0;
  if (this->parent == (RGE_Random_Map_Module *)0x0) {
    if (param_3 != '\0') {
      create_shared_resources(this);
      return this;
    }
  }
  else {
    add_module(this->parent,this);
    share_resources(this->parent,&this->search_map,&this->search_map_rows,&this->stack_array,
                    &this->stack_offsets);
  }
  return this;
}

// --------------------------------------------------

// Function: ~RGE_Random_Map_Module
// Address: 00480840
void __thiscall RGE_Random_Map_Module::~RGE_Random_Map_Module(RGE_Random_Map_Module *this)
{
  RGE_Random_Map_Module_List *pRVar1;
  RGE_Random_Map_Module *this_00;
  
  pRVar1 = this->list;
  this->_padding_ = (int)&_vftable_;
  while (pRVar1 != (RGE_Random_Map_Module_List *)0x0) {
    this_00 = pRVar1->module;
    if (this_00 != (RGE_Random_Map_Module *)0x0) {
      ~RGE_Random_Map_Module(this_00);
      operator_delete(this_00);
    }
    pRVar1 = this->list;
  }
  if (this->parent != (RGE_Random_Map_Module *)0x0) {
    remove_module(this->parent,this);
    this->search_map = (uchar *)0x0;
    this->search_map_rows = (uchar **)0x0;
    this->stack_array = (Map_Stack *)0x0;
    this->stack_offsets = (Map_Stack **)0x0;
    this->map = (RGE_Map *)0x0;
    this->map_row_offset = (RGE_Tile **)0x0;
    this->map_width = 0;
    this->map_height = 0;
    return;
  }
  destroy_shared_resources(this);
  this->map = (RGE_Map *)0x0;
  this->map_row_offset = (RGE_Tile **)0x0;
  this->map_width = 0;
  this->map_height = 0;
  return;
}

// --------------------------------------------------

// Function: get_schedule
// Address: 004808c0
float __thiscall RGE_Random_Map_Module::get_schedule(RGE_Random_Map_Module *this)
{
  return this->schedule;
}

// --------------------------------------------------

// Function: generate
// Address: 004808d0
// [HELPER] s_C__msdev_work_age1_x1_rmm_base_c: "C:\msdev\work\age1_x1\rmm_base.cpp"
// [HELPER] s_RGE_RANDOM_MAP_MODULE__map_start: "RGE_RANDOM_MAP_MODULE::map startped with random: %d."
// [HELPER] s_RGE_RANDOM_MAP_MODULE__module_co: "RGE_RANDOM_MAP_MODULE::module completed with random: %d."
uchar __thiscall RGE_Random_Map_Module::generate(RGE_Random_Map_Module *this)
{
  RGE_Random_Map_Module_List **ppRVar1;
  RGE_Random_Map_Module_List *pRVar2;
  RGE_Random_Map_Module_List *pRVar3;
  char cVar4;
  int iVar5;
  TDebuggingLog *this_00;
  RGE_Random_Map_Module_List *pRVar6;
  RGE_Random_Map_Module_List *pRVar7;
  float fVar8;
  float fVar9;
  
  pRVar2 = (RGE_Random_Map_Module_List *)0x0;
  pRVar7 = this->list;
joined_r0x004808e4:
  do {
    pRVar3 = pRVar7;
    if (pRVar3 == (RGE_Random_Map_Module_List *)0x0) {
      this->list = pRVar2;
      iVar5 = debug_rand(s_C__msdev_work_age1_x1_rmm_base_c,0x8a);
      TDebuggingLog::Log(this_00,(char *)L,s_RGE_RANDOM_MAP_MODULE__map_start,iVar5);
      pRVar7 = this->list;
      if (pRVar7 == (RGE_Random_Map_Module_List *)0x0) {
        return '\x01';
      }
      do {
        cVar4 = (**(code **)pRVar7->module->_padding_)();
        if (cVar4 == '\0') {
          return '\0';
        }
        iVar5 = debug_rand(s_C__msdev_work_age1_x1_rmm_base_c,0x8f);
        TDebuggingLog::Log(L,(char *)L,s_RGE_RANDOM_MAP_MODULE__module_co,iVar5);
        pRVar7 = pRVar7->next;
      } while (pRVar7 != (RGE_Random_Map_Module_List *)0x0);
      return '\x01';
    }
    pRVar7 = pRVar3->next;
    if (pRVar2 != (RGE_Random_Map_Module_List *)0x0) {
      fVar8 = get_schedule(pRVar3->module);
      fVar9 = get_schedule(pRVar2->module);
      pRVar6 = pRVar2;
      if (fVar9 <= fVar8) {
        do {
          if (pRVar6->next == (RGE_Random_Map_Module_List *)0x0) {
LAB_0048093c:
            pRVar3->next = pRVar6->next;
            pRVar6->next = pRVar3;
            break;
          }
          fVar8 = get_schedule(pRVar3->module);
          fVar9 = get_schedule(pRVar6->next->module);
          if (fVar8 < fVar9) goto LAB_0048093c;
          ppRVar1 = &pRVar6->next;
          pRVar6 = *ppRVar1;
        } while (*ppRVar1 != (RGE_Random_Map_Module_List *)0x0);
        goto joined_r0x004808e4;
      }
    }
    pRVar3->next = pRVar2;
    pRVar2 = pRVar3;
  } while( true );
}

// --------------------------------------------------

// Function: add_module
// Address: 004809e0
uchar __thiscall
RGE_Random_Map_Module::add_module(RGE_Random_Map_Module *this,RGE_Random_Map_Module *param_1)
{
  RGE_Random_Map_Module_List *pRVar1;
  
  if (param_1 == (RGE_Random_Map_Module *)0x0) {
    return '\0';
  }
  pRVar1 = (RGE_Random_Map_Module_List *)calloc(1,8);
  pRVar1->next = this->list;
  pRVar1->module = param_1;
  this->list = pRVar1;
  return '\x01';
}

// --------------------------------------------------

// Function: remove_module
// Address: 00480a20
uchar __thiscall
RGE_Random_Map_Module::remove_module(RGE_Random_Map_Module *this,RGE_Random_Map_Module *param_1)
{
  RGE_Random_Map_Module_List *pRVar1;
  RGE_Random_Map_Module_List **ppRVar2;
  RGE_Random_Map_Module_List *pRVar3;
  
  pRVar1 = this->list;
  pRVar3 = (RGE_Random_Map_Module_List *)0x0;
  if (pRVar1 != (RGE_Random_Map_Module_List *)0x0) {
    if (pRVar1->module == param_1) {
      this->list = pRVar1->next;
      pRVar3 = pRVar1;
    }
    else {
      ppRVar2 = &pRVar1->next;
      pRVar1 = pRVar1->next;
      while (pRVar1 != (RGE_Random_Map_Module_List *)0x0) {
        if (pRVar1->module == param_1) {
          *ppRVar2 = pRVar1->next;
          pRVar3 = pRVar1;
        }
        ppRVar2 = &(*ppRVar2)->next;
        pRVar1 = *ppRVar2;
      }
    }
  }
  if (pRVar3 == (RGE_Random_Map_Module_List *)0x0) {
    return '\0';
  }
  free(pRVar3);
  return '\x01';
}

// --------------------------------------------------

// Function: create_shared_resources
// Address: 00480a80
void __thiscall RGE_Random_Map_Module::create_shared_resources(RGE_Random_Map_Module *this)
{
  uchar *puVar1;
  uchar **ppuVar2;
  int iVar3;
  Map_Stack *pMVar4;
  Map_Stack **ppMVar5;
  int iVar6;
  int iVar7;
  
  puVar1 = (uchar *)calloc(this->map_height * this->map_width,1);
  this->search_map = puVar1;
  ppuVar2 = (uchar **)calloc(this->map_height,4);
  this->search_map_rows = ppuVar2;
  iVar3 = 0;
  if (0 < this->map_height) {
    do {
      this->search_map_rows[iVar3] = this->search_map + iVar3 * this->map_width;
      iVar3 = iVar3 + 1;
    } while (iVar3 < this->map_height);
  }
  pMVar4 = (Map_Stack *)calloc(this->map_height * this->map_width,0x18);
  this->stack_array = pMVar4;
  ppMVar5 = (Map_Stack **)calloc(this->map_height,4);
  this->stack_offsets = ppMVar5;
  iVar3 = 0;
  if (0 < this->map_height) {
    do {
      iVar7 = iVar3 + 1;
      this->stack_offsets[iVar3] = this->stack_array + iVar3 * this->map_width;
      iVar3 = iVar7;
    } while (iVar7 < this->map_height);
  }
  iVar3 = 0;
  if (0 < this->map_height) {
    do {
      iVar7 = 0;
      if (0 < this->map_width) {
        iVar6 = 0;
        do {
          *(int *)((int)&this->stack_offsets[iVar3]->x + iVar6) = iVar7;
          iVar7 = iVar7 + 1;
          *(int *)((int)&this->stack_offsets[iVar3]->y + iVar6) = iVar3;
          iVar6 = iVar6 + 0x18;
        } while (iVar7 < this->map_width);
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < this->map_height);
  }
  return;
}

// --------------------------------------------------

// Function: destroy_shared_resources
// Address: 00480b60
void __thiscall RGE_Random_Map_Module::destroy_shared_resources(RGE_Random_Map_Module *this)
{
  if (this->search_map != (uchar *)0x0) {
    free(this->search_map);
  }
  this->search_map = (uchar *)0x0;
  if (this->search_map_rows != (uchar **)0x0) {
    free(this->search_map_rows);
  }
  this->search_map_rows = (uchar **)0x0;
  if (this->stack_array != (Map_Stack *)0x0) {
    free(this->stack_array);
  }
  this->stack_array = (Map_Stack *)0x0;
  if (this->stack_offsets != (Map_Stack **)0x0) {
    free(this->stack_offsets);
  }
  this->stack_offsets = (Map_Stack **)0x0;
  return;
}

// --------------------------------------------------

// Function: update_child_resources
// Address: 00480bc0
void __thiscall RGE_Random_Map_Module::update_child_resources(RGE_Random_Map_Module *this)
{
  RGE_Random_Map_Module_List *pRVar1;
  
  for (pRVar1 = this->list; pRVar1 != (RGE_Random_Map_Module_List *)0x0; pRVar1 = pRVar1->next) {
    update_resources(pRVar1->module);
  }
  return;
}

// --------------------------------------------------

// Function: update_resources
// Address: 00480be0
void __thiscall RGE_Random_Map_Module::update_resources(RGE_Random_Map_Module *this)
{
  share_resources(this->parent,&this->search_map,&this->search_map_rows,&this->stack_array,
                  &this->stack_offsets);
  update_child_resources(this);
  return;
}

// --------------------------------------------------

// Function: update_child_map_info
// Address: 00480c10
void __thiscall RGE_Random_Map_Module::update_child_map_info(RGE_Random_Map_Module *this)
{
  RGE_Random_Map_Module_List *pRVar1;
  
  for (pRVar1 = this->list; pRVar1 != (RGE_Random_Map_Module_List *)0x0; pRVar1 = pRVar1->next) {
    update_map_info(pRVar1->module,this->map);
  }
  return;
}

// --------------------------------------------------

// Function: update_map_info
// Address: 00480c30
void __thiscall RGE_Random_Map_Module::update_map_info(RGE_Random_Map_Module *this,RGE_Map *param_1)
{
  RGE_Tile **ppRVar1;
  long lVar2;
  
  this->map = param_1;
  if (param_1 != (RGE_Map *)0x0) {
    ppRVar1 = RGE_Map::give_up_map_offsets(param_1);
    this->map_row_offset = ppRVar1;
    lVar2 = RGE_Map::get_map_width(this->map);
    this->map_width = lVar2;
    lVar2 = RGE_Map::get_map_height(this->map);
    this->map_height = lVar2;
    update_child_map_info(this);
    return;
  }
  this->map_row_offset = (RGE_Tile **)0x0;
  this->map_width = 0;
  this->map_height = 0;
  update_child_map_info(this);
  return;
}

// --------------------------------------------------

// Function: share_resources
// Address: 00480c80
void __thiscall
RGE_Random_Map_Module::share_resources
          (RGE_Random_Map_Module *this,uchar **param_1,uchar ***param_2,Map_Stack **param_3,
          Map_Stack ***param_4)
{
  if (param_1 != (uchar **)0x0) {
    *param_1 = this->search_map;
  }
  if (param_2 != (uchar ***)0x0) {
    *param_2 = this->search_map_rows;
  }
  if (param_3 != (Map_Stack **)0x0) {
    *param_3 = this->stack_array;
  }
  if (param_4 != (Map_Stack ***)0x0) {
    *param_4 = this->stack_offsets;
  }
  return;
}

// --------------------------------------------------

// Function: init_stack
// Address: 00480cc0
void __thiscall RGE_Random_Map_Module::init_stack(RGE_Random_Map_Module *this,Map_Stack *param_1)
{
  param_1->x = -1;
  param_1->y = -1;
  param_1->next = (Map_Stack *)0x0;
  param_1->prev = (Map_Stack *)0x0;
  param_1->cost = 0.0;
  param_1->tot_cost = 0.0;
  return;
}

// --------------------------------------------------

// Function: deinit_stack
// Address: 00480cf0
void __thiscall RGE_Random_Map_Module::deinit_stack(RGE_Random_Map_Module *this,Map_Stack *param_1)
{
  if (param_1->next != (Map_Stack *)0x0) {
    param_1->next->prev = (Map_Stack *)0x0;
    param_1->next = (Map_Stack *)0x0;
  }
  return;
}

// --------------------------------------------------

// Function: push_stack
// Address: 00480d10
void __thiscall
RGE_Random_Map_Module::push_stack
          (RGE_Random_Map_Module *this,Map_Stack *param_1,long param_2,long param_3,float param_4,
          float param_5)
{
  Map_Stack *pMVar1;
  Map_Stack *pMVar2;
  Map_Stack *pMVar3;
  
  pMVar1 = this->stack_offsets[param_3] + param_2;
  remove_stack_node(this,pMVar1);
  pMVar2 = param_1->next;
  if ((pMVar2 == (Map_Stack *)0x0) || (param_5 <= pMVar2->tot_cost)) {
    add_stack_node(this,param_1,pMVar1);
    pMVar1->cost = param_4;
    pMVar1->tot_cost = param_5;
    return;
  }
  do {
    pMVar3 = pMVar2;
    pMVar2 = pMVar3->next;
    if (pMVar2 == (Map_Stack *)0x0) break;
  } while (pMVar2->tot_cost < param_5);
  add_stack_node(this,pMVar3,pMVar1);
  pMVar1->cost = param_4;
  pMVar1->tot_cost = param_5;
  return;
}

// --------------------------------------------------

// Function: pop_stack
// Address: 00480da0
Map_Stack * __thiscall
RGE_Random_Map_Module::pop_stack
          (RGE_Random_Map_Module *this,Map_Stack *param_1,long *param_2,long *param_3,float *param_4
          )
{
  Map_Stack *pMVar1;
  
  pMVar1 = param_1->next;
  if (pMVar1 == (Map_Stack *)0x0) {
    return (Map_Stack *)0x0;
  }
  *param_2 = pMVar1->x;
  *param_3 = pMVar1->y;
  *param_4 = pMVar1->cost;
  remove_stack_node(this,pMVar1);
  return pMVar1;
}

// --------------------------------------------------

// Function: add_stack_node
// Address: 00480de0
void __thiscall
RGE_Random_Map_Module::add_stack_node
          (RGE_Random_Map_Module *this,Map_Stack *param_1,Map_Stack *param_2)
{
  Map_Stack *pMVar1;
  
  if ((param_2->next != (Map_Stack *)0x0) || (param_2->prev != (Map_Stack *)0x0)) {
    remove_stack_node(this,param_2);
  }
  pMVar1 = param_1->next;
  param_2->prev = param_1;
  param_2->next = pMVar1;
  if (param_1->next != (Map_Stack *)0x0) {
    param_1->next->prev = param_2;
  }
  param_1->next = param_2;
  return;
}

// --------------------------------------------------

// Function: remove_stack_node
// Address: 00480e20
void __thiscall
RGE_Random_Map_Module::remove_stack_node(RGE_Random_Map_Module *this,Map_Stack *param_1)
{
  if (param_1->prev != (Map_Stack *)0x0) {
    param_1->prev->next = param_1->next;
  }
  if (param_1->next != (Map_Stack *)0x0) {
    param_1->next->prev = param_1->prev;
  }
  param_1->next = (Map_Stack *)0x0;
  param_1->prev = (Map_Stack *)0x0;
  return;
}

// --------------------------------------------------

// Function: clear_stack
// Address: 00480e50
void __thiscall RGE_Random_Map_Module::clear_stack(RGE_Random_Map_Module *this)
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  if (0 < this->map_height) {
    do {
      iVar2 = 0;
      if (0 < this->map_width) {
        iVar1 = 0;
        do {
          iVar2 = iVar2 + 1;
          *(undefined4 *)((int)&this->stack_offsets[iVar3]->next + iVar1) = 0;
          *(undefined4 *)((int)&this->stack_offsets[iVar3]->prev + iVar1) = 0;
          iVar1 = iVar1 + 0x18;
        } while (iVar2 < this->map_width);
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < this->map_height);
  }
  return;
}

// --------------------------------------------------

// Function: check_stack
// Address: 00480ea0
uchar __thiscall RGE_Random_Map_Module::check_stack(RGE_Random_Map_Module *this,Map_Stack *param_1)
{
  if ((param_1->next == (Map_Stack *)0x0) && (param_1->prev == (Map_Stack *)0x0)) {
    return '\0';
  }
  return '\x01';
}

// --------------------------------------------------

// Function: randomize_stack
// Address: 00480ec0
// [HELPER] s_C__msdev_work_age1_x1_rmm_base_c: "C:\msdev\work\age1_x1\rmm_base.cpp"
void __thiscall
RGE_Random_Map_Module::randomize_stack(RGE_Random_Map_Module *this,Map_Stack *param_1)
{
  int *piVar1;
  Map_Stack **ppMVar2;
  Map_Stack *pMVar3;
  int iVar4;
  int local_968;
  Map_Stack sub_stacks [100];
  
  pMVar3 = (Map_Stack *)&sub_stacks[0].y;
  iVar4 = 100;
  do {
    init_stack(this,pMVar3);
    pMVar3 = pMVar3 + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  local_968 = 2;
LAB_00480ef2:
  pMVar3 = param_1->next;
  while (pMVar3 != (Map_Stack *)0x0) {
    iVar4 = debug_rand(s_C__msdev_work_age1_x1_rmm_base_c,0x1e8);
    add_stack_node(this,(Map_Stack *)&sub_stacks[(iVar4 * 100) / 0x7fff].y,param_1->next);
    pMVar3 = param_1->next;
  }
  ppMVar2 = &sub_stacks[0].prev;
  sub_stacks[0].x = 0x18;
LAB_00480f4e:
  piVar1 = (int *)((int)&sub_stacks[0].prev + sub_stacks[0].x);
LAB_00480f52:
  if (*ppMVar2 == (Map_Stack *)0x0) {
    if (*piVar1 == 0) goto LAB_00480f7c;
  }
  else {
    add_stack_node(this,param_1,*ppMVar2);
  }
  pMVar3 = (Map_Stack *)*piVar1;
  if (pMVar3 != (Map_Stack *)0x0) {
    add_stack_node(this,param_1,pMVar3);
  }
  goto LAB_00480f52;
LAB_00480f7c:
  ppMVar2 = ppMVar2 + 0xc;
  sub_stacks[0].x = sub_stacks[0].x + 0x30;
  if (0x977 < sub_stacks[0].x) goto code_r0x00480f91;
  goto LAB_00480f4e;
code_r0x00480f91:
  local_968 = local_968 + -1;
  if (local_968 == 0) {
    return;
  }
  goto LAB_00480ef2;
}

// --------------------------------------------------

// Function: find_path
// Address: 00480fb0
uchar __thiscall
RGE_Random_Map_Module::find_path
          (RGE_Random_Map_Module *this,long param_1,long param_2,long *param_3,long *param_4,
          float *param_5)
{
  uchar uVar1;
  Map_Stack path_stack;
  
  init_stack(this,(Map_Stack *)&path_stack.y);
  uVar1 = find_path(this,(Map_Stack *)&path_stack.y,param_1,param_2,param_3,param_4,param_5);
  deinit_stack(this,(Map_Stack *)&path_stack.y);
  return uVar1;
}

// --------------------------------------------------

// Function: find_path
// Address: 00481000
uchar __thiscall
RGE_Random_Map_Module::find_path
          (RGE_Random_Map_Module *this,Map_Stack *param_1,long param_2,long param_3,long *param_4,
          long *param_5,float *param_6)
{
  float fVar1;
  byte bVar2;
  uchar uVar3;
  float fVar4;
  float fVar5;
  Map_Stack *pMVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uchar *puVar10;
  int iVar11;
  bool bVar12;
  bool bVar13;
  bool bVar14;
  uchar up;
  uchar down;
  uchar right;
  float calc_cost;
  uchar tile_type;
  float tcost;
  float hcost;
  float cost;
  long ty;
  long map_h;
  long map_w;
  int local_4;
  
  ty = 0;
  local_4 = this->map_width + -1;
  map_w = this->map_height + -1;
  clear_stack(this);
  uVar7 = this->map_height * this->map_width;
  puVar10 = this->search_map;
  for (uVar8 = uVar7 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
    puVar10[0] = '\0';
    puVar10[1] = '\0';
    puVar10[2] = '\0';
    puVar10[3] = '\0';
    puVar10 = puVar10 + 4;
  }
  for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
    *puVar10 = '\0';
    puVar10 = puVar10 + 1;
  }
  this->search_map_rows[param_3][param_2] = '\x03';
  bVar2 = this->map_row_offset[*param_5][*param_4].field_0x5;
  this->search_map_rows[*param_5][*param_4] = '\x02';
  if (param_6[bVar2 & 0x1f] <= (float)UNK_00571e34._4_4_) {
    return '\0';
  }
  iVar11 = *param_5;
  map_h = (param_2 - *param_4) * (param_2 - *param_4) + (param_3 - iVar11) * (param_3 - iVar11);
  cost = SQRT((float)map_h);
  if (cost != (float)(double)UNK_00571e34._12_8_) {
    do {
      if (param_3 < map_w) {
        fVar4 = _DAT_00571e4c;
        if (param_3 < iVar11) {
          fVar4 = ram0x00571e48;
        }
        iVar11 = param_3 + 1;
        puVar10 = this->search_map_rows[iVar11] + param_2;
        uVar3 = this->search_map_rows[iVar11][param_2];
        if (uVar3 == '\0') {
          uVar8 = (byte)this->map_row_offset[iVar11][param_2].field_0x5 & 0x1f;
          if (param_6[uVar8] <= (float)(double)UNK_00571e34._12_8_) {
            *puVar10 = '\x01';
            bVar12 = false;
          }
          else {
            fVar1 = param_6[uVar8];
            *puVar10 = '\a';
            push_stack(this,param_1,param_2,iVar11,(float)ty + fVar1,
                       (float)ty + fVar1 + (cost - fVar4));
            bVar12 = true;
          }
        }
        else {
          if (uVar3 == '\x02') {
            this->search_map_rows[iVar11][param_2] = '\a';
            *param_4 = param_2;
            *param_5 = iVar11;
            return '\x01';
          }
          bVar12 = uVar3 != '\x01';
        }
      }
      else {
        bVar12 = false;
      }
      if (param_3 < 1) {
        bVar13 = false;
      }
      else {
        fVar4 = _DAT_00571e4c;
        if (*param_5 < param_3) {
          fVar4 = ram0x00571e48;
        }
        iVar11 = param_3 + -1;
        puVar10 = this->search_map_rows[iVar11] + param_2;
        uVar3 = this->search_map_rows[iVar11][param_2];
        if (uVar3 == '\0') {
          uVar8 = (byte)this->map_row_offset[iVar11][param_2].field_0x5 & 0x1f;
          if (param_6[uVar8] <= (float)(double)UNK_00571e34._12_8_) {
            *puVar10 = '\x01';
            bVar13 = false;
          }
          else {
            fVar1 = param_6[uVar8];
            *puVar10 = '\x06';
            push_stack(this,param_1,param_2,iVar11,(float)ty + fVar1,
                       (float)ty + fVar1 + (cost - fVar4));
            bVar13 = true;
          }
        }
        else {
          if (uVar3 == '\x02') {
            this->search_map_rows[iVar11][param_2] = '\x06';
            *param_4 = param_2;
            *param_5 = iVar11;
            return '\x01';
          }
          bVar13 = uVar3 != '\x01';
        }
      }
      if (0 < param_2) {
        fVar4 = _DAT_00571e4c;
        if (*param_4 < param_2) {
          fVar4 = ram0x00571e48;
        }
        fVar4 = cost - fVar4;
        iVar11 = param_2 + -1;
        puVar10 = this->search_map_rows[param_3] + iVar11;
        uVar3 = this->search_map_rows[param_3][iVar11];
        if (uVar3 == '\0') {
          bVar2 = this->map_row_offset[param_3][iVar11].field_0x5;
          if (param_6[bVar2 & 0x1f] <= (float)UNK_00571e34._4_4_) {
            *puVar10 = '\x01';
            bVar14 = false;
          }
          else {
            fVar1 = param_6[bVar2 & 0x1f];
            *puVar10 = '\x04';
            push_stack(this,param_1,iVar11,param_3,fVar1 + (float)ty,fVar1 + (float)ty + fVar4);
            bVar14 = true;
          }
        }
        else {
          if (uVar3 == '\x02') {
            this->search_map_rows[param_3][iVar11] = '\x04';
            *param_4 = iVar11;
            *param_5 = param_3;
            return '\x01';
          }
          bVar14 = uVar3 != '\x01';
        }
        if (0 < param_3) {
          map_h = param_3 + -1;
          puVar10 = this->search_map_rows[map_h] + iVar11;
          if (*puVar10 == '\0') {
            uVar8 = (byte)this->map_row_offset[map_h][iVar11].field_0x5 & 0x1f;
            if (param_6[uVar8] <= (float)UNK_00571e34._4_4_) {
              *puVar10 = '\x01';
            }
            else if ((bVar13) && (bVar14)) {
              fVar1 = (float)ty - param_6[uVar8] * _DAT_00571e50;
              *puVar10 = '\b';
              fVar5 = _DAT_00571e58;
              if (*param_5 < param_3) {
                fVar5 = _DAT_00571e54;
              }
              push_stack(this,param_1,iVar11,map_h,fVar1,fVar1 + (fVar4 - fVar5));
            }
          }
          else if (*puVar10 == '\x02') {
            this->search_map_rows[map_h][iVar11] = '\b';
            *param_4 = iVar11;
            *param_5 = map_h;
            return '\x01';
          }
        }
        if (param_3 < map_w) {
          map_h = param_3 + 1;
          puVar10 = this->search_map_rows[map_h] + iVar11;
          if (*puVar10 == '\0') {
            uVar8 = (byte)this->map_row_offset[map_h][iVar11].field_0x5 & 0x1f;
            if (param_6[uVar8] <= (float)UNK_00571e34._4_4_) {
              *puVar10 = '\x01';
            }
            else if ((bVar12) && (bVar14)) {
              fVar1 = (float)ty - param_6[uVar8] * _DAT_00571e50;
              *puVar10 = '\t';
              fVar5 = _DAT_00571e58;
              if (param_3 < *param_5) {
                fVar5 = _DAT_00571e54;
              }
              push_stack(this,param_1,iVar11,map_h,fVar1,fVar1 + (fVar4 - fVar5));
            }
          }
          else if (*puVar10 == '\x02') {
            this->search_map_rows[map_h][iVar11] = '\t';
            *param_4 = iVar11;
            *param_5 = map_h;
            return '\x01';
          }
        }
      }
      if (param_2 < local_4) {
        fVar4 = _DAT_00571e4c;
        if (param_2 < *param_4) {
          fVar4 = ram0x00571e48;
        }
        fVar4 = cost - fVar4;
        iVar11 = param_2 + 1;
        puVar10 = this->search_map_rows[param_3] + iVar11;
        uVar3 = this->search_map_rows[param_3][iVar11];
        if (uVar3 == '\0') {
          uVar8 = (byte)this->map_row_offset[param_3][iVar11].field_0x5 & 0x1f;
          if (param_6[uVar8] <= (float)UNK_00571e34._4_4_) {
            *puVar10 = '\x01';
            bVar14 = false;
          }
          else {
            fVar1 = param_6[uVar8];
            *puVar10 = '\x05';
            push_stack(this,param_1,iVar11,param_3,(float)ty + fVar1,(float)ty + fVar1 + fVar4);
            bVar14 = true;
          }
        }
        else {
          if (uVar3 == '\x02') {
            this->search_map_rows[param_3][iVar11] = '\x05';
            *param_4 = iVar11;
            *param_5 = param_3;
            return '\x01';
          }
          bVar14 = uVar3 != '\x01';
        }
        if (0 < param_3) {
          map_h = param_3 + -1;
          puVar10 = this->search_map_rows[map_h] + iVar11;
          uVar3 = this->search_map_rows[map_h][iVar11];
          if (uVar3 == '\0') {
            uVar8 = (byte)this->map_row_offset[map_h][iVar11].field_0x5 & 0x1f;
            if (param_6[uVar8] <= (float)UNK_00571e34._4_4_) {
              *puVar10 = '\x01';
            }
            else if ((bVar13) && (bVar14)) {
              fVar1 = (float)ty - param_6[uVar8] * _DAT_00571e50;
              *puVar10 = '\n';
              fVar5 = _DAT_00571e60;
              if (*param_5 < param_3) {
                fVar5 = _DAT_00571e5c;
              }
              push_stack(this,param_1,iVar11,map_h,fVar1,fVar1 + (fVar4 - fVar5));
            }
          }
          else if (uVar3 == '\x02') {
            this->search_map_rows[map_h][iVar11] = '\n';
            *param_4 = iVar11;
            *param_5 = map_h;
            return '\x01';
          }
        }
        if (param_3 < map_w) {
          iVar9 = param_3 + 1;
          uVar3 = this->search_map_rows[iVar9][iVar11];
          puVar10 = this->search_map_rows[iVar9] + iVar11;
          if (uVar3 == '\0') {
            uVar8 = (byte)this->map_row_offset[iVar9][iVar11].field_0x5 & 0x1f;
            if (param_6[uVar8] <= (float)UNK_00571e34._4_4_) {
              *puVar10 = '\x01';
            }
            else if ((bVar12) && (bVar14)) {
              fVar1 = (float)ty - param_6[uVar8] * _DAT_00571e50;
              *puVar10 = '\v';
              fVar5 = _DAT_00571e60;
              if (param_3 < *param_5) {
                fVar5 = _DAT_00571e5c;
              }
              push_stack(this,param_1,iVar11,iVar9,fVar1,fVar1 + (fVar4 - fVar5));
            }
          }
          else if (uVar3 == '\x02') {
            this->search_map_rows[iVar9][iVar11] = '\v';
            *param_4 = iVar11;
            *param_5 = iVar9;
            return '\x01';
          }
        }
      }
      pMVar6 = pop_stack(this,param_1,&param_2,&param_3,(float *)&ty);
      if (pMVar6 == (Map_Stack *)0x0) {
        return '\0';
      }
      iVar11 = *param_5;
      map_h = (param_2 - *param_4) * (param_2 - *param_4) + (param_3 - iVar11) * (param_3 - iVar11);
      cost = SQRT((float)map_h);
    } while (cost != (float)(double)UNK_00571e34._12_8_);
  }
  if (param_1->next == (Map_Stack *)0x0) {
    return '\x01';
  }
  param_1->next->prev = (Map_Stack *)0x0;
  return '\x01';
}

// --------------------------------------------------

