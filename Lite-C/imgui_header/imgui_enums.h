#define ImGuiConfigFlags_None                   0
#define ImGuiConfigFlags_NavEnableKeyboard      1 << 0   // Master keyboard navigation enable flag
#define ImGuiConfigFlags_NavEnableGamepad       1 << 1   // Master gamepad navigation enable flag
#define ImGuiConfigFlags_NavEnableSetMousePos   1 << 2   // Instruct navigation to move the mouse cursor
#define ImGuiConfigFlags_NavNoCaptureKeyboard   1 << 3   // Instruct navigation to not set the io.WantCaptureKeyboard flag when io.NavActive is set
#define ImGuiConfigFlags_NoMouse                1 << 4   // Instruct imgui to clear mouse position/buttons in NewFrame()
#define ImGuiConfigFlags_NoMouseCursorChange    1 << 5   // Instruct back-end to not alter mouse cursor shape and visibility
#define ImGuiConfigFlags_IsSRGB                 1 << 20  // Application is SRGB-aware
#define ImGuiConfigFlags_IsTouchScreen          1 << 21  // Application is using a touch screen instead of a mouse


#define ImGuiCond_Always        1 << 0
#define ImGuiCond_Once          1 << 1
#define ImGuiCond_FirstUseEver  1 << 2
#define ImGuiCond_Appearing     1 << 3 


#define ImGuiWindowFlags_None                  0
#define ImGuiWindowFlags_NoTitleBar            1 << 0  // Disable title-bar
#define ImGuiWindowFlags_NoResize              1 << 1  // Disable user resizing with the lower-right grip
#define ImGuiWindowFlags_NoMove                1 << 2  // Disable user moving the window
#define ImGuiWindowFlags_NoScrollbar           1 << 3  // Disable scrollbars (window can still scroll with mouse or programmatically)
#define ImGuiWindowFlags_NoScrollWithMouse     1 << 4  // Disable user vertically scrolling with mouse wheel. On child windowmouse wheel will be forwarded to the parent unless NoScrollbar is also set.
#define ImGuiWindowFlags_NoCollapse            1 << 5  // Disable user collapsing window by double-clicking on it
#define ImGuiWindowFlags_AlwaysAutoResize      1 << 6  // Resize every window to its content every frame
#define ImGuiWindowFlags_NoBackground          1 << 7  // Disable drawing background color (WindowBgetc.) and outside border. Similar as using SetNextWindowBgAlpha(0.0f).
#define ImGuiWindowFlags_NoSavedSettings       1 << 8  // Never load/save settings in .ini file
#define ImGuiWindowFlags_NoMouseInputs         1 << 9  // Disable catching mousehovering test with pass through.
#define ImGuiWindowFlags_MenuBar               1 << 10 // Has a menu-bar
#define ImGuiWindowFlags_HorizontalScrollbar   1 << 11 // Allow horizontal scrollbar to appear (off by default). You may use SetNextWindowContentSize(ImVec2(width,0.0f)); prior to calling Begin() to specify width. Read code in imgui_demo in the "Horizontal Scrolling" section.
#define ImGuiWindowFlags_NoFocusOnAppearing    1 << 12 // Disable taking focus when transitioning from hidden to visible state
#define ImGuiWindowFlags_NoBringToFrontOnFocus 1 << 13 // Disable bringing window to front when taking focus (e.g. clicking on it or programmatically giving it focus)
#define ImGuiWindowFlags_AlwaysVerticalScrollbar 1 << 14 // Always show vertical scrollbar (even if ContentSize.y < Size.y)
#define ImGuiWindowFlags_AlwaysHorizontalScrollbar 1<< 15 // Always show horizontal scrollbar (even if ContentSize.x < Size.x)
#define ImGuiWindowFlags_AlwaysUseWindowPadding1 << 16 // Ensure child windows without border uses style.WindowPadding (ignored by default for non-bordered child windowsbecause more convenient)
#define ImGuiWindowFlags_NoNavInputs           1 << 18 // No gamepad/keyboard navigation within the window
#define ImGuiWindowFlags_NoNavFocus            1 << 19 // No focusing toward this window with gamepad/keyboard navigation (e.g. skipped by CTRL+TAB)
#define ImGuiWindowFlags_UnsavedDocument       1 << 20 // Append '*' to title without affecting the IDas a convenience to avoid using the ### operator. When used in a tab/docking contexttab is selected on closure and closure is deferred by one frame to allow code to cancel the closure (with a confirmation popupetc.) without flicker.
#define ImGuiWindowFlags_NoNav                 ImGuiWindowFlags_NoNavInputs | ImGuiWindowFlags_NoNavFocus
#define ImGuiWindowFlags_NoDecoration          ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoCollapse
#define ImGuiWindowFlags_NoInputs              ImGuiWindowFlags_NoMouseInputs | ImGuiWindowFlags_NoNavInputs | ImGuiWindowFlags_NoNavFocus


