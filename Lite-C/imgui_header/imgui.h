#ifndef IMGUI_H
#define IMGUI_H

#include "imgui_methods.h"
#include "imgui_enums.h"

typedef struct IMGUIVtbl
{
    var Button(void *This, char *label);
    var ButtonColor(void *This, char *label, VECTOR *normal, VECTOR *hover, VECTOR *pushed);
    var ButtonImg(void *This, char *label, BMAP *input, var width, var height);
    var ButtonImgParams(void *This, char *label, BMAP *input, var width, var height, var u1, var v1, var u2, var v2, var padding, COLOR4 *background, COLOR4 *tint);
    var Checkbox(void *This, char *label, void *state);
    var CheckboxFlag(void *This, char *label, long *flags, long flag);
    var Radiobutton(void *This, char *label, int *result_pointer, int value);
    void PushButtonRepeat(void *This, int value);
    void PopButtonRepeat(void *This);
    var ArrowButton(void *This, char *str_id, long dir);
    var InvisibleButton(void *This, char *str_id, VECTOR *size);
    var RadioButton(void *This, char *label, int* v, int v_button);
    var SmallButton(void *This, char *label);
    var ImageButton(void *This, BMAP *input, VECTOR *size, VECTOR *uv0, VECTOR *uv1, int frame_padding, VECTOR* bg_col, var bg_alpha, VECTOR *tint_color, var tint_alpha );
    var ImageButtonTexId(void *This, void *my_tex_id, VECTOR *size, VECTOR *uv0, VECTOR *uv1, int frame_padding, VECTOR* bg_col, var bg_alpha, VECTOR *tint_color, var tint_alpha );
    var ColorEdit3(void *This, char *label, float *col, long flags);
    var ColorEdit4(void *This, char *label, float *col, long flags);
    void ShowMetricsWindow(void *This, int *p_open);
    void ShowStyleEditor(void *This);
    void ShowUserGuide(void *This);
    void ShowAboutWindow(void *This, int *p_open);
    int ColorButton(void *This, char *desc_id, float *col, int flags, VECTOR *size);
    int ColorPicker4(void *This, char *label, float *col, int flags, float *ref_col);
    void SetColorEditOptions(void *This, int flags);
    void* GetWindowDrawList(void *This);
    void DrawlistAddLine(void *This, void *draw_list, var xa, var ya, var xb, var yb, COLOR4 *color, var thickness);
    void DrawlistChannelSplit(void *This, void *draw_list, int channels_count);
    void DrawlistChannelSetCurrent(void *This, void *draw_list, int channel_index);
    void DrawlistAddBezierCurve(void *This, void *draw_list, VECTOR *pos0, VECTOR *cp0, VECTOR *cp1, VECTOR *pos1, VECTOR *color, var thickness, int num_segments);
    void DrawlistChannelMerge(void *This, void *draw_list);
    void DrawlistAddRectFilled(void *This, void *draw_list, VECTOR *a, VECTOR *b, VECTOR *color, var rounding);
    void DrawlistAddRect(void *This, void *draw_list, VECTOR *a, VECTOR *b, VECTOR *color, var rounding);
    void DrawlistAddCircleFilled(void *This, void *draw_list, VECTOR* center, var radius, VECTOR *color);
    void DrawlistAddTriangleFilled(void *This, void *draw_list, VECTOR *a, VECTOR *b, VECTOR *c, COLOR4 *color);
    void DrawlistAddTriangle(void *This, void *draw_list, VECTOR *a, VECTOR *b, VECTOR *c, COLOR4 *color);
    void DrawlistAddText(void *This, void *draw_list, VECTOR *pos, COLOR4 *color, char *text_begin);
    void DrawlistAddPolygon(void *This, void *draw_list, POINT **points, int num_points, COLOR4 *col, int closed, var thickness);
    void DrawlistAddImage(void *This, void *draw_list, BMAP *input, VECTOR *a, VECTOR *b, VECTOR *uv_a, VECTOR *uv_b, VECTOR *tint_color, var tint_alpha);
    var CollapsingHeader(void *This, char *label, void *p_open, long flags);
    void TreePop(void *This);
    void BeginGroup(void *This);
    void EndGroup(void *This);
    var TreeNode(void *This, char *label);
    var Treenode(void *This, void *ptr_id, char *fmt);
    var GetTreeNodeToLabelSpacing(void *This);
    int TreeNodeEx(void *This, void *ptr_id, int flags, char *fmt);
    int BeginDragDropTarget(void *This);
    void EndDragDropTarget(void *This);
    void* AcceptDragDropPayload(void *This, char *type, int flags);
    void* DragDropPayloadData(void *This, void *pl);
    int BeginTabbar(void *This, char* str_id, long flags);
    void EndTabbar(void *This);
    int BeginTabitem(void *This, char* label,void* state,long flags);
    void EndTabitem(void *This);
    void Image(void *This, BMAP *input);
    void ImageScale(void *This, BMAP *input, VECTOR *size, VECTOR *uv_start, VECTOR *uv_end);
    void ImageScaleColor(void *This, BMAP *input, VECTOR *size, VECTOR *uv_start, VECTOR *uv_end, VECTOR* tint_color, var tint_alpha, VECTOR *border_col, var border_alpha);
    void ImageScaleColorTexId(void *This, void *my_tex_id, VECTOR *size, VECTOR *uv_start, VECTOR *uv_end, VECTOR* tint_color, var tint_alpha, VECTOR *border_col, var border_alpha);
    var InputText(void *This, char *label, char *buffer, int buffer_size, long flags);
    var InputTextWithHint(void *This, char *label, char *hint, char *buf, int buf_size, long flags);
    var InputTextMultiline(void *This, char *label, char *buf, int buf_size, int width, int height, long flags);
    var InputDouble(void *This, char *label, double *v, double step, double step_fast, char *format, long flags);
    var InputInt(void *This, char *label, int *v, int step, int step_fast, long flags);
    var InputFloat(void *This, char *label, float *v, float step, float step_fast, int decimal_precision, long flags);
    var InputFloatFormat(void *This, char *label, float *v, float step, float step_fast, char *format, long flags);
    var InputVar(void *This, char *label, var *v, var step, var step_fast, long flags);
    var InputInt2(void *This, char *label, int *v, long flags);
    var InputInt3(void *This, char *label, int *v, long flags);
    var InputInt4(void *This, char *label, int *v, long flags);
    var InputFloat2(void *This, char *label, float *v, int decimal_precision, long flags);
    var InputFloat3(void *This, char *label, float *v, int decimal_precision, long flags);
    var InputFloat4(void *This, char *label, float *v, int decimal_precision, long flags);
    var InputVar2(void *This, char *label, var *v, int decimal_precision, long flags);
    var InputVar3(void *This, char *label, var *v, int decimal_precision, long flags);
    var InputVar4(void *This, char *label, var *v, int decimal_precision, long flags);
    var InputVector(void *This, char *label, VECTOR *v, int decimal_precision, long flags);
    var DragInt(void *This, char *label, int *v, float v_speed, int v_min, int v_max, char *format);
    var DragFloat(void *This, char *label, float *v, float v_speed, float v_min, float v_max, char *format, float power);
    var DragFloat4(void *This, char *label, float *v, float v_speed, float v_min, float v_max, char *format, float power);
    int DragFloatRange2(void *This, char *label, float *v_current_min, float *v_current_max, var v_speed, var v_min, var v_max, char* format, char *format_max, var power);
    int DragIntRange2(void *This, char *label, int *v_current_min, int *v_current_max, var v_speed, var v_min, var v_max, char* format, char *format_max);
    var FontAllowUserScaling(void *This);
    void Indent(void *This, var indent_w);
    void Unindent(void *This, var indent_w);
    var GetFontSize(void *This);
    void PushItemWidth(void *This, var item_width);
    void SameLine(void *This);
    void SameLineParams(void *This, var local_pos_x, var spacing_w);
    void PushStyleColor(void *This, long type, COLOR4 *color);
    void PushStyleColorHsv(void *This, int type, float h, float s, float v, float a);
    void PopStyleColor(void *This, int count);
    void AlignTextToFramePadding(void *This);
    void Separator(void *This);
    void PushStyleVar(void *This, int idx, var val);
    void PushStyleVec(void *This, int idx, VECTOR *val);
    void PopStyleVar(void *This, int count);
    void Columns(void *This, int count, char *id, int border);
    void NextColumn(void *This);
    void PopItemWidth(void *This);
    void SetColumnOffset(void *This, int column_index, var offset_x);
    void SetColumnWidth(void *This, int column_index, var width);
    void Spacing(void *This);
    VECTOR* GetStyleItemInnerSpacing(void *This);
    VECTOR* GetStyleItemSpacing(void *This);
    VECTOR* GetItemRectMin(void *This);
    VECTOR* GetItemRectMax(void *This);
    void NewLine(void *This);
    var ListboxHeader(void *This, char *label, int items_count, int height_in_items);
    void ListboxFooter(void *This);
    int Selectable(void *This, char *label, int *p_selected, int flags);
    var SelectableDirect(void *This, char *label, int p_selected);
    var SelectableSimple(void *This, char *label);
    int SelectableSize(void *This, char *label, int *p_selected, int flags, VECTOR *size);
    var Combo(void *This, char *label, int* current_item, char *items_separated_by_zeros, int popup_max_height_in_items);
    var BeginCombo(void *This, char *label, char *preview_value, long flags);
    void EndCombo(void *This);
    var ListBox(void *This, char *label, int *current_item, char **items, int items_count, int height_in_items);
    void ExtStrcpy(void *This, char *dest, char* source);
    void StartImode(void *This);
    void EndImode(void *This);
    var BeginMenuBar(void *This);
    void EndMenuBar(void *This);
    var BeginMenu(void *This, char *label, int enabled);
    void EndMenu(void *This);
    var MenuItem(void *This, char *label, char *shortcut, int selected, int enabled);
    void PlotLines(void *This, char *label, float *values, int values_count, float values_offset, char *overlay_text, float scale_min, float scale_max, VECTOR *graph_size);
    void Plotlines(void *This, char *label, float *values, int values_count);
    void PlotHistogram(void *This, char *label, float *values, int values_count, int values_offset, char *overlay_text, float scale_min, float scale_max, VECTOR *graph_size, int stride);
    void ProgressBar(void *This, var fraction, VECTOR *size_arg, char *overlay);
    var BeginPopupModals(void *This, char *name);
    var BeginPopupModalsParams(void *This, char *name, void *p_open, long flags);
    void CloseCurrentPopup(void *This);
    var BeginPopup(void *This, char *label, long flags);
    void EndPopup(void *This);
    var BeginPopupContextItem(void *This, char *label);
    void OpenPopup(void *This, char *str_id);
    VECTOR* GetMousePosOnOpeningCurrentPopup(void *This);
    var SliderInt(void *This, char *label, int *v, int v_min, int v_max);
    var SliderFloat(void *This, char *label, float *v, float v_min, float v_max, char *format, float power);
    var SliderAngle(void *This, char *label, float *v_rad, float v_degrees_min, float v_degrees_max, char *format);
    var SliderVar(void *This, char *label, var *v, var v_min, var v_max);
    var SliderAngleVar(void *This, char *label, var *v_rad, var v_degrees_min, var v_degrees_max);
    var SliderInt2(void *This, char *label, int *v, int v_min, int v_max);
    var SliderInt3(void *This, char *label, int *v, int v_min, int v_max);
    var SliderInt4(void *This, char *label, int *v, int v_min, int v_max);
    var SliderFloat2(void *This, char *label, float *v, float v_min, float v_max, char *format, float power);
    var SliderFloat3(void *This, char *label, float *v, float v_min, float v_max, char *format, float power);
    var SliderFloat4(void *This, char *label, float *v, float v_min, float v_max, char *format, float power);
    var SliderVar2(void *This, char *label, var *v, var v_min, var v_max);
    var SliderVar3(void *This, char *label, var *v, var v_min, var v_max);
    var SliderVar4(void *This, char *label, var *v, var v_min, var v_max);
    var SliderVector(void *This, char *label, VECTOR *v, var v_min, var v_max);
    var IsItemActive(void *This);
    var IsAnytimeActive(void *This);
    VECTOR* GetItemRectSize(void *This);
    int IsItemHovered(void *This);
    void PushId(void *This, var id);
    void PopId(void *This);
    var IsMouseClicked(void *This, var btn);
    VECTOR* GetCursorScreenPos(void *This);
    void SetCursorScreenPos(void *This, VECTOR *pos);
    var IsAnyItemActive(void *This);
    VECTOR* GetIoMouseDelta(void *This);
    var IsMouseDragging(void *This, int btn, var lock_threshold);
    var IsWindowHovered(void *This);
    var IsAnyItemHoverd(void *This);
    var IsMouseHoveringWindow(void *This);
    int* GetIoConfigFlags(void *This);
    var GetTime(void *This);
    var IsKeyPressed(void *This, int user_key_index, int repeat);
    int GetKeyIndex(void *This, int imgui_key);
    int* GetIoConfigInputTextCursorBlink(void *This);
    int* GetIoConfigWindowsResizeFromEdges(void *This);
    int* GetIoConfigWindowsMoveFromTitleBarOnly(void *This);
    int* GetIoMouseDrawCursor(void *This);
    int* GetIoBackendFlags(void *This);
    void LogButtons(void *This);
    void LogToClipboard(void *This);
    void LogText(void *This, char *fmt);
    void LogFinish(void *This);
    var IsItemClicked(void *This, int mouse_button);
    int GetIoKeyCtrl(void *This);
    var GetTextLineHeight(void *This);
    VECTOR* GetCursorPos(void *This);
    void* GetIoFontsTexId(void *This);
    int GetIoFontsTexWidth(void *This);
    int GetIoFontsTexHeight(void *This);
    VECTOR* GetIoMousePos(void *This);
    void SetItemDefaultFocus(void *This);
    int IsMouseDoubleClicked(void *This, int button);
    var GetIoDeltaTime(void *This);
    void ColorConvertHSVtoRGB(void *This, var h, var s, var v, var *out_r, var *out_g, var *out_b);
    void Text(void *This, char *fmt);
    void TextDisabled(void *This, char *fmt);
    void PushTextWrapPos(void *This, var wrap_local_pos_x);
    void PopTextWrapPos(void *This);
    void TextUnformatted(void *This, char *text);
    void BulletText(void *This, char *fmt);
    void TextWrapped(void *This, char *fmt);
    void LabelText(void *This, char *label, char *fmt);
    void Bullet(void *This);
    void TextColored(void *This, var r, var g, var b, var a, char* fmt);
    void SetTooltip(void *This, char *tooltip);
    void BeginTooltip(void *This);
    void EndTooltip(void *This);
    void SetNextWindowPos(void *This, var x, var y, long condition);
    void SetNextWindowSize(void *This, var width, var height, long condition);
    var GetWindowWidth(void *This);
    var GetWindowHeight(void *This);
    var GetWindowX(void *This);
    var GetWindowY(void *This);
    var Begin(void *This, char *name, void *p_close, long flags);
    void End(void *This);
    var GetFrameHeightWithSpacing(void *This);
    void BeginChild(void *This, char *id, VECTOR *size, int border, long flags);
    void EndChild(void *This);
    var GetContentRegionAvailWidth(void *This);
    VECTOR* GetWindowSize(void *This);
}IMGUIVtbl;

