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
#include <SFML/Addition/Mouse.h>

////////////////////////////////////////////////////////////
sfBool sfSprite_isMouseButtonPressed(const sfRenderWindow *renderWindow, const sfSprite *sprite, sfMouseButton mouseButton)
{
    if (!sfMouse_isButtonPressed(mouseButton))
        return (sfFalse);
    return (sfSprite_isMouseHover(renderWindow, sprite));
}

////////////////////////////////////////////////////////////
sfBool sfSprite_isMouseHover(const sfRenderWindow *renderWindow, const sfSprite *sprite)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(renderWindow);
    sfFloatRect bounds = sfSprite_getGlobalBounds(sprite);

    return (sfFloatRect_contains(&bounds, (float)mouse.x, (float)mouse.y));
}

////////////////////////////////////////////////////////////
sfBool sfAnimatedSprite_isMouseButtonPressed(const sfRenderWindow *renderWindow, const sfAnimatedSprite *animatedSprite, sfMouseButton mouseButton)
{
    return (sfSprite_isMouseButtonPressed(renderWindow, animatedSprite->sprite, mouseButton));
}

////////////////////////////////////////////////////////////
sfBool sfAnimatedSprite_isMouseHover(const sfRenderWindow *renderWindow, const sfAnimatedSprite *animatedSprite)
{
    return (sfSprite_isMouseHover(renderWindow, animatedSprite->sprite));
}
