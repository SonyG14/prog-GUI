#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    this->setWindowTitle("Text Editor");
    this->setFixedSize(700, 720);

    appMenuBar = menuBar();
    file = appMenuBar->addMenu("&File");
    edit = appMenuBar->addMenu("&Edit");
    help = appMenuBar->addMenu("&Help");

    fileOpen = new QAction("&Open", this);
    fileOpen->setIcon(QIcon::fromTheme("document-open"));
    fileOpen->setShortcut(QKeySequence::Open);

    fileNew = new QAction("&New file",this);

    fileSaveCurr = new QAction("&Save", this);
    fileSaveCurr->setShortcut(QKeySequence::Save);

    fileSave = new QAction("&Save As", this);
    fileSave->setIcon(QIcon::fromTheme("document-save"));
    fileSave->setShortcut(QKeySequence::SaveAs);

    fileClose = new QAction("&Close", this);
    fileClose->setIcon(QIcon::fromTheme("document-close"));
    fileClose->setShortcut(QKeySequence::Close);

    file->addAction(fileOpen);
    file->addSeparator();
    file->addAction(fileNew);
    file->addSeparator();
    file->addAction(fileSaveCurr);
    file->addAction(fileSave);
    file->addSeparator();
    file->addAction(fileClose);

    fileClear = new QAction("&Clear", this);

    fileToUpper = new QAction("&To uppercase", this);

    fileToLower = new QAction("To lowercase", this);

    fileToCamel = new QAction("To CamelCase", this);

    fileIncreaseTextSize = new QAction("Increase text size", this);

    fileDecreaseTextSize = new QAction("Decrease text size", this);

    edit->addAction(fileClear);
    edit->addSeparator();
    edit->addAction(fileToUpper);
    edit->addAction(fileToLower);
    edit->addAction(fileToCamel);
    edit->addSeparator();
    edit->addAction(fileIncreaseTextSize);
    edit->addAction(fileDecreaseTextSize);

    aboutAction = new QAction("About", this);

    helpAction = new QAction("Help", this);

    help->addAction(aboutAction);
    help->addAction(helpAction);

    tools = addToolBar("Tools");
    tools->addAction(fileOpen);
    tools->addAction(fileSave);
    tools->addAction(fileClose);

    editor = new QTextEdit ();
    this -> setCentralWidget ( editor );
    textSizeUp = new QToolButton();
    textSizeUp->setText("A+");
    textSizeUp->setFixedSize(QSize(56,56));
    textSizeDown = new QToolButton();
    textSizeDown->setText("A-");
    textSizeDown->setFixedSize(QSize(56,56));
    textToCamel = new QToolButton();
    textToCamel->setText("Camel");
    textToCamel->setFixedSize(QSize(56, 56));
    bold = new QToolButton();
    bold -> setText ( "B" );
    bold -> setFixedSize ( QSize (56, 56));
    newline = new QToolButton ();
    newline -> setText ( " \\ n " );
    newline -> setFixedSize ( QSize (56, 56));
    italic = new QToolButton ();
    italic -> setText (" I " );
    italic -> setFixedSize ( QSize (56, 56));
    textClr = new QToolButton();
    textClr->setText("Clr");
    textClr->setFixedSize(QSize(56, 56));
    colorButton = new QPushButton;
    colorButton->setFixedSize(QSize(56, 56));
    colorButton->setText("Колір");

    fontComboBox = new QFontComboBox;
    fontComboBox->setFixedSize(QSize(185, 25));

    dockGrid = new QGridLayout ();
    dockGrid->addWidget(bold, 0, 0);
    dockGrid->addWidget(italic, 1, 0);
    dockGrid->addWidget(newline, 2, 0);
    dockGrid->addWidget(textSizeUp, 0, 1);
    dockGrid->addWidget(textSizeDown, 1, 1);
    dockGrid->addWidget(textToCamel, 2, 1);
    dockGrid->addWidget(textClr, 0, 2);
    dockGrid->addWidget(colorButton, 1, 2);
    dockGrid->addWidget(fontComboBox, 4, 0);
    dockGrid -> setAlignment( Qt :: AlignLeft | Qt :: AlignTop );

    dock = new QDockWidget (" Dock " , this );
    dock -> setAllowedAreas ( Qt :: LeftDockWidgetArea );
    dock -> setFixedSize ( QSize (200 , 500));
    dockWidget = new QWidget ( dock );
    dockWidget -> setLayout ( dockGrid );
    dock -> setWidget ( dockWidget );
    this -> addDockWidget ( Qt :: LeftDockWidgetArea , dock );

    QToolButton *openF = new QToolButton;
    openF->setText("Open file");

    QToolButton *saveAs = new QToolButton;
    saveAs->setText("Save As");

    QToolButton *saveF = new QToolButton;
    saveF->setText("Save");

    QToolButton *newF = new QToolButton;
    newF->setText("New File");

    QToolButton *closeF = new QToolButton;
    closeF->setText("Close App");

    openF->setFixedSize ( QSize (100 , 50));
    closeF->setFixedSize ( QSize (100 , 50));
    saveAs->setFixedSize ( QSize (100 , 50));
    saveF->setFixedSize ( QSize (100 , 50));
    newF->setFixedSize ( QSize (100 , 50));

    QGridLayout *dockGrid2 = new QGridLayout;
    dockGrid2->addWidget(openF, 0, 0);
    dockGrid2->addWidget(saveAs, 0, 1);
    dockGrid2->addWidget(saveF, 0, 2);
    dockGrid2->addWidget(newF, 0, 3);
    dockGrid2->addWidget(closeF, 0, 4);

    QWidget *dockWidget2 = new QWidget;
    dockWidget2->setLayout(dockGrid2);

    QDockWidget *dock2 = new QDockWidget("Tool Buttons", this);
    dock2->setWidget(dockWidget2);

    addDockWidget(Qt::BottomDockWidgetArea, dock2);

    openFileAction = new QAction("Open File", this);
    openFileAction->setShortcut(QKeySequence::Open);
    file->addAction(openFileAction);

    QToolButton *openFileButton = new QToolButton;
    openFileButton->setText("Open File");
    openFileButton->setFixedSize(QSize(100, 50));

    connect(fileOpen, &QAction::triggered, this, &MainWindow::open);
    connect(fileNew, &QAction::triggered, this, &MainWindow::newFile);
    connect(fileSaveCurr, &QAction::triggered, this, &MainWindow::saveCurrent);
    connect(fileSave, &QAction::triggered, this, &MainWindow::save);
    connect(fileClose, &QAction::triggered, this, &MainWindow::close);
    connect(fileClear, &QAction::triggered, this, &MainWindow::clear);
    connect(fileToCamel, &QAction::triggered, this, &MainWindow::toCamelCase);
    connect(fileToUpper, &QAction::triggered, [this]() { upper(true);});
    connect(fileToLower, &QAction::triggered, [this]() { upper(false);});
    connect(fileIncreaseTextSize, &QAction::triggered, [this]() { changeTextSize(true); });
    connect(fileDecreaseTextSize, &QAction::triggered, [this]() { changeTextSize(false); });
    connect(aboutAction, &QAction::triggered, this, &MainWindow::showAboutInfo);
    connect(helpAction, &QAction::triggered, this, &MainWindow::showHelpInfo);
    connect(editor, &QTextEdit::textChanged, this, &MainWindow::changeSaveStatus);
    connect(bold, &QToolButton::clicked, this, &MainWindow::toggleBoldStyle);
    connect(italic, &QToolButton::clicked, this, &MainWindow::toggleItalicStyle);
    connect(newline, &QToolButton::clicked, this, &MainWindow::insertNewLine);
    connect(textSizeUp, &QToolButton::clicked, [this]() {changeTextSize(true);});
    connect(textSizeDown, &QToolButton::clicked, [this]() {changeTextSize(false);});
    connect(textToCamel, &QToolButton::clicked, this, &MainWindow::toCamelCase);
    connect(textClr, &QToolButton::clicked, this, &MainWindow::clear);
    connect(openF, &QToolButton::clicked, this, &MainWindow::open);
    connect(closeF, &QToolButton::clicked, this, &MainWindow::close);
    connect(saveAs, &QToolButton::clicked, this, &MainWindow::save);
    connect(saveF, &QToolButton::clicked, this, &MainWindow::saveCurrent);
    connect(newF, &QToolButton::clicked, this, &MainWindow::newFile);
    connect(fontComboBox, &QFontComboBox::currentFontChanged, this, &MainWindow::changeFont);
    connect(colorButton, &QPushButton::clicked, this, &MainWindow::changeTextColor);
    connect(openFileAction, &QAction::triggered, this, &MainWindow::open);
    connect(openFileButton, &QToolButton::clicked, this, &MainWindow::open);

}

