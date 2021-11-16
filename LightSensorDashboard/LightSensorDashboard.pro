QT       += core gui serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    current_user.cpp \
    file_saving.cpp \
    helper_functions.cpp \
    light_sensor.cpp \
    location_manager.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    current_user.h \
    file_saving.h \
    helper_functions.h \
    light_sensor.h \
    location_manager.h \
    mainwindow.h

FORMS += \
    mainwindow.ui


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images.qrc
