// tried a simple byte-by-byte loop; VC5 shrank it too far
// tried a two-byte unrolled compare with local temps; still landed in the wrong tiny-helper basin
// left in scratch because the remaining gap is codegen-family drift, not a behavior mismatch
// First-pass skeleton/partial — needs proper implementation
class RGE_Campaign_Info {
public:
    char campaign_name[255];

    unsigned char verify_campaign_name(char* campaign_name);
};

unsigned char RGE_Campaign_Info::verify_campaign_name(char* campaign_name)
{
    char* name;
    unsigned char result;
    unsigned char c1;
    unsigned char c2;

    name = this->campaign_name;
    while (1) {
        c1 = name[0];
        c2 = campaign_name[0];
        if (c1 != c2) {
            result = 0;
            break;
        }
        if (c1 == 0) {
            result = 1;
            break;
        }

        c1 = name[1];
        c2 = campaign_name[1];
        if (c1 != c2) {
            result = 0;
            break;
        }

        name = name + 2;
        campaign_name = campaign_name + 2;

        if (c1 == 0) {
            result = 1;
            break;
        }
    }

    return result;
}
