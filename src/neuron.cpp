#include "neuron.hpp"
#include <string>
#include <random> // Required for random engines and distributions

Neuron::Neuron(Coordinate c)
{
    c_ = c;
    double lower_bound = 0.0;
    double upper_bound = 1.0;

    // 1. Obtain a random seed from the hardware
    std::random_device rd;

    // 2. Initialize the standard Mersenne Twister engine with the seed
    std::mt19937 gen(rd());

    // 3. Define a uniform real distribution mapping to the desired range
    std::uniform_real_distribution<double> dis(lower_bound, upper_bound);

    // 4. Generate the random double
    double random_double = dis(gen);
    value_ = random_double;
    // dispCoord_.x_ = (c_.x_*10);
    // dispCoord_.y_ = (c_.y_*2);
}

Neuron::~Neuron()
{
}

bool Neuron::PushNeighbor(Neuron* n)
{
    neigbors_.push_back(n);
    return true;
}

bool Neuron::InsertNeighbor(Neuron* n, int i)
{
    if(i < neigbors_.size())
    {
        neigbors_[i] = n;
        return true;
    }

    return false;
}

void Neuron::ResizeNeighborsVec(int s)
{
    neigbors_.resize(s);
}

void Neuron::Perceive()
{
    // if we havent been updated yet.
    // must call reset before calling perceive again.
    if(!updated_)
    {
        updated_ = true;
        neuron_value cumTrapz = 0.0f;
        

        for(Neuron* n : neigbors_)
        {
            // Convolve.
            neuron_value nv = n->GetValue();
            cumTrapz += value_* nv;
        }
        if(cumTrapz > 1.0)
        {
            value_ = (cumTrapz / neigbors_.size());
        }
        else
        {
             value_ = (cumTrapz);
        }

    }
}

void Neuron::Reset()
{
    updated_ = false;
}

neuron_value Neuron::GetValue()
{
    return value_;
}

void Neuron::draw_neuron()
{

    // Variables to store dimensions
    int height, width;

    // Get the maximum rows (height) and columns (width) of the standard screen
    getmaxyx(stdscr, height, width);
    

    std::string disp = std::to_string(value_);
    disp += " | ";
    mvprintw(c_.y_, c_.x_*(disp.size()), disp.c_str());
    //mvprintw(10, 20, std::to_string(width).c_str());
    mvaddch(value_*height, c_.x_+60, '#');              // Top side
}
