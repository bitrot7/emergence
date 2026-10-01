#include "space.hpp"

Space::Space()
{
}

Space::~Space()
{
}

void Space::Generate(int dimS)
{
    
    // Generate rows.
    world_.resize(dimS);

    // Loop through rows.
    for(std::vector<Neuron*>& row : world_ )
    {
        // generate columns.
        row.resize(dimS);
    }

    // Loop through rows and columns and generate the neurons.
    int r = 0;

    for(std::vector<Neuron*>& row : world_ )
    {
        int c = 0;
        for(int x = 0; x < row.size(); x++)
        {
            row[x] = new Neuron(CartCoordinate(r,c));
            c++;
            //c+=10;
        }
        r++;
        //r +=2;
    }

}

void Space::DrawSpace()
{
    for(std::vector<Neuron*>& row : world_ )
    {
        for(Neuron* nCol : row)
        {
            nCol->draw_neuron();
        }
    }
}

void Space::Compute()
{

    for(std::vector<Neuron*>& row : world_ )
    {
        for(Neuron* nCol : row)
        {
            nCol->Reset();
        }

    }

    for(std::vector<Neuron*>& row : world_ )
    {
        for(Neuron* nCol : row)
        {
            nCol->Perceive();
        }
    }
}

void Space::ConnectSpace()
{
    int r = 0;
    for(std::vector<Neuron*>& row : world_ )
    {
        for(int c = 0; c < row.size(); c++)
        {
            if(c > 0)
            {
                row[c]->PushNeighbor(row[c-1]);
            }
            
            if(c < row.size()-1)
            {
                row[c]->PushNeighbor(row[c+1]);
            }

            if(r > 0)
            {
                world_[r][c]->PushNeighbor(world_[r-1][c]);
            }

            if(r < world_.size()-1)
            {
                world_[r][c]->PushNeighbor(world_[r+1][c]);
            }
        }
        r++;
    }
}
