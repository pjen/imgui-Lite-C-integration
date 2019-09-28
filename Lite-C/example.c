#include <acknex.h>
#include <default.c>

#define PRAGMA_PATH "imgui_header"

#include "imgui.h"

void window_func()
{
	// The Demo declares char*s on the fly with static. You can't do this in Lite-C, so I create it globaly
char *listbox_items[9];
char *combo_items[14];
char *item_current;
STRING *text = "The Pentium F00F bug, shorthand for F0 0F C7 C8,\nthe hexadecimal encoding of one offending instruction,\nmore formally, the invalid operand with locked CMPXCHG8B\ninstruction bug, is a design flaw in the majority of\nIntel Pentium, Pentium MMX, and Pentium OverDrive\nprocessors (all in the P5 microarchitecture).\n\n\nlabel:\n\tlock cmpxchg8b eax\n";
var saved_palette[32][4];


void ShowDemoWindowWidgets()
{
    if (!ImGui->CollapsingHeader("Widgets", NULL, 0))
        return;

    if (ImGui->TreeNode("Basic"))
    {
        static int clicked = 0;
        if (ImGui->Button("Button"))
            clicked++;
        if (clicked & 1)
        {
            ImGui->SameLine();
            ImGui->Text("Thanks for clicking me!");
        }

        static int check = 1;
        ImGui->Checkbox("checkbox", &check);

        static int e = 0;
        ImGui->RadioButton("radio a", &e, 0); ImGui->SameLine();
        ImGui->RadioButton("radio b", &e, 1); ImGui->SameLine();
        ImGui->RadioButton("radio c", &e, 2);

        // Color buttons, demonstrate using PushID() to add unique identifier in the ID stack, and changing style.
        int i; for (i = 0; i < 7; i++)
        {
            if (i > 0)
                ImGui->SameLine();
            ImGui->PushId(i);
            ImGui->PushStyleColorHsv(ImGuiCol_Button, i / 7.0, 0.6, 0.6, 1.0);
            ImGui->PushStyleColorHsv(ImGuiCol_ButtonHovered, i / 7.0, 0.7, 0.7, 1.0);
            ImGui->PushStyleColorHsv(ImGuiCol_ButtonActive, i / 7.0, 0.8, 0.8, 1.0);
            ImGui->Button("Click");
            ImGui->PopStyleColor(3);
            ImGui->PopId();
        }

        // Use AlignTextToFramePadding() to align text baseline to the baseline of framed elements (otherwise a Text+SameLine+Button sequence will have the text a little too high by default)
        ImGui->AlignTextToFramePadding();
        ImGui->Text("Hold to repeat:");
        ImGui->SameLine();

        // Arrow buttons with Repeater
        static int counter = 0;
        float spacing = (ImGui->GetStyleItemInnerSpacing())->x;
        ImGui->PushButtonRepeat(1);
        if (ImGui->ArrowButton("##left", ImGuiDir_Left)) { counter--; }
        ImGui->SameLineParams(0, spacing);
        if (ImGui->ArrowButton("##right", ImGuiDir_Right)) { counter++; }
        ImGui->PopButtonRepeat();
        ImGui->SameLine();
        ImGui->Text(_chr(str_printf(NULL, "%d", counter)));

        ImGui->Text("Hover over me");
        if (ImGui->IsItemHovered())
            ImGui->SetTooltip("I am a tooltip");

        ImGui->SameLine();
        ImGui->Text("- or me");
        if (ImGui->IsItemHovered())
        {
            ImGui->BeginTooltip();
            ImGui->Text("I am a fancy tooltip");
            static float arr[7] = { 0.6, 0.1, 1.0, 0.5, 0.92, 0.1, 0.2 };
            ImGui->Plotlines("Curve", arr, 7);
            ImGui->EndTooltip();
        }

        ImGui->Separator();

        ImGui->LabelText("label", "Value");

		// Using the _simplified_ one-liner Combo() api here
		// See "Combo" section for examples of how to use the more complete BeginCombo()/EndCombo() api.
		static char *items = "AAAA\0BBBB\0CCCC\0DDDD\0EEEE\0FFFF\0GGGG\0HHHH\0IIII\0JJJJ\0KKKK\0LLLLLLL\0MMMM\0OOOOOOO\0";
		static int item_current = 0;
		ImGui->Combo("combo", &item_current, items, -1);
		ImGui->SameLine(); HelpMarker("Refer to the \"Combo\" section below for an explanation of the full BeginCombo/EndCombo API, and demonstration of various flags.\n");

        // LITE-C You would have a global char array, you can't do a char str0[128] = "Hello World!" how this demo is supposed to work, so you get ugly char array init
        static char str0[128] = {'H','e','l','l','o',' ','W','o','r','l','d','!'};
		ImGui->InputText("input text", str0, 128, 0);
		ImGui->SameLine(); 
		HelpMarker("USER:\nHold SHIFT or use mouse to select text.\nCTRL+Left/Right to word jump.\nCTRL+A or double-click to select all.\nCTRL+X,CTRL+C,CTRL+V clipboard.\nCTRL+Z,CTRL+Y undo/redo.\nESCAPE to revert.\n\nPROGRAMMER:\nYou can use the ImGuiInputTextFlags_CallbackResize facility if you need to wire InputText() to a dynamic string type. See misc/cpp/imgui_stdlib.h for an example (this is not demonstrated in imgui_demo.cpp).");

		static char str1[128];
		ImGui->InputTextWithHint("input text (w/ hint)", "enter text here", str1, 128, 0);

		static int i0 = 123;
		ImGui->InputInt("input int", &i0, 1, 100, 0);
		ImGui->SameLine(); HelpMarker("You can apply arithmetic operators +,*,/ on numerical values.\n  e.g. [ 100 ], input \'*2\', result becomes [ 200 ]\nUse +- to subtract.\n");

		static float f0 = 0.001;
		ImGui->InputFloatFormat("input float", &f0, 0.01, 1.0, "%.3f", 0);

		static double d0 = 999999.00000001;
		ImGui->InputDouble("input double", &d0, 0.01, 1.0, "%.8f", 0);

		static float f1 = 1.e10;
		ImGui->InputFloatFormat("input scientific", &f1, 0.0, 0.0, "%e", 0);
		ImGui->SameLine(); HelpMarker("You can input value using the scientific notation,\n  e.g. \"1e+8\" becomes \"100000000\".\n");

		static float vec4a[4] = { 0.1, 0.2, 0.3, 0.44 };
		ImGui->InputFloat3("input float3", vec4a, 3, 0);

		static int i1 = 50;
        static int i2 = 42;
		ImGui->DragInt("drag int", &i1, 1, 0, 0, "%d");
		ImGui->SameLine(); HelpMarker("Click and drag to edit value.\nHold SHIFT/ALT for faster/slower edit.\nDouble-click or CTRL+click to input value.");

		ImGui->DragInt("drag int 0..100", &i2, 1, 0, 100, "%d%%");

		static float f1=1;
        static float f2=0.0067;
		ImGui->DragFloat("drag float", &f1, 0.005, 0, 0, "%.3f", 1);
		ImGui->DragFloat("drag small float", &f2, 0.0001, 0, 0, "%.06f ns", 1);

		static int i1=0;
		ImGui->SliderInt("slider int", &i1, -1, 3);
		ImGui->SameLine(); HelpMarker("CTRL+click to input value.");

		static float f1=0.123;
        static float f2=0.0;
		ImGui->SliderFloat("slider float", &f1, 0.0, 1.0, "ratio = %.3f", 1);
		ImGui->SliderFloat("slider float (curve)", &f2, -10.0, 10.0, "%.4f", 2.0);
		static float angle = 0.0;
		ImGui->SliderAngle("slider angle", &angle, -360, 360, "%.0f deg");

		static float col1[3] = { 1.0,0.0,0.2 };
		static float col2[4] = { 0.4,0.7,0.0,0.5 };
		ImGui->ColorEdit3("color 1", col1, 0);
		ImGui->SameLine(); HelpMarker("Click on the colored square to open a color picker.\nClick and hold to use drag and drop.\nRight-click on the colored square to show options.\nCTRL+click on individual component to input value.\n");

		ImGui->ColorEdit4("color 2", col2, 0);

		// List box
        listbox_items[0] = "Apple";
        listbox_items[1] = "Banana";
        listbox_items[2] = "Cherry";
        listbox_items[3] = "Kiwi";
        listbox_items[4] = "Mango";
        listbox_items[5] = "Orange";
        listbox_items[6] = "Pineapple";
        listbox_items[7] = "Strawberry";
        listbox_items[8] = "Watermelon";
		static int listbox_item_current = 1;
		ImGui->ListBox("listbox\n(single select)", &listbox_item_current, listbox_items, 9, 4);

        ImGui->TreePop();
    }

    if (ImGui->TreeNode("Trees"))
    {
        if (ImGui->TreeNode("Basic trees"))
        {
            int i; for (i = 0; i < 5; i++)
                if (ImGui->Treenode((void*)i, _chr(str_printf(NULL, "Child %d", i))))
                {
                    ImGui->Text("blah blah");
                    ImGui->SameLine();
                    if (ImGui->SmallButton("button")) { }
                    ImGui->TreePop();
                }
            ImGui->TreePop();
        }

        if (ImGui->TreeNode("Advanced, with Selectable nodes"))
        {
            HelpMarker("This is a more standard looking tree with selectable nodes.\nClick to select, CTRL+Click to toggle, click on arrows or double-click to open.");
            static int align_label_with_current_x_position = 1;
            ImGui->Checkbox("Align label with current X position)", &align_label_with_current_x_position);
            ImGui->Text("Hello!");
            if (align_label_with_current_x_position)
                ImGui->Unindent(ImGui->GetTreeNodeToLabelSpacing());

            static int selection_mask = (1 << 2); // Dumb representation of what may be user-side selection state. You may carry selection state inside or outside your objects in whatever format you see fit.
            int node_clicked = -1;                // Temporary storage of what node we have clicked to process selection at the end of the loop. May be a pointer to your own node type, etc.
            ImGui->PushStyleVar(ImGuiStyleVar_IndentSpacing, ImGui->GetFontSize() * 3); // Increase spacing to differentiate leaves from expanded contents.
            int i; for (i = 0; i < 6; i++)
            {
                // Disable the default open on single-click behavior and pass in Selected flag according to our selection state.
                int node_flags = ImGuiTreeNodeFlags_OpenOnArrow | ImGuiTreeNodeFlags_OpenOnDoubleClick | ifelse((selection_mask & (1 << i)), ImGuiTreeNodeFlags_Selected, 0);
                if (i < 3)
                {
                    // Node
                    int node_open = ImGui->TreeNodeEx((void*)i, node_flags, _chr(str_printf(NULL, "Selectable Node %d", i)));
                    if (ImGui->IsItemClicked(0))
                        node_clicked = i;
                    if (node_open)
                    {
                        ImGui->Text("Blah blah\nBlah Blah");
                        ImGui->TreePop();
                    }
                }
                else
                {
                    // Leaf: The only reason we have a TreeNode at all is to allow selection of the leaf. Otherwise we can use BulletText() or TreeAdvanceToLabelPos()+Text().
                    node_flags |= ImGuiTreeNodeFlags_Leaf | ImGuiTreeNodeFlags_NoTreePushOnOpen; // ImGuiTreeNodeFlags_Bullet
                    ImGui->TreeNodeEx((void*)i, node_flags, _chr(str_printf(NULL, "Selectable Leaf %d", i)));
                    if (ImGui->IsItemClicked(0))
                        node_clicked = i;
                }
            }
            if (node_clicked != -1)
            {
                // Update selection state. Process outside of tree loop to avoid visual inconsistencies during the clicking-frame.
                if (ImGui->GetIoKeyCtrl())
                    selection_mask ^= (1 << node_clicked);          // CTRL+click to toggle
                else //if (!(selection_mask & (1 << node_clicked))) // Depending on selection behavior you want, this commented bit preserve selection when clicking on item that is part of the selection
                    selection_mask = (1 << node_clicked);           // Click to single-select
            }
            ImGui->PopStyleVar(1);
            if (align_label_with_current_x_position)
                ImGui->Indent(ImGui->GetTreeNodeToLabelSpacing());
            ImGui->TreePop();
        }
        ImGui->TreePop();
    }

    if (ImGui->TreeNode("Collapsing Headers"))
    {
        static int closable_group = 1;
        ImGui->Checkbox("Enable extra group", &closable_group);
        if (ImGui->CollapsingHeader("Header", NULL, 0))
        {
            ImGui->Text(_chr(str_printf(NULL, "IsItemHovered: %d", ImGui->IsItemHovered())));
            int i; for (i = 0; i < 5; i++)
                ImGui->Text(_chr(str_printf(NULL, "Some content %d", i)));
        }
        if (ImGui->CollapsingHeader("Header with a close button", &closable_group, 0))
        {
            ImGui->Text(_chr(str_printf(NULL, "IsItemHovered: %d", ImGui->IsItemHovered())));
            int i; for (i = 0; i < 5; i++)
                ImGui->Text(_chr(str_printf(NULL, "More content %d", i)));
        }
        ImGui->TreePop();
    }
	
    if (ImGui->TreeNode("Bullets"))
    {
        ImGui->BulletText("Bullet point 1");
        ImGui->BulletText("Bullet point 2\nOn multiple lines");
        ImGui->Bullet(); ImGui->Text("Bullet point 3 (two calls)");
        ImGui->Bullet(); ImGui->SmallButton("Button");
        ImGui->TreePop();
    }

    if (ImGui->TreeNode("Text"))
    {
        if (ImGui->TreeNode("Colored Text"))
        {
            // Using shortcut. You can use PushStyleColor()/PopStyleColor() for more flexibility.
            ImGui->TextColored(1.0,0.0,1.0,1.0, "Pink");
            ImGui->TextColored(1.0,1.0,0.0,1.0, "Yellow");
            ImGui->TextDisabled("Disabled");
            ImGui->SameLine(); HelpMarker("The TextDisabled color is stored in ImGuiStyle.");
            ImGui->TreePop();
        }

        if (ImGui->TreeNode("Word Wrapping"))
        {
            // Using shortcut. You can use PushTextWrapPos()/PopTextWrapPos() for more flexibility.
            ImGui->TextWrapped("This text should automatically wrap on the edge of the window. The current implementation for text wrapping follows simple rules suitable for English and possibly other languages.");
            ImGui->Spacing();

            static float wrap_width = 200.0;
            ImGui->SliderFloat("Wrap width", &wrap_width, -20, 600, "%.0f", 1);

            ImGui->Text("Test paragraph 1:");
            VECTOR* pos = ImGui->GetCursorScreenPos();
			void *draw_list = ImGui->GetWindowDrawList();
            ImGui->DrawlistAddRectFilled(draw_list, vector(pos->x + wrap_width, pos->y, 0), vector(pos->x + wrap_width + 10, pos->y + ImGui->GetTextLineHeight(), 0), vector(255,0,255), 0);
            ImGui->PushTextWrapPos((ImGui->GetCursorPos())->x + wrap_width);
            ImGui->Text(_chr(str_printf(NULL, "The lazy dog is a good dog. This paragraph is made to fit within %.0f pixels. Testing a 1 character word. The quick brown fox jumps over the lazy dog.", wrap_width)));
            ImGui->DrawlistAddRect(draw_list, ImGui->GetItemRectMin(), ImGui->GetItemRectMax(), vector(255,255,0), 0);
            ImGui->PopTextWrapPos();

            ImGui->Text("Test paragraph 2:");
            pos = ImGui->GetCursorScreenPos();
            ImGui->DrawlistAddRectFilled(draw_list, vector(pos->x + wrap_width, pos->y, 0), vector(pos->x + wrap_width + 10, pos->y + ImGui->GetTextLineHeight(), 0), vector(255,0,255), 0);
            ImGui->PushTextWrapPos((ImGui->GetCursorPos())->x + wrap_width);
            ImGui->Text("aaaaaaaa bbbbbbbb, c cccccccc,dddddddd. d eeeeeeee   ffffffff. gggggggg!hhhhhhhh");
            ImGui->DrawlistAddRectFilled(draw_list, ImGui->GetItemRectMin(), ImGui->GetItemRectMax(), vector(255,255,0), 0);
            ImGui->PopTextWrapPos();

            ImGui->TreePop();
        }

        if (ImGui->TreeNode("UTF-8 Text"))
        {
            // UTF-8 test with Japanese characters
            // (Needs a suitable font, try Noto, or Arial Unicode, or M+ fonts. Read misc/fonts/README.txt for details.)
            // - From C++11 you can use the u8"my text" syntax to encode literal strings as UTF-8
            // - For earlier compiler, you may be able to encode your sources as UTF-8 (e.g. Visual Studio save your file as 'UTF-8 without signature')
            // - FOR THIS DEMO FILE ONLY, BECAUSE WE WANT TO SUPPORT OLD COMPILERS, WE ARE *NOT* INCLUDING RAW UTF-8 CHARACTERS IN THIS SOURCE FILE.
            //   Instead we are encoding a few strings with hexadecimal constants. Don't do this in your application!
            //   Please use u8"text in any language" in your application!
            // Note that characters values are preserved even by InputText() if the font cannot be displayed, so you can safely copy & paste garbled characters into another application.
            ImGui->TextWrapped("CJK text will only appears if the font was loaded with the appropriate CJK character ranges. Call io.Font->AddFontFromFileTTF() manually to load extra character ranges. Read misc/fonts/README.txt for details.");
            ImGui->Text("Hiragana: \xe3\x81\x8b\xe3\x81\x8d\xe3\x81\x8f\xe3\x81\x91\xe3\x81\x93 (kakikukeko)"); // Normally we would use u8"blah blah" with the proper characters directly in the string.
            ImGui->Text("Kanjis: \xe6\x97\xa5\xe6\x9c\xac\xe8\xaa\x9e (nihongo)");
            static char buf[32];
			buf = "\xe6\x97\xa5\xe6\x9c\xac\xe8\xaa\x9e";
            ImGui->InputText("UTF-8 input", buf, 32, 0);
            ImGui->TreePop();
        }
        ImGui->TreePop();
    }

    if (ImGui->TreeNode("Images"))
    {
        ImGui->TextWrapped("Below we are displaying the font texture (which is the only texture we have access to in this demo). Use the 'ImTextureID' type as storage to pass pointers or identifier to your own texture data. Hover the texture for a zoomed view!");

        // Here we are grabbing the font texture because that's the only one we have access to inside the demo code.
        // Remember that ImTextureID is just storage for whatever you want it to be, it is essentially a value that will be passed to the render function inside the ImDrawCmd structure.
        // If you use one of the default imgui_impl_XXXX.cpp renderer, they all have comments at the top of their file to specify what they expect to be stored in ImTextureID.
        // (for example, the imgui_impl_dx11.cpp renderer expect a 'ID3D11ShaderResourceView*' pointer. The imgui_impl_glfw_gl3.cpp renderer expect a GLuint OpenGL texture identifier etc.)
        // If you decided that ImTextureID = MyEngineTexture*, then you can pass your MyEngineTexture* pointers to ImGui::Image(), and gather width/height through your own functions, etc.
        // Using ShowMetricsWindow() as a "debugger" to inspect the draw data that are being passed to your render will help you debug issues if you are confused about this.
        // Consider using the lower-level ImDrawList::AddImage() API, via ImGui::GetWindowDrawList()->AddImage().
        void* my_tex_id = ImGui->GetIoFontsTexId();
        var my_tex_w = ImGui->GetIoFontsTexWidth();
        var my_tex_h = ImGui->GetIoFontsTexHeight();

        ImGui->Text(_chr(str_printf(NULL, "%.0fx%.0f", (double)my_tex_w, (double)my_tex_h)));
        VECTOR* pos = ImGui->GetCursorScreenPos();
        ImGui->ImageScaleColorTexId(my_tex_id, vector(my_tex_w, my_tex_h, 0), vector(0,0,0), vector(1,1,0), vector(255,255,255), 255, vector(255,255,255), 128);
        if (ImGui->IsItemHovered())
        {
            ImGui->BeginTooltip();
            var region_sz = 32.0;
            var region_x = (ImGui->GetIoMousePos())->x - pos->x - region_sz * 0.5;
            if (region_x < 0.0) region_x = 0.0; else if (region_x > my_tex_w - region_sz) region_x = my_tex_w - region_sz;
            var region_y = (ImGui->GetIoMousePos())->y - pos->y - region_sz * 0.5;
            if (region_y < 0.0) region_y = 0.0; else if (region_y > my_tex_h - region_sz) region_y = my_tex_h - region_sz;
            var zoom = 4.0;
            ImGui->Text(_chr(str_printf(NULL, "Min: (%.2f, %.2f)", (double)region_x, (double)region_y)));
            ImGui->Text(_chr(str_printf(NULL, "Max: (%.2f, %.2f)", (double)region_x + (double)region_sz, (double)region_y + (double)region_sz)));
            VECTOR* uv0 = vector((region_x) / my_tex_w, (region_y) / my_tex_h, 0);
            VECTOR* uv1 = vector((region_x + region_sz) / my_tex_w, (region_y + region_sz) / my_tex_h, 0);
            ImGui->ImageScaleColorTexId(my_tex_id, vector(region_sz * zoom, region_sz * zoom, 0), uv0, uv1, vector(255,255,255), 255, vector(255,255,255),128);
            ImGui->EndTooltip();
        }
        ImGui->TextWrapped("And now some textured buttons..");
        static int pressed_count = 0;
        int i; for (i = 0; i < 8; i++)
        {
            ImGui->PushId(i);
            int frame_padding = -1 + i;     // -1 = uses default padding
            if (ImGui->ImageButtonTexId(my_tex_id, vector(32,32, 0), vector(0,0,0), vector(32.0 / my_tex_w, 32 / my_tex_h, 0), frame_padding, vector(0,0,0), 255, vector(1, 1, 1), 1))
                pressed_count += 1;
            ImGui->PopId();
            ImGui->SameLine();
        }
        ImGui->NewLine();
        ImGui->Text(_chr(str_printf(NULL, "Pressed %d times.", pressed_count)));
        
        ImGui->TreePop();
    }


    if (ImGui->TreeNode("Combo"))
    {
        // Expose flags as checkbox for the demo
        static int flags = 0;
        ImGui->CheckboxFlag("ImGuiComboFlags_PopupAlignLeft", &flags, ImGuiComboFlags_PopupAlignLeft);
        ImGui->SameLine(); HelpMarker("Only makes a difference if the popup is larger than the combo");
        if (ImGui->CheckboxFlag("ImGuiComboFlags_NoArrowButton", &flags, ImGuiComboFlags_NoArrowButton)) {
            //flags &= ~ImGuiComboFlags_NoPreview;     // Clear the other flag, as we cannot combine both
        }
        if (ImGui->CheckboxFlag("ImGuiComboFlags_NoPreview", &flags, ImGuiComboFlags_NoPreview)) {
            //flags &= ~ImGuiComboFlags_NoArrowButton; // Clear the other flag, as we cannot combine both
        }
        // General BeginCombo() API, you have full control over your selection data and display type.
        // (your selection data could be an index, a pointer to the object, an id for the object, a flag stored in the object itself, etc.)
        combo_items[0] = "AAAA";
        combo_items[1] = "0BBBB";
        combo_items[2] = "CCCC";
        combo_items[3] = "DDDD";
        combo_items[4] = "EEEE";
        combo_items[5] = "FFFF";
        combo_items[6] = "GGGG";
        combo_items[7] = "HHHH";
        combo_items[8] = "IIII";
        combo_items[9] = "JJJJ";
        combo_items[10] = "KKKK";
        combo_items[11] = "LLLLLLL";
        combo_items[12] = "MMMM";
        combo_items[13] = "OOOOOOO";
        if (ImGui->BeginCombo("combo 1", item_current, flags)) // The second parameter is the label previewed before opening the combo.
        {
            int n; for (n = 0; n < 14; n++)
            {
                int is_selected = (item_current == combo_items[n]);
                if (ImGui->SelectableDirect(combo_items[n], is_selected))
                    item_current = combo_items[n];
                if (is_selected)
                    ImGui->SetItemDefaultFocus();   // Set the initial focus when opening the combo (scrolling + for keyboard navigation support in the upcoming navigation branch)
            }
            ImGui->EndCombo();
        }
        // Simplified one-liner Combo() API, using values packed in a single constant string
        static int item_current_2 = 0;
        ImGui->Combo("combo 2 (one-liner)", &item_current_2, "aaaa\0bbbb\0cccc\0dddd\0eeee\0\0", -1);

        ImGui->TreePop();
    }

    if (ImGui->TreeNode("Selectables"))
    {
        // Selectable() has 2 overloads:
        // - The one taking "bool selected" as a read-only selection information. When Selectable() has been clicked is returns true and you can alter selection state accordingly.
        // - The one taking "bool* p_selected" as a read-write selection information (convenient in some cases)
        // The earlier is more flexible, as in real application your selection may be stored in a different manner (in flags within objects, as an external list, etc).
        if (ImGui->TreeNode("Basic"))
        {
            static int selection[5] = { 0, 1, 0, 0, 0 };
            ImGui->SelectableDirect("1. I am selectable", &selection[0]);
            ImGui->SelectableDirect("2. I am selectable", &selection[1]);
            ImGui->Text("3. I am not selectable");
            ImGui->SelectableDirect("4. I am selectable", &selection[3]);
            if (ImGui->Selectable("5. I am double clickable", &selection[4], ImGuiSelectableFlags_AllowDoubleClick))
            {
                selection[4] = !selection[4];
                if (ImGui->IsMouseDoubleClicked(0)) {
                    selection[4] = !selection[4];
                }
            }
            ImGui->TreePop();
        }
        
        if (ImGui->TreeNode("Selection State: Single Selection"))
        {
            static int selected = -1;
            int n;for (n = 0; n < 5; n++)
            {
                STRING *buf = str_printf(NULL, "Object %d", n);
                if (ImGui->SelectableDirect(_chr(buf), selected == n))
                    selected = n;
            }
            ImGui->TreePop();
        }
        if (ImGui->TreeNode("Selection State: Multiple Selection"))
        {
            HelpMarker("Hold CTRL and click to select multiple items.");
            static int selection[5] = { 0, 0, 0, 0, 0 };
            int n; for (n = 0; n < 5; n++)
            {
                STRING *buf = str_printf(NULL, "Object %d", n);
                if (ImGui->SelectableDirect(_chr(buf), selection[n]))
                {
                    if (!ImGui->GetIoKeyCtrl()) {    // Clear selection when CTRL is not held
                        int l; for (l = 0; l < 5; l++) {
                            selection[l] = 0;
                        }
                    }
                    selection[n] ^= 1;
                }
            }
            ImGui->TreePop();
        }
        if (ImGui->TreeNode("Rendering more text into the same line"))
        {
            // Using the Selectable() override that takes "bool* p_selected" parameter and toggle your booleans automatically.
            static int selected[3] = { 0, 0, 0 };
            ImGui->Selectable("main.c",    &selected[0], 0); ImGui->SameLineParams(300, 0); ImGui->Text(" 2,345 bytes");
            ImGui->Selectable("Hello.cpp", &selected[1], 0); ImGui->SameLineParams(300, 0); ImGui->Text("12,345 bytes");
            ImGui->Selectable("Hello.h",   &selected[2], 0); ImGui->SameLineParams(300, 0); ImGui->Text(" 2,345 bytes");
            ImGui->TreePop();
        }
        if (ImGui->TreeNode("In columns"))
        {
            ImGui->Columns(3, NULL, 0);
            static int selected[16] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
            int i; for (i = 0; i < 16; i++)
            {
                STRING *label = str_printf(NULL, "Item %d", i);
                if (ImGui->Selectable(_chr(label), &selected[i], 0)) {}
                ImGui->NextColumn();
            }
            ImGui->Columns(1, NULL, 0);
            ImGui->TreePop();
        }
        if (ImGui->TreeNode("Grid"))
        {
            static int selected[16] = { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 };
            int i; for (i = 0; i < 16; i++)
            {
                ImGui->PushId(i);
                if (ImGui->SelectableSize("Sailor", &selected[i], 0, vector(50,50,0)))
                {
                    // Note: We _unnecessarily_ test for both x/y and i here only to silence some static analyzer. The second part of each test is unnecessary.
                    int x = i % 4;
                    int y = i / 4;
                    if (x > 0)           { selected[i - 1] ^= 1; }
                    if (x < 3 && i < 15) { selected[i + 1] ^= 1; }
                    if (y > 0 && i > 3)  { selected[i - 4] ^= 1; }
                    if (y < 3 && i < 12) { selected[i + 4] ^= 1; }
                }
                if ((i % 4) < 3) ImGui->SameLine();
                ImGui->PopId();
            }
            ImGui->TreePop();
        }
        if (ImGui->TreeNode("Alignment"))
        {
            HelpMarker("Alignment applies when a selectable is larger than its text content.\nBy default, Selectables uses style.SelectableTextAlign but it can be overriden on a per-item basis using PushStyleVar().");
            static int selected[9] = { 1, 0, 1, 0, 1, 0, 1, 0, 1 };
            int y; for (y = 0; y < 3; y++)
            {
                int x; for (x = 0; x < 3; x++)
                {
                    VECTOR *alignment = vector(x / 2.0, y / 2.0, 0);
                    STRING *name = str_printf(NULL, "(%.1f,%.1f)", (double)alignment->x, (double)alignment->y);
                    if (x > 0) ImGui->SameLine();
                    ImGui->PushStyleVec(ImGuiStyleVar_SelectableTextAlign, alignment);
                    ImGui->SelectableSize(_chr(name), &selected[3*y+x], ImGuiSelectableFlags_None, vector(80,80,0));
                    ImGui->PopStyleVar(1);
                }
            }
            ImGui->TreePop();
        }
        ImGui->TreePop();
    }

    if (ImGui->TreeNode("Filtered Text Input"))
    {
        static char buf1[64]; 
        ImGui->InputText("default", buf1, 64, 0);
        static char buf2[64]; 
        ImGui->InputText("decimal", buf2, 64, ImGuiInputTextFlags_CharsDecimal);
        static char buf3[64]; 
        ImGui->InputText("hexadecimal", buf3, 64, ImGuiInputTextFlags_CharsHexadecimal | ImGuiInputTextFlags_CharsUppercase);
        static char buf4[64]; 
        ImGui->InputText("uppercase", buf4, 64, ImGuiInputTextFlags_CharsUppercase);
        static char buf5[64]; 
        ImGui->InputText("no blank", buf5, 64, ImGuiInputTextFlags_CharsNoBlank);

        ImGui->Text("Password input");
        static char bufpass[64];
        ImGui->InputText("password", bufpass, 64, ImGuiInputTextFlags_Password | ImGuiInputTextFlags_CharsNoBlank);
        ImGui->SameLine(); HelpMarker("Display all characters as '*'.\nDisable clipboard cut and copy.\nDisable logging.\n");
        ImGui->InputTextWithHint("password (w/ hint)", "<password>", bufpass, 64, ImGuiInputTextFlags_Password | ImGuiInputTextFlags_CharsNoBlank);
        ImGui->InputText("password (clear)", bufpass, 64, ImGuiInputTextFlags_CharsNoBlank);

        ImGui->TreePop();
    }

    if (ImGui->TreeNode("Multi-line Text Input"))
    {
        // Note: we are using a fixed-sized buffer for simplicity here. See ImGuiInputTextFlags_CallbackResize
        // and the code in misc/cpp/imgui_stdlib.h for how to setup InputText() for dynamically resizing strings.
        static int flags = ImGuiInputTextFlags_AllowTabInput;
        HelpMarker("You can use the ImGuiInputTextFlags_CallbackResize facility if you need to wire InputTextMultiline() to a dynamic string type. See misc/cpp/imgui_stdlib.h for an example. (This is not demonstrated in imgui_demo.cpp)");
        ImGui->CheckboxFlag("ImGuiInputTextFlags_ReadOnly", &flags, ImGuiInputTextFlags_ReadOnly);
        ImGui->CheckboxFlag("ImGuiInputTextFlags_AllowTabInput", &flags, ImGuiInputTextFlags_AllowTabInput);
        ImGui->CheckboxFlag("ImGuiInputTextFlags_CtrlEnterForNewLine", &flags, ImGuiInputTextFlags_CtrlEnterForNewLine);
        ImGui->InputTextMultiline("##source", _chr(text), 4096, -1, ImGui->GetTextLineHeight() * 16, flags);
        ImGui->TreePop();
    }

    if (ImGui->TreeNode("Plots Widgets"))
    {
        static int animate = 1;
        ImGui->Checkbox("Animate", &animate);

        static float arr[7] = { 0.6, 0.1, 1.0, 0.5, 0.92, 0.1, 0.2 };
        ImGui->Plotlines("Frame Times", arr, 7);

        // Create a dummy array of contiguous float values to plot
        // Tip: If your float aren't contiguous but part of a structure, you can pass a pointer to your first float and the sizeof() of your structure in the Stride parameter.
        static float values[90];
        static int values_offset = 0;
        static double refresh_time = 0.0;
        if (!animate || refresh_time == 0.0)
            refresh_time = ImGui->GetTime();
        while (refresh_time < ImGui->GetTime()) // Create dummy data at fixed 60 hz rate for the demo
        {
            static float phase = 0.0;
            values[values_offset] = cos(phase);
            values_offset = (values_offset+1) % 90;
            phase += 0.10*values_offset;
            refresh_time += 1.0/60.0;
        }
        ImGui->PlotLines("Lines", values, 90, values_offset, "avg 0.0", -1.0, 1.0, vector(0,80,0));
        ImGui->PlotHistogram("Histogram", arr, 7, 0, NULL, 0.0, 1.0, vector(0,80, 0), 4);

        // Animate a simple progress bar
        static var progress = 0.0;
        static var progress_dir = 1.0;
        if (animate)
        {
            progress += progress_dir * 0.4 * ImGui->GetIoDeltaTime();
            if (progress >= 1.1) { progress = 1.1; progress_dir *= -1.0; }
            if (progress <= -0.1) { progress = -0.1; progress_dir *= -1.0; }
        }

        // Typically we would use ImVec2(-1.0f,0.0f) to use all available width, or ImVec2(width,0.0f) for a specified width. ImVec2(0.0f,0.0f) uses ItemWidth.
        ImGui->ProgressBar(progress, vector(0.0,0.0,0), NULL);
        ImGui->SameLineParams(0.0, (ImGui->GetStyleItemInnerSpacing()).x);
        ImGui->Text("Progress Bar");

        var progress_saturated = ifelse(progress < 0.0, 0.0, ifelse(progress > 1.0, 1.0, progress));
        STRING *buf = str_printf(NULL, "%d/%d", (int)(progress_saturated*1753), 1753);
        ImGui->ProgressBar(progress, vector(0,0,0), _chr(buf));
        
        ImGui->TreePop();
    }

    if (ImGui->TreeNode("Color/Picker Widgets"))
    {
        static float color[3] = {0.5647, 0.5647, 0.6039};
        static float color1[4] = {0.5647, 0.5647, 0.6039, 0.7843};
        static int misc_flags = ImGuiColorEditFlags_AlphaPreview | ImGuiColorEditFlags_NoDragDrop;
        ImGui->CheckboxFlag("With Alpha Preview", &misc_flags, ImGuiColorEditFlags_AlphaPreview);
        ImGui->CheckboxFlag("With Half Alpha Preview", &misc_flags, ImGuiColorEditFlags_AlphaPreview);
        ImGui->CheckboxFlag("No Drag and Drop", &misc_flags, ImGuiColorEditFlags_NoDragDrop);
        ImGui->CheckboxFlag("No Options Menu", &misc_flags, ImGuiColorEditFlags_NoOptions); 
        ImGui->SameLine(); 
        HelpMarker("Right-click on the individual color widget to show options.");
        ImGui->CheckboxFlag("With HDR", &misc_flags, ImGuiColorEditFlags_HDR); 
        ImGui->SameLine(); 
        HelpMarker("Currently all this does is to lift the 0..1 limits on dragging widgets.");
        
        ImGui->Text("Color widget:");
        ImGui->SameLine(); HelpMarker("Click on the colored square to open a color picker.\nCTRL+click on individual component to input value.\n");
        ImGui->ColorEdit3("MyColor##1", color, misc_flags);

        ImGui->Text("Color widget HSV with Alpha:");
        ImGui->ColorEdit4("MyColor##2", color1, misc_flags);

        ImGui->Text("Color widget with Float Display:");
        ImGui->ColorEdit4("MyColor##2f", color1, ImGuiColorEditFlags_Float | misc_flags);

        ImGui->Text("Color button with Picker:");
        ImGui->SameLine(); HelpMarker("With the ImGuiColorEditFlags_NoInputs flag you can hide all the slider/text inputs.\nWith the ImGuiColorEditFlags_NoLabel flag you can pass a non-empty label which will only be used for the tooltip and picker popup.");
        ImGui->ColorEdit4("MyColor##3", color1, ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_NoLabel | misc_flags);

        ImGui->Text("Color button with Custom Picker Popup:");

        // Generate a dummy default palette. The palette will persist and can be edited.
        static int saved_palette_init = 1;
        if (saved_palette_init)
        {
            var n; for (n = 0; n < 32; n++)
            {
                ImGui->ColorConvertHSVtoRGB(n / 31.0, 0.8, 0.8, &saved_palette[n][0], &saved_palette[n][1], &saved_palette[n][2]);
                saved_palette[n][3] = 1; // Alpha
            }
            saved_palette_init = 0;
        }

        static float backup_color[4];
        int open_popup = ImGui->ColorButton("MyColor##3b", color1, misc_flags, vector(0, 0, 0));
        ImGui->SameLine();
        open_popup |= ImGui->Button("Palette");
        if (open_popup)
        {
            ImGui->OpenPopup("mypicker");
            backup_color[0] = color1[0];
            backup_color[1] = color1[1];
            backup_color[2] = color1[2];
            backup_color[3] = color1[3];
        }
        if (ImGui->BeginPopup("mypicker", 0))
        {
            ImGui->Text("MY CUSTOM COLOR PICKER WITH AN AMAZING PALETTE!");
            ImGui->Separator();
            ImGui->ColorPicker4("##picker", color1, misc_flags | ImGuiColorEditFlags_NoSidePreview | ImGuiColorEditFlags_NoSmallPreview, NULL);
            ImGui->SameLine();

            ImGui->BeginGroup(); // Lock X position
            ImGui->Text("Current");
            ImGui->ColorButton("##current", color1, ImGuiColorEditFlags_NoPicker | ImGuiColorEditFlags_AlphaPreviewHalf, vector(60,40,0));
            ImGui->Text("Previous");
            if (ImGui->ColorButton("##previous", backup_color, ImGuiColorEditFlags_NoPicker | ImGuiColorEditFlags_AlphaPreviewHalf, vector(60,40,0)))
            {
                color1[0] = backup_color[0];
                color1[1] = backup_color[1];
                color1[2] = backup_color[2];
                color1[3] = backup_color[3];
            }
            ImGui->Separator();
            ImGui->Text("Palette");
            int n; for (n = 0; n < 32; n++)
            {
                ImGui->PushId(n);
                if ((n % 8) != 0)
                {
                    ImGui->SameLineParams(0.0, (ImGui->GetStyleItemSpacing())->y);
                }
                float tmp[3];
                tmp[0] = saved_palette[n][0];
                tmp[1] = saved_palette[n][1];
                tmp[2] = saved_palette[n][2];
                if (ImGui->ColorButton("##palette", tmp, ImGuiColorEditFlags_NoAlpha | ImGuiColorEditFlags_NoPicker | ImGuiColorEditFlags_NoTooltip, vector(20,20,0)))
                {
                    color1[0] = tmp[0];
                    color1[1] = tmp[1];
                    color1[2] = tmp[2];
                    color1[3] = color1[3];
                }

                // Allow user to drop colors into each palette entry
                // (Note that ColorButton is already a drag source by default, unless using ImGuiColorEditFlags_NoDragDrop)
                if (ImGui->BeginDragDropTarget())
                {
                    void* payload = ImGui->AcceptDragDropPayload(IMGUI_PAYLOAD_TYPE_COLOR_3F, 0);
                    if (payload)
                    {
                        float *cl = ImGui->DragDropPayloadData(payload);
                        saved_palette[n][0] = cl[0];
                        saved_palette[n][1] = cl[1];
                        saved_palette[n][2] = cl[2];
                    }
                    void* payload2 = ImGui->AcceptDragDropPayload(IMGUI_PAYLOAD_TYPE_COLOR_4F, 0);
                    if (payload2)
                    {
                        float *cl = ImGui->DragDropPayloadData(payload);
                        saved_palette[n][0] = cl[0];
                        saved_palette[n][1] = cl[1];
                        saved_palette[n][2] = cl[2];
                        saved_palette[n][3] = cl[3];
                    }
                    ImGui->EndDragDropTarget();
                }

                ImGui->PopId();
            }
            ImGui->EndGroup();
            ImGui->EndPopup();
        }

        ImGui->Text("Color button only:");
        ImGui->ColorButton("MyColor##3c", color1, misc_flags, vector(80,80, 0));

        ImGui->Text("Color picker:");
        static int alpha = 1;
        static int alpha_bar = 1;
        static int side_preview = 1;
        static int ref_color = 0;
        static float ref_color_v[4] = {1.0,0.0,1.0,0.5};
        static int display_mode = 0;
        static int picker_mode = 0;
        float *ref;
        ImGui->Checkbox("With Alpha", &alpha);
        ImGui->Checkbox("With Alpha Bar", &alpha_bar);
        ImGui->Checkbox("With Side Preview", &side_preview);
        if (side_preview)
        {
            ImGui->SameLine();
            ImGui->Checkbox("With Ref Color", &ref_color);
            if (ref_color)
            {
                ref = ref_color_v;
                ImGui->SameLine();
                ImGui->ColorEdit4("##RefColor", ref_color_v, ImGuiColorEditFlags_NoInputs | misc_flags);
            }
            else
            {
                ref = NULL;
            }
        }
        ImGui->Combo("Display Mode", &display_mode, "Auto/Current\0None\0RGB Only\0HSV Only\0Hex Only\0", -1);
        ImGui->SameLine(); HelpMarker("ColorEdit defaults to displaying RGB inputs if you don't specify a display mode, but the user can change it with a right-click.\n\nColorPicker defaults to displaying RGB+HSV+Hex if you don't specify a display mode.\n\nYou can change the defaults using SetColorEditOptions().");
        ImGui->Combo("Picker Mode", &picker_mode, "Auto/Current\0Hue bar + SV rect\0Hue wheel + SV triangle\0", -1);
        ImGui->SameLine(); HelpMarker("User can right-click the picker to change mode.");
        int flags = misc_flags;
        if (!alpha)            flags |= ImGuiColorEditFlags_NoAlpha;        // This is by default if you call ColorPicker3() instead of ColorPicker4()
        if (alpha_bar)         flags |= ImGuiColorEditFlags_AlphaBar;
        if (!side_preview)     flags |= ImGuiColorEditFlags_NoSidePreview;
        if (picker_mode == 1)  flags |= ImGuiColorEditFlags_PickerHueBar;
        if (picker_mode == 2)  flags |= ImGuiColorEditFlags_PickerHueWheel;
        if (display_mode == 1) flags |= ImGuiColorEditFlags_NoInputs;       // Disable all RGB/HSV/Hex displays
        if (display_mode == 2) flags |= ImGuiColorEditFlags_DisplayRGB;     // Override display mode
        if (display_mode == 3) flags |= ImGuiColorEditFlags_DisplayHSV;
        if (display_mode == 4) flags |= ImGuiColorEditFlags_DisplayHex;
 
        ImGui->ColorPicker4("MyColor##4", color1, flags, ref );

        ImGui->Text("Programmatically set defaults:");
        ImGui->SameLine(); HelpMarker("SetColorEditOptions() is designed to allow you to set boot-time default.\nWe don't have Push/Pop functions because you can force options on a per-widget basis if needed, and the user can change non-forced ones with the options menu.\nWe don't have a getter to avoid encouraging you to persistently save values that aren't forward-compatible.");
        if (ImGui->Button("Default: Uint8 + HSV + Hue Bar"))
            ImGui->SetColorEditOptions(ImGuiColorEditFlags_Uint8 | ImGuiColorEditFlags_DisplayHSV | ImGuiColorEditFlags_PickerHueBar);
        if (ImGui->Button("Default: Float + HDR + Hue Wheel"))
            ImGui->SetColorEditOptions(ImGuiColorEditFlags_Float | ImGuiColorEditFlags_HDR | ImGuiColorEditFlags_PickerHueWheel);

        // HSV encoded support (to avoid RGB<>HSV round trips and singularities when S==0 or V==0)
        static float color_stored_as_hsv[4] = {0.23, 1.0, 1.0, 1.0};
        ImGui->Spacing();
        ImGui->Text("HSV encoded colors");
        ImGui->SameLine(); HelpMarker("By default, colors are given to ColorEdit and ColorPicker in RGB, but ImGuiColorEditFlags_InputHSV allows you to store colors as HSV and pass them to ColorEdit and ColorPicker as HSV. This comes with the added benefit that you can manipulate hue values with the picker even when saturation or value are zero.");
        ImGui->Text("Color widget with InputHSV:");
        ImGui->ColorEdit4("HSV shown as HSV##1", color_stored_as_hsv, ImGuiColorEditFlags_DisplayRGB | ImGuiColorEditFlags_InputHSV | ImGuiColorEditFlags_Float);
        ImGui->ColorEdit4("HSV shown as RGB##1", color_stored_as_hsv, ImGuiColorEditFlags_DisplayHSV | ImGuiColorEditFlags_InputHSV | ImGuiColorEditFlags_Float);
        ImGui->DragFloat4("Raw HSV values", color_stored_as_hsv, 0.01, 0.0, 1.0, "%.3f", 1);

        ImGui->TreePop();
    }

    if (ImGui->TreeNode("Range Widgets"))
    {
        static float begin = 10;
        static float end = 90;
        static int begin_i = 100;
        static int end_i = 1000;
        ImGui->DragFloatRange2("range", &begin, &end, 0.25, 0.0, 100.0, "Min: %.1f %%", "Max: %.1f %%", 1);
        ImGui->DragIntRange2("range int (no bounds)", &begin_i, &end_i, 5, 0, 0, "Min: %d units", "Max: %d units");
        ImGui->TreePop();
    }
}

void loop()
{
	imgui_start_imode();
	
	ShowDemoWindowWidgets();
	
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