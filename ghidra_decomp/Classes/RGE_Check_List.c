// Class: RGE_Check_List
// Size:  0x4
//
// Member Layout:
// [0x000] RGE_Check_Node * list
// ----------------------------------------------------------------

// Function: RGE_Check_List
// Address: 004c66c0
/* public: __thiscall RGE_Check_List::RGE_Check_List(void) */

void __thiscall RGE_Check_List::RGE_Check_List(RGE_Check_List *this)
{
  this->list = (RGE_Check_Node *)0x0;
  return;
}

// --------------------------------------------------

// Function: ~RGE_Check_List
// Address: 004c66d0
/* public: __thiscall RGE_Check_List::~RGE_Check_List(void) */

void __thiscall RGE_Check_List::~RGE_Check_List(RGE_Check_List *this)
{
  RGE_Check_Node *pRVar1;
  
  pRVar1 = this->list;
  while (pRVar1 != (RGE_Check_Node *)0x0) {
    pRVar1 = this->list->next;
    free(this->list);
    this->list = pRVar1;
  }
  return;
}

// --------------------------------------------------

// Function: add_node
// Address: 004c6700
/* public: void __thiscall RGE_Check_List::add_node(class RGE_Static_Object *,float,float,unsigned
   char) */

void __thiscall
RGE_Check_List::add_node
          (RGE_Check_List *this,RGE_Static_Object *param_1,float param_2,float param_3,uchar param_4
          )
{
  RGE_Check_Node *pRVar1;
  
  pRVar1 = (RGE_Check_Node *)calloc(1,0x14);
  pRVar1->next = this->list;
  pRVar1->node = param_1;
  pRVar1->dx = param_2;
  pRVar1->dy = param_3;
  pRVar1->flag = param_4;
  this->list = pRVar1;
  return;
}

// --------------------------------------------------

