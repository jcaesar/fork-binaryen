#ifndef wasm_mutex_h
#define wasm_mutex_h

#include "config.h"

#ifdef HAVE_THREADS
#include <mutex.h>
#else

namespace std {

class mutex {};
class recursive_mutex {};

template<typename T>
class lock_guard {
public:
  lock_guard(T t) { (void)t; }
};

template<typename T>
class unique_lock {
public:
  unique_lock(T t) { (void)t; }
};

}

#endif // HAVE_THREADS

#endif
