#!/bin/bash
TEST_DIR="./tests/sudokus"

# Define the algorithms
ALGORITHMS=("A" "U" "B" "G" "I")

# Number of times to repeat each test

# Check if the -q flag is present in the command line arguments
quiet_mode=false
for arg in "$@"; do
    if [[ $arg == "-q" ]]; then
        quiet_mode=true
        break
    fi
done

# Function to run tests and store execution time in a folder
run_test() {
    BIN_DIR="./bin"
    TEST_EXEC="$BIN_DIR/TP1"
    RESULTS_DIR="./tests/results/"
    NUM_REPETITIONS=30

    
    local algorithm="$1"
    local puzzle_file="$2"
    
    # Read the puzzle from the file
    local puzzle=$(<"$puzzle_file")

    # Repeat the test multiple times
    for i in $(seq 1 $NUM_REPETITIONS); do
        # Construct the command line for running the program
        local command_line="$TEST_EXEC $algorithm $puzzle"
        
        # Start measuring the time
        local start_time=$(date +%s%3N)
        # Run the program
        output=$(eval "$command_line")
        # Calculate the elapsed time
        local end_time=$(date +%s%3N)
        local elapsed_time=$((end_time - start_time))

        echo "$puzzle_file $algorithm $i $elapsed_time"

        # Create directory for algorithm if it doesn't exist
        mkdir -p $RESULTS_DIR
        
        # Create a file path to store the execution time in CSV format
        local csv_file="$RESULTS_DIR/$(basename "$puzzle_file" .txt).csv"
       
        # Check if the CSV file exists, and if not, create it with a header
        if [[ ! -f "$csv_file" ]]; then
            echo "algorithm,puzzle_file,execution_time_ms,states_expanded" > "$csv_file"
        fi

        # Append the execution time, algorithm, and puzzle file to the CSV file
        echo "$algorithm,$puzzle_file,$elapsed_time,$output" >> "$csv_file"
    done
}

# Export the function so it can be used by GNU parallel
export -f run_test

# Run the tests for each algorithm in parallel
for algorithm in "${ALGORITHMS[@]}"; do
    find "$TEST_DIR" -type f -name "*.txt" | parallel -j 6 run_test "$algorithm" {}
done
