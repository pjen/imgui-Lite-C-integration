#include "dllmain.h"

DLLFUNC var imgui_color_edit3(char *label, float *col, long flags)
{
	bool res = ImGui::ColorEdit3(label, col, flags);
	return res ? _VAR(1) : _VAR(0);
}

DLLFUNC var imgui_color_edit4(char *label, float *col, long flags)
{
	bool res = ImGui::ColorEdit4(label, col, flags);
	return res ? _VAR(1) : _VAR(0);
}

DLLFUNC void imgui_show_metrics_window(int *p_open)
{
	bool *dirty = (bool*)p_open;
	ImGui::ShowMetricsWindow(dirty);
}

DLLFUNC void imgui_show_style_editor()
{
	ImGui::ShowStyleEditor();
}

DLLFUNC void imgui_show_user_guide()
{
	ImGui::ShowUserGuide();
}

DLLFUNC void imgui_show_about_window(int *p_open)
{
	bool *dirty = (bool*)p_open;
	ImGui::ShowAboutWindow(dirty);
}

DLLFUNC int imgui_color_button(char *desc_id, float *col, int flags, VECTOR *size)
{
	bool res = ImGui::ColorButton(desc_id, ImVec4(col[0],col[1],col[2],col[3]), flags, ImVec2(_FLOAT(size->x),_FLOAT(size->y)));
	return res ? 1 : 0;
}

DLLFUNC int imgui_color_picker_4(char *label, float *col, int flags, float *ref_col)
{
	bool res = ImGui::ColorPicker4(label, col, flags, ref_col);
	return res ? 1 : 0;
}

DLLFUNC void imgui_set_color_edit_options(int flags)
{
	ImGui::SetColorEditOptions(flags);
}