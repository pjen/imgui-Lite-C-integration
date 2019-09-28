#include "dllmain.h"

BOOL APIENTRY DllMain( HANDLE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved )
{
	engine_bind();
    return TRUE;
}

DLLFUNC void imgui_ext_strcpy(char *dest, char* source)
{
	strcpy_s(dest, sizeof(source), source);
}

DLLFUNC void imgui_init(long config_flags)
{
	LPDIRECT3DDEVICE9 pd3dDev;
	pd3dDev = (LPDIRECT3DDEVICE9)draw_begin();

	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();

	io.KeyMap[ImGuiKey_A] = 30;
	io.KeyMap[ImGuiKey_C] = 46;
	io.KeyMap[ImGuiKey_Backspace] = 10;
	io.KeyMap[ImGuiKey_Delete] = 83;
	io.KeyMap[ImGuiKey_DownArrow] = 80;
	io.KeyMap[ImGuiKey_End] = 79;
	io.KeyMap[ImGuiKey_Enter] = 28;
	io.KeyMap[ImGuiKey_Escape] = 1;
	io.KeyMap[ImGuiKey_Home] = 71;
	io.KeyMap[ImGuiKey_Insert] = 82;
	io.KeyMap[ImGuiKey_LeftArrow] = 75;
	io.KeyMap[ImGuiKey_PageDown] = 73;
	io.KeyMap[ImGuiKey_PageUp] = 81;
	io.KeyMap[ImGuiKey_RightArrow] = 77;
	io.KeyMap[ImGuiKey_Space] = 57;
	io.KeyMap[ImGuiKey_Tab] = 15;
	io.KeyMap[ImGuiKey_UpArrow] = 72;
	io.KeyMap[ImGuiKey_V] = 47;
	io.KeyMap[ImGuiKey_X] = 45;
	io.KeyMap[ImGuiKey_Y] = 21;
	io.KeyMap[ImGuiKey_Z] = 44;

	io.ConfigFlags = config_flags;
	
	ImGui_ImplDX9_Init(pd3dDev);
}

DLLFUNC void imgui_reset()
{
	ImGui_ImplDX9_InvalidateDeviceObjects();
}

DLLFUNC long custom_scan_message(UINT message, WPARAM wParam, LPARAM lParam)
{
	ImGuiIO& io = ImGui::GetIO();

	if (WM_CHAR == message)
	{ 
		io.AddInputCharacter(wParam);
	}
	if ( WM_SYSCOMMAND == message && (wParam & 0xfff0) == SC_KEYMENU) 
	{
		return(1);
	}
	return(0);
}

DLLFUNC void imgui_start_imode()
{
	ImGuiIO& io = ImGui::GetIO();

	io.KeyCtrl = _INT(v(key_ctrl)) != 0;
	io.KeyAlt = _INT(v(key_alt)) != 0;
	io.KeyShift = _INT(v(key_shift)) != 0;

	io.KeysDown[io.KeyMap[ImGuiKey_A]] = _INT(v(key_a)) != 0;
	io.KeysDown[io.KeyMap[ImGuiKey_C]] = _INT(v(key_c)) != 0;
	io.KeysDown[io.KeyMap[ImGuiKey_Backspace]] = _INT(v(key_bksp)) != 0;
	io.KeysDown[io.KeyMap[ImGuiKey_Delete]] = _INT(v(key_del)) != 0;
	io.KeysDown[io.KeyMap[ImGuiKey_DownArrow]] = _INT(v(key_cud)) != 0;
	io.KeysDown[io.KeyMap[ImGuiKey_End]] = _INT(v(key_end)) != 0;
	io.KeysDown[io.KeyMap[ImGuiKey_Enter]] = _INT(v(key_enter)) != 0;
	io.KeysDown[io.KeyMap[ImGuiKey_Escape]] = _INT(v(key_esc)) != 0;
	io.KeysDown[io.KeyMap[ImGuiKey_Home]] = _INT(v(key_home)) != 0;
	io.KeysDown[io.KeyMap[ImGuiKey_Insert]] = _INT(v(key_ins)) != 0;
	io.KeysDown[io.KeyMap[ImGuiKey_LeftArrow]] = _INT(v(key_cul)) != 0;
	io.KeysDown[io.KeyMap[ImGuiKey_PageDown]] = _INT(v(key_pgup)) != 0;
	io.KeysDown[io.KeyMap[ImGuiKey_PageUp]] = _INT(v(key_pgdn)) != 0;
	io.KeysDown[io.KeyMap[ImGuiKey_RightArrow]] = _INT(v(key_cur)) != 0;
	io.KeysDown[io.KeyMap[ImGuiKey_Space]] = _INT(v(key_space)) != 0;
	io.KeysDown[io.KeyMap[ImGuiKey_Tab]] = _INT(v(key_tab)) != 0;
	io.KeysDown[io.KeyMap[ImGuiKey_UpArrow]] = _INT(v(key_cuu)) != 0;
	io.KeysDown[io.KeyMap[ImGuiKey_V]] = _INT(v(key_v)) != 0;
	io.KeysDown[io.KeyMap[ImGuiKey_X]] = _INT(v(key_x)) != 0;
	io.KeysDown[io.KeyMap[ImGuiKey_Y]] = _INT(v(key_y)) != 0;
	io.KeysDown[io.KeyMap[ImGuiKey_Z]] = _INT(v(key_z)) != 0;

	io.DeltaTime = _FLOAT(v(time_step)) / 16.0f; 
	io.DisplaySize.x = _FLOAT(v(screen_size).x);
    io.DisplaySize.y = _FLOAT(v(screen_size).y);
	io.MousePos = ImVec2( _FLOAT(v(mouse_pos).x), _FLOAT(v(mouse_pos).y) );
	io.MouseDown[0] = _FLOAT(v(mouse_left)) == 1;
    io.MouseDown[1] = _FLOAT(v(mouse_right)) == 1;
	io.MouseDown[2] = _FLOAT(v(mouse_middle)) == 1;
	io.MouseWheel = _FLOAT(sign(v(mickey).z));

	ImGui_ImplDX9_NewFrame();
    ImGui::NewFrame();
}

DLLFUNC void imgui_end_imode()
{
	ImGui::EndFrame();
	ImGui::Render();
	ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());
}