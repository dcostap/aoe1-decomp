// Class: TRIBE_History_Info
// Size:  0x14
//
// Member Layout:
// [0x000] TRIBE_History_Entry * history
// [0x004] TRIBE_History_Events * events
// [0x008] long number_of_events
// [0x00C] long number_of_entries
// [0x010] long max_number_of_entries
// ----------------------------------------------------------------

// Function: TRIBE_History_Info
// Address: 004cc730
/* public: __thiscall TRIBE_History_Info::TRIBE_History_Info(int) */

TRIBE_History_Info * __thiscall
TRIBE_History_Info::TRIBE_History_Info(TRIBE_History_Info *this,int param_1)
{
  this->history = (TRIBE_History_Entry *)0x0;
  this->events = (TRIBE_History_Events *)0x0;
  this->number_of_entries = 0;
  this->number_of_events = 0;
  this->max_number_of_entries = 0;
  if (-1 < param_1) {
    load(this,param_1);
  }
  return this;
}

// --------------------------------------------------

// Function: ~TRIBE_History_Info
// Address: 004cc760
/* public: __thiscall TRIBE_History_Info::~TRIBE_History_Info(void) */

void __thiscall TRIBE_History_Info::~TRIBE_History_Info(TRIBE_History_Info *this)
{
  TRIBE_History_Events *pTVar1;
  
  if (this->history != (TRIBE_History_Entry *)0x0) {
    free(this->history);
  }
  pTVar1 = this->events;
  while (pTVar1 != (TRIBE_History_Events *)0x0) {
    this->events = pTVar1->next;
    free(pTVar1);
    pTVar1 = this->events;
  }
  return;
}

// --------------------------------------------------

// Function: save
// Address: 004cc7a0
/* public: void __thiscall TRIBE_History_Info::save(int) */

void __thiscall TRIBE_History_Info::save(TRIBE_History_Info *this,int param_1)
{
  TRIBE_History_Events *pTVar1;
  int iVar2;
  
  iVar2 = param_1;
  rge_write(param_1,&this->number_of_entries,4);
  rge_write(iVar2,&this->number_of_events,4);
  rge_write(iVar2,&this->max_number_of_entries,4);
  rge_write(iVar2,this->history,this->max_number_of_entries);
  pTVar1 = this->events;
  param_1 = 0;
  for (; pTVar1 != (TRIBE_History_Events *)0x0; pTVar1 = pTVar1->next) {
    param_1 = param_1 + 1;
  }
  rge_write(iVar2,&param_1,4);
  for (pTVar1 = this->events; pTVar1 != (TRIBE_History_Events *)0x0; pTVar1 = pTVar1->next) {
    rge_write(iVar2,pTVar1,0x10);
  }
  return;
}

// --------------------------------------------------

// Function: load
// Address: 004cc840
/* public: void __thiscall TRIBE_History_Info::load(int) */

void __thiscall TRIBE_History_Info::load(TRIBE_History_Info *this,int param_1)
{
  long *plVar1;
  TRIBE_History_Events **ppTVar2;
  int iVar3;
  TRIBE_History_Entry *pTVar4;
  TRIBE_History_Events *pTVar5;
  
  iVar3 = param_1;
  rge_read(param_1,&this->number_of_entries,4);
  rge_read(iVar3,&this->number_of_events,4);
  plVar1 = &this->max_number_of_entries;
  rge_read(iVar3,plVar1,4);
  pTVar4 = (TRIBE_History_Entry *)calloc(*plVar1,1);
  this->history = pTVar4;
  rge_read(iVar3,pTVar4,*plVar1);
  ppTVar2 = &this->events;
  rge_read(iVar3,&param_1,4);
  for (; 0 < param_1; param_1 = param_1 + -1) {
    pTVar5 = (TRIBE_History_Events *)calloc(1,0x10);
    rge_read(iVar3,pTVar5,0x10);
    *ppTVar2 = pTVar5;
    ppTVar2 = &pTVar5->next;
  }
  return;
}

// --------------------------------------------------

// Function: add_history_entry
// Address: 004cc8e0
/* public: void __thiscall TRIBE_History_Info::add_history_entry(unsigned char,unsigned char) */

