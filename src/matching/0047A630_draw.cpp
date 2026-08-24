// TPicturePanel::draw
// VA: 0047A630
// PDB: Pnl_pic.cpp:175-204

#include "..\..\include\game_globals.h"
#include "..\..\include\pnl_pic_context.h"

void TPicturePanel::draw()
{
    if (!this->render_area) return;
    if (!this->visible) return;
    if (!this->active) return;

    this->draw_setup(0);

    if (!this->keep_loaded)
        this->load_pic();

    void* locked = this->render_area->Lock("pnl_pic::draw", 1);
    if (locked) {
        if (this->pic_type == 0) {
            if (this->pic)
                this->pic->Draw(this->render_area, this->pnl_x, this->pnl_y, 0, 0);
        } else {
            if (this->shape)
                this->shape->shape_draw(this->render_area, this->pnl_x, this->pnl_y, 0, 0, 0);
        }
        this->render_area->Unlock("pnl_pic::draw");
    }

    if (!this->keep_loaded)
        this->free_pic();

    this->draw_finish();
}
