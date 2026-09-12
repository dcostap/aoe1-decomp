
#include "../include/Shape.h"
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



TShape::TShape()
{
    shape = 0;
    shape_header = 0;
    head = 0;
    offsets = 0;
    FShape = 0;
    shape_info = 0;
    load_type = -1;
    load_size = 0;
}

TShape::TShape(char* filename, long resource_id)
{
    char next_file[260];
    int file_handle;
    int file_size;

    shape = 0;
    shape_header = 0;
    head = 0;
    offsets = 0;
    FShape = 0;

    if (shape_file_first != 0 || resource_id < 0) {
        color_log('T', 'T', 1);
        strcpy(next_file, filename);
        strcpy(next_file + strlen(next_file) - 3, "SLP");
        ++Shape_Loads;
        file_handle = open(next_file, 0x8000);
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
            strcpy(next_file + strlen(next_file) - 3, "SHP");
            file_handle = open(next_file, 0x8000);
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

    if (FShape == 0 && shape == 0 && resource_id >= 0) {
        ++Shape_Loads;
        shape = RESFILE_load(0x73687020, resource_id,
            load_type, load_size);
        if (shape != 0) {
            if (((Shape_File_Header*)shape)->version == shape_version_110) {
                head = (Shape_File_Header*)shape;
                offsets = (Shape_Offsets*)(head + 1);
            }
        } else {
            shape = RESFILE_load(0x736c7020, resource_id,
                load_type, load_size);
            if (shape != 0) {
                FShape = (SLhape_File_Header*)shape;
                shape = 0;
                shape_info = (Shape_Info*)(FShape + 1);
            }
        }
    }
}

TShape::~TShape()
{
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

byte TShape::Check_shape(long param_1, char* param_2)
{
    char* msg = 0;

    if (this->shape == 0 && this->FShape == 0) {
        return 1;
    }

    if (this->shape != 0) {
        Shape_File_Header* h = this->head;
        if (h == 0) {
            addstring(&msg, "ERROR: (", param_2);
            addstring(&msg, msg, ") Bad shape");
            free(msg);
            return 1;
        }

        if (param_1 < 0 || param_1 < h->shape_num) {
            if (h->version != shape_version_110) {
                addstring(&msg, "ERROR: (", param_2);
                addstring(&msg, msg, ") shape version wrong");
                free(msg);
                return 1;
            }
        } else {
            addstring(&msg, "ERROR: (", param_2);
            addstring(&msg, msg, ") shape number out of bounds");
            free(msg);
            return 1;
        }
    }

    if (this->FShape != 0 && param_1 >= 0 &&
        param_1 >= this->FShape->Num_Shapes) {
        addstring(&msg, "ERROR: (", param_2);
        addstring(&msg, msg, ") Fshape number out of bounds");
        free(msg);
        return 1;
    }

    return 0;
}

int TShape::is_loaded()
{
    if (this->shape || this->FShape)
        return 1;
    return 0;
}

byte TShape::shape_bounds(long index, short& out_width, short& out_height)
{
    if (this->FShape != 0) {
        out_width = (short)this->shape_info[index].Width;
        out_height = (short)this->shape_info[index].Height;
        return 1;
    }

    if (index >= 0) {
        unsigned char result = Check_shape(index, "RGL_shape_resolution");
        if (result == 0) {
            this->shape_header =
                (Shape_Header*)(this->shape + this->offsets[index].shape);
            out_width = (short)(this->shape_header->bounds >> 16);
            out_height = (short)this->shape_header->bounds;
            return 1;
        }
    }

    return 0;
}

long TShape::shape_count()
{
    if (Check_shape(-1, "RGL_shape_count") != 0) {
        return 0;
    }
    if (this->FShape != 0) {
        return this->FShape->Num_Shapes;
    }
    return this->head->shape_num;
}

byte TShape::shape_minmax(long& out_minx, long& out_miny,
                          long& out_maxx, long& out_maxy, long facet)
{
    if (facet >= 0) {
        if (!Check_shape(facet, "RGL_shape_minxy")) {
            if (FShape != 0) {
                out_minx = -shape_info[facet].Hotspot_X;
                out_miny = -shape_info[facet].Hotspot_Y;
                out_maxx = shape_info[facet].Width - shape_info[facet].Hotspot_X - 1;
                out_maxy = shape_info[facet].Height - shape_info[facet].Hotspot_Y - 1;
            } else {
                shape_header = (Shape_Header*)(shape + offsets[facet].shape);
                out_minx = shape_header->xmin;
                out_miny = shape_header->ymin;
                out_maxx = shape_header->xmax;
                out_maxy = shape_header->ymax;
            }
            return 1;
        }
    }
    return 0;
}

byte TShape::shape_check(long x, long y, long frame)
{
    if (frame < 0 ||
        this->Check_shape(frame, (char*)"RGL_shape_draw") != 0)
        return 0;

    if (this->FShape != 0) {
        Shape_Info* info = this->shape_info + frame;
        long shape_x = info->Hotspot_X + x;
        long shape_y = info->Hotspot_Y + y;
        long width = info->Width;

        if (shape_x >= 0 && shape_y >= 0 && shape_x < width &&
            shape_y < info->Height) {
            short* outline =
                (short*)(this->FShape->Version +
                         info->Shape_Outline_Offset);
            long left = outline[shape_y * 2];
            long right = outline[shape_y * 2 + 1];

            if (left >= 0 && left <= shape_x &&
                shape_x <= width - right) {
                long* data_offsets =
                    (long*)(this->FShape->Version +
                            info->Shape_Data_Offsets);
                byte* source =
                    (byte*)(this->FShape->Version + data_offsets[shape_y]);

                if (left < width) {
                    long count;
                    while (left <= shape_x) {
                        byte command = *source++;

                        switch (command & 0x0f) {
                        case 0:
                        case 4:
                        case 8:
                        case 0x0c:
                            count = command >> 2;
                            left += count;
                            if (shape_x < left)
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
                            if (shape_x < left)
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
                            if (shape_x < left)
                                return 1;
                            source += count;
                            break;
                        case 7:
                        case 0x0a:
                            count = command >> 4;
                            if (count == 0)
                                count = *source++;
                            left += count;
                            if (shape_x < left)
                                return 1;
                            ++source;
                            break;
                        case 0x0b:
                            count = command >> 4;
                            if (count == 0)
                                count = *source++;
                            left += count;
                            if (shape_x < left)
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
            (Shape_Header*)(this->shape + this->offsets[frame].shape);
        this->shape_header = header;

        long shape_x = header->xmin;
        long shape_y = header->ymin;
        byte* source = (byte*)(header + 1);

        if (shape_y <= y && y <= header->ymax && shape_x <= x &&
            x <= header->xmax) {
            if (shape_y < y) {
                long rows = y - shape_y;
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
                        shape_x += *source;
                        if (x < shape_x)
                            return 0;
                        ++source;
                    } else {
                        shape_x += command;
                        if (x < shape_x)
                            return 1;
                        source += command;
                    }
                } else {
                    command >>= 1;
                    if (command == 0) {
                        done = 1;
                    } else {
                        shape_x += command;
                        if (x < shape_x)
                            return 1;
                        ++source;
                    }
                }
            } while (!done);
        }
    }

    return 0;
}

byte TShape::shape_draw(TDrawArea* td, long x, long y, long shape_num,
                        byte mode, byte* table)
{
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
                SDI_List->AddDrawNode(this->FShape, info, SDI_Draw_Line,
                                      x - info->Hotspot_X,
                                      y - info->Hotspot_Y, fog_next_shape,
                                      table, ASMGet_Color_Xform(),
                                      SDI_Draw_Level, SDI_Object_ID);
                return 1;
            }

            TSpan_List_Manager* cur_span_list = td->CurSpanList;
            int line_count;
            if (td->SpanList->Num_Lines < cur_span_list->Num_Lines)
                line_count = td->SpanList->Num_Lines - 1;
            else
                line_count = cur_span_list->Num_Lines - 1;
            ASMSet_Surface_Info(td->CurDisplayOffsets,
                                cur_span_list->Line_Head_Ptrs,
                                cur_span_list->Line_Tail_Ptrs,
                                0, 0, cur_span_list->Max_Span_Px,
                                line_count);
            if (table != 0)
                ASMSet_Xlate_Table(table);

            Shape_Info* info = (Shape_Info*)((char*)this->FShape +
                                             ((shape_num + 1) << 5));
            ASMDraw_Sprite(this->FShape, x - info->Hotspot_X,
                           y - info->Hotspot_Y, info->Width, info->Height,
                           info->Shape_Data_Offsets,
                           info->Shape_Outline_Offset, fog_next_shape);
            ++ASM_Fast_Count;
            return 1;
        } else {
            rect = td->ClipRect;
            if (this->shape != 0) {
                Shape_Header* frame =
                    (Shape_Header*)(this->shape +
                                    this->offsets[shape_num].shape);
                this->shape_header = frame;

                long x0 = frame->xmin + x;
                long y0 = frame->ymin + y;
                shape_x1 = frame->xmax + x;
                shape_y1 = frame->ymax + y;
                long original_x0 = x0;
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
                if (shape_x1 >= td->Width)
                    shape_x1 = td->Width - 1;
                if (shape_y1 >= td->Height)
                    shape_y1 = td->Height - 1;

                if (x <= shape_x1 && y <= shape_y1) {
                    if (x == x0 && y == y0 &&
                        shape_x1 == original_x1 && shape_y1 == original_y1) {
                        switch ((unsigned char)mode) {
                        case 2:
                            if (table == 0) {
                                long draw_x = original_x0;
                                long draw_y = original_y0;
                                ret_num = this->shape_draw_unclipped(
                                    td, draw_x, draw_y, shape_num);
                            } else {
                                ret_num = this->shape_shadow_unclipped(
                                    td, original_x0, original_y0, table);
                            }
                            break;
                        case 1:
                            if (table == 0) {
                                long draw_x = original_x0;
                                long draw_y = original_y0;
                                ret_num = this->shape_draw_unclipped(
                                    td, draw_x, draw_y, shape_num);
                            } else {
                                ret_num = this->shape_color_trans_unclipped(
                                    td, original_x0, original_y0,
                                    shape_num, table);
                            }
                            break;
                        case 0: {
                            ret_num = this->shape_draw_unclipped(
                                td, original_x0, original_y0,
                                shape_num);
                            break;
                        }
                        default:
                            break;
                        }
                        return ret_num;
                    }

                    switch ((unsigned char)mode) {
                    case 2:
                        if (table != 0)
                            return this->shape_shadow_clipped(
                                td, original_x0, original_y0, x, y,
                                shape_x1, shape_y1, table);
                        break;
                    case 1:
                        if (table != 0)
                            return this->shape_color_trans_clipped(
                                td, original_x0, original_y0, shape_num,
                                x, y, shape_x1, shape_y1, table);
                        break;
                    case 0:
                        break;
                    default:
                        return ret_num;
                    }
                    return this->shape_draw_clipped(
                        td, original_x0, original_y0, x, y, shape_x1,
                        shape_y1);
                }
            }
        }
    }

    return ret_num;
}

byte TShape::shape_draw_unclipped(TDrawArea* da, long y, long x,
                                   long table)
{
    Shape_Header* sh = this->shape_header;
    int height = sh->ymax - sh->ymin + 1;
    byte* p = (byte*)(sh + 1);
    long pitch = da->AlignedWidth() * da->Orien;
    long rows;
    byte* d;
    byte c;

    if (da->Orien < 1)
        d = da->Bits + (x - da->Height + 1) * pitch + y;
    else
        d = da->Bits + x * pitch + y;

    y = (long)d;

    if (height > 0) {
        rows = height;
        do {
            byte done = 0;
            do {
                byte b = *p++;
                if ((b & 1) == 1) {
                    c = b >> 1;
                    if (c == 0) {
                        d += *p;
                        p++;
                    } else {
                        memcpy(d, p, c);
                        d += c;
                        p += c;
                    }
                } else {
                    c = b >> 1;
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
            y += pitch;
            d = (byte*)y;
        } while (--rows);
    }

    return 1;
}

byte TShape::shape_color_trans_unclipped(TDrawArea* drawarea, long shape_x0,
                                         long shape_y0, long shape_num,
                                         byte* color_table)
{
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

byte TShape::shape_shadow_unclipped(TDrawArea* da, long x, long y,
                                    byte* table)
{
    Shape_Header* sh = shape_header;
    byte* p = (byte*)(sh + 1);
    long height = sh->ymax - sh->ymin + 1;
    byte* save_buffer;
    long rows;
    long width;

    width = da->AlignedWidth() * da->Orien;

    if (da->Orien < 1)
        save_buffer = da->Bits + ((y - da->Height) + 1) * width + x;
    else
        save_buffer = da->Bits + y * width + x;

    x = (long)save_buffer;

    if (height > 0) {
        rows = height;
        do {
            byte* dst = (byte*)x;
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
                            *dst = table[*dst];
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
                            *dst = table[*dst];
                            dst++;
                        }
                        p++;
                    }
                }
            } while (!done);

            x += width;
        } while (--rows);
    }

    return 1;
}

byte TShape::shape_draw_clipped(TDrawArea* draw_area, long shape_x1,
                                long shape_y1, long clip_x0, long clip_y0,
                                long clip_x1, long clip_y1)
{
    long pitch = draw_area->AlignedWidth() * draw_area->Orien;
    byte* src = (byte*)(this->shape_header + 1);
    byte* dst;

    if (draw_area->Orien < 1)
        dst = draw_area->Bits +
              (clip_y0 - draw_area->Height + 1) * pitch + clip_x0;
    else
        dst = draw_area->Bits + clip_y0 * pitch + clip_x0;

    byte* save_buffer = dst;

    if (shape_y1 < clip_y0) {
        long skip_rows = clip_y0 - shape_y1;
        shape_y1 += skip_rows;
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

    if (shape_y1 > clip_y1)
        return 1;

    long rows = clip_y1 - shape_y1 + 1;
    do {
        long xpos = shape_x1;
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

byte TShape::shape_color_trans_clipped(TDrawArea* draw_area, long shape_x1,
                                       long shape_y1, long shape_idx,
                                       long clip_x0, long clip_y0,
                                       long clip_x1, long clip_y1,
                                       byte* table)
{
    long pitch = draw_area->AlignedWidth() * draw_area->Orien;
    Shape_Payload* src = (Shape_Payload*)(this->shape_header + 1);
    byte* dst;
    if (draw_area->Orien < 1)
        dst = draw_area->Bits +
              (clip_y0 - draw_area->Height + 1) * pitch + clip_x0;
    else
        dst = draw_area->Bits + clip_y0 * pitch + clip_x0;

    byte* save_buffer = dst;

    if (shape_y1 < clip_y0) {
        long skip = clip_y0 - shape_y1;
        shape_y1 += skip;
        do {
            byte done = 0;
            do {
                byte command = src++->value;
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
        } while (--skip != 0);
    }

    if (shape_y1 > clip_y1)
        return 1;
    long rows = clip_y1 - shape_y1 + 1;

    do {
        long xpos = shape_x1;
        byte state;
        if (xpos < clip_x0) {
            state = 0;
            do {
                byte command = src++->value;
                if (command & 1) {
                    command >>= 1;
                    if (command == 0) {
                        command = src++->value;
                        xpos += command;
                        if (xpos >= clip_x0) {
                            if (xpos > clip_x1)
                                state = 2;
                            else {
                                state = 1;
                                dst += xpos - clip_x0;
                            }
                        }
                    } else {
                        xpos += command;
                        if (xpos >= clip_x0) {
                            if (xpos > clip_x1) {
                                long cnt = clip_x1 - clip_x0 + 1;
                                state = 2;
                                src += clip_x0 - xpos + command;
                                byte* end = dst + cnt;
                                while (dst < end)
                                    *dst++ = table[src++->value];
                                src += command -
                                       (clip_x0 - xpos + command) - cnt;
                            } else {
                                long cnt = xpos - clip_x0;
                                state = 1;
                                src += command - cnt;
                                byte* end = dst + cnt;
                                while (dst < end)
                                    *dst++ = table[src++->value];
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
                        xpos += command;
                        if (xpos >= clip_x0) {
                            if (xpos > clip_x1) {
                                long cnt = clip_x1 - clip_x0 + 1;
                                state = 2;
                                memset(dst, table[src->value], cnt);
                                dst += cnt;
                            } else {
                                long cnt = xpos - clip_x0;
                                state = 1;
                                memset(dst, table[src->value], cnt);
                                dst += cnt;
                            }
                        }
                        ++src;
                    }
                }
            } while (!state);
        } else {
            state = 1;
        }

        state--;
        if (state == 0) {
            do {
                byte command = src++->value;
                if (command & 1) {
                    command >>= 1;
                    if (command == 0) {
                        command = src++->value;
                        xpos += command;
                        dst += command;
                        if (xpos > clip_x1)
                            state = 1;
                    } else {
                        xpos += command;
                        if (xpos > clip_x1) {
                            long cnt = command + clip_x1 - xpos + 1;
                            state = 1;
                            byte* end = dst + cnt;
                            while (dst < end)
                                *dst++ = table[src++->value];
                            dst += command - cnt;
                            src += command - cnt;
                        } else {
                            byte* end = dst + command;
                            while (dst < end)
                                *dst++ = table[src++->value];
                        }
                    }
                } else {
                    command >>= 1;
                    if (command == 0) {
                        state = 3;
                    } else {
                        xpos += command;
                        if (xpos > clip_x1) {
                            long cnt = command + clip_x1 - xpos + 1;
                            state = 1;
                            memset(dst, table[src->value], cnt);
                            dst += command;
                        } else {
                            memset(dst, table[src->value], command);
                            dst += command;
                        }
                        ++src;
                    }
                }
            } while (!state);
        }

        state--;
        if (state == 0) {
            do {
                byte command = src++->value;
                if ((command & 1) == 1) {
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
            } while (!state);
        }
        save_buffer += pitch;
        dst = save_buffer;
    } while (--rows != 0);
    return 1;
}

byte TShape::shape_shadow_clipped(TDrawArea* draw_area, long shape_x1,
                                   long shape_y1, long clip_x0, long clip_y0,
                                   long clip_x1, long clip_y1, byte* table)
{
    byte command;
    char state;
    long width;
    width = draw_area->AlignedWidth() * draw_area->Orien;
    byte* buffer = (byte*)(this->shape_header + 1);

    byte* save_buffer;
    if (draw_area->Orien < 1) {
        save_buffer = draw_area->Bits +
                      (clip_y0 - draw_area->Height + 1) * width + clip_x0;
    } else {
        save_buffer = draw_area->Bits + clip_y0 * width + clip_x0;
    }

    if (shape_y1 < clip_y0) {
        long skip_rows = clip_y0 - shape_y1;
        shape_y1 += skip_rows;
        do {
            byte done = 0;
            do {
                command = *buffer++;
                if (command & 1) {
                    command >>= 1;
                    if (command)
                        buffer += command;
                    else
                        ++buffer;
                } else {
                    if ((command & 0xfe) != 0)
                        ++buffer;
                    else
                        done = 1;
                }
            } while (!done);
        } while (--skip_rows != 0);
    }

    if (shape_y1 <= clip_y1) {
        shape_y1 = clip_y1 - shape_y1 + 1;
        do {
            byte* cur = save_buffer;
            long sx = shape_x1;
            if (shape_x1 < clip_x0) {
                state = 0;
                do {
                    command = *buffer++;
                    if (command & 1) {
                        command >>= 1;
                        if (command == 0) {
                            command = *buffer++;
                            sx += command;
                            if (sx >= clip_x0) {
                                if (sx > clip_x1)
                                    state = 2;
                                else {
                                    state = 1;
                                    cur += sx - clip_x0;
                                }
                            }
                        } else {
                            sx += command;
                            if (sx >= clip_x0) {
                                if (sx > clip_x1) {
                                    state = 2;
                                    byte* end = cur + (clip_x1 - clip_x0) + 1;
                                    for (; cur < end; ++cur) {
                                        *cur = table[*cur];
                                    }
                                } else {
                                    state = 1;
                                    byte* end = cur + (sx - clip_x0);
                                    for (; cur < end; ++cur) {
                                        *cur = table[*cur];
                                    }
                                }
                            }
                            buffer += command;
                        }
                    } else {
                        command >>= 1;
                        if (command == 0)
                            state = 3;
                        else {
                            sx += command;
                            if (sx >= clip_x0) {
                                if (sx > clip_x1) {
                                    state = 2;
                                    byte* end = cur + (clip_x1 - clip_x0) + 1;
                                    for (; cur < end; ++cur) {
                                        *cur = table[*cur];
                                    }
                                } else {
                                    state = 1;
                                    byte* end = cur + (sx - clip_x0);
                                    for (; cur < end; ++cur) {
                                        *cur = table[*cur];
                                    }
                                }
                            }
                            ++buffer;
                        }
                    }
                } while (state == 0);
            } else {
                state = 1;
            }

            --state;
            while (state == 0) {
                command = *buffer++;
                if (command & 1) {
                    command >>= 1;
                    if (command == 0) {
                        command = *buffer++;
                        sx += command;
                        cur += command;
                        if (sx > clip_x1)
                            state = 1;
                    } else {
                        sx += command;
                        if (sx > clip_x1) {
                            state = 1;
                            byte* end = cur + command + clip_x1 - sx + 1;
                            while (cur < end) {
                                *cur = table[*cur];
                                ++cur;
                            }
                        } else {
                            byte* end = cur + command;
                            for (; cur < end; ++cur) {
                                *cur = table[*cur];
                            }
                        }
                        buffer += command;
                    }
                } else {
                    command >>= 1;
                    if (command == 0)
                        state = 3;
                    else {
                        sx += command;
                        if (sx > clip_x1) {
                            state = 1;
                            byte* end = cur + command + clip_x1 - sx + 1;
                            while (cur < end) {
                                *cur = table[*cur];
                                ++cur;
                            }
                        } else {
                            byte* end = cur + command;
                            for (; cur < end; ++cur) {
                                *cur = table[*cur];
                            }
                        }
                        ++buffer;
                    }
                }
            }

            --state;
            while (state == 0) {
                command = *buffer++;
                if (command & 1) {
                    command >>= 1;
                    if (command != 0)
                        buffer += command;
                    else
                        ++buffer;
                } else {
                    if ((command & 0xfe) == 0)
                        state = 2;
                    else
                        ++buffer;
                }
            }

            save_buffer += width;
        } while (--shape_y1 != 0);
    }
    return 1;
}

byte TShape::shape_mirror(TDrawArea* td, long x, long y, long shape_num,
                          byte mode, byte* table)
{
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
                    (info->Hotspot_X - info->Width) + x,
                    y - info->Hotspot_Y, fog_next_shape + 2, table,
                    ASMGet_Color_Xform(), SDI_Draw_Level, SDI_Object_ID);
                return 1;
            }

            TSpan_List_Manager* span_list = td->SpanList;
            int span_lines = span_list->Num_Lines;
            TSpan_List_Manager* current = td->CurSpanList;
            int current_lines = current->Num_Lines;
            int end_line;
            if (span_lines < current_lines)
                end_line = span_lines - 1;
            else
                end_line = current_lines - 1;
            ASMSet_Surface_Info(
                td->CurDisplayOffsets, current->Line_Head_Ptrs,
                current->Line_Tail_Ptrs, 0, 0, current->Max_Span_Px,
                end_line);
            if (table != 0)
                ASMSet_Xlate_Table(table);

            Shape_Info* info = (Shape_Info*)(this->FShape + shape_num + 1);
            ASMDraw_Sprite(
                this->FShape, (info->Hotspot_X + x) - info->Width,
                y - info->Hotspot_Y, info->Width, info->Height,
                info->Shape_Data_Offsets, info->Shape_Outline_Offset,
                fog_next_shape + 2);
            ASM_Fast_Count++;
            return 1;
        }

        rect = td->ClipRect;
        if (this->shape != 0) {
            this->shape_header =
                (Shape_Header*)(this->shape + this->offsets[shape_num].shape);

            long shape_x0 = x - shape_header->xmax;
            long raw_y0 = y + shape_header->ymin;
            clip_y0 = raw_y0;
            long shape_x1 = x - shape_header->xmin;
            shape_y1 = y + shape_header->ymax;
            long clipped_x1 = shape_x1;
            long clipped_y1 = shape_y1;
            x = shape_x0;
            y = clipped_y1;

            if (x < rect.left)
                x = rect.left;
            if (clip_y0 < rect.top)
                clip_y0 = rect.top;
            if (clipped_x1 > rect.right)
                clipped_x1 = rect.right;
            if (y > rect.bottom)
                y = rect.bottom;
            if (x < 0)
                x = 0;
            if (clip_y0 < 0)
                clip_y0 = 0;
            if (clipped_x1 >= td->Width)
                clipped_x1 = td->Width - 1;
            if (y >= td->Height)
                y = td->Height - 1;

            if (x <= clipped_x1 && clip_y0 <= y) {
                if (x != shape_x0 || clip_y0 != raw_y0 ||
                    clipped_x1 != shape_x1 || y != shape_y1) {
                    switch ((unsigned char)mode) {
                    case 2:
                        if (table != 0) {
                            ret_num = this->shape_mirror_shadow_clipped(
                                td, shape_x1, clip_y0, x, clip_y0,
                                clipped_x1, y, table);
                        } else {
                            ret_num = this->shape_mirror_clipped(
                                td, shape_x1, clip_y0, x, clip_y0,
                                clipped_x1, y);
                        }
                        break;
                    case 1:
                        if (table != 0) {
                            ret_num = this->shape_mirror_color_trans_clipped(
                                td, shape_x1, clip_y0, shape_num, x,
                                clip_y0, clipped_x1, y, table);
                        } else {
                            ret_num = this->shape_mirror_clipped(
                                td, shape_x1, clip_y0, x, clip_y0,
                                clipped_x1, y);
                        }
                        break;
                    case 0:
                        ret_num = this->shape_mirror_clipped(
                            td, shape_x1, clip_y0, x, clip_y0,
                            clipped_x1, y);
                        break;
                    default:
                        break;
                    }
                    return ret_num;
                }

                switch ((unsigned char)mode) {
                case 2:
                    if (table == 0) {
                        ret_num = this->shape_mirror_unclipped(
                            td, shape_x1, clip_y0);
                    } else {
                        ret_num = this->shape_mirror_shadow_unclipped(
                            td, shape_x1, clip_y0, table);
                    }
                    break;
                case 1:
                    if (table == 0) {
                        ret_num = this->shape_mirror_unclipped(
                            td, shape_x1, clip_y0);
                    } else {
                        ret_num = this->shape_mirror_color_trans_unclipped(
                            td, shape_x1, clip_y0, shape_num, table);
                    }
                    break;
                case 0:
                    ret_num = this->shape_mirror_unclipped(
                        td, shape_x1, clip_y0);
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

byte TShape::shape_mirror_unclipped(TDrawArea* da, long x, long y)
{
    long pitch = da->AlignedWidth() * da->Orien;
    Shape_Header* sh = this->shape_header;
    long height = sh->ymax - sh->ymin + 1;
    byte* p = (byte*)(sh + 1);
    long rows;
    byte* d;
    byte c;

    if (da->Orien < 1)
        d = da->Bits + ((y - da->Height) + 1) * pitch + x + 1;
    else
        d = da->Bits + y * pitch + x + 1;

    x = (long)d;

    if (height > 0) {
        rows = height;
        do {
            byte done = 0;
            do {
                byte b = *p++;
                if ((b & 1) == 1) {
                    c = b >> 1;
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
                    c = b >> 1;
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
            x += pitch;
            d = (byte*)x;
        } while (--rows);
    }

    return 1;
}

byte TShape::shape_mirror_color_trans_unclipped(TDrawArea* draw_area, long x,
                                                long y, long shape_idx,
                                                byte* table)
{
    long pitch = draw_area->AlignedWidth() * draw_area->Orien;
    Shape_Header* sh = this->shape_header;
    long height = sh->ymax - sh->ymin + 1;
    byte* p = (byte*)(sh + 1);
    long m;
    long rows;
    byte* d;
    byte c;

    if (draw_area->Orien < 1)
        d = draw_area->Bits +
            (y - draw_area->Height + 1) * pitch + x + 1;
    else
        d = draw_area->Bits + y * pitch + x + 1;

    x = (long)d;

    if (height > 0) {
        rows = height;
        do {
            byte done = 0;
            do {
                byte b = *p++;
                if ((b & 1) == 1) {
                    c = b >> 1;
                    if (c == 0) {
                        d -= *p;
                        p++;
                    } else {
                        while (c > 0) {
                            *--d = table[*p++];
                            c--;
                        }
                    }
                } else {
                    c = b >> 1;
                    if (c == 0) {
                        done = 1;
                    } else {
                        byte t = table[*p];
                        d -= c;
                        memset(d, t, c);
                        p++;
                    }
                }
            } while (!done);
            x += pitch;
            d = (byte*)x;
        } while (--rows);
    }

    return 1;
}

byte TShape::shape_mirror_shadow_unclipped(TDrawArea* draw_area, long x,
                                           long y, byte* table)
{
    long pitch = draw_area->AlignedWidth() * draw_area->Orien;

    Shape_Header* hdr = this->shape_header;
    long height = hdr->ymax - hdr->ymin + 1;
    byte* src = (byte*)(hdr + 1);
    long rows;
    byte* d;
    byte c;

    if (draw_area->Orien < 1)
        d = draw_area->Bits +
            ((y - draw_area->Height) + 1) * pitch + x + 1;
    else
        d = draw_area->Bits + y * pitch + x + 1;

    x = (long)d;

    if (height > 0) {
        rows = height;
        do {
            byte done = 0;
            do {
                byte b = *src++;
                if ((b & 1) == 1) {
                    c = b >> 1;
                    if (c == 0) {
                        d -= *src++;
                    } else {
                        if (c > 0) {
                            unsigned int count = c;
                            do {
                                --d;
                                *d = table[*d];
                            } while (--count);
                        }
                        src += c;
                    }
                } else {
                    c = b >> 1;
                    if (c == 0) {
                        done = 1;
                    } else {
                        if (c > 0) {
                            unsigned int count = c;
                            do {
                                --d;
                                *d = table[*d];
                            } while (--count);
                        }
                        src++;
                    }
                }
            } while (!done);
            x += pitch;
            d = (byte*)x;
        } while (--rows);
    }
    return 1;
}

byte TShape::shape_mirror_clipped(TDrawArea* area, long clip_right,
                                  long clip_top, long clip_left, long y,
                                  long x, long clip_bottom)
{
    long width = area->AlignedWidth() * area->Orien;
    byte* src = (byte*)(this->shape_header + 1);
    byte* dst;
    byte count;
    if (area->Orien < 1)
        dst = area->Bits +
                      (y - area->Height + 1) * width + x + 1;
    else
        dst = area->Bits + y * width + x + 1;
    byte* save_buffer = dst;

    long row = clip_top;
    if (clip_top < y) {
        long skip = y - clip_top;
        row += skip;
        do {
            byte done = 0;
            do {
                byte code = *src++;
                if ((code & 1) == 1) {
                    count = code >> 1;
                    if (count)
                        src += count;
                    else
                        ++src;
                } else {
                    count = code >> 1;
                    if (count == 0)
                        done = 1;
                    else
                        ++src;
                }
            } while (!done);
        } while (--skip != 0);
    }

    if (row <= clip_bottom) {
        long rows = clip_bottom - row + 1;
        do {
            long xpos = clip_right;
            char state;

            if (xpos > x) {
                state = 0;
                while (state == 0) {
                    byte code = *src++;
                    if ((code & 1) == 1) {
                        count = code >> 1;
                        if (count == 0) {
                            xpos -= *src++;
                            if (xpos <= x) {
                                if (xpos < clip_left)
                                    state = 2;
                                else {
                                    state = 1;
                                    dst += xpos - x;
                                }
                            }
                        } else {
                            xpos -= count;
                            if (xpos <= x) {
                                if (xpos < clip_left) {
                                    unsigned int copy_count = x - clip_left + 1;
                                    state = 2;
                                    src += xpos - x + count - 1;
                                    if ((unsigned char)copy_count > 0) {
                                        copy_count &= 0xff;
                                        while (copy_count != 0) {
                                            *--dst = *src++;
                                            --copy_count;
                                        }
                                    }
                                    src += clip_left - xpos;
                                } else {
                                    state = 1;
                                    unsigned int copy_count = x;
                                    copy_count -= xpos;
                                    src += count - copy_count;
                                    if ((unsigned char)copy_count > 0) {
                                        copy_count &= 0xff;
                                        while (copy_count != 0) {
                                            *--dst = *src++;
                                            --copy_count;
                                        }
                                    }
                                }
                            } else {
                                src += count;
                            }
                        }
                    } else {
                        count = code >> 1;
                        if (count == 0) {
                            state = 3;
                        } else {
                            xpos -= count;
                            if (xpos <= x) {
                                if (xpos < clip_left) {
                                    long visible = x - clip_left + 1;
                                    state = 2;
                                    dst -= visible;
                                    memset(dst, *src, visible);
                                } else {
                                    long visible = x - xpos;
                                    state = 1;
                                    dst -= visible;
                                    memset(dst, *src, visible);
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
                        byte skip_count = *src++;
                        xpos -= skip_count;
                        dst -= skip_count;
                        if (xpos < clip_left)
                            state = command & 1;
                    } else {
                        xpos -= count;
                        if (xpos < clip_left) {
                            unsigned int visible = xpos;
                            visible -= clip_left;
                            visible += count;
                            state = 1;
                            if ((unsigned char)visible > 0) {
                                visible &= 0xff;
                                while (visible != 0) {
                                    *--dst = *src++;
                                    --visible;
                                }
                            }
                            src += count - (xpos - clip_left + count);
                        } else {
                            unsigned int copy_count = count;
                            if (command != 0) {
                                while (copy_count != 0) {
                                    *--dst = *src++;
                                    --copy_count;
                                }
                            }
                        }
                    }
                } else {
                    count = command >> 1;
                    if (count == 0) {
                        state = 3;
                    } else {
                        xpos -= count;
                        if (xpos < clip_left) {
                            long visible = xpos - clip_left + count;
                            state = 1;
                            dst -= visible;
                            memset(dst, *src, visible);
                        } else {
                            dst -= count;
                            memset(dst, *src, count);
                        }
                        ++src;
                    }
                }
            }

            --state;
            while (state == 0) {
                byte code = *src++;
                if ((code & 1) == 1) {
                    count = code >> 1;
                    if (count)
                        src += count;
                    else
                        ++src;
                } else {
                    count = code >> 1;
                    if (count == 0)
                        state = 2;
                    else
                        ++src;
                }
            }

            save_buffer += width;
            dst = save_buffer;
        } while (--rows);
    }
    return 1;
}

byte TShape::shape_mirror_color_trans_clipped(
    TDrawArea* draw_area, long shape_x1, long shape_y1, long shape_idx,
    long clip_x0, long clip_y0, long clip_x1, long clip_y1, byte* table)
{
    long pitch = draw_area->AlignedWidth() * draw_area->Orien;
    Shape_Header* header = this->shape_header;
    byte* src = (byte*)(header + 1);
    long xpos;
    byte* dst;
    byte* save_buffer;
    byte state;
    byte command;
    byte done;
    long rows;

    if (draw_area->Orien < 1)
        dst = draw_area->Bits +
              (clip_y0 - draw_area->Height + 1) * pitch + clip_x1 + 1;
    else
        dst = draw_area->Bits + clip_y0 * pitch + clip_x1 + 1;

    save_buffer = dst;

    if (shape_y1 < clip_y0) {
        long skip = clip_y0 - shape_y1;
        shape_y1 += skip;
        do {
            done = 0;
            do {
                command = *src++;
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
        } while (--skip != 0);
    }

    if (shape_y1 > clip_y1)
        return 1;
    rows = clip_y1 - shape_y1 + 1;

    do {
        xpos = shape_x1;

        if (xpos <= clip_x1) {
            state = 1;
        } else {
            state = 0;
            do {
                command = *src++;
                if ((command & 1) == 1) {
                    clip_y0 = command >> 1;
                    if (clip_y0 == 0) {
                        clip_y0 = *src++;
                        xpos -= clip_y0;
                        if (xpos <= clip_x1) {
                            if (xpos < clip_x0)
                                state = 2;
                            else {
                                dst += xpos - clip_x1;
                                state = 1;
                            }
                        }
                    } else {
                        xpos -= clip_y0;
                        if (xpos <= clip_x1) {
                            if (xpos < clip_x0) {
                                unsigned int cnt =
                                    (unsigned char)(clip_x1 - clip_x0 + 1);
                                state = 2;
                                src += xpos - clip_x1 + clip_y0 - 1;
                                while (cnt-- != 0) {
                                    --dst;
                                    *dst = table[*src++];
                                }
                                src += clip_x0 - xpos;
                            } else {
                                unsigned int cnt =
                                    (unsigned char)(clip_x1 - xpos);
                                state = 1;
                                src += clip_y0 - cnt;
                                while (cnt-- != 0) {
                                    --dst;
                                    *dst = table[*src++];
                                }
                            }
                        } else {
                            src += clip_y0;
                        }
                    }
                } else {
                    clip_y0 = command >> 1;
                    if (clip_y0 == 0)
                        state = 3;
                    else {
                        xpos -= clip_y0;
                        if (xpos <= clip_x1) {
                            if (xpos < clip_x0) {
                                unsigned int cnt =
                                    (unsigned char)(clip_x1 - clip_x0 + 1);
                                state = 2;
                                dst -= cnt;
                                memset(dst, table[*src], cnt);
                            } else {
                                unsigned int cnt =
                                    (unsigned char)(clip_x1 - xpos);
                                state = 1;
                                dst -= cnt;
                                memset(dst, table[*src], cnt);
                            }
                        }
                        ++src;
                    }
                }
            } while (!state);
        }

        state--;
        if (state == 0) {
            do {
                command = *src++;
                if (command & 1) {
                    clip_y0 = command >> 1;
                    if (clip_y0 == 0) {
                        clip_y0 = *src++;
                        xpos -= clip_y0;
                        dst -= clip_y0;
                        if (xpos < clip_x0)
                            state = 1;
                    } else {
                        xpos -= clip_y0;
                        if (xpos < clip_x0) {
                            shape_y1 =
                                (unsigned char)(xpos - clip_x0 + clip_y0);
                            state = 1;
                            while ((unsigned char)shape_y1 > 0) {
                                --dst;
                                *dst = table[*src++];
                                --shape_y1;
                            }
                            src += clip_y0 -
                                   (xpos - clip_x0 + clip_y0);
                        } else {
                            while (clip_y0-- != 0) {
                                --dst;
                                *dst = table[*src++];
                            }
                        }
                    }
                } else {
                    clip_y0 = command >> 1;
                    if (clip_y0 == 0)
                        state = 3;
                    else {
                        xpos -= clip_y0;
                        if (xpos < clip_x0) {
                            unsigned int cnt =
                                (unsigned char)(xpos - clip_x0 + clip_y0);
                            state = 1;
                            dst -= cnt;
                            memset(dst, table[*src], cnt);
                        } else {
                            dst -= clip_y0;
                            memset(dst, table[*src], clip_y0);
                        }
                        ++src;
                    }
                }
            } while (!state);
        }

        state--;
        if (state == 0) {
            do {
                command = *src++;
                if (command & 1) {
                    clip_y0 = command >> 1;
                    if (clip_y0 != 0)
                        src += clip_y0;
                    else
                        ++src;
                } else {
                    if ((command & 0xfe) == 0)
                        state = 2;
                    else
                        ++src;
                }
            } while (!state);
        }

        save_buffer += pitch;
        dst = save_buffer;
        --rows;
    } while (rows != 0);

    return 1;
}

byte TShape::shape_mirror_shadow_clipped(
    TDrawArea* draw_area, long shape_x1, long shape_y1, long clip_x0,
    long clip_y0, long clip_x1, long clip_y1, byte* table)
{
    byte command;
    byte count;
    char state;
    long width;
    Shape_Header* header;
    byte* src;
    byte* save_buffer;
    byte* buffer;
    long xpos;
    unsigned int transform_count;

    width = draw_area->AlignedWidth();
    width *= draw_area->Orien;
    header = this->shape_header;
    src = (byte*)(header + 1);

    if (draw_area->Orien < 1)
        save_buffer = draw_area->Bits +
                      (clip_y0 - draw_area->Height + 1) * width + clip_x1 + 1;
    else
        save_buffer = draw_area->Bits + clip_y0 * width + clip_x1 + 1;

    if (shape_y1 < clip_y0) {
        byte skip_count;
        long skip = clip_y0 - shape_y1;
        shape_y1 += skip;
        do {
            byte done = 0;
            do {
                command = *src++;
                if ((command & 1) == 1) {
                    skip_count = command >> 1;
                    if (skip_count == 0)
                        ++src;
                    else
                        src += skip_count;
                } else {
                    if ((command & 0xfe) == 0)
                        done = 1;
                    else
                        ++src;
                }
            } while (!done);
        } while (--skip != 0);
    }

    if (shape_y1 > clip_y1)
        return 1;

    shape_y1 = clip_y1 - shape_y1 + 1;
    buffer = save_buffer;
    do {
        xpos = shape_x1;
        if (clip_x1 < xpos) {
            state = 0;
            do {
                command = *src++;
                if ((command & 1) == 1) {
                    count = command >> 1;
                    if (count == 0) {
                        count = *src++;
                        xpos -= count;
                        if (xpos <= clip_x1) {
                            if (xpos < clip_x0)
                                state = 2;
                            else {
                                buffer += xpos - clip_x1;
                                state = 1;
                            }
                        }
                    } else {
                        xpos -= count;
                        src += count;
                        if (xpos <= clip_x1) {
                            if (xpos < clip_x0) {
                                state = 2;
                                transform_count = clip_x1 - clip_x0 + 1;
                                if ((unsigned char)transform_count != 0) {
                                    transform_count &= 0xff;
                                    do {
                                        --buffer;
                                        *buffer = table[*buffer];
                                    } while (--transform_count);
                                }
                            } else {
                                state = 1;
                                transform_count = clip_x1 - xpos;
                                if ((unsigned char)transform_count != 0) {
                                    transform_count &= 0xff;
                                    do {
                                        --buffer;
                                        *buffer = table[*buffer];
                                    } while (--transform_count);
                                }
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
                            if ((unsigned char)transform_count != 0) {
                                transform_count &= 0xff;
                                do {
                                    --buffer;
                                    *buffer = table[*buffer];
                                } while (--transform_count);
                            }
                        }
                        ++src;
                    }
                }
            } while (state == 0);
        } else {
            state = 1;
        }

        state--;
        if (state == 0) {
            do {
            command = *src++;
            if ((command & 1) == 1) {
                count = command >> 1;
                if (count == 0) {
                    count = *src++;
                    xpos -= count;
                    buffer -= count;
                    if (xpos < clip_x0)
                        state = 1;
                } else {
                    xpos -= count;
                    src += count;
                    if (xpos < clip_x0) {
                        state = 1;
                        transform_count = xpos - clip_x0 + count;
                        if ((unsigned char)transform_count != 0) {
                            transform_count &= 0xff;
                            do {
                                --buffer;
                                *buffer = table[*buffer];
                            } while (--transform_count);
                        }
                    } else {
                        transform_count = count;
                        if ((unsigned char)transform_count != 0) {
                            transform_count &= 0xff;
                            do {
                                --buffer;
                                *buffer = table[*buffer];
                            } while (--transform_count);
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
                    if ((unsigned char)transform_count != 0) {
                        transform_count &= 0xff;
                        do {
                            --buffer;
                            *buffer = table[*buffer];
                        } while (--transform_count);
                    }
                    ++src;
                }
            }
            } while (state == 0);
        }

        state--;
        if (state == 0) {
            do {
            command = *src++;
            if ((command & 1) == 1) {
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
        buffer = save_buffer;
    } while (--shape_y1 != 0);

    return 1;
}

byte TShape::shape_dither(TDrawArea* area, long x, long y, long shape_num,
                          long dither_x, long dither_y)
{
    long clip_y1;
    tagRECT rect;

    rect = area->ClipRect;
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
    if (area->Width <= clip_x1)
        clip_x1 = area->Width - 1;
    if (area->Height <= clip_y1)
        clip_y1 = area->Height - 1;

    if (clip_x0 <= clip_x1 && clip_y0 <= clip_y1) {
        if (clip_x0 == shape_x0 && clip_y0 == shape_y0 &&
            clip_x1 == shape_x1 && clip_y1 == shape_y1) {
            return this->shape_dithered_unclipped(
                area, shape_x0, shape_y0, dither_x, dither_y);
        }

        return this->shape_dithered_clipped(
            area, shape_x0, shape_y0, clip_x0, clip_y0, clip_x1, clip_y1,
            dither_x, dither_y);
    }

    return 0;
}

byte TShape::shape_dithered_unclipped(TDrawArea* area, long x, long y,
                                      long p8, long p9)
{
    long orientation = area->Orien;
    long width = area->AlignedWidth() * orientation;
    Shape_Header* header = this->shape_header;
    long height = header->ymax - header->ymin + 1;
    byte* src = (byte*)(header + 1);
    long row_offset;

    if (orientation < 1)
        row_offset = (y - area->Height + 1) * width;
    else
        row_offset = y * width;

    byte* save_buffer = area->Bits + x + row_offset;
    byte dither = (byte)((p8 + x) & 1);
    if (((p9 + y) & 1U) != 0)
        dither = (byte)(dither != 1);

    if (height > 0) {
        long rows = height;
        do {
            byte row_dither = (byte)(dither != 1);
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
                            dither = (byte)(dither != 1);
                    } else {
                        byte count = source_count;
                        if (dither != 0) {
                            --count;
                            ++dst;
                        }
                        dither = (byte)(count & 1);
                        byte* end = dst + count;
                        while (dst < end) {
                            *dst = 0;
                            dst += 2;
                        }
                        if (dither != 0)
                            --dst;
                        src += source_count;
                    }
                } else {
                    byte source_count = command >> 1;
                    if (source_count == 0) {
                        done = 1;
                    } else {
                        byte count = source_count;
                        if (dither != 0) {
                            --count;
                            ++dst;
                        }
                        dither = (byte)(count & 1);
                        byte* end = dst + count;
                        while (dst < end) {
                            *dst = 0;
                            dst += 2;
                        }
                        if (dither != 0)
                            --dst;
                        ++src;
                    }
                }
            } while (done == 0);

            save_buffer += width;
            dither = row_dither;
        } while (--rows != 0);
    }

    return 1;
}

byte TShape::shape_dithered_clipped(TDrawArea* area, long x, long y,
                                     long clip_left, long clip_top,
                                     long clip_right, long clip_bottom,
                                     long p8, long p9)
{
    long orientation = area->Orien;
    long width = area->AlignedWidth();
    width *= orientation;
    Shape_Header* header = this->shape_header;
    byte* src = (byte*)(header + 1);
    long skip_rows;
    long row;
    long xpos;
    long row_offset;
    byte* save_buffer;
    if (orientation < 1)
        row_offset = (clip_top - area->Height + 1) * width;
    else
        row_offset = width * clip_top;
    save_buffer = area->Bits + clip_left + row_offset;
    byte dither;
    byte state;
    byte done;
    byte b;
    byte* end;
    dither = (byte)(((char)p8 + (char)clip_left) & 1);
    if (((p9 + clip_top) & 1U) != 0)
        dither = (byte)(dither != 1);

    row = y;
    if (y < clip_top) {
        skip_rows = clip_top - y;
        row = y + skip_rows;
        do {
            done = 0;
            do {
                y = (long)*src++;
                if ((y & 1) == 1) {
                    y >>= 1;
                    if (y == 0)
                        ++src;
                    else
                        src += (unsigned int)y;
                } else {
                    y >>= 1;
                    if (y == 0)
                        done = 1;
                    else
                        ++src;
                }
            } while (done == 0);
            --skip_rows;
        } while (skip_rows != 0);
    }

    do {
        if (row > clip_bottom)
            return 1;

        bool row_dither = (dither != 1);
        byte* dst = save_buffer;
        xpos = x;

        if (x < clip_left) {
            state = 0;
            do {
                y = (long)*src++;
                if ((y & 1) == 1) {
                    y >>= 1;
                    if (y == 0) {
                        xpos += (unsigned int)*src;
                        ++src;
                        if (clip_left <= xpos) {
                            if (clip_right < xpos) {
                                state = 2;
                            } else {
                                state = 1;
                                b = (byte)((char)xpos - (char)clip_left);
                                dst += b;
                                if ((b & 1) != 0)
                                    dither = (byte)(dither != 1);
                            }
                        }
                    } else {
                        xpos += y;
                        if (clip_left < xpos) {
                            if (clip_right < xpos) {
                                state = 2;
                                b = (byte)((char)clip_right -
                                           (char)clip_left + 1);
                                if (dither != 0) {
                                    ++dst;
                                    b = (byte)((char)clip_right -
                                               (char)clip_left);
                                }
                                dither = (byte)(b & 1);
                                end = dst + b;
                                while (dst < end) {
                                    *dst = 0;
                                    dst += 2;
                                }
                                if (dither != 0)
                                    --dst;
                                src += (unsigned int)y;
                                goto left_done;
                            } else {
                                state = 1;
                                b = (byte)((char)xpos - (char)clip_left);
                                if (dither != 0) {
                                    --b;
                                    ++dst;
                                }
                                dither = (byte)(b & 1);
                                end = dst + b;
                                while (dst < end) {
                                    *dst = 0;
                                    dst += 2;
                                }
                                if (dither != 0)
                                    --dst;
                            }
                        }
                        src += (unsigned int)y;
                    }
                } else {
                    y >>= 1;
                    if (y == 0) {
                        state = 3;
                    } else {
                        xpos += y;
                        if (clip_left < xpos) {
                            if (clip_right < xpos) {
                                state = 2;
                                b = (byte)((char)clip_right -
                                           (char)clip_left + 1);
                                if (dither != 0) {
                                    ++dst;
                                    b = (byte)((char)clip_right -
                                               (char)clip_left);
                                }
                                dither = (byte)(b & 1);
                                end = dst + b;
                                while (dst < end) {
                                    *dst = 0;
                                    dst += 2;
                                }
                                if (dither != 0)
                                    --dst;
                            } else {
                                state = 1;
                                b = (byte)((char)xpos - (char)clip_left);
                                if (dither != 0) {
                                    --b;
                                    ++dst;
                                }
                                dither = (byte)(b & 1);
                                end = dst + b;
                                while (dst < end) {
                                    *dst = 0;
                                    dst += 2;
                                }
                                if (dither != 0)
                                    --dst;
                            }
                        }
                        ++src;
                    }
                }
            left_done:
                if (state != 0)
                    break;
            } while (true);
        } else {
            state = 1;
        }
        --state;
        while (state == 0) {
            y = (long)*src++;
            if ((y & 1) == 1) {
                y >>= 1;
                if (y == 0) {
                    b = *src;
                    xpos += (unsigned int)b;
                    if ((b & 1) != 0)
                        dither = (byte)(dither != 1);
                    dst += b;
                    ++src;
                    if (clip_right < xpos)
                        state = 1;
                } else {
                    xpos += y;
                    if (clip_right < xpos) {
                        state = 1;
                        b = (byte)((char)clip_right - (char)xpos + 1 + y);
                        if (dither != 0) {
                            --b;
                            ++dst;
                        }
                        dither = (byte)(b & 1);
                        end = dst + b;
                        while (dst < end) {
                            *dst = 0;
                            dst += 2;
                        }
                        if (dither != 0)
                            --dst;
                    } else {
                        b = (byte)y;
                        if (dither != 0) {
                            --b;
                            ++dst;
                        }
                        dither = (byte)(b & 1);
                        end = dst + b;
                        while (dst < end) {
                            *dst = 0;
                            dst += 2;
                        }
                        if (dither != 0)
                            --dst;
                    }
                    src += (unsigned int)y;
                }
            } else {
                y >>= 1;
                if (y == 0) {
                    state = 3;
                } else {
                    xpos += y;
                    if (clip_right < xpos) {
                        state = 1;
                        b = (byte)((char)clip_right - (char)xpos + 1 + y);
                        if (dither != 0) {
                            --b;
                            ++dst;
                        }
                        dither = (byte)(b & 1);
                        end = dst + b;
                        while (dst < end) {
                            *dst = 0;
                            dst += 2;
                        }
                        if (dither != 0)
                            --dst;
                    } else {
                        b = (byte)y;
                        if (dither != 0) {
                            --b;
                            ++dst;
                        }
                        dither = (byte)(b & 1);
                        end = dst + b;
                        while (dst < end) {
                            *dst = 0;
                            dst += 2;
                        }
                        if (dither != 0)
                            --dst;
                    }
                    ++src;
                }
            }
        }

        --state;
        while (state == 0) {
            y = (long)*src++;
            if ((y & 1) == 1) {
                y >>= 1;
                if (y == 0)
                    ++src;
                else
                    src += (unsigned int)y;
            } else {
                y >>= 1;
                if (y == 0)
                    state = 2;
                else
                    ++src;
            }
        }

        save_buffer += width;
        ++row;
        dither = row_dither;
    } while (true);

    return 1;
}
