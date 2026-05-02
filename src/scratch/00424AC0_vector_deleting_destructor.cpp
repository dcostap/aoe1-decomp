#include "..\..\include\game_globals.h"
class IPAD { public: char _size[0xA0]; void* vector_deleting_destructor(int flags);};
extern "C" void __cdecl operator_delete(void*);
void __stdcall eh_vector_destructor_iterator(void* obj,int elemSize,int elemCount,void* dtor);
void* IPAD::vector_deleting_destructor(int flags){ if(flags & 2){ eh_vector_destructor_iterator(this,0xA0,*(int*)((char*)this-4),(void*)0x424E30); operator_delete((char*)this-4); return this;} if(flags & 1) operator_delete(this); return this;}
