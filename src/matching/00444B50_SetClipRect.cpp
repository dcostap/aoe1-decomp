// VA: 00444B50 TDrawArea::SetClipRect(tagRECT *)
// Attempt log:
// Clean reconstruction: the pointer overload copies/clamps a named RECT, then
// forwards the normalized coordinates to the four-long overload at 00444C30.
// Added the proven +20/+24 gap so ClipRect owns offsets +28..+34.
// Replaced aggregate assignment with four member copies; VC5 then kept the
// original single-ESI register basin and the PDB's separate copy-line shape.
// Inverted the null guard so the non-null path stays inline and the default
// rectangle is the late near-JE target; this produced an exact match.

#ifndef DRAWAREA_CANONICAL_TU
struct tagRECT {
    long left;
    long top;
    long right;
    long bottom;
};

class TDrawArea {
public:
    char gap_00[0x18];
    long Width;
    long Height;
    char gap_20[0x08];
    tagRECT ClipRect;

    void SetClipRect(tagRECT* rect);
    void SetClipRect(long left, long top, long right, long bottom);
};
#endif

void TDrawArea::SetClipRect(tagRECT* rect)
{
    if (rect != 0) {
        this->ClipRect.left = rect->left;
        this->ClipRect.top = rect->top;
        this->ClipRect.right = rect->right;
        this->ClipRect.bottom = rect->bottom;

        if (this->ClipRect.left < 0) {
            this->ClipRect.left = 0;
        }
        else if (this->ClipRect.left > this->Width - 1) {
            this->ClipRect.left = this->Width - 1;
        }

        if (this->ClipRect.right < 0) {
            this->ClipRect.right = 0;
        }
        else if (this->ClipRect.right > this->Width - 1) {
            this->ClipRect.right = this->Width - 1;
        }

        if (this->ClipRect.top < 0) {
            this->ClipRect.top = 0;
        }
        else if (this->ClipRect.top > this->Height - 1) {
            this->ClipRect.top = this->Height - 1;
        }

        if (this->ClipRect.bottom < 0) {
            this->ClipRect.bottom = 0;
        }
        else if (this->ClipRect.bottom > this->Height - 1) {
            this->ClipRect.bottom = this->Height - 1;
        }

        if (this->ClipRect.right < this->ClipRect.left) {
            long temp = this->ClipRect.right;
            this->ClipRect.right = this->ClipRect.left;
            this->ClipRect.left = temp;
        }

        if (this->ClipRect.bottom < this->ClipRect.top) {
            long temp = this->ClipRect.bottom;
            this->ClipRect.bottom = this->ClipRect.top;
            this->ClipRect.top = temp;
        }
    }
    else {
        this->ClipRect.left = 0;
        this->ClipRect.top = 0;
        this->ClipRect.right = this->Width - 1;
        this->ClipRect.bottom = this->Height - 1;
    }

    this->SetClipRect(this->ClipRect.left, this->ClipRect.top,
                      this->ClipRect.right, this->ClipRect.bottom);
}
