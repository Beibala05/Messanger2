#include "tools.h"

#include "../../read_file.h"

Tools::Tools(Widget* parent)
{
        this->setParent(parent);
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
}

void Tools::resizeEvent(ResizeEvent* event)
{
        message->setGeometry(5, 5, width() - 115, 50);
        send->setGeometry(width() - 110, 5, 50, 50);
        share->setGeometry(width() - 55, 5, 50, 50);

        Widget::resizeEvent(event);
}