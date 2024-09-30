TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        dwarf.cpp \
        dwarffortress.cpp \
        farmer.cpp \
        guard.cpp \
        main.cpp \
        miner.cpp \
        room.cpp

HEADERS += \
    dwarf.h \
    dwarffortress.h \
    farmer.h \
    guard.h \
    miner.h \
    room.h
