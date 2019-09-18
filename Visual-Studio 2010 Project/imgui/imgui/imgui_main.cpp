#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <string.h>

#include <d3d9.h>
#define DIRECTINPUT_VERSION 0x0800
#include <dinput.h>


#define DLL_USE
#include "adll.h"

#include "misc\freetype\imgui_freetype.h"
#include "imgui.h"
#include "imgui_impl_dx9.h"
#include "imgui_impl_win32.h"

BOOL APIENTRY DllMain( HANDLE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved )
{
	engine_bind();
    return TRUE;
}

DLLFUNC void ext_strcpy(char *dest, const char* source)
{
	strcpy_s(dest, sizeof(source), source);
}

DLLFUNC void imgui_init(long config_flags)
{
	LPDIRECT3DDEVICE9 pd3dDev;
	pd3dDev = (LPDIRECT3DDEVICE9)draw_begin();

	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();

	io.KeyMap[ImGuiKey_A] = 30;
	io.KeyMap[ImGuiKey_C] = 46;
	io.KeyMap[ImGuiKey_Backspace] = 10;
	io.KeyMap[ImGuiKey_Delete] = 83;
	io.KeyMap[ImGuiKey_DownArrow] = 80;
	io.KeyMap[ImGuiKey_End] = 79;
	io.KeyMap[ImGuiKey_Enter] = 28;
	io.KeyMap[ImGuiKey_Escape] = 1;
	io.KeyMap[ImGuiKey_Home] = 71;
	io.KeyMap[ImGuiKey_Insert] = 82;
	io.KeyMap[ImGuiKey_LeftArrow] = 75;
	io.KeyMap[ImGuiKey_PageDown] = 73;
	io.KeyMap[ImGuiKey_PageUp] = 81;
	io.KeyMap[ImGuiKey_RightArrow] = 77;
	io.KeyMap[ImGuiKey_Space] = 57;
	io.KeyMap[ImGuiKey_Tab] = 15;
	io.KeyMap[ImGuiKey_UpArrow] = 72;
	io.KeyMap[ImGuiKey_V] = 47;
	io.KeyMap[ImGuiKey_X] = 45;
	io.KeyMap[ImGuiKey_Y] = 21;
	io.KeyMap[ImGuiKey_Z] = 44;

	io.ConfigFlags = config_flags;
	
	ImGui_ImplDX9_Init(pd3dDev);
}

DLLFUNC void imgui_reset()
{
	ImGui_ImplDX9_InvalidateDeviceObjects();
}

DLLFUNC long custom_scan_message(UINT message, WPARAM wParam, LPARAM lParam)
{
	ImGuiIO& io = ImGui::GetIO();

	if (WM_CHAR == message)
	{ 
		io.AddInputCharacter(wParam);
	}
	if ( WM_SYSCOMMAND == message && (wParam & 0xfff0) == SC_KEYMENU) 
	{
		return(1);
	}
	return(0);
}


