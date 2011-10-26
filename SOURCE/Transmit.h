#ifndef TRANSMIT_H
#define	TRANSMIT_H

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

#include <QDirModel>
#include <QTreeView>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QTime>
#include "MessageEditor.h"
#define MAX_TABLE_SIZE 1000
class Transmit : public QGroupBox
{
    Q_OBJECT
    QGridLayout *TransLayout;

public:
    Transmit(QWidget *Trans);

    //signals:


private slots:
    void TransTableClear();
    void SendSlot(QString ID,QString DLC, QString DATA,QTime time);
    void TransTableSave();

private:
    QTableWidget *TransTab;
    QPushButton *TransClearButton;
    QPushButton *TransSaveButton;
    QSpacerItem *VerticalSpacer;

    int k;
    int i;
    int j;
};

#endif	/* TRANSMIT_H */

