#include<bits/stdc++.h>

using namespace std;

typedef struct buff{
    char *name;
} structure;

structure s[5];

void sort(){
    int sz = sizeof s / sizeof s[0];
    printf("sz=%d\n",sz);
    int done = 0;

    for (int i = 0; i < sz; i++){
          for (int j = i+1; j < sz; j++){

                  if (strcmp(s[i].name, s[j].name) < 0){

                      structure tmp;

                      tmp = s[i];
                      s[i] = s[j];
                      s[j] = tmp;
              }
          }
    }
    for (int i = 0; i < sz; i++){
        printf("%d - %s\n", i+1, s[i].name);
    }
}

int main() {
  s[0].name = "ANT";
  s[1].name = "ant";
  s[2].name = "aNT";
  s[3].name = "aNt";
  s[4].name = "BABA";
  cout<<strcmp("ANT","ant");

  sort();
  return 0;
}
