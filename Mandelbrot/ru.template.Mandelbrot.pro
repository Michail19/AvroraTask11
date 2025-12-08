TARGET = ru.template.Mandelbrot

CONFIG += \
    auroraapp

PKGCONFIG += \

SOURCES += \
    src/main.cpp \
    src/mandelbrot.cpp \
    src/renderthread.cpp

HEADERS += \
    src/mandelbrot.h \
    src/renderthread.h

DISTFILES += \
    rpm/ru.template.Mandelbrot.spec \

AURORAAPP_ICONS = 86x86 108x108 128x128 172x172

CONFIG += auroraapp_i18n

# RESOURCES += qml.qrc

TRANSLATIONS += \
    translations/ru.template.Mandelbrot.ts \
    translations/ru.template.Mandelbrot-ru.ts \
