// VA: 0047F5C0 RESFILE_build_res_file (1669B)
// Res_file.cpp lines 574-935
//
// Attempt log (owner DS4-7F5C0):
//   baseline 0: first reconstruction from packet/Ghidra decomp + PDB names.
//     Result: MISMATCH frame 0x4A0 (vs 0x4A4), size -28, fscanf 4/3 (loop
//     rotation), log 7/8 (tail-merge grouping), resHandle store eliminated
//     (frame -4).
//   probe control-flow: while(1)+break loop (fixes fscanf rotation), volatile
//     resHandle (keeps the binary-observed [F+2C] store), swap data/temp decl.
//     Result: fscanf 3/3, log 8/8, frame still 0x4A0, size -19. Best state.
//   probe layout: header as 0x3C + separate directory_size local, original
//     decl order (temp before data). REGRESSED: frame 0x49C, size -34. Reverted.
//   Remaining gap (best state): frame 0x4A0 vs 0x4A4 (-4) and smalls placed at
//     F+0x00.. instead of F+0x10.. (target has 12B slack + ID_List slot at
//     F+0x0C below iq; build_filename overflows frame top by 12 in original).
//     VC5 slot-packing quirks: buildFile/resHandle slots share in my build but
//     not in the original; rPassword/theHeader overlap by 4 in the original
//     only. First mismatch is prologue sub esp,4A0h vs 4A4h.
//   Binary quirk (modeled): the sprintf for resource_filename reads [entry+0x1C]
//     and the sprintf for data_filename reads [entry+0x18] -- 16/20 bytes ABOVE
//     param_3's home (E+0xC), while the PDB/mangled name declare exactly 3
//     char* params (?RESFILE_build_res_file@@YAHPAD00@Z, '00' = repeated-type
//     abbreviations). Callers (setup @ 00521822/3E/5A) push exactly 3 args
//     (add esp,0Ch). The original reads uninitialized caller-stack slots
//     (setup's saved EBX/EBP region); Ghidra's decompiler merged those reads
//     back into param_2/param_3 semantics. Modeled as params 6/7 so VC5 emits
//     the observed [esp+4BCh]/[esp+4D0h] stack reads. Params 4/5 unused.
//   PDB names: params build_list_file/source_path/target_path; locals incl.
//     resHandle (F+0x2C = 3rd dword of the id-dir record write) and dead
//     ID_List (F+0x0C). resfile_header per binary: version @ +0x28, password
//     @ +0x2C, num_res_types @ +0x38, directory_size @ +0x3C (write is 0x40
//     bytes from F+0x3C; rPassword at F+0x78 overlaps directory_size by 4).

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <io.h>

struct BuildRes_id_node {
    unsigned long id;           // +0x00
    int dataOffset;             // +0x04
    unsigned char* resData;     // +0x08
    int resSize;                // +0x0C
    BuildRes_id_node* next;     // +0x10
    char fName[260];            // +0x14 (0x104)
};

struct BuildRes_type_node {
    unsigned long type;         // +0x00
    int idOffset;               // +0x04
    int nIds;                   // +0x08
    BuildRes_id_node* idList;   // +0x0C
    BuildRes_type_node* next;   // +0x10
};

struct resfile_header {         // 0x40
    char banner_msg[40];        // +0x00
    char version[4];            // +0x28
    char password[12];          // +0x2C
    int num_res_types;          // +0x38
    int directory_size;         // +0x3C
};

struct resfile_id_dir_node {    // 0xC
    unsigned long id;
    long itemOffset;
    long itemSize;
};

struct resfile_type_dir_node {  // 0xC
    unsigned long type;
    long dirOffset;
    long numID;
};

class TDebuggingLog;
extern TDebuggingLog* L;
extern void Log(TDebuggingLog* log, char* fmt, ...);

extern unsigned long BUILDRES_get_files_resource_type(char* filename);

