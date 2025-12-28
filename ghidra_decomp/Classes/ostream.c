// Class: ostream
// Size:  0x3C
//
// VTable Layout:
// [00] `scalar_deleting_destructor'
//
// Member Layout:
// [0x004] int x_floatused
// ----------------------------------------------------------------

// Function: opfx
// Address: 0055a760
int __thiscall ostream::opfx(ostream *this)
{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)this + 4);
  if (*(uint *)(&this->field_0x8 + iVar1) != 0) {
    *(uint *)(&this->field_0x8 + iVar1) = *(uint *)(&this->field_0x8 + iVar1) | 2;
    return 0;
  }
  if (*(ostream **)(&this->field_0x20 + iVar1) != (ostream *)0x0) {
    flush(*(ostream **)(&this->field_0x20 + iVar1));
  }
  return 1;
}

// --------------------------------------------------

// Function: osfx
// Address: 0055a790
void __thiscall ostream::osfx(ostream *this)
{
  int iVar1;
  
  *(undefined4 *)(&this->field_0x30 + *(int *)(*(int *)this + 4)) = 0;
  if ((*(uint *)(&this->field_0x24 + *(int *)(*(int *)this + 4)) & 0x2000) != 0) {
    iVar1 = (**(code **)(**(int **)((int)&this->x_floatused + *(int *)(*(int *)this + 4)) + 4))();
    if (iVar1 == -1) {
      *(undefined4 *)(&this->field_0x8 + *(int *)(*(int *)this + 4)) = 6;
    }
  }
  if ((*(uint *)(&this->field_0x24 + *(int *)(*(int *)this + 4)) & 0x4000) != 0) {
    iVar1 = fflush(&DAT_00591e68);
    if (iVar1 == -1) {
      *(uint *)(&this->field_0x8 + *(int *)(*(int *)this + 4)) =
           *(uint *)(&this->field_0x8 + *(int *)(*(int *)this + 4)) | 2;
    }
    iVar1 = fflush(&DAT_00591e88);
    if (iVar1 == -1) {
      *(uint *)(&this->field_0x8 + *(int *)(*(int *)this + 4)) =
           *(uint *)(&this->field_0x8 + *(int *)(*(int *)this + 4)) | 2;
    }
  }
  return;
}

// --------------------------------------------------

// Function: operator<<
// Address: 0055a830
// [HELPER] s_: ""
ostream * __thiscall ostream::operator<<(ostream *this,char *param_1)
{
  int iVar1;
  
  iVar1 = opfx(this);
  if (iVar1 != 0) {
    writepad(this,s_,param_1);
    osfx(this);
  }
  return this;
}

// --------------------------------------------------

// Function: flush
// Address: 0055a860
ostream * __thiscall ostream::flush(ostream *this)
{
  int iVar1;
  
  iVar1 = (**(code **)(**(int **)((int)&this->x_floatused + *(int *)(*(int *)this + 4)) + 4))();
  if (iVar1 == -1) {
    *(uint *)(&this->field_0x8 + *(int *)(*(int *)this + 4)) =
         *(uint *)(&this->field_0x8 + *(int *)(*(int *)this + 4)) | 2;
  }
  return this;
}

// --------------------------------------------------

// Function: ostream
// Address: 0055a890
ostream * __thiscall ostream::ostream(ostream *this)
{
  int in_stack_00000004;
  
  if (in_stack_00000004 != 0) {
    *(undefined1 **)this = &_vbtable_;
    ios::ios((ios *)&this->field_0x8);
  }
  *(undefined ***)(&this->field_0x0 + *(int *)(*(int *)this + 4)) = &_vftable_;
  this->x_floatused = 0;
  return this;
}

// --------------------------------------------------

// Function: `scalar_deleting_destructor'
// Address: 0055a8d0
void * __thiscall ostream::_scalar_deleting_destructor_(ostream *this,uint param_1)
{
  ~ostream(this);
  ios::~ios((ios *)this);
  if ((param_1 & 1) != 0) {
    operator_delete(&this[-1].field_0x34);
  }
  return &this[-1].field_0x34;
}

// --------------------------------------------------

