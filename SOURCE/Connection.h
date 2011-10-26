#ifndef CONNECTION_H
#define	CONNECTION_H

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
#include <QHeaderView>
#include <QPaintEvent>
#include <QPainter>
#include "canlistener.h"
class Connection : public QWidget
{
    Q_OBJECT
    QHBoxLayout *ConnectionLayout;
public:
    Connection(QWidget *Con, CanListener *mcanl);

    signals:
    void active();
    void disactive();
private slots:
    void ConnectClicked();
    void DisconnectClicked();
    void EnableConnectButton();

private:
    QLabel *Interface;
    QLineEdit *can0;
    QPushButton *ConnectButton;
    QPushButton *DisconnectButton;
    QLabel *St;
    QLabel *OnOff;
    QSpacerItem *horizontalSpacer;
    CanListener *canl;
    QByteArray strInt;
    int push;
    int nid;
};

#endif	/* CONNECTION_H */

