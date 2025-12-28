// Class: PointMaker
// Size:  0x1058
//
// Member Layout:
// [0x000] PrimaryPt Prime (sz: 0x8)
// [0x008] PtToPt[500] Point (sz: 0xFA0)
// [0xFA8] char * Mask_2x2
// [0xFAC] char * Mask_3x3
// [0xFB0] char * Mask_4x4
// [0xFB4] char * Mask_5x5
// [0xFB8] int x
// [0xFBC] int y
// [0xFC0] int NumSplitsPerBranch
// [0xFC4] int NumberOfSatellites
// [0xFC8] int ChanceOfNextNode
// [0xFCC] int MaxNumberOfBranches
// [0xFD0] int MaxBranchFlag
// [0xFD4] int Width
// [0xFD8] int Height
// [0xFDC] int MinimumNumTiles
// [0xFE0] int NumNodes
// [0xFE4] int NumTilesActuallyChosen
// [0xFE8] int CurrentPoint
// [0xFEC] int ProbabilityTiles
// [0xFF0] int TargetProbabilityCount
// [0xFF4] int ProbabilityAdd
// [0xFF8] int BranchRadius
// [0xFFC] int SatelliteRadius
// [0x1000] int PrimaryRadius
// [0x1004] int SizeArrays
// [0x1008] int SatelliteDistance
// [0x100C] int BranchDistance
// [0x1010] int DirX
// [0x1014] int DirY
// [0x1018] int MaxNumberOfBranchLevels
// [0x101C] int CurrentNumberOfBranchLevels
// [0x1020] char * ExternalArray
// [0x1024] char * ProbArray
// [0x1028] char * PlacementArray
// [0x102C] char * WritableExternalArray
// [0x1030] int DoNotDrawOnFlag
// [0x1034] int DrawOnOnlyFlag
// [0x1038] int DrawOnlyInExternalArrayFlag
// [0x103C] int DrawToOneArrayFlag
// [0x1040] int BorderDepthPercentage
// [0x1044] int LeftLimit
// [0x1048] int RightLimit
// [0x104C] int TopLimit
// [0x1050] int BottomLimit
// [0x1054] char SpecialLandType
// ----------------------------------------------------------------

// Function: SetDefaultValues
// Address: 0044ab90
void __thiscall PointMaker::SetDefaultValues(PointMaker *this)
{
  int iVar1;
  PtToPt *pPVar2;
  
  this->NumberOfSatellites = 2;
  this->SatelliteRadius = 2;
  this->NumSplitsPerBranch = 3;
  this->Height = 0x118;
  this->Width = 0x118;
  this->BranchRadius = 3;
  this->BranchDistance = 3;
  this->ChanceOfNextNode = 0x32;
  this->MaxNumberOfBranches = 6;
  this->PrimaryRadius = 4;
  this->BorderDepthPercentage = 0xf;
  this->MaxBranchFlag = 0;
  this->SatelliteDistance = 1;
  this->MaxNumberOfBranchLevels = 0x10;
  this->MinimumNumTiles = 2000;
  pPVar2 = this->Point;
  for (iVar1 = 1000; iVar1 != 0; iVar1 = iVar1 + -1) {
    pPVar2->x = 0;
    pPVar2 = (PtToPt *)&pPVar2->y;
  }
  this->DoNotDrawOnFlag = 0;
  this->DrawOnOnlyFlag = 0;
  this->DrawToOneArrayFlag = 0;
  this->DrawOnlyInExternalArrayFlag = 0;
  return;
}

// --------------------------------------------------

// Function: PointMaker
// Address: 0044ac50
PointMaker * __thiscall PointMaker::PointMaker(PointMaker *this)
{
  this->ProbArray = (char *)0x0;
  this->PlacementArray = (char *)0x0;
  SetDefaultValues(this);
  MakeArrays(this);
  CreateMasks(this);
  return this;
}

// --------------------------------------------------

// Function: ~PointMaker
// Address: 0044ac80
void __thiscall PointMaker::~PointMaker(PointMaker *this)
{
  DeleteArrays(this);
  SetDefaultValues(this);
  this->ProbArray = (char *)0x0;
  this->PlacementArray = (char *)0x0;
  DeleteMasks(this);
  return;
}

// --------------------------------------------------

