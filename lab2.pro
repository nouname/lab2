TEMPLATE = subdirs

CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS += -fprofile-arcs -ftest-coverage -O0 -std=c++0x

SUBDIRS = app editor-tests

CONFIG += ordered
