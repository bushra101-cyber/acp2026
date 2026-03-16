#!/usr/bin/env bats

@test "simple test" {
  run ./demo1 <<EOF
5
3 5 0 27 1
EOF

  # Extract the line containing 'max value'
  result_line=$(echo "$output" | grep "max value")
  
  # Check that the line is exactly what we expect
  [[ "$result_line" == "max value = 27.00, index= 3" ]]
}
@test "simple test" {
    run ./demo1 <<EOF
3
1 -2 -9.2
EOF
    #Extract the line containing 'max value'
    result_line=$(echo "$output" | grep "max value")

    # Check that the line is exactly what we expect
    [[ "$result_line" == "max value = 1, index=0"]]
}
@test "simple test"{
    run ./demo1 <<EOF
6
3 5 1.4 24 99 45
EOF
    #Extract the line containing 'max value'
    result_line=$(echo "$output" | grep "max value")

    # Check that the line is exactly what we expect
    [[ "$result_line" == "max value = 99, index=4"]]
}