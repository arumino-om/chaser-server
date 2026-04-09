#ifdef __APPLE__
#include <arm_acle.h>
#endif

#include "mainwindow.h"
#include <QApplication>
#include <QTranslator>
#include <QLibraryInfo>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // ダークテーマに変わらないように設定
    // (デフォルト:windows11 -> windowsvista)
    a.setStyle("windowsvista");

    QTranslator qtTranslator;

    // 返り値を無視
    (void) qtTranslator.load("qt_" + QLocale::system().name(), QLibraryInfo::path(QLibraryInfo::TranslationsPath));
    a.installTranslator(&qtTranslator);

    while (true) {
        MainWindow w;
        w.show();

        auto res = a.exec();
        if (!MainWindow::s_boot_nextgame) return res;
    }
}
