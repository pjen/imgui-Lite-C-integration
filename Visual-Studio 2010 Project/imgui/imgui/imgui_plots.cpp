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


DLLFUNC void imgui_plot_lines(char *label, float *arr, float values_offset, char *overlay_text, VECTOR *graph_size)
{
    ImGui::PlotLines(label, arr, IM_ARRAYSIZE(arr));
}


