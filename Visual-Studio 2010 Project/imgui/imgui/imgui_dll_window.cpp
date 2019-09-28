#include "dllmain.h"

DLLFUNC void imgui_set_next_window_pos(var x, var y, long condition)
{
	ImGui::SetNextWindowPos(ImVec2(_FLOAT(x), _FLOAT(y)), condition);
}

DLLFUNC void imgui_set_next_window_size(var width, var height, long condition)
{
	ImGui::SetNextWindowSize(ImVec2(_FLOAT(width), _FLOAT(height)), condition);
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

DLLFUNC var imgui_get_content_region_avail_width()
{
	return _VAR(ImGui::GetContentRegionAvailWidth());
}

DLLFUNC VECTOR* imgui_get_window_size()
{
	ImVec2 vec = ImGui::GetWindowSize();
	return vector(_VAR(vec.x), _VAR(vec.y), _VAR(0));
}