typedef interface IMGUI { IMGUIVtbl *lpVtbl; } IMGUI;

var imgui_Button(IMGUI *This, char *label);
var imgui_ButtonColor(IMGUI *This, char *label, VECTOR *normal, VECTOR *hover, VECTOR *pushed);
var imgui_ButtonImg(IMGUI *This, char *label, BMAP *input, var width, var height);
var imgui_ButtonImgParams(IMGUI *This, char *label, BMAP *input, var width, var height, var u1, var v1, var u2, var v2, var padding, COLOR4 *background, COLOR4 *tint);
var imgui_Checkbox(IMGUI *This, char *label, void *state);
var imgui_CheckboxFlag(IMGUI *This, char *label, long *flags, long flag);
var imgui_Radiobutton(IMGUI *This, char *label, int *result_pointer, int value);
void imgui_PushButtonRepeat(IMGUI *This, int value);
void imgui_PopButtonRepeat(IMGUI *This);
var imgui_ArrowButton(IMGUI *This, char *str_id, long dir);
var imgui_InvisibleButton(IMGUI *This, char *str_id, VECTOR *size);
var imgui_RadioButton(IMGUI *This, char *label, int* v, int v_button);
var imgui_SmallButton(IMGUI *This, char *label);
var imgui_ImageButton(IMGUI *This, BMAP *input, VECTOR *size, VECTOR *uv0, VECTOR *uv1, int frame_padding, VECTOR* bg_col, var bg_alpha, VECTOR *tint_color, var tint_alpha );
var imgui_ImageButtonTexId(IMGUI *This, void *my_tex_id, VECTOR *size, VECTOR *uv0, VECTOR *uv1, int frame_padding, VECTOR* bg_col, var bg_alpha, VECTOR *tint_color, var tint_alpha );
var imgui_ColorEdit3(IMGUI *This, char *label, float *col, long flags);
var imgui_ColorEdit4(IMGUI *This, char *label, float *col, long flags);
void imgui_ShowMetricsWindow(IMGUI *This, int *p_open);
void imgui_ShowStyleEditor(IMGUI *This);
void imgui_ShowUserGuide(IMGUI *This);
void imgui_ShowAboutWindow(IMGUI *This, int *p_open);
int imgui_ColorButton(IMGUI *This, char *desc_id, float *col, int flags, VECTOR *size);
int imgui_ColorPicker4(IMGUI *This, char *label, float *col, int flags, float *ref_col);
void imgui_SetColorEditOptions(IMGUI *This, int flags);
void* imgui_GetWindowDrawList(IMGUI *This);
void imgui_DrawlistAddLine(IMGUI *This, void *draw_list, var xa, var ya, var xb, var yb, COLOR4 *color, var thickness);
void imgui_DrawlistChannelSplit(IMGUI *This, void *draw_list, int channels_count);
void imgui_DrawlistChannelSetCurrent(IMGUI *This, void *draw_list, int channel_index);
void imgui_DrawlistAddBezierCurve(IMGUI *This, void *draw_list, VECTOR *pos0, VECTOR *cp0, VECTOR *cp1, VECTOR *pos1, VECTOR *color, var thickness, int num_segments);
void imgui_DrawlistChannelMerge(IMGUI *This, void *draw_list);
void imgui_DrawlistAddRectFilled(IMGUI *This, void *draw_list, VECTOR *a, VECTOR *b, VECTOR *color, var rounding);
void imgui_DrawlistAddRect(IMGUI *This, void *draw_list, VECTOR *a, VECTOR *b, VECTOR *color, var rounding);
void imgui_DrawlistAddCircleFilled(IMGUI *This, void *draw_list, VECTOR* center, var radius, VECTOR *color);
void imgui_DrawlistAddTriangleFilled(IMGUI *This, void *draw_list, VECTOR *a, VECTOR *b, VECTOR *c, COLOR4 *color);
void imgui_DrawlistAddTriangle(IMGUI *This, void *draw_list, VECTOR *a, VECTOR *b, VECTOR *c, COLOR4 *color);
void imgui_DrawlistAddText(IMGUI *This, void *draw_list, VECTOR *pos, COLOR4 *color, char *text_begin);
void imgui_DrawlistAddPolygon(IMGUI *This, void *draw_list, POINT **points, int num_points, COLOR4 *col, int closed, var thickness);
void imgui_DrawlistAddImage(IMGUI *This, void *draw_list, BMAP *input, VECTOR *a, VECTOR *b, VECTOR *uv_a, VECTOR *uv_b, VECTOR *tint_color, var tint_alpha);
var imgui_CollapsingHeader(IMGUI *This, char *label, void *p_open, long flags);
void imgui_TreePop(IMGUI *This);
void imgui_BeginGroup(IMGUI *This);
void imgui_EndGroup(IMGUI *This);
var imgui_TreeNode(IMGUI *This, char *label);
var imgui_Treenode(IMGUI *This, void *ptr_id, char *fmt);
var imgui_GetTreeNodeToLabelSpacing(IMGUI *This);
int imgui_TreeNodeEx(IMGUI *This, void *ptr_id, int flags, char *fmt);
int imgui_BeginDragDropTarget(IMGUI *This);
void imgui_EndDragDropTarget(IMGUI *This);
void* imgui_AcceptDragDropPayload(IMGUI *This, char *type, int flags);
void* imgui_DragDropPayloadData(IMGUI *This, void *pl);
int imgui_BeginTabbar(IMGUI *This, char* str_id, long flags);
void imgui_EndTabbar(IMGUI *This);
int imgui_BeginTabitem(IMGUI *This, char* label,void* state,long flags);
void imgui_EndTabitem(IMGUI *This);
void imgui_Image(IMGUI *This, BMAP *input);
void imgui_ImageScale(IMGUI *This, BMAP *input, VECTOR *size, VECTOR *uv_start, VECTOR *uv_end);
void imgui_ImageScaleColor(IMGUI *This, BMAP *input, VECTOR *size, VECTOR *uv_start, VECTOR *uv_end, VECTOR* tint_color, var tint_alpha, VECTOR *border_col, var border_alpha);
void imgui_ImageScaleColorTexId(IMGUI *This, void *my_tex_id, VECTOR *size, VECTOR *uv_start, VECTOR *uv_end, VECTOR* tint_color, var tint_alpha, VECTOR *border_col, var border_alpha);
var imgui_InputText(IMGUI *This, char *label, char *buffer, int buffer_size, long flags);
var imgui_InputTextWithHint(IMGUI *This, char *label, char *hint, char *buf, int buf_size, long flags);
var imgui_InputTextMultiline(IMGUI *This, char *label, char *buf, int buf_size, int width, int height, long flags);
var imgui_InputDouble(IMGUI *This, char *label, double *v, double step, double step_fast, char *format, long flags);
var imgui_InputInt(IMGUI *This, char *label, int *v, int step, int step_fast, long flags);
var imgui_InputFloat(IMGUI *This, char *label, float *v, float step, float step_fast, int decimal_precision, long flags);
var imgui_InputFloatFormat(IMGUI *This, char *label, float *v, float step, float step_fast, char *format, long flags);
var imgui_InputVar(IMGUI *This, char *label, var *v, var step, var step_fast, long flags);
var imgui_InputInt2(IMGUI *This, char *label, int *v, long flags);
var imgui_InputInt3(IMGUI *This, char *label, int *v, long flags);
var imgui_InputInt4(IMGUI *This, char *label, int *v, long flags);
var imgui_InputFloat2(IMGUI *This, char *label, float *v, int decimal_precision, long flags);
var imgui_InputFloat3(IMGUI *This, char *label, float *v, int decimal_precision, long flags);
var imgui_InputFloat4(IMGUI *This, char *label, float *v, int decimal_precision, long flags);
var imgui_InputVar2(IMGUI *This, char *label, var *v, int decimal_precision, long flags);
var imgui_InputVar3(IMGUI *This, char *label, var *v, int decimal_precision, long flags);
var imgui_InputVar4(IMGUI *This, char *label, var *v, int decimal_precision, long flags);
var imgui_InputVector(IMGUI *This, char *label, VECTOR *v, int decimal_precision, long flags);
var imgui_DragInt(IMGUI *This, char *label, int *v, float v_speed, int v_min, int v_max, char *format);
var imgui_DragFloat(IMGUI *This, char *label, float *v, float v_speed, float v_min, float v_max, char *format, float power);
var imgui_DragFloat4(IMGUI *This, char *label, float *v, float v_speed, float v_min, float v_max, char *format, float power);
int imgui_DragFloatRange2(IMGUI *This, char *label, float *v_current_min, float *v_current_max, var v_speed, var v_min, var v_max, char* format, char *format_max, var power);
int imgui_DragIntRange2(IMGUI *This, char *label, int *v_current_min, int *v_current_max, var v_speed, var v_min, var v_max, char* format, char *format_max);
var imgui_FontAllowUserScaling(IMGUI *This);
void imgui_Indent(IMGUI *This, var indent_w);
void imgui_Unindent(IMGUI *This, var indent_w);
var imgui_GetFontSize(IMGUI *This);
void imgui_PushItemWidth(IMGUI *This, var item_width);
void imgui_SameLine(IMGUI *This);
void imgui_SameLineParams(IMGUI *This, var local_pos_x, var spacing_w);
void imgui_PushStyleColor(IMGUI *This, long type, COLOR4 *color);
void imgui_PushStyleColorHsv(IMGUI *This, int type, float h, float s, float v, float a);
void imgui_PopStyleColor(IMGUI *This, int count);
void imgui_AlignTextToFramePadding(IMGUI *This);
void imgui_Separator(IMGUI *This);
void imgui_PushStyleVar(IMGUI *This, int idx, var val);
void imgui_PushStyleVec(IMGUI *This, int idx, VECTOR *val);
void imgui_PopStyleVar(IMGUI *This, int count);
void imgui_Columns(IMGUI *This, int count, char *id, int border);
void imgui_NextColumn(IMGUI *This);
void imgui_PopItemWidth(IMGUI *This);
void imgui_SetColumnOffset(IMGUI *This, int column_index, var offset_x);
void imgui_SetColumnWidth(IMGUI *This, int column_index, var width);
void imgui_Spacing(IMGUI *This);
VECTOR* imgui_GetStyleItemInnerSpacing(IMGUI *This);
VECTOR* imgui_GetStyleItemSpacing(IMGUI *This);
VECTOR* imgui_GetItemRectMin(IMGUI *This);
VECTOR* imgui_GetItemRectMax(IMGUI *This);
void imgui_NewLine(IMGUI *This);
var imgui_ListboxHeader(IMGUI *This, char *label, int items_count, int height_in_items);
void imgui_ListboxFooter(IMGUI *This);
int imgui_Selectable(IMGUI *This, char *label, int *p_selected, int flags);
var imgui_SelectableDirect(IMGUI *This, char *label, int p_selected);
var imgui_SelectableSimple(IMGUI *This, char *label);
int imgui_SelectableSize(IMGUI *This, char *label, int *p_selected, int flags, VECTOR *size);
var imgui_Combo(IMGUI *This, char *label, int* current_item, char *items_separated_by_zeros, int popup_max_height_in_items);
var imgui_BeginCombo(IMGUI *This, char *label, char *preview_value, long flags);
void imgui_EndCombo(IMGUI *This);
var imgui_ListBox(IMGUI *This, char *label, int *current_item, char **items, int items_count, int height_in_items);
void imgui_ExtStrcpy(IMGUI *This, char *dest, char* source);
void imgui_StartImode(IMGUI *This);
void imgui_EndImode(IMGUI *This);
var imgui_BeginMenuBar(IMGUI *This);
void imgui_EndMenuBar(IMGUI *This);
var imgui_BeginMenu(IMGUI *This, char *label, int enabled);
void imgui_EndMenu(IMGUI *This);
var imgui_MenuItem(IMGUI *This, char *label, char *shortcut, int selected, int enabled);
void imgui_PlotLines(IMGUI *This, char *label, float *values, int values_count, float values_offset, char *overlay_text, float scale_min, float scale_max, VECTOR *graph_size);
void imgui_Plotlines(IMGUI *This, char *label, float *values, int values_count);
void imgui_PlotHistogram(IMGUI *This, char *label, float *values, int values_count, int values_offset, char *overlay_text, float scale_min, float scale_max, VECTOR *graph_size, int stride);
void imgui_ProgressBar(IMGUI *This, var fraction, VECTOR *size_arg, char *overlay);
var imgui_BeginPopupModals(IMGUI *This, char *name);
var imgui_BeginPopupModalsParams(IMGUI *This, char *name, void *p_open, long flags);
void imgui_CloseCurrentPopup(IMGUI *This);
var imgui_BeginPopup(IMGUI *This, char *label, long flags);
void imgui_EndPopup(IMGUI *This);
var imgui_BeginPopupContextItem(IMGUI *This, char *label);
void imgui_OpenPopup(IMGUI *This, char *str_id);
VECTOR* imgui_GetMousePosOnOpeningCurrentPopup(IMGUI *This);
var imgui_SliderInt(IMGUI *This, char *label, int *v, int v_min, int v_max);
var imgui_SliderFloat(IMGUI *This, char *label, float *v, float v_min, float v_max, char *format, float power);
var imgui_SliderAngle(IMGUI *This, char *label, float *v_rad, float v_degrees_min, float v_degrees_max, char *format);
var imgui_SliderVar(IMGUI *This, char *label, var *v, var v_min, var v_max);
var imgui_SliderAngleVar(IMGUI *This, char *label, var *v_rad, var v_degrees_min, var v_degrees_max);
var imgui_SliderInt2(IMGUI *This, char *label, int *v, int v_min, int v_max);
var imgui_SliderInt3(IMGUI *This, char *label, int *v, int v_min, int v_max);
var imgui_SliderInt4(IMGUI *This, char *label, int *v, int v_min, int v_max);
var imgui_SliderFloat2(IMGUI *This, char *label, float *v, float v_min, float v_max, char *format, float power);
var imgui_SliderFloat3(IMGUI *This, char *label, float *v, float v_min, float v_max, char *format, float power);
var imgui_SliderFloat4(IMGUI *This, char *label, float *v, float v_min, float v_max, char *format, float power);
var imgui_SliderVar2(IMGUI *This, char *label, var *v, var v_min, var v_max);
var imgui_SliderVar3(IMGUI *This, char *label, var *v, var v_min, var v_max);
var imgui_SliderVar4(IMGUI *This, char *label, var *v, var v_min, var v_max);
var imgui_SliderVector(IMGUI *This, char *label, VECTOR *v, var v_min, var v_max);
var imgui_IsItemActive(IMGUI *This);
var imgui_IsAnytimeActive(IMGUI *This);
VECTOR* imgui_GetItemRectSize(IMGUI *This);
int imgui_IsItemHovered(IMGUI *This);
void imgui_PushId(IMGUI *This, var id);
void imgui_PopId(IMGUI *This);
var imgui_IsMouseClicked(IMGUI *This, var btn);
VECTOR* imgui_GetCursorScreenPos(IMGUI *This);
void imgui_SetCursorScreenPos(IMGUI *This, VECTOR *pos);
var imgui_IsAnyItemActive(IMGUI *This);
VECTOR* imgui_GetIoMouseDelta(IMGUI *This);
var imgui_IsMouseDragging(IMGUI *This, int btn, var lock_threshold);
var imgui_IsWindowHovered(IMGUI *This);
var imgui_IsAnyItemHoverd(IMGUI *This);
var imgui_IsMouseHoveringWindow(IMGUI *This);
int* imgui_GetIoConfigFlags(IMGUI *This);
var imgui_GetTime(IMGUI *This);
var imgui_IsKeyPressed(IMGUI *This, int user_key_index, int repeat);
int imgui_GetKeyIndex(IMGUI *This, int imgui_key);
int* imgui_GetIoConfigInputTextCursorBlink(IMGUI *This);
int* imgui_GetIoConfigWindowsResizeFromEdges(IMGUI *This);
int* imgui_GetIoConfigWindowsMoveFromTitleBarOnly(IMGUI *This);
int* imgui_GetIoMouseDrawCursor(IMGUI *This);
int* imgui_GetIoBackendFlags(IMGUI *This);
void imgui_LogButtons(IMGUI *This);
void imgui_LogToClipboard(IMGUI *This);
void imgui_LogText(IMGUI *This, char *fmt);
void imgui_LogFinish(IMGUI *This);
var imgui_IsItemClicked(IMGUI *This, int mouse_button);
int imgui_GetIoKeyCtrl(IMGUI *This);
var imgui_GetTextLineHeight(IMGUI *This);
VECTOR* imgui_GetCursorPos(IMGUI *This);
void* imgui_GetIoFontsTexId(IMGUI *This);
int imgui_GetIoFontsTexWidth(IMGUI *This);
int imgui_GetIoFontsTexHeight(IMGUI *This);
VECTOR* imgui_GetIoMousePos(IMGUI *This);
void imgui_SetItemDefaultFocus(IMGUI *This);
int imgui_IsMouseDoubleClicked(IMGUI *This, int button);
var imgui_GetIoDeltaTime(IMGUI *This);
void imgui_ColorConvertHSVtoRGB(IMGUI *This, var h, var s, var v, var *out_r, var *out_g, var *out_b);
void imgui_Text(IMGUI *This, char *fmt);
void imgui_TextDisabled(IMGUI *This, char *fmt);
void imgui_PushTextWrapPos(IMGUI *This, var wrap_local_pos_x);
void imgui_PopTextWrapPos(IMGUI *This);
void imgui_TextUnformatted(IMGUI *This, char *text);
void imgui_BulletText(IMGUI *This, char *fmt);
void imgui_TextWrapped(IMGUI *This, char *fmt);
void imgui_LabelText(IMGUI *This, char *label, char *fmt);
void imgui_Bullet(IMGUI *This);
void imgui_TextColored(IMGUI *This, var r, var g, var b, var a, char* fmt);
void imgui_SetTooltip(IMGUI *This, char *tooltip);
void imgui_BeginTooltip(IMGUI *This);
void imgui_EndTooltip(IMGUI *This);
void imgui_SetNextWindowPos(IMGUI *This, var x, var y, long condition);
void imgui_SetNextWindowSize(IMGUI *This, var width, var height, long condition);
var imgui_GetWindowWidth(IMGUI *This);
var imgui_GetWindowHeight(IMGUI *This);
var imgui_GetWindowX(IMGUI *This);
var imgui_GetWindowY(IMGUI *This);
var imgui_Begin(IMGUI *This, char *name, void *p_close, long flags);
void imgui_End(IMGUI *This);
var imgui_GetFrameHeightWithSpacing(IMGUI *This);
void imgui_BeginChild(IMGUI *This, char *id, VECTOR *size, int border, long flags);
void imgui_EndChild(IMGUI *This);
var imgui_GetContentRegionAvailWidth(IMGUI *This);
VECTOR* imgui_GetWindowSize(IMGUI *This);

