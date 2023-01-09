#pragma once

#include <cinttypes>

#pragma pack(push, 1)

class Node {
 private:
    int32_t data_;
    Node* prev_;
    Node* next_;
 public:
    explicit Node(int32_t data = 0, Node* prev = nullptr, Node* next = nullptr)
        :
        data_(data),
        prev_(prev),
        next_(next) {}

    inline Node*& prev() {
        return prev_;
    }

    inline Node*& next() {
        return next_;
    }

    inline int32_t& data() {
        return data_;
    }
};

#pragma pack(pop)

constexpr const size_t kNodeSize = sizeof(Node);
