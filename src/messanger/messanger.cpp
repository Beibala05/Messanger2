#include "messanger.h"

#include "../read_file.h"

Messanger::Messanger(Widget* parent) : MainWindow(parent)
{
        centralWidget = new Widget(this);

        this->setCentralWidget(centralWidget);
        this->setMinimumSize(MINIMUM_MESSAGER_WIDTH, MINIMUM_MESSAGER_HEIGHT);
        this->setStyleSheet(read("../styles/main.css"));
        
        tools = new Tools(centralWidget);
}

Messanger::~Messanger()
{
        delete tools;
}

void Messanger::resizeEvent(ResizeEvent* event)
{
        tools->setGeometry(10, height() - 70, width() - 20, 50);

        MainWindow::resizeEvent(event);
}