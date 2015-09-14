TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    match.cpp \
    player.cpp \
    team.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    match.h \
    player.h \
    team.h