// Function: CreateMasks
// Address: 0044acb0
void __thiscall PointMaker::CreateMasks(PointMaker *this)
{
  char *pcVar1;
  int iVar2;
  char *pcVar3;
  char ptr2 [16];
  char ptr3 [25];
  char ptr4 [36];
  char ptr5 [49];
  
  pcVar1 = (char *)operator_new(0x10);
  this->Mask_2x2 = pcVar1;
  pcVar1 = (char *)operator_new(0x19);
  this->Mask_3x3 = pcVar1;
  pcVar1 = (char *)operator_new(0x24);
  this->Mask_4x4 = pcVar1;
  pcVar1 = (char *)operator_new(0x31);
  this->Mask_5x5 = pcVar1;
  ptr3[4] = '\0';
  ptr3[5] = '\0';
  ptr3[6] = '\0';
  ptr3[7] = '\0';
  ptr3[8] = '\0';
  ptr3[9] = '\0';
  ptr3[10] = '\x01';
  ptr3[0xb] = '\x01';
  ptr3[0xc] = '\x01';
  ptr3[0xd] = '\0';
  ptr3[0xe] = '\0';
  ptr3[0xf] = '\x01';
  ptr3[0x10] = '\x02';
  ptr3[0x11] = '\x01';
  ptr3[0x12] = '\0';
  ptr3[0x13] = '\0';
  ptr3[0x14] = '\x01';
  ptr3[0x15] = '\x01';
  ptr3[0x16] = '\x01';
  ptr3[0x17] = '\0';
  ptr3[0x18] = '\0';
  ptr4[0] = '\0';
  ptr4[4] = '\0';
  ptr4[5] = '\0';
  ptr4[6] = '\0';
  ptr4[7] = '\0';
  ptr4[8] = '\0';
  ptr4[9] = '\0';
  ptr4[10] = '\0';
  ptr4[0xb] = '\x01';
  ptr4[0xc] = '\x01';
  ptr4[0xd] = '\x01';
  ptr4[0xe] = '\x01';
  ptr4[0xf] = '\0';
  ptr4[0x10] = '\0';
  ptr4[0x11] = '\x01';
  ptr4[0x12] = '\x02';
  ptr4[0x13] = '\x02';
  ptr4[0x14] = '\x01';
  ptr4[0x15] = '\0';
  ptr4[0x16] = '\0';
  ptr4[0x1b] = '\0';
  ptr4[0x1c] = '\0';
  ptr4[0x21] = '\0';
  ptr4[0x22] = '\0';
  ptr4[0x23] = '\0';
  ptr5[0] = '\0';
  ptr5[1] = '\0';
  ptr5[2] = '\0';
  ptr5[3] = '\0';
  ptr5[4] = '\0';
  ptr5[5] = '\0';
  ptr5[6] = '\0';
  ptr5[7] = '\0';
  ptr5[8] = '\0';
  ptr5[9] = '\0';
  ptr5[10] = '\0';
  ptr5[0xb] = '\0';
  ptr5[0x11] = '\0';
  ptr5[0x12] = '\0';
  ptr5[0x18] = '\0';
  ptr5[0x19] = '\0';
  ptr5[0x1f] = '\0';
  ptr5[0x20] = '\0';
  ptr5[0x26] = '\0';
  ptr5[0x27] = '\0';
  ptr5[0x2d] = '\0';
  ptr5[0x2e] = '\0';
  ptr5[0x2f] = '\0';
  ptr5[0x30] = '\0';
  pcVar1 = this->Mask_2x2;
  ptr4[0x17] = '\x01';
  ptr4[0x1a] = '\x01';
  ptr4[0x1d] = '\x01';
  ptr4[0x1e] = '\x01';
  ptr4[0x1f] = '\x01';
  ptr4[0x20] = '\x01';
  ptr5[0xc] = '\x01';
  ptr5[0xd] = '\x01';
  ptr5[0xe] = '\x01';
  ptr5[0xf] = '\x01';
  ptr5[0x10] = '\x01';
  ptr5[0x13] = '\x01';
  ptr5[0x17] = '\x01';
  ptr5[0x1a] = '\x01';
  ptr5[0x1e] = '\x01';
  ptr5[0x21] = '\x01';
  ptr5[0x25] = '\x01';
  ptr5[0x28] = '\x01';
  ptr5[0x29] = '\x01';
  ptr5[0x2a] = '\x01';
  ptr5[0x2b] = '\x01';
  ptr5[0x2c] = '\x01';
  ptr4[0x18] = '\x02';
  ptr4[0x19] = '\x02';
  ptr5[0x14] = '\x02';
  ptr5[0x15] = '\x02';
  ptr5[0x16] = '\x02';
  ptr5[0x1b] = '\x02';
  ptr5[0x1d] = '\x02';
  ptr5[0x22] = '\x02';
  ptr5[0x23] = '\x02';
  ptr5[0x24] = '\x02';
  pcVar1[0] = '\0';
  pcVar1[1] = '\0';
  pcVar1[2] = '\0';
  pcVar1[3] = '\0';
  pcVar3 = ptr3;
  ptr5[0x1c] = '\x03';
  pcVar1[4] = '\0';
  pcVar1[5] = '\x01';
  pcVar1[6] = '\x01';
  pcVar1[7] = '\0';
  pcVar1[8] = '\0';
  pcVar1[9] = '\x01';
  pcVar1[10] = '\x01';
  pcVar1[0xb] = '\0';
  pcVar1[0xc] = '\0';
  pcVar1[0xd] = '\0';
  pcVar1[0xe] = '\0';
  pcVar1[0xf] = '\0';
  pcVar1 = this->Mask_3x3;
  for (iVar2 = 6; pcVar3 = pcVar3 + 4, iVar2 != 0; iVar2 = iVar2 + -1) {
    *(undefined4 *)pcVar1 = *(undefined4 *)pcVar3;
    pcVar1 = pcVar1 + 4;
  }
  *pcVar1 = *pcVar3;
  pcVar1 = ptr4;
  pcVar3 = this->Mask_4x4;
  for (iVar2 = 9; pcVar1 = pcVar1 + 4, iVar2 != 0; iVar2 = iVar2 + -1) {
    *(undefined4 *)pcVar3 = *(undefined4 *)pcVar1;
    pcVar3 = pcVar3 + 4;
  }
  pcVar1 = ptr5;
  pcVar3 = this->Mask_5x5;
  for (iVar2 = 0xc; pcVar1 = pcVar1 + 4, iVar2 != 0; iVar2 = iVar2 + -1) {
    *(undefined4 *)pcVar3 = *(undefined4 *)pcVar1;
    pcVar3 = pcVar3 + 4;
  }
  *pcVar3 = *pcVar1;
  return;
}

// --------------------------------------------------

// Function: DeleteMasks
// Address: 0044af90
void __thiscall PointMaker::DeleteMasks(PointMaker *this)
{
  operator_delete(this->Mask_2x2);
  operator_delete(this->Mask_3x3);
  operator_delete(this->Mask_4x4);
  operator_delete(this->Mask_5x5);
  return;
}

// --------------------------------------------------