IMGUI *create_imgui_interface()
{
    IMGUI *imgui = sys_malloc(sizeof(IMGUI));
    imgui->lpVtbl = sys_malloc(sizeof(IMGUIVtbl));
    imgui->Button = imgui_Button;
    imgui->ButtonColor = imgui_ButtonColor;
    imgui->ButtonImg = imgui_ButtonImg;
    imgui->ButtonImgParams = imgui_ButtonImgParams;
    imgui->Checkbox = imgui_Checkbox;
    imgui->CheckboxFlag = imgui_CheckboxFlag;
    imgui->Radiobutton = imgui_Radiobutton;
    imgui->PushButtonRepeat = imgui_PushButtonRepeat;
    imgui->PopButtonRepeat = imgui_PopButtonRepeat;
    imgui->ArrowButton = imgui_ArrowButton;
    imgui->InvisibleButton = imgui_InvisibleButton;
    imgui->RadioButton = imgui_RadioButton;
    imgui->SmallButton = imgui_SmallButton;
    imgui->ImageButton = imgui_ImageButton;
    imgui->ImageButtonTexId = imgui_ImageButtonTexId;
    imgui->ColorEdit3 = imgui_ColorEdit3;
    imgui->ColorEdit4 = imgui_ColorEdit4;
    imgui->ShowMetricsWindow = imgui_ShowMetricsWindow;
    imgui->ShowStyleEditor = imgui_ShowStyleEditor;
    imgui->ShowUserGuide = imgui_ShowUserGuide;
    imgui->ShowAboutWindow = imgui_ShowAboutWindow;
    imgui->ColorButton = imgui_ColorButton;
    imgui->ColorPicker4 = imgui_ColorPicker4;
    imgui->SetColorEditOptions = imgui_SetColorEditOptions;
    imgui->GetWindowDrawList = imgui_GetWindowDrawList;
    imgui->DrawlistAddLine = imgui_DrawlistAddLine;
    imgui->DrawlistChannelSplit = imgui_DrawlistChannelSplit;
    imgui->DrawlistChannelSetCurrent = imgui_DrawlistChannelSetCurrent;
    imgui->DrawlistAddBezierCurve = imgui_DrawlistAddBezierCurve;
    imgui->DrawlistChannelMerge = imgui_DrawlistChannelMerge;
    imgui->DrawlistAddRectFilled = imgui_DrawlistAddRectFilled;
    imgui->DrawlistAddRect = imgui_DrawlistAddRect;
    imgui->DrawlistAddCircleFilled = imgui_DrawlistAddCircleFilled;
    imgui->DrawlistAddTriangleFilled = imgui_DrawlistAddTriangleFilled;
    imgui->DrawlistAddTriangle = imgui_DrawlistAddTriangle;
    imgui->DrawlistAddText = imgui_DrawlistAddText;
    imgui->DrawlistAddPolygon = imgui_DrawlistAddPolygon;
    imgui->DrawlistAddImage = imgui_DrawlistAddImage;
    imgui->CollapsingHeader = imgui_CollapsingHeader;
    imgui->TreePop = imgui_TreePop;
    imgui->BeginGroup = imgui_BeginGroup;
    imgui->EndGroup = imgui_EndGroup;
    imgui->TreeNode = imgui_TreeNode;
    imgui->Treenode = imgui_Treenode;
    imgui->GetTreeNodeToLabelSpacing = imgui_GetTreeNodeToLabelSpacing;
    imgui->TreeNodeEx = imgui_TreeNodeEx;
    imgui->BeginDragDropTarget = imgui_BeginDragDropTarget;
    imgui->EndDragDropTarget = imgui_EndDragDropTarget;
    imgui->AcceptDragDropPayload = imgui_AcceptDragDropPayload;
    imgui->DragDropPayloadData = imgui_DragDropPayloadData;
    imgui->BeginTabbar = imgui_BeginTabbar;
    imgui->EndTabbar = imgui_EndTabbar;
    imgui->BeginTabitem = imgui_BeginTabitem;
    imgui->EndTabitem = imgui_EndTabitem;
    imgui->Image = imgui_Image;
    imgui->ImageScale = imgui_ImageScale;
    imgui->ImageScaleColor = imgui_ImageScaleColor;
    imgui->ImageScaleColorTexId = imgui_ImageScaleColorTexId;
    imgui->InputText = imgui_InputText;
    imgui->InputTextWithHint = imgui_InputTextWithHint;
    imgui->InputTextMultiline = imgui_InputTextMultiline;
    imgui->InputDouble = imgui_InputDouble;
    imgui->InputInt = imgui_InputInt;
    imgui->InputFloat = imgui_InputFloat;
    imgui->InputFloatFormat = imgui_InputFloatFormat;
    imgui->InputVar = imgui_InputVar;
    imgui->InputInt2 = imgui_InputInt2;
    imgui->InputInt3 = imgui_InputInt3;
    imgui->InputInt4 = imgui_InputInt4;
    imgui->InputFloat2 = imgui_InputFloat2;
    imgui->InputFloat3 = imgui_InputFloat3;
    imgui->InputFloat4 = imgui_InputFloat4;
    imgui->InputVar2 = imgui_InputVar2;
    imgui->InputVar3 = imgui_InputVar3;
    imgui->InputVar4 = imgui_InputVar4;
    imgui->InputVector = imgui_InputVector;
    imgui->DragInt = imgui_DragInt;
    imgui->DragFloat = imgui_DragFloat;
    imgui->DragFloat4 = imgui_DragFloat4;
    imgui->DragFloatRange2 = imgui_DragFloatRange2;
    imgui->DragIntRange2 = imgui_DragIntRange2;
    imgui->FontAllowUserScaling = imgui_FontAllowUserScaling;
    imgui->Indent = imgui_Indent;
    imgui->Unindent = imgui_Unindent;
    imgui->GetFontSize = imgui_GetFontSize;
    imgui->PushItemWidth = imgui_PushItemWidth;
    imgui->SameLine = imgui_SameLine;
    imgui->SameLineParams = imgui_SameLineParams;
    imgui->PushStyleColor = imgui_PushStyleColor;
    imgui->PushStyleColorHsv = imgui_PushStyleColorHsv;
    imgui->PopStyleColor = imgui_PopStyleColor;
    imgui->AlignTextToFramePadding = imgui_AlignTextToFramePadding;
    imgui->Separator = imgui_Separator;
    imgui->PushStyleVar = imgui_PushStyleVar;
    imgui->PushStyleVec = imgui_PushStyleVec;
    imgui->PopStyleVar = imgui_PopStyleVar;
    imgui->Columns = imgui_Columns;
    imgui->NextColumn = imgui_NextColumn;
    imgui->PopItemWidth = imgui_PopItemWidth;
    imgui->SetColumnOffset = imgui_SetColumnOffset;
    imgui->SetColumnWidth = imgui_SetColumnWidth;
    imgui->Spacing = imgui_Spacing;
    imgui->GetStyleItemInnerSpacing = imgui_GetStyleItemInnerSpacing;
    imgui->GetStyleItemSpacing = imgui_GetStyleItemSpacing;
    imgui->GetItemRectMin = imgui_GetItemRectMin;
    imgui->GetItemRectMax = imgui_GetItemRectMax;
    imgui->NewLine = imgui_NewLine;
    imgui->ListboxHeader = imgui_ListboxHeader;
    imgui->ListboxFooter = imgui_ListboxFooter;
    imgui->Selectable = imgui_Selectable;
    imgui->SelectableDirect = imgui_SelectableDirect;
    imgui->SelectableSimple = imgui_SelectableSimple;
    imgui->SelectableSize = imgui_SelectableSize;
    imgui->Combo = imgui_Combo;
    imgui->BeginCombo = imgui_BeginCombo;
    imgui->EndCombo = imgui_EndCombo;
    imgui->ListBox = imgui_ListBox;
    imgui->ExtStrcpy = imgui_ExtStrcpy;
    imgui->StartImode = imgui_StartImode;
    imgui->EndImode = imgui_EndImode;
    imgui->BeginMenuBar = imgui_BeginMenuBar;
    imgui->EndMenuBar = imgui_EndMenuBar;
    imgui->BeginMenu = imgui_BeginMenu;
    imgui->EndMenu = imgui_EndMenu;
    imgui->MenuItem = imgui_MenuItem;
    imgui->PlotLines = imgui_PlotLines;
    imgui->Plotlines = imgui_Plotlines;
    imgui->PlotHistogram = imgui_PlotHistogram;
    imgui->ProgressBar = imgui_ProgressBar;
    imgui->BeginPopupModals = imgui_BeginPopupModals;
    imgui->BeginPopupModalsParams = imgui_BeginPopupModalsParams;
    imgui->CloseCurrentPopup = imgui_CloseCurrentPopup;
    imgui->BeginPopup = imgui_BeginPopup;
    imgui->EndPopup = imgui_EndPopup;
    imgui->BeginPopupContextItem = imgui_BeginPopupContextItem;
    imgui->OpenPopup = imgui_OpenPopup;
    imgui->GetMousePosOnOpeningCurrentPopup = imgui_GetMousePosOnOpeningCurrentPopup;
    imgui->SliderInt = imgui_SliderInt;
    imgui->SliderFloat = imgui_SliderFloat;
    imgui->SliderAngle = imgui_SliderAngle;
    imgui->SliderVar = imgui_SliderVar;
    imgui->SliderAngleVar = imgui_SliderAngleVar;
    imgui->SliderInt2 = imgui_SliderInt2;
    imgui->SliderInt3 = imgui_SliderInt3;
    imgui->SliderInt4 = imgui_SliderInt4;
    imgui->SliderFloat2 = imgui_SliderFloat2;
    imgui->SliderFloat3 = imgui_SliderFloat3;
    imgui->SliderFloat4 = imgui_SliderFloat4;
    imgui->SliderVar2 = imgui_SliderVar2;
    imgui->SliderVar3 = imgui_SliderVar3;
    imgui->SliderVar4 = imgui_SliderVar4;
    imgui->SliderVector = imgui_SliderVector;
    imgui->IsItemActive = imgui_IsItemActive;
    imgui->IsAnytimeActive = imgui_IsAnytimeActive;
    imgui->GetItemRectSize = imgui_GetItemRectSize;
    imgui->IsItemHovered = imgui_IsItemHovered;
    imgui->PushId = imgui_PushId;
    imgui->PopId = imgui_PopId;
    imgui->IsMouseClicked = imgui_IsMouseClicked;
    imgui->GetCursorScreenPos = imgui_GetCursorScreenPos;
    imgui->SetCursorScreenPos = imgui_SetCursorScreenPos;
    imgui->IsAnyItemActive = imgui_IsAnyItemActive;
    imgui->GetIoMouseDelta = imgui_GetIoMouseDelta;
    imgui->IsMouseDragging = imgui_IsMouseDragging;
    imgui->IsWindowHovered = imgui_IsWindowHovered;
    imgui->IsAnyItemHoverd = imgui_IsAnyItemHoverd;
    imgui->IsMouseHoveringWindow = imgui_IsMouseHoveringWindow;
    imgui->GetIoConfigFlags = imgui_GetIoConfigFlags;
    imgui->GetTime = imgui_GetTime;
    imgui->IsKeyPressed = imgui_IsKeyPressed;
    imgui->GetKeyIndex = imgui_GetKeyIndex;
    imgui->GetIoConfigInputTextCursorBlink = imgui_GetIoConfigInputTextCursorBlink;
    imgui->GetIoConfigWindowsResizeFromEdges = imgui_GetIoConfigWindowsResizeFromEdges;
    imgui->GetIoConfigWindowsMoveFromTitleBarOnly = imgui_GetIoConfigWindowsMoveFromTitleBarOnly;
    imgui->GetIoMouseDrawCursor = imgui_GetIoMouseDrawCursor;
    imgui->GetIoBackendFlags = imgui_GetIoBackendFlags;
    imgui->LogButtons = imgui_LogButtons;
    imgui->LogToClipboard = imgui_LogToClipboard;
    imgui->LogText = imgui_LogText;
    imgui->LogFinish = imgui_LogFinish;
    imgui->IsItemClicked = imgui_IsItemClicked;
    imgui->GetIoKeyCtrl = imgui_GetIoKeyCtrl;
    imgui->GetTextLineHeight = imgui_GetTextLineHeight;
    imgui->GetCursorPos = imgui_GetCursorPos;
    imgui->GetIoFontsTexId = imgui_GetIoFontsTexId;
    imgui->GetIoFontsTexWidth = imgui_GetIoFontsTexWidth;
    imgui->GetIoFontsTexHeight = imgui_GetIoFontsTexHeight;
    imgui->GetIoMousePos = imgui_GetIoMousePos;
    imgui->SetItemDefaultFocus = imgui_SetItemDefaultFocus;
    imgui->IsMouseDoubleClicked = imgui_IsMouseDoubleClicked;
    imgui->GetIoDeltaTime = imgui_GetIoDeltaTime;
    imgui->ColorConvertHSVtoRGB = imgui_ColorConvertHSVtoRGB;
    imgui->Text = imgui_Text;
    imgui->TextDisabled = imgui_TextDisabled;
    imgui->PushTextWrapPos = imgui_PushTextWrapPos;
    imgui->PopTextWrapPos = imgui_PopTextWrapPos;
    imgui->TextUnformatted = imgui_TextUnformatted;
    imgui->BulletText = imgui_BulletText;
    imgui->TextWrapped = imgui_TextWrapped;
    imgui->LabelText = imgui_LabelText;
    imgui->Bullet = imgui_Bullet;
    imgui->TextColored = imgui_TextColored;
    imgui->SetTooltip = imgui_SetTooltip;
    imgui->BeginTooltip = imgui_BeginTooltip;
    imgui->EndTooltip = imgui_EndTooltip;
    imgui->SetNextWindowPos = imgui_SetNextWindowPos;
    imgui->SetNextWindowSize = imgui_SetNextWindowSize;
    imgui->GetWindowWidth = imgui_GetWindowWidth;
    imgui->GetWindowHeight = imgui_GetWindowHeight;
    imgui->GetWindowX = imgui_GetWindowX;
    imgui->GetWindowY = imgui_GetWindowY;
    imgui->Begin = imgui_Begin;
    imgui->End = imgui_End;
    imgui->GetFrameHeightWithSpacing = imgui_GetFrameHeightWithSpacing;
    imgui->BeginChild = imgui_BeginChild;
    imgui->EndChild = imgui_EndChild;
    imgui->GetContentRegionAvailWidth = imgui_GetContentRegionAvailWidth;
    imgui->GetWindowSize = imgui_GetWindowSize;
    return imgui;
}

