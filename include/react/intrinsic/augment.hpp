/*!
 * @file
 * This file defines the `react::augment` intrinsic.
 */

#ifndef REACT_INTRINSIC_AUGMENT_HPP
#define REACT_INTRINSIC_AUGMENT_HPP

#include <react/detail/auto_return.hpp>
#include <react/tag_of.hpp>

#include <utility>


namespace react {
namespace extension {
    template <typename Tag, typename Enable = void>
    struct augment_impl {
        template <typename Env, typename ...Computations,
                  bool always_false = false>
        static void call(Env&&, Computations&& ...) {
            static_assert(always_false,
            "There is no default implementation for "
            "`react::augment(Environment, Computations...)`.");
        }
    };
} // end namespace extension

static constexpr struct {
    template <typename Env, typename ...Computations>
    auto operator()(Env&& env, Computations&& ...c) const
    REACT_AUTO_RETURN(
        extension::augment_impl<
            typename tag_of<Env>::type
        >::call(std::forward<Env>(env), std::forward<Computations>(c)...)
    )
} augment{};
} // end namespace react

#endif // !REACT_INTRINSIC_AUGMENT_HPP