#include "MainWindow.h"
#include <QTreeView>
#include <QHeaderView>

#include "TableModel.h"


MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent)
{
    m_treeView = new QTreeView(this);
    setCentralWidget(m_treeView);

    TableModel* tableModel = new TableModel(m_treeView);
    tableModel->appendItem(TableModelItem("zagreb"));
    tableModel->appendItem(TableModelItem("vukovar"));
    tableModel->appendItem(TableModelItem("split"));

    m_treeView->setModel(tableModel);

    m_treeView->setSortingEnabled(true);
    connect(m_treeView->header(), SIGNAL(sortIndicatorChanged(int, Qt::SortOrder)), tableModel, SLOT(sortByColumn(int, Qt::SortOrder)));
}

MainWindow::~MainWindow()
{

}
