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

#ifndef SFML_MOUSE_ADDITION_H
    #define SFML_MOUSE_ADDITION_H

////////////////////////////////////////////////////////////
// Header
////////////////////////////////////////////////////////////
#include <SFML/Config.h>
#include <SFML/Graphics.h>
#include <SFML/Window/Mouse.h>
#include <SFML/Window/Keyboard.h>
#include <SFML/Addition/AnimatedSprite.h>

////////////////////////////////////////////////////////////
/// \brief Check if a mouse button is pressed on a sprite
///
/// \param renderWindow Render window object
/// \param sprite       Sprite object
/// \param mouseButton  Button to check
///
////////////////////////////////////////////////////////////
sfBool sfSprite_isMouseButtonPressed(const sfRenderWindow *renderWindow, const sfSprite *sprite, sfMouseButton mouseButton);

////////////////////////////////////////////////////////////
/// \brief Check if the mouse is hover a sprite
///
/// \param renderWindow Render window object
/// \param sprite       Sprite object
///
////////////////////////////////////////////////////////////
sfBool sfSprite_isMouseHover(const sfRenderWindow *renderWindow, const sfSprite *sprite);

////////////////////////////////////////////////////////////
/// \brief Check if a mouse button is pressed on an animated sprite
///
/// \param renderWindow     Render window object
/// \param animatedSprite   Sprite object
/// \param mouseButton      Button to check
///
////////////////////////////////////////////////////////////
sfBool sfAnimatedSprite_isMouseButtonPressed(const sfRenderWindow *renderWindow, const sfAnimatedSprite *animatedSprite, sfMouseButton mouseButton);

////////////////////////////////////////////////////////////
/// \brief Check if the mouse is hover an animated sprite
///
/// \param renderWindow     Render window object
/// \param animatedSprite   Animated sprite object
///
////////////////////////////////////////////////////////////
sfBool sfAnimatedSprite_isMouseHover(const sfRenderWindow *renderWindow, const sfAnimatedSprite *animatedSprite);

#endif // SFML_MOUSE_ADDITION_H
