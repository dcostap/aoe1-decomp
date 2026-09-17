
#include "../include/Shape.h"
#include <fcntl.h>
#include "../include/asm_draw.h"
#include "../include/view.h"
#include "../include/colorlog.h"
#include <string.h>
#include <memory.h>

#pragma function(memcpy)
#pragma function(memset)

extern "C" int __cdecl open(const char*, int);
extern "C" int __cdecl lseek(int, int, int);
extern "C" int __cdecl tell(int);
extern "C" void* __cdecl malloc(unsigned int);
extern "C" int __cdecl read(int, void*, unsigned int);
extern "C" int __cdecl close(int);
extern "C" void __cdecl free(void*);
extern void __cdecl addstring(char**, char*, char*);
extern int shape_version_110;



TShape::TShape() {
    shape = 0;
    shape_header = 0;
    head = 0;
    offsets = 0;
    FShape = 0;
    shape_info = 0;
    load_type = -1;
    load_size = 0;
}

TShape::TShape(char* filename, long resource_file_id) {
    char NextFile[260];
    int file_handle;
    int file_size;

    shape = 0;
    shape_header = 0;
    head = 0;
    offsets = 0;
    FShape = 0;

    if (shape_file_first != 0 || resource_file_id < 0) {
        color_log('T', 'T', 1);
        strcpy(NextFile, filename);
        strcpy(NextFile + strlen(NextFile) - 3, "SLP");
        ++Shape_Loads;
        file_handle = open(NextFile, _O_BINARY);
        if (file_handle != -1) {
            lseek(file_handle, 0, 2);
            file_size = tell(file_handle);
            FShape = (SLhape_File_Header*)malloc(file_size);
            lseek(file_handle, 0, 0);
            read(file_handle, FShape, file_size);
            close(file_handle);
            shape_info = (Shape_Info*)(FShape + 1);
            load_type = 1;
            load_size = file_size;
        }

        if (FShape == 0) {
            strcpy(NextFile + strlen(NextFile) - 3, "SHP");
            file_handle = open(NextFile, _O_BINARY);
            if (file_handle != -1) {
                lseek(file_handle, 0, 2);
                file_size = tell(file_handle);
                shape = (byte*)malloc(file_size);
                lseek(file_handle, 0, 0);
                read(file_handle, shape, file_size);
                close(file_handle);
                head = (Shape_File_Header*)shape;
                offsets = (Shape_Offsets*)(head + 1);
                load_type = 1;
                load_size = file_size;
            }
        }
        color_log('T', '_', 1);
    }

    if (FShape == 0 && shape == 0 && resource_file_id >= 0) {
        ++Shape_Loads;
        shape = RESFILE_load(0x73687020, resource_file_id,
            load_type, load_size);
        if (shape != 0) {
            if (((Shape_File_Header*)shape)->version == shape_version_110) {
                head = (Shape_File_Header*)shape;
                offsets = (Shape_Offsets*)(head + 1);
            }
        } else {
            shape = RESFILE_load(0x736c7020, resource_file_id,
                load_type, load_size);
            if (shape != 0) {
                FShape = (SLhape_File_Header*)shape;
                shape = 0;
                shape_info = (Shape_Info*)(FShape + 1);
            }
        }
    }
}

TShape::~TShape() {
    if (FShape != 0) {
        if (load_type == 1) {
            free(FShape);
        }
        if (load_type == 0) {
            RESFILE_Decommit_Mapped_Memory((byte*)FShape, load_size);
        }
    }
    if (shape != 0) {
        if (load_type == 1) {
            free(shape);
        }
        if (load_type == 0) {
            RESFILE_Decommit_Mapped_Memory(shape, load_size);
        }
    }
    shape = 0;
    shape_header = 0;
    head = 0;
    offsets = 0;
    FShape = 0;
}

byte TShape::Check_shape(long shape_num, char* proc) {
    char* msg = 0;

    if (this->shape == 0 && this->FShape == 0) {
        return 1;
    }

    if (this->shape != 0) {
        Shape_File_Header* shape_file_header = this->head;
        if (shape_file_header == 0) {
            addstring(&msg, "ERROR: (", proc);
            addstring(&msg, msg, ") Bad shape");
            free(msg);
            return 1;
        }

        if (shape_num < 0 || shape_num < shape_file_header->shape_num) {
            if (shape_file_header->version != shape_version_110) {
                addstring(&msg, "ERROR: (", proc);
                addstring(&msg, msg, ") shape version wrong");
                free(msg);
                return 1;
            }
        } else {
            addstring(&msg, "ERROR: (", proc);
            addstring(&msg, msg, ") shape number out of bounds");
            free(msg);
            return 1;
        }
    }

    if (this->FShape != 0 && shape_num >= 0 &&
        shape_num >= this->FShape->Num_Shapes) {
        addstring(&msg, "ERROR: (", proc);
        addstring(&msg, msg, ") Fshape number out of bounds");
        free(msg);
        return 1;
    }

    return 0;
}

int TShape::is_loaded() {
    if (this->shape || this->FShape)
        return 1;
    return 0;
}

byte TShape::shape_bounds(long shape_num, short& width, short& height) {
    if (this->FShape != 0) {
        width = (short)this->shape_info[shape_num].Width;
        height = (short)this->shape_info[shape_num].Height;
        return 1;
    }

    if (shape_num >= 0) {
        unsigned char result = Check_shape(shape_num, "RGL_shape_resolution");
        if (result == 0) {
            this->shape_header =
                (Shape_Header*)(this->shape + this->offsets[shape_num].shape);
            width = (short)(this->shape_header->bounds >> 16);
            height = (short)this->shape_header->bounds;
            return 1;
        }
    }

    return 0;
}

long TShape::shape_count() {
    if (Check_shape(-1, "RGL_shape_count") != 0) {
        return 0;
    }
    if (this->FShape != 0) {
        return this->FShape->Num_Shapes;
    }
    return this->head->shape_num;
}

byte TShape::shape_minmax(long& x_min, long& y_min, long& x_max, long& y_max, long shape_num) {
    if (shape_num >= 0) {
        if (!Check_shape(shape_num, "RGL_shape_minxy")) {
            if (FShape != 0) {
                x_min = -shape_info[shape_num].Hotspot_X;
                y_min = -shape_info[shape_num].Hotspot_Y;
                x_max = shape_info[shape_num].Width - shape_info[shape_num].Hotspot_X - 1;
                y_max = shape_info[shape_num].Height - shape_info[shape_num].Hotspot_Y - 1;
            } else {
                shape_header = (Shape_Header*)(shape + offsets[shape_num].shape);
                x_min = shape_header->xmin;
                y_min = shape_header->ymin;
                x_max = shape_header->xmax;
                y_max = shape_header->ymax;
            }
            return 1;
        }
    }
    return 0;
}

