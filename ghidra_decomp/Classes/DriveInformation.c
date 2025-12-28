// Class: DriveInformation
// Size:  0x274
//
// Member Layout:
// [0x000] int initialDriveValue
// [0x004] char[256] initialDirectoryValue (sz: 0x100)
// [0x104] int currentDriveValue
// [0x108] char[256] currentDirectoryValue (sz: 0x100)
// [0x208] int[27] driveValues (sz: 0x6C)
// ----------------------------------------------------------------

// Function: DriveInformation
// Address: 00449770
DriveInformation * __thiscall DriveInformation::DriveInformation(DriveInformation *this)
{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  
  iVar2 = __getdrive();
  this->initialDriveValue = iVar2;
  this->currentDriveValue = iVar2;
  updateDirectory(this);
  uVar3 = 0xffffffff;
  pcVar5 = this->currentDirectoryValue;
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
  pcVar6 = this->initialDirectoryValue;
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
  return this;
}

// --------------------------------------------------

// Function: initialDrive
// Address: 004497c0
int __thiscall DriveInformation::initialDrive(DriveInformation *this)
{
  return this->initialDriveValue;
}

// --------------------------------------------------

// Function: initialDriveAsLetter
// Address: 004497d0
char __thiscall DriveInformation::initialDriveAsLetter(DriveInformation *this)
{
  return (char)this->initialDriveValue + '@';
}

// --------------------------------------------------

// Function: initialDirectory
// Address: 004497e0
char * __thiscall DriveInformation::initialDirectory(DriveInformation *this)
{
  return this->initialDirectoryValue;
}

// --------------------------------------------------

// Function: currentDrive
// Address: 004497f0
int __thiscall DriveInformation::currentDrive(DriveInformation *this)
{
  return this->currentDriveValue;
}

// --------------------------------------------------

// Function: currentDriveAsLetter
// Address: 00449800
char __thiscall DriveInformation::currentDriveAsLetter(DriveInformation *this)
{
  return (char)this->currentDriveValue + '@';
}

// --------------------------------------------------

// Function: currentDirectory
// Address: 00449810
char * __thiscall DriveInformation::currentDirectory(DriveInformation *this)
{
  return this->currentDirectoryValue;
}

// --------------------------------------------------

// Function: numberDrives
// Address: 00449820
int __thiscall DriveInformation::numberDrives(DriveInformation *this)
{
  return this->driveValues[0];
}

// --------------------------------------------------

// Function: validDrive
// Address: 00449830
int __thiscall DriveInformation::validDrive(DriveInformation *this,int param_1)
{
  return this->driveValues[param_1];
}

// --------------------------------------------------

