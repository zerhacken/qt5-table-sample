#include "MainWindow.h"
#include <QTreeView>

#include "TableModel.h"


MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent)
{
    m_treeView = new QTreeView(this);
    setCentralWidget(m_treeView);

    QAbstractItemModel* tableModel = new TableModel(m_treeView);
    m_treeView->setModel(tableModel);
}

MainWindow::~MainWindow()
{

}
