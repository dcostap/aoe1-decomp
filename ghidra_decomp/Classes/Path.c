// Class: Path
// Size:  0x34
//
// Member Layout:
// [0x000] ulong timeStampValue
// [0x004] Waypoint startValue (sz: 0x10)
// [0x014] Waypoint goalValue (sz: 0x10)
// [0x024] Waypoint * pathValue
// [0x028] int maxSizeValue
// [0x02C] int currentSizeValue
// [0x030] int currentWaypointValue
// ----------------------------------------------------------------

// Function: Path
// Address: 0046a740
/* public: __thiscall Path::Path(int) */

Path * __thiscall Path::Path(Path *this,int param_1)
{
  Waypoint *pWVar1;
  int iVar2;
  float *pfVar3;
  int iVar4;
  
  this->timeStampValue = 0;
  this->pathValue = (Waypoint *)0x0;
  this->maxSizeValue = 0;
  this->currentSizeValue = 0;
  this->currentWaypointValue = 0;
  (this->startValue).x = 0.0;
  (this->startValue).y = 0.0;
  (this->startValue).z = 0.0;
  (this->goalValue).x = 0.0;
  (this->goalValue).y = 0.0;
  (this->goalValue).z = 0.0;
  if ((param_1 == 0) || (-1 < param_1)) {
    this->maxSizeValue = param_1;
    pWVar1 = (Waypoint *)operator_new(param_1 << 4);
    iVar4 = 0;
    if (0 < this->currentSizeValue) {
      iVar2 = 0;
      pfVar3 = &pWVar1->z;
      do {
        iVar4 = iVar4 + 1;
        ((Waypoint *)(pfVar3 + -2))->x = *(float *)((int)&this->pathValue->x + iVar2);
        pfVar3[-1] = *(float *)((int)&this->pathValue->y + iVar2);
        *pfVar3 = *(float *)((int)&this->pathValue->z + iVar2);
        *(uchar *)(pfVar3 + 1) = (&this->pathValue->facetToNextWaypoint)[iVar2];
        iVar2 = iVar2 + 0x10;
        pfVar3 = pfVar3 + 4;
      } while (iVar4 < this->currentSizeValue);
    }
    if (this->pathValue != (Waypoint *)0x0) {
      operator_delete(this->pathValue);
    }
    this->pathValue = pWVar1;
  }
  return this;
}

// --------------------------------------------------

// Function: ~Path
// Address: 0046a7f0
/* public: __thiscall Path::~Path(void) */

void __thiscall Path::~Path(Path *this)
{
  if (this->pathValue != (Waypoint *)0x0) {
    operator_delete(this->pathValue);
  }
  return;
}

// --------------------------------------------------

// Function: operator+
// Address: 0046a8e0
/* public: class Path __thiscall Path::operator+(class Path const &)const  */

Path * __thiscall Path::operator+(Path *this,Path *__return_storage_ptr__,Path *param_1)
{
  int iVar1;
  Path *pPVar2;
  int iVar3;
  Path *pPVar4;
  undefined4 *unaff_FS_OFFSET;
  Path newPath;
  undefined4 local_c;
  code *pcStack_8;
  uint local_4;
  
  local_4 = 0xffffffff;
  pcStack_8 = FUN_0055e1bf;
  local_c = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = &local_c;
  iVar1 = 0;
  newPath.timeStampValue = 0;
  Path((Path *)&newPath.startValue,this->maxSizeValue + param_1->maxSizeValue);
  iVar3 = 0;
  local_4 = 1;
  if (0 < this->currentSizeValue) {
    do {
      insertAtEnd((Path *)&newPath.startValue,*(Waypoint *)((int)&this->pathValue->x + iVar1));
      iVar3 = iVar3 + 1;
      iVar1 = iVar1 + 0x10;
    } while (iVar3 < this->currentSizeValue);
  }
  iVar1 = 0;
  if (0 < param_1->currentSizeValue) {
    iVar3 = iVar3 << 4;
    do {
      insertAtEnd((Path *)&newPath.startValue,*(Waypoint *)((int)&param_1->pathValue->x + iVar3));
      iVar3 = iVar3 + 0x10;
      iVar1 = iVar1 + 1;
    } while (iVar1 < param_1->currentSizeValue);
  }
  pPVar2 = &newPath;
  pPVar4 = __return_storage_ptr__;
  for (iVar1 = 0xd; pPVar2 = (Path *)&pPVar2->startValue, iVar1 != 0; iVar1 = iVar1 + -1) {
    pPVar4->timeStampValue = (ulong)((Waypoint *)pPVar2)->x;
    pPVar4 = (Path *)&pPVar4->startValue;
  }
  newPath.timeStampValue = 1;
  local_4 = local_4 & 0xffffff00;
  ~Path((Path *)&newPath.startValue);
  *unaff_FS_OFFSET = local_c;
  return __return_storage_ptr__;
}

