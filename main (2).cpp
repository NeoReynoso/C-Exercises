//
//  main.cpp
//  Collison
//
//  Created by Ivan Reynoso on 1/13/23.
//

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

bool LinearHashInsert(int hashTable[], int item) {
   // Hash function determines initial bucket
   int bucket = item % 31;
   int bucketsProbed = 0;
   
   while (bucketsProbed < 31) {
      // Insert item in next empty bucket
      if (hashTable[bucket] == -1) {
         hashTable[bucket] = item;
         return true;
      }

      // Increment bucket index
      bucket = (bucket + 1) % 31;

      // Increment number of buckets probed
      ++bucketsProbed;
   }

   return false;
}

bool QuadraticHashInsert(int hashTable[], int item) {
   int i = 0;
   int bucketsProbed = 0;
   int c1 = 4;
   int c2 = 8;
  
   // Hash function determines initial bucket
   int bucket = item % 31;
   while (bucketsProbed < 31) {
      // Insert item in next empty bucket
      if (hashTable[bucket] == -1) {
         hashTable[bucket] = item;
         return true;
      }

      // Increment i and recompute bucket index
      // c1 and c2 are programmer-defined constants for quadratic probing
      i = i + 1;
      bucket = item + (c1 * i + c2 * i * i) % 31;

      // Increment number of buckets probed
      bucketsProbed = bucketsProbed + 1;
   }
   return false;
}

void PrintArray(int hashTable[], int N) {
  for (int i = 0; i < N; i++) {
    cout << hashTable[i] << " ";
  }
  cout << endl;
}

int main(int argc, const char * argv[]) {
    int hashTable1[31];
      
      for (int i = 0; i < 31; i++) {
        hashTable1[i] = -1;
    }
      
      srand(time(NULL));
      
      cout << "Linear Probing" << endl;
       for (int i = 0; i < 20; i++) {
      int randomInteger = rand() % 100;
      cout << "Integer Inserted: " << randomInteger << endl;
      LinearHashInsert(hashTable1, randomInteger);
      PrintArray(hashTable1, 31);
    }
  
     cout << endl;
  
      int hashTable2[31];
      
      for (int i = 0; i < 31; i++) {
        hashTable2[i] = -1;
    }
  
    cout << "Quadratic Probing" << endl;
       for (int i = 0; i < 20; i++) {
      int randomInteger = rand() % 100;
      cout << "Integer Inserted: " << randomInteger << endl;
      QuadraticHashInsert(hashTable2, randomInteger);
      PrintArray(hashTable2, 31);
    }
  
    return 0;
}
