#include "Transmit.h"
#include <QTime>
Transmit :: Transmit(QWidget *Trans) : QGroupBox (Trans)
{

    setTitle("    Transmit");
    k=0;

    TransTab = new QTableWidget(0,4);
    TransTab->setColumnWidth(0,130);
    TransTab->setColumnWidth(1,130);
    TransTab->setColumnWidth(2,130);
    TransTab->setColumnWidth(3,294);
    QTableWidgetItem *TransTab_Item0 = new QTableWidgetItem
            (QString::fromLocal8Bit("Timestamp"));
    TransTab->setHorizontalHeaderItem(0,TransTab_Item0);
    QTableWidgetItem *TransTab_Item1 = new QTableWidgetItem
            (QString::fromLocal8Bit("ID"));
    TransTab->setHorizontalHeaderItem(1,TransTab_Item1);
    QTableWidgetItem *TransTab_Item2 = new QTableWidgetItem
            (QString::fromLocal8Bit("DLC"));
    TransTab->setHorizontalHeaderItem(2,TransTab_Item2);
    QTableWidgetItem *TransTab_Item3 = new QTableWidgetItem
            (QString::fromLocal8Bit("DATA"));
    TransTab->setHorizontalHeaderItem(3,TransTab_Item3);

    TransTab->verticalHeader()->setVisible(false);

    TransClearButton = new QPushButton("Clear");
    TransClearButton->setFixedSize(95,27);
    TransClearButton->setEnabled(false);

    TransTab->horizontalHeader()->setResizeMode(3,QHeaderView::Stretch);

   TransSaveButton=new QPushButton ("Save");
   TransSaveButton->setFixedSize (95,27);
   TransSaveButton->setEnabled(false);

   VerticalSpacer = new QSpacerItem (10,0,QSizePolicy::Expanding,
           QSizePolicy::Minimum);

    TransLayout = new QGridLayout;
    TransLayout->addWidget(TransTab,1,1,-1,1,Qt::AlignTop);
    TransLayout->addWidget(TransSaveButton,1,2,Qt::AlignTop);
    TransLayout->addWidget(TransClearButton,2,2,Qt::AlignTop);
    TransLayout->addItem(VerticalSpacer,3,2,3,0,Qt::AlignTop);

   setLayout(TransLayout);

   connect (TransClearButton,SIGNAL(clicked()),this,SLOT(TransTableClear()));
   connect (TransSaveButton,SIGNAL(clicked()),this,SLOT(TransTableSave()));
}

void Transmit :: TransTableClear()
{
    k=0;
    TransTab->clearContents();
    TransTab->setRowCount(0);
    TransSaveButton->setEnabled(false);
    TransClearButton->setEnabled(false);
}

void Transmit :: SendSlot (QString ID, QString DLC, QString DATA,QTime time)
{
    k++;
    TransClearButton->setEnabled(true);
    TransSaveButton->setEnabled(true);

    TransTab->insertRow(0);
    TransTab->setRowHeight(0,15);

    int count=TransTab->rowCount();
    if(count>MAX_TABLE_SIZE)
    {
       TransTab->removeRow(count-1);
    }

    QString text;
    text=time.toString("hh:mm:ss.zzz");

    QTableWidgetItem *T_Item1 = new QTableWidgetItem;
    T_Item1->setText(text);
    TransTab->setItem(0,0,T_Item1);
    TransTab->item(0,0)->setTextAlignment(Qt::AlignCenter);

    QTableWidgetItem *T_Item2 = new QTableWidgetItem;
    T_Item2->setText(ID);
    TransTab->setItem(0,1,T_Item2);
    TransTab->item(0,1)->setTextAlignment(Qt::AlignCenter);

    QTableWidgetItem *T_Item3 = new QTableWidgetItem
            (QString::fromLocal8Bit(""));
    T_Item3->setText(DLC);
    TransTab->setItem(0,2,T_Item3);
    TransTab->item(0,2)->setTextAlignment(Qt::AlignCenter);

    QTableWidgetItem *T_Item4 = new QTableWidgetItem
            (QString::fromLocal8Bit(""));
    T_Item4->setText(DATA);
    TransTab->setItem(0,3,T_Item4);
    TransTab->item(0,3)->setTextAlignment(Qt::AlignCenter);
}

void Transmit :: TransTableSave()
{

    QString fileName = QFileDialog::getSaveFileName(this,
            tr("Save File"), "Transmit",tr("Text Files (*.txt);"));
    if (fileName != "")
    {
        QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly))
        {
            // error message
        }
        else
        {
            QTextStream stream(&file);

            QString text;
            text="Timestamp";
            stream<<text;
            stream<<"\t\t\t";
            text="ID";
            stream<<text;
            stream<<"\t\t\t";
            text="DLC";
            stream<<text;
            stream<<"\t\t\t";
            text=" DATA";
            stream<<text;
            stream<<"\n\n";
            j=0;
            i=0;
            while (j!=k)
            {
                text = TransTab->item(j,i)->text();
                stream<<text;
                stream<<"\t\t\t";
                i++;
                text = TransTab->item(j,i)->text();
                stream<<text;
                stream<<"\t\t\t";
                i++;
                text = TransTab->item(j,i)->text();
                stream<<text;
                stream<<"\t\t\t";
                i++;
                text = TransTab->item(j,i)->text();
                stream<<text;
                stream<<"\n";
                i=0;
                j++;
            }
            file.close();
        }
    }
}