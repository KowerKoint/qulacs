#pragma once

#include <functional>

#include <csim/update_ops.hpp>

#include "state.hpp"

namespace subset {
class QuantumGate {
private:
    std::function<void(QuantumState*)> controller;
public:
    QuantumGate(std::function<void(QuantumState*)>&& controller) : controller(controller) {}

    void update_quantum_state(QuantumState* state) {
        controller(state);
    }
};

struct HGateController {
    int target_qubit_index;
    
    HGateController(int target_qubit_index) : target_qubit_index(target_qubit_index) {}
    
    void operator()(QuantumState* state) {
        H_gate(target_qubit_index, state->data(), state->dim);
    }
};

QuantumGate* H_new(UINT target_qubit_index) {
    HGateController controller(target_qubit_index);
    return new QuantumGate(std::move(controller));
}
}