#include "mpi.h"
#include <chrono>
#include <cstdio>
#include <random>
#include <thread>

int epilogue(int rank) {
  int len;
  char version[MPI_MAX_LIBRARY_VERSION_STRING];
  MPI_Get_library_version(version, &len);

  int n = 1000;
  for (int i = 0; i < n; i++) {
    std::this_thread::sleep_for(std::chrono::seconds(3));
    printf("[Rank %d] sleep\n", rank);
  }
  return 0;
}

int main(int argc, char *argv[]) {
  int rank, workers, proc_name_size;
  MPI_Init(&argc, &argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
  MPI_Comm_size(MPI_COMM_WORLD, &workers);
  if (rank == 0) {
    printf("Workers: %d\n", workers);
  }
  char hostname[MPI_MAX_PROCESSOR_NAME];
  MPI_Get_processor_name(hostname, &proc_name_size);
  printf("Rank %d on host %s\n", rank, hostname);


  //    std::minstd_rand generator(rank);
  //    std::uniform_real_distribution<double> distribution(-1.0, 1.0);
  //    double x, y;
  //    long long worker_count = 0;
  //    int worker_tests = 10000000;
  //    for (int i = 0; i < worker_tests; i++) {
  //        x = distribution(generator);
  //        y = distribution(generator);
  //        if (x * x + y * y <= 1.0) {
  //            worker_count++;
  //        }
  //    }
  //    long long total_count = 0;
  //    MPI_Reduce(&worker_count, &total_count, 1, MPI_LONG_LONG, MPI_SUM, 0,
  //    MPI_COMM_WORLD); if (rank == 0) {
  //        double pi = 4 * (double)total_count / (double)(worker_tests) /
  //        (double)(workers); printf("pi is approximately %.16lf\n", pi);
  //    }
  epilogue(rank);
  MPI_Finalize();
  return 0;
}
