#include <d3d9.h>
#define DIRECTINPUT_VERSION 0x0800
#include <dinput.h>

#define DLL_USE
#include "adll.h"

#include "misc\freetype\imgui_freetype.h"
#include "imgui.h"
#include "imgui_impl_dx9.h"
#include "imgui_impl_win32.h"

DLLFUNC var imgui_listbox_header(char *label, int items_count, int height_in_items)
{
	bool res = ImGui::ListBoxHeader(label, items_count, height_in_items);
	return res ? _VAR(0) : _VAR(1);
}

DLLFUNC void imgui_listbox_footer()
{
	ImGui::ListBoxFooter();
}

DLLFUNC var imgui_listbox(char *label, int *current_item, char **items, int items_count, int height_in_items)
{
	bool res = ImGui::ListBox(label, current_item, items, items_count, height_in_items);
	return res ? _VAR(1) : _VAR(0);
}

DLLFUNC var imgui_selectable(char *label, int *p_selected, long flags)
{
	bool *dirty = (bool*)p_selected;
	bool res = ImGui::Selectable(label, dirty, flags);
	return res ? _VAR(1) : _VAR(0);
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

DLLFUNC var imgui_begin_combo(char *label, char *preview_value, long flags)
{
	bool res = ImGui::BeginCombo(label, preview_value, flags);
	return res ? _VAR(1) : _VAR(0);
}

DLLFUNC void imgui_end_combo()
{
	ImGui::EndCombo();
}

DLLFUNC var imgui_begin_popup_context_item(char *label)
{
	bool res = ImGui::BeginPopupContextItem(label);
	return res ? _VAR(1) : _VAR(0);
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

DLLFUNC void imgui_open_popup(char *str_id)
{
	ImGui::OpenPopup(str_id);
}

DLLFUNC VECTOR* imgui_get_mouse_pos_on_opening_current_popup()
{
	ImVec2 vec = ImGui::GetMousePosOnOpeningCurrentPopup();
	return _vec(vec.x, vec.y, 0);
}