#define ImGuiInputTextFlags_None                 0
#define ImGuiInputTextFlags_CharsDecimal         1 << 0   // Allow 0123456789.+-*/
#define ImGuiInputTextFlags_CharsHexadecimal     1 << 1   // Allow 0123456789ABCDEFabcdef
#define ImGuiInputTextFlags_CharsUppercase       1 << 2   // Turn a..z into A..Z
#define ImGuiInputTextFlags_CharsNoBlank         1 << 3   // Filter out spaces tabs
#define ImGuiInputTextFlags_AutoSelectAll        1 << 4   // Select entire text when first taking mouse focus
#define ImGuiInputTextFlags_EnterReturnsTrue     1 << 5   // Return 'true' when Enter is pressed (as opposed to every time the value was modified). Consider looking at the IsItemDeactivatedAfterEdit() function.
#define ImGuiInputTextFlags_CallbackCompletion   1 << 6   // Callback on pressing TAB (for completion handling)
#define ImGuiInputTextFlags_CallbackHistory      1 << 7   // Callback on pressing Up/Down arrows (for history handling)
#define ImGuiInputTextFlags_CallbackAlways       1 << 8   // Callback on each iteration. User code may query cursor position modify text buffer.
#define ImGuiInputTextFlags_CallbackCharFilter   1 << 9   // Callback on character inputs to replace or discard them. Modify 'EventChar' to replace or discard or return 1 in callback to discard.
#define ImGuiInputTextFlags_AllowTabInput        1 << 10  // Pressing TAB input a '\t' character into the text field
#define ImGuiInputTextFlags_CtrlEnterForNewLine  1 << 11  // In multi-line mode unfocus with Enter add new line with Ctrl+Enter (default is opposite: unfocus with Ctrl+Enter add line with Enter).
#define ImGuiInputTextFlags_NoHorizontalScroll   1 << 12  // Disable following the cursor horizontally
#define ImGuiInputTextFlags_AlwaysInsertMode     1 << 13  // Insert mode
#define ImGuiInputTextFlags_ReadOnly             1 << 14  // Read-only mode
#define ImGuiInputTextFlags_Password             1 << 15  // Password mode display all characters as '*'
#define ImGuiInputTextFlags_NoUndoRedo           1 << 16  // Disable undo/redo. Note that input text owns the text data while active if you want to provide your own undo/redo stack you need e.g. to call ClearActiveID().
#define ImGuiInputTextFlags_CharsScientific      1 << 17  // Allow 0123456789.+-*/eE (Scientific notation input)
#define ImGuiInputTextFlags_CallbackResize       1 << 18


