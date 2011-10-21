#ifndef RECEIVE_H
#define	RECEIVE_H

#include <QtGui/QApplication>
#include <QLabel>
#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QLayout>
#include <QHeaderView>
#include <QScrollArea>
#include <QGridLayout>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QHeaderView>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QSpacerItem>

#include <QDirModel>
#include <QTreeView>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>

#include "MessageEditor.h"


#define MAX_TABLE_SIZE 1000

class Receive : public QGroupBox
{
    Q_OBJECT
    QGridLayout *RecLayout;

public:
    Receive(QWidget *Rec);

private slots:
    void RecTableClear();
    void ReceiveSlot(int ID,int DLC,QString DATA,QTime time);
    void RecTableSave();

private:
    QTableWidget *RecTab;
    QPushButton *RecClearButton;
    QPushButton *RecSaveButton;
    QSpacerItem *VerticalSpacer;

    int k;
    int i;
    int j;
};


#endif	/* RECEIVE_H */

