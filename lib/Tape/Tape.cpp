#include "Tape.h"

#include <stdexcept>
#include <thread>

void Tape::MoveHeadLeft() {
    if (head_->prev() == nullptr) {
        throw std::out_of_range("You are at the start of tape!");
    }
    std::this_thread::sleep_for(move_delay_);
    head_ = head_->prev();
}

void Tape::MoveHeadRight() {
    if (head_->next() == nullptr) {
        throw std::out_of_range("You are at the end of tape!");
    }
    std::this_thread::sleep_for(move_delay_);
    head_ = head_->next();
}

int32_t Tape::Read() const noexcept {
    std::this_thread::sleep_for(read_delay_);
    return head_->data();
}

void Tape::Write(int32_t value) noexcept {
    std::this_thread::sleep_for(write_delay_);
    head_->data() = value;
}

void Tape::RewindToStart() {
    std::this_thread::sleep_for(rewind_delay_);
    head_ = start_;
}

void Tape::RewindToEnd() {
    std::this_thread::sleep_for(rewind_delay_);
    head_ = end_;
}

Tape::Tape(std::ifstream& input,
           size_t size,
           DelayTime move_delay,
           DelayTime read_delay,
           DelayTime write_delay,
           DelayTime rewind_delay)
    :
    head_(nullptr),
    move_delay_(move_delay),
    read_delay_(read_delay),
    write_delay_(write_delay),
    rewind_delay_(rewind_delay) {
    if (size == 0) {
        return;
    }
    start_ = head_ = new Node;
    int32_t data;
    input >> data;
    Write(data);
    for (size_t i = 1; i < size; i++) {
        head_->next() = new Node(0, head_, nullptr);
        MoveHeadRight();
        input >> data;
        Write(data);
    }
    end_ = head_;
    RewindToStart();
}

