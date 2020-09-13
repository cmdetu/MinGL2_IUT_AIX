/**
 *
 * @file    mingl.h
 * @author  Alexandre Sollier, Clément Mathieu--Drif, Alain Casali
 * @date    Janvier 2020
 * @version 2.0
 * @brief   La bête
 *
 **/

#ifndef MINGL_H
#define MINGL_H

#include <string>
#include <vector>
#include <queue>
#include <memory> // shared_ptr

#include <GL/freeglut.h>

#include "graph/idrawable.h"
#include "graph/libgraphique_fonts.h"
#include "graph/rgbacolor.hpp"
#include "graph/vec2d.hpp"

#include "event/event_manager.h"
#include "tools/myexception.h"
#include "tools/pixelexception.h"

/*!
 * \brief keyType : custom type representing a key of the keyboard
 * \details It's a pair of int and bool <br>
 *          <ul><li> the int is for the keycode </li>
 *              <li> the bool indicates if it's special or not (true -> special, false-> not special)</li></ul>
 *
 */
typedef std::pair<int, bool> keyType; // cle, spécial
/*!
 *
 * \brief   keyMap : map of the pressed keys
 * \details The keys are \ref keyType and is linked to true if pressed and false if not pressed (or reset)
 *
 */
typedef std::map<keyType, bool> keyMap;

/*!
 * \brief The minGL class
 *          sert de classe de base à tout le bordel
 */

// Pour les polices et l'affichage des chaines de caractères, voir: https://www.opengl.org/resources/libraries/glut/spec3/node76.html

class MinGL
{
private:
    // Les données membres en tant que tel
    const Vec2D windowSize;
    const std::string windowName;
    std::shared_ptr<font> windowFont = std::make_shared<font>(FONT_HELVETICA_10);
    RGBAcolor fontColor = KWhite;
    RGBAcolor bgColor;
    keyMap keyboardMap;


    // Ce dont on a besoin pour Glut
    short glutWindowId = 0;
    std::vector<std::unique_ptr<IDrawable>> drawStack;

    nsEvent::EventManager eventManager;
    bool windowIsOpen;

    // Les handlers
    void callReshape(int h, int w);
    void callDisplay();
    void callMouse(int button, int state, int x = 0, int y = 0);
    void callMotion(int x, int y);
    void callPassiveMotion(int x, int y);
    void callKeyboard(unsigned char key, int x = 0, int y = 0);
    void callKeyboardUp(unsigned char key, int x = 0, int y = 0);
    void callKeyboardSpecial(int key, int x = 0, int y = 0);
    void callKeyboardUpSpecial(int key, int x = 0, int y = 0);
    void callClose();

public:
    static void initGlut()
    {
        int tmp=0;
        glutInit(&tmp, NULL);
    }

    void initGraphic();
    void stopGaphic();

    bool isPressed(const keyType &key);
    void resetKey(const keyType &key);

    MinGL(const std::string &name_ = std::string(), const Vec2D &windowSize_ = Vec2D(640, 480), const RGBAcolor & backgroundColor = KWhite);
    ~MinGL();

    void addDrawable(std::unique_ptr<IDrawable> drawable);
    void updateGraphic();
    void clearScreen();

    nsEvent::EventManager &getEventManager();

    void setBackgroundColor(const RGBAcolor & backgroundColor);

    const Vec2D getWindowSize() const;
    bool isOpen() const;

};

#endif // MINGL_H
