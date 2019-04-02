android|ios|winrt {
    error( "This example is not supported for android, ios, or winrt." )
}

!include( ../examples.pri ) {
    error( "Couldn't find the examples.pri file!" )
}

SOURCES += main.cpp \
           surfacegraph.cpp

HEADERS += surfacegraph.h

QT += widgets
requires(qtConfig(combobox))

RESOURCES += surface.qrc

OTHER_FILES += doc/src/* \
               doc/images/*




#QT = core
QT += serialport

#CONFIG += console
#CONFIG -= app_bundle

#TARGET = creaderasync
#TEMPLATE = app

#HEADERS += \
 #   serialportreader.h

#SOURCES += \
#    main.cpp \

 #   serialportreader.cpp
  # surfacegraph.cpp

#target.path = $$[QT_INSTALL_EXAMPLES]/serialport/creaderasync
#INSTALLS += target
