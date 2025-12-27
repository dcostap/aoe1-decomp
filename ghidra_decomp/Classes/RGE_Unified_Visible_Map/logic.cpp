// Class: RGE_Unified_Visible_Map
// Function: RGE_Unified_Visible_Map
// Address: 0053ce80
/* public: __thiscall RGE_Unified_Visible_Map::RGE_Unified_Visible_Map(int,int) */

RGE_Unified_Visible_Map * __thiscall
RGE_Unified_Visible_Map::RGE_Unified_Visible_Map
          (RGE_Unified_Visible_Map *this,int param_1,int param_2)
{
  ulong *puVar1;
  
  this->mapWidth = param_1;
  this->mapHeight = param_2;
  Map_Update_Suppresion = 0;
  if ((0 < this->mapHeight) && (0 < this->mapWidth)) {
    puVar1 = (ulong *)calloc(this->mapWidth * this->mapHeight,4);
    this->UnifiedVisibleMap = puVar1;
    Set_Map_Offsets(this);
    return this;
  }
  this->UnifiedVisibleMap = (ulong *)0x0;
  this->mapWidth = 0;
  this->mapHeight = 0;
  Set_Map_Offsets(this);
  return this;
}

// --------------------------------------------------

// Function: RGE_Unified_Visible_Map
// Address: 0053cee0
/* public: __thiscall RGE_Unified_Visible_Map::RGE_Unified_Visible_Map(int,class RGE_Game_World *)
    */

RGE_Unified_Visible_Map * __thiscall
RGE_Unified_Visible_Map::RGE_Unified_Visible_Map
          (RGE_Unified_Visible_Map *this,int param_1,RGE_Game_World *param_2)
{
  this->UnifiedVisibleMap = (ulong *)0x0;
  this->mapWidth = 0;
  this->mapHeight = 0;
  Map_Update_Suppresion = 0;
  load(this,param_1);
  Set_Map_Offsets(this);
  return this;
}

// --------------------------------------------------

// Function: load
// Address: 0053cf10
/* WARNING: Variable defined which should be unmapped: oh */
/* public: void __thiscall RGE_Unified_Visible_Map::load(int) */

void __thiscall RGE_Unified_Visible_Map::load(RGE_Unified_Visible_Map *this,int param_1)
{
  int *piVar1;
  int iVar2;
  int iVar3;
  ulong *puVar4;
  int oh;
  
  iVar2 = this->mapHeight;
  iVar3 = this->mapWidth;
  piVar1 = &this->mapHeight;
  rge_read(param_1,this,4);
  rge_read(param_1,piVar1,4);
  if ((0 < *piVar1) && (0 < this->mapWidth)) {
    if ((iVar3 != this->mapWidth) || (iVar2 != *piVar1)) {
      if (this->UnifiedVisibleMap != (ulong *)0x0) {
        free(this->UnifiedVisibleMap);
      }
      puVar4 = (ulong *)calloc(this->mapWidth * *piVar1,4);
      this->UnifiedVisibleMap = puVar4;
    }
    rge_read(param_1,this->UnifiedVisibleMap,this->mapWidth * *piVar1 * 4);
    return;
  }
  *piVar1 = 0;
  this->UnifiedVisibleMap = (ulong *)0x0;
  this->mapWidth = 0;
  return;
}

// --------------------------------------------------

// Function: ~RGE_Unified_Visible_Map
// Address: 0053cfc0
/* public: __thiscall RGE_Unified_Visible_Map::~RGE_Unified_Visible_Map(void) */

void __thiscall RGE_Unified_Visible_Map::~RGE_Unified_Visible_Map(RGE_Unified_Visible_Map *this)
{
  this->mapHeight = 0;
  Set_Map_Offsets(this);
  if (this->UnifiedVisibleMap != (ulong *)0x0) {
    free(this->UnifiedVisibleMap);
  }
  return;
}

// --------------------------------------------------

// Function: save
// Address: 0053cff0
/* public: void __thiscall RGE_Unified_Visible_Map::save(int) */

void __thiscall RGE_Unified_Visible_Map::save(RGE_Unified_Visible_Map *this,int param_1)
{
  int iVar1;
  
  rge_write(param_1,this,4);
  rge_write(param_1,&this->mapHeight,4);
  iVar1 = this->mapHeight;
  if ((0 < iVar1) && (0 < this->mapWidth)) {
    rge_write(param_1,this->UnifiedVisibleMap,this->mapWidth * iVar1 * 4);
  }
  return;
}

// --------------------------------------------------

// Function: reset
// Address: 0053d040
/* public: void __thiscall RGE_Unified_Visible_Map::reset(void) */

void __thiscall RGE_Unified_Visible_Map::reset(RGE_Unified_Visible_Map *this)
{
  uint uVar1;
  int iVar2;
  ulong *puVar3;
  
  if (this->UnifiedVisibleMap != (ulong *)0x0) {
    puVar3 = this->UnifiedVisibleMap;
    for (uVar1 = this->mapHeight * this->mapWidth & 0x3fffffff; uVar1 != 0; uVar1 = uVar1 - 1) {
      *puVar3 = 0;
      puVar3 = puVar3 + 1;
    }
    for (iVar2 = 0; iVar2 != 0; iVar2 = iVar2 + -1) {
      *(undefined1 *)puVar3 = 0;
      puVar3 = (ulong *)((int)puVar3 + 1);
    }
  }
  return;
}

// --------------------------------------------------

// Function: Set_Map_Offsets
// Address: 0053d070
/* private: void __thiscall RGE_Unified_Visible_Map::Set_Map_Offsets(void) */

void __thiscall RGE_Unified_Visible_Map::Set_Map_Offsets(RGE_Unified_Visible_Map *this)
{
  int iVar1;
  ulong ***pppuVar2;
  int iVar3;
  
  iVar1 = 0;
  if (0 < this->mapHeight) {
    pppuVar2 = &unified_map_offsets;
    do {
      iVar3 = this->mapWidth * iVar1;
      iVar1 = iVar1 + 1;
      *pppuVar2 = (ulong **)(this->UnifiedVisibleMap + iVar3);
      pppuVar2 = pppuVar2 + 1;
    } while (iVar1 < this->mapHeight);
  }
  iVar1 = this->mapHeight;
  if (iVar1 < 0x100) {
    pppuVar2 = &unified_map_offsets + iVar1;
    for (iVar3 = 0x100 - iVar1; iVar3 != 0; iVar3 = iVar3 + -1) {
      *pppuVar2 = (ulong **)0x0;
      pppuVar2 = pppuVar2 + 1;
    }
  }
  return;
}

// --------------------------------------------------

// Function: suppress_updates
// Address: 0053d0c0
/* public: void __thiscall RGE_Unified_Visible_Map::suppress_updates(int) */

void __thiscall RGE_Unified_Visible_Map::suppress_updates(RGE_Unified_Visible_Map *this,int param_1)
{
  Map_Update_Suppresion = param_1;
  return;
}

// --------------------------------------------------

