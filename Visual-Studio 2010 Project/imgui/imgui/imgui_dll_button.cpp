#include "dllmain.h"

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

DLLFUNC var imgui_invisible_button(char *str_id, VECTOR *size)
{
	bool res = ImGui::InvisibleButton(str_id, ImVec2(_FLOAT(size->x), _FLOAT(size->y)));
	return res ? _VAR(1) : _VAR(0);
}

DLLFUNC var imgui_radio_button(char *label, int* v, int v_button)
{
	bool res = ImGui::RadioButton(label, v, v_button);
	return res ? _VAR(1) : _VAR(0);
}

DLLFUNC var imgui_small_button(char *label)
{
	bool res = ImGui::SmallButton(label);
	return res ? _VAR(1) : _VAR(0);
}

DLLFUNC var imgui_image_button(BMAP *input, VECTOR *size, VECTOR *uv0, VECTOR *uv1, int frame_padding, VECTOR* bg_col, var bg_alpha, VECTOR *tint_color, var tint_alpha )
{
	ImTextureID my_tex_id = input->d3dtex;
	bool res = ImGui::ImageButton(my_tex_id, ImVec2(_FLOAT(size->x), _FLOAT(size->y)), ImVec2(_FLOAT(uv0->x), _FLOAT(uv0->y)), ImVec2(_FLOAT(uv1->x), _FLOAT(uv1->y)), frame_padding, ImVec4(_FLOAT(bg_col->x),_FLOAT(bg_col->y),_FLOAT(bg_col->z),_FLOAT(bg_alpha)), ImVec4(_FLOAT(tint_color->x),_FLOAT(tint_color->y),_FLOAT(tint_color->z),_FLOAT(tint_alpha)));
	return res ? _VAR(1) : _VAR(0);
}

DLLFUNC var imgui_image_button_tex_id(void *my_tex_id, VECTOR *size, VECTOR *uv0, VECTOR *uv1, int frame_padding, VECTOR* bg_col, var bg_alpha, VECTOR *tint_color, var tint_alpha )
{
	bool res = ImGui::ImageButton(my_tex_id, ImVec2(_FLOAT(size->x), _FLOAT(size->y)), ImVec2(_FLOAT(uv0->x), _FLOAT(uv0->y)), ImVec2(_FLOAT(uv1->x), _FLOAT(uv1->y)), frame_padding, ImVec4(_FLOAT(bg_col->x),_FLOAT(bg_col->y),_FLOAT(bg_col->z),_FLOAT(bg_alpha)), ImVec4(_FLOAT(tint_color->x),_FLOAT(tint_color->y),_FLOAT(tint_color->z),_FLOAT(tint_alpha)));
	return res ? _VAR(1) : _VAR(0);
}