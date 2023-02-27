// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
  if (n == 1) {
    return value;
  }
  return value * pown(value, n - 1);
}

uint64_t fact(uint16_t n) {
  if (n == 1) {
    return n;
  }
  return n * fact( n - 1);
}

double calcItem(double x, uint16_t n) {
  return pown(x, n) / fact(n);
}

double expn(double x, uint16_t count) {
  double res = 0;
  for (int i = 0; i <= count; i++) {
    res += calcItem(x,i);
  }
  return res;
}

double sinn(double x, uint16_t count) {
  double res = 0;
  for (int i = 1; i <= count; i++) {
    res += calcItem(x, 2 * i - 1) * pown(-1, i + 1);
  }
  return res;
}

double cosn(double x, uint16_t count) {
  double res = 0;
  for (int i = 0; i <= count; i++) {
    res += calcItem(x, 2 * i ) * pown(-1, i + 2);
  }
  return res;
}