// Function: DrawMask
// Address: 0044afe0
void __thiscall PointMaker::DrawMask(PointMaker *this,int param_1,int param_2,int param_3)
{
  int iVar1;
  char *pcVar2;
  char cVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int mapptr;
  int len;
  
  iVar9 = this->Width;
  if ((((param_1 <= iVar9) && (iVar5 = this->Height, param_2 <= iVar5)) &&
      (-1 < param_3 + 2 + param_1)) && (-1 < param_3 + 2 + param_2)) {
    iVar1 = param_3 + 2;
    iVar6 = param_2;
    if (param_3 == 2) {
      if ((param_1 + 4 <= iVar9) && (param_1 < 0)) {
        param_1 = 0;
      }
      iVar7 = param_1;
      if ((param_2 + 4 <= iVar5) && (param_2 < 0)) {
        iVar6 = 0;
      }
    }
    else {
      iVar7 = param_1;
      if (param_3 == 3) {
        if ((param_1 + 5 <= iVar9) && (param_1 < 0)) {
          param_1 = 0;
        }
        iVar6 = param_2 + (uint)(iVar5 < 5);
        iVar7 = param_1;
      }
    }
    if (param_3 == 4) {
      param_1 = (int)this->Mask_4x4;
      param_2 = iVar7 + 6;
      if (iVar9 < param_2) {
        param_2 = iVar9 - iVar7;
      }
      else if (iVar7 < 0) {
        param_1 = param_1 - iVar7;
        iVar7 = 0;
      }
      else {
        param_2 = 6;
      }
      iVar8 = iVar6 + 6;
      if (iVar5 < iVar8) {
        iVar8 = iVar5 - iVar6;
      }
      else if (iVar6 < 0) {
        param_1 = param_1 - iVar6 * iVar9;
        iVar6 = 0;
      }
      else {
        iVar8 = 6;
      }
    }
    else {
      param_1 = (int)this->Mask_5x5;
      param_2 = iVar7 + 7;
      if (iVar9 < param_2) {
        param_2 = iVar9 - iVar7;
      }
      else if (iVar7 < 0) {
        param_1 = param_1 - iVar7;
        iVar7 = 0;
      }
      else {
        param_2 = 7;
      }
      iVar8 = iVar6 + 7;
      if (iVar5 < iVar8) {
        iVar8 = iVar5 - iVar6;
      }
      else if (iVar6 < 0) {
        param_1 = param_1 - iVar6 * iVar9;
        iVar6 = 0;
      }
      else {
        iVar8 = 7;
      }
    }
    iVar7 = iVar6 * iVar9 + iVar7;
    for (; iVar8 != 0; iVar8 = iVar8 + -1) {
      if (0 < param_2) {
        iVar9 = iVar7;
        param_3 = param_2;
        do {
          cVar3 = *(char *)((param_1 - iVar7) + iVar9);
          if ((0 < iVar9) && (iVar9 < this->SizeArrays + -1)) {
            cVar4 = this->ProbArray[iVar9];
            pcVar2 = this->ProbArray + iVar9;
            if (cVar4 == '\0') {
              *pcVar2 = cVar3;
              this->ProbabilityTiles = this->ProbabilityTiles + 1;
            }
            else if ((int)cVar3 + (int)cVar4 < 0xff) {
              *pcVar2 = cVar3 + cVar4;
            }
            else {
              *pcVar2 = -1;
            }
          }
          iVar9 = iVar9 + 1;
          param_3 = param_3 + -1;
        } while (param_3 != 0);
      }
      param_1 = param_1 + iVar1;
      iVar7 = iVar7 + this->Width;
    }
  }
  return;
}

// --------------------------------------------------

// Function: ClearArrays
// Address: 0044b210
void __thiscall PointMaker::ClearArrays(PointMaker *this)
{
  uint uVar1;
  uint uVar2;
  char *pcVar3;
  
  if ((this->DrawToOneArrayFlag == 0) && (this->PlacementArray != (char *)0x0)) {
    uVar2 = this->SizeArrays;
    pcVar3 = this->PlacementArray;
    for (uVar1 = uVar2 >> 2; uVar1 != 0; uVar1 = uVar1 - 1) {
      pcVar3[0] = '\0';
      pcVar3[1] = '\0';
      pcVar3[2] = '\0';
      pcVar3[3] = '\0';
      pcVar3 = pcVar3 + 4;
    }
    for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
      *pcVar3 = '\0';
      pcVar3 = pcVar3 + 1;
    }
  }
  if (this->ProbArray != (char *)0x0) {
    uVar2 = this->SizeArrays;
    pcVar3 = this->ProbArray;
    for (uVar1 = uVar2 >> 2; uVar1 != 0; uVar1 = uVar1 - 1) {
      pcVar3[0] = '\0';
      pcVar3[1] = '\0';
      pcVar3[2] = '\0';
      pcVar3[3] = '\0';
      pcVar3 = pcVar3 + 4;
    }
    for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
      *pcVar3 = '\0';
      pcVar3 = pcVar3 + 1;
    }
  }
  return;
}

// --------------------------------------------------

// Function: DeleteArrays
// Address: 0044b270
void __thiscall PointMaker::DeleteArrays(PointMaker *this)
{
  if (this->ProbArray != (char *)0x0) {
    operator_delete(this->ProbArray);
  }
  if (this->PlacementArray != (char *)0x0) {
    operator_delete(this->PlacementArray);
  }
  this->ProbArray = (char *)0x0;
  this->PlacementArray = (char *)0x0;
  return;
}

// --------------------------------------------------

// Function: MakeArrays
// Address: 0044b2b0
void __thiscall PointMaker::MakeArrays(PointMaker *this)
{
  char *pcVar1;
  int iVar2;
  bool bVar3;
  
  this->SizeArrays = this->Height * this->Width;
  iVar2 = 9;
  do {
    if (this->ProbArray != (char *)0x0) break;
    pcVar1 = (char *)operator_new(this->SizeArrays);
    this->ProbArray = pcVar1;
    bVar3 = iVar2 != 0;
    iVar2 = iVar2 + -1;
  } while (bVar3);
  iVar2 = 9;
  do {
    if (this->PlacementArray != (char *)0x0) {
      return;
    }
    pcVar1 = (char *)operator_new(this->SizeArrays);
    this->PlacementArray = pcVar1;
    bVar3 = iVar2 != 0;
    iVar2 = iVar2 + -1;
  } while (bVar3);
  return;
}

// --------------------------------------------------

// Function: CreateShape
// Address: 0044b320
// [HELPER] s_C__msdev_work_age1_x1_fractal_cp: "C:\msdev\work\age1_x1\fractal.cpp"
int __thiscall PointMaker::CreateShape(PointMaker *this)
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  this->NumNodes = 0;
  ClearArrays(this);
  PrepareLimits(this);
  iVar3 = this->LeftLimit;
  iVar2 = debug_rand(s_C__msdev_work_age1_x1_fractal_cp,0xd7);
  iVar1 = this->TopLimit;
  this->x = iVar2 % ((this->Width * (0x32 - iVar3) * 2) / 100) + iVar3;
  iVar2 = debug_rand(s_C__msdev_work_age1_x1_fractal_cp,0xd8);
  iVar3 = this->Height;
  this->ProbabilityTiles = 0;
  this->NumNodes = 0;
  (this->Prime).x = this->x;
  iVar1 = iVar2 % ((iVar3 * (0x32 - iVar1) * 2) / 100) + iVar1;
  this->y = iVar1;
  (this->Prime).y = iVar1;
  DrawPrimaryIntoProbabilityArray(this);
  ErrorCheckingAndCorrection(this);
  iVar1 = this->MinimumNumTiles;
  iVar3 = this->ProbabilityTiles;
  this->NumTilesActuallyChosen = 0;
  iVar2 = 0;
  while ((iVar3 < iVar1 && (iVar2 < 0x5dc))) {
    iVar3 = (this->Prime).x;
    this->y = (this->Prime).y;
    this->x = iVar3;
    this->CurrentNumberOfBranchLevels = this->MaxNumberOfBranchLevels;
    this->NumNodes = 0;
    iVar3 = MakeFirstLink(this);
    Branch(this,iVar3);
    iVar3 = this->ProbabilityTiles;
    iVar2 = iVar2 + 1;
  }
  CreateMapBasedOnProbabilityArray(this);
  MapCleanUpEliminatingSinglesOnly(this);
  return this->ProbabilityTiles;
}

