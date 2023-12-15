//
// Created by Kasper de Bruin on 15/12/2023.
//

#include "VisualLinkLauncher.h"
namespace HummingBirdKasper::VisualLink {
void VisualLinkLauncher::render() {
  // Create list at the left side of the screen
  ImGui::BeginChild("VisualLinkLauncher", ImVec2(150, 0), true);
  ImGui::Text("VisualLinkLauncher");
  ImGui::Separator();

  for (int i = 0; i < m_clients.size(); i++) {
    if (ImGui::Selectable(m_clients[i].getName().c_str(),
                          m_selectedClientIndex == i)) {
      changeClient(i);
    }
  }

  ImGui::EndChild();

  ImGui::SameLine();

  ImGui::BeginGroup();

  ImGui::BeginChild(
      "item view",
      ImVec2(0, -ImGui::GetFrameHeightWithSpacing())); // Leave room for 1 line
                                                       // below us
  // create list of folders in client
  if (m_selectedClientIndex != -1) {
    ImGui::Text("Client: %s",
                m_clients[m_selectedClientIndex].getName().c_str());
    ImGui::SameLine();
    ImGui::Dummy(ImVec2(40.0f, 0.0f));
    ImGui::SameLine();

    if(ImGui::Button("<")){
      m_currentFolder.backFolder();
    }
    ImGui::SameLine();
    if(ImGui::Button(">")){
        m_currentFolder.forwardFolder();
    }
    ImGui::SameLine();
    ImGui::Dummy(ImVec2(40.0f, 0.0f));
    ImGui::Text("Location: %s", m_currentFolder.getLocation().c_str());
    ImGui::Separator();
    ImGui::BeginChild("Client Folders", ImVec2(0, 0), true);

    for(int i = 0; i < m_currentFolder.getChildFolders().size(); i++) {
      if (ImGui::Button(m_currentFolder.getChildFolders()[i].c_str())) {

        m_currentFolder.changeToChildFolder(i);
      }
    }

    ImGui::EndChild();
  }

  ImGui::EndChild();

  ImGui::EndGroup();
}
} // namespace HummingBirdKasper::VisualLink