#include "dllmain.h"

DLLFUNC var imgui_slider_int(char *label, int *v, int v_min, int v_max)
{
	bool res = ImGui::SliderInt(label, v, v_min, v_max);
	return res ? _VAR(1) : _VAR(0);
}

DLLFUNC var imgui_slider_float(char *label, float *v, float v_min, float v_max, char *format, float power)
{
	bool res = ImGui::SliderFloat(label, v, v_min, v_max, format, power);
	return res ? _VAR(1) : _VAR(0);
}

DLLFUNC var imgui_slider_angle(char *label, float *v_rad, float v_degrees_min, float v_degrees_max, char *format)
{
	bool res = ImGui::SliderAngle(label, v_rad, v_degrees_min, v_degrees_max, format);
	return res ? _VAR(1) : _VAR(0);
}

DLLFUNC var imgui_slider_var(char *label, var *v, var v_min, var v_max)
{
	float copy = _FLOAT(*v);
	bool res = ImGui::SliderFloat(label, &copy, _FLOAT(v_min), _FLOAT(v_max));
	*v = _VAR(copy);
	return res ? _VAR(1) : _VAR(0);
}

DLLFUNC var imgui_slider_angle_var(char *label, var *v_rad, var v_degrees_min, var v_degrees_max)
{
	float copy = _FLOAT(*v_rad);
	bool res = ImGui::SliderAngle(label, &copy, _FLOAT(v_degrees_min), _FLOAT(v_degrees_max));
	*v_rad = _VAR(copy);
	return res ? _VAR(1) : _VAR(0);
}

DLLFUNC var imgui_slider_int2(char *label, int *v, int v_min, int v_max)
{
	bool res = ImGui::SliderInt2(label, v, v_min, v_max);
	return res ? _VAR(1) : _VAR(0);
}

DLLFUNC var imgui_slider_int3(char *label, int *v, int v_min, int v_max)
{
	bool res = ImGui::SliderInt3(label, v, v_min, v_max);
	return res ? _VAR(1) : _VAR(0);
}

DLLFUNC var imgui_slider_int4(char *label, int *v, int v_min, int v_max)
{
	bool res = ImGui::SliderInt4(label, v, v_min, v_max);
	return res ? _VAR(1) : _VAR(0);
}

DLLFUNC var imgui_slider_float2(char *label, float *v, float v_min, float v_max, char *format, float power)
{
	bool res = ImGui::SliderFloat2(label, v, v_min, v_max, format, power);
	return res ? _VAR(1) : _VAR(0);
}

DLLFUNC var imgui_slider_float3(char *label, float *v, float v_min, float v_max, char *format, float power)
{
	bool res = ImGui::SliderFloat3(label, v, v_min, v_max, format, power);
	return res ? _VAR(1) : _VAR(0);
}

DLLFUNC var imgui_slider_float4(char *label, float *v, float v_min, float v_max, char *format, float power)
{
	bool res = ImGui::SliderFloat4(label, v, v_min, v_max, format, power);
	return res ? _VAR(1) : _VAR(0);
}

DLLFUNC var imgui_slider_var2(char *label, var *v, var v_min, var v_max)
{
	float copy[2] = {_FLOAT(v[0]), _FLOAT(v[1])};
	bool res = ImGui::SliderFloat2(label, copy, _FLOAT(v_min), _FLOAT(v_max));
	v[0] = _VAR(copy[0]);
	v[1] = _VAR(copy[1]);
	return res ? _VAR(1) : _VAR(0);
}

DLLFUNC var imgui_slider_var3(char *label, var *v, var v_min, var v_max)
{
	float copy[3] = {_FLOAT(v[0]), _FLOAT(v[1]), _FLOAT(v[2])};
	bool res = ImGui::SliderFloat3(label, copy, _FLOAT(v_min), _FLOAT(v_max));
	v[0] = _VAR(copy[0]);
	v[1] = _VAR(copy[1]);
	v[2] = _VAR(copy[2]);
	return res ? _VAR(1) : _VAR(0);
}

DLLFUNC var imgui_slider_var4(char *label, var *v, var v_min, var v_max)
{
	float copy[4] = {_FLOAT(v[0]), _FLOAT(v[1]), _FLOAT(v[2]), _FLOAT(v[3])};
	bool res = ImGui::SliderFloat4(label, copy, _FLOAT(v_min), _FLOAT(v_max));
	v[0] = _VAR(copy[0]);
	v[1] = _VAR(copy[1]);
	v[2] = _VAR(copy[2]);
	v[3] = _VAR(copy[3]);
	return res ? _VAR(1) : _VAR(0);
}

DLLFUNC var imgui_slider_vector(char *label, VECTOR *v, var v_min, var v_max)
{
	float copy[3] = {_FLOAT(v->x), _FLOAT(v->y), _FLOAT(v->z)};
	bool res = ImGui::SliderFloat3(label, copy, _FLOAT(v_min), _FLOAT(v_max));
	v->x = _VAR(copy[0]);
	v->y = _VAR(copy[1]);
	v->z = _VAR(copy[2]);
	return res ? _VAR(1) : _VAR(0);
}