byte TShape::shape_check(long check_x, long check_y, long shape_num) {
    if (shape_num < 0 ||
        this->Check_shape(shape_num, (char*)"RGL_shape_draw") != 0)
        return 0;

    if (this->FShape != 0) {
        Shape_Info* info = this->shape_info + shape_num;
        long shape_x0 = info->Hotspot_X + check_x;
        long shape_y = info->Hotspot_Y + check_y;
        long width = info->Width;

        if (shape_x0 >= 0 && shape_y >= 0 && shape_x0 < width &&
            shape_y < info->Height) {
            short* outline =
                (short*)(this->FShape->Version +
                         info->Shape_Outline_Offset);
            long left = outline[shape_y * 2];
            long right = outline[shape_y * 2 + 1];

            if (left >= 0 && left <= shape_x0 &&
                shape_x0 <= width - right) {
                long* data_offsets =
                    (long*)(this->FShape->Version +
                            info->Shape_Data_Offsets);
                byte* source =
                    (byte*)(this->FShape->Version + data_offsets[shape_y]);

                if (left < width) {
                    long count;
                    while (left <= shape_x0) {
                        byte command = *source++;

                        switch (command & 0x0f) {
                        case 0:
                        case 4:
                        case 8:
                        case 0x0c:
                            count = command >> 2;
                            left += count;
                            if (shape_x0 < left)
                                return 1;
                            source += count;
                            break;
                        case 1:
                        case 5:
                        case 9:
                        case 0x0d:
                            left += command >> 2;
                            break;
                        case 2:
                            count = ((command & 0xff) << 4) | *source++;
                            left += count;
                            if (shape_x0 < left)
                                return 1;
                            source += count;
                            break;
                        case 3:
                            count = ((command & 0xff) << 4) | *source++;
                            left += count;
                            break;
                        case 6:
                            count = command >> 4;
                            if (count == 0)
                                count = *source++;
                            left += count;
                            if (shape_x0 < left)
                                return 1;
                            source += count;
                            break;
                        case 7:
                        case 0x0a:
                            count = command >> 4;
                            if (count == 0)
                                count = *source++;
                            left += count;
                            if (shape_x0 < left)
                                return 1;
                            ++source;
                            break;
                        case 0x0b:
                            count = command >> 4;
                            if (count == 0)
                                count = *source++;
                            left += count;
                            if (shape_x0 < left)
                                return 1;
                            break;
                        default:
                            return 0;
                        }

                        if (width <= left)
                            return 0;
                    }
                }
            }
        }
    } else {
        Shape_Header* header =
            (Shape_Header*)(this->shape + this->offsets[shape_num].shape);
        this->shape_header = header;

        long r = header->xmin;
        long shape_y = header->ymin;
        byte* source = (byte*)(header + 1);

        if (shape_y <= check_y && check_y <= header->ymax && r <= check_x &&
            check_x <= header->xmax) {
            if (shape_y < check_y) {
                long rows = check_y - shape_y;
                do {
                    byte done = 0;
                    do {
                        byte command = *source++;
                        if ((command & 1) == 1) {
                            command >>= 1;
                            if (command == 0)
                                ++source;
                            else
                                source += command;
                        } else {
                            command >>= 1;
                            if (command == 0)
                                done = 1;
                            else
                                ++source;
                        }
                    } while (!done);
                } while (--rows);
            }

            byte done = 0;
            do {
                byte command = *source++;
                if ((command & 1) == 1) {
                    command >>= 1;
                    if (command == 0) {
                        r += *source;
                        if (check_x < r)
                            return 0;
                        ++source;
                    } else {
                        r += command;
                        if (check_x < r)
                            return 1;
                        source += command;
                    }
                } else {
                    command >>= 1;
                    if (command == 0) {
                        done = 1;
                    } else {
                        r += command;
                        if (check_x < r)
                            return 1;
                        ++source;
                    }
                }
            } while (!done);
        }
    }

    return 0;
}

byte TShape::shape_draw(TDrawArea* drawarea, long x, long y, long shape_num, byte flags, byte* color_table) {
    long shape_y1;
    byte ret_num = 0;
    long clip_y0;
    tagRECT rect;

    if (shape_num >= 0 &&
        this->Check_shape(shape_num, (char*)"RGL_shape_draw") == 0) {
        if (this->FShape != 0) {
            if (SDI_Capture_Info != 0) {
                Shape_Info* info = (Shape_Info*)(this->FShape + shape_num + 1);
                SDI_List->AddDrawNode(
                    this->FShape, info, SDI_Draw_Line,
                    x - info->Hotspot_X, y - info->Hotspot_Y,
                    fog_next_shape, color_table, ASMGet_Color_Xform(),
                    SDI_Draw_Level, SDI_Object_ID);
                return 1;
            }

            TSpan_List_Manager* span_list = drawarea->SpanList;
            int span_lines = span_list->Num_Lines;
            TSpan_List_Manager* current = drawarea->CurSpanList;
            int current_lines = current->Num_Lines;
            int end_line;
            if (span_lines < current_lines)
                end_line = span_lines - 1;
            else
                end_line = current_lines - 1;
            ASMSet_Surface_Info(
                drawarea->CurDisplayOffsets, current->Line_Head_Ptrs,
                current->Line_Tail_Ptrs, 0, 0, current->Max_Span_Px,
                end_line);
            if (color_table != 0)
                ASMSet_Xlate_Table(color_table);

            Shape_Info* info = (Shape_Info*)(this->FShape + shape_num + 1);
            ASMDraw_Sprite(
                this->FShape, x - info->Hotspot_X, y - info->Hotspot_Y,
                info->Width, info->Height, info->Shape_Data_Offsets,
                info->Shape_Outline_Offset, fog_next_shape);
            ASM_Fast_Count++;
            return 1;
        }

        rect = drawarea->ClipRect;
        if (this->shape != 0) {
            this->shape_header =
                (Shape_Header*)(this->shape + this->offsets[shape_num].shape);

            long shape_x0 = x + shape_header->xmin;
            long raw_y0 = y + shape_header->ymin;
            clip_y0 = raw_y0;
            long shape_x1 = x + shape_header->xmax;
            shape_y1 = y + shape_header->ymax;
            long clip_x1 = shape_x1;
            long clipped_y1 = shape_y1;
            x = shape_x0;
            y = clipped_y1;

            if (x < rect.left)
                x = rect.left;
            if (clip_y0 < rect.top)
                clip_y0 = rect.top;
            if (clip_x1 > rect.right)
                clip_x1 = rect.right;
            if (y > rect.bottom)
                y = rect.bottom;
            if (x < 0)
                x = 0;
            if (clip_y0 < 0)
                clip_y0 = 0;
            if (clip_x1 >= drawarea->Width)
                clip_x1 = drawarea->Width - 1;
            if (y >= drawarea->Height)
                y = drawarea->Height - 1;

            if (x <= clip_x1 && clip_y0 <= y) {
                if (x != shape_x0 || clip_y0 != raw_y0 ||
                    clip_x1 != shape_x1 || y != shape_y1) {
                    switch ((unsigned char)flags) {
                    case 2:
                        if (color_table != 0) {
                            ret_num = this->shape_shadow_clipped(
                                drawarea, shape_x0, raw_y0, x, clip_y0,
                                clip_x1, y, color_table);
                        } else {
                            ret_num = this->shape_draw_clipped(
                                drawarea, shape_x0, raw_y0, x, clip_y0,
                                clip_x1, y);
                        }
                        break;
                    case 1:
                        if (color_table != 0) {
                            ret_num = this->shape_color_trans_clipped(
                                drawarea, shape_x0, raw_y0, shape_num, x,
                                clip_y0, clip_x1, y, color_table);
                        } else {
                            ret_num = this->shape_draw_clipped(
                                drawarea, shape_x0, raw_y0, x, clip_y0,
                                clip_x1, y);
                        }
                        break;
                    case 0:
                        ret_num = this->shape_draw_clipped(
                            drawarea, shape_x0, raw_y0, x, clip_y0,
                            clip_x1, y);
                        break;
                    default:
                        break;
                    }
                    return ret_num;
                }

                switch ((unsigned char)flags) {
                case 2:
                    if (color_table == 0) {
                        ret_num = this->shape_draw_unclipped(
                            drawarea, shape_x0, raw_y0, shape_num);
                    } else {
                        ret_num = this->shape_shadow_unclipped(
                            drawarea, shape_x0, raw_y0, color_table);
                    }
                    break;
                case 1:
                    if (color_table == 0) {
                        ret_num = this->shape_draw_unclipped(
                            drawarea, shape_x0, raw_y0, shape_num);
                    } else {
                        ret_num = this->shape_color_trans_unclipped(
                            drawarea, shape_x0, raw_y0, shape_num, color_table);
                    }
                    break;
                case 0:
                    ret_num = this->shape_draw_unclipped(
                        drawarea, shape_x0, raw_y0, shape_num);
                    break;
                default:
                    break;
                }
                return ret_num;
            }
        }
    }
    return ret_num;
}

byte TShape::shape_draw_unclipped(TDrawArea* drawarea, long shape_x0, long shape_y0, long shape_num) {
    Shape_Header* sh = this->shape_header;
    int height = sh->ymax - sh->ymin + 1;
    byte* p = (byte*)(sh + 1);
    long width = drawarea->AlignedWidth() * drawarea->Orien;
    long rows;
    byte* d;
    byte c;

    if (drawarea->Orien < 1)
        d = drawarea->Bits + (shape_y0 - drawarea->Height + 1) * width + shape_x0;
    else
        d = drawarea->Bits + shape_y0 * width + shape_x0;

    shape_x0 = (long)d;

    if (height > 0) {
        rows = height;
        do {
            byte done = 0;
            do {
                byte command = *p++;
                if ((command & 1) == 1) {
                    c = command >> 1;
                    if (c == 0) {
                        d += *p;
                        p++;
                    } else {
                        memcpy(d, p, c);
                        d += c;
                        p += c;
                    }
                } else {
                    c = command >> 1;
                    if (c == 0) {
                        done = 1;
                    } else {
                        byte t = *p;
                        memset(d, t, c);
                        d += c;
                        p++;
                    }
                }
            } while (!done);
            shape_x0 += width;
            d = (byte*)shape_x0;
        } while (--rows);
    }

    return 1;
}