// --------------------------------------------------

// Function: CreateShape
// Address: 0044b470
int __thiscall PointMaker::CreateShape(PointMaker *this,int param_1,int param_2)
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  this->NumNodes = 0;
  ClearArrays(this);
  PrepareLimits(this);
  this->y = param_2;
  (this->Prime).y = param_2;
  this->ProbabilityTiles = 0;
  this->NumNodes = 0;
  this->x = param_1;
  (this->Prime).x = param_1;
  DrawPrimaryIntoProbabilityArray(this);
  ErrorCheckingAndCorrection(this);
  iVar1 = this->MinimumNumTiles;
  iVar3 = this->ProbabilityTiles;
  this->NumTilesActuallyChosen = 0;
  iVar2 = 0;
  while ((iVar3 < iVar1 && (iVar2 < 0x5dc))) {
    iVar3 = (this->Prime).y;
    this->x = (this->Prime).x;
    this->y = iVar3;
    this->CurrentNumberOfBranchLevels = this->MaxNumberOfBranchLevels;
    this->NumNodes = 0;
    iVar3 = MakeFirstLink(this);
    Branch(this,iVar3);
    iVar3 = this->ProbabilityTiles;
    iVar2 = iVar2 + 1;
  }
  CreateMapBasedOnProbabilityArray(this);
  MapCleanUpEliminatingSinglesOnly(this);
  return this->ProbabilityTiles;
}

// --------------------------------------------------

// Function: Branch
// Address: 0044b540
// [HELPER] s_C__msdev_work_age1_x1_fractal_cp: "C:\msdev\work\age1_x1\fractal.cpp"
void __thiscall PointMaker::Branch(PointMaker *this,int param_1)
{
  int iVar1;
  int iVar2;
  
  if (((1 < this->CurrentNumberOfBranchLevels) &&
      (iVar1 = debug_rand(s_C__msdev_work_age1_x1_fractal_cp,0x116),
      iVar1 % 100 < this->ChanceOfNextNode * 10)) &&
     (SBORROW4(this->ProbabilityTiles,this->MinimumNumTiles * 2) !=
      this->ProbabilityTiles + this->MinimumNumTiles * -2 < 0)) {
    iVar1 = 0;
    this->CurrentNumberOfBranchLevels = this->CurrentNumberOfBranchLevels + -1;
    if (0 < this->NumSplitsPerBranch) {
      do {
        this->x = this->Point[param_1].x;
        this->y = this->Point[param_1].y;
        iVar2 = MakeNewLink(this);
        DrawCurrentBranchIntoProbArray(this,iVar2);
        Branch(this,iVar2);
        iVar1 = iVar1 + 1;
      } while (iVar1 < this->NumSplitsPerBranch);
    }
  }
  iVar1 = 0;
  if (0 < this->NumberOfSatellites) {
    do {
      iVar2 = MakeSatelliteLink(this);
      DrawCurrentSatelliteIntoProbArray(this,iVar2);
      iVar1 = iVar1 + 1;
    } while (iVar1 < this->NumberOfSatellites);
  }
  return;
}

// --------------------------------------------------

// Function: MakeFirstLink
// Address: 0044b610
// [HELPER] s_C__msdev_work_age1_x1_fractal_cp: "C:\msdev\work\age1_x1\fractal.cpp"
int __thiscall PointMaker::MakeFirstLink(PointMaker *this)
{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  
  iVar2 = debug_rand(s_C__msdev_work_age1_x1_fractal_cp,0x134);
  iVar2 = iVar2 % this->BranchDistance + 2;
  uVar3 = debug_rand(s_C__msdev_work_age1_x1_fractal_cp,0x134);
  uVar7 = (int)uVar3 >> 0x1f;
  if (((uVar3 ^ uVar7) - uVar7 & 1 ^ uVar7) != uVar7) {
    iVar2 = -iVar2;
  }
  iVar4 = debug_rand(s_C__msdev_work_age1_x1_fractal_cp,0x135);
  iVar4 = iVar4 % this->BranchDistance + 2;
  uVar3 = debug_rand(s_C__msdev_work_age1_x1_fractal_cp,0x135);
  uVar7 = (int)uVar3 >> 0x1f;
  if (((uVar3 ^ uVar7) - uVar7 & 1 ^ uVar7) != uVar7) {
    iVar4 = -iVar4;
  }
  this->DirX = iVar2;
  iVar5 = iVar2 + this->x;
  iVar6 = iVar4 + this->y;
  iVar1 = this->LeftLimit;
  this->DirY = iVar4;
  if ((iVar5 < iVar1) && (iVar5 = iVar1, iVar2 < 0)) {
    this->DirX = -iVar2;
  }
  iVar2 = this->TopLimit;
  if ((iVar6 < iVar2) && (iVar6 = iVar2, iVar4 < 0)) {
    this->DirY = -iVar4;
  }
  if (this->RightLimit <= iVar5) {
    iVar5 = this->RightLimit + -1;
    if (0 < this->DirX) {
      this->DirX = -this->DirX;
    }
  }
  if (this->BottomLimit <= iVar6) {
    iVar6 = this->BottomLimit + -1;
    if (0 < this->DirY) {
      this->DirY = -this->DirY;
    }
  }
  this->y = iVar6;
  this->x = iVar5;
  this->Point[this->NumNodes].x = iVar5;
  this->Point[this->NumNodes].y = this->y;
  iVar2 = this->NumNodes;
  this->NumNodes = iVar2 + 1;
  return iVar2;
}

// --------------------------------------------------

