#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QToolButton>
#include <QGridLayout>
#include <QTextEdit>
#include <QLabel>
#include <QToolBar>
#include <QFileDialog>
#include <QMessageBox>
#include <QToolButton>
#include <QGridLayout>
#include <QDockWidget>
#include <QWidget>
#include <QTextEdit>
#include <QLabel>
#include <QMenuBar>
#include <QMenu>
#include <QApplication>
#include <QColorDialog>
#include <QFontDialog>
#include <QFontComboBox>
#include <QPushButton>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots :
    void open ();
    void newFile ();
    void saveCurrent();
    void save ();
    void close ();
    void clear();
    void upper(bool isUpper);
    void toCamelCase();
    void changeTextSize(bool isIncrease);
    void showAboutInfo();
    void showHelpInfo();
    void changeSaveStatus();
    void toggleBoldStyle();
    void toggleItalicStyle();
    void insertNewLine();
    void saveToFile(const QString &fileName);
    void changeTextColor();
    void changeFont(const QFont &font);

private :
    QString currentFileName;
    QTextEdit *editor;
    QDockWidget *dock, *dock2;
    QWidget *dockWidget, *dockWidget2;
    QToolButton *bold, *italic, *newline, *textSizeUp, *textSizeDown, *textToCamel, *textClr;
    QToolButton *openF, *closeF, *newF, *saveAs, *saveF;
    QGridLayout *dockGrid, *dockGrid2;
    QToolBar *tools;
    QMenuBar *appMenuBar;
    QMenu *file, *edit, *help;
    QAction *aboutAction, *helpAction;
    QAction *fileOpen, *fileSave, *fileClose, *fileNew, *fileSaveCurr, *openFileAction;
    QAction *fileClear, *fileToUpper, *fileToLower,*fileToCamel, *fileIncreaseTextSize, *fileDecreaseTextSize;
    QFontComboBox *fontComboBox;
    QPushButton *colorButton;


};
#endif // MAINWINDOW_H
