// VA: 00451B10 RGE_Master_Moving_Object::RGE_Master_Moving_Object (constructor)
// PDB source: m_mo_obj.cpp
// FLAGS: config/flags/00451B10_RGE_Master_Moving_Object.rsp uses /GX for original EH frame.
//
// Attempt log:
// - Initial scratch used a fake base struct and explicit ctor_init call; this lost real constructor/EH lowering
//   and produced only an 80-byte text body.
// - SpruceGlow try 1 MATCH: model real inheritance from RGE_Master_Animated_Object with a visible virtual dtor and
//   natural base-constructor initializer. Use int for the sprite/sound index parameter, matching the already-matched
//   0044FAB0 base constructor surface and avoiding movsx/register drift. VC5 emits the exact EH frame, automatic
//   derived vtable store, optional setup call, and return-this epilogue.
// Result: MATCH locally with `python tools/check_function.py --va 00451B10`.

#ifndef RGE_MO_OBJ_SHARED_CONTEXT
class RGE_Master_Animated_Object {
public:
    virtual ~RGE_Master_Animated_Object();
    RGE_Master_Animated_Object(void* stream, void** sprites, void** sounds, int index, int flag);
};

class RGE_Master_Moving_Object : public RGE_Master_Animated_Object {
public:
    char gap_04[0xD4];

    int setup(void* stream, void** sprites, void** sounds, int index);
    RGE_Master_Moving_Object(void* stream, void** sprites, void** sounds, int index, int flag);
};
#endif

RGE_Master_Moving_Object::RGE_Master_Moving_Object(void* stream, void** sprites, void** sounds, int index, int flag)
    : RGE_Master_Animated_Object(stream, sprites, sounds, index, 0)
{
    if (flag != 0) {
        this->setup(stream, sprites, sounds, index);
    }
}