void __thiscall
TRIBE_History_Info::add_history_entry(TRIBE_History_Info *this,uchar param_1,uchar param_2)
{
  TRIBE_History_Entry *pTVar1;
  uint uVar2;
  uint uVar3;
  TRIBE_History_Entry *pTVar4;
  TRIBE_History_Entry *pTVar5;
  
  uVar3 = this->max_number_of_entries;
  if ((int)uVar3 <= this->number_of_entries) {
    this->max_number_of_entries = uVar3 + 0x3c;
    pTVar1 = (TRIBE_History_Entry *)calloc(uVar3 + 0x3c,1);
    if (0 < (int)uVar3) {
      pTVar4 = this->history;
      pTVar5 = pTVar1;
      for (uVar2 = uVar3 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
        *(undefined4 *)pTVar5 = *(undefined4 *)pTVar4;
        pTVar4 = pTVar4 + 4;
        pTVar5 = pTVar5 + 4;
      }
      for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
        pTVar5->population = pTVar4->population;
        pTVar4 = pTVar4 + 1;
        pTVar5 = pTVar5 + 1;
      }
      free(this->history);
    }
    this->history = pTVar1;
  }
  if (param_1 == '\0') {
    this->history[this->number_of_entries].population = param_2;
  }
  this->number_of_entries = this->number_of_entries + 1;
  return;
}

// --------------------------------------------------

// Function: get_history_entry_num
// Address: 004cc950
/* public: long __thiscall TRIBE_History_Info::get_history_entry_num(void) */

long __thiscall TRIBE_History_Info::get_history_entry_num(TRIBE_History_Info *this)
{
  return this->number_of_entries;
}

// --------------------------------------------------

// Function: get_history_entry
// Address: 004cc960
/* public: unsigned char __thiscall TRIBE_History_Info::get_history_entry(unsigned char,long) */

uchar __thiscall
TRIBE_History_Info::get_history_entry(TRIBE_History_Info *this,uchar param_1,long param_2)
{
  if (((param_2 < this->number_of_entries) && (-1 < param_2)) && (param_1 == '\0')) {
    return this->history[param_2].population;
  }
  return '\0';
}

// --------------------------------------------------

// Function: add_history_event
// Address: 004cc990
/* public: void __thiscall TRIBE_History_Info::add_history_event(unsigned char) */

void __thiscall TRIBE_History_Info::add_history_event(TRIBE_History_Info *this,uchar param_1)
{
  TRIBE_History_Events *pTVar1;
  
  if (0 < this->number_of_entries) {
    pTVar1 = (TRIBE_History_Events *)calloc(1,0x10);
    pTVar1->next = this->events;
    pTVar1->time = this->number_of_entries;
    pTVar1->world_time = rge_base_game->world->world_time;
    pTVar1->event = param_1;
    this->events = pTVar1;
  }
  return;
}

// --------------------------------------------------

// Function: get_history_event_num
// Address: 004cc9e0
/* public: long __thiscall TRIBE_History_Info::get_history_event_num(void) */

long __thiscall TRIBE_History_Info::get_history_event_num(TRIBE_History_Info *this)
{
  return this->number_of_events;
}

// --------------------------------------------------

// Function: get_history_event
// Address: 004cc9f0
/* public: unsigned char __thiscall TRIBE_History_Info::get_history_event(long,unsigned char &,long
   &) */

uchar __thiscall
TRIBE_History_Info::get_history_event
          (TRIBE_History_Info *this,long param_1,uchar *param_2,long *param_3)
{
  TRIBE_History_Events *pTVar1;
  
  pTVar1 = this->events;
  if (pTVar1 == (TRIBE_History_Events *)0x0) {
    return '\0';
  }
  do {
    if (param_1 == 0) {
      *param_2 = pTVar1->event;
      *param_3 = pTVar1->time;
      return '\x01';
    }
    pTVar1 = pTVar1->next;
  } while (pTVar1 != (TRIBE_History_Events *)0x0);
  return '\0';
}

// --------------------------------------------------

// Function: get_history_event
// Address: 004cca30
/* public: unsigned char __thiscall TRIBE_History_Info::get_history_event(long,unsigned char &) */

uchar __thiscall
TRIBE_History_Info::get_history_event(TRIBE_History_Info *this,long param_1,uchar *param_2)
{
  TRIBE_History_Events *pTVar1;
  
  pTVar1 = this->events;
  if (pTVar1 == (TRIBE_History_Events *)0x0) {
    return '\0';
  }
  do {
    if (pTVar1->time == param_1) {
      *param_2 = pTVar1->event;
      return '\x01';
    }
    pTVar1 = pTVar1->next;
  } while (pTVar1 != (TRIBE_History_Events *)0x0);
  return '\0';
}

// --------------------------------------------------

