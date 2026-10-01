#ifndef NEURON_HPP
#define NEURON_HPP
#include <vector>
#include <coordinate.hpp>
#include <ncurses.h>
typedef float neuron_value;

class Neuron
{
public:
    Neuron(Coordinate c);
    virtual ~Neuron();
    bool PushNeighbor(Neuron* n);
    bool InsertNeighbor(Neuron* n, int i);
    void ResizeNeighborsVec(int s);

    /// @brief Perceive based on neighbors.
    /// You must call reset before calling this again.
    void Perceive();

    /// @brief Reset updated flag so next generation can update.
    void Reset();

    neuron_value GetValue();

    void draw_neuron();
protected:
    /// @brief  neighbors of this neuron. 
    /// neighbors are typically local structures
    /// where one neuron effects its neighnors in a local
    /// space.
    ///
    /// Can be as simple as a - b - c
    ///
    /// or 2d grid
    /// a - b - c
    /// |   |   | 
    /// d - e - f
    /// Or even more complicated as:
    /// 
    ///       b
    ///    c  |  f
    ///     \ | /
    ///    d--a--e
    ///     / | \ 
    ///    h  g  i
    std::vector<Neuron*> neigbors_;

    /// @brief Has this neuron been updated in this iteration (generation)
    bool updated_ = false;

    /// @brief How many generations has this neuron fired for.
    unsigned long numGenerationsComputed_ = 0;

    /// @brief Is this neuron dead.
    bool dead_ = false;

    neuron_value value_ = 0.0f;

    Coordinate c_;

    Coordinate dispCoord_;

};
#endif