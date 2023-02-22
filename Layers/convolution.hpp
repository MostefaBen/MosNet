#ifndef CONVOLUTION_HPP
#define CONVOLUTION_HPP
#include <Eigen/Core>
#include <vector>
#include <stdexcept>
#include "../Layers.hpp"

typedef double Scalar;

class Convolution : public Layers
{
    public:
        /** constructor and destructor **/
        Convolution();
        virtual ~Convolution();

    protected:

    private:
};

#endif // CONVOLUTION_HPP
