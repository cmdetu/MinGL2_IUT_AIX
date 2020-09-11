TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -lsfml-audio

SOURCES += \
    audio/minglaudioengine.cpp \
    event/event_manager.cpp \
    figs/basefig.cpp \
    figs/circle.cpp \
    figs/figure.cpp \
    figs/line.cpp \
    figs/rectangle.cpp \
    figs/triangle.cpp \
    graph/mingl.cpp \
    graph/rgbacolor.cpp \
    gui/button.cpp \
    gui/sprite.cpp \
    gui/text.cpp \
    tools/CException.cxx \
    tools/fonctoroldsound.cpp \
    tools/glut_font.cpp \
    tools/myexception.cpp \
    tools/tools.cpp \
    tools/pixelexception.cpp \
    transition/transition.cpp \
    transition/transition_contract.cpp \
    transition/transition_engine.cpp \
    main.cpp

QT += opengl core gui

#LIBS +=  -lglut -lGLU -lGL -lGLEW
LIBS +=  -lglut -lGLU -lGL

#INCLUDEPATH += /opt/local/include/GL/
INCLUDEPATH += /usr/include/GL/

QMAKE_CXXFLAGS += -Wall

HEADERS += \
    audio/minglaudioengine.h \
    event/event.hpp \
    event/event_manager.h \
    figs/basefig.h \
    figs/circle.h \
    figs/figure.h \
    figs/line.h \
    figs/rectangle.h \
    figs/triangle.h \
    graph/idrawable.h \
    graph/iminglinjectable.h \
    graph/libgraphique_fonts.h \
    graph/mingl.h \
    graph/rgbacolor.h \
    graph/vec2d.h \
    gui/button.h \
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
    tools/tools.h \
    tools/pixelexception.h \
    transition/itransitionable.h \
    transition/transition.h \
    transition/transition_contract.h \
    transition/transition_engine.h \
    transition/transition_types.h \
    macros.h

# https://retifrav.github.io/blog/2018/06/08/qmake-copy-files/
# Pour copier les fichiers de ressources directement dans le répertoire de build
# copies the given files to the destination directory
defineTest(copyToDestDir) {
    files = $$1
    dir = $$2
    # replace slashes in destination path for Windows
    win32:dir ~= s,/,\\,g

    for(file, files) {
        # replace slashes in source path for Windows
        win32:file ~= s,/,\\,g

        QMAKE_POST_LINK += $$QMAKE_COPY_DIR $$shell_quote($$file) $$shell_quote($$dir) $$escape_expand(\\n\\t)
    }

    export(QMAKE_POST_LINK)
}

copyToDestDir($$PWD/resources, $$OUT_PWD/)
