#pragma once
#include "../common.h"

void RESFILE_open_new_resource_file(char* param_1, char* param_2, char* param_3, int param_4);
void RESFILE_close_new_resource_file(char* param_1);
int RESFILE_locate_resource(ulong param_1, ulong param_2, int* param_3, int* param_4, uchar** param_5, int* param_6);
uchar* RESFILE_load(ulong param_1, ulong param_2, int* param_3, int* param_4);
int RESFILE_Extract_to_File(ulong param_1, ulong param_2, char* param_3, _iobuf** param_4);
void RESFILE_Set_Missing_Flag(int param_1);
int RESFILE_Decommit_Mapped_Memory(uchar* param_1, int param_2);
int RESFILE_build_res_file(char* param_1, char* param_2, char* param_3);
ulong BUILDRES_get_files_resource_type(char* param_1);
