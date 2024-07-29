//
// Created by Rob Patterson on 7/28/24.
//

#ifndef UTILITY_HPP
#define UTILITY_HPP

namespace utility {
    // Get subrange of container sequentially until predicate fails
    template<typename Container, typename Lambda>
    Container range_by_predicate(typename Container::iterator& iter, Lambda&& pred) {
        Container buf{};

        auto x = *iter;
        while (x && pred(x)) {
            buf.push_back(x);
            x = *(++iter);
        }

        return buf;
    }
}

#endif //UTILITY_HPP
