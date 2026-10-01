#ifndef COORDINATE_HPP
#define COORDINATE_HPP

#include <utility>
/// @brief Abstract/Interface coordinate class.
/// Coordinates especially in a discrete computing context are meant to define 
/// all the discrete possible values a state space can take.  For 2D cartesian this would be
/// the smallest possible seperation between X and Y values in a discrete implementation
/// for 2D polar this would be smallest angle and radial seperation required to define two points as different.
/// All spaces must meet this uniqueness description.
class Coordinate
{
public:

    Coordinate() = default; 
    Coordinate(const Coordinate& c) = default; 

    Coordinate(double x, double y)
    {
        x_ = x;
        y_ = y;
    }
    
    virtual ~Coordinate()
    {

    }

    /// @brief get your coordinate as two values that span your entire space.
    /// X,Y coordinate or angle,radius coordinates are most typical.  Others exist.
    std::pair<double, double> Get2DPoint()
    {
        return std::pair<double, double>(x_,y_);
    }

    /// @brief Convert your coordinates point into a unique single number ID.
    /// @return a single number that can be used.
    long GetUniqueId()
    {

        return x_ + y_; // This will span any positive space but doesnt work for negative numbers combined with positive numbers.
    }

    double x_ = 0.0;
    double y_ = 0.0;
};

#endif