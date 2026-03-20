#!/usr/bin/env bats

@test "Swaps two simple arrays" {
    # EXACT input that produces YOUR output
    run bash -c "printf '5\n2\n5\n3\n4\n6\n3\n2\n2\n4\n0' | ./demo5"
    echo "$output"
    
    [[ "$output" == *"Before swap:"* ]]
    [[ "$output" == *"Array 1 : The array is : 2 5 3 4 6"* ]]   # Your actual data
    [[ "$output" == *"Array 2 : The array is : 3 2 2 4 0"* ]]   # Your actual data
    [[ "$output" == *"After swap :"* ]]
    [[ "$output" == *"Array 1 :The array is : 3 2 2 4 0"* ]]
    [[ "$output" == *"Array 2 : The array is : 2 5 3 4 6"* ]]
}

@test "Swaps single element arrays" {
    run bash -c "printf '1\n10\n20' | ./demo5"
    [[ "$output" == *"Array 1 : The array is : 10"* ]]
    [[ "$output" == *"Array 2 : The array is : 20"* ]]
    [[ "$output" == *"After swap"* ]]
}

@test "Swaps arrays with zeros" {
    run bash -c "printf '3\n0\n0\n0\n1\n1\n0' | ./demo5"
    [[ "$output" == *"Array 1 : The array is : 0 0 0"* ]]
    [[ "$output" == *"Array 2 : The array is : 1 1 0"* ]]
}

@test "Swaps negative numbers" {
    run bash -c "printf '4\n-1\n-2\n2\n-3\n4\n1\n-4\n3' | ./demo5"
    [[ "$output" == *"Array 1 : The array is : -1 -2 2 -3"* ]]
}

@test "Swaps identical arrays" {
    run bash -c "printf '3\n1\n2\n3\n1\n2\n3' | ./demo5"
    [[ "$output" == *"Array 1 : The array is : 1 2 3"* ]]
    [[ "$output" == *"Array 2 : The array is : 1 2 3"* ]]
}