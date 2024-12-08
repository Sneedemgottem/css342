# Don't actually use this script I didn't realize the overhead from subshells was so bad it added minutes ontop of the exe call



# This script only works if the sorter program only returns time elapsed and no other text

# Path to the sorter executable
ExePath='./build/run'

# Sorting algorithms to benchmark
Algorithms=('BubbleSort' 'InsertionSort' 'MergeSort' 'IterativeMergeSort' 'QuickSort' 'ShellSort')

# N input vector size
N_Size=(10 100 1000 5000 10000 15000 20000 25000 30000 35000 40000 45000 50000 55000 60000 65000 70000 75000)

# Number of trials to average together per N
Trials=10

# how to run and capture value => t_value=$(./build/run "BubbleSort" "10000")

# Arguments: SortAlgo, N
# Returns Average Time after T trials

RunTrials() {
    local Algo=$1
    local N=$2

    declare -i Res
    Res=0

    for ((i = 0 ; i < ${Trials} ; i++)); do
        t_value=$(${ExePath} ${Algo} ${N})
        Res+=${t_value};
    done

    Res=Res/${Trials}

    echo "${Res}"
}

# Result=$(RunTrials "MergeSort" 20000)
# echo "${Result}"

echo "Starting benchmarks ... this may take a while"

# simultaneously clears or creates .csv file
printf "" > benchmarks.csv

printf 'N,' >> benchmarks.csv
for Algo in "${Algorithms[@]}"; do
    printf '%s,' "${Algo}" >> benchmarks.csv
done

echo "" >> benchmarks.csv

# benchmarks dir should exist now and be empty
for N in "${N_Size[@]}"; do
    printf '%s,' "${N}" >> benchmarks.csv
    for Algo in "${Algorithms[@]}"; do
        Result=$(RunTrials ${Algo} ${N})
        printf '%s,' "${Result}" >> benchmarks.csv
    done
    echo "" >> benchmarks.csv
done

echo "Done! Wrote results to benchmarks.csv"