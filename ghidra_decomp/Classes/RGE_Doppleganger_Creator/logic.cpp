// Class: RGE_Doppleganger_Creator
// Function: RGE_Doppleganger_Creator
// Address: 00442100
// [HELPER] s_c__aoedoppl_txt: "c:\aoedoppl.txt"
// [HELPER] s_w: "w"
/* public: __thiscall RGE_Doppleganger_Creator::RGE_Doppleganger_Creator(class RGE_Player *,int) */

RGE_Doppleganger_Creator * __thiscall
RGE_Doppleganger_Creator::RGE_Doppleganger_Creator
          (RGE_Doppleganger_Creator *this,RGE_Player *param_1,int param_2)
{
  RGE_Static_Object **ppRVar1;
  ulong **ppuVar2;
  ulong *puVar3;
  int *piVar4;
  
  ppRVar1 = (RGE_Static_Object **)calloc(param_2,4);
  this->Objects = ppRVar1;
  ppuVar2 = (ulong **)calloc(param_2,4);
  this->Map_Addresses = ppuVar2;
  puVar3 = (ulong *)calloc(param_2,4);
  this->Last_Map_Value = puVar3;
  piVar4 = (int *)calloc(param_2,4);
  this->Object_ids = piVar4;
  this->allocated_size = param_2;
  this->active_size = 0;
  this->owner = param_1;
  if (DDlogf == (_iobuf *)0x0) {
    DDlogf = (_iobuf *)fopen(s_c__aoedoppl_txt,s_w);
  }
  return this;
}

// --------------------------------------------------

// Function: ~RGE_Doppleganger_Creator
// Address: 00442180
/* public: __thiscall RGE_Doppleganger_Creator::~RGE_Doppleganger_Creator(void) */

void __thiscall RGE_Doppleganger_Creator::~RGE_Doppleganger_Creator(RGE_Doppleganger_Creator *this)
{
  if (this->Objects != (RGE_Static_Object **)0x0) {
    free(this->Objects);
  }
  if (this->Map_Addresses != (ulong **)0x0) {
    free(this->Map_Addresses);
  }
  if (this->Last_Map_Value != (ulong *)0x0) {
    free(this->Last_Map_Value);
  }
  if (this->Object_ids != (int *)0x0) {
    free(this->Object_ids);
  }
  if (DDlogf != (_iobuf *)0x0) {
    fclose(DDlogf);
    DDlogf = (_iobuf *)0x0;
  }
  return;
}

// --------------------------------------------------

// Function: add_doppleganger_check
// Address: 004421f0
// [HELPER] s_ADC____d__p__d__id__d_: "ADC (@%d) p=%d  id=%d\n"
/* public: int __thiscall RGE_Doppleganger_Creator::add_doppleganger_check(class RGE_Static_Object
   *,unsigned long *) */

int __thiscall
RGE_Doppleganger_Creator::add_doppleganger_check
          (RGE_Doppleganger_Creator *this,RGE_Static_Object *param_1,ulong *param_2)
{
  int iVar1;
  int iVar2;
  RGE_Static_Object **ppRVar3;
  
  if (DDlogf != (_iobuf *)0x0) {
    fprintf(DDlogf,s_ADC____d__p__d__id__d_,this->owner->world->world_time,(int)this->owner->id,
            param_1->id);
  }
  if (this->allocated_size <= this->active_size) {
    expand_allocations(this,0x1e);
  }
  if (param_1->owner->id != this->owner->id) {
    return 0;
  }
  iVar1 = this->active_size;
  if ((0 < iVar1) && (iVar2 = 0, 0 < iVar1)) {
    ppRVar3 = this->Objects;
    do {
      if (*ppRVar3 == param_1) {
        return 0;
      }
      iVar2 = iVar2 + 1;
      ppRVar3 = ppRVar3 + 1;
    } while (iVar2 < iVar1);
  }
  this->Objects[iVar1] = param_1;
  this->Map_Addresses[this->active_size] = param_2;
  this->Last_Map_Value[this->active_size] = *param_2;
  this->Object_ids[this->active_size] = param_1->id;
  this->active_size = this->active_size + 1;
  return 1;
}

// --------------------------------------------------

// Function: remove_doppleganger_check
// Address: 004422b0
// [HELPER] s_RDC____d___p__d__id__d_: "RDC (@%d)  p=%d  id=%d\n"
/* public: int __thiscall RGE_Doppleganger_Creator::remove_doppleganger_check(class
   RGE_Static_Object *) */

