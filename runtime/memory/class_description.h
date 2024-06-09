#ifndef EVM_RUNTIME_CLASS_DESCRIPTION_H
#define EVM_RUNTIME_CLASS_DESCRIPTION_H

#include "common/macros.h"
#include "runtime/memory/field.h"

#include <cassert>

namespace evm::runtime {

class ClassDescription {
public:
    NO_MOVE_SEMANTIC(ClassDescription);
    NO_COPY_SEMANTIC(ClassDescription);

    ClassDescription() = default;
    ~ClassDescription() = default;

    void SetFields(Field *fields)
    {
        fields_ = fields;
    }

    void SetFieldsNum(size_t fields_num)
    {
        fields_num_ = fields_num;
    }

    void SetObjectType(memory::Type object_type)
    {
        object_type_ = object_type;
    }

    bool IsStringObject() const
    {
        return object_type_ == memory::Type::STRING_OBJECT;
    }

    bool IsArrayObject() const
    {
        return object_type_ == memory::Type::ARRAY_OBJECT;
    }

    memory::Type GetObjectType() const
    {
        return object_type_;
    }

    size_t GetClassSize() const
    {
        return fields_num_ * 8;
    }

    const Field &GetField(size_t field_idx)
    {
        // printf("[ClassDescription::GetField] fields_num = %ld, fields_ptr = %p, field_idx = %ld\n", fields_num_,
        //        static_cast<void *>(fields_), field_idx);
        assert(field_idx < fields_num_);
        return fields_[field_idx];
    }

private:
    size_t fields_num_ {0};
    Field *fields_ {nullptr};

    memory::Type object_type_ {memory::Type::INVALID};
};

} // namespace evm::runtime

#endif // EVM_RUNTIME_CLASS_DESCRIPTION_H
