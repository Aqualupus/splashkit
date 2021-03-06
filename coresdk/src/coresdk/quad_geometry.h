//
//  quad_geometry.hpp
//  splashkit
//
//  Created by Andrew Cain on 23/08/2016.
//  Copyright © 2016 Andrew Cain. All rights reserved.
//

#ifndef quad_geometry_h
#define quad_geometry_h

#include "types.h"
#include "matrix_2d.h"

#include <vector>
using std::vector;

namespace splashkit_lib
{
    /**
     * Returns a quad for the passed in x & y points.
     *
     * @param  x_top_left     X coordinate of the top left of the quad
     * @param  y_top_left     Y coordinate of the top left of the quad
     * @param  x_top_right    X coordinate of the top right of the quad
     * @param  y_top_right    Y coordinate of the top right of the quad
     * @param  x_bottom_left  X coordinate of the bottom left of the quad
     * @param  y_bottom_left  Y coordinate of the bottom left of the quad
     * @param  x_bottom_right X coordinate of the bottom right of the quad
     * @param  y_bottom_right Y coordinate of the bottom right of the quad
     * @return                A quad with the indicated points
     */
    quad quad_from(
      float x_top_left, float y_top_left,
      float x_top_right, float y_top_right,
      float x_bottom_left, float y_bottom_left,
      float x_bottom_right, float y_bottom_right );

    /**
     * Returns a quad from the x-y points of a given recatangle
     *
     * @param  rect The rectangle to convert to a quad
     * @return      A quad at the same location as the rectangle
     */
    quad quad_from(const rectangle &rect);

    /**
     * Returns a quad from the rectangle, then applies the transformation to
     * the quads points.
     *
     * @param rect          The rectangle to transform to a quad.
     * @param transform     A transform to apply to the resulting quad.
     * @returns             A quad that represents the rectangle after the transformation.
     */
    quad quad_from(const rectangle &rect, const matrix_2d &transform);

    /**
     * Returns a quad from the passed in points.
     *
     * @param  p1 The top left of the quad.
     * @param  p2 The top right of the quad
     * @param  p3 The bottom left of the quad
     * @param  p4 The bottom right of the quad
     * @return    A quad from the passed in points
     */
    quad quad_from(const point_2d &p1,
                   const point_2d &p2,
                   const point_2d &p3,
                   const point_2d &p4);

    /**
     * Change a point in a quad.
     *
     * @param q     The quad to change
     * @param idx   The index of the point: 0 is top left, 1 is top right, 2 is
     *              bottom left, and 3 is bottom right
     * @param value The new value for that point in the quad
     */
    void set_quad_point(quad &q, int idx, const point_2d &value);

    /**
     * Returns true if two quads intersect.
     *
     * @param  q1 The first quad
     * @param  q2 The second quad
     * @return    True if the two quads intersect.
     */
    bool quads_intersect(const quad &q1, const quad &q2);

    /**
     * Returns the two triangles that make up a quad in a vector.
     *
     * @param q The quad
     * @return  A vector with the two triangles from the quad.
     */
    vector<triangle> triangles_from(const quad &q);

}
#endif /* quad_geometry_h */
