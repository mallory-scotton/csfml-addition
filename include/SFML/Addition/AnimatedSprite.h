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

#ifndef SFML_ANIMATEDSPRITE_H
    #define SFML_ANIMATEDSPRITE_H

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/System/Clock.h>

////////////////////////////////////////////////////////////
/// \brief Utility class for manipulating animated sprites
///
////////////////////////////////////////////////////////////
typedef struct
{
    sfSprite *sprite;
    sfTexture *texture;
    sfClock *clock;
    size_t currentFrame;
    size_t maxFrame;
    sfVector2u frameSize;
    sfVector2u gridSize;
    size_t frameRate;
} sfAnimatedSprite;

////////////////////////////////////////////////////////////
/// \brief Create a new animated sprite
///
////////////////////////////////////////////////////////////
sfAnimatedSprite *sfAnimatedSprite_create(void);

////////////////////////////////////////////////////////////
/// \brief Create a new animated sprite from a file
///
/// \param filename Path of the image file to load
/// \param area     Area of the source image to load (NULL to load the entire image)
////////////////////////////////////////////////////////////
sfAnimatedSprite *sfAnimatedSprite_createFromFile(const char *filename, const sfIntRect *area);

////////////////////////////////////////////////////////////
/// \brief Destroy an existing animated sprite
///
/// \param animatedSprite   Animated sprite to delete
///
////////////////////////////////////////////////////////////
void sfAnimatedSprite_destroy(sfAnimatedSprite *animatedSprite);

////////////////////////////////////////////////////////////
/// \brief Set the position of an animated sprite
///
/// This function completely overwrites the previous position.
/// See sfAnimatedSprite_move to apply an offset based on the previous position instead.
/// The default position of a animated sprite object is (0, 0).
///
/// \param animatedSprite   Animated sprite object
/// \param position         New position
///
////////////////////////////////////////////////////////////
void sfAnimatedSprite_setPosition(sfAnimatedSprite *animatedSprite, sfVector2f position);

////////////////////////////////////////////////////////////
/// \brief Set the orientation of an animated sprite
///
/// This function completely overwrites the previous rotation.
/// See sfAnimatedSprite_rotate to add an angle based on the previous rotation instead.
/// The default rotation of a animated sprite object is 0.
///
/// \param animatedSprite   Animated sprite object
/// \param angle            New rotation, in degrees
///
////////////////////////////////////////////////////////////
void sfAnimatedSprite_setRotation(sfAnimatedSprite *animatedSprite, float angle);

////////////////////////////////////////////////////////////
/// \brief Set the scale factors of an animated sprite
///
/// This function completely overwrites the previous scale.
/// See sfAnimatedSprite_scale to add a factor based on the previous scale instead.
/// The default scale of a animated sprite object is (1, 1).
///
/// \param animatedSprite   Animated sprite object
/// \param scale            New scale factors
///
////////////////////////////////////////////////////////////
void sfAnimatedSprite_setScale(sfAnimatedSprite *animatedSprite, sfVector2f scale);

////////////////////////////////////////////////////////////
/// \brief Set the local origin of an animated sprite
///
/// The origin of an object defines the center point for
/// all transformations (position, scale, rotation).
/// The coordinates of this point must be relative to the
/// top-left corner of the object, and ignore all
/// transformations (position, scale, rotation).
/// The default origin of a animated sprite object is (0, 0).
///
/// \param animatedSprite   Animated sprite object
/// \param origin           New origin
///
////////////////////////////////////////////////////////////
void sfAnimatedSprite_setOrigin(sfAnimatedSprite *animatedSprite, sfVector2f origin);

////////////////////////////////////////////////////////////
/// \brief Get the position of an animated sprite
///
/// \param animatedSprite   Animated sprite object
///
/// \return Current position
///
////////////////////////////////////////////////////////////
sfVector2f sfAnimatedSprite_getPosition(const sfAnimatedSprite *animatedSprite);

////////////////////////////////////////////////////////////
/// \brief Get the orientation of an animated sprite
///
/// \param animatedSprite   Animated sprite object
///
/// \return Current rotation, in degrees
///
////////////////////////////////////////////////////////////
float sfAnimatedSprite_getRotation(const sfAnimatedSprite *animatedSprite);

