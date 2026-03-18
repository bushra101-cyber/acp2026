#!/usr/bin/env bats

@test "Third rectangle largest" {
    run bash -c "printf '3\n10.5\n2.5\n30\n15\n22.2\n11.1' | ./demo3"

    echo "$output" | grep -n "largest"

    [[ "$output" == *"The rectangle 2 at index 1 is largest with area = 450.00."* ]]
    [[ "$output" =~ "Rectangle 1 area = 26.25" ]]
    [[ "$output" =~ "Rectangle 2 area = 450.00" ]]
    [[ "$output" =~ "Rectangle 3 area = 246.42" ]]
}

@test "First rectangle largest" {
    run bash -c "printf '4\n10\n5\n9\n3\n6\n2\n5\n2' | ./demo3"

    echo "$output" | grep -n "largest"

    [[ "$output" == *"The rectangle 1 at index 0 is largest with area = 50.00."* ]]
    [[ "$output" =~ "Rectangle 1 area = 50.00" ]]
    [[ "$output" =~ "Rectangle 2 area = 27.00" ]]
}

@test "Decimal and integer test" {
    run bash -c "printf '2\n10.5\n3\n15\n11.1' | ./demo3"

    echo "$output" | grep -n "largest"

    [[ "$output" == *"The rectangle 2 at index 1 is largest with area = 166.50."* ]]
    [[ "$output" =~ "Rectangle 1 area = 31.50" ]]
}
@test "All rectangles same area" {
    run bash -c "printf '3\n5\n4\n5\n4\n5\n4' | ./demo3"

    echo "$output" | grep -n "largest"

    [[ "$output" == *"The rectangle 1 at index 0 is largest with area = 20.00."* ]]
}

@test "Single rectangle" {
    run bash -c "printf '1\n7.5\n8.2' | ./demo3"

    echo "$output" | grep -n "largest"

    [[ "$output" == *"The rectangle 1 at index 0 is largest"* ]]
}