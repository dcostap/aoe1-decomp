// Class: RGE_Tile_List
// Function: add_node
// Address: 00471d70
/* public: void __thiscall RGE_Tile_List::add_node(int,int) */

void __thiscall RGE_Tile_List::add_node(RGE_Tile_List *this,int param_1,int param_2)
{
  RGE_Tile_List_Node *pRVar1;
  uint uVar2;
  int iVar3;
  RGE_Tile_List_Node *pRVar4;
  RGE_Tile_List_Node *pRVar5;
  
  if (this->list_size <= this->num_active) {
    pRVar1 = (RGE_Tile_List_Node *)calloc(this->list_size * 2,8);
    pRVar4 = this->list;
    pRVar5 = pRVar1;
    for (uVar2 = (uint)(this->list_size << 3) >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
      pRVar5->col = pRVar4->col;
      pRVar4 = (RGE_Tile_List_Node *)&pRVar4->row;
      pRVar5 = (RGE_Tile_List_Node *)&pRVar5->row;
    }
    for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
      *(char *)&pRVar5->col = (char)pRVar4->col;
      pRVar4 = (RGE_Tile_List_Node *)((int)&pRVar4->col + 1);
      pRVar5 = (RGE_Tile_List_Node *)((int)&pRVar5->col + 1);
    }
    free(this->list);
    this->list = pRVar1;
    this->list_size = this->list_size << 1;
  }
  this->list[this->num_active].col = param_1;
  this->list[this->num_active].row = param_2;
  this->num_active = this->num_active + 1;
  this->new_count = this->new_count + 1;
  return;
}

// --------------------------------------------------

// Function: del_list
// Address: 00471df0
/* public: void __thiscall RGE_Tile_List::del_list(void) */

void __thiscall RGE_Tile_List::del_list(RGE_Tile_List *this)
{
  RGE_Tile_List_Node *pRVar1;
  
  this->num_active = 0;
  this->new_count = 0;
  if (this->collapse_list != 0) {
    free(this->list);
    this->list_size = 8;
    pRVar1 = (RGE_Tile_List_Node *)calloc(8,8);
    this->list = pRVar1;
    this->collapse_list = 0;
  }
  return;
}

// --------------------------------------------------

// Function: RGE_Tile_List
// Address: 00471e40
/* public: __thiscall RGE_Tile_List::RGE_Tile_List(int) */

RGE_Tile_List * __thiscall RGE_Tile_List::RGE_Tile_List(RGE_Tile_List *this,int param_1)
{
  RGE_Tile_List_Node *pRVar1;
  
  pRVar1 = (RGE_Tile_List_Node *)calloc(param_1,8);
  this->list = pRVar1;
  this->list_size = param_1;
  this->num_active = 0;
  this->new_count = 0;
  this->collapse_list = 0;
  return this;
}

// --------------------------------------------------

// Function: ~RGE_Tile_List
// Address: 00471e70
/* public: __thiscall RGE_Tile_List::~RGE_Tile_List(void) */

void __thiscall RGE_Tile_List::~RGE_Tile_List(RGE_Tile_List *this)
{
  if (this->list != (RGE_Tile_List_Node *)0x0) {
    free(this->list);
  }
  return;
}

// --------------------------------------------------

// Function: get_list_info
// Address: 00471e90
/* public: void __thiscall RGE_Tile_List::get_list_info(struct RGE_Tile_List_Node * &,int &) */

void __thiscall
RGE_Tile_List::get_list_info(RGE_Tile_List *this,RGE_Tile_List_Node **param_1,int *param_2)
{
  *param_1 = this->list;
  *param_2 = this->num_active;
  return;
}

// --------------------------------------------------

// Function: get_new_count
// Address: 00471eb0
/* public: int __thiscall RGE_Tile_List::get_new_count(void) */

int __thiscall RGE_Tile_List::get_new_count(RGE_Tile_List *this)
{
  int iVar1;
  
  iVar1 = this->new_count;
  this->new_count = 0;
  return iVar1;
}

// --------------------------------------------------