////////////////////////////////////////////////////////////
/// \brief Get the current scale of an animated sprite
///
/// \param animatedSprite   Animated sprite object
///
/// \return Current scale factors
///
////////////////////////////////////////////////////////////
sfVector2f sfAnimatedSprite_getScale(const sfAnimatedSprite *animatedSprite);

////////////////////////////////////////////////////////////
/// \brief Get the local origin of an animated sprite
///
/// \param animatedSprite   Animated sprite object
///
/// \return Current origin
///
////////////////////////////////////////////////////////////
sfVector2f sfAnimatedSprite_getOrigin(const sfAnimatedSprite *animatedSprite);

////////////////////////////////////////////////////////////
/// \brief Move an animated sprite by a given offset
///
/// \param animatedSprite   Animated sprite object
/// \param offset           Offset
///
////////////////////////////////////////////////////////////
void sfAnimatedSprite_move(sfAnimatedSprite *animatedSprite, sfVector2f offset);

////////////////////////////////////////////////////////////
/// \brief Rotate an animated sprite
///
/// \param animatedSprite   Animated sprite object
/// \param angle            Angle of rotation, in degrees
///
////////////////////////////////////////////////////////////
void sfAnimatedSprite_rotate(sfAnimatedSprite *animatedSprite, float angle);

////////////////////////////////////////////////////////////
/// \brief Scale an animated sprite
///
/// \param animatedSprite   Animated sprite object
/// \param factors          Scale factors
///
////////////////////////////////////////////////////////////
void sfAnimatedSprite_scale(sfAnimatedSprite *animatedSprite, sfVector2f factors);

////////////////////////////////////////////////////////////
/// \brief Get the combined transform of an animated sprite
///
/// \param animatedSprite   Animated sprite object
///
/// \return Transform combining position/rotation/scale/origin of the object
///
////////////////////////////////////////////////////////////
sfTransform sfAnimatedSprite_getTransform(const sfAnimatedSprite *animatedSprite);

////////////////////////////////////////////////////////////
/// \brief Get the inverse of the combined transform of an animated sprite
///
/// \param animatedSprite   Animated sprite object
///
/// \return Inverse of the combined transformations applied to the object
///
////////////////////////////////////////////////////////////
sfTransform sfAnimatedSprite_getInverseTransform(sfAnimatedSprite *animatedSprite);

////////////////////////////////////////////////////////////
/// \brief Change the source texture of an animated sprite
///
/// The \a texture argument refers to a texture that must
/// exist as long as the sprite uses it. Indeed, the sprite
/// doesn't store its own copy of the texture, but rather keeps
/// a pointer to the one that you passed to this function.
/// If the source texture is destroyed and the sprite tries to
/// use it, the behaviour is undefined.
/// If \a resetRect is true, the TextureRect property of
/// the sprite is automatically adjusted to the size of the new
/// texture. If it is false, the texture rect is left unchanged.
///
/// \param animatedSprite   Animated sprite object
/// \param texture          New texture
/// \param resetRect        Should the texture rect be reset to the size of the new texture?
///
////////////////////////////////////////////////////////////
void sfAnimatedSprite_setTexture(sfAnimatedSprite *animatedSprite, const sfTexture *texture, sfBool resetRect);

////////////////////////////////////////////////////////////
/// \brief Set the global color of an animated sprite
///
/// This color is modulated (multiplied) with the sprite's
/// texture. It can be used to colorize the animated sprite, or change
/// its global opacity.
/// By default, the animated sprite's color is opaque white.
///
/// \param animatedSprite   Animated sprite object
/// \param color            New color of the animated sprite
///
////////////////////////////////////////////////////////////
void sfAnimatedSprite_setColor(sfAnimatedSprite *animatedSprite, sfColor color);

////////////////////////////////////////////////////////////
/// \brief Get the source texture of an animated sprite
///
/// If the sprite has no source texture, a NULL pointer is returned.
/// The returned pointer is const, which means that you can't
/// modify the texture when you retreive it with this function.
///
/// \param animatedSprite   Animated sprite object
///
/// \return Pointer to the sprite's texture
///
////////////////////////////////////////////////////////////
const sfTexture *sfAnimatedSprite_getTexture(const sfAnimatedSprite *animatedSprite);

