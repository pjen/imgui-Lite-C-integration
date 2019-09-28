#include "dllmain.h"

DLLFUNC var imgui_begin_menu_bar()
{
	bool res = ImGui::BeginMenuBar();
	return res ? _VAR(1) : _VAR(0);
}

DLLFUNC void imgui_end_menu_bar()
{
	ImGui::EndMenuBar();
}

DLLFUNC var imgui_begin_menu(char *label, int enabled)
{
	bool res = ImGui::BeginMenu(label, enabled != 0);
	return res ? _VAR(1) : _VAR(0);
}

DLLFUNC void imgui_end_menu()
{
	ImGui::EndMenu();
}

DLLFUNC var imgui_menu_item(char *label, char *shortcut, int selected, int enabled)
{
	bool res = ImGui::MenuItem(label, shortcut, selected != 0, enabled != 0);
	return res ? _VAR(1) : _VAR(0);
}