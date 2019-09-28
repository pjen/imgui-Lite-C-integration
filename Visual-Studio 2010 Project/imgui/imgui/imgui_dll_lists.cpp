#include "dllmain.h"

DLLFUNC var imgui_listbox_header(char *label, int items_count, int height_in_items)
{
	bool res = ImGui::ListBoxHeader(label, items_count, height_in_items);
	return res ? _VAR(0) : _VAR(1);
}

DLLFUNC void imgui_listbox_footer()
{
	ImGui::ListBoxFooter();
}

DLLFUNC int imgui_selectable(char *label, int *p_selected, int flags)
{
	bool *dirty = (bool*)p_selected;
	bool res = ImGui::Selectable(label, dirty, flags);
	return res ? 1 : 0;
}

DLLFUNC var imgui_selectable_direct(char *label, int p_selected)
{
	bool val = p_selected > 0 ? true : false;
	bool res = ImGui::Selectable(label, val);
	return res ? _VAR(1) : _VAR(0);
}

DLLFUNC var imgui_selectable_simple(char *label)
{
	bool res = ImGui::Selectable(label);
	return res ? _VAR(1) : _VAR(0);
}

DLLFUNC int imgui_selectable_size(char *label, int *p_selected, int flags, VECTOR *size)
{
	bool *dirty = (bool*)p_selected;
	bool res = ImGui::Selectable(label, dirty, flags, ImVec2(_FLOAT(size->x),_FLOAT(size->y)));
	return res ? 1 : 0;
}

DLLFUNC var imgui_combo(char *label, int* current_item, char *items_separated_by_zeros, int popup_max_height_in_items)
{
	bool res = ImGui::Combo(label, current_item, items_separated_by_zeros, popup_max_height_in_items);
	return res ? _VAR(1) : _VAR(0);
}

DLLFUNC var imgui_begin_combo(char *label, char *preview_value, long flags)
{
	bool res = ImGui::BeginCombo(label, preview_value, flags);
	return res ? _VAR(1) : _VAR(0);
}

DLLFUNC void imgui_end_combo()
{
	ImGui::EndCombo();
}

DLLFUNC var imgui_list_box(char *label, int *current_item, char **items, int items_count, int height_in_items)
{
	bool res = ImGui::ListBox(label, current_item, items, items_count, height_in_items);
	return res ? _VAR(1) : _VAR(0);
}