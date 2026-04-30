// VA: 0041B560 frame_passed (44B, asprite.cpp)
// Checks if the sprite's animation frame has crossed a target threshold.
// Returns 1 if the frame has passed, considering frame_changed/looped flags.
//
// Attempt log:
// - Using `this->frame >= target` generates correct `cmp [ecx+14h],ax` operand order
// - Remaining: frame_looped check uses inline return vs shared jne target
// - Return value width: unsigned char generates 8-bit mov al/xor al
// Left in scratch: small register scheduling / branch layout diff

class RGE_Active_Animated_Sprite {
public:
    char gap_00[0x14];
    short frame;              // +0x14
    char gap_16[0x0A];
    short last_frame;         // +0x20
    unsigned char frame_changed; // +0x22
    unsigned char frame_looped;  // +0x23

    unsigned char frame_passed(short param_1);
};

unsigned char RGE_Active_Animated_Sprite::frame_passed(short param_1) {
    if (this->frame_changed == 0) return 0;
    if (this->frame_looped != 0) return 1;
    if (this->frame >= param_1 && this->last_frame < param_1) return 1;
    return 0;
}
