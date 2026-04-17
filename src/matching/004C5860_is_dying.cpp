class RGE_Static_Object {
public:
    char gap_00[0x48];
    unsigned char object_state;

    unsigned char is_dying(void);
};

unsigned char RGE_Static_Object::is_dying(void) {
    if (object_state >= 3 && object_state != 6) {
        return 1;
    }
    return 0;
}
