/* file: spatial_pooling2d_layer_forward_fpt.cpp */
/*******************************************************************************
* Copyright 2014-2017 Intel Corporation
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*******************************************************************************/

/*
//++
//  Implementation of spatial pooling2d calculation algorithm and types methods.
//--
*/

#include "spatial_pooling2d_layer_types.h"
#include "spatial_pooling2d_layer_forward_types.h"

namespace daal
{
namespace algorithms
{
namespace neural_networks
{
namespace layers
{
namespace spatial_pooling2d
{
namespace forward
{
namespace interface1
{
/**
* Allocates memory to store input objects of forward 2D pooling layer
* \param[in] parameter %Parameter of forward 2D pooling layer
* \param[in] method    Computation method for the layer
*/
template <typename algorithmFPType>
DAAL_EXPORT void Input::allocate(const daal::algorithms::Parameter *parameter, const int method) {}

/**
* Allocates memory to store the result of the forward 2D pooling layer
* \param[in] input Pointer to an object containing the input data
* \param[in] method Computation method for the layer
* \param[in] parameter %Parameter of the forward 2D pooling layer
*/
template <typename algorithmFPType>
DAAL_EXPORT void Result::allocate(const daal::algorithms::Input *input, const daal::algorithms::Parameter *parameter, const int method)
{
    const Input *in = static_cast<const Input *>(input);
    const Parameter *algParameter = static_cast<const Parameter *>(parameter);

    services::Collection<size_t> valueDims = getValueSize(in->get(layers::forward::data)->getDimensions(), algParameter, method);
    if (!get(layers::forward::value))
    {
        set(layers::forward::value, data_management::TensorPtr(
                new data_management::HomogenTensor<algorithmFPType>(valueDims, data_management::Tensor::doAllocate)));
    }
    if(!algParameter->predictionStage)
    {
        if (!get(layers::forward::resultForBackward))
        {
            set(layers::forward::resultForBackward, services::SharedPtr<LayerData>(new LayerData()));
        }
    }
}

template DAAL_EXPORT void Input::allocate<DAAL_FPTYPE>(const daal::algorithms::Parameter *parameter, const int method);
template DAAL_EXPORT void Result::allocate<DAAL_FPTYPE>(const daal::algorithms::Input *input, const daal::algorithms::Parameter *parameter, const int method);

}// namespace interface1
}// namespace forward
}// namespace spatial_pooling2d
}// namespace layers
}// namespace neural_networks
}// namespace algorithms
}// namespace daal
