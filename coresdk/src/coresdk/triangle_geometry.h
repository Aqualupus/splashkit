//
//  triangle_geometry.hpp
//  splashkit
//
//  Created by Andrew Cain on 23/08/2016.
//  Copyright © 2016 Andrew Cain. All rights reserved.
//

#ifndef triangle_geometry_h
#define triangle_geometry_h

#include "types.h"

namespace splashkit_lib
{
    /**
     * Generate a triangle from a set of points.
     *
     * @param  x1 The x coordinate for the first point
     * @param  y1 The y coordinate for the first point
     * @param  x2 The x coordinate for the second point
     * @param  y2 The y coordinate for the second point
     * @param  x3 The x coordinate for the third point
     * @param  y3 The y coordinate for the third point
     * @return    A triangle at the indicated points
     *
     * @attribute suffix  _from_coordinates
     */
    triangle triangle_from(float x1, float y1, float x2, float y2, float x3, float y3);

    /**
     * Generate a triangle from a set of points.
     *
     * @param  p1 The first point of the triangle
     * @param  p2 The second point of the triangle
     * @param  p3 The third point of the triangle
     * @return    A triangle with the indicated points
     */
    triangle triangle_from(const point_2d &p1, const point_2d &p2, const point_2d &p3);

    /**
     * Returns true if the triangle intersects with the rectangle.
     *
     * @param  tri  The triangle to test
     * @param  rect The rectangle to test
     * @return      True if the triangle and rect intersect
     */
    bool triangle_rectangle_intersect(const triangle &tri, const rectangle &rect);

    /**
     * Returns true if the two triangles intersect.
     *
     * @param  t1 The first triangle
     * @param  t2 The other triangle
     * @return    True if the two triangles intersect
     */
    bool triangles_intersect(const triangle &t1, const triangle &t2);
}

#endif /* triangle_geometry_h */
