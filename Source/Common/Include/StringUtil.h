//
// Copyright (c) Microsoft. All rights reserved.
// Licensed under the MIT license. See LICENSE.md file in the project root for full license information.
//

#pragma once

#include <string>

namespace Microsoft { namespace MSR { namespace CNTK {

// Compares two ASCII strings ignoring the case.
// TODO: Should switch to boost, boost::iequal should be used instead.
template<class TElement>
inline bool AreEqualIgnoreCase(
    const std::basic_string<TElement, char_traits<TElement>, allocator<TElement>>& s1,
    const std::basic_string<TElement, char_traits<TElement>, allocator<TElement> >& s2)
{
    return std::equal(s1.begin(), s1.end(), s2.begin(), [](const TElement& a, const TElement& b)
    {
        return std::tolower(a) == std::tolower(b);
    });
}

template<class TElement>
inline bool AreEqualIgnoreCase(
    const std::basic_string<TElement, char_traits<TElement>, allocator<TElement>>& s1,
    const TElement* s2pointer)
{
    std::basic_string<TElement, char_traits<TElement>, allocator<TElement>> s2(s2pointer);
    return AreEqualIgnoreCase(s1, s2);
}

template<class TElement>
inline bool AreEqualIgnoreCase(
    const TElement* s1pointer,
    const std::basic_string<TElement, char_traits<TElement>, allocator<TElement>>& s2)
{
    std::basic_string<TElement, char_traits<TElement>, allocator<TElement>> s1(s1pointer);
    return AreEqualIgnoreCase(s1, s2);
}

}}}
