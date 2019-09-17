// Acknex specific
void imgui_init(long config_flags);
void imgui_reset();
void imgui_start_imode();
void imgui_end_imode();
long custom_scan_message(UINT message, WPARAM wParam, LPARAM lParam);
void ext_strcpy(char *dest, const char* source);

// General
var imgui_get_font_size();
void imgui_push_item_width(var item_width);
void imgui_same_line();
void imgui_same_line_params(var local_pos_x, var spacing_w);
void imgui_push_id(var id);
void imgui_pop_id();
void imgui_push_style_color(long type, COLOR4 *color);
void imgui_pop_style_color(int count);
void imgui_align_text_to_frame_padding();
var imgui_is_item_hovered();
void imgui_set_tooltip(char *tooltip);
void imgui_begin_tooltip();
void imgui_end_tooltip();
void imgui_push_style_var(int idx, var val);
void imgui_push_style_vec(int idx, VECTOR *val);
void imgui_pop_style_var(int count);
var imgui_get_frame_height_with_spacing();
void imgui_pop_item_width();
var imgui_get_content_region_avail_width();
var imgui_is_mouse_clicked(var btn);
VECTOR* imgui_get_cursor_screen_pos();
void* imgui_get_window_drawlist();
VECTOR* imgui_get_window_size();
void imgui_drawlist_add_line(void *draw_list, var xa, var ya, var xb, var yb, COLOR4 *color, var thickness);
void imgui_drawlist_channel_split(void *draw_list, int channels_count);
void imgui_drawlist_channel_set_current(void *draw_list, int channel_index);
void imgui_drawlist_add_bezier_curve(void *draw_list, VECTOR *pos0, VECTOR *cp0, VECTOR *cp1, VECTOR *pos1, VECTOR *color, var thickness, int num_segments);
void imgui_Drawlist_channel_merge(void *draw_list);
var imgui_is_anytime_active();
void imgui_set_cursor_screen_pos(VECTOR *pos);
VECTOR* imgui_get_item_rect_size();
var imgui_invisible_button(char *str_id, VECTOR *size);
var imgui_is_item_active();
VECTOR* imgui_get_io_mouse_delta();
var imgui_is_mouse_dragging(int btn, var lock_threshold);
void imgui_drawlist_add_rect_filled(void *draw_list, VECTOR *a, VECTOR *b, VECTOR *color, var rounding);
void imgui_drawlist_add_rect(void *draw_list, VECTOR *a, VECTOR *b, VECTOR *color, var rounding);
void imgui_drawlist_add_circle_filled(void *draw_list, VECTOR* center, var radius, VECTOR *color);
var imgui_is_window_hovered();
var imgui_is_any_item_active();
void imgui_drawlist_add_triangle_filled(void *draw_list, VECTOR *a, VECTOR *b, VECTOR *c, COLOR4 *color);
void imgui_drawlist_add_triangle(void *draw_list, VECTOR *a, VECTOR *b, VECTOR *c, COLOR4 *color);
void imgui_drawlist_add_text(void *draw_list, VECTOR *pos, COLOR4 *color, char *text_begin);
var imgui_is_any_item_hoverd();
var imgui_is_mouse_hovering_window();
void imgui_open_popup(char *str_id);
var imgui_begin_popup_modals(char *name);
void imgui_close_current_popup();
var imgui_begin_popup_modals_params(char *name, void *p_open, long flags);

// Window
void imgui_set_next_window_pos(var x, var y, long condition);
void imgui_set_next_window_size(var width, var height, long condition);
var imgui_get_window_width();
var imgui_get_window_height();
var imgui_get_window_x();
var imgui_get_window_y();
var imgui_begin(char *name, void *p_close, long flags);
void imgui_end();

// Label
void imgui_text(char *fmt);

