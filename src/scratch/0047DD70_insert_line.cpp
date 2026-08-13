// 0047DD70 TTextPanel::insert_line(long, char*, char*, long)
// Pnl_txt.cpp:1464-1582
//
// Canonical ownership:
//   - each TextNode owns text, text2, id, and next_node at offsets 0, 4, 8,
//     and 0x0C;
//   - TTextPanel owns list (+0xF4), num_lines (+0xF8), fixed_len (+0x138),
//     and sorted (+0x15C);
//   - the source uses ordinary C string allocation/copy operations and the
//     typed CompareStringA surface rather than raw text-buffer cursors.
//
// Attempt log:
// - Replaced the former allocation-only scaffold with the natural node
//   construction, fixed/unfixed text copies, sorted/positioned list insertion,
//   and post-insert panel refresh supported by the packet's CFG and calls.
// - The first 321 bytes (allocation, fixed/unfixed copies, and node setup
//   inputs) are exact.  Branch-local list/current/previous declaration shapes,
//   a shared zero/counter local, middle-loop forms, and a focused four-variant
//   natural init/loop lab did not change the emitted basin; the lab's best
//   group remained 181 positional bytes different with exact size/call set.
// - Moving the positional insertion counter into its natural non-sorted
//   branch-local lifetime left the emitted code unchanged; restored the clean source.
// - Restored the readable typed source after diagnostics: no parameter-home
//   casts, raw text cursors, fake volatility, or register-forcing scaffolding.

#include <stdlib.h>
#include <string.h>

extern "C" __declspec(dllimport) int __stdcall CompareStringA(
    unsigned long locale, unsigned long flags,
    const char* string1, int length1,
    const char* string2, int length2);

struct TextNode {
    char* text;                         // +0x00
    char* text2;                        // +0x04
    long id;                            // +0x08
    TextNode* next_node;                // +0x0C
};

class TTextPanel {
public:
    virtual void vf_00();
    virtual void vf_04();
    virtual void vf_08();
    virtual void vf_0C();
    virtual void vf_10();
    virtual void vf_14();
    virtual void vf_18();
    virtual void vf_1C();
    virtual void redraw(int flags);     // +0x20

    char gap_04[0xF0];                  // list begins at +0xF4
    TextNode* list;                     // +0xF4
    short num_lines;                    // +0xF8
    char gap_FA[0x3E];
    short fixed_len;                    // +0x138
    char gap_13A[0x22];
    int sorted;                         // +0x15C

    int insert_line(long line, char* text, char* text2, long value);
    void calc_draw_info(int recalc_scrollbar);
};

int TTextPanel::insert_line(long line, char* text, char* text2, long value)
{
    TextNode* node = (TextNode*)calloc(1, sizeof(TextNode));
    if (node == 0) {
        return 0;
    }

    if (this->fixed_len != 0) {
        node->text = (char*)calloc((int)this->fixed_len + 1, 1);
    } else if (text == 0) {
        node->text = (char*)calloc(1, 1);
    } else {
        node->text = (char*)calloc(strlen(text) + 1, 1);
    }

    if (node->text == 0) {
        free(node);
        return 0;
    }

    if (text2 != 0) {
        node->text2 = (char*)calloc(strlen(text2) + 1, 1);
        if (node->text2 == 0) {
            free(node->text);
            free(node);
            return 0;
        }
    }

    if (text == 0) {
        node->text[0] = '\0';
    } else if (this->fixed_len != 0) {
        strncpy(node->text, text, (int)this->fixed_len);
        node->text[(short)this->fixed_len] = '\0';
    } else {
        strcpy(node->text, text);
    }

    if (text2 != 0) {
        strcpy(node->text2, text2);
    }

    node->id = value;
    int i = 0;
    node->next_node = 0;

    TextNode* list_node = this->list;
    if (list_node == 0) {
        this->list = node;
    } else if (this->sorted != 0) {
        TextNode* current = list_node;
        TextNode* previous = 0;
        while (current != 0) {
            int result = CompareStringA(0x400, 1,
                                        node->text, -1,
                                        current->text, -1);
            if (result == 1) {
                node->next_node = current;
                if (previous == 0) {
                    this->list = node;
                } else {
                    previous->next_node = node;
                }
                break;
            }
            previous = current;
            current = current->next_node;
        }
        if (current == 0) {
            previous->next_node = node;
        }
    } else {
        if (line == 0) {
            node->next_node = list_node;
            this->list = node;
        } else if (line < this->num_lines) {
            while (i != line - 1) {
                list_node = list_node->next_node;
                i++;
            }
            node->next_node = list_node->next_node;
            list_node->next_node = node;
        } else {
            while (list_node->next_node != 0) {
                list_node = list_node->next_node;
            }
            list_node->next_node = node;
        }
    }

    this->num_lines++;
    this->calc_draw_info(1);
    this->redraw(1);
    return 1;
}
