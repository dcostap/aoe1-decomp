// Class: Visible_Resource_Manager
// Size:  0x14
//
// Member Layout:
// [0x000] VISIBLE_RESOURCE_REC * * VR_List
// [0x004] int * VR_ListSize
// [0x008] int * VR_ListUsed
// [0x00C] RGE_Player * owner
// [0x010] int num_visible_resource_lists
// ----------------------------------------------------------------

// Function: Visible_Resource_Manager
// Address: 0053bb30
Visible_Resource_Manager * __thiscall
Visible_Resource_Manager::Visible_Resource_Manager
          (Visible_Resource_Manager *this,RGE_Player *param_1,int param_2)
{
  VISIBLE_RESOURCE_REC **ppVVar1;
  int *piVar2;
  VISIBLE_RESOURCE_REC *pVVar3;
  int iVar4;
  
  this->num_visible_resource_lists = param_2;
  if (param_2 < 1) {
    this->VR_List = (VISIBLE_RESOURCE_REC **)0x0;
    this->VR_ListSize = (int *)0x0;
    this->VR_ListUsed = (int *)0x0;
  }
  else {
    ppVVar1 = (VISIBLE_RESOURCE_REC **)calloc(param_2,4);
    this->VR_List = ppVVar1;
    piVar2 = (int *)calloc(this->num_visible_resource_lists,4);
    this->VR_ListSize = piVar2;
    piVar2 = (int *)calloc(this->num_visible_resource_lists,4);
    this->VR_ListUsed = piVar2;
    iVar4 = 0;
    if (0 < this->num_visible_resource_lists) {
      do {
        pVVar3 = (VISIBLE_RESOURCE_REC *)malloc(0x100);
        this->VR_List[iVar4] = pVVar3;
        this->VR_ListSize[iVar4] = 0x20;
        this->VR_ListUsed[iVar4] = 0;
        iVar4 = iVar4 + 1;
      } while (iVar4 < this->num_visible_resource_lists);
      this->owner = param_1;
      return this;
    }
  }
  this->owner = param_1;
  return this;
}

// --------------------------------------------------

// Function: Visible_Resource_Manager
// Address: 0053bbe0
Visible_Resource_Manager * __thiscall
Visible_Resource_Manager::Visible_Resource_Manager
          (Visible_Resource_Manager *this,int param_1,RGE_Player *param_2)
{
  int *piVar1;
  VISIBLE_RESOURCE_REC **ppVVar2;
  int *piVar3;
  VISIBLE_RESOURCE_REC *pVVar4;
  int iVar5;
  int iVar6;
  
  piVar1 = &this->num_visible_resource_lists;
  if (save_game_version < _DAT_005776c8) {
    *piVar1 = 5;
  }
  else {
    rge_read(param_1,piVar1,4);
  }
  if (*piVar1 < 1) {
    this->VR_List = (VISIBLE_RESOURCE_REC **)0x0;
    this->VR_ListSize = (int *)0x0;
    this->VR_ListUsed = (int *)0x0;
  }
  else {
    ppVVar2 = (VISIBLE_RESOURCE_REC **)calloc(*piVar1,4);
    this->VR_List = ppVVar2;
    piVar3 = (int *)calloc(*piVar1,4);
    this->VR_ListSize = piVar3;
    piVar3 = (int *)calloc(*piVar1,4);
    this->VR_ListUsed = piVar3;
    iVar6 = 0;
    if (0 < *piVar1) {
      do {
        rge_read(param_1,this->VR_ListSize + iVar6,4);
        rge_read(param_1,this->VR_ListUsed + iVar6,4);
        pVVar4 = (VISIBLE_RESOURCE_REC *)malloc(this->VR_ListSize[iVar6] << 3);
        iVar5 = iVar6 + 1;
        this->VR_List[iVar6] = pVVar4;
        iVar6 = iVar5;
      } while (iVar5 < *piVar1);
    }
    iVar6 = 0;
    if (0 < *piVar1) {
      do {
        if (0 < this->VR_ListUsed[iVar6]) {
          rge_read(param_1,this->VR_List[iVar6],this->VR_ListUsed[iVar6] * 8);
        }
        iVar6 = iVar6 + 1;
      } while (iVar6 < *piVar1);
      this->owner = param_2;
      return this;
    }
  }
  this->owner = param_2;
  return this;
}

// --------------------------------------------------

