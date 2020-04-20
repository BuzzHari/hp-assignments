import threading
import time

def threads(t_name, delay):
    i = 0
    while i < 10:
        time.sleep(delay)
        i+=1
        print(t_name, delay)


if __name__ == "__main__":
    t1 = threading.Thread(None, threads, "Thread 1", ("Thread 1", 5))
    t2 = threading.Thread(None, threads, "Thread 2", ("Thread 2", 5))

    t1.start()
    t2.start()
