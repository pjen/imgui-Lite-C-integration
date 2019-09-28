#include "dllmain.h"

DLLFUNC void* imgui_get_window_draw_list()
{
	return ImGui::GetWindowDrawList();
}

DLLFUNC void imgui_drawlist_add_line(void *draw_list, var xa, var ya, var xb, var yb, COLOR4 *color, var thickness)
{
	ImDrawList *dl = (ImDrawList*)draw_list;
	dl->AddLine(ImVec2(_FLOAT(xa), _FLOAT(ya)), ImVec2(_FLOAT(xb), _FLOAT(yb)), ImGui::ColorConvertFloat4ToU32(ImVec4(_FLOAT(color->red), _FLOAT(color->green), _FLOAT(color->blue), _FLOAT(color->alpha))), _FLOAT(thickness));
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

DLLFUNC void imgui_drawlist_channel_merge(void *draw_list)
{
	ImDrawList *dl = (ImDrawList*)draw_list;
	dl->ChannelsMerge();
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

DLLFUNC void imgui_drawlist_add_image(void *draw_list, BMAP *input, VECTOR *a, VECTOR *b, VECTOR *uv_a, VECTOR *uv_b, VECTOR *tint_color, var tint_alpha)
{
	ImDrawList *dl = (ImDrawList*)draw_list;
	ImTextureID my_tex_id = input->d3dtex;
	dl->AddImage(my_tex_id, ImVec2(_FLOAT(a->x), _FLOAT(a->y)), ImVec2(_FLOAT(b->x), _FLOAT(b->y)), ImVec2(_FLOAT(uv_a->x), _FLOAT(uv_a->y)), ImVec2(_FLOAT(uv_b->x), _FLOAT(uv_b->y)), ImColor(ImVec4(_FLOAT(tint_color->x),_FLOAT(tint_color->y),_FLOAT(tint_color->z),_FLOAT(tint_alpha))));
}