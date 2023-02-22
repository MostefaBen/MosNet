#ifndef LAYERS_HPP
#define LAYERS_HPP
#include <Eigen/Core>
#include <vector>

typedef double Scalar;

class Layers
{
    public:
        /*** constructor and destructor ***/
        Layers() (const int input_size, const int output_size): tensor_input_size(input_size), tensor_output_size(output_size) {}
        virtual ~Layers();
        /*** initialization ***/
	    virtual void initialization(const Scalar& mu, const Scalar &sigma, RNG& rng) = 0;
	    /*** forward and backward ***/
        virtual void forward(const Matrix& prev_layer_output) = 0;
        virtual void backward(const Matrix& pre_layer_output, const Matrix& next_layer_data) = 0;
        virtual const Matrix& output() const = 0;
        virtual const Matrix& backward_data()const = 0;
        /*** getter and setter ***/
        int get_input_size() const { return tensor_input_size; }
	    int get_output_size() const { return tensor_output_size; }
        virtual std::vector<Scalar> get_parameter() const = 0;
        virtual void set_parameters(const std::vector<Scalar>& param) {}
        virtual std::vector<Scalar> get_derivatives() const = 0;

    protected:
        typedef Eigen::Matrix<Scalar, Eigen::Dynamic, Eigen::Dynamic> Matrix;
        typedef Eigen::Matrix < Scalar, Eigen::Dynamic, 1> Vector;
        const int tensor_input_size;
        const int tensor_output_size;
};

#endif // LAYERS_HPP
