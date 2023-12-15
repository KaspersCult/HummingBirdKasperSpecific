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

  // Create the right side of the screen
  ImGui::BeginGroup();
  // Top of right side
  ImGui::BeginChild("item view",
                    ImVec2(0, -ImGui::GetFrameHeightWithSpacing()));
  // create list of folders in client
  if (m_selectedClientIndex != -1) {

    if (ImGui::Button("<")) {
      m_currentFolder.backFolder();
    }
    ImGui::SameLine();
    if (ImGui::Button(">")) {
      m_currentFolder.forwardFolder();
    }
    ImGui::SameLine();
    ImGui::BeginChild("##VisualLinkLauncher", ImVec2(120, 20));
    ImGui::SameLine();
    ImGui::Text("Client: %s",
                m_clients[m_selectedClientIndex].getName().c_str());
    ImGui::EndChild();
    ImGui::SameLine();

    ImGui::Dummy(ImVec2(40.0f, 0.0f));
    ImGui::SameLine();
    ImGui::Dummy(ImVec2(40.0f, 0.0f));
    ImGui::SameLine();
    ImGui::Text("Location: %s", m_currentFolder.getLocation().c_str());
    ImGui::Separator();
  }


  // left of right side -- list of folders
  ImGui::BeginChild("left pane", ImVec2(150, 0), true);
  for(int i =0; i < m_currentFolder.getChildFolders().size(); i++){
    if(ImGui::Button(m_currentFolder.getChildFolders()[i].c_str())){
      m_currentFolder.changeFolder(m_currentFolder.getChildFolders()[i]);
    }
  }
  ImGui::EndChild();
  ImGui::SameLine();

  // right of right side -- list of commands
  ImGui::BeginChild("right pane",
                    ImVec2(0, -ImGui::GetFrameHeightWithSpacing()));
  ImGui::Text("VisualLinkLauncher");
  ImGui::Separator();

  for(int i = 0; i < m_clients[m_selectedClientIndex].getCommands().size(); i++){
    if(ImGui::Button(m_clients[m_selectedClientIndex].getCommands()[i].getName().c_str())){
      m_clients[m_selectedClientIndex].executeCommand(i);
    }
  }
  ImGui::EndChild();

  ImGui::EndChild();
  ImGui::EndGroup();


  if(m_clients[m_selectedClientIndex].getRunningCommands().size() > 0){
    ImGui::End();
    ImGui::Begin("terminalwindowje");
    m_clients[m_selectedClientIndex].getRunningCommands()[0].render();;
  }
}
} // namespace HummingBirdKasper::VisualLink