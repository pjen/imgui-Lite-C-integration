#include <acknex.h>
#include <default.c>

#define PRAGMA_PATH "imgui_header"

#include "imgui.h"

void window_func()
{
	imgui_set_next_window_pos(100, 100, ImGuiCond_Once);
	imgui_set_next_window_size(screen_size.x - 200, screen_size.y - 200, ImGuiCond_Once);
	
	if (!imgui_begin("Window##id", NULL, ImGuiWindowFlags_NoResize))
	{
		imgui_end();
		return;
	}
	
	imgui_end();
}

void loop()
{
	imgui_start_imode();
	
	window_func();
	
	imgui_end_imode();
}

void main()
{
	mouse_sync = 0;
	mouse_pointer = 2;
	mouse_mode = 4;
	video_switch(10, 32, 2);
	wait(1);
	level_load("");
	
	imgui_init(0);
	
	on_d3d_lost = imgui_reset;
	on_scanmessage = custom_scan_message;
	
	on_frame = loop;
}