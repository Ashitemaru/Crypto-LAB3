import random
import string

from utils.hash import hash

def preimage2(start, max, gather=None):
    cnt = 0
    file_id = ''.join([random.choice(string.ascii_letters) for _ in range(10)])
    k = set()

    while True:
        cnt += 1
        h = hash(start, gather=gather, file_id=file_id)

        if cnt % 100 == 0:
            print(cnt, start, h)

        if h in k:
            print("CRACK", cnt, start, h)
            break
        k.add(h)
        start = h

        if cnt > max:
            print("PASS", cnt, start, h)
            break

import threading
if __name__ == "__main__":
    thread_list = []
    for i in range(10):
        t = threading.Thread(target=preimage2, args=(str(i), 10000, f"preimage2-{i}"))
        thread_list.append(t)
        t.start()

    for t in thread_list:
        t.join()

