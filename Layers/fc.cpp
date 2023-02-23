#include "fc.hpp"

FC::FC(const int input_size,const int output_size): Layers(input_size, output_size)
{
    //ctor
}

FC::~FC()
{
    //dtor
}


void initialization(const Scalar& mu, const Scalar& sigma, RNG& rng) {

		tensor_weight.resize(this->tensor_input_size, this->tensor_output_size);
		tensor_bias.resize(this->tensor_output_size);
		tensor_dw.resize(this->tensor_input_size, this->tensor_output_size);
		tensor_db.resize(this->tensor_output_size);

		internal::set_normal_random(tensor_weight.data(), tensor_weight.size(), rng, mu, sigma);
		internal::set_normal_random(tensor_bias.data(), tensor_bias.size(), rng, mu, sigma);
}


void forward(const Matrix& prev_layer_data) {

		const int nobs = prev_layer_data.col();

		// z = w' * x + b
		tensor_z.resize(this->tensor_output_size, nobs);
		tensor_z.noalias() = tensor_weight.transpose()*prev_layer_data;
		tensor_z.colwise() += tensor_bias;

		// Apply activation function
		tensor_a.resize(this->tensor_output_size, nobs);
		Activation::activate(tensor_z, tensor_a);
}

const Matrix& output() const
{
		return tensor_a;
}

void backward(const Matrix& prev_layer_data, const Matrix& next_layer_data)
{
		// TODO
}

const Matrix& backward_data() const
{
		return tensor_din;
}

void update_parameters(Optimizer& opt)
{

		ConstAlignedMapVec dw(m_dw.data(), m_dw.size());
		ConstAlignedMapVec db(m_db.data(), m_db.size());
		AlignedMapVec w(m_weight.data(), m_weight.size());
		AlignedMapVec b(m_bias.data(), m_bias.size());

		opt.update(dw, w);
		opt.update(db, b);
}

std::vector<Scalar> get_parameters() const
{
    //TODO
}

void set_parameters(const std::vector<Scalar>& param)
{
    //TODO
}

std::vector<Scalar> get_derivatives() const
{
    //TODO
}