// Input
var imgui_input_text(char *label, char *buffer, int buffer_size, long flags);
var imgui_input_text_with_hint(char *label, char *hint, char *buf, int buf_size, long flags);
var imgui_input_text_multiline(char *label, char *buf, int buf_size, int width, int height, long flags);
var imgui_input_double(char *label, double *v, double step, double step_fast, char *format, long flags);
var imgui_input_int(char *label, int *v, int step, int step_fast, long flags);
var imgui_input_float(char *label, float *v, float step, float step_fast, int decimal_precision, long flags);
var imgui_input_var(char *label, var *v, var step, var step_fast, long flags);
var imgui_input_int2(char *label, int *v, long flags);
var imgui_input_int3(char *label, int *v, long flags);
var imgui_input_int4(char *label, int *v, long flags);
var imgui_input_float2(char *label, float *v, int decimal_precision, long flags);
var imgui_input_float3(char *label, float *v, int decimal_precision, long flags);
var imgui_input_float4(char *label, float *v, int decimal_precision, long flags);
var imgui_input_var2(char *label, var *v, int decimal_precision, long flags);
var imgui_input_var3(char *label, var *v, int decimal_precision, long flags);
var imgui_input_var4(char *label, var *v, int decimal_precision, long flags);
var imgui_input_vector(char *label, VECTOR *v, int decimal_precision, long flags);

var imgui_input_int3(char *label, int *vec, long flags);
var imgui_color_edit3(char *label, float *col, long flags);

// Slider
var imgui_slider_int(char *label, int *v, int v_min, int v_max);
var imgui_slider_float(char *label, float *v, float v_min, float v_max, char *format, float power);
var imgui_slider_angle(char *label, float *v_rad, float v_degrees_min, float v_degrees_max);
var imgui_slider_var(char *label, var *v, var v_min, var v_max);
var imgui_slider_angle_var(char *label, var *v_rad, var v_degrees_min, var v_degrees_max);
var imgui_slider_int2(char *label, int *v, int v_min, int v_max);
var imgui_slider_int3(char *label, int *v, int v_min, int v_max);
var imgui_slider_int4(char *label, int *v, int v_min, int v_max);
var imgui_slider_float2(char *label, float *v, float v_min, float v_max, char *format, float power);
var imgui_slider_float3(char *label, float *v, float v_min, float v_max, char *format, float power);
var imgui_slider_float4(char *label, float *v, float v_min, float v_max, char *format, float power);
var imgui_slider_var2(char *label, var *v, var v_min, var v_max);
var imgui_slider_var3(char *label, var *v, var v_min, var v_max);
var imgui_slider_var4(char *label, var *v, var v_min, var v_max);
var imgui_slider_vector(char *label, VECTOR *v, var v_min, var v_max);

// Click-Button
var imgui_button(char *label);
var imgui_button_color(char *label, VECTOR *normal, VECTOR *hover, VECTOR *pushed);
void imgui_push_button_repeat(int value);
void imgui_pop_button_repeat();
var imgui_arrow_button(char *str_id, long dir);
var imgui_button_img(char *label, BMAP *input, var width, var height);
var imgui_button_img_params(char *label, BMAP *input, var width, var height, var u1, var v1, var u2, var v2, var padding, COLOR4 *background, COLOR4 *tint);

// Checkbox
var imgui_checkbox(char *label, void *state);
var imgui_checkbox_flag(char *label, long *flags, long flag);

// Radiobutton
var imgui_radiobutton(char *label, int *result_pointer, int value);

// Plotlines
void imgui_plotlines(char *label, float *values, int values_count);

// Separator
void imgui_separator();

// Collapsable Header
var imgui_collapsing_header(char *label, void *p_open, long flags);

// Three float inputs
var imgui_input_float3(char *label, float *vec, int decimal_precision, long flags);

// Listbox
var imgui_listbox(char *label, int *current_item, char **items, int items_count, int height_in_items);
var imgui_listbox_header(char *label, int items_count, int height_in_items);
void imgui_listbox_footer();

// Selectables
var imgui_is_item_hovered();
var imgui_selectable(char *label, int *p_selected, long flags);


// Child
void imgui_begin_child(char *id, VECTOR *size, int border, long flags);
void imgui_end_child();

// Columns
void imgui_columns(int count, char *id, int border);
void imgui_next_column();
void set_column_offset(int column_index, var offset_x);
void set_column_width(int column_index, var width);

// Group
void imgui_begin_group();
void imgui_end_group();

// BMAP
void imgui_image(BMAP *map);

// Combo
var imgui_begin_combo(char *label, char *preview_value, long flags);
void imgui_end_combo();
var imgui_selectable_direct(char *label, int p_selected);

// Context
var imgui_begin_popup_context_item(char *label);
void imgui_end_popup();
var imgui_selectable_simple(char *label);
var imgui_begin_popup(char *label, long flags);
VECTOR* imgui_get_mouse_pos_on_opening_current_popup();

// Plots
void imgui_plot_lines(char *label, float *arr, float values_offset, char *overlay_text, VECTOR *graph_size);