int __cdecl RESFILE_build_res_file(char* build_list_file, char* source_path, char* target_path, char* param_4, char* param_5, char* param_6, char* param_7)
{
    char build_filename[260];
    char resource_filename[260];
    char data_filename[260];
    char temp_filename[260];
    char rPassword[40];
    resfile_header theHeader;
    resfile_type_dir_node typeDirNode;
    volatile int resHandle;
    resfile_id_dir_node idDirNode;
    unsigned long rId;
    int numResTypes;
    BuildRes_id_node* buildFile;
    BuildRes_type_node* iq;
    BuildRes_type_node* ID_List;

    iq = 0;
    rId = 0;

    sprintf(build_filename + 4, "%s%s", source_path, build_list_file);

    numResTypes = (int)fopen(build_filename + 4, "r");
    if (numResTypes == 0) {
        Log(L, "Error: could not find resource build file: %s", build_list_file);
        return 0;
    }

    fscanf((FILE*)numResTypes, "%s %s", temp_filename + 4, rPassword + 4);
    sprintf(resource_filename + 4, "%s%s", param_7, temp_filename + 4);

    while (1) {
        if (fscanf((FILE*)numResTypes, "%s", temp_filename + 4) == -1) break;
        if (fscanf((FILE*)numResTypes, "%d", &idDirNode.id) == -1) break;
        {
            unsigned long typeID;
            BuildRes_type_node* tnode;
            BuildRes_id_node* pNode;
            BuildRes_type_node* ins;
            BuildRes_type_node* found;
            int fd;
            long size;

            sprintf(data_filename + 4, "%s%s", param_6, temp_filename + 4);

            typeID = BUILDRES_get_files_resource_type(temp_filename + 4);
            if (typeID == 0) {
                Log(L, "Error: could not determine file type of: %s", temp_filename + 4);
                return 0;
            }

            ins = 0;
            found = 0;
            for (tnode = iq; tnode; tnode = tnode->next) {
                if (tnode->type == typeID) {
                    found = tnode;
                    break;
                }
                if (tnode->type < typeID) {
                    ins = tnode;
                }
            }

            if (found == 0) {
                found = new BuildRes_type_node;
                if (found == 0) {
                    Log(L, "Error: out of memory #1");
                    return 0;
                }
                found->type = typeID;
                found->idOffset = 0;
                found->nIds = 0;
                found->idList = 0;
                found->next = 0;
                if (ins == 0) {
                    found->next = iq;
                    iq = found;
                } else {
                    found->next = ins->next;
                    ins->next = found;
                }
                rId++;
            }

            buildFile = 0;
            for (pNode = found->idList; pNode; pNode = pNode->next) {
                if (pNode->id == idDirNode.id) {
                    Log(L, "Error: duplicate resources: %s & %s", pNode->fName, data_filename + 4);
                    return 0;
                }
                if (pNode->id < idDirNode.id) {
                    buildFile = pNode;
                }
            }

            pNode = new BuildRes_id_node;
            if (pNode == 0) {
                Log(L, "Error: out of memory #2");
                return 0;
            }
            pNode->id = idDirNode.id;
            pNode->dataOffset = 0;
            pNode->resData = 0;
            pNode->resSize = 0;
            pNode->next = 0;
            strcpy(pNode->fName, data_filename + 4);

            fd = _open(data_filename + 4, 0x8000);
            if (fd == -1) {
                Log(L, "Error: unable to open file: %s", data_filename + 4);
                delete pNode;
            } else {
                if (buildFile == 0) {
                    pNode->next = found->idList;
                    found->idList = pNode;
                } else {
                    pNode->next = buildFile->next;
                    buildFile->next = pNode;
                }
                found->nIds++;

                size = lseek(fd, 0, 2);
                lseek(fd, 0, 0);
                if (size <= 0) {
                    Log(L, "Error: file is empty/NULL: %s", data_filename + 4);
                    return 0;
                }
                pNode->resData = (unsigned char*)malloc(size);
                if (pNode->resData == 0) {
                    Log(L, "Error: out of memory #3");
                    return 0;
                }
                pNode->resSize = size;
                if (read(fd, pNode->resData, size) != size) {
                    Log(L, "Error: error reading file: %s", data_filename + 4);
                    return 0;
                }
                close(fd);
            }
        }
    }

    fclose((FILE*)numResTypes);
    numResTypes = _open(resource_filename + 4, 0x8301, 0x180);
    if (numResTypes == -1) {
        Log(L, "Error: unable to create resource file file: %s", resource_filename + 4);
        return 0;
    }

    {
        int pos;
        int dirSize;
        BuildRes_type_node* tnode;
        BuildRes_id_node* pNode;

        pos = rId * 12 + 0x40;
        for (tnode = iq; tnode; tnode = tnode->next) {
            tnode->idOffset = pos;
            pos += tnode->nIds * 12;
        }
        dirSize = pos;
        for (tnode = iq; tnode; tnode = tnode->next) {
            for (pNode = tnode->idList; pNode; pNode = pNode->next) {
                pNode->dataOffset = pos;
                pos += pNode->resSize;
            }
        }

        memset(&theHeader, 0, 0x40);
        strcpy(theHeader.banner_msg, "Copyright (c) 1997 Ensemble Studios.\x1a");
        strcpy(theHeader.version, "1.00");
        strcpy(theHeader.password, rPassword + 4);

        theHeader.num_res_types = rId;
        theHeader.directory_size = dirSize;

        if (write(numResTypes, &theHeader, 0x40) != 0x40) {
            Log(L, "Error writing resource file header");
            return 0;
        }

        pos = 0x40;
        for (tnode = iq; tnode; tnode = tnode->next) {
            typeDirNode.type = tnode->type;
            typeDirNode.dirOffset = tnode->idOffset;
            typeDirNode.numID = tnode->nIds;
            if (write(numResTypes, &typeDirNode, 0xC) != 0xC) {
                Log(L, "Error writing resource file header: type node");
                return 0;
            }
            pos += 0xC;
        }

        for (tnode = iq; tnode; tnode = tnode->next) {
            if (pos != tnode->idOffset) {
                Log(L, "Error writing resource file: pos out of sync 1");
                return 0;
            }
            for (pNode = tnode->idList; pNode; pNode = pNode->next) {
                idDirNode.itemOffset = pNode->id;
                idDirNode.itemSize = pNode->dataOffset;
                resHandle = pNode->resSize;
                if (write(numResTypes, &idDirNode.itemOffset, 0xC) != 0xC) {
                    Log(L, "Error writing resource file header: id node");
                    return 0;
                }
                pos += 0xC;
            }
        }

        for (tnode = iq; tnode; tnode = tnode->next) {
            for (pNode = tnode->idList; pNode; pNode = pNode->next) {
                if (pos != pNode->dataOffset) {
                    Log(L, "Error writing resource file data: pos out of sync 2");
                    return 0;
                }
                if (write(numResTypes, pNode->resData, pNode->resSize) != pNode->resSize) {
                    Log(L, "Error writing resource file data");
                    return 0;
                }
                pos += pNode->resSize;
            }
        }
    }

    close(numResTypes);

    {
        BuildRes_type_node* tnode;
        BuildRes_id_node* pNode;
        for (tnode = iq; tnode; tnode = tnode->next) {
            for (pNode = tnode->idList; pNode; pNode = pNode->next) {
                if (pNode->resData != 0) {
                    free(pNode->resData);
                }
                delete pNode;
            }
            delete tnode;
        }
    }

    return 1;
}