#define ImGuiCol_Text 0
#define ImGuiCol_TextDisabled 1
#define ImGuiCol_WindowBg      2        // Background of normal windows
#define ImGuiCol_ChildBg        3       // Background of child windows
#define ImGuiCol_PopupBg         4      // Background of popups menus tooltips windows
#define ImGuiCol_Border 5
#define ImGuiCol_BorderShadow 6
#define ImGuiCol_FrameBg       7        // Background of checkbox radio button plot slider text input
#define ImGuiCol_FrameBgHovered 8
#define ImGuiCol_FrameBgActive 9
#define ImGuiCol_TitleBg 10
#define ImGuiCol_TitleBgActive 11
#define ImGuiCol_TitleBgCollapsed 12
#define ImGuiCol_MenuBarBg 13
#define ImGuiCol_ScrollbarBg 14
#define ImGuiCol_ScrollbarGrab 15
#define ImGuiCol_ScrollbarGrabHovered 16
#define ImGuiCol_ScrollbarGrabActive 17
#define ImGuiCol_CheckMark 18
#define ImGuiCol_SliderGrab 19
#define ImGuiCol_SliderGrabActive 20
#define ImGuiCol_Button 21
#define ImGuiCol_ButtonHovered 22
#define ImGuiCol_ButtonActive 23
#define ImGuiCol_Header 24
#define ImGuiCol_HeaderHovered 25
#define ImGuiCol_HeaderActive 26
#define ImGuiCol_Separator 27
#define ImGuiCol_SeparatorHovered 28
#define ImGuiCol_SeparatorActive 29
#define ImGuiCol_ResizeGrip 30
#define ImGuiCol_ResizeGripHovered 31
#define ImGuiCol_ResizeGripActive 32
#define ImGuiCol_Tab 33
#define ImGuiCol_TabHovered 34
#define ImGuiCol_TabActive 35
#define ImGuiCol_TabUnfocused 36
#define ImGuiCol_TabUnfocusedActive 37
#define ImGuiCol_PlotLines 38
#define ImGuiCol_PlotLinesHovered 39
#define ImGuiCol_PlotHistogram 40
#define ImGuiCol_PlotHistogramHovered 41
#define ImGuiCol_TextSelectedBg 42
#define ImGuiCol_DragDropTarget 43
#define ImGuiCol_NavHighlight    44      // Gamepad/keyboard: current highlighted item
#define ImGuiCol_NavWindowingHighlight 45 // Highlight window when using CTRL+TAB
#define ImGuiCol_NavWindowingDimBg  46   // Darken/colorize entire screen behind the CTRL+TAB window list when active
#define ImGuiCol_ModalWindowDimBg  47    // Darken/colorize entire screen behind a modal window when one is active


#define ImGuiStyleVar_Alpha               0 // float     Alpha
#define ImGuiStyleVar_WindowPadding       1 // ImVec2    WindowPadding
#define ImGuiStyleVar_WindowRounding      2 // float     WindowRounding
#define ImGuiStyleVar_WindowBorderSize    3 // float     WindowBorderSize
#define ImGuiStyleVar_WindowMinSize       4 // ImVec2    WindowMinSize
#define ImGuiStyleVar_WindowTitleAlign    5 // ImVec2    WindowTitleAlign
#define ImGuiStyleVar_ChildRounding       6 // float     ChildRounding
#define ImGuiStyleVar_ChildBorderSize     7 // float     ChildBorderSize
#define ImGuiStyleVar_PopupRounding       8 // float     PopupRounding
#define ImGuiStyleVar_PopupBorderSize     9 // float     PopupBorderSize
#define ImGuiStyleVar_FramePadding        10 // ImVec2    FramePadding
#define ImGuiStyleVar_FrameRounding       11 // float     FrameRounding
#define ImGuiStyleVar_FrameBorderSize     12 // float     FrameBorderSize
#define ImGuiStyleVar_ItemSpacing         13 // ImVec2    ItemSpacing
#define ImGuiStyleVar_ItemInnerSpacing    14 // ImVec2    ItemInnerSpacing
#define ImGuiStyleVar_IndentSpacing       15 // float     IndentSpacing
#define ImGuiStyleVar_ScrollbarSize       16 // float     ScrollbarSize
#define ImGuiStyleVar_ScrollbarRounding   17 // float     ScrollbarRounding
#define ImGuiStyleVar_GrabMinSize         18 // float     GrabMinSize
#define ImGuiStyleVar_GrabRounding        19 // float     GrabRounding
#define ImGuiStyleVar_TabRounding         20 // float     TabRounding
#define ImGuiStyleVar_ButtonTextAlign     21 // ImVec2    ButtonTextAlign
#define ImGuiStyleVar_SelectableTextAlign 22 // ImVec2    SelectableTextAlign