byte TShape::shape_color_trans_unclipped(TDrawArea* drawarea, long shape_x0, long shape_y0, long shape_num, byte* color_table) {
    Shape_Header* hdr = this->shape_header;
    long height = (hdr->ymax - hdr->ymin) + 1;
    byte* src = (byte*)(hdr + 1);

    long orien = drawarea->Orien;
    long width = drawarea->AlignedWidth() * orien;
    long rows;
    byte count;
    byte* dst;
    byte* save_buffer;

    if (orien < 1) {
        dst = drawarea->Bits + shape_x0 +
              (shape_y0 - drawarea->Height + 1) * width;
    } else {
        dst = drawarea->Bits + shape_x0 + shape_y0 * width;
    }
    save_buffer = dst;

    if (height > 0) {
        rows = height;
        do {
            byte done = 0;
            do {
                byte command = *src++;
                if ((command & 1) == 1) {
                    count = command >> 1;
                    if (count == 0) {
                        dst += *src;
                        src++;
                    } else {
                        byte* end = dst + count;
                        while (dst < end) {
                            *dst = color_table[*src];
                            src++;
                            dst++;
                        }
                    }
                } else {
                    count = command >> 1;
                    if (count == 0) {
                        done = 1;
                    } else {
                        memset(dst, color_table[*src], count);
                        dst += count;
                        src++;
                    }
                }
            } while (!done);

            save_buffer += width;
            dst = save_buffer;
        } while (--rows);
    }

    return 1;
}

byte TShape::shape_shadow_unclipped(TDrawArea* drawarea, long shape_x0, long shape_y0, byte* color_table) {
    Shape_Header* sh = shape_header;
    byte* p = (byte*)(sh + 1);
    long height = sh->ymax - sh->ymin + 1;
    byte* save_buffer;
    long rows;
    long width;

    width = drawarea->AlignedWidth() * drawarea->Orien;

    if (drawarea->Orien < 1)
        save_buffer = drawarea->Bits + ((shape_y0 - drawarea->Height) + 1) * width + shape_x0;
    else
        save_buffer = drawarea->Bits + shape_y0 * width + shape_x0;

    shape_x0 = (long)save_buffer;

    if (height > 0) {
        rows = height;
        do {
            byte* dst = (byte*)shape_x0;
            byte done = 0;

            do {
                byte command = *p++;

                if ((command & 1) == 1) {
                    command >>= 1;
                    if (command == 0) {
                        dst += *p++;
                    } else {
                        byte* e = dst + (command & 0xFF);
                        while (dst < e) {
                            *dst = color_table[*dst];
                            dst++;
                        }
                        p += command;
                    }
                } else {
                    command >>= 1;
                    if (command == 0) {
                        done = 1;
                    } else {
                        byte* e = dst + (command & 0xFF);
                        while (dst < e) {
                            *dst = color_table[*dst];
                            dst++;
                        }
                        p++;
                    }
                }
            } while (!done);

            shape_x0 += width;
        } while (--rows);
    }

    return 1;
}

byte TShape::shape_draw_clipped(TDrawArea* drawarea, long shape_x0,
                                long shape_y0, long clip_x0, long clip_y0,
                                long clip_x1, long clip_y1) {
    long pitch = drawarea->AlignedWidth() * drawarea->Orien;
    byte* src = (byte*)(this->shape_header + 1);
    byte* dst;

    if (drawarea->Orien < 1)
        dst = drawarea->Bits +
              (clip_y0 - drawarea->Height + 1) * pitch + clip_x0;
    else
        dst = drawarea->Bits + clip_y0 * pitch + clip_x0;

    byte* save_buffer = dst;

    if (shape_y0 < clip_y0) {
        long skip_rows = clip_y0 - shape_y0;
        shape_y0 += skip_rows;
        do {
            byte done = 0;
            do {
                byte command = *src++;
                if (command & 1) {
                    command >>= 1;
                    if (command)
                        src += command;
                    else
                        ++src;
                } else {
                    if ((command & 0xfe) == 0)
                        done = 1;
                    else
                        ++src;
                }
            } while (!done);
        } while (--skip_rows != 0);
    }

    if (shape_y0 > clip_y1)
        return 1;

    long rows = clip_y1 - shape_y0 + 1;
    do {
        long xpos = shape_x0;
        byte state;

        if (xpos < clip_x0) {
            state = 0;
            do {
                byte command = *src++;
                if (command & 1) {
                    command >>= 1;
                    if (command == 0) {
                        xpos += *src++;
                        if (xpos >= clip_x0) {
                            if (xpos > clip_x1) {
                                state = 2;
                            } else {
                                state = 1;
                                dst += xpos - clip_x0;
                            }
                        }
                    } else {
                        xpos += command;
                        if (xpos >= clip_x0) {
                            if (xpos > clip_x1) {
                                state = 2;
                                memcpy(dst,
                                       src + clip_x0 - xpos + command,
                                       clip_x1 - clip_x0 + 1);
                                dst += clip_x1 - clip_x0 + 1;
                            } else {
                                long count = xpos - clip_x0;
                                state = 1;
                                memcpy(dst, src + command - count, count);
                                dst += count;
                            }
                        }
                        src += command;
                    }
                } else {
                    command >>= 1;
                    if (command == 0) {
                        state = 3;
                    } else {
                        xpos += command;
                        if (xpos >= clip_x0) {
                            long count;
                            if (xpos > clip_x1) {
                                state = 2;
                                count = clip_x1 - clip_x0 + 1;
                            } else {
                                state = 1;
                                count = xpos - clip_x0;
                            }
                            memset(dst, *src, count);
                            dst += count;
                        }
                        ++src;
                    }
                }
            } while (state == 0);
        } else {
            state = 1;
        }

        --state;
        while (state == 0) {
            byte command = *src++;
            if (command & 1) {
                command >>= 1;
                if (command == 0) {
                    command = *src++;
                    xpos += command;
                    dst += command;
                    if (xpos > clip_x1)
                        state = 1;
                } else {
                    xpos += command;
                    if (xpos > clip_x1) {
                        state = 1;
                        memcpy(dst, src,
                               command + clip_x1 - xpos + 1);
                    } else {
                        memcpy(dst, src, command);
                    }
                    dst += command;
                    src += command;
                }
            } else {
                command >>= 1;
                if (command == 0) {
                    state = 3;
                } else {
                    xpos += command;
                    if (xpos > clip_x1) {
                        state = 1;
                        memset(dst, *src,
                               command + clip_x1 - xpos + 1);
                    } else {
                        memset(dst, *src, command);
                    }
                    dst += command;
                    ++src;
                }
            }
        }

        --state;
        while (state == 0) {
            byte command = *src++;
            if (command & 1) {
                command >>= 1;
                if (command)
                    src += command;
                else
                    ++src;
            } else {
                if ((command & 0xfe) == 0)
                    state = 2;
                else
                    ++src;
            }
        }

        save_buffer += pitch;
        dst = save_buffer;
    } while (--rows != 0);

    return 1;
}

