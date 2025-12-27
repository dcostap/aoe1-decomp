// Class: TPicturePanel
// Function: TPicturePanel
// Address: 0047a1d0
/* public: __thiscall TPicturePanel::TPicturePanel(void) */

TPicturePanel * __thiscall TPicturePanel::TPicturePanel(TPicturePanel *this)
{
  TPanel::TPanel((TPanel *)this);
  this->keep_loaded = 1;
  this->size_from_pic = 0;
  this->own_pic = 0;
  this->pic_type = Picture;
  this->pic = (TPicture *)0x0;
  this->shape = (TShape *)0x0;
  this->_padding_ = 0;
  this->pic_name[0] = '\0';
  this->_padding_ = (int)&_vftable_;
  *(undefined1 *)((int)&this->_padding_ + 2) = 2;
  this->res_id = -1;
  return this;
}

// --------------------------------------------------

// Function: `scalar_deleting_destructor'
// Address: 0047a230
/* public: virtual void * __thiscall TPicturePanel::`scalar deleting destructor'(unsigned int) */

void * __thiscall TPicturePanel::_scalar_deleting_destructor_(TPicturePanel *this,uint param_1)
{
  ~TPicturePanel(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: ~TPicturePanel
// Address: 0047a250
/* public: virtual __thiscall TPicturePanel::~TPicturePanel(void) */

void __thiscall TPicturePanel::~TPicturePanel(TPicturePanel *this)
{
  undefined4 *unaff_FS_OFFSET;
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  pcStack_8 = FUN_0055e528;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  this->_padding_ = (int)&_vftable_;
  local_4 = 0;
  free_pic(this);
  local_4 = 0xffffffff;
  TPanel::~TPanel((TPanel *)this);
  *unaff_FS_OFFSET = local_c;
  return;
}

// --------------------------------------------------

// Function: setup
// Address: 0047a2a0
/* public: long __thiscall TPicturePanel::setup(class TDrawArea *,class TPanel
   *,long,long,long,long,char *,long,int,int) */

long __thiscall
TPicturePanel::setup
          (TPicturePanel *this,TDrawArea *param_1,TPanel *param_2,long param_3,long param_4,
          long param_5,long param_6,char *param_7,long param_8,int param_9,int param_10)
{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  
  if (param_7 == (char *)0x0) {
    this->pic_name[0] = '\0';
  }
  else {
    uVar3 = 0xffffffff;
    pcVar5 = param_7;
    do {
      pcVar6 = pcVar5;
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      pcVar6 = pcVar5 + 1;
      cVar1 = *pcVar5;
      pcVar5 = pcVar6;
    } while (cVar1 != '\0');
    uVar3 = ~uVar3;
    pcVar5 = pcVar6 + -uVar3;
    pcVar6 = this->pic_name;
    for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(undefined4 *)pcVar6 = *(undefined4 *)pcVar5;
      pcVar5 = pcVar5 + 4;
      pcVar6 = pcVar6 + 4;
    }
    for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *pcVar6 = *pcVar5;
      pcVar5 = pcVar5 + 1;
      pcVar6 = pcVar6 + 1;
    }
  }
  this->res_id = param_8;
  this->size_from_pic = param_9;
  this->keep_loaded = param_10;
  if (((param_9 != 0) || (param_10 != 0)) && (iVar2 = load_pic(this), iVar2 != 0)) {
    if (this->size_from_pic != 0) {
      if (this->pic_type == Picture) {
        param_5 = this->pic->Width;
        param_6 = this->pic->Height;
      }
      else {
        TShape::shape_bounds(this->shape,0,(short *)&param_7,(short *)&param_8);
        param_5 = (long)(short)param_7;
        param_6 = (long)(short)param_8;
      }
    }
    if (this->keep_loaded == 0) {
      free_pic(this);
    }
  }
  TPanel::setup((TPanel *)this,param_1,param_2,param_3,param_4,param_5,param_6,'\0');
  return 1;
}

// --------------------------------------------------

// Function: set_picture
// Address: 0047a3a0
/* public: void __thiscall TPicturePanel::set_picture(class TShape *,long) */

void __thiscall TPicturePanel::set_picture(TPicturePanel *this,TShape *param_1,long param_2)
{
  free_pic(this);
  this->res_id = param_2;
  this->shape = param_1;
  this->own_pic = 0;
  (**(code **)(this->_padding_ + 0x20))(1);
  return;
}

// --------------------------------------------------

// Function: load_pic
// Address: 0047a3e0
// [HELPER] s_: ""
// [HELPER] s__s_bmp: "%s.bmp"
// [HELPER] s__s_shp: "%s.shp"
/* protected: int __thiscall TPicturePanel::load_pic(void) */

