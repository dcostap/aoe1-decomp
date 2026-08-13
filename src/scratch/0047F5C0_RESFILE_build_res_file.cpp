// VA: 0047F5C0 RESFILE_build_res_file (1669B)
// Res_file.cpp lines 574-935
//
// Attempt log (owner DS4-7F5C0):
//   baseline 0: first reconstruction from packet/Ghidra decomp + PDB names.
//     Result: MISMATCH frame 0x4A0 (vs 0x4A4), size -28, fscanf 4/3 (loop
//     rotation), log 7/8 (tail-merge grouping), resHandle store eliminated
//     (frame -4).
//   probe control-flow: while(1)+break loop (fixes fscanf rotation), diagnostic
//     resHandle storage, swap data/temp decl.
//     Result: fscanf 3/3, log 8/8, frame still 0x4A0, size -19. Best state.
//   probe layout: header as 0x3C + separate directory_size local, original
//     decl order (temp before data). REGRESSED: frame 0x49C, size -34. Reverted.
//   Remaining gap (best state): frame 0x4A0 vs 0x4A4 (-4) and smalls placed at
//     F+0x00.. instead of F+0x10.. (target has 12B slack + ID_List slot at
//     F+0x0C below iq; build_filename overflows frame top by 12 in original).
//     VC5 slot-packing quirks: buildFile/resHandle slots share in my build but
//     not in the original; rPassword/theHeader overlap by 4 in the original
//     only. First mismatch is prologue sub esp,4A0h vs 4A4h.
//   ABI correction from stack accounting: the resource-name load at 0047F651
//     occurs before fscanf's 0x10-byte cleanup, so [esp+4D0] is the third
//     (target_path) argument; the data-name load at 0047F6B4 occurs after the
//     0x0C cleanup, so [esp+4BC] is the second (source_path) argument. Keep
//     the mangled three-parameter surface instead of inventing caller-stack
//     params.
//   PDB names: params build_list_file/source_path/target_path; locals incl.
//     resHandle (F+0x2C = 3rd dword of the id-dir record write) and dead
//     ID_List (F+0x0C). resfile_header per binary: version @ +0x28, password
//     @ +0x2C, num_res_types @ +0x38, directory_size @ +0x3C (write is 0x40
//     bytes from F+0x3C; rPassword at F+0x78 overlaps directory_size by 4).
//   bounded follow-up: typed FILE*/resource-file handles, PDB local declaration
//     order, the named ID_List cleanup owner, and the corrected three-parameter
//     path ABI were checked. The last correction moves the two path loads to the
//     target homes relative to the remaining frame gap; calls/CFG/size shape are
//     otherwise unchanged. Leave the natural source in scratch: the blocker is
//     one missing VC5 local-frame slot plus header-copy scheduling, not behavior.
//   Main-agent audit removed the diagnostic volatile/adjacent-stack write and
//     +4 buffer windows. The living source now uses ordinary buffers and writes
//     the complete typed ID-directory record; these compiler-steering artifacts
//     are not retained merely for byte proximity.
//   Follow-up: an ordinary resHandle local for the ID-record size was a codegen
//     duplicate and was rolled back; the frame gap remains unresolved.
//   Follow-up: reordered the typed predecessor and handle declarations; VC5
//     emitted the same frame and code. Scoped input/output handles also emitted
//     the same code. Restored the clean natural source.
//   Shard-E: PDB-named numResTypes/buildFile ABI spelling was a codegen
//     duplicate. A 0x3C header plus adjacent directory_size improved the
//     diagnostic diff to 633 but reduced the frame to 0x49C; it was not kept.
//     A banner_msg + 4 write, volatile ID_List home, and hoisted directory
//     counters produced no useful clean-source gain. Restored the 0x40 header.

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

