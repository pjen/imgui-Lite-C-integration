#include "dllmain.h"

DLLFUNC var imgui_is_item_active()
{
	bool res = ImGui::IsItemActive();
	return res ? _VAR(1) : _VAR(0);
}

DLLFUNC var imgui_is_anytime_active()
{
	bool res = ImGui::IsAnyItemActive();
	return res ? _VAR(1) : _VAR(0);
}

DLLFUNC VECTOR* imgui_get_item_rect_size()
{
	ImVec2 res = ImGui::GetItemRectSize();
	return vector(_VAR(res.x), _VAR(res.y), 0);
}

DLLFUNC int imgui_is_item_hovered()
{
	bool res = ImGui::IsItemHovered();
	return res ? 1 : 0;
}

DLLFUNC void imgui_push_id(var id)
{
	ImGui::PushID(_INT(id));
}

DLLFUNC void imgui_pop_id()
{
	ImGui::PopID();
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

DLLFUNC void imgui_set_cursor_screen_pos(VECTOR *pos)
{
	ImGui::SetCursorScreenPos(ImVec2(_FLOAT(pos->x), _FLOAT(pos->y)));
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

DLLFUNC var imgui_is_window_hovered()
{
	bool res = ImGui::IsWindowHovered();
	return res ? _VAR(1) : _VAR(0);
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

DLLFUNC int* imgui_get_io_config_flags()
{
	ImGuiIO& io = ImGui::GetIO();
	return &io.ConfigFlags;
}

DLLFUNC var imgui_get_time()
{
	float time = ImGui::GetTime();
	return _VAR(time);
}

DLLFUNC var imgui_is_key_pressed(int user_key_index, int repeat)
{
	bool rep = repeat != 0 ? true : false;
	bool res = ImGui::IsKeyPressed(user_key_index, rep);
	return res ? _VAR(1) : _VAR(0);
}

DLLFUNC int imgui_get_key_index(int imgui_key)
{
	return ImGui::GetKeyIndex(imgui_key);
	ImGuiKey_Space;
}

DLLFUNC int* imgui_get_io_config_input_text_cursor_blink()
{
	ImGuiIO& io = ImGui::GetIO();
	return (int*)&io.ConfigInputTextCursorBlink;
}

DLLFUNC int* imgui_get_io_config_windows_resize_from_edges()
{
	ImGuiIO& io = ImGui::GetIO();
	return (int*)&io.ConfigWindowsResizeFromEdges;
}

DLLFUNC int* imgui_get_io_config_windows_move_from_title_bar_only()
{
	ImGuiIO& io = ImGui::GetIO();
	return (int*)&io.ConfigWindowsMoveFromTitleBarOnly;
}

DLLFUNC int* imgui_get_io_mouse_draw_cursor()
{
	ImGuiIO& io = ImGui::GetIO();
	return (int*)&io.MouseDrawCursor;
}

DLLFUNC int* imgui_get_io_backend_flags()
{
	ImGuiIO& io = ImGui::GetIO();
	return (int*)&io.BackendFlags;
}

DLLFUNC void imgui_log_buttons()
{
	ImGui::LogButtons();
}

DLLFUNC void imgui_log_to_clipboard()
{
	ImGui::LogToClipboard();
}

DLLFUNC void imgui_log_text(char *fmt)
{
	ImGui::LogText(fmt);
}

DLLFUNC void imgui_log_finish()
{
	ImGui::LogFinish();
}

DLLFUNC var imgui_is_item_clicked(int mouse_button)
{
	bool res = ImGui::IsItemClicked(mouse_button);
	return res ? _VAR(1) : _VAR(0);
}

DLLFUNC int imgui_get_io_key_ctrl()
{
	bool res = ImGui::GetIO().KeyCtrl;
	return res ? 1 : 0;
}

DLLFUNC var imgui_get_text_line_height()
{
	return _VAR(ImGui::GetTextLineHeight());
}

DLLFUNC VECTOR* imgui_get_cursor_pos()
{
	return vector(_VAR(ImGui::GetCursorPos().x), _VAR(ImGui::GetCursorPos().y), _VAR(0));
}

DLLFUNC void* imgui_get_io_fonts_tex_id()
{
	return ImGui::GetIO().Fonts->TexID;
}

DLLFUNC int imgui_get_io_fonts_tex_width()
{
	return ImGui::GetIO().Fonts->TexWidth;
}

DLLFUNC int imgui_get_io_fonts_tex_height()
{
	return ImGui::GetIO().Fonts->TexHeight;
}

DLLFUNC VECTOR* imgui_get_io_mouse_pos()
{
	return vector(_VAR(ImGui::GetIO().MousePos.x), _VAR(ImGui::GetIO().MousePos.y), 0);
}

DLLFUNC void imgui_set_item_default_focus()
{
	ImGui::SetItemDefaultFocus();
}

DLLFUNC int imgui_is_mouse_double_clicked(int button)
{
	bool res = ImGui::IsMouseDoubleClicked(button);
	return res ? 1 : 0;
}

DLLFUNC var imgui_get_io_delta_time()
{
	return _VAR(ImGui::GetIO().DeltaTime);
}

DLLFUNC void imgui_color_convert_HSVto_RGB(var h, var s, var v, var *out_r, var *out_g, var *out_b)
{
	float r, g, b;
	ImGui::ColorConvertHSVtoRGB(_FLOAT(h), _FLOAT(s), _FLOAT(v), r, g, b);
	*out_r = _VAR(r);
	*out_g = _VAR(g);
	*out_b = _VAR(b);
}