// Function: ostream
// Address: 0055a900
ostream * __thiscall ostream::ostream(ostream *this,streambuf *param_1)
{
  undefined4 *unaff_FS_OFFSET;
  int in_stack_00000008;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00561ef6;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  if (in_stack_00000008 != 0) {
    *(undefined1 **)this = &_vbtable_;
    ios::ios((ios *)&this->field_0x8);
    local_4 = 0;
  }
  *(undefined ***)(&this->field_0x0 + *(int *)(*(int *)this + 4)) = &_vftable_;
  ios::init((ios *)(&this->field_0x0 + *(int *)(*(int *)this + 4)),param_1);
  this->x_floatused = 0;
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: ostream
// Address: 0055a990
ostream * __thiscall ostream::ostream(ostream *this,ostream *param_1)
{
  undefined4 *unaff_FS_OFFSET;
  int in_stack_00000008;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_00561f1a;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  if (in_stack_00000008 != 0) {
    *(undefined1 **)this = &_vbtable_;
    ios::ios((ios *)&this->field_0x8);
    local_4 = 0;
  }
  *(undefined ***)(&this->field_0x0 + *(int *)(*(int *)this + 4)) = &_vftable_;
  ios::init((ios *)(&this->field_0x0 + *(int *)(*(int *)this + 4)),
            *(streambuf **)((int)&param_1->x_floatused + *(int *)(*(int *)param_1 + 4)));
  this->x_floatused = 0;
  *unaff_FS_OFFSET = local_c;
  return this;
}

// --------------------------------------------------

// Function: ~ostream
// Address: 0055aa20
void __thiscall ostream::~ostream(ostream *this)
{
  *(undefined ***)(*(int *)(*(int *)&this[-1].field_0x34 + 4) + -8 + (int)this) = &_vftable_;
  return;
}

// --------------------------------------------------

// Function: operator=
// Address: 0055aa30
ostream * __thiscall ostream::operator=(ostream *this,streambuf *param_1)
{
  undefined4 *puVar1;
  ios *piVar2;
  undefined4 *unaff_FS_OFFSET;
  ios local_40;
  undefined4 uStack_c;
  code *pcStack_8;
  undefined4 uStack_4;
  
  uStack_c = *unaff_FS_OFFSET;
  uStack_4 = 0xffffffff;
  pcStack_8 = FUN_00561f38;
  *unaff_FS_OFFSET = &uStack_c;
  if ((*(int *)(&this->field_0x1c + *(int *)(*(int *)this + 4)) != 0) &&
     (puVar1 = *(undefined4 **)((int)&this->x_floatused + *(int *)(*(int *)this + 4)),
     puVar1 != (undefined4 *)0x0)) {
    (**(code **)*puVar1)(1);
  }
  *(undefined4 *)((int)&this->x_floatused + *(int *)(*(int *)this + 4)) = 0;
  piVar2 = (ios *)ios::ios(&local_40);
  uStack_4 = 0;
  ios::operator=((ios *)(&this->field_0x0 + *(int *)(*(int *)this + 4)),piVar2);
  uStack_4 = 0xffffffff;
  ios::~ios(&local_40);
  *(undefined4 *)(&this->field_0x1c + *(int *)(*(int *)this + 4)) = 0;
  ios::init((ios *)(&this->field_0x0 + *(int *)(*(int *)this + 4)),param_1);
  *unaff_FS_OFFSET = uStack_c;
  return this;
}

// --------------------------------------------------

// Function: writepad
// Address: 0055ac30
ostream * __thiscall ostream::writepad(ostream *this,char *param_1,char *param_2)
{
  char cVar1;
  byte bVar2;
  int *piVar3;
  bool bVar4;
  char *pcVar5;
  char *pcVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  char *pcVar11;
  
  pcVar5 = param_1;
  uVar8 = 0xffffffff;
  do {
    if (uVar8 == 0) break;
    uVar8 = uVar8 - 1;
    cVar1 = *param_1;
    param_1 = param_1 + 1;
  } while (cVar1 != '\0');
  iVar9 = ~uVar8 - 1;
  uVar8 = 0xffffffff;
  pcVar11 = param_2;
  do {
    if (uVar8 == 0) break;
    uVar8 = uVar8 - 1;
    cVar1 = *pcVar11;
    pcVar11 = pcVar11 + 1;
  } while (cVar1 != '\0');
  iVar10 = ~uVar8 - 1;
  if ((uint)(iVar9 + iVar10) < *(uint *)(&this->field_0x30 + *(int *)(*(int *)this + 4))) {
    param_1 = (char *)((*(uint *)(&this->field_0x30 + *(int *)(*(int *)this + 4)) - iVar10) - iVar9)
    ;
  }
  else {
    param_1 = (char *)0x0;
  }
  if ((((&this->field_0x24)[*(int *)(*(int *)this + 4)] & 10) == 0) &&
     (pcVar6 = param_1 + -1, bVar4 = 0 < (int)param_1, pcVar11 = param_1, param_1 = pcVar6, bVar4))
{
    do {
      bVar2 = (&this->field_0x2c)[*(int *)(*(int *)this + 4)];
      piVar3 = *(int **)((int)&this->x_floatused + *(int *)(*(int *)this + 4));
      if ((byte *)piVar3[7] < (byte *)piVar3[8]) {
        *(byte *)piVar3[7] = bVar2;
        uVar8 = (uint)bVar2;
        piVar3[7] = piVar3[7] + 1;
      }
      else {
        uVar8 = (**(code **)(*piVar3 + 0x1c))(bVar2);
      }
      if (uVar8 == 0xffffffff) {
        *(uint *)(&this->field_0x8 + *(int *)(*(int *)this + 4)) =
             *(uint *)(&this->field_0x8 + *(int *)(*(int *)this + 4)) | 6;
      }
      pcVar11 = pcVar11 + -1;
      param_1 = param_1 + -1;
    } while (pcVar11 != (char *)0x0);
  }
  if ((iVar9 != 0) &&
     (iVar7 = (**(code **)(**(int **)((int)&this->x_floatused + *(int *)(*(int *)this + 4)) + 0x14))
                        (pcVar5,iVar9), iVar7 != iVar9)) {
    *(uint *)(&this->field_0x8 + *(int *)(*(int *)this + 4)) =
         *(uint *)(&this->field_0x8 + *(int *)(*(int *)this + 4)) | 6;
  }
  if ((((&this->field_0x24)[*(int *)(*(int *)this + 4)] & 8) != 0) && (0 < (int)param_1)) {
    do {
      bVar2 = (&this->field_0x2c)[*(int *)(*(int *)this + 4)];
      piVar3 = *(int **)((int)&this->x_floatused + *(int *)(*(int *)this + 4));
      if ((byte *)piVar3[7] < (byte *)piVar3[8]) {
        *(byte *)piVar3[7] = bVar2;
        uVar8 = (uint)bVar2;
        piVar3[7] = piVar3[7] + 1;
      }
      else {
        uVar8 = (**(code **)(*piVar3 + 0x1c))(bVar2);
      }
      if (uVar8 == 0xffffffff) {
        *(uint *)(&this->field_0x8 + *(int *)(*(int *)this + 4)) =
             *(uint *)(&this->field_0x8 + *(int *)(*(int *)this + 4)) | 6;
      }
      param_1 = param_1 + -1;
    } while (param_1 != (char *)0x0);
  }
  iVar9 = (**(code **)(**(int **)((int)&this->x_floatused + *(int *)(*(int *)this + 4)) + 0x14))
                    (param_2,iVar10);
  if (iVar9 != iVar10) {
    *(uint *)(&this->field_0x8 + *(int *)(*(int *)this + 4)) =
         *(uint *)(&this->field_0x8 + *(int *)(*(int *)this + 4)) | 6;
  }
  if ((((&this->field_0x24)[*(int *)(*(int *)this + 4)] & 2) != 0) && (0 < iVar10)) {
    do {
      bVar2 = (&this->field_0x2c)[*(int *)(*(int *)this + 4)];
      piVar3 = *(int **)((int)&this->x_floatused + *(int *)(*(int *)this + 4));
      if ((byte *)piVar3[7] < (byte *)piVar3[8]) {
        *(byte *)piVar3[7] = bVar2;
        uVar8 = (uint)bVar2;
        piVar3[7] = piVar3[7] + 1;
      }
      else {
        uVar8 = (**(code **)(*piVar3 + 0x1c))(bVar2);
      }
      if (uVar8 == 0xffffffff) {
        *(uint *)(&this->field_0x8 + *(int *)(*(int *)this + 4)) =
             *(uint *)(&this->field_0x8 + *(int *)(*(int *)this + 4)) | 6;
      }
      iVar10 = iVar10 + -1;
    } while (iVar10 != 0);
  }
  return this;
}

// --------------------------------------------------

// Function: operator<<
// Address: 0055af00
// [HELPER] s__d: "%d"
ostream * __thiscall ostream::operator<<(ostream *this,int param_1)
{
  uint uVar1;
  byte bVar2;
  int iVar3;
  ushort local_14;
  undefined1 local_12;
  undefined1 local_11;
  undefined2 local_10;
  undefined1 local_e;
  undefined1 local_d;
  char local_c [12];
  
  local_10 = s__d;
  local_e = DAT_00584612;
  local_d = 0;
  local_14 = _s_;
  local_12 = DAT_00578052;
  local_11 = 0;
  iVar3 = opfx(this);
  if (iVar3 != 0) {
    if (param_1 != 0) {
      uVar1 = *(uint *)(&this->field_0x24 + *(int *)(*(int *)this + 4));
      if ((uVar1 & 0x60) == 0) {
        if ((0 < param_1) && ((uVar1 & 0x400) != 0)) {
          local_14 = CONCAT11(local_14._1_1_,0x2b);
        }
      }
      else {
        if ((uVar1 & 0x40) == 0) {
          local_10 = CONCAT11(0x6f,(undefined1)local_10);
        }
        else {
          bVar2 = ~(byte)(uVar1 >> 4);
          local_10 = CONCAT11(bVar2,(undefined1)local_10) & 0x20ff | 0x5800;
          local_14 = CONCAT11(bVar2,(undefined1)local_14) & 0x20ff | 0x5800;
        }
        if (((&this->field_0x24)[*(int *)(*(int *)this + 4)] & 0x80) != 0) {
          local_14 = CONCAT11(local_14._1_1_,0x30);
        }
      }
    }
    sprintf(local_c,&local_10,param_1);
    writepad(this,(char *)&local_14,local_c);
    osfx(this);
  }
  return this;
}

// --------------------------------------------------

// Function: operator<<
// Address: 0055afd0
ostream * __thiscall ostream::operator<<(ostream *this,double param_1)
{
  char cVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  uint uVar5;
  uint uVar6;
  bool bVar7;
  char local_24 [12];
  char local_18;
  char local_17 [19];
  undefined4 uStack_4;
  
  uStack_4 = 0x55afda;
  iVar2 = this->x_floatused;
  this->x_floatused = 0;
  uVar6 = (-(uint)(iVar2 != 0) & 0xfffffff7) + 0xf;
  pcVar4 = &local_18;
  if (*(uint *)(&this->field_0x28 + *(int *)(*(int *)this + 4)) < uVar6) {
    uVar6 = *(uint *)(&this->field_0x28 + *(int *)(*(int *)this + 4));
  }
  iVar2 = opfx(this);
  if (iVar2 != 0) {
    bVar7 = (*(uint *)(&this->field_0x24 + *(int *)(*(int *)this + 4)) & 0x400) != 0;
    if (bVar7) {
      local_24[0] = '+';
    }
    uVar5 = (uint)bVar7;
    if ((*(uint *)(&this->field_0x24 + *(int *)(*(int *)this + 4)) & 0x100) != 0) {
      local_24[uVar5] = '#';
      uVar5 = uVar5 + 1;
    }
    local_24[uVar5] = '\0';
    iVar3 = sprintf(local_24 + 4,"%%%s.%.0ug",local_24,uVar6);
    iVar2 = *(int *)this;
    uVar6 = *(uint *)(&this->field_0x24 + *(int *)(iVar2 + 4)) & ios::floatfield;
    if (uVar6 == 0x1000) {
      local_24[iVar3 + 3] = 'f';
    }
    else {
      if (uVar6 == 0x800) {
        local_24[iVar3 + 3] = 'e';
      }
      if ((*(uint *)(&this->field_0x24 + *(int *)(iVar2 + 4)) & 0x200) != 0) {
        cVar1 = toupper((int)local_24[iVar3 + 3]);
        local_24[iVar3 + 3] = cVar1;
      }
    }
    sprintf(&local_18,local_24 + 4,param_1);
    iVar2 = 0;
    if ((local_18 == '+') || (local_18 == '-')) {
      local_24[0] = local_18;
      iVar2 = 1;
      pcVar4 = local_17;
    }
    local_24[iVar2] = '\0';
    writepad(this,local_24,pcVar4);
    osfx(this);
  }
  return this;
}

// --------------------------------------------------

