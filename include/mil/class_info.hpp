#pragma once

#include "mil/detail/fields_ids.hpp"
#include "mil/detail/fields_list.hpp"
#include "mil/detail/parent_type.hpp"

namespace mil {

template <typename T>
class class_info {
  private:
    using fields_ids = detail::fields_ids<T>;

  public:
    using type = T;
    using parent_type = detail::parent_type_t<T>;
    using fields_list = detail::fields_list_t<T, fields_ids>;

    class_info();

    const class_info<parent_type>& parent() const;
    const fields_list& fields() const;

  private:
    class_info<parent_type> m_parent;
    fields_list m_fields;
};

template <>
class class_info<void_t> {};

template <typename T>
class_info<T>::class_info()
    : m_fields(detail::fields<T, fields_ids>()) {
}

template <typename T>
const typename class_info<T>::fields_list& class_info<T>::fields() const {
    return m_fields;
}

template <typename T>
const class_info<typename class_info<T>::parent_type>& class_info<T>::parent() const {
    return m_parent;
}

}  // namespace mil
