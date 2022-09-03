#include "pch.h"
#include "widget.h"

void Widget::Filter(const char* label, ImGuiTextFilter& filter, const char* hint)
{
    filter.Draw(label);

    if (strlen(filter.InputBuf) == 0)
    {
        ImDrawList* drawlist = ImGui::GetWindowDrawList();

        ImVec2 min = ImGui::GetItemRectMin();
        min.x += ImGui::GetStyle().FramePadding.x;
        min.y += ImGui::GetStyle().FramePadding.y;

        drawlist->AddText(min, ImGui::GetColorU32(ImGuiCol_TextDisabled), hint);
    }
}

ImVec2 Widget::CalcSize(short count, bool spacing, bool column)
{
    if (count == 1)
    {
        spacing = false;
    }

    // manually tested values
    float factor = ImGui::GetStyle().ItemSpacing.x / 2.0f;
    float x, width;

    if (count == 3)
    {
        factor = ImGui::GetStyle().ItemSpacing.x / 1.403f;
    }

    width = column ? (ImGui::GetColumnWidth() - ImGui::GetStyle().ItemSpacing.x - ImGui::GetStyle().WindowPadding.x)
                    : ImGui::GetWindowContentRegionWidth();

    if (spacing)
    {
        x = width / count - factor;
    }
    else
    {
        x = width / count;
    }

    return ImVec2(x, ImGui::GetFrameHeight());
}