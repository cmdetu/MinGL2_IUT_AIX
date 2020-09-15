macos:LIBS += -L"/usr/local/opt/freeglut/lib" -L"/usr/local/opt/sfml/lib" -framework OpenGL
LIBS += -lglut -lsfml-audio
!macos:LIBS += -lGLU -lGL

macos:INCLUDEPATH += /usr/local/opt/freeglut/include /usr/local/opt/sfml/include

SOURCES += \
    $$PWD/exception/cexception.cxx \
    $$PWD/mingl.cpp \
    $$PWD/audio/fonctoroldsound.cpp \
    $$PWD/audio/minglaudioengine.cpp \
    $$PWD/event/event_manager.cpp \
    $$PWD/shape/circle.cpp \
    $$PWD/shape/line.cpp \
    $$PWD/shape/rectangle.cpp \
    $$PWD/shape/triangle.cpp \
    $$PWD/shape/shape.cpp \
    $$PWD/graphics/rgbacolor.cpp \
    $$PWD/graphics/vec2d.cpp \
    $$PWD/gui/glut_font.cpp \
    $$PWD/gui/sprite.cpp \
    $$PWD/gui/text.cpp \
    $$PWD/transition/transition.cpp \
    $$PWD/transition/transition_contract.cpp \
    $$PWD/transition/transition_engine.cpp

HEADERS += \
    $$PWD/exception/cexception.h \
    $$PWD/exception/cexception.hxx \
    $$PWD/exception/errcode.h \
    $$PWD/macros.h \
    $$PWD/mingl.h \
    $$PWD/audio/fonctoroldsound.h \
    $$PWD/audio/minglaudioengine.h \
    $$PWD/event/event.hpp \
    $$PWD/event/event_manager.h \
    $$PWD/shape/circle.h \
    $$PWD/shape/line.h \
    $$PWD/shape/rectangle.h \
    $$PWD/shape/triangle.h \
    $$PWD/shape/shape.h \
    $$PWD/graphics/idrawable.h \
    $$PWD/graphics/iminglinjectable.h \
    $$PWD/graphics/rgbacolor.h \
    $$PWD/graphics/vec2d.h \
    $$PWD/gui/glut_font.h \
    $$PWD/gui/sprite.h \
    $$PWD/gui/text.h \
    $$PWD/tools/ieditable.h \
    $$PWD/tools/ieditable.hxx \
    $$PWD/tools/ifonctorunaire.hpp \
    $$PWD/transition/itransitionable.h \
    $$PWD/transition/transition.h \
    $$PWD/transition/transition_contract.h \
    $$PWD/transition/transition_engine.h \
    $$PWD/transition/transition_types.h
