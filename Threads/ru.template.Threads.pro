TARGET = ru.template.Threads

CONFIG += \
    auroraapp

PKGCONFIG += \

SOURCES += \
    src/main.cpp \

HEADERS += \

DISTFILES += \
    rpm/ru.template.Threads.spec \
    qml/assets/workerscript.js

AURORAAPP_ICONS = 86x86 108x108 128x128 172x172

CONFIG += auroraapp_i18n

TRANSLATIONS += \
    translations/ru.template.Threads.ts \
    translations/ru.template.Threads-ru.ts \
