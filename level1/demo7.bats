#!/usr/bin/env bats

@test "Simple strings" {
    run bash -c "printf 'Hello\nHi' | ./demo7"
    
    [[ "$output" == *"String 2 is lexicographically larger than String 1"* ]]
}
@test "Single letter" {
    run bash -c "printf 'a\nH' | ./demo7"
    
    [[ "$output" == *"String 1 is lexicographically larger than String 2"* ]]
}
@test "Sentences" {
    run bash -c "printf 'Hello I am Suzan\nHi my name is Tara' | ./demo7"
    
    [[ "$output" == *"String 2 is lexicographically larger than String 1"* ]]
}
@test "Same strings" {
    run bash -c "printf 'Coding\nCoding' | ./demo7"
    
    [[ "$output" == *"String 1 is equal to String 2"* ]]
}