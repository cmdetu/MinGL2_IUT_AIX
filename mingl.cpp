/**
 *
 * @file    mingl.cpp
 * @author  Alexandre Sollier, Clément Mathieu--Drif, Alain Casali
 * @date    Janvier 2020
 * @version 2.0
 * @brief   La bête
 *
 **/

#include <map>

#include "mingl.h"

using namespace std;
using namespace nsUtil;

// Astuce pour faire passer les handlers en fonction static dans initGraphic()
namespace {
map<int, MinGL *> anyWindow;

template<typename T, T oHandler>
struct callBackBuilder;

template<typename Obj, typename... Arg, void(Obj::* oHandler)(Arg...)>
struct callBackBuilder<void(Obj::*)(Arg...), oHandler>
{
    static void callback(Arg... arg)
    {
        int current_id = glutGetWindow();
        //cout << "window [" << current_id << "] handler call" << endl;
        auto it = anyWindow.find(current_id);
        if (it != anyWindow.end())
        {
            (it->second->*oHandler)(arg...);
        }
    }
};
}

#define BIND_CALLBACK(HANDLER) callBackBuilder<decltype(HANDLER), HANDLER>::callback

MinGL::MinGL(const std::string &name_, const Vec2D &windowSize_, const RGBAcolor & backgroundColor)
    : windowSize(windowSize_)
    , windowName(name_)
    , bgColor(backgroundColor)
    , eventManager()
    , windowIsOpen(false)
{}

MinGL::~MinGL()
{
    auto it = anyWindow.find(glutWindowId);
    if (it != anyWindow.end())
        anyWindow.erase(it);

    stopGaphic();
}

void MinGL::addDrawable(std::unique_ptr<IDrawable> drawable)
{
    drawStack.push_back(std::move(drawable));
}

void MinGL::updateGraphic()
{
    glutPostRedisplay();
    glutMainLoopEvent();
}

void MinGL::clearScreen()
{
    glClear(GL_COLOR_BUFFER_BIT);
}

nsEvent::EventManager &MinGL::getEventManager()
{
    return eventManager;
}

void MinGL::setBackgroundColor(const RGBAcolor & backgroundColor)
{
    bgColor = backgroundColor;
    glClearColor(bgColor.Red / 256.f, bgColor.Green / 256.f, bgColor.Blue / 256.f, 1.f);
}

void MinGL::initGraphic()
{
    // Initialisation GLUT
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(int(windowSize.x), int(windowSize.y));
    glutInitWindowPosition(200, 100);

    glutWindowId = glutCreateWindow(windowName.c_str());
    anyWindow[glutWindowId] = this;

    // On active la transparence
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_CONTINUE_EXECUTION);

    // Initialisation handlers
    glutReshapeFunc(BIND_CALLBACK(&MinGL::callReshape));
    glutDisplayFunc(BIND_CALLBACK(&MinGL::callDisplay));
    glutMouseFunc(BIND_CALLBACK(&MinGL::callMouse));
    glutMotionFunc(BIND_CALLBACK(&MinGL::callMotion));
    glutPassiveMotionFunc(BIND_CALLBACK(&MinGL::callPassiveMotion));
    glutKeyboardFunc(BIND_CALLBACK(&MinGL::callKeyboard));
    glutSpecialFunc(BIND_CALLBACK(&MinGL::callKeyboardSpecial));
    glutCloseFunc(BIND_CALLBACK(&MinGL::callClose));

    // On set la couleur d'effacement (prend des float, donc obligé de diviser par la taille d'un GLuint)
    glClearColor(bgColor.Red / 256.f, bgColor.Green / 256.f, bgColor.Blue / 256.f, 1.f);

    // Efface écran
    clearScreen();

    // Un tour de boucle pour lancer l'affichage
    glutMainLoopEvent();
    glutSetKeyRepeat(GLUT_KEY_REPEAT_OFF); // on désactive la répétition des touches
    windowIsOpen = true;
}

void MinGL::stopGaphic()
{
    glutDestroyWindow(glutWindowId);
    glutMainLoopEvent();
}

/*!
 *  \brief      Tell if the key is pressed (true) or not (false)
 *
 *  \return     Returns `true` if the key is pressed and `false` if the key is not pressed
 *  \param[in]  key : the keypair (keyType) corresponding to the key you want to check
 */
bool MinGL::isPressed(const keyType &key)
{
    return keyboardMap[key];
}

/*!
 *
 * \brief set the key passed in parameter to not pressed (used in menus)
 *
 */
void MinGL::resetKey(const keyType &key)
{
    keyboardMap[key] = false;
}

void MinGL::callReshape(int h, int w)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, GLfloat (windowSize.x), GLfloat (windowSize.y), 0.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glViewport(0, 0, h, w);
}

void MinGL::callDisplay()
{
    clearScreen();
    glRasterPos2i(0,0);
    glShadeModel(GL_FLAT);

    for (unsigned i = 0; i < drawStack.size(); ++i)
    {
        drawStack[i]->draw();
    }
    drawStack.clear();

    glFlush();
    glutSwapBuffers();
}

void MinGL::callMouse(int button, int state, int x, int y)
{
    nsEvent::Event_t event;
    event.eventType = nsEvent::EventType_t::MouseClick;
    event.eventData.clickData.button = button;
    event.eventData.clickData.state = state;
    event.eventData.clickData.x = x;
    event.eventData.clickData.y = y;

    eventManager.pushEvent(event);
}

void MinGL::callMotion(int x, int y)
{
    nsEvent::Event_t event;
    event.eventType = nsEvent::EventType_t::MouseDrag;
    event.eventData.moveData.x = x;
    event.eventData.moveData.y = y;

    eventManager.pushEvent(event);
}

void MinGL::callPassiveMotion(int x, int y)
{
    nsEvent::Event_t event;
    event.eventType = nsEvent::EventType_t::MouseMove;
    event.eventData.moveData.x = x;
    event.eventData.moveData.y = y;

    eventManager.pushEvent(event);
}

void MinGL::callKeyboard(unsigned char k, int x, int y)
{
    (void)(x); (void)(y);
    keyType key(k, false);
    keyboardMap[key] = true;
}
void MinGL::callKeyboardUp(unsigned char k, int x, int y)
{
    (void)(x); (void)(y);
    keyType key(k, false);
    keyboardMap[key] = false;
}

void MinGL::callKeyboardSpecial(int k, int x, int y)
{
    (void)(x); (void)(y);
    keyType key(k, true);
    keyboardMap[key] = true;
}
void MinGL::callKeyboardUpSpecial(int k, int x, int y)
{
    (void)(x); (void)(y);
    keyType key(k, true);
    keyboardMap[key] = false;
}

void MinGL::callClose()
{
    windowIsOpen = false;
}

const Vec2D MinGL::getWindowSize() const
{
    return windowSize;
}

bool MinGL::isOpen() const
{
    return windowIsOpen;
}
