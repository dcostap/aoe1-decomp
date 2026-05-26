// VA: 004568C0 RGE_Map::clean_elevation
// PDB source: map.cpp
// Attempt log:
// - broad reconstruction from packet: clamp input rectangle, expand by two, call pre-clean helper, scan cells and normalize elevation/edge shape bits from neighbors.
// - default /O2 compiles but .text is 1264 bytes vs target 1478, too short for extraction; broad neighbor logic is present but exact tile-shape case table/bit rules are under-modeled.
// - tried /Od diagnostically: extracts at target size but 91.95% positional diff from offset 0 due EBP/debug frame, confirming original optimized family.
// - restored default flags. Give-up: needs faithful reconstruction of all eight-neighbor elevation predicates and exact tile type remapping table/control flow; no accepted_drift proposed.

class Map_4568C0 {
public:
    char gap0[8]; short width; short height; char gap10[0x8d8c-0x10]; unsigned char** rows;
    void preclean(int,int,int,int,int); void clean_elevation(int x1,int y1,int x2,int y2,int mode);
};
static unsigned char* tile(Map_4568C0* m,int x,int y){ return m->rows[y] + (x+x*2)*8; }
static int elev(unsigned char* t){ return t[5]>>5; }
static void setelev(unsigned char* t,int e){ t[5]=(unsigned char)((t[5]&0x1f)|((e&7)<<5)); }

void Map_4568C0::clean_elevation(int x1,int y1,int x2,int y2,int mode)
{
    if(x1<0)x1=0; if(y1<0)y1=0; if(x2>=width)x2=width-1; if(y2>=height)y2=height-1;
    x1-=2; y1-=2; x2+=2; y2+=2;
    if(x1<0)x1=0; if(y1<0)y1=0; if(x2>=width)x2=width-1; if(y2>=height)y2=height-1;
    preclean(x1,y1,x2,y2,mode);
    int changed=0;
    for(int y=y1;y<=y2;y++){
        for(int x=x1;x<=x2;x++){
            unsigned char* t=tile(this,x,y); int e=elev(t); int mask=0;
            int n=e,s=e,w=e,ee=e,nw=e,ne=e,sw=e,se=e;
            if(y>0) n=elev(tile(this,x,y-1)); if(y<height-1) s=elev(tile(this,x,y+1));
            if(x>0) w=elev(tile(this,x-1,y)); if(x<width-1) ee=elev(tile(this,x+1,y));
            if(x>0&&y>0) nw=elev(tile(this,x-1,y-1)); if(x<width-1&&y>0) ne=elev(tile(this,x+1,y-1));
            if(x>0&&y<height-1) sw=elev(tile(this,x-1,y+1)); if(x<width-1&&y<height-1) se=elev(tile(this,x+1,y+1));
            int hi=e; if(n>hi)hi=n; if(s>hi)hi=s; if(w>hi)hi=w; if(ee>hi)hi=ee; if(nw>hi)hi=nw; if(ne>hi)hi=ne; if(sw>hi)hi=sw; if(se>hi)hi=se;
            int lo=e; if(n<lo)lo=n; if(s<lo)lo=s; if(w<lo)lo=w; if(ee<lo)lo=ee; if(nw<lo)lo=nw; if(ne<lo)lo=ne; if(sw<lo)lo=sw; if(se<lo)lo=se;
            if(hi-lo>1){ if(e<hi-1){ setelev(t,hi-1); changed=1; e=hi-1; } }
            if(n>e)mask|=1; if(ee>e)mask|=2; if(s>e)mask|=4; if(w>e)mask|=8;
            if(nw>e)mask|=0x10; if(ne>e)mask|=0x20; if(se>e)mask|=0x40; if(sw>e)mask|=0x80;
            t[4]=(unsigned char)mask;
        }
    }
    if(changed){
        for(int yy=y1;yy<=y2;yy++) for(int xx=x1;xx<=x2;xx++){
            unsigned char* t=tile(this,xx,yy); int e=elev(t); int m=0;
            if(yy>0 && elev(tile(this,xx,yy-1))>e)m|=1; if(xx<width-1 && elev(tile(this,xx+1,yy))>e)m|=2;
            if(yy<height-1 && elev(tile(this,xx,yy+1))>e)m|=4; if(xx>0 && elev(tile(this,xx-1,yy))>e)m|=8; t[4]=(unsigned char)m;
        }
    }
}
