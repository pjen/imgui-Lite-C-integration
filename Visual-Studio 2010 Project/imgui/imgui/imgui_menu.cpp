#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>

#include <d3d9.h>
#define DIRECTINPUT_VERSION 0x0800
#include <dinput.h>

#define DLL_USE
#include "adll.h"

#include "misc\freetype\imgui_freetype.h"
#include "imgui.h"
#include "imgui_impl_dx9.h"
#include "imgui_impl_win32.h"

DLLFUNC var imgui_begin_menubar()
{
	bool res = ImGui::BeginMenuBar();
	return res ? _VAR(1) : _VAR(0);
}

DLLFUNC void imgui_end_menubar()
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