DLLFUNC void imgui_start_imode()
{
	ImGuiIO& io = ImGui::GetIO();

	io.KeyCtrl = _INT(v(key_ctrl)) != 0;
	io.KeyAlt = _INT(v(key_alt)) != 0;
	io.KeyShift = _INT(v(key_shift)) != 0;

	io.KeysDown[io.KeyMap[ImGuiKey_A]] = _INT(v(key_a)) != 0;
	io.KeysDown[io.KeyMap[ImGuiKey_C]] = _INT(v(key_c)) != 0;
	io.KeysDown[io.KeyMap[ImGuiKey_Backspace]] = _INT(v(key_bksp)) != 0;
	io.KeysDown[io.KeyMap[ImGuiKey_Delete]] = _INT(v(key_del)) != 0;
	io.KeysDown[io.KeyMap[ImGuiKey_DownArrow]] = _INT(v(key_cud)) != 0;
	io.KeysDown[io.KeyMap[ImGuiKey_End]] = _INT(v(key_end)) != 0;
	io.KeysDown[io.KeyMap[ImGuiKey_Enter]] = _INT(v(key_enter)) != 0;
	io.KeysDown[io.KeyMap[ImGuiKey_Escape]] = _INT(v(key_esc)) != 0;
	io.KeysDown[io.KeyMap[ImGuiKey_Home]] = _INT(v(key_home)) != 0;
	io.KeysDown[io.KeyMap[ImGuiKey_Insert]] = _INT(v(key_ins)) != 0;
	io.KeysDown[io.KeyMap[ImGuiKey_LeftArrow]] = _INT(v(key_cul)) != 0;
	io.KeysDown[io.KeyMap[ImGuiKey_PageDown]] = _INT(v(key_pgup)) != 0;
	io.KeysDown[io.KeyMap[ImGuiKey_PageUp]] = _INT(v(key_pgdn)) != 0;
	io.KeysDown[io.KeyMap[ImGuiKey_RightArrow]] = _INT(v(key_cur)) != 0;
	io.KeysDown[io.KeyMap[ImGuiKey_Space]] = _INT(v(key_space)) != 0;
	io.KeysDown[io.KeyMap[ImGuiKey_Tab]] = _INT(v(key_tab)) != 0;
	io.KeysDown[io.KeyMap[ImGuiKey_UpArrow]] = _INT(v(key_cuu)) != 0;
	io.KeysDown[io.KeyMap[ImGuiKey_V]] = _INT(v(key_v)) != 0;
	io.KeysDown[io.KeyMap[ImGuiKey_X]] = _INT(v(key_x)) != 0;
	io.KeysDown[io.KeyMap[ImGuiKey_Y]] = _INT(v(key_y)) != 0;
	io.KeysDown[io.KeyMap[ImGuiKey_Z]] = _INT(v(key_z)) != 0;

	io.DeltaTime = _FLOAT(v(time_step)) / 16.0f; 
	io.DisplaySize.x = _FLOAT(v(screen_size).x);
    io.DisplaySize.y = _FLOAT(v(screen_size).y);
	io.MousePos = ImVec2( _FLOAT(v(mouse_pos).x), _FLOAT(v(mouse_pos).y) );
	io.MouseDown[0] = _FLOAT(v(mouse_left)) == 1;
    io.MouseDown[1] = _FLOAT(v(mouse_right)) == 1;
	io.MouseDown[2] = _FLOAT(v(mouse_middle)) == 1;
	io.MouseWheel = _FLOAT(sign(v(mickey).z));

	ImGui_ImplDX9_NewFrame();
    ImGui::NewFrame();
}

DLLFUNC void imgui_end_imode()
{
	ImGui::EndFrame();
	ImGui::Render();
	ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
}

DLLFUNC void imgui_set_next_window_pos(var x, var y, long condition)
{
	ImGui::SetNextWindowPos(ImVec2(_FLOAT(x), _FLOAT(y)), condition);
}

DLLFUNC void imgui_set_next_window_size(var width, var height, long condition)
{
	ImGui::SetNextWindowSize(ImVec2(_FLOAT(width), _FLOAT(height)), condition);
}

DLLFUNC var imgui_begin(char *name, void *p_close, long flags)
{
	bool *dirty = (bool*)p_close;
	bool res = ImGui::Begin(name, dirty, flags);
	return res ? _VAR(1) : _VAR(0);
}

DLLFUNC void imgui_end()
{
	ImGui::End();
}

DLLFUNC void imgui_text(char *fmt)
{
	ImGui::Text(fmt);
}

DLLFUNC var imgui_get_window_width()
{
	return _VAR(ImGui::GetWindowWidth());
}

DLLFUNC var imgui_get_window_height()
{
	return _VAR(ImGui::GetWindowHeight());
}

DLLFUNC var imgui_get_window_x()
{
	return _VAR(ImGui::GetWindowPos().x);
}