#define ImGuiColorEditFlags_None             0
#define ImGuiColorEditFlags_NoAlpha          1 << 1   //              // ColorEdit ColorPicker ColorButton: ignore Alpha component (will only read 3 components from the input pointer).
#define ImGuiColorEditFlags_NoPicker         1 << 2   //              // ColorEdit: disable picker when clicking on colored square.
#define ImGuiColorEditFlags_NoOptions        1 << 3   //              // ColorEdit: disable toggling options menu when right-clicking on inputs/small preview.
#define ImGuiColorEditFlags_NoSmallPreview   1 << 4   //              // ColorEdit ColorPicker: disable colored square preview next to the inputs. (e.g. to show only the inputs)
#define ImGuiColorEditFlags_NoInputs         1 << 5   //              // ColorEdit ColorPicker: disable inputs sliders/text widgets (e.g. to show only the small preview colored square).
#define ImGuiColorEditFlags_NoTooltip        1 << 6   //              // ColorEdit ColorPicker ColorButton: disable tooltip when hovering the preview.
#define ImGuiColorEditFlags_NoLabel          1 << 7   //              // ColorEdit ColorPicker: disable display of inline text label (the label is still forwarded to the tooltip and picker).
#define ImGuiColorEditFlags_NoSidePreview    1 << 8   //              // ColorPicker: disable bigger color preview on right side of the picker use small colored square preview instead.
#define ImGuiColorEditFlags_NoDragDrop       1 << 9   //              // ColorEdit: disable drag and drop target. ColorButton: disable drag and drop source.

// User Options (right-click on widget to change some of them). 
#define ImGuiColorEditFlags_AlphaBar         1 << 16  //              // ColorEdit ColorPicker: show vertical alpha bar/gradient in picker.
#define ImGuiColorEditFlags_AlphaPreview     1 << 17  //              // ColorEdit ColorPicker ColorButton: display preview as a transparent color over a checkerboard instead of opaque.
#define ImGuiColorEditFlags_AlphaPreviewHalf 1 << 18  //              // ColorEdit ColorPicker ColorButton: display half opaque / half checkerboard instead of opaque.
#define ImGuiColorEditFlags_HDR              1 << 19  //              // (WIP) ColorEdit: Currently only disable 0.0f..1.0f limits in RGBA edition (note: you probably want to use #define ImGuiColorEditFlags_Float flag as well).
#define ImGuiColorEditFlags_DisplayRGB       1 << 20  // [Display]    // ColorEdit: override _display_ type among RGB/HSV/Hex. ColorPicker: select any combination using one or more of RGB/HSV/Hex.
#define ImGuiColorEditFlags_DisplayHSV       1 << 21  // [Display]    // "
#define ImGuiColorEditFlags_DisplayHex       1 << 22  // [Display]    // "
#define ImGuiColorEditFlags_Uint8            1 << 23  // [DataType]   // ColorEdit ColorPicker ColorButton: _display_ values formatted as 0..255.
#define ImGuiColorEditFlags_Float            1 << 24  // [DataType]   // ColorEdit ColorPicker ColorButton: _display_ values formatted as 0.0f..1.0f floats instead of 0..255 integers. No round-trip of value via integers.
#define ImGuiColorEditFlags_PickerHueBar     1 << 25  // [Picker]     // ColorPicker: bar for Hue rectangle for Sat/Value.
#define ImGuiColorEditFlags_PickerHueWheel   1 << 26  // [Picker]     // ColorPicker: wheel for Hue triangle for Sat/Value.
#define ImGuiColorEditFlags_InputRGB         1 << 27  // [Input]      // ColorEdit ColorPicker: input and output data in RGB format.
#define ImGuiColorEditFlags_InputHSV         1 << 28  // [Input]      // ColorEdit ColorPicker: input and output data in HSV format.

// Defaults Options. You can set application defaults using SetColorEditOptions(). The intent is that you probably don't want to
// override them in most of your calls. Let the user choose via the option menu and/or call SetColorEditOptions() once during startup.
#define ImGuiColorEditFlags__OptionsDefault  ImGuiColorEditFlags_Uint8 | ImGuiColorEditFlags_DisplayRGB | ImGuiColorEditFlags_InputRGB | ImGuiColorEditFlags_PickerHueBar

