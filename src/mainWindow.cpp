// Includes from project
#include "mainWindow.hpp"

// Includes from 3rd party
#include <QMenuBar>
#include <QStatusBar>

MainWindow::MainWindow(QWidget* pParent) : QMainWindow(pParent)
{
	setWindowTitle("Qt6 Template Application");

    // Example menubar
    QMenu* fileMenu = menuBar()->addMenu("File");
    fileMenu->addAction("Exit", this, &QMainWindow::close);

    // Example statusbar
    statusBar()->showMessage("Ready");
}