# 00463100 RGE_Object_List::shadow_draw

`shadow_draw` is virtual slot four after the object vptr.

The master object has a virtual destructor. This supplies its vptr.

When fog is active, the function checks `master_obj->fog_flag` before the virtual call.
