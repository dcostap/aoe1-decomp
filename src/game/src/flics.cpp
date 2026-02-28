#include "RGE_Flic_Player.h"
#include "TDrawArea.h"

#include <cstdlib>
#include <cstring>
#include <fcntl.h>
#include <io.h>

// Fully verified. Source of truth: flics.cpp.decomp @ 0x00449B30
RGE_Flic_Player::RGE_Flic_Player(char* param_1) {
    int iVar1 = _open(param_1, 0x8000);
    if (-1 < iVar1) {
        _lseek(iVar1, 0, 2);
        long uVar2 = _tell(iVar1);
        uchar* puVar3 = (uchar*)calloc((size_t)uVar2, 1);
        this->flic_buffer = puVar3;
        _lseek(iVar1, 0, 0);
        _read(iVar1, this->flic_buffer, (unsigned int)uVar2);
        long* plVar5 = (long*)this->flic_buffer;
        FlicHead* pFVar6 = &this->flichead;
        for (int iVar4 = 0x21; iVar4 != 0; iVar4 = iVar4 + -1) {
            pFVar6->size = *plVar5;
            plVar5 = plVar5 + 1;
            pFVar6 = (FlicHead*)&pFVar6->type;
        }
        this->flic_width = (int)(this->flichead).width;
        this->start();
        _close(iVar1);
        return;
    }
    this->flic_buffer = (uchar*)0x0;
    this->flic_handle = -1;
}

// Fully verified. Source of truth: flics.cpp.decomp @ 0x00449BE0
RGE_Flic_Player::RGE_Flic_Player(int param_1) {
    if (-1 < param_1) {
        _read(param_1, &this->flichead, 0x84);
        this->flic_width = (int)(this->flichead).width;
        this->flic_handle = param_1;
        this->flic_buffer = (uchar*)0x0;
        this->start();
        return;
    }
    this->flic_buffer = (uchar*)0x0;
    this->flic_handle = -1;
}

// Fully verified. Source of truth: flics.cpp.decomp @ 0x00449C40
RGE_Flic_Player::~RGE_Flic_Player() {
    if (this->flic_buffer != (uchar*)0x0) {
        free(this->flic_buffer);
    }
}

