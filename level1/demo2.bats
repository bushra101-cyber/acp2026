#!/usr/bin/env bats

@test "largest rectangle test" {
  run bash -c "printf 'R1\n5\n4\nR2\n3\n3\nR3\n2\n2\n' | ./rectangle"

  echo "$output"

  [[ "$output" == *"Largest rectangle: R1"* ]]
}

@test "equal area test" {
  run bash -c "printf 'A\n4\n4\nB\n4\n4\nC\n3\n3\n' | ./rectangle"

  [[ "$output" == *"equal largest area"* ]]
}