// Function: MakeNewLink
// Address: 0044b760
// [HELPER] s_C__msdev_work_age1_x1_fractal_cp: "C:\msdev\work\age1_x1\fractal.cpp"
int __thiscall PointMaker::MakeNewLink(PointMaker *this)
{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  
  iVar2 = debug_rand(s_C__msdev_work_age1_x1_fractal_cp,0x14a);
  iVar2 = iVar2 % this->BranchDistance + 1;
  uVar3 = debug_rand(s_C__msdev_work_age1_x1_fractal_cp,0x14a);
  uVar8 = (int)uVar3 >> 0x1f;
  if (((uVar3 ^ uVar8) - uVar8 & 1 ^ uVar8) != uVar8) {
    iVar2 = -iVar2;
  }
  iVar4 = debug_rand(s_C__msdev_work_age1_x1_fractal_cp,0x14b);
  iVar4 = iVar4 % this->BranchDistance + 1;
  uVar3 = debug_rand(s_C__msdev_work_age1_x1_fractal_cp,0x14b);
  uVar8 = (int)uVar3 >> 0x1f;
  if (((uVar3 ^ uVar8) - uVar8 & 1 ^ uVar8) != uVar8) {
    iVar4 = -iVar4;
  }
  iVar6 = this->x;
  iVar2 = iVar2 + this->DirX;
  iVar4 = iVar4 + this->DirY;
  if (iVar2 + iVar6 < 5) {
    iVar2 = -iVar2;
    this->DirX = -this->DirX;
  }
  iVar5 = this->Width + -5;
  if (iVar5 <= iVar2 + iVar6) {
    iVar2 = -iVar2;
    this->DirX = -this->DirX;
  }
  iVar1 = this->y;
  if (iVar4 + iVar1 < 5) {
    iVar4 = -iVar2;
    this->DirY = -this->DirY;
  }
  iVar7 = this->Height + -5;
  if (iVar7 <= iVar4 + iVar1) {
    iVar4 = -iVar4;
  }
  iVar2 = iVar2 + iVar6;
  iVar4 = iVar4 + iVar1;
  if (iVar2 < 5) {
    iVar2 = 5;
  }
  if (iVar5 <= iVar2) {
    iVar2 = iVar5;
  }
  if (iVar4 < 5) {
    iVar4 = 5;
  }
  if (iVar7 <= iVar4) {
    iVar4 = iVar7;
  }
  uVar3 = debug_rand(s_C__msdev_work_age1_x1_fractal_cp,0x15a);
  uVar8 = (int)uVar3 >> 0x1f;
  if (((uVar3 ^ uVar8) - uVar8 & 1 ^ uVar8) != uVar8) {
    iVar6 = debug_rand(s_C__msdev_work_age1_x1_fractal_cp,0x15a);
    this->DirX = this->DirX + iVar6 % 3 + -1;
  }
  uVar3 = debug_rand(s_C__msdev_work_age1_x1_fractal_cp,0x15b);
  uVar8 = (int)uVar3 >> 0x1f;
  if (((uVar3 ^ uVar8) - uVar8 & 1 ^ uVar8) != uVar8) {
    iVar6 = debug_rand(s_C__msdev_work_age1_x1_fractal_cp,0x15b);
    this->DirY = this->DirY + iVar6 % 3 + -1;
  }
  this->x = iVar2;
  this->y = iVar4;
  this->Point[this->NumNodes].x = iVar2;
  this->Point[this->NumNodes].y = this->y;
  iVar2 = this->NumNodes;
  this->NumNodes = iVar2 + 1;
  return iVar2;
}

// --------------------------------------------------

// Function: MakeSatelliteLink
// Address: 0044b950
// [HELPER] s_C__msdev_work_age1_x1_fractal_cp: "C:\msdev\work\age1_x1\fractal.cpp"
int __thiscall PointMaker::MakeSatelliteLink(PointMaker *this)
{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  
  iVar2 = debug_rand(s_C__msdev_work_age1_x1_fractal_cp,0x165);
  iVar2 = iVar2 % this->SatelliteDistance + 1;
  uVar3 = debug_rand(s_C__msdev_work_age1_x1_fractal_cp,0x165);
  uVar5 = (int)uVar3 >> 0x1f;
  if (((uVar3 ^ uVar5) - uVar5 & 1 ^ uVar5) != uVar5) {
    iVar2 = -iVar2;
  }
  iVar4 = debug_rand(s_C__msdev_work_age1_x1_fractal_cp,0x166);
  iVar4 = iVar4 % this->SatelliteDistance + 1;
  uVar3 = debug_rand(s_C__msdev_work_age1_x1_fractal_cp,0x166);
  uVar5 = (int)uVar3 >> 0x1f;
  if (((uVar3 ^ uVar5) - uVar5 & 1 ^ uVar5) != uVar5) {
    iVar4 = -iVar4;
  }
  iVar2 = iVar2 + this->DirX;
  iVar4 = iVar4 + this->DirY;
  if (iVar2 + this->x < 3) {
    iVar2 = -iVar2;
    this->DirX = -this->DirX;
  }
  if (this->Width + -3 <= iVar2 + this->x) {
    iVar2 = -iVar2;
    this->DirX = -this->DirX;
  }
  iVar1 = this->y;
  if (iVar4 + iVar1 < 3) {
    iVar4 = -iVar2;
    this->DirY = -this->DirY;
  }
  if (this->Height + -3 <= iVar4 + iVar1) {
    iVar4 = -iVar4;
    this->DirY = -this->DirY;
  }
  iVar2 = this->x + iVar2;
  this->x = iVar2;
  this->y = iVar4 + iVar1;
  this->Point[this->NumNodes].x = iVar2;
  this->Point[this->NumNodes].y = this->y;
  iVar2 = this->NumNodes;
  this->NumNodes = iVar2 + 1;
  return iVar2;
}

// --------------------------------------------------

// Function: DrawPrimaryIntoProbabilityArray
// Address: 0044baa0
void __thiscall PointMaker::DrawPrimaryIntoProbabilityArray(PointMaker *this)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int desty;
  int i;
  int local_c;
  
  iVar5 = (this->Prime).x;
  iVar2 = (this->Prime).y;
  iVar1 = this->PrimaryRadius;
  iVar6 = iVar5 - iVar1;
  iVar4 = iVar2 - iVar1;
  iVar2 = iVar2 + iVar1;
  iVar5 = iVar1 + iVar5;
  if (iVar6 < 0) {
    iVar6 = 0;
  }
  if (iVar4 < 0) {
    iVar4 = 0;
  }
  iVar3 = this->Width + -1;
  if (iVar3 < iVar5) {
    iVar5 = iVar3;
  }
  iVar3 = this->Height + -1;
  if (iVar3 < iVar2) {
    iVar2 = iVar3;
  }
  this->ProbabilityAdd = 1;
  local_c = 0;
  if (0 < iVar1) {
    do {
      AddingRect(this,iVar6,iVar4,iVar5,iVar2);
      this->ProbabilityAdd = this->ProbabilityAdd + 1;
      local_c = local_c + 1;
      iVar2 = iVar2 + -1;
      iVar4 = iVar4 + 1;
      iVar5 = iVar5 + -1;
      iVar6 = iVar6 + 1;
    } while (local_c < this->PrimaryRadius);
  }
  return;
}

