//
// Created by Rob Patterson on 7/28/24.
//

#ifndef UTILITY_HPP
#define UTILITY_HPP

namespace utility {
    // Get subrange of container sequentially until predicate fails
    // (!!!) Changes iterator ptr in place (!!!) don't expect const
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

namespace utility::debug {
    template<typename T>
    concept Exception = std::is_base_of_v<std::exception, T>;

}

#endif //UTILITY_HPP
