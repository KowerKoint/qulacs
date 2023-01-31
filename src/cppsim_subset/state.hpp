#pragma once

#include <csim/memory_ops.hpp>

namespace subset {
class QuantumState {
private:
    ITYPE _dim;
    UINT _qubit_count;
    CTYPE* _state_vector;
    
public:
    const ITYPE& dim;
    const UINT& qubit_count;

    QuantumState(UINT qubit_count) : dim(_dim), qubit_count(_qubit_count), _qubit_count(qubit_count) {
        _dim = 1ULL << qubit_count;
        _state_vector = reinterpret_cast<CTYPE*>(allocate_quantum_state(_dim));
    }
    ~QuantumState() { release_quantum_state(_state_vector); }
    
    CTYPE* data() const { return _state_vector; }
};
}