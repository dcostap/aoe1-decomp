// GLOBAL FUNCTIONS PART 5200
// Function: FUN_00531ee2
// Address: 00531ee2
void __thiscall FUN_00531ee2(RGE_Victory_Conditions *param_1,RGE_Static_Object *param_2)
{
  RGE_Victory_Entry *pRVar1;
  RGE_Victory_Entry *pRVar2;
  
  pRVar1 = param_1->victory_list;
  while (pRVar2 = pRVar1, pRVar2 != (RGE_Victory_Entry *)0x0) {
    pRVar1 = pRVar2->next;
    if ((pRVar2->this_obj == param_2) || (pRVar2->target_obj == param_2)) {
      RGE_Victory_Conditions::sub(param_1,pRVar2);
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00531f23
// Address: 00531f23
void __thiscall FUN_00531f23(RGE_Victory_Conditions *param_1,RGE_Victory_Point_Entry *param_2)
{
  switch(param_2->command) {
  case '\0':
    RGE_Victory_Conditions::handle_points_attribute_amount(param_1,param_2);
    return;
  case '\x01':
    RGE_Victory_Conditions::handle_points_attribute_first(param_1,param_2);
    return;
  case '\x02':
    RGE_Victory_Conditions::handle_points_highest_attribute(param_1,param_2);
    return;
  case '\x03':
    RGE_Victory_Conditions::handle_points_high_attribute_once(param_1,param_2);
    return;
  case '\x04':
    RGE_Victory_Conditions::handle_points_high_attribute_amount(param_1,param_2);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00531f71
// Address: 00531f71
void __fastcall FUN_00531f71(RGE_Victory_Conditions *param_1,char param_2)
{
  int in_EAX;
  RGE_Victory_Entry *unaff_EBX;
  int unaff_EBP;
  int unaff_ESI;
  int unaff_EDI;
  
  *(char *)(unaff_EBP + 0x1f) = *(char *)(unaff_EBP + 0x1f) + (char)param_1;
  *(char *)(unaff_ESI + 0x1f) = *(char *)(unaff_ESI + 0x1f) + param_2;
  *(char *)(unaff_EDI + 0x1f) = *(char *)(unaff_EDI + 0x1f) + (char)unaff_EBX;
  *(char *)(in_EAX + 0x1f) = *(char *)(in_EAX + 0x1f) + (char)((uint)param_1 >> 8);
  *(char *)(in_EAX + -0x6f6f6f70) = *(char *)(in_EAX + -0x6f6f6f70) + param_2;
  switch(unaff_EBX->command) {
  case '\0':
    RGE_Victory_Conditions::handle_capture(param_1,unaff_EBX);
    return;
  case '\x01':
    RGE_Victory_Conditions::handle_create(param_1,unaff_EBX);
    return;
  case '\x02':
    RGE_Victory_Conditions::handle_destroy(param_1,unaff_EBX);
    return;
  case '\x03':
    RGE_Victory_Conditions::handle_destroy_multiple(param_1,unaff_EBX);
    return;
  case '\x04':
    RGE_Victory_Conditions::handle_bring_area(param_1,unaff_EBX);
    return;
  case '\x05':
    RGE_Victory_Conditions::handle_bring_object(param_1,unaff_EBX);
    return;
  case '\x06':
    RGE_Victory_Conditions::handle_attribute(param_1,unaff_EBX);
    return;
  case '\a':
    RGE_Victory_Conditions::handle_explore(param_1,unaff_EBX);
    return;
  case '\b':
    RGE_Victory_Conditions::handle_create_in_area(param_1,unaff_EBX);
    return;
  case '\t':
    RGE_Victory_Conditions::handle_destroy_all(param_1,unaff_EBX);
    return;
  case '\n':
    RGE_Victory_Conditions::handle_destroy_player(param_1,unaff_EBX);
    return;
  case '\f':
    RGE_Victory_Conditions::handle_victory_points(param_1,unaff_EBX);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00532106
// Address: 00532106
void __thiscall FUN_00532106(int param_1,int param_2)
{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int iStack_8;
  
  iVar1 = *(int *)(param_1 + 0xc);
  iVar6 = 0;
  iStack_8 = 0;
  piVar3 = *(int **)(*(int *)(iVar1 + 0x28) + 4);
  if (piVar3 != (int *)0x0) {
    do {
      if (((int)*(short *)(*(int *)(*piVar3 + 8) + 0x12) == *(int *)(param_2 + 4)) &&
         (*(char *)(*piVar3 + 0x48) == '\x02')) {
        iVar6 = iVar6 + 1;
      }
      piVar3 = (int *)piVar3[1];
      iStack_8 = iVar6;
    } while (piVar3 != (int *)0x0);
  }
  if ((*(char *)(param_2 + 0x2d) != '\0') && (*(char *)(iVar1 + 0x104) != '\0')) {
    iVar5 = 1;
    iVar6 = (int)*(short *)(*(int *)(iVar1 + 0x3c) + 0x3c);
    piVar3 = *(int **)(*(int *)(iVar1 + 0x3c) + 0x40);
    if (1 < iVar6) {
      do {
        piVar3 = piVar3 + 1;
        if (*(char *)(iVar5 + *(int *)(iVar1 + 0x84)) == '\0') {
          iVar2 = *piVar3;
          if ((((*(char *)(*(int *)(iVar2 + 0x84) + (int)*(short *)(iVar1 + 0x4a)) == '\0') &&
               (iVar5 != *(short *)(iVar1 + 0x4a))) && (*(char *)(iVar2 + 0x104) != '\0')) &&
             (piVar4 = *(int **)(*(int *)(iVar2 + 0x28) + 4), piVar4 != (int *)0x0)) {
            do {
              if (((int)*(short *)(*(int *)(*piVar4 + 8) + 0x12) == *(int *)(param_2 + 4)) &&
                 (*(char *)(*piVar4 + 0x48) == '\x02')) {
                iStack_8 = iStack_8 + 1;
              }
              piVar4 = (int *)piVar4[1];
            } while (piVar4 != (int *)0x0);
          }
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < iVar6);
    }
  }
  if (iStack_8 < *(int *)(param_2 + 0x1c)) {
    *(undefined1 *)(param_2 + 0x2e) = 0;
    return;
  }
  *(undefined1 *)(param_2 + 0x2e) = 2;
  return;
}

// --------------------------------------------------

// Function: FUN_00532213
// Address: 00532213
void __thiscall FUN_00532213(int param_1,int param_2)
{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int iStack_c;
  
  iVar1 = *(int *)(param_1 + 0xc);
  iVar5 = 0;
  iStack_c = 0;
  piVar3 = *(int **)(*(int *)(iVar1 + 0x28) + 4);
  if (piVar3 != (int *)0x0) {
    do {
      iVar6 = *piVar3;
      if ((((((int)*(short *)(*(int *)(iVar6 + 8) + 0x12) == *(int *)(param_2 + 4)) &&
            (*(char *)(iVar6 + 0x48) == '\x02')) &&
           (*(float *)(param_2 + 0xc) <= *(float *)(iVar6 + 0x38))) &&
          ((*(float *)(iVar6 + 0x38) <= *(float *)(param_2 + 0x14) &&
           (*(float *)(param_2 + 0x10) <= *(float *)(iVar6 + 0x3c))))) &&
         (*(float *)(iVar6 + 0x3c) <= *(float *)(param_2 + 0x18))) {
        iVar5 = iVar5 + 1;
      }
      piVar3 = (int *)piVar3[1];
      iStack_c = iVar5;
    } while (piVar3 != (int *)0x0);
  }
  if ((*(char *)(param_2 + 0x2d) != '\0') && (*(char *)(iVar1 + 0x104) != '\0')) {
    iVar5 = 1;
    iVar6 = (int)*(short *)(*(int *)(iVar1 + 0x3c) + 0x3c);
    piVar3 = *(int **)(*(int *)(iVar1 + 0x3c) + 0x40);
    if (1 < iVar6) {
      do {
        piVar3 = piVar3 + 1;
        if (*(char *)(iVar5 + *(int *)(iVar1 + 0x84)) == '\0') {
          iVar2 = *piVar3;
          if ((((*(char *)(*(int *)(iVar2 + 0x84) + (int)*(short *)(iVar1 + 0x4a)) == '\0') &&
               (iVar5 != *(short *)(iVar1 + 0x4a))) && (*(char *)(iVar2 + 0x104) != '\0')) &&
             (piVar4 = *(int **)(*(int *)(iVar2 + 0x28) + 4), piVar4 != (int *)0x0)) {
            do {
              iVar2 = *piVar4;
              if (((((int)*(short *)(*(int *)(iVar2 + 8) + 0x12) == *(int *)(param_2 + 4)) &&
                   (*(char *)(iVar2 + 0x48) == '\x02')) &&
                  ((*(float *)(param_2 + 0xc) <= *(float *)(iVar2 + 0x38) &&
                   ((*(float *)(iVar2 + 0x38) <= *(float *)(param_2 + 0x14) &&
                    (*(float *)(param_2 + 0x10) <= *(float *)(iVar2 + 0x3c))))))) &&
                 (*(float *)(iVar2 + 0x3c) <= *(float *)(param_2 + 0x18))) {
                iStack_c = iStack_c + 1;
              }
              piVar4 = (int *)piVar4[1];
            } while (piVar4 != (int *)0x0);
          }
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < iVar6);
    }
  }
  if (iStack_c < *(int *)(param_2 + 0x1c)) {
    *(undefined1 *)(param_2 + 0x2e) = 0;
    return;
  }
  *(undefined1 *)(param_2 + 0x2e) = 2;
  return;
}

// --------------------------------------------------

// Function: FUN_005323a4
// Address: 005323a4
void FUN_005323a4(int param_1)
{
  if ((*(int *)(param_1 + 0x28) != 0) && (*(char *)(*(int *)(param_1 + 0x28) + 0x48) == '\a')) {
    *(undefined1 *)(param_1 + 0x2e) = 2;
    *(undefined4 *)(param_1 + 0x28) = 0;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_005323cf
// Address: 005323cf
void __thiscall FUN_005323cf(int param_1,int param_2)
{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  if (*(char *)(param_2 + 0x2e) == '\0') {
    if (*(int *)(param_2 + 8) == 0) {
      iVar2 = *(int *)(param_1 + 0xc);
      iVar4 = 0;
      piVar1 = *(int **)(*(int *)(iVar2 + 0x3c) + 0x40);
      if (0 < *(short *)(*(int *)(iVar2 + 0x3c) + 0x3c)) {
        do {
          if ((*(char *)(*(int *)(iVar2 + 0x84) + iVar4) != '\0') &&
             (piVar3 = *(int **)(*(int *)(*piVar1 + 0x28) + 4), piVar3 != (int *)0x0)) {
            do {
              if (((int)*(short *)(*(int *)(*piVar3 + 8) + 0x12) == *(int *)(param_2 + 4)) &&
                 (*(char *)(*piVar3 + 0x48) == '\a')) {
                *(int *)(param_2 + 0x20) = *(int *)(param_2 + 0x20) + 1;
              }
              piVar3 = (int *)piVar3[1];
            } while (piVar3 != (int *)0x0);
          }
          iVar2 = *(int *)(param_1 + 0xc);
          iVar4 = iVar4 + 1;
          piVar1 = piVar1 + 1;
        } while (iVar4 < *(short *)(*(int *)(iVar2 + 0x3c) + 0x3c));
      }
    }
    else {
      piVar1 = *(int **)(*(int *)(*(int *)(param_2 + 8) + 0x28) + 4);
      if (piVar1 != (int *)0x0) {
        do {
          if (((int)*(short *)(*(int *)(*piVar1 + 8) + 0x12) == *(int *)(param_2 + 4)) &&
             (*(char *)(*piVar1 + 0x48) == '\a')) {
            *(int *)(param_2 + 0x20) = *(int *)(param_2 + 0x20) + 1;
          }
          piVar1 = (int *)piVar1[1];
        } while (piVar1 != (int *)0x0);
      }
    }
    if (*(int *)(param_2 + 0x1c) <= *(int *)(param_2 + 0x20)) {
      *(undefined1 *)(param_2 + 0x2e) = 2;
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00532497
// Address: 00532497
void __thiscall FUN_00532497(int param_1,int param_2)
{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  
  if (*(int *)(param_2 + 8) == 0) {
    iVar1 = *(int *)(param_1 + 0xc);
    iVar4 = 0;
    iVar5 = (int)*(short *)(*(int *)(iVar1 + 0x3c) + 0x3c);
    piVar2 = *(int **)(*(int *)(iVar1 + 0x3c) + 0x40);
    if (0 < iVar5) {
      do {
        if (((*(char *)(iVar4 + *(int *)(iVar1 + 0x84)) != '\0') &&
            (iVar4 != *(short *)(iVar1 + 0x4a))) &&
           (piVar3 = *(int **)(*(int *)(*piVar2 + 0x28) + 4), piVar3 != (int *)0x0)) {
          do {
            if ((int)*(short *)(*(int *)(*piVar3 + 8) + 0x12) == *(int *)(param_2 + 4)) {
              *(undefined1 *)(param_2 + 0x2e) = 0;
              return;
            }
            piVar3 = (int *)piVar3[1];
          } while (piVar3 != (int *)0x0);
        }
        iVar4 = iVar4 + 1;
        piVar2 = piVar2 + 1;
      } while (iVar4 < iVar5);
      *(undefined1 *)(param_2 + 0x2e) = 2;
      return;
    }
  }
  else {
    piVar2 = *(int **)(*(int *)(*(int *)(param_2 + 8) + 0x28) + 4);
    if (piVar2 != (int *)0x0) {
      do {
        if ((int)*(short *)(*(int *)(*piVar2 + 8) + 0x12) == *(int *)(param_2 + 4)) {
          *(undefined1 *)(param_2 + 0x2e) = 0;
          return;
        }
        piVar2 = (int *)piVar2[1];
      } while (piVar2 != (int *)0x0);
      *(undefined1 *)(param_2 + 0x2e) = 2;
      return;
    }
  }
  *(undefined1 *)(param_2 + 0x2e) = 2;
  return;
}

// --------------------------------------------------

// Function: FUN_00532567
// Address: 00532567
void FUN_00532567(int param_1)
{
  if (*(int *)(param_1 + 8) != 0) {
    if (*(char *)(*(int *)(param_1 + 8) + 0x80) != '\x02') {
      *(undefined1 *)(param_1 + 0x2e) = 0;
      return;
    }
    *(undefined1 *)(param_1 + 0x2e) = 2;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00532597
// Address: 00532597
void FUN_00532597(int param_1)
{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x24);
  if (iVar1 == 0) {
    *(undefined1 *)(param_1 + 0x2e) = 3;
    return;
  }
  if (2 < *(byte *)(iVar1 + 0x48)) {
    if (*(char *)(param_1 + 0x2e) == '\0') {
      *(undefined1 *)(param_1 + 0x2e) = 1;
    }
    *(undefined4 *)(param_1 + 0x24) = 0;
    return;
  }
  if ((((*(float *)(param_1 + 0xc) <= *(float *)(iVar1 + 0x38)) &&
       (*(float *)(iVar1 + 0x38) <= *(float *)(param_1 + 0x14))) &&
      (*(float *)(param_1 + 0x10) <= *(float *)(iVar1 + 0x3c))) &&
     (*(float *)(iVar1 + 0x3c) <= *(float *)(param_1 + 0x18))) {
    *(undefined1 *)(param_1 + 0x2e) = 2;
    return;
  }
  *(undefined1 *)(param_1 + 0x2e) = 0;
  return;
}

// --------------------------------------------------

// Function: FUN_0053260f
// Address: 0053260f
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0053260f(int param_1)
{
  int iVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  
  iVar1 = *(int *)(param_1 + 0x24);
  if ((iVar1 == 0) || (iVar2 = *(int *)(param_1 + 0x28), iVar2 == 0)) {
    *(undefined1 *)(param_1 + 0x2e) = 3;
  }
  else {
    if ((*(byte *)(iVar1 + 0x48) < 3) && (*(byte *)(iVar2 + 0x48) < 3)) {
      fVar3 = *(float *)(iVar1 + 0x38) - *(float *)(iVar2 + 0x38);
      fVar4 = *(float *)(iVar1 + 0x3c) - *(float *)(iVar2 + 0x3c);
      if (fVar3 < _DAT_00577588) {
        fVar3 = -fVar3;
      }
      if (fVar4 < _DAT_00577588) {
        fVar4 = -fVar4;
      }
      if ((fVar3 <= (*(float *)(*(int *)(iVar2 + 8) + 0x30) + *(float *)(*(int *)(iVar1 + 8) + 0x30)
                    ) - _DAT_0057759c) &&
         (fVar4 <= (*(float *)(*(int *)(iVar2 + 8) + 0x34) + *(float *)(*(int *)(iVar1 + 8) + 0x34))
                   - _DAT_0057759c)) {
        *(undefined1 *)(param_1 + 0x2e) = 2;
        return;
      }
      *(undefined1 *)(param_1 + 0x2e) = 0;
      return;
    }
    *(undefined4 *)(param_1 + 0x24) = 0;
    *(undefined4 *)(param_1 + 0x28) = 0;
    if (*(char *)(param_1 + 0x2e) == '\0') {
      *(undefined1 *)(param_1 + 0x2e) = 1;
      return;
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0053279e
// Address: 0053279e
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0053279e(int param_1,int param_2)
{
  int iVar1;
  int iVar2;
  int *piVar3;
  float fVar4;
  
  if ((*(char *)(param_2 + 0x2e) == '\0') && (iVar1 = *(int *)(param_1 + 0xc), iVar1 != 0)) {
    if ((*(char *)(param_2 + 0x2d) == '\0') || (*(char *)(iVar1 + 0x104) == '\0')) {
      fVar4 = RGE_Visible_Map::percentExplored(*(RGE_Visible_Map **)(iVar1 + 0x38));
      if ((float)*(int *)(param_2 + 0x20) <= fVar4 * _DAT_005775a0) {
        *(undefined1 *)(param_2 + 0x2e) = 2;
      }
    }
    else {
      iVar2 = *(short *)(*(int *)(iVar1 + 0x3c) + 0x3c) + -1;
      if (-1 < iVar2) {
        piVar3 = (int *)(*(int *)(*(int *)(iVar1 + 0x3c) + 0x40) + iVar2 * 4);
        do {
          iVar1 = *(int *)(param_1 + 0xc);
          if ((((*(char *)(*(int *)(iVar1 + 0x84) + iVar2) == '\0') &&
               (*(char *)(*(int *)(*piVar3 + 0x84) + (int)*(short *)(iVar1 + 0x4a)) == '\0')) &&
              (*(char *)(*piVar3 + 0x104) != '\0')) || (iVar2 == *(short *)(iVar1 + 0x4a))) {
            fVar4 = RGE_Visible_Map::percentExplored(*(RGE_Visible_Map **)(*piVar3 + 0x38));
            if ((float)*(int *)(param_2 + 0x20) <= fVar4 * _DAT_005775a0) {
              *(undefined1 *)(param_2 + 0x2e) = 2;
              return;
            }
          }
          iVar2 = iVar2 + -1;
          piVar3 = piVar3 + -1;
        } while (-1 < iVar2);
        return;
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0053292a
// Address: 0053292a
void __thiscall FUN_0053292a(int param_1,undefined1 param_2,undefined1 param_3)
{
  int iVar1;
  
  iVar1 = calloc(1,0x34);
  if (iVar1 != 0) {
    *(undefined1 *)(iVar1 + 0x2e) = 0;
    *(undefined1 *)(iVar1 + 0x2c) = param_2;
    *(undefined1 *)(iVar1 + 0x2d) = param_3;
    *(undefined4 *)(iVar1 + 0x20) = 0;
    *(undefined4 *)(iVar1 + 0x30) = *(undefined4 *)(param_1 + 4);
    *(int *)(param_1 + 4) = iVar1;
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0053296d
// Address: 0053296d
undefined4 __thiscall
FUN_0053296d(RGE_Victory_Conditions *param_1,uchar param_2,RGE_Static_Object *param_3,uchar param_4)
{
  RGE_Victory_Entry *pRVar1;
  
  pRVar1 = RGE_Victory_Conditions::add(param_1,param_2,param_4);
  if (pRVar1 != (RGE_Victory_Entry *)0x0) {
    pRVar1->command = '\0';
    pRVar1->target_obj = param_3;
    pRVar1->target_player = param_3->owner;
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0053299d
// Address: 0053299d
undefined4 __thiscall
FUN_0053299d(RGE_Victory_Conditions *param_1,uchar param_2,long param_3,long param_4,uchar param_5)
{
  RGE_Victory_Entry *pRVar1;
  
  pRVar1 = RGE_Victory_Conditions::add(param_1,param_2,param_5);
  if (pRVar1 != (RGE_Victory_Entry *)0x0) {
    pRVar1->command = '\x01';
    pRVar1->obj_type = param_3;
    pRVar1->number = param_4;
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_005329ce
// Address: 005329ce
undefined4 __thiscall
FUN_005329ce(RGE_Victory_Conditions *param_1,uchar param_2,long param_3,long param_4,float param_5,
            float param_6,float param_7,float param_8,uchar param_9)
{
  RGE_Victory_Entry *pRVar1;
  
  pRVar1 = RGE_Victory_Conditions::add(param_1,param_2,param_9);
  if (pRVar1 != (RGE_Victory_Entry *)0x0) {
    pRVar1->obj_type = param_3;
    pRVar1->number = param_4;
    pRVar1->x0 = param_5;
    pRVar1->y0 = param_6;
    pRVar1->command = '\b';
    pRVar1->x1 = param_7;
    pRVar1->y1 = param_8;
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_00532a1a
// Address: 00532a1a
undefined4 __thiscall
FUN_00532a1a(RGE_Victory_Conditions *param_1,uchar param_2,RGE_Static_Object *param_3)
{
  RGE_Victory_Entry *pRVar1;
  
  pRVar1 = RGE_Victory_Conditions::add(param_1,param_2,'\0');
  if (pRVar1 != (RGE_Victory_Entry *)0x0) {
    pRVar1->command = '\x02';
    pRVar1->target_obj = param_3;
    pRVar1->target_player = param_3->owner;
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_00532a4a
// Address: 00532a4a
undefined4 __thiscall
FUN_00532a4a(RGE_Victory_Conditions *param_1,uchar param_2,long param_3,long param_4,
            RGE_Player *param_5)
{
  RGE_Victory_Entry *pRVar1;
  
  pRVar1 = RGE_Victory_Conditions::add(param_1,param_2,'\0');
  if (pRVar1 != (RGE_Victory_Entry *)0x0) {
    pRVar1->obj_type = param_3;
    pRVar1->command = '\x03';
    pRVar1->number = param_4;
    pRVar1->target_player = param_5;
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_00532a82
// Address: 00532a82
undefined4 __thiscall
FUN_00532a82(RGE_Victory_Conditions *param_1,uchar param_2,long param_3,RGE_Player *param_4)
{
  RGE_Victory_Entry *pRVar1;
  
  pRVar1 = RGE_Victory_Conditions::add(param_1,param_2,'\0');
  if (pRVar1 != (RGE_Victory_Entry *)0x0) {
    pRVar1->command = '\t';
    pRVar1->obj_type = param_3;
    pRVar1->target_player = param_4;
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_00532abb
// Address: 00532abb
undefined4 __thiscall
FUN_00532abb(RGE_Victory_Conditions *param_1,uchar param_2,RGE_Player *param_3)
{
  RGE_Victory_Entry *pRVar1;
  
  pRVar1 = RGE_Victory_Conditions::add(param_1,param_2,'\0');
  if (pRVar1 != (RGE_Victory_Entry *)0x0) {
    pRVar1->command = '\n';
    pRVar1->target_player = param_3;
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_00532ae4
// Address: 00532ae4
undefined4 __thiscall
FUN_00532ae4(RGE_Victory_Conditions *param_1,uchar param_2,RGE_Static_Object *param_3,
            RGE_Static_Object *param_4)
{
  RGE_Victory_Entry *pRVar1;
  
  pRVar1 = RGE_Victory_Conditions::add(param_1,param_2,'\0');
  if (pRVar1 != (RGE_Victory_Entry *)0x0) {
    pRVar1->command = '\x05';
    pRVar1->this_obj = param_3;
    pRVar1->target_obj = param_4;
    pRVar1->target_player = param_4->owner;
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_00532b21
// Address: 00532b21
undefined4 __thiscall
FUN_00532b21(RGE_Victory_Conditions *param_1,uchar param_2,RGE_Static_Object *param_3,float param_4,
            float param_5,float param_6,float param_7)
{
  RGE_Victory_Entry *pRVar1;
  
  pRVar1 = RGE_Victory_Conditions::add(param_1,param_2,'\0');
  if (pRVar1 != (RGE_Victory_Entry *)0x0) {
    pRVar1->this_obj = param_3;
    pRVar1->x0 = param_4;
    pRVar1->y0 = param_5;
    pRVar1->command = '\x04';
    pRVar1->x1 = param_6;
    pRVar1->y1 = param_7;
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_00532b9e
// Address: 00532b9e
undefined4 __thiscall
FUN_00532b9e(RGE_Victory_Conditions *param_1,uchar param_2,long param_3,uchar param_4)
{
  RGE_Victory_Entry *pRVar1;
  
  pRVar1 = RGE_Victory_Conditions::add(param_1,param_2,param_4);
  if (pRVar1 != (RGE_Victory_Entry *)0x0) {
    pRVar1->command = '\a';
    if (param_3 < 1) {
      param_3 = 1;
    }
    if (100 < param_3) {
      param_3 = 100;
    }
    pRVar1->count = param_3;
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_00532bdb
// Address: 00532bdb
undefined4 __thiscall
FUN_00532bdb(RGE_Victory_Conditions *param_1,uchar param_2,long param_3,uchar param_4)
{
  RGE_Victory_Entry *pRVar1;
  
  pRVar1 = RGE_Victory_Conditions::add(param_1,param_2,param_4);
  if (pRVar1 != (RGE_Victory_Entry *)0x0) {
    pRVar1->command = '\f';
    pRVar1->count = param_3;
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_00532c07
// Address: 00532c07
void __thiscall FUN_00532c07(int param_1,int param_2)
{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = *(int *)(param_1 + 4);
  puVar2 = (undefined4 *)(param_1 + 4);
  if (iVar1 != 0) {
    while (iVar1 != param_2) {
      puVar2 = (undefined4 *)(iVar1 + 0x30);
      iVar1 = *(int *)(iVar1 + 0x30);
      if (iVar1 == 0) {
        return;
      }
    }
    *puVar2 = *(undefined4 *)(iVar1 + 0x30);
    free(iVar1);
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -1;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00532c4c
// Address: 00532c4c
void __fastcall FUN_00532c4c(RGE_Victory_Conditions *param_1)
{
  RGE_Victory_Entry *pRVar1;
  
  pRVar1 = param_1->victory_list;
  while (pRVar1 != (RGE_Victory_Entry *)0x0) {
    RGE_Victory_Conditions::sub(param_1,pRVar1);
    pRVar1 = param_1->victory_list;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00532c6b
// Address: 00532c6b
undefined4 __thiscall FUN_00532c6b(int *param_1,undefined4 *param_2,undefined4 *param_3)
{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  
  puVar3 = (undefined1 *)param_1[1];
  puVar1 = (undefined4 *)0x0;
  if (puVar3 == (undefined1 *)0x0) {
    *param_3 = 0;
    return 0;
  }
  do {
    if (puVar1 == param_2) {
      uVar2 = (**(code **)(*param_1 + 8))(puVar3);
      *param_2 = uVar2;
      *(undefined1 *)param_3 = *puVar3;
      return 1;
    }
    puVar3 = *(undefined1 **)(puVar3 + 0x30);
    puVar1 = (undefined4 *)((int)puVar1 + 1);
  } while (puVar3 != (undefined1 *)0x0);
  *param_3 = 0;
  return 0;
}

// --------------------------------------------------

// Function: FUN_00532e9f
// Address: 00532e9f
/* WARNING: Control flow encountered bad instruction data */

void FUN_00532e9f(void)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

// --------------------------------------------------

// Function: FUN_00532eee
// Address: 00532eee
undefined4 __fastcall FUN_00532eee(int param_1)
{
  return *(undefined4 *)(param_1 + 8);
}

// --------------------------------------------------

// Function: FUN_00532ef6
// Address: 00532ef6
bool __fastcall FUN_00532ef6(int param_1)
{
  return *(char *)(param_1 + 0x10) == '\x02';
}

// --------------------------------------------------

// Function: FUN_00532f08
// Address: 00532f08
undefined4 __thiscall FUN_00532f08(RGE_Victory_Conditions *param_1,int param_2)
{
  RGE_Victory_Entry *pRVar1;
  int iVar2;
  
  pRVar1 = param_1->victory_list;
  iVar2 = 0;
  if (pRVar1 == (RGE_Victory_Entry *)0x0) {
    return 0;
  }
  do {
    if (iVar2 == param_2) {
      RGE_Victory_Conditions::sub(param_1,pRVar1);
      return 1;
    }
    pRVar1 = pRVar1->next;
    iVar2 = iVar2 + 1;
  } while (pRVar1 != (RGE_Victory_Entry *)0x0);
  return 0;
}

// --------------------------------------------------

// Function: FUN_00532f42
// Address: 00532f42
void __thiscall FUN_00532f42(int param_1,undefined1 param_2,undefined1 param_3)
{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)calloc(1,0x1c);
  if (puVar1 != (undefined1 *)0x0) {
    puVar1[1] = 0;
    *(undefined4 *)(puVar1 + 4) = 0xffffffff;
    *(undefined4 *)(puVar1 + 8) = 0;
    *puVar1 = 0xff;
    *(undefined4 *)(puVar1 + 0xc) = 0;
    *(undefined4 *)(puVar1 + 0x10) = 0;
    *(undefined4 *)(puVar1 + 0x18) = *(undefined4 *)(param_1 + 0x14);
    puVar1[2] = param_2;
    puVar1[3] = param_3;
    *(undefined1 **)(param_1 + 0x14) = puVar1;
    *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + 1;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00532f9d
// Address: 00532f9d
void __thiscall FUN_00532f9d(int param_1,int param_2)
{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = *(int *)(param_1 + 0x14);
  puVar2 = (undefined4 *)(param_1 + 0x14);
  if (iVar1 != 0) {
    while (iVar1 != param_2) {
      puVar2 = (undefined4 *)(iVar1 + 0x18);
      iVar1 = *(int *)(iVar1 + 0x18);
      if (iVar1 == 0) {
        return;
      }
    }
    *puVar2 = *(undefined4 *)(iVar1 + 0x18);
    free(iVar1);
    *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + -1;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00532fdc
// Address: 00532fdc
undefined4 __thiscall
FUN_00532fdc(RGE_Victory_Conditions *param_1,uchar param_2,uchar param_3,long param_4,long param_5,
            long param_6)
{
  RGE_Victory_Point_Entry *pRVar1;
  
  pRVar1 = RGE_Victory_Conditions::add_point(param_1,param_3,param_2);
  if (pRVar1 != (RGE_Victory_Point_Entry *)0x0) {
    pRVar1->attribute = param_4;
    pRVar1->command = '\0';
    pRVar1->amount = param_5;
    pRVar1->points = param_6;
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_00533015
// Address: 00533015
undefined4 __thiscall
FUN_00533015(RGE_Victory_Conditions *param_1,uchar param_2,uchar param_3,long param_4,long param_5,
            long param_6)
{
  RGE_Victory_Point_Entry *pRVar1;
  
  pRVar1 = RGE_Victory_Conditions::add_point(param_1,param_3,param_2);
  if (pRVar1 != (RGE_Victory_Point_Entry *)0x0) {
    pRVar1->attribute = param_4;
    pRVar1->command = '\x01';
    pRVar1->amount = param_5;
    pRVar1->points = param_6;
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_00533055
// Address: 00533055
undefined4 __thiscall
FUN_00533055(RGE_Victory_Conditions *param_1,uchar param_2,uchar param_3,long param_4,long param_5,
            long param_6)
{
  RGE_Victory_Point_Entry *pRVar1;
  
  pRVar1 = RGE_Victory_Conditions::add_point(param_1,param_3,param_2);
  if (pRVar1 != (RGE_Victory_Point_Entry *)0x0) {
    pRVar1->attribute = param_4;
    pRVar1->command = '\x02';
    pRVar1->amount = param_5;
    pRVar1->points = param_6;
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_00533095
// Address: 00533095
undefined4 __thiscall
FUN_00533095(RGE_Victory_Conditions *param_1,uchar param_2,uchar param_3,long param_4,long param_5,
            long param_6)
{
  RGE_Victory_Point_Entry *pRVar1;
  
  pRVar1 = RGE_Victory_Conditions::add_point(param_1,param_3,param_2);
  if (pRVar1 != (RGE_Victory_Point_Entry *)0x0) {
    pRVar1->attribute = param_4;
    pRVar1->command = '\x03';
    pRVar1->amount = param_5;
    pRVar1->points = param_6;
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_005330d5
// Address: 005330d5
undefined4 __thiscall
FUN_005330d5(RGE_Victory_Conditions *param_1,uchar param_2,uchar param_3,long param_4,long param_5,
            long param_6)
{
  RGE_Victory_Point_Entry *pRVar1;
  
  pRVar1 = RGE_Victory_Conditions::add_point(param_1,param_3,param_2);
  if (pRVar1 != (RGE_Victory_Point_Entry *)0x0) {
    pRVar1->attribute = param_4;
    pRVar1->command = '\x04';
    pRVar1->amount = param_5;
    pRVar1->points = param_6;
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_00533115
// Address: 00533115
void __thiscall FUN_00533115(int param_1,int param_2)
{
  int iVar1;
  int iVar2;
  
  if (*(char *)(param_2 + 1) == '\0') {
    iVar1 = __ftol();
    iVar2 = iVar1 / *(int *)(param_2 + 8);
    *(float *)(param_2 + 0x14) = (float)iVar1;
    if (iVar2 < 0) {
      iVar2 = 0;
    }
    iVar2 = *(int *)(param_2 + 0xc) * iVar2;
    if (iVar2 - *(int *)(param_2 + 0x10) != 0) {
      *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + (iVar2 - *(int *)(param_2 + 0x10));
      *(int *)(param_2 + 0x10) = iVar2;
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00533176
// Address: 00533176
void __thiscall FUN_00533176(int param_1,int param_2)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  
  if (*(char *)(param_2 + 1) == '\0') {
    iVar4 = *(int *)(param_1 + 0xc);
    iVar1 = *(int *)(param_2 + 4);
    iVar3 = __ftol();
    iVar2 = *(int *)(param_2 + 0xc);
    piVar5 = *(int **)(*(int *)(iVar4 + 0x3c) + 0x40);
    *(float *)(param_2 + 0x14) = (float)iVar3;
    if (*(int *)(param_2 + 8) <= iVar3) {
      iVar4 = 0;
      iVar3 = (int)*(short *)(*(int *)(*(int *)(param_1 + 0xc) + 0x3c) + 0x3c);
      if (0 < iVar3) {
        do {
          if ((iVar4 != *(short *)(*(int *)(param_1 + 0xc) + 0x4a)) &&
             ((float)*(int *)(param_2 + 8) <= *(float *)(*(int *)(*piVar5 + 0x50) + iVar1 * 4))) {
            *(undefined1 *)(param_2 + 1) = 1;
            return;
          }
          iVar4 = iVar4 + 1;
          piVar5 = piVar5 + 1;
        } while (iVar4 < iVar3);
      }
      *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + (iVar2 - *(int *)(param_2 + 0x10));
      *(int *)(param_2 + 0x10) = iVar2;
      *(undefined1 *)(param_2 + 1) = 2;
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0053323a
// Address: 0053323a
void __thiscall FUN_0053323a(int param_1,int param_2)
{
  int *piVar1;
  int iVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  float *pfVar7;
  int *piVar8;
  
  iVar4 = param_2;
  if (*(char *)(param_2 + 1) == '\0') {
    iVar2 = *(int *)(param_2 + 4);
    iVar5 = __ftol();
    piVar1 = (int *)(param_2 + 0xc);
    fVar3 = (float)iVar5;
    *(float *)(param_2 + 0x14) = fVar3;
    iVar6 = *(int *)(*(int *)(param_1 + 0xc) + 0x3c);
    piVar8 = *(int **)(iVar6 + 0x40);
    if (iVar5 < *(int *)(param_2 + 8)) {
      param_2 = 0;
    }
    else {
      iVar6 = (int)*(short *)(iVar6 + 0x3c);
      iVar5 = 1;
      param_2 = *piVar1;
      if (1 < iVar6) {
        do {
          piVar8 = piVar8 + 1;
          if (iVar5 != *(short *)(*(int *)(param_1 + 0xc) + 0x4a)) {
            pfVar7 = (float *)(*(int *)(*piVar8 + 0x50) + iVar2 * 4);
            if (fVar3 < *pfVar7) {
              param_2 = 0;
              break;
            }
            if (*pfVar7 == fVar3) {
              param_2 = *(int *)(iVar4 + 0x10);
            }
          }
          iVar5 = iVar5 + 1;
        } while (iVar5 < iVar6);
      }
    }
    if (param_2 != *(int *)(iVar4 + 0x10)) {
      *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + (param_2 - *(int *)(iVar4 + 0x10));
      *(int *)(iVar4 + 0x10) = param_2;
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00533326
// Address: 00533326
void __thiscall FUN_00533326(int param_1,int param_2)
{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  
  if (*(char *)(param_2 + 1) == '\0') {
    iVar4 = *(int *)(param_2 + 4);
    iVar1 = __ftol();
    if (*(float *)(param_2 + 0x14) < (float)iVar1) {
      *(float *)(param_2 + 0x14) = (float)iVar1;
    }
    iVar2 = *(int *)(param_1 + 0xc);
    iVar6 = 1;
    piVar5 = *(int **)(*(int *)(iVar2 + 0x3c) + 0x40);
    if (1 < *(short *)(*(int *)(iVar2 + 0x3c) + 0x3c)) {
      do {
        piVar5 = piVar5 + 1;
        if ((iVar6 != *(short *)(iVar2 + 0x4a)) &&
           ((float)*(int *)(param_2 + 8) <= *(float *)(*(int *)(*piVar5 + 0x50) + iVar4 * 4))) {
          uVar3 = __ftol();
          *(undefined4 *)(param_2 + 8) = uVar3;
        }
        iVar2 = *(int *)(param_1 + 0xc);
        iVar6 = iVar6 + 1;
      } while (iVar6 < *(short *)(*(int *)(iVar2 + 0x3c) + 0x3c));
    }
    if (*(float *)(param_2 + 0x14) < (float)*(int *)(param_2 + 8)) {
      if (iVar1 == *(int *)(param_2 + 8)) {
        iVar4 = *(int *)(param_2 + 0x10);
      }
      else {
        iVar4 = 0;
      }
    }
    else {
      iVar4 = *(int *)(param_2 + 0xc);
    }
    if (iVar4 != *(int *)(param_2 + 0x10)) {
      *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + (iVar4 - *(int *)(param_2 + 0x10));
      *(int *)(param_2 + 0x10) = iVar4;
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00533473
// Address: 00533473
undefined4 __fastcall FUN_00533473(int param_1)
{
  return *(undefined4 *)(param_1 + 0x1c);
}

// --------------------------------------------------

// Function: FUN_00533484
// Address: 00533484
int __thiscall FUN_00533484(int param_1,char param_2)
{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  for (iVar1 = *(int *)(param_1 + 0x14); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x18)) {
    if ((*(char *)(iVar1 + 3) == param_2) || (param_2 == -1)) {
      iVar2 = iVar2 + *(int *)(iVar1 + 0x10);
    }
  }
  return iVar2;
}

// --------------------------------------------------

// Function: FUN_005334b4
// Address: 005334b4
undefined4 __thiscall FUN_005334b4(int param_1,char param_2)
{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  for (iVar1 = *(int *)(param_1 + 0x14); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x18)) {
    if (*(char *)(iVar1 + 2) == param_2) {
      uVar2 = *(undefined4 *)(iVar1 + 0x10);
    }
  }
  return uVar2;
}

// --------------------------------------------------

// Function: FUN_005334df
// Address: 005334df
undefined4 __thiscall FUN_005334df(int param_1,char param_2)
{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  for (iVar1 = *(int *)(param_1 + 0x14); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x18)) {
    if (*(char *)(iVar1 + 2) == param_2) {
      uVar2 = __ftol();
    }
  }
  return uVar2;
}

// --------------------------------------------------

// Function: FUN_00533508
// Address: 00533508
RGE_View * __fastcall FUN_00533508(RGE_View *param_1)
{
  int *piVar1;
  DisplaySelectedObjRec *pDVar2;
  int iVar3;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00561b08;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  TPanel::TPanel((TPanel *)param_1);
  param_1->_padding_ = (int)&RGE_View::_vftable_;
  param_1->cur_render_area = (TDrawArea *)0x0;
  param_1->calc_draw_count = 0;
  param_1->world = (RGE_Game_World *)0x0;
  param_1->player = (RGE_Player *)0x0;
  param_1->map = (RGE_Map *)0x0;
  param_1->tile_wid = 0;
  param_1->tile_hgt = 0;
  param_1->tile_half_hgt = 0;
  param_1->tile_half_wid = 0;
  param_1->elev_hgt = 0;
  param_1->max_col_num = 0;
  param_1->max_row_num = 0;
  param_1->center_scr_col = 0;
  param_1->center_scr_row = 0;
  param_1->center_scr_col_offset = 0;
  param_1->center_scr_row_offset = 0;
  param_1->center_map_col = 0;
  param_1->center_map_row = 0;
  param_1->start_scr_col = 0;
  param_1->start_scr_row = 0;
  param_1->start_map_col = 0;
  param_1->start_map_row = 0;
  param_1->map_scr_x_offset = 0;
  param_1->map_scr_y_offset = 0;
  param_1->last_view_x = -9999.0;
  param_1->last_view_y = -9999.0;
  param_1->function_mode = '\0';
  param_1->render_terrain_mode = '\0';
  param_1->save_area1 = (TDrawArea *)0x0;
  param_1->save_paint_terrain = -1;
  param_1->white_pen = (void *)0x0;
  param_1->red_pen = (void *)0x0;
  param_1->hollow_brush = (void *)0x0;
  param_1->border_line_shape = (TShape *)0x0;
  param_1->scroll_action = '\0';
  uStack_4 = 0;
  param_1->mouse_last_x = -1;
  param_1->mouse_last_y = -1;
  param_1->movable_object = (RGE_Static_Object *)0x0;
  RGE_View::set_selection_area(param_1,-1,-1,-1,-1);
  param_1->Terrain_Clip_Mask = (TSpan_List_Manager *)0x0;
  param_1->Terrain_Fog_Clip_Mask = (TSpan_List_Manager *)0x0;
  param_1->Master_Clip_Mask = (TSpan_List_Manager *)0x0;
  param_1->LastRenderBits = (uchar *)0x0;
  param_1->RenderOffsets = (void **)0x0;
  param_1->LastRenderSize = 0;
  param_1->Tile_Edge_Tables = (Tile_FogEdge_Table **)0x0;
  param_1->Black_Edge_Tables = (Tile_BlackEdge_Table **)0x0;
  param_1->Float_X_Delta = 0;
  param_1->Float_Y_Delta = 0;
  param_1->Float_Scroll_Offsets = (void **)0x0;
  param_1->Float_Scroll_Offsets_Sz = 0;
  param_1->Queued_Blits = 0;
  param_1->Blit_Queue = (Blit_Queue_Entry *)0x0;
  param_1->Blit_Queue_Size = 0;
  param_1->Current_Blit = 0;
  param_1->Blit_Offset_X = 0;
  param_1->Blit_Offset_Y = 0;
  param_1->prior_objs = (DClipInfo_List *)0x0;
  param_1->futur_objs = (DClipInfo_List *)0x0;
  piVar1 = param_1->pick_list_size;
  iVar3 = 5;
  do {
    piVar1[-5] = 0;
    *piVar1 = 0;
    piVar1 = piVar1 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  param_1->UC_ObjectTouched = 0;
  param_1->UC_TouchedObj = -0x80000000;
  param_1->UC_StartTime = 0;
  param_1->UC_ElapsedTime = 0;
  param_1->message_panel = (TMessagePanel *)0x0;
  param_1->extra_sprites = (Ov_Sprite_Draw_Rec *)0x0;
  param_1->DispSel_List_Size = 0;
  param_1->DispSel_List_Max = 8;
  pDVar2 = (DisplaySelectedObjRec *)calloc(8,0x14);
  param_1->DispSel_List = pDVar2;
  *unaff_FS_OFFSET = uStack_c;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_00533733
// Address: 00533733
RGE_View * __thiscall FUN_00533733(RGE_View *param_1,byte param_2)
{
  RGE_View::~RGE_View(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0053375e
// Address: 0053375e
void __fastcall FUN_0053375e(RGE_View *param_1)
{
  TShape *this;
  TSpan_List_Manager *pTVar1;
  DClipInfo_List *pDVar2;
  int iVar3;
  RGE_SPick_Info **ppRVar4;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  pcStack_8 = FUN_00561b28;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  param_1->_padding_ = (int)&RGE_View::_vftable_;
  this = param_1->border_line_shape;
  uStack_4 = 0;
  if (this != (TShape *)0x0) {
    TShape::~TShape(this);
    operator_delete(this);
    param_1->border_line_shape = (TShape *)0x0;
  }
  RGE_View::delete_surfaces(param_1);
  if (param_1->red_pen != (void *)0x0) {
    DeleteObject(param_1->red_pen);
    param_1->red_pen = (void *)0x0;
  }
  if (param_1->RenderOffsets != (void **)0x0) {
    free(param_1->RenderOffsets);
  }
  pTVar1 = param_1->Terrain_Clip_Mask;
  if (pTVar1 != (TSpan_List_Manager *)0x0) {
    TSpan_List_Manager::~TSpan_List_Manager(pTVar1);
    operator_delete(pTVar1);
  }
  pTVar1 = param_1->Terrain_Fog_Clip_Mask;
  if (pTVar1 != (TSpan_List_Manager *)0x0) {
    TSpan_List_Manager::~TSpan_List_Manager(pTVar1);
    operator_delete(pTVar1);
  }
  pTVar1 = param_1->Master_Clip_Mask;
  if (pTVar1 != (TSpan_List_Manager *)0x0) {
    TSpan_List_Manager::~TSpan_List_Manager(pTVar1);
    operator_delete(pTVar1);
  }
  if (param_1->Tile_Edge_Tables != (Tile_FogEdge_Table **)0x0) {
    free(param_1->Tile_Edge_Tables);
  }
  if (param_1->Black_Edge_Tables != (Tile_BlackEdge_Table **)0x0) {
    free(param_1->Black_Edge_Tables);
  }
  if (param_1->Float_Scroll_Offsets != (void **)0x0) {
    free(param_1->Float_Scroll_Offsets);
  }
  if (param_1->Blit_Queue != (Blit_Queue_Entry *)0x0) {
    free(param_1->Blit_Queue);
  }
  pDVar2 = param_1->prior_objs;
  if (pDVar2 != (DClipInfo_List *)0x0) {
    DClipInfo_List::~DClipInfo_List(pDVar2);
    operator_delete(pDVar2);
  }
  pDVar2 = param_1->futur_objs;
  if (pDVar2 != (DClipInfo_List *)0x0) {
    DClipInfo_List::~DClipInfo_List(pDVar2);
    operator_delete(pDVar2);
  }
  ppRVar4 = param_1->pick_lists;
  iVar3 = 5;
  do {
    if (*ppRVar4 != (RGE_SPick_Info *)0x0) {
      free(*ppRVar4);
    }
    ppRVar4 = ppRVar4 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  if (MouseSystem != (TMousePointer *)0x0) {
    TMousePointer::set_game_mode(MouseSystem,0);
    TMousePointer::set_game_enable(MouseSystem,0);
  }
  if (param_1->DispSel_List != (DisplaySelectedObjRec *)0x0) {
    free(param_1->DispSel_List);
  }
  RGE_View::reset_overlay_sprites(param_1);
  TPanel::~TPanel((TPanel *)param_1);
  uStack_4 = 0xffffffff;
  TPanel::~TPanel((TPanel *)param_1);
  *unaff_FS_OFFSET = uStack_c;
  return;
}

// --------------------------------------------------

// Function: FUN_00533934
// Address: 00533934
// [HELPER] s__s_shp: "%s.shp"
undefined4 __thiscall
FUN_00533934(RGE_View *param_1,TDrawArea *param_2,TPanel *param_3,long param_4,long param_5,
            long param_6,long param_7,uchar param_8,int param_9,undefined4 param_10)
{
  void *pvVar1;
  TShape *pTVar2;
  RGE_SPick_Info *pRVar3;
  int *piVar4;
  int iVar5;
  undefined4 *unaff_FS_OFFSET;
  char acStack_110 [260];
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00561b4e;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  TPanel::setup((TPanel *)param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  param_1->cur_render_area = (TDrawArea *)0x0;
  param_1->calc_draw_count = param_9;
  param_1->start_scr_col = 0;
  param_1->start_scr_row = 0;
  param_1->start_map_col = 0;
  param_1->start_map_row = 0;
  param_1->last_view_x = -9999.0;
  param_1->last_view_y = -9999.0;
  param_1->function_mode = '\0';
  pvVar1 = (void *)GetStockObject(6);
  param_1->white_pen = pvVar1;
  pvVar1 = (void *)CreatePen(0,1,0xff);
  param_1->red_pen = pvVar1;
  pvVar1 = (void *)GetStockObject(5);
  param_1->hollow_brush = pvVar1;
  sprintf(acStack_110,s__s_shp,param_10);
  pTVar2 = (TShape *)operator_new(0x20);
  uStack_4 = 0;
  if (pTVar2 == (TShape *)0x0) {
    pTVar2 = (TShape *)0x0;
  }
  else {
    pTVar2 = (TShape *)TShape::TShape(pTVar2,acStack_110,-1);
  }
  uStack_4 = 0xffffffff;
  param_1->border_line_shape = pTVar2;
  RGE_View::Init_Tile_Edge_Tables(param_1);
  piVar4 = param_1->pick_list_size;
  iVar5 = 5;
  do {
    pRVar3 = (RGE_SPick_Info *)calloc(0x40,0x14);
    piVar4[-5] = (int)pRVar3;
    *piVar4 = 0;
    piVar4 = piVar4 + 1;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  *unaff_FS_OFFSET = uStack_c;
  return 1;
}

// --------------------------------------------------

// Function: FUN_00533ab3
// Address: 00533ab3
void __thiscall FUN_00533ab3(TPanel *param_1,int param_2)
{
  TPanel::set_focus(param_1,param_2);
  if (MouseSystem != (TMousePointer *)0x0) {
    TMousePointer::set_game_enable(MouseSystem,param_1->have_focus);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00533ae4
// Address: 00533ae4
// [HELPER] s_DATA2_BLKEDGE_DAT: "DATA2\BLKEDGE.DAT"
// [HELPER] s_DATA2_TILEEDGE_DAT: "DATA2\TILEEDGE.DAT"
void __fastcall FUN_00533ae4(int param_1)
{
  byte bVar1;
  bool bVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  char cVar8;
  int *piVar9;
  uint uVar10;
  uint uVar11;
  undefined4 *puVar12;
  int iVar13;
  uint uVar14;
  undefined4 *puVar15;
  uint uVar16;
  bool bVar17;
  bool bVar18;
  bool bVar19;
  bool bVar20;
  
  iVar3 = __open(s_DATA2_TILEEDGE_DAT,0x8000);
  if (iVar3 != -1) {
    lseek(iVar3,0,2);
    uVar4 = __tell(iVar3);
    uVar5 = calloc(1,uVar4);
    *(undefined4 *)(param_1 + 0x184) = uVar5;
    lseek(iVar3,0,0);
    read(iVar3,*(undefined4 *)(param_1 + 0x184),uVar4);
    close(iVar3);
    iVar3 = *(int *)(param_1 + 0x184);
    iVar6 = 0;
    do {
      piVar9 = (int *)(*(int *)(param_1 + 0x184) + iVar6);
      iVar6 = iVar6 + 4;
      *piVar9 = *piVar9 + iVar3;
    } while (iVar6 < 0x44);
    iVar6 = 0;
    do {
      iVar13 = 0x2f;
      piVar9 = *(int **)(iVar6 + *(int *)(param_1 + 0x184));
      do {
        if (*piVar9 != 0) {
          *piVar9 = *piVar9 + iVar3;
        }
        if (piVar9[1] != 0) {
          piVar9[1] = piVar9[1] + iVar3;
        }
        piVar9 = piVar9 + 2;
        iVar13 = iVar13 + -1;
      } while (iVar13 != 0);
      iVar6 = iVar6 + 4;
    } while (iVar6 < 0x44);
  }
  iVar3 = __open(s_DATA2_BLKEDGE_DAT,0x8000);
  if (iVar3 != -1) {
    lseek(iVar3,0,2);
    uVar4 = __tell(iVar3);
    uVar5 = calloc(1,uVar4);
    *(undefined4 *)(param_1 + 0x188) = uVar5;
    lseek(iVar3,0,0);
    read(iVar3,*(undefined4 *)(param_1 + 0x188),uVar4);
    close(iVar3);
    iVar3 = *(int *)(param_1 + 0x188);
    iVar6 = 0;
    do {
      piVar9 = (int *)(*(int *)(param_1 + 0x188) + iVar6);
      iVar6 = iVar6 + 4;
      *piVar9 = *piVar9 + iVar3;
    } while (iVar6 < 0x44);
    iVar6 = 0;
    do {
      piVar9 = *(int **)(iVar6 + *(int *)(param_1 + 0x188));
      iVar13 = 0x2f;
      do {
        if (*piVar9 != 0) {
          *piVar9 = *piVar9 + iVar3;
        }
        piVar9 = piVar9 + 1;
        iVar13 = iVar13 + -1;
      } while (iVar13 != 0);
      iVar6 = iVar6 + 4;
    } while (iVar6 < 0x44);
  }
  puVar12 = (undefined4 *)(param_1 + 0x1a0);
  puVar15 = puVar12;
  for (iVar3 = 0x40; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar15 = 0xffffffff;
    puVar15 = puVar15 + 1;
  }
  iVar3 = 0;
  cVar8 = '\0';
  do {
    bVar2 = true;
    bVar1 = (byte)iVar3;
    bVar17 = (bVar1 & 1) == 1;
    bVar18 = (bVar1 & 2) == 2;
    bVar19 = (bVar1 & 4) == 4;
    bVar20 = (bVar1 & 8) == 8;
    if (((bVar1 & 0x80) == 0x80) && ((bVar17 || (bVar20)))) {
      bVar2 = false;
    }
    if (((bVar1 & 0x40) == 0x40) && ((bVar19 || (bVar20)))) {
      bVar2 = false;
    }
    if (((bVar1 & 0x20) == 0x20) && ((bVar18 || (bVar19)))) {
      bVar2 = false;
    }
    if (((bVar1 & 0x10) == 0x10) && ((bVar17 || (bVar18)))) {
      bVar2 = false;
    }
    if (bVar2) {
      *(char *)(iVar3 + (int)puVar12) = cVar8;
      cVar8 = cVar8 + '\x01';
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < 0x100);
  uVar7 = 0;
  do {
    if (*(char *)(uVar7 + (int)puVar12) == -1) {
      uVar14 = uVar7 & 1;
      uVar10 = uVar7 & 2;
      uVar16 = uVar7 & 4;
      uVar11 = uVar7 & 8;
      if ((uVar7 & 0x80) != 0) {
        uVar11 = 0;
        uVar14 = 0;
      }
      if ((uVar7 & 0x40) != 0) {
        uVar11 = 0;
        uVar16 = 0;
      }
      if ((uVar7 & 0x20) != 0) {
        uVar16 = 0;
        uVar10 = 0;
      }
      if ((uVar7 & 0x10) != 0) {
        uVar10 = 0;
        uVar14 = 0;
      }
      *(undefined1 *)(uVar7 + (int)puVar12) =
           *(undefined1 *)((uVar7 & 0xf0 | uVar11 | uVar16 | uVar10 | uVar14) + (int)puVar12);
    }
    uVar7 = uVar7 + 1;
  } while ((int)uVar7 < 0x100);
  return;
}

// --------------------------------------------------

// Function: FUN_00533e0f
// Address: 00533e0f
// [HELPER] s_C__msdev_work_age1_x1_view_cpp: "C:\msdev\work\age1_x1\view.cpp"
void __fastcall FUN_00533e0f(int param_1)
{
  int iVar1;
  ulong uVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  
  uVar2 = debug_timeGetTime(s_C__msdev_work_age1_x1_view_cpp,0x2cb);
  iVar5 = 0;
  if (0 < *(int *)(param_1 + 0x35c)) {
    iVar4 = 0;
    do {
      piVar3 = (int *)(*(int *)(param_1 + 0x354) + iVar4);
      if (*piVar3 != 0) {
        iVar1 = *(int *)(*(int *)(*(int *)(param_1 + 0xfc) + 0x88) + piVar3[1] * 4);
        if (iVar1 == 0) {
          *piVar3 = 0;
          *(int *)(param_1 + 0x358) = *(int *)(param_1 + 0x358) + -1;
        }
        else {
          if ((uint)piVar3[3] < uVar2 - piVar3[2]) {
            *piVar3 = 0;
            *(int *)(param_1 + 0x358) = *(int *)(param_1 + 0x358) + -1;
          }
          else if ((uVar2 - piVar3[2] & 0x100) == 0) {
            *(byte *)(iVar1 + 0x36) = *(byte *)(iVar1 + 0x36) | *(byte *)(piVar3 + 4);
            goto LAB_00533e8f;
          }
          *(byte *)(iVar1 + 0x36) = *(byte *)(iVar1 + 0x36) & ~*(byte *)(piVar3 + 4);
        }
      }
LAB_00533e8f:
      iVar5 = iVar5 + 1;
      iVar4 = iVar4 + 0x14;
    } while (iVar5 < *(int *)(param_1 + 0x35c));
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00533eb2
// Address: 00533eb2
// [HELPER] s_C__msdev_work_age1_x1_view_cpp: "C:\msdev\work\age1_x1\view.cpp"
void __thiscall FUN_00533eb2(int param_1,int param_2,int param_3,int param_4,int *param_5)
{
  bool bVar1;
  int *piVar2;
  ulong uVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  
  bVar1 = false;
  iVar5 = 0;
  piVar6 = param_5;
  if (0 < *(int *)(param_1 + 0x35c)) {
    iVar4 = 0;
    do {
      piVar2 = (int *)(*(int *)(param_1 + 0x354) + iVar4);
      if (*piVar2 == 0) {
        bVar1 = true;
        piVar6 = piVar2;
      }
      else if ((param_5 != (int *)0x0) && ((int *)piVar2[4] == param_5)) {
        piVar2[2] = piVar2[2] - piVar2[3];
      }
      iVar5 = iVar5 + 1;
      iVar4 = iVar4 + 0x14;
    } while (iVar5 < *(int *)(param_1 + 0x35c));
  }
  if (bVar1) {
    *piVar6 = 1;
    piVar6[1] = param_2;
    uVar3 = debug_timeGetTime(s_C__msdev_work_age1_x1_view_cpp,0x31d);
    piVar6[2] = uVar3;
    piVar6[3] = param_3;
    piVar6[4] = param_4;
    *(int *)(param_1 + 0x358) = *(int *)(param_1 + 0x358) + 1;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00533f63
// Address: 00533f63
void __thiscall FUN_00533f63(RGE_View *param_1,long param_2,int param_3,int param_4,int param_5)
{
  TSpan_List_Manager *pTVar1;
  undefined4 unaff_EBX;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00561b81;
  *unaff_FS_OFFSET = &uStack_c;
  TPanel::set_rect((TPanel *)param_1,param_2,param_3,param_4,param_5);
  RGE_View::calc_draw_vars(param_1);
  RGE_View::create_surfaces(param_1);
  pTVar1 = param_1->Terrain_Clip_Mask;
  param_1->last_view_x = -9999.0;
  param_1->last_view_y = -9999.0;
  if (pTVar1 != (TSpan_List_Manager *)0x0) {
    TSpan_List_Manager::~TSpan_List_Manager(pTVar1);
    operator_delete(pTVar1);
  }
  pTVar1 = param_1->Terrain_Fog_Clip_Mask;
  if (pTVar1 != (TSpan_List_Manager *)0x0) {
    TSpan_List_Manager::~TSpan_List_Manager(pTVar1);
    operator_delete(pTVar1);
  }
  pTVar1 = param_1->Master_Clip_Mask;
  if (pTVar1 != (TSpan_List_Manager *)0x0) {
    TSpan_List_Manager::~TSpan_List_Manager(pTVar1);
    operator_delete(pTVar1);
  }
  pTVar1 = (TSpan_List_Manager *)operator_new(0x68);
  uStack_4 = 0;
  if (pTVar1 == (TSpan_List_Manager *)0x0) {
    pTVar1 = (TSpan_List_Manager *)0x0;
  }
  else {
    pTVar1 = (TSpan_List_Manager *)TSpan_List_Manager::TSpan_List_Manager(pTVar1,param_4,param_5);
  }
  uStack_4 = 0xffffffff;
  param_1->Terrain_Clip_Mask = pTVar1;
  pTVar1 = (TSpan_List_Manager *)operator_new(0x68);
  uStack_4 = 1;
  if (pTVar1 == (TSpan_List_Manager *)0x0) {
    pTVar1 = (TSpan_List_Manager *)0x0;
  }
  else {
    pTVar1 = (TSpan_List_Manager *)TSpan_List_Manager::TSpan_List_Manager(pTVar1,param_4,param_5);
  }
  uStack_4 = 0xffffffff;
  param_1->Terrain_Fog_Clip_Mask = pTVar1;
  pTVar1 = (TSpan_List_Manager *)operator_new(0x68);
  uStack_4 = 2;
  if (pTVar1 == (TSpan_List_Manager *)0x0) {
    pTVar1 = (TSpan_List_Manager *)0x0;
  }
  else {
    pTVar1 = (TSpan_List_Manager *)TSpan_List_Manager::TSpan_List_Manager(pTVar1,param_4,param_5);
  }
  param_1->Master_Clip_Mask = pTVar1;
  uStack_4 = 0xffffffff;
  if (((MouseSystem != (TMousePointer *)0x0) && (0 < param_4)) && (0 < param_5)) {
    TMousePointer::set_game_window(MouseSystem,param_2,param_3,param_4 + param_2,param_5 + param_3);
    TMousePointer::set_game_mode(MouseSystem,1);
  }
  (**(code **)(param_1->_padding_ + 0x20))(2);
  *unaff_FS_OFFSET = unaff_EBX;
  return;
}

// --------------------------------------------------

// Function: FUN_005340fb
// Address: 005340fb
void __fastcall FUN_005340fb(int param_1)
{
  TDrawArea *this;
  
  this = *(TDrawArea **)(param_1 + 0x324);
  if (this != (TDrawArea *)0x0) {
    TDrawArea::~TDrawArea(this);
    operator_delete(this);
    *(undefined4 *)(param_1 + 0x324) = 0;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0053412b
// Address: 0053412b
// [HELPER] s_Terrain_Buffer: "Terrain Buffer"
bool __fastcall FUN_0053412b(int param_1)
{
  TDrawArea *pTVar1;
  DClipInfo_List *pDVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *unaff_FS_OFFSET;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00561bb1;
  uStack_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &uStack_c;
  if ((*(int *)(param_1 + 0x14) == 0) && (*(int *)(param_1 + 0x18) == 0)) {
    *unaff_FS_OFFSET = uStack_c;
    return true;
  }
  if (*(int *)(param_1 + 0x324) == 0) {
    pTVar1 = (TDrawArea *)operator_new(0x100);
    uStack_4 = 0;
    if (pTVar1 == (TDrawArea *)0x0) {
      pTVar1 = (TDrawArea *)0x0;
    }
    else {
      pTVar1 = (TDrawArea *)TDrawArea::TDrawArea(pTVar1,s_Terrain_Buffer,0);
    }
    uStack_4 = 0xffffffff;
    *(TDrawArea **)(param_1 + 0x324) = pTVar1;
    if (pTVar1 != (TDrawArea *)0x0) {
      TDrawArea::Init(pTVar1,(TDrawSystem *)**(undefined4 **)(param_1 + 0x20),
                      *(long *)(param_1 + 0x14),*(long *)(param_1 + 0x18),1,0);
    }
  }
  if ((*(TDrawArea **)(param_1 + 0x324) != (TDrawArea *)0x0) && (0 < *(int *)(param_1 + 0x18))) {
    TDrawArea::SetSize(*(TDrawArea **)(param_1 + 0x324),*(long *)(param_1 + 0x14),
                       *(int *)(param_1 + 0x18),1);
    *(undefined4 *)(param_1 + 0x2d0) = 0;
    *(undefined4 *)(param_1 + 0x2d4) = 0;
    TDrawArea::SetFloatOffsets(*(TDrawArea **)(param_1 + 0x324),0,0);
    pDVar2 = *(DClipInfo_List **)(param_1 + 0x334);
    if (pDVar2 != (DClipInfo_List *)0x0) {
      DClipInfo_List::~DClipInfo_List(pDVar2);
      operator_delete(pDVar2);
    }
    pDVar2 = *(DClipInfo_List **)(param_1 + 0x338);
    if (pDVar2 != (DClipInfo_List *)0x0) {
      DClipInfo_List::~DClipInfo_List(pDVar2);
      operator_delete(pDVar2);
    }
    iVar4 = *(int *)(param_1 + 0x18) + 0x1c2;
    pDVar2 = (DClipInfo_List *)operator_new(0x70);
    uStack_4 = 1;
    if (pDVar2 == (DClipInfo_List *)0x0) {
      uVar3 = 0;
    }
    else {
      uVar3 = DClipInfo_List::DClipInfo_List
                        (pDVar2,iVar4 * 2,iVar4,0x40,-200,*(int *)(param_1 + 0x18) + 0xf9,0x28);
    }
    uStack_4 = 0xffffffff;
    *(undefined4 *)(param_1 + 0x334) = uVar3;
    pDVar2 = (DClipInfo_List *)operator_new(0x70);
    uStack_4 = 2;
    if (pDVar2 == (DClipInfo_List *)0x0) {
      uVar3 = 0;
    }
    else {
      uVar3 = DClipInfo_List::DClipInfo_List
                        (pDVar2,iVar4 * 2,iVar4,0x40,-200,*(int *)(param_1 + 0x18) + 0xf9,0x28);
    }
    *(undefined4 *)(param_1 + 0x338) = uVar3;
    uStack_4 = 0xffffffff;
    DClipInfo_List::SetDrawRegion
              (*(DClipInfo_List **)(param_1 + 0x334),0,0,*(int *)(param_1 + 0x14) + -1,
               *(int *)(param_1 + 0x18) + -1);
    DClipInfo_List::SetDrawRegion
              (*(DClipInfo_List **)(param_1 + 0x338),0,0,*(int *)(param_1 + 0x14) + -1,
               *(int *)(param_1 + 0x18) + -1);
  }
  iVar4 = *(int *)(param_1 + 0x324);
  *unaff_FS_OFFSET = uStack_c;
  return iVar4 != 0;
}

// --------------------------------------------------

// Function: FUN_0053433d
// Address: 0053433d
void __fastcall FUN_0053433d(int param_1)
{
  if (((*(int *)(param_1 + 0x70) != 0) && (*(short *)(param_1 + 0x108) != 0)) &&
     (*(short *)(param_1 + 0x10a) != 0)) {
    *(undefined2 *)(param_1 + 0x11e) = 0;
    *(undefined2 *)(param_1 + 0x120) = 0;
    *(short *)(param_1 + 0x116) =
         (short)(*(int *)(param_1 + 0x14) / (int)*(short *)(param_1 + 0x108));
    *(short *)(param_1 + 0x118) =
         (short)(*(int *)(param_1 + 0x18) / (int)*(short *)(param_1 + 0x10a));
    *(short *)(param_1 + 0x11a) =
         (*(short *)(param_1 + 0x8c) - *(short *)(param_1 + 0x10c)) +
         (short)(*(int *)(param_1 + 0x14) / 2);
    *(short *)(param_1 + 0x11c) =
         (*(short *)(param_1 + 0x90) - *(short *)(param_1 + 0x10e)) +
         (short)(*(int *)(param_1 + 0x18) / 2);
    return;
  }
  *(undefined2 *)(param_1 + 0x118) = 0;
  *(undefined2 *)(param_1 + 0x116) = 0;
  *(undefined2 *)(param_1 + 0x11a) = 0;
  *(undefined2 *)(param_1 + 0x11c) = 0;
  *(undefined2 *)(param_1 + 0x122) = 0;
  *(undefined2 *)(param_1 + 0x124) = 0;
  *(undefined2 *)(param_1 + 0x11e) = 0;
  *(undefined2 *)(param_1 + 0x120) = 0;
  return;
}

// --------------------------------------------------

// Function: FUN_00534419
// Address: 00534419
void __thiscall FUN_00534419(TPanel *param_1,RedrawMode param_2)
{
  TPanel::set_redraw(param_1,param_2);
  if (param_2 == RedrawFull) {
    *(undefined1 *)((int)&param_1[1].right_panel + 2) = 0;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0053443f
// Address: 0053443f
void __thiscall FUN_0053443f(RGE_View *param_1,RGE_Game_World *param_2)
{
  RGE_Map *pRVar1;
  
  param_1->world = param_2;
  if (param_2 != (RGE_Game_World *)0x0) {
    pRVar1 = param_2->map;
    param_1->map = pRVar1;
    RGE_Map::coordinate_map(pRVar1);
    pRVar1 = param_1->map;
    param_1->tile_wid = pRVar1->tile_width;
    param_1->tile_hgt = pRVar1->tile_height;
    param_1->tile_half_wid = pRVar1->tile_half_width;
    param_1->tile_half_hgt = pRVar1->tile_half_height;
    param_1->elev_hgt = pRVar1->elev_height;
    RGE_View::calc_draw_vars(param_1);
    return;
  }
  param_1->map = (RGE_Map *)0x0;
  param_1->tile_wid = 0;
  param_1->tile_hgt = 0;
  param_1->tile_half_wid = 0;
  param_1->tile_half_hgt = 0;
  param_1->elev_hgt = 0;
  RGE_View::calc_draw_vars(param_1);
  return;
}

// --------------------------------------------------

// Function: FUN_005344f4
// Address: 005344f4
void __thiscall FUN_005344f4(int *param_1,int param_2)
{
  param_1[0x40] = param_2;
  param_1[0x4e] = -0x39e3c400;
  param_1[0x4f] = -0x39e3c400;
  (**(code **)(*param_1 + 0x20))(2);
  return;
}

// --------------------------------------------------

// Function: FUN_00534525
// Address: 00534525
void __thiscall FUN_00534525(int *param_1,int param_2,int param_3,int param_4,int param_5)
{
  if (((RGE_Map *)param_1[0x41] != (RGE_Map *)0x0) && (rge_base_game->game_mode != 0x15)) {
    RGE_Map::request_redraw
              ((RGE_Map *)param_1[0x41],param_1[0x51],param_1[0x52],param_1[0x53],param_1[0x54],'\0'
              );
  }
  param_1[0x51] = param_2;
  param_1[0x52] = param_3;
  param_1[0x53] = param_4;
  param_1[0x54] = param_5;
  if (((RGE_Map *)param_1[0x41] != (RGE_Map *)0x0) && (rge_base_game->game_mode != 0x15)) {
    RGE_Map::request_redraw((RGE_Map *)param_1[0x41],param_2,param_3,param_4,param_5,'\x10');
  }
  (**(code **)(*param_1 + 0x20))(1);
  return;
}

// --------------------------------------------------

// Function: FUN_005345cd
// Address: 005345cd
undefined4 __thiscall
FUN_005345cd(int param_1,int *param_2,int *param_3,int *param_4,int *param_5,int param_6)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  *param_2 = *(int *)(param_1 + 0x144);
  *param_3 = *(int *)(param_1 + 0x148);
  *param_4 = *(int *)(param_1 + 0x14c);
  iVar3 = *(int *)(param_1 + 0x150);
  *param_5 = iVar3;
  iVar1 = *param_2;
  if ((((iVar1 == -1) && (*param_3 == -1)) && (*param_4 == -1)) && (iVar3 == -1)) {
    return 0;
  }
  if (iVar1 < 0) {
    *param_2 = 0;
  }
  else {
    iVar3 = *(int *)(*(int *)(param_1 + 0x104) + 8);
    if (iVar3 <= iVar1) {
      *param_2 = iVar3 + -1;
    }
  }
  if (*param_3 < 0) {
    *param_3 = 0;
  }
  else {
    iVar3 = *(int *)(*(int *)(param_1 + 0x104) + 0xc);
    if (iVar3 <= *param_3) {
      *param_3 = iVar3 + -1;
    }
  }
  if (*param_4 < 0) {
    *param_4 = 0;
  }
  else {
    iVar3 = *(int *)(*(int *)(param_1 + 0x104) + 8);
    if (iVar3 <= *param_4) {
      *param_4 = iVar3 + -1;
    }
  }
  if (*param_5 < 0) {
    *param_5 = 0;
  }
  else {
    iVar3 = *(int *)(*(int *)(param_1 + 0x104) + 0xc);
    if (iVar3 <= *param_5) {
      *param_5 = iVar3 + -1;
    }
  }
  if (param_6 != 0) {
    iVar3 = *param_2;
    iVar1 = *param_4;
    iVar2 = *param_5;
    iVar4 = *param_3;
    iVar5 = iVar3;
    if (iVar1 <= iVar3) {
      iVar5 = iVar1;
    }
    *param_2 = iVar5;
    iVar5 = iVar4;
    if (iVar2 <= iVar4) {
      iVar5 = iVar2;
    }
    *param_3 = iVar5;
    if (iVar3 <= iVar1) {
      iVar3 = iVar1;
    }
    *param_4 = iVar3;
    if (iVar4 <= iVar2) {
      iVar4 = iVar2;
    }
    *param_5 = iVar4;
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_005346e5
// Address: 005346e5
void __thiscall FUN_005346e5(int param_1,int *param_2,int *param_3,int param_4,int param_5)
{
  int iVar1;
  int iVar2;
  int iVar3;
  bool bVar4;
  undefined4 uVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  int iStack_34;
  int iStack_30;
  int iStack_28;
  int iStack_24;
  int iStack_10;
  int iStack_c;
  int iStack_8;
  int iStack_4;
  
  bVar4 = false;
  if ((param_4 != 0) || (param_5 != 0)) {
    iVar6 = param_2[1];
    if ((param_3[3] < iVar6) ||
       (((iVar1 = *param_2, param_3[2] < iVar1 || (iVar2 = param_2[3], iVar2 < param_3[1])) ||
        (iVar3 = param_2[2], iVar3 < *param_3)))) {
      bVar4 = true;
      iStack_34 = 1;
    }
    else {
      iVar8 = param_5;
      if (param_5 < 0) {
        iVar8 = -param_5;
      }
      iVar9 = param_4;
      if (param_4 < 0) {
        iVar9 = -param_4;
      }
      iStack_34 = 9999;
      iStack_30 = 9999;
      if (param_5 != 0) {
        iStack_30 = (iVar8 + (iVar2 - iVar6)) / iVar8;
      }
      if (param_4 != 0) {
        iStack_34 = (iVar9 + (iVar3 - iVar1)) / iVar9;
      }
      iStack_10 = *param_2;
      iStack_c = param_2[1];
      iStack_8 = param_2[2];
      iStack_4 = param_2[3];
      iStack_24 = 0;
      iStack_28 = 0;
      if (iStack_30 < iStack_34) {
        iStack_34 = iStack_30;
        iStack_28 = param_5;
        if (param_5 < 0) {
          iStack_c = param_5 + 1 + iVar2;
        }
        else {
          iStack_4 = param_5 + -1 + iVar6;
        }
      }
      else {
        iStack_24 = param_4;
        if (param_4 < 0) {
          iStack_10 = param_4 + 1 + iVar3;
        }
        else {
          iStack_8 = param_4 + -1 + iVar1;
        }
      }
    }
    if (*(int *)(param_1 + 0x2e4) < iStack_34) {
      if (*(int *)(param_1 + 0x2dc) != 0) {
        free(*(int *)(param_1 + 0x2dc));
      }
      *(undefined4 *)(param_1 + 0x2dc) = 0;
    }
    if (*(int *)(param_1 + 0x2dc) == 0) {
      uVar5 = calloc(iStack_34,0x20);
      *(int *)(param_1 + 0x2e4) = iStack_34;
      *(undefined4 *)(param_1 + 0x2dc) = uVar5;
    }
    if (bVar4) {
      piVar7 = *(int **)(param_1 + 0x2dc);
      *piVar7 = *param_2;
      piVar7[1] = param_2[1];
      piVar7[2] = param_2[2];
      piVar7[3] = param_2[3];
      iVar6 = *(int *)(param_1 + 0x2dc);
      *(int *)(iVar6 + 0x10) = *param_3;
      *(int *)(iVar6 + 0x14) = param_3[1];
      *(int *)(iVar6 + 0x18) = param_3[2];
      *(int *)(iVar6 + 0x1c) = param_3[3];
    }
    else if (0 < iStack_34) {
      iVar6 = 0;
      param_3 = (int *)iStack_34;
      do {
        piVar7 = (int *)(iVar6 + *(int *)(param_1 + 0x2dc));
        *piVar7 = iStack_10;
        piVar7[1] = iStack_c;
        piVar7[2] = iStack_8;
        piVar7[3] = iStack_4;
        *(int *)(iVar6 + 0x14 + *(int *)(param_1 + 0x2dc)) = iStack_c - param_5;
        *(int *)(iVar6 + 0x10 + *(int *)(param_1 + 0x2dc)) = iStack_10 - param_4;
        *(int *)(iVar6 + 0x1c + *(int *)(param_1 + 0x2dc)) = iStack_4 - param_5;
        *(int *)(iVar6 + 0x18 + *(int *)(param_1 + 0x2dc)) = iStack_8 - param_4;
        iStack_c = iStack_c + iStack_28;
        iStack_4 = iStack_4 + iStack_28;
        iStack_10 = iStack_10 + iStack_24;
        iStack_8 = iStack_8 + iStack_24;
        if (iStack_c < param_2[1]) {
          iStack_c = param_2[1];
        }
        if (iStack_10 < *param_2) {
          iStack_10 = *param_2;
        }
        if (param_2[2] < iStack_8) {
          iStack_8 = param_2[2];
        }
        if (param_2[3] < iStack_4) {
          iStack_4 = param_2[3];
        }
        iVar6 = iVar6 + 0x20;
        param_3 = (int *)((int)param_3 + -1);
      } while (param_3 != (int *)0x0);
    }
    *(undefined4 *)(param_1 + 0x2d8) = 1;
    *(int *)(param_1 + 0x2e0) = iStack_34;
    *(undefined4 *)(param_1 + 0x2e8) = 0xffffffff;
    *(undefined4 *)(param_1 + 0x2ec) = *(undefined4 *)(param_1 + 0x8c);
    *(undefined4 *)(param_1 + 0x2f0) = *(undefined4 *)(param_1 + 0x90);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_005349fc
// Address: 005349fc
void __thiscall FUN_005349fc(int param_1,int param_2)
{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iStack_10;
  int iStack_c;
  int iStack_8;
  int iStack_4;
  
  if (*(int *)(param_1 + 0x2d8) != 0) {
    if ((param_2 == 0) &&
       (piVar1 = *(int **)(*(int *)(param_1 + 0x20) + 0x3c),
       iVar3 = (**(code **)(*piVar1 + 0x34))(piVar1,1), iVar3 != 0)) {
      return;
    }
    iVar3 = *(int *)(param_1 + 0x2e8) + 1;
    *(int *)(param_1 + 0x2e8) = iVar3;
    if (((*(int *)(param_1 + 0x2dc) != 0) && (-1 < iVar3)) && (iVar3 < *(int *)(param_1 + 0x2e0))) {
      piVar4 = (int *)(iVar3 * 0x20 + *(int *)(param_1 + 0x2dc));
      iVar3 = *(int *)(param_1 + 0x2f0);
      iStack_c = piVar4[1] + iVar3;
      iVar2 = *(int *)(param_1 + 0x2ec);
      iStack_10 = iVar2 + *piVar4;
      iStack_4 = piVar4[3] + 1 + iVar3;
      iStack_8 = piVar4[2] + 1 + iVar2;
      piVar1 = *(int **)(*(int *)(param_1 + 0x20) + 0x3c);
      (**(code **)(*piVar1 + 0x1c))
                (piVar1,piVar4[4] + iVar2,piVar4[5] + iVar3,piVar1,&iStack_10,0x10);
      if (*(int *)(param_1 + 0x2e8) + 1 < *(int *)(param_1 + 0x2e0)) {
        return;
      }
    }
    *(undefined4 *)(param_1 + 0x2d8) = 0;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00534adb
// Address: 00534adb
// [HELPER] s_view__draw2: "view::draw2"
// [HELPER] s_view__draw3: "view::draw3"
// [HELPER] s_view__draw: "view::draw"
void __fastcall FUN_00534adb(RGE_View *param_1)
{
  short sVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  int iVar5;
  uchar *puVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  TDrawArea *pTVar10;
  ushort uVar11;
  short unaff_BX;
  ushort uVar12;
  int iVar13;
  undefined4 *puVar14;
  int iVar15;
  undefined4 *puVar16;
  char *pcVar17;
  tagRECT tStack_44;
  tagRECT tStack_34;
  tagRECT tStack_24;
  tagRECT tStack_14;
  
  tiles_drawn = 0;
  if (view_debug_redraw_all != 0) {
    param_1->render_terrain_mode = '\0';
    view_debug_redraw_all = 0;
  }
  if ((view_debug_ObstructionMap != 0) || (view_debug_palette != 0)) {
    param_1->render_terrain_mode = '\0';
  }
  if (param_1->world == (RGE_Game_World *)0x0) {
    iVar5 = param_1->_padding_;
    (**(code **)(iVar5 + 0x28))(0);
    TDrawArea::Clear((TDrawArea *)param_1->_padding_,(tagRECT *)&param_1->_padding_,
                     (uint)*(byte *)((int)&param_1->_padding_ + 3));
    (**(code **)(iVar5 + 0x2c))();
    return;
  }
  sVar1 = param_1->start_scr_row;
  sVar2 = param_1->start_map_row;
  sVar3 = param_1->start_scr_col;
  sVar4 = param_1->start_map_col;
  TSpan_List_Manager::ResetAll(param_1->Terrain_Clip_Mask);
  TSpan_List_Manager::ResetAll(param_1->Terrain_Fog_Clip_Mask);
  TSpan_List_Manager::ResetAll(param_1->Master_Clip_Mask);
  iVar5 = param_1->map_scr_y_offset;
  iVar13 = param_1->map_scr_x_offset;
  param_1->Use_Rect2 = 0;
  param_1->Limited_Render_Rect = 0;
  RGE_View::update(param_1);
  tStack_44.left = param_1->_padding_;
  (**(code **)(tStack_44.left + 0x28))(0);
  if ((param_1->render_terrain_mode != '\x01') ||
     ((((param_1->start_map_col == sVar4 && (param_1->start_map_row == unaff_BX)) &&
       (param_1->start_scr_col == sVar2)) && (param_1->start_scr_row == sVar3)))) goto LAB_0053512b;
  uVar12 = (short)param_1->map_scr_y_offset - sVar1;
  uVar11 = (short)param_1->map_scr_x_offset - (short)iVar13;
  if ((uVar11 == 0) && (uVar12 == 0)) goto LAB_0053512b;
  iVar13 = param_1->_padding_;
  tStack_24.left = 0;
  tStack_24.top = 0;
  iVar7 = param_1->_padding_;
  tStack_24.right = iVar13 + -1;
  tStack_34.left = (long)(short)uVar11;
  tStack_34.top = (long)(short)uVar12;
  tStack_24.bottom = iVar7 + -1;
  tStack_34.right = tStack_24.right + tStack_34.left;
  tStack_34.bottom = tStack_24.bottom + tStack_34.top;
  if ((tStack_34.bottom < 0) ||
     (((tStack_34.right < 0 || (tStack_24.bottom < tStack_34.top)) ||
      (tStack_24.right < tStack_34.left)))) {
    param_1->render_terrain_mode = '\0';
    goto LAB_0053512b;
  }
  if ((uVar11 & 7) != 0) {
    uVar9 = tStack_34.left;
    if ((short)uVar11 < 1) {
      uVar9 = tStack_34.left + 7;
    }
    iVar15 = (uVar9 & 0xfffffff8) - tStack_34.left;
    uVar11 = uVar11 + (short)iVar15;
    param_1->map_scr_x_offset = param_1->map_scr_x_offset + iVar15;
  }
  if ((uVar12 & 7) != 0) {
    uVar9 = tStack_34.top;
    if ((short)uVar12 < 1) {
      uVar9 = tStack_34.top + 7;
    }
    iVar15 = (uVar9 & 0xfffffff8) - tStack_34.top;
    uVar12 = uVar12 + (short)iVar15;
    param_1->map_scr_y_offset = param_1->map_scr_y_offset + iVar15;
  }
  if ((short)uVar11 < 0) {
    tStack_24.left = 0;
    tStack_24.right = (short)uVar11 + -1 + iVar13;
    tStack_34.left = -(int)(short)uVar11;
  }
  else {
    tStack_24.left = (long)(short)uVar11;
    tStack_24.right = iVar13 + -1;
    tStack_34.left = 0;
    iVar13 = iVar13 - tStack_24.left;
  }
  tStack_34.right = iVar13 + -1;
  iVar13 = (int)(short)uVar11;
  if ((short)uVar12 < 0) {
    tStack_24.top = 0;
    tStack_24.bottom = (short)uVar12 + -1 + iVar7;
    tStack_34.top = -(int)(short)uVar12;
  }
  else {
    tStack_24.top = (long)(short)uVar12;
    tStack_24.bottom = iVar7 + -1;
    tStack_34.top = 0;
    iVar7 = iVar7 - tStack_24.top;
  }
  tStack_34.bottom = iVar7 + -1;
  iVar7 = (int)(short)uVar12;
  pTVar10 = (TDrawArea *)param_1->_padding_;
  if ((pTVar10->DrawSystem->DrawType == '\x01') || (pTVar10->UsingVidMem == 0)) {
    TDrawArea::OverlayMemCopy
              (pTVar10,&tStack_24,&tStack_34,iVar13,iVar7,param_1->_padding_,param_1->_padding_);
    param_1->Queued_Blits = 0;
  }
  else {
    RGE_View::CreateBlitQueue(param_1,&tStack_24,&tStack_34,iVar13,iVar7);
    if (MouseSystem != (TMousePointer *)0x0) {
      TMousePointer::Poll(MouseSystem);
    }
    if (param_1->Queued_Blits != 0) {
      RGE_View::ProcessQueuedBlit(param_1,0);
    }
  }
  DClipInfo_List::Scroll(param_1->prior_objs,iVar13,iVar7);
  pTVar10 = param_1->save_area1;
  iVar15 = param_1->Float_X_Delta + iVar13;
  param_1->Float_X_Delta = iVar15;
  if (iVar15 < pTVar10->Width) {
    if ((iVar15 < 0) && (puVar6 = TDrawArea::Lock(pTVar10,s_view__draw2,1), puVar6 != (uchar *)0x0))
{
      pTVar10 = param_1->save_area1;
      iVar13 = param_1->Float_Y_Delta + -1;
      param_1->Float_X_Delta = param_1->Float_X_Delta + pTVar10->Width;
      param_1->Float_Y_Delta = iVar13;
      if (iVar13 < 0) {
        param_1->Float_Y_Delta = pTVar10->Height + -1;
      }
      uVar9 = param_1->Float_X_Delta;
      pcVar17 = s_view__draw3;
      puVar14 = (undefined4 *)*pTVar10->DisplayOffsets;
      puVar16 = (undefined4 *)((int)pTVar10->DisplayOffsets[pTVar10->Height + -1] + pTVar10->Width);
      for (uVar8 = uVar9 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
        *puVar16 = *puVar14;
        puVar14 = puVar14 + 1;
        puVar16 = puVar16 + 1;
      }
      for (uVar9 = uVar9 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
        *(undefined1 *)puVar16 = *(undefined1 *)puVar14;
        puVar14 = (undefined4 *)((int)puVar14 + 1);
        puVar16 = (undefined4 *)((int)puVar16 + 1);
      }
      pTVar10 = param_1->save_area1;
      goto LAB_00534f10;
    }
  }
  else {
    puVar6 = TDrawArea::Lock(pTVar10,s_view__draw,1);
    if (puVar6 != (uchar *)0x0) {
      pTVar10 = param_1->save_area1;
      uVar8 = param_1->Float_X_Delta - iVar13;
      puVar14 = (undefined4 *)((int)pTVar10->DisplayOffsets[pTVar10->Height + -1] + pTVar10->Width);
      puVar16 = (undefined4 *)*pTVar10->DisplayOffsets;
      for (uVar9 = uVar8 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
        *puVar16 = *puVar14;
        puVar14 = puVar14 + 1;
        puVar16 = puVar16 + 1;
      }
      for (uVar8 = uVar8 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
        *(undefined1 *)puVar16 = *(undefined1 *)puVar14;
        puVar14 = (undefined4 *)((int)puVar14 + 1);
        puVar16 = (undefined4 *)((int)puVar16 + 1);
      }
      pTVar10 = param_1->save_area1;
      iVar13 = param_1->Float_Y_Delta + 1;
      param_1->Float_X_Delta = param_1->Float_X_Delta - pTVar10->Width;
      param_1->Float_Y_Delta = iVar13;
      if (pTVar10->Height <= iVar13) {
        param_1->Float_Y_Delta = 0;
      }
      pcVar17 = s_view__draw;
LAB_00534f10:
      TDrawArea::Unlock(pTVar10,pcVar17);
    }
  }
  iVar7 = param_1->Float_Y_Delta + iVar7;
  param_1->Float_Y_Delta = iVar7;
  if (iVar7 < 0) {
    param_1->Float_Y_Delta = param_1->save_area1->Height + iVar7;
  }
  iVar13 = param_1->save_area1->Height;
  if (iVar13 <= param_1->Float_Y_Delta) {
    param_1->Float_Y_Delta = param_1->Float_Y_Delta - iVar13;
  }
  TDrawArea::SetFloatOffsets(param_1->save_area1,param_1->Float_X_Delta,param_1->Float_Y_Delta);
  if ((tStack_34.left == 0) && (iVar13 = param_1->_padding_ + -1, tStack_34.right == iVar13)) {
    tStack_14.left = -1;
    if ((tStack_34.top == 0) && (tStack_34.bottom == param_1->_padding_ + -1)) {
      tStack_44.left = 0xffffffff;
    }
    else {
      tStack_44.left = 0;
      tStack_44.right = iVar13;
      if (tStack_34.top == 0) {
        tStack_44.top = tStack_34.bottom + 1;
        tStack_44.bottom = param_1->_padding_ + -1;
      }
      else {
        tStack_44.top = 0;
        tStack_44.bottom = tStack_34.top - 1;
      }
    }
  }
  else if (tStack_34.left == 0) {
    tStack_14.right = param_1->_padding_ + -1;
    tStack_14.left = tStack_34.right + 1;
    tStack_14.bottom = param_1->_padding_ + -1;
    tStack_14.top = 0;
    if ((tStack_34.top == 0) && (tStack_34.bottom == tStack_14.bottom)) {
      tStack_44.left = 0xffffffff;
    }
    else {
      tStack_44.left = 0;
      if (tStack_34.top == 0) {
        tStack_44.top = tStack_34.bottom + 1;
        tStack_44.right = tStack_34.right;
        tStack_44.bottom = tStack_14.bottom;
      }
      else {
        tStack_44.top = 0;
        tStack_44.right = tStack_34.right;
        tStack_44.bottom = tStack_34.top - 1;
      }
    }
  }
  else {
    tStack_14.right = tStack_34.left - 1;
    tStack_14.bottom = param_1->_padding_ + -1;
    tStack_14.left = 0;
    tStack_14.top = 0;
    if ((tStack_34.top == 0) && (tStack_34.bottom == tStack_14.bottom)) {
      tStack_44.left = 0xffffffff;
    }
    else {
      tStack_44.left = tStack_34.left;
      if (tStack_34.top == 0) {
        tStack_44.top = tStack_34.bottom + 1;
        tStack_44.right = param_1->_padding_ + -1;
        tStack_44.bottom = tStack_14.bottom;
      }
      else {
        tStack_44.top = 0;
        tStack_44.right = param_1->_padding_ + -1;
        tStack_44.bottom = tStack_34.top - 1;
      }
    }
  }
  if (tStack_14.left != -1) {
    TDrawArea::PtrClear(param_1->save_area1,&tStack_14,0);
    param_1->Limited_Render_Rect = 1;
    (param_1->Render_Rect1).left = tStack_14.left;
    (param_1->Render_Rect1).top = tStack_14.top;
    (param_1->Render_Rect1).right = tStack_14.right;
    (param_1->Render_Rect1).bottom = tStack_14.bottom;
  }
  if (tStack_44.left != 0xffffffff) {
    TDrawArea::PtrClear(param_1->save_area1,&tStack_44,0);
    if (tStack_14.left == -1) {
      param_1->Limited_Render_Rect = 1;
      (param_1->Render_Rect1).left = tStack_44.left;
      (param_1->Render_Rect1).top = tStack_44.top;
      (param_1->Render_Rect1).right = tStack_44.right;
      (param_1->Render_Rect1).bottom = tStack_44.bottom;
    }
    else {
      param_1->Use_Rect2 = 1;
      (param_1->Render_Rect2).left = tStack_44.left;
      (param_1->Render_Rect2).top = tStack_44.top;
      (param_1->Render_Rect2).right = tStack_44.right;
      (param_1->Render_Rect2).bottom = tStack_44.bottom;
    }
  }
LAB_0053512b:
  if (MouseSystem != (TMousePointer *)0x0) {
    TMousePointer::Poll(MouseSystem);
  }
  if (param_1->Queued_Blits != 0) {
    RGE_View::ProcessQueuedBlit(param_1,0);
  }
  iVar13 = rge_base_game->game_mode;
  if ((8 < iVar13) && ((iVar13 < 0xb || (iVar13 == 0x13)))) {
    RGE_View::draw_paint_brush(param_1);
  }
  if (param_1->render_terrain_mode == '\0') {
    param_1->Float_X_Delta = 0;
    param_1->Float_Y_Delta = 0;
    TDrawArea::SetFloatOffsets(param_1->save_area1,0,0);
    TDrawArea::PtrClear(param_1->save_area1,&param_1->save_area1->ClipRect,0);
  }
  RGE_View::draw_view(param_1,'\n',param_1->save_area1);
  param_1->render_terrain_mode = '\x01';
  (**(code **)(iVar5 + 0x2c))();
  frame_count = frame_count + 1;
  return;
}

// --------------------------------------------------

// Function: FUN_0053520b
// Address: 0053520b
void __fastcall FUN_0053520b(int param_1)
{
  short *psVar1;
  int iVar2;
  undefined2 uVar3;
  short sVar4;
  short sVar5;
  short sVar6;
  short sVar7;
  short sVar8;
  
  iVar2 = *(int *)(param_1 + 0x100);
  if ((iVar2 != 0) &&
     ((*(float *)(iVar2 + 0x114) != *(float *)(param_1 + 0x138) ||
      (*(float *)(iVar2 + 0x118) != *(float *)(param_1 + 0x13c))))) {
    uVar3 = __ftol();
    *(undefined2 *)(param_1 + 0x122) = uVar3;
    uVar3 = __ftol();
    sVar6 = *(short *)(param_1 + 0x122);
    *(undefined2 *)(param_1 + 0x124) = uVar3;
    *(undefined4 *)(param_1 + 0x138) = *(undefined4 *)(iVar2 + 0x114);
    *(undefined4 *)(param_1 + 0x13c) = *(undefined4 *)(iVar2 + 0x118);
    sVar7 = (*(short *)(param_1 + 0x8c) + (short)(*(int *)(param_1 + 0x14) / 2)) -
            *(short *)(param_1 + 0x10c);
    *(short *)(param_1 + 0x11a) = sVar7;
    sVar8 = (*(short *)(param_1 + 0x90) + (short)(*(int *)(param_1 + 0x18) / 2)) -
            *(short *)(param_1 + 0x10e);
    *(short *)(param_1 + 0x11c) = sVar8;
    sVar4 = __ftol();
    sVar5 = __ftol();
    sVar5 = -(sVar5 + (short)*(undefined4 *)(param_1 + 0x10e));
    sVar7 = sVar7 + -sVar4;
    sVar8 = sVar8 + sVar5;
    *(short *)(param_1 + 0x11a) = sVar7;
    *(short *)(param_1 + 0x11c) = sVar8;
    psVar1 = (short *)(*(int *)(*(int *)(*(int *)(param_1 + 0x104) + 0x8d8c) +
                               *(short *)(param_1 + 0x124) * 4) + sVar6 * 0x18);
    *(int *)(param_1 + 0x130) = (int)*psVar1 - (int)sVar7;
    *(uint *)(param_1 + 0x134) =
         ((int)*(short *)(param_1 + 0x110) * (uint)(*(byte *)((int)psVar1 + 5) >> 5) +
         (int)psVar1[1]) - (int)sVar8;
    *(short *)(param_1 + 0x11e) =
         (sVar6 + *(short *)(param_1 + 0x124)) * (short)*(undefined4 *)(param_1 + 0x10c) + -sVar4;
    *(undefined2 *)(param_1 + 300) = *(undefined2 *)(param_1 + 0x124);
    *(short *)(param_1 + 0x120) =
         (*(short *)(param_1 + 0x124) - sVar6) * *(short *)(param_1 + 0x10e) + sVar5;
    sVar5 = *(short *)(param_1 + 0x116) / 2 + 2;
    *(short *)(param_1 + 300) = *(short *)(param_1 + 300) - sVar5;
    *(short *)(param_1 + 0x12a) = sVar6 - sVar5;
    *(short *)(param_1 + 0x126) = sVar7 + sVar5 * (short)*(undefined4 *)(param_1 + 0x10c) * -2;
    sVar6 = *(short *)(param_1 + 0x118) / 2 + 1;
    *(short *)(param_1 + 0x12a) = *(short *)(param_1 + 0x12a) + sVar6;
    *(short *)(param_1 + 300) = *(short *)(param_1 + 300) - sVar6;
    *(short *)(param_1 + 0x128) = sVar8 + sVar6 * *(short *)(param_1 + 0x10e) * -2;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0053547b
// Address: 0053547b
// [HELPER] s_view__draw_view: "view::draw_view"
void __thiscall FUN_0053547b(RGE_View *param_1,uchar param_2,TDrawArea *param_3)
{
  tagRECT tVar1;
  uchar *puVar2;
  int iStack_10;
  int iStack_c;
  int iStack_8;
  int iStack_4;
  
  if (param_3 == (TDrawArea *)0x0) {
    param_3 = (TDrawArea *)param_1->_padding_;
  }
  param_1->cur_render_area = param_3;
  if (param_3 == param_1->save_area1) {
    iStack_10 = param_1->_padding_;
    iStack_8 = param_1->_padding_;
    iStack_c = param_1->_padding_;
    iStack_4 = param_1->_padding_;
    param_1->_padding_ = 0;
    param_1->start_scr_col = param_1->start_scr_col - (short)iStack_10;
    param_1->start_scr_row = param_1->start_scr_row - (short)iStack_c;
    param_1->_padding_ = iStack_8 - iStack_10;
    param_1->_padding_ = 0;
    param_1->_padding_ = iStack_4 - iStack_c;
    param_1->map_scr_x_offset = param_1->map_scr_x_offset + iStack_10;
    param_1->map_scr_y_offset = param_1->map_scr_y_offset + iStack_c;
  }
  puVar2 = TDrawArea::Lock(param_3,s_view__draw_view,1);
  if (puVar2 != (uchar *)0x0) {
    if (param_2 == '\n') {
      tVar1.top = iStack_c;
      tVar1.left = iStack_10;
      tVar1.right = iStack_8;
      tVar1.bottom = iStack_4;
      RGE_View::view_function_terrain(param_1,'\n',tVar1);
    }
    else {
      RGE_View::view_function
                (param_1,param_2,'\0',(tagPOINT *)0x0,(tagPOINT *)0x0,(void **)0x0,(float *)0x0,
                 (float *)0x0,(short *)0x0,(short *)0x0);
    }
    TDrawArea::Unlock(param_1->cur_render_area,s_view__draw_view);
  }
  if (param_1->cur_render_area == param_1->save_area1) {
    param_1->start_scr_col = param_1->start_scr_col + (short)iStack_10;
    param_1->start_scr_row = param_1->start_scr_row + (short)iStack_c;
    param_1->_padding_ = param_1->_padding_ + iStack_10;
    param_1->_padding_ = param_1->_padding_ + iStack_c;
    param_1->_padding_ = param_1->_padding_ + iStack_10;
    param_1->_padding_ = param_1->_padding_ + iStack_c;
    param_1->map_scr_x_offset = param_1->map_scr_x_offset - iStack_10;
    param_1->map_scr_y_offset = param_1->map_scr_y_offset - iStack_c;
  }
  param_1->cur_render_area = (TDrawArea *)0x0;
  return;
}

// --------------------------------------------------

// Function: FUN_00535603
// Address: 00535603
void __fastcall FUN_00535603(RGE_View *param_1)
{
  RGE_Master_Static_Object *this;
  int iVar1;
  RGE_Static_Object *pRVar2;
  uchar uVar3;
  char cVar4;
  short sVar5;
  short sVar6;
  RGE_Player *pRVar7;
  int iVar8;
  uint uVar9;
  RGE_Color_Table *pRVar10;
  uint uVar11;
  uint uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  short *psVar16;
  short *psVar17;
  undefined4 uVar18;
  int iVar19;
  int iVar20;
  RGE_Pick_Info *pRVar21;
  float *pfVar22;
  short asStack_38 [2];
  short asStack_34 [2];
  short asStack_30 [6];
  float fStack_24;
  float fStack_20;
  tagPOINT tStack_1c;
  RGE_Pick_Info RStack_14;
  
  sVar5 = rge_base_game->master_obj_id;
  if (sVar5 != -1) {
    pRVar7 = RGE_Base_Game::get_player(rge_base_game);
    this = pRVar7->master_objects[sVar5];
    if (this != (RGE_Master_Static_Object *)0x0) {
      RGE_Base_Game::get_mouse_pos(rge_base_game,&tStack_1c);
      if ((param_1->_padding_ <= tStack_1c.x) && (tStack_1c.x <= param_1->_padding_)) {
        if ((param_1->_padding_ <= tStack_1c.y) && (tStack_1c.y <= param_1->_padding_)) {
          uVar3 = RGE_View::pick(param_1,'(','\0',tStack_1c.x - param_1->_padding_,
                                 tStack_1c.y - param_1->_padding_,&RStack_14,
                                 (RGE_Static_Object *)0x0);
          if (uVar3 == '3') {
            iVar1 = this->_padding_;
            pfVar22 = &RStack_14.y;
            pRVar21 = &RStack_14;
            (**(code **)(iVar1 + 0x24))(pRVar21,pfVar22,param_1->world,0);
            psVar17 = asStack_38;
            iVar19 = 1;
            psVar16 = (short *)&stack0xffffffc0;
            sVar5 = __ftol();
            sVar6 = __ftol();
            iVar19 = RGE_View::get_tile_screen_coords(param_1,sVar6,sVar5,psVar16,psVar17,iVar19);
            if (iVar19 != 0) {
              RGE_Master_Static_Object::alignment_box
                        (this,param_1->world,fStack_24,fStack_20,(short *)&stack0xffffffb4,
                         (short *)&stack0xffffffbe,(short *)&stack0xffffffbc,
                         (short *)&stack0xffffffb6,asStack_34,(short *)&stack0xffffffba,
                         (short *)&stack0xffffffb8,asStack_30);
              uVar9 = (uint)this->elevation_flag;
              iVar20 = 1;
              uVar18 = 1;
              iVar19 = 1;
              uVar15 = 0;
              uVar14 = 1;
              uVar13 = 0;
              pRVar7 = RGE_Base_Game::get_player(rge_base_game);
              cVar4 = (**(code **)(iVar1 + 0x20))
                                (pRVar7,fStack_24,fStack_20,uVar13,uVar14,uVar9,uVar15,iVar19,uVar18
                                );
              if (cVar4 == '\0') {
                fog_next_shape = 5;
              }
              else {
                uVar9 = param_1->world->world_time >> 7 & 7;
                if (uVar9 < 4) {
                  iVar8 = uVar9 + 0x24;
                }
                else {
                  iVar8 = 0x2c - uVar9;
                }
                fog_next_shape = iVar8 << 4 | 9;
              }
              iVar19 = (int)&pRVar21->x + iVar19 + ((int)(short)uVar14 - (int)(short)pRVar21) / 2;
              iVar20 = (int)pfVar22 +
                       iVar20 + ((int)(short)((uint)uVar14 >> 0x10) - (int)(short)pfVar22) / 2;
              if (this->sprite != (RGE_Sprite *)0x0) {
                SDI_Draw_Line = (int)(short)iVar20;
                uVar9 = this->draw_flag & 1;
                if (cVar4 == '\0') {
                  uVar12 = (uint)this->draw_color;
                }
                else {
                  uVar12 = 0x97;
                }
                if (((rge_base_game->game_mode == 8) && (rge_base_game->sub_game_mode == 1)) &&
                   (pRVar2 = param_1->movable_object, pRVar2 != (RGE_Static_Object *)0x0)) {
                  uVar13 = 0;
                  uVar11 = (uint)pRVar2->facet;
                  pRVar10 = pRVar2->owner->color_table;
                  iVar8 = param_1->_padding_;
                }
                else {
                  uVar13 = 0;
                  uVar11 = 0;
                  pRVar7 = RGE_Base_Game::get_player(rge_base_game);
                  pRVar10 = pRVar7->color_table;
                  iVar8 = param_1->_padding_;
                }
                (**(code **)(iVar1 + 0x34))(iVar8,iVar19,iVar20,pRVar10,uVar11,uVar13,uVar9,uVar12);
              }
              fog_next_shape = 0;
            }
          }
        }
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_005358a9
// Address: 005358a9
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_005358a9(RGE_View *param_1)
{
  uchar uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  short sVar5;
  tagPOINT tStack_1c;
  RGE_Pick_Info RStack_14;
  
  RGE_View::set_selection_area(param_1,-1,-1,-1,-1);
  RGE_Base_Game::get_mouse_pos(rge_base_game,&tStack_1c);
  if ((((param_1->_padding_ <= tStack_1c.x) && (tStack_1c.x <= param_1->_padding_)) &&
      (param_1->_padding_ <= tStack_1c.y)) && (tStack_1c.y <= param_1->_padding_)) {
    uVar1 = RGE_View::pick(param_1,'(','\0',tStack_1c.x,tStack_1c.y,&RStack_14,
                           (RGE_Static_Object *)0x0);
    if (uVar1 == '3') {
      if (rge_base_game->game_mode == 0x13) {
        iVar2 = __ftol();
        RStack_14.x = _DAT_005776bc - (float)(iVar2 * -3);
        iVar2 = __ftol();
        sVar5 = 3;
        RStack_14.y = _DAT_005776bc - (float)(iVar2 * -3);
      }
      else {
        sVar5 = rge_base_game->brush_size;
      }
      iVar2 = __ftol();
      iVar3 = __ftol();
      iVar4 = (int)sVar5 >> 1;
      RGE_View::set_selection_area(param_1,iVar2 - iVar4,iVar3 - iVar4,iVar2 + iVar4,iVar3 + iVar4);
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_005359d8
// Address: 005359d8
void __thiscall
FUN_005359d8(RGE_View *param_1,uchar param_2,undefined4 param_3,long param_4,long param_5,
            float *param_6,uint param_7)
{
  uchar uVar1;
  float *pfVar2;
  long lVar3;
  tagPOINT tStack_10;
  tagPOINT tStack_8;
  
  pfVar2 = param_6;
  uVar1 = param_2;
  _param_2 = (void *)(-(uint)(param_2 != '(') & param_7);
  tStack_8.y = param_5;
  tStack_10.y = param_5;
  tStack_8.x = param_4;
  tStack_10.x = param_4;
  *param_6 = 0.0;
  param_6[1] = 0.0;
  param_6[2] = 0.0;
  param_6[3] = 0.0;
  param_6[4] = 0.0;
  lVar3 = RGE_View::view_function
                    (param_1,uVar1,(uchar)param_3,&tStack_8,&tStack_10,(void **)&param_2,param_6,
                     param_6 + 1,(short *)(param_6 + 2),(short *)((int)param_6 + 10));
  if ((char)lVar3 == '4') {
    pfVar2[3] = (float)_param_2;
    return;
  }
  if ((char)lVar3 == '3') {
    pfVar2[4] = (float)_param_2;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00535a77
// Address: 00535a77
undefined4 __thiscall
FUN_00535a77(RGE_View *param_1,uchar param_2,int param_3,int param_4,RGE_Static_Object *param_5,
            int param_6)
{
  bool bVar1;
  uchar uVar2;
  int iVar3;
  int iVar4;
  RGE_Static_Object *pRVar5;
  RGE_Pick_Obj_Info **ppRVar6;
  int iVar7;
  
  iVar7 = 0;
  bVar1 = false;
  iVar3 = RGE_View::pick_multi_objects
                    (param_1,param_3,param_4,(int)param_5,param_6,10,0x14,(int)param_1->player->id,
                     param_2,1);
  if (0 < iVar3) {
    ppRVar6 = &Picked_Objects;
    do {
      if (((*ppRVar6 != (RGE_Pick_Obj_Info *)0xffffffff) &&
          (pRVar5 = param_1->world->objectsValue[(int)*ppRVar6], pRVar5 != (RGE_Static_Object *)0x0)
          ) && (pRVar5->object_state < 7)) {
        iVar4 = RGE_Player::select_one_object(param_1->player,pRVar5,0);
        if (iVar4 == 0) break;
        bVar1 = true;
      }
      iVar7 = iVar7 + 1;
      ppRVar6 = ppRVar6 + 3;
    } while (iVar7 < iVar3);
  }
  if (bVar1) {
    return 1;
  }
  iVar7 = (int)param_5 - param_3;
  param_6 = param_6 - param_4;
  iVar3 = iVar7;
  if (param_6 <= iVar7) {
    iVar3 = param_6;
  }
  if (iVar3 < 0x32) {
    iVar3 = param_6;
    if (iVar7 < param_6) {
      iVar3 = iVar7;
    }
  }
  else {
    iVar3 = 0x32;
  }
  param_4 = RGE_View::pick_objects
                      (param_1,iVar7 / 2 + param_3,param_6 / 2 + param_4,10,0x14,iVar3,4,1);
  if (param_4 != 0) {
    iVar3 = 0;
    param_5 = (RGE_Static_Object *)0x0;
    pRVar5 = (RGE_Static_Object *)0x0;
    if (0 < param_4) {
      ppRVar6 = &Picked_Objects;
      do {
        if (((-1 < (int)*ppRVar6) &&
            (pRVar5 = param_1->world->objectsValue[(int)*ppRVar6],
            pRVar5 != (RGE_Static_Object *)0x0)) &&
           ((pRVar5->object_state < 7 && (1 < pRVar5->master_obj->select_level)))) {
          if ((param_1->map->map_visible_flag == '\0') &&
             (iVar7 = (**(code **)(param_1->_padding_ + 0xe0))(pRVar5), iVar7 == 0)) {
            iVar7 = __ftol();
            iVar4 = __ftol();
            uVar2 = RGE_Visible_Map::get_visible(param_1->player->visible,iVar4,iVar7);
            if (uVar2 != '\x0f') goto LAB_00535c2f;
          }
          iVar7 = (**(code **)(param_1->_padding_ + 0xe4))(pRVar5,(int)*(short *)(ppRVar6 + 1));
          if (pRVar5->owner == param_1->player) {
            iVar7 = iVar7 + 5;
          }
          if (iVar3 < iVar7) {
            iVar3 = iVar7;
            param_5 = pRVar5;
          }
        }
LAB_00535c2f:
        ppRVar6 = ppRVar6 + 3;
        param_4 = param_4 + -1;
        pRVar5 = param_5;
      } while (param_4 != 0);
    }
    if ((pRVar5 != (RGE_Static_Object *)0x0) &&
       (iVar3 = RGE_Player::select_one_object(param_1->player,pRVar5,0), iVar3 != 0)) {
      return 1;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_00535c6f
// Address: 00535c6f
void __thiscall
FUN_00535c6f(RGE_View *param_1,uchar param_2,uchar param_3,tagPOINT *param_4,tagPOINT *param_5,
            void **param_6,float *param_7,float *param_8,short *param_9,short *param_10)
{
  RGE_View::view_function
            (param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,param_10);
  return;
}

// --------------------------------------------------

// Function: FUN_00535ca5
// Address: 00535ca5
undefined4 FUN_00535ca5(void)
{
  return 0;
}

// --------------------------------------------------

// Function: FUN_00535cb5
// Address: 00535cb5
char __thiscall FUN_00535cb5(int param_1,int param_2,int param_3)
{
  char cVar1;
  bool bVar2;
  
  cVar1 = *(char *)(*(int *)(param_2 + 8) + 0x8d);
  if ((*(int *)(param_1 + 0x33c) == 0) || (*(int *)(param_1 + 0x340) != *(int *)(param_2 + 4))) {
    bVar2 = false;
  }
  else {
    bVar2 = true;
  }
  if (cVar1 == '\x02') {
    if (bVar2) {
      return '\x05';
    }
    if ((param_3 != 1) && (param_3 != 2)) {
      if (param_3 != 3) {
        return '\0';
      }
      return '\x02';
    }
  }
  else {
    if (cVar1 != '\x03') {
      if (cVar1 != '\x04') {
        return '\x01';
      }
      if (!bVar2) {
        if ((param_3 != 1) && (param_3 != 2)) {
          return (param_3 == 3) + '\x02';
        }
        return '\x04';
      }
      return '\x05';
    }
    if (bVar2) {
      return '\x05';
    }
    if (param_3 != 1) {
      if (param_3 != 2) {
        return '\0';
      }
      return '\x03';
    }
  }
  return '\x03';
}

// --------------------------------------------------

// Function: FUN_00535d93
// Address: 00535d93
undefined4 __thiscall
FUN_00535d93(int param_1,short param_2,short param_3,short *param_4,short *param_5,int param_6)
{
  short *psVar1;
  byte bVar2;
  int iVar3;
  short sVar4;
  
  if (param_4 != (short *)0x0) {
    *param_4 = 0;
  }
  if (param_5 != (short *)0x0) {
    *param_5 = 0;
  }
  if (-1 < param_2) {
    iVar3 = *(int *)(param_1 + 0x104);
    if (((((int)param_2 < *(int *)(iVar3 + 8)) && (-1 < param_3)) &&
        ((int)param_3 < *(int *)(iVar3 + 0xc))) &&
       (psVar1 = (short *)(*(int *)(*(int *)(iVar3 + 0x8d8c) + param_3 * 4) + param_2 * 0x18),
       psVar1 != (short *)0x0)) {
      bVar2 = *(byte *)(psVar1 + 2);
      sVar4 = (*(short *)(iVar3 + 0x1c + (uint)bVar2 * 6) + psVar1[1]) -
              (short)*(undefined4 *)(param_1 + 0x134);
      if (param_6 != 0) {
        if (bVar2 != 0) {
          sVar4 = sVar4 + *(short *)(param_1 + 0x110) / 2;
        }
        if (bVar2 == 6) {
          sVar4 = sVar4 - *(short *)(param_1 + 0x110);
        }
        if (bVar2 == 5) {
          sVar4 = sVar4 - *(short *)(param_1 + 0x110);
        }
        if (bVar2 == 3) {
          sVar4 = sVar4 - *(short *)(param_1 + 0x110);
        }
        if (bVar2 == 0xb) {
          sVar4 = sVar4 - *(short *)(param_1 + 0x110);
        }
      }
      *param_4 = *psVar1 - (short)*(undefined4 *)(param_1 + 0x130);
      *param_5 = sVar4;
      return 1;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_00535ead
// Address: 00535ead
void __thiscall FUN_00535ead(int param_1,undefined2 *param_2,undefined2 *param_3)
{
  *param_2 = *(undefined2 *)(param_1 + 0x11c);
  *param_3 = *(undefined2 *)(param_1 + 0x11a);
  return;
}

// --------------------------------------------------

// Function: FUN_00535ecf
// Address: 00535ecf
void __thiscall
FUN_00535ecf(int param_1,undefined2 *param_2,undefined2 *param_3,undefined2 *param_4,
            undefined2 *param_5)
{
  if (param_2 != (undefined2 *)0x0) {
    *param_2 = *(undefined2 *)(param_1 + 0x12a);
  }
  if (param_3 != (undefined2 *)0x0) {
    *param_3 = *(undefined2 *)(param_1 + 300);
  }
  if (param_4 != (undefined2 *)0x0) {
    *param_4 = *(undefined2 *)(param_1 + 0x126);
  }
  if (param_5 != (undefined2 *)0x0) {
    *param_5 = *(undefined2 *)(param_1 + 0x128);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00535f1b
// Address: 00535f1b
void __thiscall
FUN_00535f1b(int param_1,undefined2 *param_2,undefined2 *param_3,undefined2 *param_4,
            undefined2 *param_5)
{
  if (param_2 != (undefined2 *)0x0) {
    *param_2 = *(undefined2 *)(param_1 + 0x122);
  }
  if (param_3 != (undefined2 *)0x0) {
    *param_3 = *(undefined2 *)(param_1 + 0x124);
  }
  if (param_4 != (undefined2 *)0x0) {
    *param_4 = *(undefined2 *)(param_1 + 0x11a);
  }
  if (param_5 != (undefined2 *)0x0) {
    *param_5 = *(undefined2 *)(param_1 + 0x11c);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00535f6b
// Address: 00535f6b
void __thiscall
FUN_00535f6b(int param_1,undefined2 *param_2,undefined2 *param_3,undefined2 *param_4,
            undefined2 *param_5)
{
  if (param_2 != (undefined2 *)0x0) {
    *param_2 = *(undefined2 *)(param_1 + 0x108);
  }
  if (param_3 != (undefined2 *)0x0) {
    *param_3 = *(undefined2 *)(param_1 + 0x10a);
  }
  if (param_4 != (undefined2 *)0x0) {
    *param_4 = *(undefined2 *)(param_1 + 0x10c);
  }
  if (param_5 != (undefined2 *)0x0) {
    *param_5 = *(undefined2 *)(param_1 + 0x10e);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_00535fbb
// Address: 00535fbb
void __thiscall FUN_00535fbb(int param_1,undefined2 *param_2,undefined2 *param_3)
{
  *param_2 = *(undefined2 *)(param_1 + 0x116);
  *param_3 = *(undefined2 *)(param_1 + 0x118);
  return;
}

// --------------------------------------------------

// Function: FUN_00535fdf
// Address: 00535fdf
char __thiscall
FUN_00535fdf(RGE_View *param_1,uchar param_2,uchar param_3,tagPOINT *param_4,tagPOINT *param_5,
            undefined4 *param_6,float *param_7,float *param_8,short *param_9,short *param_10)
{
  uchar uVar1;
  short sVar2;
  RGE_Visible_Map *this;
  RGE_Tile *pRVar3;
  float fVar4;
  char cVar5;
  char cVar6;
  RGE_Static_Object *pRVar7;
  short sVar8;
  short sVar9;
  short sVar10;
  undefined4 extraout_EAX;
  RGE_Static_Object *pRVar11;
  byte bVar12;
  short *extraout_ECX;
  short *psVar13;
  undefined2 extraout_var;
  RGE_Map *pRVar14;
  short sVar16;
  byte bVar17;
  short sVar18;
  short sVar19;
  bool bVar20;
  short sVar21;
  RGE_Tile *pRVar22;
  short sVar23;
  short sVar24;
  int iVar25;
  uchar uStack_75;
  int iStack_60;
  uchar uStack_58;
  RGE_Static_Object *pRStack_40;
  uint uStack_3c;
  uint uStack_38;
  int iStack_2c;
  int iStack_28;
  int iStack_24;
  int iStack_20;
  RGE_Static_Object *pRStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  int iStack_10;
  int iStack_c;
  int iStack_8;
  RGE_Tile_List_Node *pRStack_4;
  undefined2 uVar15;
  
  param_1->function_mode = param_2;
  param_1->function_parm = param_3;
  if ((param_2 == '\n') && (param_1->calc_draw_count != 0)) {
    pRVar14 = param_1->map;
    sVar16 = 0;
    if (0 < pRVar14->num_terrain) {
      do {
        iVar25 = (int)sVar16;
        sVar16 = sVar16 + 1;
        pRVar14->terrain_types[iVar25].drawn = '\0';
        pRVar14 = param_1->map;
      } while (sVar16 < pRVar14->num_terrain);
    }
  }
  RGE_Tile_List::get_list_info(&param_1->player->tile_list,&pRStack_4,&iStack_8);
  uVar1 = param_1->function_mode;
  iVar25 = CONCAT31((int3)((uint)extraout_EAX >> 8),uVar1);
  cVar5 = '2';
  if (uVar1 == '(') {
LAB_0053609a:
    if (uVar1 == '<') goto LAB_0053609e;
  }
  else {
    if (uVar1 != '<') {
      if ((((uVar1 != ')') && (uVar1 != '*')) && (uVar1 != '+')) &&
         (psVar13 = extraout_ECX, uVar1 != ',')) goto LAB_00536104;
      goto LAB_0053609a;
    }
LAB_0053609e:
    uStack_18 = __ftol();
    uStack_14 = __ftol();
  }
  *param_7 = 0.0;
  *param_8 = 0.0;
  *param_9 = 0;
  *param_10 = 0;
  uVar1 = param_1->function_mode;
  iVar25 = CONCAT31((int3)((uint)param_9 >> 8),uVar1);
  if (((uVar1 == ')') || (uVar1 == '*')) || ((uVar1 == '+' || (uVar1 == ',')))) {
    pRStack_1c = (RGE_Static_Object *)*param_6;
  }
  *param_6 = 0;
  pRStack_40 = (RGE_Static_Object *)0x0;
  psVar13 = param_10;
LAB_00536104:
  uVar15 = (undefined2)((uint)psVar13 >> 0x10);
  if ((param_1->function_mode == '\x0e') &&
     (iVar25 = RGE_View::get_selection_area(param_1,&iStack_2c,&iStack_24,&iStack_28,&iStack_20,1),
     uVar15 = extraout_var, iVar25 == 0)) {
    return '\0';
  }
  sVar16 = param_1->start_scr_col;
  sVar2 = param_1->start_map_col;
  sVar24 = param_1->start_scr_row;
  sVar9 = param_1->start_map_row;
  iStack_c = CONCAT22((short)((uint)iVar25 >> 0x10),param_1->max_row_num + 6) << 1;
  iStack_60 = CONCAT22(uVar15,param_1->max_col_num + 4);
  cVar6 = '\x04';
  sVar10 = 0;
  iStack_10 = iStack_60;
  if (0 < (short)iStack_c) {
    do {
      sVar8 = 0;
      sVar21 = sVar16;
      sVar19 = sVar2;
      sVar23 = sVar9;
      if (0 < (short)iStack_60) {
        do {
          if ((((sVar19 < 0) || (param_1->map->map_width <= (int)sVar19)) || (sVar23 < 0)) ||
             (param_1->map->map_height <= (int)sVar23)) {
            bVar20 = false;
            if ((param_1->function_mode == '(') || (param_1->function_mode == '*'))
            goto LAB_00536221;
          }
          else {
            bVar20 = true;
LAB_00536221:
            if (bVar20) {
              this = param_1->player->visible;
              if ((this == (RGE_Visible_Map *)0x0) || (param_1->map->map_visible_flag != '\0')) {
                uStack_75 = RGE_Visible_Map::get_visible(this,(int)sVar19,(int)sVar23);
                if (uStack_75 == '\0') {
                  uStack_75 = 0x80;
                }
              }
              else {
                uStack_75 = RGE_Visible_Map::get_visible(this,(int)sVar19,(int)sVar23);
                if ((param_1->function_mode == '\x1e') || (param_1->function_mode == '\x1f')) {
                  uStack_75 = '\x0f';
                }
              }
              if ((param_1->function_mode == '\v') &&
                 (pRVar22 = param_1->map->map_row_offset[sVar23],
                 pRVar22[sVar19].draw_as == pRVar22[sVar19].last_drawn_as)) goto LAB_005362af;
            }
            else {
LAB_005362af:
              uStack_75 = '\0';
            }
            pRVar7 = pRStack_1c;
            if ((uStack_75 != '\x0f') && (uStack_75 != 0x80)) {
              uStack_75 = '\0';
            }
            if ((((uStack_75 != '\0') || (uVar1 = param_1->function_mode, uVar1 == '\x0e')) ||
                (uVar1 == '(')) || ((uVar1 == '<' || (uVar1 == '*')))) {
              if (bVar20) {
                pRVar3 = param_1->map->map_row_offset[sVar23];
                pRVar22 = pRVar3 + sVar19;
                uStack_38 = (uint)pRVar3[sVar19].tile_type;
                bVar12 = (byte)pRVar22->field_0x5 >> 5;
              }
              else {
                uStack_38 = 0;
                bVar12 = 0;
                pRVar22 = (RGE_Tile *)0x0;
              }
              sVar18 = sVar24 - (ushort)bVar12 * param_1->elev_hgt;
              switch(uStack_38) {
              case 2:
              case 6:
              case 8:
              case 10:
              case 0xe:
              case 0xf:
              case 0x10:
                sVar18 = sVar18 - param_1->elev_hgt;
              }
              if ((((param_1->_padding_ < (int)sVar21) || (param_1->_padding_ < (int)sVar18)) ||
                  (((int)param_1->map->tilesizes[uStack_38].width + (int)sVar21 <=
                    param_1->_padding_ ||
                   ((int)param_1->map->tilesizes[uStack_38].height + (int)sVar18 <=
                    param_1->_padding_)))) ||
                 ((param_1->function_mode == '\x0e' &&
                  ((((sVar19 < iStack_2c || (iStack_28 < sVar19)) || (sVar23 < iStack_24)) ||
                   (iStack_20 < sVar23)))))) {
                bVar20 = true;
              }
              else {
                bVar20 = false;
              }
              uVar1 = param_1->function_mode;
              if ((((uVar1 == '\n') || (uVar1 == '\x1e')) ||
                  (((uVar1 == '\x1f' || ((uVar1 == ' ' || (uVar1 == '\x15')))) || (uVar1 == '\v'))))
                 || (uVar1 == '\x0e')) {
                if ((!bVar20) &&
                   (((uVar1 = param_1->function_mode, uVar1 == '\n' || (uVar1 == '\v')) ||
                    (uVar1 == '\x0e')))) {
                  bVar12 = pRVar22->field_0x5;
                  pRVar14 = param_1->map;
                  bVar17 = bVar12 & 0x1f;
                  uStack_3c = bVar12 & 0xffffff1f;
                  sVar18 = pRVar14->terrain_types[bVar12 & 0x1f].terrain_to_draw;
                  if (sVar18 != -1) {
                    bVar17 = (byte)sVar18;
                    uStack_3c = (uint)bVar17;
                  }
                  if (((param_1->function_mode == '\n') && (param_1->calc_draw_count != 0)) &&
                     ((short)(ushort)bVar17 < pRVar14->num_terrain)) {
                    pRVar14->terrain_types[uStack_3c].drawn =
                         pRVar14->terrain_types[uStack_3c].drawn + '\x01';
                  }
                  if (param_1->function_mode == '\v') {
                    pRVar22->last_drawn_as = pRVar22->draw_as;
                  }
                }
                if (((uStack_75 == '\x0f') || (uStack_75 == 0x80)) &&
                   ((uVar1 = param_1->function_mode, uVar1 == '\x1e' ||
                    (((uVar1 == '\x1f' || (uVar1 == ' ')) || (uVar1 == '\x15')))))) {
                  if ((uStack_75 == '\x0f') ||
                     ((uStack_75 == 0x80 && (param_1->map->fog_flag == '\0')))) {
                    uStack_58 = '\0';
                  }
                  else {
                    uStack_58 = '\x01';
                  }
                  if (uVar1 == '\x1e') {
                    param_1->cur_render_area->CurSpanList = param_1->Terrain_Fog_Clip_Mask;
                    fog_next_shape = 1;
                    RGE_Object_List::shadow_draw
                              (&pRVar22->objects,param_1->cur_render_area,sVar21,sVar24,'\x01',
                               uStack_58);
                    param_1->cur_render_area->CurSpanList = param_1->Terrain_Clip_Mask;
                    fog_next_shape = 0;
                    RGE_Object_List::shadow_draw
                              (&pRVar22->objects,param_1->cur_render_area,sVar21,sVar24,'\x01',
                               uStack_58);
                    param_1->cur_render_area->CurSpanList = param_1->cur_render_area->SpanList;
                  }
                  if (param_1->function_mode == '\x1f') {
                    param_1->cur_render_area->CurSpanList = param_1->Terrain_Fog_Clip_Mask;
                    fog_next_shape = 1;
                    RGE_Object_List::shadow_draw
                              (&pRVar22->objects,param_1->cur_render_area,sVar21,sVar24,'\n',
                               uStack_58);
                    param_1->cur_render_area->CurSpanList = param_1->Terrain_Clip_Mask;
                    fog_next_shape = 0;
                    RGE_Object_List::shadow_draw
                              (&pRVar22->objects,param_1->cur_render_area,sVar21,sVar24,'\n',
                               uStack_58);
                    param_1->cur_render_area->CurSpanList = param_1->cur_render_area->SpanList;
                  }
                  if (param_1->function_mode == ' ') {
                    if ((param_1->map->fog_flag != '\0') && (uStack_75 == 0x80)) {
                      fog_next_shape = 1;
                    }
                    RGE_Object_List::shadow_draw
                              (&pRVar22->objects,param_1->cur_render_area,sVar21,sVar24,'\0',
                               uStack_58);
                  }
                  else {
                    if (param_1->function_mode != '\x15') goto LAB_005368a9;
                    if ((param_1->map->fog_flag != '\0') && (uStack_75 == 0x80)) {
                      fog_next_shape = 1;
                    }
                    RGE_Object_List::normal_draw
                              (&pRVar22->objects,param_1->cur_render_area,sVar21,sVar24,uStack_58);
                  }
                  fog_next_shape = 0;
                }
              }
              else {
                if (((uStack_75 == '\x0f') || (uStack_75 == 0x80)) &&
                   ((uVar1 == ')' || (((uVar1 == '*' || (uVar1 == '+')) || (uVar1 == ',')))))) {
                  if ((uStack_75 == '\x0f') ||
                     ((uStack_75 == 0x80 && (param_1->map->fog_flag == '\0')))) {
                    uStack_58 = '\0';
                  }
                  else {
                    uStack_58 = '\x01';
                  }
                  pRVar11 = RGE_View::hit_object
                                      (param_1,pRVar22,sVar21,sVar24,sVar19,sVar23,param_4,param_5,
                                       param_9,param_10,pRStack_1c,uStack_58);
                  if (pRVar11 != (RGE_Static_Object *)0x0) {
                    if (param_1->function_mode == ',') {
                      cVar5 = '4';
                    }
                    else {
                      if (((pRVar7 != (RGE_Static_Object *)0x0) && (pRVar11 == pRVar7)) &&
                         (cVar5 == '4')) {
                        *param_6 = pRStack_40;
                        return '4';
                      }
                      if (((pRStack_40 == (RGE_Static_Object *)0x0) ||
                          (pRStack_40->master_obj->select_level <= pRVar11->master_obj->select_level
                          )) || ((pRStack_40 == pRVar7 && (pRVar11 != pRVar7)))) {
                        *param_7 = pRVar11->world_x;
                        *param_8 = pRVar11->world_y;
                        cVar5 = '4';
                        pRStack_40 = pRVar11;
                      }
                    }
                  }
                }
                uVar1 = param_1->function_mode;
                if ((uVar1 == '(') || ((uVar1 == '*' && (cVar5 == '2')))) {
                  iVar25 = RGE_View::hit_tile(param_1,pRVar22,sVar21,sVar18,sVar19,sVar23,param_4);
                  if (iVar25 != 0) {
                    if (pRVar22 == (RGE_Tile *)0x0) {
                      *param_7 = (float)(int)sVar19;
                      fVar4 = (float)(int)sVar23;
                    }
                    else {
                      RGE_Map::tile_map_coords
                                (param_1->map,(short)param_4->x - sVar21,(short)param_4->y - sVar18,
                                 pRVar22,param_7,param_8);
                      *param_7 = (float)(int)sVar19 + *param_7;
                      fVar4 = (float)(int)sVar23 + *param_8;
                    }
                    *param_8 = fVar4;
                    *param_9 = sVar21;
                    cVar5 = '3';
                    *param_10 = sVar18;
                    *param_6 = pRVar22;
                  }
                }
                else if (((uVar1 == '<') && (sVar19 == (short)uStack_18)) &&
                        (sVar23 == (short)uStack_14)) {
                  *param_7 = (float)(int)sVar19;
                  *param_8 = (float)(int)sVar23;
                  *param_9 = sVar21;
                  *param_10 = sVar18;
                  *param_6 = pRVar22;
                  return '3';
                }
              }
            }
          }
LAB_005368a9:
          sVar21 = sVar21 + param_1->tile_wid;
          sVar19 = sVar19 + 1;
          sVar23 = sVar23 + 1;
          sVar8 = sVar8 + 1;
        } while (sVar8 < (short)iStack_60);
      }
      if ((cVar6 == '\x01') && ((short)iStack_60 == (short)iStack_10)) {
        cVar6 = '\x02';
      }
                    /* WARNING: Could not find normalized switch variable to match jumptable */
      switch(cVar6) {
      case '\x03':
        iStack_60 = iStack_60 + -1;
        sVar16 = sVar16 + param_1->tile_half_wid;
        sVar9 = sVar9 + 1;
        break;
      case '\x05':
                    /* WARNING: This code block may not be properly labeled as switch case */
        sVar16 = sVar16 + param_1->tile_half_wid;
        sVar9 = sVar9 + 1;
        cVar6 = '\x03';
      }
      sVar24 = sVar24 + param_1->tile_half_hgt;
      sVar10 = sVar10 + 1;
    } while (sVar10 < (short)iStack_c);
  }
  if (param_1->function_mode == '\n') {
    pRVar14 = param_1->map;
    sVar16 = 0;
    if (0 < pRVar14->num_terrain) {
      do {
        iVar25 = (int)sVar16;
        sVar16 = sVar16 + 1;
        pRVar14->terrain_types[iVar25].frame_changed = '\0';
        pRVar14 = param_1->map;
      } while (sVar16 < pRVar14->num_terrain);
    }
  }
  uVar1 = param_1->function_mode;
  if ((((uVar1 == ')') || (uVar1 == '*')) || (uVar1 == '+')) && (cVar5 == '4')) {
    *param_6 = pRStack_40;
  }
  return cVar5;
}

// --------------------------------------------------

// Function: FUN_00536912
// Address: 00536912
char FUN_00536912(void)
{
  uchar uVar1;
  RGE_Visible_Map *this;
  RGE_Tile *pRVar2;
  float fVar3;
  RGE_Map *pRVar4;
  byte bVar5;
  short sVar6;
  RGE_Map *pRVar7;
  undefined4 extraout_ECX;
  RGE_Map *extraout_ECX_00;
  RGE_Map *extraout_ECX_01;
  RGE_Map *extraout_ECX_02;
  RGE_Map *extraout_ECX_03;
  RGE_Map *extraout_ECX_04;
  RGE_Map *extraout_ECX_05;
  short sVar8;
  short sVar9;
  byte bVar10;
  bool bVar11;
  RGE_Tile *pRVar12;
  RGE_View *unaff_ESI;
  int iVar13;
  uchar uStack00000013;
  short sStack00000014;
  short sStack00000018;
  short sStack0000001c;
  short sStack00000020;
  undefined2 uStack00000022;
  short in_stack_00000024;
  short sStack00000028;
  char in_stack_0000002c;
  uchar uStack00000030;
  RGE_Map *in_stack_00000038;
  RGE_Map *in_stack_0000003c;
  char in_stack_00000040;
  RGE_Map *in_stack_00000048;
  uint uStack0000004c;
  uint uStack00000050;
  int iStack00000054;
  short in_stack_00000058;
  int in_stack_0000005c;
  int in_stack_00000060;
  int in_stack_00000064;
  int in_stack_00000068;
  RGE_Map *in_stack_0000006c;
  short in_stack_00000070;
  short in_stack_00000074;
  short in_stack_00000078;
  short in_stack_0000007c;
  tagPOINT *in_stack_00000094;
  tagPOINT *in_stack_00000098;
  undefined4 *in_stack_0000009c;
  float *in_stack_000000a0;
  float *in_stack_000000a4;
  short *in_stack_000000a8;
  short *in_stack_000000ac;
  
code_r0x00536912:
  _sStack00000020 = CONCAT22(uStack00000022,sStack00000020 - unaff_ESI->tile_half_wid);
  _sStack00000028 = _sStack00000028 + 1;
  in_stack_00000038 = (RGE_Map *)((int)&in_stack_00000038[-1].unit_manager + 3);
  goto switchD_0053690b_default;
  do {
    switch(in_stack_00000040) {
    case '\x01':
      goto code_r0x00536912;
    case '\x02':
      _sStack00000028 = _sStack00000028 + -1;
      _sStack00000020 =
           _sStack00000020 +
           CONCAT22((short)((uint)_sStack00000028 >> 0x10),unaff_ESI->tile_half_wid);
      in_stack_0000003c = (RGE_Map *)((int)&in_stack_0000003c->_padding_ + 1);
    default:
switchD_0053690b_default:
      in_stack_00000024 = in_stack_00000024 + unaff_ESI->tile_half_hgt;
      in_stack_00000058 = in_stack_00000058 + 1;
      if (in_stack_0000007c <= in_stack_00000058) {
        if (unaff_ESI->function_mode == '\n') {
          pRVar7 = unaff_ESI->map;
          sVar9 = 0;
          if (0 < pRVar7->num_terrain) {
            do {
              iVar13 = (int)sVar9;
              sVar9 = sVar9 + 1;
              pRVar7->terrain_types[iVar13].frame_changed = '\0';
              pRVar7 = unaff_ESI->map;
            } while (sVar9 < pRVar7->num_terrain);
          }
        }
        uVar1 = unaff_ESI->function_mode;
        if ((((uVar1 == ')') || (uVar1 == '*')) || (uVar1 == '+')) && (in_stack_0000002c == '4')) {
          *in_stack_0000009c = in_stack_00000048;
        }
        return in_stack_0000002c;
      }
      _sStack00000014 = _sStack00000020;
      _sStack0000001c = in_stack_00000038;
      _sStack00000018 = in_stack_0000003c;
      iStack00000054 = 0;
      pRVar7 = in_stack_0000003c;
      if (0 < sStack00000028) {
        do {
          sVar8 = (short)_sStack0000001c;
          sVar9 = (short)_sStack00000018;
          if (((sVar8 < 0) || (pRVar7 = unaff_ESI->map, (int)pRVar7->map_width <= (int)sVar8)) ||
             ((sVar9 < 0 || ((int)pRVar7->map_height <= (int)sVar9)))) {
            uVar1 = unaff_ESI->function_mode;
            pRVar7 = (RGE_Map *)CONCAT31((int3)((uint)pRVar7 >> 8),uVar1);
            bVar11 = false;
            if ((uVar1 == '(') || (uVar1 == '*')) goto LAB_00536221;
          }
          else {
            bVar11 = true;
LAB_00536221:
            if (bVar11) {
              this = unaff_ESI->player->visible;
              if ((this == (RGE_Visible_Map *)0x0) || (unaff_ESI->map->map_visible_flag != '\0')) {
                uStack00000013 = RGE_Visible_Map::get_visible(this,(int)sVar8,(int)sVar9);
                pRVar7 = extraout_ECX_00;
                if (uStack00000013 == '\0') {
                  uStack00000013 = 0x80;
                }
              }
              else {
                uStack00000013 = RGE_Visible_Map::get_visible(this,(int)sVar8,(int)sVar9);
                uVar1 = unaff_ESI->function_mode;
                pRVar7 = (RGE_Map *)CONCAT31((int3)((uint)extraout_ECX >> 8),uVar1);
                if ((uVar1 == '\x1e') || (uVar1 == '\x1f')) {
                  uStack00000013 = '\x0f';
                }
              }
              if ((unaff_ESI->function_mode == '\v') &&
                 (pRVar12 = unaff_ESI->map->map_row_offset[sVar9],
                 pRVar7 = (RGE_Map *)(pRVar12 + sVar8),
                 pRVar12[sVar8].draw_as == *(uchar *)((int)&pRVar7->map + 3))) goto LAB_005362af;
            }
            else {
LAB_005362af:
              uStack00000013 = '\0';
            }
            if ((uStack00000013 != '\x0f') && (uStack00000013 != 0x80)) {
              uStack00000013 = '\0';
            }
            if (uStack00000013 == '\0') {
              uVar1 = unaff_ESI->function_mode;
              if ((((uVar1 != '\x0e') && (uVar1 != '(')) && (uVar1 != '<')) &&
                 (pRVar7 = (RGE_Map *)CONCAT31((int3)((uint)pRVar7 >> 8),uVar1), uVar1 != '*'))
              goto LAB_005368a9;
            }
            if (bVar11) {
              pRVar2 = unaff_ESI->map->map_row_offset[sStack00000018];
              pRVar12 = pRVar2 + sStack0000001c;
              uStack00000050 = (uint)pRVar2[sStack0000001c].tile_type;
              bVar5 = (byte)pRVar12->field_0x5 >> 5;
            }
            else {
              uStack00000050 = 0;
              bVar5 = 0;
              pRVar12 = (RGE_Tile *)0x0;
            }
            sVar9 = in_stack_00000024 - (ushort)bVar5 * unaff_ESI->elev_hgt;
            switch(uStack00000050) {
            case 2:
            case 6:
            case 8:
            case 10:
            case 0xe:
            case 0xf:
            case 0x10:
              sVar9 = sVar9 - unaff_ESI->elev_hgt;
            }
            if ((((unaff_ESI->_padding_ < (int)sStack00000014) ||
                 (unaff_ESI->_padding_ < (int)sVar9)) ||
                (((int)unaff_ESI->map->tilesizes[uStack00000050].width + (int)sStack00000014 <=
                  unaff_ESI->_padding_ ||
                 (uStack00000050 =
                       (int)unaff_ESI->map->tilesizes[uStack00000050].height + (int)sVar9,
                 (int)uStack00000050 <= unaff_ESI->_padding_)))) ||
               ((unaff_ESI->function_mode == '\x0e' &&
                (((sStack0000001c < in_stack_0000005c || (in_stack_00000060 < sStack0000001c)) ||
                 ((sStack00000018 < in_stack_00000064 || (in_stack_00000068 < sStack00000018))))))))
{
              bVar11 = true;
            }
            else {
              bVar11 = false;
            }
            uVar1 = unaff_ESI->function_mode;
            pRVar7 = (RGE_Map *)CONCAT31((int3)(uStack00000050 >> 8),uVar1);
            if ((((uVar1 == '\n') || (uVar1 == '\x1e')) || (uVar1 == '\x1f')) ||
               (((uVar1 == ' ' || (uVar1 == '\x15')) || ((uVar1 == '\v' || (uVar1 == '\x0e')))))) {
              if ((!bVar11) &&
                 (((uVar1 = unaff_ESI->function_mode, uVar1 == '\n' || (uVar1 == '\v')) ||
                  (uVar1 == '\x0e')))) {
                bVar5 = pRVar12->field_0x5;
                pRVar7 = unaff_ESI->map;
                bVar10 = bVar5 & 0x1f;
                uStack0000004c = bVar5 & 0xffffff1f;
                sVar9 = pRVar7->terrain_types[bVar5 & 0x1f].terrain_to_draw;
                if (sVar9 != -1) {
                  bVar10 = (byte)sVar9;
                  uStack0000004c = (uint)bVar10;
                }
                if (((unaff_ESI->function_mode == '\n') && (unaff_ESI->calc_draw_count != 0)) &&
                   ((short)(ushort)bVar10 < pRVar7->num_terrain)) {
                  pRVar7->terrain_types[uStack0000004c].drawn =
                       pRVar7->terrain_types[uStack0000004c].drawn + '\x01';
                }
                pRVar7 = (RGE_Map *)0x0;
                if (unaff_ESI->function_mode == '\v') {
                  pRVar12->last_drawn_as = pRVar12->draw_as;
                }
              }
              if (((uStack00000013 == '\x0f') || (uStack00000013 == 0x80)) &&
                 (((uVar1 = unaff_ESI->function_mode, uVar1 == '\x1e' ||
                   ((uVar1 == '\x1f' || (uVar1 == ' ')))) || (uVar1 == '\x15')))) {
                pRVar7 = (RGE_Map *)CONCAT31((int3)((uint)pRVar7 >> 8),uStack00000013);
                if ((uStack00000013 == '\x0f') ||
                   ((uStack00000013 == 0x80 && (pRVar7 = unaff_ESI->map, pRVar7->fog_flag == '\0')))
                   ) {
                  uStack00000030 = '\0';
                }
                else {
                  uStack00000030 = '\x01';
                }
                if (uVar1 == '\x1e') {
                  unaff_ESI->cur_render_area->CurSpanList = unaff_ESI->Terrain_Fog_Clip_Mask;
                  fog_next_shape = 1;
                  RGE_Object_List::shadow_draw
                            (&pRVar12->objects,unaff_ESI->cur_render_area,sStack00000014,
                             in_stack_00000024,'\x01',uStack00000030);
                  unaff_ESI->cur_render_area->CurSpanList = unaff_ESI->Terrain_Clip_Mask;
                  fog_next_shape = 0;
                  RGE_Object_List::shadow_draw
                            (&pRVar12->objects,unaff_ESI->cur_render_area,(short)_sStack00000014,
                             in_stack_00000024,'\x01',uStack00000030);
                  unaff_ESI->cur_render_area->CurSpanList = unaff_ESI->cur_render_area->SpanList;
                  pRVar7 = extraout_ECX_03;
                }
                if (unaff_ESI->function_mode == '\x1f') {
                  unaff_ESI->cur_render_area->CurSpanList = unaff_ESI->Terrain_Fog_Clip_Mask;
                  fog_next_shape = 1;
                  RGE_Object_List::shadow_draw
                            (&pRVar12->objects,unaff_ESI->cur_render_area,(short)_sStack00000014,
                             in_stack_00000024,'\n',uStack00000030);
                  unaff_ESI->cur_render_area->CurSpanList = unaff_ESI->Terrain_Clip_Mask;
                  fog_next_shape = 0;
                  RGE_Object_List::shadow_draw
                            (&pRVar12->objects,unaff_ESI->cur_render_area,(short)_sStack00000014,
                             in_stack_00000024,'\n',uStack00000030);
                  pRVar7 = (RGE_Map *)unaff_ESI->cur_render_area->SpanList;
                  unaff_ESI->cur_render_area->CurSpanList = (TSpan_List_Manager *)pRVar7;
                }
                if (unaff_ESI->function_mode == ' ') {
                  if ((unaff_ESI->map->fog_flag != '\0') && (uStack00000013 == 0x80)) {
                    fog_next_shape = 1;
                  }
                  RGE_Object_List::shadow_draw
                            (&pRVar12->objects,unaff_ESI->cur_render_area,(short)_sStack00000014,
                             in_stack_00000024,'\0',uStack00000030);
                  pRVar7 = extraout_ECX_04;
                }
                else {
                  if (unaff_ESI->function_mode != '\x15') goto LAB_005368a9;
                  if ((unaff_ESI->map->fog_flag != '\0') && (uStack00000013 == 0x80)) {
                    fog_next_shape = 1;
                  }
                  RGE_Object_List::normal_draw
                            (&pRVar12->objects,unaff_ESI->cur_render_area,(short)_sStack00000014,
                             in_stack_00000024,uStack00000030);
                  pRVar7 = extraout_ECX_05;
                }
                fog_next_shape = 0;
              }
            }
            else {
              if (((uStack00000013 == '\x0f') || (uStack00000013 == 0x80)) &&
                 ((uVar1 == ')' || (((uVar1 == '*' || (uVar1 == '+')) || (uVar1 == ',')))))) {
                if ((uStack00000013 == '\x0f') ||
                   ((uStack00000013 == 0x80 && (unaff_ESI->map->fog_flag == '\0')))) {
                  uStack00000030 = '\0';
                }
                else {
                  uStack00000030 = '\x01';
                }
                pRVar4 = (RGE_Map *)
                         RGE_View::hit_object
                                   (unaff_ESI,pRVar12,sStack00000014,in_stack_00000024,
                                    sStack0000001c,sStack00000018,in_stack_00000094,
                                    in_stack_00000098,in_stack_000000a8,in_stack_000000ac,
                                    (RGE_Static_Object *)in_stack_0000006c,uStack00000030);
                pRVar7 = extraout_ECX_01;
                if (pRVar4 != (RGE_Map *)0x0) {
                  if (unaff_ESI->function_mode == ',') {
                    in_stack_0000002c = '4';
                    pRVar7 = extraout_ECX_01;
                  }
                  else {
                    if (((in_stack_0000006c != (RGE_Map *)0x0) && (pRVar4 == in_stack_0000006c)) &&
                       (in_stack_0000002c == '4')) {
                      *in_stack_0000009c = in_stack_00000048;
                      return '4';
                    }
                    if (((in_stack_00000048 == (RGE_Map *)0x0) ||
                        (((RGE_Master_Static_Object *)in_stack_00000048->map_width)->select_level <=
                         ((RGE_Master_Static_Object *)pRVar4->map_width)->select_level)) ||
                       ((pRVar7 = in_stack_00000048, in_stack_00000048 == in_stack_0000006c &&
                        (pRVar4 != in_stack_0000006c)))) {
                      pRVar7 = *(RGE_Map **)&pRVar4->tilesizes[5].height;
                      *in_stack_000000a0 = (float)pRVar7;
                      *in_stack_000000a4 = *(float *)(pRVar4->tilesizes + 6);
                      in_stack_0000002c = '4';
                      in_stack_00000048 = pRVar4;
                    }
                  }
                }
              }
              uVar1 = unaff_ESI->function_mode;
              sVar6 = (short)_sStack0000001c;
              sVar8 = (short)_sStack00000018;
              if ((uVar1 == '(') || ((uVar1 == '*' && (in_stack_0000002c == '2')))) {
                iVar13 = RGE_View::hit_tile(unaff_ESI,pRVar12,sStack00000014,sVar9,sVar6,sVar8,
                                            in_stack_00000094);
                pRVar7 = extraout_ECX_02;
                if (iVar13 != 0) {
                  if (pRVar12 == (RGE_Tile *)0x0) {
                    iVar13 = (int)sStack00000018;
                    *in_stack_000000a0 = (float)(int)sStack0000001c;
                    fVar3 = (float)iVar13;
                  }
                  else {
                    RGE_Map::tile_map_coords
                              (unaff_ESI->map,(short)in_stack_00000094->x - sStack00000014,
                               (short)in_stack_00000094->y - sVar9,pRVar12,in_stack_000000a0,
                               in_stack_000000a4);
                    iVar13 = (int)sStack0000001c;
                    *in_stack_000000a0 = (float)iVar13 + *in_stack_000000a0;
                    fVar3 = (float)(int)sStack00000018 + *in_stack_000000a4;
                  }
                  *in_stack_000000a4 = fVar3;
                  *in_stack_000000a8 = sStack00000014;
                  in_stack_0000002c = '3';
                  *in_stack_000000ac = sVar9;
                  *in_stack_0000009c = pRVar12;
                  pRVar7 = (RGE_Map *)CONCAT22((short)((uint)iVar13 >> 0x10),sVar9);
                }
              }
              else if (((uVar1 == '<') && (pRVar7 = _sStack0000001c, sVar6 == in_stack_00000070)) &&
                      (sVar8 == in_stack_00000074)) {
                *in_stack_000000a0 = (float)(int)sVar6;
                *in_stack_000000a4 = (float)(int)sVar8;
                *in_stack_000000a8 = sStack00000014;
                *in_stack_000000ac = sVar9;
                *in_stack_0000009c = pRVar12;
                return '3';
              }
            }
          }
LAB_005368a9:
          pRVar7 = (RGE_Map *)CONCAT22((short)((uint)pRVar7 >> 0x10),unaff_ESI->tile_wid);
          _sStack00000014 = (int)&((RGE_Map *)(pRVar7->tilesizes + -4))->_padding_ + _sStack00000014
          ;
          _sStack0000001c = (RGE_Map *)((int)&_sStack0000001c->_padding_ + 1);
          _sStack00000018 = (RGE_Map *)((int)&_sStack00000018->_padding_ + 1);
          iStack00000054 = iStack00000054 + 1;
        } while ((short)iStack00000054 < sStack00000028);
      }
      if ((in_stack_00000040 == '\x01') && (sStack00000028 == in_stack_00000078)) {
        in_stack_00000040 = '\x02';
      }
      break;
    case '\x03':
      in_stack_00000040 = '\x04';
      _sStack00000020 = CONCAT22(uStack00000022,sStack00000020 - unaff_ESI->tile_half_wid);
      in_stack_00000038 = (RGE_Map *)((int)&in_stack_00000038[-1].unit_manager + 3);
      break;
    case '\x04':
      _sStack00000020 =
           _sStack00000020 + CONCAT22((short)((uint)pRVar7 >> 0x10),unaff_ESI->tile_half_wid);
      in_stack_0000003c = (RGE_Map *)((int)&in_stack_0000003c->_padding_ + 1);
      in_stack_00000040 = '\x03';
      break;
    }
  } while( true );
}

// --------------------------------------------------

// Function: FUN_00536957
// Address: 00536957
char FUN_00536957(void)
{
  uchar uVar1;
  RGE_Visible_Map *this;
  RGE_Tile *pRVar2;
  float fVar3;
  char cVar4;
  RGE_Map *pRVar5;
  byte bVar6;
  short sVar7;
  RGE_Map *pRVar8;
  undefined4 extraout_ECX;
  RGE_Map *extraout_ECX_00;
  RGE_Map *extraout_ECX_01;
  RGE_Map *extraout_ECX_02;
  RGE_Map *extraout_ECX_03;
  RGE_Map *extraout_ECX_04;
  RGE_Map *extraout_ECX_05;
  short sVar9;
  short sVar10;
  byte bVar11;
  bool bVar12;
  RGE_Tile *pRVar13;
  RGE_View *unaff_ESI;
  int iVar14;
  uchar uStack00000013;
  short sStack00000014;
  short sStack00000018;
  short sStack0000001c;
  short sStack00000020;
  undefined2 uStack00000022;
  short in_stack_00000024;
  short sStack00000028;
  char in_stack_0000002c;
  uchar uStack00000030;
  RGE_Map *in_stack_00000038;
  RGE_Map *in_stack_0000003c;
  RGE_Map *in_stack_00000048;
  uint uStack0000004c;
  uint uStack00000050;
  int iStack00000054;
  short in_stack_00000058;
  int in_stack_0000005c;
  int in_stack_00000060;
  int in_stack_00000064;
  int in_stack_00000068;
  RGE_Map *in_stack_0000006c;
  short in_stack_00000070;
  short in_stack_00000074;
  short in_stack_00000078;
  short in_stack_0000007c;
  tagPOINT *in_stack_00000094;
  tagPOINT *in_stack_00000098;
  undefined4 *in_stack_0000009c;
  float *in_stack_000000a0;
  float *in_stack_000000a4;
  short *in_stack_000000a8;
  short *in_stack_000000ac;
  
code_r0x00536957:
  cVar4 = '\x04';
  _sStack00000020 = CONCAT22(uStack00000022,sStack00000020 - unaff_ESI->tile_half_wid);
  in_stack_00000038 = (RGE_Map *)((int)&in_stack_00000038[-1].unit_manager + 3);
  goto switchD_0053690b_default;
  do {
    switch(cVar4) {
    case '\x01':
      _sStack00000020 = CONCAT22(uStack00000022,sStack00000020 - unaff_ESI->tile_half_wid);
      _sStack00000028 = _sStack00000028 + 1;
      in_stack_00000038 = (RGE_Map *)((int)&in_stack_00000038[-1].unit_manager + 3);
    default:
switchD_0053690b_default:
      in_stack_00000024 = in_stack_00000024 + unaff_ESI->tile_half_hgt;
      in_stack_00000058 = in_stack_00000058 + 1;
      if (in_stack_0000007c <= in_stack_00000058) {
        if (unaff_ESI->function_mode == '\n') {
          pRVar8 = unaff_ESI->map;
          sVar10 = 0;
          if (0 < pRVar8->num_terrain) {
            do {
              iVar14 = (int)sVar10;
              sVar10 = sVar10 + 1;
              pRVar8->terrain_types[iVar14].frame_changed = '\0';
              pRVar8 = unaff_ESI->map;
            } while (sVar10 < pRVar8->num_terrain);
          }
        }
        uVar1 = unaff_ESI->function_mode;
        if ((((uVar1 == ')') || (uVar1 == '*')) || (uVar1 == '+')) && (in_stack_0000002c == '4')) {
          *in_stack_0000009c = in_stack_00000048;
        }
        return in_stack_0000002c;
      }
      _sStack00000014 = _sStack00000020;
      _sStack0000001c = in_stack_00000038;
      _sStack00000018 = in_stack_0000003c;
      iStack00000054 = 0;
      pRVar8 = in_stack_0000003c;
      if (0 < sStack00000028) {
        do {
          sVar9 = (short)_sStack0000001c;
          sVar10 = (short)_sStack00000018;
          if (((sVar9 < 0) || (pRVar8 = unaff_ESI->map, (int)pRVar8->map_width <= (int)sVar9)) ||
             ((sVar10 < 0 || ((int)pRVar8->map_height <= (int)sVar10)))) {
            uVar1 = unaff_ESI->function_mode;
            pRVar8 = (RGE_Map *)CONCAT31((int3)((uint)pRVar8 >> 8),uVar1);
            bVar12 = false;
            if ((uVar1 == '(') || (uVar1 == '*')) goto LAB_00536221;
          }
          else {
            bVar12 = true;
LAB_00536221:
            if (bVar12) {
              this = unaff_ESI->player->visible;
              if ((this == (RGE_Visible_Map *)0x0) || (unaff_ESI->map->map_visible_flag != '\0')) {
                uStack00000013 = RGE_Visible_Map::get_visible(this,(int)sVar9,(int)sVar10);
                pRVar8 = extraout_ECX_00;
                if (uStack00000013 == '\0') {
                  uStack00000013 = 0x80;
                }
              }
              else {
                uStack00000013 = RGE_Visible_Map::get_visible(this,(int)sVar9,(int)sVar10);
                uVar1 = unaff_ESI->function_mode;
                pRVar8 = (RGE_Map *)CONCAT31((int3)((uint)extraout_ECX >> 8),uVar1);
                if ((uVar1 == '\x1e') || (uVar1 == '\x1f')) {
                  uStack00000013 = '\x0f';
                }
              }
              if ((unaff_ESI->function_mode == '\v') &&
                 (pRVar13 = unaff_ESI->map->map_row_offset[sVar10],
                 pRVar8 = (RGE_Map *)(pRVar13 + sVar9),
                 pRVar13[sVar9].draw_as == *(uchar *)((int)&pRVar8->map + 3))) goto LAB_005362af;
            }
            else {
LAB_005362af:
              uStack00000013 = '\0';
            }
            if ((uStack00000013 != '\x0f') && (uStack00000013 != 0x80)) {
              uStack00000013 = '\0';
            }
            if (uStack00000013 == '\0') {
              uVar1 = unaff_ESI->function_mode;
              if ((((uVar1 != '\x0e') && (uVar1 != '(')) && (uVar1 != '<')) &&
                 (pRVar8 = (RGE_Map *)CONCAT31((int3)((uint)pRVar8 >> 8),uVar1), uVar1 != '*'))
              goto LAB_005368a9;
            }
            if (bVar12) {
              pRVar2 = unaff_ESI->map->map_row_offset[sStack00000018];
              pRVar13 = pRVar2 + sStack0000001c;
              uStack00000050 = (uint)pRVar2[sStack0000001c].tile_type;
              bVar6 = (byte)pRVar13->field_0x5 >> 5;
            }
            else {
              uStack00000050 = 0;
              bVar6 = 0;
              pRVar13 = (RGE_Tile *)0x0;
            }
            sVar10 = in_stack_00000024 - (ushort)bVar6 * unaff_ESI->elev_hgt;
            switch(uStack00000050) {
            case 2:
            case 6:
            case 8:
            case 10:
            case 0xe:
            case 0xf:
            case 0x10:
              sVar10 = sVar10 - unaff_ESI->elev_hgt;
            }
            if ((((unaff_ESI->_padding_ < (int)sStack00000014) ||
                 (unaff_ESI->_padding_ < (int)sVar10)) ||
                (((int)unaff_ESI->map->tilesizes[uStack00000050].width + (int)sStack00000014 <=
                  unaff_ESI->_padding_ ||
                 (uStack00000050 =
                       (int)unaff_ESI->map->tilesizes[uStack00000050].height + (int)sVar10,
                 (int)uStack00000050 <= unaff_ESI->_padding_)))) ||
               ((unaff_ESI->function_mode == '\x0e' &&
                (((sStack0000001c < in_stack_0000005c || (in_stack_00000060 < sStack0000001c)) ||
                 ((sStack00000018 < in_stack_00000064 || (in_stack_00000068 < sStack00000018))))))))
{
              bVar12 = true;
            }
            else {
              bVar12 = false;
            }
            uVar1 = unaff_ESI->function_mode;
            pRVar8 = (RGE_Map *)CONCAT31((int3)(uStack00000050 >> 8),uVar1);
            if ((((uVar1 == '\n') || (uVar1 == '\x1e')) || (uVar1 == '\x1f')) ||
               (((uVar1 == ' ' || (uVar1 == '\x15')) || ((uVar1 == '\v' || (uVar1 == '\x0e')))))) {
              if ((!bVar12) &&
                 (((uVar1 = unaff_ESI->function_mode, uVar1 == '\n' || (uVar1 == '\v')) ||
                  (uVar1 == '\x0e')))) {
                bVar6 = pRVar13->field_0x5;
                pRVar8 = unaff_ESI->map;
                bVar11 = bVar6 & 0x1f;
                uStack0000004c = bVar6 & 0xffffff1f;
                sVar10 = pRVar8->terrain_types[bVar6 & 0x1f].terrain_to_draw;
                if (sVar10 != -1) {
                  bVar11 = (byte)sVar10;
                  uStack0000004c = (uint)bVar11;
                }
                if (((unaff_ESI->function_mode == '\n') && (unaff_ESI->calc_draw_count != 0)) &&
                   ((short)(ushort)bVar11 < pRVar8->num_terrain)) {
                  pRVar8->terrain_types[uStack0000004c].drawn =
                       pRVar8->terrain_types[uStack0000004c].drawn + '\x01';
                }
                pRVar8 = (RGE_Map *)0x0;
                if (unaff_ESI->function_mode == '\v') {
                  pRVar13->last_drawn_as = pRVar13->draw_as;
                }
              }
              if (((uStack00000013 == '\x0f') || (uStack00000013 == 0x80)) &&
                 (((uVar1 = unaff_ESI->function_mode, uVar1 == '\x1e' ||
                   ((uVar1 == '\x1f' || (uVar1 == ' ')))) || (uVar1 == '\x15')))) {
                pRVar8 = (RGE_Map *)CONCAT31((int3)((uint)pRVar8 >> 8),uStack00000013);
                if ((uStack00000013 == '\x0f') ||
                   ((uStack00000013 == 0x80 && (pRVar8 = unaff_ESI->map, pRVar8->fog_flag == '\0')))
                   ) {
                  uStack00000030 = '\0';
                }
                else {
                  uStack00000030 = '\x01';
                }
                if (uVar1 == '\x1e') {
                  unaff_ESI->cur_render_area->CurSpanList = unaff_ESI->Terrain_Fog_Clip_Mask;
                  fog_next_shape = 1;
                  RGE_Object_List::shadow_draw
                            (&pRVar13->objects,unaff_ESI->cur_render_area,sStack00000014,
                             in_stack_00000024,'\x01',uStack00000030);
                  unaff_ESI->cur_render_area->CurSpanList = unaff_ESI->Terrain_Clip_Mask;
                  fog_next_shape = 0;
                  RGE_Object_List::shadow_draw
                            (&pRVar13->objects,unaff_ESI->cur_render_area,(short)_sStack00000014,
                             in_stack_00000024,'\x01',uStack00000030);
                  unaff_ESI->cur_render_area->CurSpanList = unaff_ESI->cur_render_area->SpanList;
                  pRVar8 = extraout_ECX_03;
                }
                if (unaff_ESI->function_mode == '\x1f') {
                  unaff_ESI->cur_render_area->CurSpanList = unaff_ESI->Terrain_Fog_Clip_Mask;
                  fog_next_shape = 1;
                  RGE_Object_List::shadow_draw
                            (&pRVar13->objects,unaff_ESI->cur_render_area,(short)_sStack00000014,
                             in_stack_00000024,'\n',uStack00000030);
                  unaff_ESI->cur_render_area->CurSpanList = unaff_ESI->Terrain_Clip_Mask;
                  fog_next_shape = 0;
                  RGE_Object_List::shadow_draw
                            (&pRVar13->objects,unaff_ESI->cur_render_area,(short)_sStack00000014,
                             in_stack_00000024,'\n',uStack00000030);
                  pRVar8 = (RGE_Map *)unaff_ESI->cur_render_area->SpanList;
                  unaff_ESI->cur_render_area->CurSpanList = (TSpan_List_Manager *)pRVar8;
                }
                if (unaff_ESI->function_mode == ' ') {
                  if ((unaff_ESI->map->fog_flag != '\0') && (uStack00000013 == 0x80)) {
                    fog_next_shape = 1;
                  }
                  RGE_Object_List::shadow_draw
                            (&pRVar13->objects,unaff_ESI->cur_render_area,(short)_sStack00000014,
                             in_stack_00000024,'\0',uStack00000030);
                  pRVar8 = extraout_ECX_04;
                }
                else {
                  if (unaff_ESI->function_mode != '\x15') goto LAB_005368a9;
                  if ((unaff_ESI->map->fog_flag != '\0') && (uStack00000013 == 0x80)) {
                    fog_next_shape = 1;
                  }
                  RGE_Object_List::normal_draw
                            (&pRVar13->objects,unaff_ESI->cur_render_area,(short)_sStack00000014,
                             in_stack_00000024,uStack00000030);
                  pRVar8 = extraout_ECX_05;
                }
                fog_next_shape = 0;
              }
            }
            else {
              if (((uStack00000013 == '\x0f') || (uStack00000013 == 0x80)) &&
                 ((uVar1 == ')' || (((uVar1 == '*' || (uVar1 == '+')) || (uVar1 == ',')))))) {
                if ((uStack00000013 == '\x0f') ||
                   ((uStack00000013 == 0x80 && (unaff_ESI->map->fog_flag == '\0')))) {
                  uStack00000030 = '\0';
                }
                else {
                  uStack00000030 = '\x01';
                }
                pRVar5 = (RGE_Map *)
                         RGE_View::hit_object
                                   (unaff_ESI,pRVar13,sStack00000014,in_stack_00000024,
                                    sStack0000001c,sStack00000018,in_stack_00000094,
                                    in_stack_00000098,in_stack_000000a8,in_stack_000000ac,
                                    (RGE_Static_Object *)in_stack_0000006c,uStack00000030);
                pRVar8 = extraout_ECX_01;
                if (pRVar5 != (RGE_Map *)0x0) {
                  if (unaff_ESI->function_mode == ',') {
                    in_stack_0000002c = '4';
                    pRVar8 = extraout_ECX_01;
                  }
                  else {
                    if (((in_stack_0000006c != (RGE_Map *)0x0) && (pRVar5 == in_stack_0000006c)) &&
                       (in_stack_0000002c == '4')) {
                      *in_stack_0000009c = in_stack_00000048;
                      return '4';
                    }
                    if (((in_stack_00000048 == (RGE_Map *)0x0) ||
                        (((RGE_Master_Static_Object *)in_stack_00000048->map_width)->select_level <=
                         ((RGE_Master_Static_Object *)pRVar5->map_width)->select_level)) ||
                       ((pRVar8 = in_stack_00000048, in_stack_00000048 == in_stack_0000006c &&
                        (pRVar5 != in_stack_0000006c)))) {
                      pRVar8 = *(RGE_Map **)&pRVar5->tilesizes[5].height;
                      *in_stack_000000a0 = (float)pRVar8;
                      *in_stack_000000a4 = *(float *)(pRVar5->tilesizes + 6);
                      in_stack_0000002c = '4';
                      in_stack_00000048 = pRVar5;
                    }
                  }
                }
              }
              uVar1 = unaff_ESI->function_mode;
              sVar7 = (short)_sStack0000001c;
              sVar9 = (short)_sStack00000018;
              if ((uVar1 == '(') || ((uVar1 == '*' && (in_stack_0000002c == '2')))) {
                iVar14 = RGE_View::hit_tile(unaff_ESI,pRVar13,sStack00000014,sVar10,sVar7,sVar9,
                                            in_stack_00000094);
                pRVar8 = extraout_ECX_02;
                if (iVar14 != 0) {
                  if (pRVar13 == (RGE_Tile *)0x0) {
                    iVar14 = (int)sStack00000018;
                    *in_stack_000000a0 = (float)(int)sStack0000001c;
                    fVar3 = (float)iVar14;
                  }
                  else {
                    RGE_Map::tile_map_coords
                              (unaff_ESI->map,(short)in_stack_00000094->x - sStack00000014,
                               (short)in_stack_00000094->y - sVar10,pRVar13,in_stack_000000a0,
                               in_stack_000000a4);
                    iVar14 = (int)sStack0000001c;
                    *in_stack_000000a0 = (float)iVar14 + *in_stack_000000a0;
                    fVar3 = (float)(int)sStack00000018 + *in_stack_000000a4;
                  }
                  *in_stack_000000a4 = fVar3;
                  *in_stack_000000a8 = sStack00000014;
                  in_stack_0000002c = '3';
                  *in_stack_000000ac = sVar10;
                  *in_stack_0000009c = pRVar13;
                  pRVar8 = (RGE_Map *)CONCAT22((short)((uint)iVar14 >> 0x10),sVar10);
                }
              }
              else if (((uVar1 == '<') && (pRVar8 = _sStack0000001c, sVar7 == in_stack_00000070)) &&
                      (sVar9 == in_stack_00000074)) {
                *in_stack_000000a0 = (float)(int)sVar7;
                *in_stack_000000a4 = (float)(int)sVar9;
                *in_stack_000000a8 = sStack00000014;
                *in_stack_000000ac = sVar10;
                *in_stack_0000009c = pRVar13;
                return '3';
              }
            }
          }
LAB_005368a9:
          pRVar8 = (RGE_Map *)CONCAT22((short)((uint)pRVar8 >> 0x10),unaff_ESI->tile_wid);
          _sStack00000014 = (int)&((RGE_Map *)(pRVar8->tilesizes + -4))->_padding_ + _sStack00000014
          ;
          _sStack0000001c = (RGE_Map *)((int)&_sStack0000001c->_padding_ + 1);
          _sStack00000018 = (RGE_Map *)((int)&_sStack00000018->_padding_ + 1);
          iStack00000054 = iStack00000054 + 1;
        } while ((short)iStack00000054 < sStack00000028);
      }
      if ((cVar4 == '\x01') && (sStack00000028 == in_stack_00000078)) {
        cVar4 = '\x02';
      }
      break;
    case '\x02':
      _sStack00000028 = _sStack00000028 + -1;
      _sStack00000020 =
           _sStack00000020 +
           CONCAT22((short)((uint)_sStack00000028 >> 0x10),unaff_ESI->tile_half_wid);
      in_stack_0000003c = (RGE_Map *)((int)&in_stack_0000003c->_padding_ + 1);
      break;
    case '\x03':
      goto code_r0x00536957;
    case '\x04':
      _sStack00000020 =
           _sStack00000020 + CONCAT22((short)((uint)pRVar8 >> 0x10),unaff_ESI->tile_half_wid);
      in_stack_0000003c = (RGE_Map *)((int)&in_stack_0000003c->_padding_ + 1);
      cVar4 = '\x03';
      break;
    }
  } while( true );
}

// --------------------------------------------------

// Function: FUN_00536b03
// Address: 00536b03
// [HELPER] s_C__msdev_work_age1_x1_view_cpp: "C:\msdev\work\age1_x1\view.cpp"
// [HELPER] s_view__view_function_terrain: "view::view_function_terrain"
/* WARNING: Instruction at (ram,0x00536ba3) overlaps instruction at (ram,0x00536b9d)
    */

undefined4 __fastcall FUN_00536b03(int param_1,char *param_2)
{
  byte *pbVar1;
  RGE_Tile *pRVar2;
  undefined1 uVar3;
  short sVar4;
  Tile_FogEdge_Table *pTVar5;
  uint uVar6;
  Ov_Sprite_Draw_Rec *pOVar7;
  Ov_Sprite_Draw_Rec *pOVar8;
  TSpan_List_Manager *pTVar9;
  undefined4 *puVar10;
  TMessagePanel *this;
  int *piVar11;
  int *piVar12;
  Shape_Info *pSVar13;
  longlong lVar14;
  char cVar15;
  char cVar16;
  byte bVar17;
  undefined4 in_EAX;
  undefined3 uVar25;
  RGE_Map *pRVar19;
  long lVar20;
  ulong uVar21;
  DClipInfo_Node *pDVar22;
  TDrawArea *pTVar23;
  DClipInfo_List *pDVar24;
  uchar uVar26;
  RGE_View *this_00;
  int iVar27;
  ushort uVar28;
  int iVar29;
  DClipInfo_Node *pDVar30;
  RGE_Visible_Map *unaff_EBX;
  RGE_View *unaff_EBP;
  uint uVar31;
  Shape_Info **ppSVar32;
  undefined1 *unaff_EDI;
  int iVar33;
  Shape_Info **ppSVar34;
  byte in_CF;
  bool bVar35;
  char cStack00000013;
  int iStack00000014;
  int iStack00000018;
  int iStack00000020;
  RGE_Visible_Map *in_stack_00000028;
  int in_stack_0000002c;
  uchar uStack00000030;
  uint in_stack_00000034;
  uchar uStack00000038;
  VSpanMiniList *in_stack_0000003c;
  uint in_stack_00000040;
  int in_stack_00000044;
  long in_stack_00000048;
  int in_stack_0000004c;
  long in_stack_00000050;
  Tile_BlackEdge_Table *in_stack_00000054;
  int in_stack_00000058;
  RGE_Visible_Map *in_stack_0000005c;
  ulong in_stack_00000060;
  VSpanMiniList *in_stack_00000064;
  int in_stack_00000068;
  int in_stack_0000006c;
  VSpanMiniList *in_stack_00000070;
  int in_stack_00000074;
  ulong in_stack_00000078;
  uint in_stack_0000007c;
  int in_stack_00000080;
  int in_stack_00000084;
  int in_stack_00000088;
  int in_stack_0000008c;
  int in_stack_00000090;
  int in_stack_00000094;
  int in_stack_00000098;
  int in_stack_0000009c;
  uchar in_stack_00000124;
  int in_stack_00000128;
  int in_stack_0000012c;
  short sVar36;
  short sVar37;
  char *pcVar18;
  
  uVar28 = (ushort)param_2;
  *(ushort *)&unaff_EBX->map_offsets =
       *(short *)&unaff_EBX->map_offsets +
       (ushort)in_CF * ((uVar28 & 3) - (*(ushort *)&unaff_EBX->map_offsets & 3));
  *(ushort *)&unaff_EBX->map_offsets =
       *(short *)&unaff_EBX->map_offsets +
       (ushort)in_CF * ((uVar28 & 3) - (*(ushort *)&unaff_EBX->map_offsets & 3));
  *(ushort *)&unaff_EBX->map_offsets =
       *(short *)&unaff_EBX->map_offsets +
       (ushort)in_CF * ((uVar28 & 3) - (*(ushort *)&unaff_EBX->map_offsets & 3));
  *(ushort *)&unaff_EBX->map_offsets =
       *(short *)&unaff_EBX->map_offsets +
       (ushort)in_CF * ((uVar28 & 3) - (*(ushort *)&unaff_EBX->map_offsets & 3));
  *(ushort *)&unaff_EBX->map_offsets =
       *(short *)&unaff_EBX->map_offsets +
       (ushort)in_CF * ((uVar28 & 3) - (*(ushort *)&unaff_EBX->map_offsets & 3));
  uVar3 = in(uVar28);
  *unaff_EDI = uVar3;
  *(ushort *)&unaff_EBX->map_offsets =
       *(short *)&unaff_EBX->map_offsets +
       (ushort)in_CF * ((uVar28 & 3) - (*(ushort *)&unaff_EBX->map_offsets & 3));
  cRam05010505 = cRam05010505 + (char)in_EAX;
  uVar25 = (undefined3)((uint)in_EAX >> 8);
  cVar15 = (char)in_EAX + cRam05050503;
  cVar16 = cVar15 + -0x6c;
  pcVar18 = (char *)CONCAT31(uVar25,cVar16);
  this_00 = (RGE_View *)
            CONCAT22((short)((uint)param_1 >> 0x10),
                     CONCAT11((char)((uint)param_1 >> 8) + *(char *)(param_1 + 0x53) +
                              (0x6f < (byte)(cVar15 + 4U)),(char)param_1));
  *param_2 = *param_2 + (char)((uint)param_2 >> 8);
  lVar14 = (longlong)(int)unaff_EBX->map_offsets * 0x536957;
  if ((int)lVar14 == lVar14) {
    *(char *)&this_00[-0x2378d9]._padding_ = (char)this_00[-0x2378d9]._padding_ + (char)param_1;
    *pcVar18 = *pcVar18 + cVar16;
  }
  else {
    pbVar1 = (byte *)(pcVar18 + -0x7e6f6f70);
    bVar17 = *pbVar1;
    *pbVar1 = *pbVar1 + (byte)lVar14;
    cVar15 = in((short)lVar14);
    pcVar18 = (char *)CONCAT31(uVar25,cVar15);
    *(char *)&this_00->_padding_ = (char)this_00->_padding_ + cVar15 + CARRY1(bVar17,(byte)lVar14);
    *pcVar18 = *pcVar18 + cVar15;
    unaff_EBX = (RGE_Visible_Map *)0x0;
    unaff_EBP = this_00;
    if (0 < this_00->DispSel_List_Size) {
      RGE_View::update_display_selected_objects(this_00);
    }
  }
  in_stack_00000068 = (int)unaff_EBP->start_map_col;
  in_stack_0000002c = (int)unaff_EBP->start_map_row;
  in_stack_00000074 = unaff_EBP->max_col_num + 5;
  iVar33 = unaff_EBP->max_row_num * 2 + 0xc;
  in_stack_00000048 = unaff_EBP->map->map_width;
  in_stack_00000050 = unaff_EBP->map->map_height;
  unaff_EBP->function_mode = in_stack_00000124;
  pRVar19 = unaff_EBP->map;
  iVar27 = 0;
  if ((short)unaff_EBX < pRVar19->num_terrain) {
    iVar29 = 0;
    do {
      *(undefined1 *)((int)pRVar19->terrain_types[0].tiles + iVar29 + -1) = 0;
      pRVar19 = unaff_EBP->map;
      iVar27 = iVar27 + 1;
      iVar29 = iVar29 + 0x198;
    } while (iVar27 < pRVar19->num_terrain);
  }
  in_stack_00000078 = unaff_EBP->player->mutualExploredMask;
  in_stack_00000060 = unaff_EBP->player->mutualVisibleMask;
  SDI_List = unaff_EBP->futur_objs;
  in_stack_00000080 = iVar33;
  DClipInfo_List::ReclaimAllNodes(unaff_EBP->futur_objs);
  iStack00000018 = -1;
  if ((unaff_EBP->player->visible == unaff_EBX) ||
     (in_stack_0000005c = unaff_EBX, unaff_EBP->map->map_visible_flag != '\0')) {
    in_stack_0000005c = (RGE_Visible_Map *)0x1;
  }
  in_stack_00000028 = unaff_EBX;
  if ((int)unaff_EBX < iVar33) {
    do {
      iVar33 = in_stack_00000068;
      in_stack_0000004c = in_stack_00000068;
      iStack00000020 = in_stack_0000002c;
      in_stack_00000028 = unaff_EBX;
      if ((((byte)unaff_EBX & 3) == 3) && (MouseSystem != (TMousePointer *)0x0)) {
        TMousePointer::Poll(MouseSystem);
      }
      uVar31 = (uint)unaff_EBX & 1;
      in_stack_0000007c = uVar31;
      if ((uVar31 == 1) && (unaff_EBP->Queued_Blits != 0)) {
        RGE_View::ProcessQueuedBlit(unaff_EBP,0);
      }
      in_stack_0000006c = 0;
      if (0 < in_stack_00000074) {
        do {
          if ((-1 < iStack00000020) && (-1 < iVar33)) {
            if ((iStack00000020 < in_stack_00000050) && (iVar33 < in_stack_00000048)) {
              pRVar19 = unaff_EBP->map;
              pRVar2 = pRVar19->map_row_offset[iStack00000020] + iVar33;
              iVar29 = (int)pRVar19->map_row_offset[iStack00000020][iVar33].screen_xpos -
                       unaff_EBP->map_scr_x_offset;
              iVar27 = (int)pRVar2->screen_ypos - unaff_EBP->map_scr_y_offset;
              in_stack_0000003c = (VSpanMiniList *)(unaff_EBP->tile_wid + iVar29);
              in_stack_00000034 = pRVar19->tilesizes[pRVar2->tile_type].height + iVar27;
              sVar36 = (short)iVar29;
              sVar37 = (short)iVar27;
              if (((uint)(&unified_map_offsets)[iStack00000020][iVar33] & in_stack_00000060) == 0) {
                if (((in_stack_00000078 & (uint)(&unified_map_offsets)[iStack00000020][iVar33]) != 0
                    ) || (in_stack_0000005c != (RGE_Visible_Map *)0x0)) {
                  uVar26 = (-(pRVar19->fog_flag != '\0') & 0x71U) + 0xf;
                  goto LAB_00536d7a;
                }
                uVar26 = '\0';
                pRVar2->last_drawn_as = '\0';
              }
              else {
                uVar26 = '\x0f';
LAB_00536d7a:
                if ((((iVar29 <= unaff_EBP->_padding_) && (iVar27 <= unaff_EBP->_padding_)) &&
                    (unaff_EBP->_padding_ < (int)in_stack_0000003c)) &&
                   (unaff_EBP->_padding_ < (int)in_stack_00000034)) {
                  if ((unaff_EBP->calc_draw_count != 0) &&
                     ((short)(ushort)(pRVar2->field_0x5 & 0x1f) < pRVar19->num_terrain)) {
                    uVar31 = (byte)pRVar2->field_0x5 & 0x1f;
                    pRVar19->terrain_types[uVar31].drawn =
                         pRVar19->terrain_types[uVar31].drawn + '\x01';
                  }
                  _uStack00000038 = 0xffffffff;
                  _uStack00000030 = 0xffffffff;
                  in_stack_00000044 = 0;
                  in_stack_00000058 = 0;
                  if ((unaff_EBP->render_terrain_mode != '\0') && (pRVar2->last_drawn_as == uVar26))
{
                    if (uVar26 == '\x0f') {
                      if (unaff_EBP->map->fog_flag == '\0') {
                        _uStack00000038 = 0;
                      }
                      else {
                        _uStack00000038 =
                             RGE_View::get_tile_mask_num
                                       (unaff_EBP,iVar33,iStack00000020,in_stack_00000048,
                                        in_stack_00000050,in_stack_00000060);
                      }
                      if (pRVar2->last_drawn_shape != _uStack00000038) goto LAB_00536f71;
                    }
                    if ((uVar26 == '\x0f') || (uVar26 == 0x80)) {
                      if (in_stack_0000005c == (RGE_Visible_Map *)0x0) {
                        _uStack00000030 =
                             RGE_View::get_tile_mask_num
                                       (unaff_EBP,iVar33,iStack00000020,in_stack_00000048,
                                        in_stack_00000050,in_stack_00000078);
                      }
                      else {
                        _uStack00000030 = 0;
                      }
                      if (pRVar2->last_drawn_shape2 != _uStack00000030) goto LAB_00536f71;
                    }
                    if (unaff_EBP->Limited_Render_Rect == 0) goto LAB_0053739b;
                    if ((unaff_EBP->Use_Rect2 != 0) &&
                       (((((unaff_EBP->Render_Rect2).right < iVar29 ||
                          ((int)in_stack_0000003c < (unaff_EBP->Render_Rect2).left)) ||
                         ((unaff_EBP->Render_Rect2).bottom < iVar27)) ||
                        (in_stack_00000058 = 1,
                        (int)in_stack_00000034 < (unaff_EBP->Render_Rect2).top)))) {
                      in_stack_00000058 = 0;
                    }
                    if ((((unaff_EBP->Render_Rect1).right < iVar29) ||
                        ((int)in_stack_0000003c < (unaff_EBP->Render_Rect1).left)) ||
                       (((unaff_EBP->Render_Rect1).bottom < iVar27 ||
                        ((int)in_stack_00000034 < (unaff_EBP->Render_Rect1).top)))) {
                      if (in_stack_00000058 == 0) goto LAB_0053739b;
                      in_stack_00000058 = 0;
                      in_stack_00000044 = 2;
                    }
                    else {
                      in_stack_00000044 = 1;
                    }
                  }
LAB_00536f71:
                  pTVar5 = unaff_EBP->Tile_Edge_Tables[pRVar2->tile_type];
                  in_stack_00000054 = unaff_EBP->Black_Edge_Tables[pRVar2->tile_type];
                  if (unaff_EBP->map->fog_flag == '\0') {
                    _uStack00000038 = 0;
                  }
                  if (in_stack_0000005c != (RGE_Visible_Map *)0x0) {
                    _uStack00000030 = 0;
                  }
                  if (_uStack00000038 == 0xffffffff) {
                    if (uVar26 == '\x0f') {
                      _uStack00000038 =
                           RGE_View::get_tile_mask_num
                                     (unaff_EBP,in_stack_0000004c,iStack00000020,in_stack_00000048,
                                      in_stack_00000050,in_stack_00000060);
                    }
                    else {
                      _uStack00000038 = 0;
                    }
                  }
                  uVar31 = _uStack00000030;
                  if ((_uStack00000030 == 0xffffffff) && (uVar31 = 0, uVar26 != '\0')) {
                    uVar31 = RGE_View::get_tile_mask_num
                                       (unaff_EBP,in_stack_0000004c,iStack00000020,in_stack_00000048
                                        ,in_stack_00000050,in_stack_00000078);
                  }
                  _uStack00000030 = uVar31;
                  in_stack_00000070 = pTVar5[_uStack00000038].normal_draw;
                  in_stack_00000064 = pTVar5[_uStack00000038].fog_draw;
                  in_stack_0000003c = in_stack_00000054[_uStack00000030].black_UNdraw;
                  if (uVar26 == 0x80) {
                    in_stack_00000064 = pTVar5->normal_draw;
                    in_stack_00000040 = 1;
                    in_stack_00000034 = 0;
                  }
                  else {
                    in_stack_00000034 = (uint)(in_stack_00000070 != (VSpanMiniList *)0x0);
                    in_stack_00000040 = (uint)(in_stack_00000064 != (VSpanMiniList *)0x0);
                  }
                  if (((int)_uStack00000030 < 1) ||
                     (in_stack_00000054 = (Tile_BlackEdge_Table *)0x1,
                     in_stack_0000003c == (VSpanMiniList *)0x0)) {
                    in_stack_00000054 = (Tile_BlackEdge_Table *)0x0;
                  }
                  if (in_stack_00000044 != iStack00000018) {
                    if (in_stack_00000044 == 0) {
                      TSpan_List_Manager::SetSpanRegions
                                (unaff_EBP->Terrain_Clip_Mask,unaff_EBP->_padding_,
                                 unaff_EBP->_padding_,unaff_EBP->_padding_,unaff_EBP->_padding_);
                      TSpan_List_Manager::SetSpanRegions
                                (unaff_EBP->Terrain_Fog_Clip_Mask,unaff_EBP->_padding_,
                                 unaff_EBP->_padding_,unaff_EBP->_padding_,unaff_EBP->_padding_);
                    }
                    if (in_stack_00000044 == 1) {
                      TSpan_List_Manager::SetSpanRegions
                                (unaff_EBP->Terrain_Clip_Mask,(unaff_EBP->Render_Rect1).left,
                                 (unaff_EBP->Render_Rect1).top,(unaff_EBP->Render_Rect1).right,
                                 (unaff_EBP->Render_Rect1).bottom);
                      TSpan_List_Manager::SetSpanRegions
                                (unaff_EBP->Terrain_Fog_Clip_Mask,(unaff_EBP->Render_Rect1).left,
                                 (unaff_EBP->Render_Rect1).top,(unaff_EBP->Render_Rect1).right,
                                 (unaff_EBP->Render_Rect1).bottom);
                    }
                    iStack00000018 = in_stack_00000044;
                    if (in_stack_00000044 == 2) {
                      TSpan_List_Manager::SetSpanRegions
                                (unaff_EBP->Terrain_Clip_Mask,(unaff_EBP->Render_Rect2).left,
                                 (unaff_EBP->Render_Rect2).top,(unaff_EBP->Render_Rect2).right,
                                 (unaff_EBP->Render_Rect2).bottom);
                      TSpan_List_Manager::SetSpanRegions
                                (unaff_EBP->Terrain_Fog_Clip_Mask,(unaff_EBP->Render_Rect2).left,
                                 (unaff_EBP->Render_Rect2).top,(unaff_EBP->Render_Rect2).right,
                                 (unaff_EBP->Render_Rect2).bottom);
                      iStack00000018 = in_stack_00000044;
                    }
                  }
                  if (in_stack_00000034 != 0) {
                    TSpan_List_Manager::AddMiniList
                              (unaff_EBP->Terrain_Clip_Mask,in_stack_00000070,iVar29,iVar27);
                  }
                  if (in_stack_00000040 != 0) {
                    TSpan_List_Manager::AddMiniList
                              (unaff_EBP->Terrain_Fog_Clip_Mask,in_stack_00000064,iVar29,iVar27);
                  }
                  if (in_stack_00000054 != (Tile_BlackEdge_Table *)0x0) {
                    if (in_stack_00000034 != 0) {
                      TSpan_List_Manager::SubtractMiniList
                                (unaff_EBP->Terrain_Clip_Mask,in_stack_0000003c,iVar29,iVar27);
                    }
                    if (in_stack_00000040 != 0) {
                      TSpan_List_Manager::SubtractMiniList
                                (unaff_EBP->Terrain_Fog_Clip_Mask,in_stack_0000003c,iVar29,iVar27);
                    }
                  }
                  if (in_stack_00000058 != 0) {
                    TSpan_List_Manager::SetSpanRegions
                              (unaff_EBP->Terrain_Clip_Mask,(unaff_EBP->Render_Rect2).left,
                               (unaff_EBP->Render_Rect2).top,(unaff_EBP->Render_Rect2).right,
                               (unaff_EBP->Render_Rect2).bottom);
                    TSpan_List_Manager::SetSpanRegions
                              (unaff_EBP->Terrain_Fog_Clip_Mask,(unaff_EBP->Render_Rect2).left,
                               (unaff_EBP->Render_Rect2).top,(unaff_EBP->Render_Rect2).right,
                               (unaff_EBP->Render_Rect2).bottom);
                    iStack00000018 = 2;
                    if (in_stack_00000034 != 0) {
                      TSpan_List_Manager::AddMiniList
                                (unaff_EBP->Terrain_Clip_Mask,in_stack_00000070,iVar29,iVar27);
                    }
                    if (in_stack_00000040 != 0) {
                      TSpan_List_Manager::AddMiniList
                                (unaff_EBP->Terrain_Fog_Clip_Mask,in_stack_00000064,iVar29,iVar27);
                    }
                    if (in_stack_00000054 != (Tile_BlackEdge_Table *)0x0) {
                      if (in_stack_00000034 != 0) {
                        TSpan_List_Manager::SubtractMiniList
                                  (unaff_EBP->Terrain_Clip_Mask,in_stack_0000003c,iVar29,iVar27);
                      }
                      if (in_stack_00000040 != 0) {
                        TSpan_List_Manager::SubtractMiniList
                                  (unaff_EBP->Terrain_Fog_Clip_Mask,in_stack_0000003c,iVar29,iVar27)
                        ;
                      }
                    }
                  }
                  bVar17 = pRVar2->field_0x5 & 0x1f;
                  sVar4 = unaff_EBP->map->terrain_types[(byte)pRVar2->field_0x5 & 0x1f].
                          terrain_to_draw;
                  if (sVar4 != -1) {
                    bVar17 = (byte)sVar4;
                  }
                  pRVar2->last_drawn_shape2 = uStack00000030;
                  pRVar2->last_drawn_shape = uStack00000038;
                  pRVar2->last_drawn_as = uVar26;
                  pRVar2->draw_as = uVar26;
                  pRVar2->draw_attribute = pRVar2->draw_attribute & 0xbf;
                  RGE_View::draw_tile(unaff_EBP,pRVar2,bVar17,sVar36,sVar37,(short)in_stack_0000004c
                                      ,(short)iStack00000020,uVar26,in_stack_00000034,
                                      in_stack_00000040);
                  tiles_drawn = tiles_drawn + 1;
                  iVar33 = in_stack_0000004c;
                }
              }
LAB_0053739b:
              if ((pRVar2 != (RGE_Tile *)0x0) && ((pRVar2->draw_attribute & 0x40) == 0x40)) {
                bVar17 = pRVar2->field_0x5 & 0x1f;
                sVar4 = unaff_EBP->map->terrain_types[(byte)pRVar2->field_0x5 & 0x1f].
                        terrain_to_draw;
                if (sVar4 != -1) {
                  bVar17 = (byte)sVar4;
                }
                RGE_View::draw_tile(unaff_EBP,pRVar2,bVar17,sVar36,sVar37,(short)iVar33,
                                    (short)iStack00000020,uVar26,1,1);
                pRVar2->draw_attribute = pRVar2->draw_attribute & 0xbf;
              }
              if ((view_debug_Objects == 0) && (pRVar2 != (RGE_Tile *)0x0)) {
                SDI_Capture_Info = 1;
                if (uVar26 == '\0') {
                  DClipInfo_List::SetCaptureLevel(unaff_EBP->futur_objs,0,5);
                }
                if (uVar26 != '\x0f') {
                  fog_next_shape = 1;
                }
                RGE_Object_List::draw
                          (&pRVar2->objects,unaff_EBP->save_area1,sVar36,
                           (ushort)((byte)pRVar2->field_0x5 >> 5) * unaff_EBP->tile_half_hgt +
                           sVar37,uVar26 == 0x80);
                DClipInfo_List::SetCaptureLevel(unaff_EBP->futur_objs,0,0x28);
                fog_next_shape = 0;
                SDI_Capture_Info = 0;
              }
            }
            else {
              in_stack_0000006c = in_stack_00000074;
            }
          }
          iVar33 = iVar33 + 1;
          iStack00000020 = iStack00000020 + 1;
          in_stack_0000006c = in_stack_0000006c + 1;
          unaff_EBX = in_stack_00000028;
          uVar31 = in_stack_0000007c;
          in_stack_0000004c = iVar33;
        } while (in_stack_0000006c < in_stack_00000074);
      }
      if (uVar31 == 1) {
        in_stack_0000002c = in_stack_0000002c + 1;
      }
      else {
        in_stack_00000068 = in_stack_00000068 + -1;
      }
      unaff_EBX = (RGE_Visible_Map *)((int)&unaff_EBX->map_offsets + 1);
      in_stack_00000028 = unaff_EBX;
    } while ((int)unaff_EBX < in_stack_00000080);
  }
  iVar33 = unaff_EBP->Queued_Blits;
  while (iVar33 != 0) {
    RGE_View::ProcessQueuedBlit(unaff_EBP,1);
    iVar33 = unaff_EBP->Queued_Blits;
  }
  if (MouseSystem != (TMousePointer *)0x0) {
    TMousePointer::Poll(MouseSystem);
  }
  unaff_EBP->_padding_ = unaff_EBP->_padding_ + in_stack_00000128;
  unaff_EBP->_padding_ = unaff_EBP->_padding_ + in_stack_0000012c;
  unaff_EBP->_padding_ = unaff_EBP->_padding_ + in_stack_00000128;
  unaff_EBP->_padding_ = unaff_EBP->_padding_ + in_stack_0000012c;
  SDI_Capture_Info = 1;
  if (unaff_EBP->scroll_action == '\x02') {
    DClipInfo_List::AddGDINode
              (unaff_EBP->futur_objs,4,0x14,unaff_EBP->_padding_ - in_stack_00000128,
               unaff_EBP->_padding_ - in_stack_0000012c,unaff_EBP->mouse_last_x - in_stack_00000128,
               unaff_EBP->mouse_last_y - in_stack_0000012c,0,0,0,0,0x28,0xff,0);
  }
  iVar33 = rge_base_game->game_mode;
  if ((iVar33 == 1) || ((6 < iVar33 && (iVar33 < 9)))) {
    RGE_View::draw_object_outline(unaff_EBP);
  }
  if (rge_base_game->game_mode == 0x15) {
    (**(code **)(unaff_EBP->_padding_ + 0xf8))();
  }
  cStack00000013 = '\0';
  if (unaff_EBP->extra_sprites != (Ov_Sprite_Draw_Rec *)0x0) {
    in_stack_00000028 = (RGE_Visible_Map *)debug_timeGetTime(s_C__msdev_work_age1_x1_view_cpp,0xe3e)
    ;
    pOVar8 = unaff_EBP->extra_sprites;
    while (pOVar8 != (Ov_Sprite_Draw_Rec *)0x0) {
      bVar35 = false;
      if (pOVar8->theShape == (TShape *)0x0) {
LAB_005376e9:
        if (bVar35) goto LAB_005376ed;
        pOVar8 = pOVar8->next;
      }
      else {
        if (pOVar8->LastDrawTime == 0) {
          pOVar8->LastDrawTime = (ulong)in_stack_00000028;
        }
        else if (((pOVar8->displayfunction == 1) || (pOVar8->displayfunction == 2)) &&
                (uVar31 = (int)in_stack_00000028 - pOVar8->LastDrawTime,
                pOVar8->DrawTimeInterval <= uVar31)) {
          do {
            pOVar8->thefacet = pOVar8->thefacet + 1;
            lVar20 = TShape::shape_count(pOVar8->theShape);
            if ((lVar20 <= pOVar8->thefacet) && (pOVar8->thefacet = 0, pOVar8->displayfunction == 2)
               ) {
              bVar35 = true;
              cStack00000013 = '\x01';
            }
            uVar6 = pOVar8->DrawTimeInterval;
            uVar31 = uVar31 - uVar6;
            pOVar8->LastDrawTime = pOVar8->LastDrawTime + uVar6;
          } while (uVar6 <= uVar31);
        }
        if (!bVar35) {
          SDI_Draw_Level = pOVar8->drawLevel;
          SDI_Object_ID = -1;
          TShape::shape_draw(pOVar8->theShape,(TDrawArea *)unaff_EBP->_padding_,
                             pOVar8->world_x - unaff_EBP->map_scr_x_offset,
                             pOVar8->world_y - unaff_EBP->map_scr_y_offset,pOVar8->thefacet,
                             (uchar)pOVar8->flags,pOVar8->colortable);
          goto LAB_005376e9;
        }
LAB_005376ed:
        if (pOVar8->prev != (Ov_Sprite_Draw_Rec *)0x0) {
          pOVar8->prev->next = pOVar8->next;
        }
        if (pOVar8->next != (Ov_Sprite_Draw_Rec *)0x0) {
          pOVar8->next->prev = pOVar8->prev;
        }
        if (pOVar8->prev == (Ov_Sprite_Draw_Rec *)0x0) {
          unaff_EBP->extra_sprites = pOVar8->next;
        }
        pOVar7 = pOVar8->next;
        operator_delete(pOVar8);
        pOVar8 = pOVar7;
      }
    }
  }
  if (cStack00000013 != '\0') {
    RGE_View::reset_cyclic_overlay_sprites(unaff_EBP);
  }
  iVar33 = 0;
  SDI_Capture_Info = 0;
  unaff_EBP->_padding_ = unaff_EBP->_padding_ - in_stack_00000128;
  unaff_EBP->_padding_ = unaff_EBP->_padding_ - in_stack_0000012c;
  unaff_EBP->_padding_ = unaff_EBP->_padding_ - in_stack_00000128;
  unaff_EBP->_padding_ = unaff_EBP->_padding_ - in_stack_0000012c;
  pDVar24 = unaff_EBP->futur_objs;
  if (0 < pDVar24->YLine_Size) {
    do {
      for (pDVar22 = pDVar24->Draw_Clip_Nodes[iVar33]; pDVar22 != (DClipInfo_Node *)0x0;
          pDVar22 = pDVar22->Next) {
        iVar27 = pDVar22->Draw_Level;
        pDVar30 = unaff_EBP->futur_objs->Draw_Level_Tail[iVar27];
        if (pDVar30 == (DClipInfo_Node *)0x0) {
          unaff_EBP->futur_objs->Draw_Level_Head[iVar27] = pDVar22;
        }
        else {
          pDVar30->NextOnLevel = pDVar22;
        }
        unaff_EBP->futur_objs->Draw_Level_Tail[iVar27] = pDVar22;
      }
      pDVar24 = unaff_EBP->futur_objs;
      iVar33 = iVar33 + 1;
    } while (iVar33 < pDVar24->YLine_Size);
  }
  iVar33 = 0;
  Clip_draw = 0;
  Clip_remove = 0;
  if (iStack00000018 != 0) {
    TSpan_List_Manager::SetSpanRegions
              (unaff_EBP->Terrain_Clip_Mask,unaff_EBP->_padding_,unaff_EBP->_padding_,
               unaff_EBP->_padding_,unaff_EBP->_padding_);
    TSpan_List_Manager::SetSpanRegions
              (unaff_EBP->Terrain_Fog_Clip_Mask,unaff_EBP->_padding_,unaff_EBP->_padding_,
               unaff_EBP->_padding_,unaff_EBP->_padding_);
  }
  do {
    for (iVar27 = *(int *)((int)unaff_EBP->futur_objs->Draw_Level_Head + iVar33); iVar27 != 0;
        iVar27 = *(int *)(iVar27 + 4)) {
      if (*(int *)(iVar27 + 0x2c) == 0) {
        pTVar9 = unaff_EBP->Terrain_Clip_Mask;
        _ASMSet_Surface_Info
                  (unaff_EBP->save_area1->CurDisplayOffsets,pTVar9->Line_Head_Ptrs,
                   pTVar9->Line_Tail_Ptrs,pTVar9->Min_Span_Px,pTVar9->Min_Line,pTVar9->Max_Span_Px,
                   pTVar9->Max_Line);
        _ASMSet_Color_Xform(*(undefined4 *)(iVar27 + 0x28));
        _ASMSet_Xlate_Table(*(undefined4 *)(iVar27 + 0x24));
        puVar10 = *(undefined4 **)(iVar27 + 0xc);
        _ASMDraw_Sprite(*(undefined4 *)(iVar27 + 0x20),*(undefined4 *)(iVar27 + 0x14),
                        *(undefined4 *)(iVar27 + 0x18),puVar10[4],puVar10[5],*puVar10,puVar10[1],
                        *(uint *)(iVar27 + 0x1c) & 0xfe);
        pTVar9 = unaff_EBP->Terrain_Fog_Clip_Mask;
        _ASMSet_Surface_Info
                  (unaff_EBP->save_area1->CurDisplayOffsets,pTVar9->Line_Head_Ptrs,
                   pTVar9->Line_Tail_Ptrs,pTVar9->Min_Span_Px,pTVar9->Min_Line,pTVar9->Max_Span_Px,
                   pTVar9->Max_Line);
        _ASMDraw_Sprite(*(undefined4 *)(iVar27 + 0x20),*(undefined4 *)(iVar27 + 0x14),
                        *(undefined4 *)(iVar27 + 0x18),puVar10[4],puVar10[5],*puVar10,puVar10[1],
                        *(uint *)(iVar27 + 0x1c) | 1);
      }
    }
    iVar33 = iVar33 + 4;
  } while (iVar33 < 0x15);
  if (MouseSystem != (TMousePointer *)0x0) {
    TMousePointer::Poll(MouseSystem);
  }
  if (((rge_base_game->prog_mode == 4) && (unaff_EBP->_padding_ != 0)) &&
     (iVar33 = TMousePointer::get_game_enable(MouseSystem), iVar33 != 0)) {
    uVar21 = debug_timeGetTime(s_C__msdev_work_age1_x1_view_cpp,0xf11);
    iVar33 = RGE_View::Get_Cursor_Position
                       (unaff_EBP,(tagPOINT *)&stack0x00000088,-in_stack_00000128,-in_stack_0000012c
                       );
    if (iVar33 != 0) {
      iVar33 = RGE_View::pick_touched_object
                         (unaff_EBP,unaff_EBP->futur_objs,in_stack_00000088,in_stack_0000008c,10,
                          0x28,&stack0x00000084);
      if (iVar33 == 1) {
        if (((unaff_EBP->UC_ObjectTouched != 0) && (unaff_EBP->UC_TouchedObj == in_stack_00000084))
           || (unaff_EBP->UC_ObjectTouched = 1, unaff_EBP->UC_TouchedObj == in_stack_00000084))
        goto LAB_00537b2a;
        unaff_EBP->UC_StartTime = uVar21;
        unaff_EBP->UC_TouchedObj = in_stack_00000084;
        in_stack_00000028 = (RGE_Visible_Map *)0x0;
        in_stack_0000002c = 0;
        iVar33 = (**(code **)(unaff_EBP->player->_padding_ + 0x9c))
                           (in_stack_00000084,&stack0x00000028,&stack0x0000002c);
        if (iVar33 == 1) {
          TMousePointer::set_game_facet(MouseSystem,(int)in_stack_00000028);
          if ((unaff_EBP->message_panel != (TMessagePanel *)0x0) && (rge_base_game->rollover != 0))
{
            TPanel::get_string((TPanel *)unaff_EBP,in_stack_0000002c,&stack0x000000a0,0x7f);
            TMessagePanel::show_message
                      (unaff_EBP->message_panel,InfoMessage,&stack0x000000a0,'p','\0',(void *)0x0,0,
                       0);
          }
          goto LAB_00537b2a;
        }
        TMousePointer::set_game_facet(MouseSystem,0);
        this = unaff_EBP->message_panel;
        if (this == (TMessagePanel *)0x0) goto LAB_00537b2a;
        iVar33 = rge_base_game->rollover;
      }
      else {
        if (unaff_EBP->UC_ObjectTouched == 0) goto LAB_00537b2a;
        unaff_EBP->UC_ObjectTouched = 0;
        unaff_EBP->UC_TouchedObj = -0x80000000;
        TMousePointer::set_game_facet(MouseSystem,0);
        this = unaff_EBP->message_panel;
        if (this == (TMessagePanel *)0x0) goto LAB_00537b2a;
        iVar33 = rge_base_game->rollover;
      }
      if (iVar33 != 0) {
        TMessagePanel::remove_message(this);
      }
    }
  }
LAB_00537b2a:
  for (piVar11 = (int *)unaff_EBP->_padding_; piVar11 != (int *)0x0; piVar11 = (int *)piVar11[2]) {
    piVar12 = (int *)*piVar11;
    if ((piVar12[0x1b] != 0) && (piVar12[0xe] != 0)) {
      (**(code **)(*piVar12 + 0xb8))(&stack0x00000090);
      iVar27 = in_stack_00000094 - in_stack_0000012c;
      iVar33 = in_stack_00000090 - in_stack_00000128;
      if (iVar33 < 0) {
        iVar33 = 0;
      }
      if (iVar27 < 0) {
        iVar27 = 0;
      }
      pDVar22 = DClipInfo_List::AddGDINode
                          (unaff_EBP->futur_objs,3,in_stack_0000009c - in_stack_0000012c,iVar33,
                           iVar27,in_stack_00000098 - in_stack_00000128,
                           in_stack_0000009c - in_stack_0000012c,0,0,0,0,0x1e,piVar12[0x38],0);
      if (pDVar22 != (DClipInfo_Node *)0x0) {
        pDVar30 = unaff_EBP->futur_objs->Draw_Level_Tail[0x1e];
        if (pDVar30 == (DClipInfo_Node *)0x0) {
          unaff_EBP->futur_objs->Draw_Level_Head[0x1e] = pDVar22;
        }
        else {
          pDVar30->NextOnLevel = pDVar22;
        }
        unaff_EBP->futur_objs->Draw_Level_Tail[0x1e] = pDVar22;
      }
    }
  }
  if (unaff_EBP->render_terrain_mode == '\0') {
    pTVar23 = unaff_EBP->save_area1;
    iVar33 = 0;
    if (0 < pTVar23->Height) {
      do {
        TSpan_List_Manager::AddSpan(unaff_EBP->Master_Clip_Mask,0,pTVar23->Width + -1,iVar33);
        pTVar23 = unaff_EBP->save_area1;
        iVar33 = iVar33 + 1;
      } while (iVar33 < pTVar23->Height);
    }
    DClipInfo_List::ReclaimAllNodes(unaff_EBP->prior_objs);
  }
  else {
    TSpan_List_Manager::Merge_n_Align
              (unaff_EBP->Master_Clip_Mask,unaff_EBP->Terrain_Clip_Mask,
               unaff_EBP->Terrain_Fog_Clip_Mask);
    if (unaff_EBP->Limited_Render_Rect != 0) {
      if ((-1 < (unaff_EBP->Render_Rect1).left) &&
         (iVar33 = (unaff_EBP->Render_Rect1).top, iVar33 <= (unaff_EBP->Render_Rect1).bottom)) {
        do {
          TSpan_List_Manager::AddSpan
                    (unaff_EBP->Master_Clip_Mask,(unaff_EBP->Render_Rect1).left,
                     (unaff_EBP->Render_Rect1).right,iVar33);
          iVar33 = iVar33 + 1;
        } while (iVar33 <= (unaff_EBP->Render_Rect1).bottom);
      }
      if (((unaff_EBP->Use_Rect2 != 0) && (-1 < (unaff_EBP->Render_Rect2).left)) &&
         (iVar33 = (unaff_EBP->Render_Rect2).top, iVar33 <= (unaff_EBP->Render_Rect2).bottom)) {
        do {
          TSpan_List_Manager::AddSpan
                    (unaff_EBP->Master_Clip_Mask,(unaff_EBP->Render_Rect2).left,
                     (unaff_EBP->Render_Rect2).right,iVar33);
          iVar33 = iVar33 + 1;
        } while (iVar33 <= (unaff_EBP->Render_Rect2).bottom);
      }
    }
    pDVar24 = unaff_EBP->futur_objs;
    iStack00000014 = 0;
    if (0 < pDVar24->YLine_Size) {
      do {
        for (pDVar22 = pDVar24->Draw_Clip_Nodes[iStack00000014]; pDVar22 != (DClipInfo_Node *)0x0;
            pDVar22 = pDVar22->Next) {
          if (5 < pDVar22->Draw_Level) {
            pDVar30 = unaff_EBP->prior_objs->Draw_Clip_Nodes[iStack00000014];
            bVar35 = true;
            in_stack_0000002c = 1;
            if (pDVar30 != (DClipInfo_Node *)0x0) {
              do {
                bVar35 = true;
                iVar33 = (-(uint)(pDVar22->Node_Type != 0) & 0x10) + 0x24;
                ppSVar32 = &pDVar22->Shape;
                ppSVar34 = &pDVar30->Shape;
                do {
                  if (iVar33 == 0) break;
                  iVar33 = iVar33 + -1;
                  bVar35 = *(char *)ppSVar32 == *(char *)ppSVar34;
                  ppSVar32 = (Shape_Info **)((int)ppSVar32 + 1);
                  ppSVar34 = (Shape_Info **)((int)ppSVar34 + 1);
                } while (bVar35);
                if (bVar35) {
                  bVar35 = false;
                  Clip_remove = Clip_remove + 1;
                  pDVar30->Node_Type = -1;
                  goto LAB_00537d85;
                }
                pDVar30 = pDVar30->Next;
              } while (pDVar30 != (DClipInfo_Node *)0x0);
              bVar35 = true;
            }
LAB_00537d85:
            if (bVar35) {
              if (pDVar22->Node_Type == 0) {
                TSpan_List_Manager::AddShape_Align
                          (unaff_EBP->Master_Clip_Mask,pDVar22->Shape_Base,pDVar22->Shape,
                           pDVar22->Draw_X,pDVar22->Draw_Y,
                           (uint)(((byte)pDVar22->Draw_Flag & 2) == 2));
                Clip_draw = Clip_draw + 1;
              }
              else {
                RGE_View::Add_GDI_Clip_Mask(unaff_EBP,pDVar22,unaff_EBP->Master_Clip_Mask);
              }
            }
          }
        }
        for (pDVar22 = unaff_EBP->prior_objs->Draw_Clip_Nodes[iStack00000014];
            pDVar22 != (DClipInfo_Node *)0x0; pDVar22 = pDVar22->Next) {
          if ((5 < pDVar22->Draw_Level) && (pDVar22->Node_Type != -1)) {
            pDVar30 = unaff_EBP->futur_objs->Draw_Clip_Nodes[iStack00000014];
            bVar35 = true;
            in_stack_0000002c = 1;
            if (pDVar30 != (DClipInfo_Node *)0x0) {
              do {
                bVar35 = true;
                iVar33 = (-(uint)(pDVar22->Node_Type != 0) & 0x10) + 0x24;
                ppSVar32 = &pDVar30->Shape;
                ppSVar34 = &pDVar22->Shape;
                do {
                  if (iVar33 == 0) break;
                  iVar33 = iVar33 + -1;
                  bVar35 = *(char *)ppSVar32 == *(char *)ppSVar34;
                  ppSVar32 = (Shape_Info **)((int)ppSVar32 + 1);
                  ppSVar34 = (Shape_Info **)((int)ppSVar34 + 1);
                } while (bVar35);
                if (bVar35) {
                  bVar35 = false;
                  goto LAB_00537e5a;
                }
                pDVar30 = pDVar30->Next;
              } while (pDVar30 != (DClipInfo_Node *)0x0);
              bVar35 = true;
            }
LAB_00537e5a:
            if (bVar35) {
              if (pDVar22->Node_Type == 0) {
                TSpan_List_Manager::AddShape_Align
                          (unaff_EBP->Master_Clip_Mask,pDVar22->Shape_Base,pDVar22->Shape,
                           pDVar22->Draw_X,pDVar22->Draw_Y,
                           (uint)(((byte)pDVar22->Draw_Flag & 2) == 2));
                Clip_draw = Clip_draw + 1;
              }
              else {
                RGE_View::Add_GDI_Clip_Mask(unaff_EBP,pDVar22,unaff_EBP->Master_Clip_Mask);
              }
            }
          }
        }
        pDVar24 = unaff_EBP->futur_objs;
        iStack00000014 = iStack00000014 + 1;
      } while (iStack00000014 < pDVar24->YLine_Size);
    }
  }
  iVar27 = in_stack_0000012c;
  iVar33 = in_stack_00000128;
  unaff_EBP->_padding_ = unaff_EBP->_padding_ + in_stack_00000128;
  unaff_EBP->_padding_ = unaff_EBP->_padding_ + in_stack_0000012c;
  unaff_EBP->_padding_ = unaff_EBP->_padding_ + in_stack_00000128;
  unaff_EBP->_padding_ = unaff_EBP->_padding_ + in_stack_0000012c;
  TDrawArea::PtrSpanCopy
            (unaff_EBP->save_area1,(TDrawArea *)unaff_EBP->_padding_,unaff_EBP->_padding_,
             unaff_EBP->_padding_,&unaff_EBP->save_area1->ClipRect,
             (uchar **)unaff_EBP->Master_Clip_Mask->Line_Head_Ptrs);
  RGE_View::Update_Render_Pointers(unaff_EBP);
  unaff_EBP->_padding_ = unaff_EBP->_padding_ - iVar33;
  unaff_EBP->_padding_ = unaff_EBP->_padding_ - iVar27;
  unaff_EBP->_padding_ = unaff_EBP->_padding_ - iVar33;
  pTVar9 = unaff_EBP->Master_Clip_Mask;
  unaff_EBP->_padding_ = unaff_EBP->_padding_ - iVar27;
  _ASMSet_Surface_Info
            (unaff_EBP->RenderOffsets,pTVar9->Line_Head_Ptrs,pTVar9->Line_Tail_Ptrs,
             pTVar9->Min_Span_Px,pTVar9->Min_Line,pTVar9->Max_Span_Px,pTVar9->Max_Line);
  *(TSpan_List_Manager **)(unaff_EBP->_padding_ + 0xd0) = unaff_EBP->Master_Clip_Mask;
  in_stack_00000028 = (RGE_Visible_Map *)0x18;
  do {
    for (pDVar22 = *(DClipInfo_Node **)
                    ((int)unaff_EBP->futur_objs->Draw_Level_Head + (int)in_stack_00000028);
        pDVar22 != (DClipInfo_Node *)0x0; pDVar22 = pDVar22->NextOnLevel) {
      if (pDVar22->Node_Type == 0) {
        bVar35 = false;
        uVar31 = pDVar22->Draw_Flag & 0xffc;
        if (uVar31 != 0) {
          if (((byte)uVar31 & 4) == 4) {
            _ASMSet_Shadowing(0xffffff,0,0xffff00ff,0);
          }
          if (((byte)uVar31 & 8) == 8) {
            uVar31 = ((int)uVar31 >> 4) << 0x10 | (int)uVar31 >> 4;
            _ASMSet_Shadowing(&DAT_ff00ff00,uVar31,0xff00ff,uVar31 << 8);
          }
          bVar35 = true;
        }
        _ASMSet_Color_Xform(pDVar22->Xform_Mask);
        _ASMSet_Xlate_Table(pDVar22->Color_Table);
        pSVar13 = pDVar22->Shape;
        _ASMDraw_Sprite(pDVar22->Shape_Base,pDVar22->Draw_X,pDVar22->Draw_Y,pSVar13->Width,
                        pSVar13->Height,pSVar13->Shape_Data_Offsets,pSVar13->Shape_Outline_Offset,
                        pDVar22->Draw_Flag & 3);
        if (bVar35) {
          _ASMSet_Shadowing(0xff00ff,0,&DAT_ff00ff00,0);
        }
      }
      else {
        RGE_View::Draw_GDI_Object(unaff_EBP,pDVar22,(TDrawArea *)unaff_EBP->_padding_);
      }
    }
    in_stack_00000028 = (RGE_Visible_Map *)((int)in_stack_00000028 + 4);
  } while ((int)in_stack_00000028 < 0xa1);
  if ((view_debug_spans != 0) && (unaff_EBP->render_terrain_mode != '\0')) {
    iVar33 = frame_count % 0xdc;
    pTVar23 = (TDrawArea *)unaff_EBP->_padding_;
    iVar27 = 0;
    if (0 < pTVar23->Height) {
      do {
        TDrawArea::DrawLine(pTVar23,0,iVar27,pTVar23->Width + -1,iVar27,(char)iVar33 + '\x10');
        pTVar23 = (TDrawArea *)unaff_EBP->_padding_;
        iVar27 = iVar27 + 1;
      } while (iVar27 < pTVar23->Height);
    }
  }
  if (view_debug_palette != 0) {
    cVar15 = '\0';
    iVar33 = 0x20;
    do {
      cVar16 = '\0';
      cStack00000013 = cVar15 << 4;
      iVar27 = 0;
      do {
        TDrawArea::FillRect((TDrawArea *)unaff_EBP->_padding_,iVar27,iVar33,iVar27 + 0x1f,
                            iVar33 + 0xf,cVar16 + cStack00000013);
        iVar27 = iVar27 + 0x20;
        cVar16 = cVar16 + '\x01';
      } while (iVar27 < 0x200);
      iVar33 = iVar33 + 0x10;
      cVar15 = cVar15 + '\x01';
    } while (iVar33 < 0x120);
  }
  TDrawArea::Unlock((TDrawArea *)unaff_EBP->_padding_,s_view__view_function_terrain);
  *(undefined4 *)(unaff_EBP->_padding_ + 0xd0) = *(undefined4 *)(unaff_EBP->_padding_ + 0xcc);
  pDVar24 = unaff_EBP->futur_objs;
  unaff_EBP->futur_objs = unaff_EBP->prior_objs;
  unaff_EBP->prior_objs = pDVar24;
  return 0;
}

// --------------------------------------------------

// Function: FUN_0053827e
// Address: 0053827e
void FUN_0053827e(int param_1,TSpan_List_Manager *param_2)
{
  undefined2 uVar1;
  short sVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  
  iVar5 = *(int *)(param_1 + 0x2c);
  if (iVar5 != 1) {
    if ((iVar5 == 2) || (iVar5 == 3)) {
      uVar1 = *(undefined2 *)(param_1 + 0x30);
      sVar2 = *(short *)(param_1 + 0x34);
      iVar8 = (int)*(short *)(param_1 + 0x32);
      iVar7 = (int)*(short *)(param_1 + 0x36);
      iVar5 = iVar7;
      iVar9 = iVar8;
      if ((iVar8 <= iVar7) || (iVar5 = iVar8, iVar9 = iVar7, iVar7 <= iVar8)) {
        do {
          TSpan_List_Manager::AddSpan
                    (param_2,CONCAT31((int3)(char)((ushort)uVar1 >> 8),(char)uVar1) & 0xfffffffc,
                     (int)sVar2 | 3,iVar9);
          iVar9 = iVar9 + 1;
        } while (iVar9 <= iVar5);
      }
    }
    if (*(int *)(param_1 + 0x2c) == 4) {
      uVar3 = (uint)*(short *)(param_1 + 0x30);
      uVar6 = (uint)*(short *)(param_1 + 0x34);
      uVar4 = uVar3;
      if ((int)uVar6 < (int)uVar3) {
        uVar4 = uVar6;
        uVar6 = uVar3;
      }
      iVar9 = (int)*(short *)(param_1 + 0x36);
      uVar10 = uVar4 & 0xfffffffc;
      uVar3 = uVar6 | 3;
      iVar7 = (int)*(short *)(param_1 + 0x32);
      iVar5 = iVar7;
      if (iVar9 < iVar7) {
        iVar5 = iVar9;
        iVar9 = iVar7;
      }
      TSpan_List_Manager::AddSpan(param_2,uVar10,uVar3,iVar5);
      TSpan_List_Manager::AddSpan(param_2,uVar10,uVar3,iVar9);
      while (iVar5 = iVar5 + 1, iVar5 < iVar9) {
        TSpan_List_Manager::AddSpan(param_2,uVar10,uVar4 | 3,iVar5);
        TSpan_List_Manager::AddSpan(param_2,uVar6 & 0xfffffffc,uVar3,iVar5);
      }
    }
    return;
  }
  TSpan_List_Manager::AddLine_Align
            (param_2,(int)*(short *)(param_1 + 0x30),(int)*(short *)(param_1 + 0x32),
             (int)*(short *)(param_1 + 0x34),(int)*(short *)(param_1 + 0x36));
  TSpan_List_Manager::AddLine_Align
            (param_2,(int)*(short *)(param_1 + 0x34),(int)*(short *)(param_1 + 0x36),
             (int)*(short *)(param_1 + 0x38),(int)*(short *)(param_1 + 0x3a));
  TSpan_List_Manager::AddLine_Align
            (param_2,(int)*(short *)(param_1 + 0x38),(int)*(short *)(param_1 + 0x3a),
             (int)*(short *)(param_1 + 0x3c),(int)*(short *)(param_1 + 0x3e));
  TSpan_List_Manager::AddLine_Align
            (param_2,(int)*(short *)(param_1 + 0x3c),(int)*(short *)(param_1 + 0x3e),
             (int)*(short *)(param_1 + 0x30),(int)*(short *)(param_1 + 0x32));
  return;
}

// --------------------------------------------------

// Function: FUN_00538401
// Address: 00538401
void FUN_00538401(void)
{
  return;
}

// --------------------------------------------------

// Function: FUN_00538411
// Address: 00538411
void FUN_00538411(int param_1,TDrawArea *param_2)
{
  int iVar1;
  
  if (*(int *)(param_1 + 0x2c) == 1) {
    TDrawArea::DrawLine(param_2,(int)*(short *)(param_1 + 0x30),(int)*(short *)(param_1 + 0x32),
                        (int)*(short *)(param_1 + 0x34),(int)*(short *)(param_1 + 0x36),
                        *(uchar *)(param_1 + 0x1c));
    TDrawArea::DrawLine(param_2,(int)*(short *)(param_1 + 0x34),(int)*(short *)(param_1 + 0x36),
                        (int)*(short *)(param_1 + 0x38),(int)*(short *)(param_1 + 0x3a),
                        *(uchar *)(param_1 + 0x1c));
    TDrawArea::DrawLine(param_2,(int)*(short *)(param_1 + 0x38),(int)*(short *)(param_1 + 0x3a),
                        (int)*(short *)(param_1 + 0x3c),(int)*(short *)(param_1 + 0x3e),
                        *(uchar *)(param_1 + 0x1c));
    TDrawArea::DrawLine(param_2,(int)*(short *)(param_1 + 0x3c),(int)*(short *)(param_1 + 0x3e),
                        (int)*(short *)(param_1 + 0x30),(int)*(short *)(param_1 + 0x32),
                        *(uchar *)(param_1 + 0x1c));
    return;
  }
  if ((*(int *)(param_1 + 0x2c) == 2) &&
     (iVar1 = (int)*(short *)(param_1 + 0x32), iVar1 <= *(short *)(param_1 + 0x36))) {
    do {
      if (*(short *)(param_1 + 0x3a) != 0) {
        TDrawArea::DrawLine(param_2,(int)*(short *)(param_1 + 0x30),iVar1,
                            (int)*(short *)(param_1 + 0x38),iVar1,'J');
      }
      if (*(short *)(param_1 + 0x3e) != 0) {
        TDrawArea::DrawLine(param_2,(int)*(short *)(param_1 + 0x3c),iVar1,
                            (int)*(short *)(param_1 + 0x34),iVar1,0x97);
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 <= *(short *)(param_1 + 0x36));
  }
  if (*(int *)(param_1 + 0x2c) == 4) {
    TDrawArea::DrawLine(param_2,(int)*(short *)(param_1 + 0x30),(int)*(short *)(param_1 + 0x32),
                        (int)*(short *)(param_1 + 0x34),(int)*(short *)(param_1 + 0x32),0xff);
    TDrawArea::DrawLine(param_2,(int)*(short *)(param_1 + 0x30),(int)*(short *)(param_1 + 0x36),
                        (int)*(short *)(param_1 + 0x34),(int)*(short *)(param_1 + 0x36),0xff);
    TDrawArea::DrawLine(param_2,(int)*(short *)(param_1 + 0x30),(int)*(short *)(param_1 + 0x32),
                        (int)*(short *)(param_1 + 0x30),(int)*(short *)(param_1 + 0x36),0xff);
    TDrawArea::DrawLine(param_2,(int)*(short *)(param_1 + 0x34),(int)*(short *)(param_1 + 0x32),
                        (int)*(short *)(param_1 + 0x34),(int)*(short *)(param_1 + 0x36),0xff);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0053858e
// Address: 0053858e
undefined1 __thiscall
FUN_0053858e(int param_1,int param_2,int param_3,int param_4,int param_5,uint param_6)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  uVar5 = 0;
  if ((((param_2 < 1) || (param_3 < 1)) || (param_4 + -1 <= param_2)) || (param_5 + -1 <= param_3))
{
    if ((0 < param_2) && (((uint)(&unified_map_offsets)[param_3][param_2 + -1] & param_6) == 0)) {
      uVar5 = 0x10;
    }
    param_4 = param_4 + -1;
    if ((param_2 < param_4) && (((uint)(&unified_map_offsets)[param_3][param_2 + 1] & param_6) == 0)
       ) {
      uVar5 = uVar5 | 0x40;
    }
    if ((0 < param_3) &&
       ((*(uint *)(*(int *)(&UNK_0087d850.field_0x8fb4 + param_3 * 4) + param_2 * 4) & param_6) == 0
       )) {
      uVar5 = uVar5 | 0x80;
    }
    param_5 = param_5 + -1;
    if ((param_3 < param_5) && ((*(uint *)((&DAT_0088680c)[param_3] + param_2 * 4) & param_6) == 0))
{
      uVar5 = uVar5 | 0x20;
    }
    if (0 < param_2) {
      if ((0 < param_3) &&
         ((*(uint *)(*(int *)(&UNK_0087d850.field_0x8fb4 + param_3 * 4) + -4 + param_2 * 4) &
          param_6) == 0)) {
        uVar5 = uVar5 | 1;
      }
      if (((0 < param_2) && (param_3 < param_5)) &&
         ((*(uint *)((&DAT_0088680c)[param_3] + -4 + param_2 * 4) & param_6) == 0)) {
        uVar5 = uVar5 | 2;
      }
    }
    if (param_2 < param_4) {
      if ((0 < param_3) &&
         ((*(uint *)(*(int *)(&UNK_0087d850.field_0x8fb4 + param_3 * 4) + 4 + param_2 * 4) & param_6
          ) == 0)) {
        uVar5 = uVar5 | 8;
      }
      if (((param_2 < param_4) && (param_3 < param_5)) &&
         ((*(uint *)((&DAT_0088680c)[param_3] + 4 + param_2 * 4) & param_6) == 0)) {
        uVar5 = uVar5 | 4;
      }
    }
  }
  else {
    iVar3 = *(int *)(&UNK_0087d850.field_0x8fb4 + param_3 * 4);
    iVar1 = param_2 * 4;
    if ((*(uint *)(iVar3 + iVar1) & param_6) == 0) {
      uVar5 = 0x80;
    }
    iVar2 = param_2 * 4 + 4;
    if (((uint)(&unified_map_offsets)[param_3][param_2 + 1] & param_6) == 0) {
      uVar5 = uVar5 | 0x40;
    }
    iVar4 = (&DAT_0088680c)[param_3];
    if ((*(uint *)(iVar4 + iVar1) & param_6) == 0) {
      uVar5 = uVar5 | 0x20;
    }
    if (((uint)(&unified_map_offsets)[param_3][param_2 + -1] & param_6) == 0) {
      uVar5 = uVar5 | 0x10;
    }
    if ((*(uint *)(iVar2 + iVar3) & param_6) == 0) {
      uVar5 = uVar5 | 8;
    }
    if ((*(uint *)(iVar4 + iVar2) & param_6) == 0) {
      uVar5 = uVar5 | 4;
    }
    if ((*(uint *)(iVar4 + -4 + iVar1) & param_6) == 0) {
      uVar5 = uVar5 | 2;
    }
    if ((*(uint *)(iVar3 + -4 + iVar1) & param_6) == 0) {
      uVar5 = uVar5 | 1;
    }
  }
  return *(undefined1 *)(uVar5 + 0x1a0 + param_1);
}

// --------------------------------------------------

// Function: FUN_0053870e
// Address: 0053870e
undefined4 __thiscall
FUN_0053870e(RGE_View *param_1,int param_2,byte param_3,short param_4,short param_5,short param_6,
            short param_7,uchar param_8,int param_9,int param_10)
{
  uchar *puVar1;
  byte bVar2;
  byte bVar3;
  uchar uVar4;
  RGE_Map *pRVar5;
  TShape *pTVar6;
  RGE_Tile *pRVar7;
  bool bVar8;
  short sVar9;
  int iVar10;
  uint uVar11;
  byte bVar12;
  int iStack_18;
  int iStack_14;
  int iStack_10;
  int iStack_c;
  undefined4 uStack_8;
  int iStack_4;
  
  bVar2 = *(byte *)(param_2 + 10);
  pRVar5 = param_1->map;
  if ((pRVar5->num_terrain <= (short)(ushort)param_3) ||
     (iStack_4 = (uint)param_3 * 0x198, pRVar5->terrain_types[param_3].loaded == '\0')) {
    return 0;
  }
  uVar4 = '\x01';
  uStack_8 = 0;
  bVar8 = false;
  bVar3 = *(byte *)(param_2 + 6);
  bVar12 = bVar3 & 0xf;
  if ((((bVar3 & 0xf) != 0) && (uVar11 = bVar3 & 0xf, pRVar5->border_types[uVar11].loaded != '\0'))
     && (pRVar5->border_types[uVar11].shape != (TShape *)0x0)) {
    if (pRVar5->border_types[uVar11].border_style == 0) {
      sVar9 = RGE_View::get_border_picture
                        (param_1,bVar12,*(uchar *)(param_2 + 4),bVar3 >> 4,param_6,param_7);
      if (sVar9 != -1) {
        bVar8 = true;
        uVar4 = param_1->map->border_types[uVar11].draw_tile;
      }
    }
    else {
      iVar10 = RGE_View::get_border_edge_pictures
                         (param_1,bVar12,*(uchar *)(param_2 + 4),bVar3 >> 4,param_6,param_7,
                          &iStack_18,&iStack_10,&iStack_14,&iStack_c);
      if (iVar10 != 0) {
        bVar8 = true;
        uVar4 = '\x01';
      }
    }
  }
  if (((0 < View_Grid_Mode) && ((bVar2 & 0xdf) == 0)) &&
     (((char)((int)param_6 / View_Grid_Mode) + (char)((int)param_7 / View_Grid_Mode) & 1U) == 1)) {
    bVar2 = bVar2 | 0x20;
  }
  if (view_debug_ObstructionMap != 0) {
    bVar8 = false;
  }
  if (uVar4 != '\0') {
    pTVar6 = *(TShape **)(param_1->map->terrain_types[0].pict_name + iStack_4 + 0x11);
    sVar9 = RGE_View::get_tile_picture(param_1,param_3,*(uchar *)(param_2 + 4),param_6,param_7);
    if ((pTVar6 != (TShape *)0x0) && (sVar9 != -1)) {
      if (view_debug_ObstructionMap != 0) {
        RGE_View::draw_terrain_obstruction_map
                  (param_1,(int)param_4,(int)param_5,pTVar6,(int)sVar9,(int)param_6,(int)param_7);
        return 1;
      }
      RGE_View::draw_terrain_shape
                (param_1,(int)param_4,(int)param_5,pTVar6,(int)sVar9,param_8,bVar2,param_9,param_10)
      ;
      uStack_8 = 1;
    }
    if (!bVar8) {
      if (0 < param_6) {
        puVar1 = &param_1->map->map_row_offset[param_7][param_6 + -1].draw_attribute;
        *puVar1 = *puVar1 | 0x40;
      }
      if ((int)param_7 < param_1->map->map_height + -1) {
        puVar1 = &param_1->map->map_row_offset[param_7 + 1][param_6].draw_attribute;
        *puVar1 = *puVar1 | 0x40;
      }
    }
  }
  if (!bVar8) {
    return uStack_8;
  }
  pTVar6 = param_1->map->border_types[bVar3 & 0xf].shape;
  if (pTVar6 == (TShape *)0x0) goto LAB_00538b0e;
  if (param_1->map->border_types[bVar3 & 0xf].border_style == 0) {
    sVar9 = RGE_View::get_border_picture
                      (param_1,bVar12,*(uchar *)(param_2 + 4),*(byte *)(param_2 + 6) >> 4,param_6,
                       param_7);
    if (sVar9 == -1) goto LAB_00538b0e;
    iStack_c = (int)sVar9;
  }
  else {
    iVar10 = RGE_View::get_border_edge_pictures
                       (param_1,bVar12,*(uchar *)(param_2 + 4),*(byte *)(param_2 + 6) >> 4,param_6,
                        param_7,&iStack_18,&iStack_10,&iStack_14,&iStack_c);
    if (iVar10 == 0) goto LAB_00538b0e;
    if (iStack_18 != -1) {
      RGE_View::draw_terrain_shape
                (param_1,(int)param_4,(int)param_5,pTVar6,iStack_18,param_8,bVar2,param_9,param_10);
    }
    if (iStack_14 != -1) {
      RGE_View::draw_terrain_shape
                (param_1,(int)param_4,(int)param_5,pTVar6,iStack_14,param_8,bVar2,param_9,param_10);
    }
    if (iStack_10 != -1) {
      RGE_View::draw_terrain_shape
                (param_1,(int)param_4,(int)param_5,pTVar6,iStack_10,param_8,bVar2,param_9,param_10);
    }
    if (iStack_c == -1) goto LAB_00538b0e;
  }
  RGE_View::draw_terrain_shape
            (param_1,(int)param_4,(int)param_5,pTVar6,iStack_c,param_8,bVar2,param_9,param_10);
LAB_00538b0e:
  if (0 < param_6) {
    puVar1 = &param_1->map->map_row_offset[param_7][param_6 + -1].draw_attribute;
    *puVar1 = *puVar1 | 0x40;
  }
  if ((int)param_7 < param_1->map->map_height + -1) {
    pRVar7 = param_1->map->map_row_offset[param_7 + 1];
    pRVar7[param_6].draw_attribute = pRVar7[param_6].draw_attribute | 0x40;
  }
  return uStack_8;
}

// --------------------------------------------------

// Function: FUN_00538b7f
// Address: 00538b7f
void __thiscall
FUN_00538b7f(int param_1,int param_2,int param_3,TShape *param_4,long param_5,char param_6,
            byte param_7,int param_8,int param_9)
{
  int iVar1;
  int iVar2;
  
  iVar2 = param_4->shape_info[param_5].Hotspot_Y;
  iVar1 = param_4->shape_info[param_5].Hotspot_X;
  if ((param_7 & 0x10) == 0x10) {
    fog_next_shape = 1;
    _ASMSet_Shadowing(0xff00ff,0x28002800,&DAT_ff00ff00,0x280028);
    TShape::shape_draw(param_4,*(TDrawArea **)(param_1 + 0xf4),param_2 - iVar1,param_3 - iVar2,
                       param_5,'\0',(uchar *)0x0);
    _ASMSet_Shadowing(0xff00ff,0,&DAT_ff00ff00,0);
    fog_next_shape = 0;
    return;
  }
  if ((param_7 & 0x20) == 0x20) {
    _ASMSet_Shadowing(0xff00ff,0x56005600,&DAT_ff00ff00,&DAT_00560056);
  }
  if ((param_7 & 0x80) == 0x80) {
    iVar2 = (param_7 & 0xf) * 0x10001000 + 0x4000400;
    _ASMSet_Shadowing(0xff00ff,iVar2,&DAT_ff00ff00,iVar2);
  }
  if ((*(char *)(*(int *)(param_1 + 0x104) + 0x8db9) != '\0') && (param_6 == -0x80)) {
    fog_next_shape = 1;
  }
  if (param_9 != 0) {
    *(undefined4 *)(*(int *)(param_1 + 0xf4) + 0xd0) = *(undefined4 *)(param_1 + 0x17c);
    fog_next_shape = 1;
    TShape::shape_draw(param_4,*(TDrawArea **)(param_1 + 0xf4),param_2,param_3,param_5,'\0',
                       (uchar *)0x0);
    fog_next_shape = 0;
  }
  if ((param_7 & 0xa0) != 0) {
    fog_next_shape = 1;
  }
  if (param_8 != 0) {
    *(undefined4 *)(*(int *)(param_1 + 0xf4) + 0xd0) = *(undefined4 *)(param_1 + 0x178);
    TShape::shape_draw(param_4,*(TDrawArea **)(param_1 + 0xf4),param_2,param_3,param_5,'\0',
                       (uchar *)0x0);
  }
  *(undefined4 *)(*(int *)(param_1 + 0xf4) + 0xd0) =
       *(undefined4 *)(*(int *)(param_1 + 0xf4) + 0xcc);
  _ASMSet_Shadowing(0xff00ff,0,&DAT_ff00ff00,0);
  fog_next_shape = 0;
  return;
}

// --------------------------------------------------

// Function: FUN_00538d58
// Address: 00538d58
void __thiscall
FUN_00538d58(int param_1,int param_2,int param_3,TShape *param_4,long param_5,int param_6,
            int param_7)
{
  int iVar1;
  byte bVar2;
  TShape *this;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar1 = param_6 * 4;
  *(undefined4 *)(*(int *)(param_1 + 0xf4) + 0xd0) = *(undefined4 *)(param_1 + 0x178);
  TShape::shape_draw(param_4,*(TDrawArea **)(param_1 + 0xf4),param_2,param_3,param_5,'\0',
                     (uchar *)0x0);
  this = RGE_Base_Game::get_shape(rge_base_game,0);
  param_6 = 0;
  do {
    iVar4 = 0;
    iVar5 = param_6 * 8;
    iVar3 = param_6 * 4;
    do {
      bVar2 = PathingSystem::obstruction(&pathSystem,iVar4 + iVar1,param_6 + param_7 * 4);
      if (bVar2 != 0) {
        TShape::shape_draw(this,*(TDrawArea **)(param_1 + 0xf4),param_2 + 2 + iVar5,
                           param_3 + 0xd + iVar3,bVar2 - 1,'\0',(uchar *)0x0);
      }
      iVar4 = iVar4 + 1;
      iVar5 = iVar5 + 8;
      iVar3 = iVar3 + -4;
    } while (iVar4 < 4);
    param_6 = param_6 + 1;
  } while (param_6 < 4);
  return;
}

// --------------------------------------------------

// Function: FUN_00538e5a
// Address: 00538e5a
undefined4 __thiscall FUN_00538e5a(int param_1,int *param_2,int param_3,int param_4)
{
  GetCursorPos(param_2);
  if (*(char *)(**(int **)(param_1 + 0x20) + 0x479) == '\x01') {
    ScreenToClient((*(int **)(param_1 + 0x20))[1],param_2);
    if (0x7fff < *param_2) {
      *param_2 = *param_2 + -0x10000;
    }
    if (0x7fff < param_2[1]) {
      param_2[1] = param_2[1] + -0x10000;
    }
  }
  param_3 = *param_2 + param_3;
  *param_2 = param_3;
  param_4 = param_2[1] + param_4;
  param_2[1] = param_4;
  if ((((*(int *)(param_1 + 0x8c) <= param_3) && (param_3 <= *(int *)(param_1 + 0x94))) &&
      (*(int *)(param_1 + 0x90) <= param_4)) && (param_4 <= *(int *)(param_1 + 0x98))) {
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_00538ef7
// Address: 00538ef7
undefined4 __thiscall
FUN_00538ef7(RGE_View *param_1,int param_2,int param_3,int *param_4,int *param_5)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iStack_4;
  
  iVar1 = param_1->map->map_width;
  iStack_4 = param_1->map->map_height;
  iVar2 = (param_1->map_scr_x_offset - param_1->_padding_) + param_2;
  iVar4 = (param_1->map_scr_y_offset - param_1->_padding_) + param_3;
  if (iVar2 < 0) {
    *param_4 = -1;
    *param_5 = -1;
    return 0;
  }
  if (iVar2 < iVar1 * param_1->tile_wid) {
    iVar2 = iVar2 / (int)param_1->tile_wid;
    iVar3 = iVar4 / (int)param_1->tile_hgt;
    iVar5 = iVar2 - iVar3;
    for (iVar2 = iVar2 + iVar3; (iVar5 < 0 || (iVar1 <= iVar2)); iVar2 = iVar2 + -1) {
      iVar5 = iVar5 + 1;
    }
    for (; (iStack_4 <= iVar5 || (iVar2 < 0)); iVar2 = iVar2 + 1) {
      iVar5 = iVar5 + -1;
    }
    param_4 = (int *)0x1;
    do {
      RGE_View::get_tile_bounding_coords
                (param_1,iVar2,iVar5,&iStack_4,(int *)&param_5,&param_3,&param_2);
      if (iVar4 < (int)param_5) {
        iVar2 = iVar2 + 1;
        iVar5 = iVar5 + -1;
      }
      else if (param_2 < iVar4) {
        iVar2 = iVar2 + -1;
        iVar5 = iVar5 + 1;
      }
      else {
        param_4 = (int *)0x0;
      }
    } while (param_4 != (int *)0x0);
    param_1->tile_half_hgt = 0;
    param_1->tile_half_wid = 0;
    return 0;
  }
  *param_4 = iVar1 + 1;
  *param_5 = iStack_4 + 1;
  return 0;
}

// --------------------------------------------------

// Function: FUN_0053902d
// Address: 0053902d
void __thiscall
FUN_0053902d(int param_1,int param_2,int param_3,int *param_4,int *param_5,int *param_6,int *param_7
            )
{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar1 = *(int *)(*(int *)(*(int *)(param_1 + 0x104) + 0x8d8c) + param_3 * 4);
  iVar3 = (int)*(short *)(iVar1 + param_2 * 0x18);
  iVar1 = iVar1 + param_2 * 0x18;
  uVar2 = (uint)*(byte *)(iVar1 + 4);
  *param_4 = iVar3;
  *param_6 = *(short *)(*(int *)(param_1 + 0x104) + (uVar2 + 4) * 6) + -1 + iVar3;
  *param_5 = (int)*(short *)(iVar1 + 2) - (int)*(short *)(param_1 + 0x10e);
  *(undefined2 *)(param_1 + 0x10e) = 0;
  *(undefined2 *)(param_1 + 0x10c) = 0;
  *(undefined2 *)(param_1 + 0x110) = 0;
  *param_7 = *(short *)(*(int *)(param_1 + 0x104) + 0x1a + uVar2 * 6) + -1 + *param_5;
  return;
}

// --------------------------------------------------

// Function: FUN_005390c3
// Address: 005390c3
int __thiscall
FUN_005390c3(RGE_View *param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
            int param_7,int param_8)
{
  short sVar1;
  DClipInfo_Node *pDVar2;
  bool bVar3;
  int iVar4;
  RGE_SPick_Info *pRVar5;
  int iVar6;
  RGE_SPick_Info *pRVar7;
  RGE_SPick_Info *pRVar8;
  undefined2 *puVar9;
  undefined4 *puVar10;
  int iVar11;
  int iVar12;
  int *piVar13;
  RGE_SPick_Info *pRVar14;
  int iStack_44;
  int iStack_40;
  int aiStack_3c [6];
  int aiStack_24 [5];
  int aiStack_10 [4];
  
  iStack_40 = 0;
  if (((((param_6 < 0) || (param_5 < param_4)) || (param_2 < param_1->_padding_)) ||
      ((param_1->_padding_ < param_2 || (param_3 < param_1->_padding_)))) ||
     ((param_1->_padding_ < param_3 || ((0x28 < param_4 || (param_5 < 0)))))) {
    return 0;
  }
  if (param_4 < 0) {
    param_4 = 0;
  }
  if (0x28 < param_5) {
    param_5 = 0x28;
  }
  pRVar5 = (RGE_SPick_Info *)(param_3 - param_1->_padding_);
  param_2 = param_2 - param_1->_padding_;
  aiStack_10[0] = 0;
  aiStack_10[1] = 0;
  aiStack_10[2] = 0;
  aiStack_10[3] = 0;
  aiStack_24[0] = 0;
  aiStack_24[1] = 0;
  aiStack_24[2] = 0;
  aiStack_24[3] = 0;
  aiStack_3c[1] = 0;
  aiStack_3c[2] = 0;
  aiStack_3c[3] = 0;
  aiStack_3c[4] = 0;
  param_1->pick_list_size[1] = 0;
  param_1->pick_list_size[2] = 0;
  param_1->pick_list_size[3] = 0;
  param_1->pick_list_size[4] = 0;
  pRVar14 = pRVar5;
  do {
    if (param_5 < param_4) {
      iVar12 = 1;
      piVar13 = aiStack_3c;
      do {
        piVar13 = piVar13 + 1;
        puVar10 = (undefined4 *)*piVar13;
        if (puVar10 != (undefined4 *)0x0) {
          puVar9 = &DAT_0087d4a4 + iStack_40 * 6;
          do {
            iStack_40 = iStack_40 + 1;
            *(undefined4 *)(puVar9 + -2) = *puVar10;
            *puVar9 = *(undefined2 *)(puVar10 + 1);
            puVar9[1] = *(undefined2 *)((int)puVar10 + 6);
            puVar9[2] = *(undefined2 *)(puVar10 + 2);
            puVar9[3] = *(undefined2 *)((int)puVar10 + 10);
            puVar9 = puVar9 + 6;
            if (0x87d7a3 < (int)puVar9) {
              return 0x40;
            }
            puVar10 = (undefined4 *)puVar10[3];
          } while (puVar10 != (undefined4 *)0x0);
        }
        iVar12 = iVar12 + 1;
      } while (iVar12 < 5);
      return iStack_40;
    }
    for (pDVar2 = param_1->prior_objs->Draw_Level_Head[param_5]; pDVar2 != (DClipInfo_Node *)0x0;
        pDVar2 = pDVar2->NextOnLevel) {
      iVar12 = 0;
      if ((pDVar2->Node_Type == 0) && ((param_8 == 0 || (-1 < pDVar2->Object_ID)))) {
        iVar11 = (int)pDVar2->y1;
        iVar6 = (int)pDVar2->x2;
        if ((param_2 < pDVar2->x1 - param_6) ||
           ((((int)pRVar5 < iVar11 - param_6 || (param_6 + iVar6 < param_2)) ||
            (pDVar2->y2 + param_6 < (int)pRVar5)))) {
          iVar12 = 0;
        }
        else {
          iVar12 = 4;
          if (((pDVar2->x1 <= param_2) && (iVar11 <= (int)pRVar5)) &&
             ((param_2 <= iVar6 && ((int)pRVar5 <= (int)pDVar2->y2)))) {
            iVar12 = 3;
            if (((byte)pDVar2->Draw_Flag & 2) == 2) {
              iVar6 = iVar6 - param_2;
            }
            else {
              iVar6 = param_2 - pDVar2->x1;
            }
            iVar6 = RGE_View::sprite_check
                              (param_1,pDVar2->Shape_Base,pDVar2->Shape,iVar6,(int)pRVar5 - iVar11);
            if (iVar6 == 1) {
              iVar12 = 2;
            }
            else if (iVar6 == 2) {
              iVar12 = 1;
            }
          }
        }
      }
      if ((iVar12 != 0) && (iVar12 <= param_7)) {
        sVar1 = pDVar2->y3;
        iVar6 = pDVar2->Object_ID;
        iVar11 = 1;
        bVar3 = true;
        piVar13 = aiStack_3c;
        pRVar8 = (RGE_SPick_Info *)0x0;
        do {
          piVar13 = piVar13 + 1;
          pRVar7 = pRVar8;
          if (pRVar8 != (RGE_SPick_Info *)0x0) goto LAB_0053931b;
          for (pRVar14 = (RGE_SPick_Info *)*piVar13;
              (pRVar7 = pRVar8, iVar4 = iStack_44, pRVar14 != (RGE_SPick_Info *)0x0 &&
              (pRVar7 = pRVar14, iVar4 = iVar11, pRVar14->object_id != iVar6));
              pRVar14 = pRVar14->next) {
          }
          iStack_44 = iVar4;
          iVar11 = iVar11 + 1;
          pRVar8 = pRVar7;
        } while (iVar11 < 5);
        if (pRVar7 != (RGE_SPick_Info *)0x0) {
LAB_0053931b:
          if ((iStack_44 < iVar12) || ((iStack_44 == iVar12 && (sVar1 < pRVar7->draw_level)))) {
            bVar3 = false;
          }
          if (bVar3) {
            if ((RGE_SPick_Info *)aiStack_3c[iStack_44] == pRVar7) {
              aiStack_3c[iStack_44] = (int)pRVar7->next;
            }
            if ((RGE_SPick_Info *)aiStack_3c[iStack_44 + 5] == pRVar7) {
              aiStack_3c[iStack_44 + 5] = (int)pRVar7->prev;
            }
            if (pRVar7->next != (RGE_SPick_Info *)0x0) {
              pRVar7->next->prev = pRVar7->prev;
            }
            if (pRVar7->prev != (RGE_SPick_Info *)0x0) {
              pRVar7->prev->next = pRVar7->next;
            }
            pRVar7->next = (RGE_SPick_Info *)aiStack_3c[iStack_44 + 10];
            pRVar7->prev = (RGE_SPick_Info *)0x0;
            aiStack_3c[iStack_44 + 10] = (int)pRVar7;
          }
        }
        if (bVar3) {
          pRVar8 = (RGE_SPick_Info *)aiStack_3c[iVar12 + 10];
          if (pRVar8 == (RGE_SPick_Info *)0x0) {
            iVar11 = param_1->pick_list_size[iVar12];
            if (iVar11 == 0x40) {
              bVar3 = false;
            }
            else {
              pRVar14 = param_1->pick_lists[iVar12] + iVar11;
              param_1->pick_list_size[iVar12] = iVar11 + 1;
            }
          }
          else {
            aiStack_3c[iVar12 + 10] = (int)pRVar8->next;
            pRVar14 = pRVar8;
          }
          if (bVar3) {
            pRVar14->object_id = iVar6;
            pRVar14->confidence = (short)iVar12;
            pRVar14->draw_level = sVar1;
            pRVar14->draw_x = (short)pDVar2->Draw_X;
            piVar13 = aiStack_3c + iVar12;
            pRVar14->draw_y = (short)pDVar2->Draw_Y;
            pRVar8 = (RGE_SPick_Info *)*piVar13;
            pRVar14->next = (RGE_SPick_Info *)0x0;
            pRVar14->prev = (RGE_SPick_Info *)0x0;
            if (pRVar8 == (RGE_SPick_Info *)0x0) {
              *piVar13 = (int)pRVar14;
LAB_00539462:
              aiStack_3c[iVar12 + 5] = (int)pRVar14;
            }
            else {
              do {
                if (pRVar8->draw_level <= sVar1) {
                  pRVar14->next = pRVar8;
                  pRVar7 = pRVar8->prev;
                  pRVar14->prev = pRVar7;
                  if (pRVar7 == (RGE_SPick_Info *)0x0) {
                    *piVar13 = (int)pRVar14;
                    pRVar8->prev = pRVar14;
                  }
                  else {
                    pRVar14->prev->next = pRVar14;
                    pRVar8->prev = pRVar14;
                  }
                  break;
                }
                pRVar7 = pRVar8->next;
                if (pRVar7 == (RGE_SPick_Info *)0x0) {
                  pRVar8->next = pRVar14;
                  pRVar14->prev = pRVar8;
                  goto LAB_00539462;
                }
                pRVar8 = pRVar7;
              } while (pRVar7 != (RGE_SPick_Info *)0x0);
            }
          }
        }
      }
    }
    param_5 = param_5 + -1;
  } while( true );
}

// --------------------------------------------------

// Function: FUN_00539509
// Address: 00539509
undefined4 FUN_00539509(int param_1,int *param_2,int param_3,int param_4)
{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  byte *pbVar4;
  int iVar5;
  uint uVar6;
  
  if ((((param_2 != (int *)0x0) && (-1 < param_3)) && (iVar2 = param_2[4], param_3 < iVar2)) &&
     ((-1 < param_4 && (param_4 < param_2[5])))) {
    iVar5 = (int)*(short *)(param_2[1] + param_1 + param_4 * 4);
    if ((-1 < iVar5) &&
       ((iVar5 <= param_3 && (param_3 <= iVar2 - *(short *)(param_2[1] + param_1 + 2 + param_4 * 4))
        ))) {
      pbVar3 = (byte *)(*(int *)(*param_2 + param_1 + param_4 * 4) + param_1);
      if (iVar5 < iVar2) {
        while (iVar5 <= param_3) {
          bVar1 = *pbVar3;
          pbVar4 = pbVar3 + 1;
          param_2 = (int *)(uint)bVar1;
          switch(bVar1 & 0xf) {
          case 0:
          case 4:
          case 8:
          case 0xc:
            iVar5 = iVar5 + (uint)(bVar1 >> 2);
            if (param_3 < iVar5) {
              return 2;
            }
            pbVar4 = pbVar4 + (bVar1 >> 2);
            break;
          case 1:
          case 5:
          case 9:
          case 0xd:
            iVar5 = iVar5 + (uint)(bVar1 >> 2);
            break;
          case 2:
            uVar6 = (int)param_2 << 4 | (uint)*pbVar4;
            iVar5 = iVar5 + uVar6;
            if (param_3 < iVar5) {
              return 2;
            }
            pbVar4 = pbVar3 + uVar6 + 2;
            break;
          case 3:
            bVar1 = *pbVar4;
            pbVar4 = pbVar3 + 2;
            iVar5 = iVar5 + ((int)param_2 << 4 | (uint)bVar1);
            break;
          case 6:
            uVar6 = (uint)(bVar1 >> 4);
            if (uVar6 == 0) {
              uVar6 = (uint)*pbVar4;
              pbVar4 = pbVar3 + 2;
            }
            iVar5 = iVar5 + uVar6;
            if (param_3 < iVar5) {
              return 2;
            }
            pbVar4 = pbVar4 + uVar6;
            break;
          case 7:
          case 10:
            uVar6 = (uint)(bVar1 >> 4);
            if (uVar6 == 0) {
              uVar6 = (uint)*pbVar4;
              pbVar4 = pbVar3 + 2;
            }
            iVar5 = iVar5 + uVar6;
            if (param_3 < iVar5) {
              return 2;
            }
            pbVar4 = pbVar4 + 1;
            break;
          case 0xb:
            uVar6 = (uint)(bVar1 >> 4);
            if (uVar6 == 0) {
              uVar6 = (uint)*pbVar4;
              pbVar4 = pbVar3 + 2;
            }
            iVar5 = iVar5 + uVar6;
            if (param_3 < iVar5) {
              return 2;
            }
            break;
          case 0xe:
          case 0xf:
            goto switchD_005395b3_caseD_e;
          default:
            goto switchD_005395b3_default;
          }
          pbVar3 = pbVar4;
          if (iVar2 <= iVar5) {
            return 1;
          }
        }
      }
switchD_005395b3_default:
      return 1;
    }
  }
switchD_005395b3_caseD_e:
  return 0;
}

// --------------------------------------------------

// Function: FUN_005396ad
// Address: 005396ad
int __fastcall FUN_005396ad(int param_1)
{
  char *pcVar1;
  int iVar2;
  bool bVar3;
  short sVar4;
  uint in_EAX;
  int iVar5;
  RGE_Pick_Obj_Info *pRVar6;
  char cVar8;
  RGE_Pick_Obj_Info *unaff_EBX;
  RGE_Pick_Obj_Info **ppRVar7;
  undefined4 unaff_EBP;
  int iVar9;
  char unaff_SI;
  int iVar10;
  short *psVar11;
  byte unaff_retaddr;
  int iVar12;
  RGE_Pick_Obj_Info *pRVar13;
  RGE_Pick_Obj_Info *pRVar14;
  
  iVar5 = CONCAT31((int3)((uint)unaff_EBP >> 8),(char)unaff_EBP + (char)unaff_EBX);
  *(char *)&unaff_EBX->object_id = (char)unaff_EBX->object_id + (char)param_1;
  cVar8 = (char)((uint)unaff_EBX >> 8);
  cRamf400a72a = cRamf400a72a + cVar8;
  *(char *)&unaff_EBX->object_id = (char)unaff_EBX->object_id + (char)((uint)unaff_EBP >> 8);
  *(char *)(param_1 + -0x6a) = *(char *)(param_1 + -0x6a) + (char)in_EAX;
  cRamf400a72a = cRamf400a72a + cVar8;
  *(char *)(param_1 + -0x6a) = *(char *)(param_1 + -0x6a) + unaff_SI;
  pcVar1 = (char *)(iVar5 + -0x6a);
  *pcVar1 = *pcVar1 + (char)unaff_EBX;
  cRamf400a72a = cRamf400a72a + cVar8;
  pcVar1 = (char *)(iVar5 + 0x7ea54ea7);
  *pcVar1 = *pcVar1 + (char)(in_EAX >> 8);
  *(char *)&unaff_EBX[0x5b64113].draw_x = (char)unaff_EBX[0x5b64113].draw_x + (char)in_EAX;
  iVar9 = 0;
  iVar5 = *(int *)(param_1 + 0x8c);
  iVar12 = 0;
  if ((((((int)(in_EAX & 0xffffff18) < iVar5) || (*(int *)(param_1 + 0x94) < (int)unaff_EBX)) ||
       (iVar2 = *(int *)(param_1 + 0x90), (int)unaff_EBX < iVar2)) ||
      ((*(int *)(param_1 + 0x98) < (int)unaff_EBX || (0x28 < (int)unaff_EBX)))) ||
     ((int)unaff_EBX < 0)) {
    return 0;
  }
  pRVar13 = unaff_EBX;
  if ((int)unaff_EBX < 0) {
    pRVar13 = (RGE_Pick_Obj_Info *)0x0;
  }
  pRVar6 = unaff_EBX;
  if (0x28 < (int)unaff_EBX) {
    pRVar6 = (RGE_Pick_Obj_Info *)0x28;
  }
  pRVar14 = unaff_EBX;
  do {
    if ((int)pRVar6 < (int)pRVar13) {
      return iVar9;
    }
    iVar10 = *(int *)(*(int *)(*(int *)(param_1 + 0x334) + 0x5c) + (int)pRVar6 * 4);
    if (iVar10 != 0) {
      psVar11 = &DAT_0087d4a4 + iVar9 * 6;
      iVar9 = iVar12;
      do {
        sVar4 = 0;
        if ((*(int *)(iVar10 + 0x2c) == 0) &&
           (pRVar14 = *(RGE_Pick_Obj_Info **)(iVar10 + 8), -1 < (int)pRVar14)) {
          if (((((int)unaff_EBX - iVar5 <= (int)*(short *)(iVar10 + 0x34)) &&
               ((((int)*(short *)(iVar10 + 0x30) <= (int)unaff_EBX - iVar5 &&
                 ((int)unaff_EBX - iVar2 <= (int)*(short *)(iVar10 + 0x36))) &&
                ((int)*(short *)(iVar10 + 0x32) <= (int)unaff_EBX - iVar2)))) &&
              (((iVar12 = *(int *)(*(int *)(*(int *)(param_1 + 0xfc) + 0x88) + (int)pRVar14 * 4),
                unaff_EBX == (RGE_Pick_Obj_Info *)0xffffffff ||
                ((RGE_Pick_Obj_Info *)(int)*(short *)(*(int *)(iVar12 + 0xc) + 0x4a) == unaff_EBX))
               && (*(char *)(iVar12 + 0x48) == '\x02')))) &&
             (unaff_retaddr <= *(byte *)(*(int *)(iVar12 + 8) + 0x8d))) {
            sVar4 = 1;
          }
        }
        if (sVar4 != 0) {
          bVar3 = true;
          if ((0x87d4a4 < (int)psVar11) && (iVar12 = 0, 0x87d4a4 < (int)psVar11)) {
            ppRVar7 = &Picked_Objects;
            do {
              if (*ppRVar7 == pRVar14) {
                bVar3 = false;
                if (sVar4 < (short)(&DAT_0087d4a4)[iVar12 * 6]) {
                  (&DAT_0087d4a4)[iVar12 * 6] = sVar4;
                }
                break;
              }
              iVar12 = iVar12 + 1;
              ppRVar7 = ppRVar7 + 3;
            } while (iVar12 < iVar9);
          }
          if (bVar3) {
            *(RGE_Pick_Obj_Info **)(psVar11 + -2) = pRVar14;
            *psVar11 = sVar4;
            psVar11[1] = sVar4;
            psVar11[2] = *(short *)(iVar10 + 0x14);
            psVar11[3] = *(short *)(iVar10 + 0x18);
            iVar9 = iVar9 + 1;
            psVar11 = psVar11 + 6;
          }
          if (0x87d7a3 < (int)psVar11) {
            return 0x40;
          }
        }
        iVar10 = *(int *)(iVar10 + 4);
        iVar12 = iVar9;
      } while (iVar10 != 0);
    }
    pRVar6 = (RGE_Pick_Obj_Info *)((int)&pRVar6[-1].draw_y + 1);
  } while( true );
}

// --------------------------------------------------

// Function: FUN_00539926
// Address: 00539926
undefined4 __thiscall
FUN_00539926(RGE_View *param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
            undefined4 *param_7)
{
  int iVar1;
  bool bVar2;
  int iVar3;
  
  *param_7 = 0;
  if ((((param_5 <= param_6) && (param_1->_padding_ <= param_3)) && (param_3 <= param_1->_padding_))
     && (((param_1->_padding_ <= param_4 && (param_4 <= param_1->_padding_)) &&
         ((param_5 < 0x29 && (-1 < param_6)))))) {
    if (param_5 < 0) {
      param_5 = 0;
    }
    if (0x28 < param_6) {
      param_6 = 0x28;
    }
    bVar2 = false;
    for (; param_5 <= param_6; param_6 = param_6 + -1) {
      for (iVar1 = *(int *)(*(int *)(param_2 + 0x5c) + param_6 * 4); iVar1 != 0;
          iVar1 = *(int *)(iVar1 + 4)) {
        if (*(int *)(iVar1 + 0x2c) == 0) {
          if (((byte)*(undefined4 *)(iVar1 + 0x1c) & 2) == 2) {
            iVar3 = RGE_View::sprite_check
                              (param_1,*(uchar **)(iVar1 + 0x20),*(Shape_Info **)(iVar1 + 0xc),
                               *(short *)(iVar1 + 0x34) - param_3,param_4 - *(short *)(iVar1 + 0x32)
                              );
            if (iVar3 == 2) {
              bVar2 = true;
              *param_7 = *(undefined4 *)(iVar1 + 8);
            }
          }
          else {
            iVar3 = RGE_View::sprite_check
                              (param_1,*(uchar **)(iVar1 + 0x20),*(Shape_Info **)(iVar1 + 0xc),
                               param_3 - *(short *)(iVar1 + 0x30),param_4 - *(short *)(iVar1 + 0x32)
                              );
            if (iVar3 == 2) {
              bVar2 = true;
              *param_7 = *(undefined4 *)(iVar1 + 8);
            }
          }
        }
      }
      if (bVar2) {
        return 1;
      }
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_00539a95
// Address: 00539a95
int __thiscall FUN_00539a95(int param_1,uint param_2,uint param_3,short param_4,short param_5)
{
  int iVar1;
  byte bVar2;
  short sVar3;
  int iVar4;
  byte bVar5;
  int iVar6;
  uint uVar7;
  
  uVar7 = *(int *)(param_1 + 0x104) + 0x8c + (param_2 & 0xff) * 0x198;
  if (*(int *)(*(int *)(param_1 + 0x104) + 0xac + (param_2 & 0xff) * 0x198) == 0) {
    return 0xffff;
  }
  sVar3 = *(short *)(uVar7 + 0x46 + (param_3 & 0xff) * 6);
  iVar1 = uVar7 + 0x46 + (param_3 & 0xff) * 6;
  if (sVar3 == 0) {
    return 0xffff;
  }
  iVar6 = 0;
  if (1 < sVar3) {
    bVar5 = *(byte *)(uVar7 + 0xba);
    iVar4 = 0;
    bVar2 = *(byte *)(uVar7 + 0xbc);
    param_2 = (uint)bVar5;
    param_3 = (uint)bVar2;
    if ((1 < bVar5) || (1 < bVar2)) {
      if (bVar5 == 0) {
        bVar5 = 0;
      }
      else {
        iVar4 = (int)param_5 / (int)param_2;
        uVar7 = (int)param_5 % (int)param_2;
        bVar5 = (byte)uVar7;
      }
      if (bVar2 == 0) {
        param_3 = uVar7 & 0xffffff00;
      }
      else {
        iVar4 = (int)param_4 / (int)param_3;
        param_3 = (int)param_4 % (int)param_3;
      }
      iVar6 = (uint)bVar5 * (CONCAT31((int3)((uint)iVar4 >> 8),bVar2) & 0xffff00ff) +
              CONCAT22((short)(param_3 >> 0x10),(ushort)(byte)param_3);
    }
  }
  if (sVar3 + -1 < (int)(short)iVar6) {
    iVar6 = 0;
  }
  return CONCAT22((short)((uint)(sVar3 + -1) >> 0x10),*(undefined2 *)(iVar1 + 2)) * iVar6 +
         CONCAT22((short)((uint)iVar6 >> 0x10),*(undefined2 *)(iVar1 + 4));
}

// --------------------------------------------------

// Function: FUN_00539b8e
// Address: 00539b8e
int __thiscall
FUN_00539b8e(int param_1,uint param_2,uint param_3,byte param_4,short param_5,short param_6)
{
  int iVar1;
  int iVar2;
  short sVar3;
  short sVar4;
  int iVar5;
  
  iVar2 = (param_2 & 0xff) * 0x5a0 + 0x338c + *(int *)(param_1 + 0x104);
  if (*(int *)(iVar2 + 0x20) == 0) {
    return 0xffff;
  }
  iVar1 = param_4 + 10 + (param_3 & 0xff) * 0xc;
  sVar3 = *(short *)(iVar2 + iVar1 * 6);
  iVar1 = iVar2 + iVar1 * 6;
  if (sVar3 == 0) {
    return 0xffff;
  }
  iVar5 = 0;
  if (1 < sVar3) {
    sVar4 = *(short *)(iVar2 + 0x59e);
    if (((sVar4 == 0) && ((param_4 == 0xb || (param_4 == 0xc)))) ||
       ((sVar4 == 1 && ((param_4 == 3 || (param_4 == 2)))))) {
      iVar5 = (int)param_6 % (int)sVar3;
    }
    else if (((sVar4 == 0) && ((param_4 == 9 || (param_4 == 10)))) ||
            ((sVar4 == 1 && ((param_4 == 1 || (param_4 == 4)))))) {
      iVar5 = (int)param_5 % (int)sVar3;
    }
    else {
      iVar5 = 0;
    }
  }
  if (sVar3 + -1 < (int)(short)iVar5) {
    iVar5 = 0;
  }
  return CONCAT22((short)((uint)(sVar3 + -1) >> 0x10),*(undefined2 *)(iVar1 + 2)) * iVar5 +
         CONCAT22((short)((uint)iVar5 >> 0x10),*(undefined2 *)(iVar1 + 4));
}

// --------------------------------------------------

// Function: FUN_00539c7f
// Address: 00539c7f
undefined4 __thiscall
FUN_00539c7f(RGE_View *param_1,byte param_2,uchar param_3,byte param_4,short param_5,short param_6,
            int *param_7,int *param_8,int *param_9,int *param_10)
{
  short sVar1;
  
  *param_7 = -1;
  *param_9 = -1;
  *param_8 = -1;
  *param_10 = -1;
  if (param_1->map->border_types[param_2].shape != (TShape *)0x0) {
    if (param_4 != 0) {
      if ((param_4 & 1) != 0) {
        sVar1 = RGE_View::get_border_picture(param_1,param_2,param_3,'\x01',param_5,param_6);
        *param_7 = (int)sVar1;
      }
      if ((param_4 & 2) != 0) {
        sVar1 = RGE_View::get_border_picture(param_1,param_2,param_3,'\x04',param_5,param_6);
        *param_10 = (int)sVar1;
      }
      if ((param_4 & 4) != 0) {
        sVar1 = RGE_View::get_border_picture(param_1,param_2,param_3,'\x03',param_5,param_6);
        *param_9 = (int)sVar1;
      }
      if ((param_4 & 8) != 0) {
        sVar1 = RGE_View::get_border_picture(param_1,param_2,param_3,'\x02',param_5,param_6);
        *param_8 = (int)sVar1;
      }
      return 1;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_00539d84
// Address: 00539d84
undefined4 __thiscall
FUN_00539d84(RGE_View *param_1,int param_2,short param_3,short param_4,short param_5,short param_6,
            int *param_7)
{
  RGE_Map *pRVar1;
  TShape *this;
  uchar uVar2;
  short sVar3;
  int iVar4;
  int iVar5;
  ushort uVar6;
  
  uVar6 = 0;
  if (param_2 == 0) {
    param_2._0_2_ = 0;
  }
  else {
    uVar6 = *(byte *)(param_2 + 5) & 0x1f;
    param_2._0_2_ = (ushort)*(byte *)(param_2 + 4);
  }
  if ((int)param_3 <= *param_7) {
    iVar4 = (int)(short)(ushort)param_2;
    pRVar1 = param_1->map;
    if (*param_7 < (int)pRVar1->tilesizes[iVar4].width + (int)param_3) {
      iVar5 = (int)param_4;
      if ((iVar5 <= param_7[1]) && (param_7[1] < pRVar1->tilesizes[iVar4].height + iVar5)) {
        if (((short)uVar6 < pRVar1->num_terrain) &&
           (pRVar1->terrain_types[(short)uVar6].loaded != '\0')) {
          this = pRVar1->terrain_types[(short)uVar6].shape;
          sVar3 = RGE_View::get_tile_picture
                            (param_1,(uchar)uVar6,(uchar)(ushort)param_2,param_5,param_6);
          if ((this != (TShape *)0x0) && (sVar3 != -1)) {
            if (param_1->map->tilesizes[iVar4].height + iVar5 <= param_7[1]) {
              return 0;
            }
            uVar2 = TShape::shape_check(this,*param_7 - (int)param_3,param_7[1] - iVar5,(int)sVar3);
            if (uVar2 == '\0') {
              return 0;
            }
            return 1;
          }
        }
        return 1;
      }
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_00539ebc
// Address: 00539ebc
RGE_Static_Object *
FUN_00539ebc(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,short *param_6,short *param_7,short *param_8,short *param_9,RGE_Static_Object *param_10
            ,char param_11)
{
  char cVar1;
  RGE_Static_Object *this;
  RGE_Object_Node *pRVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  short *psVar5;
  RGE_Static_Object *pRVar6;
  uchar uVar7;
  int iVar8;
  short sVar9;
  short sVar10;
  short sStack_1a;
  RGE_Static_Object *pRStack_18;
  int iStack_14;
  RGE_Object_Node *pRStack_10;
  RGE_Object_Node *pRStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  pRStack_18 = (RGE_Static_Object *)0x0;
  if ((RGE_Object_List *)(param_1 + 0xc) != (RGE_Object_List *)0x0) {
    pRStack_10 = RGE_Object_List::sort((RGE_Object_List *)(param_1 + 0xc));
    psVar5 = param_6;
    uVar4 = param_3;
    uVar3 = param_2;
    pRStack_c = pRStack_10;
    for (; (pRStack_10 != (RGE_Object_Node *)0x0 &&
           (this = pRStack_10->node, this != (RGE_Static_Object *)0x0));
        pRStack_10 = pRStack_10->next) {
      pRVar6 = pRStack_18;
      if ((this->object_state < 7) &&
         (((param_11 == '\0' || (this->master_obj->fog_flag != '\0')) &&
          (*(byte *)(iStack_14 + 0x141) <= this->master_obj->select_level)))) {
        cVar1 = *(char *)(iStack_14 + 0x140);
        sVar9 = (short)uVar3;
        sVar10 = (short)uVar4;
        if ((cVar1 == '+') || (cVar1 == ',')) {
          if (this->owner == *(RGE_Player **)(iStack_14 + 0x100)) {
            if (cVar1 != ',') goto LAB_00539fb7;
            uVar7 = RGE_Static_Object::box_hit_test
                              (this,sVar9,sVar10,*param_7,param_7[2],*psVar5,psVar5[2]);
            pRVar6 = pRStack_18;
            if ((uVar7 != '\0') &&
               (iVar8 = RGE_Player::select_one_object(*(RGE_Player **)(iStack_14 + 0x100),this,0),
               pRVar6 = this, iVar8 == 0)) break;
          }
        }
        else {
LAB_00539fb7:
          uVar7 = RGE_Static_Object::hit_test(this,sVar9,sVar10,*psVar5,psVar5[2],5);
          pRVar6 = pRStack_18;
          if (uVar7 != '\0') {
            if (((param_10 != (RGE_Static_Object *)0x0) && (this == param_10)) &&
               (pRStack_18 != (RGE_Static_Object *)0x0)) {
              return pRStack_18;
            }
            if ((pRStack_18 == (RGE_Static_Object *)0x0) ||
               (((this->owner == *(RGE_Player **)(iStack_14 + 0x100) ||
                 (pRStack_18->owner != *(RGE_Player **)(iStack_14 + 0x100))) &&
                ((pRStack_18 == (RGE_Static_Object *)0x0 ||
                 (pRStack_18->master_obj->select_level <= this->master_obj->select_level)))))) {
              pRStack_18 = this;
              iVar8 = RGE_Static_Object::get_frame
                                (this,(short *)&uStack_8,(short *)&uStack_4,&sStack_1a,
                                 (short *)&param_1);
              if (iVar8 == 0) {
                uStack_8 = 0;
                uStack_4 = 0;
              }
              *param_8 = this->screen_x_offset + (short)uStack_8 + sVar9;
              *param_9 = this->screen_y_offset + (short)uStack_4 + sVar10;
              pRVar6 = pRStack_18;
            }
          }
        }
      }
      pRStack_18 = pRVar6;
    }
    while (pRStack_c != (RGE_Object_Node *)0x0) {
      pRVar2 = pRStack_c->next;
      free(pRStack_c);
      pRStack_c = pRVar2;
    }
  }
  return pRStack_18;
}

// --------------------------------------------------

// Function: FUN_0053a0c5
// Address: 0053a0c5
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall
FUN_0053a0c5(RGE_View *param_1,uchar param_2,long param_3,long param_4,int param_5,int param_6)
{
  int iVar1;
  uchar uVar2;
  long lVar3;
  long lVar4;
  int iVar5;
  RGE_Pick_Info RStack_14;
  
  if (param_2 == '\x03') {
    uVar2 = RGE_View::pick(param_1,'(','\0',param_3,param_4,&RStack_14,(RGE_Static_Object *)0x0);
    if (uVar2 != '3') {
      return 0;
    }
    lVar3 = __ftol();
    lVar4 = __ftol();
    RGE_View::set_selection_area(param_1,lVar4,lVar3,lVar4,lVar3);
  }
  else if (param_2 == '\t') {
    RGE_View::pick(param_1,'(','\0',param_3,param_4,&RStack_14,(RGE_Static_Object *)0x0);
    lVar3 = __ftol();
    param_1->real_old_map_col = lVar3;
    lVar3 = __ftol();
    iVar1 = param_1->_padding_;
    param_1->real_old_map_row = lVar3;
    iVar5 = (**(code **)(iVar1 + 0xf4))(param_3,param_4,param_3,param_4,1);
    if (iVar5 == 0) {
      return 0;
    }
    (**(code **)(iVar1 + 0x20))(1);
  }
  param_1->scroll_action = param_2;
  param_1->mouse_last_x = param_3;
  param_1->_padding_ = param_3;
  param_1->mouse_last_y = param_4;
  param_1->_padding_ = param_4;
  TPanel::capture_mouse((TPanel *)param_1);
  uVar2 = param_1->scroll_action;
  if ((((uVar2 == '\x01') || (uVar2 == '\x02')) || (uVar2 == '\x06')) ||
     ((uVar2 == '\a' || (uVar2 == '\b')))) {
    RGE_Base_Game::mouse_off(rge_base_game);
  }
  if (param_1->scroll_action == '\x02') {
    if ((param_6 == 0) && (param_5 == 0)) {
      RGE_Player::unselect_object(param_1->player);
    }
    (**(code **)(param_1->_padding_ + 0x20))(1);
  }
  if ((param_1->scroll_action == '\x06') || (param_1->scroll_action == '\b')) {
    uVar2 = RGE_View::pick(param_1,'(','\0',param_3,param_4,&RStack_14,(RGE_Static_Object *)0x0);
    if (uVar2 == '3') {
      RGE_Player::set_view_loc
                (param_1->player,RStack_14.x - _DAT_005776c0,RStack_14.y - _DAT_005776c0);
      (**(code **)(param_1->_padding_ + 0x20))(1);
      return 1;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0053a285
// Address: 0053a285
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_0053a285(RGE_View *param_1,int param_2,int param_3)
{
  long *plVar1;
  short *psVar2;
  RGE_Player *pRVar3;
  float fVar4;
  float fVar5;
  RGE_Static_Object *pRVar6;
  RGE_Active_Sprite_List *this;
  RGE_Sprite *this_00;
  bool bVar7;
  uchar uVar8;
  short sVar9;
  int iVar10;
  uint uVar11;
  long lVar12;
  long lVar13;
  uint uVar14;
  float unaff_EBP;
  float unaff_retaddr;
  undefined1 auStack_1c [8];
  RGE_Pick_Info RStack_14;
  
  iVar10 = param_1->mouse_last_x;
  plVar1 = &param_1->mouse_last_x;
  if ((param_2 == iVar10) && (param_3 == param_1->mouse_last_y)) {
    return 0;
  }
  pRVar3 = param_1->player;
  fVar4 = pRVar3->view_x;
  fVar5 = pRVar3->view_y;
  uVar8 = param_1->scroll_action;
  switch(uVar8) {
  case '\x02':
    *plVar1 = param_2;
    param_1->mouse_last_y = param_3;
    TPanel::bound_point((TPanel *)param_1,plVar1,&param_1->mouse_last_y);
    (**(code **)(param_1->_padding_ + 0x20))(1);
    return 0;
  case '\x06':
    iVar10 = (**(code **)(param_1->_padding_ + 0xbc))(param_2,param_3);
    if ((iVar10 != 0) &&
       (uVar8 = RGE_View::pick(param_1,'(','\0',param_2,param_3,(RGE_Pick_Info *)auStack_1c,
                               (RGE_Static_Object *)0x0), uVar8 == '3')) {
      RGE_Player::set_view_loc
                (param_1->player,(float)auStack_1c._0_4_ - _DAT_005776c0,
                 (float)auStack_1c._4_4_ - _DAT_005776c0);
    }
    *plVar1 = param_2;
    param_1->mouse_last_y = param_3;
    if ((unaff_retaddr == param_1->player->view_x) && (unaff_EBP == param_1->player->view_y)) {
      return 0;
    }
    (**(code **)&RStack_14.tile[1].last_drawn_shape)(1);
    return 1;
  case '\a':
    iVar10 = param_3 - param_1->mouse_last_y;
    if (((param_3 != param_1->mouse_last_y) && (iVar10 < 100)) && (-100 < iVar10)) {
      sVar9 = __ftol();
      psVar2 = &param_1->player->map_y;
      *psVar2 = *psVar2 + sVar9;
      psVar2 = &param_1->player->map_x;
      *psVar2 = *psVar2 - sVar9;
    }
    iVar10 = param_2 - *plVar1;
    if (((param_2 != *plVar1) && (iVar10 < 100)) && (-100 < iVar10)) {
      sVar9 = __ftol();
      psVar2 = &param_1->player->map_y;
      *psVar2 = *psVar2 + sVar9;
      psVar2 = &param_1->player->map_x;
      *psVar2 = *psVar2 + sVar9;
    }
    auStack_1c._4_4_ = param_1->_padding_;
    uVar11 = param_3 - auStack_1c._4_4_ >> 0x1f;
    if (((int)((param_3 - auStack_1c._4_4_ ^ uVar11) - uVar11) < 9) &&
       (uVar11 = param_2 - param_1->_padding_, uVar14 = (int)uVar11 >> 0x1f,
       (int)((uVar11 ^ uVar14) - uVar14) < 9)) {
      *plVar1 = param_2;
      param_1->mouse_last_y = param_3;
      (**(code **)(param_1->_padding_ + 0x20))(1);
      return 1;
    }
    auStack_1c._0_4_ = param_1->_padding_;
    ClientToScreen(*(undefined4 *)(param_1->_padding_ + 4),auStack_1c);
    SetCursorPos(auStack_1c._0_4_,auStack_1c._4_4_);
    param_1->mouse_last_y = param_1->_padding_;
    *plVar1 = param_1->_padding_;
    (**(code **)(param_1->_padding_ + 0x20))(1);
    return 1;
  case '\b':
    iVar10 = param_3 - param_1->mouse_last_y;
    if (((param_3 != param_1->mouse_last_y) && (iVar10 < 100)) && (-100 < iVar10)) {
      iVar10 = __ftol();
      pRVar3 = param_1->player;
      RGE_Player::set_view_loc(pRVar3,pRVar3->view_x - (float)iVar10,pRVar3->view_y + (float)iVar10)
      ;
    }
    iVar10 = param_2 - *plVar1;
    if (((param_2 != *plVar1) && (iVar10 < 100)) && (-100 < iVar10)) {
      iVar10 = __ftol();
      pRVar3 = param_1->player;
      RGE_Player::set_view_loc(pRVar3,pRVar3->view_x + (float)iVar10,pRVar3->view_y + (float)iVar10)
      ;
    }
    uVar11 = param_3 - param_1->_padding_;
    uVar14 = (int)uVar11 >> 0x1f;
    if (((int)((uVar11 ^ uVar14) - uVar14) < 9) &&
       (uVar11 = param_2 - param_1->_padding_, uVar14 = (int)uVar11 >> 0x1f,
       (int)((uVar11 ^ uVar14) - uVar14) < 9)) {
      *plVar1 = param_2;
      param_1->mouse_last_y = param_3;
    }
    else {
      auStack_1c._0_4_ = param_1->_padding_;
      auStack_1c._4_4_ = param_1->_padding_;
      ClientToScreen(*(undefined4 *)(param_1->_padding_ + 4),auStack_1c);
      SetCursorPos(auStack_1c._0_4_,auStack_1c._4_4_);
      *plVar1 = param_1->_padding_;
      param_1->mouse_last_y = param_1->_padding_;
    }
    if ((fVar4 == param_1->player->view_x) && (fVar5 == param_1->player->view_y)) {
      return 0;
    }
    (**(code **)(param_1->_padding_ + 0x20))(1);
    return 1;
  }
  if (((uVar8 == '\x03') || (uVar8 == '\x04')) || (uVar8 == '\t')) {
    if (((((param_2 < param_1->_padding_ + 0x40) && (param_2 < iVar10)) ||
         ((param_1->_padding_ + -0x40 < param_2 && (iVar10 < param_2)))) ||
        ((param_3 < param_1->_padding_ + 0x20 && (param_3 < param_1->mouse_last_y)))) ||
       ((param_1->_padding_ + -0x20 < param_3 && (param_1->mouse_last_y < param_3)))) {
      bVar7 = true;
    }
    else {
      bVar7 = false;
    }
  }
  else {
    bVar7 = true;
  }
  iVar10 = param_3 - param_1->mouse_last_y;
  if ((((iVar10 != 0) && (iVar10 < 200)) && (-200 < iVar10)) && (bVar7)) {
    RGE_Player::set_view_loc
              (pRVar3,pRVar3->view_x - (float)iVar10 * _DAT_005776c4,
               pRVar3->view_y + (float)iVar10 * _DAT_005776c4);
  }
  iVar10 = param_2 - param_1->mouse_last_x;
  if (((iVar10 != 0) && (iVar10 < 200)) && ((-200 < iVar10 && (bVar7)))) {
    pRVar3 = param_1->player;
    RGE_Player::set_view_loc
              (pRVar3,pRVar3->view_x + (float)iVar10 * _DAT_005776c4,
               pRVar3->view_y + (float)iVar10 * _DAT_005776c4);
  }
  lVar12 = param_1->mouse_last_x;
  lVar13 = param_1->mouse_last_y;
  param_1->mouse_last_x = param_2;
  param_1->mouse_last_y = param_3;
  if (bVar7) {
    uVar11 = param_3 - param_1->_padding_;
    uVar14 = (int)uVar11 >> 0x1f;
    if ((8 < (int)((uVar11 ^ uVar14) - uVar14)) ||
       (uVar11 = param_2 - param_1->_padding_, uVar14 = (int)uVar11 >> 0x1f,
       8 < (int)((uVar11 ^ uVar14) - uVar14))) {
      auStack_1c._0_4_ = param_1->_padding_;
      auStack_1c._4_4_ = param_1->_padding_;
      ClientToScreen(*(undefined4 *)(param_1->_padding_ + 4),auStack_1c);
      SetCursorPos(auStack_1c._0_4_,auStack_1c._4_4_);
      param_1->mouse_last_x = param_1->_padding_;
      param_1->mouse_last_y = param_1->_padding_;
    }
  }
  else {
    param_1->_padding_ = param_2;
    param_1->_padding_ = param_3;
  }
  uVar8 = param_1->scroll_action;
  if (uVar8 == '\x03') {
    uVar8 = RGE_View::pick(param_1,'(','\0',param_2,param_3,&RStack_14,(RGE_Static_Object *)0x0);
    if ((uVar8 == '3') && (param_1->player != (RGE_Player *)0x0)) {
      lVar12 = __ftol();
      lVar13 = __ftol();
      RGE_View::set_selection_area(param_1,param_1->sel_col1,param_1->sel_row1,lVar13,lVar12);
    }
  }
  else if (uVar8 == '\x04') {
    if ((param_1->player->selected_obj != (RGE_Static_Object *)0x0) &&
       (uVar8 = RGE_View::pick(param_1,'(','\0',param_2,param_3,&RStack_14,(RGE_Static_Object *)0x0)
       , uVar8 == '3')) {
      (**(code **)(param_1->player->selected_obj->_padding_ + 0x34))(RStack_14.x,RStack_14.y,0);
      pRVar6 = param_1->player->selected_obj;
      this = pRVar6->sprite_list;
      if (this == (RGE_Active_Sprite_List *)0x0) {
        this_00 = pRVar6->sprite;
        if (this_00 == (RGE_Sprite *)0x0) {
          uVar8 = '\x14';
        }
        else {
          uVar8 = RGE_Sprite::get_lowest_draw_level(this_00);
        }
      }
      else {
        uVar8 = RGE_Active_Sprite_List::get_lowest_draw_level(this);
      }
      if (uVar8 == '\0') {
        (**(code **)(param_1->_padding_ + 0x20))(2);
      }
      else {
        (**(code **)(param_1->_padding_ + 0x20))(1);
      }
    }
  }
  else if (uVar8 == '\t') {
    iVar10 = param_1->_padding_;
    (**(code **)(iVar10 + 0xf4))(lVar12,lVar13,param_2,param_3,2);
    (**(code **)(iVar10 + 0x20))(1);
  }
  if ((fVar4 == param_1->player->view_x) && (fVar5 == param_1->player->view_y)) {
    return 0;
  }
  (**(code **)(param_1->_padding_ + 0x20))(1);
  return 1;
}

// --------------------------------------------------

// Function: FUN_0053a999
// Address: 0053a999
void __fastcall FUN_0053a999(RGE_View *param_1,undefined4 param_2)
{
  uchar uVar1;
  int iVar2;
  undefined4 in_EAX;
  int iVar3;
  int iVar4;
  char cVar5;
  int iVar6;
  int unaff_EDI;
  int iVar7;
  int iStack_1c;
  int iStack_18;
  
  iRama5020053 = CONCAT31((int3)((uint)in_EAX >> 8),(char)in_EAX + -0x5d);
  cVar5 = (char)((uint)param_2 >> 8);
  *(char *)(unaff_EDI + -0x5a) = *(char *)(unaff_EDI + -0x5a) + cVar5;
  *(char *)(unaff_EDI + -0x5a) = *(char *)(unaff_EDI + -0x5a) + cVar5;
  *(char *)(unaff_EDI + -0x5a) = *(char *)(unaff_EDI + -0x5a) + cVar5;
  cRamd90053a3 = cRamd90053a3 + (char)((uint)param_1 >> 8);
  *(char *)(iRama5020053 + -0x6f6f6f70) = *(char *)(iRama5020053 + -0x6f6f6f70) + (char)param_2;
  switch(param_1->scroll_action) {
  case '\x01':
  case '\x06':
  case '\a':
  case '\b':
    iStack_1c = param_1->_padding_;
    iStack_18 = param_1->_padding_;
    ClientToScreen(*(undefined4 *)(param_1->_padding_ + 4),&iStack_1c);
    SetCursorPos(iStack_1c,iStack_18);
    break;
  case '\x02':
    iVar7 = param_1->_padding_;
    iVar2 = param_1->mouse_last_x;
    iVar6 = iVar2;
    if (iVar2 < iVar7) {
      iVar6 = iVar7;
      iVar7 = iVar2;
    }
    iVar2 = param_1->_padding_;
    iVar4 = param_1->mouse_last_y;
    iVar3 = iVar2;
    if (iVar4 < iVar2) {
      iVar3 = iVar4;
      iVar4 = iVar2;
    }
    RGE_View::pick_multi(param_1,'\x04',iVar7,iVar3,iVar6,iVar4);
    (**(code **)(param_1->_padding_ + 0x20))(1);
    break;
  case '\t':
    iVar7 = param_1->_padding_;
    (**(code **)(iVar7 + 0xf4))
              (param_1->_padding_,param_1->_padding_,param_1->_padding_,param_1->_padding_,0);
    (**(code **)(iVar7 + 0x20))(1);
  }
  uVar1 = param_1->scroll_action;
  if ((((uVar1 == '\x01') || (uVar1 == '\x02')) || (uVar1 == '\x06')) ||
     ((uVar1 == '\a' || (uVar1 == '\b')))) {
    RGE_Base_Game::mouse_on(rge_base_game);
  }
  TPanel::release_mouse((TPanel *)param_1);
  param_1->scroll_action = '\0';
  return;
}

// --------------------------------------------------

// Function: FUN_0053ac3c
// Address: 0053ac3c
void __fastcall FUN_0053ac3c(int param_1)
{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar2 = *(undefined4 **)(param_1 + 0x350);
  while (puVar2 != (undefined4 *)0x0) {
    puVar1 = (undefined4 *)*puVar2;
    operator_delete(puVar2);
    puVar2 = puVar1;
  }
  *(undefined4 *)(param_1 + 0x350) = 0;
  return;
}

// --------------------------------------------------

// Function: FUN_0053ac6c
// Address: 0053ac6c
void __fastcall FUN_0053ac6c(int param_1)
{
  int *piVar1;
  int *piVar2;
  
  piVar2 = *(int **)(param_1 + 0x350);
  while (piVar2 != (int *)0x0) {
    if (piVar2[8] == 1) {
      if ((int *)piVar2[1] != (int *)0x0) {
        *(int *)piVar2[1] = *piVar2;
      }
      if (*piVar2 != 0) {
        *(int *)(*piVar2 + 4) = piVar2[1];
      }
      if (piVar2[1] == 0) {
        *(int *)(param_1 + 0x350) = *piVar2;
      }
      piVar1 = (int *)*piVar2;
      operator_delete(piVar2);
      piVar2 = piVar1;
    }
    else {
      piVar2 = (int *)*piVar2;
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0053acc8
// Address: 0053acc8
void __thiscall
FUN_0053acc8(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,int param_7,
            int param_8,int param_9,int param_10)
{
  int iVar1;
  int *piVar2;
  
  piVar2 = (int *)operator_new(0x30);
  if (piVar2 != (int *)0x0) {
    iVar1 = *(int *)(param_1 + 0x350);
    piVar2[1] = 0;
    *piVar2 = iVar1;
    if (iVar1 != 0) {
      *(int **)(iVar1 + 4) = piVar2;
    }
    *(int **)(param_1 + 0x350) = piVar2;
    piVar2[2] = param_2;
    piVar2[3] = param_3;
    piVar2[4] = param_4;
    piVar2[5] = param_5;
    piVar2[6] = param_6;
    piVar2[7] = param_7;
    piVar2[0xb] = param_8;
    piVar2[8] = param_9;
    piVar2[10] = param_10;
    piVar2[9] = 0;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0053ad41
// Address: 0053ad41
undefined4 __thiscall FUN_0053ad41(int param_1,int param_2,char param_3)
{
  DClipInfo_Node *pDVar1;
  
  pDVar1 = DClipInfo_List::LocateIDbyDrawLevel
                     (*(DClipInfo_List **)(param_1 + 0x334),param_2,6,0x28,0);
  if (pDVar1 == (DClipInfo_Node *)0x0) {
    return 0;
  }
  if ((param_3 == '\0') && ((pDVar1->Draw_Flag & 1) != 0)) {
    return 0;
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_0053ad87
// Address: 0053ad87
DClipInfo_List * __thiscall
FUN_0053ad87(DClipInfo_List *param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
            int param_7)
{
  DClipInfo_Node **ppDVar1;
  
  param_1->Free_Pool_Zone = -1;
  param_1->Free_Pool_Index = -1;
  param_1->Element_Size = param_4;
  param_1->Default_Grow_Size = param_3;
  param_1->YLine_Size = (param_6 - param_5) + 1;
  param_1->Zone_Ptrs = (DClipInfo_Node **)0x0;
  param_1->Zone_Size_Ptrs = (int *)0x0;
  param_1->Max_Zones = 8;
  param_1->Used_Zones = 0;
  param_1->Free_Head = (DClipInfo_Node *)0x0;
  param_1->Total_Blocks = 0;
  param_1->Free_Blocks = 0;
  param_1->YLine_Offset = -param_5;
  param_1->Max_Draw_Levels = param_7;
  DClipInfo_List::SetCaptureLevel(param_1,0,param_7);
  ppDVar1 = (DClipInfo_Node **)calloc(param_1->YLine_Size,4);
  param_1->Draw_Clip_Nodes = ppDVar1;
  ppDVar1 = (DClipInfo_Node **)calloc(param_1->Max_Draw_Levels + 1,4);
  param_1->Draw_Level_Head = ppDVar1;
  ppDVar1 = (DClipInfo_Node **)calloc(param_1->Max_Draw_Levels + 1,4);
  param_1->Draw_Level_Tail = ppDVar1;
  DClipInfo_List::ResetStats(param_1);
  DClipInfo_List::SetNumZones(param_1,8);
  DClipInfo_List::InitNewZone(param_1,param_2);
  param_1->Select_Box = (short *)0x0;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0053ae45
// Address: 0053ae45
void __fastcall FUN_0053ae45(int *param_1)
{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if (0 < param_1[2]) {
    do {
      iVar1 = *(int *)(*param_1 + iVar2 * 4);
      if (iVar1 != 0) {
        free(iVar1);
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < param_1[2]);
  }
  if (*param_1 != 0) {
    free(*param_1);
  }
  if (param_1[1] != 0) {
    free(param_1[1]);
  }
  if (param_1[0x16] != 0) {
    free(param_1[0x16]);
  }
  if (param_1[0x17] != 0) {
    free(param_1[0x17]);
  }
  if (param_1[0x18] != 0) {
    free(param_1[0x18]);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0053aec9
// Address: 0053aec9
void __thiscall FUN_0053aec9(int param_1,int param_2,int param_3)
{
  int iVar1;
  
  iVar1 = param_3;
  if (param_3 < param_2) {
    iVar1 = param_2;
    param_2 = param_3;
  }
  if (param_2 < 0) {
    param_2 = 0;
  }
  if (*(int *)(param_1 + 0x4c) < iVar1) {
    iVar1 = *(int *)(param_1 + 0x4c);
  }
  *(int *)(param_1 + 0x50) = param_2;
  *(int *)(param_1 + 0x54) = iVar1;
  return;
}

// --------------------------------------------------

// Function: FUN_0053aefc
// Address: 0053aefc
void __thiscall FUN_0053aefc(int *param_1,int param_2)
{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  if (param_1[3] <= param_2) {
    iVar3 = calloc(param_2,4);
    iVar4 = calloc(param_2,4);
    if (*param_1 != 0) {
      iVar5 = 0;
      if (0 < param_1[2]) {
        do {
          puVar1 = (undefined4 *)(iVar4 + iVar5 * 4);
          iVar2 = iVar5 * 4;
          iVar5 = iVar5 + 1;
          *(undefined4 *)((iVar3 - iVar4) + (int)puVar1) = *(undefined4 *)(*param_1 + iVar2);
          *puVar1 = *(undefined4 *)(param_1[1] + -4 + iVar5 * 4);
        } while (iVar5 < param_1[2]);
      }
      free(*param_1);
      free(param_1[1]);
    }
    *param_1 = iVar3;
    param_1[1] = iVar4;
    param_1[3] = param_2;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0053af87
// Address: 0053af87
void __thiscall FUN_0053af87(DClipInfo_List *param_1,int param_2)
{
  int iVar1;
  int iVar2;
  DClipInfo_Node *pDVar3;
  
  if (param_1->Used_Zones == param_1->Max_Zones) {
    DClipInfo_List::SetNumZones(param_1,param_1->Used_Zones + 4);
  }
  iVar1 = param_1->Used_Zones;
  param_1->Used_Zones = iVar1 + 1;
  iVar2 = param_1->Element_Size;
  param_1->Zone_Size_Ptrs[iVar1] = param_2;
  pDVar3 = (DClipInfo_Node *)malloc(iVar2 * param_2);
  param_1->Zone_Ptrs[iVar1] = pDVar3;
  param_1->NewZone_Count = param_1->NewZone_Count + 1;
  param_1->Total_Blocks = param_1->Total_Blocks + param_2;
  param_1->Free_Blocks = param_1->Free_Blocks + param_2;
  if (param_1->Free_Pool_Zone == -1) {
    param_1->Free_Pool_Zone = iVar1;
    param_1->Free_Pool_Index = 0;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0053b06d
// Address: 0053b06d
void __thiscall FUN_0053b06d(int param_1,int param_2,int param_3,int param_4,int param_5)
{
  if (param_2 <= param_4) {
    if (param_3 <= param_5) {
      *(int *)(param_1 + 0x3c) = param_2;
      *(int *)(param_1 + 0x40) = param_4;
      *(int *)(param_1 + 0x44) = param_3;
      *(int *)(param_1 + 0x48) = param_5;
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0053b09b
// Address: 0053b09b
void __thiscall
FUN_0053b09b(DClipInfo_List *param_1,uchar *param_2,Shape_Info *param_3,int param_4,int param_5,
            int param_6,int param_7,uchar *param_8,int param_9,int param_10,int param_11)
{
  DClipInfo_Node *pDVar1;
  short sVar2;
  short sVar3;
  DClipInfo_Node *pDVar4;
  DClipInfo_Node *pDVar5;
  short sVar6;
  short sVar7;
  
  param_4 = param_1->YLine_Offset + param_4;
  if ((param_10 <= param_1->Accept_Max_Level) && (param_1->Accept_Min_Level <= param_10)) {
    sVar2 = (short)param_5;
    sVar7 = (short)param_3->Hotspot_X + sVar2;
    sVar3 = (short)param_6;
    sVar6 = (short)param_3->Hotspot_Y + sVar3;
    if (((param_5 <= param_1->SD_XMax) &&
        (((param_1->SD_XMin <= param_5 + -1 + param_3->Width && (param_6 <= param_1->SD_YMax)) &&
         (param_1->SD_YMin <= param_6 + -1 + param_3->Height)))) &&
       ((-1 < param_4 && (param_4 < param_1->YLine_Size)))) {
      pDVar5 = DClipInfo_List::GetNode(param_1);
      pDVar1 = param_1->Draw_Clip_Nodes[param_4];
      if (pDVar1 == (DClipInfo_Node *)0x0) {
        param_1->Draw_Clip_Nodes[param_4] = pDVar5;
      }
      else {
        for (pDVar4 = pDVar1->Next; pDVar4 != (DClipInfo_Node *)0x0; pDVar4 = pDVar4->Next) {
          pDVar1 = pDVar4;
        }
        pDVar1->Next = pDVar5;
      }
      pDVar5->Object_ID = param_11;
      pDVar5->Draw_Flag = param_7;
      pDVar5->Shape_Base = param_2;
      pDVar5->Color_Table = param_8;
      pDVar5->Xform_Mask = param_9;
      pDVar5->Next = (DClipInfo_Node *)0x0;
      pDVar5->NextOnLevel = (DClipInfo_Node *)0x0;
      pDVar5->Shape = param_3;
      pDVar5->Draw_X = param_5;
      pDVar5->Draw_Y = param_6;
      pDVar5->Draw_Level = param_10;
      pDVar5->Node_Type = 0;
      if (param_1->Select_Box == (short *)0x0) {
        pDVar5->x1 = sVar2;
        pDVar5->y1 = sVar3;
        pDVar5->x2 = sVar2 + (short)param_3->Width + -1;
        pDVar5->y2 = sVar3 + (short)param_3->Height + -1;
      }
      else {
        pDVar5->x1 = sVar7 + *param_1->Select_Box;
        pDVar5->y1 = param_1->Select_Box[1] + sVar6;
        pDVar5->x2 = param_1->Select_Box[2] + sVar7;
        pDVar5->y2 = param_1->Select_Box[3] + sVar6;
        param_1->Select_Box = (short *)0x0;
      }
      pDVar5->x3 = sVar7;
      pDVar5->y3 = sVar6;
      pDVar5->x4 = 0;
      pDVar5->y4 = 0;
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0053b21b
// Address: 0053b21b
DClipInfo_Node * __thiscall
FUN_0053b21b(DClipInfo_List *param_1,int param_2,int param_3,short param_4,short param_5,
            short param_6,short param_7,short param_8,short param_9,short param_10,short param_11,
            int param_12,int param_13,int param_14)
{
  DClipInfo_Node *pDVar1;
  
  param_3 = param_1->YLine_Offset + param_3;
  if ((((param_12 <= param_1->Accept_Max_Level) && (param_1->Accept_Min_Level <= param_12)) &&
      (-1 < param_3)) && (param_3 < param_1->YLine_Size)) {
    pDVar1 = DClipInfo_List::GetNode(param_1);
    pDVar1->Next = param_1->Draw_Clip_Nodes[param_3];
    param_1->Draw_Clip_Nodes[param_3] = pDVar1;
    pDVar1->Object_ID = param_14;
    pDVar1->Draw_Flag = param_13;
    pDVar1->Node_Type = param_2;
    pDVar1->x1 = param_4;
    pDVar1->y1 = param_5;
    pDVar1->x2 = param_6;
    pDVar1->y2 = param_7;
    pDVar1->x3 = param_8;
    pDVar1->y3 = param_9;
    pDVar1->NextOnLevel = (DClipInfo_Node *)0x0;
    pDVar1->Shape = (Shape_Info *)0x0;
    pDVar1->Draw_X = 0;
    pDVar1->Draw_Y = 0;
    pDVar1->Shape_Base = (uchar *)0x0;
    pDVar1->Color_Table = (uchar *)0x0;
    pDVar1->Xform_Mask = 0;
    pDVar1->Draw_Level = param_12;
    pDVar1->x4 = param_10;
    pDVar1->y4 = param_11;
    return pDVar1;
  }
  return (DClipInfo_Node *)0x0;
}

// --------------------------------------------------

// Function: FUN_0053b2fb
// Address: 0053b2fb
int __thiscall FUN_0053b2fb(int param_1,int param_2,int param_3,int param_4,int param_5)
{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  iVar2 = param_3;
  if (param_4 < param_3) {
    iVar2 = param_4;
    param_4 = param_3;
  }
  if (iVar2 < 0) {
    iVar2 = 0;
  }
  iVar1 = *(int *)(param_1 + 0x4c);
  if (iVar1 < param_4) {
    param_4 = iVar1;
  }
  if (((iVar2 <= iVar1) && (-1 < param_4)) && (iVar2 <= param_4)) {
    piVar3 = (int *)(*(int *)(param_1 + 0x5c) + iVar2 * 4);
    do {
      for (iVar1 = *piVar3; iVar1 != 0; iVar1 = *(int *)(iVar1 + 4)) {
        if ((*(int *)(iVar1 + 8) == param_2) && (*(int *)(iVar1 + 0x2c) == param_5)) {
          return iVar1;
        }
      }
      iVar2 = iVar2 + 1;
      piVar3 = piVar3 + 1;
    } while (iVar2 <= param_4);
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0053b367
// Address: 0053b367
void __thiscall FUN_0053b367(int param_1,int param_2,int param_3)
{
  undefined4 *puVar1;
  int iVar2;
  short sVar3;
  int iVar4;
  short sVar5;
  int iVar6;
  
  if (0 < param_3) {
    iVar2 = 0;
    if (*(int *)(param_1 + 0x68) != param_3 && -1 < *(int *)(param_1 + 0x68) - param_3) {
      iVar6 = param_3 * 4;
      do {
        iVar2 = iVar2 + 1;
        puVar1 = (undefined4 *)(iVar6 + *(int *)(param_1 + 0x58));
        iVar6 = iVar6 + 4;
        *(undefined4 *)(*(int *)(param_1 + 0x58) + -4 + iVar2 * 4) = *puVar1;
      } while (iVar2 < *(int *)(param_1 + 0x68) - param_3);
    }
    iVar2 = *(int *)(param_1 + 0x68) - param_3;
    if (iVar2 < *(int *)(param_1 + 0x68)) {
      do {
        iVar2 = iVar2 + 1;
        *(undefined4 *)(*(int *)(param_1 + 0x58) + -4 + iVar2 * 4) = 0;
      } while (iVar2 < *(int *)(param_1 + 0x68));
    }
  }
  if (param_3 < 0) {
    iVar6 = -param_3;
    iVar2 = *(int *)(param_1 + 0x68) + -1;
    if (SBORROW4(iVar2,iVar6) == iVar2 + param_3 < 0) {
      iVar4 = (param_3 + -1 + *(int *)(param_1 + 0x68)) * 4;
      do {
        iVar2 = iVar2 + -1;
        puVar1 = (undefined4 *)(iVar4 + *(int *)(param_1 + 0x58));
        iVar4 = iVar4 + -4;
        *(undefined4 *)(*(int *)(param_1 + 0x58) + 4 + iVar2 * 4) = *puVar1;
      } while (iVar6 <= iVar2);
    }
    iVar2 = 0;
    if (iVar6 != 0 && param_3 < 1) {
      do {
        iVar2 = iVar2 + 1;
        *(undefined4 *)(*(int *)(param_1 + 0x58) + -4 + iVar2 * 4) = 0;
      } while (iVar2 < iVar6);
    }
  }
  iVar2 = 0;
  if (0 < *(int *)(param_1 + 0x68)) {
    do {
      for (puVar1 = *(undefined4 **)(*(int *)(param_1 + 0x58) + iVar2 * 4);
          puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)*puVar1) {
        sVar3 = (short)param_3;
        sVar5 = (short)param_2;
        switch(puVar1[0xb]) {
        case 0:
          puVar1[5] = puVar1[5] - param_2;
          puVar1[6] = puVar1[6] - param_3;
          break;
        case 1:
          *(short *)((int)puVar1 + 0x3a) = *(short *)((int)puVar1 + 0x3a) - sVar3;
          *(short *)((int)puVar1 + 0x3e) = *(short *)((int)puVar1 + 0x3e) - sVar3;
        case 2:
          *(short *)(puVar1 + 0xe) = *(short *)(puVar1 + 0xe) - sVar5;
          *(short *)(puVar1 + 0xf) = *(short *)(puVar1 + 0xf) - sVar5;
        case 3:
        case 4:
          *(short *)(puVar1 + 0xc) = *(short *)(puVar1 + 0xc) - sVar5;
          *(short *)((int)puVar1 + 0x32) = *(short *)((int)puVar1 + 0x32) - sVar3;
          *(short *)(puVar1 + 0xd) = *(short *)(puVar1 + 0xd) - sVar5;
          *(short *)((int)puVar1 + 0x36) = *(short *)((int)puVar1 + 0x36) - sVar3;
        }
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < *(int *)(param_1 + 0x68));
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0053b475
// Address: 0053b475
void __fastcall FUN_0053b475(int param_1,char param_2)
{
  char cVar1;
  undefined4 in_EAX;
  undefined4 *puVar3;
  int iVar2;
  
  cVar1 = (char)in_EAX;
  iVar2 = CONCAT22((short)((uint)in_EAX >> 0x10),CONCAT11(0x53,cVar1));
  *(char *)(iVar2 + -0x4c) = *(char *)(iVar2 + -0x4c) + cVar1;
  *(char *)(iVar2 + -0x4c) = *(char *)(iVar2 + -0x4c) + (char)param_1;
  *(char *)(iVar2 + -0x4c) = *(char *)(iVar2 + -0x4c) + param_2;
  *(char *)(iVar2 + -0x4c) = *(char *)(iVar2 + -0x4c) + param_2;
  *(char *)(iVar2 + -0x746f6f70) = *(char *)(iVar2 + -0x746f6f70) + param_2;
  puVar3 = (undefined4 *)(CONCAT31((int3)((uint)iVar2 >> 8),cVar1) & 0xffffff04);
  *puVar3 = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 **)(param_1 + 0x10) = puVar3;
  *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + 1;
  return;
}

// --------------------------------------------------

// Function: FUN_0053b4a2
// Address: 0053b4a2
int __thiscall FUN_0053b4a2(int param_1,int *param_2,int *param_3)
{
  int iVar1;
  int *piVar2;
  int *piVar3;
  
  iVar1 = 0;
  if (param_2 == (int *)0x0) {
    return iVar1;
  }
  piVar3 = param_2;
  if (param_3 == (int *)0x0) {
    do {
      piVar2 = piVar3;
      iVar1 = iVar1 + 1;
      *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + 1;
      piVar3 = (int *)*piVar2;
    } while (piVar3 != (int *)0x0);
    *piVar2 = *(int *)(param_1 + 0x10);
    *(int **)(param_1 + 0x10) = param_2;
    return iVar1;
  }
  do {
    iVar1 = iVar1 + 1;
    *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + 1;
    if (piVar3 == param_3) {
      piVar3 = (int *)0x0;
    }
    else {
      piVar3 = (int *)*piVar3;
    }
  } while (piVar3 != (int *)0x0);
  *param_3 = *(int *)(param_1 + 0x10);
  *(int **)(param_1 + 0x10) = param_2;
  return iVar1;
}

// --------------------------------------------------

// Function: FUN_0053b50d
// Address: 0053b50d
void __fastcall FUN_0053b50d(int param_1)
{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  
  puVar3 = *(undefined4 **)(param_1 + 0x58);
  for (uVar1 = *(uint *)(param_1 + 0x68) & 0x3fffffff; uVar1 != 0; uVar1 = uVar1 - 1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  for (iVar2 = 0; iVar2 != 0; iVar2 = iVar2 + -1) {
    *(undefined1 *)puVar3 = 0;
    puVar3 = (undefined4 *)((int)puVar3 + 1);
  }
  puVar3 = *(undefined4 **)(param_1 + 0x5c);
  for (uVar1 = *(int *)(param_1 + 0x4c) * 4 + 4U >> 2; uVar1 != 0; uVar1 = uVar1 - 1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  for (iVar2 = 0; iVar2 != 0; iVar2 = iVar2 + -1) {
    *(undefined1 *)puVar3 = 0;
    puVar3 = (undefined4 *)((int)puVar3 + 1);
  }
  puVar3 = *(undefined4 **)(param_1 + 0x60);
  for (uVar1 = *(int *)(param_1 + 0x4c) * 4 + 4U >> 2; uVar1 != 0; uVar1 = uVar1 - 1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  for (iVar2 = 0; iVar2 != 0; iVar2 = iVar2 + -1) {
    *(undefined1 *)puVar3 = 0;
    puVar3 = (undefined4 *)((int)puVar3 + 1);
  }
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(param_1 + 0x1c);
  *(int *)(param_1 + 0x38) = *(int *)(param_1 + 0x38) + 1;
  return;
}

// --------------------------------------------------

// Function: FUN_0053b582
// Address: 0053b582
void __fastcall FUN_0053b582(int param_1)
{
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined4 *)(param_1 + 0x30) = 0;
  *(undefined4 *)(param_1 + 0x34) = 0;
  *(undefined4 *)(param_1 + 0x38) = 0;
  return;
}

// --------------------------------------------------

// Function: FUN_0053b59f
// Address: 0053b59f
Visible_Unit_Manager * __thiscall
FUN_0053b59f(Visible_Unit_Manager *param_1,int param_2,int param_3)
{
  VISIBLE_UNIT_PTR **ppVVar1;
  VISIBLE_UNIT_PTR *pVVar2;
  VISIBLE_UNIT_REC *pVVar3;
  int iVar4;
  VISIBLE_UNIT_REC **ppVVar5;
  int iVar6;
  short *psVar7;
  
  iVar6 = 0;
  param_1->Player_Count = param_2;
  param_1->Category_Count = param_3 + 1;
  param_1->distanceTable = (uchar *)0x0;
  ppVVar1 = (VISIBLE_UNIT_PTR **)calloc(param_2,4);
  param_1->PlayerDataPtrs = ppVVar1;
  if (0 < param_1->Player_Count) {
    do {
      pVVar2 = (VISIBLE_UNIT_PTR *)calloc(param_1->Category_Count,8);
      iVar4 = 0;
      param_1->PlayerDataPtrs[iVar6] = pVVar2;
      if (0 < param_1->Category_Count) {
        psVar7 = &param_1->PlayerDataPtrs[iVar6]->used;
        do {
          psVar7[-1] = 0x20;
          *psVar7 = 0;
          pVVar3 = (VISIBLE_UNIT_REC *)calloc(0x20,8);
          ((VISIBLE_UNIT_PTR *)(psVar7 + -3))->unit_list = pVVar3;
          iVar4 = iVar4 + 1;
          psVar7 = psVar7 + 4;
        } while (iVar4 < param_1->Category_Count);
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < param_1->Player_Count);
  }
  ppVVar5 = param_1->Return_Buffer;
  iVar6 = 0;
  do {
    pVVar3 = (VISIBLE_UNIT_REC *)malloc(0x800);
    *ppVVar5 = pVVar3;
    *(VISIBLE_UNIT_REC **)((int)&VisibleUnitList + iVar6) = pVVar3;
    *(undefined4 *)((int)&VisibleUnitList_Size + iVar6) = 0;
    iVar6 = iVar6 + 4;
    ppVVar5 = ppVVar5 + 1;
  } while (iVar6 < 0x14);
  Visible_Unit_Manager::Build_Distance_Table(param_1);
  VisibleUnitManager = param_1;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0053b664
// Address: 0053b664
void __fastcall FUN_0053b664(int *param_1)
{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iStack_4;
  
  if (*param_1 != 0) {
    iStack_4 = 0;
    if (0 < param_1[6]) {
      do {
        piVar3 = *(int **)(*param_1 + iStack_4 * 4);
        if (piVar3 != (int *)0x0) {
          iVar2 = 0;
          piVar1 = piVar3;
          if (0 < param_1[7]) {
            do {
              if (*piVar1 != 0) {
                free(*piVar1);
              }
              iVar2 = iVar2 + 1;
              piVar1 = piVar1 + 2;
            } while (iVar2 < param_1[7]);
          }
          free(piVar3);
        }
        iStack_4 = iStack_4 + 1;
      } while (iStack_4 < param_1[6]);
    }
    free(*param_1);
  }
  piVar3 = param_1 + 1;
  iVar2 = 0;
  do {
    if (*piVar3 != 0) {
      free(*piVar3);
    }
    *(undefined4 *)((int)&VisibleUnitList + iVar2) = 0;
    *(undefined4 *)((int)&VisibleUnitList_Size + iVar2) = 0;
    iVar2 = iVar2 + 4;
    piVar3 = piVar3 + 1;
  } while (iVar2 < 0x14);
  if (param_1[8] != 0) {
    free(param_1[8]);
  }
  VisibleUnitManager = (Visible_Unit_Manager *)0x0;
  return;
}

// --------------------------------------------------

// Function: FUN_0053b727
// Address: 0053b727
void __fastcall FUN_0053b727(int param_1)
{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  int iVar6;
  char cVar7;
  int *piVar8;
  undefined **ppuStack_4;
  
  if (*(int *)(param_1 + 0x20) != 0) {
    free(*(int *)(param_1 + 0x20));
  }
  puVar2 = (undefined4 *)malloc(0x100);
  *(undefined4 **)(param_1 + 0x20) = puVar2;
  for (iVar3 = 0x40; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar2 = 0xffffffff;
    puVar2 = puVar2 + 1;
  }
  cVar7 = '\0';
  ppuStack_4 = &NormalLOS;
  do {
    piVar8 = (int *)*ppuStack_4;
    iVar3 = *piVar8;
    while (iVar3 != 999) {
      iVar6 = piVar8[1];
      iVar4 = piVar8[2];
      if ((-1 < iVar3) && (iVar3 < 0x10)) {
        if (iVar6 < 0) {
          iVar6 = 0;
        }
        if (0xf < iVar4) {
          iVar4 = 0xf;
        }
        iVar3 = iVar3 * 0x10 + iVar6;
        if (iVar6 <= iVar4) {
          iVar6 = (iVar4 - iVar6) + 1;
          do {
            pcVar5 = (char *)(*(int *)(param_1 + 0x20) + iVar3);
            if (*pcVar5 == -1) {
              *pcVar5 = cVar7;
            }
            iVar3 = iVar3 + 1;
            iVar6 = iVar6 + -1;
          } while (iVar6 != 0);
        }
      }
      piVar1 = piVar8 + 3;
      piVar8 = piVar8 + 3;
      iVar3 = *piVar1;
    }
    ppuStack_4 = ppuStack_4 + 1;
    cVar7 = cVar7 + '\x01';
  } while ((int)ppuStack_4 < 0x58ea51);
  return;
}

// --------------------------------------------------

// Function: FUN_0053b7dd
// Address: 0053b7dd
void __thiscall
FUN_0053b7dd(int *param_1,undefined4 param_2,undefined1 param_3,undefined1 param_4,
            undefined1 param_5,int param_6,uint param_7,uint param_8,int *param_9)
{
  int *piVar1;
  undefined4 *puVar2;
  short sVar3;
  int iVar4;
  int *piVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  int *piVar9;
  int *piVar10;
  int iStack_c;
  
  uVar8 = (param_8 ^ param_7) & 0xffff;
  if ((param_6 < param_1[7]) && (iStack_c = 0, 0 < param_1[6])) {
    iVar4 = 0x194 - (int)param_9;
    do {
      if (uVar8 == 0) {
        return;
      }
      if (((byte)uVar8 & 1) == 1) {
        piVar1 = (int *)(*(int *)(*param_1 + iStack_c * 4) + param_6 * 8);
        if (((byte)param_8 & 1) == 1) {
          sVar3 = (short)piVar1[1];
          if (*(short *)((int)piVar1 + 6) == sVar3) {
            piVar5 = (int *)calloc(sVar3 * 2,8);
            piVar9 = (int *)*piVar1;
            piVar10 = piVar5;
            for (uVar6 = (uint)(sVar3 * 8) >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
              *piVar10 = *piVar9;
              piVar9 = piVar9 + 1;
              piVar10 = piVar10 + 1;
            }
            for (iVar7 = 0; iVar7 != 0; iVar7 = iVar7 + -1) {
              *(char *)piVar10 = (char)*piVar9;
              piVar9 = (int *)((int)piVar9 + 1);
              piVar10 = (int *)((int)piVar10 + 1);
            }
            free(*piVar1);
            iVar7 = 0;
            *piVar1 = (int)piVar5;
            *(short *)(piVar1 + 1) = sVar3 * 2;
            if (0 < *(short *)((int)piVar1 + 6)) {
              do {
                if (VIS_UNIT_objectsValue[*piVar5] != (RGE_Static_Object *)0x0) {
                  *(int **)((int)VIS_UNIT_objectsValue[*piVar5] + iVar4 + (int)param_9) = piVar5;
                }
                iVar7 = iVar7 + 1;
                piVar5 = piVar5 + 2;
              } while (iVar7 < *(short *)((int)piVar1 + 6));
            }
          }
          sVar3 = *(short *)((int)piVar1 + 6);
          iVar7 = *piVar1;
          *(undefined1 *)(iVar7 + 4 + sVar3 * 8) = 0;
          puVar2 = (undefined4 *)(iVar7 + sVar3 * 8);
          *puVar2 = param_2;
          *(undefined1 *)((int)puVar2 + 5) = param_3;
          *(undefined1 *)((int)puVar2 + 6) = param_4;
          *(undefined1 *)((int)puVar2 + 7) = param_5;
          *(short *)((int)piVar1 + 6) = *(short *)((int)piVar1 + 6) + 1;
          *param_9 = (int)puVar2;
        }
        else {
          piVar10 = (int *)*param_9;
          piVar9 = (int *)(*piVar1 + -8 + *(short *)((int)piVar1 + 6) * 8);
          if (piVar9 != piVar10) {
            *piVar10 = *piVar9;
            piVar10[1] = piVar9[1];
            if (VIS_UNIT_objectsValue[*piVar10] != (RGE_Static_Object *)0x0) {
              *(int **)((int)VIS_UNIT_objectsValue[*piVar10] + iVar4 + (int)param_9) = piVar10;
            }
          }
          *param_9 = 0;
          *(short *)((int)piVar1 + 6) = *(short *)((int)piVar1 + 6) + -1;
        }
      }
      param_9 = param_9 + 1;
      param_8 = param_8 >> 1;
      uVar8 = uVar8 >> 1;
      iStack_c = iStack_c + 1;
    } while (iStack_c < param_1[6]);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0053b99d
// Address: 0053b99d
int __thiscall
FUN_0053b99d(int *param_1,int param_2,int param_3,int param_4,int param_5,int *param_6,int param_7,
            int param_8)
{
  undefined4 *puVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  VISIBLE_UNIT_REC **ppVVar7;
  undefined4 uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  undefined4 *puVar12;
  int iStack_8;
  
  iStack_8 = 0;
  if (param_7 < 1) {
    return 0;
  }
  if (param_1[6] <= param_5) {
    return 0;
  }
  if (0xf < param_4) {
    param_4 = 0xf;
  }
  iVar3 = param_1[8];
  iVar4 = *(int *)(*param_1 + param_5 * 4);
  VisibleUnitList_Size = (int *)0x0;
  DAT_0087d7cc = 0;
  DAT_0087d7d0 = 0;
  DAT_0087d7d4 = 0;
  DAT_0087d7d8 = 0;
  do {
    iVar5 = *param_6;
    param_6 = param_6 + 1;
    puVar1 = (undefined4 *)(iVar4 + iVar5 * 8);
    puVar12 = (undefined4 *)*puVar1;
    for (uVar9 = *(uint *)((int)puVar1 + 6) & 0xffff; uVar9 != 0; uVar9 = uVar9 - 1) {
      uVar11 = (uint)*(byte *)((int)puVar12 + 6);
      if ((int)uVar11 <= param_2 + param_4) {
        if ((int)uVar11 < param_2) {
          if ((int)uVar11 < param_2 - param_4) goto LAB_0053baff;
          uVar11 = param_2 - uVar11;
        }
        else {
          uVar11 = uVar11 - param_2;
        }
        uVar10 = (uint)*(byte *)((int)puVar12 + 7);
        if ((int)uVar10 <= param_4 + param_3) {
          if ((int)uVar10 < param_3) {
            if ((int)uVar10 < param_3 - param_4) goto LAB_0053baff;
            uVar10 = param_3 - uVar10;
          }
          else {
            uVar10 = uVar10 - param_3;
          }
          bVar2 = *(byte *)(iVar3 + (uVar11 & 0xf) + (uVar10 & 0xf) * 0x10);
          if ((int)(uint)bVar2 <= param_4) {
            iVar5 = *(int *)(param_8 + (uint)*(byte *)((int)puVar12 + 5) * 4);
            piVar6 = (&VisibleUnitList_Size)[iVar5];
            if ((int)piVar6 < 0x100) {
              ppVVar7 = (&VisibleUnitList)[iVar5];
              (&VisibleUnitList_Size)[iVar5] = (int *)((int)piVar6 + 1);
              uVar8 = puVar12[1];
              iStack_8 = iStack_8 + 1;
              ppVVar7[(int)piVar6 * 2] = (VISIBLE_UNIT_REC *)*puVar12;
              (ppVVar7 + (int)piVar6 * 2)[1] =
                   (VISIBLE_UNIT_REC *)CONCAT31((int3)((uint)uVar8 >> 8),bVar2);
            }
          }
        }
      }
LAB_0053baff:
      puVar12 = puVar12 + 2;
    }
    param_7 = param_7 + -1;
    if (param_7 == 0) {
      return iStack_8;
    }
  } while( true );
}

// --------------------------------------------------

// Function: FUN_0053bb23
// Address: 0053bb23
int * __thiscall FUN_0053bb23(int *param_1,int param_2,int param_3)
{
  int iVar1;
  undefined4 uVar2;
  
  param_1[4] = param_3;
  if (param_3 < 1) {
    *param_1 = 0;
    param_1[1] = 0;
    param_1[2] = 0;
  }
  else {
    iVar1 = calloc(param_3,4);
    *param_1 = iVar1;
    iVar1 = calloc(param_1[4],4);
    param_1[1] = iVar1;
    iVar1 = calloc(param_1[4],4);
    param_1[2] = iVar1;
    iVar1 = 0;
    if (0 < param_1[4]) {
      do {
        uVar2 = malloc(0x100);
        *(undefined4 *)(*param_1 + iVar1 * 4) = uVar2;
        *(undefined4 *)(param_1[1] + iVar1 * 4) = 0x20;
        *(undefined4 *)(param_1[2] + iVar1 * 4) = 0;
        iVar1 = iVar1 + 1;
      } while (iVar1 < param_1[4]);
      param_1[3] = param_2;
      return param_1;
    }
  }
  param_1[3] = param_2;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0053bbd5
// Address: 0053bbd5
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int * __thiscall FUN_0053bbd5(int *param_1,int param_2,int param_3)
{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  piVar1 = param_1 + 4;
  if (save_game_version < _DAT_005776c8) {
    *piVar1 = 5;
  }
  else {
    rge_read(param_2,piVar1,4);
  }
  iVar4 = 0;
  if (*piVar1 < 1) {
    *param_1 = 0;
    param_1[1] = 0;
    param_1[2] = 0;
  }
  else {
    iVar2 = calloc(*piVar1,4);
    *param_1 = iVar2;
    iVar2 = calloc(*piVar1,4);
    param_1[1] = iVar2;
    iVar2 = calloc(*piVar1,4);
    param_1[2] = iVar2;
    if (0 < *piVar1) {
      do {
        iVar2 = iVar4 * 4;
        rge_read(param_2,(void *)(param_1[1] + iVar2),4);
        rge_read(param_2,(void *)(param_1[2] + iVar2),4);
        uVar3 = malloc(*(int *)(param_1[1] + iVar2) << 3);
        iVar4 = iVar4 + 1;
        *(undefined4 *)(*param_1 + iVar2) = uVar3;
      } while (iVar4 < *piVar1);
    }
    iVar4 = 0;
    if (0 < *piVar1) {
      do {
        iVar2 = *(int *)(param_1[2] + iVar4 * 4);
        if (0 < iVar2) {
          rge_read(param_2,*(void **)(*param_1 + iVar4 * 4),iVar2 * 8);
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < *piVar1);
      param_1[3] = param_3;
      return param_1;
    }
  }
  param_1[3] = param_3;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0053bd0a
// Address: 0053bd0a
void __fastcall FUN_0053bd0a(int *param_1)
{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if (0 < param_1[4]) {
    do {
      iVar1 = *(int *)(*param_1 + iVar2 * 4);
      if (iVar1 != 0) {
        free(iVar1);
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < param_1[4]);
  }
  if (*param_1 != 0) {
    free(*param_1);
  }
  if (param_1[1] != 0) {
    free(param_1[1]);
  }
  if (param_1[2] != 0) {
    free(param_1[2]);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0053bd69
// Address: 0053bd69
void __thiscall FUN_0053bd69(int *param_1,int param_2)
{
  int iVar1;
  int iVar2;
  
  rge_write(param_2,param_1 + 4,4);
  iVar2 = 0;
  if (0 < param_1[4]) {
    do {
      rge_write(param_2,(void *)(param_1[1] + iVar2 * 4),4);
      rge_write(param_2,(void *)(param_1[2] + iVar2 * 4),4);
      iVar2 = iVar2 + 1;
    } while (iVar2 < param_1[4]);
  }
  iVar2 = 0;
  if (0 < param_1[4]) {
    do {
      iVar1 = *(int *)(param_1[2] + iVar2 * 4);
      if (0 < iVar1) {
        rge_write(param_2,*(void **)(*param_1 + iVar2 * 4),iVar1 << 3);
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < param_1[4]);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0053bdf7
// Address: 0053bdf7
void __thiscall FUN_0053bdf7(Visible_Resource_Manager *param_1,RGE_Tile_List *param_2)
{
  RGE_Object_Node *pRVar1;
  RGE_Static_Object *pRVar2;
  int iVar3;
  int iVar4;
  int iStack_8;
  RGE_Tile **ppRStack_4;
  
  RGE_Tile_List::get_list_info(param_2,(RGE_Tile_List_Node **)&param_2,&iStack_8);
  if ((0 < iStack_8) && (param_1->num_visible_resource_lists != 0)) {
    iVar3 = 0;
    ppRStack_4 = param_1->owner->world->map->map_row_offset;
    if (0 < iStack_8) {
      do {
        iVar4 = (int)ppRStack_4[param_2->num_active][param_2->list_size].objects.number_of_objects;
        if (0 < iVar4) {
          pRVar1 = ppRStack_4[param_2->num_active][param_2->list_size].objects.list;
          for (; (pRVar1 != (RGE_Object_Node *)0x0 && (0 < iVar4)); iVar4 = iVar4 + -1) {
            pRVar2 = pRVar1->node;
            if ((pRVar2 != (RGE_Static_Object *)0x0) &&
               (pRVar2->master_obj->track_as_resource != '\0')) {
              Visible_Resource_Manager::AddResource
                        (param_1,pRVar2->id,(uint)pRVar2->master_obj->resource_group);
            }
            pRVar1 = pRVar1->next;
          }
        }
        iVar3 = iVar3 + 1;
        param_2 = (RGE_Tile_List *)&param_2->new_count;
      } while (iVar3 < iStack_8);
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0053bec3
// Address: 0053bec3
void __thiscall FUN_0053bec3(int *param_1,int param_2,int param_3)
{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  undefined4 *puVar6;
  uint uVar7;
  int iVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  
  if ((param_1[4] != 0) && (VIS_UNIT_objectsValue[param_2] != (RGE_Static_Object *)0x0)) {
    iVar3 = *(int *)(param_1[1] + param_3 * 4);
    iVar2 = param_3 * 4;
    if (*(int *)(param_1[2] + param_3 * 4) == iVar3) {
      puVar6 = (undefined4 *)malloc(iVar3 * 0x10);
      puVar9 = *(undefined4 **)(*param_1 + iVar2);
      puVar10 = puVar6;
      for (uVar7 = (uint)(*(int *)(param_1[1] + iVar2) << 3) >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
        *puVar10 = *puVar9;
        puVar9 = puVar9 + 1;
        puVar10 = puVar10 + 1;
      }
      for (iVar8 = 0; iVar8 != 0; iVar8 = iVar8 + -1) {
        *(undefined1 *)puVar10 = *(undefined1 *)puVar9;
        puVar9 = (undefined4 *)((int)puVar9 + 1);
        puVar10 = (undefined4 *)((int)puVar10 + 1);
      }
      free(*(undefined4 *)(*param_1 + iVar2));
      *(undefined4 **)(*param_1 + iVar2) = puVar6;
      *(int *)(param_1[1] + iVar2) = iVar3 * 2;
    }
    piVar1 = (int *)(*(int *)(*param_1 + iVar2) + *(int *)(param_1[2] + iVar2) * 8);
    uVar4 = __ftol();
    uVar5 = __ftol();
    *piVar1 = param_2;
    *(undefined1 *)(piVar1 + 1) = 0;
    *(undefined1 *)((int)piVar1 + 5) = 0;
    *(undefined1 *)((int)piVar1 + 6) = uVar4;
    *(undefined1 *)((int)piVar1 + 7) = uVar5;
    *(int *)(iVar2 + param_1[2]) = *(int *)(iVar2 + param_1[2]) + 1;
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0053bfc4
// Address: 0053bfc4
undefined4 __thiscall FUN_0053bfc4(int *param_1,int param_2,int param_3)
{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  if (param_1[4] != 0) {
    iVar3 = *(int *)(param_1[2] + param_3 * 4);
    param_3 = param_3 * 4;
    if (iVar3 != 0) {
      iVar3 = iVar3 + -1;
      piVar1 = *(int **)(*param_1 + param_3);
      iVar2 = 0;
      piVar4 = piVar1;
      if (-1 < iVar3) {
        do {
          if (*piVar4 == param_2) {
            if (iVar2 < iVar3) {
              piVar1[iVar2 * 2] = piVar1[iVar3 * 2];
              piVar1[iVar2 * 2 + 1] = piVar1[iVar3 * 2 + 1];
            }
            *(int *)(param_1[2] + param_3) = *(int *)(param_1[2] + param_3) + -1;
            return 1;
          }
          iVar2 = iVar2 + 1;
          piVar4 = piVar4 + 2;
        } while (iVar2 <= iVar3);
        return 0;
      }
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0053c04a
// Address: 0053c04a
int * __thiscall
FUN_0053c04a(int *param_1,int param_2,int param_3,undefined4 param_4,int param_5,int *param_6,
            int param_7)
{
  bool bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  uint uVar6;
  int iVar7;
  int *piVar8;
  int iStack_8;
  int *piStack_4;
  
  if (((-1 < param_5) && (param_1[4] != 0)) && (param_5 < param_1[4])) {
    iStack_8 = *(int *)(param_1[2] + param_5 * 4);
    if (iStack_8 != 0) {
      piVar8 = *(int **)(*param_1 + param_5 * 4);
      param_5 = 9999;
      piStack_4 = (int *)0x0;
      piVar5 = (int *)0x0;
      if (0 < iStack_8) {
        do {
          uVar2 = (uint)*(byte *)((int)piVar8 + 6);
          uVar6 = (uint)*(byte *)((int)piVar8 + 7);
          bVar1 = false;
          if (param_2 < (int)uVar2) {
            iVar3 = uVar2 - param_2;
          }
          else {
            iVar3 = param_2 - uVar2;
          }
          if (param_3 < (int)uVar6) {
            iVar7 = uVar6 - param_3;
          }
          else {
            iVar7 = param_3 - uVar6;
          }
          if (iVar7 < iVar3) {
            iVar4 = __ftol();
            iVar7 = (iVar3 - iVar4) - iVar7;
          }
          else {
            iVar4 = __ftol();
            iVar7 = (iVar7 - iVar4) - iVar3;
          }
          if (iVar7 < param_5) {
            if (((param_7 != 0) && (param_6 != (int *)0x0)) && (iVar3 = 0, 0 < param_7)) {
              piVar5 = param_6;
              do {
                if (*piVar8 == *piVar5) {
                  bVar1 = true;
                  break;
                }
                iVar3 = iVar3 + 1;
                piVar5 = piVar5 + 1;
              } while (iVar3 < param_7);
            }
            if (!bVar1) {
              param_5 = iVar7;
              piStack_4 = piVar8;
            }
          }
          piVar8 = piVar8 + 2;
          iStack_8 = iStack_8 + -1;
          piVar5 = piStack_4;
        } while (iStack_8 != 0);
      }
      if (0xff < param_5) {
        param_5 = 0xff;
      }
      if (piVar5 != (int *)0x0) {
        *(undefined1 *)(piVar5 + 1) = (undefined1)param_5;
      }
      return piVar5;
    }
  }
  return (int *)0x0;
}

// --------------------------------------------------

// Function: FUN_0053c1af
// Address: 0053c1af
int * __thiscall FUN_0053c1af(int *param_1,int param_2,int param_3)
{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  
  param_1[1] = *(int *)(param_3 + 0x3c);
  param_1[2] = param_3;
  param_1[3] = param_2;
  iVar2 = *(int *)(param_2 + 8);
  param_1[5] = iVar2;
  iVar1 = *(int *)(param_2 + 0xc);
  param_1[6] = iVar1;
  param_1[7] = 0;
  param_1[8] = iVar1 * iVar2;
  if ((iVar2 < 1) || (iVar1 < 1)) {
    param_1[4] = 0;
    *param_1 = 0;
  }
  else {
    iVar2 = calloc(iVar1 * iVar2,1);
    param_1[4] = iVar2;
    iVar2 = calloc(param_1[6],4);
    *param_1 = iVar2;
    iVar2 = 0;
    if (0 < param_1[6]) {
      do {
        *(int *)(*param_1 + iVar2 * 4) = iVar2 * param_1[5] + param_1[4];
        iVar2 = iVar2 + 1;
      } while (iVar2 < param_1[6]);
    }
    iVar2 = param_1[6];
    iVar1 = param_1[5];
    puVar4 = (undefined4 *)param_1[4];
    for (uVar3 = (uint)(iVar2 * iVar1) >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      *puVar4 = 0xffffffff;
      puVar4 = puVar4 + 1;
    }
    for (uVar3 = iVar2 * iVar1 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *(undefined1 *)puVar4 = 0xff;
      puVar4 = (undefined4 *)((int)puVar4 + 1);
    }
  }
  uVar3 = 1 << (*(byte *)(param_3 + 0x4a) & 0x1f);
  param_1[0xd] = 0;
  param_1[9] = uVar3;
  param_1[10] = ~uVar3;
  param_1[0xb] = param_1[9] << 0x10;
  param_1[0xc] = ~(param_1[9] << 0x10);
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0053c284
// Address: 0053c284
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int * __thiscall FUN_0053c284(int *param_1,int param_2,int param_3)
{
  int *piVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  int *piStack_4;
  
  piVar1 = param_1 + 5;
  param_1[1] = param_3;
  param_1[3] = *(int *)(param_3 + 0x28);
  param_1[7] = 0;
  piStack_4 = param_1;
  rge_read(param_2,piVar1,4);
  piVar2 = param_1 + 6;
  rge_read(param_2,piVar2,4);
  if (_DAT_005776e0 <= save_game_version) {
    rge_read(param_2,param_1 + 7,4);
  }
  rge_read(param_2,&piStack_4,2);
  iVar3 = *piVar2 * *piVar1;
  param_1[8] = iVar3;
  param_1[2] = *(int *)(*(int *)(param_3 + 0x40) + (short)piStack_4 * 4);
  if ((*piVar1 < 1) || (*piVar2 < 1)) {
    param_1[4] = 0;
    *param_1 = 0;
  }
  else {
    iVar3 = calloc(iVar3,1);
    param_1[4] = iVar3;
    iVar3 = calloc(*piVar2,4);
    *param_1 = iVar3;
    iVar3 = 0;
    if (0 < *piVar2) {
      do {
        *(int *)(*param_1 + iVar3 * 4) = iVar3 * *piVar1 + param_1[4];
        iVar3 = iVar3 + 1;
      } while (iVar3 < *piVar2);
    }
    rge_read(param_2,(void *)param_1[4],*piVar1 * *piVar2);
  }
  uVar4 = 1 << ((byte)piStack_4 & 0x1f);
  param_1[0xd] = 0;
  param_1[9] = uVar4;
  param_1[0xb] = uVar4 << 0x10;
  param_1[0xc] = ~(uVar4 << 0x10);
  param_1[10] = ~uVar4;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0053c3b6
// Address: 0053c3b6
void __fastcall FUN_0053c3b6(int *param_1)
{
  if (param_1[4] != 0) {
    free(param_1[4]);
    param_1[4] = 0;
  }
  if (*param_1 != 0) {
    free(*param_1);
    *param_1 = 0;
  }
  param_1[2] = 0;
  param_1[3] = 0;
  return;
}

// --------------------------------------------------

// Function: FUN_0053c3ff
// Address: 0053c3ff
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0053c3ff(int param_1,int param_2)
{
  int iVar1;
  int iVar2;
  
  rge_write(param_2,(int *)(param_1 + 0x14),4);
  rge_write(param_2,(int *)(param_1 + 0x18),4);
  if (_DAT_005776e0 <= save_game_version) {
    rge_write(param_2,(void *)(param_1 + 0x1c),4);
  }
  rge_write(param_2,(void *)(*(int *)(param_1 + 8) + 0x4a),2);
  iVar1 = *(int *)(param_1 + 0x14);
  if ((0 < iVar1) && (iVar2 = *(int *)(param_1 + 0x18), 0 < iVar2)) {
    rge_write(param_2,*(void **)(param_1 + 0x10),iVar2 * iVar1);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0053c481
// Address: 0053c481
uint __thiscall FUN_0053c481(int param_1,int param_2,int param_3)
{
  ulong *puVar1;
  undefined3 uVar2;
  
  puVar1 = (&unified_map_offsets)[param_3][param_2];
  uVar2 = (undefined3)((uint)puVar1 >> 8);
  if (((uint)puVar1 & *(uint *)(*(int *)(param_1 + 8) + 0xd4)) != 0) {
    return CONCAT31(uVar2,0xf);
  }
  return CONCAT31(uVar2,-((*(uint *)(*(int *)(param_1 + 8) + 0xd0) & (uint)puVar1) != 0)) &
         0xffffff80;
}

// --------------------------------------------------

// Function: FUN_0053c4cb
// Address: 0053c4cb
void __thiscall FUN_0053c4cb(int *param_1,byte param_2)
{
  uint uVar1;
  int iVar2;
  int iVar3;
  ulong ***pppuVar4;
  uint uVar5;
  
  log_map_call(*(int *)(param_1[1] + 4),(int)*(short *)(param_1[2] + 0x4a),5,0,(uint)param_2,0,0,0,0
              );
  iVar3 = 0;
  if (0 < param_1[6]) {
    do {
      iVar2 = 0;
      if (0 < param_1[5]) {
        do {
          iVar2 = iVar2 + 1;
          *(byte *)(*(int *)(*param_1 + iVar3 * 4) + -1 + iVar2) = param_2;
        } while (iVar2 < param_1[5]);
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < param_1[6]);
  }
  if ((param_2 == 0xff) || (param_2 == 0)) {
    uVar5 = param_1[10];
    if (param_2 == 0xff) {
      uVar5 = uVar5 & param_1[0xc];
    }
    iVar3 = 0;
    if (0 < param_1[6]) {
      pppuVar4 = &unified_map_offsets;
      do {
        iVar2 = 0;
        if (0 < param_1[5]) {
          do {
            (*pppuVar4)[iVar2] = (ulong *)((uint)(*pppuVar4)[iVar2] & uVar5);
            iVar2 = iVar2 + 1;
          } while (iVar2 < param_1[5]);
        }
        iVar3 = iVar3 + 1;
        pppuVar4 = pppuVar4 + 1;
      } while (iVar3 < param_1[6]);
    }
  }
  else {
    uVar5 = param_1[0xb];
    uVar1 = param_1[9];
    iVar3 = 0;
    if (0 < param_1[6]) {
      pppuVar4 = &unified_map_offsets;
      do {
        iVar2 = 0;
        if (0 < param_1[5]) {
          do {
            (*pppuVar4)[iVar2] = (ulong *)((uint)(*pppuVar4)[iVar2] | uVar5 | uVar1);
            iVar2 = iVar2 + 1;
          } while (iVar2 < param_1[5]);
        }
        iVar3 = iVar3 + 1;
        pppuVar4 = pppuVar4 + 1;
      } while (iVar3 < param_1[6]);
    }
  }
  if (param_2 != 0xff) {
    param_1[7] = param_1[8];
    return;
  }
  param_1[7] = 0;
  return;
}

// --------------------------------------------------

// Function: FUN_0053c5ce
// Address: 0053c5ce
void __fastcall FUN_0053c5ce(int *param_1)
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  log_map_call(*(int *)(param_1[1] + 4),(int)*(short *)(param_1[2] + 0x4a),6,0,0,0,0,0,0);
  iVar2 = 0;
  if (0 < param_1[6]) {
    iVar1 = 0;
    do {
      iVar3 = 0;
      if (0 < param_1[5]) {
        do {
          if (*(char *)(iVar3 + *(int *)(*param_1 + iVar1)) == -1) {
            *(undefined1 *)(iVar3 + *(int *)(*param_1 + iVar1)) = 0;
            param_1[7] = param_1[7] + 1;
            *(uint *)(*(int *)((int)&unified_map_offsets + iVar1) + iVar3 * 4) =
                 *(uint *)(*(int *)((int)&unified_map_offsets + iVar1) + iVar3 * 4) | param_1[0xb];
            RGE_Tile_List::add_node((RGE_Tile_List *)(param_1[2] + 0x58),iVar3,iVar2);
          }
          iVar3 = iVar3 + 1;
        } while (iVar3 < param_1[5]);
      }
      iVar2 = iVar2 + 1;
      iVar1 = iVar1 + 4;
    } while (iVar2 < param_1[6]);
  }
  *(undefined4 *)(param_1[2] + 100) = 1;
  return;
}

// --------------------------------------------------

// Function: FUN_0053c66c
// Address: 0053c66c
float10 __fastcall FUN_0053c66c(int param_1)
{
  return (float10)*(int *)(param_1 + 0x1c) / (float10)*(int *)(param_1 + 0x20);
}

// --------------------------------------------------

// Function: FUN_0053c677
// Address: 0053c677
void __fastcall FUN_0053c677(int *param_1)
{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  param_1[7] = 0;
  if (0 < param_1[6]) {
    do {
      iVar1 = 0;
      if (0 < param_1[5]) {
        do {
          if (*(char *)(iVar1 + *(int *)(*param_1 + iVar2 * 4)) != -1) {
            param_1[7] = param_1[7] + 1;
          }
          iVar1 = iVar1 + 1;
        } while (iVar1 < param_1[5]);
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < param_1[6]);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0053c6b8
// Address: 0053c6b8
undefined * FUN_0053c6b8(int param_1,int param_2)
{
  if (0x10 < param_1) {
    param_1 = 0x10;
  }
  if (param_1 < 0) {
    param_1 = 0;
  }
  if (param_2 != 0) {
    return (&SquareLOS)[param_1];
  }
  return (&NormalLOS)[param_1];
}

// --------------------------------------------------

// Function: FUN_0053c912
// Address: 0053c912
void __thiscall
FUN_0053c912(int *param_1,uint param_2,uint param_3,uint param_4,int param_5,int param_6,int param_7
            )
{
  int *piVar1;
  uint uVar2;
  int iVar3;
  char *pcVar4;
  char cVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  ulong **ppuVar9;
  int iStack_8;
  
  iStack_8 = 0;
  log_map_call(*(int *)(param_1[1] + 4),(int)*(short *)(param_1[2] + 0x4a),3,param_7,param_2,param_3
               ,param_4,param_5,Map_Update_Suppresion);
  if (Map_Update_Suppresion == 0) {
    uVar2 = param_1[0xd] << 3;
    uVar2 = (((uVar2 | (uint)param_1[0xd] >> 0x1d) ^ 0x20202020) << 2 | uVar2 >> 0x1e) ^
            (int)*(short *)(param_1[2] + 0x4a);
    uVar2 = (uVar2 << 3 | uVar2 >> 0x1d) ^ param_2;
    uVar2 = (uVar2 << 4 | uVar2 >> 0x1c) ^ param_3;
    param_1[0xd] = ((uVar2 << 3 | uVar2 >> 0x1d) ^ param_4) + param_5;
    if (0x10 < (int)param_4) {
      param_4 = 0x10;
    }
    if (param_5 == 0) {
      piVar7 = (int *)(&NormalLOS)[param_4];
    }
    else {
      piVar7 = (int *)(&SquareLOS)[param_4];
    }
    iVar3 = *piVar7;
    while (iVar3 != 999) {
      iVar3 = iVar3 + param_3;
      if ((-1 < iVar3) && (iVar3 < param_1[6])) {
        iVar6 = piVar7[1] + param_2;
        if (iVar6 < 0) {
          iVar6 = 0;
        }
        iVar8 = piVar7[2] + param_2;
        if (param_1[5] <= iVar8) {
          iVar8 = param_1[5] + -1;
        }
        pcVar4 = (char *)(*(int *)(*param_1 + iVar3 * 4) + iVar6);
        ppuVar9 = (&unified_map_offsets)[iVar3] + iVar6;
        if (param_6 != 0) {
          iStack_8 = *(int *)(*(int *)(param_1[3] + 0x8d8c) + iVar3 * 4) + iVar6 * 0x18;
        }
        if (iVar6 <= iVar8) {
          iVar3 = (iVar8 - iVar6) + 1;
          do {
            cVar5 = *pcVar4 + -1;
            if (cVar5 == -1) {
              cVar5 = '\0';
            }
            if (cVar5 == '\0') {
              if (param_6 != 0) {
                *(undefined1 *)(iStack_8 + 9) = 0x80;
              }
              *ppuVar9 = (ulong *)((uint)*ppuVar9 & param_1[10]);
            }
            *pcVar4 = cVar5;
            pcVar4 = pcVar4 + 1;
            ppuVar9 = ppuVar9 + 1;
            iStack_8 = iStack_8 + 0x18;
            iVar3 = iVar3 + -1;
          } while (iVar3 != 0);
        }
      }
      piVar1 = piVar7 + 3;
      piVar7 = piVar7 + 3;
      iVar3 = *piVar1;
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0053cab1
// Address: 0053cab1
int __thiscall
FUN_0053cab1(int *param_1,uint param_2,uint param_3,uint param_4,uint param_5,int param_6,
            int param_7)
{
  int iVar1;
  int iVar2;
  char cVar3;
  uint uVar4;
  char *pcVar5;
  ulong **ppuVar6;
  bool bVar7;
  int iStack_10;
  int iStack_c;
  
  iStack_c = 0;
  log_map_call(*(int *)(param_1[1] + 4),(int)*(short *)(param_1[2] + 0x4a),2,param_7,param_2,param_3
               ,param_4,param_5,Map_Update_Suppresion);
  if (Map_Update_Suppresion == 0) {
    bVar7 = *(int *)(*(int *)(*(int *)(param_1[1] + 0x40) + *(short *)(param_1[1] + 0x7c) * 4) +
                     0xac + *(short *)(param_1[2] + 0x4a) * 4) == 1;
    param_7 = 0;
    iStack_10 = 0;
    uVar4 = param_1[0xd] << 3;
    uVar4 = (((uVar4 | (uint)param_1[0xd] >> 0x1d) ^ 0x34343434) << 2 | uVar4 >> 0x1e) ^ param_2;
    uVar4 = (uVar4 << 4 | uVar4 >> 0x1c) ^ param_3;
    uVar4 = (uVar4 << 3 | uVar4 >> 0x1d) ^ param_4;
    param_1[0xd] = (uVar4 << 3 | uVar4 >> 0x1d) ^ param_5;
    if (bVar7) {
      iStack_10 = *(int *)(*(int *)(param_1[1] + 0x40) + *(short *)(param_1[1] + 0x7c) * 4);
    }
    iVar1 = param_1[5];
    if (((((int)param_2 < iVar1) && (-1 < (int)param_4)) &&
        (iVar2 = param_1[6], (int)param_3 < iVar2)) && (-1 < (int)param_5)) {
      if ((int)param_2 < 0) {
        param_2 = 0;
      }
      if (iVar1 <= (int)param_4) {
        param_4 = iVar1 - 1;
      }
      if ((int)param_3 < 0) {
        param_3 = 0;
      }
      if (iVar2 <= (int)param_5) {
        param_5 = iVar2 - 1;
      }
      for (; (int)param_3 <= (int)param_5; param_3 = param_3 + 1) {
        ppuVar6 = (&unified_map_offsets)[param_3] + param_2;
        pcVar5 = (char *)(*(int *)(*param_1 + param_3 * 4) + param_2);
        uVar4 = param_2;
        if (param_6 != 0) {
          param_7 = *(int *)(*(int *)(param_1[3] + 0x8d8c) + param_3 * 4) + param_2 * 0x18;
        }
        for (; (int)uVar4 <= (int)param_4; uVar4 = uVar4 + 1) {
          cVar3 = *pcVar5 + '\x01';
          if (cVar3 == '\0') {
            iStack_c = iStack_c + 1;
            param_1[7] = param_1[7] + 1;
            RGE_Tile_List::add_node((RGE_Tile_List *)(param_1[2] + 0x58),uVar4,param_3);
            if (bVar7) {
              RGE_Tile_List::add_node((RGE_Tile_List *)(iStack_10 + 0x6c),uVar4,param_3);
            }
            cVar3 = '\x01';
            *ppuVar6 = (ulong *)((uint)*ppuVar6 | param_1[0xb]);
          }
          if (cVar3 == '\x01') {
            if (param_6 != 0) {
              *(undefined1 *)(param_7 + 9) = 0xf;
            }
            *ppuVar6 = (ulong *)((uint)*ppuVar6 | param_1[9]);
          }
          if (cVar3 == -6) {
            cVar3 = -7;
          }
          *pcVar5 = cVar3;
          pcVar5 = pcVar5 + 1;
          ppuVar6 = ppuVar6 + 1;
          param_7 = param_7 + 0x18;
        }
      }
      return iStack_c;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0053cce6
// Address: 0053cce6
void __thiscall
FUN_0053cce6(int *param_1,uint param_2,uint param_3,uint param_4,uint param_5,int param_6,
            int param_7)
{
  int iVar1;
  uint uVar2;
  char *pcVar3;
  char cVar4;
  ulong **ppuVar5;
  int iVar6;
  int iStack_8;
  
  iStack_8 = 0;
  log_map_call(*(int *)(param_1[1] + 4),(int)*(short *)(param_1[2] + 0x4a),4,param_7,param_2,param_3
               ,param_4,param_5,Map_Update_Suppresion);
  if (Map_Update_Suppresion == 0) {
    uVar2 = (param_1[0xd] << 3 | (uint)param_1[0xd] >> 0x1d) ^ 0x56565656;
    uVar2 = (uVar2 << 2 | uVar2 >> 0x1e) ^ param_2;
    uVar2 = (uVar2 << 4 | uVar2 >> 0x1c) ^ param_3;
    uVar2 = (uVar2 << 3 | uVar2 >> 0x1d) ^ param_4;
    param_1[0xd] = (uVar2 << 3 | uVar2 >> 0x1d) ^ param_5;
    iVar6 = param_1[5];
    if (((((int)param_2 < iVar6) && (-1 < (int)param_4)) &&
        (iVar1 = param_1[6], (int)param_3 < iVar1)) && (-1 < (int)param_5)) {
      if ((int)param_2 < 0) {
        param_2 = 0;
      }
      if (iVar6 <= (int)param_4) {
        param_4 = iVar6 - 1;
      }
      if ((int)param_3 < 0) {
        param_3 = 0;
      }
      if (iVar1 <= (int)param_5) {
        param_5 = iVar1 - 1;
      }
      for (; (int)param_3 <= (int)param_5; param_3 = param_3 + 1) {
        pcVar3 = (char *)(*(int *)(*param_1 + param_3 * 4) + param_2);
        ppuVar5 = (&unified_map_offsets)[param_3] + param_2;
        if (param_6 != 0) {
          iStack_8 = *(int *)(*(int *)(param_1[3] + 0x8d8c) + param_3 * 4) + param_2 * 0x18;
        }
        if ((int)param_2 <= (int)param_4) {
          iVar6 = (param_4 - param_2) + 1;
          do {
            cVar4 = *pcVar3 + -1;
            if (cVar4 == -1) {
              cVar4 = '\0';
            }
            if (cVar4 == '\0') {
              if (param_6 != 0) {
                *(undefined1 *)(iStack_8 + 9) = 0x80;
              }
              *ppuVar5 = (ulong *)((uint)*ppuVar5 & param_1[10]);
            }
            *pcVar3 = cVar4;
            pcVar3 = pcVar3 + 1;
            ppuVar5 = ppuVar5 + 1;
            iStack_8 = iStack_8 + 0x18;
            iVar6 = iVar6 + -1;
          } while (iVar6 != 0);
        }
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0053ce6d
// Address: 0053ce6d
undefined4 __fastcall FUN_0053ce6d(int param_1)
{
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)(param_1 + 0x34);
  *(undefined4 *)(param_1 + 0x34) = 0;
  return uVar1;
}

// --------------------------------------------------

// Function: FUN_0053ce7b
// Address: 0053ce7b
RGE_Unified_Visible_Map * __thiscall
FUN_0053ce7b(RGE_Unified_Visible_Map *param_1,int param_2,int param_3)
{
  ulong *puVar1;
  
  param_1->mapWidth = param_2;
  param_1->mapHeight = param_3;
  Map_Update_Suppresion = 0;
  if ((0 < param_1->mapHeight) && (0 < param_1->mapWidth)) {
    puVar1 = (ulong *)calloc(param_1->mapWidth * param_1->mapHeight,4);
    param_1->UnifiedVisibleMap = puVar1;
    RGE_Unified_Visible_Map::Set_Map_Offsets(param_1);
    return param_1;
  }
  param_1->UnifiedVisibleMap = (ulong *)0x0;
  param_1->mapWidth = 0;
  param_1->mapHeight = 0;
  RGE_Unified_Visible_Map::Set_Map_Offsets(param_1);
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0053ced8
// Address: 0053ced8
RGE_Unified_Visible_Map * __thiscall FUN_0053ced8(RGE_Unified_Visible_Map *param_1,int param_2)
{
  param_1->UnifiedVisibleMap = (ulong *)0x0;
  param_1->mapWidth = 0;
  param_1->mapHeight = 0;
  Map_Update_Suppresion = 0;
  RGE_Unified_Visible_Map::load(param_1,param_2);
  RGE_Unified_Visible_Map::Set_Map_Offsets(param_1);
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0053cf09
// Address: 0053cf09
void __thiscall FUN_0053cf09(int *param_1,int param_2)
{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = param_1[1];
  iVar2 = *param_1;
  piVar1 = param_1 + 1;
  rge_read(param_2,param_1,4);
  rge_read(param_2,piVar1,4);
  if ((0 < *piVar1) && (0 < *param_1)) {
    if ((iVar2 != *param_1) || (iVar3 != *piVar1)) {
      if (param_1[2] != 0) {
        free(param_1[2]);
      }
      iVar3 = calloc(*param_1 * *piVar1,4);
      param_1[2] = iVar3;
    }
    rge_read(param_2,(void *)param_1[2],*param_1 * *piVar1 * 4);
    return;
  }
  *piVar1 = 0;
  param_1[2] = 0;
  *param_1 = 0;
  return;
}

// --------------------------------------------------

// Function: FUN_0053cfb1
// Address: 0053cfb1
void __fastcall FUN_0053cfb1(RGE_Unified_Visible_Map *param_1)
{
  param_1->mapHeight = 0;
  RGE_Unified_Visible_Map::Set_Map_Offsets(param_1);
  if (param_1->UnifiedVisibleMap != (ulong *)0x0) {
    free(param_1->UnifiedVisibleMap);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0053cfe1
// Address: 0053cfe1
void __thiscall FUN_0053cfe1(int *param_1,int param_2)
{
  int iVar1;
  
  rge_write(param_2,param_1,4);
  rge_write(param_2,param_1 + 1,4);
  iVar1 = param_1[1];
  if ((0 < iVar1) && (0 < *param_1)) {
    rge_write(param_2,(void *)param_1[2],*param_1 * iVar1 * 4);
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0053d03a
// Address: 0053d03a
void __fastcall FUN_0053d03a(int *param_1)
{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  
  if ((undefined4 *)param_1[2] != (undefined4 *)0x0) {
    puVar3 = (undefined4 *)param_1[2];
    for (uVar1 = param_1[1] * *param_1 & 0x3fffffff; uVar1 != 0; uVar1 = uVar1 - 1) {
      *puVar3 = 0;
      puVar3 = puVar3 + 1;
    }
    for (iVar2 = 0; iVar2 != 0; iVar2 = iVar2 + -1) {
      *(undefined1 *)puVar3 = 0;
      puVar3 = (undefined4 *)((int)puVar3 + 1);
    }
  }
  return;
}

// --------------------------------------------------

// Function: FUN_0053d065
// Address: 0053d065
void __fastcall FUN_0053d065(int *param_1)
{
  int iVar1;
  ulong ***pppuVar2;
  int iVar3;
  
  iVar1 = 0;
  if (0 < param_1[1]) {
    pppuVar2 = &unified_map_offsets;
    do {
      iVar3 = *param_1 * iVar1;
      iVar1 = iVar1 + 1;
      *pppuVar2 = (ulong **)(param_1[2] + iVar3 * 4);
      pppuVar2 = pppuVar2 + 1;
    } while (iVar1 < param_1[1]);
  }
  iVar1 = param_1[1];
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

// Function: FUN_0053d0b8
// Address: 0053d0b8
void FUN_0053d0b8(int param_1)
{
  Map_Update_Suppresion = param_1;
  return;
}

// --------------------------------------------------

// Function: FUN_0053d0cc
// Address: 0053d0cc
byte __fastcall FUN_0053d0cc(int *param_1)
{
  byte bVar1;
  int iVar2;
  int iVar3;
  
  bVar1 = 0;
  iVar3 = 0;
  if (0 < param_1[6]) {
    do {
      iVar2 = 0;
      if (0 < param_1[5]) {
        do {
          bVar1 = bVar1 ^ *(byte *)(iVar2 + *(int *)(*param_1 + iVar3 * 4));
          iVar2 = iVar2 + 1;
        } while (iVar2 < param_1[5]);
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < param_1[6]);
  }
  return bVar1;
}

// --------------------------------------------------

// Function: FUN_0053d106
// Address: 0053d106
uint __fastcall FUN_0053d106(int param_1)
{
  ulong *puVar1;
  uint uVar2;
  ulong **ppuVar3;
  int iVar4;
  int iVar5;
  ulong ***pppuVar6;
  
  iVar5 = *(int *)(param_1 + 0x18);
  uVar2 = 0;
  if (0 < iVar5) {
    pppuVar6 = &unified_map_offsets;
    do {
      if (0 < *(int *)(param_1 + 0x14)) {
        ppuVar3 = *pppuVar6;
        iVar4 = *(int *)(param_1 + 0x14);
        do {
          puVar1 = *ppuVar3;
          ppuVar3 = ppuVar3 + 1;
          uVar2 = uVar2 ^ (uint)puVar1;
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
      }
      pppuVar6 = pppuVar6 + 1;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
  }
  return uVar2;
}

// --------------------------------------------------

// Function: FUN_0053d144
// Address: 0053d144
void FUN_0053d144(VC_LOG *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9)
{
  int iVar1;
  
  iVar1 = VCALL_LOG_HEAD + 1;
  if (iVar1 < 0x400) {
    if ((-1 < VCALL_LOG_TAIL) && (VCALL_LOG_TAIL = VCALL_LOG_HEAD + 2, 0x3ff < VCALL_LOG_TAIL)) {
      VCALL_LOG_TAIL = 0;
    }
  }
  else {
    iVar1 = 0;
    VCALL_LOG_TAIL = 1;
  }
  VCALL_LOG_HEAD = iVar1;
  (&VCALL_LOG)[iVar1 * 9] = param_1;
  (&DAT_0087d80c)[iVar1 * 9] = param_2;
  (&DAT_0087d810)[iVar1 * 9] = param_3;
  (&DAT_0087d814)[iVar1 * 9] = param_4;
  (&DAT_0087d818)[iVar1 * 9] = param_5;
  (&DAT_0087d81c)[iVar1 * 9] = param_6;
  (&DAT_0087d820)[iVar1 * 9] = param_7;
  (&DAT_0087d824)[iVar1 * 9] = param_8;
  (&DAT_0087d828)[iVar1 * 9] = param_9;
  return;
}

// --------------------------------------------------

// Function: log_map_call
// Address: 0053d150
/* void __cdecl log_map_call(int,int,int,int,int,int,int,int,int) */

void __cdecl
log_map_call(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,int param_7,
            int param_8,int param_9)
{
  int iVar1;
  
  iVar1 = VCALL_LOG_HEAD + 1;
  if (iVar1 < 0x400) {
    if ((-1 < VCALL_LOG_TAIL) && (VCALL_LOG_TAIL = VCALL_LOG_HEAD + 2, 0x3ff < VCALL_LOG_TAIL)) {
      VCALL_LOG_TAIL = 0;
    }
  }
  else {
    iVar1 = 0;
    VCALL_LOG_TAIL = 1;
  }
  VCALL_LOG_HEAD = iVar1;
  (&VCALL_LOG)[iVar1 * 9] = (VC_LOG *)param_1;
  (&DAT_0087d80c)[iVar1 * 9] = param_2;
  (&DAT_0087d810)[iVar1 * 9] = param_3;
  (&DAT_0087d814)[iVar1 * 9] = param_4;
  (&DAT_0087d818)[iVar1 * 9] = param_5;
  (&DAT_0087d81c)[iVar1 * 9] = param_6;
  (&DAT_0087d820)[iVar1 * 9] = param_7;
  (&DAT_0087d824)[iVar1 * 9] = param_8;
  (&DAT_0087d828)[iVar1 * 9] = param_9;
  return;
}

// --------------------------------------------------

// Function: FUN_0053d1f6
// Address: 0053d1f6
// [HELPER] s_EXPLORE_ALL_: "EXPLORE ALL "
// [HELPER] s_EXPLORE_SQ__: "EXPLORE SQ  "
// [HELPER] s_EXPLORE_____: "EXPLORE     "
// [HELPER] s_NULL_LOG_: "NULL LOG\n"
// [HELPER] s_SET_ALL_____: "SET ALL     "
// [HELPER] s_UNEXPLORE_SQ: "UNEXPLORE SQ"
// [HELPER] s_UNEXPLORE___: "UNEXPLORE   "
// [HELPER] s__ERROR__Undef_Action____d_: "*ERROR* Undef Action = %d "
// [HELPER] s__wt____d__plyr____d__id____d__x1: " wt = %d, plyr = %d, id = %d, x1=%d, y1=%d, x2=%d, y2=%d, s=%d\n"
// [HELPER] s_c__aoeexlog_txt: "c:\aoeexlog.txt"
// [HELPER] s_w: "w"
void FUN_0053d1f6(void)
{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  
  bVar1 = false;
  uVar2 = fopen(s_c__aoeexlog_txt,s_w);
  if (-1 < VCALL_LOG_HEAD) {
    iVar3 = VCALL_LOG_TAIL;
    if (VCALL_LOG_TAIL < 0) {
      iVar3 = 0;
    }
    do {
      switch((&DAT_0087d810)[iVar3 * 9]) {
      case 1:
        fprintf(uVar2,s_EXPLORE_____);
        break;
      case 2:
        fprintf(uVar2,s_EXPLORE_SQ__);
        break;
      case 3:
        fprintf(uVar2,s_UNEXPLORE___);
        break;
      case 4:
        fprintf(uVar2,s_UNEXPLORE_SQ);
        break;
      case 5:
        fprintf(uVar2,s_SET_ALL_____);
        break;
      case 6:
        fprintf(uVar2,s_EXPLORE_ALL_);
        break;
      default:
        fprintf(uVar2,s__ERROR__Undef_Action____d_,(&DAT_0087d810)[iVar3 * 9]);
      }
      fprintf(uVar2,s__wt____d__plyr____d__id____d__x1,(&VCALL_LOG)[iVar3 * 9],
              (&DAT_0087d80c)[iVar3 * 9],(&DAT_0087d814)[iVar3 * 9],(&DAT_0087d818)[iVar3 * 9],
              (&DAT_0087d81c)[iVar3 * 9],(&DAT_0087d820)[iVar3 * 9],(&DAT_0087d824)[iVar3 * 9],
              (&DAT_0087d828)[iVar3 * 9]);
      if (iVar3 == VCALL_LOG_HEAD) {
        bVar1 = true;
      }
      iVar3 = iVar3 + 1;
      if (0x3ff < iVar3) {
        iVar3 = 0;
      }
    } while (!bVar1);
    fclose(uVar2);
    return;
  }
  fprintf(uVar2,s_NULL_LOG_);
  fclose(uVar2);
  return;
}

// --------------------------------------------------

// Function: dump_vismap_log
// Address: 0053d200
// [HELPER] s_EXPLORE_ALL_: "EXPLORE ALL "
// [HELPER] s_EXPLORE_SQ__: "EXPLORE SQ  "
// [HELPER] s_EXPLORE_____: "EXPLORE     "
// [HELPER] s_NULL_LOG_: "NULL LOG\n"
// [HELPER] s_SET_ALL_____: "SET ALL     "
// [HELPER] s_UNEXPLORE_SQ: "UNEXPLORE SQ"
// [HELPER] s_UNEXPLORE___: "UNEXPLORE   "
// [HELPER] s__ERROR__Undef_Action____d_: "*ERROR* Undef Action = %d "
// [HELPER] s__wt____d__plyr____d__id____d__x1: " wt = %d, plyr = %d, id = %d, x1=%d, y1=%d, x2=%d, y2=%d, s=%d\n"
// [HELPER] s_c__aoeexlog_txt: "c:\aoeexlog.txt"
// [HELPER] s_w: "w"
/* void __cdecl dump_vismap_log(void) */

void __cdecl dump_vismap_log(void)
{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  
  bVar1 = false;
  uVar2 = fopen(s_c__aoeexlog_txt,s_w);
  if (-1 < VCALL_LOG_HEAD) {
    iVar3 = VCALL_LOG_TAIL;
    if (VCALL_LOG_TAIL < 0) {
      iVar3 = 0;
    }
    do {
      switch((&DAT_0087d810)[iVar3 * 9]) {
      case 1:
        fprintf(uVar2,s_EXPLORE_____);
        break;
      case 2:
        fprintf(uVar2,s_EXPLORE_SQ__);
        break;
      case 3:
        fprintf(uVar2,s_UNEXPLORE___);
        break;
      case 4:
        fprintf(uVar2,s_UNEXPLORE_SQ);
        break;
      case 5:
        fprintf(uVar2,s_SET_ALL_____);
        break;
      case 6:
        fprintf(uVar2,s_EXPLORE_ALL_);
        break;
      default:
        fprintf(uVar2,s__ERROR__Undef_Action____d_,(&DAT_0087d810)[iVar3 * 9]);
      }
      fprintf(uVar2,s__wt____d__plyr____d__id____d__x1,(&VCALL_LOG)[iVar3 * 9],
              (&DAT_0087d80c)[iVar3 * 9],(&DAT_0087d814)[iVar3 * 9],(&DAT_0087d818)[iVar3 * 9],
              (&DAT_0087d81c)[iVar3 * 9],(&DAT_0087d820)[iVar3 * 9],(&DAT_0087d824)[iVar3 * 9],
              (&DAT_0087d828)[iVar3 * 9]);
      if (iVar3 == VCALL_LOG_HEAD) {
        bVar1 = true;
      }
      iVar3 = iVar3 + 1;
      if (0x3ff < iVar3) {
        iVar3 = 0;
      }
    } while (!bVar1);
    fclose(uVar2);
    return;
  }
  fprintf(uVar2,s_NULL_LOG_);
  fclose(uVar2);
  return;
}

// --------------------------------------------------

// Function: FUN_0053d37c
// Address: 0053d37c
RGE_Diamond_Map_View * __thiscall FUN_0053d37c(RGE_Diamond_Map_View *param_1,byte param_2)
{
  RGE_Diamond_Map_View::~RGE_Diamond_Map_View(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0053d3a5
// Address: 0053d3a5
void __thiscall
FUN_0053d3a5(RGE_Diamond_Map *param_1,uchar param_2,long param_3,long param_4,int param_5,
            int param_6)
{
  long lVar1;
  long lVar2;
  int iVar3;
  RGE_Diamond_Map *pRStack_4;
  
  lVar2 = param_4;
  lVar1 = param_3;
  pRStack_4 = param_1;
  iVar3 = RGE_Diamond_Map::pick_tile
                    (param_1,param_3,param_4,(short *)&param_3,(short *)&param_4,
                     (RGE_Tile **)&pRStack_4);
  if (iVar3 == 0) {
    return;
  }
  TPanel::handle_mouse_down((TPanel *)param_1,param_2,lVar1,lVar2,param_5,param_6);
  return;
}

// --------------------------------------------------

// Function: FUN_0053d47e
// Address: 0053d47e
undefined4 __thiscall FUN_0053d47e(RGE_Diamond_Map *param_1,long param_2,long param_3)
{
  int iVar1;
  
  iVar1 = rge_base_game->prog_mode;
  if ((((iVar1 == 4) || (iVar1 == 6)) || (iVar1 == 7)) || (iVar1 == 5)) {
    iVar1 = RGE_Base_Game::get_paused(rge_base_game);
    if (iVar1 != 0) {
      if (param_1->scrolling != 0) {
        RGE_Diamond_Map::end_scroll_view(param_1);
        return 0;
      }
      TPanel::release_mouse((TPanel *)param_1);
      return 0;
    }
    if (param_1->scrolling != 0) {
      RGE_Diamond_Map::handle_scroll_view(param_1,param_2,param_3);
      return 1;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0053d4f2
// Address: 0053d4f2
undefined4 __thiscall FUN_0053d4f2(RGE_Diamond_Map *param_1,long param_2,long param_3)
{
  int iVar1;
  short sStack_8;
  short sStack_6;
  RGE_Tile *pRStack_4;
  
  iVar1 = rge_base_game->prog_mode;
  if ((((iVar1 == 4) || (iVar1 == 6)) || (iVar1 == 7)) || (iVar1 == 5)) {
    if (param_1->scrolling != 0) {
      RGE_Diamond_Map::end_scroll_view(param_1);
      return 1;
    }
    TPanel::release_mouse((TPanel *)param_1);
    iVar1 = RGE_Base_Game::get_paused(rge_base_game);
    if ((iVar1 == 0) && (rge_base_game->prog_mode != 5)) {
      iVar1 = RGE_Diamond_Map::pick_tile(param_1,param_2,param_3,&sStack_6,&sStack_8,&pRStack_4);
      if (iVar1 != 0) {
        iVar1 = rge_base_game->game_mode;
        if (iVar1 == 0) {
          if (rge_base_game->prog_info->interface_style != 2) {
            iVar1 = (**(code **)(param_1->_padding_ + 0xf4))(param_2,param_3);
            if (iVar1 != 0) {
              return 1;
            }
          }
        }
        else {
          if (iVar1 == 4) {
            (**(code **)(param_1->_padding_ + 0xf8))(param_2,param_3);
            return 1;
          }
          if (iVar1 == 5) {
            (**(code **)(param_1->_padding_ + 0xfc))(param_2,param_3);
            return 1;
          }
        }
      }
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0053d61c
// Address: 0053d61c
undefined4 __thiscall FUN_0053d61c(RGE_Diamond_Map *param_1,long param_2,long param_3)
{
  int iVar1;
  
  iVar1 = RGE_Base_Game::get_paused(rge_base_game);
  if (iVar1 == 0) {
    iVar1 = rge_base_game->prog_mode;
    if ((((iVar1 == 4) || (iVar1 == 6)) || (iVar1 == 7)) || (iVar1 == 5)) {
      if (rge_base_game->prog_info->interface_style == 2) {
        if (((iVar1 == 4) || (iVar1 == 6)) || (iVar1 == 7)) {
          TPanel::capture_mouse((TPanel *)param_1);
          return 1;
        }
      }
      else {
        RGE_Diamond_Map::start_scroll_view(param_1,param_2,param_3);
      }
      return 1;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0053d69e
// Address: 0053d69e
undefined4 __thiscall FUN_0053d69e(RGE_Diamond_Map *param_1,long param_2,long param_3)
{
  int iVar1;
  
  iVar1 = rge_base_game->prog_mode;
  if ((((iVar1 == 4) || (iVar1 == 6)) || (iVar1 == 7)) || (iVar1 == 5)) {
    iVar1 = RGE_Base_Game::get_paused(rge_base_game);
    if (iVar1 != 0) {
      if (param_1->scrolling != 0) {
        RGE_Diamond_Map::end_scroll_view(param_1);
        return 0;
      }
      TPanel::release_mouse((TPanel *)param_1);
      return 0;
    }
    if (param_1->scrolling != 0) {
      RGE_Diamond_Map::handle_scroll_view(param_1,param_2,param_3);
      return 1;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0053d712
// Address: 0053d712
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall
FUN_0053d712(RGE_Diamond_Map *param_1,long param_2,long param_3,undefined4 param_4,int param_5)
{
  char cVar1;
  int iVar2;
  RGE_Diamond_Map *pRStack_4;
  
  iVar2 = rge_base_game->prog_mode;
  if ((((iVar2 == 4) || (iVar2 == 6)) || (iVar2 == 7)) || (iVar2 == 5)) {
    pRStack_4 = param_1;
    if (param_1->scrolling != 0) {
      RGE_Diamond_Map::end_scroll_view(param_1);
      return 1;
    }
    TPanel::release_mouse((TPanel *)param_1);
    iVar2 = RGE_Base_Game::get_paused(rge_base_game);
    if ((iVar2 == 0) && ((cVar1 = (char)param_1->_padding_, cVar1 == '\x01' || (cVar1 == '\x02'))))
{
      if (rge_base_game->prog_info->interface_style == 2) {
        if ((rge_base_game->game_mode == 0) && (rge_base_game->prog_mode != 5)) {
          if (param_5 != 0) {
            iVar2 = RGE_Diamond_Map::pick_tile
                              (param_1,param_2,param_3,(short *)&param_2,(short *)&param_3,
                               (RGE_Tile **)&pRStack_4);
            if (iVar2 != 0) {
              param_5 = (int)(short)param_2;
              (**(code **)(param_1->player->_padding_ + 0xd8))
                        ((float)param_5 - _DAT_005777e8,(float)(int)(short)param_3 - _DAT_005777e8,
                         0x3f800000);
            }
            return 1;
          }
          iVar2 = (**(code **)(param_1->_padding_ + 0xf4))(param_2,param_3);
          if (iVar2 != 0) {
            return 1;
          }
        }
      }
      else if (rge_base_game->prog_mode != 7) {
        if (rge_base_game->game_mode != 0) {
          (**(code **)(rge_base_game->_padding_ + 0x10))(0,0);
          return 0;
        }
        RGE_Player::unselect_object(param_1->player);
      }
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0053d8d4
// Address: 0053d8d4
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 __thiscall FUN_0053d8d4(RGE_Diamond_Map *param_1,long param_2,long param_3)
{
  undefined1 uVar1;
  int iVar2;
  RGE_Tile *pRStack_4;
  
  if (allow_user_commands == 0) {
    return 0;
  }
  uVar1 = 0;
  iVar2 = RGE_Diamond_Map::pick_tile
                    (param_1,param_2,param_3,(short *)&param_2,(short *)&param_3,&pRStack_4);
  if (iVar2 != 0) {
    uVar1 = (**(code **)(param_1->player->_padding_ + 0xa8))
                      (0,(float)(int)(short)param_2 - _DAT_005777e8,
                       (float)(int)(short)param_3 - _DAT_005777e8);
  }
  return uVar1;
}

// --------------------------------------------------

// Function: FUN_0053d96d
// Address: 0053d96d
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 __thiscall FUN_0053d96d(RGE_Diamond_Map *param_1,long param_2,long param_3)
{
  undefined1 uVar1;
  int iVar2;
  RGE_Tile *pRStack_4;
  
  if (allow_user_commands == 0) {
    return 0;
  }
  uVar1 = 0;
  iVar2 = RGE_Diamond_Map::pick_tile
                    (param_1,param_2,param_3,(short *)&param_2,(short *)&param_3,&pRStack_4);
  if (iVar2 != 0) {
    uVar1 = (**(code **)(param_1->player->_padding_ + 0xa0))
                      (0,(float)(int)(short)param_2 - _DAT_005777e8,
                       (float)(int)(short)param_3 - _DAT_005777e8);
  }
  (**(code **)(rge_base_game->_padding_ + 0x10))(0,0);
  return uVar1;
}

// --------------------------------------------------

// Function: FUN_0053da0c
// Address: 0053da0c
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 __thiscall FUN_0053da0c(RGE_Diamond_Map *param_1,long param_2,long param_3)
{
  undefined1 uVar1;
  int iVar2;
  RGE_Tile *pRStack_4;
  
  if (allow_user_commands == 0) {
    return 0;
  }
  uVar1 = 0;
  iVar2 = RGE_Diamond_Map::pick_tile
                    (param_1,param_2,param_3,(short *)&param_2,(short *)&param_3,&pRStack_4);
  if (iVar2 != 0) {
    uVar1 = (**(code **)(param_1->player->_padding_ + 0xa4))
                      (0,(float)(int)(short)param_2 - _DAT_005777e8,
                       (float)(int)(short)param_3 - _DAT_005777e8);
  }
  (**(code **)(rge_base_game->_padding_ + 0x10))(0,0);
  return uVar1;
}

// --------------------------------------------------

// Function: FUN_0053daac
// Address: 0053daac
RGE_View * __fastcall FUN_0053daac(RGE_View *param_1)
{
  RGE_View::RGE_View(param_1);
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  param_1[1]._padding_ = 0;
  param_1->_padding_ = (int)&RGE_Main_View::_vftable_;
  param_1->_padding_ = 10;
  param_1[1]._padding_ = -1;
  param_1[1]._padding_ = -1;
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0053db01
// Address: 0053db01
RGE_Main_View * __thiscall FUN_0053db01(RGE_Main_View *param_1,byte param_2)
{
  RGE_Main_View::~RGE_Main_View(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}

// --------------------------------------------------

// Function: FUN_0053db35
// Address: 0053db35
long __fastcall FUN_0053db35(RGE_Main_View *param_1)
{
  long lVar1;
  
  color_log('E','E',5);
  RGE_Main_View::do_auto_scroll(param_1);
  color_log('E','\x16',5);
  RGE_Main_View::handle_keys(param_1);
  color_log('E','$',5);
  lVar1 = TPanel::handle_idle((TPanel *)param_1);
  color_log('E','_',5);
  return lVar1;
}

// --------------------------------------------------

// Function: FUN_0053db96
// Address: 0053db96
// [HELPER] s_C__msdev_work_age1_x1_vw_main_cp: "C:\msdev\work\age1_x1\vw_main.cpp"
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

long __fastcall FUN_0053db96(TPanel *param_1)
{
  float fVar1;
  RGE_Prog_Info *pRVar2;
  float fVar3;
  short sVar4;
  short sVar5;
  int iVar6;
  void *pvVar7;
  TPanel *pTVar8;
  RGE_Player *pRVar9;
  short sVar10;
  float10 fVar11;
  float10 extraout_ST0;
  float10 fVar12;
  int iStack_20;
  int iStack_1c;
  ulong uStack_18;
  undefined4 uStack_14;
  int iStack_10;
  int iStack_c;
  int iStack_8;
  int iStack_4;
  
  iVar6 = rge_base_game->prog_mode;
  if ((((((iVar6 != 4) && (iVar6 != 6)) && (iVar6 != 7)) && (iVar6 != 5)) ||
      (((iVar6 = RGE_Base_Game::get_paused(rge_base_game), iVar6 != 0 ||
        (sVar10 = 0, rge_base_game->prog_info->auto_scroll == 0)) ||
       ((pvVar7 = (void *)GetForegroundWindow(), pvVar7 != param_1->render_area->Wnd ||
        (pTVar8 = TPanelSystem::modalPanel(&panel_system), pTVar8 != (TPanel *)0x0)))))) ||
     (((pTVar8 = TPanelSystem::mouseOwner(&panel_system), pTVar8 != (TPanel *)0x0 &&
       (pTVar8 = TPanelSystem::mouseOwner(&panel_system), pTVar8 != param_1)) ||
      (param_1[3].left_border != 0)))) {
    param_1[3].render_rect.left = 0;
    return 0;
  }
  GetWindowRect(param_1->render_area->Wnd,&iStack_10);
  GetCursorPos(&iStack_20);
  sVar4 = 0;
  pRVar2 = rge_base_game->prog_info;
  sVar5 = GetAsyncKeyState(1);
  if ((sVar5 < 0) || (sVar5 = GetAsyncKeyState(2), sVar5 < 0)) goto LAB_0053de6d;
  iVar6 = pRVar2->mouse_scroll_edge;
  if (iStack_20 < iStack_10 + iVar6) {
    sVar10 = -1;
  }
  else if (iStack_8 - iVar6 < iStack_20) {
    sVar10 = 1;
  }
  if (iStack_1c < iStack_c + iVar6) {
    sVar4 = -1;
  }
  else if (iStack_4 - iVar6 < iStack_1c) {
    sVar4 = 1;
  }
  if ((sVar10 == 0) && (sVar4 == 0)) goto LAB_0053de6d;
  pvVar7 = (void *)debug_timeGetTime(s_C__msdev_work_age1_x1_vw_main_cp,0xaa);
  if (param_1[3].render_rect.left == 0) {
    fVar11 = (float10)_DAT_00577900;
    param_1[3].render_rect.left = 1;
  }
  else {
    uStack_18 = pRVar2->key_scroll_interval;
    uStack_14 = 0;
    iVar6 = __ftol();
    fVar1 = _DAT_00577904;
    if (extraout_ST0 - (float10)iVar6 < (float10)_DAT_00577904) {
      fVar1 = _DAT_00577908;
    }
    fVar11 = (float10)fVar1 + (float10)iVar6;
  }
  if ((float10)pRVar2->mouse_scroll_max_dist < fVar11) {
    fVar11 = (float10)pRVar2->mouse_scroll_max_dist;
  }
  if (fVar11 <= (float10)_DAT_00577908) goto LAB_0053de6d;
  fVar1 = (float)(fVar11 + fVar11);
  if (sVar10 == -1) {
    pRVar9 = (RGE_Player *)param_1[1].pnl_x;
    fVar12 = (float10)pRVar9->view_y - fVar11;
    fVar11 = (float10)pRVar9->view_x - fVar11;
LAB_0053dddf:
    RGE_Player::set_view_loc(pRVar9,(float)fVar11,(float)fVar12);
  }
  else if (sVar10 == 1) {
    pRVar9 = (RGE_Player *)param_1[1].pnl_x;
    fVar12 = (float10)pRVar9->view_y + fVar11;
    fVar11 = (float10)pRVar9->view_x + fVar11;
    goto LAB_0053dddf;
  }
  if (sVar4 == -1) {
    pRVar9 = (RGE_Player *)param_1[1].pnl_x;
    fVar3 = pRVar9->view_y - fVar1;
    fVar1 = pRVar9->view_x + fVar1;
LAB_0053de3b:
    RGE_Player::set_view_loc(pRVar9,fVar1,fVar3);
  }
  else if (sVar4 == 1) {
    pRVar9 = (RGE_Player *)param_1[1].pnl_x;
    fVar3 = pRVar9->view_y + fVar1;
    fVar1 = pRVar9->view_x - fVar1;
    goto LAB_0053de3b;
  }
  (**(code **)(param_1->_padding_ + 0x20))(1);
  if ((int *)param_1[3].just_drawn != (int *)0x0) {
    (**(code **)(*(int *)param_1[3].just_drawn + 0x20))(1);
  }
  param_1[3].clip_rgn = pvVar7;
LAB_0053de6d:
  if ((sVar10 == 0) && (sVar4 == 0)) {
    param_1[3].render_rect.left = 0;
  }
  return param_1[3].render_rect.left;
}

// --------------------------------------------------

// Function: FUN_0053dea5
// Address: 0053dea5
// [HELPER] s_C__msdev_work_age1_x1_vw_main_cp: "C:\msdev\work\age1_x1\vw_main.cpp"
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool __fastcall FUN_0053dea5(int *param_1)
{
  float fVar1;
  RGE_Prog_Info *pRVar2;
  int *piVar3;
  float fVar4;
  short sVar5;
  int iVar6;
  ulong uVar7;
  RGE_Player *pRVar8;
  bool bVar9;
  float10 fVar10;
  float10 extraout_ST0;
  float10 fVar11;
  short sVar12;
  undefined1 auStack_100 [33];
  byte bStack_df;
  byte bStack_de;
  byte bStack_dd;
  byte bStack_dc;
  
  iVar6 = RGE_Base_Game::get_paused(rge_base_game);
  if (((iVar6 != 0) ||
      ((((iVar6 = rge_base_game->prog_mode, iVar6 != 4 && (iVar6 != 6)) && (iVar6 != 7)) &&
       (iVar6 != 5)))) ||
     ((iVar6 = GetForegroundWindow(), iVar6 != *(int *)(param_1[8] + 4) ||
      (bVar9 = false, param_1[0x1e] == 0)))) {
    param_1[0xde] = 0;
    return false;
  }
  GetKeyboardState(auStack_100);
  sVar12 = 0;
  sVar5 = 0;
  pRVar2 = rge_base_game->prog_info;
  if (((rge_base_game->game_mode == 0x12) && (param_1[0x40] != 0)) &&
     (piVar3 = *(int **)(param_1[0x40] + 0x130), piVar3 != (int *)0x0)) {
    if (1 < bStack_de) {
      (**(code **)(*piVar3 + 0x34))
                ((float)piVar3[0xe] + pRVar2->key_scroll_object_move,
                 (float)piVar3[0xf] - pRVar2->key_scroll_object_move,0);
    }
    if (1 < bStack_dc) {
      (**(code **)(**(int **)(param_1[0x40] + 0x130) + 0x34))
                ((float)piVar3[0xe] - pRVar2->key_scroll_object_move,
                 (float)piVar3[0xf] + pRVar2->key_scroll_object_move,0);
    }
    if (1 < bStack_df) {
      (**(code **)(**(int **)(param_1[0x40] + 0x130) + 0x34))
                ((float)piVar3[0xe] - pRVar2->key_scroll_object_move,
                 (float)piVar3[0xf] - pRVar2->key_scroll_object_move,0);
    }
    bVar9 = 1 < bStack_df || (1 < bStack_dc || 1 < bStack_de);
    if (1 < bStack_dd) {
      (**(code **)(**(int **)(param_1[0x40] + 0x130) + 0x34))
                ((float)piVar3[0xe] + pRVar2->key_scroll_object_move,
                 (float)piVar3[0xf] + pRVar2->key_scroll_object_move,0);
      bVar9 = true;
    }
    goto LAB_0053e214;
  }
  if (param_1[0x40] == 0) goto LAB_0053e214;
  if (bStack_df < 2) {
    if (1 < bStack_dd) {
      sVar12 = 1;
    }
  }
  else {
    sVar12 = -1;
  }
  if (bStack_de < 2) {
    if (1 < bStack_dc) {
      sVar5 = 1;
    }
  }
  else {
    sVar5 = -1;
  }
  if ((sVar12 == 0) && (sVar5 == 0)) goto LAB_0053e214;
  uVar7 = debug_timeGetTime(s_C__msdev_work_age1_x1_vw_main_cp,0x153);
  if (param_1[0xde] == 0) {
    fVar10 = (float10)_DAT_00577900;
    param_1[0xde] = 1;
  }
  else {
    iVar6 = __ftol();
    fVar1 = _DAT_00577904;
    if (extraout_ST0 - (float10)iVar6 < (float10)_DAT_00577904) {
      fVar1 = _DAT_00577908;
    }
    fVar10 = (float10)fVar1 + (float10)iVar6;
  }
  if ((float10)pRVar2->key_scroll_max_dist < fVar10) {
    fVar10 = (float10)pRVar2->key_scroll_max_dist;
  }
  if (fVar10 <= (float10)_DAT_00577908) goto LAB_0053e214;
  fVar1 = (float)(fVar10 + fVar10);
  if (sVar12 == -1) {
    pRVar8 = (RGE_Player *)param_1[0x40];
    fVar11 = (float10)pRVar8->view_y - fVar10;
    fVar10 = (float10)pRVar8->view_x - fVar10;
LAB_0053e19b:
    RGE_Player::set_view_loc(pRVar8,(float)fVar10,(float)fVar11);
  }
  else if (sVar12 == 1) {
    pRVar8 = (RGE_Player *)param_1[0x40];
    fVar11 = (float10)pRVar8->view_y + fVar10;
    fVar10 = (float10)pRVar8->view_x + fVar10;
    goto LAB_0053e19b;
  }
  if (sVar5 == -1) {
    pRVar8 = (RGE_Player *)param_1[0x40];
    fVar4 = pRVar8->view_y - fVar1;
    fVar1 = pRVar8->view_x + fVar1;
LAB_0053e1f7:
    RGE_Player::set_view_loc(pRVar8,fVar1,fVar4);
  }
  else if (sVar5 == 1) {
    pRVar8 = (RGE_Player *)param_1[0x40];
    fVar4 = pRVar8->view_y + fVar1;
    fVar1 = pRVar8->view_x - fVar1;
    goto LAB_0053e1f7;
  }
  param_1[0xdd] = uVar7;
  bVar9 = true;
LAB_0053e214:
  if ((sVar12 == 0) && (sVar5 == 0)) {
    param_1[0xde] = 0;
  }
  if (bVar9 != false) {
    (**(code **)(*param_1 + 0x20))(1);
    if ((int *)param_1[0xd8] != (int *)0x0) {
      (**(code **)(*(int *)param_1[0xd8] + 0x20))(1);
    }
  }
  return bVar9;
}

// --------------------------------------------------

// Function: FUN_0053e274
// Address: 0053e274
// [HELPER] s_C__msdev_work_age1_x1_vw_main_cp: "C:\msdev\work\age1_x1\vw_main.cpp"
long __thiscall
FUN_0053e274(TPanel *param_1,uchar param_2,long param_3,long param_4,int param_5,int param_6)
{
  ulong uVar1;
  long lVar2;
  ulong uVar3;
  
  uVar1 = debug_timeGetTime(s_C__msdev_work_age1_x1_vw_main_cp,0x1ae);
  lVar2 = TPanel::handle_mouse_up(param_1,param_2,param_3,param_4,param_5,param_6);
  uVar3 = debug_timeGetTime(s_C__msdev_work_age1_x1_vw_main_cp,0x1b0);
  RGE_Base_Game::add_to_timing(rge_base_game,0xd,uVar3 - uVar1);
  return lVar2;
}

// --------------------------------------------------

// Function: FUN_0053e2e3
// Address: 0053e2e3
undefined4 __fastcall FUN_0053e2e3(int *param_1)
{
  int iVar1;
  
  iVar1 = rge_base_game->prog_mode;
  if ((((iVar1 != 4) && (iVar1 != 6)) && (iVar1 != 7)) && (iVar1 != 5)) {
    return 0;
  }
  iVar1 = rge_base_game->game_mode;
  if ((iVar1 == 1) || ((6 < iVar1 && (iVar1 < 9)))) {
    (**(code **)(*param_1 + 0x20))(1);
  }
  return 1;
}

// --------------------------------------------------

// Function: FUN_0053e339
// Address: 0053e339
undefined4 __thiscall
FUN_0053e339(RGE_Main_View *param_1,long param_2,long param_3,undefined4 param_4,undefined4 param_5)
{
  int *piVar1;
  uchar uVar2;
  int iVar3;
  RGE_Player *pRVar4;
  undefined4 unaff_ESI;
  undefined4 unaff_retaddr;
  undefined4 uStack_24;
  undefined4 uStack_20;
  int iStack_1c;
  undefined4 uStack_18;
  RGE_Pick_Info RStack_14;
  
  iVar3 = RGE_Base_Game::get_paused(rge_base_game);
  if ((iVar3 == 0) &&
     ((((iVar3 = rge_base_game->prog_mode, iVar3 == 4 || (iVar3 == 6)) || (iVar3 == 7)) ||
      (iVar3 == 5)))) {
    iVar3 = rge_base_game->game_mode;
    color_log('L',0xba,1);
    switch(iVar3) {
    case 1:
      uVar2 = RGE_Main_View::pick1
                        (param_1,'(','\0',param_2,param_3,&RStack_14,(RGE_Static_Object *)0x0,1);
      if (uVar2 == '3') {
        RGE_Main_View::fixup_pick_info(param_1,&RStack_14);
        iVar3 = (int)rge_base_game->master_obj_id;
        if (iVar3 != -1) {
          piVar1 = *(int **)(*(int *)(param_1->_padding_ + 0x24) + iVar3 * 4);
          if (piVar1 == (int *)0x0) {
            if (iVar3 != -1) {
              piVar1 = *(int **)(*(int *)(**(int **)(param_1->_padding_ + 0x40) + 0x24) + iVar3 * 4)
              ;
              if (piVar1 != (int *)0x0) {
                (**(code **)(*piVar1 + 0x24))(&RStack_14,&RStack_14.y,param_1->_padding_,0);
                (**(code **)(*(int *)**(undefined4 **)(param_1->_padding_ + 0x40) + 0xb0))
                          (iVar3,uStack_24,uStack_20,0);
              }
            }
          }
          else {
            (**(code **)(*piVar1 + 0x24))(&RStack_14,&RStack_14.y,param_1->_padding_,0);
            (**(code **)(*(int *)param_1->_padding_ + 0xb0))(iVar3,uStack_24,uStack_20,0);
          }
        }
      }
      break;
    case 2:
    case 3:
    case 0x11:
      if (((RGE_Player *)param_1->_padding_)->selected_obj != (RGE_Static_Object *)0x0) {
        RGE_Player::unselect_object((RGE_Player *)param_1->_padding_);
        (**(code **)(param_1->_padding_ + 0x20))(1);
      }
    case 0x15:
      (**(code **)(param_1->_padding_ + 0xe8))(3,param_2,param_3,param_4,param_5);
      break;
    default:
      TPanel::capture_mouse((TPanel *)param_1);
      break;
    case 9:
    case 10:
    case 0x13:
      if (((RGE_Player *)param_1->_padding_)->selected_obj != (RGE_Static_Object *)0x0) {
        RGE_Player::unselect_object((RGE_Player *)param_1->_padding_);
        (**(code **)(param_1->_padding_ + 0x20))(1);
      }
      if (iVar3 == 0x13) {
        (**(code **)(rge_base_game->_padding_ + 0x10))(0x13,0);
      }
      (**(code **)(param_1->_padding_ + 0xe8))(9,param_2,param_3,param_4,param_5);
      break;
    case 0xf:
      uVar2 = RGE_Main_View::pick1
                        (param_1,')','\0',param_2,param_3,&RStack_14,
                         *(RGE_Static_Object **)(param_1->_padding_ + 0x130),1);
      if ((uVar2 == '4') && ((RStack_14.object)->master_obj->object_group != 0x22)) {
        if ((RStack_14.object)->sprite_list == (RGE_Active_Sprite_List *)0x0) {
          if ((RStack_14.object)->sprite == (RGE_Sprite *)0x0) {
            uVar2 = '\x14';
          }
          else {
            uVar2 = RGE_Sprite::get_lowest_draw_level((RStack_14.object)->sprite);
          }
        }
        else {
          uVar2 = RGE_Active_Sprite_List::get_lowest_draw_level((RStack_14.object)->sprite_list);
        }
        pRVar4 = RGE_Base_Game::get_player(rge_base_game);
        param_1->save_player = pRVar4;
        (**(code **)(rge_base_game->_padding_ + 0x14))
                  (CONCAT22((short)((uint)(RStack_14.object)->owner >> 0x10),
                            (RStack_14.object)->owner->id));
        rge_base_game->master_obj_id = *(short *)(*(int *)(RStack_14._8_4_ + 8) + 0x10);
        param_1->_padding_ = RStack_14._8_4_;
        *(undefined1 *)(RStack_14._8_4_ + 0x48) = 7;
        if (uVar2 == '\0') {
          (**(code **)(param_1->_padding_ + 0x20))(2);
        }
        (**(code **)(rge_base_game->_padding_ + 0x10))(8,1);
        if (((RGE_Static_Object *)param_1->_padding_)->sprite != (RGE_Sprite *)0x0) {
          RGE_Static_Object::get_frame
                    ((RGE_Static_Object *)param_1->_padding_,(short *)&stack0xffffffd0,
                     (short *)&stack0xffffffd2,(short *)&stack0xffffffd6,(short *)&stack0xffffffd4);
          uStack_24 = (int)uStack_18._2_2_ - (int)(short)((uint)unaff_ESI >> 0x10);
          if (*(char *)(*(int *)param_1->_padding_ + 0x479) == '\x01') {
            ClientToScreen(((int *)param_1->_padding_)[1],&stack0xffffffd8);
          }
        }
        (**(code **)(param_1->_padding_ + 0xe8))(9,param_2,param_3,unaff_retaddr,param_2);
      }
      break;
    case 0x12:
      uVar2 = RGE_Main_View::pick1
                        (param_1,')','\0',param_2,param_3,&RStack_14,
                         *(RGE_Static_Object **)(param_1->_padding_ + 0x130),1);
      if (uVar2 == '4') {
        RGE_Player::unselect_object((RGE_Player *)param_1->_padding_);
        RGE_Player::select_one_object((RGE_Player *)param_1->_padding_,RStack_14.object,1);
        iVar3 = param_1->_padding_;
        (**(code **)(iVar3 + 0x20))(1);
        if ((RStack_14.object)->sprite != (RGE_Sprite *)0x0) {
          RGE_Static_Object::get_frame
                    (RStack_14.object,(short *)&uStack_24,(short *)((int)&uStack_24 + 2),
                     (short *)((int)&uStack_20 + 2),(short *)&uStack_20);
          iStack_1c = (int)RStack_14.scr_x - (int)(short)uStack_24;
          uStack_18 = (int)RStack_14.scr_y - (int)uStack_24._2_2_;
          if (*(char *)(*(int *)param_1->_padding_ + 0x479) == '\x01') {
            ClientToScreen(((int *)param_1->_padding_)[1],&iStack_1c);
          }
          if (*(char *)(*(int *)param_1->_padding_ + 0x479) == '\x01') {
            ScreenToClient(((int *)param_1->_padding_)[1],&iStack_1c);
          }
          (**(code **)(iVar3 + 0xe8))(4,iStack_1c,uStack_18,param_4,param_5);
        }
      }
    }
    color_log('L','_',1);
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0053e7b3
// Address: 0053e7b3
undefined4 __fastcall
FUN_0053e7b3(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)
{
  char cVar1;
  byte bVar2;
  undefined4 uVar3;
  byte *pbVar4;
  int iVar5;
  byte bVar6;
  int *piVar7;
  TPanel *this;
  byte *pbVar8;
  byte *unaff_EBX;
  int unaff_EDI;
  undefined4 unaff_retaddr;
  
  pbVar8 = (byte *)CONCAT22((short)((uint)param_2 >> 0x10),CONCAT11(0xe4,(char)param_2));
  bVar6 = (byte)param_1;
  uVar3 = in(0x53);
  *(char *)(unaff_EDI + 0x380053e5) = *(char *)(unaff_EDI + 0x380053e5) + (char)unaff_EBX;
  out(0x53,(char)uVar3);
  piVar7 = (int *)CONCAT22((short)((uint)param_1 >> 0x10),
                           CONCAT11((char)((uint)param_1 >> 8) + -0x38,bVar6));
  in(0x53);
  pbVar8[-0x60ffac1d] = pbVar8[-0x60ffac1d] - 0x1c;
  pbVar4 = (byte *)in(0x53);
  *unaff_EBX = *unaff_EBX + (char)param_2;
  bVar2 = (byte)pbVar4;
  out(0x53,bVar2);
  unaff_EBX[0x53e7] = unaff_EBX[0x53e7] + bVar2;
  *piVar7 = (int)(pbVar4 + *piVar7);
  *pbVar4 = *pbVar4 | bVar6;
  *pbVar4 = *pbVar4 | bVar6;
  *pbVar8 = *pbVar8 | bVar2;
  this = (TPanel *)CONCAT31((int3)((uint)piVar7 >> 8),bVar6 + *pbVar4);
  *pbVar4 = *pbVar4 | bVar6 + *pbVar4;
  *unaff_EBX = *unaff_EBX | bVar2;
  pbVar4[-0x6ff8f7fa] = pbVar4[-0x6ff8f7fa] | bVar2;
  iVar5 = rge_base_game->prog_mode;
  if ((((iVar5 != 4) && (iVar5 != 6)) && (iVar5 != 7)) && (iVar5 != 5)) {
    return 0;
  }
  iVar5 = RGE_Base_Game::get_paused(rge_base_game);
  cVar1 = (char)this[1].tab_stop;
  if (iVar5 == 0) {
    if (cVar1 != '\0') {
      (**(code **)(this->_padding_ + 0xec))(unaff_retaddr,param_3);
      return 1;
    }
    switch(rge_base_game->game_mode) {
    case 0:
      TPanel::release_mouse(this);
      iVar5 = this->_padding_;
      (**(code **)(iVar5 + 0xe8))(2,this->mouse_down_x,this->mouse_down_y,param_4,param_5);
      (**(code **)(iVar5 + 0xec))(param_4,param_5);
      return 1;
    case 1:
    case 7:
    case 8:
      (**(code **)(this->_padding_ + 0x20))(1);
    }
    return 1;
  }
  if (cVar1 != '\0') {
    (**(code **)(this->_padding_ + 0xf0))();
    return 0;
  }
  TPanel::release_mouse(this);
  return 0;
}

// --------------------------------------------------

// Function: FUN_0053e8e9
// Address: 0053e8e9
/* WARNING: Control flow encountered bad instruction data */

void FUN_0053e8e9(void)
{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

// --------------------------------------------------

// Function: FUN_0053f2e9
// Address: 0053f2e9
undefined4 __thiscall
FUN_0053f2e9(TPanel *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)
{
  char cVar1;
  int iVar2;
  
  iVar2 = rge_base_game->prog_mode;
  if ((((iVar2 == 4) || (iVar2 == 6)) || (iVar2 == 7)) || (iVar2 == 5)) {
    iVar2 = RGE_Base_Game::get_paused(rge_base_game);
    cVar1 = (char)param_1[1].tab_stop;
    if (iVar2 != 0) {
      if (cVar1 != '\0') {
        (**(code **)(param_1->_padding_ + 0xf0))();
        return 0;
      }
      TPanel::release_mouse(param_1);
      return 0;
    }
    if (cVar1 != '\0') {
      (**(code **)(param_1->_padding_ + 0xec))(param_2,param_3);
      return 1;
    }
    if (*(short *)(param_1[1].pnl_x + 0x19c) == 0) {
      TPanel::release_mouse(param_1);
      iVar2 = param_1->_padding_;
      (**(code **)(iVar2 + 0xe8))(1,param_1->mouse_down_x,param_1->mouse_down_y,param_4,param_5);
      (**(code **)(iVar2 + 0xec))(param_4,param_5);
      return 1;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0053f3ca
// Address: 0053f3ca
undefined4 __thiscall
FUN_0053f3ca(RGE_Main_View *param_1,int param_2,int param_3,undefined4 param_4,int param_5)
{
  char cVar1;
  uchar uVar2;
  int iVar3;
  RGE_Static_Object **ppRStack_18;
  RGE_Pick_Info RStack_14;
  
  iVar3 = rge_base_game->prog_mode;
  if ((((iVar3 != 4) && (iVar3 != 6)) && (iVar3 != 7)) && (iVar3 != 5)) {
    return 0;
  }
  color_log('L','2',1);
  if ((char)param_1->_padding_ == '\0') {
    TPanel::release_mouse((TPanel *)param_1);
    if (rge_base_game->game_mode == 0x14) {
      uVar2 = RGE_Main_View::pick1
                        (param_1,')','\x02',param_2,param_3,&RStack_14,
                         *(RGE_Static_Object **)(param_1->_padding_ + 0x130),1);
      if (uVar2 == '4') {
        (**(code **)((RStack_14.object)->_padding_ + 0x78))(0xffffffff);
      }
    }
    else {
      iVar3 = RGE_Base_Game::get_paused(rge_base_game);
      if ((iVar3 != 0) || ((cVar1 = (char)param_1->_padding_, cVar1 != '\x01' && (cVar1 != '\x02')))
         ) {
        color_log('L','_',1);
        return 0;
      }
      iVar3 = rge_base_game->prog_mode;
      if (rge_base_game->prog_info->interface_style == 2) {
        if ((iVar3 == 5) || (iVar3 == 7)) goto LAB_0053f63b;
        if (rge_base_game->game_mode != 0) {
          if (rge_base_game->game_mode == 0x15) {
            RGE_View::set_selection_area((RGE_View *)param_1,-1,-1,-1,-1);
            (**(code **)(param_1->_padding_ + 0x20))(1);
          }
          (**(code **)(rge_base_game->_padding_ + 0x10))(0,0);
          goto LAB_0053f63b;
        }
        if (param_5 == 0) {
          (**(code **)(param_1->_padding_ + 0x100))(param_2,param_3,1,0xffffffff);
          goto LAB_0053f63b;
        }
        uVar2 = RGE_Player::get_selected_objects_to_command
                          ((RGE_Player *)param_1->_padding_,&ppRStack_18,(short *)&param_5,-1,-1,-1,
                           -1);
        if (uVar2 == '\0') goto LAB_0053f63b;
        free(ppRStack_18);
        if (allow_user_commands == 0) goto LAB_0053f63b;
        uVar2 = RGE_Main_View::pick1
                          (param_1,'(','\0',param_2,param_3,&RStack_14,(RGE_Static_Object *)0x0,1);
        if (uVar2 != '3') goto LAB_0053f63b;
        RGE_Main_View::fixup_pick_info(param_1,&RStack_14);
        (**(code **)(*(int *)param_1->_padding_ + 0xd8))(RStack_14.x,RStack_14.y,0x3f800000);
        RGE_Main_View::reset_display_object_selection(param_1,2);
        RGE_View::add_overlay_sprite
                  ((RGE_View *)param_1,rge_base_game->shapes[1],0,param_1->_padding_ + param_2,
                   param_1->_padding_ + param_3,0,0xf,(uchar *)0x0,1,0xfa);
      }
      else {
        if (iVar3 == 7) goto LAB_0053f63b;
        if (rge_base_game->game_mode != 0) {
          (**(code **)(rge_base_game->_padding_ + 0x10))(0,0);
          goto LAB_0053f63b;
        }
        RGE_Player::unselect_object((RGE_Player *)param_1->_padding_);
      }
      (**(code **)(param_1->_padding_ + 0x20))(1);
    }
  }
  else {
    (**(code **)(param_1->_padding_ + 0xf0))();
  }
LAB_0053f63b:
  color_log('L','_',1);
  return 1;
}

// --------------------------------------------------

// Function: FUN_0053f657
// Address: 0053f657
undefined4 __thiscall
FUN_0053f657(RGE_View *param_1,uchar param_2,long param_3,long param_4,int param_5,int param_6)
{
  int iVar1;
  
  iVar1 = RGE_View::start_scroll_view(param_1,param_2,param_3,param_4,param_5,param_6);
  if (iVar1 != 0) {
    if ((int *)param_1[1]._padding_ != (int *)0x0) {
      (**(code **)(*(int *)param_1[1]._padding_ + 0x20))(1);
    }
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0053f6a7
// Address: 0053f6a7
undefined4 __thiscall FUN_0053f6a7(RGE_View *param_1,long param_2,long param_3)
{
  int iVar1;
  
  iVar1 = RGE_View::handle_scroll_view(param_1,param_2,param_3);
  if (iVar1 != 0) {
    if ((int *)param_1[1]._padding_ != (int *)0x0) {
      (**(code **)(*(int *)param_1[1]._padding_ + 0x20))(1);
    }
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0053f6e8
// Address: 0053f6e8
// [HELPER] s_: ""
// [HELPER] s_C__msdev_work_age1_x1_vw_main_cp: "C:\msdev\work\age1_x1\vw_main.cpp"
void __fastcall FUN_0053f6e8(RGE_View *param_1)
{
  int iVar1;
  ulong uVar2;
  ulong uVar3;
  ulong uVar4;
  ulong uVar5;
  
  uVar2 = debug_timeGetTime(s_C__msdev_work_age1_x1_vw_main_cp,0x522);
  uVar3 = RGE_Base_Game::get_accum_time(rge_base_game,0xb);
  if ((param_1->world == (RGE_Game_World *)0x0) || (param_1->player == (RGE_Player *)0x0)) {
    iVar1 = param_1->_padding_;
    (**(code **)(iVar1 + 0x28))(0);
    TDrawArea::Clear((TDrawArea *)param_1->_padding_,(tagRECT *)&param_1->_padding_,
                     (uint)*(byte *)((int)&param_1->_padding_ + 3));
    (**(code **)(iVar1 + 0x2c))();
  }
  else {
    if (do_draw_log != 0) {
      write_draw_log2(s_<vs>);
    }
    color_log('L','L',1);
    RGE_View::draw(param_1);
    color_log('L','_',1);
    if (do_draw_log != 0) {
      write_draw_log2(s_<vf>_);
    }
  }
  uVar4 = RGE_Base_Game::get_accum_time(rge_base_game,0xb);
  uVar5 = debug_timeGetTime(s_C__msdev_work_age1_x1_vw_main_cp,0x542);
  RGE_Base_Game::add_to_timing(rge_base_game,6,(uVar5 - uVar2) - (uVar4 - uVar3));
  RGE_Base_Game::increment_view_update_count(rge_base_game);
  RGE_Base_Game::add_to_timing(rge_base_game,0xc,uVar4 - uVar3);
  return;
}

// --------------------------------------------------

// Function: FUN_0053f7f4
// Address: 0053f7f4
void FUN_0053f7f4(void)
{
  return;
}

// --------------------------------------------------

// Function: FUN_0053f801
// Address: 0053f801
undefined4 __thiscall FUN_0053f801(RGE_Main_View *param_1,long param_2,long param_3)
{
  RGE_Master_Static_Object *pRVar1;
  int iVar2;
  uchar uVar3;
  char cVar4;
  RGE_Player *pRVar5;
  int *piVar6;
  uint uVar7;
  int iVar8;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  int iVar13;
  undefined4 uVar14;
  RGE_Pick_Info RStack_14;
  
  if ((allow_user_commands != 0) &&
     (uVar3 = RGE_Main_View::pick1
                        (param_1,'(','\0',param_2,param_3,&RStack_14,(RGE_Static_Object *)0x0,1),
     uVar3 == '3')) {
    RGE_Main_View::fixup_pick_info(param_1,&RStack_14);
    iVar8 = (int)rge_base_game->master_obj_id;
    if ((iVar8 != -1) &&
       (pRVar5 = RGE_Base_Game::get_player(rge_base_game),
       pRVar5->master_objects[iVar8] != (RGE_Master_Static_Object *)0x0)) {
      pRVar5 = RGE_Base_Game::get_player(rge_base_game);
      pRVar1 = pRVar5->master_objects[iVar8];
      iVar2 = pRVar1->_padding_;
      (**(code **)(iVar2 + 0x24))
                (&RStack_14,&RStack_14.y,param_1->_padding_,rge_base_game->sub_game_mode != 3);
      uVar7 = (uint)pRVar1->elevation_flag;
      uVar14 = 1;
      iVar13 = 1;
      uVar12 = 1;
      uVar11 = 0;
      uVar10 = 1;
      uVar9 = 0;
      pRVar5 = RGE_Base_Game::get_player(rge_base_game);
      cVar4 = (**(code **)(iVar2 + 0x20))
                        (pRVar5,unaff_EDI,unaff_ESI,uVar9,uVar10,uVar7,uVar11,uVar12,iVar13,uVar14);
      if (cVar4 == '\0') {
        if (rge_base_game->game_mode == 1) {
          pRVar5 = RGE_Base_Game::get_player(rge_base_game);
          cVar4 = (**(code **)(pRVar5->_padding_ + 0xb0))(iVar8,uVar10,uVar7,0);
          if (cVar4 != '\0') {
            if (iVar13 == 0) {
              return 1;
            }
            (**(code **)(rge_base_game->_padding_ + 0x10))(0,0);
            return 1;
          }
        }
        else if (rge_base_game->game_mode == 8) {
          if (rge_base_game->sub_game_mode == 1) {
            piVar6 = (int *)param_1->_padding_;
            (**(code **)(*piVar6 + 0x34))(uVar10,uVar7,0);
          }
          else {
            pRVar5 = RGE_Base_Game::get_player(rge_base_game);
            piVar6 = (int *)(**(code **)(pRVar5->_padding_ + 0x94))(iVar8,uVar10,uVar7,0,1);
          }
          if (piVar6 != (int *)0x0) {
            if ((RGE_Active_Sprite_List *)piVar6[6] == (RGE_Active_Sprite_List *)0x0) {
              if ((RGE_Sprite *)piVar6[4] == (RGE_Sprite *)0x0) {
                uVar3 = '\x14';
              }
              else {
                uVar3 = RGE_Sprite::get_lowest_draw_level((RGE_Sprite *)piVar6[4]);
              }
            }
            else {
              uVar3 = RGE_Active_Sprite_List::get_lowest_draw_level
                                ((RGE_Active_Sprite_List *)piVar6[6]);
            }
            if (uVar3 != '\0') {
              (**(code **)(param_1->_padding_ + 0x20))(1);
              return 1;
            }
            (**(code **)(param_1->_padding_ + 0x20))(2);
            return 1;
          }
        }
      }
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_0053fbc8
// Address: 0053fbc8
uchar __thiscall
FUN_0053fbc8(RGE_Main_View *param_1,char param_2,byte param_3,int param_4,
            RGE_Pick_Obj_Info **param_5,RGE_Pick_Info *param_6,RGE_Static_Object *param_7,
            int param_8)
{
  RGE_Static_Object *pRVar1;
  bool bVar2;
  uchar uVar3;
  RGE_Static_Object *pRVar4;
  int iVar5;
  short sVar6;
  short sVar7;
  RGE_Pick_Obj_Info **ppRVar8;
  int iVar9;
  int iVar10;
  
  if (param_2 != ')') {
    if (param_2 == '*') {
      uVar3 = RGE_Main_View::pick1(param_1,')',param_3,param_4,(long)param_5,param_6,param_7,1);
      if (uVar3 == '4') {
        return uVar3;
      }
    }
    uVar3 = RGE_View::pick((RGE_View *)param_1,'(',param_3,param_4,(long)param_5,param_6,param_7);
    return uVar3;
  }
  param_6->x = 0.0;
  param_6->y = 0.0;
  param_6->scr_x = 0;
  param_6->scr_y = 0;
  param_6->object = (RGE_Static_Object *)0x0;
  param_6->tile = (RGE_Tile *)0x0;
  if (param_3 == 0) {
    iVar10 = 0x28;
    iVar9 = 0;
  }
  else {
    iVar10 = 0x14;
    iVar9 = 10;
  }
  iVar9 = RGE_View::pick_objects((RGE_View *)param_1,param_4,(int)param_5,iVar9,iVar10,0xf,4,1);
  if (iVar9 == 0) {
    return '2';
  }
  if (param_7 == (RGE_Static_Object *)0x0) {
    sVar7 = 0;
    _param_2 = (RGE_Static_Object *)0x0;
    sVar6 = 0;
    param_4 = 0;
    pRVar4 = (RGE_Static_Object *)0x0;
    if (0 < iVar9) {
      ppRVar8 = &Picked_Objects;
      param_5 = (RGE_Pick_Obj_Info **)iVar9;
      do {
        if ((((-1 < (int)*ppRVar8) &&
             (pRVar4 = *(RGE_Static_Object **)
                        (*(int *)(param_1->_padding_ + 0x88) + (int)*ppRVar8 * 4),
             pRVar4 != (RGE_Static_Object *)0x0)) && (pRVar4->object_state < 7)) &&
           (param_3 <= pRVar4->master_obj->select_level)) {
          if (((param_8 == 0) && (*(char *)(param_1->_padding_ + 0x8db8) == '\0')) &&
             (iVar9 = (**(code **)(param_1->_padding_ + 0xe0))(pRVar4), iVar9 == 0)) {
            iVar9 = __ftol();
            iVar10 = __ftol();
            uVar3 = RGE_Visible_Map::get_visible
                              (*(RGE_Visible_Map **)(param_1->_padding_ + 0x38),iVar10,iVar9);
            if (uVar3 != '\x0f') goto LAB_0053fd33;
          }
          iVar9 = (**(code **)(param_1->_padding_ + 0xe4))(pRVar4,(int)*(short *)(ppRVar8 + 1));
          if (param_4 < iVar9) {
            sVar7 = (short)param_1->_padding_ + *(short *)(ppRVar8 + 2);
            sVar6 = (short)param_1->_padding_ + *(short *)((int)ppRVar8 + 10);
            _param_2 = pRVar4;
            param_4 = iVar9;
          }
        }
LAB_0053fd33:
        ppRVar8 = ppRVar8 + 3;
        param_5 = (RGE_Pick_Obj_Info **)((int)param_5 + -1);
        pRVar4 = _param_2;
      } while (param_5 != (RGE_Pick_Obj_Info **)0x0);
    }
    if (pRVar4 != (RGE_Static_Object *)0x0) {
      param_6->object = pRVar4;
      param_6->scr_x = sVar7;
      param_6->scr_y = sVar6;
      param_6->x = pRVar4->world_x;
      param_6->y = pRVar4->world_y;
      return '4';
    }
  }
  else {
    bVar2 = false;
    _param_2 = (RGE_Static_Object *)0x0;
    param_4 = 0;
    if (iVar9 < 1) {
      sVar6 = (short)param_7;
      sVar7 = 0;
    }
    else {
      sVar7 = 0;
      param_5 = &Picked_Objects;
      pRVar4 = param_7;
      do {
        if ((((-1 < (int)*param_5) &&
             (pRVar1 = *(RGE_Static_Object **)
                        (*(int *)(param_1->_padding_ + 0x88) + (int)*param_5 * 4),
             pRVar1 != (RGE_Static_Object *)0x0)) && (pRVar1->object_state < 7)) &&
           ((param_3 <= pRVar1->master_obj->select_level &&
            (iVar10 = (**(code **)(param_1->_padding_ + 0xe4))(pRVar1,(int)*(short *)(param_5 + 1)),
            0 < iVar10)))) {
          if ((param_8 == 0) &&
             ((*(char *)(param_1->_padding_ + 0x8db8) == '\0' &&
              (iVar10 = (**(code **)(param_1->_padding_ + 0xe0))(pRVar1), iVar10 == 0)))) {
            iVar10 = __ftol();
            iVar5 = __ftol();
            uVar3 = RGE_Visible_Map::get_visible
                              (*(RGE_Visible_Map **)(param_1->_padding_ + 0x38),iVar5,iVar10);
            if (uVar3 != '\x0f') goto LAB_0053fe82;
          }
          if (pRVar1 == param_7) {
            bVar2 = true;
          }
          else {
            if (bVar2) {
              sVar7 = (&DAT_0087d4a8)[param_4 * 6] + (short)param_1->_padding_;
              sVar6 = (&DAT_0087d4aa)[param_4 * 6] + (short)param_1->_padding_;
              _param_2 = pRVar1;
              break;
            }
            if (_param_2 == (RGE_Static_Object *)0x0) {
              sVar7 = (short)param_1->_padding_ + *(short *)(param_5 + 2);
              pRVar4 = (RGE_Static_Object *)
                       (uint)(ushort)((short)param_1->_padding_ + *(short *)((int)param_5 + 10));
              _param_2 = pRVar1;
            }
          }
        }
LAB_0053fe82:
        sVar6 = (short)pRVar4;
        param_4 = param_4 + 1;
        param_5 = param_5 + 3;
      } while (param_4 < iVar9);
    }
    if ((bVar2) && (_param_2 == (RGE_Static_Object *)0x0)) {
      _param_2 = param_7;
      sVar7 = (&DAT_0087d4a8)[param_4 * 6] + (short)param_1->_padding_;
      sVar6 = (&DAT_0087d4aa)[param_4 * 6] + (short)param_1->_padding_;
    }
    if (_param_2 != (RGE_Static_Object *)0x0) {
      param_6->object = _param_2;
      param_6->scr_x = sVar7;
      param_6->scr_y = sVar6;
      param_6->x = _param_2->world_x;
      param_6->y = _param_2->world_y;
      return '4';
    }
  }
  return '2';
}

// --------------------------------------------------

// Function: FUN_0053ffa6
// Address: 0053ffa6
int __thiscall FUN_0053ffa6(RGE_View *param_1,long param_2,long param_3,int *param_4,int param_5)
{
  uchar uVar1;
  RGE_Static_Object *pRVar2;
  int iVar3;
  int *piVar4;
  RGE_Pick_Info RStack_14;
  
  iVar3 = 0;
  pRVar2 = (RGE_Static_Object *)0x0;
  piVar4 = param_4;
  while( true ) {
    if (iVar3 == param_5) {
      return iVar3;
    }
    uVar1 = RGE_View::pick(param_1,')','\0',param_2,param_3,&RStack_14,pRVar2);
    if (uVar1 != '4') break;
    if ((0 < iVar3) && (RStack_14.object == (RGE_Static_Object *)*param_4)) {
      return iVar3;
    }
    *piVar4 = (int)RStack_14.object;
    iVar3 = iVar3 + 1;
    piVar4 = piVar4 + 1;
    pRVar2 = RStack_14.object;
  }
  return iVar3;
}

// --------------------------------------------------

// Function: FUN_0054000a
// Address: 0054000a
RGE_Static_Object * __thiscall
FUN_0054000a(RGE_View *param_1,int param_2,int param_3,undefined4 *param_4,short param_5)
{
  RGE_Master_Static_Object *pRVar1;
  uchar uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  RGE_Player *pRVar6;
  int iVar7;
  RGE_Static_Object *pRVar8;
  uint uVar9;
  int iVar10;
  undefined4 *puVar11;
  int *piVar12;
  RGE_Pick_Obj_Info **ppRVar13;
  short *psStack_224;
  short sStack_21e;
  RGE_View *pRStack_21c;
  RGE_Static_Object **ppRStack_218;
  int iStack_214;
  int iStack_210;
  uint uStack_20c;
  RGE_Master_Static_Object *pRStack_208;
  int iStack_204;
  int aiStack_200 [64];
  undefined4 auStack_100 [64];
  
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = 0;
  }
  pRStack_21c = param_1;
  uVar3 = RGE_View::pick_objects(param_1,param_2,param_3,10,0x14,0xf,4,1);
  if (uVar3 == 0) {
    return (RGE_Static_Object *)0x0;
  }
  uStack_20c = uVar3;
  uVar2 = RGE_Player::get_selected_objects_to_command
                    (param_1->player,&ppRStack_218,&sStack_21e,-1,-1,-1,-1);
  if (uVar2 == '\0') {
    return (RGE_Static_Object *)0x0;
  }
  if (0 < (int)uVar3) {
    puVar11 = auStack_100;
    for (uVar9 = uVar3 & 0x3fffffff; uVar9 != 0; uVar9 = uVar9 - 1) {
      *puVar11 = 0;
      puVar11 = puVar11 + 1;
    }
    piVar12 = aiStack_200;
    for (uVar9 = uVar3 & 0x3fffffff; uVar9 != 0; uVar9 = uVar9 - 1) {
      *piVar12 = 0;
      piVar12 = piVar12 + 1;
    }
  }
  iStack_214 = 0;
  if (0 < sStack_21e) {
    do {
      iStack_210 = 0;
      pRStack_208 = ppRStack_218[iStack_214]->master_obj;
      if (0 < (int)uVar3) {
        psStack_224 = &DAT_0087d4a4;
        do {
          pRVar1 = pRStack_208;
          if (((-1 < *(int *)(psStack_224 + -2)) &&
              (pRVar8 = param_1->world->objectsValue[*(int *)(psStack_224 + -2)],
              pRVar8 != (RGE_Static_Object *)0x0)) && (pRVar8->object_state < 7)) {
            iVar4 = (**(code **)(*(int *)(pRStack_208[1].undead_sprite)->pict_name + 4))
                              (ppRStack_218[iStack_214],pRVar8,0,0,0);
            if (iVar4 != 0) {
              if ((param_5 != -1) && (*(short *)(iVar4 + 6) != param_5)) {
                iVar4 = 0;
              }
              if (iVar4 != 0) {
                iStack_204 = iStack_210 * 4;
                iVar5 = (**(code **)(param_1->_padding_ + 0xe4))(pRVar8,(int)*psStack_224);
                uVar3 = uStack_20c;
                iVar10 = *(int *)(pRVar1[1].undead_sprite)->pict_name;
                *(int *)((int)&pRStack_208 + uStack_20c) =
                     *(int *)((int)&pRStack_208 + uStack_20c) + iVar5;
                iVar4 = (**(code **)(iVar10 + 8))(iVar4);
joined_r0x005401ac:
                if (iVar4 != 0) {
                  *(undefined4 *)((int)auStack_100 + uVar3) = 1;
                }
                goto LAB_005402a9;
              }
            }
            if (*(char *)&pRVar1[1].radius_y != '\0') {
              iVar4 = 0;
              pRVar6 = pRStack_21c->player;
              if (0 < pRVar6->master_object_num) {
                do {
                  pRVar1 = pRVar6->master_objects[iVar4];
                  if (((pRVar1 != (RGE_Master_Static_Object *)0x0) &&
                      (pRVar1->object_group == pRStack_208->object_group)) &&
                     ((pRVar1->master_type == pRStack_208->master_type &&
                      ((*(char *)&pRVar1[1].radius_y == *(char *)&pRStack_208[1].radius_y &&
                       (iVar5 = (**(code **)(*(int *)(pRVar1[1].undead_sprite)->pict_name + 4))
                                          (ppRStack_218[iStack_214],pRVar8,0,0,0),
                       iVar10 = iStack_210, iVar5 != 0)))))) {
                    if ((param_5 != -1) && (*(short *)(iVar5 + 6) != param_5)) {
                      iVar5 = 0;
                    }
                    if (iVar5 != 0) {
                      uVar3 = iStack_210 * 4;
                      iVar7 = (**(code **)(pRStack_21c->_padding_ + 0xe4))(pRVar8,(int)*psStack_224)
                      ;
                      iVar4 = *(int *)(pRVar1[1].undead_sprite)->pict_name;
                      (&pRStack_208)[iVar10] =
                           (RGE_Master_Static_Object *)
                           ((int)(&pRStack_208)[iVar10]->attribute_type_held + iVar7 + -0x6a);
                      iVar4 = (**(code **)(iVar4 + 8))(iVar5);
                      goto joined_r0x005401ac;
                    }
                  }
                  iVar4 = iVar4 + 1;
                  pRVar6 = pRStack_21c->player;
                } while (iVar4 < pRVar6->master_object_num);
              }
            }
          }
LAB_005402a9:
          iStack_210 = iStack_210 + 1;
          psStack_224 = psStack_224 + 6;
          param_1 = pRStack_21c;
          uVar3 = uStack_20c;
        } while (iStack_210 < (int)uStack_20c);
      }
      iStack_214 = iStack_214 + 1;
    } while (iStack_214 < sStack_21e);
  }
  free(ppRStack_218);
  iVar4 = 0;
  pRVar8 = (RGE_Static_Object *)0x0;
  iVar10 = 0;
  if (0 < (int)uVar3) {
    ppRVar13 = &Picked_Objects;
    do {
      iVar5 = aiStack_200[iVar10];
      if ((iVar4 < iVar5) &&
         (pRVar8 = param_1->world->objectsValue[(int)*ppRVar13], iVar4 = iVar5,
         param_4 != (undefined4 *)0x0)) {
        *param_4 = auStack_100[iVar10];
        uVar3 = uStack_20c;
      }
      iVar10 = iVar10 + 1;
      ppRVar13 = ppRVar13 + 3;
    } while (iVar10 < (int)uVar3);
  }
  return pRVar8;
}

// --------------------------------------------------

// Function: FUN_00540347
// Address: 00540347
undefined1 __thiscall FUN_00540347(RGE_Main_View *param_1,long param_2,long param_3)
{
  uchar uVar1;
  undefined1 uVar2;
  short sStack_1a;
  RGE_Static_Object **ppRStack_18;
  RGE_Pick_Info RStack_14;
  
  if (allow_user_commands != 0) {
    uVar1 = RGE_Player::get_selected_objects_to_command
                      ((RGE_Player *)param_1->_padding_,&ppRStack_18,&sStack_1a,-1,-1,-1,-1);
    if (uVar1 != '\0') {
      free(ppRStack_18);
      uVar2 = 0;
      uVar1 = RGE_Main_View::pick1
                        (param_1,'*','\x01',param_2,param_3,&RStack_14,(RGE_Static_Object *)0x0,1);
      if (uVar1 != '2') {
        RGE_Main_View::fixup_pick_info(param_1,&RStack_14);
        uVar2 = (**(code **)(*(int *)param_1->_padding_ + 0xa0))
                          (RStack_14.object,RStack_14.x,RStack_14.y);
        (**(code **)(param_1->_padding_ + 0x20))(1);
      }
      (**(code **)(rge_base_game->_padding_ + 0x10))(0,0);
      return uVar2;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: FUN_00540415
// Address: 00540415
char __thiscall FUN_00540415(RGE_Main_View *param_1,int param_2,int param_3)
{
  uchar uVar1;
  char cVar2;
  RGE_Static_Object *pRVar3;
  short sStack_1e;
  RGE_Static_Object **ppRStack_1c;
  int iStack_18;
  RGE_Pick_Info RStack_14;
  
  if (allow_user_commands != 0) {
    uVar1 = RGE_Player::get_selected_objects_to_command
                      ((RGE_Player *)param_1->_padding_,&ppRStack_1c,&sStack_1e,-1,-1,-1,-1);
    if (uVar1 != '\0') {
      free(ppRStack_1c);
      pRVar3 = RGE_Main_View::pick_best_target(param_1,param_2,param_3,&iStack_18,-1);
      if (pRVar3 != (RGE_Static_Object *)0x0) {
        cVar2 = (**(code **)(*(int *)param_1->_padding_ + 0xa4))
                          (pRVar3,pRVar3->world_x,pRVar3->world_y);
        if (cVar2 != '\0') {
          RGE_View::display_object_selection((RGE_View *)param_1,pRVar3->id,0x5dc,2,2);
        }
        RGE_View::reset_overlay_sprites((RGE_View *)param_1);
        (**(code **)(param_1->_padding_ + 0x20))(1);
        (**(code **)(rge_base_game->_padding_ + 0x10))(0,0);
        return cVar2;
      }
      uVar1 = RGE_Main_View::pick1
                        (param_1,'(','\0',param_2,param_3,&RStack_14,(RGE_Static_Object *)0x0,1);
      if (uVar1 == '3') {
        RGE_Main_View::fixup_pick_info(param_1,&RStack_14);
        cVar2 = (**(code **)(*(int *)param_1->_padding_ + 0xa4))(0,RStack_14.x,RStack_14.y);
        if (cVar2 != '\0') {
          RGE_Main_View::reset_display_object_selection(param_1,2);
          RGE_View::add_overlay_sprite
                    ((RGE_View *)param_1,rge_base_game->shapes[2],0,param_1->_padding_ + param_2,
                     param_1->_padding_ + param_3,0,0xf,(uchar *)0x0,2,0x5a);
        }
        (**(code **)(param_1->_padding_ + 0x20))(1);
        (**(code **)(rge_base_game->_padding_ + 0x10))(0,0);
        return cVar2;
      }
      RGE_View::reset_overlay_sprites((RGE_View *)param_1);
      (**(code **)(param_1->_padding_ + 0x20))(1);
      (**(code **)(rge_base_game->_padding_ + 0x10))(0,0);
    }
  }
  return '\0';
}

// --------------------------------------------------

// Function: FUN_005405bc
// Address: 005405bc
undefined4 __fastcall FUN_005405bc(RGE_View *param_1)
{
  RGE_View::set_selection_area(param_1,-1,-1,-1,-1);
  (**(code **)(param_1->_padding_ + 0x20))(1);
  return 0;
}

// --------------------------------------------------

// Function: FUN_005405df
// Address: 005405df
uchar __thiscall
FUN_005405df(RGE_Main_View *param_1,char **param_2,long *param_3,long param_4,long param_5)
{
  char cVar1;
  uchar uVar2;
  long lVar3;
  char *pcVar4;
  uint uVar5;
  uint uVar6;
  char *pcVar7;
  RGE_Pick_Info RStack_14;
  
  uVar2 = RGE_Main_View::pick1
                    (param_1,')','\x02',param_4,param_5,&RStack_14,(RGE_Static_Object *)0x0,1);
  if (uVar2 != '4') {
    uVar2 = TPanel::get_help_info((TPanel *)param_1,param_2,param_3,param_4,param_5);
    return uVar2;
  }
  lVar3 = RGE_Master_Static_Object::get_help_message((RStack_14.object)->master_obj);
  pcVar4 = TPanel::get_string((TPanel *)param_1,lVar3);
  uVar5 = 0xffffffff;
  do {
    pcVar7 = pcVar4;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    pcVar7 = pcVar4 + 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar7;
  } while (cVar1 != '\0');
  uVar5 = ~uVar5;
  pcVar4 = pcVar7 + -uVar5;
  pcVar7 = *param_2;
  for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined4 *)pcVar7 = *(undefined4 *)pcVar4;
    pcVar4 = pcVar4 + 4;
    pcVar7 = pcVar7 + 4;
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *pcVar7 = *pcVar4;
    pcVar4 = pcVar4 + 1;
    pcVar7 = pcVar7 + 1;
  }
  lVar3 = RGE_Master_Static_Object::get_help_page((RStack_14.object)->master_obj);
  *param_3 = lVar3;
  return '\x01';
}

// --------------------------------------------------

