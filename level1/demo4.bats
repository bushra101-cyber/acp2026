#!/usr/bin/env bats

@test "Finds Delhi flight AI101" {
    run bash -c "printf 'AI101\nDelhi\n150\nAI202\nMumbai\n100\nAI303\nDelhi\n75\nAI404\nChennai\n120\nDelhi' | ./demo4"
    echo "$output"
    [[ "$output" == *"Flight AI101 available"* ]]
    [[ "$output" == *"Flight AI303 available"* ]]
}

@test "Finds Mumbai flight" {
    run bash -c "printf 'AI101\nDelhi\n150\nAI202\nMumbai\n100\nAI303\nDelhi\n75\nAI404\nChennai\n120\nMumbai' | ./demo4"
    echo "$output"
    [[ "$output" == *"Flight AI202 available"* ]]
}

@test "Multiple flights to same destination" {
    run bash -c "printf 'AI101\nDelhi\n150\nAI202\nMumbai\n100\nAI303\nDelhi\n75\nAI404\nDelhi\n120\nDelhi' | ./demo4"
    echo "$output"
    [[ "$output" == *"Flight AI101 available"* ]]
    [[ "$output" == *"Flight AI303 available"* ]]
    [[ "$output" == *"Flight AI404 available"* ]]
}

@test "No flights to unknown destination" {
    run bash -c "printf 'AI101\nDelhi\n150\nAI202\nMumbai\n100\nAI303\nDelhi\n75\nAI404\nChennai\n120\nBangalore' | ./demo4"
    echo "$output"
    [[ "$output" == *"No flights available to Bangalore"* ]]
}

@test "Shows available seats count" {
    run bash -c "printf 'AI101\nDelhi\n150\nAI202\nMumbai\n100\nAI303\nDelhi\n75\nAI404\nChennai\n120\nDelhi' | ./demo4"
    echo "$output"
    [[ "$output" == *"150"* || "$output" == *"75"* ]]
}
