#include "tools.h"

#include "../help.h"

#include "../messages/abstract.h"
#include "../messages/text_message.h"
#include "../messages/photo_message.h"

Tools::Tools(Widget* parent, Widget* chat, ScrollArea* scrollWidget)
{
        this->parent            = parent;
        this->chat              = chat;
        this->scrollWidget      = scrollWidget;
        this->setParent(this->parent);
        this->setMinimumSize(MINIMUM_MESSAGER_WIDTH, 60);
        this->setGeometry(10, MINIMUM_MESSAGER_HEIGHT - 70, MINIMUM_MESSAGER_WIDTH - 20, 50);

        message = new LineEdit(this);
        message->setGeometry(5, 5, 650, 50);
        message->setPlaceholderText("Enter text here...");
        Font font = message->font();
        font.setPointSize(15);
        message->setFont(font);

        send = new PushButton(this);
        send->setGeometry(655, 5, 50, 50);
        send->setIcon(Icon("../res/tool_bar/send.png"));
        send->setIconSize(Size(40, 40));

        share = new PushButton(this);
        share->setGeometry(710, 5, 50, 50);
        share->setIcon(Icon("../res/tool_bar/share.png"));
        share->setIconSize(Size(40, 40));

        send->setStyleSheet(read("../styles/button.css"));
        share->setStyleSheet(read("../styles/button.css"));
        message->setStyleSheet(read("../styles/message_text.css"));
        this->setStyleSheet(read("../styles/tool_bar.css"));

        Object::connect(send, &PushButton::clicked, this, &Tools::createTextMessageSlot);
        Object::connect(share, &PushButton::clicked, this, &Tools::shareDataSlot);
        Object::connect(message, &LineEdit::returnPressed, this, &Tools::createTextMessageSlot);
}

void Tools::resizeEvent(ResizeEvent* event)
{
        message->setGeometry(5, 5, width() - 115, 50);
        send->setGeometry(width() - 110, 5, 50, 50);
        share->setGeometry(width() - 55, 5, 50, 50);

        Widget::resizeEvent(event);
}

void Tools::createTextMessageSlot()
{
        if (message->text().isEmpty()) return;
        
        u_sh position = AbstractMessage::count() % 2 == 0 ? MessagePosition::RIGHT : MessagePosition::LEFT; 
        AbstractMessage* newTextMessage = new TextMessage(scrollWidget, chat, parent, position, message->text());
        message->clear();
}

void Tools::shareDataSlot()
{
        StringList supportedFormats;
        supportedFormats << "*.png" << "*.mp4" << "*.jpg";

        String selectedFilter;
        String fileDir = FileDialog::getOpenFileName(this, tr("Open File"), "", supportedFormats.join(";;"), &selectedFilter);

        if (fileDir != "")
        {
                u_sh position = AbstractMessage::count() % 2 == 0 ? MessagePosition::RIGHT : MessagePosition::LEFT; 
                AbstractMessage* newPhotoMessage = new PhotoMessage(scrollWidget, chat, parent, position, fileDir);
                message->clear();
        }
}