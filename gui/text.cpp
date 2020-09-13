/**
 *
 * @file    text.h
 * @author  Alexandre Sollier
 * @date    Janvier 2020
 * @version 1.0
 * @brief   Du texte
 *
 **/

#include "text.h"

#include "../macros.h"

#define TEXT nsGui::Text

TEXT::Text(const Vec2D &position, const std::string &content,
           const RGBAcolor &textColor, const GlutFont::GlutFonts &textFont,
           const HorizontalAlignment &horizontalAlignment,
           const VerticalAlignment &verticalAlignment)
    : m_position(position)
    , m_content(content)
    , m_textColor(textColor)
    , m_textFont(textFont)
    , m_horizontalAlignment(horizontalAlignment)
    , m_verticalAlignment(verticalAlignment)
{} // Text()

std::unique_ptr<IDrawable> TEXT::clone() const
{
    return std::unique_ptr<Text>(new Text(*this));
} // clone()

void TEXT::getValues(const int &id, std::vector<float> &values)
{
    switch (id) {
        case TRANSITION_COLOR_RGB:
            values[0] = m_textColor.Red;
            values[1] = m_textColor.Green;
            values[2] = m_textColor.Blue;

            break;
        case TRANSITION_COLOR_ALPHA:
            values[0] = m_textColor.Alpha;

            break;
        case TRANSITION_POSITION:
            values[0] = m_position.x;
            values[1] = m_position.y;

            break;
    }
} // getValues()

void TEXT::setValues(const int &id, const std::vector<float> &values)
{
    switch (id) {
        case TRANSITION_COLOR_RGB:
            m_textColor.Red    = values[0];
            m_textColor.Green  = values[1];
            m_textColor.Blue   = values[2];

            break;
        case TRANSITION_COLOR_ALPHA:
            m_textColor.Alpha = values[0];

            break;
        case TRANSITION_POSITION:
            m_position.x = values[0];
            m_position.y = values[1];

            break;
    }
} // setValues()

int TEXT::computeWidth() const
{
    return glutBitmapLength(m_textFont.convertForGlut(), reinterpret_cast<const unsigned char *>(m_content.c_str()));
} // computeWidth()

int TEXT::computeHeight() const
{
    return glutBitmapHeight(m_textFont.convertForGlut());
} // computeHeight()

Vec2D TEXT::computeVisiblePosition() const
{
    int posX = m_position.x;
    switch (m_horizontalAlignment)
    {
        case TEXT::ALIGNH_RIGHT:
            posX -= computeWidth();

            break;
        case TEXT::ALIGNH_CENTER:
            posX -= computeWidth() / 2;

            break;
        default:
            break;
    }

    int posY = m_position.y;
    switch (m_verticalAlignment)
    {
        case TEXT::ALIGNV_TOP:
            posY += computeHeight();

            break;
        case TEXT::ALIGNV_CENTER:
            posY += computeHeight() / 2;

            break;
        default:
            break;
    }

    return Vec2D(posX, posY);
} // computeVisiblePosition()

Vec2D TEXT::computeVisibleEndPosition() const
{
    return computeVisiblePosition() + Vec2D(computeWidth(), -computeHeight());
} // computeVisibleEndPosition()

const std::string& TEXT::getContent() const
{
    return m_content;
} // getContent()

void nsGui::Text::setContent(const std::string &content)
{
    m_content = content;
} // setContent()

void TEXT::draw(MinGL &window)
{
    UNUSED(window);

    // Draw the text with the right color using Glut
    glColor4ub(m_textColor.Red, m_textColor.Green, m_textColor.Blue, m_textColor.Alpha);

    // Set the text position according to its alignment
    const Vec2D visiblePos = computeVisiblePosition();
    glRasterPos2i(visiblePos.x, visiblePos.y);

    glutBitmapString(m_textFont.convertForGlut(), reinterpret_cast<const unsigned char *>(m_content.c_str()));
} // draw()

#undef TEXT
