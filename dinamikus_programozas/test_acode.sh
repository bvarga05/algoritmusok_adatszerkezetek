#!/bin/bash

C_PROGRAM="./acode"

PROGRAM="acode_alphacode.cpp"

TEST_DIR="./tests"

g++ -std=c++14 -o $C_PROGRAM $PROGRAM

for INPUT_FILE in $TEST_DIR/*_in.txt; do
    TEST_NAME=$(basename "$INPUT_FILE" _in.txt)
    EXPECTED_FILE="$TEST_DIR/${TEST_NAME}_expected.txt"
    ACTUAL_FILE="${TEST_DIR}/${TEST_NAME}_actual.txt"

    $C_PROGRAM < "$INPUT_FILE" > "$ACTUAL_FILE"

    echo "Running $TEST_NAME..."
    if diff -u "$EXPECTED_FILE" "$ACTUAL_FILE" > /dev/null; then
        echo "$TEST_NAME: Passed"
    else
        echo "$TEST_NAME: Failed"
        echo "Differences:"
        diff -u "$EXPECTED_FILE" "$ACTUAL_FILE"
    fi

    rm -f "$ACTUAL_FILE"
done
