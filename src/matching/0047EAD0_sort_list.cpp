extern "C" void __cdecl qsort(void* base, unsigned int num, unsigned int width, int (__cdecl* compare)(const void*, const void*));
extern "C" int __cdecl rdlg_list_compare(const void* a, const void* b);

class RGE_Dialog_List {
public:
    char gap_00[0x4B0];
    short list_size;
    char gap_4B2[0x02];
    void* list_info;

    void sort_list();
};

void RGE_Dialog_List::sort_list() {
    qsort(this->list_info, (int)this->list_size, 0x66, rdlg_list_compare);
}
