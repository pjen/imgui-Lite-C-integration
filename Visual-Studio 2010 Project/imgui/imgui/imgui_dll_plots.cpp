#include "dllmain.h"

DLLFUNC void imgui_plot_lines(char *label, float *values, int values_count, float values_offset, char *overlay_text, float scale_min, float scale_max, VECTOR *graph_size)
{
	ImGui::PlotLines(label, values, values_count, values_offset, overlay_text, scale_min, scale_max, ImVec2(_FLOAT(graph_size->x), _FLOAT(graph_size->y)));
}


DLLFUNC void imgui_plotlines(char *label, float *values, int values_count)
{
	ImGui::PlotLines(label, values, values_count);
}

DLLFUNC void imgui_plot_histogram(char *label, float *values, int values_count, int values_offset, char *overlay_text, float scale_min, float scale_max, VECTOR *graph_size, int stride)
{
	ImGui::PlotHistogram(label, values, values_count, values_offset, overlay_text, scale_min, scale_max, ImVec2(_FLOAT(graph_size->x), _FLOAT(graph_size->y)), stride);
}

DLLFUNC void imgui_progress_bar(var fraction, VECTOR *size_arg, char *overlay)
{
	ImGui::ProgressBar(_FLOAT(fraction), ImVec2(_FLOAT(size_arg->x), _FLOAT(size_arg->y)), overlay);
}