// --------------------------------------------------

// Function: DrawCurrentBranchIntoProbArray
// Address: 0044bb60
void __thiscall PointMaker::DrawCurrentBranchIntoProbArray(PointMaker *this,int param_1)
{
  char cVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  char cVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int desty;
  int i;
  int local_4;
  
  iVar8 = this->Point[param_1].x;
  iVar2 = this->BranchRadius;
  iVar3 = this->Point[param_1].y;
  iVar7 = iVar2 + iVar8;
  iVar8 = iVar8 - iVar2;
  iVar6 = iVar3 - iVar2;
  i = iVar3 + iVar2;
  if ((((-1 < iVar7) && (-1 < i)) && (iVar8 < this->Width)) && (iVar6 < this->Height)) {
    if (iVar8 < 0) {
      iVar8 = 0;
    }
    if (iVar6 < 0) {
      iVar6 = 0;
    }
    if (this->Width <= iVar7) {
      iVar7 = this->Width + -1;
    }
    if (this->Height <= i) {
      i = this->Height + -1;
    }
    this->ProbabilityAdd = 1;
    local_4 = 0;
    if (0 < iVar2) {
      do {
        AddingRect(this,iVar8,iVar6,iVar7,i);
        iVar8 = iVar8 + 1;
        if (((this->Width <= iVar8) || (iVar6 = iVar6 + 1, this->Height <= iVar6)) ||
           ((iVar7 = iVar7 + -1, iVar7 < 0 || (i = i + -1, i < 0)))) break;
        this->ProbabilityAdd = this->ProbabilityAdd + 1;
        local_4 = local_4 + 1;
      } while (local_4 < this->BranchRadius);
    }
    iVar7 = this->Width * this->Point[param_1].y + this->Point[param_1].x;
    if ((0 < iVar7) && (iVar7 < this->SizeArrays + -1)) {
      pcVar4 = this->ProbArray + iVar7;
      cVar1 = *pcVar4;
      cVar5 = (char)this->ProbabilityAdd;
      if (cVar1 == '\0') {
        *pcVar4 = cVar5;
        this->ProbabilityTiles = this->ProbabilityTiles + 1;
        return;
      }
      if (this->ProbabilityAdd + (int)cVar1 < 0xff) {
        *pcVar4 = cVar5 + cVar1;
        return;
      }
      *pcVar4 = -1;
    }
  }
  return;
}

// --------------------------------------------------

// Function: DrawCurrentSatelliteIntoProbArray
// Address: 0044bcd0
void __thiscall PointMaker::DrawCurrentSatelliteIntoProbArray(PointMaker *this,int param_1)
{
  char cVar1;
  char *pcVar2;
  char cVar3;
  int iVar4;
  
  iVar4 = this->SatelliteRadius;
  this->ProbabilityAdd = 2;
  for (; -1 < iVar4; iVar4 = iVar4 + -1) {
    AddingCircle(this,this->Point[param_1].x,this->Point[param_1].y,iVar4);
    this->ProbabilityAdd = this->ProbabilityAdd + 1;
  }
  iVar4 = this->Point[param_1].y * this->Width + this->Point[param_1].x;
  if ((0 < iVar4) && (iVar4 < this->SizeArrays + -1)) {
    pcVar2 = this->ProbArray + iVar4;
    cVar1 = *pcVar2;
    cVar3 = (char)this->ProbabilityAdd;
    if (cVar1 == '\0') {
      *pcVar2 = cVar3;
      this->ProbabilityTiles = this->ProbabilityTiles + 1;
      return;
    }
    if (this->ProbabilityAdd + (int)cVar1 < 0xff) {
      *pcVar2 = cVar3 + cVar1;
      return;
    }
    *pcVar2 = -1;
  }
  return;
}

// --------------------------------------------------

// Function: AddingRect
// Address: 0044bd80
void __thiscall
PointMaker::AddingRect(PointMaker *this,int param_1,int param_2,int param_3,int param_4)
{
  char cVar1;
  int iVar2;
  int iVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  char *pcVar7;
  int iVar8;
  int w;
  
  iVar5 = param_2 * this->Width + param_1;
  iVar6 = param_3 - param_1;
  iVar3 = (param_4 - param_2) + -1;
  iVar8 = iVar3 * this->Width + iVar5;
  if ((-1 < iVar6) && (-1 < param_4 - param_2)) {
    if (-1 < iVar6) {
      param_3 = iVar6 + 1;
      iVar2 = iVar5;
      do {
        if ((0 < iVar2) && (iVar2 < this->SizeArrays + -1)) {
          pcVar7 = this->ProbArray + iVar2;
          cVar1 = *pcVar7;
          cVar4 = (char)this->ProbabilityAdd;
          if (cVar1 == '\0') {
            *pcVar7 = cVar4;
            this->ProbabilityTiles = this->ProbabilityTiles + 1;
          }
          else if (this->ProbabilityAdd + (int)cVar1 < 0xff) {
            *pcVar7 = cVar4 + cVar1;
          }
          else {
            *pcVar7 = -1;
          }
        }
        if ((0 < iVar8) && (iVar8 < this->SizeArrays + -1)) {
          pcVar7 = this->ProbArray + iVar8;
          cVar1 = this->ProbArray[iVar8];
          cVar4 = (char)this->ProbabilityAdd;
          if (cVar1 == '\0') {
            *pcVar7 = cVar4;
            this->ProbabilityTiles = this->ProbabilityTiles + 1;
          }
          else if (this->ProbabilityAdd + (int)cVar1 < 0xff) {
            *pcVar7 = cVar4 + cVar1;
          }
          else {
            *pcVar7 = -1;
          }
        }
        iVar8 = iVar8 + 1;
        iVar2 = iVar2 + 1;
        param_3 = param_3 + -1;
      } while (param_3 != 0);
    }
    iVar5 = iVar5 + this->Width;
    if (-1 < iVar3) {
      for (; iVar3 != 0; iVar3 = iVar3 + -1) {
        if ((0 < iVar5) && (iVar5 < this->SizeArrays + -1)) {
          pcVar7 = this->ProbArray + iVar5;
          cVar1 = this->ProbArray[iVar5];
          cVar4 = (char)this->ProbabilityAdd;
          if (cVar1 == '\0') {
            *pcVar7 = cVar4;
            this->ProbabilityTiles = this->ProbabilityTiles + 1;
          }
          else if (this->ProbabilityAdd + (int)cVar1 < 0xff) {
            *pcVar7 = cVar4 + cVar1;
          }
          else {
            *pcVar7 = -1;
          }
        }
        iVar8 = iVar6 + iVar5;
        if ((0 < iVar8) && (iVar8 < this->SizeArrays + -1)) {
          pcVar7 = this->ProbArray + iVar8;
          cVar1 = *pcVar7;
          cVar4 = (char)this->ProbabilityAdd;
          if (cVar1 == '\0') {
            *pcVar7 = cVar4;
            this->ProbabilityTiles = this->ProbabilityTiles + 1;
          }
          else if (this->ProbabilityAdd + (int)cVar1 < 0xff) {
            *pcVar7 = cVar4 + cVar1;
          }
          else {
            *pcVar7 = -1;
          }
        }
        iVar5 = iVar5 + this->Width;
      }
    }
  }
  return;
}