// [Internal] Masks
#define ImGuiColorEditFlags__DisplayMask      ImGuiColorEditFlags_DisplayRGB | ImGuiColorEditFlags_DisplayHSV | ImGuiColorEditFlags_DisplayHex
#define ImGuiColorEditFlags__DataTypeMask     ImGuiColorEditFlags_Uint8 | ImGuiColorEditFlags_Float
#define ImGuiColorEditFlags__PickerMask       ImGuiColorEditFlags_PickerHueWheel | ImGuiColorEditFlags_PickerHueBar
#define ImGuiColorEditFlags__InputMask        ImGuiColorEditFlags_InputRGB | ImGuiColorEditFlags_InputHSV


#define ImGuiMouseCursor_None -1
#define ImGuiMouseCursor_Arrow 0
#define ImGuiMouseCursor_TextInput 1         // When hovering over InputText, etc.
#define ImGuiMouseCursor_ResizeAll 2         // (Unused by #define ImGui functions)
#define ImGuiMouseCursor_ResizeNS 3          // When hovering over an horizontal border
#define ImGuiMouseCursor_ResizeEW 4          // When hovering over a vertical border or a column
#define ImGuiMouseCursor_ResizeNESW 5        // When hovering over the bottom-left corner of a window
#define ImGuiMouseCursor_ResizeNWSE 6        // When hovering over the bottom-right corner of a window
#define ImGuiMouseCursor_Hand 7              // (Unused by #define ImGui functions. Use for e.g. hyperlinks)


#define ImGuiBackendFlags_None                   0
#define ImGuiBackendFlags_HasGamepad             1 << 0   // Back-end supports gamepad and currently has one connected.
#define ImGuiBackendFlags_HasMouseCursors        1 << 1   // Back-end supports honoring GetMouseCursor() value to change the OS cursor shape.
#define ImGuiBackendFlags_HasSetMousePos         1 << 2    // Back-end supports io.WantSetMousePos requests to reposition the OS mouse position (only used if #define ImGuiConfigFlags_NavEnableSetMousePos is set).


#define ImGuiTreeNodeFlags_None                  0
#define ImGuiTreeNodeFlags_Selected              1 << 0   // Draw as selected
#define ImGuiTreeNodeFlags_Framed                1 << 1   // Full colored frame (e.g. for CollapsingHeader)
#define ImGuiTreeNodeFlags_AllowItemOverlap      1 << 2   // Hit testing to allow subsequent widgets to overlap this one
#define ImGuiTreeNodeFlags_NoTreePushOnOpen      1 << 3   // Don't do a TreePush() when open (e.g. for CollapsingHeader)  no extra indent nor pushing on ID stack
#define ImGuiTreeNodeFlags_NoAutoOpenOnLog       1 << 4   // Don't automatically and temporarily open node when Logging is active (by default logging will automatically open tree nodes)
#define ImGuiTreeNodeFlags_DefaultOpen           1 << 5   // Default node to be open
#define ImGuiTreeNodeFlags_OpenOnDoubleClick     1 << 6   // Need double-click to open node
#define ImGuiTreeNodeFlags_OpenOnArrow           1 << 7   // Only open when clicking on the arrow part. If #define ImGuiTreeNodeFlags_OpenOnDoubleClick is also set single-click arrow or double-click all box to open.
#define ImGuiTreeNodeFlags_Leaf                  1 << 8   // No collapsing no arrow (use as a convenience for leaf nodes).
#define ImGuiTreeNodeFlags_Bullet                1 << 9   // Display a bullet instead of arrow
#define ImGuiTreeNodeFlags_FramePadding          1 << 10  // Use FramePadding (even for an unframed text node) to vertically align text baseline to regular widget height. Equivalent to calling AlignTextToFramePadding().
#define ImGuiTreeNodeFlags_NavLeftJumpsBackHere  1 << 13  // (WIP) Nav: left direction may move to this TreeNode() from any of its child (items submitted between TreeNode and TreePop)
#define ImGuiTreeNodeFlags_CollapsingHeader      ImGuiTreeNodeFlags_Framed | ImGuiTreeNodeFlags_NoTreePushOnOpen | ImGuiTreeNodeFlags_NoAutoOpenOnLog


#define ImGuiSelectableFlags_None                0
#define ImGuiSelectableFlags_DontClosePopups     1 << 0   // Clicking this don't close parent popup window
#define ImGuiSelectableFlags_SpanAllColumns      1 << 1   // Selectable frame can span all columns (text will still fit in current column)
#define ImGuiSelectableFlags_AllowDoubleClick    1 << 2   // Generate press events on double clicks too
#define ImGuiSelectableFlags_Disabled            1 << 3    // Cannot be selected display greyed out text



