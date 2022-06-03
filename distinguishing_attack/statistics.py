import os
import numpy as np
import argparse

def gather():
    with open("gather.txt", "w+") as f:
        k = set()
        # Iteratively read all files in `./gather`
        for filename in os.listdir("./gather"):
            with open("./gather/" + filename, "r") as f_read:
                # Read the first line
                line = f_read.readline()
                line = line.strip()
                while line:

                    if line in k:
                        print("Duplicate: " + line)

                    k.add(line)
                    f.write(line + "\n")
                    line = f_read.readline().strip()

# Relations
single_bit = [0 for _ in range(80)]
double_bit = [[0 for _ in range(80)] for _ in range(80)]

if __name__ == "__main__":

    parser = argparse.ArgumentParser()
    parser.add_argument("--max", type=int, default=100000)
    args = parser.parse_args()

    # Open `gather.txt`
    max_read = args.max
    cnt = 0

    with open("gather.txt", "r") as f:
        for line in f.readlines():
            cnt += 1
            line = line.strip()
            if len(line) == 0:
                break

            assert len(line) == 20

            # Convert this hex string to 80 bits
            bits = [int(line[i:i+2], 16) for i in range(0, 20, 2)]

            bit_string = ""
            for bit in bits:
                bit_string += bin(bit)[2:].zfill(8)

            # Count single bit
            for i in range(80):
                if bit_string[i] == "1":
                    single_bit[i] += 1

            # Count double bit
            for i in range(80):
                for j in range(i, 80):
                    if bit_string[i] == bit_string[j]:
                        double_bit[i][j] += 1
                        double_bit[j][i] += 1

            if cnt >= max_read:
                break

    # Save single bit and double bit
    dic = {
        "single_bit": np.array(single_bit),
        "double_bit": np.array(double_bit)
    }

    np.savez(f"statistics-{args.max}.npz", dic)





