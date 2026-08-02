// VA: 00444040 TDrawArea::Init
// PDB source: Drawarea.cpp lines 1818-1874
// ACCEPTED_DRIFT: the sole byte difference is the second list-walk load using
// `[eax+8]` instead of `[ecx+8]` immediately after `mov ecx,eax`; both bases are
// therefore identical, and calls, memory effects, CFG, and all other bytes match.
// Baseline reconstruction: the DrawAreaNode list is owned by TDrawSystem.
// Attempt log:
// baseline: natural named TDrawSystem/TDrawArea fields, calloc node allocation,
//           and the Drawarea.cpp list insertion/SetSize control flow gave 199/199
//           bytes, correct calls/CFG, and one byte of drift.
// probes: alternate for/while/do-while and explicit cur/node update spellings,
//         narrow volatile reads/field qualification, and a proven raw +8 load
//         all emitted the same one-byte drift; an inline helper worsened structure.
// left in scratch: original +007F is `mov eax,[ecx+8]`, while the clean natural
// source emits `mov eax,[eax+8]`; all other 198 bytes, calls, and boundaries match.

void* __cdecl calloc(unsigned int count, unsigned int size);

class TDrawArea;

struct DrawAreaNode {
    TDrawArea* DrawArea;
    DrawAreaNode* PrevNode;
    DrawAreaNode* NextNode;
};

class TDrawSystem {
public:
    char gap_00[0x04];
    void* Wnd;                         // +0x04
    char gap_08[0x0C];
    DrawAreaNode* DrawAreaList;        // +0x14
    char gap_18[0x460];
    unsigned char DrawType;            // +0x478
};

class TDrawArea {
public:
    TDrawSystem* DrawSystem;           // +0x00
    void* Wnd;                         // +0x04
    char gap_08[0xA4];
    DrawAreaNode* Node;                // +0xAC
    char gap_B0[0x40];
    int IsPrimarySurface;              // +0xF0

    void SetSize(long width, long height, int flags);
    int Init(TDrawSystem* draw_system, long width, long height, int flags,
             int is_primary);
};

int TDrawArea::Init(TDrawSystem* draw_system, long width, long height,
                    int flags, int is_primary)
{
    DrawAreaNode* node;
    DrawAreaNode* cur;

    this->DrawSystem = draw_system;
    this->IsPrimarySurface = is_primary;
    if (draw_system != 0) {
        this->Wnd = draw_system->Wnd;
        if (this->Node == 0) {
            node = (DrawAreaNode*)calloc(1, 0x0C);
            this->Node = node;
            if (node == 0) {
                return 0;
            }

            node->DrawArea = this;
            this->Node->PrevNode = 0;
            this->Node->NextNode = 0;
            cur = this->DrawSystem->DrawAreaList;
            if (cur == 0) {
                this->DrawSystem->DrawAreaList = this->Node;
            } else {
                for (node = cur->NextNode; node != 0; node = node->NextNode) {
                    cur = node;
                }
                cur->NextNode = this->Node;
                this->Node->PrevNode = cur;
            }
        }

        if (this->DrawSystem->DrawType == 1) {
            return 0;
        }
    }

    this->SetSize(width, height, flags);
    return 1;
}