// --------------------------------------------------

// Function: AddingCircle
// Address: 0044bf90
// [HELPER] s_C__msdev_work_age1_x1_fractal_cp: "C:\msdev\work\age1_x1\fractal.cpp"
void __thiscall PointMaker::AddingCircle(PointMaker *this,int param_1,int param_2,int param_3)
{
  char cVar1;
  int iVar2;
  char *pcVar3;
  uint uVar4;
  int iVar5;
  char cVar6;
  uint uVar7;
  int iVar8;
  float10 extraout_ST0;
  float fVar9;
  float fVar10;
  float curx;
  float lastx;
  float lasty;
  float W;
  float x;
  int step;
  
  if (param_3 == 0) {
    param_3 = 1;
  }
  lasty = 0.0;
  W = 0.0;
  iVar8 = 0;
  do {
    fVar9 = TRIGONOMETRY::sin360(&trig,iVar8);
    fVar9 = fVar9 * (float)param_3;
    fVar10 = TRIGONOMETRY::cos360(&trig,iVar8);
    if ((fVar9 != lasty) || (fVar10 * (float)param_3 != W)) {
      iVar2 = __ftol();
      if ((0 < iVar2) && (iVar2 < this->SizeArrays + -1)) {
        pcVar3 = this->ProbArray + iVar2;
        cVar1 = *pcVar3;
        cVar6 = (char)this->ProbabilityAdd;
        if (cVar1 == '\0') {
          *pcVar3 = cVar6;
          this->ProbabilityTiles = this->ProbabilityTiles + 1;
        }
        else if (this->ProbabilityAdd + (int)cVar1 < 0xff) {
          *pcVar3 = cVar6 + cVar1;
        }
        else {
          *pcVar3 = -1;
        }
      }
      W = (float)extraout_ST0;
      uVar4 = debug_rand(s_C__msdev_work_age1_x1_fractal_cp,0x1f1);
      uVar7 = (int)uVar4 >> 0x1f;
      lasty = fVar9;
      if (((uVar4 ^ uVar7) - uVar7 & 1 ^ uVar7) != uVar7) {
        TRIGONOMETRY::sin360(&trig,iVar8);
        debug_rand(s_C__msdev_work_age1_x1_fractal_cp,499);
        TRIGONOMETRY::cos360(&trig,iVar8);
        debug_rand(s_C__msdev_work_age1_x1_fractal_cp,500);
        iVar2 = __ftol();
        iVar5 = this->ProbabilityAdd + 1;
        if ((0 < iVar2) && (iVar2 < this->SizeArrays + -1)) {
          pcVar3 = this->ProbArray + iVar2;
          cVar1 = *pcVar3;
          cVar6 = (char)iVar5;
          if (cVar1 == '\0') {
            *pcVar3 = cVar6;
            this->ProbabilityTiles = this->ProbabilityTiles + 1;
          }
          else if (iVar5 + cVar1 < 0xff) {
            *pcVar3 = cVar6 + cVar1;
          }
          else {
            *pcVar3 = -1;
          }
        }
      }
    }
    iVar8 = iVar8 + (int)(0x168 / (longlong)(param_3 * 3));
  } while (iVar8 < 0x168);
  return;
}

// --------------------------------------------------