////////////////////////////////////////////////////////////
/// \brief Get the global color of an animated sprite
///
/// \param animatedSprite   Animated sprite object
///
/// \return Global color of an animated sprite
///
////////////////////////////////////////////////////////////
sfColor sfAnimatedSprite_getColor(const sfAnimatedSprite *animatedSprite);

////////////////////////////////////////////////////////////
/// \brief Get the local bounding rectangle of an animated sprite
///
/// The returned rectangle is in local coordinates, which means
/// that it ignores the transformations (translation, rotation,
/// scale, ...) that are applied to the entity.
/// In other words, this function returns the bounds of the
/// entity in the entity's coordinate system.
///
/// \param animatedSprite   Animated sprite object
///
/// \return Local bounding rectangle of the entity
///
////////////////////////////////////////////////////////////
sfFloatRect sfAnimatedSprite_getLocalBounds(const sfAnimatedSprite *animatedSprite);

////////////////////////////////////////////////////////////
/// \brief Get the global bouding rectangle of an animated sprite
///
/// The returned rectangle is in global coordinates, which means
/// that it takes in account the transformations (translation,
/// rotation, scale, ...) that are applied to the entity.
/// In other words, this function returns the bounds of the
/// animated sprite in the global 2D world's coodinate system.
///
/// \param animatedSprite   Animated sprite object
///
/// \return Global bounding rectangle of the entity
///
////////////////////////////////////////////////////////////
sfFloatRect sfAnimatedSprite_getGlobalBounds(const sfAnimatedSprite *animatedSprite);

////////////////////////////////////////////////////////////
/// \brief Set the frame rate of the animation of an animated sprite
///
/// \param animatedSprite   Animated sprite object
/// \param frameRate        Frame rate, in frames per seconds
///
////////////////////////////////////////////////////////////
void sfAnimatedSprite_setFrameRate(sfAnimatedSprite *animatedSprite, size_t frameRate);

////////////////////////////////////////////////////////////
/// \brief Get the frame rate of an animated sprite
///
/// \param animatedSprite   Animated sprite object
///
/// \return Frame rate, in frames per seconds
///
////////////////////////////////////////////////////////////
size_t sfAnimatedSprite_getFrameRate(const sfAnimatedSprite *animatedSprite);

////////////////////////////////////////////////////////////
/// \brief Set the frame size of an animated sprite
///
/// \param animatedSprite   Animated sprite object
/// \param size             Size of a frame
///
////////////////////////////////////////////////////////////
void sfAnimatedSprite_setFrameSize(sfAnimatedSprite *animatedSprite, sfVector2u size);

////////////////////////////////////////////////////////////
/// \brief Get the frame size of an animated sprite
///
/// \param animatedSprite   Animated sprite object
///
/// \return The frame size
///
////////////////////////////////////////////////////////////
sfVector2u sfAnimatedSprite_getFrameSize(const sfAnimatedSprite *animatedSprite);

////////////////////////////////////////////////////////////
/// \brief Set the grid size of an animated sprite
///
/// The grid size represents how many frames there is in
/// x, and how many there is in y.
///
/// \param animatedSprite   Animated sprite object
/// \param size             The size of the grid
///
////////////////////////////////////////////////////////////
void sfAnimatedSprite_setGridSize(sfAnimatedSprite *animatedSprite, sfVector2u size);

////////////////////////////////////////////////////////////
/// \brief Get the grid size of an animated sprite
///
/// The grid size represents how many frames there is in
/// x, and how many there is in y.
///
/// \param animatedSprite   Animated sprite object
///
/// \return The grid size
///
////////////////////////////////////////////////////////////
sfVector2u sfAnimatedSprite_getGridSize(const sfAnimatedSprite *animatedSprite);

////////////////////////////////////////////////////////////
/// \brief Draw a drawable object to the render-target
///
/// \param renderWindow     render window object
/// \param animatedSprite   Object to draw
/// \param states           Render states to use for drawing (NULL to use the default states)
///
////////////////////////////////////////////////////////////
void sfRenderWindow_drawAnimatedSprite(const sfRenderWindow *renderWindow, sfAnimatedSprite *animatedSprite, sfRenderStates *states);

#endif // SFML_ANIMATEDSPRITE_H
