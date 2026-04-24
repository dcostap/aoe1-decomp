// attempt 1: RXEntry class with index-based loop; wrong loop counter/register usage
// attempt 2: byte-offset loop with void* arithmetic; registers swapped (ebp=this, ebx=zero)
// attempt 3: unsigned int loop counter; same register swap issue
// attempt 4: same; VC5 picks ebp for this, ebx for zero, esi for counter
// attempt 5: same; loop bound adjust; same register swap
// Original uses ebx=this, ebp=zero, edi=counter, eax=base, esi=entry, edx=player
// VC5 uses ebp=this, ebx=zero, esi=counter, edi=base, ecx=player
// Left in scratch: benign register-allocation drift, behavior fully correct

class TCommunications_Handler {
public:
    char gap_00[0x1524];
    void* rx_base;
    char gap_1528[0x3C];
    unsigned int player_ids[16];

    void ClearRXForPlayer(unsigned int player);
};

void TCommunications_Handler::ClearRXForPlayer(unsigned int player) {
    void* base = rx_base;
    for (unsigned int i = 0; i < 0x2EF8; i += 0x18) {
        unsigned int id = *(unsigned int*)((char*)base + i + 0x0C);
        if (id == player_ids[player]) {
            void* ptr = *(void**)((char*)base + i);
            if (ptr != 0) {
                operator delete(ptr);
            }
            *(void**)((char*)base + i) = 0;
            *(void**)((char*)base + i + 4) = 0;
            *(void**)((char*)base + i + 8) = 0;
            *(void**)((char*)base + i + 0xC) = 0;
            *(void**)((char*)base + i + 0x10) = 0;
        }
    }
}
