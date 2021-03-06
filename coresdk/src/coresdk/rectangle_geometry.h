//
//  rectangle_geometry.h
//  splashkit
//
//  Created by Jacob Milligan on 19/08/2016.
//  Copyright © 2016 Andrew Cain. All rights reserved.
//

#ifndef rectangle_geometry_H
#define rectangle_geometry_H

#include "types.h"
#include <string>

using namespace std;
namespace splashkit_lib
{
    /**
     * Returns a rectangle from a given x,y location with the specified width
     * and height.
     *
     * @param  x      The x coordinate of the rectangle
     * @param  y      The y coordinate of the rectangle
     * @param  width  The width of the rectangle
     * @param  height The height of the rectangle
     * @return        A rectangle with the specified dimensions and location.
     */
    rectangle rectangle_from(float x, float y, float width, float height);

    /**
     * Returns a rectangle with pt1 and pt2 defining the two distant edge points.
     *
     * @param  pt1 The first point
     * @param  pt2 The second point
     * @return     A rectangle enclosing the two points.
     */
    rectangle rectangle_from(const point_2d pt1, const point_2d pt2);

    /**
     * Returns a rectangle at the specified point with a given width and height
     *
     * @param  pt     The origin for the rectangle
     * @param  width  Its width
     * @param  height Its height
     * @return        A rectangle with the specified dimensions and location
     */
    rectangle rectangle_from(const point_2d pt, const float width, const float height);

    /**
     *  Returns a rectangle that is moved by the provided vector.
     *
     * @param  rect   The original rectangle
     * @param  offset The amount and direction for the rectangle to move
     * @return        A new rectangle that represents the original rectangle
     *                after being moved by the offset vector.
     */
    rectangle rectangle_offset_by(const rectangle &rect, const vector_2d &offset);

    /**
     * Returns the center point of a given rectangle
     *
     * @param  rect The rectangle
     * @return      The center point of the vector
     */
    point_2d rectangle_center(const rectangle &rect);

    /**
     * Returns a rectangle that surrounds a given line segment
     *
     * @param  l The line
     * @return   A rectangle that will surround the line
     */
    rectangle rectangle_around(const line &l);

    /**
     * Returns a rectangle that surrounds a given circle
     *
     * @param  c The circle
     * @return   A rectangle that will surround the circle
     */
    rectangle rectangle_around(const circle &c);

    /**
     * Returns a rectangle that surrounds a given triangle
     *
     * @param  t The triangle
     * @return   A rectangle that will surround the triangle
     */
    rectangle rectangle_around(const triangle &t);

    /**
     * Returns a rectangle that represents the intersection of two rectangles.
     *
     * @param rect1     The first rectangle
     * @param rect2     The second rectangle
     * @returns         The intersection of rect1 and rect2.
     */
    rectangle intersection(const rectangle &rect1, const rectangle &rect2);

    /**
     * Returns true if the two rectangles intersect.
     *
     * @param rect1     The first rectangle
     * @param rect2     The second rectangle
     * @returns         True when rect1 and rect2 intersect.
     */
    bool rectangles_intersect(const rectangle &rect1, const rectangle &rect2);

    /**
     * The top of the rectangle.
     *
     * @param  rect The rectangle.
     * @return      Its distance from the top of the screen.
     */
    float rectangle_top(const rectangle &rect);

    /**
     * The location of the bottom of the rectangle.
     *
     * @param  rect The rectangle.
     * @return      The distance from the top of the screen to the bottom of
     *              the rectangle.
     */
    float rectangle_bottom(const rectangle &rect);

    /**
     * The location of the left edge of the rectangle.
     *
     * @param  rect The rectangle.
     * @return      The distance from the left of the screen to the left side of
     *              the rectangle.
     */
    float rectangle_left(const rectangle &rect);

    /**
     * The location of the right edge of the rectangle.
     *
     * @param  rect The rectangle.
     * @return      The distance from the left of the screen to the right side
     *              of the rectangle.
     */
    float rectangle_right(const rectangle &rect);

    /**
     *  Get a text representation of the passed in rectangle.
     *
     * @param  rect The rectangle
     * @return      A string representation of the rectangle.
     */
    string rectangle_to_string(const rectangle &rect);


}
#endif /* rectangle_geometry_H */