// Fully verified. Source of truth: flics.cpp.decomp @ 0x00449C50
void RGE_Flic_Player::palette(tagRGBQUAD* param_1) {
    int* local_8 = (int*)0x0;
    intptr_t index1 = 0;
    int* piVar2 = nullptr;
    if (this->flic_handle < 0) {
        index1 = (intptr_t)(this->flichead).oframe2;
        piVar2 = (int*)(index1 + 0x10);
    } else {
        index1 = (intptr_t)calloc(1, 0x10);
        _lseek(this->flic_handle, (long)(this->flichead).oframe2, 0);
        _read(this->flic_handle, (void*)index1, 0x10);
        piVar2 = (int*)calloc((size_t)*(unsigned int*)index1, 1);
        _read(this->flic_handle, piVar2, (unsigned int)*(unsigned int*)index1);
        local_8 = piVar2;
    }

    char* temp_buffer = (char*)0x0;
    if (0 < *(short*)(index1 + 6)) {
        do {
            if ((short)piVar2[1] == 4) {
                int iVar5 = (int)*(short*)((intptr_t)piVar2 + 6);
                int iVar8 = 0;
                int* piVar3 = piVar2 + 2;
                if (0 < iVar5) {
                    do {
                        int iVar7 = (int)*(char*)((intptr_t)piVar3 + 1);
                        iVar8 = iVar8 + (char)*piVar3;
                        if (iVar7 == 0) {
                            iVar7 = 0x100;
                        }
                        piVar3 = (int*)((intptr_t)piVar3 + 2);
                        if (0 < iVar7) {
                            uchar* puVar6 = &param_1[iVar8].rgbGreen;
                            iVar8 = iVar8 + iVar7;
                            int* piVar4 = piVar3;
                            do {
                                piVar3 = (int*)((intptr_t)piVar4 + 3);
                                puVar6[1] = (uchar)*piVar4;
                                *puVar6 = *(uchar*)((intptr_t)piVar4 + 1);
                                ((tagRGBQUAD*)(puVar6 - 1))->rgbBlue = *(uchar*)((intptr_t)piVar4 + 2);
                                puVar6 = puVar6 + 4;
                                iVar7 = iVar7 + -1;
                                piVar4 = piVar3;
                            } while (iVar7 != 0);
                        }
                        iVar5 = iVar5 + -1;
                    } while (iVar5 != 0);
                }
            }
            if ((short)piVar2[1] == 0xb) {
                int iVar5 = (int)*(short*)((intptr_t)piVar2 + 6);
                int iVar8 = 0;
                int* piVar3 = piVar2 + 2;
                if (0 < iVar5) {
                    do {
                        int iVar7 = (int)*(char*)((intptr_t)piVar3 + 1);
                        iVar8 = iVar8 + (char)*piVar3;
                        if (iVar7 == 0) {
                            iVar7 = 0x100;
                        }
                        piVar3 = (int*)((intptr_t)piVar3 + 2);
                        if (0 < iVar7) {
                            tagRGBQUAD* ptVar1 = param_1 + iVar8;
                            iVar8 = iVar8 + iVar7;
                            uchar* puVar6 = &ptVar1->rgbGreen;
                            do {
                                puVar6[1] = (char)*piVar3 << 2;
                                *puVar6 = *(char*)((intptr_t)piVar3 + 1) << 2;
                                ((tagRGBQUAD*)(puVar6 - 1))->rgbBlue = *(char*)((intptr_t)piVar3 + 2) << 2;
                                piVar3 = (int*)((intptr_t)piVar3 + 3);
                                iVar7 = iVar7 + -1;
                                puVar6 = puVar6 + 4;
                            } while (iVar7 != 0);
                        }
                        iVar5 = iVar5 + -1;
                    } while (iVar5 != 0);
                }
            }
            piVar2 = (int*)((intptr_t)piVar2 + *piVar2);
            temp_buffer = temp_buffer + 1;
        } while ((intptr_t)temp_buffer < (intptr_t)*(short*)(index1 + 6));
    }
    if (-1 < this->flic_handle) {
        if (index1 != 0) {
            free((void*)index1);
        }
        if (local_8 != (int*)0x0) {
            free(local_8);
        }
    }
}

// Fully verified. Source of truth: flics.cpp.decomp @ 0x00449DF0
long RGE_Flic_Player::resolution() {
    return (int)(this->flichead).width << 0x10 | (int)(this->flichead).height;
}

// Fully verified. Source of truth: flics.cpp.decomp @ 0x00449E00
long RGE_Flic_Player::time_delay() {
    return (this->flichead).speed;
}

// Fully verified. Source of truth: flics.cpp.decomp @ 0x00449E10
short RGE_Flic_Player::frames() {
    return (this->flichead).frames;
}

// Fully verified. Source of truth: flics.cpp.decomp @ 0x00449E20
void RGE_Flic_Player::start() {
    ushort uVar1 = (this->flichead).type;
    if (uVar1 == 0xaf11) {
        (this->flichead).oframe1 = (char*)(this->flic_buffer + 0x84);
        (this->flichead).speed = ((this->flichead).speed * 1000) / 0x46;
    } else if (uVar1 == 0xaf12) {
        char* pcVar2 = (this->flichead).oframe1 + (intptr_t)this->flic_buffer;
        (this->flichead).oframe1 = pcVar2;
        (this->flichead).oframe2 = pcVar2;
        return;
    }
    (this->flichead).oframe2 = (this->flichead).oframe1;
}

// Fully verified. Source of truth: flics.cpp.decomp @ 0x00449E80
void RGE_Flic_Player::reset() {
    (this->flichead).oframe2 = (this->flichead).oframe1;
}

