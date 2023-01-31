#include <iostream>

#include <cppsim/gate_factory.hpp>
#include <cppsim/state.hpp>

#include <cppsim_subset/gate_old.hpp>
#include <cppsim_subset/gate_new.hpp>

constexpr int ITR = 100000000;

double gate_present_bench() {
    QuantumState* state = new QuantumState(1);    
    QuantumGateBase* gate = gate::H(0);

    clock_t st = clock();
    for(UINT i = 0; i < ITR; ++i) {
        gate->update_quantum_state(state);
    }
    clock_t ed = clock();
    
    delete state;
    delete gate;
    return 1. * (ed - st) / CLOCKS_PER_SEC;
}

double gate_old_bench() {
    subset::QuantumState* state = new subset::QuantumState(1);
    subset::QuantumGateBase* gate = subset::H_old(0);
    
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
    subset::QuantumState* state = new subset::QuantumState(1);
    subset::QuantumGate* gate = subset::H_new(0);
    
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
    std::cout << "present:" << gate_present_bench() << " sec\n";
    std::cout << "old:" << gate_old_bench() << " sec\n";
    std::cout << "new:" << gate_new_bench() << " sec\n";
}