int __thiscall TPicturePanel::load_pic(TPicturePanel *this)
{
  TShape *pTVar1;
  int iVar2;
  TPicture *this_00;
  undefined4 *unaff_FS_OFFSET;
  char file_name [80];
  undefined4 local_c;
  code *pcStack_8;
  undefined4 local_4;
  
  local_c = *unaff_FS_OFFSET;
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055e561;
  *unaff_FS_OFFSET = &local_c;
  free_pic(this);
  if (this->pic_name[0] == '\0') {
    if (this->res_id == -1) goto LAB_0047a59a;
    file_name._0_4_ = operator_new(0x20);
    local_4 = 1;
    if ((TShape *)file_name._0_4_ == (TShape *)0x0) {
      pTVar1 = (TShape *)0x0;
    }
    else {
      pTVar1 = (TShape *)TShape::TShape((TShape *)file_name._0_4_,s_,this->res_id);
    }
  }
  else {
    sprintf(file_name + 4,s__s_shp,this->pic_name);
    file_name._0_4_ = operator_new(0x20);
    local_4 = 0;
    if ((TShape *)file_name._0_4_ == (TShape *)0x0) {
      pTVar1 = (TShape *)0x0;
    }
    else {
      pTVar1 = (TShape *)TShape::TShape((TShape *)file_name._0_4_,file_name + 4,this->res_id);
    }
  }
  local_4 = 0xffffffff;
  this->shape = pTVar1;
  if (pTVar1 != (TShape *)0x0) {
    iVar2 = TShape::is_loaded(pTVar1);
    if (iVar2 != 0) {
      this->pic_type = Shape;
      this->own_pic = 1;
      *unaff_FS_OFFSET = local_c;
      return 1;
    }
    pTVar1 = this->shape;
    if (pTVar1 != (TShape *)0x0) {
      TShape::~TShape(pTVar1);
      operator_delete(pTVar1);
    }
    this->shape = (TShape *)0x0;
  }
  sprintf(file_name + 4,s__s_bmp,this->pic_name);
  file_name._0_4_ = operator_new(0x20);
  local_4 = 2;
  if ((TPicture *)file_name._0_4_ == (TPicture *)0x0) {
    this_00 = (TPicture *)0x0;
  }
  else {
    this_00 = (TPicture *)
              TPicture::TPicture((TPicture *)file_name._0_4_,file_name + 4,-1,0,(void *)0x0,0);
  }
  local_4 = 0xffffffff;
  this->pic = this_00;
  if (this_00 != (TPicture *)0x0) {
    if (this_00->Dib != (tagBITMAPINFOHEADER *)0x0) {
      this->pic_type = Picture;
      this->own_pic = 1;
      *unaff_FS_OFFSET = local_c;
      return 1;
    }
    TPicture::~TPicture(this_00);
    operator_delete(this_00);
    this->pic = (TPicture *)0x0;
  }
LAB_0047a59a:
  *unaff_FS_OFFSET = local_c;
  return 0;
}

// --------------------------------------------------

// Function: free_pic
// Address: 0047a5b0
/* protected: void __thiscall TPicturePanel::free_pic(void) */

void __thiscall TPicturePanel::free_pic(TPicturePanel *this)
{
  TPicture *this_00;
  TShape *this_01;
  
  this_00 = this->pic;
  if (this_00 != (TPicture *)0x0) {
    if ((this->own_pic != 0) && (this_00 != (TPicture *)0x0)) {
      TPicture::~TPicture(this_00);
      operator_delete(this_00);
    }
    this->pic = (TPicture *)0x0;
  }
  this_01 = this->shape;
  if (this_01 != (TShape *)0x0) {
    if ((this->own_pic != 0) && (this_01 != (TShape *)0x0)) {
      TShape::~TShape(this_01);
      operator_delete(this_01);
    }
    this->shape = (TShape *)0x0;
  }
  this->own_pic = 0;
  return;
}

// --------------------------------------------------

// Function: draw
// Address: 0047a630
// [HELPER] s_pnl_pic__draw: "pnl_pic::draw"
/* public: virtual void __thiscall TPicturePanel::draw(void) */

void __thiscall TPicturePanel::draw(TPicturePanel *this)
{
  int iVar1;
  uchar *puVar2;
  
  if (((this->_padding_ != 0) && (this->_padding_ != 0)) && (this->_padding_ != 0)) {
    iVar1 = this->_padding_;
    (**(code **)(iVar1 + 0x28))(0);
    if (this->keep_loaded == 0) {
      load_pic(this);
    }
    puVar2 = TDrawArea::Lock((TDrawArea *)this->_padding_,s_pnl_pic__draw,1);
    if (puVar2 != (uchar *)0x0) {
      if (this->pic_type == Picture) {
        if (this->pic != (TPicture *)0x0) {
          TPicture::Draw(this->pic,(TDrawArea *)this->_padding_,this->_padding_,this->_padding_,0,0)
          ;
        }
      }
      else if (this->shape != (TShape *)0x0) {
        TShape::shape_draw(this->shape,(TDrawArea *)this->_padding_,this->_padding_,this->_padding_,
                           0,'\0',(uchar *)0x0);
      }
      TDrawArea::Unlock((TDrawArea *)this->_padding_,s_pnl_pic__draw);
    }
    if (this->keep_loaded == 0) {
      free_pic(this);
    }
    (**(code **)(iVar1 + 0x2c))();
  }
  return;
}

// --------------------------------------------------

