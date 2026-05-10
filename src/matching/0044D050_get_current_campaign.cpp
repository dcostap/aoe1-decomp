// 0044D050 RGE_Person_Info::get_current_campaign
//
// MATCHED: the key was deleting the explicit `campaign_num <= 0` guard and letting
// the natural `for (i = 0; i < this->campaign_num; ++i)` condition own the empty-loop
// check. VC5 then emits `mov campaign_num; xor edi,edi; test eax,eax; jle fail` once
// and reloads campaign_num at the loop tail, exactly like the original.
//
// Attempt log:
// 1. Count local caused EBX save and wrong prologue.
// 2. Reload campaign_num from this each iteration: no EBX, but first iteration peeled.
// 3. Natural for-loop with reloaded bound plus an explicit pre-loop empty check caused a duplicate test.
// 4. Initializing i before the empty-loop check, `i >= campaign_num`, and explicit bottom-test goto all still peel or duplicate the test.
// 5. variant_lab over split/nested guards and countlocal/reload_do/reload_for/ptrloop shapes with vc5-small flags: no exact. Best edit family was reload_for (edit 26), best positional among no-EBX families was reload_do (pos 47.5) but with peeled first iteration and larger body.
// 6. Removed explicit empty check and used only the for-loop condition; exact match.

class RGE_Campaign { public: char* get_name(void); };
class RGE_Campaign_Info { public: unsigned char verify_campaign_name(char* campaign_name); };

class RGE_Person_Info {
public:
    char name[0x100];
    long current_campaign;
    long campaign_info_num;
    RGE_Campaign_Info** campaign_info;
    long campaign_num;
    RGE_Campaign** campaigns;
    long get_current_campaign(void);
};

long RGE_Person_Info::get_current_campaign(void) {
    if (this->current_campaign < 0 || this->current_campaign >= this->campaign_info_num) {
        return -1;
    }

    for (long i = 0; i < this->campaign_num; ++i) {
        if (this->campaign_info[this->current_campaign]->verify_campaign_name(this->campaigns[i]->get_name()) != 0) {
            return i;
        }
    }

    return -1;
}