#define ImGuiComboFlags_None                     0
#define ImGuiComboFlags_PopupAlignLeft           1 << 0   // Align the popup toward the left by default
#define ImGuiComboFlags_HeightSmall              1 << 1   // Max ~4 items visible. Tip: If you want your combo popup to be a specific size you can use SetNextWindowSizeConstraints() prior to calling BeginCombo()
#define ImGuiComboFlags_HeightRegular            1 << 2   // Max ~8 items visible (default)
#define ImGuiComboFlags_HeightLarge              1 << 3   // Max ~20 items visible
#define ImGuiComboFlags_HeightLargest            1 << 4   // As many fitting items as possible
#define ImGuiComboFlags_NoArrowButton            1 << 5   // Display on the preview box without the square arrow button
#define ImGuiComboFlags_NoPreview                1 << 6   // Display only a square arrow button
#define ImGuiComboFlags_HeightMask_              ImGuiComboFlags_HeightSmall | ImGuiComboFlags_HeightRegular | ImGuiComboFlags_HeightLarge | ImGuiComboFlags_HeightLargest


#define ImGuiTabBarFlags_None                            0
#define ImGuiTabBarFlags_Reorderable                     1 << 0   // Allow manually dragging tabs to re-order them + New tabs are appended at the end of list
#define ImGuiTabBarFlags_AutoSelectNewTabs               1 << 1   // Automatically select new tabs when they appear
#define ImGuiTabBarFlags_TabListPopupButton              1 << 2
#define ImGuiTabBarFlags_NoCloseWithMiddleMouseButton    1 << 3   // Disable behavior of closing tabs (that are submitted with p_open ! NULL) with middle mouse button. You can still repro this behavior on user's side with if (IsItemHovered() && IsMouseClicked(2)) *p_open  false.
#define ImGuiTabBarFlags_NoTabListScrollingButtons       1 << 4
#define ImGuiTabBarFlags_NoTooltip                       1 << 5   // Disable tooltips when hovering a tab
#define ImGuiTabBarFlags_FittingPolicyResizeDown         1 << 6   // Resize tabs when they don't fit
#define ImGuiTabBarFlags_FittingPolicyScroll             1 << 7   // Add scroll buttons when tabs don't fit
#define ImGuiTabBarFlags_FittingPolicyMask_              ImGuiTabBarFlags_FittingPolicyResizeDown | ImGuiTabBarFlags_FittingPolicyScroll
#define ImGuiTabBarFlags_FittingPolicyDefault_           ImGuiTabBarFlags_FittingPolicyResizeDown


#define ImGuiTabItemFlags_None                           0
#define ImGuiTabItemFlags_UnsavedDocument                1 << 0   // Append '*' to title without affecting the ID as a convenience to avoid using the ### operator. Also: tab is selected on closure and closure is deferred by one frame to allow code to undo it without flicker.
#define ImGuiTabItemFlags_SetSelected                    1 << 1   // Trigger flag to programmatically make the tab selected when calling BeginTabItem()
#define ImGuiTabItemFlags_NoCloseWithMiddleMouseButton   1 << 2   // Disable behavior of closing tabs (that are submitted with p_open ! NULL) with middle mouse button. You can still repro this behavior on user's side with if (IsItemHovered() && IsMouseClicked(2)) *p_open  false.
#define ImGuiTabItemFlags_NoPushId                       1 << 3    // Don't call PushID(tab->ID)/PopID() on BeginTabItem()/EndTabItem()


#define ImGuiFocusedFlags_None                           0
#define ImGuiFocusedFlags_ChildWindows                   1 << 0   // IsWindowFocused(): Return true if any children of the window is focused
#define ImGuiFocusedFlags_RootWindow                     1 << 1   // IsWindowFocused(): Test from root window (top most parent of the current hierarchy)
#define ImGuiFocusedFlags_AnyWindow                      1 << 2   // IsWindowFocused(): Return true if any window is focused. Important: If you are trying to tell how to dispatch your low-level inputs, do NOT use this. Use #define ImGui::GetIO().WantCaptureMouse instead.
#define ImGuiFocusedFlags_RootAndChildWindows            ImGuiFocusedFlags_RootWindow | ImGuiFocusedFlags_ChildWindows


