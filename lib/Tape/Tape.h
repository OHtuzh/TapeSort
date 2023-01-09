#pragma once

#include "ITape.h"
#include "Node.h"

#include <chrono>

using namespace std::chrono_literals;
typedef std::chrono::milliseconds DelayTime;

class Tape : public ITape {
 private:
    Node* head_;
    Node* start_;
    Node* end_;

    DelayTime move_delay_;
    DelayTime read_delay_;
    DelayTime write_delay_;
    DelayTime rewind_delay_;

 public:
    void MoveHeadLeft() override;
    void MoveHeadRight() override;
    void RewindToStart() override;
    void RewindToEnd() override;
    [[nodiscard]] int32_t Read() const noexcept override;
    void Write(int32_t value) noexcept override;


    explicit Tape(std::ifstream& input,
                  size_t size,
                  DelayTime move_delay = 0s,
                  DelayTime read_delay = 0s,
                  DelayTime write_delay = 0s,
                  DelayTime rewind_delay = 0s);
};

constexpr const size_t kTapeSize = sizeof(Tape);
