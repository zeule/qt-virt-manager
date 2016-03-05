/*
   Copyright (C) 2014 Lindsay Mathieson (lindsay.mathieson@gmail.com).

   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with this library; if not, see <http://www.gnu.org/licenses/>.
*/

#ifndef QSPICESESSION_H
#define QSPICESESSION_H

#include <QObject>

#include "qspicechannel.h"

// Forward Declarations
class QSpiceHelper;

class QSpiceSession : public QSpiceObject
{
    Q_OBJECT
public:
    explicit QSpiceSession(QObject *parent = nullptr);
    friend class QSpiceHelper;
    friend class QSpiceWidget;
    friend class QSpiceUsbDeviceManager;

    Q_GPROP_STR (Uri, "uri")
    //Q_GPROP_BOOL(EnableClientSockets, "client-sockets") // doc default FALSE
    Q_GPROP_BOOL(EnableAudio, "enable-audio")           // doc default TRUE
    Q_GPROP_BOOL(EnableSmartcard, "enable-smartcard")   // doc default FALSE
    Q_GPROP_BOOL(EnableUsbredir, "enable-usbredir")     // doc default TRUE
    Q_GPROP_STR (SharedDir, "shared-dir")               // doc default "/home/elmarco/Public"
    Q_GPROP_STR (SmartcardDB, "smartcard-db")
    Q_GPROP_STRLIST (SmartcardCAC, "smartcard-certificates")

    bool Connect();
    void Disconnect();
    
signals:
    void channelNew(QSpiceChannel *channel);
    void channelDestroyed(QSpiceChannel *channel);
    
public slots:

private:

protected:
    void init();
};

#endif // QSPICESESSION_H