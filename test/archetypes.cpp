/*!
 * @file
 * This file contains compile-time unit tests for the concept archetypes.
 */

#include <react/archetypes.hpp>
#include <react/concepts.hpp>

#include <boost/concept/assert.hpp>


using namespace react;

BOOST_CONCEPT_ASSERT((Computation<
    computation_archetype<>,
    dependencies_results<>
>));

BOOST_CONCEPT_ASSERT((ComputationName<
    computation_name_archetype<>
>));

BOOST_CONCEPT_ASSERT((Environment<
    environment_archetype<>,
    available_names<>
>));


int main() { }
