import subprocess
import sys
import os
from math import log2, floor
from shutil import copy

def evaluate_file(input_file: str):

    size =  os.path.getsize(input_file) * 8

    # block_size = 128

    prelude = f"""
    0
    {input_file}
    0
    """

    n_size = 128 * 8

    # adjust the size of n
    # according to requirements 
    # specified in the documentation
    n = {}
    # n = {
    #     2: block_size * 90,
    #     8: block_size * 90,
    # }

    # # test parameters
    tests = {}
    tests = {
        2: f"""
            0
            """,
        8: f"""
            0
            """,
        9: f"""
            0
            """,
        11: f"""
            1
            {floor(log2(n_size)) - 5 - 1}
            0
            """,  # m < floor(log_2 n) - 2
        14: f"""
            1
            {floor(log2(n_size)) - 2 - 1}
            0
            """,  # m < floor(log_2 n) - 2
        15: f"""
            0
            """,
    }

    def evaluate(test_id: int):
        
        choice = "0" * (test_id - 1) + "1" + "0" * (15 - test_id)
        num_streams = n[test_id] if test_id in n else n_size
        input_s = f"""
        {prelude}
        {choice}
        {tests[test_id] if test_id in tests else ""}
        {300} 
        1
        
        """
        print("Total bits:", size)
        print("Bits in a single stream:", num_streams)
        print("Total Streams:", size // num_streams)
        print(input_s)
        p = subprocess.run(['./assess', str(num_streams)], input=input_s ,encoding='ascii')
        print(p.returncode, p.stdout)

        result_dir = input_file.replace('.out', '')

        if not os.path.exists(result_dir):
            os.mkdir(result_dir)

        copy("experiments/AlgorithmTesting/finalAnalysisReport.txt", f"{result_dir}/report_{test_id}.txt")

    for i in range(1, 16):
        evaluate(i)

if __name__ == "__main__":
    evaluate_file('sample_random.out')
    evaluate_file('sample_low_density.out')
    evaluate_file('sample_high_density.out')
