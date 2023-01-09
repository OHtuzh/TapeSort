#pragma once

#include <fstream>

class ITape {
 public:
    virtual void MoveHeadLeft() = 0;    // Will throw out of range in some cases
    virtual void MoveHeadRight() = 0;   // Will throw out of range in some cases
    virtual void RewindToStart() = 0;
    virtual void RewindToEnd() = 0;
    virtual int32_t Read() const noexcept = 0;
    virtual void Write(int32_t value) noexcept = 0;
};