DLLFUNC var imgui_get_window_y()
{
	return _VAR(ImGui::GetWindowPos().y);
}

DLLFUNC var imgui_get_font_size()
{
	return _VAR(ImGui::GetFontSize());
}

DLLFUNC void imgui_push_item_width(var item_width)
{
	ImGui::PushItemWidth(_FLOAT(item_width));
}

DLLFUNC var imgui_button(char *label)
{
	bool res = ImGui::Button(label);
	return res ? _VAR(1) : _VAR(0);
}

DLLFUNC var imgui_button_color(char *label, VECTOR *normal, VECTOR *hover, VECTOR *pushed)
{
	bool res = false;
	int color = 0;
	ImGui::SameLine();
    ImGui::PushID(10);
	if( normal ) {  color++; ImGui::PushStyleColor(ImGuiCol_Button, (ImVec4)ImColor::ImColor(_INT(normal->x), _INT(normal->y), _INT(normal->z))); }
	if( hover ) {  color++; ImGui::PushStyleColor(ImGuiCol_ButtonHovered, (ImVec4)ImColor::ImColor(_INT(hover->x), _INT(hover->y), _INT(hover->z))); }
	if( pushed ) {  color++; ImGui::PushStyleColor(ImGuiCol_ButtonActive, (ImVec4)ImColor::ImColor(_INT(pushed->x), _INT(pushed->y), _INT(pushed->z))); }
    ImGui::Button("Click");
    ImGui::PopStyleColor(color);
    ImGui::PopID();
	return res ? _VAR(1) : _VAR(0);
}

DLLFUNC var imgui_button_img(char *label, BMAP *input, var width, var height)
{
	ImTextureID my_tex_id = input->d3dtex;
	ImGui::PushID(label);
	bool res = ImGui::ImageButton(my_tex_id, ImVec2(_FLOAT(width), _FLOAT(height)), ImVec2(0, 0), ImVec2(1, 1), -1, ImVec4(0, 0, 0, 0), ImVec4(128, 128, 128, 255));
	ImGui::PopID();
	return res ? _VAR(1) : _VAR(0);
}

DLLFUNC var imgui_button_img_params(char *label, BMAP *input, var width, var height, var u1, var v1, var u2, var v2, var padding, COLOR4 *background, COLOR4 *tint)
{
	ImTextureID my_tex_id = input->d3dtex;
	ImGui::PushID(label);
	bool res = ImGui::ImageButton(my_tex_id, ImVec2(_FLOAT(width), _FLOAT(height)), ImVec2(_FLOAT(u1), _FLOAT(v1)), ImVec2(_FLOAT(u2), _FLOAT(v2)), _INT(padding), ImVec4(_FLOAT(background->red), _FLOAT(background->green), _FLOAT(background->blue), _FLOAT(background->alpha)), ImVec4(_FLOAT(tint->red), _FLOAT(tint->green), _FLOAT(tint->blue), _FLOAT(tint->alpha)));
	ImGui::PopID();
	return res ? _VAR(1) : _VAR(0);
}

DLLFUNC var imgui_checkbox(char *label, void *state)
{
	bool *dirty = (bool*)state;
	bool res = ImGui::Checkbox(label, dirty);
	return res ? _VAR(1) : _VAR(0);
}

DLLFUNC var imgui_checkbox_flag(char *label, long *flags, long flag)
{
	bool prev = (*flags & flag) > 0;
	bool state = (*flags & flag) > 0;
	bool res = ImGui::Checkbox(label, &state);
	if( prev && !state) { *flags &= ~flag; }  
	if( !prev && state ) { *flags |= flag; }
	return res ? _VAR(1) : _VAR(0);
}

DLLFUNC var imgui_radiobutton(char *label, int *result_pointer, int value)
{
	bool res = ImGui::RadioButton(label, result_pointer, value);
	return res ? _VAR(1) : _VAR(0);
}

