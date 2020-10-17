#include <type_traits>

template <typename T, typename First, typename... Rest>
struct any_of {
  static constexpr bool value = std::is_same_v<std::decay<T>, std::decay<First>> || 
    ((std::is_same_v<std::decay<T>, std::decay<Rest>>) || ...);
};

template <typename T, typename First, typename... Rest>
struct any_but {
  static constexpr bool value = !any_of<T, First, Rest...>::value;
};