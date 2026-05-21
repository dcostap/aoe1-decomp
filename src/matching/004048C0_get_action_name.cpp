// RGE_Action_List::get_action_name — MATCH
// VA: 004048C0
// PDB: act_list.cpp:529-548
// Key fixes: use action_type cases 20/21 for RunAway/Make (not 14/15), spell the null-list
// case as an early `strcpy(...); return` before the switch to recover the original `jne`
// layout, and put `strcpy(...); return` directly in every named switch case while leaving
// only default to fall through. VC5 then emits the original sparse byte-table dispatch and
// duplicated strcpy tails.
#include "..\..\include\game_globals.h"
#include <string.h>
class RGE_Action { public: char gap_00[4]; short action_type; };
class RGE_Action_Node { public: RGE_Action* action; };
class RGE_Action_List { public: char gap_00[8]; RGE_Action_Node* list; void get_action_name(char* dest); };
void RGE_Action_List::get_action_name(char* dest)
{
 const char* name;
 if (this->list == 0) { name="None"; strcpy(dest,name); return; }
 switch (this->list->action->action_type) {
 case 1: name="MoveTo"; strcpy(dest,name); return;
 case 4: name="Explore"; strcpy(dest,name); return;
 case 5: name="Gather"; strcpy(dest,name); return;
 case 8: name="Missile"; strcpy(dest,name); return;
 case 9: name="Attack"; strcpy(dest,name); return;
 case 10: name="Bird"; strcpy(dest,name); return;
 case 20: name="RunAway"; strcpy(dest,name); return;
 case 21: name="Make"; strcpy(dest,name); return;
 default: name="Unknown"; break;
 }
 strcpy(dest,name);
}
