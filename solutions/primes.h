/*
 * Header file contains the implementation of checking if a number is prime or not.
 */

bool isPrime(int n){
  if (n == 2)
    return true;
  if (n % 2 == 0)
    return false;
  for(int i = 3; i*i <= n; i++)
    if(n%i == 0)
      return false;
  return true;
}
