#!/usr/bin/env bats

@test "Simple strings" {
    run bash -c "printf 'Hello\nWorld' | ./demo8"
    [[ "$output" == *"Concatenated string: HelloWorld"* ]]
}

@test "Single letters" {
    run bash -c "printf 'a\nb' | ./demo8"
    [[ "$output" == *"Concatenated string: ab"* ]]
}

@test "Sentences with spaces" {
    run bash -c "printf 'Hello World\nHow are you' | ./demo8"
    [[ "$output" == *"Concatenated string: Hello WorldHow are you"* ]]
}

@test "Empty second string" {
    run bash -c "printf 'Hello\n' | ./demo8"
    [[ "$output" == *"Concatenated string: Hello"* ]]
}