// --------------------------------------------------

// Function: operator=
// Address: 0046a9e0
/* public: class Path & __thiscall Path::operator=(class Path const &) */

Path * __thiscall Path::operator=(Path *this,Path *param_1)
{
  Waypoint *pWVar1;
  int iVar2;
  float *pfVar3;
  int iVar4;
  
  iVar4 = this->maxSizeValue;
  iVar2 = param_1->maxSizeValue;
  if (iVar2 <= iVar4) goto LAB_0046aa70;
  if (iVar2 == 0) {
LAB_0046aa00:
    iVar2 = iVar4;
  }
  else {
    if (iVar2 < iVar4) goto LAB_0046aa70;
    if (iVar2 == 0) goto LAB_0046aa00;
  }
  this->maxSizeValue = iVar2 + iVar4;
  pWVar1 = (Waypoint *)operator_new((iVar2 + iVar4) * 0x10);
  iVar4 = 0;
  if (0 < this->currentSizeValue) {
    iVar2 = 0;
    pfVar3 = &pWVar1->z;
    do {
      iVar4 = iVar4 + 1;
      ((Waypoint *)(pfVar3 + -2))->x = *(float *)((int)&this->pathValue->x + iVar2);
      pfVar3[-1] = *(float *)((int)&this->pathValue->y + iVar2);
      *pfVar3 = *(float *)((int)&this->pathValue->z + iVar2);
      *(uchar *)(pfVar3 + 1) = (&this->pathValue->facetToNextWaypoint)[iVar2];
      iVar2 = iVar2 + 0x10;
      pfVar3 = pfVar3 + 4;
    } while (iVar4 < this->currentSizeValue);
  }
  if (this->pathValue != (Waypoint *)0x0) {
    operator_delete(this->pathValue);
  }
  this->pathValue = pWVar1;
LAB_0046aa70:
  iVar4 = 0;
  if (0 < param_1->currentSizeValue) {
    iVar2 = 0;
    do {
      iVar4 = iVar4 + 1;
      *(undefined4 *)((int)&this->pathValue->x + iVar2) =
           *(undefined4 *)((int)&param_1->pathValue->x + iVar2);
      *(undefined4 *)((int)&this->pathValue->y + iVar2) =
           *(undefined4 *)((int)&param_1->pathValue->y + iVar2);
      *(undefined4 *)((int)&this->pathValue->z + iVar2) =
           *(undefined4 *)((int)&param_1->pathValue->z + iVar2);
      (&this->pathValue->facetToNextWaypoint)[iVar2] =
           (&param_1->pathValue->facetToNextWaypoint)[iVar2];
      iVar2 = iVar2 + 0x10;
    } while (iVar4 < param_1->currentSizeValue);
  }
  this->currentWaypointValue = param_1->currentWaypointValue;
  this->currentSizeValue = param_1->currentSizeValue;
  return this;
}

// --------------------------------------------------

// Function: operator==
// Address: 0046aae0
/* public: int __thiscall Path::operator==(class Path const &)const  */