var imgui_Button(IMGUI *This, char *label)
{
    return imgui_button(label);
}

var imgui_ButtonColor(IMGUI *This, char *label, VECTOR *normal, VECTOR *hover, VECTOR *pushed)
{
    return imgui_button_color(label,normal,hover,pushed);
}

var imgui_ButtonImg(IMGUI *This, char *label, BMAP *input, var width, var height)
{
    return imgui_button_img(label,input,width,height);
}

var imgui_ButtonImgParams(IMGUI *This, char *label, BMAP *input, var width, var height, var u1, var v1, var u2, var v2, var padding, COLOR4 *background, COLOR4 *tint)
{
    return imgui_button_img_params(label,input,width,height,u1,v1,u2,v2,padding,background,tint);
}

var imgui_Checkbox(IMGUI *This, char *label, void *state)
{
    return imgui_checkbox(label,state);
}

var imgui_CheckboxFlag(IMGUI *This, char *label, long *flags, long flag)
{
    return imgui_checkbox_flag(label,flags,flag);
}

var imgui_Radiobutton(IMGUI *This, char *label, int *result_pointer, int value)
{
    return imgui_radiobutton(label,result_pointer,value);
}

void imgui_PushButtonRepeat(IMGUI *This, int value)
{
    imgui_push_button_repeat(value);
}

