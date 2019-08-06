#include <jni.h>

#include "lucas.h"
#include "lucas_jni.h"

jlong Java_Mersenne_mersenne(JNIEnv* env, jclass classname, jlong index) {
  return mersenne(index);
}

  
