#include <stdio.h>
#include <stdbool.h>
// Add any extra import statements you may need here


// Add any helper functions you may need here


bool areTheyEqual(int n, int array_a[], int array_b[]) {

    int aux = 0;
    int cont = 0;

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++){

            if (array_a[i] == array_b[j]) {
                aux = array_b[i];               //Saves variable B[i] in aux memory
                array_b[i] = array_b[j];        //Realocates B[j] to i position
                array_b[j] = aux;               //Put b[i] in j position
                cont++;
                break;
            }
        }
    }

    if (cont == n){
        return true;
    }else{
        return false;
    }

}












// These are the tests we use to determine if the solution is correct.
// You can add your own at the bottom.
int test_case_number = 1;

void check(bool expected, bool output) {
  const char* rightTick = u8"\u2713";
  const char* wrongTick = u8"\u2717";
  if (expected == output) {
    printf("%s Test #%d\n", rightTick, test_case_number);
  }
  else {
    printf("%s Test #%d: Expected ", wrongTick, test_case_number);
    printf("%s", expected ? "true" : "false");
    printf(" Your output: ");
    printf("%s", output ? "true" : "false");
    printf("\n");
  }
  test_case_number++;
}

int main() {

  int n_1 = 4;
  int array_a_1[] = {1, 2, 3, 4};
  int array_b_1[] = {1, 4, 3, 2};
  bool expected_1 = true;
  bool output_1 = areTheyEqual(n_1, array_a_1, array_b_1);
  check(expected_1, output_1);

  int n_2 = 4;
  int array_a_2[] = {1, 2, 3, 4};
  int array_b_2[] = {1, 4, 3, 3};
  bool expected_2 = false;
  bool output_2 = areTheyEqual(n_2, array_a_2, array_b_2);
  check(expected_2, output_2);

  // Add your own test cases here

}
