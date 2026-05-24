#include <bthread/bthread.h>

#include <iostream>
#include <vector>

struct SharedState {
  int counter = 0;
  bthread_mutex_t mutex;
};

struct WorkerArg {
  int id = 0;
  int repeat = 0;
  SharedState *state = nullptr;
};

void *worker(void *raw_arg) {
  auto *arg = static_cast<WorkerArg *>(raw_arg);

  for (int i = 0; i < arg->repeat; ++i) {
    bthread_mutex_lock(&arg->state->mutex);
    ++arg->state->counter;
    bthread_mutex_unlock(&arg->state->mutex);

    // Sleep for 10 ms without blocking the underlying worker pthread.
    bthread_usleep(10 * 1000);
  }

  std::cout << "worker " << arg->id << " finished\n";
  return nullptr;
}

int main() {
  constexpr int kWorkerCount = 4;
  constexpr int kRepeat = 5;

  SharedState state;
  bthread_mutex_init(&state.mutex, nullptr);

  std::vector<bthread_t> tids(kWorkerCount);
  std::vector<WorkerArg> args(kWorkerCount);
  bthread_attr_t attr = BTHREAD_ATTR_NORMAL;
  bthread_attr_set_name(&attr, "demo_worker");
  int started = 0;

  for (int i = 0; i < kWorkerCount; ++i) {
    args[i] = WorkerArg{i, kRepeat, &state};

    const int rc =
        bthread_start_background(&tids[i], &attr, worker, &args[i]);
    if (rc != 0) {
      std::cerr << "failed to start bthread " << i << ", error = " << rc
                << '\n';
      for (int j = 0; j < started; ++j) {
        bthread_join(tids[j], nullptr);
      }
      bthread_mutex_destroy(&state.mutex);
      return 1;
    }
    ++started;
  }

  for (bthread_t tid : tids) {
    bthread_join(tid, nullptr);
  }

  std::cout << "counter = " << state.counter << '\n';

  bthread_mutex_destroy(&state.mutex);
  return 0;
}
