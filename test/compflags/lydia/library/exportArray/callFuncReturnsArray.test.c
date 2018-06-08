#include <stdio.h>
#include <stdint.h>

#include "returnExternArray.h"

extern void chpl_library_init(int argc, char* argv[]);
extern void chpl_library_finalize(void);


extern void chpl_call_free(chpl_external_array x);

// Test of calling an exported function that returns an array
int main(int argc, char* argv[]) {
  // Initialize the Chapel runtime and standard modules
  chpl_library_init(argc, argv);

  // Call the function to get the array
  chpl_external_array arr = foo();
  int64_t* actual = (int64_t*)arr.elts;

  // Write its elements
  for (int i = 0; i < 4; i++) {
    printf("Element[%d] = %lld\n", i, actual[i]);
  }

  // Call the cleanup function
  chpl_free_external_array(arr);

  // Shutdown the Chapel runtime and standard modules
  chpl_library_finalize();

  return 0;
}
