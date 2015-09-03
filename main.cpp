#include <sstream>
#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int count_string_occurance(const string &source, const char &target) {
  int count = 0;

  for (char c : source) {
    if (c == target) {
      count++;
    }
  }

  return count;
}

string slurp(const string &filename) {
  ifstream in(filename, ifstream::in);
  stringstream sstr;
  sstr << in.rdbuf();
  string file = sstr.str();
  return file;
}

int main(int argc, char *argv[]) {
  int c;
  string filename;
  bool fexists = false;
  if (argc > 1) {
    for (c = 1; c < argc; c++) {
      if (strcmp(argv[c], "-f") == 0) {
        fexists = true;
        filename = string(argv[c + 1]);
        cout << "Running program with file input " + filename + "\n";
      }
    }
  }

  if (fexists == false) {
    cout << "Please provide a filename with the -f parameter";
  }

  clock_t begin_read = clock();
  string file_to_analyze = slurp(filename);
  clock_t end_read = clock();
  double elapsed_secs_read = double(end_read - begin_read) / CLOCKS_PER_SEC;

  clock_t begin_gcount = clock();
  int gcount = count_string_occurance(file_to_analyze, 'G');
  clock_t end_gcount = clock();
  double elapsed_secs_gcount =
      double(end_gcount - begin_gcount) / CLOCKS_PER_SEC;

  clock_t begin_acount = clock();
  int acount = count_string_occurance(file_to_analyze, 'A');
  clock_t end_acount = clock();
  double elapsed_secs_acount =
      double(end_acount - begin_acount) / CLOCKS_PER_SEC;

  clock_t begin_ccount = clock();
  int ccount = count_string_occurance(file_to_analyze, 'C');
  clock_t end_ccount = clock();
  double elapsed_secs_ccount =
      double(end_ccount - begin_ccount) / CLOCKS_PER_SEC;

  clock_t begin_tcount = clock();
  int tcount = count_string_occurance(file_to_analyze, 'T');
  clock_t end_tcount = clock();
  double elapsed_secs_tcount =
      double(end_tcount - begin_tcount) / CLOCKS_PER_SEC;

  double total = (double)file_to_analyze.size();

  printf("Adenine (A) Count (Percentage): %i (%f%%) \n", acount,
         (acount / total) * 100);
  printf("Thymine (T) Count (Percentage): %i (%f%%) \n", tcount,
         (tcount / total) * 100);
  printf("Cytosine (C) Count (Percentage): %i (%f%%) \n", ccount,
         (ccount / total) * 100);
  printf("Guanine (G) Count (Percentage): %i (%f%%) \n", gcount,
         (gcount / total) * 100);

  printf("Read Time: %f \n"
         "A Count Time: %f \n"
         "T Count Time: %f \n"
         "C Count Time: %f \n"
         "G Count Time: %f \n",
         elapsed_secs_read, elapsed_secs_gcount, elapsed_secs_tcount,
         elapsed_secs_ccount, elapsed_secs_gcount);

  return 0;
}
