package main

import (
	"encoding/csv"
	"fmt"
	"io"
	"os"
	"strconv"
	"time"
)

func main() {
	start := time.Now()

	// Read the CSV file
	file, err := os.Open("data.csv")
	if err != nil {
		fmt.Println("Error opening file:", err)
		return
	}
	defer file.Close()

	reader := csv.NewReader(file)

	var X, Y, Z []int

	// Read rows from CSV and populate X and Y arrays
	for i := 0; i < 2; i++ {
		record, err := reader.Read()
		if err == io.EOF {
			break
		} else if err != nil {
			fmt.Println("Error reading CSV row:", err)
			return
		}

		row := make([]int, len(record))
		for j, val := range record {
			num, err := strconv.Atoi(val)
			if err != nil {
				fmt.Println("Error converting CSV value to int:", err)
				return
			}
			row[j] = num
		}

		if i == 0 {
			X = row
		} else if i == 1 {
			Y = row
		}
	}

	// Calculate Z = X + Y^2 + 2
	Z = make([]int, len(X))
	for i := 0; i < len(X); i++ {
		Z[i] = X[i] + Y[i]*Y[i] + 2
	}

	// Calculate the sum of the first 100 elements of Z
	sum := 0
	for i := 0; i < 100 && i < len(Z); i++ {
		sum += Z[i]
	}

        elapsed := time.Since(start).Seconds()
         
	// Print the sum and the total time spent
	fmt.Println("Sum of the first 100 elements of Z:", sum)
	fmt.Println("Total time spent:", elapsed)
}

