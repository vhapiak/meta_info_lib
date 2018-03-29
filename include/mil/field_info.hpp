#pragma once

namespace mil {

template <typename Class, typename Type>
class field_info {
  public:
    using pointer_t = Type Class::*;

    field_info(pointer_t pointer, const char* name)
        : m_field(pointer)
        , m_name(name) {}

    const char* name() const;
    pointer_t field() const;
    Type& value(Class& obj) const;
    const Type& value(const Class& obj) const;

  private:
    pointer_t m_field;
    const char* m_name;
};

template <typename Class, typename Type>
const char* field_info<Class, Type>::name() const {
    return m_name;
}

template <typename Class, typename Type>
typename field_info<Class, Type>::pointer_t field_info<Class, Type>::field() const {
    return m_field;
}

template <typename Class, typename Type>
Type& field_info<Class, Type>::value(Class& obj) const {
    return obj.*m_field;
}

template <typename Class, typename Type>
const Type& field_info<Class, Type>::value(const Class& obj) const {
    return obj.*m_field;
}

}  // namespace mil