byte TShape::shape_color_trans_clipped(
    TDrawArea* drawarea, long shape_x0, long shape_y0, long shape_num,
    long clip_x0, long clip_y0, long clip_x1, long clip_y1,
    byte* color_table) {
    long orientation = drawarea->Orien;
    long pitch = drawarea->AlignedWidth() * orientation;
    byte* src = (byte*)(this->shape_header + 1);
    byte* dst;

    if (orientation < 1)
        dst = drawarea->Bits +
              (clip_y0 - drawarea->Height + 1) * pitch + clip_x0;
    else
        dst = drawarea->Bits + clip_y0 * pitch + clip_x0;

    byte* temp_buffer = dst;

    if (shape_y0 < clip_y0) {
        long skip_rows = clip_y0 - shape_y0;
        shape_y0 += skip_rows;
        do {
            byte done = 0;
            do {
                byte command = *src++;
                if (command & 1) {
                    command >>= 1;
                    if (command)
                        src += command;
                    else
                        ++src;
                } else {
                    if ((command & 0xfe) == 0)
                        done = 1;
                    else
                        ++src;
                }
            } while (!done);
        } while (--skip_rows != 0);
    }

    if (shape_y0 > clip_y1)
        return 1;

    long rows = clip_y1 - shape_y0 + 1;
    do {
        long xpos = shape_x0;
        byte state;

        if (xpos < clip_x0) {
            state = 0;
            do {
                byte command = *src++;
                if (command & 1) {
                    byte count = command >> 1;
                    if (count == 0) {
                        xpos += *src++;
                        if (xpos >= clip_x0) {
                            if (xpos > clip_x1) {
                                state = 2;
                            } else {
                                state = 1;
                                dst += xpos - clip_x0;
                            }
                        }
                    } else {
                        xpos += count;
                        if (xpos < clip_x0) {
                            src += count;
                        } else if (xpos > clip_x1) {
                            long first = clip_x0 - xpos + count;
                            long visible = clip_x1 - clip_x0 + 1;
                            src += first;
                            state = 2;
                            byte* end = dst + visible;
                            while (dst < end) {
                                byte color = *src++;
                                *dst++ = color_table[color];
                            }
                            src += count - visible - first;
                        } else {
                            long visible = xpos - clip_x0;
                            src += count - visible;
                            state = 1;
                            byte* end = dst + visible;
                            while (dst < end) {
                                byte color = *src++;
                                *dst++ = color_table[color];
                            }
                        }
                    }
                } else {
                    byte count = command >> 1;
                    if (count == 0) {
                        state = 3;
                    } else {
                        xpos += count;
                        if (xpos >= clip_x0) {
                            long visible;
                            if (xpos > clip_x1) {
                                visible = clip_x1 - clip_x0 + 1;
                                state = 2;
                            } else {
                                visible = xpos - clip_x0;
                                state = 1;
                            }
                            memset(dst, color_table[*src], visible);
                            dst += visible;
                        }
                        ++src;
                    }
                }
            } while (state == 0);
        } else {
            state = 1;
        }

        --state;
        while (state == 0) {
            byte command = *src++;
            if (command & 1) {
                byte count = command >> 1;
                if (count == 0) {
                    count = *src++;
                    xpos += count;
                    dst += count;
                    if (xpos > clip_x1)
                        state = 1;
                } else {
                    xpos += count;
                    long visible = count;
                    if (xpos > clip_x1) {
                        visible = clip_x1 - xpos + count + 1;
                        state = 1;
                    }

                    byte* end = dst + visible;
                    while (dst < end) {
                        byte color = *src++;
                        *dst++ = color_table[color];
                    }
                    src += count - visible;
                }
            } else {
                byte count = command >> 1;
                if (count == 0) {
                    state = 3;
                } else {
                    xpos += count;
                    long visible = count;
                    if (xpos > clip_x1) {
                        visible = clip_x1 - xpos + count + 1;
                        state = 1;
                    }
                    memset(dst, color_table[*src], visible);
                    dst += count;
                    ++src;
                }
            }
        }

        --state;
        while (state == 0) {
            byte command = *src++;
            if (command & 1) {
                command >>= 1;
                if (command)
                    src += command;
                else
                    ++src;
            } else {
                if ((command & 0xfe) == 0)
                    state = 2;
                else
                    ++src;
            }
        }

        temp_buffer += pitch;
        dst = temp_buffer;
    } while (--rows != 0);

    return 1;
}

byte TShape::shape_shadow_clipped(TDrawArea* drawarea, long shape_x0,
                                  long shape_y0, long clip_x0, long clip_y0,
                                  long clip_x1, long clip_y1,
                                  byte* color_table) {
    long orientation = drawarea->Orien;
    long pitch = drawarea->AlignedWidth() * orientation;
    byte* src = (byte*)(this->shape_header + 1);
    byte* dst;

    if (orientation < 1)
        dst = drawarea->Bits +
              (clip_y0 - drawarea->Height + 1) * pitch + clip_x0;
    else
        dst = drawarea->Bits + clip_y0 * pitch + clip_x0;

    byte* save_buffer = dst;

    if (shape_y0 < clip_y0) {
        long skip_rows = clip_y0 - shape_y0;
        shape_y0 += skip_rows;
        do {
            byte done = 0;
            do {
                byte command = *src++;
                if (command & 1) {
                    command >>= 1;
                    if (command)
                        src += command;
                    else
                        ++src;
                } else {
                    if ((command & 0xfe) == 0)
                        done = 1;
                    else
                        ++src;
                }
            } while (!done);
        } while (--skip_rows != 0);
    }

    if (shape_y0 <= clip_y1) {
        long rows = clip_y1 - shape_y0 + 1;
        do {
            long xpos = shape_x0;
            byte state;

            if (xpos < clip_x0) {
                state = 0;
                do {
                    byte command = *src++;
                    if (command & 1) {
                        command >>= 1;
                        if (command == 0) {
                            xpos += *src++;
                            if (xpos >= clip_x0) {
                                if (xpos > clip_x1) {
                                    state = 2;
                                } else {
                                    state = 1;
                                    dst += xpos - clip_x0;
                                }
                            }
                        } else {
                            xpos += command;
                            if (xpos >= clip_x0) {
                                if (xpos > clip_x1) {
                                    state = 2;
                                    long count = clip_x1 - clip_x0 + 1;
                                    byte* end = dst + count;
                                    while (dst < end) {
                                        byte value = *dst;
                                        ++dst;
                                        *(dst - 1) = color_table[value];
                                    }
                                } else {
                                    state = 1;
                                    long count = xpos - clip_x0;
                                    byte* end = dst + count;
                                    while (dst < end) {
                                        byte value = *dst;
                                        ++dst;
                                        *(dst - 1) = color_table[value];
                                    }
                                }
                            }
                            src += command;
                        }
                    } else {
                        command >>= 1;
                        if (command == 0) {
                            state = 3;
                        } else {
                            xpos += command;
                            if (xpos >= clip_x0) {
                                if (xpos > clip_x1) {
                                    state = 2;
                                    long count = clip_x1 - clip_x0 + 1;
                                    byte* end = dst + count;
                                    while (dst < end) {
                                        byte value = *dst;
                                        ++dst;
                                        *(dst - 1) = color_table[value];
                                    }
                                } else {
                                    state = 1;
                                    long count = xpos - clip_x0;
                                    byte* end = dst + count;
                                    while (dst < end) {
                                        byte value = *dst;
                                        ++dst;
                                        *(dst - 1) = color_table[value];
                                    }
                                }
                            }
                            ++src;
                        }
                    }
                } while (state == 0);
            } else {
                state = 1;
            }

            --state;
            while (state == 0) {
                byte command = *src++;
                if (command & 1) {
                    command >>= 1;
                    if (command == 0) {
                        command = *src++;
                        xpos += command;
                        dst += command;
                        if (xpos > clip_x1)
                            state = 1;
                    } else {
                        xpos += command;
                        if (xpos > clip_x1) {
                            state = 1;
                            long count = command + clip_x1 - xpos + 1;
                            byte* end = dst + count;
                            while (dst < end) {
                                byte value = *dst;
                                ++dst;
                                *(dst - 1) = color_table[value];
                            }
                        } else {
                            byte* end = dst + command;
                            while (dst < end) {
                                byte value = *dst;
                                ++dst;
                                *(dst - 1) = color_table[value];
                            }
                        }
                        src += command;
                    }
                } else {
                    command >>= 1;
                    if (command == 0) {
                        state = 3;
                    } else {
                        xpos += command;
                        if (xpos > clip_x1) {
                            state = 1;
                            long count = command + clip_x1 - xpos + 1;
                            byte* end = dst + count;
                            while (dst < end) {
                                byte value = *dst;
                                ++dst;
                                *(dst - 1) = color_table[value];
                            }
                        } else {
                            byte* end = dst + command;
                            while (dst < end) {
                                byte value = *dst;
                                ++dst;
                                *(dst - 1) = color_table[value];
                            }
                        }
                        ++src;
                    }
                }
            }

            --state;
            while (state == 0) {
                byte command = *src++;
                if (command & 1) {
                    command >>= 1;
                    if (command)
                        src += command;
                    else
                        ++src;
                } else {
                    if ((command & 0xfe) == 0)
                        state = 2;
                    else
                        ++src;
                }
            }

            save_buffer += pitch;
            dst = save_buffer;
        } while (--rows != 0);
    }

    return 1;
}

