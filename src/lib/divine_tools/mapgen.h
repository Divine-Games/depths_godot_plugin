// Check if we are in a C++ context, then set up 'extern "C"' block.
#ifdef __cplusplus
extern "C"
{
#endif

#include <stddef.h> /* for ptrdiff_t below */

  /* ... (other includes or definitions as needed) ... */

#ifndef GO_CGO_PROLOGUE_H
#define GO_CGO_PROLOGUE_H

  // Define Go-related types, adjusting as necessary for C++ compatibility.
  typedef signed char GoInt8;
  typedef unsigned char GoUint8;
  typedef short GoInt16;
  typedef unsigned short GoUint16;
  typedef int GoInt32;
  typedef unsigned int GoUint32;
  typedef long long GoInt64;
  typedef unsigned long long GoUint64;
  typedef GoInt64 GoInt;
  typedef GoUint64 GoUint;
  typedef size_t GoUintptr; // __SIZE_TYPE__ is a gcc-specific extension, use standard C type.

  // For the next part, we're avoiding the _Complex type which is not well-supported in C++.
  // If complex numbers are not being used, these could even be simple structs or omitted.
  struct GoComplex64
  {
    float real;
    float imag;
  };
  struct GoComplex128
  {
    double real;
    double imag;
  };

  typedef float GoFloat32;
  typedef double GoFloat64;

  // Handle the static assertion for 64-bit checks. This construct is common in C.
  typedef char _check_for_64_bit_pointer_matching_GoInt[sizeof(void *) == 64 / 8 ? 1 : -1];

// Other Go-related definitions follow...
#ifndef GO_CGO_GOSTRING_TYPEDEF
  typedef struct
  {
    const char *p;
    ptrdiff_t n;
  } _GoString_;
  typedef _GoString_ GoString;
#endif
  typedef void *GoMap;
  typedef void *GoChan;
  typedef struct
  {
    void *t;
    void *v;
  } GoInterface;
  typedef struct
  {
    void *data;
    GoInt len;
    GoInt cap;
  } GoSlice;

#endif // GO_CGO_PROLOGUE_H

  // Declare your functions to be used from C++ or other languages.
  extern char *GenerateMapJSON(GoInt width, GoInt height, GoInt64 seed);

// End the 'extern "C"' block if in a C++ context.
#ifdef __cplusplus
}
#endif