void imgui_PopButtonRepeat(IMGUI *This)
{
    imgui_pop_button_repeat();
}

var imgui_ArrowButton(IMGUI *This, char *str_id, long dir)
{
    return imgui_arrow_button(str_id,dir);
}

var imgui_InvisibleButton(IMGUI *This, char *str_id, VECTOR *size)
{
    return imgui_invisible_button(str_id,size);
}

var imgui_RadioButton(IMGUI *This, char *label, int* v, int v_button)
{
    return imgui_radio_button(label,v,v_button);
}

var imgui_SmallButton(IMGUI *This, char *label)
{
    return imgui_small_button(label);
}

var imgui_ImageButton(IMGUI *This, BMAP *input, VECTOR *size, VECTOR *uv0, VECTOR *uv1, int frame_padding, VECTOR* bg_col, var bg_alpha, VECTOR *tint_color, var tint_alpha )
{
    return imgui_image_button(input,size,uv0,uv1,frame_padding,bg_col,bg_alpha,tint_color,tint_alpha);
}

var imgui_ImageButtonTexId(IMGUI *This, void *my_tex_id, VECTOR *size, VECTOR *uv0, VECTOR *uv1, int frame_padding, VECTOR* bg_col, var bg_alpha, VECTOR *tint_color, var tint_alpha )
{
    return imgui_image_button_tex_id(my_tex_id,size,uv0,uv1,frame_padding,bg_col,bg_alpha,tint_color,tint_alpha);
}

