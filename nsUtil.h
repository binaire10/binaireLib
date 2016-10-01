/**
 *
 * @file    nsUtil.h
 *
 * @authors M. Laporte, D. Mathieu
 *
 * @date    10/11/2005
 *
 * @version V1.0
 *
 * @brief   Quelques outils pour les TPs d'Algo-Programmation
 *
 *      int Rand (int Min, int Max) 
 *              renvoie un entier aleatoire dans l'intervalle [Min, Max]
 **/

#pragma once
#include  <cstdlib>

namespace nsUtil
{
    inline int Rand (int Min, int Max)
    {
        return rand()%(Max-Min) +Min;
    }

} // namespace nsUtil