// Fully verified. Source of truth: flics.cpp.decomp @ 0x00449E90
uchar RGE_Flic_Player::draw(TDrawArea* param_1, long param_2, long param_3) {
    int* local_4 = (int*)0x0;
    int* piVar4 = nullptr;
    int* piVar5 = nullptr;
    if (this->flic_handle < 0) {
        piVar4 = (int*)(this->flichead).oframe2;
        piVar5 = piVar4 + 4;
    } else {
        piVar4 = (int*)calloc(1, 0x10);
        _lseek(this->flic_handle, (long)(this->flichead).oframe2, 0);
        _read(this->flic_handle, piVar4, 0x10);
        piVar5 = (int*)calloc((size_t)*piVar4, 1);
        _read(this->flic_handle, piVar5, (unsigned int)*piVar4);
        local_4 = piVar5;
    }
    short sVar1 = (this->flichead).width;
    this->x1 = param_2;
    this->drawarea = param_1;
    short sVar2 = (this->flichead).height;
    this->x2 = sVar1 + param_2;
    this->y1 = param_3;
    this->y2 = sVar2 + param_3;
    long lVar6 = param_1->AlignedWidth();
    int iVar7 = (int)(lVar6 * param_1->Orien);
    this->drawarea_width = iVar7;
    if (param_1->Orien < 1) {
        this->window_buffer = param_1->Bits + this->x1 + ((this->y1 - param_1->Height) + 1) * iVar7;
    } else {
        this->window_buffer = param_1->Bits + this->x1 + iVar7 * this->y1;
    }
    iVar7 = 0;
    this->save_buffer = this->window_buffer;
    if (0 < *(short*)((intptr_t)piVar4 + 6)) {
        do {
            this->chunk = (char*)((intptr_t)piVar5 + 6);
            switch ((short)piVar5[1]) {
            case 7:
                this->delta_flc();
                break;
            case 0xc:
                this->delta_fli();
                break;
            case 0xd:
                this->black();
                break;
            case 0xf:
                this->byte_run();
                break;
            case 0x10:
                this->literal();
            }
            piVar5 = (int*)((intptr_t)piVar5 + *piVar5);
            iVar7 = iVar7 + 1;
        } while (iVar7 < *(short*)((intptr_t)piVar4 + 6));
    }
    uchar* puVar3 = this->flic_buffer;
    char* pcVar9 = (this->flichead).oframe2 + *piVar4;
    (this->flichead).oframe2 = pcVar9;
    uchar uVar8;
    if ((intptr_t)pcVar9 - (intptr_t)puVar3 < (this->flichead).size) {
        uVar8 = '\0';
    } else {
        piVar5 = (int*)(this->flichead).oframe1;
        (this->flichead).oframe2 = (char*)piVar5;
        if (puVar3 != (uchar*)0x0) {
            (this->flichead).oframe2 = (char*)((intptr_t)piVar5 + *piVar5);
        }
        uVar8 = '\x02';
    }
    if (-1 < this->flic_handle) {
        if (piVar4 != (int*)0x0) {
            free(piVar4);
        }
        if (local_4 != (int*)0x0) {
            free(local_4);
        }
    }
    return uVar8;
}

// Fully verified. Source of truth: flics.cpp.decomp @ 0x0044A05D
void FUN_0044a05d() {
}

// Fully verified. Source of truth: flics.cpp.decomp @ 0x0044A090
void RGE_Flic_Player::literal() {
    int iVar3 = 0;
    if (0 < this->flic_size_y) {
        do {
            uint uVar2 = (uint)this->flic_size_x;
            uchar* puVar4 = (uchar*)this->chunk;
            uchar* puVar5 = this->window_buffer;
            for (uint uVar1 = uVar2 >> 2; uVar1 != 0; uVar1 = uVar1 - 1) {
                *(uint32_t*)puVar5 = *(uint32_t*)puVar4;
                puVar4 = puVar4 + 4;
                puVar5 = puVar5 + 4;
            }
            for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
                *puVar5 = *puVar4;
                puVar4 = puVar4 + 1;
                puVar5 = puVar5 + 1;
            }
            this->window_buffer = this->window_buffer + this->drawarea_width;
            iVar3 = iVar3 + 1;
            this->chunk = this->chunk + this->flic_width;
        } while (iVar3 < this->flic_size_y);
    }
}

