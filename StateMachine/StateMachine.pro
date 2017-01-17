QT += core
QT -= gui

CONFIG += c++11

TARGET = StateMachine
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    statemachine.cpp

HEADERS += \
    statemachine.h