var imgui_ColorEdit3(IMGUI *This, char *label, float *col, long flags)
{
    return imgui_color_edit3(label,col,flags);
}

var imgui_ColorEdit4(IMGUI *This, char *label, float *col, long flags)
{
    return imgui_color_edit4(label,col,flags);
}

void imgui_ShowMetricsWindow(IMGUI *This, int *p_open)
{
    imgui_show_metrics_window(p_open);
}

void imgui_ShowStyleEditor(IMGUI *This)
{
    imgui_show_style_editor();
}

void imgui_ShowUserGuide(IMGUI *This)
{
    imgui_show_user_guide();
}

void imgui_ShowAboutWindow(IMGUI *This, int *p_open)
{
    imgui_show_about_window(p_open);
}

int imgui_ColorButton(IMGUI *This, char *desc_id, float *col, int flags, VECTOR *size)
{
    return imgui_color_button(desc_id,col,flags,size);
}

int imgui_ColorPicker4(IMGUI *This, char *label, float *col, int flags, float *ref_col)
{
    return imgui_color_picker_4(label,col,flags,ref_col);
}

void imgui_SetColorEditOptions(IMGUI *This, int flags)
{
    imgui_set_color_edit_options(flags);
}

void* imgui_GetWindowDrawList(IMGUI *This)
{
    return imgui_get_window_draw_list();
}

void imgui_DrawlistAddLine(IMGUI *This, void *draw_list, var xa, var ya, var xb, var yb, COLOR4 *color, var thickness)
{
    imgui_drawlist_add_line(draw_list,xa,ya,xb,yb,color,thickness);
}

void imgui_DrawlistChannelSplit(IMGUI *This, void *draw_list, int channels_count)
{
    imgui_drawlist_channel_split(draw_list,channels_count);
}

void imgui_DrawlistChannelSetCurrent(IMGUI *This, void *draw_list, int channel_index)
{
    imgui_drawlist_channel_set_current(draw_list,channel_index);
}

void imgui_DrawlistAddBezierCurve(IMGUI *This, void *draw_list, VECTOR *pos0, VECTOR *cp0, VECTOR *cp1, VECTOR *pos1, VECTOR *color, var thickness, int num_segments)
{
    imgui_drawlist_add_bezier_curve(draw_list,pos0,cp0,cp1,pos1,color,thickness,num_segments);
}

void imgui_DrawlistChannelMerge(IMGUI *This, void *draw_list)
{
    imgui_drawlist_channel_merge(draw_list);
}

void imgui_DrawlistAddRectFilled(IMGUI *This, void *draw_list, VECTOR *a, VECTOR *b, VECTOR *color, var rounding)
{
    imgui_drawlist_add_rect_filled(draw_list,a,b,color,rounding);
}

void imgui_DrawlistAddRect(IMGUI *This, void *draw_list, VECTOR *a, VECTOR *b, VECTOR *color, var rounding)
{
    imgui_drawlist_add_rect(draw_list,a,b,color,rounding);
}

void imgui_DrawlistAddCircleFilled(IMGUI *This, void *draw_list, VECTOR* center, var radius, VECTOR *color)
{
    imgui_drawlist_add_circle_filled(draw_list,center,radius,color);
}

void imgui_DrawlistAddTriangleFilled(IMGUI *This, void *draw_list, VECTOR *a, VECTOR *b, VECTOR *c, COLOR4 *color)
{
    imgui_drawlist_add_triangle_filled(draw_list,a,b,c,color);
}

void imgui_DrawlistAddTriangle(IMGUI *This, void *draw_list, VECTOR *a, VECTOR *b, VECTOR *c, COLOR4 *color)
{
    imgui_drawlist_add_triangle(draw_list,a,b,c,color);
}

void imgui_DrawlistAddText(IMGUI *This, void *draw_list, VECTOR *pos, COLOR4 *color, char *text_begin)
{
    imgui_drawlist_add_text(draw_list,pos,color,text_begin);
}

void imgui_DrawlistAddPolygon(IMGUI *This, void *draw_list, POINT **points, int num_points, COLOR4 *col, int closed, var thickness)
{
    imgui_drawlist_add_polygon(draw_list,points,num_points,col,closed,thickness);
}

void imgui_DrawlistAddImage(IMGUI *This, void *draw_list, BMAP *input, VECTOR *a, VECTOR *b, VECTOR *uv_a, VECTOR *uv_b, VECTOR *tint_color, var tint_alpha)
{
    imgui_drawlist_add_image(draw_list,input,a,b,uv_a,uv_b,tint_color,tint_alpha);
}

var imgui_CollapsingHeader(IMGUI *This, char *label, void *p_open, long flags)
{
    return imgui_collapsing_header(label,p_open,flags);
}

void imgui_TreePop(IMGUI *This)
{
    imgui_tree_pop();
}

void imgui_BeginGroup(IMGUI *This)
{
    imgui_begin_group();
}

void imgui_EndGroup(IMGUI *This)
{
    imgui_end_group();
}

var imgui_TreeNode(IMGUI *This, char *label)
{
    return imgui_tree_node(label);
}

var imgui_Treenode(IMGUI *This, void *ptr_id, char *fmt)
{
    return imgui_treenode(ptr_id,fmt);
}

var imgui_GetTreeNodeToLabelSpacing(IMGUI *This)
{
    return imgui_get_tree_node_to_label_spacing();
}

int imgui_TreeNodeEx(IMGUI *This, void *ptr_id, int flags, char *fmt)
{
    return imgui_tree_node_ex(ptr_id,flags,fmt);
}

int imgui_BeginDragDropTarget(IMGUI *This)
{
    return imgui_begin_drag_drop_target();
}

void imgui_EndDragDropTarget(IMGUI *This)
{
    imgui_end_drag_drop_target();
}

void* imgui_AcceptDragDropPayload(IMGUI *This, char *type, int flags)
{
    return imgui_accept_drag_drop_payload(type,flags);
}

void* imgui_DragDropPayloadData(IMGUI *This, void *pl)
{
    return imgui_drag_drop_payload_data(pl);
}

int imgui_BeginTabbar(IMGUI *This, char* str_id, long flags)
{
    return imgui_begin_tabbar(str_id,flags);
}

void imgui_EndTabbar(IMGUI *This)
{
    imgui_end_tabbar();
}

int imgui_BeginTabitem(IMGUI *This, char* label,void* state,long flags)
{
    return imgui_begin_tabitem(label,state,flags);
}

void imgui_EndTabitem(IMGUI *This)
{
    imgui_end_tabitem();
}

void imgui_Image(IMGUI *This, BMAP *input)
{
    imgui_image(input);
}

void imgui_ImageScale(IMGUI *This, BMAP *input, VECTOR *size, VECTOR *uv_start, VECTOR *uv_end)
{
    imgui_image_scale(input,size,uv_start,uv_end);
}

void imgui_ImageScaleColor(IMGUI *This, BMAP *input, VECTOR *size, VECTOR *uv_start, VECTOR *uv_end, VECTOR* tint_color, var tint_alpha, VECTOR *border_col, var border_alpha)
{
    imgui_image_scale_color(input,size,uv_start,uv_end,tint_color,tint_alpha,border_col,border_alpha);
}

void imgui_ImageScaleColorTexId(IMGUI *This, void *my_tex_id, VECTOR *size, VECTOR *uv_start, VECTOR *uv_end, VECTOR* tint_color, var tint_alpha, VECTOR *border_col, var border_alpha)
{
    imgui_image_scale_color_tex_id(my_tex_id,size,uv_start,uv_end,tint_color,tint_alpha,border_col,border_alpha);
}

var imgui_InputText(IMGUI *This, char *label, char *buffer, int buffer_size, long flags)
{
    return imgui_input_text(label,buffer,buffer_size,flags);
}

var imgui_InputTextWithHint(IMGUI *This, char *label, char *hint, char *buf, int buf_size, long flags)
{
    return imgui_input_text_with_hint(label,hint,buf,buf_size,flags);
}

var imgui_InputTextMultiline(IMGUI *This, char *label, char *buf, int buf_size, int width, int height, long flags)
{
    return imgui_input_text_multiline(label,buf,buf_size,width,height,flags);
}

var imgui_InputDouble(IMGUI *This, char *label, double *v, double step, double step_fast, char *format, long flags)
{
    return imgui_input_double(label,v,step,step_fast,format,flags);
}

var imgui_InputInt(IMGUI *This, char *label, int *v, int step, int step_fast, long flags)
{
    return imgui_input_int(label,v,step,step_fast,flags);
}

var imgui_InputFloat(IMGUI *This, char *label, float *v, float step, float step_fast, int decimal_precision, long flags)
{
    return imgui_input_float(label,v,step,step_fast,decimal_precision,flags);
}

var imgui_InputFloatFormat(IMGUI *This, char *label, float *v, float step, float step_fast, char *format, long flags)
{
    return imgui_input_float_format(label,v,step,step_fast,format,flags);
}

var imgui_InputVar(IMGUI *This, char *label, var *v, var step, var step_fast, long flags)
{
    return imgui_input_var(label,v,step,step_fast,flags);
}

var imgui_InputInt2(IMGUI *This, char *label, int *v, long flags)
{
    return imgui_input_int2(label,v,flags);
}

var imgui_InputInt3(IMGUI *This, char *label, int *v, long flags)
{
    return imgui_input_int3(label,v,flags);
}

var imgui_InputInt4(IMGUI *This, char *label, int *v, long flags)
{
    return imgui_input_int4(label,v,flags);
}

