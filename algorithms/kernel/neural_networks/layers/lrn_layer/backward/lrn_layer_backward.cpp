/* file: lrn_layer_backward.cpp */
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
//  Implementation of lrn calculation algorithm and types methods.
//--
*/

#include "lrn_layer_backward_types.h"
#include "lrn_layer_types.h"
#include "serialization_utils.h"

namespace daal
{
namespace algorithms
{
namespace neural_networks
{
namespace layers
{
namespace lrn
{
namespace backward
{
namespace interface1
{
__DAAL_REGISTER_SERIALIZATION_CLASS(Result, SERIALIZATION_NEURAL_NETWORKS_LAYERS_LRN_BACKWARD_RESULT_ID);
/** Default constructor */
Input::Input() {};

/**
 * Returns an input object for the backward local response normalization layer
 * \param[in] id    Identifier of the input object
 * \return          %Input object that corresponds to the given identifier
 */
services::SharedPtr<data_management::Tensor> Input::get(LayerDataId id) const
{
    services::SharedPtr<layers::LayerData> layerData =
        services::staticPointerCast<layers::LayerData, data_management::SerializationIface>(Argument::get(layers::backward::inputFromForward));
    return services::staticPointerCast<data_management::Tensor, data_management::SerializationIface>((*layerData)[id]);
}

/**
 * Sets an input object for the backward local response normalization layer
 * \param[in] id      Identifier of the input object
 * \param[in] value   Pointer to the object
 */
void Input::set(LayerDataId id, const services::SharedPtr<data_management::Tensor> &value)
{
    services::SharedPtr<layers::LayerData> layerData =
        services::staticPointerCast<layers::LayerData, data_management::SerializationIface>(Argument::get(layers::backward::inputFromForward));
    (*layerData)[id] = value;
}

/**
 * Checks an input object for the backward local response normalization layer
 * \param[in] par     Algorithm parameter
 * \param[in] method  Computation method
 */
void Input::check(const daal::algorithms::Parameter *par, int method) const
{
    const layers::Parameter *param = static_cast<const Parameter *>(par);
    if (!param->propagateGradient) { return; }
    layers::backward::Input::check(par, method);
    if(this->_errors->size() != 0) {return;}

    services::SharedPtr<data_management::Tensor> inputGradientTensor = get(layers::backward::inputGradient);
    if (!data_management::checkTensor(inputGradientTensor.get(), this->_errors.get(), inputGradientStr())) { return; }

    const services::Collection<size_t> &dataDims = inputGradientTensor->getDimensions();
    if (!data_management::checkTensor(get(auxData).get(),   this->_errors.get(), auxDataStr(), &dataDims)) { return; }
    if (!data_management::checkTensor(get(auxSmBeta).get(), this->_errors.get(), auxSmBetaStr(), &dataDims)) { return; }
}

    /** Default constructor */
Result::Result() : layers::backward::Result() {}

/**
 * Checks the result of the backward local response normalization layer
 * \param[in] input   %Input object for the layer
 * \param[in] par     %Parameter of the layer
 * \param[in] method  Computation method
 */
void Result::check(const daal::algorithms::Input *input, const daal::algorithms::Parameter *par, int method) const
{
    const layers::Parameter *param = static_cast<const Parameter *>(par);
    if (!param->propagateGradient) { return; }
}

}// namespace interface1
}// namespace backward
}// namespace lrn
}// namespace layers
}// namespace neural_networks
}// namespace algorithms
}// namespace daal