DLLFUNC void imgui_same_line()
{
	ImGui::SameLine();
}
DLLFUNC void imgui_same_line_params(var local_pos_x, var spacing_w)
{
	ImGui::SameLine(_FLOAT(local_pos_x), _FLOAT(spacing_w) );
}

DLLFUNC void imgui_push_id(var id)
{
	ImGui::PushID(_INT(id));
}

DLLFUNC void imgui_pop_id()
{
	ImGui::PopID();
}

DLLFUNC void imgui_push_style_color(long type, COLOR4 *color)
{
	ImGui::PushStyleColor(type, (ImVec4)ImColor::ImColor(_INT(color->red), _INT(color->green), _INT(color->blue), _INT(color->alpha)));
}

DLLFUNC void imgui_pop_style_color(int count)
{
	ImGui::PopStyleColor(count);
}

DLLFUNC void imgui_align_text_to_frame_padding()
{
	ImGui::AlignTextToFramePadding();
}

DLLFUNC void imgui_push_button_repeat(int value)
{
	bool b = value > 0;
	ImGui::PushButtonRepeat(b);
}

DLLFUNC void imgui_pop_button_repeat()
{
	ImGui::PopButtonRepeat();
}

DLLFUNC var imgui_arrow_button(char *str_id, long dir)
{
	bool res = ImGui::ArrowButton(str_id, dir);
	return res ? _VAR(1) : _VAR(0);
}

DLLFUNC var imgui_is_item_hovered()
{
	bool res = ImGui::IsItemHovered();
	return res ? _VAR(1) : _VAR(0);
}

DLLFUNC void imgui_set_tooltip(char *tooltip)
{
	ImGui::SetTooltip(tooltip);
}

DLLFUNC void imgui_begin_tooltip()
{
	ImGui::BeginTooltip();
}

DLLFUNC void imgui_end_tooltip()
{
	ImGui::EndTooltip();
}

DLLFUNC void imgui_plotlines(char *label, float *values, int values_count)
{
	ImGui::PlotLines(label, values, values_count);
}

DLLFUNC void imgui_separator()
{
	ImGui::Separator();
}

DLLFUNC var imgui_collapsing_header(char *label, void *p_open, long flags)
{
	bool *dirty = (bool*)p_open;
	bool res = ImGui::CollapsingHeader(label, dirty, flags);
	return res ? _VAR(1) : _VAR(0);
}

DLLFUNC void imgui_tree_pop()
{
	ImGui::TreePop();
}

DLLFUNC void imgui_image(BMAP *input)
{
	ImTextureID my_tex_id = input->d3dtex;
    float my_tex_w = _FLOAT(bmap_width(input));
    float my_tex_h = _FLOAT(bmap_height(input));
	ImGui::Image(my_tex_id, ImVec2(my_tex_w, my_tex_h));
}

DLLFUNC void imgui_image_scale(BMAP *input, VECTOR *size, VECTOR *uv_start, VECTOR *uv_end)
{
	ImTextureID my_tex_id = input->d3dtex;
   
	ImGui::Image(my_tex_id, ImVec2(_FLOAT(size->x), _FLOAT(size->y)), ImVec2(_FLOAT(uv_start->x), _FLOAT(uv_start->y)), ImVec2(_FLOAT(uv_end->x), _FLOAT(uv_end->y)));
}

DLLFUNC void imgui_push_style_var(int idx, var val)
{
	ImGui::PushStyleVar(idx, _FLOAT(val));
}

DLLFUNC void imgui_push_style_vec(int idx, VECTOR *val)
{
	ImGui::PushStyleVar(idx, ImVec2(_FLOAT(val->x), _FLOAT(val->y)));
}

DLLFUNC void imgui_pop_style_var(int count)
{
	ImGui::PopStyleVar(count);
}

