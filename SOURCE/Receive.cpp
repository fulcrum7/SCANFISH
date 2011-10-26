#include "Receive.h"
#include <QTime>
Receive :: Receive(QWidget *Rec) : QGroupBox (Rec)
{
    k=0; //

    setTitle("    Receive");
    RecTab = new QTableWidget(0,4);
    RecTab->setColumnWidth(0,130);
    RecTab->setColumnWidth(1,130);
    RecTab->setColumnWidth(2,130);
    RecTab->setColumnWidth(3,294);
    QTableWidgetItem *RecTab_Item0 = new QTableWidgetItem
            (QString::fromLocal8Bit("Timestamp"));
    RecTab->setHorizontalHeaderItem(0,RecTab_Item0);
    QTableWidgetItem *RecTab_Item1 = new QTableWidgetItem
            (QString::fromLocal8Bit("ID"));
    RecTab->setHorizontalHeaderItem(1,RecTab_Item1);
    QTableWidgetItem *RecTab_Item2 = new QTableWidgetItem
            (QString::fromLocal8Bit("DLC"));
    RecTab->setHorizontalHeaderItem(2,RecTab_Item2);
    QTableWidgetItem *RecTab_Item3 = new QTableWidgetItem
            (QString::fromLocal8Bit("DATA"));
    RecTab->setHorizontalHeaderItem(3,RecTab_Item3);

   RecClearButton = new QPushButton("Clear");
   RecClearButton->setFixedSize(95,27);
   RecClearButton->setEnabled(false);

   RecSaveButton=new QPushButton ("Save");
   RecSaveButton->setFixedSize (95,27);
   RecSaveButton->setEnabled(false);

   VerticalSpacer = new QSpacerItem (10,0,QSizePolicy::Expanding,
           QSizePolicy::Minimum);

   RecLayout = new QGridLayout;
   RecLayout->addWidget(RecTab,1,1,-1,1,Qt::AlignTop);
   RecLayout->addWidget(RecSaveButton,1,2,Qt::AlignTop);
   RecLayout->addWidget(RecClearButton,2,2,Qt::AlignTop);
   RecLayout->addItem(VerticalSpacer,3,2,3,0,Qt::AlignTop);

   setLayout(RecLayout);

   RecTab->horizontalHeader()->setResizeMode(3,QHeaderView::Stretch);
   RecTab->verticalHeader()->setVisible(false);

   connect (RecClearButton,SIGNAL(clicked()),this,SLOT(RecTableClear()));
   connect (RecSaveButton,SIGNAL(clicked()),this,SLOT(RecTableSave()));
}

void Receive :: RecTableClear()
{
    k=0;
    RecTab->clearContents();
    RecTab->setRowCount(0);
    RecSaveButton->setEnabled(false);
    RecClearButton->setEnabled(false);
}

void Receive :: ReceiveSlot(int ID,int DLC,QString DATA,QTime time)
{
    k++;
    RecClearButton->setEnabled(true);
    RecSaveButton->setEnabled(true);

    RecTab->insertRow(0);
    RecTab->setRowHeight(0,15);
    QString text;

    int count=RecTab->rowCount();
    if(count>MAX_TABLE_SIZE)
    {
       RecTab->removeRow(count-1);
    }
    
    text=time.toString("hh:mm:ss.zzz");

    QTableWidgetItem *T_Item1 = new QTableWidgetItem;
    T_Item1->setText(text);
    RecTab->setItem(0,0,T_Item1);
    RecTab->item(0,0)->setTextAlignment(Qt::AlignCenter);

    text = QVariant(ID).toString();
    QTableWidgetItem *T_Item2 = new QTableWidgetItem;
    T_Item2->setText(text);
    RecTab->setItem(0,1,T_Item2);
    RecTab->item(0,1)->setTextAlignment(Qt::AlignCenter);

    text = QVariant(DLC).toString();
    QTableWidgetItem *T_Item3 = new QTableWidgetItem
            (QString::fromLocal8Bit(""));
    T_Item3->setText(text);
    RecTab->setItem(0,2,T_Item3);
    RecTab->item(0,2)->setTextAlignment(Qt::AlignCenter);

    QTableWidgetItem *T_Item4 = new QTableWidgetItem
            (QString::fromLocal8Bit(""));

    T_Item4->setText(DATA);
    RecTab->setItem(0,3,T_Item4);
    RecTab->item(0,3)->setTextAlignment(Qt::AlignCenter);

}

void Receive :: RecTableSave()
{

    QString fileName = QFileDialog::getSaveFileName(this, 
            tr("Save File"), "Receive",tr("Text Files (*.txt);"));
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
                text = RecTab->item(j,i)->text();
                stream<<text;
                stream<<"\t\t\t";
                i++;
                text = RecTab->item(j,i)->text();
                stream<<text;
                stream<<"\t\t\t";
                i++;
                text = RecTab->item(j,i)->text();
                stream<<text;
                stream<<"\t\t\t";
                i++;
                text = RecTab->item(j,i)->text();
                stream<<text;
                stream<<"\n";
                i=0;
                j++;
            }        
            file.close();
        }
    }
}