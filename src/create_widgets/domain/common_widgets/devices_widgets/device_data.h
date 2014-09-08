#ifndef DEVICE_DATA_H
#define DEVICE_DATA_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QStringList>
#include <QScrollArea>
#include <QMessageBox>
#include "create_widgets/domain/domain_widgets.h"

class DeviceData : public QWidget
{
    Q_OBJECT
public:
    explicit DeviceData(
            QWidget *parent = 0,
            virConnectPtr conn = NULL);

signals:
    void errorMsg(QString);
    void saveDeviceXMLDesc(QString&);

private:
    QLabel          *devName;
    QPushButton     *save;
    QPushButton     *revert;
    QPushButton     *_close;
    QHBoxLayout     *panelLayout;
    QWidget         *panel;

    _QWidget        *device = NULL;
    QWidget         *scrolled = NULL;
    QVBoxLayout     *infoLayout;
    QScrollArea     *infoWidget;
    QVBoxLayout     *commonLayout;

    bool             currentStateSaved = true;
    QString          currentDeviceXMLDesc;
    QStringList      devices;
    QStringList      nets;
    virConnectPtr    currWorkConnect = NULL;
    virNodeDevice  **nodeDevices = NULL;
    virErrorPtr      virtErrors;

public slots:
    QDomDocument getResult() const;
    void showDevice(QString&, QString&);

private slots:
    void currentStateChanged();
    void readNetworkList();
    void readNodeDevicesList();
    void saveDeviceData();
    void revertDeviceData();
    void _closeDeviceData();
    void setStartState();

    void sendConnErrors();
    void sendGlobalErrors();
};

#endif // DEVICE_DATA_H