void MainWindow::newFile()
{
    QString txt = editor ->toPlainText();
    if (!txt.isEmpty())
    {
        QMessageBox::StandardButton reply = QMessageBox::question(this, "Save file", "Do you want to save your previous file?", QMessageBox::Yes | QMessageBox::No);
        if (reply == QMessageBox::Yes)
        {
            this->save();
        }
        editor->clear();
        this->save();
        this->setWindowTitle("Text Editor");
    }
}

void MainWindow::saveCurrent()
{
    if (!currentFileName.isEmpty())
    {
        saveToFile(currentFileName);
    }
    else
    {
        QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), "default.txt", tr("Text files (*.txt)"));
        if (!fileName.isEmpty())
        {
            currentFileName = fileName;
            saveToFile(currentFileName);
        }
    }
}

void MainWindow::save()
{
    QString fileName = QFileDialog :: getSaveFileName ( this , tr (" Save File " ),
                                                     "default.txt", tr (" Text files (*.txt)" ));
    if (! fileName . isEmpty ())
    {
        QFile file ( fileName );
        if (! file . open ( QIODevice :: WriteOnly ))
        {
            QMessageBox :: critical ( this , tr ( " Error ") , tr (" Can't open file " ));
            return;
        }
        else
        {
            saveToFile(fileName);
            this->setWindowTitle("Text Editor - " + fileName);
        }
    }
}

