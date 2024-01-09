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

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Addition/BezierCurve.h>

////////////////////////////////////////////////////////////
sfBezierCurve *sfBezierCurve_create(void)
{
    sfBezierCurve *bezierCurve = malloc(sizeof(sfBezierCurve));

    if (!bezierCurve)
        return (bezierCurve);
    bezierCurve->color = sfTransparent;
    bezierCurve->pointCount = 0;
    bezierCurve->points = NULL;
    return (bezierCurve);
}

////////////////////////////////////////////////////////////
void sfBezierCurve_destroy(sfBezierCurve *bezierCurve)
{
    if (bezierCurve == NULL)
        return;
    free(bezierCurve->points);
    free(bezierCurve);
}

////////////////////////////////////////////////////////////
void sfBezierCurve_setCurveColor(sfBezierCurve *bezierCurve, sfColor color)
{
    if (bezierCurve == NULL)
        return;
    bezierCurve->color = color;
}

////////////////////////////////////////////////////////////
void sfBezierCurve_addPoint(sfBezierCurve *bezierCurve, sfVector2f point)
{
    if (bezierCurve == NULL)
        return;
    bezierCurve->pointCount++;
    bezierCurve->points = realloc(bezierCurve->points, bezierCurve->pointCount * sizeof(sfVector2f));
    bezierCurve->points[bezierCurve->pointCount - 1] = point;
}

////////////////////////////////////////////////////////////
sfVector2f sfBezierCurve_calculatePoint(const sfBezierCurve *bezierCurve, float time)
{
    sfVector2f *points = bezierCurve->points;
    size_t n = bezierCurve->pointCount - 1;
    sfVector2f *tmpPoints = malloc(sizeof(sfVector2f) * bezierCurve->pointCount);
    sfVector2f result;

    if (n < 1)
        return ((sfVector2f){-1, -1});
    for (size_t i = 0; i < bezierCurve->pointCount; i++)
        tmpPoints[i] = points[i];
    for (size_t k = 0; k <= n; k++) {
        for (size_t i = 0; i <= n; i++) {
            tmpPoints[i].x = (1 - time) * tmpPoints[i].x + time * tmpPoints[i + 1].x;
            tmpPoints[i].y = (1 - time) * tmpPoints[i].y + time * tmpPoints[i + 1].y;
        }
    }
    result = tmpPoints[0];
    free(tmpPoints);
    return (result);
}

////////////////////////////////////////////////////////////
void sfBezierCurve_move(sfBezierCurve *bezierCurve, sfVector2f offset)
{
    if (bezierCurve == NULL)
        return;
    for (size_t i = 0; i < bezierCurve->pointCount; i++) {
        bezierCurve->points[i].x += offset.x;
        bezierCurve->points[i].y += offset.y;
    }
}

////////////////////////////////////////////////////////////
void sfRenderWindow_drawBezierCurve(const sfRenderWindow *renderWindow, const sfBezierCurve *bezierCurve, const sfRenderStates *states)
{
    sfVertexArray *curve = sfVertexArray_create();
    sfVertex vertex;

    if (bezierCurve == NULL || bezierCurve->pointCount < 2)
        return (sfVertexArray_destroy(curve));
    for (float time = 0; time < 1; time += 0.0001) {
        vertex.position = sfBezierCurve_calculatePoint(bezierCurve, time);
        vertex.color = bezierCurve->color;
        sfVertexArray_append(curve, vertex);
    }
    sfRenderWindow_drawVertexArray(renderWindow, curve, states);
    sfVertexArray_destroy(curve);
}
