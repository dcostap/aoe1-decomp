// VA: 0044B2B0
// PointMaker::MakeArrays()
// Source: fractal.cpp lines 194-206

// attempt log:
// 1. for(int i) for(int j) -> VC5 scope error
// 2. do-while(--count) -> 36% diff, wrong loop shape (compiler merged alloc check into condition)
// 3. do-while(count--) -> 41% diff, same problem + extra test eax,je after counter check
// 4. while(==0 && count--) -> 32% diff, short-circuit evaluation changed structure
// 5. while(==0){alloc;if(--count==0)break} -> 32% diff, compiler still added alloc check to loop condition
// 6. do{if(==0)alloc}while(--count>=0) -> 51% diff, counter start changed (0Ah vs 09) and loop uses dec;jne instead of original mov/dec/test/jne pattern
// 
// Left in scratch: persistent codegen-family problem. Original loop has:
//   mov edx, edi; dec edi; test edx, edx; jne
// (save counter, decrement, check saved pre-decrement value)
// Every natural C form produces either dec; jne (checking post-decrement) or adds an
// extra allocation-result check. The multiply operand order (Height*Width) is also
// reversed by the compiler. Needs variant_lab to find the winning basin.

void* __cdecl operator_new(unsigned int size);

class PointMaker {
public:
    char gap_000[0xFD4];
    int Width;           // +0xFD4
    int Height;          // +0xFD8
    char gap_FDC[0x28];
    int SizeArrays;      // +0x1004
    char gap_1008[0x1C];
    char* ProbArray;     // +0x1024
    char* PlacementArray;// +0x1028

    void MakeArrays();
};

void PointMaker::MakeArrays() {
    this->SizeArrays = this->Height * this->Width;

    int count = 9;
    do {
        if (this->ProbArray == 0) {
            this->ProbArray = (char*)operator_new(this->SizeArrays);
        }
        count--;
    } while (count >= 0);

    count = 9;
    do {
        if (this->PlacementArray == 0) {
            this->PlacementArray = (char*)operator_new(this->SizeArrays);
        }
        count--;
    } while (count >= 0);
}