void MainWindow::close()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Close Application", "Are you sure you want to close the application?", QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes)
    {
        QApplication::quit();
    }
}

void MainWindow::saveToFile(const QString &fileName)
{
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QMessageBox::critical(this, tr("Error"), tr("Can't open file for writing"));
        return;
    }

    QTextStream outputStream(&file);
    QString txt = editor->toPlainText();
    outputStream << txt;
    this->setWindowTitle(fileName);
    file.close();
}

void MainWindow::clear()
{
    editor->clear();
}

void MainWindow::upper(bool isUpper)
{
    QString text = editor->toPlainText();

    if (isUpper)
    {
        editor->setPlainText(text.toUpper());
    }
    else
    {
        editor->setPlainText(text.toLower());
    }
}

void MainWindow::toCamelCase()
{
    QString input = editor->toPlainText();
    QString result;
    bool capitalizeNext = true;

    for (QString c : input)
    {
        if (c != " ")
        {
            if (capitalizeNext)
            {
                result += c.toUpper();
                capitalizeNext = false;
            }
            else
                result += c.toLower();
        }
        else
            capitalizeNext = true;
    }

    editor->setPlainText(result);
}

void MainWindow::changeTextSize(bool isIncrease)
{
    QFont font = editor->font();
    int size = font.pointSize();

    if (isIncrease)
        ++size;
    else
        --size;

    font.setPointSize(size);
    editor->setFont(font);
}

void MainWindow::showAboutInfo()
{
    QMessageBox::information(this, "About", "Simple Text Editor \n v. 1");
}

void MainWindow::showHelpInfo()
{
    QMessageBox::information(this, "Help", "Just use it like default windows text editor.");
}


void MainWindow::changeSaveStatus()
{
    QString title = this->windowTitle();
    if (!title.endsWith('*'))
    {
        this->setWindowTitle(title + "*");
    }
}

void MainWindow::toggleBoldStyle()
{
    QTextCursor cursor = editor->textCursor();
    QTextCharFormat format = cursor.charFormat();

    if (format.fontWeight() == QFont::Bold)
    {
        format.setFontWeight(QFont::Normal);
    }
    else
    {
        format.setFontWeight(QFont::Bold);
    }
    cursor.setCharFormat(format);
    editor->setTextCursor(cursor);
}

void MainWindow::toggleItalicStyle()
{
    QTextCursor cursor = editor->textCursor();
    QTextCharFormat format = cursor.charFormat();

    if (format.fontItalic())
    {
        format.setFontItalic(false);
    }
    else
    {
        format.setFontItalic(true);
    }

    cursor.setCharFormat(format);
    editor->setTextCursor(cursor);
}

void MainWindow::insertNewLine()
{
    editor->textCursor().insertText("\n");}

void MainWindow::changeFont(const QFont &font) {
    editor->setFont(font);
}

void MainWindow::changeTextColor() {
    QColor chosenColor = QColorDialog::getColor(editor->textColor(), this, "Оберіть колір тексту", QColorDialog::ShowAlphaChannel);
    if (chosenColor.isValid()) {
        QPalette palette = editor->palette();
        palette.setColor(QPalette::Text, chosenColor);
        editor->setPalette(palette);
    }
}
void MainWindow::open()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), QString(), tr("Text files (*.txt)"));
    if (!fileName.isEmpty())
    {
        currentFileName = fileName;
        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly))
        {
            QMessageBox::critical(this, tr("Error"), tr("Can't open file"));
            return;
        }
        QTextStream inputStream(&file);
        QString txt = inputStream.readAll();
        editor->setText(txt);
        this->setWindowTitle(fileName);
        file.close();
    }
}


MainWindow::~MainWindow()
{
}
