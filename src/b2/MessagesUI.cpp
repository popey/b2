#include <shared/system.h>
#include "MessagesUI.h"
#include "dear_imgui.h"
#include "Messages.h"

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

static const ImVec4 INFO_COLOUR(1.f,1.f,1.f,1.f);
static const ImVec4 WARNING_COLOUR(1.f,1.f,0.f,1.f);
static const ImVec4 ERROR_COLOUR(1.f,0.f,0.f,1.f);

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

MessagesUI::MessagesUI() {
}

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

MessagesUI::~MessagesUI() {
}

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

void MessagesUI::DoMessageImGui(const MessageList::Message *m) {
    ImGuiStyleColourPusher pusher;

    switch(m->type) {
    case MessageType_Info:
        pusher.Push(ImGuiCol_Text,INFO_COLOUR);
        break;

    case MessageType_Warning:
        pusher.Push(ImGuiCol_Text,WARNING_COLOUR);
        break;

    case MessageType_Error:
        pusher.Push(ImGuiCol_Text,ERROR_COLOUR);
        break;
    }

    ImGui::TextUnformatted(m->text.c_str(),m->text.c_str()+m->text.size());
}

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

class MessagesUIImpl:
    public MessagesUI
{
public:
    void SetMessageList(std::shared_ptr<MessageList> message_list) override;

    void DoImGui() override;
protected:
private:
    std::shared_ptr<MessageList> m_message_list;
};

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

std::unique_ptr<MessagesUI> MessagesUI::Create() {
    return std::make_unique<MessagesUIImpl>();
}

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

void MessagesUIImpl::SetMessageList(std::shared_ptr<MessageList> message_list) {
    m_message_list=std::move(message_list);
}

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

void MessagesUIImpl::DoImGui() {
    if(ImGui::Button("Clear")) {
        m_message_list->ClearMessages();
    }

    ImGui::SameLine();

    ImGuiIO &io=ImGui::GetIO();

    if(io.SetClipboardTextFn) {
        if(ImGui::Button("Copy")) {
            std::string text;

            m_message_list->ForEachMessage(
                [&text](const MessageList::Message *m) {
                text+=m->text;
            });

            (*io.SetClipboardTextFn)(io.ClipboardUserData,text.c_str());
        }
    }

    ImGui::BeginChild("",ImVec2(),true);

    m_message_list->ForEachMessage(
        [this](const MessageList::Message *m) {
        this->DoMessageImGui(m);
    });

    ImGui::EndChild();
}

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////
