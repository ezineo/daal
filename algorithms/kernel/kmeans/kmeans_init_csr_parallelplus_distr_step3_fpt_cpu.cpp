/* file: kmeans_init_csr_parallelplus_distr_step3_fpt_cpu.cpp */
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
//  Implementation of Lloyd method for K-means algorithm
//--
*/

#include "kmeans_init_kernel.h"
#include "kmeans_init_container.h"
#include "kmeans_plusplus_init_distr_impl.i"

namespace daal
{
namespace algorithms
{
namespace kmeans
{
namespace init
{
namespace interface1
{
template class DistributedContainer<step3Master, DAAL_FPTYPE, parallelPlusCSR, DAAL_CPU>;
}
namespace internal
{
template class KMeansinitStep3MasterKernel<parallelPlusCSR, DAAL_FPTYPE, DAAL_CPU>;
} // namespace daal::algorithms::kmeans::init::internal
} // namespace daal::algorithms::kmeans::init
} // namespace daal::algorithms::kmeans
} // namespace daal::algorithms
} // namespace daal