byte TShape::shape_mirror(TDrawArea* drawarea, long x, long y, long shape_num, byte flags, byte* color_table) {
    byte ret_num;
    long shape_y1;
    long shape_x1;
    tagRECT rect;
    ret_num = 0;

    if (shape_num >= 0 &&
        this->Check_shape(shape_num, (char*)"RGL_shape_draw") == 0) {
        if (this->FShape != 0) {
            if (SDI_Capture_Info != 0) {
                Shape_Info* info = (Shape_Info*)((char*)this->FShape +
                                                 ((shape_num + 1) << 5));
                SDI_List->AddDrawNode(
                    this->FShape, info, SDI_Draw_Line,
                    info->Hotspot_X - info->Width + x,
                    y - info->Hotspot_Y, fog_next_shape + 2, color_table,
                    ASMGet_Color_Xform(), SDI_Draw_Level, SDI_Object_ID);
                return 1;
            }

            TSpan_List_Manager* span_list = drawarea->SpanList;
            TSpan_List_Manager* cur_span_list = drawarea->CurSpanList;
            int line_count;
            if (span_list->Num_Lines < cur_span_list->Num_Lines)
                line_count = span_list->Num_Lines - 1;
            else
                line_count = cur_span_list->Num_Lines - 1;
            ASMSet_Surface_Info(drawarea->CurDisplayOffsets,
                                cur_span_list->Line_Head_Ptrs,
                                cur_span_list->Line_Tail_Ptrs,
                                0, 0, cur_span_list->Max_Span_Px,
                                line_count);
            if (color_table != 0)
                ASMSet_Xlate_Table(color_table);

            Shape_Info* info = (Shape_Info*)((char*)this->FShape +
                                             ((shape_num + 1) << 5));
            ASMDraw_Sprite(this->FShape,
                           info->Hotspot_X + x - info->Width,
                           y - info->Hotspot_Y, info->Width, info->Height,
                           info->Shape_Data_Offsets,
                           info->Shape_Outline_Offset, fog_next_shape + 2);
            ++ASM_Fast_Count;
            return 1;
        } else {
            rect = drawarea->ClipRect;
            if (this->shape != 0) {
                Shape_Header* frame =
                    (Shape_Header*)(this->shape +
                                    this->offsets[shape_num].shape);
                this->shape_header = frame;

                long x0 = x - frame->xmax;
                long y0 = frame->ymin + y;
                shape_x1 = x - frame->xmin;
                shape_y1 = frame->ymax + y;
                long original_y0 = y0;
                long original_x1 = shape_x1;
                long original_y1 = shape_y1;

                x = x0;
                y = y0;
                if (x < rect.left)
                    x = rect.left;
                if (y < rect.top)
                    y = rect.top;
                if (shape_x1 > rect.right)
                    shape_x1 = rect.right;
                if (shape_y1 > rect.bottom)
                    shape_y1 = rect.bottom;
                if (x < 0)
                    x = 0;
                if (y < 0)
                    y = 0;
                if (shape_x1 >= drawarea->Width)
                    shape_x1 = drawarea->Width - 1;
                if (shape_y1 >= drawarea->Height)
                    shape_y1 = drawarea->Height - 1;

                if (x <= shape_x1 && y <= shape_y1) {
                    if (x == x0 && y == y0 &&
                        shape_x1 == original_x1 &&
                        shape_y1 == original_y1) {
                        switch ((unsigned char)flags) {
                        case 2:
                            if (color_table == 0) {
                                ret_num = this->shape_mirror_unclipped(
                                    drawarea, original_x1, original_y0);
                            } else {
                                ret_num = this->shape_mirror_shadow_unclipped(
                                    drawarea, original_x1, original_y0,
                                    color_table);
                            }
                            break;
                        case 1:
                            if (color_table == 0) {
                                ret_num = this->shape_mirror_unclipped(
                                    drawarea, original_x1, original_y0);
                            } else {
                                ret_num =
                                    this->shape_mirror_color_trans_unclipped(
                                        drawarea, original_x1, original_y0,
                                        shape_num, color_table);
                            }
                            break;
                        case 0:
                            ret_num = this->shape_mirror_unclipped(
                                drawarea, original_x1, original_y0);
                            break;
                        default:
                            break;
                        }
                        return ret_num;
                    }

                    switch ((unsigned char)flags) {
                    case 2:
                        if (color_table != 0)
                            return this->shape_mirror_shadow_clipped(
                                drawarea, original_x1, original_y0, x, y,
                                shape_x1, shape_y1, color_table);
                        break;
                    case 1:
                        if (color_table != 0)
                            return this->shape_mirror_color_trans_clipped(
                                drawarea, original_x1, original_y0,
                                shape_num, x, y, shape_x1, shape_y1,
                                color_table);
                        break;
                    case 0:
                        break;
                    default:
                        return ret_num;
                    }
                    return this->shape_mirror_clipped(
                        drawarea, original_x1, original_y0, x, y,
                        shape_x1, shape_y1);
                }
            }
        }
    }

    return ret_num;
}

byte TShape::shape_mirror_unclipped(TDrawArea* drawarea, long shape_x1, long shape_y0) {
    long pitch = drawarea->AlignedWidth() * drawarea->Orien;
    Shape_Header* sh = this->shape_header;
    long height = sh->ymax - sh->ymin + 1;
    byte* p = (byte*)(sh + 1);
    long rows;
    byte* d;
    byte c;

    if (drawarea->Orien < 1)
        d = drawarea->Bits + ((shape_y0 - drawarea->Height) + 1) * pitch + shape_x1 + 1;
    else
        d = drawarea->Bits + shape_y0 * pitch + shape_x1 + 1;

    shape_x1 = (long)d;

    if (height > 0) {
        rows = height;
        do {
            byte done = 0;
            do {
                byte command = *p++;
                if ((command & 1) == 1) {
                    c = command >> 1;
                    if (c == 0) {
                        d -= *p;
                        p++;
                    } else {
                        while (c > 0) {
                            *--d = *p++;
                            c--;
                        }
                    }
                } else {
                    c = command >> 1;
                    if (c == 0) {
                        done = 1;
                    } else {
                        byte t = *p;
                        d -= c;
                        memset(d, t, c);
                        p++;
                    }
                }
            } while (!done);
            shape_x1 += pitch;
            d = (byte*)shape_x1;
        } while (--rows);
    }

    return 1;
}

byte TShape::shape_mirror_color_trans_unclipped(
    TDrawArea* drawarea, long shape_x1, long shape_y0, long shape_num,
    byte* color_table) {
    long pitch = drawarea->AlignedWidth() * drawarea->Orien;
    Shape_Header* sh = this->shape_header;
    long height = sh->ymax - sh->ymin + 1;
    byte* p = (byte*)(sh + 1);
    long m;
    long rows;
    byte* d;
    byte c;

    if (drawarea->Orien < 1)
        d = drawarea->Bits +
            (shape_y0 - drawarea->Height + 1) * pitch + shape_x1 + 1;
    else
        d = drawarea->Bits + shape_y0 * pitch + shape_x1 + 1;

    shape_x1 = (long)d;

    if (height > 0) {
        rows = height;
        do {
            byte done = 0;
            do {
                byte command = *p++;
                if ((command & 1) == 1) {
                    c = command >> 1;
                    if (c == 0) {
                        d -= *p;
                        p++;
                    } else {
                        while (c > 0) {
                            *--d = color_table[*p++];
                            c--;
                        }
                    }
                } else {
                    c = command >> 1;
                    if (c == 0) {
                        done = 1;
                    } else {
                        byte t = color_table[*p];
                        d -= c;
                        memset(d, t, c);
                        p++;
                    }
                }
            } while (!done);
            shape_x1 += pitch;
            d = (byte*)shape_x1;
        } while (--rows);
    }

    return 1;
}

