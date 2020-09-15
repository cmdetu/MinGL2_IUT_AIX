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

// Astuce pour faire passer les handlers en fonction static dans initGraphic()
namespace {

std::map<int, MinGL *> anyWindow;

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

} // namespace

#define BIND_CALLBACK(HANDLER) callBackBuilder<decltype(HANDLER), HANDLER>::callback

MinGL::MinGL(const std::string& name, const nsGraphics::Vec2D& windowSize, const nsGraphics::RGBAcolor& backgroundColor)
    : windowSize(windowSize)
    , windowName(name)
    , bgColor(backgroundColor)
    , eventManager()
    , windowIsOpen(false)
{} // MinGL()

MinGL::~MinGL()
{
    auto it = anyWindow.find(glutWindowId);
    if (it != anyWindow.end())
        anyWindow.erase(it);

    stopGaphic();
} //~MinGL()

void MinGL::finishFrame()
{
    glutPostRedisplay();
    glutMainLoopEvent();
} // finishFrame()

void MinGL::clearScreen()
{
    glClear(GL_COLOR_BUFFER_BIT);
} // clearScreen()

nsEvent::EventManager& MinGL::getEventManager()
{
    return eventManager;
} // getEventManager()

const nsGraphics::RGBAcolor& MinGL::getBackgroundColor() const
{
    return bgColor;
} // getBackgroundColor()

void MinGL::setBackgroundColor(const nsGraphics::RGBAcolor& backgroundColor)
{
    bgColor = backgroundColor;
    glClearColor(bgColor.getRed() / 256.f, bgColor.getGreen() / 256.f, bgColor.getBlue() / 256.f, bgColor.getAlpha() / 256.f);
} // setBackgroundColor()

void MinGL::initGraphic()
{
    // Initialisation GLUT
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(int(windowSize.getX()), int(windowSize.getY()));
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
    glClearColor(bgColor.getRed() / 256.f, bgColor.getGreen() / 256.f, bgColor.getBlue() / 256.f, bgColor.getAlpha() / 256.f);

    // Efface écran
    clearScreen();

    // Un tour de boucle pour lancer l'affichage
    glutMainLoopEvent();
    glutSetKeyRepeat(GLUT_KEY_REPEAT_OFF); // on désactive la répétition des touches
    windowIsOpen = true;
} // initGraphic()

void MinGL::stopGaphic()
{
    glutDestroyWindow(glutWindowId);
    glutMainLoopEvent();
} // stopGraphic()

/*!
 *  \brief      Tell if the key is pressed (true) or not (false)
 *
 *  \return     Returns `true` if the key is pressed and `false` if the key is not pressed
 *  \param[in]  key : the keypair (keyType) corresponding to the key you want to check
 */
bool MinGL::isPressed(const keyType &key)
{
    return keyboardMap[key];
} // isPressed()

/*!
 *
 * \brief set the key passed in parameter to not pressed (used in menus)
 *
 */
void MinGL::resetKey(const keyType &key)
{
    keyboardMap[key] = false;
} // resetKey()

void MinGL::callReshape(int h, int w)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, GLfloat (windowSize.getX()), GLfloat (windowSize.getY()), 0.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glViewport(0, 0, h, w);
} // callReshape()

void MinGL::callDisplay()
{
    glFlush();
    glutSwapBuffers();
} // callDisplay()

void MinGL::callMouse(int button, int state, int x, int y)
{
    nsEvent::Event_t event;
    event.eventType = nsEvent::EventType_t::MouseClick;
    event.eventData.clickData.button = button;
    event.eventData.clickData.state = state;
    event.eventData.clickData.x = x;
    event.eventData.clickData.y = y;

    eventManager.pushEvent(event);
} // calMouse()

void MinGL::callMotion(int x, int y)
{
    nsEvent::Event_t event;
    event.eventType = nsEvent::EventType_t::MouseDrag;
    event.eventData.moveData.x = x;
    event.eventData.moveData.y = y;

    eventManager.pushEvent(event);
} // callMotion()

void MinGL::callPassiveMotion(int x, int y)
{
    nsEvent::Event_t event;
    event.eventType = nsEvent::EventType_t::MouseMove;
    event.eventData.moveData.x = x;
    event.eventData.moveData.y = y;

    eventManager.pushEvent(event);
} // callPassiveMotion()

void MinGL::callKeyboard(unsigned char k, int x, int y)
{
    (void)(x); (void)(y);
    keyType key(k, false);
    keyboardMap[key] = true;
} // callKeyboard()

void MinGL::callKeyboardUp(unsigned char k, int x, int y)
{
    (void)(x); (void)(y);
    keyType key(k, false);
    keyboardMap[key] = false;
} // callKeyboardUp()

void MinGL::callKeyboardSpecial(int k, int x, int y)
{
    (void)(x); (void)(y);
    keyType key(k, true);
    keyboardMap[key] = true;
} // callKeyboardSpecial()

void MinGL::callKeyboardUpSpecial(int k, int x, int y)
{
    (void)(x); (void)(y);
    keyType key(k, true);
    keyboardMap[key] = false;
} // callKeyboardUpSpecial()

void MinGL::callClose()
{
    windowIsOpen = false;
} // callClose()

const nsGraphics::Vec2D MinGL::getWindowSize() const
{
    return windowSize;
} // getWindowSize()

bool MinGL::isOpen() const
{
    return windowIsOpen;
} // isOpen()
