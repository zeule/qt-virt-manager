#ifndef VIRTUAL_PORT_H
#define VIRTUAL_PORT_H

#include <QWidget>
#include <QMap>
#include <QString>
#include <QLabel>
#include <QLineEdit>
#include <QCheckBox>
#include <QComboBox>
#include <QGridLayout>
#include <QVBoxLayout>
#include "create_widgets/domain/_changed.h"

typedef QMap<QString, QString> ParameterList;

class VirtualPort : public _Changed
{
    Q_OBJECT
public:
    explicit VirtualPort(QWidget *parent = nullptr);
    QComboBox           *type;
    QLineEdit           *managerId, *typeId,
                        *typeIdVer, *instanceId,
                        *interfaceId, *profileId;

signals:
    //void                 dataChanged();

private:
    QCheckBox           *useVirtPort;
    QLabel              *typeLabel, *managerIdLabel,
                        *typeIdLabel, *typeIdVerLabel,
                        *instanceIdLabel, *interfaceIdLabel,
                        *profileIdLabel;
    QWidget             *parameters;
    QGridLayout         *parametersLayout;
    QVBoxLayout         *commonLayout;

public slots:
    bool                 isUsed() const;
    void                 setUsage(bool);
    ParameterList        getParameterList() const;
    void                 setParameterList(ParameterList&);

private slots:
    void                 useingChanged(bool);
    void                 virtPortTypeChanged(int);
};

#endif // VIRTUAL_PORT_H