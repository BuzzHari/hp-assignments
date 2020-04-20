import threading

balance = 500

lock = threading.Lock()

def with_draw(value):
	lock.acquire()
	global balance
	if (balance < 1000):
		print("Thread ", threading.currentThread().getName(), "Balance is very low to Withdraw")
	else:
		balance -= value
		print("Thread ", threading.currentThread().getName(), "Withdrew ", value)
		print("Total balance ", balance)
	lock.release()

def deposit(value):
	lock.acquire()
	global balance
	balance += value
	print("Thread ", threading.currentThread().getName(), "Deposited ", value)
	print("Total balance ", balance)
	lock.release()


d1 = threading.Thread(target=deposit, args=[1000])

w1 = threading.Thread(target=with_draw, args=[50])

d1.start()
w1.start()

