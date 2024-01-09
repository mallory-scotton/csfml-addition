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
#include <SFML/Addition/AnimatedSprite.h>

////////////////////////////////////////////////////////////
sfAnimatedSprite *sfAnimatedSprite_create(void)
{
    sfAnimatedSprite *animatedSprite = malloc(sizeof(sfAnimatedSprite));

    if (animatedSprite == NULL)
        return (NULL);
    animatedSprite->clock = sfClock_create();
    animatedSprite->currentFrame = 0;
    animatedSprite->frameRate = 0;
    animatedSprite->texture = NULL;
    animatedSprite->sprite = sfSprite_create();
    if (animatedSprite->clock == NULL || animatedSprite->sprite == NULL) {
        if (animatedSprite->clock)
            sfClock_destroy(animatedSprite->clock);
        if (animatedSprite->sprite)
            sfSprite_destroy(animatedSprite->sprite);
        free(animatedSprite);
        return (NULL);
    }
    return (animatedSprite);
}

////////////////////////////////////////////////////////////
sfAnimatedSprite *sfAnimatedSprite_createFromFile(const char *filename, const sfIntRect *area)
{
    sfAnimatedSprite *animatedSprite = sfAnimatedSprite_create();

    if (animatedSprite == NULL)
        return (NULL);
    animatedSprite->texture = sfTexture_createFromFile(filename, area);
    if (animatedSprite->texture == NULL) {
        sfClock_destroy(animatedSprite->clock);
        free(animatedSprite);
        return (NULL);
    }
    sfSprite_setTexture(animatedSprite->sprite, animatedSprite->texture, sfTrue);
    return (animatedSprite);
}

////////////////////////////////////////////////////////////
void sfAnimatedSprite_destroy(sfAnimatedSprite *animatedSprite)
{
    if (animatedSprite == NULL)
        return;
    if (animatedSprite->texture)
        sfTexture_destroy(animatedSprite->texture);
    sfSprite_destroy(animatedSprite->sprite);
    sfClock_destroy(animatedSprite->clock);
    free(animatedSprite);
}

////////////////////////////////////////////////////////////
void sfAnimatedSprite_setPosition(sfAnimatedSprite *animatedSprite, sfVector2f position)
{
    if (animatedSprite == NULL)
        return;
    sfSprite_setPosition(animatedSprite->sprite, position);
}

////////////////////////////////////////////////////////////
void sfAnimatedSprite_setRotation(sfAnimatedSprite *animatedSprite, float angle)
{
    if (animatedSprite == NULL)
        return;
    sfSprite_setRotation(animatedSprite->sprite, angle);
}

////////////////////////////////////////////////////////////
void sfAnimatedSprite_setScale(sfAnimatedSprite *animatedSprite, sfVector2f scale)
{
    if (animatedSprite == NULL)
        return;
    sfSprite_setScale(animatedSprite->sprite, scale);
}

////////////////////////////////////////////////////////////
void sfAnimatedSprite_setOrigin(sfAnimatedSprite *animatedSprite, sfVector2f origin)
{
    if (animatedSprite == NULL)
        return;
    sfSprite_setOrigin(animatedSprite->sprite, origin);
}

////////////////////////////////////////////////////////////
sfVector2f sfAnimatedSprite_getPosition(const sfAnimatedSprite *animatedSprite)
{
    if (animatedSprite == NULL)
        return ((sfVector2f){0, 0});
    return (sfSprite_getPosition(animatedSprite->sprite));
}

////////////////////////////////////////////////////////////
float sfAnimatedSprite_getRotation(const sfAnimatedSprite *animatedSprite)
{
    if (animatedSprite == NULL)
        return (0.0);
    return (sfSprite_getRotation(animatedSprite->sprite));
}

////////////////////////////////////////////////////////////
sfVector2f sfAnimatedSprite_getScale(const sfAnimatedSprite *animatedSprite)
{
    if (animatedSprite == NULL)
        return ((sfVector2f){0, 0});
    return (sfSprite_getScale(animatedSprite->sprite));
}

////////////////////////////////////////////////////////////
sfVector2f sfAnimatedSprite_getOrigin(const sfAnimatedSprite *animatedSprite)
{
    if (animatedSprite == NULL)
        return ((sfVector2f){0, 0});
    return (sfSprite_getOrigin(animatedSprite->sprite));
}

////////////////////////////////////////////////////////////
void sfAnimatedSprite_move(sfAnimatedSprite *animatedSprite, sfVector2f offset)
{
    if (animatedSprite == NULL)
        return;
    sfSprite_move(animatedSprite->sprite, offset);
}

////////////////////////////////////////////////////////////
void sfAnimatedSprite_rotate(sfAnimatedSprite *animatedSprite, float angle)
{
    if (animatedSprite == NULL)
        return;
    sfSprite_rotate(animatedSprite->sprite, angle);
}

////////////////////////////////////////////////////////////
void sfAnimatedSprite_scale(sfAnimatedSprite *animatedSprite, sfVector2f factors)
{
    if (animatedSprite == NULL)
        return;
    sfSprite_scale(animatedSprite->sprite, factors);
}

