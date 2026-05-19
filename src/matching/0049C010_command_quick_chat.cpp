class TMessagePanel { public: void show_message(int kind, const char* msg); };
class TPanel { public: const char* get_string(int id,int a,int b,int c,int d,int e); };
class TribeSendQuickMessageDialog { public: char bytes[0x49c]; TribeSendQuickMessageDialog(TPanel* screen, int mode); };
class RGE_Base_Game { public: char gap[0x1B0]; int prog_mode; };
extern RGE_Base_Game* rge_base_game; void* __cdecl operator new(unsigned int);
class TRIBE_Screen_Game: public TPanel { public: char gap1[0x544]; TMessagePanel* message_panel; char gap2[0x7B4-0x548]; int field_7B4; void command_quick_chat(); };
void TRIBE_Screen_Game::command_quick_chat(){
    if(field_7B4==0 && rge_base_game->prog_mode==5){ const char* msg=get_string(0xBFE,0x32,0,0,0,0); message_panel->show_message(1,msg); return; } TribeSendQuickMessageDialog* d=new TribeSendQuickMessageDialog((TPanel*)this,0);
}