DLLFUNC var imgui_get_frame_height_with_spacing()
{
	return _VAR(ImGui::GetFrameHeightWithSpacing());
}

DLLFUNC void imgui_begin_child(char *id, VECTOR *size, int border, long flags)
{
	 bool bborder = border > 0 ? true : false;
	 ImGui::BeginChild(id, ImVec2(_FLOAT(size->x), _FLOAT(size->y)), bborder, flags);
}

DLLFUNC void imgui_end_child()
{
	ImGui::EndChild();
}

DLLFUNC var imgui_color_edit3(char *label, float *col, long flags)
{
	bool res = ImGui::ColorEdit3(label, col, flags);
	return res ? _VAR(1) : _VAR(0);
}

DLLFUNC void imgui_columns(int count, char *id, int border)
{
	bool bborder = border > 0 ? true : false;
	ImGui::Columns(count, id, bborder);
}

DLLFUNC void imgui_next_column()
{
	ImGui::NextColumn();
}

DLLFUNC void imgui_pop_item_width()
{
	ImGui::PopItemWidth();
}

DLLFUNC void set_column_offset(int column_index, var offset_x)
{
	ImGui::SetColumnOffset(column_index, _FLOAT(offset_x));
}

DLLFUNC void set_column_width(int column_index, var width)
{
	ImGui::SetColumnWidth(column_index, _FLOAT(width));
}

DLLFUNC var imgui_get_content_region_avail_width()
{
	return _VAR(ImGui::GetContentRegionAvailWidth());
}

DLLFUNC void imgui_begin_group()
{
	ImGui::BeginGroup();
}

DLLFUNC void imgui_end_group()
{
	ImGui::EndGroup();
}

DLLFUNC var imgui_is_mouse_clicked(var btn)
{
	bool res = ImGui::IsMouseClicked(_INT(btn));
	return res ? _VAR(1) : _VAR(0);
}

DLLFUNC VECTOR* imgui_get_cursor_screen_pos()
{
	ImVec2 vec = ImGui::GetCursorScreenPos();
	return vector(_VAR(vec.x), _VAR(vec.y), _VAR(0));
}

DLLFUNC void* imgui_get_window_drawlist()
{
	return ImGui::GetWindowDrawList();
}

DLLFUNC void imgui_drawlist_add_line(void *draw_list, var xa, var ya, var xb, var yb, COLOR4 *color, var thickness)
{
	ImDrawList *dl = (ImDrawList*)draw_list;
	dl->AddLine(ImVec2(_FLOAT(xa), _FLOAT(ya)), ImVec2(_FLOAT(xb), _FLOAT(yb)), ImGui::ColorConvertFloat4ToU32(ImVec4(_FLOAT(color->red), _FLOAT(color->green), _FLOAT(color->blue), _FLOAT(color->alpha))), _FLOAT(thickness));
}

DLLFUNC VECTOR* imgui_get_window_size()
{
	ImVec2 vec = ImGui::GetWindowSize();
	return vector(_VAR(vec.x), _VAR(vec.y), _VAR(0));
}

DLLFUNC void imgui_drawlist_channel_split(void *draw_list, int channels_count)
{
	ImDrawList *dl = (ImDrawList*)draw_list;
	dl->ChannelsSplit(channels_count);
}

DLLFUNC void imgui_drawlist_channel_set_current(void *draw_list, int channel_index)
{
	ImDrawList *dl = (ImDrawList*)draw_list;
	dl->ChannelsSetCurrent(channel_index);
}

DLLFUNC void imgui_drawlist_add_bezier_curve(void *draw_list, VECTOR *pos0, VECTOR *cp0, VECTOR *cp1, VECTOR *pos1, VECTOR *color, var thickness, int num_segments)
{
	ImDrawList *dl = (ImDrawList*)draw_list;
	dl->AddBezierCurve(ImVec2(_FLOAT(pos0->x), _FLOAT(pos0->y)), ImVec2(_FLOAT(cp0->x), _FLOAT(cp0->y)), ImVec2(_FLOAT(cp1->x), _FLOAT(cp1->y)), ImVec2(_FLOAT(pos1->x), _FLOAT(pos1->y)), ImGui::ColorConvertFloat4ToU32(ImVec4(_FLOAT(color->x), _FLOAT(color->y), _FLOAT(color->z), _FLOAT(255))), _FLOAT(thickness), num_segments);
}

