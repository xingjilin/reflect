// The MIT License (MIT)
//
// Copyright (c) 2014 Jeremy Letang
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#ifndef REFLECT_OBJECT
#define REFLECT_OBJECT

#include "class.h"

namespace rf {

class object_t {

    friend class class_t;

private:

    std::string type_name_;
    void *ptr;

    object_t() = delete;
    object_t(std::string type_name, void *ptr)
    : type_name_(type_name), ptr(ptr) {}

public:

    template<typename T> T &get() {
        return *static_cast<T*>(this->ptr);
    }

    void *get_ptr() {
        return this->ptr;
    }

    std::string &type_name() {
        return this->type_name_;
    }

    bool operator==(object_t &oth) {
        return this->ptr == oth.ptr;
    }

    bool operator!=(object_t &oth) {
        return this->ptr != oth.ptr;
    }

    friend bool operator==(std::nullptr_t nullp, object_t &o);
    friend bool operator==(object_t &o, std::nullptr_t nullp);
    friend bool operator!=(std::nullptr_t nullp, object_t &o);
    friend bool operator!=(object_t &o, std::nullptr_t nullp);

};

bool
operator==(std::nullptr_t nullp, object_t &o) {
    return o.ptr == nullptr;
}

bool
operator==(object_t &o, std::nullptr_t nullp) {
    return o.ptr == nullptr;
}

bool
operator!=(std::nullptr_t nullp, object_t &o) {
    return o.ptr != nullptr;
}

bool
operator!=(object_t &o, std::nullptr_t nullp) {
    return o.ptr != nullptr;
}

// FIXEM: get_class() -> class_t,

}

#endif
