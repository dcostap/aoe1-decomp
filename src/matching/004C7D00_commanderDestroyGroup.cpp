#ifndef RGE_STAT_OBJ_SHARED_CONTEXT
void* __cdecl operator_new(unsigned int); void __cdecl operator_delete(void*); class RGE_Game_World { public: void* object(int id); }; class RGE_Player { public: char gap_00[0x3C]; RGE_Game_World* world; }; class RGE_Static_Object { public: char gap_00[0x04]; int id; char gap_08[0x04]; RGE_Player* owner; char gap_10[0x54]; int* group_value; int group_number; char gap_6C[0x04]; int group_max; int commanderDestroyGroup(); int destroyGroup();};
#endif
int RGE_Static_Object::commanderDestroyGroup(){ this->destroyGroup(); return 1; }
