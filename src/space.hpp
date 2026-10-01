#ifndef SPACE_HPP
#define SPACE_HPP

#include <vector>
#include <neuron.hpp>
#include <cart_coordinate.hpp>

/// @brief The space of all things.
class Space
{
public:
    Space();
    virtual ~Space();

    // Generate the square space.
    void Generate(int dimS);

    void DrawSpace();

    void Compute();

    void ConnectSpace();

protected:
    /// @brief Currently space is a 2d rect grid.
    /// It should be able to be any discrete surface or shape.
    std::vector<std::vector<Neuron*>> world_;
};
#endif