// Fully verified. Source of truth: flics.cpp.decomp @ 0x0044A100
void RGE_Flic_Player::delta_flc() {
    int local_4 = (int)*(short*)this->chunk;
    ushort* puVar8 = (ushort*)((intptr_t)this->chunk + 2);
    if (0 < local_4) {
        do {
            bool bVar4 = false;
            ushort* puVar7 = puVar8;
            ushort uVar9 = 0;
            do {
                ushort uVar2 = *puVar7;
                uVar9 = 0;
                puVar8 = puVar7 + 1;
                ushort uVar3 = uVar2 >> 0xe;
                if (uVar3 == 0) {
                    uVar9 = uVar2;
                    bVar4 = true;
                } else {
                    if (uVar3 == 2) {
                        this->window_buffer[this->flic_width - 1] = (uchar)uVar2;
                        uVar2 = *puVar8;
                        puVar8 = puVar7 + 2;
                        uVar9 = uVar2;
                        bVar4 = true;
                    } else if (uVar3 == 3) {
                        uchar* puVar10 = this->save_buffer;
                        this->save_buffer = puVar10 + this->drawarea_width * (int)(short)-uVar2;
                        this->window_buffer = puVar10 + this->drawarea_width * (int)(short)-uVar2;
                    }
                }
                puVar7 = puVar8;
            } while (!bVar4);
            if (0 < (short)uVar9) {
                int local_8 = (int)(short)uVar9;
                do {
                    ushort uVar2 = *puVar8;
                    uchar* puVar10 = this->window_buffer;
                    this->window_buffer = puVar10 + (char)uVar2;
                    char cVar1 = *(char*)((intptr_t)puVar8 + 1);
                    puVar7 = puVar8 + 1;
                    if (cVar1 < '\x01') {
                        uint uVar5 = (uint)(cVar1 * -2);
                        if (1 < (int)uVar5) {
                            uint uVar6 = uVar5 >> 1;
                            do {
                                uVar5 = uVar5 - 2;
                                *(ushort*)this->window_buffer = *puVar7;
                                uVar6 = uVar6 - 1;
                                this->window_buffer = this->window_buffer + 2;
                            } while (uVar6 != 0);
                        }
                        if (uVar5 == 1) {
                            *this->window_buffer = (uchar)*puVar7;
                            this->window_buffer = this->window_buffer + 1;
                        }
                        puVar8 = puVar8 + 2;
                    } else {
                        uint uVar6 = (uint)(cVar1 * 2);
                        puVar8 = puVar7;
                        puVar10 = puVar10 + (char)uVar2;
                        for (uint uVar5 = uVar6 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
                            *(uint32_t*)puVar10 = *(uint32_t*)puVar8;
                            puVar8 = puVar8 + 2;
                            puVar10 = puVar10 + 4;
                        }
                        for (uint uVar5 = uVar6 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
                            *puVar10 = (uchar)*puVar8;
                            puVar8 = (ushort*)((intptr_t)puVar8 + 1);
                            puVar10 = puVar10 + 1;
                        }
                        puVar8 = puVar7 + cVar1;
                        this->window_buffer = this->window_buffer + uVar6;
                    }
                    local_8 = local_8 + -1;
                } while (local_8 != 0);
            }
            this->window_buffer = this->save_buffer + this->drawarea_width;
            local_4 = local_4 + -1;
            this->save_buffer = this->save_buffer + this->drawarea_width;
        } while (local_4 != 0);
    }
}

