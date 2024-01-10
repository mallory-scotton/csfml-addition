# 🎬 Animated Sprites

### Structures

`sfAnimatedSprite` is here to make working with animated sprite easier and automated.

```c
typedef struct
{
    sfSprite *sprite;       //<-Sprite object
    sfTexture *texture;     //<-Texture object
    sfClock *clock;         //<-Animation clock
    size_t currentFrame;    //<-Current frame index
    size_t maxFrame;        //<-Max frame count
    sfVector2u frameSize;   //<-Frame size (width, height)
    sfVector2u gridSize;    //<-Grid size (x, y)
    size_t frameRate;       //<-Frame rate, in frame per sec
} sfAnimatedSprite;
```

### Functions

- `sfAnimatedSprite_create`:
  - _Create a new animated sprite_
- `sfAnimatedSprite_createFromFile`:
  - _Create a new animated sprite from a file_
- `sfAnimatedSprite_destroy`:
  - _Destroy an existing animated sprite_
- `sfAnimatedSprite_setPosition`:
  - _Set the position of an animated sprite_
    - This function completely overwrites the previous position. See `sfAnimatedSprite_move` to apply an offset based on the previous position instead. The default position of a animated sprite object is (0, 0).
- `sfAnimatedSprite_setRotation`:
  - _Set the orientation of an animated sprite_
    - This function completely overwrites the previous rotation. See `sfAnimatedSprite_rotate` to add an angle based on the previous rotation instead. The default rotation of a animated sprite object is 0.
- `sfAnimatedSprite_setScale`:
  - _Set the scale factors of an animated sprite_
    - This function completely overwrites the previous scale. See `sfAnimatedSprite_scale` to add a factor based on the previous scale instead.
- `sfAnimatedSprite_setOrigin`:
  - _Set the local origin of an animated sprite_
    - The origin of an object defines the center point for all transformations (position, scale, rotation). The coordinates of this point must be relative to the top-left corner of the object, and ignore all transformations (position, scale, rotation). The default origin of a animated sprite object is (0, 0).
- `sfAnimatedSprite_getPosition`:
  - _Get the position of an animated sprite_
- `sfAnimatedSprite_getRotation`:
  - _Get the orientation of an animated sprite_
- `sfAnimatedSprite_getScale`:
  - _Get the current scale of an animated sprite_
- `sfAnimatedSprite_getOrigin`:
  - _Get the local origin of an animated sprite_
- `sfAnimatedSprite_move`:
  - _Move an animated sprite by a given offset_
- `sfAnimatedSprite_rotate`:
  - _Rotate an animated sprite_
- `sfAnimatedSprite_scale`:
  - _Scale an animated sprite_
- `sfAnimatedSprite_getTransform`:
  - _Get the combined transform of an animated sprite_
- `sfAnimatedSprite_getInverseTransform`:
  - _Get the inverse of the combined transform of an animated sprite_
- `sfAnimatedSprite_setTexture`:
  - _Change the source texture of an animated sprite_
    - The texture argument refers to a texture that must exist as long as the sprite uses it. Indeed, the sprite doesn't store its own copy of the texture, but rather keeps a pointer to the one that you passed to this function. If the source texture is destroyed and the sprite tries to use it, the behaviour is undefined. If resetRect is true, the TextureRect property of the sprite is automatically adjusted to the size of the new texture. If it is false, the texture rect is left unchanged.
- `sfAnimatedSprite_setColor`:
  - _Set the global color of an animated sprite_
    - This color is modulated (multiplied) with the sprite's texture. It can be used to colorize the animated sprite, or change its global opacity. By default, the animated sprite's color is opaque white.
- `sfAnimatedSprite_getTexture`:
  - _Get the source texture of an animated sprite_
    - If the sprite has no source texture, a NULL pointer is returned. The returned pointer is const, which means that you can't modify the texture when you retreive it with this function.
- `sfAnimatedSprite_getColor`:
  - _Get the global color of an animated sprite_
- `sfAnimatedSprite_getLocalBounds`:
  - _Get the local bounding rectangle of an animated sprite_
    - The returned rectangle is in local coordinates, which means that it ignores the transformations (translation, rotation, scale, ...) that are applied to the entity. In other words, this function returns the bounds of the entity in the entity's coordinate system.
- `sfAnimatedSprite_getGlobalBounds`:
  - _Get the global bouding rectangle of an animated sprite_
    - The returned rectangle is in global coordinates, which means that it takes in account the transformations (translation, rotation, scale, ...) that are applied to the entity. In other words, this function returns the bounds of the animated sprite in the global 2D world's coodinate system.
- `sfAnimatedSprite_setFrameRate`:
  - _Set the frame rate of the animation of an animated sprite_
- `sfAnimatedSprite_getFrameRate`:
  - _Get the frame rate of an animated sprite_
- `sfAnimatedSprite_setFrameSize`:
  - _Set the frame size of an animated sprite_
- `sfAnimatedSprite_getFrameSize`:
  - _Get the frame size of an animated sprite_
- `sfAnimatedSprite_setGridSize`:
  - _Set the grid size of an animated sprite_
- `sfAnimatedSprite_getGridSize`:
  - _Get the grid size of an animated sprite_
    - The grid size represents how many frames there is in x, and how many there is in y.
- `sfRenderWindow_drawAnimatedSprite`:
  - _Draw a drawable object to the render-target_

### Exemple

This exemple will create a 1920x1080 pixels windows, that displays a 10 frame at the speed of 3 frames per seconds.

Once the game loop complete, we clear the used assets.

```c
int main(void)
{
    // Definition of the variables
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow *window;
    sfAnimatedSprite *asprite;
    sfEvent event;

    // Creating the window
    window = sfRenderWindow_create(mode, "CSFML Addition", sfClose, NULL);
    if (!window)
        return (1);

    // Creating the animated sprite:
    asprite = sfAnimatedSprite_createFromFile("my_animation.png");
    if (!asprite)
        return (1);

    /**
     * Here, we set the grid to be a 10 x 1
     * animation sprite sheet.
     */
    sfAnimatedSprite_setGridSize(asprite, (sfVector2i){10, 1});

    // A frame will be 200x200 pixel
    sfAnimatedSprite_setFrameSize(asprite, (sfVector2i){200, 200});

    // Setting the max frame to avoid leaving the texture
    sfAnimatedSprite_setMaxFrame(asprite, 10);

    // Set the frame rate in frame per seconds
    // Here, 3 frames will be drawn each seconds.
    sfAnimatedSprite_setFrameRate(asprite, 3);

    // Game loop
    while (sfRenderWindow_isOpen(window)) {
        // Listening the events
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }

        // Clear the screen
        sfRenderWindow_clear(window, sfBlack);

        // Draw the animated sprite
        sfRenderWindow_drawAnimatedSprite(window, asprite, NULL);

        // Display
        sfRenderWindow_display(window);
    }

    // Game loop is complete
    // clear the assets
    sfAnimatedSprite_destroy(asprite);
    sfRenderWindow_destroy(window);

    // Leaving the process
    return (0);
}
```