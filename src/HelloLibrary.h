//
// Created by Kasper de Bruin on 14/12/2023.
//
#pragma once

#include <UIWindows/UIWindow.h>
#include <imgui.h>

namespace HummingBirdKasper {
    class HelloLibrary : public HummingBirdCore::UIWindow{
    public:
        HelloLibrary(): HelloLibrary(ImGuiWindowFlags_None) {}
        HelloLibrary(const ImGuiWindowFlags flags) : UIWindow(flags) {

        }

        ~HelloLibrary();

        void Render() override;

        void HelloWorld();
    };

} // HummingBirdKasper