int __cdecl RESFILE_build_res_file(char* build_list_file, char* source_path, char* target_path)
{
    char build_filename[260];
    char resource_filename[260];
    char data_filename[260];
    char temp_filename[260];
    char rPassword[40];
    resfile_header theHeader;
    resfile_type_dir_node typeDirNode;
    resfile_id_dir_node idDirNode;
    BuildRes_type_node* ID_List;
    BuildRes_type_node* iq;
    FILE* buildFile;
    int resourceFile;
    BuildRes_id_node* previous;
    unsigned long rId;

    iq = 0;
    rId = 0;

    sprintf(build_filename, "%s%s", source_path, build_list_file);

    buildFile = fopen(build_filename, "r");
    if (buildFile == 0) {
        Log(L, "Error: could not find resource build file: %s", build_list_file);
        return 0;
    }

    fscanf(buildFile, "%s %s", temp_filename, rPassword);
    sprintf(resource_filename, "%s%s", target_path, temp_filename);

    while (1) {
        if (fscanf(buildFile, "%s", temp_filename) == -1) break;
        if (fscanf(buildFile, "%d", &idDirNode.id) == -1) break;
        {
            unsigned long typeID;
            BuildRes_type_node* tnode;
            BuildRes_id_node* pNode;
            BuildRes_type_node* ins;
            BuildRes_type_node* found;
            int fd;
            long size;

            sprintf(data_filename, "%s%s", source_path, temp_filename);

            typeID = BUILDRES_get_files_resource_type(temp_filename);
            if (typeID == 0) {
                Log(L, "Error: could not determine file type of: %s", temp_filename);
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

            previous = 0;
            for (pNode = found->idList; pNode; pNode = pNode->next) {
                if (pNode->id == idDirNode.id) {
                    Log(L, "Error: duplicate resources: %s & %s", pNode->fName, data_filename);
                    return 0;
                }
                if (pNode->id < idDirNode.id) {
                    previous = pNode;
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
            strcpy(pNode->fName, data_filename);

            fd = _open(data_filename, 0x8000);
            if (fd == -1) {
                Log(L, "Error: unable to open file: %s", data_filename);
                delete pNode;
            } else {
                if (previous == 0) {
                    pNode->next = found->idList;
                    found->idList = pNode;
                } else {
                    pNode->next = previous->next;
                    previous->next = pNode;
                }
                found->nIds++;

                size = lseek(fd, 0, 2);
                lseek(fd, 0, 0);
                if (size <= 0) {
                    Log(L, "Error: file is empty/NULL: %s", data_filename);
                    return 0;
                }
                pNode->resData = (unsigned char*)malloc(size);
                if (pNode->resData == 0) {
                    Log(L, "Error: out of memory #3");
                    return 0;
                }
                pNode->resSize = size;
                if (read(fd, pNode->resData, size) != size) {
                    Log(L, "Error: error reading file: %s", data_filename);
                    return 0;
                }
                close(fd);
            }
        }
    }

    fclose(buildFile);
    resourceFile = _open(resource_filename, 0x8301, 0x180);
    if (resourceFile == -1) {
        Log(L, "Error: unable to create resource file file: %s", resource_filename);
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
        strcpy(theHeader.password, rPassword);

        theHeader.num_res_types = rId;
        theHeader.directory_size = dirSize;

        if (write(resourceFile, &theHeader, 0x40) != 0x40) {
            Log(L, "Error writing resource file header");
            return 0;
        }

        pos = 0x40;
        for (tnode = iq; tnode; tnode = tnode->next) {
            typeDirNode.type = tnode->type;
            typeDirNode.dirOffset = tnode->idOffset;
            typeDirNode.numID = tnode->nIds;
            if (write(resourceFile, &typeDirNode, 0xC) != 0xC) {
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
                idDirNode.id = pNode->id;
                idDirNode.itemOffset = pNode->dataOffset;
                idDirNode.itemSize = pNode->resSize;
                if (write(resourceFile, &idDirNode, sizeof(idDirNode)) != sizeof(idDirNode)) {
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
                if (write(resourceFile, pNode->resData, pNode->resSize) != pNode->resSize) {
                    Log(L, "Error writing resource file data");
                    return 0;
                }
                pos += pNode->resSize;
            }
        }
    }

    close(resourceFile);

    {
        BuildRes_id_node* pNode;
        ID_List = iq;
        for (; ID_List; ID_List = ID_List->next) {
            for (pNode = ID_List->idList; pNode; pNode = pNode->next) {
                if (pNode->resData != 0) {
                    free(pNode->resData);
                }
                delete pNode;
            }
            delete ID_List;
        }
    }

    return 1;
}
