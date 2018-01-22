#pragma once

#include <QMainWindow>
#include <QTreeView>

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow();
private:
    QTreeView* m_treeView;
};

