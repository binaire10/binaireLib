/**
 *
 * @file    CstCodErr.h
 *
 * @authors M. Laporte, D. Mathieu
 *
 * @date    21/04/2010
 *
 * @version V2.0
 *
 * @brief   Codes d'erreurs
 *
 **/
#pragma once

namespace nsUtil
{
    enum {KNoExc          = 0,
          KNoError        = 0,

          KExcOpInterdite = 101,      // operation interdite

          KErrArg         = 253,      // erreur des arguments (nombre ou types)
          KExcStd         = 254,
          KExcInconnue    = 255
         };

} // namespace nsUtil
