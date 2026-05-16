// VA: 004C4360 RGE_Static_Object::save(int)
// Attempt log:
// 1: natural decompiler source with raw byte-offset layout and rge_write calls; incomplete first pass compiled too small.
// 2: completed group/pathing loops; 34.17% diff, frame 0x0c vs original 0x08 due extra durable temp.
// 3: reuse incoming `file` parameter as serialized int temp; still 0x0c frame and worse scheduling.
// 4: collapse sprite/inside temporaries to one address-taken local to probe 0x08 frame recovery; recovered frame/prologue and exact through offset 0x4D.
// 5: using one temp worsens semantic stack-slot placement vs original two logical slots (`[esp+10]` and `[esp+14]`), first mismatch becomes temp slot/sign-extension.
// 6: unsigned short load tried implicitly via cast; worsened to movzx/movsx family. Original wants `mov ax,[eax+72]; mov [slot],eax` preserving high half from -1.
// 7: natural `new int[i+1]`/`delete[]` gives right operator new/delete calls but later loop has shifted local slot and branch/register drift.
// 8: parameter-slot reuse for group/path temp attempted (`file = count/id`), but with separate saved handle local it kept 0x0c frame; rolled into current best.
// 9: raw byte-offset layout keeps all rge_write offsets/order correct through scalar field sequence.
// 10: no inline asm/custom flags; left in scratch at best 33.2916% positional / 18.3980% edit, not accepted-drift-safe.

extern "C" void __cdecl rge_write(int file, void* buf, int len);
class RGE_Active_Sprite_List { public: void save(int file); };
class RGE_Static_Object { public: char data[0x88]; void save(int file); };
#define PTR(o) ((char*)this + (o))
#define I(o) (*(int*)PTR(o))

void RGE_Static_Object::save(int file)
{
    int val;
    int saved_file = file;
    int i;
    int j;
    int* nv;

    rge_write(saved_file, PTR(0x4e), 1); rge_write(saved_file, (char*)I(0x0c) + 0x4a, 1); rge_write(saved_file, (char*)I(0x08) + 0x10, 2);
    if (I(0x10) == 0) val = -1; else val = *(short*)((char*)I(0x10) + 0x72);
    rge_write(saved_file, &val, 2);
    if (I(0x20) == 0) val = -1; else val = *(int*)((char*)I(0x20) + 4);
    rge_write(saved_file, &val, 4);
    rge_write(saved_file, PTR(0x30), 4); rge_write(saved_file, PTR(0x48), 1); rge_write(saved_file, PTR(0x49), 1); rge_write(saved_file, PTR(0x4a), 1); rge_write(saved_file, PTR(0x4b), 1); rge_write(saved_file, PTR(0x04), 4); rge_write(saved_file, PTR(0x35), 1); rge_write(saved_file, PTR(0x38), 4); rge_write(saved_file, PTR(0x3c), 4); rge_write(saved_file, PTR(0x40), 4); rge_write(saved_file, PTR(0x28), 2); rge_write(saved_file, PTR(0x2a), 2); rge_write(saved_file, PTR(0x2c), 2); rge_write(saved_file, PTR(0x2e), 2); rge_write(saved_file, PTR(0x37), 1); rge_write(saved_file, PTR(0x4c), 2); rge_write(saved_file, PTR(0x44), 4); rge_write(saved_file, PTR(0x4f), 1); rge_write(saved_file, PTR(0x34), 1); rge_write(saved_file, PTR(0x86), 1); rge_write(saved_file, PTR(0x78), 4); rge_write(saved_file, PTR(0x80), 4);

    file = I(0x68); rge_write(saved_file, &file, 4); i = 0;
    if (I(0x68) > 0) do {
        if (i > I(0x70) - 1) { nv = new int[i + 1]; if (nv != 0) { j = 0; if (I(0x70) > 0) do { if (j >= i + 1) break; j++; nv[j-1] = ((int*)I(0x64))[j-1]; } while (j < I(0x70)); delete [] (int*)I(0x64); I(0x64) = (int)nv; I(0x70) = i + 1; } }
        file = ((int*)I(0x64))[i]; rge_write(saved_file, &file, 4); i++;
    } while (i < I(0x68));

    file = I(0x58); rge_write(saved_file, &file, 4); i = 0;
    if (I(0x58) > 0) do {
        if (i > I(0x60) - 1) { nv = new int[i + 1]; if (nv != 0) { j = 0; if (I(0x60) > 0) do { if (j >= i + 1) break; j++; nv[j-1] = ((int*)I(0x54))[j-1]; } while (j < I(0x60)); delete [] (int*)I(0x54); I(0x54) = (int)nv; I(0x60) = i + 1; } }
        file = ((int*)I(0x54))[i]; rge_write(saved_file, &file, 4); i++;
    } while (i < I(0x58));
    ((RGE_Active_Sprite_List*)I(0x18))->save(saved_file);
}