int __thiscall
RGE_Doppleganger_Creator::remove_doppleganger_check
          (RGE_Doppleganger_Creator *this,RGE_Static_Object *param_1)
{
  int iVar1;
  RGE_Static_Object **ppRVar2;
  int iVar3;
  RGE_Static_Object **ppRVar4;
  
  if (DDlogf != (_iobuf *)0x0) {
    fprintf(DDlogf,s_RDC____d___p__d__id__d_,this->owner->world->world_time,(int)this->owner->id,
            param_1->id);
  }
  iVar1 = this->active_size;
  if ((0 < iVar1) && (iVar3 = 0, 0 < iVar1)) {
    ppRVar2 = this->Objects;
    ppRVar4 = ppRVar2;
    do {
      if (*ppRVar4 == param_1) {
        iVar1 = iVar1 + -1;
        this->active_size = iVar1;
        if (iVar3 < iVar1) {
          ppRVar2[iVar3] = ppRVar2[iVar1];
          this->Map_Addresses[iVar3] = this->Map_Addresses[this->active_size];
          this->Last_Map_Value[iVar3] = this->Last_Map_Value[this->active_size];
          this->Object_ids[iVar3] = this->Object_ids[this->active_size];
        }
        this->Objects[this->active_size] = (RGE_Static_Object *)0x0;
        this->Map_Addresses[this->active_size] = (ulong *)0x0;
        this->Last_Map_Value[this->active_size] = 0;
        this->Object_ids[this->active_size] = 0;
        return 1;
      }
      iVar3 = iVar3 + 1;
      ppRVar4 = ppRVar4 + 1;
    } while (iVar3 < iVar1);
    return 0;
  }
  return 0;
}

// --------------------------------------------------

// Function: perform_doppleganger_checks
// Address: 00442390
// [HELPER] s_NEW_DOP____d__by_p__d_for_p__d_o: "NEW DOP (@%d) by p=%d for p=%d of id=%d (x=%d, y=%d)\n"
// [HELPER] s_____REMOVE_CHECK____d__by_p__d_i: "*** REMOVE CHECK (@%d) by p=%d id=%d\n"
/* WARNING: Variable defined which should be unmapped: Unified_Map_Value */
/* public: void __thiscall RGE_Doppleganger_Creator::perform_doppleganger_checks(void) */

void __thiscall
RGE_Doppleganger_Creator::perform_doppleganger_checks(RGE_Doppleganger_Creator *this)
{
  uint uVar1;
  RGE_Player *pRVar2;
  RGE_Static_Object *pRVar3;
  int iVar4;
  undefined4 uVar5;
  RGE_Static_Object *pRVar6;
  int iVar7;
  uint uVar8;
  ulong Unified_Map_Value;
  int x;
  RGE_Static_Object *remove_me;
  RGE_Static_Object *local_c;
  
  local_c = (RGE_Static_Object *)0x0;
  if (0 < this->active_size) {
    remove_me = (RGE_Static_Object *)0x0;
    pRVar6 = (RGE_Static_Object *)0x0;
    if (0 < this->active_size) {
      do {
        uVar1 = *this->Map_Addresses[(int)remove_me];
        if (uVar1 != this->Last_Map_Value[(int)remove_me]) {
          pRVar6 = this->Objects[(int)remove_me];
          if (pRVar6 == (RGE_Static_Object *)0x0) {
LAB_00442506:
            local_c = pRVar6;
            if (DDlogf != (_iobuf *)0x0) {
              fprintf(DDlogf,s_____REMOVE_CHECK____d__by_p__d_i,this->owner->world->world_time,
                      (int)this->owner->id,this->Object_ids[(int)remove_me]);
            }
          }
          else {
            pRVar6 = this->Objects[(int)remove_me];
            pRVar3 = RGE_Game_World::object(this->owner->world,this->Object_ids[(int)remove_me]);
            if (pRVar3 != pRVar6) goto LAB_00442506;
            iVar7 = 1;
            for (uVar8 = ((uVar1 ^ this->Last_Map_Value[(int)remove_me]) &
                         this->Last_Map_Value[(int)remove_me]) >> 1 & 0x7fff; uVar8 != 0;
                uVar8 = uVar8 >> 1) {
              if (((byte)uVar8 & 1) == 1) {
                pRVar2 = this->owner;
                iVar4 = (int)pRVar2->id;
                if (iVar7 != iVar4) {
                  if (DDlogf != (_iobuf *)0x0) {
                    pRVar6 = this->Objects[(int)remove_me];
                    uVar5 = __ftol();
                    uVar5 = __ftol(uVar5);
                    fprintf(DDlogf,s_NEW_DOP____d__by_p__d_for_p__d_o,pRVar2->world->world_time,
                            iVar4,iVar7,pRVar6->id,uVar5);
                  }
                  pRVar2 = this->owner->world->players[iVar7];
                  pRVar6 = this->Objects[(int)remove_me];
                  (**(code **)(pRVar2->master_objects[0xf3]->_padding_ + 0x38))
                            (pRVar2,pRVar6->world_x,pRVar6->world_y,pRVar6->world_z,pRVar6);
                }
              }
              iVar7 = iVar7 + 1;
            }
          }
          this->Last_Map_Value[(int)remove_me] = uVar1;
        }
        remove_me = (RGE_Static_Object *)((int)&remove_me->_padding_ + 1);
        pRVar6 = local_c;
      } while ((int)remove_me < this->active_size);
    }
    if (pRVar6 != (RGE_Static_Object *)0x0) {
      remove_doppleganger_check(this,pRVar6);
    }
  }
  return;
}

