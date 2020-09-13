/**
 *
 * @file    event.hpp
 * @author  Alexandre Sollier
 * @date    Décembre 2019
 * @version 1.0
 * @brief   Différents types utile pour le gestionnaire d'événements
 *
 **/

#ifndef EVENT_HPP
#define EVENT_HPP

/**
 * @namespace nsEvent
 * @brief Espace de nom pour la gestion d'événements
 */
namespace nsEvent {

/**
 * @brief EventType_t : Liste de tout les types d'événements
 */
enum EventType_t {
    MouseClick, /**< L'utilisateur a cliqué sur un des boutons de la souris */
    MouseMove /**< Le curseur s'est déplacé */,
    MouseDrag, /**< Le curseur s'est déplacé pendant qu'un des boutons de la souris était pressé */
};

/**
 * @struct MouseClickData_t
 * @brief Possède des données pour un événement MouseClick
 */
struct MouseClickData_t {
    /**
     * @brief Constructeur pour la structure MouseClickData_t
     * @param[in] button_ : Bouton de la souris
     * @param[in] state_ : Etat du bouton
     * @param[in] x_ : Coordonnée X du curseur
     * @param[in] y_ : Coordonnée Y du curseur
     * @fn MouseClickData_t(const int &button_, const int &state_, const int &x_, const int &y_);
     */
    MouseClickData_t(const int &button_, const int &state_, const int &x_, const int &y_)
        : button(button_)
        , state(state_)
        , x(x_)
        , y(y_)
    {}

    int button; /**< ID numérique du bouton */
    int state; /**< Nouvel état du bouton */
    int x; /**< Coordonnée X du curseur, relative au coin supérieur-gauche de la fenêtre */
    int y; /**< Coordonnée Y du curseur, relative au coin supérieur-gauche de la fenêtre */
};

/**
 * @struct MouseMoveData_t
 * @brief Possède des données pour un événement MouseMove/MouseDrag
 */
struct MouseMoveData_t {
    /**
     * @brief Constructeur pour la structure MouseMoveData_t
     * @param[in] x_ : Coordonnée X du curseur
     * @param[in] y_ : Coordonnée Y du curseur
     * @fn MouseMoveData_t(const int &x_, const int &y_);
     */
    MouseMoveData_t(const int &x_, const int &y_)
        : x(x_)
        , y(y_)
    {}

    int x; /**< Coordonnée X du curseur, relative au coin supérieur-gauche de la fenêtre */
    int y; /**< Coordonnée Y du curseur, relative au coin supérieur-gauche de la fenêtre */
};

/**
 * @union EventData_t
 * @brief Union contenant les données d'un événement
 */
union EventData_t {
    MouseClickData_t clickData; /**< Données pour un événement MouseClick */
    MouseMoveData_t moveData; /**< Données pour un événment MouseMove/MouseDrag */
};

/**
 * @struct Event_t
 * @brief Possède des données pour un événement
 */
struct Event_t {
    /**
     * @brief Constructeur pour la structure Event_t
     * @param[in] eventType_ : Type d'événement
     * @param[in] eventData_ : Données d'événement
     * @fn Event_t(const EventType_t &eventType_, const EventData_t &eventData_);
     */
    Event_t(const EventType_t &eventType_, const EventData_t &eventData_)
        : eventType(eventType_)
        , eventData(eventData_)
    {}

    EventType_t eventType; /**< Type de l'événement */
    EventData_t eventData; /**< Données de l'événement */
};

} // namespace nsEvent

#endif // EVENT_HPP
