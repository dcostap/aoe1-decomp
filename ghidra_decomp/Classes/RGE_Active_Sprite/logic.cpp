// Class: RGE_Active_Sprite
// Function: RGE_Active_Sprite
// Address: 0041ad20
/* public: __thiscall RGE_Active_Sprite::RGE_Active_Sprite(class RGE_Sprite *) */

void __thiscall RGE_Active_Sprite::RGE_Active_Sprite(RGE_Active_Sprite *this,RGE_Sprite *param_1)
{
  this->sprite = param_1;
  this->_padding_ = (int)&_vftable_;
  this->type = '\x01';
  this->offset_x = 0;
  this->offset_y = 0;
  return;
}

// --------------------------------------------------

// Function: `scalar_deleting_destructor'
// Address: 0041ad40
/* public: virtual void * __thiscall RGE_Active_Sprite::`scalar deleting destructor'(unsigned int)
    */

void * __thiscall
RGE_Active_Sprite::_scalar_deleting_destructor_(RGE_Active_Sprite *this,uint param_1)
{
  ~RGE_Active_Sprite(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: RGE_Active_Sprite
// Address: 0041ad60
/* public: __thiscall RGE_Active_Sprite::RGE_Active_Sprite(int,class RGE_Sprite * *) */

RGE_Active_Sprite * __thiscall
RGE_Active_Sprite::RGE_Active_Sprite(RGE_Active_Sprite *this,int param_1,RGE_Sprite **param_2)
{
  int iVar1;
  
  iVar1 = param_1;
  this->_padding_ = (int)&_vftable_;
  this->type = '\x01';
  rge_read(param_1,&param_1,2);
  if ((short)param_1 < 0) {
    this->sprite = (RGE_Sprite *)0x0;
  }
  else {
    this->sprite = param_2[(short)param_1];
  }
  rge_read(iVar1,&this->offset_x,4);
  rge_read(iVar1,&this->offset_y,4);
  return this;
}

// --------------------------------------------------

// Function: ~RGE_Active_Sprite
// Address: 0041add0
/* public: virtual __thiscall RGE_Active_Sprite::~RGE_Active_Sprite(void) */

void __thiscall RGE_Active_Sprite::~RGE_Active_Sprite(RGE_Active_Sprite *this)
{
  this->_padding_ = (int)&_vftable_;
  return;
}

// --------------------------------------------------

// Function: set_offset
// Address: 0041ade0
/* public: virtual void __thiscall RGE_Active_Sprite::set_offset(long,long) */

void __thiscall RGE_Active_Sprite::set_offset(RGE_Active_Sprite *this,long param_1,long param_2)
{
  this->offset_x = param_1;
  this->offset_y = param_2;
  return;
}

// --------------------------------------------------

// Function: save
// Address: 0041ae00
/* public: virtual void __thiscall RGE_Active_Sprite::save(int) */

void __thiscall RGE_Active_Sprite::save(RGE_Active_Sprite *this,int param_1)
{
  rge_write(param_1,&this->type,1);
  rge_write(param_1,&this->sprite->id,2);
  rge_write(param_1,&this->offset_x,4);
  rge_write(param_1,&this->offset_y,4);
  return;
}

// --------------------------------------------------

// Function: update
// Address: 0041ae50
/* public: virtual void __thiscall RGE_Active_Sprite::update(float,float) */

void __thiscall RGE_Active_Sprite::update(RGE_Active_Sprite *this,float param_1,float param_2)
{
  return;
}

// --------------------------------------------------

// Function: draw
// Address: 0041ae60
/* public: virtual void __thiscall RGE_Active_Sprite::draw(short,long,long,long,long,class
   RGE_Color_Table *,class TDrawArea *) */

void __thiscall
RGE_Active_Sprite::draw
          (RGE_Active_Sprite *this,short param_1,long param_2,long param_3,long param_4,long param_5
          ,RGE_Color_Table *param_6,TDrawArea *param_7)
{
  RGE_Sprite::draw(this->sprite,(int)param_1,0,param_2 + this->offset_x,param_3 + this->offset_y,
                   param_4 + this->offset_x,param_5 + this->offset_y,param_6,param_7,'\0');
  return;
}

// --------------------------------------------------

// Function: normal_draw
// Address: 0041aeb0
/* public: virtual void __thiscall RGE_Active_Sprite::normal_draw(short,long,long,class
   RGE_Color_Table *,class TDrawArea *) */

void __thiscall
RGE_Active_Sprite::normal_draw
          (RGE_Active_Sprite *this,short param_1,long param_2,long param_3,RGE_Color_Table *param_4,
          TDrawArea *param_5)
{
  RGE_Sprite::normal_draw
            (this->sprite,(int)param_1,0,this->offset_x + param_2,this->offset_y + param_3,param_4,
             param_5);
  return;
}

// --------------------------------------------------

// Function: shadow_draw
// Address: 0041aef0
/* public: virtual void __thiscall RGE_Active_Sprite::shadow_draw(short,long,long,class
   RGE_Color_Table *,class TDrawArea *,unsigned char) */

void __thiscall
RGE_Active_Sprite::shadow_draw
          (RGE_Active_Sprite *this,short param_1,long param_2,long param_3,RGE_Color_Table *param_4,
          TDrawArea *param_5,uchar param_6)
{
  RGE_Sprite::shadow_draw
            (this->sprite,(int)param_1,0,this->offset_x + param_2,this->offset_y + param_3,param_4,
             param_5,param_6);
  return;
}

// --------------------------------------------------

// Function: what_frame
// Address: 0041af30
/* public: virtual short __thiscall RGE_Active_Sprite::what_frame(void) */

short __thiscall RGE_Active_Sprite::what_frame(RGE_Active_Sprite *this)
{
  return 0;
}

// --------------------------------------------------

// Function: set_frame
// Address: 0041af40
/* public: virtual void __thiscall RGE_Active_Sprite::set_frame(short) */

void __thiscall RGE_Active_Sprite::set_frame(RGE_Active_Sprite *this,short param_1)
{
  return;
}

// --------------------------------------------------

// Function: is_animating
// Address: 0041af50
/* public: virtual unsigned char __thiscall RGE_Active_Sprite::is_animating(void) */

uchar __thiscall RGE_Active_Sprite::is_animating(RGE_Active_Sprite *this)
{
  return '\0';
}

// --------------------------------------------------

// Function: frame_passed
// Address: 0041af60
/* public: virtual unsigned char __thiscall RGE_Active_Sprite::frame_passed(short) */

uchar __thiscall RGE_Active_Sprite::frame_passed(RGE_Active_Sprite *this,short param_1)
{
  return '\0';
}

// --------------------------------------------------

// Function: looped
// Address: 0041af70
/* public: virtual unsigned char __thiscall RGE_Active_Sprite::looped(void) */

uchar __thiscall RGE_Active_Sprite::looped(RGE_Active_Sprite *this)
{
  return '\0';
}

// --------------------------------------------------

// Function: get_facetindex
// Address: 0041af80
/* WARNING: Variable defined which should be unmapped: facet_index */
/* public: virtual short __thiscall RGE_Active_Sprite::get_facetindex(short) */

short __thiscall RGE_Active_Sprite::get_facetindex(RGE_Active_Sprite *this,short param_1)
{
  long facet_index;
  long local_4;
  
  local_4 = 0;
  RGE_Sprite::get_facetindex(this->sprite,(int)param_1,0,&local_4);
  return (short)local_4;
}

// --------------------------------------------------

// Function: get_frame
// Address: 0041afb0
/* public: virtual unsigned char __thiscall RGE_Active_Sprite::get_frame(short &,short &,short
   &,short &,long) */

uchar __thiscall
RGE_Active_Sprite::get_frame
          (RGE_Active_Sprite *this,short *param_1,short *param_2,short *param_3,short *param_4,
          long param_5)
{
  int iVar1;
  
  iVar1 = RGE_Sprite::get_frame(this->sprite,param_1,param_2,param_3,param_4,param_5,0);
  return (uchar)iVar1;
}

// --------------------------------------------------

// Function: get_lowest_draw_level
// Address: 0041afe0
/* public: unsigned char __thiscall RGE_Active_Sprite::get_lowest_draw_level(void) */

uchar __thiscall RGE_Active_Sprite::get_lowest_draw_level(RGE_Active_Sprite *this)
{
  uchar uVar1;
  
  if (this->sprite != (RGE_Sprite *)0x0) {
    uVar1 = RGE_Sprite::get_lowest_draw_level(this->sprite);
    return uVar1;
  }
  return '\x14';
}

// --------------------------------------------------

// Function: setToFirstFrame
// Address: 0041aff0
/* public: virtual void __thiscall RGE_Active_Sprite::setToFirstFrame(void) */

void __thiscall RGE_Active_Sprite::setToFirstFrame(RGE_Active_Sprite *this)
{
  return;
}

// --------------------------------------------------

// Function: check_for_shadows
// Address: 0041b000
/* public: int __thiscall RGE_Active_Sprite::check_for_shadows(void) */

int __thiscall RGE_Active_Sprite::check_for_shadows(RGE_Active_Sprite *this)
{
  int iVar1;
  
  if (this->sprite != (RGE_Sprite *)0x0) {
    iVar1 = RGE_Sprite::check_for_shadows(this->sprite);
    return iVar1;
  }
  return 0;
}

// --------------------------------------------------