int __thiscall Path::operator==(Path *this,Path *param_1)
{
  Waypoint *pWVar1;
  float *pfVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 0;
  if (this->currentSizeValue < 1) {
    return 1;
  }
  pWVar1 = param_1->pathValue;
  pfVar2 = &this->pathValue->z;
  iVar3 = (int)this->pathValue - (int)pWVar1;
  while( true ) {
    if ((*(float *)(iVar3 + (int)pWVar1) != pWVar1->x) || (pfVar2[-1] != pWVar1->y)) {
      return 0;
    }
    if (*pfVar2 != pWVar1->z) {
      return 0;
    }
    if (*(uchar *)(pfVar2 + 1) != pWVar1->facetToNextWaypoint) break;
    iVar4 = iVar4 + 1;
    pfVar2 = pfVar2 + 4;
    pWVar1 = pWVar1 + 1;
    if (this->currentSizeValue <= iVar4) {
      return 1;
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: insertAtCurrent
// Address: 0046ab60
/* public: int __thiscall Path::insertAtCurrent(struct Waypoint const &) */

int __thiscall Path::insertAtCurrent(Path *this,Waypoint *param_1)
{
  Waypoint *pWVar1;
  int iVar2;
  float *pfVar3;
  int iVar4;
  
  if (1000 < this->currentSizeValue) {
    return 0;
  }
  pWVar1 = (Waypoint *)operator_new((this->currentSizeValue + 1) * 0x10);
  iVar4 = 0;
  pWVar1->x = param_1->x;
  pWVar1->y = param_1->y;
  pWVar1->z = param_1->z;
  pWVar1->facetToNextWaypoint = param_1->facetToNextWaypoint;
  if (0 < this->currentSizeValue) {
    iVar2 = 0;
    pfVar3 = &pWVar1[1].y;
    do {
      iVar4 = iVar4 + 1;
      ((Waypoint *)(pfVar3 + -1))->x = *(float *)((int)&this->pathValue->x + iVar2);
      *pfVar3 = *(float *)((int)&this->pathValue->y + iVar2);
      pfVar3[1] = *(float *)((int)&this->pathValue->z + iVar2);
      *(uchar *)(pfVar3 + 2) = (&this->pathValue->facetToNextWaypoint)[iVar2];
      iVar2 = iVar2 + 0x10;
      pfVar3 = pfVar3 + 4;
    } while (iVar4 < this->currentSizeValue);
  }
  if (this->pathValue != (Waypoint *)0x0) {
    operator_delete(this->pathValue);
  }
  this->pathValue = pWVar1;
  this->currentSizeValue = this->currentSizeValue + 1;
  return 1;
}

// --------------------------------------------------

// Function: insertAtEnd
// Address: 0046ac10
/* public: int __thiscall Path::insertAtEnd(struct Waypoint) */

int __thiscall Path::insertAtEnd(Path *this,Waypoint param_1)
{
  Waypoint *pWVar1;
  int iVar2;
  float *pfVar3;
  int iVar4;
  
  iVar4 = this->maxSizeValue;
  if (this->currentSizeValue == iVar4) {
    this->maxSizeValue = iVar4 * 2;
    pWVar1 = (Waypoint *)operator_new(iVar4 << 5);
    iVar4 = 0;
    if (0 < this->currentSizeValue) {
      iVar2 = 0;
      pfVar3 = &pWVar1->z;
      do {
        iVar4 = iVar4 + 1;
        ((Waypoint *)(pfVar3 + -2))->x = *(float *)((int)&this->pathValue->x + iVar2);
        pfVar3[-1] = *(float *)((int)&this->pathValue->y + iVar2);
        *pfVar3 = *(float *)((int)&this->pathValue->z + iVar2);
        *(uchar *)(pfVar3 + 1) = (&this->pathValue->facetToNextWaypoint)[iVar2];
        iVar2 = iVar2 + 0x10;
        pfVar3 = pfVar3 + 4;
      } while (iVar4 < this->currentSizeValue);
    }
    if (this->pathValue != (Waypoint *)0x0) {
      operator_delete(this->pathValue);
    }
    this->pathValue = pWVar1;
  }
  this->pathValue[this->currentSizeValue].x = param_1.x;
  this->pathValue[this->currentSizeValue].y = param_1.y;
  this->pathValue[this->currentSizeValue].z = param_1.z;
  this->pathValue[this->currentSizeValue].facetToNextWaypoint = param_1.facetToNextWaypoint;
  this->currentSizeValue = this->currentSizeValue + 1;
  return 1;
}

// --------------------------------------------------

// Function: contains
// Address: 0046ace0
/* public: int __thiscall Path::contains(struct Waypoint const &)const  */

int __thiscall Path::contains(Path *this,Waypoint *param_1)
{
  int iVar1;
  int iVar2;
  float10 fVar3;
  float10 fVar4;
  
  iVar1 = 0;
  if (this->currentSizeValue < 1) {
    return 0;
  }
  iVar2 = 0;
  do {
    fVar3 = (float10)floor((double)*(float *)((int)&this->pathValue->x + iVar2));
    fVar4 = (float10)floor((double)param_1->x);
    if ((float10)(double)fVar3 == fVar4) {
      fVar3 = (float10)floor((double)*(float *)((int)&this->pathValue->y + iVar2));
      fVar4 = (float10)floor((double)param_1->y);
      if ((float10)(double)fVar3 == fVar4) {
        return 1;
      }
    }
    iVar1 = iVar1 + 1;
    iVar2 = iVar2 + 0x10;
  } while (iVar1 < this->currentSizeValue);
  return 0;
}

// --------------------------------------------------

// Function: killPath
// Address: 0046ada0
/* public: void __thiscall Path::killPath(void) */

void __thiscall Path::killPath(Path *this)
{
  this->currentSizeValue = 0;
  this->currentWaypointValue = 0;
  return;
}

// --------------------------------------------------

// Function: maxNumberOfWaypoints
// Address: 0046adb0
/* public: int const __thiscall Path::maxNumberOfWaypoints(void)const  */

int __thiscall Path::maxNumberOfWaypoints(Path *this)
{
  return this->maxSizeValue;
}

// --------------------------------------------------

// Function: numberOfWaypoints
// Address: 0046adc0
/* public: int const __thiscall Path::numberOfWaypoints(void)const  */

int __thiscall Path::numberOfWaypoints(Path *this)
{
  return this->currentSizeValue;
}

// --------------------------------------------------

// Function: timeStamp
// Address: 0046add0
/* public: unsigned long __thiscall Path::timeStamp(void)const  */

ulong __thiscall Path::timeStamp(Path *this)
{
  return this->timeStampValue;
}

// --------------------------------------------------

// Function: setTimeStamp
// Address: 0046ade0
/* public: void __thiscall Path::setTimeStamp(unsigned long) */

void __thiscall Path::setTimeStamp(Path *this,ulong param_1)
{
  this->timeStampValue = param_1;
  return;
}

// --------------------------------------------------

// Function: length
// Address: 0046adf0
/* public: float __thiscall Path::length(void)const  */

float __thiscall Path::length(Path *this)
{
  Waypoint *pWVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  
  fVar2 = (float)DAT_00570e40;
  if (1 < this->currentSizeValue) {
    iVar5 = this->currentSizeValue + -1;
    pWVar1 = this->pathValue;
    do {
      fVar3 = pWVar1[1].x - pWVar1->x;
      fVar4 = pWVar1[1].y - pWVar1->y;
      iVar5 = iVar5 + -1;
      fVar2 = SQRT(fVar4 * fVar4 +
                   fVar3 * fVar3 + (pWVar1[1].z - pWVar1->x) * (pWVar1[1].z - pWVar1->z)) + fVar2;
      pWVar1 = pWVar1 + 1;
    } while (iVar5 != 0);
  }
  return fVar2;
}

// --------------------------------------------------

// Function: start
// Address: 0046ae50
/* public: struct Waypoint const & __thiscall Path::start(void)const  */

Waypoint * __thiscall Path::start(Path *this)
{
  return &this->startValue;
}

// --------------------------------------------------

// Function: goal
// Address: 0046ae60
/* public: struct Waypoint const & __thiscall Path::goal(void)const  */

Waypoint * __thiscall Path::goal(Path *this)
{
  return &this->goalValue;
}

// --------------------------------------------------

// Function: waypoint
// Address: 0046ae70
/* public: struct Waypoint const * __thiscall Path::waypoint(int)const  */

Waypoint * __thiscall Path::waypoint(Path *this,int param_1)
{
  if (((this->pathValue != (Waypoint *)0x0) && (-1 < param_1)) && (param_1 < this->currentSizeValue)
     ) {
    return this->pathValue + param_1;
  }
  return (Waypoint *)0x0;
}

// --------------------------------------------------

// Function: currentWaypoint
// Address: 0046aea0
/* public: struct Waypoint * __thiscall Path::currentWaypoint(void)const  */

Waypoint * __thiscall Path::currentWaypoint(Path *this)
{
  int iVar1;
  
  if (((this->pathValue != (Waypoint *)0x0) && (iVar1 = this->currentWaypointValue, -1 < iVar1)) &&
     (iVar1 < this->currentSizeValue)) {
    return this->pathValue + iVar1;
  }
  return (Waypoint *)0x0;
}

// --------------------------------------------------

// Function: currentWaypointNumber
// Address: 0046aec0
/* public: int const __thiscall Path::currentWaypointNumber(void)const  */

int __thiscall Path::currentWaypointNumber(Path *this)
{
  return this->currentWaypointValue;
}

// --------------------------------------------------

// Function: setCurrentWaypointNumber
// Address: 0046aed0
/* public: void __thiscall Path::setCurrentWaypointNumber(int) */

void __thiscall Path::setCurrentWaypointNumber(Path *this,int param_1)
{
  this->currentWaypointValue = param_1;
  return;
}

// --------------------------------------------------

// Function: nextWaypoint
// Address: 0046aee0
/* public: struct Waypoint const * __thiscall Path::nextWaypoint(void)const  */

Waypoint * __thiscall Path::nextWaypoint(Path *this)
{
  int iVar1;
  
  if (((this->pathValue != (Waypoint *)0x0) && (-1 < this->currentWaypointValue)) &&
     (iVar1 = this->currentWaypointValue + 1, iVar1 < this->currentSizeValue)) {
    return this->pathValue + iVar1;
  }
  return (Waypoint *)0x0;
}

// --------------------------------------------------

// Function: previousWaypoint
// Address: 0046af10
/* public: struct Waypoint const * __thiscall Path::previousWaypoint(void)const  */

Waypoint * __thiscall Path::previousWaypoint(Path *this)
{
  int iVar1;
  
  if (((this->pathValue != (Waypoint *)0x0) &&
      (iVar1 = this->currentWaypointValue, iVar1 != -1 && -1 < iVar1 + 1)) &&
     (iVar1 < this->currentSizeValue)) {
    return this->pathValue + iVar1 + -1;
  }
  return (Waypoint *)0x0;
}

// --------------------------------------------------

// Function: firstWaypoint
// Address: 0046af40
/* public: struct Waypoint const * __thiscall Path::firstWaypoint(void)const  */

Waypoint * __thiscall Path::firstWaypoint(Path *this)
{
  Waypoint *pWVar1;
  
  pWVar1 = this->pathValue;
  if ((pWVar1 == (Waypoint *)0x0) || (this->currentSizeValue < 1)) {
    pWVar1 = (Waypoint *)0x0;
  }
  return pWVar1;
}

// --------------------------------------------------

// Function: lastWaypoint
// Address: 0046af60
/* public: struct Waypoint const * __thiscall Path::lastWaypoint(void)const  */

Waypoint * __thiscall Path::lastWaypoint(Path *this)
{
  if ((this->pathValue != (Waypoint *)0x0) && (0 < this->currentSizeValue)) {
    return this->pathValue + this->currentSizeValue + -1;
  }
  return (Waypoint *)0x0;
}

// --------------------------------------------------

// Function: initToStart
// Address: 0046af80
/* public: void __thiscall Path::initToStart(void) */

void __thiscall Path::initToStart(Path *this)
{
  this->currentWaypointValue = 0;
  return;
}

// --------------------------------------------------

// Function: initToEnd
// Address: 0046af90
/* public: void __thiscall Path::initToEnd(void) */

void __thiscall Path::initToEnd(Path *this)
{
  this->currentWaypointValue = this->currentSizeValue + -1;
  return;
}

// --------------------------------------------------

// Function: moveToNextWaypoint
// Address: 0046afa0
/* public: int __thiscall Path::moveToNextWaypoint(void) */

int __thiscall Path::moveToNextWaypoint(Path *this)
{
  int iVar1;
  
  iVar1 = this->currentSizeValue + -1;
  if (this->currentWaypointValue < iVar1) {
    this->currentWaypointValue = this->currentWaypointValue + 1;
    return 1;
  }
  this->currentWaypointValue = iVar1;
  return 0;
}

// --------------------------------------------------

// Function: moveToLastWaypoint
// Address: 0046afc0
/* public: int __thiscall Path::moveToLastWaypoint(void) */

int __thiscall Path::moveToLastWaypoint(Path *this)
{
  if (0 < this->currentWaypointValue) {
    this->currentWaypointValue = this->currentWaypointValue + -1;
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: distanceToNextWaypoint
// Address: 0046afe0
/* public: float __thiscall Path::distanceToNextWaypoint(void)const  */

float __thiscall Path::distanceToNextWaypoint(Path *this)
{
  Waypoint *pWVar1;
  Waypoint *pWVar2;
  int iVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  
  pWVar2 = this->pathValue;
  fVar4 = (float)DAT_00570e40;
  if (((pWVar2 != (Waypoint *)0x0) && (iVar3 = this->currentWaypointValue, -1 < iVar3)) &&
     (iVar3 < this->currentSizeValue + -1)) {
    pWVar1 = pWVar2 + iVar3;
    fVar4 = pWVar2[iVar3 + 1].x - pWVar1->x;
    fVar5 = pWVar1[1].y - pWVar1->y;
    fVar6 = pWVar1[1].z - pWVar1->z;
    fVar4 = SQRT(fVar6 * fVar6 + fVar5 * fVar5 + fVar4 * fVar4);
  }
  return fVar4;
}

// --------------------------------------------------