var imgui_InputFloat2(IMGUI *This, char *label, float *v, int decimal_precision, long flags)
{
    return imgui_input_float2(label,v,decimal_precision,flags);
}

var imgui_InputFloat3(IMGUI *This, char *label, float *v, int decimal_precision, long flags)
{
    return imgui_input_float3(label,v,decimal_precision,flags);
}

var imgui_InputFloat4(IMGUI *This, char *label, float *v, int decimal_precision, long flags)
{
    return imgui_input_float4(label,v,decimal_precision,flags);
}

var imgui_InputVar2(IMGUI *This, char *label, var *v, int decimal_precision, long flags)
{
    return imgui_input_var2(label,v,decimal_precision,flags);
}

var imgui_InputVar3(IMGUI *This, char *label, var *v, int decimal_precision, long flags)
{
    return imgui_input_var3(label,v,decimal_precision,flags);
}

var imgui_InputVar4(IMGUI *This, char *label, var *v, int decimal_precision, long flags)
{
    return imgui_input_var4(label,v,decimal_precision,flags);
}

var imgui_InputVector(IMGUI *This, char *label, VECTOR *v, int decimal_precision, long flags)
{
    return imgui_input_vector(label,v,decimal_precision,flags);
}

var imgui_DragInt(IMGUI *This, char *label, int *v, float v_speed, int v_min, int v_max, char *format)
{
    return imgui_drag_int(label,v,v_speed,v_min,v_max,format);
}

var imgui_DragFloat(IMGUI *This, char *label, float *v, float v_speed, float v_min, float v_max, char *format, float power)
{
    return imgui_drag_float(label,v,v_speed,v_min,v_max,format,power);
}

var imgui_DragFloat4(IMGUI *This, char *label, float *v, float v_speed, float v_min, float v_max, char *format, float power)
{
    return imgui_drag_float4(label,v,v_speed,v_min,v_max,format,power);
}

int imgui_DragFloatRange2(IMGUI *This, char *label, float *v_current_min, float *v_current_max, var v_speed, var v_min, var v_max, char* format, char *format_max, var power)
{
    return imgui_drag_float_range2(label,v_current_min,v_current_max,v_speed,v_min,v_max,format,format_max,power);
}

int imgui_DragIntRange2(IMGUI *This, char *label, int *v_current_min, int *v_current_max, var v_speed, var v_min, var v_max, char* format, char *format_max)
{
    return imgui_drag_int_range2(label,v_current_min,v_current_max,v_speed,v_min,v_max,format,format_max);
}

var imgui_FontAllowUserScaling(IMGUI *This)
{
    return imgui_font_allow_user_scaling();
}

void imgui_Indent(IMGUI *This, var indent_w)
{
    imgui_indent(indent_w);
}

void imgui_Unindent(IMGUI *This, var indent_w)
{
    imgui_unindent(indent_w);
}

var imgui_GetFontSize(IMGUI *This)
{
    return imgui_get_font_size();
}

void imgui_PushItemWidth(IMGUI *This, var item_width)
{
    imgui_push_item_width(item_width);
}

void imgui_SameLine(IMGUI *This)
{
    imgui_same_line();
}

void imgui_SameLineParams(IMGUI *This, var local_pos_x, var spacing_w)
{
    imgui_same_line_params(local_pos_x,spacing_w);
}

void imgui_PushStyleColor(IMGUI *This, long type, COLOR4 *color)
{
    imgui_push_style_color(type,color);
}

void imgui_PushStyleColorHsv(IMGUI *This, int type, float h, float s, float v, float a)
{
    imgui_push_style_color_hsv(type,h,s,v,a);
}

void imgui_PopStyleColor(IMGUI *This, int count)
{
    imgui_pop_style_color(count);
}

void imgui_AlignTextToFramePadding(IMGUI *This)
{
    imgui_align_text_to_frame_padding();
}

void imgui_Separator(IMGUI *This)
{
    imgui_separator();
}

void imgui_PushStyleVar(IMGUI *This, int idx, var val)
{
    imgui_push_style_var(idx,val);
}

void imgui_PushStyleVec(IMGUI *This, int idx, VECTOR *val)
{
    imgui_push_style_vec(idx,val);
}

void imgui_PopStyleVar(IMGUI *This, int count)
{
    imgui_pop_style_var(count);
}

void imgui_Columns(IMGUI *This, int count, char *id, int border)
{
    imgui_columns(count,id,border);
}

void imgui_NextColumn(IMGUI *This)
{
    imgui_next_column();
}

void imgui_PopItemWidth(IMGUI *This)
{
    imgui_pop_item_width();
}

void imgui_SetColumnOffset(IMGUI *This, int column_index, var offset_x)
{
    imgui_set_column_offset(column_index,offset_x);
}

void imgui_SetColumnWidth(IMGUI *This, int column_index, var width)
{
    imgui_set_column_width(column_index,width);
}

void imgui_Spacing(IMGUI *This)
{
    imgui_spacing();
}

VECTOR* imgui_GetStyleItemInnerSpacing(IMGUI *This)
{
    return imgui_get_style_item_inner_spacing();
}

VECTOR* imgui_GetStyleItemSpacing(IMGUI *This)
{
    return imgui_get_style_item_spacing();
}

VECTOR* imgui_GetItemRectMin(IMGUI *This)
{
    return imgui_get_item_rect_min();
}

VECTOR* imgui_GetItemRectMax(IMGUI *This)
{
    return imgui_get_item_rect_max();
}

void imgui_NewLine(IMGUI *This)
{
    imgui_new_line();
}

var imgui_ListboxHeader(IMGUI *This, char *label, int items_count, int height_in_items)
{
    return imgui_listbox_header(label,items_count,height_in_items);
}

void imgui_ListboxFooter(IMGUI *This)
{
    imgui_listbox_footer();
}

int imgui_Selectable(IMGUI *This, char *label, int *p_selected, int flags)
{
    return imgui_selectable(label,p_selected,flags);
}

var imgui_SelectableDirect(IMGUI *This, char *label, int p_selected)
{
    return imgui_selectable_direct(label,p_selected);
}

var imgui_SelectableSimple(IMGUI *This, char *label)
{
    return imgui_selectable_simple(label);
}

int imgui_SelectableSize(IMGUI *This, char *label, int *p_selected, int flags, VECTOR *size)
{
    return imgui_selectable_size(label,p_selected,flags,size);
}

var imgui_Combo(IMGUI *This, char *label, int* current_item, char *items_separated_by_zeros, int popup_max_height_in_items)
{
    return imgui_combo(label,current_item,items_separated_by_zeros,popup_max_height_in_items);
}

var imgui_BeginCombo(IMGUI *This, char *label, char *preview_value, long flags)
{
    return imgui_begin_combo(label,preview_value,flags);
}

void imgui_EndCombo(IMGUI *This)
{
    imgui_end_combo();
}

var imgui_ListBox(IMGUI *This, char *label, int *current_item, char **items, int items_count, int height_in_items)
{
    return imgui_list_box(label,current_item,items,items_count,height_in_items);
}

void imgui_ExtStrcpy(IMGUI *This, char *dest, char* source)
{
    imgui_ext_strcpy(dest,source);
}

void imgui_StartImode(IMGUI *This)
{
    imgui_start_imode();
}

void imgui_EndImode(IMGUI *This)
{
    imgui_end_imode();
}

var imgui_BeginMenuBar(IMGUI *This)
{
    return imgui_begin_menu_bar();
}

void imgui_EndMenuBar(IMGUI *This)
{
    imgui_end_menu_bar();
}

var imgui_BeginMenu(IMGUI *This, char *label, int enabled)
{
    return imgui_begin_menu(label,enabled);
}

void imgui_EndMenu(IMGUI *This)
{
    imgui_end_menu();
}

var imgui_MenuItem(IMGUI *This, char *label, char *shortcut, int selected, int enabled)
{
    return imgui_menu_item(label,shortcut,selected,enabled);
}

void imgui_PlotLines(IMGUI *This, char *label, float *values, int values_count, float values_offset, char *overlay_text, float scale_min, float scale_max, VECTOR *graph_size)
{
    imgui_plot_lines(label,values,values_count,values_offset,overlay_text,scale_min,scale_max,graph_size);
}

void imgui_Plotlines(IMGUI *This, char *label, float *values, int values_count)
{
    imgui_plotlines(label,values,values_count);
}

void imgui_PlotHistogram(IMGUI *This, char *label, float *values, int values_count, int values_offset, char *overlay_text, float scale_min, float scale_max, VECTOR *graph_size, int stride)
{
    imgui_plot_histogram(label,values,values_count,values_offset,overlay_text,scale_min,scale_max,graph_size,stride);
}

void imgui_ProgressBar(IMGUI *This, var fraction, VECTOR *size_arg, char *overlay)
{
    imgui_progress_bar(fraction,size_arg,overlay);
}

var imgui_BeginPopupModals(IMGUI *This, char *name)
{
    return imgui_begin_popup_modals(name);
}

var imgui_BeginPopupModalsParams(IMGUI *This, char *name, void *p_open, long flags)
{
    return imgui_begin_popup_modals_params(name,p_open,flags);
}

void imgui_CloseCurrentPopup(IMGUI *This)
{
    imgui_close_current_popup();
}

var imgui_BeginPopup(IMGUI *This, char *label, long flags)
{
    return imgui_begin_popup(label,flags);
}

void imgui_EndPopup(IMGUI *This)
{
    imgui_end_popup();
}

var imgui_BeginPopupContextItem(IMGUI *This, char *label)
{
    return imgui_begin_popup_context_item(label);
}

void imgui_OpenPopup(IMGUI *This, char *str_id)
{
    imgui_open_popup(str_id);
}

VECTOR* imgui_GetMousePosOnOpeningCurrentPopup(IMGUI *This)
{
    return imgui_get_mouse_pos_on_opening_current_popup();
}

var imgui_SliderInt(IMGUI *This, char *label, int *v, int v_min, int v_max)
{
    return imgui_slider_int(label,v,v_min,v_max);
}

var imgui_SliderFloat(IMGUI *This, char *label, float *v, float v_min, float v_max, char *format, float power)
{
    return imgui_slider_float(label,v,v_min,v_max,format,power);
}

