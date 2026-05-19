struct Terrain { char gap0[8]; int width; int height; char gap10[0x8d8c - 0x10]; unsigned char** rows; };
struct WorldA { char gap[0x28]; Terrain* terrain; };
struct AiPlayer { char gap[0x3c]; WorldA* worlda; };
struct MD { char gap[0x1256c]; AiPlayer* aiPlayer; };
struct TribeInformationAIModule { char gap[0x100]; MD* md; int hasAdjacentTileType(int x,int y,int type); };
int TribeInformationAIModule::hasAdjacentTileType(int param_1,int param_2,int param_3){
    Terrain* terrain=this->md->aiPlayer->worlda->terrain; int x=param_1; int y=param_2;
    for(int i=0;i<8;i++){ switch(i){case 0: goto c0; case 1: case 2: goto incx; case 3: case 4: goto incy; case 5: case 6: goto decx; case 7: goto decy; default: goto check;}
check:
        if (x >= 0 && y >= 0 && x <= terrain->width - 1 && y <= terrain->height - 1) { unsigned char* row=terrain->rows[y]; int xx=x+x*2; int tile=row[xx*8+5]&0x1f; if(tile==param_3) return 1; }
        continue; c0: x=param_1; y=param_2; x--; c7: y--; goto check; incx: x++; goto check; incy: y++; goto check; decx: x--; goto check; decy: y--; goto check; } return 0;
}
