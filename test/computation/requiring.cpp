/*!
 * @file
 * Contains unit tests for `react::computation::requiring`.
 */

#include <react/computation/requiring.hpp>

#include <react/archetypes.hpp>
#include <react/concept/assert.hpp>
#include <react/concept/computation.hpp>

#include <boost/concept_archetype.hpp>


using namespace react;

template <int>
struct requirement : feature_archetype<> { };

template <typename ...Requirements>
using test = Computation<
    computation::requiring<Requirements...>,
    typename fake_result_of<
        Requirements
    >::template with<
        boost::copy_constructible_archetype<>
    >...
>;

REACT_CONCEPT_ASSERT(test<>);
REACT_CONCEPT_ASSERT(test<requirement<1>>);
REACT_CONCEPT_ASSERT(test<requirement<1>, requirement<2>>);


int main() { }
