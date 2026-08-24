#ifndef DRAWAREA_CANONICAL_TU
class TDrawArea { public: void DrawHorzLine(long x,long y,long w,unsigned char color); void DrawVertLine(long x,long y,long h,unsigned char color); void DrawBevel(long x1,long y1,long x2,long y2,unsigned char c1,unsigned char c2);};
#endif
void TDrawArea::DrawBevel(long x1,long y1,long x2,long y2,unsigned char c1,unsigned char c2){ if(x1>x2){long t=x1;x1=x2;x2=t;} if(y1>y2){long t=y1;y1=y2;y2=t;} long w=x2-x1+1; if(w<1)return; long h=y2-y1+1; if(h<1)return; DrawHorzLine(x1+1,y1,w-1,c1); DrawVertLine(x2,y1+1,h-1,c1); DrawHorzLine(x1,y2,w,c2); DrawVertLine(x1,y1,h-1,c2);}