byte TShape::shape_mirror_shadow_unclipped(TDrawArea* drawarea, long shape_x1, long shape_y0, byte* color_table) {
    long pitch = drawarea->AlignedWidth() * drawarea->Orien;

    Shape_Header* hdr = this->shape_header;
    long height = hdr->ymax - hdr->ymin + 1;
    byte* src = (byte*)(hdr + 1);
    long rows;
    byte* d;
    byte c;

    if (drawarea->Orien < 1)
        d = drawarea->Bits +
            ((shape_y0 - drawarea->Height) + 1) * pitch + shape_x1 + 1;
    else
        d = drawarea->Bits + shape_y0 * pitch + shape_x1 + 1;

    shape_x1 = (long)d;

    if (height > 0) {
        rows = height;
        do {
            byte done = 0;
            do {
                byte command = *src++;
                if ((command & 1) == 1) {
                    c = command >> 1;
                    if (c == 0) {
                        d -= *src++;
                    } else {
                        if (c > 0) {
                            unsigned int count = c;
                            do {
                                --d;
                                *d = color_table[*d];
                            } while (--count);
                        }
                        src += c;
                    }
                } else {
                    c = command >> 1;
                    if (c == 0) {
                        done = 1;
                    } else {
                        if (c > 0) {
                            unsigned int count = c;
                            do {
                                --d;
                                *d = color_table[*d];
                            } while (--count);
                        }
                        src++;
                    }
                }
            } while (!done);
            shape_x1 += pitch;
            d = (byte*)shape_x1;
        } while (--rows);
    }
    return 1;
}

byte TShape::shape_mirror_clipped(TDrawArea* drawarea, long shape_x1,
                                  long shape_y0, long clip_x0, long clip_y0,
                                  long clip_x1, long clip_y1) {
    long pitch = drawarea->AlignedWidth() * drawarea->Orien;
    byte* src = (byte*)(this->shape_header + 1);
    byte* dst;

    if (drawarea->Orien < 1)
        dst = drawarea->Bits +
              (clip_y0 - drawarea->Height + 1) * pitch + clip_x1 + 1;
    else
        dst = drawarea->Bits + clip_y0 * pitch + clip_x1 + 1;

    byte* save_buffer = dst;

    if (shape_y0 < clip_y0) {
        long skip_rows = clip_y0 - shape_y0;
        shape_y0 += skip_rows;
        do {
            byte done = 0;
            do {
                byte command = *src++;
                if (command & 1) {
                    command >>= 1;
                    if (command != 0)
                        src += command;
                    else
                        ++src;
                } else {
                    if ((command & 0xfe) == 0)
                        done = 1;
                    else
                        ++src;
                }
            } while (!done);
        } while (--skip_rows != 0);
    }

    if (shape_y0 > clip_y1)
        return 1;

    long rows = clip_y1 - shape_y0 + 1;
    do {
        long xpos = shape_x1;
        byte state;

        if (xpos <= clip_x1) {
            state = 1;
        } else {
            state = 0;
            do {
                byte command = *src++;
                if (command & 1) {
                    command >>= 1;
                    if (command == 0) {
                        command = *src++;
                        xpos -= command;
                        if (xpos <= clip_x1) {
                            if (xpos < clip_x0) {
                                state = 2;
                            } else {
                                state = 1;
                                dst += xpos - clip_x1;
                            }
                        }
                    } else {
                        xpos -= command;
                        if (xpos <= clip_x1) {
                            if (xpos < clip_x0) {
                                state = 2;
                                long count = clip_x1 - clip_x0 + 1;
                                src += xpos - clip_x1 + command - 1;
                                unsigned int copy_count =
                                    (unsigned char)count;
                                if (copy_count != 0) {
                                    do {
                                        --dst;
                                        *dst = *src++;
                                    } while (--copy_count != 0);
                                }
                                src += clip_x0 - xpos;
                            } else {
                                state = 1;
                                long count = clip_x1 - xpos;
                                src += command - count;
                                unsigned int copy_count =
                                    (unsigned char)count;
                                if (copy_count != 0) {
                                    do {
                                        --dst;
                                        *dst = *src++;
                                    } while (--copy_count != 0);
                                }
                            }
                        } else {
                            src += command;
                        }
                    }
                } else {
                    command >>= 1;
                    if (command == 0) {
                        state = 3;
                    } else {
                        xpos -= command;
                        if (xpos <= clip_x1) {
                            long count;
                            if (xpos < clip_x0) {
                                state = 2;
                                count = clip_x1 - clip_x0 + 1;
                            } else {
                                state = 1;
                                count = clip_x1 - xpos;
                            }
                            dst -= count;
                            memset(dst, *src, count);
                        }
                        ++src;
                    }
                }
            } while (state == 0);
        }

        --state;
        while (state == 0) {
            byte command = *src++;
            if (command & 1) {
                command >>= 1;
                if (command == 0) {
                    command = *src++;
                    xpos -= command;
                    dst -= command;
                    if (xpos < clip_x0)
                        state = 1;
                } else {
                    xpos -= command;
                    if (xpos < clip_x0) {
                        state = 1;
                        long count = xpos - clip_x0 + command;
                        unsigned int copy_count = (unsigned char)count;
                        if (copy_count != 0) {
                            do {
                                --dst;
                                *dst = *src++;
                            } while (--copy_count != 0);
                        }
                        src += command - count;
                    } else {
                        long count = command;
                        unsigned int copy_count = (unsigned char)count;
                        if (copy_count != 0) {
                            do {
                                --dst;
                                *dst = *src++;
                            } while (--copy_count != 0);
                        }
                    }
                }
            } else {
                command >>= 1;
                if (command == 0) {
                    state = 3;
                } else {
                    xpos -= command;
                    long count;
                    if (xpos < clip_x0) {
                        state = 1;
                        count = xpos - clip_x0 + command;
                    } else {
                        count = command;
                    }
                    dst -= count;
                    memset(dst, *src, count);
                    ++src;
                }
            }
        }

        --state;
        while (state == 0) {
            byte command = *src++;
            if (command & 1) {
                command >>= 1;
                if (command != 0)
                    src += command;
                else
                    ++src;
            } else {
                if ((command & 0xfe) == 0)
                    state = 2;
                else
                    ++src;
            }
        }

        save_buffer += pitch;
        dst = save_buffer;
    } while (--rows != 0);

    return 1;
}

byte TShape::shape_mirror_color_trans_clipped(
    TDrawArea* drawarea, long shape_x1, long shape_y0, long shape_num,
    long clip_x0, long clip_y0, long clip_x1, long clip_y1,
    byte* color_table) {
    byte command;
    byte count;
    char state;
    long width;
    Shape_Header* header;
    Shape_Payload* src;
    byte* save_buffer;
    byte* dst;
    long xpos;
    unsigned int transform_count;

    width = drawarea->AlignedWidth();
    width *= drawarea->Orien;
    header = this->shape_header;
    src = (Shape_Payload*)(header + 1);

    if (drawarea->Orien < 1)
        save_buffer = drawarea->Bits +
                      (clip_y0 - drawarea->Height + 1) * width + clip_x1 + 1;
    else
        save_buffer = drawarea->Bits + clip_y0 * width + clip_x1 + 1;
    dst = save_buffer;

    if (shape_y0 < clip_y0) {
        long skip_rows = clip_y0 - shape_y0;
        shape_y0 += skip_rows;
        do {
            byte done = 0;
            do {
                command = src++->value;
                if (command & 1) {
                    command >>= 1;
                    if (command != 0)
                        src += command;
                    else
                        ++src;
                } else {
                    if ((command & 0xfe) == 0)
                        done = 1;
                    else
                        ++src;
                }
            } while (!done);
        } while (--skip_rows != 0);
    }

    if (shape_y0 > clip_y1)
        return 1;

    long rows = clip_y1 - shape_y0 + 1;
    do {
        xpos = shape_x1;
        if (clip_x1 < xpos) {
            state = 0;
            do {
                command = src++->value;
                if (command & 1) {
                    count = command >> 1;
                    if (count == 0) {
                        count = src++->value;
                        xpos -= count;
                        if (xpos <= clip_x1) {
                            if (xpos < clip_x0) {
                                state = 2;
                            } else {
                                state = 1;
                                dst += xpos - clip_x1;
                            }
                        }
                    } else {
                        xpos -= count;
                        if (clip_x1 < xpos) {
                            src += count;
                        } else if (xpos < clip_x0) {
                            state = 2;
                            transform_count = clip_x1 - clip_x0 + 1;
                            src += xpos - clip_x1 + count - 1;
                            if ((byte)transform_count != 0) {
                                unsigned int n = transform_count & 0xff;
                                do {
                                    --dst;
                                    *dst = color_table[src++->value];
                                } while (--n != 0);
                            }
                            src += clip_x0 - xpos;
                        } else {
                            state = 1;
                            transform_count = clip_x1 - xpos;
                            src += count - transform_count;
                            if ((byte)transform_count != 0) {
                                unsigned int n = transform_count & 0xff;
                                do {
                                    --dst;
                                    *dst = color_table[src++->value];
                                } while (--n != 0);
                            }
                        }
                    }
                } else {
                    count = command >> 1;
                    if (count == 0) {
                        state = 3;
                    } else {
                        xpos -= count;
                        if (xpos <= clip_x1) {
                            if (xpos < clip_x0) {
                                state = 2;
                                transform_count = clip_x1 - clip_x0 + 1;
                            } else {
                                state = 1;
                                transform_count = clip_x1 - xpos;
                            }
                            dst -= transform_count;
                            memset(dst, color_table[src->value], transform_count);
                        }
                        ++src;
                    }
                }
            } while (state == 0);
        } else {
            state = 1;
        }

        --state;
        if (state == 0) {
            do {
                command = src++->value;
                if (command & 1) {
                    count = command >> 1;
                    if (count == 0) {
                        count = src++->value;
                        xpos -= count;
                        dst -= count;
                        if (xpos < clip_x0)
                            state = 1;
                    } else {
                        xpos -= count;
                        if (xpos < clip_x0) {
                            state = 1;
                            transform_count = xpos - clip_x0 + count;
                            if ((byte)transform_count != 0) {
                                unsigned int n = transform_count & 0xff;
                                do {
                                    --dst;
                                    *dst = color_table[src++->value];
                                } while (--n != 0);
                            }
                            src += count - transform_count;
                        } else {
                            transform_count = count;
                            if ((byte)transform_count != 0) {
                                unsigned int n = transform_count & 0xff;
                                do {
                                    --dst;
                                    *dst = color_table[src++->value];
                                } while (--n != 0);
                            }
                        }
                    }
                } else {
                    count = command >> 1;
                    if (count == 0) {
                        state = 3;
                    } else {
                        xpos -= count;
                        if (xpos < clip_x0) {
                            state = 1;
                            transform_count = xpos - clip_x0 + count;
                        } else {
                            transform_count = count;
                        }
                        dst -= transform_count;
                        memset(dst, color_table[src->value], transform_count);
                        ++src;
                    }
                }
            } while (state == 0);
        }

        --state;
        if (state == 0) {
            do {
                command = src++->value;
                if (command & 1) {
                    count = command >> 1;
                    if (count != 0)
                        src += count;
                    else
                        ++src;
                } else {
                    if ((command & 0xfe) == 0)
                        state = 2;
                    else
                        ++src;
                }
            } while (state == 0);
        }

        save_buffer += width;
        dst = save_buffer;
    } while (--rows != 0);

    return 1;
}

