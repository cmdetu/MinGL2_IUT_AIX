#include "button.h"

#define BUTTON nsGui::Button

BUTTON::Button(const std::string &text, const Vec2D &position, const Vec2D &size, const RGBAcolor &firstColor, const RGBAcolor &secondColor)
    : m_buttonText(Vec2D(position.x + size.x / 2, position.y + size.y / 2 - 5), text, KWhite,
                   GlutFont::BITMAP_HELVETICA_18, nsGui::Text::ALIGNH_CENTER, nsGui::Text::ALIGNV_CENTER)
    , m_firstColor(firstColor)
    , m_secondColor(secondColor)
    , m_position(position)
    , m_size(size)
{} // Button()

BUTTON::Button(const std::string &text, const Vec2D &position, const Vec2D &size, const RGBAcolor &firstColor)
    : Button(text, position, size, firstColor, firstColor)
{} // Button()

std::unique_ptr<IDrawable> BUTTON::clone() const
{
    return std::unique_ptr<Button>(new Button(*this));
} // clone()

void BUTTON::getValues(const int &id, std::vector<float> &values)
{
    switch (id) {
        case TRANSITION_FIRST_RGB:
            values[0] = m_firstColor.Red;
            values[1] = m_firstColor.Green;
            values[2] = m_firstColor.Blue;

            break;
        case TRANSITION_SECOND_RGB:
            values[0] = m_secondColor.Red;
            values[1] = m_secondColor.Green;
            values[2] = m_secondColor.Blue;

            break;
        case TRANSITION_FIRST_ALPHA:
            values[0] = m_firstColor.Alpha;

            break;
        case TRANSITION_SECOND_ALPHA:
            values[0] = m_secondColor.Alpha;

            break;
        case TRANSITION_POSITION:
            values[0] = m_position.x;
            values[1] = m_position.y;

            break;

        case TRANSITION_SIZE:
            values[0] = m_size.x;
            values[1] = m_size.y;

            break;
    }
} // getValues()

void BUTTON::setValues(const int &id, const std::vector<float> &values)
{
    switch (id) {
        case TRANSITION_FIRST_RGB:
            m_firstColor.Red    = values[0];
            m_firstColor.Green  = values[1];
            m_firstColor.Blue   = values[2];

            break;
        case TRANSITION_SECOND_RGB:
            m_secondColor.Red    = values[0];
            m_secondColor.Green  = values[1];
            m_secondColor.Blue   = values[2];

            break;
        case TRANSITION_FIRST_ALPHA:
            m_firstColor.Alpha = values[0];

            break;
        case TRANSITION_SECOND_ALPHA:
            m_secondColor.Alpha = values[0];

            break;
        case TRANSITION_POSITION:
            m_position.x    = values[0];
            m_position.y    = values[1];

            break;
        case TRANSITION_SIZE:
            m_size.x = values[0];
            m_size.y = values[1];

            break;
    }
} // setValues()

const Vec2D& nsGui::Button::getPosition() const
{
    return m_position;
} // getPosition()

void nsGui::Button::setPosition(const Vec2D &position)
{
    m_position = position;
} // setPosition()

const Vec2D& nsGui::Button::getSize() const
{
    return m_size;
} // getSize()

void nsGui::Button::setSize(const Vec2D &size)
{
    m_size = size;
} // setSize()

void BUTTON::draw(MinGL &window)
{
    // Draw the button background
    glShadeModel(GL_SMOOTH);

    glBegin(GL_POLYGON);

    glColor4ub(m_firstColor.Red, m_firstColor.Green, m_firstColor.Blue, m_firstColor.Alpha);
    glVertex2i(m_position.x, m_position.y);
    glVertex2i(m_position.x, m_position.y + m_size.y);

    glColor4ub(m_secondColor.Red, m_secondColor.Green, m_secondColor.Blue, m_secondColor.Alpha);
    glVertex2i(m_position.x + m_size.x, m_position.y + m_size.y);
    glVertex2i(m_position.x + m_size.x, m_position.y);

    glEnd();

    glShadeModel(GL_FLAT);

    // Draw the text
    window << m_buttonText;
} // draw()

#undef BUTTON
