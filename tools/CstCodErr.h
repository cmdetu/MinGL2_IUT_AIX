/**
 *
 * @file    CstCodErr.h
 *
 * @authors D. Mathieu
 *
 * @date    28/08/2010
 *
 * @version V2.0
 *
 * @brief   Codes d'erreurs
 *
 **/

#if ! defined __CSTCODERR_H__
#define       __CSTCODERR_H__

#include <map>
#include <string>

namespace nsUtil
{
    enum {
        KNoExc          = 0,
        KNoError        = 0,

        kColorOutOfBounds = 100,

        KFileError      = 252, // Erreur a l'ouverture du fichier
        KErrArg         = 253, // Erreur des arguments (nombre ou types)
        KExcStd         = 254,
        kExcInconnue    = -1,

        kErrTooHight    = 300,
        kErrTooRight    = 301,
        kErrFontSize    = 302,
        kNoTriangle     = 303,
        kNoLine         = 304,
        kNoRectangle    = 305,
        kNoCircle       = 306,
        kTypeNotFound   = 307,

        kScreenNotFound     = 400,
        kDifficultyNotFound = 401,
        kFileNotFound       = 402,
    };

    const std::map <unsigned, std::string> kError
    {
        {kErrTooHight, "Trop haut"},
        {kErrTooRight, "Trop à droite"},
        {kErrFontSize, "Taille de police incorrecte"},
        {kNoTriangle, "Nombre incorrect de points pour la construction du triangle"},
        {kNoLine, "Nombre incorrect de points pour la construction d'une ligne"},
        {kNoRectangle, "Nombre incorrect de points pour la construction d'un rectangle"},
        {kNoCircle, "Nombre incorrect de points pour la construction d'un cercle"},
        {kTypeNotFound, "Instanciation impossible: Pas le bon type"},
        {kScreenNotFound, "Impossible de trouver l'écran via son identifiant."},
        {kDifficultyNotFound, "Impossible de trouver la difficulté spécifiée."},
        {kFileNotFound, "Le fichier spécifié est introuvable."}
    };
} // namespace nsUtil

#endif        /* __CSTCODERR_H__ */