byte TShape::shape_mirror_shadow_clipped(
    TDrawArea* drawarea, long shape_x1, long shape_y0, long clip_x0,
    long clip_y0, long clip_x1, long clip_y1, byte* color_table) {
    long pitch = drawarea->AlignedWidth() * drawarea->Orien;
    byte* src = (byte*)(this->shape_header + 1);
    byte* dst;
    byte count;

    if (drawarea->Orien < 1)
        dst = drawarea->Bits +
              (clip_y0 - drawarea->Height + 1) * pitch + clip_x1 + 1;
    else
        dst = drawarea->Bits + clip_y0 * pitch + clip_x1 + 1;

    byte* save_buffer = dst;

    if (shape_y0 < clip_y0) {
        long skip = clip_y0 - shape_y0;
        shape_y0 += skip;
        do {
            byte done = 0;
            do {
                byte command = *src++;
                if ((command & 1) == 1) {
                    count = command >> 1;
                    if (count)
                        src += count;
                    else
                        ++src;
                } else {
                    if ((command & 0xfe) == 0)
                        done = 1;
                    else
                        ++src;
                }
            } while (!done);
        } while (--skip != 0);
    }

    if (shape_y0 <= clip_y1) {
        long rows = clip_y1 - shape_y0 + 1;
        do {
            long xpos = shape_x1;
            char state;

            if (xpos > clip_x1) {
                state = 0;
                while (state == 0) {
                    byte command = *src++;
                    if ((command & 1) == 1) {
                        count = command >> 1;
                        if (count == 0) {
                            xpos -= *src++;
                            if (xpos <= clip_x1) {
                                if (xpos < clip_x0)
                                    state = 2;
                                else {
                                    state = 1;
                                    dst += xpos - clip_x1;
                                }
                            }
                        } else {
                            xpos -= count;
                            if (xpos <= clip_x1) {
                                unsigned int transform_count;
                                if (xpos < clip_x0) {
                                    transform_count =
                                        clip_x1 - clip_x0 + 1;
                                    state = 2;
                                } else {
                                    transform_count = clip_x1 - xpos;
                                    state = 1;
                                }
                                if ((byte)transform_count != 0) {
                                    transform_count &= 0xff;
                                    do {
                                        --dst;
                                        *dst = color_table[*dst];
                                    } while (--transform_count != 0);
                                }
                            }
                            src += count;
                        }
                    } else {
                        count = command >> 1;
                        if (count == 0) {
                            state = 3;
                        } else {
                            xpos -= count;
                            if (xpos <= clip_x1) {
                                unsigned int transform_count;
                                if (xpos < clip_x0) {
                                    transform_count =
                                        clip_x1 - clip_x0 + 1;
                                    state = 2;
                                } else {
                                    transform_count = clip_x1 - xpos;
                                    state = 1;
                                }
                                if ((byte)transform_count != 0) {
                                    transform_count &= 0xff;
                                    do {
                                        --dst;
                                        *dst = color_table[*dst];
                                    } while (--transform_count != 0);
                                }
                            }
                            ++src;
                        }
                    }
                }
            } else {
                state = 1;
            }

            --state;
            while (state == 0) {
                byte command = *src++;
                if ((command & 1) == 1) {
                    count = command >> 1;
                    if (count == 0) {
                        count = *src++;
                        xpos -= count;
                        dst -= count;
                        if (xpos < clip_x0)
                            state = 1;
                    } else {
                        xpos -= count;
                        if (xpos < clip_x0) {
                            unsigned int transform_count =
                                xpos - clip_x0 + count;
                            state = 1;
                            if ((byte)transform_count != 0) {
                                transform_count &= 0xff;
                                do {
                                    --dst;
                                    *dst = color_table[*dst];
                                } while (--transform_count != 0);
                            }
                        } else {
                            unsigned int transform_count = count;
                            do {
                                --dst;
                                *dst = color_table[*dst];
                            } while (--transform_count != 0);
                        }
                        src += count;
                    }
                } else {
                    count = command >> 1;
                    if (count == 0) {
                        state = 3;
                    } else {
                        xpos -= count;
                        if (xpos < clip_x0) {
                            unsigned int transform_count =
                                xpos - clip_x0 + count;
                            state = 1;
                            if ((byte)transform_count != 0) {
                                transform_count &= 0xff;
                                do {
                                    --dst;
                                    *dst = color_table[*dst];
                                } while (--transform_count != 0);
                            }
                        } else {
                            unsigned int transform_count = count;
                            do {
                                --dst;
                                *dst = color_table[*dst];
                            } while (--transform_count != 0);
                        }
                        ++src;
                    }
                }
            }

            --state;
            while (state == 0) {
                byte command = *src++;
                if ((command & 1) == 1) {
                    count = command >> 1;
                    if (count)
                        src += count;
                    else
                        ++src;
                } else {
                    if ((command & 0xfe) == 0)
                        state = 2;
                    else
                        ++src;
                }
            }

            save_buffer += pitch;
            dst = save_buffer;
        } while (--rows != 0);
    }

    return 1;
}

