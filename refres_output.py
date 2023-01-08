import sys
import time
import curses
t1 = time.time()

# print("processing : ")
# for _ in range(10):
# 	sys.stdout.write(f"\r{(_+1)/10}")
# 	sys.stdout.flush()
# 	time.sleep(1.)

# 

def func(window):
	for i in range(10):
		window.addstr(10, 10, "[" + ('='*i) + ">" + (" "*(10-i)) + ']')
		window.refresh()
		time.sleep(0.4)

curses.wrapper(func)

print(f"\nTime Taken : {(time.time() - t1):.3} sec")