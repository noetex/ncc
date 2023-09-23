#ifdef _MSC_VER
  #define ALIGNED(x) __declspec(align(x))
#else
  // clang or gcc
  #define ALIGNED(x) __attribute__((aligned(x)))
#endif

