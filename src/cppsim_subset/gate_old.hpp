#pragma once

#include <string>
#include <vector>

#include <csim/type.hpp>
#include <csim/update_ops.hpp>

#include "state.hpp"

namespace subset {
class QuantumGateBase {
protected:
    std::vector<UINT> _target_qubit_list;
    std::vector<UINT> _controll_qubit_list;
    std::string _name = "Generic gate";

public:
    virtual void update_quantum_state(QuantumState* state) = 0;
};

class ClsHGate : public QuantumGateBase {
public:
    ClsHGate(UINT target_qubit_index) {
        _name = "H";
        _target_qubit_list.push_back(target_qubit_index);
    }
    
    void update_quantum_state(QuantumState* state) override {
        H_gate(_target_qubit_list[0], state->data(), state->dim);
    }
};

ClsHGate* H_old(UINT target_qubit_index) { return new ClsHGate(target_qubit_index); }
}