//
// Created by Kasper de Bruin on 14/12/2023.
//

#include "HelloLibrary.h"
#include <iostream>

namespace HummingBirdKasper {
    void HelloLibrary::HelloWorld() {
    }

    HelloLibrary::~HelloLibrary() {
        std::cout << "Hello Library destroyed" << std::endl;
    }

    void HelloLibrary::Render() {
        ImGui::Text("Hello Library");
    }
} // HummingBirdKasper