// Function: checkDrives
// Address: 00449840
void __thiscall DriveInformation::checkDrives(DriveInformation *this)
{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  this->driveValues[0] = 0;
  iVar3 = 1;
  piVar2 = this->driveValues;
  do {
    piVar2 = piVar2 + 1;
    iVar1 = __chdrive(iVar3);
    if (iVar1 == 0) {
      this->driveValues[0] = this->driveValues[0] + 1;
      *piVar2 = 1;
    }
    else {
      *piVar2 = 0;
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < 0x1b);
  __chdrive(this->currentDriveValue);
  return;
}

// --------------------------------------------------

// Function: numberOfFilesWithFilename
// Address: 004498a0
int __thiscall DriveInformation::numberOfFilesWithFilename(DriveInformation *this,char *param_1)
{
  int iVar1;
  int iVar2;
  int iVar3;
  _finddata_t fileInfo;
  
  iVar1 = __findfirst(param_1,&fileInfo.time_create);
  if (iVar1 != -1) {
    iVar3 = 1;
    iVar2 = __findnext(iVar1,&fileInfo.time_create);
    while (iVar2 != -1) {
      iVar3 = iVar3 + 1;
      iVar2 = __findnext(iVar1,&fileInfo.time_create);
    }
    return iVar3;
  }
  return 0;
}

// --------------------------------------------------

// Function: numberOfFilesWithAttribute
// Address: 00449910
// [HELPER] s____: "*.*"
int __thiscall DriveInformation::numberOfFilesWithAttribute(DriveInformation *this,int param_1)
{
  int iVar1;
  int iVar2;
  int iVar3;
  _finddata_t fileInfo;
  
  iVar1 = __findfirst(s____,&fileInfo.time_create);
  if (iVar1 == -1) {
    return 0;
  }
  iVar3 = 1;
  iVar2 = __findnext(iVar1,&fileInfo.time_create);
  while (iVar2 != -1) {
    if ((fileInfo.time_create & param_1) != 0) {
      iVar3 = iVar3 + 1;
    }
    iVar2 = __findnext(iVar1,&fileInfo.time_create);
  }
  return iVar3;
}

// --------------------------------------------------

// Function: numberOfFilesWithFilenameOrAttribute
// Address: 00449990
// [HELPER] s____: "*.*"
int __thiscall
DriveInformation::numberOfFilesWithFilenameOrAttribute
          (DriveInformation *this,char *param_1,int param_2)
{
  int iVar1;
  int iVar2;
  int iVar3;
  _finddata_t fileInfo;
  
  iVar1 = __findfirst(s____,&fileInfo.time_create);
  if (iVar1 == -1) {
    return 0;
  }
  iVar3 = 1;
  iVar2 = __findnext(iVar1,&fileInfo.time_create);
  while (iVar2 != -1) {
    if (((fileInfo.time_create & param_2) != 0) ||
       (iVar2 = strstr(fileInfo.name + 4,param_1), iVar2 != 0)) {
      iVar3 = iVar3 + 1;
    }
    iVar2 = __findnext(iVar1,&fileInfo.time_create);
  }
  return iVar3;
}

// --------------------------------------------------

// Function: resetCurrentDriveAndDirectory
// Address: 00449a20
int __thiscall DriveInformation::resetCurrentDriveAndDirectory(DriveInformation *this)
{
  int iVar1;
  
  iVar1 = resetCurrentDrive(this);
  if (iVar1 != 0) {
    iVar1 = resetCurrentDirectory(this);
    return iVar1;
  }
  return 0;
}

// --------------------------------------------------

// Function: resetCurrentDrive
// Address: 00449a40
int __thiscall DriveInformation::resetCurrentDrive(DriveInformation *this)
{
  int iVar1;
  
  iVar1 = changeDrive(this,this->initialDriveValue);
  return iVar1;
}

// --------------------------------------------------

// Function: resetCurrentDirectory
// Address: 00449a50
int __thiscall DriveInformation::resetCurrentDirectory(DriveInformation *this)
{
  int iVar1;
  
  iVar1 = changeDirectory(this,this->initialDirectoryValue);
  return iVar1;
}

// --------------------------------------------------

// Function: changeDrive
// Address: 00449a60
int __thiscall DriveInformation::changeDrive(DriveInformation *this,int param_1)
{
  int iVar1;
  
  iVar1 = __chdrive(param_1);
  if (iVar1 == 0) {
    this->currentDriveValue = param_1;
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: changeDirectory
// Address: 00449a90
int __thiscall DriveInformation::changeDirectory(DriveInformation *this,char *param_1)
{
  int iVar1;
  
  iVar1 = __chdir(param_1);
  if (iVar1 == 0) {
    updateDirectory(this);
    return 1;
  }
  return 0;
}

// --------------------------------------------------

// Function: updateDirectory
// Address: 00449ac0
// [HELPER] s__s_s_s: "%s%s%s"
void __thiscall DriveInformation::updateDirectory(DriveInformation *this)
{
  char *pcVar1;
  char cDrive [3];
  char extension [256];
  char filename [256];
  char fullPath [260];
  
  __getcwd(fullPath + 4,0x104);
  pcVar1 = this->currentDirectoryValue;
  __splitpath(fullPath + 4,extension,pcVar1,filename + 4,extension + 4);
  sprintf(pcVar1,s__s_s_s,pcVar1,filename + 4,extension + 4);
  return;
}

// --------------------------------------------------