// Fully verified. Source of truth: flics.cpp.decomp @ 0x0044A2A0
void RGE_Flic_Player::delta_fli() {
    long cur_x = *(long*)this->chunk;
    int* piVar6 = (int*)((intptr_t)this->chunk + 8);
    if (0 < cur_x) {
        do {
            int local_c = (int)(char)*piVar6;
            int iVar5 = 0;
            piVar6 = (int*)((intptr_t)piVar6 + 1);
            if (0 < local_c) {
                do {
                    iVar5 = iVar5 + (char)*piVar6;
                    char cVar1 = *(char*)((intptr_t)piVar6 + 1);
                    uchar* puVar7 = (uchar*)((intptr_t)piVar6 + 2);
                    uint uVar4 = 0;
                    if (cVar1 < '\0') {
                        uVar4 = (uint)-cVar1;
                        uchar uVar2 = *puVar7;
                        puVar7 = this->window_buffer + iVar5;
                        for (uint uVar3 = uVar4 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
                            *(uint32_t*)puVar7 = (uint32_t)uVar2 | ((uint32_t)uVar2 << 8) | ((uint32_t)uVar2 << 16) | ((uint32_t)uVar2 << 24);
                            puVar7 = puVar7 + 4;
                        }
                        piVar6 = (int*)((intptr_t)piVar6 + 3);
                        for (uint uVar3 = uVar4 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
                            *puVar7 = uVar2;
                            puVar7 = puVar7 + 1;
                        }
                    } else {
                        uVar4 = (uint)cVar1;
                        uchar* puVar8 = puVar7;
                        uchar* puVar9 = this->window_buffer + iVar5;
                        for (uint uVar3 = uVar4 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
                            *(uint32_t*)puVar9 = *(uint32_t*)puVar8;
                            puVar8 = puVar8 + 4;
                            puVar9 = puVar9 + 4;
                        }
                        piVar6 = (int*)(puVar7 + uVar4);
                        for (uint uVar3 = uVar4 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
                            *puVar9 = *puVar8;
                            puVar8 = puVar8 + 1;
                            puVar9 = puVar9 + 1;
                        }
                    }
                    iVar5 = iVar5 + uVar4;
                    local_c = local_c + -1;
                } while (local_c != 0);
            }
            cur_x = cur_x + -1;
            this->window_buffer = this->window_buffer + this->drawarea_width;
        } while (cur_x != 0);
    }
}

// Fully verified. Source of truth: flics.cpp.decomp @ 0x0044A390
void RGE_Flic_Player::black() {
    int iVar3 = 0;
    if (0 < this->flic_size_y) {
        do {
            uint uVar2 = (uint)this->flic_size_x;
            uchar* puVar4 = this->window_buffer;
            for (uint uVar1 = uVar2 >> 2; uVar1 != 0; uVar1 = uVar1 - 1) {
                puVar4[0] = '\0';
                puVar4[1] = '\0';
                puVar4[2] = '\0';
                puVar4[3] = '\0';
                puVar4 = puVar4 + 4;
            }
            for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
                *puVar4 = '\0';
                puVar4 = puVar4 + 1;
            }
            iVar3 = iVar3 + 1;
            this->window_buffer = this->window_buffer + this->drawarea_width;
        } while (iVar3 < this->flic_size_y);
    }
}

// Fully verified. Source of truth: flics.cpp.decomp @ 0x0044A3E0
void RGE_Flic_Player::byte_run() {
    uchar* puVar3 = (uchar*)this->chunk;
    int local_4 = this->y1 - 1 + this->flic_size_y;
    if (-1 < local_4) {
        local_4 = local_4 + 1;
        do {
            puVar3 = puVar3 + 1;
            int local_8 = 0;
            do {
                uchar uVar1 = *puVar3;
                uchar* puVar4 = puVar3 + 1;
                uint uVar5;
                if ((char)uVar1 < '\0') {
                    uVar5 = (uint)(char)-uVar1;
                    uchar* puVar6 = puVar4;
                    uchar* puVar7 = this->window_buffer + local_8;
                    for (uint uVar2 = uVar5 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
                        *(uint32_t*)puVar7 = *(uint32_t*)puVar6;
                        puVar6 = puVar6 + 4;
                        puVar7 = puVar7 + 4;
                    }
                    puVar3 = puVar4 + uVar5;
                    for (uint uVar2 = uVar5 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
                        *puVar7 = *puVar6;
                        puVar6 = puVar6 + 1;
                        puVar7 = puVar7 + 1;
                    }
                } else {
                    uVar5 = (uint)(char)uVar1;
                    uVar1 = *puVar4;
                    puVar4 = this->window_buffer + local_8;
                    for (uint uVar2 = uVar5 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
                        *(uint32_t*)puVar4 = (uint32_t)uVar1 | ((uint32_t)uVar1 << 8) | ((uint32_t)uVar1 << 16) | ((uint32_t)uVar1 << 24);
                        puVar4 = puVar4 + 4;
                    }
                    puVar3 = puVar3 + 2;
                    for (uint uVar2 = uVar5 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
                        *puVar4 = uVar1;
                        puVar4 = puVar4 + 1;
                    }
                }
                local_8 = local_8 + uVar5;
            } while (local_8 < this->flic_width);
            local_4 = local_4 + -1;
            this->window_buffer = this->window_buffer + this->drawarea_width;
        } while (local_4 != 0);
    }
}
