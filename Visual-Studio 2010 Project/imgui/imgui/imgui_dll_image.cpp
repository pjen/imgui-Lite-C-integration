#include "dllmain.h"

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

DLLFUNC void imgui_image_scale_color(BMAP *input, VECTOR *size, VECTOR *uv_start, VECTOR *uv_end, VECTOR* tint_color, var tint_alpha, VECTOR *border_col, var border_alpha)
{
	ImTextureID my_tex_id = input->d3dtex;
	ImGui::Image(my_tex_id, ImVec2(_FLOAT(size->x), _FLOAT(size->y)), ImVec2(_FLOAT(uv_start->x), _FLOAT(uv_start->y)), ImVec2(_FLOAT(uv_end->x), _FLOAT(uv_end->y)), ImVec4(_FLOAT(tint_color->x),_FLOAT(tint_color->y),_FLOAT(tint_color->z),_FLOAT(tint_alpha)), ImVec4(_FLOAT(border_col->x),_FLOAT(border_col->y),_FLOAT(border_col->z),_FLOAT(border_alpha)));
}

DLLFUNC void imgui_image_scale_color_tex_id(void *my_tex_id, VECTOR *size, VECTOR *uv_start, VECTOR *uv_end, VECTOR* tint_color, var tint_alpha, VECTOR *border_col, var border_alpha)
{
	ImGui::Image(my_tex_id, ImVec2(_FLOAT(size->x), _FLOAT(size->y)), ImVec2(_FLOAT(uv_start->x), _FLOAT(uv_start->y)), ImVec2(_FLOAT(uv_end->x), _FLOAT(uv_end->y)), ImVec4(_FLOAT(tint_color->x),_FLOAT(tint_color->y),_FLOAT(tint_color->z),_FLOAT(tint_alpha)), ImVec4(_FLOAT(border_col->x),_FLOAT(border_col->y),_FLOAT(border_col->z),_FLOAT(border_alpha)));
}

