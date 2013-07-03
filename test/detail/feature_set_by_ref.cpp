/*!
 * @file
 * This file defines unit tests for `react::detail::feature_set_by_ref`.
 */

#include <react/detail/feature_set_by_ref.hpp>
#include <react/archetypes.hpp>
#include <react/concepts.hpp>

#include <boost/concept/assert.hpp>
#include <boost/concept_archetype.hpp>


using namespace react;

struct default_constructible
    : detail::feature_set_by_ref<feature_set_archetype<>>
{
    default_constructible();
};

BOOST_CONCEPT_ASSERT((FeatureSet<
    default_constructible,
    default_construct,
    semantic_tags<boost::null_archetype<>>,
    dependency_results<>
>));


int main() { }