#define ImGuiHoveredFlags_None                           0        // Return true if directly over the item/window not obstructed by another window not obstructed by an active popup or modal blocking inputs under them.
#define ImGuiHoveredFlags_ChildWindows                   1 << 0   // IsWindowHovered() only: Return true if any children of the window is hovered
#define ImGuiHoveredFlags_RootWindow                     1 << 1   // IsWindowHovered() only: Test from root window (top most parent of the current hierarchy)
#define ImGuiHoveredFlags_AnyWindow                      1 << 2   // IsWindowHovered() only: Return true if any window is hovered
#define ImGuiHoveredFlags_AllowWhenBlockedByPopup        1 << 3   // Return true even if a popup window is normally blocking access to this item/window
#define ImGuiHoveredFlags_AllowWhenBlockedByActiveItem   1 << 5   // Return true even if an active item is blocking access to this item/window. Useful for Drag and Drop patterns.
#define ImGuiHoveredFlags_AllowWhenOverlapped            1 << 6   // Return true even if the position is overlapped by another window
#define ImGuiHoveredFlags_AllowWhenDisabled              1 << 7   // Return true even if the item is disabled
#define ImGuiHoveredFlags_RectOnly                      ImGuiHoveredFlags_AllowWhenBlockedByPopup | ImGuiHoveredFlags_AllowWhenBlockedByActiveItem | ImGuiHoveredFlags_AllowWhenOverlapped
#define ImGuiHoveredFlags_RootAndChildWindows           ImGuiHoveredFlags_RootWindow | ImGuiHoveredFlags_ChildWindows


#define ImGuiDragDropFlags_None                          0
#define ImGuiDragDropFlags_SourceNoPreviewTooltip        1 << 0   // By default a successful call to BeginDragDropSource opens a tooltip so you can display a preview or description of the source contents. This flag disable this behavior.
#define ImGuiDragDropFlags_SourceNoDisableHover          1 << 1   // By default when dragging we clear data so that IsItemHovered() will return false to avoid subsequent user code submitting tooltips. This flag disable this behavior so you can still call IsItemHovered() on the source item.
#define ImGuiDragDropFlags_SourceNoHoldToOpenOthers      1 << 2   // Disable the behavior that allows to open tree nodes and collapsing header by holding over them while dragging a source item.
#define ImGuiDragDropFlags_SourceAllowNullID             1 << 3   // Allow items such as Text() Image() that have no unique identifier to be used as drag source by manufacturing a temporary identifier based on their window-relative position. This is extremely unusual within the dear #define ImGui ecosystem and so we made it explicit.
#define ImGuiDragDropFlags_SourceExtern                  1 << 4   // External source (from outside of #define ImGui) won't attempt to read current item/window info. Will always return true. Only one Extern source can be active simultaneously.
#define ImGuiDragDropFlags_SourceAutoExpirePayload       1 << 5   // Automatically expire the payload if the source cease to be submitted (otherwise payloads are persisting while being dragged)
#define ImGuiDragDropFlags_AcceptBeforeDelivery          1 << 10  // AcceptDragDropPayload() will returns true even before the mouse button is released. You can then call IsDelivery() to test if the payload needs to be delivered.
#define ImGuiDragDropFlags_AcceptNoDrawDefaultRect       1 << 11  // Do not draw the default highlight rectangle when hovering over target.
#define ImGuiDragDropFlags_AcceptNoPreviewTooltip        1 << 12  // Request hiding the BeginDragDropSource tooltip from the BeginDragDropTarget site.
#define ImGuiDragDropFlags_AcceptPeekOnly               ImGuiDragDropFlags_AcceptBeforeDelivery | ImGuiDragDropFlags_AcceptNoDrawDefaultRect  // For peeking ahead and inspecting the payload before delivery.


#define ImGuiDir_None     -1 
#define ImGuiDir_Left     0    
#define ImGuiDir_Right    1
    
#define ImGuiDir_Up       2
    
#define ImGuiDir_Down    3