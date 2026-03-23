#!/usr/bin/env bats

@test "Simple Memory allocation and deallocation" {
    run bash -c "printf '3\n2\n4\n6' | ./demo6"
    
    [[ "$output" == *"Array: 2 4 6"* ]]
    [[ "$output" == *"Memory freed safely."* ]]
    [[ "$output" == *"No dangling pointers!"* ]]
}

@test "Single element allocation and deallocation" {
    run bash -c "printf '1\n42' | ./demo6"
    
    [[ "$output" == *"Array: 42"* ]]
    [[ "$output" == *"Memory freed safely."* ]]
    [[ "$output" == *"No dangling pointers!"* ]]
}

@test "zero elements allocation and deallocation" {
    run bash -c "printf '0' | ./demo6"
    
    [[ "$output" == *"Array: "* ]]
    [[ "$output" == *"Memory freed safely."* ]]
    [[ "$output" == *"No dangling pointers!"* ]]
}

@test "Negative elements allocation and deallocation" {
    run bash -c "printf '3\n-3\n-5\n-7' | ./demo6"
    
    [[ "$output" == *"Array: -3 -5 -7"* ]]
    [[ "$output" == *"Memory freed safely."* ]]
    [[ "$output" == *"No dangling pointers!"* ]]
}