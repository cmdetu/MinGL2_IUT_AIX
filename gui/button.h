#ifndef BUTTON_H
#define BUTTON_H

#include "text.h"
#include "../graph/iminglinjectable.h"
#include "../transition/itransitionable.h"

namespace nsGui
{

/**
 * @class Button
 * @brief Fournit un fond coloré avec du texte centré a l'intérieur, a utiliser comme bouton
 */
class Button : public IminGlInjectable, public nsTransition::ITransitionable
{
public:
    /**
     * @brief TransitionIds : Liste de toutes les transitions que cet élément peut exécuter
     */
    enum TransitionIds {
        TRANSITION_FIRST_RGB, /**< Transition pour la première couleur RGB */
        TRANSITION_SECOND_RGB, /**< Transition pour la seconde couleur RGB (pour un dégradé) */
        TRANSITION_FIRST_ALPHA, /**< Transition pour la première transparence */
        TRANSITION_SECOND_ALPHA, /**< Transition pour la seconde transparence (pour un dégradé) */
        TRANSITION_POSITION, /**< Transition pour la position */
        TRANSITION_SIZE, /**< Transition pour la taille */
    };

    /**
     * @brief Constructeur pour la classe Button, utiliser celle-ci produira un dégradé
     * @param[in] text : Texte a l'intérieur du Button
     * @param[in] position : Position du Button
     * @param[in] size : Size du Button
     * @param[in] firstColor : Première couleur du Button
     * @param[in] secondColor : Seconde couleur du Button
     * @fn Button(const std::string &text, const Vec2D &position, const Vec2D &size, const RGBAcolor &firstColor, const RGBAcolor &secondColor);
     */
    Button(const std::string &text, const Vec2D &position, const Vec2D &size, const RGBAcolor &firstColor, const RGBAcolor &secondColor);

    /**
     * @brief Constructeur pour la classe Button, utiliser celle-ci produira un bouton unicolore
     * @param[in] text : Texte a l'intérieur du Button
     * @param[in] position : Position du Button
     * @param[in] size : Size du Button
     * @param[in] firstColor : Première couleur du Button
     * @fn Button(const std::string &text, const Vec2D &position, const Vec2D &size, const RGBAcolor &firstColor);
     */
    Button(const std::string &text, const Vec2D &position, const Vec2D &size, const RGBAcolor &firstColor);

    virtual std::unique_ptr<IDrawable> clone() const override;
    virtual void draw(MinGL &window) override;

    virtual void getValues(const int &id, std::vector<float> &values) override;
    virtual void setValues(const int &id, const std::vector<float> &values) override;

    /**
     * @brief Récupère la position du bouton
     * @return Une référence const vers m_position
     * @fn const Vec2D& getPosition() const;
     */
    const Vec2D& getPosition() const;

    /**
     * @brief Définit la nouvelle position du bouton
     * @param[in] position : Nouvelle position
     * @fn void setPosition(const Vec2D &position);
     */
    void setPosition(const Vec2D &position);

    /**
     * @brief Récupère la taille du bouton
     * @return Une référence const vers m_size
     * @fn const Vec2D& getSize() const;
     */
    const Vec2D& getSize() const;

    /**
     * @brief Définit la nouvelle taille du bouton
     * @param[in] size : Nouvelle taille
     * @fn void setSize(const Vec2D &size);
     */
    void setSize(const Vec2D &size);

private:
    /**
     * @brief m_buttonText : L'objet Text de ce Button
     */
    Text m_buttonText;

    /**
     * @brief m_firstColor : La première couleur, la plus a gauche
     */
    RGBAcolor m_firstColor;

    /**
     * @brief m_secondColor : La seconde couleur, la plus a droite
     */
    RGBAcolor m_secondColor;

    /**
     * @brief m_position : Position de ce Button
     */
    Vec2D m_position;

    /**
     * @brief m_position : Taille de ce Button
     */
    Vec2D m_size;
};

} // namespace nsGui

#endif // BUTTON_H
