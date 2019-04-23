TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    load.c \
    save.c \
    editor.c \
    text/append_line.c \
    text/change_cursor_position.c \
    text/create_text.c \
    text/delete_line.c \
    text/process_forward.c \
    text/remove_all.c \
    show.c \
    shownum.c \
    getcrsr.c \
    mle.c \
    mwbb.c \
    mwcrsr.c \
    text/create_objects.c

HEADERS += \
    text/text.h \
    text/_text.h \
    common.h \
    data.h

QMAKE_CFLAGS += -Wall -Wextra  -std=c++0x

# gcov
QMAKE_CFLAGS += -fprofile-arcs \
    -ftest-coverage
LIBS += -lgcov
