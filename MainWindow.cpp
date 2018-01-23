#include "MainWindow.h"
#include <QTreeView>

#include "TableModel.h"


MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent)
{
    m_treeView = new QTreeView(this);
    setCentralWidget(m_treeView);

    TableModel* tableModel = new TableModel(m_treeView);
    m_treeView->setModel(tableModel);

    tableModel->insertRows(0, 1, QModelIndex());
}

MainWindow::~MainWindow()
{

}
