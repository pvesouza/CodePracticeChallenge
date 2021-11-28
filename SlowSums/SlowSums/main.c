#include <stdio.h>
#include <stdbool.h>

// Add any extra import statements you may need here


// Add any helper functions you may need here

// Returns thew sum of the twho largest
int twoLargestSum(int arr[], int n_bytes) {

    int greatest = 0;
    int greatestPosition = 0;
    int secondGreatest = 0;
    int secondGreatestPosition = 0;
    int sum = 0;

    // Finding the greatest
    for (int i = 0; i < n_bytes; i++) {
        if (greatest < arr[i]){
            greatest = arr[i];
            greatestPosition = i;
        }

    }

    for (int i = 0; i < n_bytes; i++) {
        if (i != greatestPosition){
            if (secondGreatest < arr[i]){
                secondGreatest = arr[i];
                secondGreatestPosition = i;
            }
        }
    }

    sum = greatest + secondGreatest;
    arr[greatestPosition] = sum;
    arr[secondGreatestPosition] = 0;

    return sum;

}

// Counts the number of zeros
int countZeros(int arr[], int n_bytes) {
    int count = 0;
    //printf("{");
    for (int i = 0; i < n_bytes; i++){
        //printf("%d, ", arr[i]);
        if (arr[i] == 0) {
            count ++;
        }
    }
    //printf("}\n");

    return count;
}


int getTotalTime(int arr[], int n) {

    int totalSum = 0;
    int count = 0;
    int limit = n -1;

    do {
        totalSum = totalSum + twoLargestSum(arr, n);
        count = countZeros(arr, n);
        //printf("count = %d\n", count);
        //printf("Sum = %d\n", totalSum);

    }while(count < limit);

    return totalSum;

}












// These are the tests we use to determine if the solution is correct.
// You can add your own at the bottom.
void printInteger(int n) {
  printf("[%d]", n);
}

int test_case_number = 1;

void check(int expected, int output) {
  int result = (expected == output);
  const char* rightTick = u8"\u2713";
  const char* wrongTick = u8"\u2717";
  if (result) {
    printf("%s Test #%d\n", rightTick, test_case_number);
  }
  else {
    printf("%s Test #%d: Expected ", wrongTick, test_case_number);
    printInteger(expected);
    printf(" Your output: ");
    printInteger(output);
    printf("\n");
  }
  test_case_number++;
}

int main() {

  int n_1 = 4;
  int arr_1[] = {4, 2, 1, 3};
  int expected_1 = 26;
  int output_1 = getTotalTime(arr_1, n_1);
  //printf("Sum 1: %d\n", output_1);
  check(expected_1, output_1);

  int n_2 = 5;
  int arr_2[] = {2, 3, 9, 8, 4};
  int expected_2 = 88;
  int output_2 = getTotalTime(arr_2, n_2);
  //printf("Sum 2: %d\n", output_2);
  check(expected_2, output_2);

  // Add your own test cases here

}
