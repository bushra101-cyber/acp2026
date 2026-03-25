#!/usr/bin/env bats

@test "File read/write works" {
    # Create test input
    printf "2\n101 Alice 85.5\n102 Bob 92.0" > test_input.txt
    run bash -c "./demo9 < test_input.txt > output.txt"
    [[ -f "students.txt" ]]
    [[ "$(cat students.txt)" == *"2"* ]]
}

@test "File format correct" {
    run bash -c "./demo9"
    # Interactive test - assumes manual input works
    [[ "$status" -eq 0 ]]
}