////////////////////////////////////////////////////////////
sfTransform sfAnimatedSprite_getTransform(const sfAnimatedSprite *animatedSprite)
{
    return (sfSprite_getTransform(animatedSprite->sprite));
}

////////////////////////////////////////////////////////////
sfTransform sfAnimatedSprite_getInverseTransform(sfAnimatedSprite *animatedSprite)
{
    return (sfSprite_getInverseTransform(animatedSprite->sprite));
}

////////////////////////////////////////////////////////////
void sfAnimatedSprite_setTexture(sfAnimatedSprite *animatedSprite, const sfTexture *texture, sfBool resetRect)
{
    if (animatedSprite == NULL)
        return;
    sfSprite_setTexture(animatedSprite->sprite, texture, resetRect);
}

////////////////////////////////////////////////////////////
void sfAnimatedSprite_setColor(sfAnimatedSprite *animatedSprite, sfColor color)
{
    if (animatedSprite == NULL)
        return;
    sfSprite_setColor(animatedSprite->sprite, color);
}

////////////////////////////////////////////////////////////
const sfTexture *sfAnimatedSprite_getTexture(const sfAnimatedSprite *animatedSprite)
{
    if (animatedSprite == NULL)
        return (NULL);
    return (sfSprite_getTexture(animatedSprite->sprite));
}

////////////////////////////////////////////////////////////
sfColor sfAnimatedSprite_getColor(const sfAnimatedSprite *animatedSprite)
{
    if (animatedSprite == NULL)
        return ((sfColor){0, 0, 0, 0});
    return (sfSprite_getColor(animatedSprite->sprite));
}

////////////////////////////////////////////////////////////
sfFloatRect sfAnimatedSprite_getLocalBounds(const sfAnimatedSprite *animatedSprite)
{
    if (animatedSprite == NULL)
        return ((sfFloatRect){0, 0, 0, 0});
    return (sfSprite_getLocalBounds(animatedSprite->sprite));
}

////////////////////////////////////////////////////////////
sfFloatRect sfAnimatedSprite_getGlobalBounds(const sfAnimatedSprite *animatedSprite)
{
    if (animatedSprite == NULL)
        return ((sfFloatRect){0, 0, 0, 0});
    return (sfSprite_getGlobalBounds(animatedSprite->sprite));
}

////////////////////////////////////////////////////////////
void sfAnimatedSprite_setFrameRate(sfAnimatedSprite *animatedSprite, size_t frameRate)
{
    if (animatedSprite == NULL)
        return;
    animatedSprite->frameRate = frameRate;
}

////////////////////////////////////////////////////////////
size_t sfAnimatedSprite_getFrameRate(const sfAnimatedSprite *animatedSprite)
{
    if (animatedSprite == NULL)
        return (-1);
    return (animatedSprite->frameRate);
}

////////////////////////////////////////////////////////////
void sfAnimatedSprite_setFrameSize(sfAnimatedSprite *animatedSprite, sfVector2u frameRate)
{
    if (animatedSprite == NULL)
        return;
    animatedSprite->frameSize = frameRate;
}

////////////////////////////////////////////////////////////
sfVector2u sfAnimatedSprite_getFrameSize(const sfAnimatedSprite *animatedSprite)
{
    if (animatedSprite == NULL)
        return ((sfVector2u){0, 0});
    return (animatedSprite->frameSize);
}

////////////////////////////////////////////////////////////
void sfAnimatedSprite_setGridSize(sfAnimatedSprite *animatedSprite, sfVector2u size)
{
    if (animatedSprite == NULL)
        return;
    animatedSprite->gridSize = size;
}

////////////////////////////////////////////////////////////
sfVector2u sfAnimatedSprite_getGridSize(const sfAnimatedSprite *animatedSprite)
{
    if (animatedSprite == NULL)
        return ((sfVector2u){0, 0});
    return (animatedSprite->gridSize);
}

////////////////////////////////////////////////////////////
void sfRenderWindow_drawAnimatedSprite(const sfRenderWindow *renderWindow, sfAnimatedSprite *animatedSprite, sfRenderStates *states)
{
    int fps = ((int)((float)(60 / animatedSprite->frameRate)) * 10);
    int ms = sfClock_getElapsedTime(animatedSprite->clock).microseconds * 1000;
    sfIntRect mask = {0, 0, animatedSprite->frameSize.x, animatedSprite->frameSize.y};

    if (ms >= fps) {
        animatedSprite->currentFrame++;
        sfClock_restart(animatedSprite->clock);
    }
    if (animatedSprite->currentFrame == animatedSprite->maxFrame)
        animatedSprite->currentFrame = 0;
    mask.left = (animatedSprite->currentFrame % animatedSprite->gridSize.x) * animatedSprite->frameSize.x;
    mask.top = (animatedSprite->currentFrame / animatedSprite->gridSize.y) * animatedSprite->frameSize.y;
    sfSprite_setTextureRect(animatedSprite->sprite, mask);
    sfRenderWindow_drawSprite(renderWindow, animatedSprite->sprite, states);
}
