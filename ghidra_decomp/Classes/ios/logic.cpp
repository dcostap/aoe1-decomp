// Class: ios
// Function: ios
// Address: 0055b110
/* protected: __thiscall ios::ios(void) */

void __thiscall ios::ios(ios *this)
{
  this->_padding_ = (int)&_vftable_;
  this->bp = (streambuf *)0x0;
  this->state = 4;
  this->ispecial = 0;
  this->ospecial = 0;
  this->x_tie = (ostream *)0x0;
  this->x_flags = 0;
  this->x_precision = 6;
  this->x_fill = ' ';
  this->x_width = 0;
  this->x_delbuf = 0;
  return;
}

// --------------------------------------------------

// Function: `vector_deleting_destructor'
// Address: 0055b150
/* public: virtual void * __thiscall ios::`vector deleting destructor'(unsigned int) */

void * __thiscall ios::_vector_deleting_destructor_(ios *this,uint param_1)
{
  ~ios(this);
  if ((param_1 & 1) != 0) {
    operator_delete(this);
  }
  return this;
}

// --------------------------------------------------

// Function: ios
// Address: 0055b170
/* public: __thiscall ios::ios(class streambuf *) */

void __thiscall ios::ios(ios *this,streambuf *param_1)
{
  this->bp = param_1;
  this->_padding_ = (int)&_vftable_;
  this->x_precision = 6;
  this->x_fill = ' ';
  this->state = (-(uint)(param_1 != (streambuf *)0x0) & 0xfffffffc) + 4;
  this->ispecial = 0;
  this->ospecial = 0;
  this->x_tie = (ostream *)0x0;
  this->x_flags = 0;
  this->x_width = 0;
  this->x_delbuf = 0;
  return;
}

// --------------------------------------------------

// Function: ios
// Address: 0055b1b0
/* protected: __thiscall ios::ios(class ios const &) */

ios * __thiscall ios::ios(ios *this,ios *param_1)
{
  this->bp = (streambuf *)0x0;
  this->x_delbuf = 0;
  this->_padding_ = (int)&_vftable_;
  operator=(this,param_1);
  return this;
}

// --------------------------------------------------

// Function: ~ios
// Address: 0055b1e0
/* public: virtual __thiscall ios::~ios(void) */

void __thiscall ios::~ios(ios *this)
{
  this->_padding_ = (int)&_vftable_;
  if ((this->x_delbuf != 0) && (this->bp != (streambuf *)0x0)) {
    (**(code **)this->bp->_padding_)(1);
  }
  this->bp = (streambuf *)0x0;
  this->state = 4;
  return;
}

// --------------------------------------------------

// Function: init
// Address: 0055b210
/* protected: void __thiscall ios::init(class streambuf *) */

void __thiscall ios::init(ios *this,streambuf *param_1)
{
  if ((this->x_delbuf != 0) && (this->bp != (streambuf *)0x0)) {
    (**(code **)this->bp->_padding_)(1);
  }
  this->bp = param_1;
  if (param_1 != (streambuf *)0x0) {
    this->state = this->state & 0xfffffffb;
    return;
  }
  this->state = this->state | 4;
  return;
}

// --------------------------------------------------

// Function: operator=
// Address: 0055b250
/* protected: class ios & __thiscall ios::operator=(class ios const &) */

ios * __thiscall ios::operator=(ios *this,ios *param_1)
{
  uint uVar1;
  
  this->x_tie = param_1->x_tie;
  this->x_flags = param_1->x_flags;
  this->x_precision = (int)(char)param_1->x_precision;
  this->x_fill = param_1->x_fill;
  this->x_width = (int)(char)param_1->x_width;
  uVar1 = param_1->state;
  this->state = uVar1;
  if (this->bp == (streambuf *)0x0) {
    this->state = uVar1 | 4;
  }
  return this;
}

// --------------------------------------------------

// Function: xalloc
// Address: 0055b290
/* public: static int __cdecl ios::xalloc(void) */

int __cdecl ios::xalloc(void)
{
  long *plVar1;
  int iVar2;
  int iVar3;
  
  plVar1 = (long *)operator_new(x_curindex * 4 + 8);
  if (plVar1 == (long *)0x0) {
    return -1;
  }
  iVar2 = 0;
  if (-1 < x_curindex) {
    do {
      iVar3 = iVar2 + 1;
      plVar1[iVar2] = x_statebuf[iVar2];
      iVar2 = iVar3;
    } while (iVar3 <= x_curindex);
  }
  x_curindex = x_curindex + 1;
  plVar1[x_curindex] = 0;
  if (x_statebuf != (long *)0x0) {
    operator_delete(x_statebuf);
  }
  x_statebuf = plVar1;
  return x_curindex;
}

// --------------------------------------------------

// Function: bitalloc
// Address: 0055b310
/* public: static long __cdecl ios::bitalloc(void) */

long __cdecl ios::bitalloc(void)
{
  x_maxbit = x_maxbit << 1;
  return x_maxbit;
}

// --------------------------------------------------

