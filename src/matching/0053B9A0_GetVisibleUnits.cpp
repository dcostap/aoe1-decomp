// vis_unit.cpp target: Visible_Unit_Manager::GetVisibleUnits
//
// BINARY NOTE: The PDB maps the shipped scan one instruction per source line.
// It also preserves labels such as start, scan_list, do_ypos, and empty_list.
// Lines 302-304 map to pushes of EBX, ESI, and EDI. These facts identify
// hand-written assembly. The user approved its recovery for this function.
//
// Recovery notes:
// - Natural typed C++ reached 381 bytes with 279 positional differences.
// - A C++ setup plus the recovered scan reached exact size and frame shape.
// - The remaining setup stores depend on direct assembly parameter-home reads.
// - The complete approved recovery matches all 387 bytes with default flags.

struct VisibleUnitRec {
    int object_id;
    unsigned char distance;
    unsigned char player;
    unsigned char pos_x;
    unsigned char pos_y;
};

struct VisibleUnitPtr {
    VisibleUnitRec* unit_list;
    short list_size;
    unsigned short used;
};

extern VisibleUnitRec* VisibleUnitList[5];
extern int VisibleUnitList_Size[5];

class Visible_Unit_Manager {
public:
    VisibleUnitPtr** PlayerDataPtrs;
    VisibleUnitRec* Return_Buffer[5];
    int Player_Count;
    int Category_Count;
    unsigned char* distanceTable;

    int GetVisibleUnits(int x, int y, int distance, int player, int* categories, int category_count, int* player_map);
};

__declspec(naked) int Visible_Unit_Manager::GetVisibleUnits(int, int, int, int, int*, int, int*) {
    __asm {
        push ebp
        mov ebp, esp
        sub esp, 1ch
        mov eax, [ebp+1ch]
        xor edx, edx
        push ebx
        push esi
        cmp eax, edx
        push edi
        mov [ebp-4], edx
        jg category_count_ok
        xor eax, eax
        pop edi
        pop esi
        pop ebx
        mov esp, ebp
        pop ebp
        ret 1ch
category_count_ok:
        mov esi, [ebp+14h]
        mov eax, [ecx+18h]
        cmp esi, eax
        jl player_ok
        xor eax, eax
        pop edi
        pop esi
        pop ebx
        mov esp, ebp
        pop ebp
        ret 1ch
player_ok:
        mov eax, [ebp+10h]
        cmp eax, 0fh
        jle distance_ok
        mov eax, 0fh
        mov [ebp+10h], eax
distance_ok:
        mov edi, [ecx]
        mov ecx, [ecx+20h]
        mov [ebp+14h], ecx
        mov ecx, [ebp+8]
        mov esi, [edi+esi*4]
        mov VisibleUnitList_Size, edx
        mov VisibleUnitList_Size[4], edx
        mov VisibleUnitList_Size[8], edx
        mov VisibleUnitList_Size[0ch], edx
        mov VisibleUnitList_Size[10h], edx
        mov edx, ecx
        add ecx, eax
        sub edx, eax
        mov [ebp-14h], ecx
        mov ecx, [ebp+0ch]
        mov [ebp-10h], edx
        mov edx, ecx
        mov [ebp-18h], esi
        sub edx, eax
        add eax, ecx
        mov [ebp-8], edx
        mov [ebp-0ch], eax
        push ebx
        push esi
        push edi
start:
        mov ebx, [ebp+18h]
        mov eax, [ebx]
        add ebx, 4
        mov [ebp+18h], ebx
        mov edx, [ebp-18h]
        lea ebx, [edx+eax*8]
        mov esi, [ebx]
        mov ecx, [ebx+6]
        and ecx, 0ffffh
        jz empty_list
        mov [ebp-1ch], ecx
scan_list:
        mov eax, 0
        mov al, [esi+6]
        cmp eax, [ebp-14h]
        jg next_entry
        cmp eax, [ebp+8]
        jge do_ypos2
        cmp eax, [ebp-10h]
        jl next_entry
        mov edx, [ebp+8]
        sub edx, eax
        jmp do_ypos
do_ypos2:
        sub eax, [ebp+8]
        mov edx, eax
do_ypos:
        mov eax, 0
        and edx, 0fh
        mov al, [esi+7]
        cmp eax, [ebp-0ch]
        jg next_entry
        cmp eax, [ebp+0ch]
        jge do_dist2
        cmp eax, [ebp-8]
        jl next_entry
        mov ecx, [ebp+0ch]
        sub ecx, eax
        jmp do_dist
do_dist2:
        sub eax, [ebp+0ch]
        mov ecx, eax
do_dist:
        and ecx, 0fh
        mov eax, 0
        shl ecx, 4
        mov ebx, [ebp+14h]
        add edx, ecx
        mov al, [ebx+edx]
        cmp eax, [ebp+10h]
        jg next_entry
        mov edx, eax
        mov al, [esi+5]
        mov edi, [ebp+20h]
        mov eax, [edi+eax*4]
        mov ecx, VisibleUnitList_Size[eax*4]
        cmp ecx, 100h
        jge next_entry
        mov edi, VisibleUnitList[eax*4]
        mov ebx, [ebp-4]
        lea edi, [edi+ecx*8]
        inc ecx
        mov VisibleUnitList_Size[eax*4], ecx
        mov eax, [esi+4]
        mov ecx, [esi]
        mov al, dl
        inc ebx
        mov [edi], ecx
        mov [edi+4], eax
        mov [ebp-4], ebx
next_entry:
        add esi, 8
        dec dword ptr [ebp-1ch]
        jne scan_list
empty_list:
        dec dword ptr [ebp+1ch]
        jne start
        pop edi
        pop esi
        pop ebx
        mov eax, [ebp-4]
        pop edi
        pop esi
        pop ebx
        mov esp, ebp
        pop ebp
        ret 1ch
    }
}
