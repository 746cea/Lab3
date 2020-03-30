#include <iostream>
#include <ctime>

using namespace std;

int main()
{
  srand(time(0));
  int n = rand() % 7 + 1;
  int sum = 0;
  int *array = new int[n];
       for (int i = 0; i < n; i++)
                array[i] = rand() % 7 + 1;
                    for (int i = 0; i < n; i++)
                            cout << array[i] << " ";
                            cout<<endl;
  asm(
      "mov %[n], %%ecx\n\t"
      "mov %[array], %%ebx\n\t"
      "perehod:\n\t"
      "mov (%%ebx), %%eax\n\t"
      "mull (%%ebx)\n\t"
      "add %%eax, %[sum]\n\t"
      "add $4, %%ebx\n\t"
      "loop perehod\n\t"
      :
      :[n]"m"(n), [array]"m"(array), [sum]"m"(sum)
      :"%eax", "%ebx", "%ecx"
     );

  cout << "summa kvadratov: " << sum << endl;
  delete [] array;
  return 0;
}