DLLFUNC void imgui_Drawlist_channel_merge(void *draw_list)
{
	ImDrawList *dl = (ImDrawList*)draw_list;
	dl->ChannelsMerge();
}

DLLFUNC var imgui_is_anytime_active()
{
	bool res = ImGui::IsAnyItemActive();
	return res ? _VAR(1) : _VAR(0);
}

DLLFUNC void imgui_set_cursor_screen_pos(VECTOR *pos)
{
	ImGui::SetCursorScreenPos(ImVec2(_FLOAT(pos->x), _FLOAT(pos->y)));
}

DLLFUNC VECTOR* imgui_get_item_rect_size()
{
	ImVec2 res = ImGui::GetItemRectSize();
	return vector(_VAR(res.x), _VAR(res.y), 0);
}

DLLFUNC var imgui_invisible_button(char *str_id, VECTOR *size)
{
	bool res = ImGui::InvisibleButton(str_id, ImVec2(_FLOAT(size->x), _FLOAT(size->y)));
	return res ? _VAR(1) : _VAR(0);
}

DLLFUNC var imgui_is_item_active()
{
	bool res = ImGui::IsItemActive();
	return res ? _VAR(1) : _VAR(0);
}

DLLFUNC var imgui_is_any_item_active()
{
	bool res = ImGui::IsAnyItemActive();
	return res ? _VAR(1) : _VAR(0);
}

DLLFUNC VECTOR* imgui_get_io_mouse_delta()
{
	ImVec2 res = ImGui::GetIO().MouseDelta;
	return vector(_VAR(res.x), _VAR(res.y), 0);
}

DLLFUNC var imgui_is_mouse_dragging(int btn, var lock_threshold)
{
	bool res = ImGui::IsMouseDragging(btn, _FLOAT(lock_threshold));
	return res ? _VAR(1) : _VAR(0);
}

DLLFUNC void imgui_drawlist_add_rect_filled(void *draw_list, VECTOR *a, VECTOR *b, VECTOR *color, var rounding)
{
	ImDrawList *dl = (ImDrawList*)draw_list;
	dl->AddRectFilled(ImVec2(_FLOAT(a->x),_FLOAT(a->y)), ImVec2(_FLOAT(b->x),_FLOAT(b->y)), ImGui::ColorConvertFloat4ToU32(ImVec4(_FLOAT(color->x), _FLOAT(color->y), _FLOAT(color->z), _FLOAT(255))), _FLOAT(rounding));
}

DLLFUNC void imgui_drawlist_add_rect(void *draw_list, VECTOR *a, VECTOR *b, VECTOR *color, var rounding)
{
	ImDrawList *dl = (ImDrawList*)draw_list;
	dl->AddRect(ImVec2(_FLOAT(a->x),_FLOAT(a->y)), ImVec2(_FLOAT(b->x),_FLOAT(b->y)), ImGui::ColorConvertFloat4ToU32(ImVec4(_FLOAT(color->x), _FLOAT(color->y), _FLOAT(color->z), _FLOAT(255))), _FLOAT(rounding));
}

DLLFUNC void imgui_drawlist_add_circle_filled(void *draw_list, VECTOR* center, var radius, VECTOR *color)
{
	ImDrawList *dl = (ImDrawList*)draw_list;
	dl->AddCircleFilled(ImVec2(_FLOAT(center->x), _FLOAT(center->y)), _FLOAT(radius), ImGui::ColorConvertFloat4ToU32(ImVec4(_FLOAT(color->x), _FLOAT(color->y), _FLOAT(color->z), _FLOAT(255))));
}

