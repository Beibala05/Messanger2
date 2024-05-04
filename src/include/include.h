#ifndef INCLUDE_H
#define INCLUDE_H

// qt libs
#include <QApplication>
#include <QMainWindow>
#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QResizeEvent>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QFont>
#include <QIcon>
#include <QSize>
#include <QObject>
#include <QDebug>
#include <QLabel>
#include <QScrollArea>
#include <QTime>

#define MINIMUM_MESSAGER_HEIGHT 600
#define MINIMUM_MESSAGER_WIDTH  775

using Application       = QApplication;
using MainWindow        = QMainWindow;
using Widget            = QWidget;
using LineEdit          = QLineEdit;
using PushButton        = QPushButton;
using ResizeEvent       = QResizeEvent;
using String            = QString;
using File              = QFile;
using Font              = QFont;
using Icon              = QIcon;
using Size              = QSize;
using Object            = QObject;
using Label             = QLabel;
using ScrollArea        = QScrollArea;
using Time              = QTime;

typedef unsigned short u_sh;

#endif // INCLUDE_H