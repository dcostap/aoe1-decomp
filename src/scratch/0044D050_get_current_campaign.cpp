// 0044D050 RGE_Person_Info::get_current_campaign
//
// BLOCKER: behavior and call sequence are understood, but VC5 is in a stable
// loop-shape basin. The closest edit-diff source has the right saved registers,
// guard checks, call order, EDI index, campaign_num reload after failed compare,
// success/failure returns, but emits an extra pre-loop `test eax,eax; jle` after
// `xor edi,edi`; original performs only the initial `campaign_num` test and
// falls directly into the loop. Do/while/goto variants remove that extra test but
// peel the first iteration, using `[eax]` for campaigns[0] and duplicating the
// loop body. A count local avoids the duplicate test/peel but saves EBX and uses
// a different prologue basin.
//
// Attempt log:
// 1. Count local caused EBX save and wrong prologue.
// 2. Reload campaign_num from this each iteration: no EBX, but first iteration peeled.
// 3. Natural for-loop with reloaded bound: closest edit diff; extra pre-loop test shifts branches by 4 bytes.
// 4. Initializing i before the empty-loop check, `i >= campaign_num`, and explicit bottom-test goto all still peel or duplicate the test.
// 5. variant_lab over split/nested guards and countlocal/reload_do/reload_for/ptrloop shapes with vc5-small flags: no exact. Best edit family is reload_for (edit 26), best positional among no-EBX families is reload_do (pos 47.5) but with peeled first iteration and larger body.

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

    if (this->campaign_num <= 0) {
        return -1;
    }

    for (long i = 0; i < this->campaign_num; ++i) {
        if (this->campaign_info[this->current_campaign]->verify_campaign_name(this->campaigns[i]->get_name()) != 0) {
            return i;
        }
    }

    return -1;
}
