/**
 * @header Database
 * @author Andrew Cain
 * @brief SplashKit camera functionality allows you to move a virtual camera
 *        around in your world.
 *
 * Splashkit camera functionality allows you to move a virtual camera around in
 * your world. This camera projects to the users window, allowing you to
 * draw things to the screen in your world coordinates.
 *
 * @attribute static camera
 */

#ifndef camera_hpp
#define camera_hpp

#include "geometry.h"
namespace splashkit_lib
{
    /**
     * Returns the x location of the camera in game coordinates. This represents
     * the left most x value shown on the screen, with the right of the screen
     * being at camera x + screen width.
     *
     * @returns The x location of the camera in game coordinates.
     */
    float camera_x();

    /**
     * Returns the y location of the camera in game coordinates. This represents
     * the stop most y value shown on the screen, with bottom of screen being
     * at camera y + screen height.
     *
     * @returns The y location of the camera in game coordinates.
     */
    float camera_y();

    /*
     * Change the X position of the camera to a specified world coordinate. This
     * will then be the new left most position of the screen within the world.
     *
     * @param x The new x coordinate for the camera
     */
    void set_camera_x(float x);

    /**
     * Change the Y position of the camera to a specified world coordinate. This
     * will then be the new top most position of the screen within the world.
     *
     * @param y The new y coordinate for the camera
     */
    void set_camera_y(float y);

    /**
     * Change the position of the camera to a specified world coordinate. This
     * will then be the new top left most position of the screen within the world.
     *
     * @param pos   The new location of the camera.
     */
    void set_camera_position(point_2d pos);

    /**
     * Returns the position of the camera in game coordinates. This will be the
     * coordinate of the upper left corner of the screen.
     *
     * @returns The position of the camera as a point_2d.
     */
    point_2d camera_position();

    /**
     * Returns the center of the screen in world coordinates.
     *
     * @returns The center of the screen in world coordinates.
     */
    point_2d screen_center();

    //---------------------------------------------------------------------------
    // World-To-Screen Translation
    //---------------------------------------------------------------------------

    /**
     * Translate a world x value to the current screen x value which is based on
     * the camera position.
     *
     * @param world_x   The value of the x coordinate to translate to screen.
     * @returns         The x location of the world coordinate on the screen.
     */
    float to_screen_x(float world_x);

    /**
     * Translate a world y value to the current screen y value set by the camera.
     *
     * @param world_y   The value of the y coordinate to translate to screen.
     * @returns         The y location of the world coordinate on the screen.
     */
    float to_screen_y(float world_y);

    /**
     * Convert the passed in world coordinates to screen coordinates.
     *
     * @param pt    The point to convert - this should be in world coordinates.
     * @returns     A point that represents pt in screen coordinates.
     */
    point_2d to_screen(const point_2d &pt);

    /**
     * Convert the rectangle in world coordinates to screen coordinates.
     *
     * @param rect  The rectangle to convert - this should be in world coordinates.
     * @returns     A rectangle that represents rect in screen coordinates.
     */
    rectangle to_screen(const rectangle &rect);

    /**
     * Returns a vector that can transform points from world to screen coordinates.
     *
     * @returns A vector representing the distance and direction points need
     *          to move to map from world to screen coordinates.
     */
    vector_2d vector_world_to_screen();

    /**
     * Returns a rectangle that represents the dimensions of the window.
     *
     * @returns     A rectangle representing the dimensions of the current window.
     */
    rectangle screen_rectangle();

    //---------------------------------------------------------------------------
    // Screen-To-World Translation
    //---------------------------------------------------------------------------

    /**
     * Translate a screen x value (based on the camera) to a world x value
     *
     * @param screen_x   The value of the x coordinate on screen to translate to
     *                   the world.
     * @returns         The x location of the screen coordinate in the world.
     */
    float to_world_x(float screen_x);

    /**
     * Translate a screen y value (based on the camera) to a world y value
     *
     * @param screen_y   The value of the y coordinate on screen to translate to
     *                   the world.
     * @returns         The y location of the screen coordinate in the world.
     */
    float to_world_y(float screen_y);

    /**
     * Converts the passed in point from screen coordinates to world coordinates.
     *
     * @param pt    The point in screen coordinates.
     * @returns     The same point in world coordinates.
     */
    point_2d to_world(const point_2d &pt);


    //---------------------------------------------------------------------------
    // Screen tests
    //---------------------------------------------------------------------------

    /**
     * Tests if the rectangle is on the screen.
     *
     * @param  rect The rectangle to check.
     * @returns     True if any part of the rectangle is on the screen.
     */
    bool rect_on_screen(const rectangle &rect);

    /**
     * Tests if the point is on the screen.
     *
     * @param  pt   The point to check.
     * @returns     True if the point is on the screen.
     */
    bool point_on_screen(const point_2d &pt);


    //---------------------------------------------------------------------------
    // Camera movement
    //---------------------------------------------------------------------------

    /**
     * Move the camera view to a world location specified by the x and y values.
     * This will be the new top left corner of the screen.
     *
     * @param x The new camera x location
     * @param y The new camera y location
     */
    void move_camera_to(float x, float y);

    /**
     * Move the camera view (screen top left) to a specified point in the world.
     * This will be the new top left corner of the screen.
     *
     * @param pt The new camera location
     */
    void move_camera_to(const point_2d &pt);

    /**
     * Move the camera (offset its world x and y values) using the specified
     * dx (change in x) and dy (change in x) values.
     *
     * @param dx The amount to move the camera along the x axis.
     * @param dy The amount to move the camera along the y axis.
     */
    void move_camera_by(float dx, float dy);

    /**
     * Move the camera (offset its world x and y values) using the specified
     * vector. For example, if you move the camera by the same speed vector of
     * a sprite the camera will "track" (be locked on to) the sprite as it moves.
     *
     * @param offset The amount to move the camera.
     */
    void move_camera_by(const vector_2d &offset);

    /**
     * Set the camera view to be centered over the specific sprite. The offset
     * vector allows you to move the sprite from the direct center of the screen.
     *
     * @param s        The sprite to track.
     * @param offset_x An additional offset added to the camera, allowing you to
     *                 position the sprite offset from the center of the screen.
     * @param offset_y An additional offset added to the camera, allowing you to
     *                 position the sprite offset from the center of the screen.
     */
    void center_camera_on(sprite s, float offset_x, float offset_y);
    
    /**
     * Set the camera view to be centered over the specific sprite. The offset
     * vector allows you to move the sprite from the direct center of the screen.
     *
     * @param s        The sprite to track.
     * @param offset   The amount to offset the camera, allowing you to position
     *                 the sprite away from the center of the screen.
     */
    void center_camera_on(sprite s, const vector_2d &offset);
    
#endif /* camera_hpp */
}