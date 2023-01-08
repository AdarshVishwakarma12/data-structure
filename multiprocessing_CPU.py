# import time
# import concurrent.futures

# t1 = time.time()

# def do_something(n):
# 	time.sleep(1)
# 	return f'me{n}'

# res = list()
# if __name__ == '__main__':
# 	with concurrent.futures.ProcessPoolExecutor()  as executor:
# 		results = executor.map(do_something, range(10, 0, -1))
# 		for i in results:
# 			res.append(i)

# 	print(res)
# 	t2 = time.time()
# 	print(f"Completed in {round(t2-t1, 2)} second(s)")

import time
import concurrent.futures

# t1 = time.time()

# num = [0, 1, 2, 3, 4, 5, 6]

def do_something(n):
    time.sleep(1)
    return n*n
    
# def main():
#     t1 = time.time()
#     with concurrent.futures.ProcessPoolExecutor() as executor:
#         print([val for val in executor.map(do_something, num)])
        
#     t2 = time.time()
#     print(f"Completed in {round(t2-t1, 2)} second(s)")

# if __name__ == '__main__':
#     main()