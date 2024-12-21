/**
 * @file main.cpp
 * @brief 包含主函数
 */

#include "mainwindow.h"
#include <QApplication>

/**
 * @brief main
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/favicon.ico")); // 设置图标
    MainWindow w;
    w.show();
    return a.exec();
}
