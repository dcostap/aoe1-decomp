
#include "../include/Shape.h"
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
extern "C" void __cdecl addstring(char**, const char*, const char*);
extern int shape_version_110;


extern "C" int __cdecl ASMGet_Color_Xform();
extern "C" void __cdecl ASMSet_Surface_Info(void*, void*, void*, int, int,
                                             int, int);
extern "C" void __cdecl ASMSet_Xlate_Table(void*);
extern "C" void __cdecl ASMDraw_Sprite(void*, long, long, long, long, long,
                                        long, int);

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

TShape::TShape(char* filename, long resource_file_id)
{
    this->shape = 0;
    this->shape_header = 0;
    this->head = 0;
    this->offsets = 0;
    this->FShape = 0;

    char NextFile[260];
    int fd;
    if (shape_file_first || resource_file_id < 0) {
        color_log('T', 'T', 1);

        strcpy(NextFile, filename);
        Shape_Loads++;
        fd = open(strcpy(NextFile + strlen(NextFile) - 4, ".slp"), 0x8000);
        if (fd != -1) {
            lseek(fd, 0, 2);
            int sz = tell(fd);
            this->FShape = (SLhape_File_Header*)malloc(sz);
            lseek(fd, 0, 0);
            read(fd, this->FShape, sz);
            close(fd);
            this->shape_info = (Shape_Info*)(this->FShape + 1);
            this->load_type = 1;
            this->load_size = sz;
        }

        if (this->FShape == 0) {
            fd = open(strcpy(NextFile + strlen(NextFile) - 4, ".shp"), 0x8000);
            if (fd != -1) {
                lseek(fd, 0, 2);
                int sz = tell(fd);
                this->shape = (byte*)malloc(sz);
                lseek(fd, 0, 0);
                read(fd, this->shape, sz);
                close(fd);
                this->head = (Shape_File_Header*)this->shape;
                this->offsets = (Shape_Offsets*)(this->shape +
                                                   sizeof(Shape_File_Header));
                this->load_type = 1;
                this->load_size = sz;
            }
        }

        color_log('T', '_', 1);
    }

    if (this->FShape == 0 && this->shape == 0 && resource_file_id >= 0) {
        Shape_Loads++;
        this->shape = (byte*)RESFILE_load(0x73687020, resource_file_id,
                                          this->load_type, this->load_size);
        if (this->shape != 0) {
            if (((Shape_File_Header*)this->shape)->version == shape_version_110) {
                this->head = (Shape_File_Header*)this->shape;
                this->offsets = (Shape_Offsets*)(this->shape +
                                                   sizeof(Shape_File_Header));
                return;
            }
        } else {
            this->shape = (byte*)RESFILE_load(0x736c7020, resource_file_id,
                                              this->load_type, this->load_size);
            if (this->shape != 0) {
                this->FShape = (SLhape_File_Header*)this->shape;
                this->shape = 0;
                this->shape_info = (Shape_Info*)(this->FShape + 1);
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
    byte* p;
    byte command;

    if (frame < 0)
        return 0;
    if (Check_shape(frame, "RGL_shape_draw"))
        return 0;

    byte* base = (byte*)this->FShape;
    if (base != 0) {
        Shape_Info* info;
        int px;
        int py;
        int width;
        info = &this->shape_info[frame];
        px = info->Hotspot_X + x;
        py = info->Hotspot_Y + y;
        width = info->Width;
        if (px < 0 || py < 0 || px >= width || py >= info->Height)
            return 0;
        int row_offset = py * 4;
        byte* rowtab = base + info->Shape_Outline_Offset;
        int minx = *(short*)(rowtab + row_offset);
        int span = *(short*)(rowtab + row_offset + 2);
        if (minx < 0 || px < minx || px > width - span)
            return 0;
        byte* data = base + info->Shape_Data_Offsets;
        int data_offset = *(int*)(data + row_offset);
        p = base + data_offset;
        while (minx < width) {
            if (px < minx)
                return 0;
            command = *p++;
            switch (command & 0xf) {
            case 0:
            case 4:
            case 8:
            case 12: {
                unsigned int n = ((unsigned int)command) >> 2;
                minx += n;
                if (px < minx)
                    return 1;
                p += n;
                break;
            }
            case 2: {
                unsigned int n = (((unsigned int)command) << 4) | *p++;
                minx += n;
                if (px < minx)
                    return 1;
                p += n;
                break;
            }
            case 1:
            case 5:
            case 9:
            case 13: {
                unsigned int n = ((unsigned int)command) >> 2;
                minx += n;
                break;
            }
            case 3: {
                unsigned int n = (((unsigned int)command) << 4) | *p++;
                minx += n;
                break;
            }
            case 6: {
                unsigned int n = ((unsigned int)command) >> 4;
                if (n == 0)
                    n = *p++;
                minx += n;
                if (px < minx)
                    return 1;
                p += n;
                break;
            }
            case 7:
            case 10: {
                unsigned int n = ((unsigned int)command) >> 4;
                if (n == 0)
                    n = *p++;
                minx += n;
                if (px < minx)
                    return 1;
                ++p;
                break;
            }
            case 11: {
                unsigned int n = ((unsigned int)command) >> 4;
                if (n == 0)
                    n = *p++;
                minx += n;
                if (px < minx)
                    return 1;
                break;
            }
            case 15:
                return 0;
            default:
                return 0;
            }
        }
    } else {
        Shape_Header* header =
            (Shape_Header*)(this->shape + this->offsets[frame].shape);
        this->shape_header = header;
        int minY = header->ymin;
        int minX2 = header->xmin;
        int maxX2 = header->xmax;
        p = (byte*)(header + 1);
        int maxY2 = header->ymax;
        if (y < minY || y > maxY2 || x < minX2 || x > maxX2)
            return 0;
        if (minY < y) {
            int rows = y - minY;
            do {
                byte done = 0;
                do {
                    command = *p++;
                    if ((command & 1) == 1) {
                        command >>= 1;
                        if (command == 0)
                            done = 1;
                        else
                            p += command;
                    } else {
                        command >>= 1;
                        if (command == 0)
                            done = 1;
                        else
                            ++p;
                    }
                } while (!done);
                --rows;
            } while (rows != 0);
        }
        long r = minX2;
        byte done = 0;
        do {
            command = *p++;
            if ((command & 1) == 1) {
                command >>= 1;
                if (command == 0) {
                    int n = *p;
                    r += n;
                    if (r > x)
                        return 0;
                } else {
                    r += command;
                    if (r > x)
                        return 1;
                    p += command;
                }
            } else {
                command >>= 1;
                if (command == 0) {
                    done = 1;
                } else {
                    r += command;
                    if (r > x)
                        return 1;
                }
                ++p;
            }
        } while (!done);
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

                if (x0 < rect.left)
                    x0 = rect.left;
                if (y0 < rect.top)
                    y0 = rect.top;
                if (shape_x1 > rect.right)
                    shape_x1 = rect.right;
                if (shape_y1 > rect.bottom)
                    shape_y1 = rect.bottom;
                if (x0 < 0)
                    x0 = 0;
                if (y0 < 0)
                    y0 = 0;
                if (shape_x1 >= td->Width)
                    shape_x1 = td->Width - 1;
                if (shape_y1 >= td->Height)
                    shape_y1 = td->Height - 1;

                if (x0 <= shape_x1 && y0 <= shape_y1) {
                    if (x0 == original_x0 && y0 == original_y0 &&
                        shape_x1 == original_x1 && shape_y1 == original_y1) {
                        switch ((unsigned char)mode) {
                        case 2:
                            if (table == 0) {
                                long draw_x = shape_x1;
                                long draw_y = shape_y1;
                                return this->shape_draw_unclipped(
                                    td, draw_x, draw_y, shape_num);
                            }
                            return this->shape_shadow_unclipped(
                                td, original_x0, original_y0, table);
                        case 1:
                            if (table == 0) {
                                long draw_x = x0;
                                long draw_y = y0;
                                return this->shape_draw_unclipped(
                                    td, draw_x, draw_y, shape_num);
                            }
                            return this->shape_color_trans_unclipped(
                                td, original_x0, original_y0, shape_num,
                                table);
                        case 0: {
                            long draw_x = original_x0;
                            long draw_y = original_y0;
                            return this->shape_draw_unclipped(
                                td, draw_x, draw_y, shape_num);
                        }
                        default:
                            return ret_num;
                        }
                    }

                    switch ((unsigned char)mode) {
                    case 2:
                        if (table != 0)
                            return this->shape_shadow_clipped(
                                td, original_x0, original_y0, x0, y0,
                                shape_x1, shape_y1, table);
                        break;
                    case 1:
                        if (table != 0)
                            return this->shape_color_trans_clipped(
                                td, original_x0, original_y0, shape_num,
                                x0, y0, shape_x1, shape_y1, table);
                        break;
                    case 0:
                        break;
                    default:
                        return ret_num;
                    }
                    return this->shape_draw_clipped(
                        td, original_x0, original_y0, x0, y0,
                        shape_x1, shape_y1);
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

byte TShape::shape_color_trans_unclipped(TDrawArea* td, long p2, long p3,
                                         long p4, byte* pal)
{
    Shape_Header* hdr = this->shape_header;
    long width = (hdr->ymax - hdr->ymin) + 1;

    int Orien = td->Orien;
    long stride = td->AlignedWidth() * Orien;
    Shape_Payload* src = (Shape_Payload*)(hdr + 1);
    byte count;
    byte* row;
    long dest_off;
    if (Orien < 1) {
        dest_off = (p3 - td->Height + 1) * stride;
    } else {
        dest_off = p3 * stride;
    }
    row = td->Bits + p2 + dest_off;

    if (width > 0) {
        do {
            byte done = 0;
            byte* dst = row;
            do {
                byte b = src++->value;
                if ((b & 1) == 1) {
                    count = b >> 1;
                    if (count == 0) {
                        dst += src->value;
                        src++;
                    } else {
                        byte* end = dst + count;
                        while (dst < end) {
                            *dst = pal[src->value];
                            src++;
                            dst++;
                        }
                    }
                } else {
                    count = b >> 1;
                    if (count == 0) {
                        done = 1;
                    } else {
                        memset(dst, pal[src->value], count);
                        src++;
                        dst += count;
                    }
                }
            } while (!done);

            row += stride;
        } while (--width);
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

byte TShape::shape_draw_clipped(TDrawArea* area, long shape_x, long shape_y,
                                long clip_left, long clip_top,
                                long clip_right, long clip_bottom)
{
    long pitch = area->AlignedWidth() * area->Orien;
    byte* src = (byte*)(this->shape_header + 1);
    byte* save_buffer;
    byte count;

    if (area->Orien < 1)
        save_buffer = area->Bits + (clip_top - area->Height + 1) * pitch;
    else
        save_buffer = area->Bits + clip_top * pitch;
    save_buffer += clip_left;

    if (shape_y < clip_top) {
        clip_top = clip_top - shape_y;
        shape_y = shape_y + clip_top;
        do {
            byte done = 0;
            do {
                byte code = *src++;
                if (code & 1) {
                    count = code >> 1;
                    if (count == 0)
                        ++src;
                    else
                        src += count;
                } else {
                    if ((code & 0xfe) == 0)
                        done = 1;
                    else
                        ++src;
                }
            } while (!done);
            --clip_top;
        } while (clip_top != 0);
    }

    if (shape_y <= clip_bottom) {
        clip_bottom = clip_bottom - shape_y + 1;
        do {
            long xpos = shape_x;
            byte* dst = save_buffer;

            if (shape_x < clip_left) {
                clip_top = 0;
                do {
                    byte code = *src++;
                    if (code & 1) {
                        count = code >> 1;
                        if (count == 0) {
                            xpos += *src++;
                            if (xpos >= clip_left) {
                                if (xpos > clip_right)
                                    clip_top = 2;
                                else {
                                    clip_top = 1;
                                    dst += xpos - clip_left;
                                }
                            }
                        } else {
                            xpos += count;
                            if (xpos >= clip_left) {
                                long copy_count;
                                byte* copy_source;
                                if (xpos > clip_right) {
                                    clip_top = 2;
                                    copy_count = clip_right - clip_left + 1;
                                    copy_source = src + count + clip_left - xpos;
                                } else {
                                    clip_top = 1;
                                    copy_count = xpos - clip_left;
                                    copy_source = src + count - copy_count;
                                }
                                memcpy(dst, copy_source, copy_count);
                                dst += copy_count;
                            }
                            src += count;
                        }
                    } else {
                        count = code >> 1;
                        if (count == 0) {
                            clip_top = 3;
                        } else {
                            xpos += count;
                            if (xpos >= clip_left) {
                                long fill_count;
                                if (xpos > clip_right) {
                                    clip_top = 2;
                                    fill_count = clip_right - clip_left + 1;
                                } else {
                                    clip_top = 1;
                                    fill_count = xpos - clip_left;
                                }
                                memset(dst, *src, fill_count);
                                dst += fill_count;
                            }
                            ++src;
                        }
                    }
                } while ((byte)clip_top == 0);
            } else {
                clip_top = 1;
            }

            clip_top = (byte)clip_top - 1;
            while ((byte)clip_top == 0) {
                byte code = *src++;
                if (code & 1) {
                    count = code >> 1;
                    if (count == 0) {
                        count = *src++;
                        xpos += count;
                        dst += count;
                        if (xpos > clip_right)
                            clip_top = 1;
                    } else {
                        xpos += count;
                        if (xpos > clip_right) {
                            clip_top = 1;
                            memcpy(dst, src,
                                   clip_right - xpos + 1 + count);
                            dst += count;
                            src += count;
                        } else {
                            memcpy(dst, src, count);
                            dst += count;
                            src += count;
                        }
                    }
                } else {
                    count = code >> 1;
                    if (count == 0) {
                        clip_top = 3;
                    } else {
                        long fill_count = count;
                        xpos += count;
                        if (xpos > clip_right) {
                            fill_count = count + clip_right - xpos + 1;
                            clip_top = 1;
                        }
                        memset(dst, *src, fill_count);
                        dst += count;
                        ++src;
                    }
                }
            }

            clip_top = (byte)clip_top - 1;
            while ((byte)clip_top == 0) {
                byte code = *src++;
                if (code & 1) {
                    count = code >> 1;
                    if (count)
                        src += count;
                    else
                        ++src;
                } else {
                    if ((code & 0xfe) == 0)
                        clip_top = 2;
                    else
                        ++src;
                }
            }

            save_buffer += pitch;
            --clip_bottom;
        } while (clip_bottom != 0);
    }

    return 1;
}

byte TShape::shape_color_trans_clipped(TDrawArea* draw_area, long shape_x1,
                                       long shape_y1, long shape_idx,
                                       long clip_x0, long clip_y0,
                                       long clip_x1, long clip_y1,
                                       byte* table)
{
    long pitch = draw_area->AlignedWidth() * draw_area->Orien;
    byte* src = (byte*)(this->shape_header + 1);
    byte* dst;
    if (draw_area->Orien < 1)
        dst = draw_area->Bits +
              (clip_y0 - draw_area->Height + 1) * pitch + clip_x0;
    else
        dst = draw_area->Bits + clip_y0 * pitch + clip_x0;

    if (shape_y1 < clip_y0) {
        long skip = clip_y0 - shape_y1;
        shape_y1 += skip;
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
                byte command = *src++;
                if (command & 1) {
                    command >>= 1;
                    if (command == 0) {
                        command = *src++;
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
                                unsigned int cnt = clip_x1 - clip_x0 + 1;
                                state = 2;
                                src += clip_x0 - xpos + command;
                                byte* end = dst + cnt;
                                while (dst < end)
                                    *dst++ = table[*src++];
                                src += command -
                                       (clip_x0 - xpos + command) - cnt;
                            } else {
                                unsigned int cnt = xpos - clip_x0;
                                state = 1;
                                src += command - cnt;
                                byte* end = dst + cnt;
                                while (dst < end)
                                    *dst++ = table[*src++];
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
                                unsigned int cnt = clip_x1 - clip_x0 + 1;
                                state = 2;
                                memset(dst, table[*src], cnt);
                                dst += cnt;
                            } else {
                                unsigned int cnt = xpos - clip_x0;
                                state = 1;
                                memset(dst, table[*src], cnt);
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
                            unsigned int cnt = command + clip_x1 - xpos + 1;
                            state = 1;
                            byte* end = dst + cnt;
                            while (dst < end)
                                *dst++ = table[*src++];
                            dst += command - cnt;
                            src += command - cnt;
                        } else {
                            byte* end = dst + command;
                            while (dst < end)
                                *dst++ = table[*src++];
                        }
                    }
                } else {
                    command >>= 1;
                    if (command == 0) {
                        state = 3;
                    } else {
                        xpos += command;
                        if (xpos > clip_x1) {
                            unsigned int cnt = command + clip_x1 - xpos + 1;
                            state = 1;
                            memset(dst, table[*src], cnt);
                            dst += command;
                        } else {
                            memset(dst, table[*src], command);
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
                byte command = *src++;
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
        dst += pitch;
    } while (--rows != 0);
    return 1;
}

byte TShape::shape_shadow_clipped(TDrawArea* draw_area, long shape_x1,
                                   long shape_y1, long clip_x0, long clip_y0,
                                   long clip_x1, long clip_y1, byte* table)
{
    byte cmd;
    byte count;
    byte state;
    long pitch = draw_area->AlignedWidth() * draw_area->Orien;
    byte* p = (byte*)(this->shape_header + 1);
    byte* shadow_table = table;

    byte* dst;
    if (draw_area->Orien < 1) {
        dst = draw_area->Bits +
              (clip_y0 - draw_area->Height + 1) * pitch + clip_x0;
    } else {
        dst = draw_area->Bits + clip_y0 * pitch + clip_x0;
    }

    long y = shape_y1;

    if (y < clip_y0) {
        long skip_rows = clip_y0 - y;
        y += skip_rows;
        do {
            byte done = 0;
            do {
                cmd = *p++;
                if ((cmd & 1) == 1) {
                    count = (byte)(cmd >> 1);
                    if (count)
                        p += count;
                    else
                        ++p;
                } else {
                    if ((cmd & 0xfe) != 0)
                        ++p;
                    else
                        done = 1;
                }
            } while (!done);
        } while (--skip_rows != 0);
    }

    if (y <= clip_y1) {
        long rows = clip_y1 - y + 1;
        do {
            byte* cur = dst;
            long sx = shape_x1;
            if (shape_x1 < clip_x0) {
                state = 0;
                do {
                    cmd = *p++;
                    count = (byte)(cmd >> 1);
                    if ((cmd & 1) == 1) {
                        if (count == 0) {
                            count = *p++;
                            sx += count;
                            if (sx >= clip_x0) {
                                if (sx > clip_x1)
                                    state = 2;
                                else {
                                    state = 1;
                                    cur += sx - clip_x0;
                                }
                            }
                        } else {
                            sx += count;
                            if (sx >= clip_x0) {
                                if (sx > clip_x1) {
                                    state = 2;
                                    unsigned int n = clip_x1 - clip_x0 + 1;
                                    if (n > 0) {
                                        do {
                                            *cur = shadow_table[*cur];
                                            ++cur;
                                        } while (--n != 0);
                                    }
                                } else {
                                    state = 1;
                                    unsigned int n = sx - clip_x0;
                                    if (n > 0) {
                                        do {
                                            *cur = shadow_table[*cur];
                                            ++cur;
                                        } while (--n != 0);
                                    }
                                }
                            }
                            p += count;
                        }
                    } else {
                        if (count == 0)
                            state = 3;
                        else {
                            sx += count;
                            if (sx >= clip_x0) {
                                if (sx > clip_x1) {
                                    state = 2;
                                    count = (byte)(clip_x1 - clip_x0 + 1);
                                } else {
                                    state = 1;
                                    count = (byte)(sx - clip_x0);
                                }
                                unsigned int n = count;
                                if (n > 0) {
                                    do {
                                        *cur = shadow_table[*cur];
                                        ++cur;
                                    } while (--n != 0);
                                }
                            }
                            ++p;
                        }
                    }
                } while (state == 0);
            } else {
                state = 1;
            }

            --state;
            while (state == 0) {
                cmd = *p++;
                count = (byte)(cmd >> 1);
                if ((cmd & 1) == 1) {
                    if (count == 0) {
                        byte n = *p++;
                        sx += n;
                        cur += n;
                        if (sx > clip_x1)
                            state = 1;
                    } else {
                        sx += count;
                        unsigned int n;
                        if (sx > clip_x1) {
                            state = 1;
                            n = count + clip_x1 - sx + 1;
                        } else {
                            n = count;
                        }
                        if (n > 0) {
                            do {
                                *cur = shadow_table[*cur];
                                ++cur;
                            } while (--n != 0);
                        }
                        p += count;
                    }
                } else {
                    if (count == 0)
                        state = 3;
                    else {
                        sx += count;
                        unsigned int n;
                        if (sx > clip_x1) {
                            n = count + clip_x1 - sx + 1;
                            state = 1;
                        } else {
                            n = count;
                        }
                        if (n > 0) {
                            do {
                                *cur = shadow_table[*cur];
                                ++cur;
                            } while (--n != 0);
                        }
                        ++p;
                    }
                }
            }

            --state;
            while (state == 0) {
                cmd = *p++;
                if ((cmd & 1) == 1) {
                    count = (byte)(cmd >> 1);
                    if (count != 0)
                        p += count;
                    else
                        ++p;
                } else {
                    if ((cmd & 0xfe) == 0)
                        state = 2;
                    else
                        ++p;
                }
            }

            dst += pitch;
        } while (--rows != 0);
    }
    return 1;
}

byte TShape::shape_mirror(TDrawArea* td, long x, long y, long shape_num,
                          byte mode, byte* table)
{
    byte ret_num = 0;
    long clip_y0;
    long shape_y1;
    Rect rect;

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
            Shape_Header* header =
                (Shape_Header*)(this->shape + this->offsets[shape_num].shape);
            this->shape_header = header;

            long shape_x0 = x - header->xmax;
            long raw_y0 = y + header->ymin;
            long shape_x1 = x - header->xmin;
            clip_y0 = raw_y0;
            shape_y1 = y + header->ymax;
            long clipped_x1 = shape_x1;
            long clipped_y1 = shape_y1;

            if (shape_x0 < rect.left)
                shape_x0 = rect.left;
            if (clip_y0 < rect.top)
                clip_y0 = rect.top;
            if (clipped_x1 > rect.right)
                clipped_x1 = rect.right;
            if (clipped_y1 > rect.bottom)
                clipped_y1 = rect.bottom;
            if (shape_x0 < 0)
                shape_x0 = 0;
            if (clip_y0 < 0)
                clip_y0 = 0;
            if (clipped_x1 >= td->Width)
                clipped_x1 = td->Width - 1;
            if (clipped_y1 >= td->Height)
                clipped_y1 = td->Height - 1;

            if (shape_x0 <= clipped_x1 && clip_y0 <= clipped_y1) {
                if (shape_x0 != x - header->xmax || clip_y0 != raw_y0 ||
                    clipped_x1 != shape_x1 || clipped_y1 != shape_y1) {
                    switch ((unsigned char)mode) {
                    case 2:
                        if (table != 0) {
                            ret_num = this->shape_mirror_shadow_clipped(
                                td, shape_x1, clip_y0, shape_x0, clip_y0,
                                clipped_x1, clipped_y1, table);
                        } else {
                            ret_num = this->shape_mirror_clipped(
                                td, shape_x1, clip_y0, shape_x0, clip_y0,
                                clipped_x1, clipped_y1);
                        }
                        break;
                    case 1:
                        if (table != 0) {
                            ret_num = this->shape_mirror_color_trans_clipped(
                                td, shape_x1, clip_y0, shape_num, shape_x0,
                                clip_y0, clipped_x1, clipped_y1, table);
                        } else {
                            ret_num = this->shape_mirror_clipped(
                                td, shape_x1, clip_y0, shape_x0, clip_y0,
                                clipped_x1, clipped_y1);
                        }
                        break;
                    case 0:
                        ret_num = this->shape_mirror_clipped(
                            td, shape_x1, clip_y0, shape_x0, clip_y0,
                            clipped_x1, clipped_y1);
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
    Shape_Byte_Table* table_view = (Shape_Byte_Table*)table;
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
                                *d = table_view->table[*d];
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
                                *d = table_view->table[*d];
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
    long pitch = area->AlignedWidth() * area->Orien;
    byte* src = (byte*)(this->shape_header + 1);
    byte* save_buffer;
    if (area->Orien < 1)
        save_buffer = area->Bits +
                      (y - area->Height + 1) * pitch + x + 1;
    else
        save_buffer = area->Bits + y * pitch + x + 1;

    long row = clip_top;
    if (row < y) {
        long skip = y - row;
        row += skip;
        do {
            byte done = 0;
            while (!done) {
                byte code = *src++;
                if ((code & 1) == 1) {
                    byte count = code >> 1;
                    if (count)
                        src += count;
                    else
                        ++src;
                } else {
                    byte count = code >> 1;
                    if (count == 0)
                        done = 1;
                    else
                        ++src;
                }
            }
        } while (--skip != 0);
    }

    if (row <= clip_bottom) {
        long rows = clip_bottom - row + 1;
        do {
            long xpos = clip_right;
            byte state;

            state = 1;
            if (xpos > x) {
                state = 0;
                while (state == 0) {
                    byte code = *src++;
                    if ((code & 1) == 1) {
                        byte count = code >> 1;
                        if (count == 0) {
                            count = *src++;
                            xpos -= count;
                            if (xpos <= x) {
                                if (xpos < clip_left)
                                    state = 2;
                                else {
                                    state = 1;
                                    save_buffer += xpos - x;
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
                                        do {
                                            *--save_buffer = *src++;
                                        } while (--copy_count != 0);
                                    }
                                    src += clip_left - xpos;
                                } else {
                                    state = 1;
                                    unsigned int copy_count = x;
                                    copy_count -= xpos;
                                    src += count - copy_count;
                                    if ((unsigned char)copy_count > 0) {
                                        copy_count &= 0xff;
                                        do {
                                            *--save_buffer = *src++;
                                        } while (--copy_count != 0);
                                    }
                                }
                            } else {
                                src += count;
                            }
                        }
                    } else {
                        byte count = code >> 1;
                        if (count == 0) {
                            state = 3;
                        } else {
                            xpos -= count;
                            if (xpos <= x) {
                                if (xpos < clip_left) {
                                    long visible = x - clip_left + 1;
                                    state = 2;
                                    save_buffer -= visible;
                                    memset(save_buffer, *src, visible);
                                } else {
                                    long visible = x - xpos;
                                    state = 1;
                                    save_buffer -= visible;
                                    memset(save_buffer, *src, visible);
                                }
                            }
                            ++src;
                        }
                    }
                }
            }

            if (state != 0) {
                --state;
                if (state == 0) {
                    while (state == 0) {
                        byte code = *src++;
                        if ((code & 1) == 1) {
                            byte count = code >> 1;
                            if (count == 0) {
                                count = *src++;
                                xpos -= count;
                                save_buffer -= count;
                                if (xpos < clip_left)
                                    state = 1;
                            } else {
                                xpos -= count;
                                if (xpos < clip_left) {
                                    unsigned int visible = xpos;
                                    visible -= clip_left;
                                    visible += count;
                                    state = 1;
                                    if ((unsigned char)visible > 0) {
                                        visible &= 0xff;
                                        do {
                                            *--save_buffer = *src++;
                                        } while (--visible != 0);
                                    }
                                    src += count - (xpos - clip_left + count);
                                } else {
                                    unsigned int copy_count = x - xpos;
                                    state = 1;
                                    src += count - copy_count;
                                    if ((unsigned char)copy_count > 0) {
                                        do {
                                            *--save_buffer = *src++;
                                        } while (--copy_count != 0);
                                    }
                                }
                            }
                        } else {
                            byte count = code >> 1;
                            if (count == 0) {
                                state = 3;
                            } else {
                                xpos -= count;
                                if (xpos < clip_left) {
                                    long visible = xpos - clip_left + count;
                                    state = 1;
                                    save_buffer -= visible;
                                    memset(save_buffer, *src, visible);
                                } else {
                                    save_buffer -= count;
                                    memset(save_buffer, *src, count);
                                }
                                ++src;
                            }
                        }
                    }
                } else {
                    --state;
                    if (state == 0) {
                        while (state == 0) {
                            byte code = *src++;
                            if ((code & 1) == 1) {
                                byte count = code >> 1;
                                if (count)
                                    src += count;
                                else
                                    ++src;
                            } else {
                                byte count = code >> 1;
                                if (count == 0)
                                    state = 2;
                                else
                                    ++src;
                            }
                        }
                    }
                }
            }

            save_buffer += pitch;
        } while (--rows);
    }
    return 1;
}

byte TShape::shape_mirror_color_trans_clipped(
    TDrawArea* draw_area, long shape_x1, long shape_y1, long shape_idx,
    long clip_x0, long clip_y0, long clip_x1, long clip_y1, byte* table)
{
    long pitch = draw_area->AlignedWidth() * draw_area->Orien;
    byte* src = (byte*)(this->shape_header + 1);
    byte* dst;

    if (draw_area->Orien < 1)
        dst = draw_area->Bits +
              (clip_y0 - draw_area->Height + 1) * pitch + clip_x1 + 1;
    else
        dst = draw_area->Bits + clip_y0 * pitch + clip_x1 + 1;

    if (shape_y1 < clip_y0) {
        long skip = clip_y0 - shape_y1;
        shape_y1 += skip;
        do {
            byte done = 0;
            do {
                byte code = *src++;
                if (code & 1) {
                    code >>= 1;
                    if (code != 0)
                        src += code;
                    else
                        ++src;
                } else {
                    if ((code & 0xfe) == 0)
                        done = 1;
                    else
                        ++src;
                }
            } while (!done);
        } while (--skip != 0);
    }

    if (shape_y1 > clip_y1)
        return 1;
    clip_y1 = clip_y1 - shape_y1 + 1;

    do {
        long xpos = shape_x1;
        byte state;

        if (clip_x1 < xpos) {
            state = 0;
            do {
                byte code = *src++;
                if (code & 1) {
                    clip_y0 = code >> 1;
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
                    clip_y0 = code >> 1;
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
        } else {
            state = 1;
        }

        state--;
        if (state == 0) {
            do {
                byte code = *src++;
                if (code & 1) {
                    clip_y0 = code >> 1;
                    if (clip_y0 == 0) {
                        clip_y0 = *src++;
                        xpos -= clip_y0;
                        dst -= clip_y0;
                        if (xpos < clip_x0)
                            state = 1;
                    } else {
                        xpos -= clip_y0;
                        if (xpos < clip_x0) {
                            unsigned int cnt =
                                (unsigned char)(xpos - clip_x0 + clip_y0);
                            shape_idx = cnt;
                            state = 1;
                            while (shape_idx-- != 0) {
                                --dst;
                                *dst = table[*src++];
                            }
                            src += clip_y0 - cnt;
                        } else {
                            while (clip_y0-- != 0) {
                                --dst;
                                *dst = table[*src++];
                            }
                        }
                    }
                } else {
                    clip_y0 = code >> 1;
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
                byte code = *src++;
                if (code & 1) {
                    clip_y0 = code >> 1;
                    if (clip_y0 != 0)
                        src += clip_y0;
                    else
                        ++src;
                } else {
                    if ((code & 0xfe) == 0)
                        state = 2;
                    else
                        ++src;
                }
            } while (!state);
        }

        dst += pitch;
        --clip_y1;
    } while (clip_y1 != 0);

    return 1;
}

byte TShape::shape_mirror_shadow_clipped(
    TDrawArea* draw_area, long shape_x1, long shape_y1, long clip_x0,
    long clip_y0, long clip_x1, long clip_y1, byte* table)
{
    Byte_Table* table_view = (Byte_Table*)table;
    long pitch = draw_area->AlignedWidth() * draw_area->Orien;
    Shape_Header* header = this->shape_header;
    byte* src = (byte*)(header + 1);
    byte* save_buffer;
    byte* dst;
    char state;
    byte command;
    long xpos;
    long rows;
    unsigned int transform_count;

    if (draw_area->Orien < 1)
        save_buffer = draw_area->Bits +
                      (clip_y0 - draw_area->Height + 1) * pitch + clip_x1 + 1;
    else
        save_buffer = draw_area->Bits + clip_y0 * pitch + clip_x1 + 1;

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

    dst = save_buffer;
    rows = clip_y1 - shape_y1 + 1;
    byte count;
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
                                dst += xpos - clip_x1;
                                state = 1;
                            }
                        }
                    } else {
                        xpos -= count;
                        src += count;
                        if (xpos <= clip_x1) {
                            if (xpos < clip_x0) {
                                count = (byte)(clip_x1 - clip_x0 + 1);
                                state = 2;
                                transform_count = count;
                                if (transform_count > 0) {
                                    do {
                                        --dst;
                                        *dst = ((Byte_Table*)table)->value[*dst];
                                    } while (--transform_count);
                                }
                            } else {
                                count = (byte)(clip_x1 - xpos);
                                state = 1;
                                transform_count = count;
                                if (transform_count > 0) {
                                    do {
                                        --dst;
                                        *dst = ((Byte_Table*)table)->value[*dst];
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
                                count = (byte)(clip_x1 - clip_x0 + 1);
                                state = 2;
                            } else {
                                count = (byte)(clip_x1 - xpos);
                                state = 1;
                            }
                            transform_count = count;
                            if (transform_count > 0) {
                                do {
                                    --dst;
                                    *dst = table_view->value[*dst];
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
        while (state == 0) {
            command = *src++;
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
                    src += count;
                    if (xpos < clip_x0) {
                        count = (byte)(xpos - clip_x0 + count);
                        state = 1;
                        transform_count = count;
                        if (transform_count > 0) {
                            do {
                                --dst;
                                *dst = table_view->value[*dst];
                            } while (--transform_count);
                        }
                    } else {
                        transform_count = count;
                        if (transform_count > 0) {
                            do {
                                --dst;
                                *dst = table_view->value[*dst];
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
                        count = (byte)(xpos - clip_x0 + count);
                        state = 1;
                    }
                    transform_count = count;
                    if (transform_count > 0) {
                        do {
                            --dst;
                            *dst = table_view->value[*dst];
                        } while (--transform_count);
                    }
                    ++src;
                }
            }
        }

        state--;
        while (state == 0) {
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
        }

        save_buffer += pitch;
        dst = save_buffer;
    } while (--rows != 0);

    return 1;
}

byte TShape::shape_dither(TDrawArea* area, long x, long y, long shape_num,
                          long param_5, long param_6)
{
    tagRECT rect = area->ClipRect;

    if (Check_shape(shape_num, "RGL_shape_draw") != 0)
        return 0;

    this->shape_header =
        (Shape_Header*)(this->offsets[shape_num].shape + this->shape);

    long sx1 = x + this->shape_header->xmin;
    long sy1 = y + this->shape_header->ymin;
    long sx2 = x + this->shape_header->xmax;
    long sy2_orig = y + this->shape_header->ymax;

    x = sx1;
    shape_num = sy1;
    y = sx2;
    long sy2 = sy2_orig;
    if (sx1 < rect.left)
        x = rect.left;
    if (sy1 < rect.top)
        shape_num = rect.top;
    if (sx2 > rect.right)
        y = rect.right;
    if (sy2_orig > rect.bottom)
        sy2 = rect.bottom;
    if (x < 0)
        x = 0;
    if (shape_num < 0)
        shape_num = 0;
    if (y >= area->Width)
        y = area->Width - 1;
    if (sy2 >= area->Height)
        sy2 = area->Height - 1;

    if (x <= y && shape_num <= sy2) {
        if (x == sx1 && shape_num == sy1 && y == sx2 && sy2 == sy2_orig)
            return shape_dithered_unclipped(area, sx1, sy1, param_5, param_6);

        return shape_dithered_clipped(area, sx1, sy1, x, shape_num,
                                      y, sy2, param_5, param_6);
    }

    return 0;
}

byte TShape::shape_dithered_unclipped(TDrawArea* area, long x, long y,
                                       long param_5, long param_6)
{
    long pitch;
    long orientation;
    Shape_Header* sh;
    long height;
    byte* src;
    byte* dst;
    byte* save_buffer;
    long parity;
    long next_parity;
    long run;
    byte done;
    byte cmd;
    byte count;
    byte* end;

    orientation = area->Orien;
    pitch = area->AlignedWidth() * orientation;
    sh = this->shape_header;
    src = (byte*)(sh + 1);
    height = sh->ymax - sh->ymin + 1;

    if (orientation < 1) {
        dst = area->Bits + x + (y - area->Height + 1) * pitch;
    } else {
        dst = area->Bits + x + y * pitch;
    }

    parity = (param_5 + x) & 1;
    if (((param_6 + y) & 1) != 0)
        parity = (parity != 1);

    save_buffer = dst;
    if (height > 0) {
        do {
            next_parity = (parity != 1);
            done = 0;
            do {
                cmd = *src++;
                if ((cmd & 1) == 1) {
                    count = (byte)(cmd >> 1);
                    if (count == 0) {
                        count = *src;
                        dst += (unsigned int)count;
                        if ((count & 1) != 0)
                            parity = (parity != 1);
                        src++;
                    } else {
                        if (parity != 0) {
                            count--;
                            dst++;
                        }
                        run = (unsigned int)count;
                        end = dst + run;
                        run = ((unsigned int)count) & 1;
                        while (dst < end) {
                            *dst = 0;
                            dst += 2;
                        }
                        if (run != 0)
                            dst--;
                        src += (unsigned int)count;
                    }
                } else {
                    count = (byte)(cmd >> 1);
                    if (count == 0) {
                        done = 1;
                    } else {
                        if (parity != 0) {
                            count--;
                            dst++;
                        }
                        run = (unsigned int)count;
                        end = dst + run;
                        run = ((unsigned int)count) & 1;
                        while (dst < end) {
                            *dst = 0;
                            dst += 2;
                        }
                        if (run != 0)
                            dst--;
                        src++;
                    }
                }
            } while (!done);
            save_buffer += pitch;
            dst = save_buffer;
            parity = next_parity;
        } while (--height);
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
    long row_offset;
    byte* save_buffer;
    if (orientation < 1)
        row_offset = (clip_top - area->Height + 1) * width;
    else
        row_offset = width * clip_top;
    save_buffer = area->Bits + clip_left + row_offset;
    byte dither;
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
            byte end_line = 0;
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
                        end_line = 1;
                    else
                        ++src;
                }
            } while (end_line == 0);
            --skip_rows;
        } while (skip_rows != 0);
    }

    do {
        if (row > clip_bottom)
            return 1;

        bool row_dither = (dither != 1);
        byte* dst = save_buffer;
        p9 = x;

        if (x < clip_left) {
            clip_top = 0;
            do {
                y = (long)*src++;
                if ((y & 1) == 1) {
                    y >>= 1;
                    if (y == 0) {
                        p9 += (unsigned int)*src;
                        ++src;
                        if (clip_left <= p9) {
                            if (clip_right < p9) {
                                clip_top = 2;
                            } else {
                                clip_top = 1;
                                b = (byte)((char)p9 - (char)clip_left);
                                p8 = (long)b;
                                dst += b;
                                if ((b & 1) != 0)
                                    dither = (byte)(dither != 1);
                            }
                        }
                    } else {
                        p9 += y;
                        if (clip_left < p9) {
                            if (clip_right < p9) {
                                clip_top = 2;
                                b = (byte)((char)clip_right -
                                           (char)clip_left + 1);
                                if (dither != 0) {
                                    ++dst;
                                    b = (byte)((char)clip_right -
                                               (char)clip_left);
                                }
                                p8 = (long)b;
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
                                clip_top = 1;
                                b = (byte)((char)p9 - (char)clip_left);
                                if (dither != 0) {
                                    --b;
                                    ++dst;
                                }
                                p8 = (long)b;
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
                        clip_top = 3;
                    } else {
                        p9 += y;
                        if (clip_left < p9) {
                            if (clip_right < p9) {
                                clip_top = 2;
                                b = (byte)((char)clip_right -
                                           (char)clip_left + 1);
                                if (dither != 0) {
                                    ++dst;
                                    b = (byte)((char)clip_right -
                                               (char)clip_left);
                                }
                                p8 = (long)b;
                                dither = (byte)(b & 1);
                                end = dst + b;
                                while (dst < end) {
                                    *dst = 0;
                                    dst += 2;
                                }
                                if (dither != 0)
                                    --dst;
                            } else {
                                clip_top = 1;
                                b = (byte)((char)p9 - (char)clip_left);
                                if (dither != 0) {
                                    --b;
                                    ++dst;
                                }
                                p8 = (long)b;
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
                if (clip_top != 0)
                    break;
            } while (true);
        } else {
            clip_top = 1;
        }
        clip_top = (byte)clip_top - 1;
        while (clip_top == 0) {
            y = (long)*src++;
            if ((y & 1) == 1) {
                y >>= 1;
                if (y == 0) {
                    b = *src;
                    p9 += (unsigned int)b;
                    if ((b & 1) != 0)
                        dither = (byte)(dither != 1);
                    dst += b;
                    ++src;
                    if (clip_right < p9)
                        clip_top = 1;
                } else {
                    p9 += y;
                    if (clip_right < p9) {
                        clip_top = 1;
                        b = (byte)((char)clip_right - (char)p9 + 1 + y);
                        if (dither != 0) {
                            --b;
                            ++dst;
                        }
                        p8 = (long)b;
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
                        p8 = (long)b;
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
                    clip_top = 3;
                } else {
                    p9 += y;
                    if (clip_right < p9) {
                        clip_top = 1;
                        b = (byte)((char)clip_right - (char)p9 + 1 + y);
                        if (dither != 0) {
                            --b;
                            ++dst;
                        }
                        p8 = (long)b;
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
                        p8 = (long)b;
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

        clip_top = (byte)(clip_top - 1);
        while (clip_top == 0) {
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
                    clip_top = 2;
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