// Function: CreateMapBasedOnProbabilityArray
// Address: 0044c1b0
void __thiscall PointMaker::CreateMapBasedOnProbabilityArray(PointMaker *this)
{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  iVar1 = 0;
  if (0 < this->SizeArrays) {
    do {
      if (this->ProbArray[iVar1] != '\0') {
        iVar2 = iVar2 + 1;
        this->PlacementArray[iVar1] = '\x01';
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < this->SizeArrays);
  }
  this->NumTilesActuallyChosen = this->NumTilesActuallyChosen + iVar2;
  return;
}

// --------------------------------------------------

// Function: SetPoint
// Address: 0044c200
void __thiscall PointMaker::SetPoint(PointMaker *this,int param_1,int param_2)
{
  this->x = param_1;
  this->y = param_2;
  return;
}

// --------------------------------------------------

// Function: SetMaxNumberOfBranches
// Address: 0044c220
void __thiscall PointMaker::SetMaxNumberOfBranches(PointMaker *this,int param_1)
{
  this->MaxNumberOfBranches = param_1;
  return;
}

// --------------------------------------------------

// Function: SetChanceOfNextNode
// Address: 0044c230
void __thiscall PointMaker::SetChanceOfNextNode(PointMaker *this,int param_1)
{
  this->ChanceOfNextNode = param_1;
  return;
}

// --------------------------------------------------

// Function: SetNumberOfSatellites
// Address: 0044c240
void __thiscall PointMaker::SetNumberOfSatellites(PointMaker *this,int param_1)
{
  this->NumberOfSatellites = param_1;
  return;
}

// --------------------------------------------------

// Function: SetSplitsPerBranch
// Address: 0044c250
void __thiscall PointMaker::SetSplitsPerBranch(PointMaker *this,int param_1)
{
  this->NumSplitsPerBranch = param_1;
  return;
}

// --------------------------------------------------

// Function: SetWidthAndHeight
// Address: 0044c260
void __thiscall PointMaker::SetWidthAndHeight(PointMaker *this,int param_1,int param_2)
{
  this->Width = param_1;
  this->Height = param_2;
  return;
}

// --------------------------------------------------

// Function: SetStartPositionRadius
// Address: 0044c280
void __thiscall PointMaker::SetStartPositionRadius(PointMaker *this,int param_1)
{
  this->PrimaryRadius = param_1;
  return;
}

// --------------------------------------------------

// Function: SetBranchsRadius
// Address: 0044c290
void __thiscall PointMaker::SetBranchsRadius(PointMaker *this,int param_1)
{
  this->BranchRadius = param_1;
  return;
}

// --------------------------------------------------

// Function: SetSatelliteRadius
// Address: 0044c2a0
void __thiscall PointMaker::SetSatelliteRadius(PointMaker *this,int param_1)
{
  this->SatelliteRadius = param_1;
  return;
}

// --------------------------------------------------

// Function: SetMaxNumberOfBranchLevels
// Address: 0044c2b0
void __thiscall PointMaker::SetMaxNumberOfBranchLevels(PointMaker *this,int param_1)
{
  this->MaxBranchFlag = 1;
  this->MaxNumberOfBranchLevels = param_1;
  return;
}

// --------------------------------------------------

// Function: SetSatelliteDistance
// Address: 0044c2d0
void __thiscall PointMaker::SetSatelliteDistance(PointMaker *this,int param_1)
{
  this->SatelliteDistance = param_1;
  return;
}

// --------------------------------------------------

// Function: SetBranchDistance
// Address: 0044c2e0
void __thiscall PointMaker::SetBranchDistance(PointMaker *this,int param_1)
{
  this->BranchDistance = param_1;
  return;
}

// --------------------------------------------------

// Function: SetMinimumNumberOfTiles
// Address: 0044c2f0
void __thiscall PointMaker::SetMinimumNumberOfTiles(PointMaker *this,int param_1)
{
  this->MinimumNumTiles = param_1;
  return;
}

// --------------------------------------------------

// Function: SetDrawToOneArray
// Address: 0044c300
void __thiscall PointMaker::SetDrawToOneArray(PointMaker *this)
{
  this->DrawToOneArrayFlag = 1;
  return;
}

// --------------------------------------------------

// Function: SetBorderDepthPercentage
// Address: 0044c310
void __thiscall PointMaker::SetBorderDepthPercentage(PointMaker *this,int param_1)
{
  this->BorderDepthPercentage = param_1;
  if (0x1e < param_1) {
    this->BorderDepthPercentage = 0x1e;
  }
  if (this->BorderDepthPercentage < 5) {
    this->BorderDepthPercentage = 5;
  }
  PrepareLimits(this);
  return;
}

// --------------------------------------------------

// Function: RetrieveMap
// Address: 0044c350
char * __thiscall PointMaker::RetrieveMap(PointMaker *this)
{
  return this->PlacementArray;
}

// --------------------------------------------------

// Function: RetrieveProbMap
// Address: 0044c360
char * __thiscall PointMaker::RetrieveProbMap(PointMaker *this)
{
  return this->ProbArray;
}

// --------------------------------------------------

// Function: ErrorCheckingAndCorrection
// Address: 0044c370
void __thiscall PointMaker::ErrorCheckingAndCorrection(PointMaker *this)
{
  int iVar1;
  int iVar2;
  
  iVar1 = this->Width;
  iVar2 = this->Height * iVar1;
  this->SizeArrays = iVar2;
  if (iVar1 < this->BranchRadius) {
    this->BranchRadius = (iVar1 * 2) / 3;
  }
  if (iVar1 < this->SatelliteRadius) {
    this->SatelliteRadius = (iVar1 * 2) / 3;
  }
  if (iVar1 < this->PrimaryRadius) {
    this->PrimaryRadius = (iVar1 * 2) / 3;
  }
  if (4 < this->NumSplitsPerBranch) {
    this->NumSplitsPerBranch = 4;
  }
  if (4 < this->NumberOfSatellites) {
    this->NumberOfSatellites = 4;
  }
  iVar2 = iVar2 / this->MinimumNumTiles;
  this->DrawToOneArrayFlag = 0;
  iVar1 = (10 - iVar2) * 10;
  this->ChanceOfNextNode = iVar1;
  if (iVar1 < 0x23) {
    this->ChanceOfNextNode = 0x23;
  }
  if (0x50 < this->ChanceOfNextNode) {
    this->ChanceOfNextNode = 0x50;
  }
  if (this->MaxBranchFlag == 0) {
    this->MaxNumberOfBranchLevels = iVar2 - this->ChanceOfNextNode / 5;
  }
  if (this->MaxNumberOfBranchLevels < 10) {
    this->MaxNumberOfBranchLevels = 10;
  }
  if (0x1e < this->MaxNumberOfBranchLevels) {
    this->MaxNumberOfBranchLevels = 0x1e;
  }
  this->MaxBranchFlag = 0;
  return;
}

// --------------------------------------------------

// Function: PrepareLimits
// Address: 0044c4b0
void __thiscall PointMaker::PrepareLimits(PointMaker *this)
{
  int iVar1;
  
  iVar1 = (this->BorderDepthPercentage * this->Width) / 100;
  this->LeftLimit = iVar1;
  this->RightLimit = this->Width - iVar1;
  iVar1 = (this->Height * this->BorderDepthPercentage) / 100;
  this->TopLimit = iVar1;
  this->BottomLimit = this->Height - iVar1;
  return;
}

// --------------------------------------------------

// Function: MapCleanUpEliminatingSinglesOnly
// Address: 0044c510
void __thiscall PointMaker::MapCleanUpEliminatingSinglesOnly(PointMaker *this)
{
  int iVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  char cVar6;
  int iVar7;
  int w;
  int h;
  
  iVar4 = this->Height + -1;
  iVar5 = 1;
  iVar2 = this->Width + -1;
  if (1 < iVar4) {
    do {
      iVar7 = 1;
      if (1 < iVar2) {
        do {
          iVar1 = this->Width;
          pcVar3 = this->PlacementArray + iVar5 * iVar1 + iVar7;
          cVar6 = '\0' < pcVar3[-iVar1];
          if ('\0' < pcVar3[-1]) {
            cVar6 = cVar6 + '\x01';
          }
          if ('\0' < pcVar3[1]) {
            cVar6 = cVar6 + '\x01';
          }
          if ('\0' < pcVar3[iVar1]) {
            cVar6 = cVar6 + '\x01';
          }
          if ((*pcVar3 != '\0') && (cVar6 == '\0')) {
            *pcVar3 = '\0';
          }
          iVar7 = iVar7 + 1;
        } while (iVar7 < iVar2);
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < iVar4);
  }
  return;
}

// --------------------------------------------------