DLLFUNC var imgui_is_window_hovered()
{
	bool res = ImGui::IsWindowHovered();
	return res ? _VAR(1) : _VAR(0);
}

DLLFUNC void imgui_drawlist_add_triangle_filled(void *draw_list, VECTOR *a, VECTOR *b, VECTOR *c, COLOR4 *color)
{
	ImDrawList *dl = (ImDrawList*)draw_list;
	dl->AddTriangleFilled(ImVec2(_FLOAT(a->x),_FLOAT(a->y)), ImVec2(_FLOAT(b->x),_FLOAT(b->y)), ImVec2(_FLOAT(c->x),_FLOAT(c->y)), ImGui::ColorConvertFloat4ToU32(ImVec4(_FLOAT(color->red), _FLOAT(color->green), _FLOAT(color->blue), _FLOAT(color->alpha))));
}

DLLFUNC void imgui_drawlist_add_triangle(void *draw_list, VECTOR *a, VECTOR *b, VECTOR *c, COLOR4 *color)
{
	ImDrawList *dl = (ImDrawList*)draw_list;
	dl->AddTriangle(ImVec2(_FLOAT(a->x),_FLOAT(a->y)), ImVec2(_FLOAT(b->x),_FLOAT(b->y)), ImVec2(_FLOAT(c->x),_FLOAT(c->y)), ImGui::ColorConvertFloat4ToU32(ImVec4(_FLOAT(color->red), _FLOAT(color->green), _FLOAT(color->blue), _FLOAT(color->alpha))));
}

DLLFUNC void imgui_drawlist_add_text(void *draw_list, VECTOR *pos, COLOR4 *color, char *text_begin)
{
	ImDrawList *dl = (ImDrawList*)draw_list;
	dl->AddText(ImVec2(_FLOAT(pos->x),_FLOAT(pos->y)), ImGui::ColorConvertFloat4ToU32(ImVec4(_FLOAT(color->red), _FLOAT(color->green), _FLOAT(color->blue), _FLOAT(color->alpha))), text_begin);
}

DLLFUNC var imgui_is_any_item_hoverd()
{
	bool res = ImGui::IsAnyItemHovered();
	return res ? _VAR(1) : _VAR(0);
}

DLLFUNC var imgui_is_mouse_hovering_window()
{
	bool res = ImGui::IsMouseHoveringWindow();
	return res ? _VAR(1) : _VAR(0);
}

DLLFUNC var imgui_begin_popup_modals(char *name)
{
	bool res = ImGui::BeginPopupModal(name, NULL, ImGuiWindowFlags_AlwaysAutoResize);
	return res ? _VAR(1) : _VAR(0);
}

DLLFUNC var imgui_begin_popup_modals_params(char *name, void *p_open, long flags)
{
	bool *dirty = (bool*)p_open;
	bool res = ImGui::BeginPopupModal(name, dirty, flags);
	return res ? _VAR(1) : _VAR(0);
}

DLLFUNC void imgui_close_current_popup()
{
	ImGui::CloseCurrentPopup();
}

DLLFUNC void imgui_drawlist_add_polygon(void *draw_list, POINT **points, int num_points, COLOR4 *col, int closed, var thickness)
{
	ImDrawList *dl = (ImDrawList*)draw_list;
	ImVec2 vec_array[100];
	for(int i=0; i < num_points; i++)
	{
		POINT *point = points[i];
		vec_array[i] = ImVec2((float)point->x, (float)point->y);
	}
	ImColor vcol = ImColor(_FLOAT(col->red), _FLOAT(col->green), _FLOAT(col->blue), _FLOAT(col->alpha));
	bool bclosed = closed > 0 ? true : false;
	dl->AddPolyline(vec_array, num_points, vcol, bclosed, _FLOAT(thickness));
}

