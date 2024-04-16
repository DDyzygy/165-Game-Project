TEMPLATE = app
TARGET = space game

QT = core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

)

SOURCES += \
    main.cpp \
    window.cpp

HEADERS += \
    window.h
