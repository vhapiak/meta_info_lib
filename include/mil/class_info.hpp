#pragma once

#include "mil/detail/fields_ids.hpp"
#include "mil/detail/fields_list.hpp"

namespace mil {

template <typename T>
class class_info {
  private:
    using fields_ids = detail::fields_ids<T>;

  public:
    using type = T;
    using fields_list = detail::fields_list_t<T, fields_ids>;

    class_info();

    const fields_list& fields() const;

  private:
    fields_list m_fields;
};

template <typename T>
class_info<T>::class_info()
    : m_fields(detail::fields<T, fields_ids>()) {
}

template <typename T>
const typename class_info<T>::fields_list& class_info<T>::fields() const {
    return m_fields;
}

}  // namespace mil
