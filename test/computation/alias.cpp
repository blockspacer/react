/*!
 * @file
 * Contains unit tests for `react::computation::alias`.
 */

#include <react/computation/alias.hpp>

#include <react/archetypes.hpp>
#include <react/concept/assert.hpp>
#include <react/concept/computation.hpp>

#include <boost/concept_archetype.hpp>


using namespace react;

REACT_CONCEPT_ASSERT(Computation<
    computation::alias<feature_archetype<>>,
    fake_result_of<
        feature_archetype<>
    >::with<
        boost::copy_constructible_archetype<>
    >
>);


int main() { }
