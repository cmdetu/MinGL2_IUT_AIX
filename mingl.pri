macos:LIBS += -L"/usr/local/opt/freeglut/lib" -L"/usr/local/opt/sfml/lib" -framework OpenGL
LIBS += -lglut -lsfml-audio
!macos:LIBS += -lGLU -lGL

macos:INCLUDEPATH += /usr/local/opt/freeglut/include /usr/local/opt/sfml/include

SOURCES += \
    $$PWD/mingl.cpp \
    $$PWD/audio/minglaudioengine.cpp \
    $$PWD/event/event_manager.cpp \
    $$PWD/shape/circle.cpp \
    $$PWD/shape/line.cpp \
    $$PWD/shape/rectangle.cpp \
    $$PWD/shape/triangle.cpp \
    $$PWD/shape/shape.cpp \
    $$PWD/graph/rgbacolor.cpp \
    $$PWD/gui/sprite.cpp \
    $$PWD/gui/text.cpp \
    $$PWD/tools/CException.cxx \
    $$PWD/tools/fonctoroldsound.cpp \
    $$PWD/tools/glut_font.cpp \
    $$PWD/tools/myexception.cpp \
    $$PWD/tools/pixelexception.cpp \
    $$PWD/tools/tools.cpp \
    $$PWD/transition/transition.cpp \
    $$PWD/transition/transition_contract.cpp \
    $$PWD/transition/transition_engine.cpp

HEADERS += \
    $$PWD/graph/rgbacolor.hpp \
    $$PWD/graph/vec2d.hpp \
    $$PWD/macros.h \
    $$PWD/mingl.h \
    $$PWD/audio/minglaudioengine.h \
    $$PWD/event/event.hpp \
    $$PWD/event/event_manager.h \
    $$PWD/shape/circle.h \
    $$PWD/shape/line.h \
    $$PWD/shape/rectangle.h \
    $$PWD/shape/triangle.h \
    $$PWD/shape/shape.h \
    $$PWD/graph/idrawable.h \
    $$PWD/graph/iminglinjectable.h \
    $$PWD/graph/libgraphique_fonts.h \
    $$PWD/gui/sprite.h \
    $$PWD/gui/text.h \
    $$PWD/tools/CException.h \
    $$PWD/tools/CException.hxx \
    $$PWD/tools/CstCodErr.h \
    $$PWD/tools/IEditable.h \
    $$PWD/tools/IEditable.hxx \
    $$PWD/tools/IFonctorUnaire.hpp \
    $$PWD/tools/fonctoroldsound.h \
    $$PWD/tools/glut_font.h \
    $$PWD/tools/myexception.h \
    $$PWD/tools/pixel.h \
    $$PWD/tools/pixelexception.h \
    $$PWD/tools/tools.h \
    $$PWD/transition/itransitionable.h \
    $$PWD/transition/transition.h \
    $$PWD/transition/transition_contract.h \
    $$PWD/transition/transition_engine.h \
    $$PWD/transition/transition_types.h