byte TShape::shape_dither(TDrawArea* drawarea, long x, long y, long shape_num, long dx, long dy) {
    long clip_y1;
    tagRECT rect;

    rect = drawarea->ClipRect;
    if (this->Check_shape(shape_num, (char*)"RGL_shape_draw") != 0)
        return 0;

    Shape_Header* frame =
        (Shape_Header*)(this->shape + this->offsets[shape_num].shape);
    this->shape_header = frame;

    long shape_x0 = frame->xmin + x;
    long shape_y0 = frame->ymin + y;
    long shape_x1 = frame->xmax + x;
    long shape_y1 = frame->ymax + y;

    long clip_x0 = shape_x0;
    long clip_y0 = shape_y0;
    long clip_x1 = shape_x1;
    clip_y1 = shape_y1;

    if (shape_x0 < rect.left)
        clip_x0 = rect.left;
    if (shape_y0 < rect.top)
        clip_y0 = rect.top;
    if (shape_x1 > rect.right)
        clip_x1 = rect.right;
    if (shape_y1 > rect.bottom)
        clip_y1 = rect.bottom;
    if (clip_x0 < 0)
        clip_x0 = 0;
    if (clip_y0 < 0)
        clip_y0 = 0;
    if (drawarea->Width <= clip_x1)
        clip_x1 = drawarea->Width - 1;
    if (drawarea->Height <= clip_y1)
        clip_y1 = drawarea->Height - 1;

    if (clip_x0 <= clip_x1 && clip_y0 <= clip_y1) {
        if (clip_x0 == shape_x0 && clip_y0 == shape_y0 &&
            clip_x1 == shape_x1 && clip_y1 == shape_y1) {
            return this->shape_dithered_unclipped(
                drawarea, shape_x0, shape_y0, dx, dy);
        }

        return this->shape_dithered_clipped(
            drawarea, shape_x0, shape_y0, clip_x0, clip_y0, clip_x1, clip_y1,
            dx, dy);
    }

    return 0;
}

byte TShape::shape_dithered_unclipped(TDrawArea* drawarea, long shape_x0, long shape_y0, long dx, long dy) {
    long orientation = drawarea->Orien;
    long width = drawarea->AlignedWidth() * orientation;
    Shape_Header* header = this->shape_header;
    long height = header->ymax - header->ymin + 1;
    byte* src = (byte*)(header + 1);
    long save_flag;

    if (orientation < 1)
        save_flag = (shape_y0 - drawarea->Height + 1) * width;
    else
        save_flag = shape_y0 * width;

    byte* save_buffer = drawarea->Bits + shape_x0 + save_flag;
    byte index1 = (byte)((dx + shape_x0) & 1);
    if (((dy + shape_y0) & 1U) != 0)
        index1 = (byte)(index1 != 1);

    if (height > 0) {
        long rows = height;
        do {
            byte row_dither = (byte)(index1 != 1);
            byte* dst = save_buffer;
            byte done = 0;

            do {
                byte command = *src++;
                if ((command & 1) == 1) {
                    byte source_count = command >> 1;
                    if (source_count == 0) {
                        byte count = *src++;
                        dst += count;
                        if ((count & 1) != 0)
                            index1 = (byte)(index1 != 1);
                    } else {
                        byte count = source_count;
                        if (index1 != 0) {
                            --count;
                            ++dst;
                        }
                        index1 = (byte)(count & 1);
                        byte* end = dst + count;
                        while (dst < end) {
                            *dst = 0;
                            dst += 2;
                        }
                        if (index1 != 0)
                            --dst;
                        src += source_count;
                    }
                } else {
                    byte source_count = command >> 1;
                    if (source_count == 0) {
                        done = 1;
                    } else {
                        byte count = source_count;
                        if (index1 != 0) {
                            --count;
                            ++dst;
                        }
                        index1 = (byte)(count & 1);
                        byte* end = dst + count;
                        while (dst < end) {
                            *dst = 0;
                            dst += 2;
                        }
                        if (index1 != 0)
                            --dst;
                        ++src;
                    }
                }
            } while (done == 0);

            save_buffer += width;
            index1 = row_dither;
        } while (--rows != 0);
    }

    return 1;
}

byte TShape::shape_dithered_clipped(TDrawArea* drawarea, long shape_x0,
                                    long shape_y0, long clip_x0,
                                    long clip_y0, long clip_x1,
                                    long clip_y1, long dx, long dy) {
    long orientation = drawarea->Orien;
    long width = drawarea->AlignedWidth() * orientation;
    byte* src = (byte*)(this->shape_header + 1);
    long y = clip_y0;

    if (orientation < 1)
        y = clip_y0 - drawarea->Height + 1;

    byte* save_buffer = drawarea->Bits + clip_x0 + y * width;
    byte save_flag = (byte)((dx + clip_x0) & 1);
    if (((dy + clip_y0) & 1U) != 0)
        save_flag = (byte)(save_flag != 1);

    y = shape_y0;
    if (shape_y0 < clip_y0) {
        long skip_rows = clip_y0 - shape_y0;
        y += skip_rows;
        do {
            byte done = 0;
            do {
                byte command = *src++;
                if ((command & 1) == 1) {
                    command >>= 1;
                    if (command != 0)
                        src += command;
                    else
                        ++src;
                } else {
                    if ((command & 0xfe) == 0)
                        done = 1;
                    else
                        ++src;
                }
            } while (done == 0);
        } while (--skip_rows != 0);
    }

    if (y > clip_y1)
        return 1;

    do {
        byte index1 = (byte)(save_flag != 1);
        byte* dst = save_buffer;
        long x = shape_x0;
        byte state;

        if (x < clip_x0) {
            state = 0;
            do {
                byte command = *src++;
                if ((command & 1) == 1) {
                    command >>= 1;
                    if (command == 0) {
                        command = *src++;
                        x += command;
                        if (x >= clip_x0) {
                            if (x > clip_x1) {
                                state = 2;
                            } else {
                                state = 1;
                                byte count = (byte)(x - clip_x0);
                                dst += count;
                                if ((count & 1) != 0)
                                    save_flag = (byte)(save_flag != 1);
                            }
                        }
                    } else {
                        x += command;
                        if (x > clip_x0) {
                            byte count;
                            if (x > clip_x1) {
                                state = 2;
                                count = (byte)(clip_x1 - clip_x0 + 1);
                            } else {
                                state = 1;
                                count = (byte)(x - clip_x0);
                            }

                            if (save_flag != 0) {
                                --count;
                                ++dst;
                            }
                            save_flag = (byte)(count & 1);
                            byte* end = dst + count;
                            while (dst < end) {
                                *dst = 0;
                                dst += 2;
                            }
                            if (save_flag != 0)
                                --dst;
                        }
                        src += command;
                    }
                } else {
                    command >>= 1;
                    if (command == 0) {
                        state = 3;
                    } else {
                        x += command;
                        if (x > clip_x0) {
                            byte count;
                            if (x > clip_x1) {
                                state = 2;
                                count = (byte)(clip_x1 - clip_x0 + 1);
                            } else {
                                state = 1;
                                count = (byte)(x - clip_x0);
                            }

                            if (save_flag != 0) {
                                --count;
                                ++dst;
                            }
                            save_flag = (byte)(count & 1);
                            byte* end = dst + count;
                            while (dst < end) {
                                *dst = 0;
                                dst += 2;
                            }
                            if (save_flag != 0)
                                --dst;
                        }
                        ++src;
                    }
                }
            } while (state == 0);
        } else {
            state = 1;
        }

        --state;
        while (state == 0) {
            byte command = *src++;
            if ((command & 1) == 1) {
                command >>= 1;
                if (command == 0) {
                    command = *src++;
                    x += command;
                    if ((command & 1) != 0)
                        save_flag = (byte)(save_flag != 1);
                    dst += command;
                    if (x > clip_x1)
                        state = 1;
                } else {
                    x += command;
                    byte count = command;
                    if (x > clip_x1) {
                        state = 1;
                        count = (byte)(clip_x1 - x + command + 1);
                    }

                    if (save_flag != 0) {
                        --count;
                        ++dst;
                    }
                    save_flag = (byte)(count & 1);
                    byte* end = dst + count;
                    while (dst < end) {
                        *dst = 0;
                        dst += 2;
                    }
                    if (save_flag != 0)
                        --dst;
                    src += command;
                }
            } else {
                command >>= 1;
                if (command == 0) {
                    state = 3;
                } else {
                    x += command;
                    byte count = command;
                    if (x > clip_x1) {
                        state = 1;
                        count = (byte)(clip_x1 - x + command + 1);
                    }

                    if (save_flag != 0) {
                        --count;
                        ++dst;
                    }
                    save_flag = (byte)(count & 1);
                    byte* end = dst + count;
                    while (dst < end) {
                        *dst = 0;
                        dst += 2;
                    }
                    if (save_flag != 0)
                        --dst;
                    ++src;
                }
            }
        }

        --state;
        while (state == 0) {
            byte command = *src++;
            if ((command & 1) == 1) {
                command >>= 1;
                if (command != 0)
                    src += command;
                else
                    ++src;
            } else {
                if ((command & 0xfe) == 0)
                    state = 2;
                else
                    ++src;
            }
        }

        save_buffer += width;
        ++y;
        save_flag = index1;
    } while (y <= clip_y1);

    return 1;
}
