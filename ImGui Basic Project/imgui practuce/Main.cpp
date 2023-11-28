#include "EasyImGui.h"
#include <iostream>

int main()
{
    ImGuiSetup(L"hello world",600,800);

    clear_color = ImVec4(20, 20, 20, 255);

    //ImGui::ColorEdit3("clear color", (float*)&clear_color); 

    const char* items[] = { "Option 1", "Option 2", "Option 3", "Option 4" };
    int currentItem = 0;

    bool done = false;
    while (!done)
    {
        ImGuiLogic;
        
        ImGui::NewFrame();
        {   
            ImGui::Begin("Debug");
            ImGui::Text("%.3f ms/frame (%.1f FPS)", 1000.0f / io.Framerate, io.Framerate);
            ImGui::End();

            static float f = 0.0f;
            static int counter = 0;
            

            ImGui::Begin("Hello, world!");                          
            ImGui::Text("This is some useful text.");               
            ImGui::SliderFloat("Float", &f, 0.0f, 100.0f);                        
            ImGui::Combo("Select an option", &currentItem, items, IM_ARRAYSIZE(items));

            ImGui::InputFloat("input field", &f);

            if (currentItem == 2) {
                ImGui::Text("selected option 3.");
            }
            if (ImGui::Button("Button"))                            
                counter++;
            ImGui::SameLine();
            ImGui::Text("counter = %d", counter);
            ImGui::Text("counter = %f", f);
            
           
            ImGui::End();
        }

        ImGuiEndFrame;
    }
    ImGuiCleanup;
    return 0;
}

