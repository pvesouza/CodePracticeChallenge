#include <stdio.h>
// Add any extra import statements you may need here



// Find the Three Large
int findThreeLargest (int *ptr, int n) {

    int threeLargest[3] = {0,0,0};
    int lastPosition[3] = {0,0,0};
    int i = 0;


    for (i = 0; i <= n; i++){
        if (threeLargest[2] < *(ptr + i)) {
            threeLargest[2] = *(ptr + i);
            lastPosition[2] = i;
        }
    }


    for (i = 0; i <= n; i++) {
        if (i != lastPosition[2]) {
            if (threeLargest[1] < *(ptr + i)) {
                threeLargest[1] = *(ptr + i);
                lastPosition[1] = i;
            }
        }
    }

    for (i = 0; i <= n; i++) {
        if (i != lastPosition[2] && i != lastPosition[1]) {
            if (threeLargest[0] < *(ptr + i)) {
                threeLargest[0] = *(ptr + i);
                lastPosition[0] = i;
            }
        }
    }

    return threeLargest[0] * threeLargest[1] * threeLargest[2];

}

// Copies n_bytes from source to destiny
void memcopy(int destiny[], int source[], int n_bytes)
{
    for (int i = 0; i < n_bytes; i++) {

        destiny[i] = source[i];
    }

}


int* findMaxProduct(int arr[], int n, int *output_size) {

    int array_out[n];
    int var = *output_size;
    int *ptr_threeLargest = arr;

    for (int i = 0; i < n; i++) {

        if (i < 2){
            array_out[i] = -1;
            var++;              //Incrementa o tamanho do array de saída
        }else{
            array_out[i] = findThreeLargest(ptr_threeLargest, i);
            var++;
        }
    }

    *output_size = var;

    memcopy(arr, array_out, n);

    return arr;

}












// These are the tests we use to determine if the solution is correct.
// You can add your own at the bottom.
void printIntegerArray(int array[], int size) {
  printf("[");
  for (int i = 0; i < size; i++) {
    if (i != 0) {
      printf(", ");
    }
    printf("%d", array[i]);
  }
  printf("]");
}

int test_case_number = 1;

void check(int expected[], int output[], int size, int out_size) {
  int expected_size = size;
  int output_size = out_size;
  int result = 1;
  if (expected_size != output_size) {
    result = 0;
  }
  else {
    for (int i = 0; i < size; i++) {
      result &= (output[i] == expected[i]);
    }
  }
  const char* rightTick = u8"\u2713";
  const char* wrongTick = u8"\u2717";
  if (result) {
    printf("%s Test #%d\n", rightTick, test_case_number);
  }
  else {
    printf("%s Test #%d: Expected ", wrongTick, test_case_number);
    printIntegerArray(expected, size);
    printf(" Your output: ");
    printIntegerArray(output, output_size);
    printf("\n");
  }
  test_case_number++;
}

int main() {
  // Testcase 1
  int n_1 = 5;
  int arr_1[] = {1, 2, 3, 4, 5};
  int expected_1[] = {-1, -1, 6, 24, 60};
  int output_1_size = 0;
  int *output_1 = findMaxProduct(arr_1, n_1, &output_1_size);
  check(expected_1, output_1, n_1, output_1_size);

  // Testcase 2
  int n_2 = 6;
  int arr_2[] = {2, 4, 7, 1, 5, 3};
  int expected_2[] = {-1, -1, 56, 56, 140, 140};
  int output_2_size;
  int *output_2 = findMaxProduct(arr_2, n_2, &output_2_size);
  check(expected_2, output_2, n_2, output_2_size);

  // Add your own test cases here

}