// Function: ~Visible_Resource_Manager
// Address: 0053bd10
void __thiscall Visible_Resource_Manager::~Visible_Resource_Manager(Visible_Resource_Manager *this)
{
  int iVar1;
  
  iVar1 = 0;
  if (0 < this->num_visible_resource_lists) {
    do {
      if (this->VR_List[iVar1] != (VISIBLE_RESOURCE_REC *)0x0) {
        free(this->VR_List[iVar1]);
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < this->num_visible_resource_lists);
  }
  if (this->VR_List != (VISIBLE_RESOURCE_REC **)0x0) {
    free(this->VR_List);
  }
  if (this->VR_ListSize != (int *)0x0) {
    free(this->VR_ListSize);
  }
  if (this->VR_ListUsed != (int *)0x0) {
    free(this->VR_ListUsed);
  }
  return;
}

// --------------------------------------------------

// Function: save
// Address: 0053bd70
void __thiscall Visible_Resource_Manager::save(Visible_Resource_Manager *this,int param_1)
{
  int iVar1;
  
  rge_write(param_1,&this->num_visible_resource_lists,4);
  iVar1 = 0;
  if (0 < this->num_visible_resource_lists) {
    do {
      rge_write(param_1,this->VR_ListSize + iVar1,4);
      rge_write(param_1,this->VR_ListUsed + iVar1,4);
      iVar1 = iVar1 + 1;
    } while (iVar1 < this->num_visible_resource_lists);
  }
  iVar1 = 0;
  if (0 < this->num_visible_resource_lists) {
    do {
      if (0 < this->VR_ListUsed[iVar1]) {
        rge_write(param_1,this->VR_List[iVar1],this->VR_ListUsed[iVar1] << 3);
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < this->num_visible_resource_lists);
  }
  return;
}

// --------------------------------------------------

// Function: Process_New_Tiles
// Address: 0053be00
void __thiscall
Visible_Resource_Manager::Process_New_Tiles(Visible_Resource_Manager *this,RGE_Tile_List *param_1)
{
  RGE_Object_Node *pRVar1;
  RGE_Static_Object *pRVar2;
  int iVar3;
  int iVar4;
  int size;
  RGE_Tile **TileOffsets;
  RGE_Tile **local_4;
  
  RGE_Tile_List::get_list_info(param_1,(RGE_Tile_List_Node **)&param_1,(int *)&TileOffsets);
  if ((0 < (int)TileOffsets) && (this->num_visible_resource_lists != 0)) {
    iVar3 = 0;
    local_4 = this->owner->world->map->map_row_offset;
    if (0 < (int)TileOffsets) {
      do {
        iVar4 = (int)local_4[param_1->num_active][param_1->list_size].objects.number_of_objects;
        if (0 < iVar4) {
          pRVar1 = local_4[param_1->num_active][param_1->list_size].objects.list;
          for (; (pRVar1 != (RGE_Object_Node *)0x0 && (0 < iVar4)); iVar4 = iVar4 + -1) {
            pRVar2 = pRVar1->node;
            if ((pRVar2 != (RGE_Static_Object *)0x0) &&
               (pRVar2->master_obj->track_as_resource != '\0')) {
              AddResource(this,pRVar2->id,(uint)pRVar2->master_obj->resource_group);
            }
            pRVar1 = pRVar1->next;
          }
        }
        iVar3 = iVar3 + 1;
        param_1 = (RGE_Tile_List *)&param_1->new_count;
      } while (iVar3 < (int)TileOffsets);
    }
  }
  return;
}

// --------------------------------------------------

// Function: AddResource
// Address: 0053bed0
void __thiscall
Visible_Resource_Manager::AddResource(Visible_Resource_Manager *this,int param_1,int param_2)
{
  int iVar1;
  uchar uVar2;
  uchar uVar3;
  VISIBLE_RESOURCE_REC *pVVar4;
  uint uVar5;
  int iVar6;
  VISIBLE_RESOURCE_REC *pVVar7;
  VISIBLE_RESOURCE_REC *pVVar8;
  int n;
  RGE_Static_Object *o;
  
  if ((this->num_visible_resource_lists != 0) &&
     (VIS_UNIT_objectsValue[param_1] != (RGE_Static_Object *)0x0)) {
    iVar1 = this->VR_ListSize[param_2];
    if (this->VR_ListUsed[param_2] == iVar1) {
      pVVar4 = (VISIBLE_RESOURCE_REC *)malloc(iVar1 * 0x10);
      pVVar7 = this->VR_List[param_2];
      pVVar8 = pVVar4;
      for (uVar5 = (uint)(this->VR_ListSize[param_2] << 3) >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
        pVVar8->object_id = pVVar7->object_id;
        pVVar7 = (VISIBLE_RESOURCE_REC *)&pVVar7->distance;
        pVVar8 = (VISIBLE_RESOURCE_REC *)&pVVar8->distance;
      }
      for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {
        *(char *)&pVVar8->object_id = (char)pVVar7->object_id;
        pVVar7 = (VISIBLE_RESOURCE_REC *)((int)&pVVar7->object_id + 1);
        pVVar8 = (VISIBLE_RESOURCE_REC *)((int)&pVVar8->object_id + 1);
      }
      free(this->VR_List[param_2]);
      this->VR_List[param_2] = pVVar4;
      this->VR_ListSize[param_2] = iVar1 * 2;
    }
    pVVar7 = this->VR_List[param_2] + this->VR_ListUsed[param_2];
    uVar2 = __ftol();
    uVar3 = __ftol();
    pVVar7->object_id = param_1;
    pVVar7->distance = '\0';
    pVVar7->zone = '\0';
    pVVar7->pos_x = uVar2;
    pVVar7->pos_y = uVar3;
    this->VR_ListUsed[param_2] = this->VR_ListUsed[param_2] + 1;
  }
  return;
}

// --------------------------------------------------

// Function: Remove_Resource
// Address: 0053bfd0
int __thiscall
Visible_Resource_Manager::Remove_Resource(Visible_Resource_Manager *this,int param_1,int param_2)
{
  VISIBLE_RESOURCE_REC *pVVar1;
  uchar uVar2;
  uchar uVar3;
  uchar uVar4;
  int iVar5;
  int iVar6;
  VISIBLE_RESOURCE_REC *pVVar7;
  
  if (this->num_visible_resource_lists != 0) {
    if (this->VR_ListUsed[param_2] != 0) {
      iVar6 = this->VR_ListUsed[param_2] + -1;
      pVVar1 = this->VR_List[param_2];
      iVar5 = 0;
      pVVar7 = pVVar1;
      if (-1 < iVar6) {
        do {
          if (pVVar7->object_id == param_1) {
            if (iVar5 < iVar6) {
              pVVar1[iVar5].object_id = pVVar1[iVar6].object_id;
              pVVar7 = pVVar1 + iVar6;
              uVar2 = pVVar7->zone;
              uVar3 = pVVar7->pos_x;
              uVar4 = pVVar7->pos_y;
              pVVar1 = pVVar1 + iVar5;
              pVVar1->distance = pVVar7->distance;
              pVVar1->zone = uVar2;
              pVVar1->pos_x = uVar3;
              pVVar1->pos_y = uVar4;
            }
            this->VR_ListUsed[param_2] = this->VR_ListUsed[param_2] + -1;
            return 1;
          }
          iVar5 = iVar5 + 1;
          pVVar7 = pVVar7 + 1;
        } while (iVar5 <= iVar6);
        return 0;
      }
    }
  }
  return 0;
}

// --------------------------------------------------

// Function: Get_Closest_Resource
// Address: 0053c050
VISIBLE_RESOURCE_REC * __thiscall
Visible_Resource_Manager::Get_Closest_Resource
          (Visible_Resource_Manager *this,int param_1,int param_2,int param_3,int param_4,
          int *param_5,int param_6)
{
  bool bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  uint uVar6;
  int iVar7;
  VISIBLE_RESOURCE_REC *pVVar8;
  VISIBLE_RESOURCE_REC *pVVar9;
  int xd;
  int Reject;
  VISIBLE_RESOURCE_REC *c;
  VISIBLE_RESOURCE_REC *local_4;
  
  if (((-1 < param_4) && (this->num_visible_resource_lists != 0)) &&
     (param_4 < this->num_visible_resource_lists)) {
    c = (VISIBLE_RESOURCE_REC *)this->VR_ListUsed[param_4];
    if (c != (VISIBLE_RESOURCE_REC *)0x0) {
      pVVar9 = this->VR_List[param_4];
      param_4 = 9999;
      local_4 = (VISIBLE_RESOURCE_REC *)0x0;
      pVVar8 = (VISIBLE_RESOURCE_REC *)0x0;
      if (0 < (int)c) {
        do {
          uVar2 = (uint)pVVar9->pos_x;
          uVar6 = (uint)pVVar9->pos_y;
          bVar1 = false;
          if (param_1 < (int)uVar2) {
            iVar3 = uVar2 - param_1;
          }
          else {
            iVar3 = param_1 - uVar2;
          }
          if (param_2 < (int)uVar6) {
            iVar7 = uVar6 - param_2;
          }
          else {
            iVar7 = param_2 - uVar6;
          }
          if (iVar7 < iVar3) {
            iVar4 = __ftol();
            iVar7 = (iVar3 - iVar4) - iVar7;
          }
          else {
            iVar4 = __ftol();
            iVar7 = (iVar7 - iVar4) - iVar3;
          }
          if (iVar7 < param_4) {
            if (((param_6 != 0) && (param_5 != (int *)0x0)) && (iVar3 = 0, 0 < param_6)) {
              piVar5 = param_5;
              do {
                if (pVVar9->object_id == *piVar5) {
                  bVar1 = true;
                  break;
                }
                iVar3 = iVar3 + 1;
                piVar5 = piVar5 + 1;
              } while (iVar3 < param_6);
            }
            if (!bVar1) {
              param_4 = iVar7;
              local_4 = pVVar9;
            }
          }
          pVVar9 = pVVar9 + 1;
          c = (VISIBLE_RESOURCE_REC *)&c[-1].pos_y;
          pVVar8 = local_4;
        } while (c != (VISIBLE_RESOURCE_REC *)0x0);
      }
      if (0xff < param_4) {
        param_4 = 0xff;
      }
      if (pVVar8 != (VISIBLE_RESOURCE_REC *)0x0) {
        pVVar8->distance = (uchar)param_4;
      }
      return pVVar8;
    }
  }
  return (VISIBLE_RESOURCE_REC *)0x0;
}

// --------------------------------------------------

