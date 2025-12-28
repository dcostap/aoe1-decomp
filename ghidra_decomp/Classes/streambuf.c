// Class: streambuf
// Size:  0x30
//
// Member Layout:
// [0x004] int _fAlloc
// [0x008] int _fUnbuf
// [0x00C] int x_lastc
// [0x010] char * _base
// [0x014] char * _ebuf
// [0x018] char * _pbase
// [0x01C] char * _pptr
// [0x020] char * _epptr
// [0x024] char * _eback
// [0x028] char * _gptr
// [0x02C] char * _egptr
// ----------------------------------------------------------------

// Function: snextc
// Address: 0055b320
int __thiscall streambuf::snextc(streambuf *this)
{
  int iVar1;
  byte *pbVar2;
  
  if (this->_fUnbuf != 0) {
    if (this->x_lastc == -1) {
      (**(code **)(this->_padding_ + 0x20))();
    }
    iVar1 = (**(code **)(this->_padding_ + 0x20))();
    this->x_lastc = iVar1;
    return iVar1;
  }
  if ((this->_egptr == (char *)0x0) || (this->_egptr <= this->_gptr)) {
    (**(code **)(this->_padding_ + 0x20))();
  }
  pbVar2 = (byte *)(this->_gptr + 1);
  this->_gptr = (char *)pbVar2;
  if (pbVar2 < this->_egptr) {
    return (uint)*pbVar2;
  }
  iVar1 = (**(code **)(this->_padding_ + 0x20))();
  return iVar1;
}

// --------------------------------------------------

// Function: sbumpc
// Address: 0055b380
int __thiscall streambuf::sbumpc(streambuf *this)
{
  byte bVar1;
  int iVar2;
  
  if (this->_fUnbuf == 0) {
    if (this->_gptr < this->_egptr) {
      bVar1 = *this->_gptr;
      this->_gptr = this->_gptr + 1;
      return (uint)bVar1;
    }
    iVar2 = (**(code **)(this->_padding_ + 0x20))();
    this->_gptr = this->_gptr + 1;
    return iVar2;
  }
  iVar2 = this->x_lastc;
  if (iVar2 == -1) {
    iVar2 = (**(code **)(this->_padding_ + 0x20))();
    return iVar2;
  }
  this->x_lastc = -1;
  return iVar2;
}

// --------------------------------------------------

// Function: stossc
// Address: 0055b3d0
void __thiscall streambuf::stossc(streambuf *this)
{
  if (this->_fUnbuf == 0) {
    if (this->_egptr <= this->_gptr) {
      (**(code **)(this->_padding_ + 0x20))();
    }
    if (this->_gptr < this->_egptr) {
      this->_gptr = this->_gptr + 1;
    }
    return;
  }
  if (this->x_lastc == -1) {
    (**(code **)(this->_padding_ + 0x20))();
    return;
  }
  this->x_lastc = -1;
  return;
}

// --------------------------------------------------

// Function: sgetc
// Address: 0055b420
int __thiscall streambuf::sgetc(streambuf *this)
{
  int iVar1;
  
  if (this->_fUnbuf != 0) {
    if (this->x_lastc == -1) {
      iVar1 = (**(code **)(this->_padding_ + 0x20))();
      this->x_lastc = iVar1;
    }
    return this->x_lastc;
  }
  iVar1 = (**(code **)(this->_padding_ + 0x20))();
  return iVar1;
}

// --------------------------------------------------

