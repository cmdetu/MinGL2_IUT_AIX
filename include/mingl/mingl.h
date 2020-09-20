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

#include <map>
#include <memory> // shared_ptr
#include <queue>
#include <string>
#include <vector>

#include <GL/freeglut.h>

#include "graphics/idrawable.h"
#include "graphics/rgbacolor.h"
#include "graphics/vec2d.h"

#include "event/event_manager.h"

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

public:
    MinGL(const std::string& name, const nsGraphics::Vec2D& windowSize = nsGraphics::Vec2D(640, 480), const nsGraphics::RGBAcolor& backgroundColor = nsGraphics::KWhite);
    ~MinGL();

    static void initGlut()
    {
        int tmp=0;
        glutInit(&tmp, NULL);
    }

    void initGraphic();
    void stopGaphic();

    bool isPressed(const keyType& key);
    void resetKey(const keyType& key);

    void finishFrame();
    void clearScreen();

    nsEvent::EventManager& getEventManager();

    const nsGraphics::RGBAcolor& getBackgroundColor() const;
    void setBackgroundColor(const nsGraphics::RGBAcolor& backgroundColor);

    const nsGraphics::Vec2D getWindowSize() const;
    bool isOpen() const;

private:
    // Les données membres en tant que tel
    const nsGraphics::Vec2D windowSize;
    const std::string windowName;
    nsGraphics::RGBAcolor fontColor = nsGraphics::KWhite;
    nsGraphics::RGBAcolor bgColor;
    keyMap keyboardMap;

    // Ce dont on a besoin pour Glut
    short glutWindowId = 0;

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

}; // class MinGL

#endif // MINGL_H
