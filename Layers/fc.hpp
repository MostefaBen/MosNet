#ifndef FC_HPP
#define FC_HPP
#include <Eigen/Core>
#include <vector>
#include <stdexcept>
#include "../layers.hpp"

typedef double Scalar;

template<typename Activation>

class FC : public Layers
{
    public:
        /** constructor and destructor **/
        FC(const int input_size,const int output_size);
        virtual ~FC();
        /*** initialization ***/
        void initialization(const Scalar& mu, const Scalar& sigma, RNG& rng);
        /*** forward and backward ***/
        void forward(const Matrix& prev_layer_data);
        void backward(const Matrix& prev_layer_data, const Matrix& next_layer_data);
        void update_parameters(Optimizer& opt);
        /*** getter and setter ***/
        const Matrix& backward_data() const;
        const Matrix& output() const;
        std::vector<Scalar> get_parameters() const;
        void set_parameters(const std::vector<Scalar>& param);
        std::vector<Scalar> get_derivatives() const;


    private:
        typedef Eigen::Matrix<Scalar, Eigen::Dynamic, Eigen::Dynamic> Matrix;
        typedef Eigen::Matrix<Scalar, Eigen::Dynamic, 1> Vector;
        Matrix tensor_weight;  // weights
        Vector tensor_bias;    // bias
        Matrix tensor_dw;      // derivative of the weights
        Vector tensor_db;      // derivative of the bias
        Matrix tensor_z;       // z = w*x + b
        Matrix tensor_a;       // a = function(z)
        Matrix tensor_din;     //  derivative of the input
};

#endif // FC_HPP