var imgui_SliderAngle(IMGUI *This, char *label, float *v_rad, float v_degrees_min, float v_degrees_max, char *format)
{
    return imgui_slider_angle(label,v_rad,v_degrees_min,v_degrees_max,format);
}

var imgui_SliderVar(IMGUI *This, char *label, var *v, var v_min, var v_max)
{
    return imgui_slider_var(label,v,v_min,v_max);
}

var imgui_SliderAngleVar(IMGUI *This, char *label, var *v_rad, var v_degrees_min, var v_degrees_max)
{
    return imgui_slider_angle_var(label,v_rad,v_degrees_min,v_degrees_max);
}

var imgui_SliderInt2(IMGUI *This, char *label, int *v, int v_min, int v_max)
{
    return imgui_slider_int2(label,v,v_min,v_max);
}

var imgui_SliderInt3(IMGUI *This, char *label, int *v, int v_min, int v_max)
{
    return imgui_slider_int3(label,v,v_min,v_max);
}

var imgui_SliderInt4(IMGUI *This, char *label, int *v, int v_min, int v_max)
{
    return imgui_slider_int4(label,v,v_min,v_max);
}

var imgui_SliderFloat2(IMGUI *This, char *label, float *v, float v_min, float v_max, char *format, float power)
{
    return imgui_slider_float2(label,v,v_min,v_max,format,power);
}

var imgui_SliderFloat3(IMGUI *This, char *label, float *v, float v_min, float v_max, char *format, float power)
{
    return imgui_slider_float3(label,v,v_min,v_max,format,power);
}

var imgui_SliderFloat4(IMGUI *This, char *label, float *v, float v_min, float v_max, char *format, float power)
{
    return imgui_slider_float4(label,v,v_min,v_max,format,power);
}

var imgui_SliderVar2(IMGUI *This, char *label, var *v, var v_min, var v_max)
{
    return imgui_slider_var2(label,v,v_min,v_max);
}

var imgui_SliderVar3(IMGUI *This, char *label, var *v, var v_min, var v_max)
{
    return imgui_slider_var3(label,v,v_min,v_max);
}

var imgui_SliderVar4(IMGUI *This, char *label, var *v, var v_min, var v_max)
{
    return imgui_slider_var4(label,v,v_min,v_max);
}

var imgui_SliderVector(IMGUI *This, char *label, VECTOR *v, var v_min, var v_max)
{
    return imgui_slider_vector(label,v,v_min,v_max);
}

var imgui_IsItemActive(IMGUI *This)
{
    return imgui_is_item_active();
}

var imgui_IsAnytimeActive(IMGUI *This)
{
    return imgui_is_anytime_active();
}

VECTOR* imgui_GetItemRectSize(IMGUI *This)
{
    return imgui_get_item_rect_size();
}

int imgui_IsItemHovered(IMGUI *This)
{
    return imgui_is_item_hovered();
}

void imgui_PushId(IMGUI *This, var id)
{
    imgui_push_id(id);
}

void imgui_PopId(IMGUI *This)
{
    imgui_pop_id();
}

var imgui_IsMouseClicked(IMGUI *This, var btn)
{
    return imgui_is_mouse_clicked(btn);
}

VECTOR* imgui_GetCursorScreenPos(IMGUI *This)
{
    return imgui_get_cursor_screen_pos();
}

void imgui_SetCursorScreenPos(IMGUI *This, VECTOR *pos)
{
    imgui_set_cursor_screen_pos(pos);
}

var imgui_IsAnyItemActive(IMGUI *This)
{
    return imgui_is_any_item_active();
}

VECTOR* imgui_GetIoMouseDelta(IMGUI *This)
{
    return imgui_get_io_mouse_delta();
}

var imgui_IsMouseDragging(IMGUI *This, int btn, var lock_threshold)
{
    return imgui_is_mouse_dragging(btn,lock_threshold);
}

var imgui_IsWindowHovered(IMGUI *This)
{
    return imgui_is_window_hovered();
}

var imgui_IsAnyItemHoverd(IMGUI *This)
{
    return imgui_is_any_item_hoverd();
}

var imgui_IsMouseHoveringWindow(IMGUI *This)
{
    return imgui_is_mouse_hovering_window();
}

int* imgui_GetIoConfigFlags(IMGUI *This)
{
    return imgui_get_io_config_flags();
}

var imgui_GetTime(IMGUI *This)
{
    return imgui_get_time();
}

var imgui_IsKeyPressed(IMGUI *This, int user_key_index, int repeat)
{
    return imgui_is_key_pressed(user_key_index,repeat);
}

int imgui_GetKeyIndex(IMGUI *This, int imgui_key)
{
    return imgui_get_key_index(imgui_key);
}

int* imgui_GetIoConfigInputTextCursorBlink(IMGUI *This)
{
    return imgui_get_io_config_input_text_cursor_blink();
}

int* imgui_GetIoConfigWindowsResizeFromEdges(IMGUI *This)
{
    return imgui_get_io_config_windows_resize_from_edges();
}

int* imgui_GetIoConfigWindowsMoveFromTitleBarOnly(IMGUI *This)
{
    return imgui_get_io_config_windows_move_from_title_bar_only();
}

int* imgui_GetIoMouseDrawCursor(IMGUI *This)
{
    return imgui_get_io_mouse_draw_cursor();
}

int* imgui_GetIoBackendFlags(IMGUI *This)
{
    return imgui_get_io_backend_flags();
}

void imgui_LogButtons(IMGUI *This)
{
    imgui_log_buttons();
}

void imgui_LogToClipboard(IMGUI *This)
{
    imgui_log_to_clipboard();
}

void imgui_LogText(IMGUI *This, char *fmt)
{
    imgui_log_text(fmt);
}

void imgui_LogFinish(IMGUI *This)
{
    imgui_log_finish();
}

var imgui_IsItemClicked(IMGUI *This, int mouse_button)
{
    return imgui_is_item_clicked(mouse_button);
}

int imgui_GetIoKeyCtrl(IMGUI *This)
{
    return imgui_get_io_key_ctrl();
}

var imgui_GetTextLineHeight(IMGUI *This)
{
    return imgui_get_text_line_height();
}

VECTOR* imgui_GetCursorPos(IMGUI *This)
{
    return imgui_get_cursor_pos();
}

void* imgui_GetIoFontsTexId(IMGUI *This)
{
    return imgui_get_io_fonts_tex_id();
}

int imgui_GetIoFontsTexWidth(IMGUI *This)
{
    return imgui_get_io_fonts_tex_width();
}

int imgui_GetIoFontsTexHeight(IMGUI *This)
{
    return imgui_get_io_fonts_tex_height();
}

VECTOR* imgui_GetIoMousePos(IMGUI *This)
{
    return imgui_get_io_mouse_pos();
}

void imgui_SetItemDefaultFocus(IMGUI *This)
{
    imgui_set_item_default_focus();
}

int imgui_IsMouseDoubleClicked(IMGUI *This, int button)
{
    return imgui_is_mouse_double_clicked(button);
}

var imgui_GetIoDeltaTime(IMGUI *This)
{
    return imgui_get_io_delta_time();
}

void imgui_ColorConvertHSVtoRGB(IMGUI *This, var h, var s, var v, var *out_r, var *out_g, var *out_b)
{
    imgui_color_convert_HSVto_RGB(h,s,v,out_r,out_g,out_b);
}

void imgui_Text(IMGUI *This, char *fmt)
{
    imgui_text(fmt);
}

void imgui_TextDisabled(IMGUI *This, char *fmt)
{
    imgui_text_disabled(fmt);
}

void imgui_PushTextWrapPos(IMGUI *This, var wrap_local_pos_x)
{
    imgui_push_text_wrap_pos(wrap_local_pos_x);
}

void imgui_PopTextWrapPos(IMGUI *This)
{
    imgui_pop_text_wrap_pos();
}

void imgui_TextUnformatted(IMGUI *This, char *text)
{
    imgui_text_unformatted(text);
}

void imgui_BulletText(IMGUI *This, char *fmt)
{
    imgui_bullet_text(fmt);
}

void imgui_TextWrapped(IMGUI *This, char *fmt)
{
    imgui_text_wrapped(fmt);
}

void imgui_LabelText(IMGUI *This, char *label, char *fmt)
{
    imgui_label_text(label,fmt);
}

void imgui_Bullet(IMGUI *This)
{
    imgui_bullet();
}

void imgui_TextColored(IMGUI *This, var r, var g, var b, var a, char* fmt)
{
    imgui_text_colored(r,g,b,a,fmt);
}

void imgui_SetTooltip(IMGUI *This, char *tooltip)
{
    imgui_set_tooltip(tooltip);
}

void imgui_BeginTooltip(IMGUI *This)
{
    imgui_begin_tooltip();
}

void imgui_EndTooltip(IMGUI *This)
{
    imgui_end_tooltip();
}

void imgui_SetNextWindowPos(IMGUI *This, var x, var y, long condition)
{
    imgui_set_next_window_pos(x,y,condition);
}

void imgui_SetNextWindowSize(IMGUI *This, var width, var height, long condition)
{
    imgui_set_next_window_size(width,height,condition);
}

var imgui_GetWindowWidth(IMGUI *This)
{
    return imgui_get_window_width();
}

var imgui_GetWindowHeight(IMGUI *This)
{
    return imgui_get_window_height();
}

var imgui_GetWindowX(IMGUI *This)
{
    return imgui_get_window_x();
}

var imgui_GetWindowY(IMGUI *This)
{
    return imgui_get_window_y();
}

var imgui_Begin(IMGUI *This, char *name, void *p_close, long flags)
{
    return imgui_begin(name,p_close,flags);
}

void imgui_End(IMGUI *This)
{
    imgui_end();
}

var imgui_GetFrameHeightWithSpacing(IMGUI *This)
{
    return imgui_get_frame_height_with_spacing();
}

void imgui_BeginChild(IMGUI *This, char *id, VECTOR *size, int border, long flags)
{
    imgui_begin_child(id,size,border,flags);
}

void imgui_EndChild(IMGUI *This)
{
    imgui_end_child();
}

var imgui_GetContentRegionAvailWidth(IMGUI *This)
{
    return imgui_get_content_region_avail_width();
}

VECTOR* imgui_GetWindowSize(IMGUI *This)
{
    return imgui_get_window_size();
}

#endif