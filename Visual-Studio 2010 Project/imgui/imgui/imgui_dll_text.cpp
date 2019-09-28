#include "dllmain.h"

DLLFUNC void imgui_text(char *fmt)
{
	ImGui::Text(fmt);
}

DLLFUNC void imgui_text_disabled(char *fmt)
{
	ImGui::TextDisabled(fmt);
}

DLLFUNC void imgui_push_text_wrap_pos(var wrap_local_pos_x)
{
	ImGui::PushTextWrapPos(_FLOAT(wrap_local_pos_x));
}

DLLFUNC void imgui_pop_text_wrap_pos()
{
	ImGui::PopTextWrapPos();
}

DLLFUNC void imgui_text_unformatted(char *text)
{
	ImGui::TextUnformatted(text);
}

DLLFUNC void imgui_bullet_text(char *fmt)
{
	ImGui::BulletText(fmt);
}

DLLFUNC void imgui_text_wrapped(char *fmt)
{
	ImGui::TextWrapped(fmt);
}

DLLFUNC void imgui_label_text(char *label, char *fmt)
{
	ImGui::LabelText(label, fmt);
}

DLLFUNC void imgui_bullet()
{
	ImGui::Bullet();
}

DLLFUNC void imgui_text_colored(var r, var g, var b, var a, char* fmt)
{
	ImGui::TextColored(ImVec4(_FLOAT(r), _FLOAT(g), _FLOAT(b), _FLOAT(a)), fmt);
}