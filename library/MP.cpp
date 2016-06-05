A[0] = -1;
int j = -1;
for (int i = 0; i < S.size(); i++) {
      while (j >= 0 && S[i] != S[j]) j = A[j];
        j++;
          A[i+1] = j;
}
