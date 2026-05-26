// 00484D00 base_elevation_generate - rough direct reconstruction
// Attempts:
// - Modeled the packet/decompiler algorithm: initialize per-clump stacks, link start stack randomly, seed clumps with check_start_elevation/remove_area_from_lists, then expand while stacks produce eligible cells, finally deinit stacks.
// - Key modeled offsets: width +0x14, height +0x18, tile rows +0x10/+0x24, tile elevation bits at cell+5 high 3 bits, and 24-byte tile stride.
// - This scratch is intentionally raw/local and not exact; exact match needs real Map_Stack layout/calling surfaces and source shape for the large expansion loop.
// - Current compile is far too small (.text 992 vs original 1273), indicating missing natural call/argument/liveness detail and likely wrong RGE_Elevation_Info_Line/Map_Stack surfaces. Not accepted-drift quality.
struct Map_Stack { int x; int y; float a; float b; Map_Stack* next; Map_Stack* prev; };
struct RGE_Elevation_Info_Line { int elevation_size; int clumps; int base_terrain_type; int base_elevation; int spacing; int elevation; int p6; int p7; };
extern int __cdecl debug_rand(char*, int); extern char s_C__msdev_work_age1_x1_rmm_elev_c[]; extern "C" int __cdecl _ftol(float);
class RGE_RMM_Elevation_Generator { public:
    char pad0[0x10]; unsigned char** tiles10; int width; int height; char pad1c[8]; unsigned char** tiles24;
    void init_stack(Map_Stack*); void deinit_stack(Map_Stack*); void link_stack_randomly(Map_Stack*); Map_Stack* pop_stack(Map_Stack*, long*, long*, float*); void push_stack(Map_Stack*, long, long, float, float); unsigned char check_start_elevation(long,long,unsigned char,unsigned char,unsigned char); void remove_area_from_lists(long,long,long); unsigned char check_elevation(unsigned char,long,long,int,unsigned char,unsigned char); float fig_chance(unsigned int,long,long); unsigned char base_elevation_generate(RGE_Elevation_Info_Line);
};
unsigned char RGE_RMM_Elevation_Generator::base_elevation_generate(RGE_Elevation_Info_Line info){
    long x=0,y=0,max_x=0; float chance=0.0f, local=0.0f; Map_Stack loc_stack; Map_Stack stack[99];
    long maxx=this->width-1, maxy=this->height-1;
    int i; for(i=0;i<info.clumps;i++) this->init_stack(&stack[i]);
    loc_stack.prev=0; loc_stack.x=0; this->link_stack_randomly(&loc_stack);
    long clump_size = _ftol((float)info.elevation_size / (float)info.clumps); clump_size/=2; if(clump_size<2) clump_size=2;
    int made=0; for(i=0;i<info.clumps;i++){
        if(!this->pop_stack(&loc_stack,&y,&x,(float*)&max_x)) break;
        if(this->tiles24[x][y]==0 && this->check_start_elevation(y,x,(unsigned char)info.base_terrain_type,(unsigned char)info.base_elevation,(unsigned char)info.spacing)){
            this->remove_area_from_lists(y,x,clump_size); unsigned char* cell=this->tiles10[x]+y*24+5; *cell=((unsigned char)info.elevation<<5)|(*cell&0x1f);
            if(y>0) this->push_stack(&stack[i],y-1,x,0,0); if(x>0) this->push_stack(&stack[i],y,x-1,0,0); if(y<maxx) this->push_stack(&stack[i],y+1,x,0,0); if(x<maxy) this->push_stack(&stack[i],y,x+1,0,0);
            chance=(float)((int)chance+1); made++;
        }
    }
    unsigned char done; do { done=1; for(i=0;i<info.clumps;i++) if((int)chance<info.elevation_size && this->pop_stack(&stack[i],&y,&x,(float*)&max_x)){
        done=0; unsigned char* mark=this->tiles24[x]+y; int r=(debug_rand(s_C__msdev_work_age1_x1_rmm_elev_c,0x171)*100)/0x7fff; if(r < *mark){ *mark=0x65; continue; }
        unsigned char* cell=this->tiles10[x]+y*24; unsigned char ok=this->check_elevation((unsigned char)info.elevation,y,x,info.spacing,(unsigned char)info.base_terrain_type,(unsigned char)info.base_elevation);
        if(((cell[5]>>5)==info.base_elevation) && ok){ local=this->fig_chance(ok,y,x); cell[5]=((unsigned char)info.elevation<<5)|(cell[5]&0x1f); if(y>0) this->push_stack(&stack[i],y-1,x,0,local); if(y<maxx) this->push_stack(&stack[i],y+1,x,0,local); if(x>0) this->push_stack(&stack[i],y,x-1,0,local); if(x<maxy) this->push_stack(&stack[i],y,x+1,0,local); chance=(float)((int)chance+1); }
    } } while(!done);
    for(i=0;i<info.clumps;i++) this->deinit_stack(&stack[i]);
    return 1;
}
