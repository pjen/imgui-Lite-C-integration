#include "dllmain.h"

DLLFUNC void imgui_set_tooltip(char *tooltip)
{
	ImGui::SetTooltip(tooltip);
}

DLLFUNC void imgui_begin_tooltip()
{
	ImGui::BeginTooltip();
}

DLLFUNC void imgui_end_tooltip()
{
	ImGui::EndTooltip();
}