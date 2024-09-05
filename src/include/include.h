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
#include <QFileDialog>
#include <QStringList>
#include <QPixmap>
#include <QClipboard>
#include <QStandardPaths>
#include <QMessageBox>


#define MINIMUM_MESSAGER_HEIGHT     600 * 1.5
#define MINIMUM_MESSAGER_WIDTH      775 * 1.5

#define PATH_IS_EMPTY               -1
#define FILE_IS_EMPTY               -2
#define FILE_IS_NOT_EXISTS          -3


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
using FileDialog        = QFileDialog;
using StringList        = QStringList;
using Pixmap            = QPixmap;
using StandardPaths     = QStandardPaths;
using MessageBox        = QMessageBox;

typedef unsigned short u_sh;

#endif // INCLUDE_H