QT       += core gui widgets network serialport serialbus

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
CONFIG += -qreal float

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Message.cpp \
    TcpServer.cpp \
    ac.cpp \
    acstatehandler.cpp \
    apd/apd.cpp \
    celhandler.cpp \
    cellstorage.cpp \
    datachanel.cpp \
    datachanelnoptr.cpp \
    dataserver.cpp \
    devices/devicefactory.cpp \
    devices/deviceinterface.cpp \
    devices/devicelib/devicemanager.cpp \
    devices/devicelib/telemetrypoller.cpp \
    devices/doslib/dos.cpp \
    devices/doslib/dosbeamformer.cpp \
    devices/doslib/doscalgen.cpp \
    devices/pcolib/pcoacqu.cpp \
    devices/pcolib/pcoapi.cpp \
    devices/pcolib/pcobeamformer.cpp \
    devices/pcolib/pcocalrec.cpp \
    devices/pcolib/pcodds.cpp \
    devices/pcolib/pcosync.cpp \
    logger.cpp \
    logmessage.cpp \
    main.cpp \
    mainwindow.cpp \
    math/antmodel.cpp \
    messagehandler.cpp \
    messageprocessor.cpp \
    modbus/genlib/fpn16.cpp \
    modbus/modbusdevice.cpp \
    p2sockethandler.cpp \
    packet.cpp \
    planfactory.cpp \
    planstorage.cpp \
    reportstatechecker.cpp \
    sector.cpp \
    sectorplan.cpp \
    segmentplan.cpp \
    sequentialidprovider.cpp \
    sessionrequesthandler.cpp \
    stophandler.cpp \
    toytelemetry.cpp

HEADERS += \
    Message.h \
    TcpServer.h \
    ac.h \
    acstatehandler.h \
    apd/apd.h \
    celhandler.h \
    cellstorage.h \
    datachanel.h \
    datachanelnoptr.h \
    dataserver.h \
    devices/devicefactory.h \
    devices/deviceinterface.h \
    devices/deviceinterfaceuser.h \
    devices/devicelib/devicemanager.h \
    devices/devicelib/devicemodel.h \
    devices/devicelib/telemetrycollector.h \
    devices/devicelib/telemetrypoller.h \
    devices/devicelib/telemetrytypes.h \
    devices/doslib/dos.h \
    devices/doslib/dosbeamformer.h \
    devices/doslib/doscalgen.h \
    devices/doslib/dosregmap.h \
    devices/pcolib/pcoacqu.h \
    devices/pcolib/pcoapi.h \
    devices/pcolib/pcobeamformer.h \
    devices/pcolib/pcocalrec.h \
    devices/pcolib/pcodds.h \
    devices/pcolib/pcoregmap.h \
    devices/pcolib/pcosync.h \
    fpm/fixed.hpp \
    fpm/ios.hpp \
    fpm/math.hpp \
    logger.h \
    logmessage.h \
    mainwindow.h \
    math/antmodel.h \
    math/matrix.h \
    messagebroker.h \
    messagehandler.h \
    messageprocessor.h \
    modbus/genlib/fpn16.h \
    modbus/genlib/generic.h \
    modbus/genlib/modbus_layout.h \
    modbus/genlib/regmap.h \
    modbus/genlib/rf_constants.h \
    modbus/genlib/types.h \
    modbus/modbus_literals.h \
    modbus/modbusdevice.h \
    p2sockethandler.h \
    packet.h \
    planfactory.h \
    planstorage.h \
    reportstatechecker.h \
    sector.h \
    sectorplan.h \
    segmentplan.h \
    sequentialidprovider.h \
    sessionrequesthandler.h \
    stophandler.h \
    toytelemetry.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    autostart.sh
