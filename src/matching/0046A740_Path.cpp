void* __cdecl operator_new(unsigned int);
void __cdecl operator_delete(void*);
struct Waypoint { float x,y,z; unsigned char facetToNextWaypoint; char pad[3]; };
struct Path { int timeStampValue; float startValue[3]; int gap10; float goalValue[3]; int gap20; Waypoint* pathValue; int maxSizeValue; int currentSizeValue; int currentWaypointValue; Path(int); };
Path::Path(int max_size)
{
    timeStampValue=0; pathValue=0; maxSizeValue=0; currentSizeValue=0; currentWaypointValue=0;
    startValue[0]=0; startValue[1]=0; startValue[2]=0; goalValue[0]=0; goalValue[1]=0; goalValue[2]=0;
    if (max_size == 0 || max_size >= 0) {
        maxSizeValue=max_size;
        Waypoint* new_path=(Waypoint*)operator_new(max_size<<4);
        int i=0;
        if(currentSizeValue>0){
            int off=0; Waypoint* dst=new_path;
            do { dst->x=*(float*)((char*)pathValue+off); dst->y=*(float*)((char*)pathValue+off+4); dst->z=*(float*)((char*)pathValue+off+8); dst->facetToNextWaypoint=*(unsigned char*)((char*)pathValue+off+12); ++i; ++dst; off+=16; } while(i<currentSizeValue);
        }
        if(pathValue) operator_delete(pathValue);
        pathValue=new_path;
    }
}
