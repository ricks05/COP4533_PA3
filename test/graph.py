import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv("./io/runtimes.csv")

plt.figure(figsize=(8, 5))
plt.bar(df["filename"], df["T"])
plt.title('Runtime per Input File')
plt.xlabel('Filename')
plt.ylabel('Runtime (ns)')
plt.xticks(rotation=75)  # rotate labels if filenames are long
plt.tight_layout()
plt.show()
