import multiprocessing
import time

def do_something(num, Q):
	Q[num] = (num*num)
	time.sleep(.05)

def do_something2(num):
	time.sleep(.05)
	return num*num
    

if __name__ == '__main__':
	print('multiprocessing : ')
	t1 = time.time()
	Q_p = multiprocessing.Manager()
	Q_c = Q_p.dict()

	task = list()
	for _ in range(6):

		task1 = multiprocessing.Process(target = do_something, args = (_, Q_c))
		task1.start()
		task.append(task1)
	
	for i in task:
		i.join()
		i.terminate()

	t2 = time.time()
	print(f"Completed in : {round(t2-t1, 5)} second(s)")
	print(Q_c, "\n")