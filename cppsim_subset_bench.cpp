#include <iostream>

#include <cppsim_subset/gate_old.hpp>
#include <cppsim_subset/gate_new.hpp>

constexpr int ITR = 100000000;

double gate_old_bench() {
    QuantumState* state = new QuantumState(1);
    QuantumGateBase* gate = H_old(0);
    
    clock_t st = clock();
    for(UINT i = 0; i < ITR; ++i) {
        gate->update_quantum_state(state);
    }
    clock_t ed = clock();
    
    delete state;
    delete gate;
    return 1. * (ed - st) / CLOCKS_PER_SEC;
}

double gate_new_bench() {
    QuantumState* state = new QuantumState(1);
    QuantumGate* gate = H_new(0);
    
    clock_t st = clock();
    for(UINT i = 0; i < ITR; ++i) {
        gate->update_quantum_state(state);
    }
    clock_t ed = clock();
    
    delete state;
    delete gate;
    return 1. * (ed - st) / CLOCKS_PER_SEC;
}

int main() {
    std::cout << "old:" << gate_old_bench() << '\n';
    std::cout << "new:" << gate_new_bench() << '\n';
}