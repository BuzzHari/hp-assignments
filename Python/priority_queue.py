import queue
import time
import threading

lock = threading.Lock()
pqueue = queue.PriorityQueue(10)

class Worker(threading.Thread):
    def __init__(self):
        super().__init__(group=None)
        self.executed = False


    def run(self):
        while not self.executed:
            lock.acquire()
            if not pqueue.empty():
                item = pqueue.get()
                lock.release()
                print(item, "being processed by thread", self.ident)
                self.executed = True
            else:
                lock.release()
                time.sleep(0.5)


items = [2, 89, 69, 420, 1729, 1331]

for item in items:
    pqueue.put(item)

work_threads = []

for i in range(len(items)):
    worker = Worker()
    worker.start()
    work_threads.append(worker)

for thread in work_threads:
    thread.join()
