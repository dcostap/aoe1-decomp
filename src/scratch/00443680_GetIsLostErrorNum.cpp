class TDrawSystem {
public:
    int GetIsLostErrorNum(long error_num);
};

// tried a direct if/else ladder; VC5 inverted the outer branch and moved the zero check deeper
// tried an explicit goto/high-label shape; VC5 expanded the high path and exceeded the target size
// tried signed literals; the compiler still drifted, so this version keeps the high path separate
int TDrawSystem::GetIsLostErrorNum(long error_num)
{
    if (error_num > 0x88760082)
    {
        if (error_num == 0x887601C2)
            return 0x6A6;
    }

    if (error_num == 0x88760082)
        return 0x6A4;

    if (error_num == 0x80070057)
        return 0x6A5;

    if (error_num == 0)
        return 0;

    return 0x707;
}
