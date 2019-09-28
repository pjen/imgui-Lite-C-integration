#include "dllmain.h"

DLLFUNC var imgui_font_allow_user_scaling()
{
	bool res = ImGui::GetIO().FontAllowUserScaling;
	return res ? _VAR(1) : _VAR(0);
}

DLLFUNC void imgui_indent(var indent_w)
{
	ImGui::Indent(_FLOAT(indent_w));
}

DLLFUNC void imgui_unindent(var indent_w)
{
	ImGui::Unindent(_FLOAT(indent_w));
}

DLLFUNC var imgui_get_font_size()
{
	return _VAR(ImGui::GetFontSize());
}

DLLFUNC void imgui_push_item_width(var item_width)
{
	ImGui::PushItemWidth(_FLOAT(item_width));
}

DLLFUNC void imgui_same_line()
{
	ImGui::SameLine();
}

DLLFUNC void imgui_same_line_params(var local_pos_x, var spacing_w)
{
	ImGui::SameLine(_FLOAT(local_pos_x), _FLOAT(spacing_w) );
}

DLLFUNC void imgui_push_style_color(long type, COLOR4 *color)
{
	ImGui::PushStyleColor(type, (ImVec4)ImColor::ImColor(_INT(color->red), _INT(color->green), _INT(color->blue), _INT(color->alpha)));
}

DLLFUNC void imgui_push_style_color_hsv(int type, float h, float s, float v, float a)
{
	ImGui::PushStyleColor(type, (ImVec4)ImColor::HSV(h, s, v, a));
}

DLLFUNC void imgui_pop_style_color(int count)
{
	ImGui::PopStyleColor(count);
}

DLLFUNC void imgui_align_text_to_frame_padding()
{
	ImGui::AlignTextToFramePadding();
}

DLLFUNC void imgui_separator()
{
	ImGui::Separator();
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

DLLFUNC void imgui_set_column_offset(int column_index, var offset_x)
{
	ImGui::SetColumnOffset(column_index, _FLOAT(offset_x));
}

DLLFUNC void imgui_set_column_width(int column_index, var width)
{
	ImGui::SetColumnWidth(column_index, _FLOAT(width));
}

DLLFUNC void imgui_spacing()
{
	ImGui::Spacing();
}

DLLFUNC VECTOR* imgui_get_style_item_inner_spacing()
{
	return vector(_VAR(ImGui::GetStyle().ItemInnerSpacing.x), _VAR(ImGui::GetStyle().ItemInnerSpacing.y), _VAR(0));
}

DLLFUNC VECTOR* imgui_get_style_item_spacing()
{
	return vector(_VAR(ImGui::GetStyle().ItemSpacing.x), _VAR(ImGui::GetStyle().ItemSpacing.y), _VAR(0));
}


DLLFUNC VECTOR* imgui_get_item_rect_min()
{
	return vector(_VAR(ImGui::GetItemRectMin().x), _VAR(ImGui::GetItemRectMin().y), _VAR(0));
}

DLLFUNC VECTOR* imgui_get_item_rect_max()
{
	return vector(_VAR(ImGui::GetItemRectMax().x), _VAR(ImGui::GetItemRectMax().y), _VAR(0));
}

DLLFUNC void imgui_new_line()
{
	ImGui::NewLine();
}