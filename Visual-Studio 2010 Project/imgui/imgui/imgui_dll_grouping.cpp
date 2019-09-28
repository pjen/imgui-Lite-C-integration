#include "dllmain.h"

DLLFUNC var imgui_collapsing_header(char *label, void *p_open, long flags)
{
	bool *dirty = (bool*)p_open;
	bool res = ImGui::CollapsingHeader(label, dirty, flags);
	return res ? _VAR(1) : _VAR(0);
}

DLLFUNC void imgui_tree_pop()
{
	ImGui::TreePop();
}

DLLFUNC void imgui_begin_group()
{
	ImGui::BeginGroup();
}

DLLFUNC void imgui_end_group()
{
	ImGui::EndGroup();
}

DLLFUNC var imgui_tree_node(char *label)
{
	bool res = ImGui::TreeNode(label);
	return res ? _VAR(1) : _VAR(0);
}

DLLFUNC var imgui_treenode(void *ptr_id, char *fmt)
{
	bool res = ImGui::TreeNode(ptr_id, fmt);
	return res ? _VAR(1) : _VAR(0);
}

DLLFUNC var imgui_get_tree_node_to_label_spacing()
{
	return _VAR(ImGui::GetTreeNodeToLabelSpacing());
}

DLLFUNC int imgui_tree_node_ex(void *ptr_id, int flags, char *fmt)
{
	bool res = ImGui::TreeNodeEx(ptr_id, flags, fmt);
	return res ? 1 : 0;
}

DLLFUNC int imgui_begin_drag_drop_target()
{
	bool res = ImGui::BeginDragDropTarget();
	return res ? 1 : 0;
}

DLLFUNC void imgui_end_drag_drop_target()
{
	ImGui::EndDragDropTarget();
}

DLLFUNC void* imgui_accept_drag_drop_payload(char *type, int flags)
{
	return (void*)ImGui::AcceptDragDropPayload(type, flags);
}

DLLFUNC void* imgui_drag_drop_payload_data(void *pl)
{
	ImGuiPayload *payload = (ImGuiPayload*)pl;
	return payload->Data;
}

DLLFUNC int imgui_begin_tabbar(char* str_id, long flags)
{
	bool res = ImGui::BeginTabBar(str_id, flags);
	return res ? 1 : 0;
}

DLLFUNC void imgui_end_tabbar()
{
	ImGui::EndTabBar();
}

DLLFUNC int imgui_begin_tabitem(char* label,void* state,long flags)
{
	bool* dirty = (bool*)state;
	bool res = ImGui::BeginTabItem(label, dirty,flags);
	return res ? 1 : 0;
}

DLLFUNC void imgui_end_tabitem()
{	
	ImGui::EndTabItem(); 
}