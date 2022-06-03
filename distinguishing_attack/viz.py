import IPython
import numpy as np
from matplotlib import pyplot as plt

if __name__ == "__main__":

    plt.title("Single bit")

    for idx, max_length in enumerate([2500, 5000, 10000, 20000, 50000, 100000]):
        data = np.load(f"statistics-{max_length}.npz", allow_pickle=True)
        single_data = data["arr_0"].item()['single_bit']
        plt.subplot(2, 3, idx + 1)
        plt.plot([i for i in range(1, 81)], single_data / max_length, label=f"{max_length}")
        plt.xlabel("Index of bits")
        plt.ylabel("Probability")
        plt.title(f"Sample = {max_length}")

    plt.tight_layout()
    plt.savefig("single_bit_prob.png", format="png", dpi=300)

    for idx, max_length in enumerate([2500, 5000, 10000, 20000, 50000, 100000]):
        data = np.load(f"statistics-{max_length}.npz", allow_pickle=True)
        double_data = data["arr_0"].item()['double_bit']
        plt.subplot(2, 3, idx + 1)
        plt.xlabel("Index of bits")
        plt.ylabel("Index of bits")
        plt.title(f"Sample = {max_length}")
        plt.pcolormesh(double_data / max_length, cmap="jet")

    plt.tight_layout()
    plt.savefig("double_bit_prob.png", format="png", dpi=300)
