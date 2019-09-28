#include "dllmain.h"

DLLFUNC var imgui_input_text(char *label, char *buffer, int buffer_size, long flags)
{
	bool res = ImGui::InputText(label, buffer, buffer_size, flags);
	return res ? _VAR(1) : _VAR(0);
}

DLLFUNC var imgui_input_text_with_hint(char *label, char *hint, char *buf, int buf_size, long flags)
{
	bool res = ImGui::InputTextWithHint(label, hint, buf, buf_size, flags);
	return res ? _VAR(1) : _VAR(0);
}

DLLFUNC var imgui_input_text_multiline(char *label, char *buf, int buf_size, int width, int height, long flags)
{
	bool res = ImGui::InputTextMultiline(label, buf, buf_size, ImVec2((float)width, (float)height), flags);
	return res ? _VAR(1) : _VAR(0);
}

DLLFUNC var imgui_input_double(char *label, double *v, double step, double step_fast, char *format, long flags)
{
	bool res = ImGui::InputDouble(label, v, step, step_fast, format, flags);
	return res ? _VAR(1) : _VAR(0);
}

DLLFUNC var imgui_input_int(char *label, int *v, int step, int step_fast, long flags)
{
	bool res = ImGui::InputInt(label, v, step, step_fast, flags);
	return res ? _VAR(1) : _VAR(0);
}

DLLFUNC var imgui_input_float(char *label, float *v, float step, float step_fast, int decimal_precision, long flags)
{
	bool res = ImGui::InputFloat(label, v, step, step_fast, decimal_precision, flags);
	return res ? _VAR(1) : _VAR(0);
}

DLLFUNC var imgui_input_float_format(char *label, float *v, float step, float step_fast, char *format, long flags)
{
	bool res = ImGui::InputFloat(label, v, step, step_fast, format, flags);
	return res ? _VAR(1) : _VAR(0);
}

DLLFUNC var imgui_input_var(char *label, var *v, var step, var step_fast, long flags)
{
	float copy = _FLOAT(*v);
	bool res = ImGui::InputFloat(label, &copy, _FLOAT(step), _FLOAT(step_fast), 3, flags);
	*v = _VAR(copy);
	return res ? _VAR(1) : _VAR(0);
}

DLLFUNC var imgui_input_int2(char *label, int *v, long flags)
{
	bool res = ImGui::InputInt2(label, v, flags);
	return res ? _VAR(1) : _VAR(0);
}

DLLFUNC var imgui_input_int3(char *label, int *v, long flags)
{
	bool res = ImGui::InputInt3(label, v, flags);
	return res ? _VAR(1) : _VAR(0);
}

DLLFUNC var imgui_input_int4(char *label, int *v, long flags)
{
	bool res = ImGui::InputInt4(label, v, flags);
	return res ? _VAR(1) : _VAR(0);
}

DLLFUNC var imgui_input_float2(char *label, float *v, int decimal_precision, long flags)
{
	bool res = ImGui::InputFloat2(label, v, decimal_precision, flags);
	return res ? _VAR(1) : _VAR(0);
}

DLLFUNC var imgui_input_float3(char *label, float *v, int decimal_precision, long flags)
{
	bool res = ImGui::InputFloat3(label, v, decimal_precision, flags);
	return res ? _VAR(1) : _VAR(0);
}

DLLFUNC var imgui_input_float4(char *label, float *v, int decimal_precision, long flags)
{
	bool res = ImGui::InputFloat4(label, v, decimal_precision, flags);
	return res ? _VAR(1) : _VAR(0);
}

DLLFUNC var imgui_input_var2(char *label, var *v, int decimal_precision, long flags)
{
	float copy[2] = { _FLOAT(v[0]), _FLOAT(v[1]) };
	bool res = ImGui::InputFloat2(label, copy, decimal_precision, flags);
	return res ? _VAR(1) : _VAR(0);
}

DLLFUNC var imgui_input_var3(char *label, var *v, int decimal_precision, long flags)
{
	float copy[3] = { _FLOAT(v[0]), _FLOAT(v[1]), _FLOAT(v[2]) };
	bool res = ImGui::InputFloat3(label, copy, decimal_precision, flags);
	v[0] = _VAR(copy[0]);
	v[1] = _VAR(copy[1]);
	v[2] = _VAR(copy[2]);
	return res ? _VAR(1) : _VAR(0);
}

DLLFUNC var imgui_input_var4(char *label, var *v, int decimal_precision, long flags)
{
	float copy[4] = { _FLOAT(v[0]), _FLOAT(v[1]), _FLOAT(v[2]), _FLOAT(v[3]) };
	bool res = ImGui::InputFloat4(label, copy, decimal_precision, flags);
	v[0] = _VAR(copy[0]);
	v[1] = _VAR(copy[1]);
	v[2] = _VAR(copy[2]);
	v[3] = _VAR(copy[3]);
	return res ? _VAR(1) : _VAR(0);
}

DLLFUNC var imgui_input_vector(char *label, VECTOR *v, int decimal_precision, long flags)
{
	float copy[3] = { _FLOAT(v->x), _FLOAT(v->y), _FLOAT(v->z) };
	bool res = ImGui::InputFloat3(label, copy, decimal_precision, flags);
	v->x = _VAR(copy[0]);
	v->y = _VAR(copy[1]);
	v->z = _VAR(copy[2]);
	return res ? _VAR(1) : _VAR(0);
}

DLLFUNC var imgui_drag_int(char *label, int *v, float v_speed, int v_min, int v_max, char *format)
{
	bool res = ImGui::DragInt(label, v, v_speed, v_min, v_max, format);
	return res ? _VAR(1) : _VAR(0);
}

DLLFUNC var imgui_drag_float(char *label, float *v, float v_speed, float v_min, float v_max, char *format, float power)
{
	bool res = ImGui::DragFloat(label, v, v_speed, v_min, v_max, format, power);
	return res ? _VAR(1) : _VAR(0);
}


DLLFUNC var imgui_drag_float4(char *label, float *v, float v_speed, float v_min, float v_max, char *format, float power)
{
	bool res = ImGui::DragFloat4(label, v, v_speed, v_min, v_max, format, power);
	return res ? _VAR(1) : _VAR(0);
}

DLLFUNC int imgui_drag_float_range2(char *label, float *v_current_min, float *v_current_max, var v_speed, var v_min, var v_max, char* format, char *format_max, var power)
{
	bool res = ImGui::DragFloatRange2(label, v_current_min, v_current_max, _FLOAT(v_speed), _FLOAT(v_min), _FLOAT(v_max), format, format_max, _FLOAT(power));
	return res ? 1 : 0;
}

DLLFUNC int imgui_drag_int_range2(char *label, int *v_current_min, int *v_current_max, var v_speed, var v_min, var v_max, char* format, char *format_max)
{
	bool res = ImGui::DragIntRange2(label, v_current_min, v_current_max, _FLOAT(v_speed), _INT(v_min), _INT(v_max), format, format_max);
	return res ? 1 : 0;
}