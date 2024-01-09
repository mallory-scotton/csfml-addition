////////////////////////////////////////////////////////////
//
// CSFML-ADDITION - Simple and Fast Multimedia Library addon
// Copyright (C) 2023 Mallory Scotton (mscotton.pro@gmail.com)
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
////////////////////////////////////////////////////////////

#ifndef SFML_BEZIERCURVE_H
    #define SFML_BEZIERCURVE_H

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Graphics.h>
#include <stdlib.h>

////////////////////////////////////////////////////////////
/// \brief
///
////////////////////////////////////////////////////////////
typedef struct
{
    sfVector2f *points;
    size_t pointCount;
    sfColor color;
} sfBezierCurve;

////////////////////////////////////////////////////////////
/// \brief Construct a new bezier curve
///
////////////////////////////////////////////////////////////
CSFML_API_EXPORT sfBezierCurve *sfBezierCurve_create(void);

////////////////////////////////////////////////////////////
/// \brief Destroy an existing bezier curve
///
/// \param bezierCurve Bezier curve to destroy
///
////////////////////////////////////////////////////////////
CSFML_API_EXPORT void sfBezierCurve_destroy(sfBezierCurve *bezierCurve);

////////////////////////////////////////////////////////////
/// \brief Set the color of the curve
///
/// By default, the color is set to sfTransparent.
///
/// \param bezierCurve  Bezier curve object
/// \param color        New color of the curve
///
////////////////////////////////////////////////////////////
CSFML_API_EXPORT void sfBezierCurve_setCurveColor(sfBezierCurve *bezierCurve, sfColor color);

////////////////////////////////////////////////////////////
/// \brief Add a new point to the curve
///
/// \param bezierCurve  Bezier curve object
/// \param point        New point of the curve
///
////////////////////////////////////////////////////////////
CSFML_API_EXPORT void sfBezierCurve_addPoint(sfBezierCurve *bezierCurve, sfVector2f point);

////////////////////////////////////////////////////////////
/// \brief Calculate current point based with time in percent from 0 to 1
///
/// \param bezierCurve  Bezier curve object
/// \param time         Time from 0 to 1 for point offset
///
////////////////////////////////////////////////////////////
CSFML_API_EXPORT sfVector2f sfBezierCurve_calculatePoint(const sfBezierCurve *bezierCurve, float time);

////////////////////////////////////////////////////////////
/// \brief Draw a drawable object to the render-target
///
/// \param renderWindow render window object
/// \param bezierCurve  Object to draw
/// \param states       Render states to use for drawing (NULL to use the default states)
///
////////////////////////////////////////////////////////////
CSFML_API_EXPORT void sfRenderWindow_drawBezierCurve(const sfRenderWindow *renderWindow, const sfBezierCurve *bezierCurve, const sfRenderStates *states);

////////////////////////////////////////////////////////////
/// \brief Move a bezier curve by a given offset
///
/// \param bezierCurve  Bezier curve object
/// \param offset       Offset
///
////////////////////////////////////////////////////////////
CSFML_API_EXPORT void sfBezierCurve_move(sfBezierCurve *bezierCurve, sfVector2f offset);

#endif // SFML_BEZIERCURVE_H
