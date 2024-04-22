#!/bin/bash

# Define directories for tests and executable
BIN_DIR="./bin"
TEST_EXEC="$BIN_DIR/TP1.out"

# Define the algorithms
ALGORITHMS=("A" "U" "B" "G" "I")

# Define the Sudoku puzzles as space-separated strings
# Format each puzzle as a single line string
SUDOKU_PUZZLES=(
    # Sudoku 1 - Intermediário
    "530070000 600195000 098000060 800060003 400803001 700020006 060000280 000419005 000080079"
    # Sudoku 2 - Difícil
    "800000000 003600000 070090200 050007000 000045700 000100030 001000068 008500010 090000400"
    # Sudoku 3 - Intermediário
    "800700000 003600005 070090200 050007090 000045700 000100034 001000068 008500010 090000400"
    # Add more puzzles here as needed
    # "869752341 423618579 175493286 354867192 600045700 000100030 001000068 008500010 090000400"
    
    "123456789 987321654 000000000 000000000 000000000 000000000 000000000 000000000 000000000"
    )

# Function to run tests and print execution time and program details
run_test() {
    local algorithm="$1"
    local puzzle="$2"
    local puzzle_index="$3"

    # Construct the command line for running the program
    local command_line="$TEST_EXEC $algorithm $puzzle"
    
    # Echo the program being run and its input
    echo "Running command: $command_line"
    # Start measuring the time
    local start_time=$(date +%s%3N)

    # Run the program and capture its output
    output=$(eval "$command_line")

    # Calculate the elapsed time
    local end_time=$(date +%s%3N)
    local elapsed_time=$((end_time - start_time))

    # Print the execution time
    echo "Execution time for $algorithm on Sudoku Puzzle $((puzzle_index + 1)): $elapsed_time ms"
    
    # Print the program output
    echo "$output"
    echo
}

# Run the tests for each algorithm and each puzzle
for algorithm in "${ALGORITHMS[@]}"; do
    for index in "${!SUDOKU_PUZZLES[@]}"; do
        # Get the puzzle at the current index
        puzzle="${SUDOKU_PUZZLES[$index]}"
        
        # Run the test
        run_test "$algorithm" "$puzzle" "$index"
    done
done
