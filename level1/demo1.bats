#!/usr/bin/env bats

@test "max value in middle" {
    run bash -c "printf '5\n1\n2\n26\n4\n5\n' | ./demo1"

    echo "$output"

    [[ "$output" == *"max value = 26.00, index= 2"* ]]
}

@test "max value at last index" {
    run bash -c "printf '4\n5\n10\n20\n100\n' | ./demo1"

    echo "$output"

    [[ "$output" == *"max value = 100.00, index= 3"* ]]
}

@test "decimal numbers" {
    run bash -c "printf '4\n2.5\n7.8\n6.1\n3.4\n' | ./demo1"

    echo "$output"
    
    [[ "$output" == *"max value = 7.80, index= 1"* ]]
}