// --------------------------------------------------

// Function: expand_allocations
// Address: 00442540
// [HELPER] s_RESIZE____d__p__d__grow__d_: "RESIZE (@%d) p=%d  grow=%d\n"
/* WARNING: Variable defined which should be unmapped: TLast_Map_Value */
/* protected: void __thiscall RGE_Doppleganger_Creator::expand_allocations(int) */

void __thiscall
RGE_Doppleganger_Creator::expand_allocations(RGE_Doppleganger_Creator *this,int param_1)
{
  RGE_Static_Object **ppRVar1;
  ulong **ppuVar2;
  ulong *puVar3;
  int *piVar4;
  uint uVar5;
  int iVar6;
  RGE_Static_Object **ppRVar7;
  ulong **ppuVar8;
  ulong *puVar9;
  int *piVar10;
  RGE_Static_Object **ppRVar11;
  ulong **ppuVar12;
  ulong *puVar13;
  int *piVar14;
  ulong *TLast_Map_Value;
  int *TObject_ids;
  
  if (DDlogf != (_iobuf *)0x0) {
    fprintf(DDlogf,s_RESIZE____d__p__d__grow__d_,this->owner->world->world_time,(int)this->owner->id
            ,param_1);
  }
  iVar6 = this->allocated_size + param_1;
  this->allocated_size = iVar6;
  ppRVar1 = (RGE_Static_Object **)calloc(iVar6,4);
  ppuVar2 = (ulong **)calloc(this->allocated_size,4);
  puVar3 = (ulong *)calloc(this->allocated_size,4);
  piVar4 = (int *)calloc(this->allocated_size,4);
  ppRVar7 = this->Objects;
  ppRVar11 = ppRVar1;
  for (uVar5 = this->active_size & 0x3fffffff; uVar5 != 0; uVar5 = uVar5 - 1) {
    *ppRVar11 = *ppRVar7;
    ppRVar7 = ppRVar7 + 1;
    ppRVar11 = ppRVar11 + 1;
  }
  for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {
    *(undefined1 *)ppRVar11 = *(undefined1 *)ppRVar7;
    ppRVar7 = (RGE_Static_Object **)((int)ppRVar7 + 1);
    ppRVar11 = (RGE_Static_Object **)((int)ppRVar11 + 1);
  }
  ppuVar8 = this->Map_Addresses;
  ppuVar12 = ppuVar2;
  for (uVar5 = this->active_size & 0x3fffffff; uVar5 != 0; uVar5 = uVar5 - 1) {
    *ppuVar12 = *ppuVar8;
    ppuVar8 = ppuVar8 + 1;
    ppuVar12 = ppuVar12 + 1;
  }
  for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {
    *(undefined1 *)ppuVar12 = *(undefined1 *)ppuVar8;
    ppuVar8 = (ulong **)((int)ppuVar8 + 1);
    ppuVar12 = (ulong **)((int)ppuVar12 + 1);
  }
  puVar9 = this->Last_Map_Value;
  puVar13 = puVar3;
  for (uVar5 = this->active_size & 0x3fffffff; uVar5 != 0; uVar5 = uVar5 - 1) {
    *puVar13 = *puVar9;
    puVar9 = puVar9 + 1;
    puVar13 = puVar13 + 1;
  }
  for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {
    *(char *)puVar13 = (char)*puVar9;
    puVar9 = (ulong *)((int)puVar9 + 1);
    puVar13 = (ulong *)((int)puVar13 + 1);
  }
  piVar10 = this->Object_ids;
  piVar14 = piVar4;
  for (uVar5 = this->active_size & 0x3fffffff; uVar5 != 0; uVar5 = uVar5 - 1) {
    *piVar14 = *piVar10;
    piVar10 = piVar10 + 1;
    piVar14 = piVar14 + 1;
  }
  for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {
    *(char *)piVar14 = (char)*piVar10;
    piVar10 = (int *)((int)piVar10 + 1);
    piVar14 = (int *)((int)piVar14 + 1);
  }
  free(this->Objects);
  free(this->Map_Addresses);
  free(this->Last_Map_Value);
  free(this->Object_ids);
  this->Objects = ppRVar1;
  this->Map_Addresses = ppuVar2;
  this->Last_Map_Value = puVar3;
  this->Object_ids = piVar4;
  return;
}

// --------------------------------------------------

