CONFIG -= qt

TEMPLATE = lib
CONFIG += staticlib

CONFIG += c++11

LIBS +=  -lglut -lGLU -lGL -lsfml-audio

QMAKE_CFLAGS += -Wall
QMAKE_CXXFLAGS += -Wall

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    mingl.cpp \
    audio/minglaudioengine.cpp \
    event/event_manager.cpp \
    shape/circle.cpp \
    shape/line.cpp \
    shape/rectangle.cpp \
    shape/triangle.cpp \
    shape/shape.cpp \
    graph/rgbacolor.cpp \
    gui/sprite.cpp \
    gui/text.cpp \
    tools/CException.cxx \
    tools/fonctoroldsound.cpp \
    tools/glut_font.cpp \
    tools/myexception.cpp \
    tools/pixelexception.cpp \
    tools/tools.cpp \
    transition/transition.cpp \
    transition/transition_contract.cpp \
    transition/transition_engine.cpp

HEADERS += \
    graph/rgbacolor.hpp \
    graph/vec2d.hpp \
    macros.h \
    mingl.h \
    audio/minglaudioengine.h \
    event/event.hpp \
    event/event_manager.h \
    shape/circle.h \
    shape/line.h \
    shape/rectangle.h \
    shape/triangle.h \
    shape/shape.h \
    graph/idrawable.h \
    graph/iminglinjectable.h \
    graph/libgraphique_fonts.h \
    gui/sprite.h \
    gui/text.h \
    tools/CException.h \
    tools/CException.hxx \
    tools/CstCodErr.h \
    tools/IEditable.h \
    tools/IEditable.hxx \
    tools/IFonctorUnaire.hpp \
    tools/fonctoroldsound.h \
    tools/glut_font.h \
    tools/myexception.h \
    tools/pixel.h \
    tools/pixelexception.h \
    tools/tools.h \
    transition/itransitionable.h \
    transition/transition.h \
    transition/transition_contract.h \
    transition/transition_engine.h \
    transition/transition_types.h

# Default rules for deployment.
unix {
    target.path = $$[QT_INSTALL_PLUGINS]/generic
}
!isEmpty(target.path): INSTALLS += target
