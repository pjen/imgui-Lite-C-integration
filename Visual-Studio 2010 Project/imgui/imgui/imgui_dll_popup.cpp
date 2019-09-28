#include "dllmain.h"

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

DLLFUNC var imgui_begin_popup(char *label, long flags)
{
	bool res = ImGui::BeginPopup(label, flags);
	return res ? _VAR(1) : _VAR(0);
}

DLLFUNC void imgui_end_popup()
{
	ImGui::EndPopup();
}

DLLFUNC var imgui_begin_popup_context_item(char *label)
{
	bool res = ImGui::BeginPopupContextItem(label);
	return res ? _VAR(1) : _VAR(0);
}

DLLFUNC void imgui_open_popup(char *str_id)
{
	ImGui::OpenPopup(str_id);
}

DLLFUNC VECTOR* imgui_get_mouse_pos_on_opening_current_popup()
{
	ImVec2 vec = ImGui::GetMousePosOnOpeningCurrentPopup();
	return _vec(vec.x, vec.y, 0);
}