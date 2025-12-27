// Class: TScreenPanel
// Function: TScreenPanel
// Address: 0047ba70
/* public: __thiscall TScreenPanel::TScreenPanel(void) */

TScreenPanel * __thiscall TScreenPanel::TScreenPanel(TScreenPanel *this)
{
  TEasy_Panel::TEasy_Panel((TEasy_Panel *)this);
  *(undefined ***)this = &_vftable_;
  return this;
}

// --------------------------------------------------

// Function: `vector_deleting_destructor'
// Address: 0047ba90
/* public: virtual void * __thiscall TScreenPanel::`vector deleting destructor'(unsigned int) */

void * __thiscall TScreenPanel::_vector_deleting_destructor_(TScreenPanel *this,uint param_1)
{
  ~TScreenPanel(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: TScreenPanel
// Address: 0047bab0
/* public: __thiscall TScreenPanel::TScreenPanel(char *) */

TScreenPanel * __thiscall TScreenPanel::TScreenPanel(TScreenPanel *this,char *param_1)
{
  TEasy_Panel::TEasy_Panel((TEasy_Panel *)this,param_1);
  *(undefined ***)this = &_vftable_;
  return this;
}

// --------------------------------------------------

// Function: ~TScreenPanel
// Address: 0047bad0
/* public: virtual __thiscall TScreenPanel::~TScreenPanel(void) */

void __thiscall TScreenPanel::~TScreenPanel(TScreenPanel *this)
{
  *(undefined ***)this = &_vftable_;
  TEasy_Panel::~TEasy_Panel((TEasy_Panel *)this);
  return;
}

// --------------------------------------------------

// Function: setup
// Address: 0047bae0
/* public: long __thiscall TScreenPanel::setup(class TDrawArea *,char *,long,int) */

long __thiscall
TScreenPanel::setup(TScreenPanel *this,TDrawArea *param_1,char *param_2,long param_3,int param_4)
{
  long lVar1;
  
  lVar1 = TEasy_Panel::setup((TEasy_Panel *)this,param_1,(TPanel *)0x0,param_2,param_3,1,0,0,0,0,
                             param_4);
  return (uint)(lVar1 != 0);
}

// --------------------------------------------------

// Function: setup
// Address: 0047bb10
/* public: long __thiscall TScreenPanel::setup(class TDrawArea *,char *,long,unsigned char,int) */

long __thiscall
TScreenPanel::setup(TScreenPanel *this,TDrawArea *param_1,char *param_2,long param_3,uchar param_4,
                   int param_5)
{
  long lVar1;
  
  lVar1 = TEasy_Panel::setup((TEasy_Panel *)this,param_1,(TPanel *)0x0,(char *)0x0,-1,1,0,0,0,0,
                             param_5);
  return (uint)(lVar1 != 0);
}

// --------------------------------------------------

// Function: draw
// Address: 0047bb40
/* public: virtual void __thiscall TScreenPanel::draw(void) */

void __thiscall TScreenPanel::draw(TScreenPanel *this)
{
  if (this->field_0xf3 != '\0') {
    if (*(int *)&this->field_0x46c != 0) {
      TEasy_Panel::setup_shadow_area((TEasy_Panel *)this,1);
    }
    this->field_0xf3 = 0;
  }
  if (this->field_0xf2 != '\0') {
    (**(code **)(*(int *)this + 0xe0))(1);
    return;
  }
  (**(code **)(*(int *)this + 0xe0))(0);
  return;
}

// --------------------------------------------------

// Function: handle_paint
// Address: 0047bb50
/* public: virtual long __thiscall TScreenPanel::handle_paint(void) */

long __thiscall TScreenPanel::handle_paint(TScreenPanel *this)
{
  TPanel::handle_paint((TPanel *)this);
  return 0;
}

// --------------------------------------------------

// Function: set_focus
// Address: 0047bb60
/* WARNING: Variable defined which should be unmapped: color */
/* public: virtual void __thiscall TScreenPanel::set_focus(int) */

void __thiscall TScreenPanel::set_focus(TScreenPanel *this,int param_1)
{
  TDrawArea *pTVar1;
  TDrawSystem *pTVar2;
  bool bVar3;
  tagPALETTEENTRY color;
  int save_focus;
  tagPALETTEENTRY color_table [256];
  
  color_table[0].peRed = this->field_0x78;
  color_table[0].peGreen = this->field_0x79;
  color_table[0].peBlue = this->field_0x7a;
  color_table[0].peFlags = this->field_0x7b;
  bVar3 = this != last_screen;
  pTVar1 = *(TDrawArea **)&this->field_0x20;
  if (((((pTVar1 != (TDrawArea *)0x0) && (pTVar2 = pTVar1->DrawSystem, pTVar2 != (TDrawSystem *)0x0)
        ) && (param_1 != 0)) && (bVar3)) &&
     ((pTVar2->ScreenMode == '\x02' || (pTVar2->DrawType == '\x01')))) {
    save_focus = save_focus & 0xff000000;
    if (*(int *)&this->field_0x20c == 0) {
      TDrawArea::GetPalette(pTVar1,color_table + 1);
    }
    else {
      GetPaletteEntries(*(int *)&this->field_0x20c,0,0x100,color_table + 1);
    }
    RGE_fade_palette(*(TDrawArea **)&this->field_0x20,(tagPALETTEENTRY)save_focus,0.13,'\x01',
                     (tagPALETTEENTRY *)0x0,-1,-1);
    TDrawArea::Clear(*(TDrawArea **)&this->field_0x20,(tagRECT *)0x0,0);
    TDrawSystem::Paint((TDrawSystem *)**(undefined4 **)&this->field_0x20,(tagRECT *)0x0);
  }
  TEasy_Panel::set_focus((TEasy_Panel *)this,param_1);
  pTVar1 = *(TDrawArea **)&this->field_0x20;
  if ((((pTVar1 != (TDrawArea *)0x0) && (pTVar2 = pTVar1->DrawSystem, pTVar2 != (TDrawSystem *)0x0))
      && ((param_1 != 0 && (bVar3)))) &&
     ((pTVar2->ScreenMode == '\x02' || (pTVar2->DrawType == '\x01')))) {
    RGE_fade_palette(pTVar1,(tagPALETTEENTRY)save_focus,0.0,'\x02',color_table + 1,-1,-1);
    (**(code **)(*(int *)this + 0x54))();
    RGE_fade_palette(*(TDrawArea **)&this->field_0x20,(tagPALETTEENTRY)save_focus,0.0,'\x01',
                     (tagPALETTEENTRY *)0x0,-1,-1);
    TDrawSystem::Paint((TDrawSystem *)**(undefined4 **)&this->field_0x20,(tagRECT *)0x0);
    RGE_fade_palette(*(TDrawArea **)&this->field_0x20,(tagPALETTEENTRY)save_focus,0.13,'\x02',
                     color_table + 1,-1,-1);
  }
  if (((tagPALETTEENTRY)param_1 != color_table[0]) && (*(int *)&this->field_0x78 != 0)) {
    last_screen = this;
  }
  return;
}

// --------------------------------------------------

